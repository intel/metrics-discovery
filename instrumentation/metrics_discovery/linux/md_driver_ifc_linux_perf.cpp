/*****************************************************************************\

    Copyright © 2018, Intel Corporation

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.

    File Name:  md_driver_ifc_linux_perf.cpp

    Abstract:   C++ implementation for Linux/Android with Perf

\*****************************************************************************/
#include "md_driver_ifc_linux_perf.h"
#include "iu_i915_perf.h"

#include <math.h>
#include <string.h>
#include <inttypes.h>      // for PRIu64 (printing uint64_t)
#include <errno.h>
#include <vector>
#include <string>
#include <functional>      // for std::hash
#include <algorithm>       // for std::find, std::remove

#include <sys/stat.h>
#include <sys/sysmacros.h> // for major, minor
#include <fcntl.h>
#include <dirent.h>
#include <poll.h>
#include <unistd.h>        // close, write, read

#include "xf86drm.h"       // for drmOpen/drmClose/drmIoctl

#if defined(__cplusplus)
extern "C" {
#endif
#include "gen_device_info.h"    // MESA
#if defined(__cplusplus)
}
#endif

/*****************************************************************************\

Description:
    General defines used by Perf driver interface.

\*****************************************************************************/
#define MD_PERF_OA_BUFFER_SIZE             (16 * MD_MBYTE) // OaBuffer size in Perf is constant and it's always 16MB
#define MD_MAX_PATH_LENGTH                 128
#define MD_PERF_GUID_LENGTH                37              // GUID is a string formatted like "%08x-%04x-%04x-%04x-%012x"
#define MD_PERF_GUID_FOR_QUERY             "2f01b241-7014-42a7-9eb6-a925cad3daba" // static GUID for storing Query configuration

/*****************************************************************************\

Description:
    Register used for reading GPU Timestamp.

\*****************************************************************************/
#define MD_TIMESTAMP_LOW_OFFSET            0x2358

/*****************************************************************************\

Description:
    Default GpuTimestampFrequency, used if value obtained from Mesa is invalid.

\*****************************************************************************/
#define MD_DEFAULT_GPU_TIMESTAMP_FREQUENCY 12500000;       // One tick per 80ns

/*****************************************************************************\

Description:
    Hardware info used in number of shading units and number of render output
    units calculation. Based on Intel driver instrumentation files.

\*****************************************************************************/
#define MD_NUM_PIXELS_OUT_PER_CLOCK        4
#define MD_EU_SIMD_SIZE_PER_CLOCK          4

/*****************************************************************************\

Description:
    For platforms <= SKL mask of size '3' is used to preserve backward compatibility
    with MDAPI metric equation definitions. Based on Intel driver instrumentation
    files.

\*****************************************************************************/
#define MD_MAX_SUBSLICE_PER_SLICE_OLD      3

