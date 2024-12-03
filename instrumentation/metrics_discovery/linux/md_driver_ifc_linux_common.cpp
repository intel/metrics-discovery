/*========================== begin_copyright_notice ============================

Copyright (C) 2023-2024 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_driver_ifc_linux_common.cpp

//     Abstract:   C++ common implementation for Linux

#include "md_driver_ifc_linux_perf.h"
#include "md_driver_ifc_linux_xe.h"
#include "md_adapter.h"
#include "md_metrics_device.h"
#include "md_metric_set.h"
#include "md_utils.h"
#include "md_gfx_device_info.h"

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

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
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
        : m_count( 1 )
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
        std::unique_lock<std::mutex> lock( m_mutex );
        ++m_count;
        m_conditionVariable.notify_one();
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
        std::unique_lock<std::mutex> lock( m_mutex );
        while( !m_count )
        {
            m_conditionVariable.wait( lock );
        }
        --m_count;
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
        std::unique_lock<std::mutex> lock( m_mutex );

        bool semLocking = false;
        if( m_count == 0 )
        {
            auto result = m_conditionVariable.wait_for( lock, std::chrono::milliseconds( timeoutMs ) );
            if( ( result == std::cv_status::no_timeout ) && ( m_count > 0 ) )
            {
                --m_count;
                semLocking = true;
            }
        }
        else // (m_count > 0)
        {
            --m_count;
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
        std::unique_lock<std::mutex> lock( m_mutex );
        if( m_count )
        {
            --m_count;
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
        return m_count;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterface
    //
    // Method:
    //     CreateInstance
    //
    // Description:
    //     Returns instance of CDriverInterface for Linux supporting Perf.
    //
    // Output:
    //     CDriverInterface* - Pointer to new allocated object of CDriverInterfaceLinuxCommon
    //
    //////////////////////////////////////////////////////////////////////////////
    CDriverInterface* CDriverInterface::CreateInstance( CAdapterHandle& adapterHandle )
    {
        // Initialize DRM.
        CDriverInterface* driverInterface = nullptr;

        switch( CDriverInterfaceLinuxCommon::GetDrmVersion( static_cast<CAdapterHandleLinux&>( adapterHandle ) ) )
        {
            case DRM_VERSION_I915:
                MD_LOG( LOG_INFO, "Initializing i915..." );
                driverInterface = new( std::nothrow ) CDriverInterfaceLinuxPerf( adapterHandle );
                break;

            case DRM_VERSION_XE:
                MD_LOG( LOG_INFO, "Initializing XE KMD..." );
                driverInterface = new( std::nothrow ) CDriverInterfaceLinuxXe( adapterHandle );
                break;

            default:
                MD_LOG( LOG_ERROR, "ERROR: Wrong DRM version!" );
                break;
        }

        if( ( driverInterface != nullptr ) && ( driverInterface->CreateContext() == false ) )
        {
            MD_SAFE_DELETE( driverInterface );
        }

        return driverInterface;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterface
    //
    // Method:
    //     ReleaseResources
    //
    // Description:
    //     Cleans-up Linux Driver Interface resources.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CDriverInterface::ReleaseResources()
    {
    }

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
    //
    // Output:
    //     TCompletionCode - result of operation (*CC_OK* is OK)
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterface::GetAvailableAdapters( std::vector<TAdapterData>& adapters )
    {
        // The maximum number of drm devices is 64, see:
        // https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git/tree/drivers/gpu/drm/drm_drv.c#n110
        const uint32_t DRM_MAX_DEVICES = 64;

        std::array<drmDevicePtr, DRM_MAX_DEVICES> devices          = {};
        int32_t                                   availableDevices = drmGetDevices( devices.data(), devices.size() );

        if( availableDevices < 0 )
        {
            MD_LOG( LOG_ERROR, "ERROR: Failed to get the list of drm devices" );
            return CC_ERROR_GENERAL;
        }

#define IS_DRM_NODE_AVAILABLE( _nodes, _node_type ) ( ( _nodes ) & ( 1 << ( _node_type ) ) )

        for( int32_t i = 0; i < availableDevices; ++i )
        {
            if( devices[i] == nullptr )
            {
                MD_LOG( LOG_ERROR, "ERROR: Uninitialized drm device" );
                continue;
            }

            const drmDevice& device    = *devices[i];
            int32_t          drmFd     = -1;
            int32_t          minorBase = 0;

            if( IS_DRM_NODE_AVAILABLE( device.available_nodes, DRM_NODE_RENDER ) )
            {
                MD_LOG( LOG_DEBUG, "Open render node '%s'", device.nodes[DRM_NODE_RENDER] );
                drmFd     = open( device.nodes[DRM_NODE_RENDER], O_RDWR );
                minorBase = DRM_NODE_RENDER * DRM_MAX_DEVICES;
            }

            if( drmFd == -1 && IS_DRM_NODE_AVAILABLE( device.available_nodes, DRM_NODE_PRIMARY ) )
            {
                MD_LOG( LOG_DEBUG, "Open primary node '%s'", device.nodes[DRM_NODE_PRIMARY] );
                drmFd     = open( device.nodes[DRM_NODE_PRIMARY], O_RDWR );
                minorBase = DRM_NODE_PRIMARY * DRM_MAX_DEVICES;
            }

            if( drmFd == -1 )
            {
                MD_LOG( LOG_ERROR, "ERROR: Failed to open drm device" );
                continue;
            }

            drmVersionPtr deviceVersion = drmGetVersion( drmFd );

            if( deviceVersion == nullptr )
            {
                MD_LOG( LOG_ERROR, "ERROR: Cannot get version for drm device" );

                close( drmFd );
                continue;
            }

            constexpr uint32_t i915NameLength = sizeof( "i915" ) - 1;
            constexpr uint32_t xeNameLength   = sizeof( "xe" ) - 1;

            if( ( deviceVersion->name_len != i915NameLength || iu_strncmp( deviceVersion->name, "i915", i915NameLength ) ) &&
                ( deviceVersion->name_len != xeNameLength || iu_strncmp( deviceVersion->name, "xe", xeNameLength ) ) )
            {
                MD_LOG( LOG_DEBUG, "Skip non-Intel device '%s'", ( deviceVersion->name_len && deviceVersion->name ? deviceVersion->name : "" ) );

                drmFreeVersion( deviceVersion );
                close( drmFd );
                continue;
            }

            drmFreeVersion( deviceVersion );

            TAdapterData adapter = {};

            // Get platform info
            TGfxDeviceInfo gfxDeviceInfo = {};

            TCompletionCode ret = CDriverInterfaceLinuxCommon::GetGfxDeviceInfo( device.deviceinfo.pci->device_id, gfxDeviceInfo );

            if( ret != CC_OK || gfxDeviceInfo.PlatformIndex == GTDI_PLATFORM_MAX )
            {
                MD_LOG( LOG_ERROR, "ERROR: Cannot detect platform index" );

                close( drmFd );
                continue;
            }

            adapter.Params.Platform = gfxDeviceInfo.PlatformIndex;
            adapter.Params.Type     = CDriverInterfaceLinuxCommon::GetAdapterType( gfxDeviceInfo );

            // Get system id (major/minor pair)
            struct stat sbuf = {};
            if( fstat( drmFd, &sbuf ) )
            {
                MD_LOG( LOG_ERROR, "ERROR: Cannot get system id" );

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

                adapter.Params.ShortName = GetCopiedCString( drmGetDeviceNameFromFd2( drmFd ), IU_ADAPTER_ID_UNKNOWN );
            }

            adapter.Handle = new( std::nothrow ) CAdapterHandleLinux( drmFd ); // Important: adapterData.Handle has to be deleted later!
            if( adapter.Handle == nullptr )
            {
                MD_LOG( LOG_ERROR, "ERROR: Cannot create adapter handle" );

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
    //     CDriverInterfaceLinuxCommon
    //
    // Method:
    //     CDriverInterfaceLinuxCommon constructor
    //
    // Description:
    //     Creates driver context.
    //
    //////////////////////////////////////////////////////////////////////////////
    CDriverInterfaceLinuxCommon::CDriverInterfaceLinuxCommon( CAdapterHandle& adapterHandle, const TDrmVersion drmVersion )
        : m_DrmDeviceHandle( static_cast<CAdapterHandleLinux&>( adapterHandle ) )
        , m_DrmCardNumber( -1 )
        , m_DrmVersion( drmVersion )
        , m_CachedBoostFrequency( 0 )
        , m_CachedMinFrequency( 0 )
        , m_CachedMaxFrequency( 0 )
        , m_CachedGfxDeviceInfo{ GTDI_PLATFORM_MAX, GFX_GTTYPE_UNDEFINED, 0, 0 }
        , m_CachedDeviceId( -1 )
        , m_CachedRevisionId( -1 )
    {
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
    //
    // Method:
    //     CDriverInterfaceLinuxCommon destructor
    //
    // Description:
    //     Deletes driver context.
    //
    //////////////////////////////////////////////////////////////////////////////
    CDriverInterfaceLinuxCommon::~CDriverInterfaceLinuxCommon()
    {
        MD_LOG_ENTER_A( m_adapterId );
        DeleteContext();
        MD_LOG_EXIT_A( m_adapterId );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
    //
    // Method:
    //     DeleteContext
    //
    // Description:
    //     Deletes driver context. Closes Perf stream if opened and closes DRM.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CDriverInterfaceLinuxCommon::DeleteContext()
    {
        DeinitializeIntelDrm();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
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
    TCompletionCode CDriverInterfaceLinuxCommon::ForceSupportDisable()
    {
        // Intentionally - not supported
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
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
    TCompletionCode CDriverInterfaceLinuxCommon::SendSupportEnableEscape( bool enable )
    {
        // Not needed on Linux Perf
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
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
    //     CMetricsDevice&           metricsDevice - a reference to device
    //
    // Output:
    //     TCompletionCode                         - *CC_OK* means succeess
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxCommon::SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM param, GTDIDeviceInfoParamExtOut& out, CMetricsDevice& metricsDevice )
    {
        TCompletionCode       ret           = CC_OK;
        GTDI_PLATFORM_INDEX   platformId    = GTDI_PLATFORM_MAX;
        const TGfxDeviceInfo* gfxDeviceInfo = nullptr;

        ret = GetGfxDeviceInfo( gfxDeviceInfo );
        MD_CHECK_CC_RET_A( m_adapterId, ret );
        platformId = gfxDeviceInfo->PlatformIndex;

        switch( param )
        {
            case GTDI_DEVICE_PARAM_EU_CORES_TOTAL_COUNT:
            {
                ret = GetEuCoresTotalCount( out, metricsDevice );
                MD_CHECK_CC_RET_A( m_adapterId, ret );
                break;
            }

            case GTDI_DEVICE_PARAM_EU_CORES_PER_SUBSLICE_COUNT:
            {
                ret = GetEuCoresPerSubsliceCount( out, metricsDevice );
                MD_CHECK_CC_RET_A( m_adapterId, ret );
                break;
            }

            case GTDI_DEVICE_PARAM_DUALSUBSLICES_TOTAL_COUNT:
            {
                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out.ValueUint32 = 0;

                if( IsDualSubsliceSupported() )
                {
                    int64_t dualSubsliceMask = 0;

                    ret = GetSubsliceMask( dualSubsliceMask, metricsDevice );
                    MD_CHECK_CC_RET_A( m_adapterId, ret );

                    out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                    out.ValueUint32 = CalculateEnabledBits( dualSubsliceMask );
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
                int64_t subsliceMask = 0;

                ret = GetSubsliceMask( subsliceMask, metricsDevice );
                MD_CHECK_CC_RET_A( m_adapterId, ret );

                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out.ValueUint32 = CalculateEnabledBits( subsliceMask );

                if( IsDualSubsliceSupported() && param != GTDI_DEVICE_PARAM_SAMPLERS_COUNT )
                {
                    out.ValueUint32 *= MD_MAX_SUBSLICE_PER_DSS;
                }
                break;
            }

            case GTDI_DEVICE_PARAM_SLICES_COUNT:
            {
                int32_t sliceMask = 0;

                ret = GetSliceMask( sliceMask, metricsDevice );
                MD_CHECK_CC_RET_A( m_adapterId, ret );

                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out.ValueUint32 = CalculateEnabledBits( static_cast<uint64_t>( sliceMask ), static_cast<uint64_t>( 0xFFFFFFFF ) );
                MD_ASSERT_A( m_adapterId, out.ValueUint32 <= MD_MAX_SLICE );
                break;
            }

            case GTDI_DEVICE_PARAM_MAX_SLICE:
            {
                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out.ValueUint32 = GetGtMaxSlice();
                break;
            }

            case GTDI_DEVICE_PARAM_MAX_SUBSLICE_PER_SLICE:
            {
                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out.ValueUint32 = GetGtMaxSubslicePerSlice();
                break;
            }

            case GTDI_DEVICE_PARAM_MAX_DUALSUBSLICE_PER_SLICE:
            {
                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out.ValueUint32 = GetGtMaxDualSubslicePerSlice();
                break;
            }

            case GTDI_DEVICE_PARAM_NUMBER_OF_RENDER_OUTPUT_UNITS:
            {
                int32_t sliceMask = 0;

                ret = GetSliceMask( sliceMask, metricsDevice );
                MD_CHECK_CC_RET_A( m_adapterId, ret );

                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out.ValueUint32 = MD_NUM_PIXELS_OUT_PER_CLOCK * CalculateEnabledBits( static_cast<uint64_t>( sliceMask ) ); // pixels_out_per_clock * sliceCount
                break;
            }

            case GTDI_DEVICE_PARAM_EU_THREADS_COUNT:
            {
                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out.ValueUint32 = gfxDeviceInfo->ThreadsPerEu;
                break;
            }

            case GTDI_DEVICE_PARAM_NUMBER_OF_SHADING_UNITS:
            {
                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out.ValueUint32 = MD_EU_SIMD_SIZE_PER_CLOCK * gfxDeviceInfo->ThreadsPerEu; // eu_simd_size_per_clock * euThreadCount
                break;
            }

            case GTDI_DEVICE_PARAM_SUBSLICES_MASK:
            {
                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT64;
                out.ValueUint64 = 0;

                if( IsDualSubsliceSupported() )
                {
                    ret = CC_ERROR_NOT_SUPPORTED;
                }
                else
                {
                    int64_t subSliceMask = 0;
                    ret                  = GetSubsliceMask( subSliceMask, metricsDevice );
                    MD_CHECK_CC_RET( ret );

                    out.ValueUint64 = static_cast<uint64_t>( subSliceMask );
                }

                break;
            }

            case GTDI_DEVICE_PARAM_DUALSUBSLICES_MASK:
            {
                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT64;
                out.ValueUint64 = 0;

                if( IsDualSubsliceSupported() )
                {
                    // Return value is a mask of enabled dual subslices
                    int64_t dualSubsliceMask = 0;
                    ret                      = GetSubsliceMask( dualSubsliceMask, metricsDevice );
                    MD_CHECK_CC_RET_A( m_adapterId, ret );

                    out.ValueUint64 = static_cast<uint64_t>( dualSubsliceMask );
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

                ret = GetSliceMask( sliceMask, metricsDevice );
                MD_CHECK_CC_RET_A( m_adapterId, ret );

                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out.ValueUint32 = sliceMask;

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
                uint64_t* minFrequency = ( param == GTDI_DEVICE_PARAM_GPU_CORE_MIN_FREQUENCY ) ? &out.ValueUint64 : nullptr;
                uint64_t* maxFrequency = ( param == GTDI_DEVICE_PARAM_GPU_CORE_MAX_FREQUENCY ) ? &out.ValueUint64 : nullptr;
                uint64_t* actFrequency = ( param == GTDI_DEVICE_PARAM_GPU_CORE_FREQUENCY ) ? &out.ValueUint64 : nullptr;

                ret = GetGpuFrequencyInfo( metricsDevice, minFrequency, maxFrequency, actFrequency, nullptr );
                MD_CHECK_CC_RET_A( m_adapterId, ret );

                out.ValueType = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT64;
                break;
            }

            case GTDI_DEVICE_PARAM_GPU_STATIC_FREQUENCY_OVERRIDE:
            {
                uint64_t minFrequencyOverride = 0;
                uint64_t maxFrequencyOverride = 0;

                ReadSysFsFile( metricsDevice, SYS_FS_MIN_FREQ_OV, &minFrequencyOverride );
                ReadSysFsFile( metricsDevice, SYS_FS_MAX_FREQ_OV, &maxFrequencyOverride );

                const bool isFrequencyOverrideEnabled = ( minFrequencyOverride != 0 && maxFrequencyOverride != 0 && minFrequencyOverride == maxFrequencyOverride );

                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out.ValueUint32 = isFrequencyOverrideEnabled ? 1 : 0;
                break;
            }

            case GTDI_DEVICE_PARAM_PCI_DEVICE_ID:
            {
                int32_t deviceId = -1;

                ret = GetDeviceId( deviceId );
                MD_CHECK_CC_RET_A( m_adapterId, ret );

                out.ValueUint32 = (uint32_t) deviceId;
                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                break;
            }

            case GTDI_DEVICE_PARAM_REVISION_ID:
            {
                int32_t revisionId = -1;

                ret = GetRevisionId( revisionId );
                MD_CHECK_CC_RET_A( m_adapterId, ret );

                out.ValueUint32 = (uint32_t) revisionId;
                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                break;
            }

            case GTDI_DEVICE_PARAM_PLATFORM_INDEX:
            {
                out.ValueUint32 = static_cast<uint32_t>( platformId );
                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                break;
            }

            case GTDI_DEVICE_PARAM_GT_TYPE:
            {
                // Returning mapped GtType for compatibility reasons
                out.ValueType = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                // PVC GT values is based of revId and slicesMask
                out.ValueUint32 = ( platformId == GENERATION_PVC )
                    ? static_cast<uint32_t>( MapDeviceInfoToInstrGtTypeGfxVer12( *gfxDeviceInfo, metricsDevice ) )
                    : static_cast<uint32_t>( gfxDeviceInfo->GtType );
                break;
            }

            case GTDI_DEVICE_PARAM_APERTURE_SIZE:
                ret = CC_ERROR_NOT_SUPPORTED;
                break;

            case GTDI_DEVICE_PARAM_CAPABILITIES:
                ret = CC_ERROR_NOT_SUPPORTED;
                break;

            case GTDI_DEVICE_PARAM_OA_BUFFER_SIZE_MIN:
            case GTDI_DEVICE_PARAM_OA_BUFFER_SIZE_MAX:
            {
                uint32_t oaBufferSizeMin = 0;
                uint32_t oaBufferSizeMax = 0;

                ret = GetOaBufferSupportedSizes( platformId, oaBufferSizeMin, oaBufferSizeMax );

                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out.ValueUint32 = ( param == GTDI_DEVICE_PARAM_OA_BUFFER_SIZE_MIN ) ? oaBufferSizeMin : oaBufferSizeMax;
                break;
            }

            case GTDI_DEVICE_PARAM_GPU_TIMESTAMP_FREQUENCY:
            {
                uint64_t gpuTimestampFrequency = 0;

                ret = GetGpuTimestampFrequency( gpuTimestampFrequency );
                MD_CHECK_CC_RET_A( m_adapterId, ret );

                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT64;
                out.ValueUint64 = gpuTimestampFrequency;
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
                uint32_t oaBufferCount = 0;

                ret = GetOaBufferCount( metricsDevice, oaBufferCount );
                MD_CHECK_CC_RET_A( m_adapterId, ret );

                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out.ValueUint32 = oaBufferCount;
                break;
            }

            case GTDI_DEVICE_PARAM_L3_BANK_TOTAL_COUNT:
            {
                uint32_t l3BankCount = 0;

                ret = GetL3BankTotalCount( metricsDevice, l3BankCount );
                MD_CHECK_CC_RET_A( m_adapterId, ret );

                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out.ValueUint32 = l3BankCount;
                break;
            }

            case GTDI_DEVICE_PARAM_L3_NODE_TOTAL_COUNT:
            case GTDI_DEVICE_PARAM_SQIDI_TOTAL_COUNT:
            {
                uint32_t l3NodeCount = 0;

                ret = GetL3NodeTotalCount( metricsDevice, l3NodeCount );
                MD_CHECK_CC_RET_A( m_adapterId, ret );

                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out.ValueUint32 = l3NodeCount;
                break;
            }

            case GTDI_DEVICE_PARAM_COMPUTE_ENGINE_TOTAL_COUNT:
            {
                uint32_t computeEngineCount = 0;

                ret = GetComputeEngineTotalCount( metricsDevice, computeEngineCount );
                MD_CHECK_CC_RET_A( m_adapterId, ret );

                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out.ValueUint32 = computeEngineCount;
                break;
            }

            case GTDI_DEVICE_PARAM_COPY_ENGINE_TOTAL_COUNT:
            {
                uint32_t copyEngineCount = 0;

                ret = GetCopyEngineTotalCount( metricsDevice, copyEngineCount );
                MD_CHECK_CC_RET_A( m_adapterId, ret );

                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out.ValueUint32 = copyEngineCount;
                break;
            }

            case GTDI_DEVICE_PARAM_L3_BANK_MASK:
            {
                uint64_t l3BankMask = 0;

                ret = GetL3BankMask( metricsDevice, l3BankMask );
                MD_CHECK_CC_RET_A( m_adapterId, ret );

                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT64;
                out.ValueUint32 = l3BankMask;
                break;
            }

            case GTDI_DEVICE_PARAM_L3_NODE_MASK:
            {
                uint64_t l3NodeMask = 0;

                ret = GetL3NodeMask( metricsDevice, l3NodeMask );
                MD_CHECK_CC_RET_A( m_adapterId, ret );

                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT64;
                out.ValueUint32 = l3NodeMask;
                break;
            }

            case GTDI_DEVICE_PARAM_COPY_ENGINE_MASK:
            {
                uint64_t copyEngineMask = 0;

                ret = GetCopyEngineMask( metricsDevice, copyEngineMask );
                MD_CHECK_CC_RET_A( m_adapterId, ret );

                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT64;
                out.ValueUint32 = copyEngineMask;
                break;
            }

            case GTDI_DEVICE_PARAM_MAX_L3_NODE:
                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out.ValueUint32 = GetGtMaxL3Node();
                break;

            case GTDI_DEVICE_PARAM_MAX_L3_BANK_PER_L3_NODE:
                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out.ValueUint32 = GetGtMaxL3BankPerL3Node();
                break;

            case GTDI_DEVICE_PARAM_MAX_COPY_ENGINE:
                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out.ValueUint32 = GetGtMaxCopyEngine();
                break;

            case GTDI_DEVICE_PARAM_PLATFORM_VERSION:
                out.ValueType   = GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32;
                out.ValueUint32 = gfxDeviceInfo->PlatformVersion;
                break;

            default:
                ret = CC_ERROR_INVALID_PARAMETER;
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
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
    //     CMetricsDevice&            device       - a reference to device
    //
    // Output:
    //     TCompletionCode                         - *CC_OK* means succeess
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxCommon::GetMaxMinOaBufferSize( const GTDI_OA_BUFFER_TYPE oaBufferType, const GTDI_DEVICE_PARAM param, GTDIDeviceInfoParamExtOut& out, CMetricsDevice& device )
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

        return SendDeviceInfoParamEscape( param, out, device );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
    //
    // Method:
    //     SendPmRegsConfig
    //
    // Description:
    //     (ONLY FOR QUERY)
    //     Adds PmRegs configuration to the kernel through i915 Perf or XE OA interface.
    //     configuration is added under a fixed GUID, which is known to the UMD driver.
    //     Configuration added under this GUID is later used as a Query configuration.
    //
    //     Before adding the configuration to a i915 or XE kernel, the previous one (if exists)
    //     is removed.
    //
    // Input:
    //     TRegister**                 regVector      - array of pointers to registers to program
    //     const uint32_t              regCount       - register count
    //     const uint32_t              subDeviceIndex - sub device index
    //     const GTDI_OA_BUFFER_TYPE   oaBufferType   - oa buffer type
    //
    // Output:
    //     TCompletionCode                            - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxCommon::SendPmRegsConfig( TRegister** regVector, const uint32_t regCount, const uint32_t subDeviceIndex, const GTDI_OA_BUFFER_TYPE oaBufferType )
    {
        MD_LOG_ENTER_A( m_adapterId );
        MD_CHECK_PTR_RET_A( m_adapterId, regVector, CC_ERROR_INVALID_PARAMETER );

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
            RemoveOaConfigQuery( guid.c_str() );

            // 2. ADD CONFIG
            ret = AddOaConfig( regVector, regCount, subDeviceIndex, guid.c_str(), addedConfigId );
            MD_ASSERT_A( m_adapterId, addedConfigId != -1 );

            // 3. REMEMBER ADDED CONFIG
            if( ret == CC_OK )
            {
                if( std::find( m_AddedOaConfigs.begin(), m_AddedOaConfigs.end(), addedConfigId ) == m_AddedOaConfigs.end() )
                {
                    m_AddedOaConfigs.push_back( addedConfigId ); // Remember configId for later removal, only if it wasn't added before - may happen when
                                                                 // the config is already added and ID is reused.
                }
            }
            else
            {
                RemoveOaConfig( addedConfigId );
            }
        }

        MD_LOG_EXIT_A( m_adapterId );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
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
    //
    // Output:
    //     TCompletionCode       - *CC_OK* means succeess
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxCommon::SendReadRegsConfig( TRegister** regVector, uint32_t regCount )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
    //
    // Method:
    //     GetPmRegsConfigHandles
    //
    // Description:
    //     Retrieves handles to the Oa, Gp and read regs configuration from the driver.
    //     !READ REGS NOT SUPPORTED ON LINUX YET!
    //
    // Input:
    //     uint32_t* oaConfigHandle - (OUT) OA config handle in KMD
    //     uint32_t* gpConfigHandle - (OUT) GP config handle in KMD
    //     uint32_t* rrConfigHandle - (OUT) Read regs config handle in KMD
    //
    // Output:
    //     TCompletionCode           - *CC_OK* means succeess
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxCommon::GetPmRegsConfigHandles( uint32_t* oaConfigHandle, uint32_t* gpConfigHandle, uint32_t* rrConfigHandle )
    {
        // Not supported on Linux - returning CC_OK on purpose
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
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
    TCompletionCode CDriverInterfaceLinuxCommon::ValidatePmRegsConfig( TRegister* regVector, uint32_t regCount, uint32_t platformId )
    {
        // Not supported on Linux - returning CC_OK on purpose
        return CC_ERROR_NOT_SUPPORTED;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
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
    TCompletionCode CDriverInterfaceLinuxCommon::SendGetCtxIdTagsEscape( TGetCtxTagsIdParams* params )
    {
        // Not supported on Linux - returning CC_OK on purpose
        return CC_ERROR_NOT_SUPPORTED;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
    //
    // Method:
    //     IsOaBufferSupported
    //
    // Description:
    //     Returns information is given oa buffer type is supported.
    //
    // Input:
    //     const GTDI_OA_BUFFER_TYPE oaBufferType  - oa buffer type
    //     CMetricsDevice&           metricsDevice - metrics device
    //
    // Output:
    //     bool                                    - true if supported
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CDriverInterfaceLinuxCommon::IsOaBufferSupported( const GTDI_OA_BUFFER_TYPE oaBufferType, CMetricsDevice& metricsDevice )
    {
        GTDIDeviceInfoParamExtOut out = {};
        auto                      ret = SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_OA_BUFFERS_COUNT, out, metricsDevice );
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
    //     CDriverInterfaceLinuxCommon
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
    uint32_t CDriverInterfaceLinuxCommon::GetAdapterId()
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
    //     CDriverInterfaceLinuxCommon
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
    TCompletionCode CDriverInterfaceLinuxCommon::LockConcurrentGroup( const char* name, void** semaphore )
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
    //     CDriverInterfaceLinuxCommon
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
    TCompletionCode CDriverInterfaceLinuxCommon::UnlockConcurrentGroup( const char* name, void** semaphore )
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
    //     CDriverInterfaceLinuxCommon
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
    TCompletionCode CDriverInterfaceLinuxCommon::OpenIoStream( COAConcurrentGroup& oaConcurrentGroup, const uint32_t processId, uint32_t& nsTimerPeriod, uint32_t& bufferSize )
    {
        const char* concurrentGroupName = oaConcurrentGroup.GetParams()->SymbolName;
        auto&       metricsDevice       = oaConcurrentGroup.GetMetricsDevice();
        auto        metricSet           = oaConcurrentGroup.GetIoMetricSet();

        MD_CHECK_PTR_RET_A( m_adapterId, concurrentGroupName, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( m_adapterId, metricSet, CC_ERROR_INVALID_PARAMETER );

        if( !IsStreamTypeSupported( oaConcurrentGroup.GetStreamType() ) )
        {
            return CC_ERROR_NOT_SUPPORTED;
        }

        // 1. ACTIVATE
        auto ret = metricSet->ActivateInternal( false, false );
        MD_CHECK_CC_RET_A( m_adapterId, ret );

        MD_ASSERT_A( m_adapterId, metricsDevice.GetStreamConfigId() == -1 ); // Should be -1, which means stream is closed

        // 2. SET PARAMS
        const uint32_t timerPeriodExponent = GetTimerPeriodExponent( nsTimerPeriod );
        const uint32_t oaReportType        = GetOaReportType( metricSet->GetReportType() );
        const uint32_t oaReportSize        = metricSet->GetParams()->RawReportSize;
        int32_t        oaMetricSetId       = -1;
        uint32_t       regCount            = 0;
        TRegister**    regVector           = metricSet->GetStartConfiguration( regCount );

        if( oaReportType == static_cast<uint32_t>( -1 ) )
        {
            ret = CC_ERROR_NOT_SUPPORTED;
            goto deactivate;
        }

        // 3. ADD HW CONFIG
        ret = AddOaConfig( regVector, regCount, metricsDevice.GetSubDeviceIndex(), nullptr, oaMetricSetId );
        if( ret != CC_OK )
        {
            goto deactivate;
        }
        MD_ASSERT_A( m_adapterId, oaMetricSetId != -1 );

        // 4. OPEN STREAM
        ret = OpenOaStream( metricsDevice, oaMetricSetId, oaReportType, oaReportSize, timerPeriodExponent, bufferSize, oaConcurrentGroup.GetOaBufferType() );
        if( ret != CC_OK )
        {
            goto remove_config;
        }

        // 5. RETURN PARAMETERS
        nsTimerPeriod = GetNsTimerPeriod( timerPeriodExponent );

        ret = GetOaBufferSize( metricsDevice.GetStreamId(), bufferSize );
        if( ret != CC_OK )
        {
            goto remove_config;
        }

        metricsDevice.SetStreamConfigId( oaMetricSetId ); // Remember oa config id so it could be removed from the kernel on CloseIoStream

        MD_LOG_A( m_adapterId, LOG_DEBUG, "Oa stream opened with metricSetId: %d, periodNs: %u, exponent: %u, bufferSize: %u", oaMetricSetId, nsTimerPeriod, timerPeriodExponent, bufferSize );
        return CC_OK;

    remove_config:
        RemoveOaConfig( oaMetricSetId );
    deactivate:
        metricSet->Deactivate();
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
    //
    // Method:
    //     ReadIoStream
    //
    // Description:
    //     Reads data from previously opened OA/Sys IO Stream.
    //
    // Input:
    //     COAConcurrentGroup&              oaConcurrentGroup - oa concurrent group
    //     char*                            reportData        - (out) pointer to the read data
    //     uint32_t&                        reportsCount      - (in/out) reports read/to read from the stream
    //     uint32_t&                        frequency         - (out) frequency from GTDIReadCounterStreamExtOut
    //     GTDIReadCounterStreamExceptions& exceptions        - (out) exceptions from GTDIReadCounterStreamExtOut
    //
    // Output:
    //     TCompletionCode                                    - *CC_OK* means succeess
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxCommon::ReadIoStream( COAConcurrentGroup& oaConcurrentGroup, char* reportData, uint32_t& reportsCount, uint32_t& frequency, GTDIReadCounterStreamExceptions& exceptions )
    {
        if( !IsStreamTypeSupported( oaConcurrentGroup.GetStreamType() ) )
        {
            return CC_ERROR_NOT_SUPPORTED;
        }

        auto& device    = oaConcurrentGroup.GetMetricsDevice();
        auto  metricSet = oaConcurrentGroup.GetIoMetricSet();

        MD_CHECK_PTR_RET_A( m_adapterId, metricSet, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( m_adapterId, reportData, CC_ERROR_INVALID_PARAMETER );

        const uint32_t reportSize  = metricSet->GetParams()->RawReportSize;
        const uint32_t bytesToRead = reportsCount * reportSize;
        uint32_t       readBytes   = 0;

        // Read flags are ignored for Linux
        TCompletionCode ret = ReadOaStream( device, reportSize, reportsCount, reportData, readBytes, exceptions );
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
            if( GetGpuFrequencyInfo( device, nullptr, nullptr, &currentFrequency, nullptr ) == CC_OK )
            {
                frequency = static_cast<uint32_t>( currentFrequency / MD_MHERTZ );
            }
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
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
    TCompletionCode CDriverInterfaceLinuxCommon::CloseIoStream( COAConcurrentGroup& oaConcurrentGroup )
    {
        if( !IsStreamTypeSupported( oaConcurrentGroup.GetStreamType() ) )
        {
            return CC_ERROR_NOT_SUPPORTED;
        }

        auto& metricsDevice = oaConcurrentGroup.GetMetricsDevice();
        auto  metricSet     = oaConcurrentGroup.GetIoMetricSet();

        MD_CHECK_PTR_RET_A( m_adapterId, metricSet, CC_ERROR_INVALID_PARAMETER );

        // 1. CLOSE STREAM
        CloseOaStream( metricsDevice );

        // 2. REMOVE HW CONFIG
        if( RemoveOaConfig( metricsDevice.GetStreamConfigId() ) == CC_OK )
        {
            metricsDevice.SetStreamConfigId( -1 );
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
    //     CDriverInterfaceLinuxCommon
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
    TCompletionCode CDriverInterfaceLinuxCommon::HandleIoStreamExceptions( COAConcurrentGroup& oaConcurrentGroup, const uint32_t processId, uint32_t& reportCount, const GTDIReadCounterStreamExceptions exceptions )
    {
        // Not needed on Linux Perf - returning CC_OK on purpose
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
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
    TCompletionCode CDriverInterfaceLinuxCommon::WaitForIoStreamReports( COAConcurrentGroup& oaConcurrentGroup, const uint32_t milliseconds )
    {
        if( !IsStreamTypeSupported( oaConcurrentGroup.GetStreamType() ) )
        {
            return CC_ERROR_NOT_SUPPORTED;
        }

        return WaitForOaStreamReports( oaConcurrentGroup.GetMetricsDevice(), milliseconds );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
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
    bool CDriverInterfaceLinuxCommon::IsIoMeasurementInfoAvailable( const TIoMeasurementInfoType ioMeasurementInfoType )
    {
        // Only ReportLost, BufferOverflow and Frequency during read available with Perf
        return ioMeasurementInfoType == IO_MEASUREMENT_INFO_REPORT_LOST ||
            ioMeasurementInfoType == IO_MEASUREMENT_INFO_BUFFER_OVERFLOW ||
            ioMeasurementInfoType == IO_MEASUREMENT_INFO_CORE_FREQUENCY_MHZ;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
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
    bool CDriverInterfaceLinuxCommon::IsStreamTypeSupported( const TStreamType streamType )
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
    //     CDriverInterfaceLinuxCommon
    //
    // Method:
    //     SetFrequencyOverride
    //
    // Description:
    //     Enables / disables frequency override using CoreU function.
    //
    // Input:
    //     CMetricsDevice&                        device - a reference to device
    //     const TSetFrequencyOverrideParams_1_2& params - frequency override params
    //
    // Output:
    //     TCompletionCode                               - *CC_OK* means succeess
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxCommon::SetFrequencyOverride( CMetricsDevice& device, const TSetFrequencyOverrideParams_1_2& params )
    {
        if( params.Pid != 0 )
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
        TCompletionCode ret = GetGpuFrequencyInfo( device, &minFrequency, &maxFrequency, nullptr, boostFrequencyPtr );
        MD_CHECK_CC_RET_A( m_adapterId, ret );

        MD_LOG_A( m_adapterId, LOG_DEBUG, "MinFreq: %llu, MaxFreq: %llu, BoostFreq: %llu MHz", minFrequency, maxFrequency, m_CachedBoostFrequency );

        // 2. Decide frequency values to be set (e.g. check range)
        if( params.Enable )
        {
            if( params.FrequencyMhz == 0 )
            {
                MD_LOG_A( m_adapterId, LOG_DEBUG, "Using MaxFrequency as a default value (%llu MHz)", maxFrequency );
                maxFrequencyToSet   = maxFrequency;
                minFrequencyToSet   = maxFrequency;
                boostFrequencyToSet = maxFrequency;
            }
            else if( params.FrequencyMhz >= minFrequency && params.FrequencyMhz <= maxFrequency )
            {
                MD_LOG_A( m_adapterId, LOG_DEBUG, "Setting frequency to %u MHz", params.FrequencyMhz );
                maxFrequencyToSet   = params.FrequencyMhz;
                minFrequencyToSet   = params.FrequencyMhz;
                boostFrequencyToSet = params.FrequencyMhz;
            }
            else
            {
                MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Invalid frequency (%u MHz), should be in range [%llu, %llu]", params.FrequencyMhz, minFrequency, maxFrequency );
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
            ret = WriteSysFsFile( device, SYS_FS_MIN_FREQ_OV, minFrequencyToSet );
            MD_CHECK_CC_RET_A( m_adapterId, ret );

            ret = WriteSysFsFile( device, SYS_FS_MAX_FREQ_OV, maxFrequencyToSet );
            MD_CHECK_CC_RET_A( m_adapterId, ret );

            // If boost frequency file available
            if( m_CachedBoostFrequency )
            {
                ret = WriteSysFsFile( device, SYS_FS_BOOST_FREQ_OV, boostFrequencyToSet );
                MD_CHECK_CC_RET_A( m_adapterId, ret );
            }
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
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
    TCompletionCode CDriverInterfaceLinuxCommon::SetFreqChangeReportsOverride( bool enable )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
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
    bool CDriverInterfaceLinuxCommon::IsOverrideAvailable( TOverrideType overrideType )
    {
        // Only Frequency Override is available with Perf
        return overrideType == OVERRIDE_TYPE_FREQUENCY;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
    //
    // Method:
    //     GetQueryModeOverride
    //
    // Description:
    //     Gets enabled query mode.
    //
    // Output:
    //     TQueryMode - enabled query mode
    //
    //////////////////////////////////////////////////////////////////////////////
    TQueryMode CDriverInterfaceLinuxCommon::GetQueryModeOverride()
    {
        // Only OAG query is supported on Linux.
        return QUERY_MODE_GLOBAL;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
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
    //     const TSetQueryOverrideParams_1_2&   params         - query override params
    //
    // Output:
    //     TCompletionCode                                     - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxCommon::SetQueryOverride( TOverrideType overrideType, uint32_t oaBufferSize, const TSetQueryOverrideParams_1_2& params )
    {
        return CC_ERROR_NOT_SUPPORTED;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
    //
    // Method:
    //     CloseOaStream
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
    TCompletionCode CDriverInterfaceLinuxCommon::CloseOaStream( CMetricsDevice& metricsDevice )
    {
        int32_t id = metricsDevice.GetStreamId();

        if( id >= 0 )
        {
            MD_LOG_A( m_adapterId, LOG_DEBUG, "Closing oa stream, fd: %d", id );
            close( id );
            metricsDevice.SetStreamId( -1 );
        }
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
    //
    // Method:
    //     WaitForOaStreamReports
    //
    // Description:
    //     Wait for any data available in the previously opened oa stream. Currently,
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
    TCompletionCode CDriverInterfaceLinuxCommon::WaitForOaStreamReports( CMetricsDevice& metricsDevice, uint32_t timeoutMs )
    {
        TCompletionCode retVal     = CC_OK;
        pollfd          pollParams = {};

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
            retVal = CC_INTERRUPTED;
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
    //     CDriverInterfaceLinuxCommon
    //
    // Method:
    //     GenerateQueryGUID
    //
    // Description:
    //     Generates query oa guid for given subDeviceIndex.
    //
    // Input:
    //     const uint32_t subDeviceIndex - sub device index
    //
    // Output:
    //     std::string                   - generated guid
    //
    //////////////////////////////////////////////////////////////////////////////
    std::string CDriverInterfaceLinuxCommon::GenerateQueryGuid( const uint32_t subDeviceIndex )
    {
        const std::string valueToReplace    = "42a7";
        const uint32_t    maxSubDeviceIndex = std::pow( 2, valueToReplace.length() * 4 ) - 1;

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
        stream << std::setfill( '0' ) << std::setw( valueToReplace.length() ) << std::hex << subDeviceIndex;
        std::string subDeviceIndexHexString( stream.str() );

        return std::regex_replace( defaultGuid, std::regex( valueToReplace ), subDeviceIndexHexString.c_str() );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
    //
    // Method:
    //     RemoveOaConfigQuery
    //
    // Description:
    //     Removes OA config previously added under MD_PERF_GUID_FOR_QUERY from i915 Perf or XE OA (if exists).
    //     Query oa config has to be removed e.g. in case when measuring different sets or previous execution crash.
    //
    // Input:
    //     const char* guid - configuration guid
    //
    // Output:
    //     TCompletionCode - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxCommon::RemoveOaConfigQuery( const char* guid )
    {
        if( !OaMetricSetExists( guid ) )
        {
            MD_LOG_A( m_adapterId, LOG_DEBUG, "Oa configuration with query guid doesn't exist" );
            return CC_OK;
        }

        int32_t         existingConfigId = -1;
        TCompletionCode ret              = GetOaMetricSetId( guid, existingConfigId );
        if( ret == CC_OK )
        {
            MD_LOG_A( m_adapterId, LOG_DEBUG, "Removing oa config with query guid: %s, id: %d", guid, existingConfigId );

            ret = RemoveOaConfig( existingConfigId );
            if( ret == CC_OK )
            {
                // Remove from remembered oa configs
                m_AddedOaConfigs.erase( std::remove( m_AddedOaConfigs.begin(), m_AddedOaConfigs.end(), existingConfigId ), m_AddedOaConfigs.end() );
            }
            else
            {
                MD_LOG_A( m_adapterId, LOG_WARNING, "WARNING: Removing oa configuration with query guid failed, id: %d", existingConfigId );
            }
            existingConfigId = -1;
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
    //
    // Method:
    //     GetOaMetricSetId
    //
    // Description:
    //     Returns oa metric set ID (configuration ID) for the configuration with the
    //     given GUID.
    //
    // Input:
    //     const char* guid          - GUID for which to read configuration ID
    //     int32_t&    oaMetricSetId - (OUT) oa configuration ID, not changed if error
    //
    // Output:
    //     TCompletionCode           - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxCommon::GetOaMetricSetId( const char* guid, int32_t& oaMetricSetId )
    {
        MD_ASSERT_A( m_adapterId, m_DrmCardNumber >= 0 );

        char     filePath[MD_MAX_PATH_LENGTH];
        uint64_t metricSetId = -1;

        // Read oa metric set ID based on GUID
        snprintf( filePath, sizeof( filePath ), "/sys/class/drm/card%d/metrics/%s/id", m_DrmCardNumber, guid );

        TCompletionCode ret = ReadUInt64FromFile( filePath, &metricSetId );
        MD_CHECK_CC_RET_A( m_adapterId, ret );
        if( !metricSetId )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Invalid oa config id read from %s", filePath );
            return CC_ERROR_GENERAL;
        }

        oaMetricSetId = static_cast<int32_t>( metricSetId );
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
    //
    // Method:
    //     OaMetricSetExists
    //
    // Description:
    //     Returns true if oa has configuration with the given GUID.
    //
    // Input:
    //     const char* guid - GUID for which to read configuration ID
    //
    // Output:
    //     bool             - true if exists, false otherwise
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CDriverInterfaceLinuxCommon::OaMetricSetExists( const char* guid )
    {
        MD_ASSERT_A( m_adapterId, m_DrmCardNumber >= 0 );

        char filePath[MD_MAX_PATH_LENGTH];

        // Read oa metric set ID path based on GUID
        snprintf( filePath, sizeof( filePath ), "/sys/class/drm/card%d/metrics/%s/id", m_DrmCardNumber, guid );

        // Check whether the file exists (F_OK)
        return ( access( filePath, F_OK ) != -1 );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
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
    bool CDriverInterfaceLinuxCommon::InitializeIntelDrm()
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
    //     CDriverInterfaceLinuxCommon
    //
    // Method:
    //     DeinitializeIntelDrm
    //
    // Description:
    //     Deinitializes previously initialized DRM interface.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CDriverInterfaceLinuxCommon::DeinitializeIntelDrm()
    {
        m_DrmCardNumber = -1;
        MD_LOG_A( m_adapterId, LOG_DEBUG, "DRM deinitialized" );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
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
    int32_t CDriverInterfaceLinuxCommon::GetDrmCardNumber( int32_t drmFd )
    {
        struct stat fileInfo;
        if( fstat( drmFd, &fileInfo ) )
        {
            MD_LOG_A( IU_ADAPTER_ID_UNKNOWN, LOG_ERROR, "ERROR: Failed to stat DRM fd" );
            return -1;
        }

        int32_t majorNumber = major( fileInfo.st_rdev );
        int32_t minorNumber = minor( fileInfo.st_rdev );

        char drmDirPath[MD_MAX_PATH_LENGTH] = { 0 };
        snprintf( drmDirPath, sizeof( drmDirPath ), "/sys/dev/char/%d:%d/device/drm", majorNumber, minorNumber );

        DIR* drmDir = opendir( drmDirPath );
        MD_CHECK_PTR_RET_A( IU_ADAPTER_ID_UNKNOWN, drmDir, -1 );

        dirent* entry         = nullptr;
        int32_t retCardNumber = -1;
        while( ( entry = readdir( drmDir ) ) != nullptr )
        {
            // If it's a directory named 'card.*'
            if( entry->d_type == DT_DIR && iu_strncmp( entry->d_name, "card", 4 ) == 0 )
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
    //     CDriverInterfaceLinuxCommon
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
    TCompletionCode CDriverInterfaceLinuxCommon::AcquireAdapterId()
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
    //     CDriverInterfaceLinuxCommon
    //
    // Method:
    //     ReadSysFsFile
    //
    // Description:
    //     Reads a 64-bit unsigned value from the given SysFs file. SysFs path is
    //     based on DRM card number.
    //
    // Input:
    //     CMetricsDevice&  device   - a reference to device
    //     const TSysFsType fileType - type of SysFs file to write
    //     uint64_t         value    - value to write
    //
    // Output:
    //     TCompletionCode           - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxCommon::ReadSysFsFile( CMetricsDevice& device, const TSysFsType fileType, uint64_t* readValue )
    {
        MD_ASSERT_A( m_adapterId, m_DrmCardNumber >= 0 );

        char filePath[MD_MAX_PATH_LENGTH] = { 0 };

        GetSysFsPath( device, fileType, filePath, MD_MAX_PATH_LENGTH );

        return ReadUInt64FromFile( filePath, readValue );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
    //
    // Method:
    //     WriteSysFsFile
    //
    // Description:
    //     Writes a 64-bit unsigned value the the given SysFs file. SysFs path is
    //     based on DRM card number.
    //
    // Input:
    //     CMetricsDevice&  device   - a reference to device
    //     const TSysFsType fileType - type of SysFs file to write
    //     uint64_t         value    - value to write
    //
    // Output:
    //     TCompletionCode           - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxCommon::WriteSysFsFile( CMetricsDevice& device, const TSysFsType fileType, uint64_t value )
    {
        MD_ASSERT_A( m_adapterId, m_DrmCardNumber >= 0 );

        char filePath[MD_MAX_PATH_LENGTH] = { 0 };

        GetSysFsPath( device, fileType, filePath, MD_MAX_PATH_LENGTH );

        return WriteUInt64ToFile( filePath, value );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
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
    TCompletionCode CDriverInterfaceLinuxCommon::ReadUInt64FromFile( const char* filePath, uint64_t* readValue )
    {
        MD_CHECK_PTR_RET_A( m_adapterId, filePath, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( m_adapterId, readValue, CC_ERROR_INVALID_PARAMETER );

        char buffer[32] = { 0 };

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
    //     CDriverInterfaceLinuxCommon
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
    TCompletionCode CDriverInterfaceLinuxCommon::WriteUInt64ToFile( const char* filePath, uint64_t value )
    {
        MD_CHECK_PTR_RET_A( m_adapterId, filePath, CC_ERROR_INVALID_PARAMETER );

        char buffer[32] = { 0 };

        int32_t length = snprintf( buffer, sizeof( buffer ), "%" PRIu64, value ); // Note: length does not contain null-terminating character
        if( length >= (int32_t) sizeof( buffer ) || length <= 0 )
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
    //     CDriverInterfaceLinuxCommon
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
    int32_t CDriverInterfaceLinuxCommon::SendIoctl( int32_t drmFd, uint32_t request, void* argument )
    {
        return drmIoctl( drmFd, request, argument );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
    //
    // Method:
    //     GetGfxDeviceInfo
    //
    // Description:
    //     Returns Gfx device info structure, based on device id.
    //     Gfx device info is used for e.g. ChipsetId and Platform matching.
    //
    // Input:
    //     int32_t                deviceId      - Device id
    //     const TGfxDeviceInfo&  gfxDeviceInfo - (OUT) Gfx device info structure
    //
    // Output:
    //     TCompletionCode                       - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxCommon::GetGfxDeviceInfo( int32_t deviceId, TGfxDeviceInfo& gfxDeviceInfo )
    {
        TCompletionCode ret = CC_ERROR_NOT_SUPPORTED;

        const auto platformIndexMapIterator = platformIndexMap.find( deviceId );

        if( platformIndexMapIterator != platformIndexMap.end() )
        {
            gfxDeviceInfo.PlatformIndex   = platformIndexMapIterator->second.PlatformIndex;
            gfxDeviceInfo.GtType          = platformIndexMapIterator->second.GtType;
            gfxDeviceInfo.PlatformVersion = platformIndexMapIterator->second.PlatformVersion;

            const auto threadsPerEuMapIterator = threadsPerEuMap.find( gfxDeviceInfo.PlatformIndex );

            if( threadsPerEuMapIterator != threadsPerEuMap.end() )
            {
                gfxDeviceInfo.ThreadsPerEu = threadsPerEuMapIterator->second;
                ret                        = CC_OK;
            }
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
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
    //     const TGfxDeviceInfo& TGfxDeviceInfo - Gfx device info structure
    //
    // Output:
    //     TAdapterType                         - Discrete or integrated.
    //
    //////////////////////////////////////////////////////////////////////////////
    TAdapterType CDriverInterfaceLinuxCommon::GetAdapterType( const TGfxDeviceInfo& gfxDeviceInfo )
    {
        switch( gfxDeviceInfo.PlatformIndex )
        {
            case GENERATION_DG1:
            case GENERATION_ACM:
            case GENERATION_PVC:
            case GENERATION_BMG:
                return ADAPTER_TYPE_DISCRETE;
            default:
                return ADAPTER_TYPE_INTEGRATED;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
    //
    // Method:
    //     GetDrmVersion
    //
    // Description:
    //     Returns DRM version.
    //
    // Input:
    //     int32_t drmFd - DRM file descriptor
    //
    // Output:
    //     TDrmVersion   - DRM version
    //
    //////////////////////////////////////////////////////////////////////////////
    TDrmVersion CDriverInterfaceLinuxCommon::GetDrmVersion( int32_t drmFd )
    {
        drm_version version = {};
        char        name[5] = {};

        version.name     = name;
        version.name_len = sizeof( name );

        if( SendIoctl( drmFd, DRM_IOCTL_VERSION, &version ) != 0 )
        {
            return DRM_VERSION_UNDEFINED;
        }

        name[4] = '\0';

        if( std::string_view( name ) == "i915" )
        {
            return DRM_VERSION_I915;
        }
        else if( std::string_view( name ) == "xe" )
        {
            return DRM_VERSION_XE;
        }

        return DRM_VERSION_UNDEFINED;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
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
    //     const gfx_device_info*& gfxDeviceInfo - (OUT) gfx device info structure
    //
    // Output:
    //     TCompletionCode                        - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxCommon::GetGfxDeviceInfo( const TGfxDeviceInfo*& gfxDeviceInfo )
    {
        // Get gfxDeviceInfo if not cached already
        if( m_CachedGfxDeviceInfo.PlatformIndex == GTDI_PLATFORM_MAX )
        {
            int32_t         deviceId = 0;
            TCompletionCode ret      = GetDeviceId( deviceId );

            MD_CHECK_CC_RET_A( m_adapterId, ret );

            if( GetGfxDeviceInfo( deviceId, m_CachedGfxDeviceInfo ) != CC_OK )
            {
                return CC_ERROR_NOT_SUPPORTED;
            }
        }

        gfxDeviceInfo = &m_CachedGfxDeviceInfo;

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
    //
    // Method:
    //     GetGpuFrequencyInfo
    //
    // Description:
    //     Reads GPU frequency info from the SysFs files. Minimum and maximum frequencies
    //     are cached (they don't change).
    //
    // Input:
    //     CMetricsDevice& device         - a reference to device
    //     uint64_t*       minFrequency   - (OUT) in MHz
    //     uint64_t*       maxFrequency   - (OUT) in MHz
    //     uint64_t*       actFrequency   - (OUT) in Hz to preserve compatibility with other MDAPI driver interfaces
    //     uint64_t*       boostFrequency - (OUT) in Mhz
    //
    // Output:
    //     TCompletionCode          - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxCommon::GetGpuFrequencyInfo( CMetricsDevice& device, uint64_t* minFrequency, uint64_t* maxFrequency, uint64_t* actFrequency, uint64_t* boostFrequency )
    {
        TCompletionCode ret = CC_ERROR_GENERAL; // Error if all parameters nullptr

        // Read minimum frequency
        if( minFrequency )
        {
            if( !m_CachedMinFrequency )
            {
                ret = ReadSysFsFile( device, SYS_FS_MIN_FREQ, &m_CachedMinFrequency );

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
                ret = ReadSysFsFile( device, SYS_FS_MAX_FREQ, &m_CachedMaxFrequency );

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
            ret = ReadSysFsFile( device, SYS_FS_ACT_FREQ, &actFrequencyMhz );

            MD_CHECK_CC_RET_A( m_adapterId, ret );

            // Convert reading to Hz (for compatibility with the other MDAPI driver interfaces)
            *actFrequency = actFrequencyMhz * MD_MHERTZ;
        }

        // Read boost frequency [optional]
        if( boostFrequency )
        {
            uint64_t boostFrequencyMhz = 0;

            TCompletionCode readBoostFreqRet = ReadSysFsFile( device, SYS_FS_BOOST_FREQ_OV, &boostFrequencyMhz );
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
    //     CDriverInterfaceLinuxCommon
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
    TCompletionCode CDriverInterfaceLinuxCommon::GetOaTimestamp( const uint64_t csTimestamp, uint64_t& oaTimestamp )
    {
        const TGfxDeviceInfo* gfxDeviceInfo = nullptr;
        TCompletionCode       ret           = GetGfxDeviceInfo( gfxDeviceInfo );
        MD_CHECK_CC_RET_A( m_adapterId, ret );

        uint64_t oaTimestampFrequency = 0;
        uint64_t csTimestampFrequency = 0;

        switch( gfxDeviceInfo->PlatformIndex )
        {
            case GENERATION_ACM:
            case GENERATION_PVC:
            case GENERATION_MTL:
            case GENERATION_ARL:
                ret = GetOaTimestampFrequency( oaTimestampFrequency );
                MD_CHECK_CC_RET_A( m_adapterId, ret );
                ret = GetCsTimestampFrequency( csTimestampFrequency );
                MD_CHECK_CC_RET_A( m_adapterId, ret );

                if( csTimestampFrequency != 0 )
                {
                    oaTimestamp = csTimestamp * oaTimestampFrequency / csTimestampFrequency;
                }
                else
                {
                    oaTimestamp = 0;
                    MD_LOG( LOG_DEBUG, "csTimestampFrequency = 0" );
                    return CC_ERROR_GENERAL;
                }

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
    //     CDriverInterfaceLinuxCommon
    //
    // Method:
    //     GetGpuTimestampFrequency
    //
    // Description:
    //     Returns GPU oa timestamp frequency.
    //
    // Input:
    //     uint64_t& gpuTimestampFrequency - (OUT) GPU Timestamp frequency in Hz
    //
    // Output:
    //     TCompletionCode                 - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxCommon::GetGpuTimestampFrequency( uint64_t& gpuTimestampFrequency )
    {
        const TGfxDeviceInfo* gfxDeviceInfo = nullptr;
        auto                  result        = GetGfxDeviceInfo( gfxDeviceInfo );
        MD_CHECK_CC_RET_A( m_adapterId, result );

        switch( gfxDeviceInfo->PlatformIndex )
        {
            case GENERATION_ACM:
            case GENERATION_PVC:
            case GENERATION_MTL:
            case GENERATION_ARL:
                result = GetOaTimestampFrequency( gpuTimestampFrequency );
                break;

            default:
                result = GetCsTimestampFrequency( gpuTimestampFrequency );
                break;
        }

        MD_CHECK_CC_RET_A( m_adapterId, result );
        return result;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
    //
    // Method:
    //     GetGpuTimestampPeriodNs
    //
    // Description:
    //     Returns minimum GPU timestamp period is nanoseconds based on GPU timestamp
    //     frequency.
    //
    // Input:
    //     uint64_t& gpuTimestampPeriodNs - (OUT) GPU timestamp period in ns
    //
    // Output:
    //     TCompletionCode                - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxCommon::GetGpuTimestampPeriodNs( uint64_t& gpuTimestampPeriodNs )
    {
        // 1. Get GpuTimestamFrequency
        uint64_t        gpuTimestampFrequency = 0;
        TCompletionCode ret                   = GetGpuTimestampFrequency( gpuTimestampFrequency );
        MD_CHECK_CC_RET_A( m_adapterId, ret );

        MD_ASSERT_A( m_adapterId, gpuTimestampFrequency != 0 );

        if( gpuTimestampFrequency == 0 )
        {
            gpuTimestampPeriodNs = 0;
            MD_LOG( LOG_DEBUG, "gpuTimestampFrequency = 0" );
            return CC_ERROR_GENERAL;
        }

        // 2. Transform Hz to period (ns)
        gpuTimestampPeriodNs = MD_NSEC_PER_SEC / gpuTimestampFrequency;

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
    //
    // Method:
    //     GetGtMaxSlice
    //
    // Description:
    //     Returns information about max active slices on GPU.
    //     Based on __InstrGetMaxSlice().
    //
    // Output:
    //     uint32_t - max slice
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CDriverInterfaceLinuxCommon::GetGtMaxSlice()
    {
        const TGfxDeviceInfo* gfxDeviceInfo = nullptr;
        auto                  result        = GetGfxDeviceInfo( gfxDeviceInfo );

        if( result != CC_OK )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "WARNING: Failed to get platform ID" );
            return MD_MAX_SLICE;
        }

        switch( gfxDeviceInfo->PlatformIndex )
        {
            case GENERATION_LNL:
                return MD_MAX_SLICE_LNL;

            case GENERATION_BMG:
                switch( gfxDeviceInfo->PlatformVersion )
                {
                    case 2:
                        return MD_MAX_SLICE_BMG_G21;

                    default:
                        // Unsupported BMG device id
                        MD_ASSERT_A( m_adapterId, false );
                        return 0;
                }

            case GENERATION_PTL:
                switch( gfxDeviceInfo->PlatformVersion )
                {
                    case 1:
                        return MD_MAX_SLICE_PTL_H;

                    case 2:
                        return MD_MAX_SLICE_PTL_U;

                    default:
                        // Unsupported PTL device id
                        MD_ASSERT_A( m_adapterId, false );
                        return 0;
                }

            default:
                // Return the legacy value for pre-Xe2 platforms.
                return MD_MAX_SLICE;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
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
    uint32_t CDriverInterfaceLinuxCommon::GetGtMaxSubslicePerSlice()
    {
        const TGfxDeviceInfo* gfxDeviceInfo = nullptr;
        auto                  result        = GetGfxDeviceInfo( gfxDeviceInfo );

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
            case GENERATION_ACM:
            case GENERATION_MTL:
            case GENERATION_ARL:
                return MD_MAX_DUALSUBSLICE_PER_SLICE * MD_MAX_SUBSLICE_PER_DSS;

            case GENERATION_LNL:
            case GENERATION_BMG:
                return MD_SUBSLICE_PER_SLICE_BMG;

            case GENERATION_PTL:
                return MD_SUBSLICE_PER_SLICE_PTL;

            default:
                MD_LOG_A( m_adapterId, LOG_WARNING, "WARNING: Unsupported platform, default MaxSubslicePerSlice used" );
                return MD_MAX_SUBSLICE_PER_SLICE;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
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
    uint32_t CDriverInterfaceLinuxCommon::GetGtMaxDualSubslicePerSlice()
    {
        const TGfxDeviceInfo* gfxDeviceInfo = nullptr;
        auto                  result        = GetGfxDeviceInfo( gfxDeviceInfo );

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

            case GENERATION_ACM:
            case GENERATION_MTL:
            case GENERATION_ARL:
                return MD_DUALSUBSLICE_PER_SLICE;

            default:
                return MD_MAX_DUALSUBSLICE_PER_SLICE;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
    //
    // Method:
    //     GetGtMaxL3Node
    //
    // Description:
    //     Returns information about max active l3 nodes on GPU.
    //     Based on __InstrGetMaxL3Node().
    //
    // Output:
    //     uint32_t - max l3 nodes
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CDriverInterfaceLinuxCommon::GetGtMaxL3Node()
    {
        const TGfxDeviceInfo* gfxDeviceInfo = nullptr;
        auto                  result        = GetGfxDeviceInfo( gfxDeviceInfo );

        if( result != CC_OK )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "WARNING: Failed to get platform ID" );
            return 0;
        }

        switch( gfxDeviceInfo->PlatformIndex )
        {
            case GENERATION_BMG:
                switch( gfxDeviceInfo->PlatformVersion )
                {
                    case 2:
                        return MD_MAX_L3_NODE_BMG_G21;

                    default:
                        // Unsupported BMG device id
                        MD_ASSERT_A( m_adapterId, false );
                        return 0;
                }

            case GENERATION_LNL:
                return MD_MAX_L3_NODE_LNL;

            case GENERATION_PTL:
                switch( gfxDeviceInfo->PlatformVersion )
                {
                    case 1:
                        return MD_MAX_L3_NODE_PTL_H;

                    case 2:
                        return MD_MAX_L3_NODE_PTL_U;

                    default:
                        // Unsupported PTL device id
                        MD_ASSERT_A( m_adapterId, false );
                        return 0;
                }

            default:
                // Return 0 for pre-Xe2 platforms as unsupported
                return 0;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
    //
    // Method:
    //     GetGtMaxL3BankPerL3Node
    //
    // Description:
    //     Returns information about max active l3 banks per l3 node on GPU.
    //     Based on __InstrGetGtMaxL3BankPerL3Node().
    //
    // Output:
    //     uint32_t - max l3 banks per l3 node
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CDriverInterfaceLinuxCommon::GetGtMaxL3BankPerL3Node()
    {
        const TGfxDeviceInfo* gfxDeviceInfo = nullptr;
        auto                  result        = GetGfxDeviceInfo( gfxDeviceInfo );

        if( result != CC_OK )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "WARNING: Failed to get platform ID" );
            return 0;
        }

        switch( gfxDeviceInfo->PlatformIndex )
        {
            case GENERATION_LNL:
            case GENERATION_BMG:
            case GENERATION_PTL:
                return MD_MAX_L3_BANK_PER_L3_NODE;

            default:
                // Return 0 for pre-Xe2 platforms as unsupported.
                return 0;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
    //
    // Method:
    //     GetGtMaxCopyEngine
    //
    // Description:
    //     Returns information about max active copy engines on GPU.
    //     Based on __InstrGetMaxCopyEngine().
    //
    // Output:
    //     uint32_t - max copy engines
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CDriverInterfaceLinuxCommon::GetGtMaxCopyEngine()
    {
        const uint32_t maxL3NodeCount = GetGtMaxL3Node();

        return ( maxL3NodeCount & 1 )
            ? ( ( maxL3NodeCount + 1 ) / MD_MAX_L3_NODE_PER_COPY_ENGINE )
            : ( maxL3NodeCount / MD_MAX_L3_NODE_PER_COPY_ENGINE );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
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
    bool CDriverInterfaceLinuxCommon::IsDualSubsliceSupported()
    {
        const TGfxDeviceInfo* gfxDeviceInfo = nullptr;

        TCompletionCode ret = GetGfxDeviceInfo( gfxDeviceInfo );
        if( ret != CC_OK )
        {
            MD_LOG_A( m_adapterId, LOG_WARNING, "WARNING: Cannot get gfx device info" );
            return false;
        }

        switch( gfxDeviceInfo->PlatformIndex )
        {
            case GENERATION_TGL:
            case GENERATION_DG1:
            case GENERATION_ACM:
            case GENERATION_RKL:
            case GENERATION_ADLP:
            case GENERATION_ADLS:
            case GENERATION_ADLN:
            case GENERATION_MTL:
            case GENERATION_ARL:
                return true;

            default:
                return false;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxCommon
    //
    // Method:
    //     MapDeviceInfoToInstrGtTypeGfxVer12
    //
    // Description:
    //     Gfx version 12 platforms need additional logic to determine their type using slice mask,
    //     device id and PCI revision id.
    //
    // Input:
    //     const TGfxDeviceInfo& gfxDeviceInfo - basic device information.
    //     CMetricsDevice&       metricsDevice - metrics device.
    //
    // Output:
    //     TGfxGtType                          - graphics GT type, used by Intel driver
    //
    //////////////////////////////////////////////////////////////////////////////
    TGfxGtType CDriverInterfaceLinuxCommon::MapDeviceInfoToInstrGtTypeGfxVer12( const TGfxDeviceInfo& gfxDeviceInfo, CMetricsDevice& metricsDevice )
    {
        TGfxGtType gtType = GFX_GTTYPE_UNDEFINED;

        if( gfxDeviceInfo.PlatformIndex == GENERATION_PVC )
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
    // Class:
    //     CDriverInterfaceLinuxCommon
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
    uint32_t CDriverInterfaceLinuxCommon::GetTimerPeriodExponent( uint32_t nsTimerPeriod )
    {
        // 1. Get minimum GPU timestamp period
        uint64_t timestampPeriodNs = 0;
        GetGpuTimestampPeriodNs( timestampPeriodNs );
        if( timestampPeriodNs == 0 )
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
    //     CDriverInterfaceLinuxCommon
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
    uint32_t CDriverInterfaceLinuxCommon::GetNsTimerPeriod( uint32_t timerPeriodExponent )
    {
        // 1. Get minimum GPU timestamp period
        uint64_t timestampPeriodNs = 0;
        GetGpuTimestampPeriodNs( timestampPeriodNs );
        if( timestampPeriodNs == 0 )
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
    //     CDriverInterfaceLinuxCommon
    //
    // Method:
    //     CalculateOaBufferSize
    //
    // Description:
    //     Changes the requested OA buffer size to the nearest power of 2 value.
    //     Size is rounded down.
    //
    // Input:
    //     const uint32_t  requestedBufferSize - requested oa buffer size in bytes
    //     CMetricsDevice& metricsDevice       - a reference to device
    //
    // Output:
    //     uint32_t                           - power of 2 oa buffer size in bytes
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CDriverInterfaceLinuxCommon::CalculateOaBufferSize( const uint32_t requestedBufferSize, CMetricsDevice& metricsDevice )
    {
        auto     ret             = CC_OK;
        auto     out             = GTDIDeviceInfoParamExtOut();
        uint32_t maxOaBufferSize = MD_OA_BUFFER_SIZE_MAX;
        uint32_t minOaBufferSize = MD_OA_BUFFER_SIZE_MAX; // default 16 mb value

        ret = SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_OA_BUFFER_SIZE_MAX, out, metricsDevice );
        if( ret != CC_OK )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Cannot calculate oa buffer size. Using default value: %u", maxOaBufferSize );
            return maxOaBufferSize;
        }
        maxOaBufferSize = out.ValueUint32;

        ret = SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_OA_BUFFER_SIZE_MIN, out, metricsDevice );
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
