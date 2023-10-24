/*========================== begin_copyright_notice ============================

Copyright (C) 2020-2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_driver_ifc_linux_perf.cpp

//     Abstract:   C++ implementation for Linux with Perf

#include "md_sub_devices_linux.h"
#include "md_driver_ifc_linux_perf.h"
#include "md_adapter.h"
#include "md_metrics_device.h"
#include "md_utils.h"

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

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    //////////////////////////////////////////////////////////////////////////////
    //
    // Struct:
    //    iu_i915_perf_config_register
    //
    // Description:
    //    For adding configs to kernel. Based on i915_oa_reg defined in kernel in i915_drv.h.
    //    DRM_IOCTL_I915_PERF_ADD_CONFIG expects just (address, value) tuples.
    //
    //////////////////////////////////////////////////////////////////////////////
    struct iu_i915_perf_config_register
    {
        uint32_t address;
        uint32_t value;
    };

    //////////////////////////////////////////////////////////////////////////////
    //
    // Struct:
    //    iu_i915_perf_record
    //
    // Description:
    //    For reading reports from kernel. Content of 'data' depends on flags passed to
    //    DRM_IOCTL_I915_PERF_OPEN, it may contain multiple different information at once,
    //    e.g. PID, CTX, timestamp, OA report.
    //
    //////////////////////////////////////////////////////////////////////////////
    struct iu_i915_perf_record
    {
        struct drm_i915_perf_record_header header;
        uint8_t                            data[];
    };

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
        : CDriverInterfaceLinuxCommon( adapterHandle, DRM_VERSION_I915 )
        , m_perfCapabilities{}
        , m_subDevicesSupported( false )
        , m_cachedPerfRevision( -1 )
    {
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

        for( int32_t oaConfigId : m_AddedOaConfigs )
        {
            RemoveOaConfig( oaConfigId );
        }
        m_AddedOaConfigs.clear();

        ResetPerfCapabilities();

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
        TCompletionCode       result                = GetGfxDeviceInfo( gfxDeviceInfo );
        MD_CHECK_CC_RET_A( m_adapterId, result );
        platform = gfxDeviceInfo->PlatformIndex;

        bool useKernelVersion = false;

        switch( platform )
        {
            case GENERATION_XEHP_SDV:
            case GENERATION_ACM:
            case GENERATION_PVC:
            case GENERATION_MTL:
                useKernelVersion = m_perfCapabilities.IsGpuCpuTimestampSupported;
                break;

            default:
                break;
        }

        if( useKernelVersion )
        {
            result = GetGpuTimestampFrequency( &gpuTimestampFrequency );
            MD_CHECK_CC_RET_A( m_adapterId, result );

            result = GetGpuCpuTimestamps( device, gpuTimestampFrequency, gpuTimestampNs, cpuTimestampNs );
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
    //     IsTbsEngineValid
    //
    // Input:
    //     EngineParams_1_9& engineParams      - engine params
    //     const uint32_t    requestedInstance - requested engine instance
    //     const bool        isOam             - indicates if validated engine is related to oam
    //
    // Output:
    //      bool                               - result
    //
    // Description:
    //     Checks if engine with given params can be used to open tbs.
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CDriverInterfaceLinuxPerf::IsTbsEngineValid(
        const TEngineParams_1_9& engineParams,
        const uint32_t           requestedInstance /*= -1*/,
        const bool               isOam /*= false*/ ) const
    {
        const bool isRenderEngine       = engineParams.EngineId.ClassInstance.Class == I915_ENGINE_CLASS_RENDER;
        const bool isComputeEngine      = engineParams.EngineId.ClassInstance.Class == I915_ENGINE_CLASS_COMPUTE;
        const bool isVideoEngine        = engineParams.EngineId.ClassInstance.Class == I915_ENGINE_CLASS_VIDEO;
        const bool isVideoEnhanceEngine = engineParams.EngineId.ClassInstance.Class == I915_ENGINE_CLASS_VIDEO_ENHANCE;
        bool       isValidInstance      = requestedInstance != static_cast<uint32_t>( -1 ) ? engineParams.EngineId.ClassInstance.Instance == requestedInstance : true;

        if( isValidInstance && ( ( isOam && ( isVideoEngine || isVideoEnhanceEngine ) ) || ( !isOam && ( isRenderEngine || isComputeEngine ) ) ) )
        {
            return true;
        }

        return false;
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
    //     Reads gpu and cpu timestamps in ns from given sub device.
    //
    // Input:
    //     CMetricsDevice& device         - (IN) Metrics device
    //     uint64_t gpuTimestampFrequency - (IN) Gpu timestamp frequency
    //
    // Output:
    //     uint64_t& gpuTimestampNs       - (OUT) Gpu timestamp in ns
    //     uint64_t& cpuTimestampNs       - (OUT) Cpu timestamp in ns
    //     TCompletionCode                - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetGpuCpuTimestamps(
        CMetricsDevice& device,
        const uint64_t  gpuTimestampFrequency,
        uint64_t&       gpuTimestampNs,
        uint64_t&       cpuTimestampNs )
    {
        auto& subDevices     = device.GetAdapter().GetSubDevices();
        auto  subDeviceIndex = device.GetSubDeviceIndex();
        auto  engine         = TEngineParams_1_9{};
        auto  result         = subDevices.GetTbsEngineParams( subDeviceIndex, engine );

        MD_CHECK_CC_RET_A( m_adapterId, result );

        auto     query                = drm_i915_query{};
        auto     queryItem            = drm_i915_query_item{};
        auto     queryTimestamp       = prelim_drm_i915_query_cs_cycles{};
        uint64_t oaGpuTimestampNs     = 0;
        uint64_t oaGpuTimestampCycles = 0;

        // Query timestamp data.
        queryTimestamp.clockid                = CLOCK_MONOTONIC;
        queryTimestamp.engine.engine_class    = static_cast<uint16_t>( engine.EngineId.ClassInstance.Class );
        queryTimestamp.engine.engine_instance = static_cast<uint16_t>( engine.EngineId.ClassInstance.Instance );

        // Query item data.
        queryItem.query_id = PRELIM_DRM_I915_QUERY_CS_CYCLES;
        queryItem.length   = sizeof( prelim_drm_i915_query_cs_cycles );
        queryItem.data_ptr = reinterpret_cast<uint64_t>( &queryTimestamp );

        // Query data.
        query.num_items = 1;
        query.items_ptr = reinterpret_cast<uint64_t>( &queryItem );

        // Send io control.
        result = QueryDrm( query );
        MD_CHECK_CC_RET_A( m_adapterId, result );

        // Return cpu and gpu timestamp information.
        result = GetOaTimestamp( queryTimestamp.cs_cycles, oaGpuTimestampCycles );
        MD_CHECK_CC_RET_A( m_adapterId, result );

        oaGpuTimestampNs = device.ConvertGpuTimestampToNs( oaGpuTimestampCycles, gpuTimestampFrequency );
        gpuTimestampNs   = oaGpuTimestampNs;
        cpuTimestampNs   = queryTimestamp.cpu_timestamp;

        return result;
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
        return m_subDevicesSupported;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     EnumerateSubDevices
    //
    // Description:
    //     Detects available sub devices.
    //
    // Output:
    //     TCompletionCode - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::EnumerateSubDevices( CSubDevices& subDevices )
    {
        auto            engines   = std::vector<drm_i915_engine_info>();
        auto            regions   = std::vector<drm_i915_memory_region_info>();
        auto            distances = std::vector<prelim_drm_i915_query_distance_info>();
        TCompletionCode ret       = CC_OK;

        // Check sub device support.
        m_subDevicesSupported = m_perfCapabilities.IsSubDeviceSupported;

        const TGfxDeviceInfo* gfxDeviceInfo = nullptr;
        ret                                 = GetGfxDeviceInfo( gfxDeviceInfo );
        MD_CHECK_CC_RET_A( m_adapterId, ret );

        m_subDevicesSupported &= IsPlatformMatch(
            gfxDeviceInfo->PlatformIndex,
            GENERATION_MTL,
            GENERATION_XEHP_SDV,
            GENERATION_ACM,
            GENERATION_PVC );

        if( m_subDevicesSupported )
        {
            // Enumerate engines.
            ret = GetEngines( engines );
            MD_CHECK_CC_RET_A( m_adapterId, ret );

            // Enumerate memory regions.
            ret = GetMemoryRegions( regions );
            MD_CHECK_CC_RET_A( m_adapterId, ret );

            // Enumerate engine distances.
            ret = GetEngineDistances( engines, regions, distances );
            MD_CHECK_CC_RET_A( m_adapterId, ret );

            // Enumerate sub device engines.
            ret = GetSubDeviceEngines( subDevices, distances );
            MD_CHECK_CC_RET_A( m_adapterId, ret );

            // Make space for CMetricsDevices.
            subDevices.MakeSpaceForMetricsDevices();

            MD_LOG_A( m_adapterId, LOG_DEBUG, "Sub devices count %u", subDevices.GetAllEnginesCount() );
        }
        else
        {
            MD_LOG_A( m_adapterId, LOG_DEBUG, "Platform without sub devices" );
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetEngines
    //
    // Description:
    //     Returns available engines.
    //
    // Input:
    //     CDriverInterfaceLinuxPerf& driver          - driver interface
    //
    // Output:
    //     std::vector<drm_i915_engine_info>& engines - available engines
    //     TCompletionCode                            - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetEngines(
        std::vector<drm_i915_engine_info>& engines )
    {
        auto            buffer = std::vector<uint8_t>();
        TCompletionCode ret    = QueryDrm( DRM_I915_QUERY_ENGINE_INFO, buffer );
        const size_t    size   = buffer.size();

        MD_CHECK_CC_RET_A( m_adapterId, ret );
        MD_CHECK_CC_RET_A( m_adapterId, size ? CC_OK : CC_ERROR_GENERAL );

        // Copy engine data.
        auto enginesData = reinterpret_cast<drm_i915_query_engine_info*>( buffer.data() );

        for( uint32_t i = 0; i < enginesData->num_engines; ++i )
        {
            engines.push_back( std::move( enginesData->engines[i] ) );
        }

        MD_ASSERT_A( m_adapterId, engines.size() );

        return engines.size()
            ? CC_OK
            : CC_ERROR_GENERAL;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetMemoryRegions
    //
    // Description:
    //     Returns available memory regions.
    //
    // Input:
    //     CDriverInterfaceLinuxPerf& driver                 - driver interface
    //
    // Output:
    //     std::vector<drm_i915_memory_region_info>& regions - available memory regions
    //     TCompletionCode                                   - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetMemoryRegions(
        std::vector<drm_i915_memory_region_info>& regions )
    {
        // Check supported memory classes. Prefer device local memory.
        auto getPreferredMemoryClass = [&]( drm_i915_query_memory_regions* regionsData )
        {
            for( uint32_t i = 0; i < regionsData->num_regions; ++i )
            {
                if( regionsData->regions[i].region.memory_class == I915_MEMORY_CLASS_DEVICE )
                {
                    // Device has local memory.
                    return I915_MEMORY_CLASS_DEVICE;
                }
            }
            // Device has only system memory.
            return I915_MEMORY_CLASS_SYSTEM;
        };

        // Obtain memory regions.
        auto            buffer = std::vector<uint8_t>();
        TCompletionCode ret    = QueryDrm( DRM_I915_QUERY_MEMORY_REGIONS, buffer );
        const size_t    size   = buffer.size();

        MD_CHECK_CC_RET_A( m_adapterId, ret );
        MD_CHECK_CC_RET_A( m_adapterId, size ? CC_OK : CC_ERROR_GENERAL );

        // Legacy version check.
        auto regionsData = reinterpret_cast<drm_i915_query_memory_regions*>( buffer.data() );

        const auto preferredMemoryClass = getPreferredMemoryClass( regionsData );

        for( uint32_t i = 0; i < regionsData->num_regions; ++i )
        {
            if( regionsData->regions[i].region.memory_class == preferredMemoryClass )
            {
                regions.push_back( std::move( regionsData->regions[i] ) );
            }
        }

        MD_ASSERT_A( m_adapterId, regions.size() );

        return regions.size()
            ? CC_OK
            : CC_ERROR_GENERAL;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetEngineDistances
    //
    // Description:
    //     Returns engine distances.
    //
    // Input:
    //     CDriverInterfaceLinuxPerf& driver                           - driver interface
    //     const std::vector<drm_i915_engine_info>& engines            - available engines
    //     const std::vector<drm_i915_memory_region_info>& regions     - available memory regions
    //     std::vector<prelim_drm_i915_query_distance_info>& distances - engine distances
    //
    // Output:
    //     std::vector<prelim_drm_i915_query_distance_info>& distances - engine distances
    //     TCompletionCode                                             - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetEngineDistances(
        const std::vector<drm_i915_engine_info>&          engines,
        const std::vector<drm_i915_memory_region_info>&   regions,
        std::vector<prelim_drm_i915_query_distance_info>& distances )
    {
        auto items = std::vector<drm_i915_query_item>();
        auto query = drm_i915_query{};

        // Prepare distance information.
        for( uint32_t i = 0; i < regions.size(); ++i )
        {
            auto distance                   = prelim_drm_i915_query_distance_info{};
            distance.region.memory_class    = regions[i].region.memory_class;
            distance.region.memory_instance = regions[i].region.memory_instance;

            for( uint32_t j = 0; j < engines.size(); ++j )
            {
                auto engine = engines[j];

                switch( engine.engine.engine_class )
                {
                    case I915_ENGINE_CLASS_RENDER:
                    case I915_ENGINE_CLASS_COPY:
                    case I915_ENGINE_CLASS_COMPUTE:
                    case I915_ENGINE_CLASS_VIDEO:
                    case I915_ENGINE_CLASS_VIDEO_ENHANCE:
                        distance.engine = engine.engine;
                        distances.push_back( std::move( distance ) );
                    default:
                        break;
                }
            }
        }

        // Prepare query items.
        items.resize( distances.size(), {} );

        for( uint32_t i = 0; i < distances.size(); ++i )
        {
            items[i]          = {};
            items[i].query_id = PRELIM_DRM_I915_QUERY_DISTANCE_INFO;
            items[i].length   = sizeof( prelim_drm_i915_query_distance_info );
            items[i].data_ptr = reinterpret_cast<uint64_t>( &( distances[i] ) );
        }

        // Prepare query data.
        query.items_ptr = reinterpret_cast<uint64_t>( items.data() );
        query.num_items = static_cast<uint32_t>( items.size() );

        return QueryDrm( query );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetSubDeviceEngines
    //
    // Description:
    //     Returns sub device engines.
    //
    // Input:
    //      const std::vector<prelim_drm_i915_query_distance_info>& distances - engine distances
    //
    // Output:
    //     TCompletionCode                                             - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetSubDeviceEngines(
        CSubDevices&                                            subDevices,
        const std::vector<prelim_drm_i915_query_distance_info>& distances )
    {
        for( uint32_t i = 0; i < distances.size(); ++i )
        {
            auto       engine        = distances[i].engine;
            const bool validDistance = distances[i].distance == 0;
            const bool newDevice     = ( i > 0 ) && ( distances[i].region.memory_instance != distances[i - 1].region.memory_instance );

            if( ( i == 0 ) || newDevice )
            {
                subDevices.AppendSubDeviceEngine();
            }

            if( validDistance )
            {
                switch( engine.engine_class )
                {
                    case I915_ENGINE_CLASS_RENDER:
                    case I915_ENGINE_CLASS_COPY:
                    case I915_ENGINE_CLASS_COMPUTE:
                    case I915_ENGINE_CLASS_VIDEO:
                    case I915_ENGINE_CLASS_VIDEO_ENHANCE:
                        MD_LOG_A( m_adapterId, LOG_DEBUG, "Sub device %u / engine %u:%u", subDevices.GetAllEnginesCount(), engine.engine_class, engine.engine_instance );
                        subDevices.AddEngine( engine.engine_class, engine.engine_instance );
                        break;

                    default:
                        MD_LOG_A( m_adapterId, LOG_ERROR, "Unknown engine type" );
                        MD_ASSERT_A( m_adapterId, 0 );
                        break;
                }
            }
        }

        const uint32_t subDeviceEngines = subDevices.GetAllEnginesCount();

        MD_ASSERT_A( m_adapterId, subDeviceEngines );

        return subDeviceEngines
            ? CC_OK
            : CC_ERROR_GENERAL;
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
        TCompletionCode getPerfRevisionRet = GetPerfRevision( perfRevision );

        auto requirePerfRevision = [getPerfRevisionRet, perfRevision]( int32_t requiredPerfRevision )
        {
            return getPerfRevisionRet == CC_OK && perfRevision >= requiredPerfRevision;
        };

        // Check capabilities. Update when OA interrupt will be merged.

        m_perfCapabilities.IsOaInterruptSupported     = false;
        m_perfCapabilities.IsSubDeviceSupported       = requirePerfRevision( 10 );
        m_perfCapabilities.IsGpuCpuTimestampSupported = requirePerfRevision( 11 );

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
        m_perfCapabilities = {};
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

        MD_LOG_A( m_adapterId, LOG_INFO, "Oa interrupt: %s", getSupportedString( m_perfCapabilities.IsOaInterruptSupported ) );
        MD_LOG_A( m_adapterId, LOG_INFO, "Sub devices: %s", getSupportedString( m_perfCapabilities.IsSubDeviceSupported ) );
        MD_LOG_A( m_adapterId, LOG_INFO, "Cpu gpu timestamps: %s", getSupportedString( m_perfCapabilities.IsGpuCpuTimestampSupported ) );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     OpenOaStream
    //
    // Description:
    //     Sends IOCTL opening oa stream. Output reports will include header and
    //     OA report part. OA configuration should be already added to kernel at this
    //     point.
    //
    // Input:
    //     CMetricsDevice&           metricsDevice       - metrics device
    //     uint32_t                  oaMetricSetId       - oa configuration ID (previously added)
    //     uint32_t                  oaReportType        - oa report type
    //     uint32_t                  timerPeriodExponent - timer period exponent
    //     uint32_t                  bufferSize          - oa buffer size
    //     const GTDI_OA_BUFFER_TYPE oaBufferType        - oa buffer type
    //
    // Output:
    //     TCompletionCode                               - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::OpenOaStream( CMetricsDevice& metricsDevice, uint32_t oaMetricSetId, uint32_t oaReportType, uint32_t timerPeriodExponent, uint32_t bufferSize, const GTDI_OA_BUFFER_TYPE oaBufferType )
    {
        TCompletionCode       ret                    = CC_ERROR_GENERAL;
        int32_t               oaRevision             = -1;
        int32_t               oaEventFd              = -1;
        uint32_t              requiredEngineInstance = -1;
        const bool            isOamRequested         = IsOamRequested( oaReportType );
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
        addProperty( DRM_I915_PERF_PROP_OA_METRICS_SET, oaMetricSetId );
        addProperty( DRM_I915_PERF_PROP_OA_FORMAT, oaReportType );
        addProperty( DRM_I915_PERF_PROP_OA_EXPONENT, timerPeriodExponent );

        if( IsSubDeviceSupported() )
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

            MD_LOG_A( m_adapterId, LOG_DEBUG, "Opening i915 Perf stream with params: oaMetricSetId: %u, oaReportType: %u, timerPeriodExponent: %u, bufferSize: %u", oaMetricSetId, oaReportType, timerPeriodExponent, bufferSize );

            oaEventFd = SendIoctl( m_DrmDeviceHandle, DRM_IOCTL_I915_PERF_OPEN, &param );
        }
        while( oaEventFd == -1 && UpdateTbsEngineParams( metricsDevice, properties ) == CC_OK );

        if( oaEventFd == -1 )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: opening i915 Perf stream failed, fd: %d, errno: %d (%s)", oaEventFd, errno, strerror( errno ) );
            return CC_ERROR_GENERAL;
        }

        metricsDevice.SetStreamId( oaEventFd );

        MD_LOG_A( m_adapterId, LOG_DEBUG, "i915 Perf stream opened successfully, fd: %d", oaEventFd );
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     ReadOaStream
    //
    // Description:
    //     Reads data from the previously opened oa stream and copies only OA reports
    //     to the output buffer. If report lost header is obtained or oa buffer overflows,
    //     exception flags are set.
    //
    // Input:
    //     CMetricsDevice&                  metricsDevice - metrics device
    //     uint32_t                         reportSize    - size of a single OA report, currently always 256 bytes
    //     uint32_t                         reportsToRead - number of reports to read
    //     char*                            reportData    - (OUT) buffer for reports
    //     uint32_t&                        readBytes     - (OUT) number of bytes read and copied to the output buffer
    //     GTDIReadCounterStreamExceptions& exceptions    - (OUT) exception flags reported by i915 Perf
    //
    // Output:
    //     TCompletionCode                   - *CC_OK* means success, BUT IT DOESN'T MEAN ALL REQUESTED DATA WAS READ !!
    //                                         (check readBytes for that).
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::ReadOaStream( CMetricsDevice& metricsDevice, uint32_t reportSize, uint32_t reportsToRead, char* reportData, uint32_t& readBytes, GTDIReadCounterStreamExceptions& exceptions )
    {
        const int32_t streamId = metricsDevice.GetStreamId();

        if( streamId < 0 )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Perf stream not opened" );
            return CC_ERROR_FILE_NOT_FOUND;
        }

        constexpr size_t oaHeaderSize    = sizeof( drm_i915_perf_record_header );
        const size_t     outBufferSize   = reportSize * reportsToRead;
        const size_t     perfReportSize  = oaHeaderSize + reportSize;                     // i915 Perf report size is bigger (additional header)
        const size_t     perfBytesToRead = reportsToRead * perfReportSize + oaHeaderSize; // Adding header for flag only reports, e.g. for situations where user
                                                                                          // requests 1 report, but first report from i915 Perf is REPORT_LOST flag.

        auto& streamBuffer = metricsDevice.GetStreamBuffer();

        // Resize report buffer if needed
        if( streamBuffer.size() < perfBytesToRead )
        {
            streamBuffer.resize( perfBytesToRead );
        }

        MD_LOG_A( m_adapterId, LOG_DEBUG, "Trying to read %u reports from i915 Perf stream, fd: %d", reportsToRead, streamId );

        // #Note May read 1 sample less than requested if ReportLost is returned from kernel

        // 1. READ DATA
        int32_t perfReadBytes = read( streamId, streamBuffer.data(), perfBytesToRead );
        if( perfReadBytes < 0 )
        {
            readBytes = 0;
            if( errno == EAGAIN )
            {
                MD_LOG_A( m_adapterId, LOG_DEBUG, "i915 Perf stream data not available yet" );
                return CC_OK;
            }
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Reading i915 Perf stream failed, errno: %d (%s)", errno, strerror( errno ) );
            return CC_ERROR_GENERAL;
        }
        MD_LOG_A( m_adapterId, LOG_DEBUG, "Read %u Perf bytes (= %lu reports), perfReportSize: %lu", perfReadBytes, perfReadBytes / perfReportSize, perfReportSize );

        // 2. PROCESS AND COPY DATA
        size_t bytesCopied    = 0;
        size_t perfDataOffset = 0;
        while( perfDataOffset < static_cast<size_t>( perfReadBytes ) )
        {
            const iu_i915_perf_record* perfRecord = reinterpret_cast<const iu_i915_perf_record*>( streamBuffer.data() + perfDataOffset );
            if( !perfRecord->header.size )
            {
                MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: 0 header size" );
                return CC_ERROR_GENERAL;
            }
            perfDataOffset += perfRecord->header.size;

            switch( perfRecord->header.type )
            {
                case DRM_I915_PERF_RECORD_SAMPLE:
                {
                    if( perfRecord->header.size != perfReportSize )
                    {
                        MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Invalid record size" );
                        return CC_ERROR_GENERAL;
                    }

                    // In MDAPI usage model 'perfRecord->data' contains only raw OA report
                    iu_memcpy_s( reportData + bytesCopied, outBufferSize - bytesCopied, perfRecord->data, reportSize );
                    bytesCopied += reportSize;
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
                    MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Unknown header type = %d", perfRecord->header.type );
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
    //     AddOaConfig
    //
    // Description:
    //     Adds OA configuration to the kernel through i915 Perf interface. If no GUID passed
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
    //     int32_t&       addedConfigId  - (OUT) added oa configuration ID, -1 if error
    //
    // Output:
    //     TCompletionCode               - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::AddOaConfig( TRegister** regVector, const uint32_t regCount, const uint32_t subDeviceIndex, const char* requestedGuid, int32_t& addedConfigId )
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

        // 1. TRANSFORM CONFIG TO I915 PERF FORMAT
        MD_LOG_A( m_adapterId, LOG_DEBUG, "AddOaConfig regCount: %u", regCount );
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

        // 4. ADD CONFIG TO I915 PERF
        addedConfigId = SendIoctl( m_DrmDeviceHandle, DRM_IOCTL_I915_PERF_ADD_CONFIG, &param );
        if( addedConfigId == -1 )
        {
            if( errno != EADDRINUSE ) // errno == 98 (EADDRINUSE) means set with the given GUID is already added
            {
                MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Adding i915 Perf configuration failed, errno: %s (%d)", strerror( errno ), errno );
                ret = CC_ERROR_GENERAL;
            }
            else
            {
                MD_LOG_A( m_adapterId, LOG_DEBUG, "Configuration with the given GUID already added, reusing" );
                ret = GetOaMetricSetId( guid, addedConfigId );
            }
        }

        if( ret == CC_OK )
        {
            MD_LOG_A( m_adapterId, LOG_DEBUG, "i915 Perf configuration added/reused, id: %d", addedConfigId );
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
    //     RemoveOaConfig
    //
    // Description:
    //     Removes from i915 Perf previously added OA config based on its ID.
    //
    //     Note from i915: "Configs can be removed while being used, the will stop appearing in SysFs
    //                      and their content will be freed when the stream using the config is closed."
    //
    // Input:
    //     int32_t         oaConfigId - valid oa configuration ID (previously added)
    //
    // Output:
    //     TCompletionCode            - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::RemoveOaConfig( int32_t oaConfigId )
    {
        TCompletionCode ret = CC_OK;

        // Note from i915: "Configs can be removed while being used, the will stop appearing in SysFs
        //                  and their content will be freed when the stream using the config is closed."

        if( oaConfigId != -1 )
        {
            MD_LOG_A( m_adapterId, LOG_DEBUG, "Removing i915 Perf configuration with id: %d", oaConfigId );

            uint64_t      oaConfigId64 = static_cast<uint64_t>( oaConfigId );
            const int32_t ioctlResult  = SendIoctl( m_DrmDeviceHandle, DRM_IOCTL_I915_PERF_REMOVE_CONFIG, &oaConfigId64 );
            if( ioctlResult )
            {
                if( errno != ENOENT ) // errno == 2 (ENOENT) means set with the given ID doesn't exist
                {
                    MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Removing i915 Perf configuration with id %d failed, config not found", oaConfigId );
                }
                else
                {
                    MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Removing i915 Perf configuration with id %d failed, errno: %d (%s)", oaConfigId, errno, strerror( errno ) );
                }
                ret = CC_ERROR_GENERAL;
            }
            else
            {
                MD_LOG_A( m_adapterId, LOG_DEBUG, "i915 Perf configuration with id %d removed", oaConfigId );
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
    //     GetOaReportType
    //
    // Description:
    //     Returns i915 Perf report format based on MDAPI report type and current platform.
    //
    // Input:
    //     const TReportType reportType - MDAPI report type
    //
    // Output:
    //     uint32_t                     - Perf report format, I915_OA_FORMAT_MAX if error
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CDriverInterfaceLinuxPerf::GetOaReportType( const TReportType reportType )
    {
        // Get platform ID
        const TGfxDeviceInfo* gfxDeviceInfo = nullptr;
        auto                  ret           = GetGfxDeviceInfo( gfxDeviceInfo );
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

        drm_i915_getparam_t params = {};

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

        // Send query io control.
        return QueryDrm( query );
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
        TCompletionCode       ret           = GetGfxDeviceInfo( gfxDeviceInfo );
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
        if( !m_perfCapabilities.IsSubDeviceSupported )
        {
            MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Sub devices are not supported by i915 kernel" );
            return CC_ERROR_GENERAL;
        }

        uint32_t flags = ( engine.EngineId.ClassInstance.Class & 0xFF ) | ( ( engine.EngineId.ClassInstance.Instance & 0xFF ) << 8 );

        // DRM_I915_QUERY_GEOMETRY_SUBSLICES is returning empty subslice mask on PVC.
        // Use PRELIM_DRM_I915_QUERY_COMPUTE_SUBSLICES instead.
        uint32_t queryItemId = ( gfxDeviceInfo->PlatformIndex == GENERATION_PVC )
            ? PRELIM_DRM_I915_QUERY_COMPUTE_SUBSLICES
            : DRM_I915_QUERY_GEOMETRY_SUBSLICES;

        ret = QueryDrm( queryItemId, buffer, flags );

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
        MD_CHECK_PTR_RET_A( m_adapterId, sliceMask, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( m_adapterId, metricsDevice, CC_ERROR_INVALID_PARAMETER );

        *sliceMask = 0;

        if( !IsXePlus() )
        {
            return SendGetParamIoctl( m_DrmDeviceHandle, I915_PARAM_SLICE_MASK, sliceMask );
        }

        TCompletionCode ret = CC_OK;

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

        return ret;
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
                    const uint64_t targetSubsliceMask = static_cast<uint64_t>( singleSubsliceMask ) << ( maxSubslicePerSliceCount * i );
                    *subsliceMask |= targetSubsliceMask;
                }
            }
        }
        else
        {
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
        if( !IsXePlus() )
        {
            return SendGetParamIoctl( m_DrmDeviceHandle, I915_PARAM_EU_TOTAL, out );
        }

        TCompletionCode ret = CC_OK;

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
    //     GetEuCoresPerSubsliceCount
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
    TCompletionCode CDriverInterfaceLinuxPerf::GetEuCoresPerSubsliceCount( GTDIDeviceInfoParamExtOut* out, CMetricsDevice* metricsDevice )
    {
        // #TODO_perf_later - it will be later added to i915 kernel (temporarily EuCoresTotalCount / EuSubslicesTotalCount)
        int32_t euCoresTotalCount   = 0;
        int32_t subslicesTotalCount = 0;

        TCompletionCode ret = CC_OK;

        if( IsXePlus() )
        {
            ret = GetEuCoresTotalCount( out, metricsDevice );
            MD_CHECK_CC_RET_A( m_adapterId, ret );

            int64_t subsliceMask = 0;
            ret                  = GetSubsliceMask( &subsliceMask, metricsDevice );
            MD_CHECK_CC_RET_A( m_adapterId, ret );

            subslicesTotalCount = CalculateEnabledBits( subsliceMask );

            const TGfxDeviceInfo* gfxDeviceInfo = nullptr;
            ret                                 = GetGfxDeviceInfo( gfxDeviceInfo );
            MD_CHECK_CC_RET_A( m_adapterId, ret );

            switch( gfxDeviceInfo->PlatformIndex )
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

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetDeviceId
    //
    // Description:
    //     Returns DeviceId (ChipsetId) obtained from kernel using i915_GETPARAM IOCTL.
    //
    // Input:
    //     int32_t& deviceId - (OUT) returned DeviceId
    //
    // Output:
    //     TCompletionCode   - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetDeviceId( int32_t& deviceId )
    {
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

        deviceId = m_CachedDeviceId;
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     GetRevisionId
    //
    // Description:
    //     Returns RevisionId obtained from kernel using i915_GETPARAM IOCTL.
    //
    // Input:
    //     int32_t& deviceId - (OUT) returned DeviceId
    //
    // Output:
    //     TCompletionCode   - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetRevisionId( int32_t& revisionId )
    {
        TCompletionCode ret = CC_OK;

        if( m_CachedRevisionId == -1 )
        {
            ret = SendGetParamIoctl( m_DrmDeviceHandle, I915_PARAM_REVISION, &m_CachedRevisionId );
            if( ret != CC_OK )
            {
                m_CachedRevisionId = -1;
                return ret;
            }
        }

        revisionId = m_CachedRevisionId;
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
    //     int32_t& perfRevision - (OUT) returned perf revision number
    //
    // Output:
    //     TCompletionCode       - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetPerfRevision( int32_t& perfRevision )
    {
        if( m_cachedPerfRevision == -1 )
        {
            drm_i915_getparam_t params = {};
            params.param               = I915_PARAM_PERF_REVISION;
            params.value               = &m_cachedPerfRevision;

            int32_t ioctlRet = SendIoctl( m_DrmDeviceHandle, DRM_IOCTL_I915_GETPARAM, &params );
            if( ioctlRet )
            {
                if( errno == EINVAL ) // errno == EINVAL means kernel doesn't support I915_PARAM_PERF_REVISION IOCTL, assuming revision 1
                {
                    MD_LOG_A( m_adapterId, LOG_INFO, "I915_PARAM_PERF_REVISION not supported, assuming revision '1'" );
                    m_cachedPerfRevision = 1;
                }
                else
                {
                    MD_LOG_A( m_adapterId, LOG_ERROR, "ERROR: Getting i915 perf revision failed, errno: %d (%s)", errno, strerror( errno ) );
                    m_cachedPerfRevision = -1;
                    return CC_ERROR_GENERAL;
                }
            }
            MD_LOG_A( m_adapterId, LOG_DEBUG, "i915 perf revision: %d", m_cachedPerfRevision );
        }

        perfRevision = m_cachedPerfRevision;
        return CC_OK;
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
        int32_t freq = 0;

        TCompletionCode result = SendGetParamIoctl( m_DrmDeviceHandle, I915_PARAM_OA_TIMESTAMP_FREQUENCY, &freq );
        MD_CHECK_CC_RET_A( m_adapterId, result );
        frequency = static_cast<uint64_t>( freq );

        return CC_OK;
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
        int32_t freq = 0;

        TCompletionCode result = SendGetParamIoctl( m_DrmDeviceHandle, I915_PARAM_CS_TIMESTAMP_FREQUENCY, &freq );
        MD_CHECK_CC_RET_A( m_adapterId, result );
        frequency = static_cast<uint64_t>( freq );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CDriverInterfaceLinuxPerf
    //
    // Method:
    //     UpdateTbsEngineParams
    //
    // Input:
    //     CMetricsDevice&        metricsDevice - metrics device
    //     std::vector<uint64_t>& properties    - open perf stream properties to be updated
    //
    // Output:
    //     std::vector<uint64_t>& properties    - updated properties
    //     TCompletionCode                      - operation status
    //
    // Description:
    //     Returns properties vector with incremented compute instance.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::UpdateTbsEngineParams( CMetricsDevice& metricsDevice, std::vector<uint64_t>& properties )
    {
        auto findProperty = [&]( const uint64_t key )
        {
            auto propertyIterator = std::find( properties.begin(), properties.end(), key );
            if( propertyIterator != properties.end() )
            {
                propertyIterator++;
                return *propertyIterator;
            }
            return 0ul;
        };

        auto incrementProperty = [&]( const uint64_t key )
        {
            auto propertyIterator = std::find( properties.begin(), properties.end(), key );
            if( propertyIterator != properties.end() )
            {
                propertyIterator++;
                ( *propertyIterator )++;
                return ( *propertyIterator );
            }
            return 0ul;
        };

        auto engineClass = findProperty( PRELIM_DRM_I915_PERF_PROP_OA_ENGINE_CLASS );

        if( engineClass != I915_ENGINE_CLASS_COMPUTE )
        {
            return CC_ERROR_GENERAL;
        }

        auto updatedInstance = incrementProperty( PRELIM_DRM_I915_PERF_PROP_OA_ENGINE_INSTANCE );

        auto subDevices     = metricsDevice.GetAdapter().GetSubDevices();
        auto subDeviceIndex = metricsDevice.GetSubDeviceIndex();

        auto subDeviceParams = TSubDeviceParamsLatest{};
        auto result          = subDevices.GetSubDeviceParams( subDeviceIndex, subDeviceParams );
        MD_CHECK_CC_RET_A( m_adapterId, result );

        for( uint32_t engineIndex = 0; engineIndex < subDeviceParams.EnginesCount; ++engineIndex )
        {
            auto engineParams = TEngineParamsLatest{};
            result            = subDevices.GetEngineParams( subDeviceIndex, engineIndex, engineParams );
            MD_CHECK_CC_RET_A( m_adapterId, result );

            if( engineParams.EngineId.ClassInstance.Class == engineClass &&
                engineParams.EngineId.ClassInstance.Instance == updatedInstance )
            {
                return CC_OK;
            }
        }

        return CC_ERROR_GENERAL;
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

        // 3. Convert GpuTimestampTicks to OA domain
        uint64_t oaGpuTimestampTicks = 0;
        ret                          = GetOaTimestamp( gpuTimestampTicks, oaGpuTimestampTicks );
        MD_CHECK_CC_RET_A( m_adapterId, ret );

        // 4. Convert GpuTimestampTicks to ns
        *gpuTimestampNs = metricsDevice.ConvertGpuTimestampToNs( oaGpuTimestampTicks, gpuTimestampFrequency );

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

        struct drm_i915_reg_read regReadParams = {};

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
    //     GetOaBufferSupportedSizes
    //
    // Description:
    //     Returns oa buffer supported sizes.
    //
    // Input:
    //     const uint32_t  platformId - (IN) platform index
    //     uint32_t&       minSize    - (OUT) oa buffer minimum supported size
    //     uint32_t&       maxSize    - (OUT) oa buffer maximum supported size
    //
    // Output:
    //     TCompletionCode               - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CDriverInterfaceLinuxPerf::GetOaBufferSupportedSizes( const uint32_t platformId, uint32_t& minSize, uint32_t& maxSize )
    {
        // Buffer size in Perf is constant
        minSize = MD_OA_BUFFER_SIZE_MAX;
        maxSize = MD_OA_BUFFER_SIZE_MAX;

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
        oaBufferCount = 1; // OAG/OA buffer

        if( IsOamSupported() && IsSubDeviceSupported() )
        {
            auto           subDevices              = metricsDevice.GetAdapter().GetSubDevices();
            const uint32_t subDeviceIndex          = metricsDevice.GetSubDeviceIndex();
            const uint32_t videoEngineCount        = subDevices.GetClassInstancesCount( subDeviceIndex, I915_ENGINE_CLASS_VIDEO );
            const uint32_t videoEnhanceEngineCount = subDevices.GetClassInstancesCount( subDeviceIndex, I915_ENGINE_CLASS_VIDEO_ENHANCE );

            if( videoEngineCount != videoEnhanceEngineCount )
            {
                MD_LOG_A( m_adapterId, LOG_ERROR, "Video engine count (%u) and video enhance engine count (%u) mismatch.", videoEngineCount, videoEnhanceEngineCount );
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

        auto ret = GetGfxDeviceInfo( gfxDeviceInfo );
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

} // namespace MetricsDiscoveryInternal
