/*========================== begin_copyright_notice ============================

Copyright (C) 2020-2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_driver_ifc_linux_perf.cpp

//     Abstract:   C++ implementation for Linux with Perf

#include "md_driver_ifc_linux_perf.h"
#include "md_adapter.h"
#include "md_metrics_device.h"
#include "md_metric_set.h"
#include "md_utils.h"
#include "iu_i915_perf.h"
#include "gfx_device_info.h"

#include <cmath>
#include <cstring>
#include <inttypes.h> // for PRIu64 (printing uint64_t)
#include <errno.h>
#include <array>
#include <vector>
#include <string>
#include <functional> // for std::hash
#include <algorithm>  // for std::find, std::remove
#include <iomanip>
#include <sstream>
#include <regex>

#include <sys/stat.h>
#include <sys/sysmacros.h> // for major, minor
#include <fcntl.h>
#include <dirent.h>
#include <poll.h>
#include <unistd.h> // close, write, read

#include "xf86drm.h" // for drmOpen/drmClose/drmIoctl

//////////////////////////////////////////////////////////////////////////////
//
// Description:
//     General defines used by Perf driver interface.
//
//////////////////////////////////////////////////////////////////////////////
#define MD_MAX_PATH_LENGTH     128
#define MD_PERF_GUID_LENGTH    37                                     // GUID is a string formatted like "%08x-%04x-%04x-%04x-%012x"
#define MD_PERF_GUID_FOR_QUERY "2f01b241-7014-42a7-9eb6-a925cad3daba" // static GUID for storing Query configuration

//////////////////////////////////////////////////////////////////////////////
//
// Description:
//     Register used for reading GPU Timestamp.
//
//////////////////////////////////////////////////////////////////////////////
#define MD_TIMESTAMP_LOW_OFFSET 0x2358

//////////////////////////////////////////////////////////////////////////////
//
// Description:
//     Default GpuTimestampFrequency, used if value obtained from drm is invalid.
//
//////////////////////////////////////////////////////////////////////////////
#define MD_DEFAULT_GPU_TIMESTAMP_FREQUENCY 12000000; // Default, one tick per 83.333ns.

//////////////////////////////////////////////////////////////////////////////
//
// Description:
//     Hardware info used in number of shading units and number of render output
//     units calculation. Based on Intel driver instrumentation files.
//
//////////////////////////////////////////////////////////////////////////////
#define MD_NUM_PIXELS_OUT_PER_CLOCK 4
#define MD_EU_SIMD_SIZE_PER_CLOCK   4

//////////////////////////////////////////////////////////////////////////////
//
// Description:
//     For platforms <= SKL mask of size '3' is used to preserve backward compatibility
//     with MDAPI metric equation definitions. Based on Intel driver instrumentation
//     files.
//
//////////////////////////////////////////////////////////////////////////////
#define MD_MAX_SUBSLICE_PER_SLICE_OLD 3

//////////////////////////////////////////////////////////////////////////////
//
// Description:
//     Maximums which bound all supported GT. Must update as needed with new GT.
//     Based on Intel driver files.
//
//////////////////////////////////////////////////////////////////////////////
#define MD_MAX_SUBSLICE_PER_SLICE     8 // Currently max value
#define MD_MAX_SLICE                  8 // Currently max value
#define MD_MAX_DUALSUBSLICE_PER_SLICE 6 // Currently max value
#define MD_MAX_SUBSLICE_PER_DSS       2 // Currently max value
#define MD_DUALSUBSLICE_PER_SLICE     4 // Current value

//////////////////////////////////////////////////////////////////////////////
//
// Description:
//     Masks helping to define OA Adder workaround need
//
//////////////////////////////////////////////////////////////////////////////
#define SLICES0TO3  0x0F
#define SLICES4TO7  0xF0
#define SLICES4AND5 0x30
#define SLICES6AND7 0xC0

//////////////////////////////////////////////////////////////////////////////
//
// Description:
//     Oa buffer min/max size value
//
//////////////////////////////////////////////////////////////////////////////
// Oa buffer min/max size is equal to 16 MB
#define MD_OA_BUFFER_SIZE_MAX ( 16 * MD_MBYTE )

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    //////////////////////////////////////////////////////////////////////////////
    //
    // Global variables:
    //     Frequency SysFs file names.
    //
    // Description:
    //     Min/Max frequency files return the min/max frequency that can be set on the HW.
    //     Min/Max/Boost frequency override files return currently set frequency. Setting
    //     static frequency requires writing to all of these 3 files.
    //
    //////////////////////////////////////////////////////////////////////////////
    static constexpr char ACT_FREQ_FILE_NAME[] = "gt_act_freq_mhz";
    static constexpr char MAX_FREQ_FILE_NAME[] = "gt_RP0_freq_mhz";
    static constexpr char MIN_FREQ_FILE_NAME[] = "gt_RPn_freq_mhz";

    static constexpr char MAX_FREQ_OV_FILE_NAME[]   = "gt_max_freq_mhz";
    static constexpr char MIN_FREQ_OV_FILE_NAME[]   = "gt_min_freq_mhz";
    static constexpr char BOOST_FREQ_OV_FILE_NAME[] = "gt_boost_freq_mhz";

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSemaphore
    //
    // Method:
    //     CSemaphore constructor
    //
    // Description:
    //     Initializes member variables, setting initial semaphore count to 1 - unlocked
    //     state with one available resource.
    //
    //////////////////////////////////////////////////////////////////////////////
    CSemaphore::CSemaphore()
        : semCount( 1 )
    {
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSemaphore
    //
    // Method:
    //     Notify
    //
    // Description:
    //     Unlocks semaphore.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CSemaphore::Notify()
    {
        std::unique_lock<TFenceMutex> lock( semMutex );
        ++semCount;
        semCv.notify_one();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSemaphore
    //
    // Method:
    //     Wait
    //
    // Description:
    //     Waits (without timeout) for free resources then acquires semaphore.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CSemaphore::Wait()
    {
        std::unique_lock<TFenceMutex> lock( semMutex );
        while( !semCount )
        {
            semCv.wait( lock );
        }
        --semCount;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSemaphore
    //
    // Method:
    //     WaitFor
    //
    // Description:
    //     Tries to acquire semaphore, waiting up to *timeoutMs* milliseconds for
    //     free resources.
    //
    // Input:
    //     uint64_t timeoutMs - maximal time to wait for free semaphore resources
    //
    // Output:
    //     bool - true if semaphore was acquired successfully, false otherwise
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CSemaphore::WaitFor( uint64_t timeoutMs )
    {
        std::unique_lock<TFenceMutex> lock( semMutex );

        bool semLocking = false;
        if( semCount == 0 )
        {
            auto result = semCv.wait_for( lock, std::chrono::milliseconds( timeoutMs ) );
            if( ( result == std::cv_status::no_timeout ) && ( semCount > 0 ) )
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

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSemaphore
    //
    // Method:
    //     TryWait
    //
    // Description:
    //     Tries to acquire semaphore without any waiting and returns immediately.
    //
    // Output:
    //     bool - true if semaphore was acquired successfully, false otherwise
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CSemaphore::TryWait()
    {
        std::unique_lock<TFenceMutex> lock( semMutex );
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

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSemaphore
    //
    // Method:
    //     GetValue
    //
    // Description:
    //     Returns free semaphore resources count. 0 means no free resources.
    //
    // Output:
    //     uint32_t - Semaphore resources count
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CSemaphore::GetValue()
    {
        return semCount;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterface
    //
    // Method:
    //     GetInstance()
    //
    // Description:
    //     Returns instance of CDriverInterface for Linux supporting Perf.
    //
    // Output:
    //     CDriverInterface* - Pointer to new allocated object of CDriverInterfaceLinuxPerfPerf
    //
    //////////////////////////////////////////////////////////////////////////////
#if defined( MD_USE_PERF )
    CDriverInterface* CDriverInterface::CreateInstance( CAdapterHandle& adapterHandle )
    {
        // Read debug logs settings
        IuLogGetSettings( nullptr );

        CDriverInterface* driverInterface = new( std::nothrow ) CDriverInterfaceLinuxPerf( adapterHandle );
        if( ( driverInterface != nullptr ) && ( driverInterface->CreateContext() == false ) )
        {
            MD_SAFE_DELETE( driverInterface );
        }

        return driverInterface;
    }
#endif

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterface
    //
    // Method:
    //     GetAvailableAdapters
    //
    // Description:
    //     Linux implementation of static function GetAvailableAdapters.
    //     Enumerates all available adapters in the system and return Intel ones.
    //
    // Input:
    //     std::vector<TAdapterData>& adapters  - [out] available Intel adapters
    //     const uint32_t             adapterId - adapter id for the purpose of logging
    //
    // Output:
    //     TCompletionCode - result of operation (*CC_OK* is OK)
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterface::GetAvailableAdapters( std::vector<TAdapterData>& adapters, const uint32_t adapterId )
    {
        // The maximum number of drm devices is 64, see:
        // https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git/tree/drivers/gpu/drm/drm_drv.c#n110
        const uint32_t DRM_MAX_DEVICES = 64;

        std::array<drmDevicePtr, DRM_MAX_DEVICES> devices;
        int32_t                                   availableDevices = drmGetDevices( devices.data(), devices.size() );

        if( availableDevices < 0 )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "ERROR: Failed to get the list of drm devices" );
            return CC_ERROR_GENERAL;
        }

#define IS_DRM_NODE_AVAILABLE( _nodes, _node_type ) ( ( _nodes ) & ( 1 << ( _node_type ) ) )

        for( int32_t i = 0; i < availableDevices; ++i )
        {
            if( devices[i] == nullptr )
            {
                MD_LOG_A( adapterId, LOG_ERROR, "ERROR: Uninitialized drm device" );
                continue;
            }

            const drmDevice& device    = *devices[i];
            int32_t          drmFd     = -1;
            int32_t          minorBase = 0;

            if( IS_DRM_NODE_AVAILABLE( device.available_nodes, DRM_NODE_RENDER ) )
            {
                MD_LOG_A( adapterId, LOG_DEBUG, "Open render noder '%s'", device.nodes[DRM_NODE_RENDER] );
                drmFd     = open( device.nodes[DRM_NODE_RENDER], O_RDWR );
                minorBase = DRM_NODE_RENDER * DRM_MAX_DEVICES;
            }

            if( drmFd == -1 && IS_DRM_NODE_AVAILABLE( device.available_nodes, DRM_NODE_PRIMARY ) )
            {
                MD_LOG_A( adapterId, LOG_DEBUG, "Open primary noder '%s'", device.nodes[DRM_NODE_PRIMARY] );
                drmFd     = open( device.nodes[DRM_NODE_PRIMARY], O_RDWR );
                minorBase = DRM_NODE_PRIMARY * DRM_MAX_DEVICES;
            }

            if( drmFd == -1 )
            {
                MD_LOG_A( adapterId, LOG_ERROR, "ERROR: Failed to open drm device" );
                continue;
            }

            drmVersionPtr deviceVersion = drmGetVersion( drmFd );

            if( deviceVersion == nullptr )
            {
                MD_LOG_A( adapterId, LOG_ERROR, "ERROR: Cannot get version for drm device" );

                close( drmFd );
                continue;
            }

            if( deviceVersion->name_len != 4 || strncmp( deviceVersion->name, "i915", 4 ) )
            {
                MD_LOG_A( adapterId, LOG_DEBUG, "Skip non-Intel device '%s'", ( deviceVersion->name_len && deviceVersion->name ? deviceVersion->name : "" ) );

                drmFreeVersion( deviceVersion );
                close( drmFd );
                continue;
            }

            drmFreeVersion( deviceVersion );

            TAdapterData adapter = {};

            // Get platform info
            TGfxDeviceInfo gfxDeviceInfo = {};

            TCompletionCode ret = CDriverInterfaceLinuxPerf::GetGfxDeviceInfo( device.deviceinfo.pci->device_id, &gfxDeviceInfo, adapterId );

            if( ret != CC_OK || gfxDeviceInfo.PlatformIndex == GTDI_PLATFORM_MAX )
            {
                MD_LOG_A( adapterId, LOG_ERROR, "ERROR: Cannot detect platform index" );

                close( drmFd );
                continue;
            }

            adapter.Params.Platform = gfxDeviceInfo.PlatformIndex;
            adapter.Params.Type     = CDriverInterfaceLinuxPerf::GetAdapterType( &gfxDeviceInfo );

            // Get system id (major/minor pair)
            struct stat sbuf = {};
            if( fstat( drmFd, &sbuf ) )
            {
                MD_LOG_A( adapterId, LOG_ERROR, "ERROR: Cannot get system id" );

                close( drmFd );
                continue;
            }

            adapter.Params.SystemId.Type             = ADAPTER_ID_TYPE_MAJOR_MINOR;
            adapter.Params.SystemId.MajorMinor.Major = major( sbuf.st_rdev );
            adapter.Params.SystemId.MajorMinor.Minor = minor( sbuf.st_rdev ) - minorBase;

            // Set capabilities
            adapter.Params.CapabilityMask = IS_DRM_NODE_AVAILABLE( device.available_nodes, DRM_NODE_RENDER )
                ? ADAPTER_CAPABILITY_RENDER_SUPPORTED
                : ADAPTER_CAPABILITY_UNDEFINED;

            // Get device info
            if( devices[i]->bustype == DRM_BUS_PCI )
            {
                adapter.Params.BusNumber      = device.businfo.pci->bus;
                adapter.Params.DeviceNumber   = device.businfo.pci->dev;
                adapter.Params.FunctionNumber = device.businfo.pci->func;
                adapter.Params.DomainNumber   = device.businfo.pci->domain;

                adapter.Params.VendorId    = device.deviceinfo.pci->vendor_id;
                adapter.Params.SubVendorId = device.deviceinfo.pci->subvendor_id;
                adapter.Params.DeviceId    = device.deviceinfo.pci->device_id;

                adapter.Params.ShortName = GetCopiedCString( drmGetDeviceNameFromFd2( drmFd ), adapterId );
            }

            adapter.Handle = new( std::nothrow ) CAdapterHandleLinux( drmFd ); // Important: adapterData.Handle has to be deleted later!
            if( adapter.Handle == nullptr )
            {
                MD_LOG_A( adapterId, LOG_ERROR, "ERROR: Cannot create adapter handle" );

                close( drmFd );
                continue;
            }

            adapters.push_back( std::move( adapter ) );
        }

#undef IS_DRM_NODE_AVAILABLE

        drmFreeDevices( devices.data(), availableDevices );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterface
    //
    // Method:
    //     ReadDebugLogSettings()
    //
    // Description:
    //     Reads global debug log settings in instr utils framework.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CDriverInterface::ReadDebugLogSettings()
    {
        // Read global debug logs settings
        IuLogGetSettings( nullptr );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterface
    //
    // Method:
    //     IsSupportEnableRequired
    //
    // Description:
    //     Return true if this is metrics discovery library responsibility to call
    //     Support Enable.
    //
    // Output:
    //     boolean value indicating whether SupportEnable needs to be called from MD
    //     library
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CDriverInterface::IsSupportEnableRequired()
    {
        return false;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     CDriverInterfaceLinuxPerf constructor
    //
    // Description:
    //     Creates driver context.
    //
    //////////////////////////////////////////////////////////////////////////////
    CDriverInterfaceLinuxPerf::CDriverInterfaceLinuxPerf( CAdapterHandle& adapterHandle )
        : m_DrmDeviceHandle( static_cast<CAdapterHandleLinux&>( adapterHandle ) )
        , m_DrmCardNumber( -1 )
        , m_PerfCapabilities{}
        , m_CachedBoostFrequency( 0 )
        , m_CachedMinFrequency( 0 )
        , m_CachedMaxFrequency( 0 )
        , m_CachedGfxDeviceInfo{ GTDI_PLATFORM_MAX, GFX_GTTYPE_UNDEFINED, 0 }
        , m_CachedDeviceId( -1 )
        , m_CachedPerfRevision( -1 )
    {
        MD_LOG_ENTER_A( IU_ADAPTER_ID_UNKNOWN );
        MD_LOG_EXIT_A( IU_ADAPTER_ID_UNKNOWN );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     CDriverInterfaceLinuxPerf destructor
    //
    // Description:
    //     Deletes driver context.
    //
    //////////////////////////////////////////////////////////////////////////////
    CDriverInterfaceLinuxPerf::~CDriverInterfaceLinuxPerf()
    {
        MD_LOG_ENTER_A( m_adapterId );
        DeleteContext();
        MD_LOG_EXIT_A( m_adapterId );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     CreateContext
    //
    // Description:
    //     Creates driver context.
    //
    // Output:
    //     bool - *true* if successful
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CDriverInterfaceLinuxPerf::CreateContext()
    {
        if( !InitializeIntelDrm() )
        {
            return false;
        }

        AcquireAdapterId();
        ReadPerfCapabilities();
        return true;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     DeleteContext
    //
    // Description:
    //     Deletes driver context. Closes Perf stream if opened and closes DRM.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CDriverInterfaceLinuxPerf::DeleteContext()
    {
        // Query
        for( int32_t perfConfigId : m_AddedPerfConfigs )
        {
            RemovePerfConfig( perfConfigId );
        }
        m_AddedPerfConfigs.clear();

        ResetPerfCapabilities();
        DeinitializeIntelDrm();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     ForceSupportDisable
    //
    // Description:
    //     Not needed on Linux.
    //
    // Output:
    //     TCompletionCode - CC_OK means successful reset
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::ForceSupportDisable()
    {
        // Intentionally - not supported
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     SendSupportEnableEscape
    //
    // Description:
    //     Enable performance monitoring support.
    //
    // Input:
    //     bool enable     - true to enable support, false to disable support
    //
    // Output:
    //     TCompletionCode - *CC_OK* means succeess
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::SendSupportEnableEscape( bool enable )
    {
        // Not needed on Linux Perf
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     SendDeviceInfoParamEscape
    //
    // Description:
    //     Gets chosen device info param using information from kernel.
    //
    // Input:
    //     GTDI_DEVICE_PARAM         param         - chosen param
    //     GTDIDeviceInfoParamExtOut out           - (out) escape result
    //     CMetricsDevice*           metricsDevice - pointer to device
    //
    // Output:
    //     TCompletionCode                         - *CC_OK* means succeess
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM param, GTDIDeviceInfoParamExtOut* out, CMetricsDevice* metricsDevice /* = nullptr */ )
    {
        MD_CHECK_PTR_RET_A( m_adapterId, out, CC_ERROR_INVALID_PARAMETER );

        TCompletionCode       ret           = CC_OK;
        GTDI_PLATFORM_INDEX   platformId    = GTDI_PLATFORM_MAX;
        const TGfxDeviceInfo* gfxDeviceInfo = nullptr;

        ret = GetGfxDeviceInfo( &gfxDeviceInfo );
        MD_CHECK_CC_RET_A( m_adapterId, ret );
        platformId = gfxDeviceInfo->PlatformIndex;

        switch( param )
        {
            case GTDI_DEVICE_PARAM_EU_CORES_TOTAL_COUNT:
            {
                if( IsXePlus() )
                {
                    ret = GetEuCoresTotalCount( out, metricsDevice );
                }
                else
                {
                    ret = SendGetParamIoctl( m_DrmDeviceHandle, I915_PARAM_EU_TOTAL, out );
                }

                MD_CHECK_CC_RET_A( m_adapterId, ret );
                break;
            }

            case GTDI_DEVICE_PARAM_EU_CORES_PER_SUBSLICE_COUNT:
            {
                // #TODO_perf_later - it will be later added to i915 kernel (temporarily EuCoresTotalCount / EuSubslicesTotalCount)
                int32_t euCoresTotalCount   = 0;
                int32_t subslicesTotalCount = 0;

                MD_CHECK_CC_RET_A( m_adapterId, ret );

                if( IsXePlus() )
                {
                    ret = GetEuCoresTotalCount( out, metricsDevice );
                    MD_CHECK_CC_RET_A( m_adapterId, ret );

                    int64_t subsliceMask = 0;
                    ret                  = GetSubsliceMask( &subsliceMask, metricsDevice );
                    MD_CHECK_CC_RET_A( m_adapterId, ret );

                    subslicesTotalCount = CalculateEnabledBits( subsliceMask );

                    switch( platformId )
                    {
                        case GENERATION_TGL:
                        case GENERATION_DG1:
                        case GENERATION_ADLP:
                        case GENERATION_ADLS:
                        case GENERATION_ADLN:
                        case GENERATION_XEHP_SDV:
                            subslicesTotalCount *= MD_MAX_SUBSLICE_PER_DSS;
                            break;
                        default:
                            break;
                    }
                }
                else
                {
                    ret = SendGetParamIoctl( m_DrmDeviceHandle, I915_PARAM_EU_TOTAL, out );
                    MD_CHECK_CC_RET_A( m_adapterId, ret );

                    ret = SendGetParamIoctl( m_DrmDeviceHandle, I915_PARAM_SUBSLICE_TOTAL, &subslicesTotalCount );
                    MD_CHECK_CC_RET_A( m_adapterId, ret );
                }

                euCoresTotalCount = out->ValueUint32;

                out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out->ValueUint32 = ( subslicesTotalCount > 0 ) ? euCoresTotalCount / subslicesTotalCount : 0;
                break;
            }

            case GTDI_DEVICE_PARAM_DUALSUBSLICES_TOTAL_COUNT:
            {
                if( IsDualSubsliceSupported() )
                {
                    int64_t dualSubsliceMask = 0;

                    ret = GetSubsliceMask( &dualSubsliceMask, metricsDevice );
                    MD_CHECK_CC_RET_A( m_adapterId, ret );

                    out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                    out->ValueUint32 = CalculateEnabledBits( dualSubsliceMask );
                }
                else
                {
                    ret = CC_ERROR_INVALID_PARAMETER;
                }
                break;
            }

            case GTDI_DEVICE_PARAM_SUBSLICES_TOTAL_COUNT:
            case GTDI_DEVICE_PARAM_SAMPLERS_COUNT:
            {
                if( IsXePlus() )
                {
                    int64_t subsliceMask = 0;

                    ret = GetSubsliceMask( &subsliceMask, metricsDevice );
                    MD_CHECK_CC_RET_A( m_adapterId, ret );

                    out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                    out->ValueUint32 = CalculateEnabledBits( subsliceMask );

                    if( IsDualSubsliceSupported() && param != GTDI_DEVICE_PARAM_SAMPLERS_COUNT )
                    {
                        out->ValueUint32 *= MD_MAX_SUBSLICE_PER_DSS;
                    }
                }
                else
                {
                    ret = SendGetParamIoctl( m_DrmDeviceHandle, I915_PARAM_SUBSLICE_TOTAL, out );
                }
                break;
            }

            case GTDI_DEVICE_PARAM_SLICES_COUNT:
            {
                int32_t sliceMask = 0;

                if( IsXePlus() )
                {
                    ret = GetSliceMask( &sliceMask, metricsDevice );
                    MD_CHECK_CC_RET_A( m_adapterId, ret );
                }
                else
                {
                    ret = SendGetParamIoctl( m_DrmDeviceHandle, I915_PARAM_SLICE_MASK, &sliceMask );
                    MD_CHECK_CC_RET_A( m_adapterId, ret );
                }

                out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out->ValueUint32 = CalculateEnabledBits( static_cast<uint64_t>( sliceMask ), static_cast<uint64_t>( 0xFFFFFFFF ) );
                MD_ASSERT_A( m_adapterId, out->ValueUint32 <= MD_MAX_SLICE );
                break;
            }

            case GTDI_DEVICE_PARAM_MAX_SLICE:
            {
                out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out->ValueUint32 = MD_MAX_SLICE;
                break;
            }

            case GTDI_DEVICE_PARAM_MAX_SUBSLICE_PER_SLICE:
            {
                out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out->ValueUint32 = GetGtMaxSubslicePerSlice();
                break;
            }

            case GTDI_DEVICE_PARAM_MAX_DUALSUBSLICE_PER_SLICE:
            {
                out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out->ValueUint32 = GetGtMaxDualSubslicePerSlice();
                break;
            }

            case GTDI_DEVICE_PARAM_NUMBER_OF_RENDER_OUTPUT_UNITS:
            {
                int32_t sliceMask = 0;

                if( IsXePlus() )
                {
                    ret = GetSliceMask( &sliceMask, metricsDevice );
                }
                else
                {
                    ret = SendGetParamIoctl( m_DrmDeviceHandle, I915_PARAM_SLICE_MASK, &sliceMask );
                }

                MD_CHECK_CC_RET_A( m_adapterId, ret );

                out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out->ValueUint32 = MD_NUM_PIXELS_OUT_PER_CLOCK * CalculateEnabledBits( static_cast<uint64_t>( sliceMask ) ); // pixels_out_per_clock * sliceCount
                break;
            }

            case GTDI_DEVICE_PARAM_EU_THREADS_COUNT:
            {
                out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out->ValueUint32 = gfxDeviceInfo->ThreadsPerEu;
                break;
            }

            case GTDI_DEVICE_PARAM_NUMBER_OF_SHADING_UNITS:
            {
                out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out->ValueUint32 = MD_EU_SIMD_SIZE_PER_CLOCK * gfxDeviceInfo->ThreadsPerEu; // eu_simd_size_per_clock * euThreadCount
                break;
            }

            case GTDI_DEVICE_PARAM_SUBSLICES_MASK:
            {
                out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT64;
                out->ValueUint64 = 0;

                if( IsXePlus() )
                {
                    if( IsDualSubsliceSupported() )
                    {
                        ret = CC_ERROR_NOT_SUPPORTED;
                    }
                    else
                    {
                        int64_t subSliceMask = 0;
                        ret                  = GetSubsliceMask( &subSliceMask, metricsDevice );
                        MD_CHECK_CC_RET( ret );

                        out->ValueUint64 = static_cast<uint64_t>( subSliceMask );
                    }
                }
                else
                {
                    // Return value is a mask for one slice (assuming it's uniform for each slice)
                    int32_t  singleSubsliceMask       = 0;
                    int32_t  sliceMask                = 0;
                    uint32_t maxSubslicePerSliceCount = GetGtMaxSubslicePerSlice();

                    ret = SendGetParamIoctl( m_DrmDeviceHandle, I915_PARAM_SUBSLICE_MASK, &singleSubsliceMask );
                    MD_CHECK_CC_RET_A( m_adapterId, ret );
                    ret = SendGetParamIoctl( m_DrmDeviceHandle, I915_PARAM_SLICE_MASK, &sliceMask );
                    MD_CHECK_CC_RET_A( m_adapterId, ret );

                    for( int32_t i = 0; i < MD_MAX_SLICE; ++i )
                    {
                        // If slice enabled
                        if( sliceMask & MD_BIT( i ) )
                        {
                            uint64_t targetSubsliceMask = singleSubsliceMask << ( maxSubslicePerSliceCount * i );
                            out->ValueUint64 |= targetSubsliceMask;
                        }
                    }
                }
                break;
            }

            case GTDI_DEVICE_PARAM_DUALSUBSLICES_MASK:
            {
                out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT64;
                out->ValueUint64 = 0;

                if( IsDualSubsliceSupported() )
                {
                    // Return value is a mask of enabled dual subslices
                    int64_t dualSubsliceMask = 0;
                    ret                      = GetSubsliceMask( &dualSubsliceMask, metricsDevice );
                    MD_CHECK_CC_RET_A( m_adapterId, ret );

                    out->ValueUint64 = static_cast<uint64_t>( dualSubsliceMask );
                }
                else
                {
                    ret = CC_ERROR_NOT_SUPPORTED;
                }
                break;
            }

            case GTDI_DEVICE_PARAM_SLICES_MASK:
            {
                int32_t sliceMask = 0;

                if( IsXePlus() )
                {
                    ret = GetSliceMask( &sliceMask, metricsDevice );
                }
                else
                {
                    ret = SendGetParamIoctl( m_DrmDeviceHandle, I915_PARAM_SLICE_MASK, &sliceMask );
                }

                MD_CHECK_CC_RET_A( m_adapterId, ret );

                out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out->ValueUint32 = sliceMask;

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
                uint64_t* minFrequency = ( param == GTDI_DEVICE_PARAM_GPU_CORE_MIN_FREQUENCY ) ? &out->ValueUint64 : nullptr;
                uint64_t* maxFrequency = ( param == GTDI_DEVICE_PARAM_GPU_CORE_MAX_FREQUENCY ) ? &out->ValueUint64 : nullptr;
                uint64_t* actFrequency = ( param == GTDI_DEVICE_PARAM_GPU_CORE_FREQUENCY ) ? &out->ValueUint64 : nullptr;

                ret = GetGpuFrequencyInfo( minFrequency, maxFrequency, actFrequency, nullptr );
                MD_CHECK_CC_RET_A( m_adapterId, ret );

                out->ValueType = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT64;
                break;
            }

            case GTDI_DEVICE_PARAM_PCI_DEVICE_ID:
            {
                int32_t deviceId = -1;

                ret = GetDeviceId( &deviceId );
                MD_CHECK_CC_RET_A( m_adapterId, ret );

                out->ValueUint32 = (uint32_t) deviceId;
                out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                break;
            }

            case GTDI_DEVICE_PARAM_REVISION_ID:
            {
                ret = SendGetParamIoctl( m_DrmDeviceHandle, I915_PARAM_REVISION, out );
                break;
            }

            case GTDI_DEVICE_PARAM_PLATFORM_INDEX:
            {
                out->ValueUint32 = static_cast<uint32_t>( platformId );
                out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                break;
            }

            case GTDI_DEVICE_PARAM_GT_TYPE:
            {
                // Returning mapped GtType for compatibility reasons
                out->ValueType = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                // GfxVer12 gt values is based of revId and slicesMask
                if( IsPlatformMatch( platformId, GENERATION_ACM, GENERATION_XEHP_SDV, GENERATION_PVC ) )
                {
                    out->ValueUint32 = (uint32_t) MapDeviceInfoToInstrGtTypeGfxVer12( gfxDeviceInfo, metricsDevice );
                }
                else
                {
                    out->ValueUint32 = (uint32_t) gfxDeviceInfo->GtType;
                }
                break;
            }

            case GTDI_DEVICE_PARAM_APERTURE_SIZE:
            {
                drm_i915_gem_get_aperture getApertureParams = {
                    0,
                };

                int32_t ioctlRet = SendIoctl( m_DrmDeviceHandle, DRM_IOCTL_I915_GEM_GET_APERTURE, &getApertureParams );
                if( ioctlRet == -1 )
                {
                    MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Failed to send DRM_I915_GEM_GET_APERTURE ioctl" );
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
                out->ValueUint32 = MD_OA_BUFFER_SIZE_MAX;
                break;
            }
            case GTDI_DEVICE_PARAM_GPU_TIMESTAMP_FREQUENCY:
            {
                uint64_t gpuTimestampFrequency = 0;

                ret = GetGpuTimestampFrequency( &gpuTimestampFrequency );
                MD_CHECK_CC_RET_A( m_adapterId, ret );

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
                ret = CC_ERROR_NOT_SUPPORTED;
                break;

            case GTDI_DEVICE_PARAM_OA_BUFFERS_COUNT:
            {
                MD_CHECK_PTR_RET_A( m_adapterId, metricsDevice, CC_ERROR_INVALID_PARAMETER );
                uint32_t oaBufferCount = 0;

                ret = GetOaBufferCount( *metricsDevice, oaBufferCount );
                MD_CHECK_CC_RET_A( m_adapterId, ret );

                out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out->ValueUint32 = oaBufferCount;
                break;
            }

            case GTDI_DEVICE_PARAM_L3_BANK_TOTAL_COUNT:
                ret = CC_ERROR_NOT_SUPPORTED;
                break;

            case GTDI_DEVICE_PARAM_L3_NODE_TOTAL_COUNT:
                ret = CC_ERROR_NOT_SUPPORTED;
                break;

            case GTDI_DEVICE_PARAM_SQIDI_TOTAL_COUNT:
                ret = CC_ERROR_NOT_SUPPORTED;
                break;

            case GTDI_DEVICE_PARAM_COMPUTE_ENGINE_TOTAL_COUNT:
                ret = CC_ERROR_NOT_SUPPORTED;
                break;

            case GTDI_DEVICE_PARAM_COPY_ENGINE_TOTAL_COUNT:
                ret = CC_ERROR_NOT_SUPPORTED;
                break;

            case GTDI_DEVICE_PARAM_PLATFORM_VERSION:
            {
                out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out->ValueUint32 = 0;
                break;
            }

            default:
                ret = CC_ERROR_INVALID_PARAMETER;
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetMaxMinOaBufferSize
    //
    // Description:
    //     Return minimum or maximum oa buffer size.
    //
    // Input:
    //     const GTDI_OA_BUFFER_TYPE  oaBufferType - oa buffer type
    //     const GTDI_DEVICE_PARAM    param        - chosen param
    //     GTDIDeviceInfoParamExtOut& out          - (out) escape result
    //
    // Output:
    //     TCompletionCode                         - *CC_OK* means succeess
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetMaxMinOaBufferSize( const GTDI_OA_BUFFER_TYPE oaBufferType, const GTDI_DEVICE_PARAM param, GTDIDeviceInfoParamExtOut& out )
    {
        switch( param )
        {
            case GTDI_DEVICE_PARAM_OA_BUFFER_SIZE_MAX:
            case GTDI_DEVICE_PARAM_OA_BUFFER_SIZE_MIN:
                break;
            default:
                MD_LOG_A( m_adapterId, LOG_ERROR, "Error: Invalid device param: %u", param );
                return CC_ERROR_INVALID_PARAMETER;
        }

        return SendDeviceInfoParamEscape( param, &out );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     SendPmRegsConfig
    //
    // Description:
    //     (ONLY FOR QUERY)
    //     Adds PmRegs configuration to the i915 kernel through Perf interface.
    //     configuration is added under a fixed GUID, which is known to the UMD driver.
    //     Configuration added under this GUID is later used as a Query configuration.
    //
    //     Before adding the configuration to a i915 kernel, the previous one (if exists)
    //     is removed.
    //
    // Input:
    //     TRegister**                 regVector      - array of pointers to registers to program
    //     const uint32_t              regCount       - register count
    //     const uint32_t              apiMask        - API mask
    //     const uint32_t              subDeviceIndex - sub device index
    //     const GTDI_OA_BUFFER_TYPE   oaBufferType   - oa buffer type
    //
    // Output:
    //     TCompletionCode                            - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::SendPmRegsConfig( TRegister** regVector, const uint32_t regCount, const uint32_t apiMask, const uint32_t subDeviceIndex, const GTDI_OA_BUFFER_TYPE oaBufferType )
    {
        MD_LOG_ENTER_A( m_adapterId );
        MD_CHECK_PTR_RET_A( m_adapterId, regVector, CC_ERROR_INVALID_PARAMETER );
        if( apiMask & API_TYPE_IOSTREAM )
        {
            MD_LOG_A( m_adapterId, LOG_DEBUG, "SetApiFiltering wasn't used" );
        }

        TCompletionCode ret = CC_OK;

        if( regCount ) // It's ok if regCount is 0, e.g. for PipelineStats metric set, which has no configuration (only QueryId)
        {
            int32_t     addedConfigId = -1;
            std::string guid          = GenerateQueryGuid( subDeviceIndex );

            MD_LOG_A( m_adapterId, LOG_DEBUG, "Generated guid: %s", guid.c_str() );

            // Validate query config GUID
            static_assert( sizeof( MD_PERF_GUID_FOR_QUERY ) == MD_PERF_GUID_LENGTH, "MD_PERF_GUID_FOR_QUERY must be of size MD_PERF_GUID_LENGTH" );
            if( guid.size() != MD_PERF_GUID_LENGTH - 1 )
            {
                MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: incorrect guid size. Expected: %d, actual: %d", MD_PERF_GUID_LENGTH - 1, guid.size() );
                return CC_ERROR_GENERAL;
            }

            // 1. REMOVE PREVIOUS QUERY CONFIG IF exists
            //    WARNING: Config from the latest Activate() call will always be used!
            RemovePerfConfigQuery( guid.c_str() );

            // 2. ADD CONFIG
            ret = AddPerfConfig( regVector, regCount, subDeviceIndex, guid.c_str(), addedConfigId );
            MD_ASSERT_A( m_adapterId, addedConfigId != -1 );

            // 3. REMEMBER ADDED CONFIG
            if( ret == CC_OK )
            {
                if( std::find( m_AddedPerfConfigs.begin(), m_AddedPerfConfigs.end(), addedConfigId ) == m_AddedPerfConfigs.end() )
                {
                    m_AddedPerfConfigs.push_back( addedConfigId ); // Remember configId for later removal, only if it wasn't added before - may happen when
                                                                   // the config is already added and ID is reused.
                }
            }
            else
            {
                RemovePerfConfig( addedConfigId );
            }
        }

        MD_LOG_EXIT_A( m_adapterId );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     SendReadRegsConfig
    //
    // Description:
    //     (ONLY FOR QUERY)
    //     Sends ReadRegs configuration to the driver.
    //
    // Input:
    //     TRegister** regVector - array of pointers to registers to program
    //     uint32_t    regCount  - register count
    //     uint32_t    apiMask   - API mask
    //
    // Output:
    //     TCompletionCode       - *CC_OK* means succeess
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::SendReadRegsConfig( TRegister** regVector, uint32_t regCount, uint32_t apiMask )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetPmRegsConfigHandles
    //
    // Description:
    //     Retrieves handles to the Oa, Gp and read regs configuration from the driver.
    //     !READ REGS NOT SUPPORTED ON LINUX YET!
    //
    // Input:
    //     uint32_t  configId       - config id
    //     uint32_t* oaConfigHandle - (OUT) OA config handle in KMD
    //     uint32_t* gpConfigHandle - (OUT) GP config handle in KMD
    //     uint32_t* rrConfigHandle - (OUT) Read regs config handle in KMD
    //
    // Output:
    //     TCompletionCode           - *CC_OK* means succeess
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetPmRegsConfigHandles( uint32_t configId, uint32_t* oaConfigHandle, uint32_t* gpConfigHandle, uint32_t* rrConfigHandle )
    {
        // Not supported on Linux Perf - returning CC_OK on purpose
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     ValidatePmRegsConfig
    //
    // Description:
    //     !NOT SUPPORTED ON LINUX!
    //     Validates PmRegs configuration.
    //
    // Input:
    //     TRegister*    regVector   - array of registers to check
    //     uint32_t      regCount    - register count
    //     uint32_t      platformId  - platform id for which validate the config
    //
    // Output:
    //     TCompletionCode           - *CC_OK* means succeess
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::ValidatePmRegsConfig( TRegister* regVector, uint32_t regCount, uint32_t platformId )
    {
        // Not supported on Linux Perf - returning CC_OK on purpose
        return CC_ERROR_NOT_SUPPORTED;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetGpuCpuTimestamps
    //
    // Description:
    //     Reads GPU and CPU timestamp.
    //     GpuTimestamp is read from DRM_IOCTL_I915_REG_READ ioctl that has the RCS timestamp register whitelisted.
    //     CpuTimestamp is read from clock_gettime() CLOCK_MONOTONIC.
    //
    // Input:
    //     CMetricsDevice& device         - (IN)  metrics device
    //     uint64_t* gpuTimestamp         - (OUT) GPU timestamp in ns
    //     uint64_t* cpuTimestamp         - (OUT) CPU timestamp in ns
    //     uint32_t* cpuId                - (OUT) CPU id
    //     uint64_t* correlationIndicator - (out) correlation indicator in ns !ON LINUX ALWAYS 0!
    //
    // Output:
    //     TCompletionCode                  - *CC_OK* means succeess
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetGpuCpuTimestamps( CMetricsDevice& device, uint64_t* gpuTimestamp, uint64_t* cpuTimestamp, uint32_t* cpuId, uint64_t* correlationIndicator )
    {
        MD_LOG_ENTER_A( m_adapterId );
        MD_CHECK_PTR_RET_A( m_adapterId, gpuTimestamp, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( m_adapterId, cpuTimestamp, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( m_adapterId, cpuId, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( m_adapterId, correlationIndicator, CC_ERROR_INVALID_PARAMETER );

        auto                  platform              = GTDI_PLATFORM_INDEX::GTDI_PLATFORM_MAX;
        uint64_t              gpuTimestampFrequency = 0;
        uint64_t              gpuTimestampNs        = 0;
        uint64_t              cpuTimestampNs        = 0;
        const TGfxDeviceInfo* gfxDeviceInfo         = nullptr;
        TCompletionCode       result                = GetGfxDeviceInfo( &gfxDeviceInfo );
        MD_CHECK_CC_RET_A( m_adapterId, result );
        platform = gfxDeviceInfo->PlatformIndex;

        auto& subDevices       = device.GetAdapter().GetSubDevices();
        bool  useKernelVersion = false;

        switch( platform )
        {
            case GENERATION_XEHP_SDV:
            case GENERATION_ACM:
            case GENERATION_PVC:
            case GENERATION_MTL:
                useKernelVersion = m_PerfCapabilities.IsGpuCpuTimestampSupported;
                break;

            default:
                break;
        }

        if( useKernelVersion )
        {
            result = GetGpuTimestampFrequency( &gpuTimestampFrequency );
            MD_CHECK_CC_RET_A( m_adapterId, result );

            result = subDevices.GetGpuCpuTimestamps( device.GetSubDeviceIndex(), gpuTimestampFrequency, gpuTimestampNs, cpuTimestampNs );
            MD_CHECK_CC_RET_A( m_adapterId, result );
        }
        else
        {
            MD_ASSERT_A( m_adapterId, device.GetSubDeviceIndex() == 0 );

            result = GetGpuTimestampNs( device, &gpuTimestampNs );
            MD_CHECK_CC_RET_A( m_adapterId, result );

            result = GetCpuTimestampNs( &cpuTimestampNs );
            MD_CHECK_CC_RET_A( m_adapterId, result );
        }

        // Set GPU & CPU timestamps
        *cpuTimestamp = cpuTimestampNs;
        *gpuTimestamp = gpuTimestampNs;

        MD_LOG_EXIT_A( m_adapterId );
        return result;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     SendGetCtxIdTagsEscape
    //
    // Description:
    //     Sends GetCtxIdTags escape.
    //     *NOT SUPPORTED ON LINUX*
    //
    // Input:
    //     TGetCtxTagsIdParams* params - params
    //
    // Output:
    //     TCompletionCode             - *CC_OK* means succeess
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::SendGetCtxIdTagsEscape( TGetCtxTagsIdParams* params )
    {
        // Not supported on Linux Perf - returning CC_OK on purpose
        return CC_ERROR_NOT_SUPPORTED;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinux
    //
    // Method:
    //     IsOaBufferSupported
    //
    // Description:
    //     Returns information is given oa buffer type is supported.
    //
    // Input:
    //     const GTDI_OA_BUFFER_TYPE oaBufferType  - oa buffer type
    //     CMetricsDevice*           metricsDevice - metrics device
    //
    // Output:
    //     bool                                    - true if supported
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CDriverInterfaceLinuxPerf::IsOaBufferSupported( const GTDI_OA_BUFFER_TYPE oaBufferType, CMetricsDevice* metricsDevice /* = nullptr */ )
    {
        GTDIDeviceInfoParamExtOut out = {};
        auto                      ret = SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_OA_BUFFERS_COUNT, &out, metricsDevice );
        if( ret != CC_OK )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "Error: Cannot send GTDI_DEVICE_PARAM_OA_BUFFERS_COUNT escape" );
            return false;
        }

        MD_LOG_A( m_adapterId, LOG_INFO, "Oa buffer count: %u", out.ValueUint32 );
        return static_cast<uint32_t>( oaBufferType ) < out.ValueUint32;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetAdapterId
    //
    // Description:
    //     Returns adapter id
    //
    // Output:
    //     uint32_t - adapter id
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CDriverInterfaceLinuxPerf::GetAdapterId()
    {
        return m_adapterId;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterface
    //
    // Method:
    //     SemaphoreCreate
    //
    // Description:
    //     Creates the unnamed semaphore, initial count and max count equal to 1.
    //
    // Input:
    //     char*          name      - *NOT USED ON LINUX* name of a semaphore
    //     void**         semaphore - (OUT) pointer to the memory where the semaphore handle will be stored
    //     const uint32_t adapterId - adapter id for the purpose of logging
    //
    // Output:
    //     TCompletionCode     - *CC_OK* means succeess
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterface::SemaphoreCreate( const char* name, void** semaphore, const uint32_t adapterId )
    {
        MD_LOG_ENTER_A( adapterId );
        if( semaphore == nullptr )
        {
            MD_ASSERT_A( adapterId, semaphore != nullptr );
            return CC_ERROR_INVALID_PARAMETER;
        }
        *semaphore = nullptr;

        CSemaphore* _sem = new( std::nothrow ) CSemaphore;
        MD_CHECK_PTR_RET_A( adapterId, _sem, CC_ERROR_NO_MEMORY );

        *semaphore = (void*) _sem;

        MD_LOG_EXIT_A( adapterId );
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterface
    //
    // Method:
    //     SemaphoreWait
    //
    // Description:
    //     Tries to enter the semaphore gate, waits *miliseconds* until timeout.
    //
    // Input:
    //     uint32_t       milliseconds - time to wait in milliseconds
    //     cosnt uint32_t adapterId    - adapter id for the purpose of logging
    //
    // Output:
    //     TSemaphoreWaitResult  - result of operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TSemaphoreWaitResult CDriverInterface::SemaphoreWait( uint32_t milliseconds, void* semaphore, const uint32_t adapterId )
    {
        MD_LOG_ENTER_A( adapterId );
        if( !semaphore )
        {
            MD_ASSERT_A( adapterId, false );
            MD_LOG_EXIT_A( adapterId );
            return WAIT_RESULT_ERROR_GENERAL;
        }

        CSemaphore*          _sem   = (CSemaphore*) semaphore;
        TSemaphoreWaitResult retVal = WAIT_RESULT_TIMEOUT;

        if( _sem->WaitFor( milliseconds ) )
        {
            retVal = WAIT_RESULT_SUCCESSFUL;
        }

        MD_LOG_EXIT_A( adapterId );
        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterface
    //
    // Method:
    //     SemaphoreRelease
    //
    // Description:
    //     Releases earlier created semaphore.
    //
    // Input:
    //     void**         semaphore - pointer to the semaphore handle
    //     const uint32_t adapterId - adapter id for the purpose of logging
    //
    // Output:
    //     TCompletionCode - result of operation (*CC_OK* is OK)
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterface::SemaphoreRelease( void** semaphore, const uint32_t adapterId )
    {
        MD_LOG_ENTER_A( adapterId );
        if( semaphore == nullptr || ( *semaphore ) == nullptr )
        {
            MD_ASSERT_A( adapterId, semaphore != nullptr );
            MD_ASSERT_A( adapterId, ( *semaphore ) != nullptr );
            MD_LOG_EXIT_A( adapterId );
            return CC_ERROR_INVALID_PARAMETER;
        }

        CSemaphore* _sem     = *( (CSemaphore**) semaphore );
        int32_t     semValue = 0;

        _sem->Notify();
        semValue = _sem->GetValue();

        if( semValue > 0 )
        {
            MD_LOG_A( adapterId, LOG_DEBUG, "destroying semaphore" );
            MD_SAFE_DELETE( _sem );
            *semaphore = nullptr;
        }

        MD_LOG_EXIT_A( adapterId );
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     LockConcurrentGroup
    //
    // Description:
    //     Locks concurrent group of given name. Creates semaphore and waits up to 1s if
    //     needed.
    //     ! On Linux name isn't used, only semaphore pointer. !
    //
    // Input:
    //     const char* name        - concurrent group name
    //     void**      semaphore   - (IN/OUT) pointer to the semaphore
    //
    // Output:
    //     TCompletionCode         - *CC_OK* means succeess
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::LockConcurrentGroup( const char* name, void** semaphore )
    {
        MD_CHECK_PTR_RET_A( m_adapterId, semaphore, CC_ERROR_INVALID_PARAMETER );

        TCompletionCode retVal = CC_OK;

        if( *semaphore == nullptr )
        {
            if( SemaphoreCreate( name, semaphore, m_adapterId ) != CC_OK )
            {
                MD_LOG_A( m_adapterId, LOG_ERROR, "Creating semaphore failed" );
                return CC_ERROR_GENERAL;
            }
        }

        TSemaphoreWaitResult result = SemaphoreWait( 1000L, *semaphore, m_adapterId ); // Wait 1 sec
        switch( result )
        {
            case WAIT_RESULT_SUCCESSFUL: // The semaphore object was signaled
                retVal = CC_OK;
                break;

            case WAIT_RESULT_TIMEOUT: // A time-out occurred
                retVal = CC_CONCURRENT_GROUP_LOCKED;
                MD_LOG_A( m_adapterId, LOG_DEBUG, "Concurrent group locked" );
                break;

            default:
                retVal = CC_ERROR_GENERAL;
                break;
        }

        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     UnlockConcurrentGroup
    //
    // Description:
    //     Unlocks concurrent group of given name.
    //     ! On Linux name isn't used, only semaphore pointer. !
    //
    // Input:
    //     const char*     name        - name of the ConcurrentGroup
    //     void**          semaphore   - (IN/OUT) pointer to the semaphore
    //
    // Output:
    //     TCompletionCode             - *CC_OK* means succeess
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::UnlockConcurrentGroup( const char* name, void** semaphore )
    {
        MD_CHECK_PTR_RET_A( m_adapterId, semaphore, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( m_adapterId, *semaphore, CC_ERROR_INVALID_PARAMETER );

        if( SemaphoreRelease( semaphore, m_adapterId ) != CC_OK )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Releasing semaphore failed" );
            return CC_ERROR_GENERAL;
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     OpenIoStream
    //
    // Description:
    //     Enables Timer Mode and opens OA or Sys Counter Stream (IO Stream) .
    //
    // Input:
    //     COAConcurrentGroup& oaConcurrentGroup - oa concurrent group
    //     uint32_t            processId         - PID of the measured app (0 is global context)
    //     uint32_t&           nsTimerPeriod     - (in/out) requested/set sampling period time in nanoseconds
    //     uint32_t&           bufferSize        - (in/out) requested/set OA Buffer/buffer size in bytes
    //
    // Output:
    //     TCompletionCode                       - *CC_OK* means succeess
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::OpenIoStream( COAConcurrentGroup& oaConcurrentGroup, const uint32_t processId, uint32_t& nsTimerPeriod, uint32_t& bufferSize )
    {
        const char* concurrentGroupName = oaConcurrentGroup.GetParams()->SymbolName;
        auto        metricSet           = oaConcurrentGroup.GetIoMetricSet();
        auto        metricsDevice       = oaConcurrentGroup.GetMetricsDevice();

        MD_CHECK_PTR_RET_A( m_adapterId, concurrentGroupName, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( m_adapterId, metricSet, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( m_adapterId, metricsDevice, CC_ERROR_INVALID_PARAMETER );

        if( !IsStreamTypeSupported( oaConcurrentGroup.GetStreamType() ) )
        {
            return CC_ERROR_NOT_SUPPORTED;
        }

        // 1. ACTIVATE
        TCompletionCode ret = metricSet->ActivateInternal( false, false );
        MD_CHECK_CC_RET_A( m_adapterId, ret );

        MD_ASSERT_A( m_adapterId, metricsDevice->GetStreamConfigId() == -1 ); // Should be -1, which means stream is closed

        // 2. SET PARAMS
        const uint32_t timerPeriodExponent = GetTimerPeriodExponent( nsTimerPeriod );
        const uint32_t perfReportType      = GetPerfReportType( metricSet->GetReportType() );
        int32_t        perfMetricSetId     = -1;
        uint32_t       regCount            = 0;
        TRegister**    regVector           = metricSet->GetStartConfiguration( &regCount );

        if( perfReportType == static_cast<uint32_t>( -1 ) )
        {
            ret = CC_ERROR_NOT_SUPPORTED;
            goto deactivate;
        }

        // 3. ADD HW CONFIG
        ret = AddPerfConfig( regVector, regCount, metricsDevice->GetSubDeviceIndex(), nullptr, perfMetricSetId );
        if( ret != CC_OK )
        {
            goto deactivate;
        }
        MD_ASSERT_A( m_adapterId, perfMetricSetId != -1 );

        // 4. OPEN PERF STREAM
        ret = OpenPerfStream( *metricsDevice, perfMetricSetId, perfReportType, timerPeriodExponent, bufferSize, oaConcurrentGroup.GetOaBufferType() );
        if( ret != CC_OK )
        {
            goto remove_config;
        }

        // 5. RETURN PARAMETERS
        nsTimerPeriod = GetNsTimerPeriod( timerPeriodExponent );
        bufferSize    = MD_OA_BUFFER_SIZE_MAX;

        metricsDevice->SetStreamConfigId( perfMetricSetId ); // Remember Perf config id so it could be removed from the kernel on CloseIoStream

        MD_LOG_A( m_adapterId, LOG_DEBUG, "Perf stream opened with metricSetId: %d, periodNs: %u, exponent: %u, bufferSize: %u", perfMetricSetId, nsTimerPeriod, timerPeriodExponent, bufferSize );
        return CC_OK;

    remove_config:
        RemovePerfConfig( perfMetricSetId );
    deactivate:
        metricSet->Deactivate();
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     ReadIoStream
    //
    // Description:
    //     Reads data from previously opened OA/Sys IO Stream.
    //
    // Input:
    //     COAConcurrentGroup&              oaConcurrentGroup - oa concurrent group
    //     uint32_t                         readFlags         - read flags
    //     char*                            reportData        - (out) pointer to the read data
    //     uint32_t&                        reportsCount      - (in/out) reports read/to read from the stream
    //     uint32_t&                        frequency         - (out) frequency from GTDIReadCounterStreamExtOut
    //     GTDIReadCounterStreamExceptions& exceptions        - (out) exceptions from GTDIReadCounterStreamExtOut
    //
    // Output:
    //     TCompletionCode                                    - *CC_OK* means succeess
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::ReadIoStream( COAConcurrentGroup& oaConcurrentGroup, const uint32_t readFlags, char* reportData, uint32_t& reportsCount, uint32_t& frequency, GTDIReadCounterStreamExceptions& exceptions )
    {
        if( !IsStreamTypeSupported( oaConcurrentGroup.GetStreamType() ) )
        {
            return CC_ERROR_NOT_SUPPORTED;
        }

        auto metricSet     = oaConcurrentGroup.GetIoMetricSet();
        auto metricsDevice = oaConcurrentGroup.GetMetricsDevice();

        MD_CHECK_PTR_RET_A( m_adapterId, metricSet, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( m_adapterId, metricsDevice, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( m_adapterId, reportData, CC_ERROR_INVALID_PARAMETER );

        const uint32_t reportSize  = metricSet->GetParams()->RawReportSize;
        const uint32_t bytesToRead = reportsCount * reportSize;
        uint32_t       readBytes   = 0;

        // Read flags are ignored for Perf
        TCompletionCode ret = ReadPerfStream( *metricsDevice, reportSize, reportsCount, reportData, readBytes, exceptions );
        if( ret == CC_OK )
        {
            MD_ASSERT_A( m_adapterId, ( readBytes % reportSize ) == 0 );
            reportsCount = readBytes / reportSize;

            if( readBytes < bytesToRead )
            {
                ret = CC_READ_PENDING;
            }

            // Read gpu frequency
            uint64_t currentFrequency = 0;
            if( GetGpuFrequencyInfo( nullptr, nullptr, &currentFrequency, nullptr ) == CC_OK )
            {
                frequency = static_cast<uint32_t>( currentFrequency / MD_MHERTZ );
            }
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     CloseIoStream
    //
    // Description:
    //     Closes OA/Sys Counter Stream (IO Stream) and disables Timer Mode.
    //
    // Input:
    //     COAConcurrentGroup& oaConcurrentGroup - oa concurrent group
    //
    // Output:
    //     TCompletionCode                       - *CC_OK* means succeess
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::CloseIoStream( COAConcurrentGroup& oaConcurrentGroup )
    {
        if( !IsStreamTypeSupported( oaConcurrentGroup.GetStreamType() ) )
        {
            return CC_ERROR_NOT_SUPPORTED;
        }

        auto metricSet     = oaConcurrentGroup.GetIoMetricSet();
        auto metricsDevice = oaConcurrentGroup.GetMetricsDevice();

        MD_CHECK_PTR_RET_A( m_adapterId, metricSet, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( m_adapterId, metricsDevice, CC_ERROR_INVALID_PARAMETER );

        // 1. CLOSE STREAM
        ClosePerfStream( *metricsDevice );

        // 2. REMOVE HW CONFIG
        if( RemovePerfConfig( metricsDevice->GetStreamConfigId() ) == CC_OK )
        {
            metricsDevice->SetStreamConfigId( -1 );
        }

        // 3. DEACTIVATE
        TCompletionCode ret = metricSet->Deactivate();
        if( ret != CC_OK )
        {
            MD_ASSERT_A( m_adapterId, false );
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     HandleIoStreamExceptions
    //
    // Description:
    //     !NOT NEEDED ON LINUX!
    //     Handles buffer overflow and overrun exceptions.
    //
    // Input:
    //     COAConcurrentGroup&                   oaConcurrentGroup - oa concurrent group
    //     uint32_t                              processId         - PID of the measured app (0 is global context)
    //     uint32_t&                             reportsCount      - (in/out) reports read/to read from the stream
    //     const GTDIReadCounterStreamExceptions exceptions        - (out) exceptions from GTDIReadCounterStreamExtOut
    //
    // Output:
    //     TCompletionCode                                         - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::HandleIoStreamExceptions( COAConcurrentGroup& oaConcurrentGroup, const uint32_t processId, uint32_t& reportCount, const GTDIReadCounterStreamExceptions exceptions )
    {
        // Not needed on Linux Perf - returning CC_OK on purpose
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     WaitForIoStreamReports
    //
    // Description:
    //     Waits the given number of milliseconds for reports from IoStream.
    //     Returns *CC_OK* if wait was successful (data waiting in the buffer was signaled).
    //
    // Input:
    //     COAConcurrentGroup& oaConcurrentGroup - oa concurrent group
    //     uint32_t            milliseconds      - number of milliseconds to wait
    //
    // Output:
    //     TCompletionCode                       - *CC_OK* means succeess (reports available)
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::WaitForIoStreamReports( COAConcurrentGroup& oaConcurrentGroup, const uint32_t milliseconds )
    {
        if( !IsStreamTypeSupported( oaConcurrentGroup.GetStreamType() ) )
        {
            return CC_ERROR_NOT_SUPPORTED;
        }

        auto metricsDevice = oaConcurrentGroup.GetMetricsDevice();
        MD_CHECK_PTR_RET_A( m_adapterId, metricsDevice, CC_ERROR_INVALID_PARAMETER );

        return WaitForPerfStreamReports( *metricsDevice, milliseconds );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     IsIoMeasurementInfoAvailable
    //
    // Description:
    //     Returns true for IO measurement types which are available on this driver interface.
    //
    // Input:
    //     const TIoMeasurementInfoType ioMeasurementInfoType - IO measurement type to check
    //
    // Output:
    //     bool                                               - *true* if available
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CDriverInterfaceLinuxPerf::IsIoMeasurementInfoAvailable( const TIoMeasurementInfoType ioMeasurementInfoType )
    {
        // Only ReportLost, BufferOverflow and Frequency during read available with Perf
        return ioMeasurementInfoType == IO_MEASUREMENT_INFO_REPORT_LOST ||
            ioMeasurementInfoType == IO_MEASUREMENT_INFO_BUFFER_OVERFLOW ||
            ioMeasurementInfoType == IO_MEASUREMENT_INFO_CORE_FREQUENCY_MHZ;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     IsStreamTypeSupported
    //
    // Description:
    //     Returns true if given stream type is supported.
    //
    // Input:
    //     const TStreamType streamType - stream type
    //
    // Output:
    //     bool                         - *true* if supported
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CDriverInterfaceLinuxPerf::IsStreamTypeSupported( const TStreamType streamType )
    {
        switch( streamType )
        {
            case STREAM_TYPE_OA:
            case STREAM_TYPE_OAM:
                return true;
            default:
                MD_LOG_A( m_adapterId, LOG_ERROR, "Error: Given stream type is not supported: %d", static_cast<uint32_t>( streamType ) );
                return false;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     SetFrequencyOverride
    //
    // Description:
    //     Enables / disables frequency override using CoreU function.
    //
    // Input:
    //     const TSetFrequencyOverrideParams_1_2* params - frequency override params
    //
    // Output:
    //     TCompletionCode                               - *CC_OK* means succeess
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::SetFrequencyOverride( const TSetFrequencyOverrideParams_1_2* params )
    {
        MD_CHECK_PTR_RET_A( m_adapterId, params, CC_ERROR_INVALID_PARAMETER );
        if( params->Pid != 0 )
        {
            MD_LOG_A( m_adapterId, LOG_WARNING, "Pid ignored, frequency override supported only in global mode (Pid = 0)" );
        }

        uint64_t minFrequency        = 0;
        uint64_t maxFrequency        = 0;
        uint64_t minFrequencyToSet   = 0;
        uint64_t maxFrequencyToSet   = 0;
        uint64_t boostFrequencyToSet = 0;

        // Boost frequency needs to be remembered at the beginning for disable
        uint64_t* boostFrequencyPtr = ( m_CachedBoostFrequency ) ? nullptr : &m_CachedBoostFrequency;

        // 1. Read Min/Max and optional Boost frequency
        TCompletionCode ret = GetGpuFrequencyInfo( &minFrequency, &maxFrequency, nullptr, boostFrequencyPtr );
        MD_CHECK_CC_RET_A( m_adapterId, ret );

        MD_LOG_A( m_adapterId, LOG_DEBUG, "MinFreq: %llu, MaxFreq: %llu, BoostFreq: %llu MHz", minFrequency, maxFrequency, m_CachedBoostFrequency );

        // 2. Decide frequency values to be set (e.g. check range)
        if( params->Enable )
        {
            if( params->FrequencyMhz == 0 )
            {
                MD_LOG_A( m_adapterId, LOG_DEBUG, "Using MaxFrequency as a default value (%llu MHz)", maxFrequency );
                maxFrequencyToSet   = maxFrequency;
                minFrequencyToSet   = maxFrequency;
                boostFrequencyToSet = maxFrequency;
            }
            else if( params->FrequencyMhz >= minFrequency && params->FrequencyMhz <= maxFrequency )
            {
                MD_LOG_A( m_adapterId, LOG_DEBUG, "Setting frequency to %u MHz", params->FrequencyMhz );
                maxFrequencyToSet   = params->FrequencyMhz;
                minFrequencyToSet   = params->FrequencyMhz;
                boostFrequencyToSet = params->FrequencyMhz;
            }
            else
            {
                MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Invalid frequency (%u MHz), should be in range [%llu, %llu]", params->FrequencyMhz, minFrequency, maxFrequency );
                ret = CC_ERROR_INVALID_PARAMETER;
            }
        }
        else
        {
            MD_LOG_A( m_adapterId, LOG_DEBUG, "Disabling frequency override" );
            minFrequencyToSet   = minFrequency;
            maxFrequencyToSet   = maxFrequency;
            boostFrequencyToSet = m_CachedBoostFrequency;
        }

        // 3. Request frequency change (set frequency override)
        if( ret == CC_OK )
        {
            ret = WriteSysFsFile( MIN_FREQ_OV_FILE_NAME, minFrequencyToSet );
            MD_CHECK_CC_RET_A( m_adapterId, ret );

            ret = WriteSysFsFile( MAX_FREQ_OV_FILE_NAME, maxFrequencyToSet );
            MD_CHECK_CC_RET_A( m_adapterId, ret );

            // If boost frequency file available
            if( m_CachedBoostFrequency )
            {
                ret = WriteSysFsFile( BOOST_FREQ_OV_FILE_NAME, boostFrequencyToSet );
                MD_CHECK_CC_RET_A( m_adapterId, ret );
            }
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     SetFreqChangeReportsOverride
    //
    // Description:
    //     Allows to toggle frequency change reports.
    //
    // Input:
    //     bool enable     - true to enable, false to disable
    //
    // Output:
    //     TCompletionCode - result, *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::SetFreqChangeReportsOverride( bool enable )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     IsOverrideAvailable
    //
    // Description:
    //     Returns true for overrides available through this driver interface.
    //
    // Input:
    //     TOverrideType overrideType - override type to check
    //
    // Output:
    //     bool                       - *true* if available
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CDriverInterfaceLinuxPerf::IsOverrideAvailable( TOverrideType overrideType )
    {
        // Only Frequency Override is available with Perf
        return overrideType == OVERRIDE_TYPE_FREQUENCY;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     IsSubDeviceSupported
    //
    // Description:
    //     Returns true if sub device support is available.
    //
    // Output:
    //     bool - *true* if available
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CDriverInterfaceLinuxPerf::IsSubDeviceSupported()
    {
        return m_PerfCapabilities.IsSubDeviceSupported;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     SetQueryOverride
    //
    // Description:
    //     Enables/disables multisampled/extended query mode using escape code.
    //
    // Input:
    //     TOverrideType                        overrideType   - override type: extended/multisampled
    //     uint32_t                             oaBufferSize   - default Oa buffer size
    //     const TSetQueryOverrideParams_1_2*   params         - query override params
    //
    // Output:
    //     TCompletionCode                                     - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::SetQueryOverride( TOverrideType overrideType, uint32_t oaBufferSize, const TSetQueryOverrideParams_1_2* params )
    {
        MD_CHECK_PTR_RET_A( m_adapterId, params, CC_ERROR_INVALID_PARAMETER );
        return CC_ERROR_NOT_SUPPORTED;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     ReadPerfCapabilities
    //
    // Description:
    //     Checks whether certain i915 Perf features are supported.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CDriverInterfaceLinuxPerf::ReadPerfCapabilities()
    {
        ResetPerfCapabilities();

        int32_t         perfRevision       = -1;
        TCompletionCode getPerfRevisionRet = GetPerfRevision( &perfRevision );

        auto requirePerfRevision = [=]( int32_t requiredPerfRevision )
        {
            return getPerfRevisionRet == CC_OK && perfRevision >= requiredPerfRevision;
        };

        // Check capabilities. Update when OA interrupt will be mergerd.

        m_PerfCapabilities.IsOaInterruptSupported     = false;
        m_PerfCapabilities.IsSubDeviceSupported       = requirePerfRevision( 10 );
        m_PerfCapabilities.IsGpuCpuTimestampSupported = requirePerfRevision( 11 );

        PrintPerfCapabilities();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     ResetPerfCapabilities
    //
    // Description:
    //     Resets all i915 Perf capabilities struct fields to 'false'.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CDriverInterfaceLinuxPerf::ResetPerfCapabilities()
    {
        memset( &m_PerfCapabilities, 0, sizeof( m_PerfCapabilities ) );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     PrintPerfCapabilities
    //
    // Description:
    //     Prints all i915 Perf capabilities. For debug / information purposes.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CDriverInterfaceLinuxPerf::PrintPerfCapabilities()
    {
        auto getSupportedString = []( bool supported )
        {
            return supported ? "supported"
                             : "not supported";
        };

        MD_LOG_A( m_adapterId, LOG_INFO, "Oa interrupt: %s", getSupportedString( m_PerfCapabilities.IsOaInterruptSupported ) );
        MD_LOG_A( m_adapterId, LOG_INFO, "Sub devices supported: %s", getSupportedString( m_PerfCapabilities.IsSubDeviceSupported ) );
        MD_LOG_A( m_adapterId, LOG_INFO, "Cpu gpu timestamps supported: %s", getSupportedString( m_PerfCapabilities.IsGpuCpuTimestampSupported ) );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     OpenPerfStream
    //
    // Description:
    //     Sends IOCTL opening Perf stream. Output reports will include header and
    //     OA report part. OA configuration should be already added to kernel at this
    //     point.
    //
    // Input:
    //     CMetricsDevice&           metricsDevice       - metrics device
    //     uint32_t                  perfMetricSetId     - Perf configuration ID (previously added)
    //     uint32_t                  perfReportType      - Perf report type
    //     uint32_t                  timerPeriodExponent - timer period exponent
    //     uint32_t                  bufferSize          - oa buffer size
    //     const GTDI_OA_BUFFER_TYPE oaBufferType        - oa buffer type
    //
    // Output:
    //     TCompletionCode                               - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::OpenPerfStream( CMetricsDevice& metricsDevice, uint32_t perfMetricSetId, uint32_t perfReportType, uint32_t timerPeriodExponent, uint32_t bufferSize, const GTDI_OA_BUFFER_TYPE oaBufferType )
    {
        TCompletionCode       ret                    = CC_ERROR_GENERAL;
        int32_t               perfRevision           = -1;
        int32_t               perfEventFd            = -1;
        uint32_t              requiredEngineInstance = -1;
        const bool            isOamRequested         = IsOamRequested( perfReportType );
        const uint32_t        subDeviceIndex         = metricsDevice.GetSubDeviceIndex();
        auto                  subDevices             = metricsDevice.GetAdapter().GetSubDevices();
        auto                  engine                 = TEngineParams_1_9{};
        auto                  param                  = drm_i915_perf_open_param{};
        std::vector<uint64_t> properties             = {};

        auto isValidValue = []( uint32_t value )
        {
            return value != static_cast<uint32_t>( -1 );
        };
        auto addProperty = [&]( const uint64_t key, const uint64_t value )
        {
            properties.push_back( key );
            properties.push_back( value );
        };

        if( isOamRequested && !IsOamSupported() )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: OAM requested but it is not supported on current platform" );
            return CC_ERROR_GENERAL;
        }

        param.flags = 0;
        param.flags |= I915_PERF_FLAG_FD_CLOEXEC;
        param.flags |= I915_PERF_FLAG_FD_NONBLOCK; // We want a non-blocking read

        // Standard tbs properties.
        addProperty( DRM_I915_PERF_PROP_SAMPLE_OA, true );
        addProperty( DRM_I915_PERF_PROP_OA_METRICS_SET, perfMetricSetId );
        addProperty( DRM_I915_PERF_PROP_OA_FORMAT, perfReportType );
        addProperty( DRM_I915_PERF_PROP_OA_EXPONENT, timerPeriodExponent );

        if( subDevices.IsSupported() )
        {
            if( isOamRequested )
            {
                const uint32_t oamBufferSlice = static_cast<uint32_t>( oaBufferType ) - 1;
                if( !isValidValue( oamBufferSlice ) )
                {
                    MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Incorrect oa buffer type for OAM. oaBufferType: %d, oamBufferSlice: %d", static_cast<uint32_t>( oaBufferType ), oamBufferSlice );
                    return CC_ERROR_INVALID_PARAMETER;
                }

                uint32_t baseEngineInstance = 0;
                for( uint32_t i = 0; i < subDeviceIndex; ++i )
                {
                    const uint32_t videoEngineCount        = subDevices.GetClassInstancesCount( i, I915_ENGINE_CLASS_VIDEO );
                    const uint32_t videoEnhanceEngineCount = subDevices.GetClassInstancesCount( i, I915_ENGINE_CLASS_VIDEO_ENHANCE );

                    ret = ( !isValidValue( videoEngineCount ) || !isValidValue( videoEnhanceEngineCount ) || videoEngineCount != videoEnhanceEngineCount )
                        ? CC_ERROR_GENERAL
                        : CC_OK;
                    MD_CHECK_CC_RET_A( m_adapterId, ret );

                    baseEngineInstance += videoEngineCount;
                }

                requiredEngineInstance = baseEngineInstance + oamBufferSlice;
            }

            ret = subDevices.GetTbsEngineParams( subDeviceIndex, engine, requiredEngineInstance, isOamRequested );
            if( ret != CC_OK )
            {
                MD_LOG_A( m_adapterId, LOG_ERROR, "Error: No requested engine found, unable to open tbs on sub device. subDeviceIndex: %d, requiredEngineInstance: %d, isOam: %d", subDeviceIndex, requiredEngineInstance, isOamRequested );
                return CC_ERROR_NOT_SUPPORTED;
            }

            addProperty( PRELIM_DRM_I915_PERF_PROP_OA_ENGINE_CLASS, engine.EngineId.ClassInstance.Class );
            addProperty( PRELIM_DRM_I915_PERF_PROP_OA_ENGINE_INSTANCE, engine.EngineId.ClassInstance.Instance );
        }
        else
        {
            MD_LOG_A( m_adapterId, LOG_DEBUG, "Sub devices are not supported on current platform" );
        }

        param.properties_ptr = reinterpret_cast<uint64_t>( properties.data() );
        param.num_properties = properties.size() / 2;

        do
        {
            MD_LOG_A( m_adapterId, LOG_DEBUG, "Using engine %d:%d ", engine.EngineId.ClassInstance.Class, engine.EngineId.ClassInstance.Instance );

            MD_LOG_A( m_adapterId, LOG_DEBUG, "Opening i915 perf stream with params: perfMetricSetId: %u, perfReportType: %u, timerPeriodExponent: %u, bufferSize: %u", perfMetricSetId, perfReportType, timerPeriodExponent, bufferSize );

            perfEventFd = SendIoctl( m_DrmDeviceHandle, DRM_IOCTL_I915_PERF_OPEN, &param );
        }
        while( perfEventFd == -1 && subDevices.UpdateTbsEngineParams( subDeviceIndex, properties ) == CC_OK );

        if( perfEventFd == -1 )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: opening i915 perf stream failed, fd: %d, errno: %d (%s)", perfEventFd, errno, strerror( errno ) );
            return CC_ERROR_GENERAL;
        }

        metricsDevice.SetStreamId( perfEventFd );

        MD_LOG_A( m_adapterId, LOG_DEBUG, "i915 perf stream opened successfully, fd: %d", perfEventFd );
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     ReadPerfStream
    //
    // Description:
    //     Reads data from the previously opened Perf stream and copies only OA reports
    //     to the output buffer. If report lost header is obtained or oa buffer overflows,
    //     exception flags are set.
    //
    // Input:
    //     CMetricsDevice&                  metricsDevice - metrics device
    //     uint32_t                         oaReportSize  - size of a single OA report, currently always 256 bytes
    //     uint32_t                         reportsToRead - number of reports to read
    //     char*                            reportData    - (OUT) buffer for reports
    //     uint32_t&                        readBytes     - (OUT) number of bytes read and copied to the output buffer
    //     GTDIReadCounterStreamExceptions& exceptions    - (OUT) exception flags reported by Perf
    //
    // Output:
    //     TCompletionCode                   - *CC_OK* means success, BUT IT DOESN'T MEAN ALL REQUESTED DATA WAS READ !!
    //                                         (check readBytes for that).
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::ReadPerfStream( CMetricsDevice& metricsDevice, uint32_t oaReportSize, uint32_t reportsToRead, char* reportData, uint32_t& readBytes, GTDIReadCounterStreamExceptions& exceptions )
    {
        const int32_t streamId = metricsDevice.GetStreamId();

        if( streamId < 0 )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Perf stream not opened" );
            return CC_ERROR_FILE_NOT_FOUND;
        }

        constexpr size_t perfHeaderSize  = sizeof( drm_i915_perf_record_header );
        const size_t     outBufferSize   = oaReportSize * reportsToRead;
        const size_t     perfReportSize  = perfHeaderSize + oaReportSize;                   // Perf report size is bigger (additional header)
        const size_t     perfBytesToRead = reportsToRead * perfReportSize + perfHeaderSize; // Adding header for flag only reports, e.g. for situations where user
                                                                                            // requests 1 report, but first report from Perf is REPORT_LOST flag.

        auto& streamBuffer = metricsDevice.GetStreamBuffer();

        // Resize Perf report buffer if needed
        if( streamBuffer.size() < perfBytesToRead )
        {
            streamBuffer.resize( perfBytesToRead );
        }

        MD_LOG_A( m_adapterId, LOG_DEBUG, "Trying to read %u reports from i915 perf stream, fd: %d", reportsToRead, streamId );

        // #Note May read 1 sample less than requested if ReportLost is returned from kernel

        // 1. READ DATA
        int32_t perfReadBytes = read( streamId, streamBuffer.data(), perfBytesToRead );
        if( perfReadBytes < 0 )
        {
            readBytes = 0;
            if( errno == EAGAIN )
            {
                MD_LOG_A( m_adapterId, LOG_DEBUG, "i915 perf stream data not available yet" );
                return CC_OK;
            }
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Reading i915 stream failed, errno: %d (%s)", errno, strerror( errno ) );
            return CC_ERROR_GENERAL;
        }
        MD_LOG_A( m_adapterId, LOG_DEBUG, "Read %u perf bytes (= %lu reports), perfReportSize: %lu", perfReadBytes, perfReadBytes / perfReportSize, perfReportSize );

        // 2. PROCESS AND COPY DATA
        size_t bytesCopied    = 0;
        size_t perfDataOffset = 0;
        while( perfDataOffset < static_cast<size_t>( perfReadBytes ) )
        {
            const iu_i915_perf_record* perfOaRecord = reinterpret_cast<const iu_i915_perf_record*>( streamBuffer.data() + perfDataOffset );
            if( !perfOaRecord->header.size )
            {
                MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: 0 header size" );
                return CC_ERROR_GENERAL;
            }
            perfDataOffset += perfOaRecord->header.size;

            switch( perfOaRecord->header.type )
            {
                case DRM_I915_PERF_RECORD_SAMPLE:
                {
                    if( perfOaRecord->header.size != perfReportSize )
                    {
                        MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Invalid record size" );
                        return CC_ERROR_GENERAL;
                    }

                    // In MDAPI usage model 'perfOaRecord->data' contains only raw OA report
                    iu_memcpy_s( reportData + bytesCopied, outBufferSize - bytesCopied, perfOaRecord->data, oaReportSize );
                    bytesCopied += oaReportSize;
                    break;
                }

                case DRM_I915_PERF_RECORD_OA_REPORT_LOST:
                    MD_LOG_A( m_adapterId, LOG_DEBUG, "OA report lost" );
                    exceptions.ReportLost = true;
                    break;

                case DRM_I915_PERF_RECORD_OA_BUFFER_LOST:
                    MD_LOG_A( m_adapterId, LOG_DEBUG, "OA buffer lost" );
                    exceptions.BufferOverflow = true;
                    break;

                default:
                    MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Unknown header type = %d", perfOaRecord->header.type );
            }
        }

        readBytes = bytesCopied;
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     ClosePerfStream
    //
    // Description:
    //     Closes previously opened Perf stream.
    //
    // Input:
    //     CMetricsDevice& metricsDevice - metrics device
    //
    // Output:
    //     TCompletionCode              - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::ClosePerfStream( CMetricsDevice& metricsDevice )
    {
        int32_t id = metricsDevice.GetStreamId();

        if( id >= 0 )
        {
            MD_LOG_A( m_adapterId, LOG_DEBUG, "Closing i915 perf stream, fd: %d", id );
            close( id );
            metricsDevice.SetStreamId( -1 );
        }
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     WaitForPerfStreamReports
    //
    // Description:
    //     Wait for any data available in the previously opened Perf stream. Currently,
    //     it's not possible to wait for the half-buffer, so it's a DIFFERENT BEHAVIOUR THAN
    //     THE PREVIOUS IMPLEMENTATIONS.
    //
    // Input:
    //     CMetricsDevice& metricsDevice - metrics device
    //     uint32_t        timeoutMs     - wait timeout in milliseconds
    //
    // Output:
    //     TCompletionCode               - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::WaitForPerfStreamReports( CMetricsDevice& metricsDevice, uint32_t timeoutMs )
    {
        TCompletionCode retVal = CC_OK;
        struct pollfd   pollParams;

        memset( &pollParams, 0, sizeof( pollParams ) );

        pollParams.fd      = metricsDevice.GetStreamId();
        pollParams.revents = 0;
        pollParams.events  = POLLIN;

        MD_LOG_A( m_adapterId, LOG_DEBUG, "Waiting %d ms", timeoutMs );

        int32_t pollResult = poll( &pollParams, 1, timeoutMs );
        if( pollResult > 0 )
        {
            // OK, can read
            MD_LOG_A( m_adapterId, LOG_DEBUG, "Poll successful" );
            retVal = CC_OK;
        }
        else if( pollResult == 0 )
        {
            MD_LOG_A( m_adapterId, LOG_DEBUG, "Poll timeout" );
            retVal = CC_WAIT_TIMEOUT;
        }
        else if( /*ret < 0 && */ errno == EINTR )
        {
            MD_LOG_A( m_adapterId, LOG_DEBUG, "Poll interrupted" );
            retVal = MetricsDiscovery::CC_INTERRUPTED;
        }
        else
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Poll failed" );
            retVal = CC_ERROR_GENERAL;
        }

        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GenerateQueryGUID
    //
    // Description:
    //     Generates query perf guid for given subDeviceIndex.
    //
    // Input:
    //     const uint32_t subDeviceIndex - sub device index
    //
    // Output:
    //     std::string                   - generated guid
    //
    //////////////////////////////////////////////////////////////////////////////
    std::string CDriverInterfaceLinuxPerf::GenerateQueryGuid( const uint32_t subDeviceIndex )
    {
        const std::string valueToReplace    = "42a7";
        const uint32_t    maxSubDeviceIndex = std::pow( 2, valueToReplace.size() * 4 ) - 1;

        if( subDeviceIndex > maxSubDeviceIndex )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Invalid sub device index" );
            return "";
        }

        std::string defaultGuid( MD_PERF_GUID_FOR_QUERY );

        if( subDeviceIndex == 0 || subDeviceIndex == MD_ROOT_DEVICE_INDEX )
        {
            return defaultGuid;
        }

        std::stringstream stream;
        stream << std::setfill( '0' ) << std::setw( valueToReplace.size() ) << std::hex << subDeviceIndex;
        std::string subDeviceIndexHexString( stream.str() );

        return std::regex_replace( defaultGuid, std::regex( valueToReplace ), subDeviceIndexHexString.c_str() );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     AddPerfConfig
    //
    // Description:
    //     Adds OA configuration to the kernel through Perf interface. If no GUID passed
    //     in parameter, GUID of the added configuration is calculated based on concatenated
    //     register offsets and values string.
    //     When the same configuration is already added, its ID is reused (configuration isn't
    //     send for the second time).
    //
    // Input:
    //     TRegister**    regVector      - array of pointers to registers to send (add)
    //     const uint32_t regCount       - register count
    //     const uint32_t subDeviceIndex - sub device index
    //     const char*    requestedGuid  - [optional] GUID under which configuration will be added, if nullptr GUID will be generated
    //     int32_t&       addedConfigId  - (OUT) added perf configuration ID, -1 if error
    //
    // Output:
    //     TCompletionCode               - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::AddPerfConfig( TRegister** regVector, const uint32_t regCount, const uint32_t subDeviceIndex, const char* requestedGuid, int32_t& addedConfigId )
    {
        MD_LOG_ENTER_A( m_adapterId );
        MD_CHECK_PTR_RET_A( m_adapterId, regVector, CC_ERROR_INVALID_PARAMETER );
        if( !regCount )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Empty configuration" );
            return CC_ERROR_GENERAL;
        }

        TCompletionCode                           ret  = CC_OK;
        const char*                               guid = requestedGuid;
        std::vector<iu_i915_perf_config_register> noaRegisters;
        std::vector<iu_i915_perf_config_register> flexRegisters;
        std::vector<iu_i915_perf_config_register> oaRegisters;
        std::string                               regsString; // For hash (guid)

        // 1. TRANSFORM CONFIG TO PERF FORMAT
        MD_LOG_A( m_adapterId, LOG_DEBUG, "AddPerfConfig regCount: %u", regCount );
        for( uint32_t i = 0; i < regCount; i++ )
        {
            if( regVector[i] )
            {
                auto& registers = regVector[i]->type == REGISTER_TYPE_FLEX ? flexRegisters
                                                                           : ( regVector[i]->type == REGISTER_TYPE_OA ? oaRegisters
                                                                                                                      : noaRegisters );
                registers.push_back( { regVector[i]->offset, regVector[i]->value } );
                if( !guid )
                {
                    regsString += regVector[i]->offset;
                    regsString += regVector[i]->value;
                }
                MD_LOG_A( m_adapterId, LOG_DEBUG, "regOffset: %#x, regValue: %#x", regVector[i]->offset, regVector[i]->value );
            }
        }

        // 2. GENERATE CONFIG GUID (if needed) - string formatted like "%08x-%04x-%04x-%04x-%012x"
        char generatedGuid[MD_PERF_GUID_LENGTH];
        if( !guid )
        {
            std::hash<std::string> stringHash;

            // Use std::hash for GUID generation
            snprintf( generatedGuid, sizeof( generatedGuid ), "%08x-%04x-%04x-%04x-%012x", 0, 0, subDeviceIndex, 0, static_cast<uint32_t>( stringHash( regsString ) ) );
            guid = generatedGuid;
        }

        MD_LOG_A( m_adapterId, LOG_DEBUG, "Adding configuration under guid: %s", guid );

        // 3. SET PARAMS
        struct drm_i915_perf_oa_config param = {
            { 0 }, // clang suggest braces around initialization of subobject
        };

        static_assert( sizeof( param.uuid ) == ( MD_PERF_GUID_LENGTH - 1 ), "GUID length mismatch with i915 Perf API" );
        iu_memcpy_s( param.uuid, sizeof( param.uuid ), guid, MD_PERF_GUID_LENGTH - 1 ); // Copy without ending '\0' (size 36)

        param.boolean_regs_ptr = reinterpret_cast<uint64_t>( oaRegisters.data() );
        param.mux_regs_ptr     = reinterpret_cast<uint64_t>( noaRegisters.data() );
        param.flex_regs_ptr    = reinterpret_cast<uint64_t>( flexRegisters.data() );

        param.n_boolean_regs = static_cast<uint32_t>( oaRegisters.size() );
        param.n_mux_regs     = static_cast<uint32_t>( noaRegisters.size() );
        param.n_flex_regs    = static_cast<uint32_t>( flexRegisters.size() );

        // 4. ADD CONFIG TO PERF
        addedConfigId = SendIoctl( m_DrmDeviceHandle, DRM_IOCTL_I915_PERF_ADD_CONFIG, &param );
        if( addedConfigId == -1 )
        {
            if( errno != EADDRINUSE ) // errno == 98 (EADDRINUSE) means set with the given GUID is already added
            {
                MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Adding i915 perf configuration failed, errno: %s (%d)", strerror( errno ), errno );
                ret = CC_ERROR_GENERAL;
            }
            else
            {
                MD_LOG_A( m_adapterId, LOG_DEBUG, "Configuration with the given GUID already added, reusing" );
                ret = GetPerfMetricSetId( guid, addedConfigId );
            }
        }

        if( ret == CC_OK )
        {
            MD_LOG_A( m_adapterId, LOG_DEBUG, "i915 perf configuration added/reused, id: %d", addedConfigId );
        }

        MD_LOG_EXIT_A( m_adapterId );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     RemovePerfConfig
    //
    // Description:
    //     Removes from i915 Perf previously added OA config based on its ID.
    //
    //     Note from i915: "Configs can be removed while being used, the will stop appearing in SysFs
    //                      and their content will be freed when the stream using the config is closed."
    //
    // Input:
    //     int32_t perfConfigId - valid Perf configuration ID (previously added)
    //
    // Output:
    //     TCompletionCode  - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::RemovePerfConfig( int32_t perfConfigId )
    {
        TCompletionCode ret = CC_OK;

        // Note from i915: "Configs can be removed while being used, the will stop appearing in SysFs
        //                  and their content will be freed when the stream using the config is closed."

        if( perfConfigId != -1 )
        {
            MD_LOG_A( m_adapterId, LOG_DEBUG, "Removing perf configuration with id: %d", perfConfigId );

            uint64_t      perfConfigId64 = static_cast<uint64_t>( perfConfigId );
            const int32_t ioctlResult    = SendIoctl( m_DrmDeviceHandle, DRM_IOCTL_I915_PERF_REMOVE_CONFIG, &perfConfigId64 );
            if( ioctlResult )
            {
                if( errno != ENOENT ) // errno == 2 (ENOENT) means set with the given ID doesn't exist
                {
                    MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Removing perf configuration with id %d failed, config not found", perfConfigId );
                    ;
                }
                else
                {
                    MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Removing perf configuration with id %d failed, errno: %d (%s)", perfConfigId, errno, strerror( errno ) );
                }
                ret = CC_ERROR_GENERAL;
            }
            else
            {
                MD_LOG_A( m_adapterId, LOG_DEBUG, "Perf configuration with id %d removed", perfConfigId );
            }
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     RemovePerfConfigQuery
    //
    // Description:
    //     Removes OA config previously added under MD_PERF_GUID_FOR_QUERY from i915 Perf (if exists).
    //     Query Perf config has to be removed e.g. in case when measuring different sets or previous execution crash.
    //
    // Input:
    //     const char* guid - configuration guid
    //
    // Output:
    //     TCompletionCode - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::RemovePerfConfigQuery( const char* guid )
    {
        if( !PerfMetricSetExists( guid ) )
        {
            MD_LOG_A( m_adapterId, LOG_DEBUG, "Perf configuration with query guid doesn't exist" );
            return CC_OK;
        }

        int32_t         existingConfigId = -1;
        TCompletionCode ret              = GetPerfMetricSetId( guid, existingConfigId );
        if( ret == CC_OK )
        {
            MD_LOG_A( m_adapterId, LOG_DEBUG, "Removing perf config with query guid: %s, id: %d", guid, existingConfigId );

            ret = RemovePerfConfig( existingConfigId );
            if( ret == CC_OK )
            {
                // Remove from remembered Perf configs
                m_AddedPerfConfigs.erase( std::remove( m_AddedPerfConfigs.begin(), m_AddedPerfConfigs.end(), existingConfigId ), m_AddedPerfConfigs.end() );
            }
            else
            {
                MD_LOG_A( m_adapterId, LOG_WARNING, "WARNING: Removing perf configuration with query guid failed, id: %d", existingConfigId );
            }
            existingConfigId = -1;
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetPerfMetricSetId
    //
    // Description:
    //     Returns Perf metric set ID (configuration ID) for the configuration with the
    //     given GUID.
    //
    // Input:
    //     const char* guid            - GUID for which to read configuration ID
    //     int32_t&    perfMetricSetId - (OUT) Perf configuration ID, not changed if error
    //
    // Output:
    //     TCompletionCode             - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetPerfMetricSetId( const char* guid, int32_t& perfMetricSetId )
    {
        MD_ASSERT_A( m_adapterId, m_DrmCardNumber >= 0 );

        char     filePath[MD_MAX_PATH_LENGTH];
        uint64_t metricSetId = -1;

        // Read Perf metric set ID based on GUID
        snprintf( filePath, sizeof( filePath ), "/sys/class/drm/card%d/metrics/%s/id", m_DrmCardNumber, guid );

        TCompletionCode ret = ReadUInt64FromFile( filePath, &metricSetId );
        MD_CHECK_CC_RET_A( m_adapterId, ret );
        if( !metricSetId )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Invalid perf config id read from %s", filePath );
            return CC_ERROR_GENERAL;
        }

        perfMetricSetId = static_cast<int32_t>( metricSetId );
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     PerfMetricSetExists
    //
    // Description:
    //     Returns true if Perf has configuration with the given GUID.
    //
    // Input:
    //     const char* guid - GUID for which to read configuration ID
    //
    // Output:
    //     bool             - true if exists, false otherwise
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CDriverInterfaceLinuxPerf::PerfMetricSetExists( const char* guid )
    {
        MD_ASSERT_A( m_adapterId, m_DrmCardNumber >= 0 );

        char filePath[MD_MAX_PATH_LENGTH];

        // Read Perf metric set ID path based on GUID
        snprintf( filePath, sizeof( filePath ), "/sys/class/drm/card%d/metrics/%s/id", m_DrmCardNumber, guid );

        // Check whether the file exists (F_OK)
        return ( access( filePath, F_OK ) != -1 );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetPerfReportType
    //
    // Description:
    //     Returns Perf report format based on MDAPI report type and current platform.
    //
    // Input:
    //     const TReportType reportType - MDAPI report type
    //
    // Output:
    //     uint32_t                     - Perf report format, I915_OA_FORMAT_MAX if error
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CDriverInterfaceLinuxPerf::GetPerfReportType( const TReportType reportType )
    {
        // Get platform ID
        const TGfxDeviceInfo* gfxDeviceInfo = nullptr;
        auto                  ret           = GetGfxDeviceInfo( &gfxDeviceInfo );
        if( ret != CC_OK )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Cannot obtain device info" );
            return -1;
        }

        switch( gfxDeviceInfo->PlatformIndex )
        {
            case GENERATION_HSW:
            {
                switch( reportType )
                {
                    case OA_REPORT_TYPE_256B_A45_NOA16:
                        return I915_OA_FORMAT_A45_B8_C8;
                    default:
                        return -1;
                }
            }
            case GENERATION_XEHP_SDV:
            case GENERATION_PVC:
            {
                switch( reportType )
                {
                    case OA_REPORT_TYPE_256B_A45_NOA16:
                        return I915_OA_FORMAT_A24u40_A14u32_B8_C8;
                    default:
                        return -1;
                }
            }
            case GENERATION_ACM:
            {
                switch( reportType )
                {
                    case OA_REPORT_TYPE_128B_OAM:
                        return PRELIM_I915_OAM_FORMAT_A2u64_B8_C8;
                    case OA_REPORT_TYPE_256B_A45_NOA16:
                        return I915_OA_FORMAT_A24u40_A14u32_B8_C8;
                    default:
                        return -1;
                }
            }
            case GENERATION_MTL:
            {
                switch( reportType )
                {
                    case OA_REPORT_TYPE_128B_MPEC8_NOA16:
                        return PRELIM_I915_OAM_FORMAT_MPEC8u32_B8_C8;
                    case OA_REPORT_TYPE_192B_MPEC8LL_NOA16:
                        return PRELIM_I915_OAM_FORMAT_MPEC8u64_B8_C8;
                    case OA_REPORT_TYPE_256B_A45_NOA16:
                        return I915_OA_FORMAT_A24u40_A14u32_B8_C8;
                    default:
                        return -1;
                }
            }
            default:
            {
                switch( reportType )
                {
                    case OA_REPORT_TYPE_256B_A45_NOA16:
                        return I915_OA_FORMAT_A32u40_A4u32_B8_C8;
                    default:
                        return -1;
                }
            }
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     InitializeIntelDrm
    //
    // Description:
    //     Initializes Intel DRM using libdrm. Reads also DRM card number for the later
    //     use, based on just opened DRM file descriptor.
    //
    // Output:
    //     bool - *true* if success
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CDriverInterfaceLinuxPerf::InitializeIntelDrm()
    {
        if( !m_DrmDeviceHandle.IsValid() )
        {
            return false;
        }

        m_DrmCardNumber = GetDrmCardNumber( m_DrmDeviceHandle );
        if( m_DrmCardNumber < 0 )
        {
            DeinitializeIntelDrm();
            MD_LOG_A( IU_ADAPTER_ID_UNKNOWN, LOG_ERROR, "ERROR: Failed to get DRM card info" );
            return false;
        }

        MD_LOG_A( m_DrmCardNumber, LOG_DEBUG, "DRM initalized successfully" ); // should NOT use m_DrmCardNumber as adapter id if
                                                                               // we ever stop using drm card number as adapter id.
        return true;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     DeinitializeIntelDrm
    //
    // Description:
    //     Deinitializes previously initialized DRM interface.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CDriverInterfaceLinuxPerf::DeinitializeIntelDrm()
    {
        m_DrmCardNumber = -1;
        MD_LOG_A( m_adapterId, LOG_DEBUG, "DRM deinitialized" );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     OpenIntelDrm
    //
    // Description:
    //     Opens DRM connection.
    //     Based on skuwa's openDrm().
    //
    // Output:
    //     int32_t - the DRM file descriptor on success, negative errno value on failure
    //
    //////////////////////////////////////////////////////////////////////////////
    int32_t CDriverInterfaceLinuxPerf::OpenIntelDrm()
    {
        int32_t fd = drmOpenWithType( "i915", nullptr, DRM_NODE_RENDER );
        if( fd < 0 )
        {
            fd = drmOpenWithType( "i915", nullptr, DRM_NODE_PRIMARY );
        }

        if( fd < 0 )
        {
            int32_t status = -errno;
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Failure opening drm device, status = %d", status );
            return status;
        }

        MD_LOG_A( m_adapterId, LOG_DEBUG, "Drm device opened, fd = %d", fd );
        return fd;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     CloseIntelDrm
    //
    // Description:
    //     Closes DRM connection.
    //     Based on skuwa's closeDrm().
    //
    // Input:
    //     int32_t drmFd - DRM file descriptor
    //
    //////////////////////////////////////////////////////////////////////////////
    void CDriverInterfaceLinuxPerf::CloseIntelDrm( int32_t drmFd )
    {
        drmClose( drmFd );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetDrmCardNumber
    //
    // Description:
    //     Returns DRM card number used for e.g. SysFs reads/writes.
    //     Based on GpuTop get_card_for_fd().
    //
    // Input:
    //     int32_t drmFd - valid DRM file descriptor
    //
    // Output:
    //     int32_t       - DRM card number or -1 on error
    //
    //////////////////////////////////////////////////////////////////////////////
    int32_t CDriverInterfaceLinuxPerf::GetDrmCardNumber( int32_t drmFd )
    {
        struct stat fileInfo;
        if( fstat( drmFd, &fileInfo ) )
        {
            MD_LOG_A( IU_ADAPTER_ID_UNKNOWN, LOG_ERROR, "ERROR: Failed to stat DRM fd" );
            return -1;
        }

        int32_t majorNumber = major( fileInfo.st_rdev );
        int32_t minorNumber = minor( fileInfo.st_rdev );

        char drmDirPath[MD_MAX_PATH_LENGTH] = {
            0,
        };
        snprintf( drmDirPath, sizeof( drmDirPath ), "/sys/dev/char/%d:%d/device/drm", majorNumber, minorNumber );

        DIR* drmDir = opendir( drmDirPath );
        MD_CHECK_PTR_RET_A( IU_ADAPTER_ID_UNKNOWN, drmDir, -1 );

        dirent* entry         = nullptr;
        int32_t retCardNumber = -1;
        while( ( entry = readdir( drmDir ) ) != nullptr )
        {
            // If it's a directory named 'card.*'
            if( entry->d_type == DT_DIR && strncmp( entry->d_name, "card", 4 ) == 0 )
            {
                retCardNumber = strtoull( entry->d_name + 4, nullptr, 10 );
                MD_LOG_A( retCardNumber, LOG_DEBUG, "DRM card number: %d", retCardNumber ); // Should NOT use reCardNumber as adapter id if we
                                                                                            // ever stop using drm card number as adapterId on perf linux.
                break;
            }
        }
        closedir( drmDir );

        return retCardNumber;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     AcquireAdapterId
    //
    // Description:
    //     Sets m_adapterId to drm card number as adapter id on linux perf implementation.
    //
    // Output:
    //     TCompletionCode - result of operation (*CC_OK* is OK)
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::AcquireAdapterId()
    {
        if( m_DrmCardNumber > -1 )
        {
            m_adapterId = m_DrmCardNumber;
            return CC_OK;
        }
        m_adapterId = IU_ADAPTER_ID_UNKNOWN;
        return CC_ERROR_GENERAL;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     ReadSysFsFile
    //
    // Description:
    //     Reads a 64-bit unsigned value from the given SysFs file. SysFs path is
    //     based on DRM card number.
    //
    // Input:
    //     const char* fileName  - name of SysFs file to read
    //     uint64_t*   readValue - (OUT) read value (content of the file)
    //
    // Output:
    //     TCompletionCode       - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::ReadSysFsFile( const char* fileName, uint64_t* readValue )
    {
        MD_CHECK_PTR_RET_A( m_adapterId, fileName, CC_ERROR_INVALID_PARAMETER );
        MD_ASSERT_A( m_adapterId, m_DrmCardNumber >= 0 );

        char filePath[MD_MAX_PATH_LENGTH] = {
            0,
        };
        snprintf( filePath, sizeof( filePath ), "/sys/class/drm/card%d/%s", m_DrmCardNumber, fileName );

        return ReadUInt64FromFile( filePath, readValue );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     WriteSysFsFile
    //
    // Description:
    //     Writes a 64-bit unsigned value the the given SysFs file. SysFs path is
    //     based on DRM card number.
    //
    // Input:
    //     const char* fileName - name of SysFs file to write
    //     uint64_t    value    - value to write
    //
    // Output:
    //     TCompletionCode      - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::WriteSysFsFile( const char* fileName, uint64_t value )
    {
        MD_CHECK_PTR_RET_A( m_adapterId, fileName, CC_ERROR_INVALID_PARAMETER );
        MD_ASSERT_A( m_adapterId, m_DrmCardNumber >= 0 );

        char filePath[MD_MAX_PATH_LENGTH] = {
            0,
        };
        snprintf( filePath, sizeof( filePath ), "/sys/class/drm/card%d/%s", m_DrmCardNumber, fileName );

        return WriteUInt64ToFile( filePath, value );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     ReadUInt64FromFile
    //
    // Description:
    //     Reads 64-bit unsigned value from the given file.
    //     Based on GpuTop read_file_uint64().
    //
    // Input:
    //     const char* filePath  - file to read the value from
    //     uint64_t*   readValue - (OUT) read value, not changed in case of error.
    //
    // Output:
    //     TCompletionCode       - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::ReadUInt64FromFile( const char* filePath, uint64_t* readValue )
    {
        MD_CHECK_PTR_RET_A( m_adapterId, filePath, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( m_adapterId, readValue, CC_ERROR_INVALID_PARAMETER );

        char buffer[32] = {
            0,
        };

        int32_t fd = open( filePath, O_RDONLY );
        if( fd < 0 )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Failed to open %s, error: %d (%s)", filePath, errno, strerror( errno ) );
            return CC_ERROR_FILE_NOT_FOUND;
        }

        int32_t readBytes = read( fd, buffer, sizeof( buffer ) - 1 );
        close( fd );

        if( readBytes < 0 )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Read negative number of bytes, error: %d (%s)", errno, strerror( errno ) );
            return CC_ERROR_GENERAL;
        }

        buffer[readBytes] = '\0';
        *readValue        = strtoull( buffer, 0, 0 );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     WriteUInt64ToFile
    //
    // Description:
    //     Writes 64-bit unsigned value to the given file.
    //     Based on GpuTop read_file_uint64().
    //
    // Input:
    //     const char* filePath - file to write the value
    //     uint64_t    value    - value to write
    //
    // Output:
    //     TCompletionCode      - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::WriteUInt64ToFile( const char* filePath, uint64_t value )
    {
        MD_CHECK_PTR_RET_A( m_adapterId, filePath, CC_ERROR_INVALID_PARAMETER );

        char buffer[32] = {
            0,
        };

        int32_t length = snprintf( buffer, sizeof( buffer ), "%" PRIu64, value ); // Note: length does not contain null-terminating character
        if( length >= (int) sizeof( buffer ) || length <= 0 )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Failed to convert value to string" );
            return CC_ERROR_GENERAL;
        }

        int32_t fd = open( filePath, O_WRONLY );
        if( fd < 0 )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Failed to open %s, error: %d (%s)", filePath, errno, strerror( errno ) );
            return CC_ERROR_FILE_NOT_FOUND;
        }

        int32_t writeBytes = write( fd, buffer, length + 1 );
        close( fd );

        if( writeBytes < length )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Failed to write %s, error: %d (%s)", filePath, errno, strerror( errno ) );
            return CC_ERROR_GENERAL;
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     SendIoctl
    //
    // Description:
    //     Sends the given IOCTL to the DRM represented by its file descriptor. Uses libdrm.
    //
    // Input:
    //     int32_t  drmFd    - DRM file descriptor
    //     uint32_t request  - DRM IOCTL type
    //     void*    argument - IOCTL params
    //
    // Output:
    //     int32_t           - interpretation depends on IOCTL, -1 if error and errno set appropriately
    //
    //////////////////////////////////////////////////////////////////////////////
    int32_t CDriverInterfaceLinuxPerf::SendIoctl( int32_t drmFd, uint32_t request, void* argument )
    {
        return drmIoctl( drmFd, request, argument );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     SendGetParamIoctl
    //
    // Description:
    //     Sends DRM_IOCTL_I915_GETPARAM IOCTL to obtain value of the given parameter.
    //     Returned value is always 32-bit integer.
    //
    // Input:
    //     int32_t                 drmFd    - DRM file descriptor
    //     uint32_t                paramId  - parameter to get through i915 GetParam IOCTL
    //     GTDIDeviceInfoParamOut* outValue - (OUT) output value
    //
    // Output:
    //     TCompletionCode                  - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::SendGetParamIoctl( int32_t drmFd, uint32_t paramId, GTDIDeviceInfoParamExtOut* outValue )
    {
        MD_CHECK_PTR_RET_A( m_adapterId, outValue, CC_ERROR_INVALID_PARAMETER );

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

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     SendGetParamIoctl
    //
    // Description:
    //     Sends DRM_IOCTL_I915_GETPARAM IOCTL to obtain value of the given parameter.
    //     Returned value is always 32-bit integer.
    //
    // Input:
    //     int32_t  drmFd    - DRM file descriptor
    //     uint32_t paramId  - parameter to get through i915 GetParam IOCTL
    //     int32_t* outValue - (OUT) output value
    //
    // Output:
    //     TCompletionCode   - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::SendGetParamIoctl( int32_t drmFd, uint32_t paramId, int32_t* outValue )
    {
        MD_CHECK_PTR_RET_A( m_adapterId, outValue, CC_ERROR_INVALID_PARAMETER );

        drm_i915_getparam_t params = {
            0,
        };
        params.param = paramId;
        params.value = outValue;

        int32_t ioctlRet = SendIoctl( drmFd, DRM_IOCTL_I915_GETPARAM, &params );
        if( ioctlRet )
        {
            MD_LOG_A( m_adapterId, LOG_WARNING, "ERROR: Failed to send GET_PARAM ioctl, paramId: %u, errno: %d (%s)", paramId, errno, strerror( errno ) );
            return CC_ERROR_GENERAL;
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetGfxDeviceInfo
    //
    // Description:
    //     Returns Gfx device info structure, based on device id.
    //     Gfx device info is used for e.g. ChipsetId and Platform matching.
    //
    // Input:
    //     int32_t                 deviceId      - Device id
    //     const TGfxDeviceInfo**  gfxDeviceInfo - (OUT) Gfx device info structure
    //
    // Output:
    //     TCompletionCode                       - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetGfxDeviceInfo( int32_t deviceId, TGfxDeviceInfo* gfxDeviceInfo, const uint32_t adapterId )
    {
        MD_CHECK_PTR_RET_A( adapterId, gfxDeviceInfo, CC_ERROR_INVALID_PARAMETER );
        TCompletionCode ret = CC_ERROR_NOT_SUPPORTED;

        if( platformIndexMap.find( deviceId ) != platformIndexMap.end() )
        {
            gfxDeviceInfo->PlatformIndex = platformIndexMap[deviceId].PlatformIndex;
            gfxDeviceInfo->GtType        = platformIndexMap[deviceId].GtType;
            if( threadsPerEuMap.find( gfxDeviceInfo->PlatformIndex ) != threadsPerEuMap.end() )
            {
                gfxDeviceInfo->ThreadsPerEu = threadsPerEuMap[gfxDeviceInfo->PlatformIndex];
                ret                         = CC_OK;
            }
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetQueryDrmDataLength
    //
    // Description:
    //     Returns drm data information length.
    //
    // Input:
    //     const uint32_t   queryId   - query identifier
    //     const uint32_t   flags     - query item flags
    //
    // Output:
    //     uint32_t                   - drm query information length
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CDriverInterfaceLinuxPerf::GetQueryDrmDataLength( const uint32_t queryId, const uint32_t flags /* = 0 */ )
    {
        auto query = drm_i915_query{};
        auto item  = drm_i915_query_item{};

        // Query length.
        item.query_id   = queryId;
        item.length     = 0;
        item.flags      = flags;
        query.items_ptr = reinterpret_cast<uint64_t>( &item );
        query.num_items = 1;

        const bool validCall   = SendIoctl( m_DrmDeviceHandle, DRM_IOCTL_I915_QUERY, &query ) == 0;
        const bool validLength = item.length > 0;

        return ( validCall && validLength )
            ? item.length
            : 0;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     QueryDrm
    //
    // Description:
    //     Allows to query drm to obtain needed information.
    //
    // Input:
    //     const uint32_t           queryId   - query identifier
    //     const uint32_t           flags     - query item flags
    //
    // Output:
    //     std::vector<uint8_t>&    data      - query data
    //     TCompletionCode                    - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::QueryDrm(
        const uint32_t        queryId,
        std::vector<uint8_t>& data,
        const uint32_t        flags /* = 0 */ )
    {
        auto query = drm_i915_query{};
        auto item  = drm_i915_query_item{};

        // Prepare space for query data.
        data.resize( GetQueryDrmDataLength( queryId, flags ) );

        // Prepare query item.
        item.query_id   = queryId;
        item.length     = data.size();
        item.flags      = flags;
        item.data_ptr   = reinterpret_cast<uint64_t>( data.data() );
        query.items_ptr = reinterpret_cast<uint64_t>( &item );
        query.num_items = 1;

        // Input check.
        if( item.length == 0 )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: invalid drm query data length" );
            return CC_ERROR_GENERAL;
        }

        // Send io control.
        if( SendIoctl( m_DrmDeviceHandle, DRM_IOCTL_I915_QUERY, &query ) )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: invalid drm query result" );
            return CC_ERROR_GENERAL;
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     QueryDrm
    //
    // Description:
    //     Allows to query drm to obtain needed information.
    //
    // Input:
    //     drm_i915_query&          query   - [In/Out] query data
    //
    // Output:
    //     TCompletionCode                  - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::QueryDrm( drm_i915_query& query )
    {
        if( SendIoctl( m_DrmDeviceHandle, DRM_IOCTL_I915_QUERY, &query ) )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: invalid drm query result" );
            return CC_ERROR_GENERAL;
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetQueryGeometrySlices
    //
    // Description:
    //     Allows to query drm to obtain query information per subdevice.
    //
    // Input:
    //     std::vector<uint8_t>&    buffer         - [In/Out] data
    //     CMetricsDevice*          metricsDevice  - pointer to device
    //
    // Output:
    //     TCompletionCode                         - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetQueryGeometrySlices( std::vector<uint8_t>& buffer, CMetricsDevice* metricsDevice )
    {
        MD_CHECK_CC_RET_A( m_adapterId, metricsDevice != nullptr ? CC_OK : CC_ERROR_GENERAL );

        const TGfxDeviceInfo* gfxDeviceInfo = nullptr;
        TCompletionCode       ret           = GetGfxDeviceInfo( &gfxDeviceInfo );
        MD_CHECK_CC_RET_A( m_adapterId, ret );

        const uint32_t subDeviceIndex = metricsDevice->GetSubDeviceIndex();
        // For root device we don't need prelim function and can use GetQueryTopologyInfo
        if( subDeviceIndex == 0 )
        {
            return GetQueryTopologyInfo( buffer );
        }

        auto subDevices = metricsDevice->GetAdapter().GetSubDevices();
        auto engine     = TEngineParams_1_9{};

        // Obtain sub device engines.
        ret = subDevices.GetTbsEngineParams( subDeviceIndex, engine );
        MD_CHECK_CC_RET_A( m_adapterId, ret );

        // Check sub device engines support.
        const bool enginesSupported = IsSubDeviceSupported();
        if( !enginesSupported )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Sub devices are not supported by i915 kernel" );
            return CC_ERROR_GENERAL;
        }

        uint32_t flags = ( engine.EngineId.ClassInstance.Class & 0xFF ) | ( ( engine.EngineId.ClassInstance.Instance & 0xFF ) << 8 );
        // DRM_I915_QUERY_GEOMETRY_SUBSLICES is returning empty subslice mask on PVC.
        // Use PRELIM_DRM_I915_QUERY_COMPUTE_SLICES instead.
        if( IsPlatformMatch( gfxDeviceInfo->PlatformIndex, GENERATION_PVC ) )
        {
            ret = QueryDrm( PRELIM_DRM_I915_QUERY_COMPUTE_SUBSLICES, buffer, flags );
            MD_CHECK_CC_RET_A( m_adapterId, ret );
        }
        else
        {
            ret = QueryDrm( DRM_I915_QUERY_GEOMETRY_SUBSLICES, buffer, flags );
            MD_CHECK_CC_RET_A( m_adapterId, ret );
        }
        MD_CHECK_CC_RET_A( m_adapterId, buffer.size() ? CC_OK : CC_ERROR_GENERAL );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetQueryTopologyInfo
    //
    // Description:
    //     Allows to query drm to obtain query topology information.
    //
    // Input:
    //     std::vector<uint8_t>&    buffer         - [In/Out] data
    //
    // Output:
    //     TCompletionCode                         - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetQueryTopologyInfo( std::vector<uint8_t>& buffer )
    {
        TCompletionCode ret = CC_OK;
        ret                 = QueryDrm( DRM_I915_QUERY_TOPOLOGY_INFO, buffer );
        MD_CHECK_CC_RET_A( m_adapterId, ret );
        MD_CHECK_CC_RET_A( m_adapterId, buffer.size() ? CC_OK : CC_ERROR_GENERAL );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetSliceMask
    //
    // Description:
    //     Allows to obtain slice mask value.
    //     Works only on Xe+ platforms.
    //
    // Input:
    //     int32_t*       sliceMask        - [out] data
    //     CMetricsDevice* metricsDevice    - pointer to device
    //
    // Output:
    //     TCompletionCode                  - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetSliceMask( int32_t* sliceMask, CMetricsDevice* metricsDevice )
    {
        TCompletionCode ret = CC_OK;

        MD_CHECK_PTR_RET_A( m_adapterId, sliceMask, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( m_adapterId, metricsDevice, CC_ERROR_INVALID_PARAMETER );

        if( !IsXePlus() )
        {
            return CC_ERROR_GENERAL;
        }

        *sliceMask = 0;

        // Return value is a mask of enabled subslices or dual-subslices
        uint32_t subslicePerSlice = 0;
        int64_t  subsliceMask     = 0;

        if( IsDualSubsliceSupported() )
        {
            subslicePerSlice = GetGtMaxDualSubslicePerSlice();
        }
        else
        {
            subslicePerSlice = GetGtMaxSubslicePerSlice();
        }

        ret = GetSubsliceMask( &subsliceMask, metricsDevice );
        MD_CHECK_CC_RET_A( m_adapterId, ret );

        for( uint32_t i = 0; i < MD_MAX_SLICE; ++i )
        {
            if( ( subsliceMask >> ( subslicePerSlice * i ) ) & MD_BITMASK( subslicePerSlice ) )
            {
                *sliceMask |= MD_BIT( i );
            }
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetSubsliceMask
    //
    // Description:
    //     Allows to obtain subslice mask or dual-subslice mask (depends on platform) value per sub device.
    //     Works only on Xe+ platforms.
    //     Starting with Gen12 term "subslice" is used to refer to what the hardware documentation describes as a "dual-subslices".
    //
    // Input:
    //     int64_t*        subsliceMask     - [out] data
    //     CMetricsDevice* metricsDevice    - pointer to device
    //
    // Output:
    //     TCompletionCode                  - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetSubsliceMask( int64_t* subsliceMask, CMetricsDevice* metricsDevice )
    {
        TCompletionCode ret = CC_OK;

        MD_CHECK_PTR_RET_A( m_adapterId, subsliceMask, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( m_adapterId, metricsDevice, CC_ERROR_INVALID_PARAMETER );

        *subsliceMask = 0;

        if( !IsXePlus() )
        {
            return CC_ERROR_GENERAL;
        }

        if( IsDualSubsliceSupported() )
        {
            MD_LOG_A( m_adapterId, LOG_INFO, "Obtaining dual subslice mask" );
        }
        else
        {
            MD_LOG_A( m_adapterId, LOG_INFO, "Obtaining subslice mask" );
        }

        // Get subslice or dual-subslice mask per sub device.
        auto buffer = std::vector<uint8_t>();
        ret         = GetQueryGeometrySlices( buffer, metricsDevice );
        MD_CHECK_CC_RET_A( m_adapterId, ret );

        auto topology = reinterpret_cast<drm_i915_query_topology_info*>( buffer.data() );

        const uint16_t subsliceOffset = topology->subslice_offset;
        const uint16_t subsliceStride = topology->subslice_stride;
        uint32_t       ssIndex        = 0;

        for( uint32_t sliceIndex = 0; sliceIndex < topology->max_slices; ++sliceIndex )
        {
            for( uint32_t subSliceIndex = 0; subSliceIndex < topology->max_subslices; ++subSliceIndex )
            {
                const uint32_t dataIndex = subsliceOffset + ( sliceIndex * subsliceStride ) + ( subSliceIndex / 8 );
                if( ( ( topology->data[dataIndex] ) >> ( subSliceIndex % 8 ) ) & 1 )
                {
                    *subsliceMask |= 1UL << ssIndex;
                }
                ssIndex++;
            }
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetEuCoresTotalCount
    //
    // Description:
    //     Allows to obtain EuCoresTotalCount value per sub device.
    //
    // Input:
    //     GTDIDeviceInfoParamExtOut* out            - [out] data
    //     CMetricsDevice*            metricsDevice  - pointer to device
    //
    // Output:
    //     TCompletionCode                           - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetEuCoresTotalCount( GTDIDeviceInfoParamExtOut* out, CMetricsDevice* metricsDevice )
    {
        TCompletionCode ret = CC_OK;

        if( !IsXePlus() )
        {
            return CC_ERROR_GENERAL;
        }

        // Get EuCoresTotalCount per sub device.
        auto buffer = std::vector<uint8_t>();

        ret = GetQueryGeometrySlices( buffer, metricsDevice );
        MD_CHECK_CC_RET_A( m_adapterId, ret );

        auto topology = reinterpret_cast<drm_i915_query_topology_info*>( buffer.data() );

        out->ValueUint32 = 0;
        out->ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;

        const uint16_t euOffset = topology->eu_offset;
        const uint16_t euStride = topology->eu_stride;

        for( uint16_t sliceIndex = 0; sliceIndex < topology->max_slices; ++sliceIndex )
        {
            for( uint16_t i = 0; i < topology->max_eus_per_subslice; ++i )
            {
                for( uint16_t subSliceIndex = 0; subSliceIndex < topology->max_subslices; ++subSliceIndex )
                {
                    const uint16_t eu        = topology->max_eus_per_subslice - 1 - i;
                    const uint32_t dataIndex = euOffset + ( sliceIndex * topology->max_subslices + subSliceIndex ) * euStride + eu / 8;

                    out->ValueUint32 += ( topology->data[dataIndex] >> ( eu % 8 ) ) & 1;
                }
            }
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetAdapterType
    //
    // Description:
    //     Returns adapter type based on gfx device info.
    //     It can be better to use information about the device type directly from i915 driver.
    //     But now 'is_dgfx' property is not available via standard interface:
    //     https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git/tree/drivers/gpu/drm/i915/intel_device_info.h#n110
    // Input:
    //     const TGfxDeviceInfo* TGfxDeviceInfo - Gfx device info structure
    //
    // Output:
    //     TAdapterType                           - Discrete or integrated.
    //
    //////////////////////////////////////////////////////////////////////////////
    TAdapterType CDriverInterfaceLinuxPerf::GetAdapterType( const TGfxDeviceInfo* gfxDeviceInfo )
    {
        switch( gfxDeviceInfo->PlatformIndex )
        {
            case GENERATION_DG1:
            case GENERATION_ACM:
            case GENERATION_XEHP_SDV:
            case GENERATION_PVC:
                return ADAPTER_TYPE_DISCRETE;
            default:
                return ADAPTER_TYPE_INTEGRATED;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetGfxDeviceInfo
    //
    // Description:
    //     Returns gfx device info structure, based on DeviceId read from kernel.
    //     Gfx device info is used for e.g. ChipsetId and Platform matching or
    //     getting timestamp frequency.
    //     Struct is obtained only once and cached for later use.
    //
    // Input:
    //     const gfx_device_info** gfxDeviceInfo - (OUT) gfx device info structure
    //
    // Output:
    //     TCompletionCode                        - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetGfxDeviceInfo( const TGfxDeviceInfo** gfxDeviceInfo )
    {
        // Get gfxDeviceInfo if not cached already
        if( m_CachedGfxDeviceInfo.PlatformIndex == GTDI_PLATFORM_MAX )
        {
            int32_t         deviceId = 0;
            TCompletionCode ret      = GetDeviceId( &deviceId );

            MD_CHECK_CC_RET_A( m_adapterId, ret );

            if( GetGfxDeviceInfo( deviceId, &m_CachedGfxDeviceInfo, m_adapterId ) != CC_OK )
            {
                return CC_ERROR_NOT_SUPPORTED;
            }
        }

        *gfxDeviceInfo = &m_CachedGfxDeviceInfo;

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetChipsetId
    //
    // Description:
    //     Returns DeviceId (ChipsetId) obtained from kernel using i915_GETPARAM IOCTL.
    //
    // Input:
    //     int32_t* deviceId - (OUT) returned DeviceId
    //
    // Output:
    //     TCompletionCode   - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetDeviceId( int32_t* deviceId )
    {
        MD_CHECK_PTR_RET_A( m_adapterId, deviceId, CC_ERROR_INVALID_PARAMETER );
        TCompletionCode ret = CC_OK;

        if( m_CachedDeviceId == -1 )
        {
            ret = SendGetParamIoctl( m_DrmDeviceHandle, I915_PARAM_CHIPSET_ID, &m_CachedDeviceId );
            if( ret != CC_OK )
            {
                m_CachedDeviceId = -1;
                return ret;
            }
        }

        *deviceId = m_CachedDeviceId;
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetPerfRevision
    //
    // Description:
    //     Returns i915 Perf interface revision obtained from kernel using i915_GETPARAM IOCTL.
    //     SendGetParamIoctl function isn't used here because kernel error code needs to be checked
    //     directly.
    //     I915_PARAM_PERF_REVISION was added in revision '2', so not supported error code ('EINVAL')
    //     means that it's revision '1'.
    //
    // Input:
    //     int32_t* perfRevision - (OUT) returned perf revision number
    //
    // Output:
    //     TCompletionCode       - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetPerfRevision( int32_t* perfRevision )
    {
        MD_CHECK_PTR_RET_A( m_adapterId, perfRevision, CC_ERROR_INVALID_PARAMETER );

        if( m_CachedPerfRevision == -1 )
        {
            drm_i915_getparam_t params = {
                0,
            };
            params.param = I915_PARAM_PERF_REVISION;
            params.value = &m_CachedPerfRevision;

            int32_t ioctlRet = SendIoctl( m_DrmDeviceHandle, DRM_IOCTL_I915_GETPARAM, &params );
            if( ioctlRet )
            {
                if( errno == EINVAL ) // errno == EINVAL means kernel doesn't support I915_PARAM_PERF_REVISION IOCTL, assuming revision 1
                {
                    MD_LOG_A( m_adapterId, LOG_INFO, "I915_PARAM_PERF_REVISION not supported, assuming revision '1'" );
                    m_CachedPerfRevision = 1;
                }
                else
                {
                    MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Getting i915 perf revision failed, errno: %d (%s)", errno, strerror( errno ) );
                    m_CachedPerfRevision = -1;
                    return CC_ERROR_GENERAL;
                }
            }
            MD_LOG_A( m_adapterId, LOG_DEBUG, "i915 perf revision: %d", m_CachedPerfRevision );
        }

        *perfRevision = m_CachedPerfRevision;
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetGpuFrequencyInfo
    //
    // Description:
    //     Reads GPU frequency info from the SysFs files. Minimum and maximum frequencies
    //     are cached (they don't change).
    //
    // Input:
    //     uint64_t* minFrequency   - (OUT) in MHz
    //     uint64_t* maxFrequency   - (OUT) in MHz
    //     uint64_t* actFrequency   - (OUT) in Hz to preserve compatibility with other MDAPI driver interfaces
    //     uint64_t* boostFrequency - (OUT) in Mhz
    //
    // Output:
    //     TCompletionCode          - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetGpuFrequencyInfo( uint64_t* minFrequency, uint64_t* maxFrequency, uint64_t* actFrequency, uint64_t* boostFrequency )
    {
        TCompletionCode ret = CC_ERROR_GENERAL; // Error if all parameters nullptr

        // Read minimum frequency
        if( minFrequency )
        {
            if( !m_CachedMinFrequency )
            {
                ret = ReadSysFsFile( MIN_FREQ_FILE_NAME, &m_CachedMinFrequency );
                MD_CHECK_CC_RET_A( m_adapterId, ret );
            }

            *minFrequency = m_CachedMinFrequency;
            ret           = CC_OK;
        }

        // Read maximum frequency
        if( maxFrequency )
        {
            if( !m_CachedMaxFrequency )
            {
                ret = ReadSysFsFile( MAX_FREQ_FILE_NAME, &m_CachedMaxFrequency );
                MD_CHECK_CC_RET_A( m_adapterId, ret );
            }

            *maxFrequency = m_CachedMaxFrequency;
            ret           = CC_OK;
        }

        // Read actual frequency
        if( actFrequency )
        {
            uint64_t actFrequencyMhz = 0;

            // Using act ('actual') frequency file, curr ('current') freq file may show
            // frequency requested by the driver not the actual GPU frequency.
            ret = ReadSysFsFile( ACT_FREQ_FILE_NAME, &actFrequencyMhz );
            MD_CHECK_CC_RET_A( m_adapterId, ret );

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
                MD_LOG_A( m_adapterId, LOG_WARNING, "WARNING: Reading BoostGpuFrequency file failed" );
            }
            else
            {
                *boostFrequency = boostFrequencyMhz;
                ret             = CC_OK;
            }
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetOaTimestampFrequency
    //
    // Description:
    //     Returns oa timestamp frequency.
    //
    // Input:
    //     uint64_t& frequency  - (OUT) oa timestamp frequency
    //
    // Output:
    //     TCompletionCode      - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetOaTimestampFrequency( uint64_t& frequency )
    {
        int32_t         freq   = 0;
        TCompletionCode result = SendGetParamIoctl( m_DrmDeviceHandle, I915_PARAM_OA_TIMESTAMP_FREQUENCY, &freq );
        MD_CHECK_CC_RET_A( m_adapterId, result );
        frequency = static_cast<uint64_t>( freq );

        return result;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetCsTimestampFrequency
    //
    // Description:
    //     Returns cs timestamp frequency.
    //
    // Input:
    //     uint64_t& frequency  - (OUT) cs timestamp frequency
    //
    // Output:
    //     TCompletionCode      - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetCsTimestampFrequency( uint64_t& frequency )
    {
        int32_t         freq   = 0;
        TCompletionCode result = SendGetParamIoctl( m_DrmDeviceHandle, I915_PARAM_CS_TIMESTAMP_FREQUENCY, &freq );
        MD_CHECK_CC_RET_A( m_adapterId, result );
        frequency = static_cast<uint64_t>( freq );

        return result;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     IsOamSupported
    //
    // Description:
    //     Returns information if oam supported for given platform.
    //
    // Output:
    //     bool - true if supported
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CDriverInterfaceLinuxPerf::IsOamSupported()
    {
        const TGfxDeviceInfo* gfxDeviceInfo = nullptr;
        auto                  ret           = GetGfxDeviceInfo( &gfxDeviceInfo );
        if( ret != CC_OK )
        {
            return false;
        }

        switch( gfxDeviceInfo->PlatformIndex )
        {
            case GENERATION_ACM:
            case GENERATION_MTL:
                return true;
            default:
                return false;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     IsOamRequested
    //
    // Description:
    //     Returns information if access to oam requested.
    //
    // Input:
    //     const uint32_t reportType - report type
    //
    // Output:
    //     bool                      - true if access to oam requested.
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CDriverInterfaceLinuxPerf::IsOamRequested( const uint32_t reportType )
    {
        switch( reportType )
        {
            case PRELIM_I915_OAM_FORMAT_A2u64_B8_C8:
                return true;
            default:
                return false;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetOaTimestamp
    //
    // Description:
    //     Returns oa timestamp for given cs timestamp.
    //
    // Input:
    //     uint64_t  csTimestamp     - (IN)  oa timestamp in ticks
    //     uint64_t& oaTimestamp     - (OUT) cs timestamp in ticks
    //
    // Output:
    //     TCompletionCode           - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetOaTimestamp( const uint64_t csTimestamp, uint64_t& oaTimestamp )
    {
        const TGfxDeviceInfo* gfxDeviceInfo = nullptr;
        TCompletionCode       ret           = GetGfxDeviceInfo( &gfxDeviceInfo );
        MD_CHECK_CC_RET_A( m_adapterId, ret );

        uint64_t oaTimestampFrequency = 0;
        uint64_t csTimestampFrequency = 0;

        switch( gfxDeviceInfo->PlatformIndex )
        {
            case GENERATION_ACM:
            case GENERATION_PVC:
            case GENERATION_MTL:
                ret = GetOaTimestampFrequency( oaTimestampFrequency );
                MD_CHECK_CC_RET_A( m_adapterId, ret );
                ret = GetCsTimestampFrequency( csTimestampFrequency );
                MD_CHECK_CC_RET_A( m_adapterId, ret );
                oaTimestamp = csTimestamp * oaTimestampFrequency / csTimestampFrequency;
                break;

            default:
                oaTimestamp = csTimestamp;
                break;
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetGpuTimestampFrequency
    //
    // Description:
    //     Returns GPU oa timestamp frequency.
    //
    // Input:
    //     uint64_t* gpuTimestampFrequency - (OUT) GPU Timestamp frequency in Hz
    //
    // Output:
    //     TCompletionCode                 - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetGpuTimestampFrequency( uint64_t* gpuTimestampFrequency )
    {
        MD_CHECK_PTR_RET_A( m_adapterId, gpuTimestampFrequency, CC_ERROR_INVALID_PARAMETER );

        const TGfxDeviceInfo* gfxDeviceInfo = nullptr;
        auto                  result        = GetGfxDeviceInfo( &gfxDeviceInfo );
        MD_CHECK_CC_RET_A( m_adapterId, result );

        switch( gfxDeviceInfo->PlatformIndex )
        {
            case GENERATION_ACM:
            case GENERATION_PVC:
            case GENERATION_MTL:
                result = GetOaTimestampFrequency( *gpuTimestampFrequency );
                break;

            default:
                result = GetCsTimestampFrequency( *gpuTimestampFrequency );
                break;
        }

        MD_CHECK_CC_RET_A( m_adapterId, result );
        return result;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetGpuTimestampPeriodNs
    //
    // Description:
    //     Returns minimum GPU timestamp period is nanoseconds based on GPU timestamp
    //     frequency.
    //
    // Input:
    //     uint64_t* gpuTimestampPeriodNs - (OUT) GPU timestamp period in ns
    //
    // Output:
    //     TCompletionCode                - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetGpuTimestampPeriodNs( uint64_t* gpuTimestampPeriodNs )
    {
        MD_CHECK_PTR_RET_A( m_adapterId, gpuTimestampPeriodNs, CC_ERROR_INVALID_PARAMETER );

        // 1. Get GpuTimestamFrequency
        uint64_t        gpuTimestampFrequency = 0;
        TCompletionCode ret                   = GetGpuTimestampFrequency( &gpuTimestampFrequency );
        MD_CHECK_CC_RET_A( m_adapterId, ret );

        MD_ASSERT_A( m_adapterId, gpuTimestampFrequency != 0 );

        // 2. Transform Hz to period (ns)
        *gpuTimestampPeriodNs = MD_NSEC_PER_SEC / gpuTimestampFrequency;
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetGpuTimestampNs
    //
    // Description:
    //     Reads GPU timestamp in nanoseconds. It uses GPU timestamp in ticks and
    //     GPU timestamp frequency to get the timestamp in ns.
    //
    // Input:
    //     CMetricsDevice& device         - metrics device
    //     uint64_t*       gpuTimestampNs - (OUT) GPU timestamp in nanoseconds
    //
    // Output:
    //     TCompletionCode                - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetGpuTimestampNs( CMetricsDevice& metricsDevice, uint64_t* gpuTimestampNs )
    {
        MD_CHECK_PTR_RET_A( m_adapterId, gpuTimestampNs, CC_ERROR_INVALID_PARAMETER );

        // 1. Get GpuTimestamFrequency
        uint64_t        gpuTimestampFrequency = 0;
        TCompletionCode ret                   = GetGpuTimestampFrequency( &gpuTimestampFrequency );
        MD_CHECK_CC_RET_A( m_adapterId, ret );

        MD_ASSERT_A( m_adapterId, gpuTimestampFrequency != 0 );

        // 2. Get GpuTimestampTicks
        uint64_t gpuTimestampTicks = 0;
        ret                        = GetGpuTimestampTicks( &gpuTimestampTicks );
        MD_CHECK_CC_RET_A( m_adapterId, ret );

        // 3. Convert GpuTimestamp to ns
        *gpuTimestampNs = metricsDevice.ConvertGpuTimestampToNs( gpuTimestampTicks, gpuTimestampFrequency );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetGpuTimestampTicks
    //
    // Description:
    //     Reads GPU timestamp in ticks from GPU timestamp register through REG_READ
    //     IOCTL.
    //
    // Input:
    //     uint64_t* gpuTimestampTicks - (OUT) GPU timestamp in ticks
    //
    // Output:
    //     TCompletionCode             - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetGpuTimestampTicks( uint64_t* gpuTimestampTicks )
    {
        MD_CHECK_PTR_RET_A( m_adapterId, gpuTimestampTicks, CC_ERROR_INVALID_PARAMETER );

        struct drm_i915_reg_read regReadParams = {
            0,
        };
        regReadParams.offset = MD_TIMESTAMP_LOW_OFFSET | 1; // '| 1' to read low and high part separately. This is how kernel handles
                                                            // flags in REG_READ (kind of hack) - registers are naturally aligned so there's place for flags.

        int32_t ioctlRet = SendIoctl( m_DrmDeviceHandle, DRM_IOCTL_I915_REG_READ, &regReadParams );
        if( ioctlRet )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Failed to send DRM_IOCTL_I915_REG_READ ioctl" );
            return CC_ERROR_GENERAL;
        }

        *gpuTimestampTicks = regReadParams.val;
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetCpuTimestampNs
    //
    // Description:
    //     Returns the CPU timestamp in nanoseconds, based on clock monotonic or
    //     std::chrono (depending on OS).
    //     Based on iStdLib's GetTimestampCounter().
    //
    // Input:
    //     uint64_t* cpuTimestampNs - (OUT) CPU timestamp in nanoseconds
    //
    // Output:
    //     TCompletionCode          - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetCpuTimestampNs( uint64_t* cpuTimestampNs )
    {
        MD_CHECK_PTR_RET_A( m_adapterId, cpuTimestampNs, CC_ERROR_INVALID_PARAMETER );

        struct timespec time;
        if( clock_gettime( CLOCK_MONOTONIC, &time ) )
        {
            return CC_ERROR_GENERAL;
        }
        *cpuTimestampNs = (uint64_t) time.tv_nsec + (uint64_t) time.tv_sec * (uint64_t) MD_NSEC_PER_SEC;

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetOaBufferCount
    //
    // Description:
    //     Returns oa buffer count for current platform.
    //
    // Input:
    //     CMetricsDevice& metricsDevice - (IN) metrics device
    //     uint32_t&       oaBufferCount - (OUT) oa buffer count
    //
    // Output:
    //     TCompletionCode               - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetOaBufferCount( CMetricsDevice& metricsDevice, uint32_t& oaBufferCount )
    {
        const uint32_t adapterId = metricsDevice.GetAdapter().GetAdapterId();

        oaBufferCount = 1; // OAG/OA buffer

        auto subDevices = metricsDevice.GetAdapter().GetSubDevices();
        if( IsOamSupported() && subDevices.IsSupported() )
        {
            const uint32_t subDeviceIndex          = metricsDevice.GetSubDeviceIndex();
            const uint32_t videoEngineCount        = subDevices.GetClassInstancesCount( subDeviceIndex, I915_ENGINE_CLASS_VIDEO );
            const uint32_t videoEnhanceEngineCount = subDevices.GetClassInstancesCount( subDeviceIndex, I915_ENGINE_CLASS_VIDEO_ENHANCE );

            if( videoEngineCount != videoEnhanceEngineCount )
            {
                MD_LOG_A( adapterId, LOG_ERROR, "Video engine count (%u) and video enhance engine count (%u) mismatch.", videoEngineCount, videoEnhanceEngineCount );
                return CC_ERROR_GENERAL;
            }

            oaBufferCount += videoEngineCount;
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //   CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetGtMaxSubslicePerSlice
    //
    // Description:
    //     Returns information about active subslices on GPU. For platforms <= SKL subslice size '3'
    //     is used to preserve backward compatibility with MDAPI metric equation definitions
    //     Based on __InstrGetGtMaxSubslicePerSlice().
    //
    // Output:
    //     uint32_t - max subslices per slice
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CDriverInterfaceLinuxPerf::GetGtMaxSubslicePerSlice()
    {
        const TGfxDeviceInfo* gfxDeviceInfo = nullptr;
        auto                  result        = GetGfxDeviceInfo( &gfxDeviceInfo );

        if( result != CC_OK )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "WARNING: Failed to get platform ID" );
            return MD_MAX_SUBSLICE_PER_SLICE;
        }

        switch( gfxDeviceInfo->PlatformIndex )
        {
            case GENERATION_HSW:
            case GENERATION_BDW:
            case GENERATION_SKL:
            case GENERATION_BXT:
            case GENERATION_KBL:
            case GENERATION_CFL:
            case GENERATION_GLK:
                return MD_MAX_SUBSLICE_PER_SLICE_OLD;
            case GENERATION_ICL:
            case GENERATION_EHL:
            case GENERATION_PVC:
                return MD_MAX_SUBSLICE_PER_SLICE;
            case GENERATION_TGL:
            case GENERATION_DG1:
            case GENERATION_RKL:
            case GENERATION_ADLP:
            case GENERATION_ADLS:
            case GENERATION_ADLN:
            case GENERATION_XEHP_SDV:
            case GENERATION_ACM:
            case GENERATION_MTL:
                return MD_MAX_DUALSUBSLICE_PER_SLICE * MD_MAX_SUBSLICE_PER_DSS;
            default:
                MD_LOG_A( m_adapterId, LOG_WARNING, "WARNING: Unsupported platform, default MaxSubslicePerSlice used" );
                return MD_MAX_SUBSLICE_PER_SLICE;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //   CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetGtMaxDualSubslicePerSlice
    //
    // Description:
    //     Returns information about active dual subslices on GPU.
    //
    // Output:
    //     uint32_t - max dual subslices per slice
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CDriverInterfaceLinuxPerf::GetGtMaxDualSubslicePerSlice()
    {
        const TGfxDeviceInfo* gfxDeviceInfo = nullptr;
        auto                  result        = GetGfxDeviceInfo( &gfxDeviceInfo );

        if( result != CC_OK )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "WARNING: Failed to get platform ID" );
            return MD_MAX_DUALSUBSLICE_PER_SLICE;
        }

        switch( gfxDeviceInfo->PlatformIndex )
        {
            case GENERATION_TGL:
            case GENERATION_DG1:
            case GENERATION_ADLP:
            case GENERATION_ADLS:
            case GENERATION_ADLN:
            case GENERATION_RKL:
                return MD_MAX_DUALSUBSLICE_PER_SLICE;
            case GENERATION_XEHP_SDV:
            case GENERATION_ACM:
            case GENERATION_MTL:
                return MD_DUALSUBSLICE_PER_SLICE;
            default:
                return MD_MAX_DUALSUBSLICE_PER_SLICE;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //   CDriverInterfaceLinuxPerf
    //
    // Method:
    //     IsXePlus
    //
    // Description:
    //     Returns information if current platform is Xe+.
    //
    // Output:
    //     bool - true if current platform is Xe+
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CDriverInterfaceLinuxPerf::IsXePlus()
    {
        const TGfxDeviceInfo* gfxDeviceInfo = nullptr;

        auto ret = GetGfxDeviceInfo( &gfxDeviceInfo );
        if( ret != CC_OK )
        {
            MD_LOG_A( m_adapterId, LOG_WARNING, "WARNING: Cannot get gfx device info" );
            return false;
        }

        switch( gfxDeviceInfo->PlatformIndex )
        {
            case GENERATION_TGL:
            case GENERATION_DG1:
            case GENERATION_XEHP_SDV:
            case GENERATION_PVC:
            case GENERATION_ACM:
            case GENERATION_RKL:
            case GENERATION_ADLP:
            case GENERATION_ADLS:
            case GENERATION_ADLN:
            case GENERATION_MTL:
                return true;
            default:
                return false;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //   CDriverInterfaceLinuxPerf
    //
    // Method:
    //     IsDualSubsliceSupported
    //
    // Description:
    //     Returns information if current platform supports dual sub slices
    //
    // Output:
    //     bool - true if current platform supports dual sub slices
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CDriverInterfaceLinuxPerf::IsDualSubsliceSupported()
    {
        const TGfxDeviceInfo* gfxDeviceInfo = nullptr;

        TCompletionCode ret = GetGfxDeviceInfo( &gfxDeviceInfo );
        if( ret != CC_OK )
        {
            MD_LOG_A( m_adapterId, LOG_WARNING, "WARNING: Cannot get gfx device info" );
            return false;
        }

        switch( gfxDeviceInfo->PlatformIndex )
        {
            case GENERATION_TGL:
            case GENERATION_DG1:
            case GENERATION_XEHP_SDV:
            case GENERATION_ACM:
            case GENERATION_RKL:
            case GENERATION_ADLP:
            case GENERATION_ADLS:
            case GENERATION_ADLN:
            case GENERATION_MTL:
                return true;
            default:
                return false;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     MapDeviceInfoToInstrGtTypeGfxVer12
    //
    // Description:
    //     Gfx version 12 platforms need additional logic to determine their type using slice mask,
    //     device id and PCI revision id.
    //
    // Input:
    //     const TGfxDeviceInfo* gfxDeviceInfo - basic device information.
    //     CMetricsDevice* metricsDevice       - metrics device.
    //
    // Output:
    //     TGfxGtType                          - graphics GT type, used by Intel driver
    //
    //////////////////////////////////////////////////////////////////////////////
    TGfxGtType CDriverInterfaceLinuxPerf::MapDeviceInfoToInstrGtTypeGfxVer12( const TGfxDeviceInfo* gfxDeviceInfo, CMetricsDevice* metricsDevice )
    {
        TGfxGtType      gtType                 = GFX_GTTYPE_UNDEFINED;
        bool            isAdderWorkaroundValid = false;
        bool            isAdderWaNeeded        = false;
        TCompletionCode ret                    = CC_OK;
        int64_t         sliceMask              = 0;

        MD_CHECK_PTR_RET_A( m_adapterId, metricsDevice, gtType );
        ret = GetSubsliceMask( &sliceMask, metricsDevice );
        if( ret != CC_OK )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "Unable to obtain dual-subslice/subslice mask while defining GT type" );
            return gtType;
        }

        if( ( sliceMask & SLICES0TO3 ) && ( sliceMask & SLICES4TO7 ) )
        {
            isAdderWorkaroundValid = true;
            isAdderWaNeeded        = true;
        }
        else if( !( ( sliceMask & SLICES4AND5 ) && ( sliceMask & SLICES6AND7 ) ) )
        {
            isAdderWorkaroundValid = true;
        }

        if( IsPlatformMatch( gfxDeviceInfo->PlatformIndex, GENERATION_ACM ) )
        {
            drmDevicePtr drmDevice = nullptr;

            if( drmGetDevice( m_DrmDeviceHandle, &drmDevice ) != 0 || drmDevice == nullptr )
            {
                MD_LOG_A( m_adapterId, LOG_ERROR, "PCI revision_id not recognized. drmGetDevice failed." );
                return gtType;
            }

            switch( drmDevice->deviceinfo.pci->device_id )
            {
                case 0x4F80:
                case 0x4F81:
                case 0x4F82:
                case 0x4F83:
                case 0x4F84:
                case 0x5690:
                case 0x5691:
                case 0x5692:
                case 0x56A0:
                case 0x56A1:
                case 0x56A2:
                case 0x56C0:
                {
                    MD_LOG_A( m_adapterId, LOG_INFO, "PCI revision_id is %u", drmDevice->deviceinfo.pci->revision_id );
                    if( drmDevice->deviceinfo.pci->revision_id > 1 )
                    {
                        gtType = GFX_GTTYPE_GT3; // 512
                    }
                    break;
                }
                case 0x4F85:
                case 0x4F86:
                case 0x5696:
                case 0x5697:
                case 0x56A3:
                case 0x56A4:
                case 0x56B2:
                case 0x56B3:
                {
                    gtType = GFX_GTTYPE_GT2; // 256
                    break;
                }
                case 0x4F87:
                case 0x4F88:
                case 0x5693:
                case 0x5694:
                case 0x5695:
                case 0x56A5:
                case 0x56A6:
                case 0x56B0:
                case 0x56B1:
                case 0x56C1:
                {
                    gtType = GFX_GTTYPE_GT1; // 128
                    break;
                }
            }
        }
        else if( IsPlatformMatch( gfxDeviceInfo->PlatformIndex, GENERATION_XEHP_SDV ) )
        {
            if( isAdderWorkaroundValid )
            {
                gtType = isAdderWaNeeded ? GFX_GTTYPE_GT1 : GFX_GTTYPE_GT2;
            }
        }
        else if( IsPlatformMatch( gfxDeviceInfo->PlatformIndex, GENERATION_PVC ) )
        {
            drmDevicePtr drmDevice = nullptr;

            if( drmGetDevice( m_DrmDeviceHandle, &drmDevice ) != 0 || drmDevice == nullptr )
            {
                MD_LOG_A( m_adapterId, LOG_ERROR, "PCI revision_id not recognized. drmGetDevice failed." );
                return gtType;
            }

            MD_LOG_A( m_adapterId, LOG_INFO, "PCI revision_id is %u", drmDevice->deviceinfo.pci->revision_id );

            if( drmDevice->deviceinfo.pci->revision_id >= 0x1E )
            {
                gtType = GFX_GTTYPE_GT2;
            }
            else
            {
                gtType = GFX_GTTYPE_GT1;
            }
        }

        m_CachedGfxDeviceInfo.GtType = gtType;

        return gtType;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Function:
    //     CalcEnabledBits
    //
    // Description:
    //     Helper function to get number of ENABLED bits on given bitmask value
    //     Based on __InstrCalcEnabledBits.
    //
    // Input:
    //     uint64_t value - input value
    //     uint64_t mask  - valid bits
    //
    // Output:
    //     uint32_t       - number of enabled bits
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CDriverInterfaceLinuxPerf::CalculateEnabledBits( uint64_t value, uint64_t mask /* = UINT64_MAX */ )
    {
        uint32_t count = 0;

        value &= mask;
        while( mask )
        {
            count += ( value & 1 );
            value >>= 1;
            mask >>= 1;
        }

        return count;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetTimerPeriodExponent
    //
    // Description:
    //     Changes the given timer period in nanoseconds to the OA timer period exponent.
    //     Periods are rounded down to the nearest exponent.
    //     Based on documentation: "StrobePeriod = MinimumTimeStampPeriod * 2^( TimerExponent + 1 )".
    //
    // Input:
    //     uint32_t nsTimerPeriod - timer period in nanoseconds
    //
    // Output:
    //     uint32_t               - timer period exponent
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CDriverInterfaceLinuxPerf::GetTimerPeriodExponent( uint32_t nsTimerPeriod )
    {
        // 1. Get minimum GPU timestamp period
        uint64_t timestampPeriodNs = 0;
        GetGpuTimestampPeriodNs( &timestampPeriodNs );
        if( !timestampPeriodNs )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Invalid GPU Timestamp Period" );
            return 0;
        }

        // 2. Compute timer exponent
        return log2( nsTimerPeriod / timestampPeriodNs ) - 1;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetNsTimerPeriod
    //
    // Description:
    //     Changes the given timer period exponent to the OA timer period in nanoseconds.
    //
    // Input:
    //     uint32_t timerPeriodExponent - timer period exponent
    //
    // Output:
    //     uint32_t                     - timer period in nanoseconds
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CDriverInterfaceLinuxPerf::GetNsTimerPeriod( uint32_t timerPeriodExponent )
    {
        // 1. Get minimum GPU timestamp period
        uint64_t timestampPeriodNs = 0;
        GetGpuTimestampPeriodNs( &timestampPeriodNs );
        if( !timestampPeriodNs )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Invalid GPU Timestamp Period" );
            return 0;
        }

        // 2. Compute timer period (StrobePeriod = MinimumTimeStampPeriod * 2^( TimerExponent + 1 ))
        return timestampPeriodNs * ( 1 << ( timerPeriodExponent + 1 ) );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     CalculateOaBufferSize
    //
    // Description:
    //     Changes the requested OA buffer size to the nearest power of 2 value.
    //     Size is rounded down.
    //
    // Input:
    //     const uint32_t requestedBufferSize - requested oa buffer size in bytes
    //
    // Output:
    //     uint32_t                           - power of 2 oa buffer size in bytes
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CDriverInterfaceLinuxPerf::CalculateOaBufferSize( const uint32_t requestedBufferSize )
    {
        auto     ret             = CC_OK;
        auto     out             = GTDIDeviceInfoParamExtOut();
        uint32_t maxOaBufferSize = MD_OA_BUFFER_SIZE_MAX;
        uint32_t minOaBufferSize = MD_OA_BUFFER_SIZE_MAX; // default 16 mb value

        ret = SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_OA_BUFFER_SIZE_MAX, &out );
        if( ret != CC_OK )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Cannot calculate oa buffer size. Using default value: %u", maxOaBufferSize );
            return maxOaBufferSize;
        }
        maxOaBufferSize = out.ValueUint32;

        ret = SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_OA_BUFFER_SIZE_MIN, &out );
        if( ret != CC_OK )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Cannot calculate oa buffer size. Using default value: %u", minOaBufferSize );
            return minOaBufferSize;
        }
        minOaBufferSize = out.ValueUint32;

        if( requestedBufferSize < minOaBufferSize )
        {
            MD_LOG_A( m_adapterId, LOG_DEBUG, "Requested oa buffer size (%u bytes) is lower than minimum oa buffer size (%u bytes)", requestedBufferSize, minOaBufferSize );
            return minOaBufferSize;
        }
        else if( requestedBufferSize > maxOaBufferSize )
        {
            MD_LOG_A( m_adapterId, LOG_DEBUG, "Requested oa buffer size (%u bytes) is higher than maximum oa buffer size (%u bytes)", requestedBufferSize, maxOaBufferSize );
            return maxOaBufferSize;
        }

        return std::pow( 2, std::floor( log2( requestedBufferSize ) ) );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapterHandleLinux
    //
    // Method:
    //     CAdapterHandleLinux
    //
    // Description:
    //     Constructor.
    //
    // Input:
    //     int32_t adapterHandle - adapter handle in a system format
    //
    //////////////////////////////////////////////////////////////////////////////
    CAdapterHandleLinux::CAdapterHandleLinux( int32_t adapterHandle )
        : m_handle( adapterHandle )
    {
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapterHandleLinux
    //
    // Method:
    //     ~CAdapterHandleLinux
    //
    // Description:
    //     Destructor (handle not closed on purpose).
    //
    //////////////////////////////////////////////////////////////////////////////
    CAdapterHandleLinux::~CAdapterHandleLinux()
    {
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapterHandleLinux
    //
    // Method:
    //     Close
    //
    // Description:
    //     Closes adapter handle.
    //
    // Input:
    //     const uint32_t adapterId - adapter id for the purpose of logging
    //
    // Output:
    //     TCompletionCode - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CAdapterHandleLinux::Close( const uint32_t adapterId )
    {
        if( IsValid() )
        {
            if( close( m_handle ) )
            {
                MD_LOG_A( adapterId, LOG_ERROR, "Closing adapter failed, %d", m_handle );
                MD_LOG_EXIT_A( adapterId );
                return CC_ERROR_GENERAL;
            }
            m_handle = InvalidValue;
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapterHandleLinux
    //
    // Method:
    //     IsValid
    //
    // Description:
    //     Checks if the underlying adapter handle is valid.
    //
    // Output:
    //     bool - true if handle is valid
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CAdapterHandleLinux::IsValid() const
    {
        return m_handle != InvalidValue;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapterHandleLinux
    //
    // Method:
    //     operator int()
    //
    // Description:
    //     Returns adapter handle in the system format.
    //
    // Output:
    //     int32_t - DRM device file descriptor
    //
    //////////////////////////////////////////////////////////////////////////////
    CAdapterHandleLinux::operator int() const
    {
        return m_handle;
    }

} // namespace MetricsDiscoveryInternal