/*****************************************************************************\

Description:
    Maximums which bound all supported GT. Must update as needed with new GT.
    Based on Intel driver files.

\*****************************************************************************/
#define MD_MAX_SUBSLICE_PER_SLICE          8    // Currently max value
#define MD_MAX_SLICE                       4    // Currently max value

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{

/*****************************************************************************\

Global variables:
    Frequency SysFs file names.

Description:
    Min/Max frequency files return the min/max frequency that can be set on the HW.
    Min/Max/Boost frequency override files return currently set frequency. Setting
    static frequency requires writing to all of these 3 files.

\*****************************************************************************/
static const char ACT_FREQ_FILE_NAME[]     = "gt_act_freq_mhz";
static const char MAX_FREQ_FILE_NAME[]     = "gt_RP0_freq_mhz";
static const char MIN_FREQ_FILE_NAME[]     = "gt_RPn_freq_mhz";

static const char MAX_FREQ_OV_FILE_NAME[]   = "gt_max_freq_mhz";
static const char MIN_FREQ_OV_FILE_NAME[]   = "gt_min_freq_mhz";
static const char BOOST_FREQ_OV_FILE_NAME[] = "gt_boost_freq_mhz";

/*****************************************************************************\

Class:
    CSemaphore

Method:
    CSemaphore constructor

Description:
    Initializes member variables, setting initial semaphore count to 1 - unlocked
    state with one available resource.

\*****************************************************************************/
CSemaphore::CSemaphore()
    : semCount(1)
{ }

/*****************************************************************************\

Class:
    CSemaphore

Method:
    Notify

Description:
    Unlocks semaphore.

\*****************************************************************************/
void CSemaphore::Notify()
{
    std::unique_lock<TFenceMutex> lock( semMutex );
    ++semCount;
    semCv.notify_one();
}

/*****************************************************************************\

Class:
    CSemaphore

Method:
    Wait

Description:
    Waits (without timeout) for free resources then acquires semaphore.

\*****************************************************************************/
void CSemaphore::Wait()
{
    std::unique_lock<TFenceMutex> lock( semMutex );
    while( !semCount )
    {
        semCv.wait( lock );
    }
    --semCount;
}

/*****************************************************************************\

Class:
    CSemaphore

Method:
    WaitFor

Description:
    Tries to acquire semaphore, waiting up to *timeoutMs* milliseconds for
    free resources.

Input:
    uint64_t timeoutMs - maximal time to wait for free semaphore resources

Output:
    bool - true if semaphore was acquired successfully, false otherwise

\*****************************************************************************/
bool CSemaphore::WaitFor( uint64_t timeoutMs )
{
    std::unique_lock<TFenceMutex> lock( semMutex );

    bool semLocking = false;
    if( semCount == 0 )
    {
        auto result = semCv.wait_for( lock,
                                      std::chrono::milliseconds(timeoutMs) );
        if(( result == std::cv_status::no_timeout ) &&
           ( semCount > 0 ))
        {
            --semCount;
            semLocking = true;
        }
    }
    else // (semCount > 0)
    {
        --semCount;
        semLocking = true;
    }

    return semLocking;
}

/*****************************************************************************\

Class:
    CSemaphore

Method:
    TryWait

Description:
    Tries to acquire semaphore without any waiting and returns immediately.

Output:
    bool - true if semaphore was acquired successfully, false otherwise

\*****************************************************************************/
bool CSemaphore::TryWait()
{
    std::unique_lock<TFenceMutex> lock(semMutex);
    if( semCount )
    {
        --semCount;
        return true;
    }
    else
    {
        return false;
    }
}

/*****************************************************************************\

Class:
    CSemaphore

Method:
    GetValue

Description:
    Returns free semaphore resources count. 0 means no free resources.

Output:
    uint32_t - Semaphore resources count

\*****************************************************************************/
uint32_t CSemaphore::GetValue()
{
    return semCount;
}

/*****************************************************************************\

Class:
    CDriverInterface

Method:
    GetInstance()

Description:
    Returns instance of CDriverInterface for Linux/Android supporting Perf.

Output:
    CDriverInterface* - Pointer to new allocated object of CDriverInterfaceLinuxPerfPerf

\*****************************************************************************/
#if defined(MD_USE_PERF)
CDriverInterface* CDriverInterface::GetInstance()
{
    CDriverInterface* driverInterface = new (std::nothrow) CDriverInterfaceLinuxPerf();
    if( ( driverInterface != NULL ) &&
        ( driverInterface->CreateContext() == false ) )
    {
        MD_SAFE_DELETE( driverInterface );
    }

    return driverInterface;
}
#endif

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    CDriverInterfaceLinuxPerf constructor

Description:
    Creates driver context.

\*****************************************************************************/
CDriverInterfaceLinuxPerf::CDriverInterfaceLinuxPerf()
    : m_DrmFd( -1 )
    , m_DrmCardNumber( -1 )
    , m_PerfStreamFd( -1 )
    , m_PerfStreamConfigId( -1 )
{
    MD_LOG_ENTER();
    MD_LOG_EXIT();
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    CDriverInterfaceLinuxPerf destructor

Description:
    Deletes driver context.

\*****************************************************************************/
CDriverInterfaceLinuxPerf::~CDriverInterfaceLinuxPerf()
{
    MD_LOG_ENTER();
    DeleteContext();
    MD_LOG_EXIT();
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    CreateContext

Description:
    Creates driver context.

Output:
    bool - *true* if successful

\*****************************************************************************/
bool CDriverInterfaceLinuxPerf::CreateContext()
{
    return InitializeIntelDrm();
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    DeleteContext

Description:
    Deletes driver context. Closes Perf stream if opened and closes DRM.

\*****************************************************************************/
void CDriverInterfaceLinuxPerf::DeleteContext()
{
    // Query
    for( int32_t perfConfigId : m_AddedPerfConfigs )
    {
        RemovePerfConfig( perfConfigId );
    }
    m_AddedPerfConfigs.clear();

    // Close Perf stream if opened
    ClosePerfStream();

    if( RemovePerfConfig( m_PerfStreamConfigId ) == CC_OK )
    {
        m_PerfStreamConfigId = -1;
    }

    DeinitializeIntelDrm();
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    GetDeviceName

Description:
    Returns device name, e.g. "Intel HD 6000 Graphics Media Accelerator"

Output:
    const char* - device name

\*****************************************************************************/
const char* CDriverInterfaceLinuxPerf::GetDeviceName()
{
    int32_t     deviceId   = -1;
    const char* deviceName = NULL;

    if( GetDeviceId( &deviceId ) == CC_OK )
    {
        deviceName = gen_get_device_name( deviceId );
    }

    return (deviceName) ? deviceName : "";
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    GetNeedSupportEnable

Description:
    Return true if this is metrics discovery library responsibility to call
    Support Enable.

Output:
    boolean value indicating whether SupportEnable needs to be called from MD
    library

\*****************************************************************************/
bool CDriverInterfaceLinuxPerf::GetNeedSupportEnable()
{
    return false;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    SendSupportEnableEscape

Description:
    Enable performance monitoring support.

Input:
    bool enable     - true to enable support, false to disable support

Output:
    TCompletionCode - *CC_OK* means succeess

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::SendSupportEnableEscape( bool enable )
{
    // Not needed on Linux Perf
    return CC_OK;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    SendDeviceInfoParamEscape

Description:
    Gets chosen device info param using information from kernel.

Input:
    GTDI_DEVICE_PARAM param    - chosen param
    GTDIDeviceInfoParamOut out - (OUT) escape result

Output:
    TCompletionCode            - *CC_OK* means succeess

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM param, GTDIDeviceInfoParamOut* out )
{
    MD_CHECK_PTR_RET( out, CC_ERROR_INVALID_PARAMETER );

    TCompletionCode ret = CC_OK;

    switch( param )
    {
        case GTDI_DEVICE_PARAM_EU_CORES_TOTAL_COUNT:
        {
            ret = SendGetParamIoctl( m_DrmFd, I915_PARAM_EU_TOTAL, out );
            break;
        }

        case GTDI_DEVICE_PARAM_EU_CORES_PER_SUBSLICE_COUNT:
        {
            // #TODO_perf_later - it will be later added to i915 kernel (temporarily EuCoresTotalCount / EuSubslicesTotalCount)
            int32_t euCoresTotalCount   = 0;
            int32_t subslicesTotalCount = 0;

            ret = SendGetParamIoctl( m_DrmFd, I915_PARAM_EU_TOTAL, &euCoresTotalCount );
            MD_CHECK_CC_RET(ret);
            ret = SendGetParamIoctl( m_DrmFd, I915_PARAM_SUBSLICE_TOTAL, &subslicesTotalCount );
            MD_CHECK_CC_RET(ret);

            out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
            out->ValueUint32 = euCoresTotalCount / subslicesTotalCount;
            break;
        }

        case GTDI_DEVICE_PARAM_SUBSLICES_TOTAL_COUNT:
        case GTDI_DEVICE_PARAM_SAMPLERS_COUNT:
        {
            ret = SendGetParamIoctl( m_DrmFd, I915_PARAM_SUBSLICE_TOTAL, out );
            break;
        }

        case GTDI_DEVICE_PARAM_SUBSLICES_PER_SLICE_COUNT:
        {
            // Return value is a mask for one slice (assuming it's uniform for each slice)
            int32_t singleSubsliceMask = 0;

            ret = SendGetParamIoctl( m_DrmFd, I915_PARAM_SUBSLICE_MASK, &singleSubsliceMask );
            MD_CHECK_CC_RET( ret );

            out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
            out->ValueUint32 = CalculateEnabledBits( singleSubsliceMask, 0xFFFFFFFF );

            MD_ASSERT( out->ValueUint32 <= GetGtMaxSubslicePerSlice() );
            break;
        }

        case GTDI_DEVICE_PARAM_SLICES_COUNT:
        {
            int32_t sliceMask = 0;

            ret = SendGetParamIoctl( m_DrmFd, I915_PARAM_SLICE_MASK, &sliceMask );
            MD_CHECK_CC_RET( ret );

            out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
            out->ValueUint32 = CalculateEnabledBits( (uint32_t)sliceMask, 0xFFFFFFFF );

            MD_ASSERT( out->ValueUint32 <= MD_MAX_SLICE );
            break;
        }

        case GTDI_DEVICE_PARAM_NUMBER_OF_RENDER_OUTPUT_UNITS:
        {
            int32_t sliceMask = 0;

            ret = SendGetParamIoctl( m_DrmFd, I915_PARAM_SLICE_MASK, &sliceMask );
            MD_CHECK_CC_RET( ret );

            out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
            out->ValueUint32 = MD_NUM_PIXELS_OUT_PER_CLOCK * CalculateEnabledBits( (uint32_t)sliceMask, 0xFFFFFFFF ); // pixels_out_per_clock * sliceCount
            break;
        }

        case GTDI_DEVICE_PARAM_EU_THREADS_COUNT:
        {
            const gen_device_info* mesaDeviceInfo = NULL;

            ret = GetMesaDeviceInfo( &mesaDeviceInfo );
            MD_CHECK_CC_RET( ret );

            out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
            out->ValueUint32 = mesaDeviceInfo->num_thread_per_eu;
            break;
        }

        case GTDI_DEVICE_PARAM_NUMBER_OF_SHADING_UNITS:
        {
            const gen_device_info* mesaDeviceInfo = NULL;

            ret = GetMesaDeviceInfo( &mesaDeviceInfo );
            MD_CHECK_CC_RET( ret );

            out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
            out->ValueUint32 = MD_EU_SIMD_SIZE_PER_CLOCK * mesaDeviceInfo->num_thread_per_eu; // eu_simd_size_per_clock * euThreadCount
            break;
        }

        case GTDI_DEVICE_PARAM_SUBSLICES_MASK:
        {
            // Return value is a mask for one slice (assuming it's uniform for each slice)
            int32_t  singleSubsliceMask       = 0;
            int32_t  sliceMask                = 0;
            uint32_t maxSubslicePerSliceCount = GetGtMaxSubslicePerSlice();

            ret = SendGetParamIoctl( m_DrmFd, I915_PARAM_SUBSLICE_MASK, &singleSubsliceMask );
            MD_CHECK_CC_RET( ret );
            ret = SendGetParamIoctl( m_DrmFd, I915_PARAM_SLICE_MASK, &sliceMask );
            MD_CHECK_CC_RET( ret );

            out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
            out->ValueUint32 = 0;

            for( int32_t i = 0; i < MD_MAX_SLICE; ++i )
            {
                // If slice enabled
                if( sliceMask & MD_BIT( i ) )
                {
                    int32_t targetSubsliceMask = singleSubsliceMask << (maxSubslicePerSliceCount * i);
                    out->ValueUint32 |= targetSubsliceMask;
                }
            }
            break;
        }

        case GTDI_DEVICE_PARAM_SLICES_MASK:
        {
            ret = SendGetParamIoctl( m_DrmFd, I915_PARAM_SLICE_MASK, out );
            break;
        }

        case GTDI_DEVICE_PARAM_DRAM_PEAK_THROUGHTPUT:
            ret = CC_ERROR_NOT_SUPPORTED;
            break;

        case GTDI_DEVICE_PARAM_DRAM_FREQUENCY:
            ret = CC_ERROR_NOT_SUPPORTED;
            break;

        case GTDI_DEVICE_PARAM_GPU_CORE_MIN_FREQUENCY:
        case GTDI_DEVICE_PARAM_GPU_CORE_MAX_FREQUENCY:
        case GTDI_DEVICE_PARAM_GPU_CORE_FREQUENCY:
        {
            uint64_t* minFrequency = (param == GTDI_DEVICE_PARAM_GPU_CORE_MIN_FREQUENCY) ? &out->ValueUint64 : NULL;
            uint64_t* maxFrequency = (param == GTDI_DEVICE_PARAM_GPU_CORE_MAX_FREQUENCY) ? &out->ValueUint64 : NULL;
            uint64_t* actFrequency = (param == GTDI_DEVICE_PARAM_GPU_CORE_FREQUENCY)     ? &out->ValueUint64 : NULL;

            ret = GetGpuFrequencyInfo( minFrequency, maxFrequency, actFrequency, NULL );
            MD_CHECK_CC_RET( ret );

            out->ValueType = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT64;
            break;
        }

        case GTDI_DEVICE_PARAM_PCI_DEVICE_ID:
        {
            int32_t deviceId = -1;

            ret = GetDeviceId( &deviceId );
            MD_CHECK_CC_RET( ret );

            out->ValueUint32 = (uint32_t) deviceId;
            out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
            break;
        }

        case GTDI_DEVICE_PARAM_REVISION_ID:
        {
            ret = SendGetParamIoctl( m_DrmFd, I915_PARAM_REVISION, out );
            break;
        }

        case GTDI_DEVICE_PARAM_PLATFORM_INDEX:
        {
            GTDI_PLATFORM_INDEX platformIndex;
            ret = GetInstrPlatformId( &platformIndex );
            MD_CHECK_CC_RET( ret );

            out->ValueUint32 = (uint32_t) platformIndex;
            out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
            break;
        }

        case GTDI_DEVICE_PARAM_GT_TYPE:
        {
            const gen_device_info* mesaDeviceInfo = NULL;

            ret = GetMesaDeviceInfo( &mesaDeviceInfo );
            MD_CHECK_CC_RET( ret );

            // Returning mapped GtType for compatibility reasons
            out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
            out->ValueUint32 = (uint32_t) MapMesaToInstrGtType( mesaDeviceInfo->gt );
            break;
        }

        case GTDI_DEVICE_PARAM_APERTURE_SIZE:
        {
            drm_i915_gem_get_aperture getApertureParams = {0,};

            int32_t ioctlRet = SendIoctl( m_DrmFd, DRM_IOCTL_I915_GEM_GET_APERTURE, &getApertureParams );
            if( ioctlRet )
            {
                MD_LOG( LOG_WARNING, "ERROR: Failed to send DRM_I915_GEM_GET_APERTURE ioctl" );
                return CC_ERROR_GENERAL;
            }

            out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT64;
            out->ValueUint64 = getApertureParams.aper_size;
            break;
        }

        case GTDI_DEVICE_PARAM_CAPABILITIES:
            ret = CC_ERROR_NOT_SUPPORTED;
            break;

        case GTDI_DEVICE_PARAM_OA_BUFFER_SIZE_MIN:
        case GTDI_DEVICE_PARAM_OA_BUFFER_SIZE_MAX:
        {
            // Buffer size in Perf is constant
            out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
            out->ValueUint32 = MD_PERF_OA_BUFFER_SIZE;
            break;
        }

        case GTDI_DEVICE_PARAM_GPU_TIMESTAMP_FREQUENCY:
        {
            uint64_t gpuTimestampFrequency = 0;

            ret = GetGpuTimestampFrequency( &gpuTimestampFrequency );
            MD_CHECK_CC_RET( ret );

            out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT64;
            out->ValueUint64 = gpuTimestampFrequency;
            break;
        }

        case GTDI_DEVICE_PARAM_EDRAM_SIZE:
            ret = CC_ERROR_NOT_SUPPORTED;
            // It probably could be read from DebugFs i915_llc
            break;

        case GTDI_DEVICE_PARAM_LLC_SIZE:
            ret = CC_ERROR_NOT_SUPPORTED;
            break;

        case GTDI_DEVICE_PARAM_L3_SIZE:
            ret = CC_ERROR_NOT_SUPPORTED;
            break;

        case GTDI_DEVICE_PARAM_GPU_TIMESTAMP:
        {
            uint64_t gpuTimestampNs = 0;

            ret = GetGpuTimestampNs( &gpuTimestampNs );
            MD_CHECK_CC_RET( ret );

            out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT64;
            out->ValueUint64 = gpuTimestampNs;
            break;
        }

        default:
            ret = CC_ERROR_INVALID_PARAMETER;
    }

    return ret;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    SendPmRegsConfig

Description:
    (ONLY FOR QUERY)
    Adds PmRegs configuration to the i915 kernel through Perf interface.
    configuration is added under a fixed GUID, which is known to the UMD driver.
    Configuration added under this GUID is later used as a Query configuration.

    Before adding the configuration to a i915 kernel, the previous one (if exists)
    is removed.
    WARNING: Only one configuration may be used at a time!

Input:
    TRegister** regVector - array of pointers to registers to program
    uint32_t    regCount  - register count
    uint32_t    apiMask   - API mask

Output:
    TCompletionCode       - *CC_OK* means success

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::SendPmRegsConfig( TRegister** regVector, uint32_t regCount, uint32_t apiMask )
{
    MD_LOG_ENTER();
    MD_CHECK_PTR_RET( regVector, CC_ERROR_INVALID_PARAMETER );
    if( apiMask & API_TYPE_IOSTREAM )
    {
        MD_LOG( LOG_DEBUG, "SetApiFiltering wasn't used" );
    }

    TCompletionCode ret = CC_OK;

    if( regCount )      // It's ok if regCount is 0, e.g. for PipelineStats metric set, which has no configuration (only QueryId)
    {
        int32_t addedConfigId = -1;

        // Validate query config GUID
        static_assert( sizeof(MD_PERF_GUID_FOR_QUERY) == MD_PERF_GUID_LENGTH, "MD_PERF_GUID_FOR_QUERY must be of size MD_PERF_GUID_LENGTH" );

        // 1. REMOVE PREVIOUS QUERY CONFIG IF exists
        //    WARNING: Config from the latest Activate() call will always be used!
        RemovePerfConfigQuery();

        // 2. ADD CONFIG
        ret = AddPerfConfig( regVector, regCount, MD_PERF_GUID_FOR_QUERY, &addedConfigId );
        MD_CHECK_CC_RET( ret );

        MD_ASSERT( addedConfigId != -1 );

        // 3. REMEMBER ADDED CONFIG
        if( ret == CC_OK )
        {
            if( std::find( m_AddedPerfConfigs.begin(), m_AddedPerfConfigs.end(), addedConfigId ) == m_AddedPerfConfigs.end() )
            {
                m_AddedPerfConfigs.push_back( addedConfigId );      // Remember configId for later removal, only if it wasn't added before - may happen when
                                                                    // the config is already added and ID is reused.
            }
        }
        else
        {
            RemovePerfConfig( addedConfigId );
        }
    }

    MD_LOG_EXIT();
    return ret;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    SendReadRegsConfig

Description:
    (ONLY FOR QUERY)
    Sends ReadRegs configuration to the driver.

Input:
    TRegister** regVector - array of pointers to registers to program
    uint32_t    regCount  - register count
    uint32_t    apiMask   - API mask

Output:
    TCompletionCode       - *CC_OK* means succeess

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::SendReadRegsConfig( TRegister** regVector, uint32_t regCount, uint32_t apiMask )
{
    return CC_ERROR_NOT_SUPPORTED;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    GetPmRegsConfigHandles

Description:
    Retrieves handles to the Oa, Gp and read regs configuration from the driver.
    !READ REGS NOT SUPPORTED ON ANDROID YET!

Input:
    uint32_t  configId       - config id
    uint32_t* oaConfigHandle - (OUT) OA config handle in KMD
    uint32_t* gpConfigHandle - (OUT) GP config handle in KMD
    uint32_t* rrConfigHandle - (OUT) Read regs config handle in KMD

Output:
    TCompletionCode           - *CC_OK* means succeess

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::GetPmRegsConfigHandles( uint32_t configId, uint32_t* oaConfigHandle,
    uint32_t* gpConfigHandle, uint32_t* rrConfigHandle )
{
    // Not supported on Linux Perf - returning CC_OK on purpose
    return CC_OK;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    ValidatePmRegsConfig

Description:
    !NOT SUPPORTED ON LINUX/ANDROID!
    Validates PmRegs configuration.

Input:
    TRegister*    regVector - array of registers to check
    uint32_t      regCount  - register count
    TPlatformType platform  - platform for which validate the config

Output:
    TCompletionCode         - *CC_OK* means succeess

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::ValidatePmRegsConfig( TRegister* regVector, uint32_t regCount, TPlatformType platform )
{
    // Not supported on Linux Perf - returning CC_OK on purpose
    return CC_ERROR_NOT_SUPPORTED;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    GetGpuCpuTimestamps

Description:
    Reads GPU and CPU timestamp.
    GpuTimestamp is read from DRM_IOCTL_I915_REG_READ ioctl that has the RCS timestamp register whitelisted.
    CpuTimestamp is read from clock_gettime() CLOCK_MONOTONIC.

Input:
    uint64_t* gpuTimestamp - (OUT) GPU timestamp in ns
    uint64_t* cpuTimestamp - (OUT) CPU timestamp in ns
    uint32_t* cpuId        - (OUT) CPU id

Output:
    TCompletionCode                  - *CC_OK* means succeess

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::GetGpuCpuTimestamps( uint64_t* gpuTimestamp, uint64_t* cpuTimestamp, uint32_t* cpuId )
{
    MD_LOG_ENTER();
    MD_CHECK_PTR_RET( gpuTimestamp, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( cpuTimestamp, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( cpuId, CC_ERROR_INVALID_PARAMETER );

    uint64_t gpuTimestampNs = 0;
    uint64_t cpuTimestampNs = 0;

    TCompletionCode ret = GetGpuTimestampNs( &gpuTimestampNs );
    MD_CHECK_CC_RET( ret );

    ret = GetCpuTimestampNs( &cpuTimestampNs );
    MD_CHECK_CC_RET( ret );

    // Set GPU & CPU timestamps
    *cpuTimestamp = cpuTimestampNs;
    *gpuTimestamp = gpuTimestampNs;

    MD_LOG_EXIT();
    return ret;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    SendGetCtxIdTagsEscape

Description:
    Sends GetCtxIdTags escape.
    *NOT SUPPORTED ON ANDROID/LINUX*

Input:
    TGetCtxTagsIdParams* params - params

Output:
    TCompletionCode             - *CC_OK* means succeess

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::SendGetCtxIdTagsEscape( TGetCtxTagsIdParams* params )
{
    // Not supported on Linux Perf - returning CC_OK on purpose
    return CC_ERROR_NOT_SUPPORTED;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    SemaphoreCreate

Description:
    Creates the unnamed semaphore, initial count and max count equal to 1.

Input:
    char*   name        - *NOT USED ON ANDROID/LINUX* name of a semaphore
    void**  semaphore   - (OUT) pointer to the memory where the semaphore handle will be stored

Output:
    TCompletionCode     - *CC_OK* means succeess

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::SemaphoreCreate( const char* name, void** semaphore )
{
    MD_LOG_ENTER();
    if( semaphore == NULL )
    {
        MD_ASSERT( semaphore != NULL );
        return CC_ERROR_INVALID_PARAMETER;
    }
    *semaphore = NULL;

    CSemaphore* _sem = new (std::nothrow) CSemaphore;
    MD_CHECK_PTR_RET( _sem, CC_ERROR_NO_MEMORY );

    *semaphore = (void*)_sem;

    MD_LOG_EXIT();
    return CC_OK;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    SemaphoreWait

Description:
    Tries to enter the semaphore gate, waits *miliseconds* until timeout.

Input:
    uint32_t milliseconds - time to wait in milliseconds

Output:
    TSemaphoreWaitResult  - result of operation

\*****************************************************************************/
TSemaphoreWaitResult CDriverInterfaceLinuxPerf::SemaphoreWait( uint32_t milliseconds, void* semaphore )
{
    MD_LOG_ENTER();
    if( !semaphore )
    {
        MD_ASSERT( false );
        MD_LOG_EXIT();
        return WAIT_RESULT_ERROR_GENERAL;
    }

    CSemaphore* _sem = (CSemaphore*)semaphore;
    TSemaphoreWaitResult retVal  = WAIT_RESULT_TIMEOUT;

    if( _sem->WaitFor(milliseconds) )
    {
        retVal = WAIT_RESULT_SUCCESSFUL;
    }

    MD_LOG_EXIT();
    return retVal;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    SemaphoreRelease

Description:
    Releases earlier created semaphore.

Output:
    TCompletionCode - result of operation (*CC_OK* is OK)

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::SemaphoreRelease( void** semaphore )
{
    MD_LOG_ENTER();
    if( semaphore == NULL || (*semaphore) == NULL )
    {
        MD_ASSERT( semaphore    != NULL );
        MD_ASSERT( (*semaphore) != NULL );
        MD_LOG_EXIT();
        return CC_ERROR_INVALID_PARAMETER;
    }

    CSemaphore* _sem     = *((CSemaphore**)semaphore);
    int32_t     semValue = 0;

    _sem->Notify();
    semValue = _sem->GetValue();

    if( semValue > 0 )
    {
        MD_LOG(LOG_DEBUG, "destroying semaphore");
        MD_SAFE_DELETE( _sem );
        *semaphore = NULL;
    }

    MD_LOG_EXIT();
    return CC_OK;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    LockConcurrentGroup

Description:
    Locks concurrent group of given name. Creates semaphore and waits up to 1s if
    needed.
    ! On Linux name isn't used, only semaphore pointer. !

Input:
    const char* name        - concurrent group name
    void**      semaphore   - (IN/OUT) pointer to the semaphore

Output:
    TCompletionCode         - *CC_OK* means succeess

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::LockConcurrentGroup( const char* name, void** semaphore )
{
    MD_CHECK_PTR_RET( semaphore, CC_ERROR_INVALID_PARAMETER );

    TCompletionCode retVal = CC_OK;

    if( *semaphore == NULL )
    {
        if( SemaphoreCreate( name, semaphore ) != CC_OK )
        {
            MD_LOG( LOG_ERROR, "Creating semaphore failed" );
            return CC_ERROR_GENERAL;
        }
    }

    TSemaphoreWaitResult result = SemaphoreWait( 1000L, *semaphore ); // Wait 1 sec
    switch( result )
    {
        case WAIT_RESULT_SUCCESSFUL: // The semaphore object was signaled
            retVal = CC_OK;
            break;

        case WAIT_RESULT_TIMEOUT: // A time-out occurred
            retVal = CC_CONCURRENT_GROUP_LOCKED;
            MD_LOG( LOG_DEBUG, "Concurrent group locked" );
            break;

        default:
            retVal = CC_ERROR_GENERAL;
            break;
    }

    return retVal;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    UnlockConcurrentGroup

Description:
    Unlocks concurrent group of given name.
    ! On Linux name isn't used, only semaphore pointer. !

Input:
    const char*     name        - name of the ConcurrentGroup
    void**          semaphore   - (IN/OUT) pointer to the semaphore

Output:
    TCompletionCode             - *CC_OK* means succeess

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::UnlockConcurrentGroup( const char* name, void** semaphore )
{
    MD_CHECK_PTR_RET( semaphore, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( *semaphore, CC_ERROR_INVALID_PARAMETER );

    if( SemaphoreRelease( semaphore ) != CC_OK )
    {
        MD_LOG(LOG_ERROR, "ERROR: Releasing semaphore failed");
        return CC_ERROR_GENERAL;
    }

    return CC_OK;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    OpenIoStream

Description:
    Enables Timer Mode and opens OA or Sys Counter Stream (IO Stream) .

Input:
    TStreamType     streamType          - stream type
    IMetricSet_1_0* metricSet           - metric set
    const char*     concurrentGroupName - concurrent group symbol name
    uint32_t        processId           - PID of the measured app (0 is global context)
    uint32_t*       nsTimerPeriod       - (IN/OUT) requested/set sampling period time in nanoseconds
    uint32_t*       bufferSize          - (IN/OUT) requested/set OA Buffer size in bytes
    void**          streamEventHandle   - *NOT USED ON ANDROID/LINUX*

Output:
    TCompletionCode                     - *CC_OK* means succeess

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::OpenIoStream( TStreamType streamType, CMetricSet* metricSet, const char* concurrentGroupName,
    uint32_t processId, uint32_t* nsTimerPeriod, uint32_t* bufferSize, void** streamEventHandle )
{
    if( streamType != STREAM_TYPE_OA )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }

    MD_CHECK_PTR_RET( metricSet, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( concurrentGroupName, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( nsTimerPeriod, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( bufferSize, CC_ERROR_INVALID_PARAMETER );

    // 1. ACTIVATE
    TCompletionCode ret = metricSet->ActivateInternal( false, false );
    MD_CHECK_CC_RET( ret );

    MD_ASSERT( m_PerfStreamConfigId == -1 );         // Should be -1, which means stream is closed

    // 2. SET PARAMS
    uint32_t    timerPeriodExponent = GetTimerPeriodExponent( *nsTimerPeriod );
    uint32_t    perfReportType      = I915_OA_FORMAT_A32u40_A4u32_B8_C8;
    int32_t     perfMetricSetId     = -1;
    uint32_t    regCount            = 0;
    TRegister** regVector           = metricSet->GetStartConfiguration( &regCount );

    if( metricSet->GetReportType() != OA_REPORT_TYPE_256B_A45_NOA16 )
    {
        ret = CC_ERROR_NOT_SUPPORTED;
        goto deactivate;
    }

    // 3. ADD HW CONFIG
    ret = AddPerfConfig( regVector, regCount, NULL, &perfMetricSetId );
    if( ret != CC_OK )
    {
        goto deactivate;
    }
    MD_ASSERT( perfMetricSetId != -1 );

    // 4. OPEN PERF STREAM
    ret = OpenPerfStream( perfMetricSetId, perfReportType, timerPeriodExponent );
    if( ret != CC_OK )
    {
        goto remove_config;
    }

    // 5. RETURN PARAMETERS
    *nsTimerPeriod = GetNsTimerPeriod(timerPeriodExponent);
    *bufferSize    = MD_PERF_OA_BUFFER_SIZE;                // OaBuffer size in Perf is constant and not configurable

    m_PerfStreamConfigId = perfMetricSetId;                 // Remember Perf config id so it could be removed from the kernel on CloseIoStream

    MD_LOG( LOG_DEBUG, "Perf stream opened with metricSetId: %d, periodNs: %u, exponent: %u", perfMetricSetId, *nsTimerPeriod, timerPeriodExponent );
    return CC_OK;

remove_config:
    RemovePerfConfig( perfMetricSetId );
deactivate:
    metricSet->Deactivate();
    return ret;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    ReadIoStream

Description:
    Reads data from previously opened OA/Sys IO Stream.

Input:
    TStreamType     streamType                  - stream type
    IMetricSet_1_0* metricSet                   - metricSet for which stream was opened
    char*           reportData                  - (OUT) pointer to the read data
    uint32_t*       reportsCount                - (IN/OUT) reports read/to read from the stream
    uint32_t        readFlags                   - read flags
    uint32_t*       frequency                   - (OUT) frquency from GTDIReadCounterStreamExtOut
    GTDIReadCounterStreamExceptions* exceptions - (OUT) exceptions from GTDIReadCounterStreamExtOut

Output:
    TCompletionCode - result of operation

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::ReadIoStream( TStreamType streamType, IMetricSet_1_0* metricSet, char* reportData,
    uint32_t* reportsCount, uint32_t readFlags, uint32_t* frequency, GTDIReadCounterStreamExceptions* exceptions )
{
    if( streamType != STREAM_TYPE_OA )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }

    MD_CHECK_PTR_RET( metricSet, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( reportData, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( reportsCount, CC_ERROR_INVALID_PARAMETER );

    uint32_t reportSize        = metricSet->GetParams()->RawReportSize;
    uint32_t bytesToRead       = (*reportsCount) * reportSize;
    uint32_t readBytes         = 0;
    bool     reportLostOccured = false;

    // Read flags are ignored for Perf
    TCompletionCode ret = ReadPerfStream( reportSize, *reportsCount, reportData, &readBytes, &reportLostOccured );
    if( ret == CC_OK )
    {
        MD_ASSERT( (readBytes % reportSize) == 0 );
        *reportsCount = readBytes / reportSize;

        if( readBytes < bytesToRead )
        {
            ret = CC_READ_PENDING;
        }

        // For MDAPI with Perf only ReportLost and Frequency during read are available
        if( exceptions )
        {
            uint64_t currentFrequency = 0;
            if( frequency && GetGpuFrequencyInfo( NULL, NULL, &currentFrequency, NULL ) == CC_OK)
            {
                *frequency = (uint32_t)currentFrequency / MD_MHERTZ;
            }

            exceptions->ReportLost = (uint32_t)reportLostOccured;
        }
    }

    return ret;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    CloseIoStream

Description:
    Closes OA/Sys Counter Stream (IO Stream) and disables Timer Mode.

Input:
    TStreamType streamType          - stream type
    void**      streamEventHandle   - *NOT USED ON ANDROID/LINUX*
    const char* concurrentGroupName - *NOT USED ON ANDROID/LINUX* concurrent group symbol name
    CMetricSet* metricSet           - metric set for which the stream was opened

Output:
    TCompletionCode                 - *CC_OK* means succeess

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::CloseIoStream( TStreamType streamType, void** streamEventHandle, const char* concurrentGroupName,
    CMetricSet* metricSet )
{
    if( streamType != STREAM_TYPE_OA )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }
    MD_CHECK_PTR_RET( metricSet, CC_ERROR_INVALID_PARAMETER );

    // 1. CLOSE STREAM
    ClosePerfStream();

    // 2. REMOVE HW CONFIG
    if( RemovePerfConfig( m_PerfStreamConfigId ) == CC_OK )
    {
        m_PerfStreamConfigId = -1;
    }

    // 3. DEACTIVATE
    TCompletionCode ret = metricSet->Deactivate();
    if( ret != CC_OK )
    {
        MD_ASSERT( false );
    }

    return ret;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    WaitForIoStreamReports

Description:
    Waits the given number of milliseconds for reports from IoStream.
    Returns *CC_OK* if wait was successful (data waiting in the buffer was signaled).

Input:
    TStreamType streamType        - stream type
    uint32_t    milliseconds      - max number of milliseconds to wait
    void*       streamEventHandle - *NOT USED ON ANDROID/LINUX*

Output:
    TCompletionCode                - *CC_OK* means succeess (reports available)

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::WaitForIoStreamReports( TStreamType streamType, uint32_t milliseconds, void* streamEventHandle )
{
    if( streamType != STREAM_TYPE_OA )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }

    return WaitForPerfStreamReports( milliseconds );
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    IsIoMeasurementInfoAvailable

Description:
    Returns true for IO measurement types which are available on this driver interface.

Input:
    TIoMeasurementInfoType ioMeasurementInfoType - IO measurement type to check

Output:
    bool                                         - *true* if available

\*****************************************************************************/
bool CDriverInterfaceLinuxPerf::IsIoMeasurementInfoAvailable( TIoMeasurementInfoType ioMeasurementInfoType )
{
    // Only ReportLost and Frequency during read available with Perf
    return ioMeasurementInfoType == IO_MEASUREMENT_INFO_REPORT_LOST ||
           ioMeasurementInfoType == IO_MEASUREMENT_INFO_CORE_FREQUENCY_MHZ;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    SetFrequencyOverride

Description:
    Enables / disables frequency override using CoreU function. Pid param is always
    ignored on Android - only global mode's supported.

Input:
    const TSetFrequencyOverrideParams_1_2* params - frequency override params

Output:
    TCompletionCode                               - *CC_OK* means succeess

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::SetFrequencyOverride( const TSetFrequencyOverrideParams_1_2* params )
{
    MD_CHECK_PTR_RET( params, CC_ERROR_INVALID_PARAMETER );
    if( params->Pid != 0 )
    {
        MD_LOG( LOG_WARNING, "Pid ignored, frequency override supported only in global mode (Pid = 0)" );
    }

    uint64_t minFrequency        = 0;
    uint64_t maxFrequency        = 0;
    uint64_t minFrequencyToSet   = 0;
    uint64_t maxFrequencyToSet   = 0;
    uint64_t boostFrequencyToSet = 0;

    // Boost frequency needs to be remembered at the beginning for disable
    static uint64_t boostFrequency    = 0;
    uint64_t*       boostFrequencyPtr = (boostFrequency) ? NULL : &boostFrequency;

    // 1. Read Min/Max and optional Boost frequency
    TCompletionCode ret = GetGpuFrequencyInfo( &minFrequency, &maxFrequency, NULL, boostFrequencyPtr );
    MD_CHECK_CC_RET( ret );

    MD_LOG( LOG_DEBUG, "MinFreq: %llu, MaxFreq: %llu, BoostFreq: %llu MHz", minFrequency, maxFrequency, boostFrequency );

    // 2. Decide frequency values to be set (e.g. check range)
    if( params->Enable )
    {
        if( params->FrequencyMhz == 0 )
        {
            MD_LOG( LOG_DEBUG, "Using MaxFrequency as a default value (%llu MHz)", maxFrequency );
            maxFrequencyToSet   = maxFrequency;
            minFrequencyToSet   = maxFrequency;
            boostFrequencyToSet = maxFrequency;
        }
        else if( params->FrequencyMhz >= minFrequency && params->FrequencyMhz <= maxFrequency )
        {
            MD_LOG( LOG_DEBUG, "Setting frequency to %u MHz", params->FrequencyMhz );
            maxFrequencyToSet   = params->FrequencyMhz;
            minFrequencyToSet   = params->FrequencyMhz;
            boostFrequencyToSet = params->FrequencyMhz;
        }
        else
        {
            MD_LOG( LOG_ERROR, "ERROR: Invalid frequency (%u MHz), should be in range [%llu, %llu]", params->FrequencyMhz, minFrequency, maxFrequency );
            ret = CC_ERROR_INVALID_PARAMETER;
        }
    }
    else
    {
        MD_LOG( LOG_DEBUG, "Disabling frequency override" );
        minFrequencyToSet   = minFrequency;
        maxFrequencyToSet   = maxFrequency;
        boostFrequencyToSet = boostFrequency;
    }

    // 3. Request frequency change (set frequency override)
    if( ret == CC_OK )
    {
        ret = WriteSysFsFile( MIN_FREQ_OV_FILE_NAME, minFrequencyToSet );
        MD_CHECK_CC_RET( ret );

        ret = WriteSysFsFile( MAX_FREQ_OV_FILE_NAME, maxFrequencyToSet );
        MD_CHECK_CC_RET( ret );

        // If boost frequency file available
        if( boostFrequency )
        {
            ret = WriteSysFsFile( BOOST_FREQ_OV_FILE_NAME, boostFrequencyToSet );
            MD_CHECK_CC_RET( ret );
        }
    }

    return ret;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    SetFreqChangeReportsOverride

Description:
    Allows to toggle frequency change reports.

Input:
    bool enable     - true to enable, false to disable

Output:
    TCompletionCode - result, *CC_OK* means success

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::SetFreqChangeReportsOverride( bool enable )
{
    return CC_ERROR_NOT_SUPPORTED;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    IsOverrideAvailable

Description:
    Returns true for overrides available through this driver interface.

Input:
    TOverrideType overrideType - override type to check

Output:
    bool                       - *true* if available

\*****************************************************************************/
bool CDriverInterfaceLinuxPerf::IsOverrideAvailable( TOverrideType overrideType )
{
    // Only Frequency Override is available with Perf
    return overrideType == OVERRIDE_TYPE_FREQUENCY;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    SetQueryOverride

Description:
    Enables/disables multisampled/extended query mode using escape code.

Input:
    TOverrideType overrideType                    - override type: extended/multisampled
    TPlatformType platform                        - platform type
    uint32_t      oaBufferSize                    - default Oa buffer size
    const TSetQueryOverrideParams_1_2* params     - query override params

Output:
    TCompletionCode                               - *CC_OK* means success

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::SetQueryOverride( TOverrideType overrideType, TPlatformType platform, uint32_t oaBufferSize, const TSetQueryOverrideParams_1_2* params )
{
    MD_CHECK_PTR_RET( params, CC_ERROR_INVALID_PARAMETER );
    return CC_ERROR_NOT_SUPPORTED;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    OpenPerfStream

Description:
    Sends IOCTL opening Perf stream. Output reports will include header and
    OA report part. OA configuration should be already added to kernel at this
    point.

Input:
    uint32_t perfMetricSetId     - Perf configuration ID (previously added)
    uint32_t perfReportType      - Perf report type
    uint32_t timerPeriodExponent - timer period exponent

Output:
    TCompletionCode                  - *CC_OK* means success

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::OpenPerfStream( uint32_t perfMetricSetId, uint32_t perfReportType, uint32_t timerPeriodExponent )
{
    int32_t  perfEventFd     = -1;
    int32_t  ring_id         = I915_EXEC_RENDER; /* RCS */
    uint64_t properties[]    = { DRM_I915_PERF_PROP_SAMPLE_OA,      true,
                                 DRM_I915_PERF_PROP_OA_METRICS_SET, perfMetricSetId,
                                 DRM_I915_PERF_PROP_OA_FORMAT,      perfReportType,
                                 DRM_I915_PERF_PROP_OA_EXPONENT,    timerPeriodExponent };
    struct drm_i915_perf_open_param param = {0,};

    param.flags = 0;
    param.flags |= I915_PERF_FLAG_FD_CLOEXEC;
    param.flags |= I915_PERF_FLAG_FD_NONBLOCK;    // We want a non-blocking read

    param.properties_ptr = (uint64_t)properties;
    param.num_properties = sizeof(properties) / 16;

    perfEventFd = SendIoctl( m_DrmFd, DRM_IOCTL_I915_PERF_OPEN, &param );
    if( perfEventFd == -1 )
    {
        MD_LOG( LOG_ERROR, "ERROR: opening i915 perf stream failed, fd: %d, errno: %s", perfEventFd, strerror(errno) );
        return CC_ERROR_GENERAL;
    }
    m_PerfStreamFd = perfEventFd;

    MD_LOG( LOG_DEBUG, "i915 perf stream opened successfully, fd: %d", m_PerfStreamFd );
    return CC_OK;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    ReadPerfStream

Description:
    Reads data from the previously opened Perf stream and copies only OA reports
    to the output buffer. If report lost header is obtained, reportLostOccured flag
    is set.

Input:
    uint32_t  oaReportSize      - size of a single OA report, currently always 256 bytes
    uint32_t  reportsToRead     - number of reports to read
    char*     reportData        - (OUT) buffer for reports
    uint32_t* readBytes         - (OUT) number of bytes read and copied to the output buffer
    bool*     reportLostOccured - (OUT) true if report lost was reported by Perf

Output:
    TCompletionCode                 - *CC_OK* means success, BUT IT DOESN'T MEAN ALL REQUESTED DATA WAS READ !!
                                      (check readBytes for that).

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::ReadPerfStream( uint32_t oaReportSize, uint32_t reportsToRead, char* reportData, uint32_t* readBytes, bool* reportLostOccured )
{
    if( m_PerfStreamFd < 0 )
    {
        MD_LOG( LOG_ERROR, "ERROR: Perf stream not opened" );
        return CC_ERROR_FILE_NOT_FOUND;
    }

    const size_t               outBufferSize   = oaReportSize * reportsToRead;
    const size_t               perfReportSize  = sizeof(drm_i915_perf_record_header) + oaReportSize;    // Perf report size is bigger (additional header)
    const size_t               perfBytesToRead = reportsToRead * perfReportSize;
    std::vector<unsigned char> perfReportData( perfBytesToRead );

    MD_LOG( LOG_DEBUG, "Trying to read %u reports from i915 perf stream, fd: %d", reportsToRead, m_PerfStreamFd );

    // #Note May read 1 sample less than requested if ReportLost is returned from kernel

    // 1. READ DATA
    int32_t perfReadBytes = read( m_PerfStreamFd, perfReportData.data(), perfBytesToRead );
    if( perfReadBytes < 0 )
    {
        *readBytes = 0;
        if( errno == EAGAIN )
        {
            MD_LOG( LOG_DEBUG, "i915 perf stream data not available yet" );
            return CC_OK;
        }
        MD_LOG( LOG_ERROR, "ERROR: Reading i915 stream failed, errno: %d (%s)", errno, strerror(errno) );
        return CC_ERROR_GENERAL;
    }
    MD_LOG( LOG_DEBUG, "Read %u perf bytes (= %lu reports), perfReportSize: %lu", perfReadBytes, perfReadBytes / perfReportSize, perfReportSize );

    // 2. PROCESS AND COPY DATA
    size_t bytesCopied    = 0;
    size_t perfDataOffset = 0;
    while( perfDataOffset < (size_t)perfReadBytes )
    {
        const iu_i915_perf_record* perfOaRecord = (const iu_i915_perf_record*) (perfReportData.data() + perfDataOffset);
        if( !perfOaRecord->header.size )
        {
            MD_LOG( LOG_ERROR, "ERROR: 0 header size" );
            return CC_ERROR_GENERAL;
        }
        perfDataOffset += perfOaRecord->header.size;

        switch( perfOaRecord->header.type )
        {
            case DRM_I915_PERF_RECORD_SAMPLE:
            {
                if( perfOaRecord->header.size != perfReportSize )
                {
                    MD_LOG( LOG_ERROR, "ERROR: Invalid record size" );
                    return CC_ERROR_GENERAL;
                }

                // In MDAPI usage model 'perfOaRecord->data' contains only raw OA report
                iu_memcpy_s( reportData + bytesCopied, outBufferSize - bytesCopied, perfOaRecord->data, oaReportSize );
                bytesCopied += oaReportSize;
                break;
            }

            case DRM_I915_PERF_RECORD_OA_REPORT_LOST:
            {
                MD_LOG( LOG_DEBUG, "OA report lost" );
                if( reportLostOccured )
                {
                    *reportLostOccured = true;
                }
                break;
            }

            case DRM_I915_PERF_RECORD_OA_BUFFER_LOST:
                MD_LOG( LOG_DEBUG, "OA buffer lost" );
                break;

            default:
                MD_LOG( LOG_ERROR, "ERROR: Unknown header type = %d", perfOaRecord->header.type );
        }
    }

    *readBytes = bytesCopied;
    return CC_OK;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    ClosePerfStream

Description:
    Closes previously opened Perf stream.

Output:
    TCompletionCode - *CC_OK* means success

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::ClosePerfStream()
{
    if( m_PerfStreamFd >= 0 )
    {
        MD_LOG( LOG_DEBUG, "Closing i915 perf stream, fd: %d", m_PerfStreamFd );
        close( m_PerfStreamFd );
        m_PerfStreamFd = -1;
    }
    return CC_OK;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    WaitForPerfStreamReports

Description:
    Wait for any data available in the previously opened Perf stream. Currently,
    it's not possible to wait for the half-buffer, so it's a DIFFERENT BEHAVIOUR THAN
    THE PREVIOUS IMPLEMENTATIONS.

Input:
    uint32_t timeoutMs - wait timeout in milliseconds

Output:
    TCompletionCode    - *CC_OK* means success

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::WaitForPerfStreamReports( uint32_t timeoutMs )
{
    TCompletionCode retVal = CC_OK;
    struct pollfd   pollParams;

    memset( &pollParams, 0, sizeof(pollParams) );

    pollParams.fd      = m_PerfStreamFd;
    pollParams.revents = 0;
    pollParams.events  = POLLIN;

    MD_LOG( LOG_DEBUG, "Waiting %d ms", timeoutMs );

    int32_t pollResult = poll( &pollParams, 1, timeoutMs );
    if( pollResult > 0 )
    {
        // OK, can read
        MD_LOG( LOG_DEBUG, "Poll successful" );
        retVal = CC_OK;
    }
    else if( pollResult == 0 )
    {
        MD_LOG( LOG_DEBUG, "Poll timeout" );
        retVal = CC_WAIT_TIMEOUT;
    }
    else if( /*ret < 0 && */ errno == EINTR )
    {
        MD_LOG( LOG_DEBUG, "Poll interrupted" );
        retVal = MetricsDiscovery::CC_INTERRUPTED;
    }
    else
    {
        MD_LOG( LOG_ERROR, "ERROR: Poll failed" );
        retVal = CC_ERROR_GENERAL;
    }

    return retVal;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    AddPerfConfig

Description:
    Adds OA configuration to the kernel through Perf interface. If no GUID passed
    in parameter, GUID of the added configuration is calculated based on concatenated
    register offsets and values string.
    When the same configuration is already added, its ID is reused (configuration isn't
    send for the second time).

Input:
    TRegister** regVector     - array of pointers to registers to send (add)
    uint32_t    regCount      - register count
    const char* requestedGuid - [optional] GUID under which configuration will be added, if NULL GUID will be generated
    int32_t*    addedConfigId - (OUT) added Perf configuration ID, -1 if error

Output:
    TCompletionCode            - *CC_OK* means success

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::AddPerfConfig( TRegister** regVector, uint32_t regCount, const char* requestedGuid,  int32_t* addedConfigId )
{
    MD_LOG_ENTER();
    MD_CHECK_PTR_RET( regVector, CC_ERROR_INVALID_PARAMETER );
    if( !regCount )
    {
        MD_LOG( LOG_ERROR, "ERROR: Empty configuration" );
        return CC_ERROR_GENERAL;
    }

    TCompletionCode                           ret  = CC_OK;
    const char*                               guid = requestedGuid;
    std::vector<iu_i915_perf_config_register> noaRegisters;
    std::vector<iu_i915_perf_config_register> flexRegisters;
    std::vector<iu_i915_perf_config_register> oaRegisters;
    std::string                               regsString;    // For hash (guid)

    // 1. TRANSFORM CONFIG TO PERF FORMAT
    MD_LOG( LOG_DEBUG, "AddPerfConfig regCount: %u", regCount );
    for( uint32_t i = 0; i < regCount; i++ )
    {
        if( regVector[i] )
        {
            auto& registers = regVector[i]->type == REGISTER_TYPE_FLEX ? flexRegisters
                             : (regVector[i]->type == REGISTER_TYPE_OA ? oaRegisters
                                                                       : noaRegisters);
            registers.push_back( {regVector[i]->offset, regVector[i]->value} );
            if( !guid )
            {
                regsString += regVector[i]->offset;
                regsString += regVector[i]->value;
            }
            MD_LOG( LOG_DEBUG, "regOffset: %#x, regValue: %#x", regVector[i]->offset, regVector[i]->value );
        }
    }

    // 2. GENERATE CONFIG GUID (if needed) - string formatted like "%08x-%04x-%04x-%04x-%012x"
    char generatedGuid[MD_PERF_GUID_LENGTH];
    if( !guid )
    {
        std::hash<std::string> stringHash;

        // Use std::hash for GUID generation
        snprintf( generatedGuid, sizeof(generatedGuid), "%08x-%04x-%04x-%04x-%012x", 0, 0, 0, 0, (uint32_t)stringHash(regsString) );
        guid = generatedGuid;
    }

    MD_LOG( LOG_DEBUG, "Adding configuration under guid: %s", guid );

    // 3. SET PARAMS
    struct drm_i915_perf_oa_config param = {0,};

    static_assert( sizeof(param.uuid) == (MD_PERF_GUID_LENGTH - 1), "GUID length mismatch with i915 Perf API" );
    iu_memcpy_s( param.uuid, sizeof(param.uuid), guid, MD_PERF_GUID_LENGTH - 1 );   // Copy without ending '\0' (size 36)

    param.boolean_regs_ptr = (uint64_t)oaRegisters.data();
    param.mux_regs_ptr     = (uint64_t)noaRegisters.data();
    param.flex_regs_ptr    = (uint64_t)flexRegisters.data();

    param.n_boolean_regs   = (uint32_t)oaRegisters.size();
    param.n_mux_regs       = (uint32_t)noaRegisters.size();
    param.n_flex_regs      = (uint32_t)flexRegisters.size();

    // 4. ADD CONFIG TO PERF
    *addedConfigId = SendIoctl( m_DrmFd, DRM_IOCTL_I915_PERF_ADD_CONFIG, &param );
    if( *addedConfigId == -1 )
    {
        if( errno != EADDRINUSE ) // errno == 98 (EADDRINUSE) means set with the given GUID is already added
        {
            MD_LOG( LOG_ERROR, "ERROR: Adding i915 perf configuration failed, errno: %s (%u)", strerror(errno), errno );
            ret = CC_ERROR_GENERAL;
        }
        else
        {
            MD_LOG( LOG_DEBUG, "Configuration with the given GUID already added, reusing" );
            ret = GetPerfMetricSetId( guid, (uint32_t*)addedConfigId );
        }
    }

    if( ret == CC_OK )
    {
        MD_LOG( LOG_DEBUG, "i915 perf configuration added/reused, id: %d", *addedConfigId );
    }

    MD_LOG_EXIT();
    return ret;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    RemovePerfConfig

Description:
    Removes from i915 Perf previously added OA config based on its ID.

    Note from i915: "Configs can be removed while being used, the will stop appearing in SysFs
                     and their content will be freed when the stream using the config is closed."

Input:
    int32_t perfConfigId - valid Perf configuration ID (previously added)

Output:
    TCompletionCode  - *CC_OK* means success

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::RemovePerfConfig( int32_t perfConfigId )
{
    TCompletionCode ret = CC_OK;

    // Note from i915: "Configs can be removed while being used, the will stop appearing in SysFs
    //                  and their content will be freed when the stream using the config is closed."

    if( perfConfigId != -1 )
    {
        MD_LOG( LOG_DEBUG, "Removing perf configuration with id: %d", perfConfigId );

        uint64_t perfConfigId64 = (uint64_t)perfConfigId;
        int32_t ioctlResult = SendIoctl( m_DrmFd, DRM_IOCTL_I915_PERF_REMOVE_CONFIG, &perfConfigId64 );
        if( ioctlResult )
        {
            if( errno != ENOENT ) // errno == 2 (ENOENT) means set with the given ID doesn't exist
            {
                MD_LOG( LOG_ERROR, "ERROR: Removing perf configuration with id %d failed, config not found", perfConfigId );;
            }
            else
            {
                MD_LOG( LOG_ERROR, "ERROR: Removing perf configuration with id %d failed, errno: %s (%u)", perfConfigId, strerror( errno ), errno );
            }
            ret = CC_ERROR_GENERAL;
        }
        else
        {
            MD_LOG( LOG_DEBUG, "Perf configuration with id %d removed", perfConfigId );
        }
    }

    return ret;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    RemovePerfConfigQuery

Description:
    Removes OA config previously added under MD_PERF_GUID_FOR_QUERY from i915 Perf (if exists).
    Query Perf config has to be removed e.g. in case when measuring different sets or previous execution crash.

Output:
    TCompletionCode - *CC_OK* means success

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::RemovePerfConfigQuery()
{
    if( !PerfMetricSetExists( MD_PERF_GUID_FOR_QUERY ) )
    {
        MD_LOG( LOG_DEBUG, "Perf configuration with query guid doesn't exist" );
        return CC_OK;
    }

    int32_t existingConfigId = -1;

    TCompletionCode ret = GetPerfMetricSetId( MD_PERF_GUID_FOR_QUERY, (uint32_t*)&existingConfigId );
    if( ret == CC_OK )
    {
        MD_LOG( LOG_DEBUG, "Removing perf config with query guid: %s, id: %d", MD_PERF_GUID_FOR_QUERY, existingConfigId );

        ret = RemovePerfConfig( existingConfigId );
        if( ret == CC_OK )
        {
            // Remove from remembered Perf configs
            m_AddedPerfConfigs.erase( std::remove( m_AddedPerfConfigs.begin(), m_AddedPerfConfigs.end(), existingConfigId ), m_AddedPerfConfigs.end() );
        }
        else
        {
            MD_LOG( LOG_WARNING, "WARNING: Removing perf configuration with query guid failed, id: %d", existingConfigId );
        }
        existingConfigId = -1;
    }

    return ret;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    GetPerfMetricSetId

Description:
    Returns Perf metric set ID (configuration ID) for the configuration with the
    given GUID.

Input:
    const char* guid            - GUID for which to read configuration ID
    uint32_t*   perfMetricSetId - (OUT) Perf configuration ID, not changed if error

Output:
    TCompletionCode               - *CC_OK* means success

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::GetPerfMetricSetId( const char* guid, uint32_t* perfMetricSetId )
{
    MD_ASSERT( m_DrmCardNumber >= 0 );

    char     filePath[MD_MAX_PATH_LENGTH];
    uint64_t metricSetId = -1;

    // Read Perf metric set ID based on GUID
    snprintf( filePath, sizeof(filePath), "/sys/class/drm/card%d/metrics/%s/id", m_DrmCardNumber, guid );

    TCompletionCode ret = ReadUInt64FromFile( filePath, &metricSetId );
    MD_CHECK_CC_RET( ret );
    if( !metricSetId )
    {
        MD_LOG( LOG_ERROR, "ERROR: Invalid perf config id read from %s", filePath );
        return CC_ERROR_GENERAL;
    }

    *perfMetricSetId = (uint32_t)metricSetId;
    return CC_OK;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    PerfMetricSetExists

Description:
    Returns true if Perf has configuration with the given GUID.

Input:
    const char* guid - GUID for which to read configuration ID

Output:
    bool             - true if exists, false otherwise

\*****************************************************************************/
bool CDriverInterfaceLinuxPerf::PerfMetricSetExists( const char* guid )
{
    MD_ASSERT( m_DrmCardNumber >= 0 );

    char filePath[MD_MAX_PATH_LENGTH];

    // Read Perf metric set ID path based on GUID
    snprintf( filePath, sizeof(filePath), "/sys/class/drm/card%d/metrics/%s/id", m_DrmCardNumber, guid );

    // Check whether the file exists (F_OK)
    return (access( filePath, F_OK ) != -1);
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    InitializeIntelDrm

Description:
    Initializes Intel DRM using libdrm. Reads also DRM card number for the later
    use, based on just opened DRM file descriptor.

Output:
    bool - *true* if success

\*****************************************************************************/
bool CDriverInterfaceLinuxPerf::InitializeIntelDrm()
{
    if( m_DrmFd >= 0 )
    {
        MD_LOG( LOG_DEBUG, "DRM already initalized, reusing" );
        return true;
    }
    MD_ASSERT( m_DrmFd == -1 );
    MD_ASSERT( m_DrmCardNumber == -1 );

    m_DrmFd = OpenIntelDrm();
    if( m_DrmFd < 0 )
    {
        MD_LOG( LOG_ERROR, "ERROR: Failed to open render node" );
        return false;
    }

    m_DrmCardNumber = GetDrmCardNumber( m_DrmFd );
    if( m_DrmCardNumber < 0 )
    {
        DeinitializeIntelDrm();
        MD_LOG( LOG_ERROR, "ERROR: Failed to get DRM card info" );
        return false;
    }

    MD_LOG( LOG_DEBUG, "DRM initalized successfully" );
    return true;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    DeinitializeIntelDrm

Description:
    Deinitializes previously initialized DRM interface.

\*****************************************************************************/
void CDriverInterfaceLinuxPerf::DeinitializeIntelDrm()
{
    if( m_DrmFd >= 0 )
    {
        CloseIntelDrm( m_DrmFd );
        m_DrmFd = -1;
    }
    m_DrmCardNumber = -1;
    MD_LOG( LOG_DEBUG, "DRM deinitialized" );
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    OpenIntelDrm

Description:
    Opens DRM connection.
    Based on skuwa's openDrm().

Output:
    int32_t - the DRM file descriptor on success, negative errno value on failure

\*****************************************************************************/
int32_t CDriverInterfaceLinuxPerf::OpenIntelDrm()
{
    int32_t fd = drmOpenWithType( "i915", NULL, DRM_NODE_RENDER );
    if( fd < 0 )
    {
        fd = drmOpenWithType( "i915", NULL, DRM_NODE_PRIMARY );
    }

    if( fd < 0 )
    {
        int32_t status = -errno;
        MD_LOG( LOG_ERROR, "ERROR: Failure opening drm device, status = %d", status );
        return status;
    }

    MD_LOG( LOG_DEBUG, "Drm device opened, fd = %d", fd );
    return fd;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    CloseIntelDrm

Description:
    Closes DRM connection.
    Based on skuwa's closeDrm().

Input:
    int32_t drmFd - DRM file descriptor

\*****************************************************************************/
void CDriverInterfaceLinuxPerf::CloseIntelDrm( int32_t drmFd )
{
    drmClose( drmFd );
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    GetDrmCardNumber

Description:
    Returns DRM card number used for e.g. SysFs reads/writes.
    Based on GpuTop get_card_for_fd().

Input:
    int32_t drmFd - valid DRM file descriptor

Output:
    int32_t       - DRM card number or -1 on error

\*****************************************************************************/
int32_t CDriverInterfaceLinuxPerf::GetDrmCardNumber( int32_t drmFd )
{
    struct stat fileInfo;
    if( fstat( drmFd, &fileInfo ) )
    {
        MD_LOG( LOG_ERROR, "ERROR: Failed to stat DRM fd" );
        return -1;
    }

    int32_t majorNumber = major( fileInfo.st_rdev );
    int32_t minorNumber = minor( fileInfo.st_rdev );

    char drmDirPath[MD_MAX_PATH_LENGTH] = {0,};
    snprintf( drmDirPath, sizeof(drmDirPath), "/sys/dev/char/%d:%d/device/drm", majorNumber, minorNumber );

    DIR* drmDir = opendir( drmDirPath );
    MD_CHECK_PTR_RET( drmDir, -1 );

    dirent* entry         = NULL;
    int32_t retCardNumber = -1;
    while( (entry = readdir( drmDir )) != NULL )
    {
        // If it's a directory named 'card.*'
        if( entry->d_type == DT_DIR && strncmp( entry->d_name, "card", 4 ) == 0 )
        {
            retCardNumber = strtoull( entry->d_name + 4, NULL, 10 );
            MD_LOG(LOG_DEBUG, "DRM card number: %d", retCardNumber);
            break;
        }
    }
    closedir( drmDir );

    return retCardNumber;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    ReadSysFsFile

Description:
    Reads a 64-bit unsigned value from the given SysFs file. SysFs path is
    based on DRM card number.

Input:
    const char* fileName  - name of SysFs file to read
    uint64_t*   readValue - (OUT) read value (content of the file)

Output:
    TCompletionCode       - *CC_OK* means success

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::ReadSysFsFile( const char* fileName, uint64_t* readValue )
{
    MD_CHECK_PTR_RET( fileName, CC_ERROR_INVALID_PARAMETER );
    MD_ASSERT( m_DrmCardNumber >= 0 );

    char filePath[MD_MAX_PATH_LENGTH] = {0,};
    snprintf( filePath, sizeof(filePath), "/sys/class/drm/card%d/%s", m_DrmCardNumber, fileName );

    return ReadUInt64FromFile( filePath, readValue );
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    WriteSysFsFile

Description:
    Writes a 64-bit unsigned value the the given SysFs file. SysFs path is
    based on DRM card number.

Input:
    const char* fileName - name of SysFs file to write
    uint64_t    value    - value to write

Output:
    TCompletionCode      - *CC_OK* means success

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::WriteSysFsFile( const char* fileName, uint64_t value )
{
    MD_CHECK_PTR_RET( fileName, CC_ERROR_INVALID_PARAMETER );
    MD_ASSERT( m_DrmCardNumber >= 0 );

    char filePath[MD_MAX_PATH_LENGTH] = {0,};
    snprintf( filePath, sizeof(filePath), "/sys/class/drm/card%d/%s", m_DrmCardNumber, fileName );

    return WriteUInt64ToFile( filePath, value );
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    ReadUInt64FromFile

Description:
    Reads 64-bit unsigned value from the given file.
    Based on GpuTop read_file_uint64().

Input:
    const char* filePath  - file to read the value from
    uint64_t*   readValue - (OUT) read value, not changed in case of error.

Output:
    TCompletionCode       - *CC_OK* means success

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::ReadUInt64FromFile( const char* filePath, uint64_t* readValue )
{
    MD_CHECK_PTR_RET( filePath, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( readValue, CC_ERROR_INVALID_PARAMETER );

    char buffer[32] = {0,};

    int32_t fd = open( filePath, O_RDONLY );
    if( fd < 0 )
    {
        MD_LOG( LOG_ERROR, "ERROR: Failed to open %s, error: %d (%s)", filePath, errno, strerror(errno) );
        return CC_ERROR_FILE_NOT_FOUND;
    }

    int32_t readBytes = read( fd, buffer, sizeof(buffer) - 1 );
    close(fd);

    if( readBytes < 0 )
    {
        MD_LOG( LOG_ERROR, "ERROR: Read negative number of bytes, error %s", strerror(errno) );
        return CC_ERROR_GENERAL;
    }

    buffer[readBytes] = '\0';
    *readValue        = strtoull( buffer, 0, 0 );

    return CC_OK;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    WriteUInt64ToFile

Description:
    Writes 64-bit unsigned value to the given file.
    Based on GpuTop read_file_uint64().

Input:
    const char* filePath - file to write the value
    uint64_t    value    - value to write

Output:
    TCompletionCode      - *CC_OK* means success

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::WriteUInt64ToFile( const char* filePath, uint64_t value )
{
    MD_CHECK_PTR_RET( filePath, CC_ERROR_INVALID_PARAMETER );

    char buffer[32] = {0,};

    int32_t length = snprintf( buffer, sizeof(buffer), "%" PRIu64, value );     // Note: length does not contain null-terminating character
    if( length >= (int)sizeof(buffer) || length <= 0 )
    {
        MD_LOG( LOG_ERROR, "ERROR: Failed to convert value to string" );
        return CC_ERROR_GENERAL;
    }

    int32_t fd = open( filePath, O_WRONLY );
    if( fd < 0 )
    {
        MD_LOG( LOG_ERROR, "ERROR: Failed to open %s, error: %d (%s)", filePath, errno, strerror(errno) );
        return CC_ERROR_FILE_NOT_FOUND;
    }

    int32_t writeBytes = write( fd, buffer, length + 1 );
    close( fd );

    if( writeBytes < length )
    {
        MD_LOG( LOG_ERROR, "ERROR: Failed to write %s, error: %d (%s)", filePath, errno, strerror( errno ) );
        return CC_ERROR_GENERAL;
    }

    return CC_OK;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    SendIoctl

Description:
    Sends the given IOCTL to the DRM represented by its file descriptor. Uses libdrm.

Input:
    int32_t  drmFd    - DRM file descriptor
    uint32_t request  - DRM IOCTL type
    void*    argument - IOCTL params

Output:
    int32_t                - interpretation depends on IOCTL, -1 if error and errno set appropriately

\*****************************************************************************/
int32_t CDriverInterfaceLinuxPerf::SendIoctl( int32_t drmFd, uint32_t request, void* argument )
{
    return drmIoctl( drmFd, request, argument );
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    SendGetParamIoctl

Description:
    Sends DRM_IOCTL_I915_GETPARAM IOCTL to obtain value of the given parameter.
    Returned value is always 32-bit integer.

Input:
    int32_t                 drmFd    - DRM file descriptor
    uint32_t                paramId  - parameter to get through i915 GetParam IOCTL
    GTDIDeviceInfoParamOut* outValue - (OUT) output value

Output:
    TCompletionCode                  - *CC_OK* means success

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::SendGetParamIoctl( int32_t drmFd, uint32_t paramId, GTDIDeviceInfoParamOut* outValue )
{
    MD_CHECK_PTR_RET( outValue, CC_ERROR_INVALID_PARAMETER );

    // GET_PARAM IOCTLs always return integers
    int32_t paramValue = 0;

    TCompletionCode ret = SendGetParamIoctl( drmFd, paramId, &paramValue );
    if( ret == CC_OK )
    {
        outValue->ValueUint32 = paramValue;
        outValue->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
    }
    return ret;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    SendGetParamIoctl

Description:
    Sends DRM_IOCTL_I915_GETPARAM IOCTL to obtain value of the given parameter.
    Returned value is always 32-bit integer.

Input:
    int32_t  drmFd    - DRM file descriptor
    uint32_t paramId  - parameter to get through i915 GetParam IOCTL
    int32_t* outValue - (OUT) output value

Output:
    TCompletionCode   - *CC_OK* means success

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::SendGetParamIoctl( int32_t drmFd, uint32_t paramId, int32_t* outValue )
{
    MD_CHECK_PTR_RET( outValue, CC_ERROR_INVALID_PARAMETER );

    drm_i915_getparam_t params = {0,};
    params.param = paramId;
    params.value = outValue;

    int32_t ioctlRet = SendIoctl( drmFd, DRM_IOCTL_I915_GETPARAM, &params );
    if( ioctlRet )
    {
        MD_LOG( LOG_WARNING, "ERROR: Failed to send GET_PARAM ioctl, paramId: %u, errno: %d (%s)", paramId, errno, strerror(errno) );
        return CC_ERROR_GENERAL;
    }

    return CC_OK;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    GetMesaDeviceInfo

Description:
    Returns Mesa device info structure, based on DeviceId read from kernel.
    Mesa device info is used for e.g. ChipsetId and Platform matching or
    getting timestamp frequency.
    Struct is obtained only once and cached for later use.

    Files containing Mesa device info are compiled into MDAPI - Mesa doesn't
    have any interface allowing querying this information.

Input:
    const gen_device_info** mesaDeviceInfo - (OUT) Mesa device info structure

Output:
    TCompletionCode                        - *CC_OK* means success

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::GetMesaDeviceInfo( const gen_device_info** mesaDeviceInfo )
{
    static bool            isMesaDeviceInfoCached = false;
    static gen_device_info cachedMesaDeviceInfo   = {0,};
    int32_t                deviceId               = -1;

    // 1. Get DeviceId
    TCompletionCode ret = GetDeviceId( &deviceId );
    MD_CHECK_CC_RET( ret );

    // 2. Get MesaDeviceInfo if not cached already
    if( !isMesaDeviceInfoCached )
    {
        if( !gen_get_device_info( deviceId, &cachedMesaDeviceInfo ) )
        {
            MD_LOG( LOG_ERROR, "ERROR: DeviceId not supported" );
            return CC_ERROR_NOT_SUPPORTED;
        }
        isMesaDeviceInfoCached = true;
    }

    *mesaDeviceInfo = &cachedMesaDeviceInfo;
    return CC_OK;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    GetChipsetId

Description:
    Returns DeviceId (ChipsetId) obtained from kernel using i915_GETPARAM IOCTL.

Input:
    int32_t* deviceId - (OUT) returned DeviceId

Output:
    TCompletionCode   - *CC_OK* means success

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::GetDeviceId( int32_t* deviceId )
{
    MD_CHECK_PTR_RET( deviceId, CC_ERROR_INVALID_PARAMETER );
    TCompletionCode ret = CC_OK;

    static int32_t cachedDeviceId = -1;
    if( cachedDeviceId == -1 )
    {
        ret = SendGetParamIoctl( m_DrmFd, I915_PARAM_CHIPSET_ID, &cachedDeviceId );
        if( ret != CC_OK )
        {
            cachedDeviceId = -1;
            return ret;
        }
    }

    *deviceId = cachedDeviceId;
    return ret;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    GetInstrPlatformId

Description:
    Returns current platform ID in instrumentation format.

Input:
    GTDI_PLATFORM_INDEX* instrPlatformId - (OUT) platform ID in instrumentation format

Output:
    TCompletionCode                      - *CC_OK* means success

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::GetInstrPlatformId( GTDI_PLATFORM_INDEX* instrPlatformId )
{
    MD_CHECK_PTR_RET( instrPlatformId, CC_ERROR_INVALID_PARAMETER );

    const gen_device_info* mesaDeviceInfo = NULL;

    TCompletionCode ret = GetMesaDeviceInfo( &mesaDeviceInfo );
    MD_CHECK_CC_RET( ret );

    ret = MapMesaToInstrPlatform( mesaDeviceInfo, instrPlatformId );
    MD_CHECK_CC_RET( ret );

    return CC_OK;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    GetGpuFrequencyInfo

Description:
    Reads GPU frequency info from the SysFs files. Minimum and maximum frequencies
    are cached (they don't change).

Input:
    uint64_t* minFrequency   - (OUT) in MHz
    uint64_t* maxFrequency   - (OUT) in MHz
    uint64_t* actFrequency   - (OUT) in Hz to preserve compatibility with other MDAPI driver interfaces
    uint64_t* boostFrequency - (OUT) in Mhz

Output:
    TCompletionCode          - *CC_OK* means success

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::GetGpuFrequencyInfo( uint64_t* minFrequency, uint64_t* maxFrequency, uint64_t* actFrequency,
    uint64_t* boostFrequency )
{
    TCompletionCode ret = CC_ERROR_GENERAL;     // Error if all parameters NULL

    // Read minimum frequency
    if( minFrequency )
    {
        static uint64_t cachedMinFrequency = 0;
        if( !cachedMinFrequency )
        {
            ret = ReadSysFsFile( MIN_FREQ_FILE_NAME, &cachedMinFrequency);
            MD_CHECK_CC_RET( ret );
        }

        *minFrequency = cachedMinFrequency;
        ret = CC_OK;
    }

    // Read maximum frequency
    if( maxFrequency )
    {
        static uint64_t cachedMaxFrequency = 0;
        if( !cachedMaxFrequency )
        {
            ret = ReadSysFsFile( MAX_FREQ_FILE_NAME, &cachedMaxFrequency );
            MD_CHECK_CC_RET( ret );
        }

        *maxFrequency = cachedMaxFrequency;
        ret = CC_OK;
    }

    // Read actual frequency
    if( actFrequency )
    {
        uint64_t actFrequencyMhz = 0;

        // Using act ('actual') frequency file, curr ('current') freq file may show
        // frequency requested by the driver not the actual GPU frequency.
        ret = ReadSysFsFile( ACT_FREQ_FILE_NAME, &actFrequencyMhz );
        MD_CHECK_CC_RET( ret );

        // Convert reading to Hz (for compatibility with the other MDAPI driver interfaces)
        *actFrequency = actFrequencyMhz * MD_MHERTZ;
    }

    // Read boost frequency [optional]
    if( boostFrequency )
    {
        uint64_t boostFrequencyMhz = 0;

        TCompletionCode readBoostFreqRet = ReadSysFsFile( BOOST_FREQ_OV_FILE_NAME, &boostFrequencyMhz );
        if( readBoostFreqRet != CC_OK )
        {
            // No error return on purpose, it's expected on older kernels
            MD_LOG( LOG_WARNING, "WARNING: Reading BoostGpuFrequency file failed" );
        }
        else
        {
            *boostFrequency = boostFrequencyMhz;
            ret = CC_OK;
        }
    }

    return ret;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    GetGpuTimestampFrequency

Description:
    Returns GPU timestamp frequency based on Mesa device info (which uses DeviceId).

Input:
    uint64_t* gpuTimestampFrequency - (OUT) GPU Timestamp frequency in Hz

Output:
    TCompletionCode                 - *CC_OK* means success

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::GetGpuTimestampFrequency( uint64_t* gpuTimestampFrequency )
{
    MD_CHECK_PTR_RET( gpuTimestampFrequency, CC_ERROR_INVALID_PARAMETER );
    const gen_device_info* mesaDeviceInfo = NULL;

    // 1. Get MesaDeviceInfo
    TCompletionCode ret = GetMesaDeviceInfo( &mesaDeviceInfo );
    MD_CHECK_CC_RET( ret );

    // 2. Copy TimestampFrequency to the output
    if( mesaDeviceInfo->timestamp_frequency )
    {
        *gpuTimestampFrequency = mesaDeviceInfo->timestamp_frequency;
    }
    else
    {
        MD_LOG( LOG_WARNING, "WARNING: 0 GPU Timestamp Frequency, default value used" );
        *gpuTimestampFrequency = MD_DEFAULT_GPU_TIMESTAMP_FREQUENCY;
    }

    return CC_OK;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    GetGpuTimestampPeriodNs

Description:
    Returns minimum GPU timestamp period is nanoseconds based on GPU timestamp
    frequency.

Input:
    uint64_t* gpuTimestampPeriodNs - (OUT) GPU timestamp period in ns

Output:
    TCompletionCode                - *CC_OK* means success

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::GetGpuTimestampPeriodNs( uint64_t* gpuTimestampPeriodNs )
{
    MD_CHECK_PTR_RET( gpuTimestampPeriodNs, CC_ERROR_INVALID_PARAMETER );

    // 1. Get GpuTimestamFrequency
    uint64_t gpuTimestampFrequency = 0;
    TCompletionCode ret = GetGpuTimestampFrequency( &gpuTimestampFrequency );
    MD_CHECK_CC_RET( ret );

    MD_ASSERT( gpuTimestampFrequency != 0 );

    // 2. Transform Hz to period (ns)
    *gpuTimestampPeriodNs = MD_NSEC_PER_SEC / gpuTimestampFrequency;
    return CC_OK;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    GetGpuTimestampNs

Description:
    Reads GPU timestamp in nanoseconds. It uses GPU timestamp in ticks and
    GPU timestamp frequency to get the timestamp in ns.

    !! Timestamp in nanoseconds is masked to (currently) 32-bits to match
       OA report timestamps !!

Input:
    uint64_t* gpuTimestampNs - (OUT) GPU timestamp in nanoseconds

Output:
    TCompletionCode          - *CC_OK* means success

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::GetGpuTimestampNs( uint64_t* gpuTimestampNs )
{
    MD_CHECK_PTR_RET( gpuTimestampNs, CC_ERROR_INVALID_PARAMETER );

    // 1. Get GpuTimestamFrequency
    uint64_t gpuTimestampFrequency = 0;
    TCompletionCode ret = GetGpuTimestampFrequency( &gpuTimestampFrequency );
    MD_CHECK_CC_RET( ret );

    MD_ASSERT( gpuTimestampFrequency != 0 );

    // 2. Get GpuTimestampTicks
    uint64_t gpuTimestampTicks = 0;
    ret = GetGpuTimestampTicks( &gpuTimestampTicks );
    MD_CHECK_CC_RET( ret );

    // 3. Convert GpuTimestamp to ns
    //    ! Ticks masked to 32bit to get sync with report timestamps !
    *gpuTimestampNs = (gpuTimestampTicks & MD_GPU_TIMESTAMP_MASK) * MD_SECOND_IN_NS / gpuTimestampFrequency;

    return CC_OK;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    GetGpuTimestampTicks

Description:
    Reads GPU timestamp in ticks from GPU timestamp register through REG_READ
    IOCTL.

Input:
    uint64_t* gpuTimestampTicks - (OUT) GPU timestamp in ticks

Output:
    TCompletionCode             - *CC_OK* means success

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::GetGpuTimestampTicks( uint64_t* gpuTimestampTicks )
{
    MD_CHECK_PTR_RET( gpuTimestampTicks, CC_ERROR_INVALID_PARAMETER );

    struct drm_i915_reg_read regReadParams = {0,};
    regReadParams.offset = MD_TIMESTAMP_LOW_OFFSET | 1; // '| 1' to read low and high part separately. This is how kernel handles
                                                        // flags in REG_READ (kind of hack) - registers are naturally aligned so there's place for flags.

    int32_t ioctlRet = SendIoctl( m_DrmFd, DRM_IOCTL_I915_REG_READ, &regReadParams );
    if( ioctlRet )
    {
        MD_LOG( LOG_WARNING, "ERROR: Failed to send DRM_IOCTL_I915_REG_READ ioctl" );
        return CC_ERROR_GENERAL;
    }

    *gpuTimestampTicks = regReadParams.val;
    return CC_OK;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    GetCpuTimestampNs

Description:
    Returns the CPU timestamp in nanoseconds, based on clock monotonic or
    std::chrono (depending on OS).
    Based on iStdLib's GetTimestampCounter().

Input:
    uint64_t* cpuTimestampNs - (OUT) CPU timestamp in nanoseconds

Output:
    TCompletionCode          - *CC_OK* means success

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::GetCpuTimestampNs( uint64_t* cpuTimestampNs )
{
    MD_CHECK_PTR_RET( cpuTimestampNs, CC_ERROR_INVALID_PARAMETER );

    struct timespec time;
    if( clock_gettime( CLOCK_MONOTONIC, &time ) )
    {
        return CC_ERROR_GENERAL;
    }
    *cpuTimestampNs = (uint64_t)time.tv_nsec + (uint64_t)time.tv_sec * (uint64_t)MD_NSEC_PER_SEC;

    return CC_OK;
}

/*****************************************************************************\

Class:
  CDriverInterfaceLinuxPerf

Method:
    GetGtMaxSubslicePerSlice

Description:
    Returns information about active subslices on GPU. For platforms <= SKL subslice size '3'
    is used to preserve backward compatibility with MDAPI metric equation definitions
    Based on __InstrGetGtMaxSubslicePerSlice().

Output:
    uint32_t - max subslices per slice

\*****************************************************************************/
uint32_t CDriverInterfaceLinuxPerf::GetGtMaxSubslicePerSlice()
{
    GTDI_PLATFORM_INDEX instrPlatformId = GTDI_PLATFORM_MAX;

    TCompletionCode result = GetInstrPlatformId( &instrPlatformId );
    if( result != CC_OK )
    {
        MD_LOG( LOG_WARNING, "WARNING: Failed to get platform ID" );
    }

    switch( instrPlatformId )
    {
        case GENERATION_HSW:
        case GENERATION_BDW:
        case GENERATION_SKL:
        case GENERATION_BXT:
        case GENERATION_KBL:
            return MD_MAX_SUBSLICE_PER_SLICE_OLD;
        default:
            MD_LOG( LOG_WARNING, "WARNING: Unsupported platform, default MaxSubslicePerSlice used" );
            return MD_MAX_SUBSLICE_PER_SLICE;
    }
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    MapMesaToInstrPlatform

Description:
    Maps Mesa platform information to the instrumentation format.

Input:
    gen_device_info&     mesaDeviceInfo     - Mesa device info struct obtained from GetMesaDeviceInfo()
    GTDI_PLATFORM_INDEX* outInstrPlatformId - (OUT) platform ID in instrumentation format

Output:
    TCompletionCode                         - *CC_OK* means success

\*****************************************************************************/
TCompletionCode CDriverInterfaceLinuxPerf::MapMesaToInstrPlatform( const gen_device_info* mesaDeviceInfo, GTDI_PLATFORM_INDEX* outInstrPlatformId )
{
    MD_CHECK_PTR_RET( mesaDeviceInfo, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( outInstrPlatformId, CC_ERROR_INVALID_PARAMETER );

    TCompletionCode ret = CC_OK;

    if( mesaDeviceInfo->is_haswell )
    {
        *outInstrPlatformId = GENERATION_HSW;
    }
    else if( mesaDeviceInfo->is_broadwell )
    {
        *outInstrPlatformId = GENERATION_BDW;
    }
    else if( mesaDeviceInfo->is_skylake )
    {
        *outInstrPlatformId = GENERATION_SKL;
    }
    else if( mesaDeviceInfo->is_broxton )
    {
        *outInstrPlatformId = GENERATION_BXT;
    }
    else if( mesaDeviceInfo->is_kabylake )
    {
        *outInstrPlatformId = GENERATION_KBL;
    }
    else
    {
        MD_LOG( LOG_ERROR, "ERROR: Unrecognized platform" );
        ret = CC_ERROR_NOT_SUPPORTED;
    }

    return ret;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    MapMesaToInstrGtType

Description:
    Maps GT type format provided by Mesa device info to GT type enum used by
    Intel driver (different OSes compatibility reasons).

Input:
    int32_t mesaGtType - GT type provided by Mesa (simple integer value, e.g. 1 = GT1)

Output:
    TGfxGtType         - graphics GT type, used by Intel driver

\*****************************************************************************/
TGfxGtType CDriverInterfaceLinuxPerf::MapMesaToInstrGtType( int32_t mesaGtType )
{
    // Mesa doesn't support reporting GtTypes like 0.5, 1.75, it always rounds down, so GT1_75 = GT1
    switch( mesaGtType )
    {
        case 0:
            return GFX_GTTYPE_GT0;
        case 1:
            return GFX_GTTYPE_GT1;
        case 2:
            return GFX_GTTYPE_GT2;
        case 3:
            return GFX_GTTYPE_GT3;
        case 4:
            return GFX_GTTYPE_GT4;
        default:
            return GFX_GTTYPE_UNDEFINED;
    }
}

/*****************************************************************************\

Function:
    CalcEnabledBits

Description:
    Helper function to get number of ENABLED bits on given bitmask value
    Based on __InstrCalcEnabledBits.

Input:
    uint32_t value - input value
    uint32_t mask  - valid bits

Output:
    uint32_t       - number of enabled bits

\*****************************************************************************/
uint32_t CDriverInterfaceLinuxPerf::CalculateEnabledBits(uint32_t value, uint32_t mask)
{
    uint32_t count = 0;

    value &= mask;
    while( mask )
    {
        count += (value & 1);
        value >>= 1;
        mask >>= 1;
    }

    return count;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    GetTimerPeriodExponent

Description:
    Changes the given timer period in nanoseconds to the OA timer period exponent.
    Periods are rounded down to the nearest exponent.
    Based on documentation: "StrobePeriod = MinimumTimeStampPeriod * 2^( TimerExponent + 1 )".

Input:
    uint32_t nsTimerPeriod - timer period in nanoseconds

Output:
    uint32_t               - timer period exponent

\*****************************************************************************/
uint32_t CDriverInterfaceLinuxPerf::GetTimerPeriodExponent( uint32_t nsTimerPeriod )
{
    // 1. Get minimum GPU timestamp period
    uint64_t timestampPeriodNs = 0;
    GetGpuTimestampPeriodNs( &timestampPeriodNs );
    if( !timestampPeriodNs )
    {
        MD_LOG( LOG_ERROR, "ERROR: Invalid GPU Timestamp Period" );
        return 0;
    }

    // 2. Compute timer exponent
    return log2( nsTimerPeriod / timestampPeriodNs ) - 1;
}

/*****************************************************************************\

Class:
    CDriverInterfaceLinuxPerf

Method:
    GetNsTimerPeriod

Description:
    Changes the given timer period exponent to the OA timer period in nanoseconds.

Input:
    uint32_t timerPeriodExponent - timer period exponent

Output:
    uint32_t                     - timer period in nanoseconds

\*****************************************************************************/
uint32_t CDriverInterfaceLinuxPerf::GetNsTimerPeriod( uint32_t timerPeriodExponent )
{
    // 1. Get minimum GPU timestamp period
    uint64_t timestampPeriodNs = 0;
    GetGpuTimestampPeriodNs( &timestampPeriodNs );
    if( !timestampPeriodNs )
    {
        MD_LOG( LOG_ERROR, "ERROR: Invalid GPU Timestamp Period" );
        return 0;
    }

    // 2. Compute timer period (StrobePeriod = MinimumTimeStampPeriod * 2^( TimerExponent + 1 ))
    return timestampPeriodNs * (1 << (timerPeriodExponent + 1));
}

}
