/*========================== begin_copyright_notice ============================

Copyright (C) 2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_sub_devices_linux.cpp

//     Abstract:   C++ sub devices implementation for Linux

#include "md_sub_devices_linux.h"
#include "md_driver_ifc_linux_perf.h"
#include "md_utils.h"
#include <cmath>
#include <algorithm>

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDeviceEngines
    //
    // Method:
    //     Add engine
    //
    // Input:
    //      const uint32_t engineClass    - engine class
    //      const uint32_t engineInstance - engine instance
    //
    // Description:
    //     Adds engine to sub device.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSubDeviceEngines::AddEngine( const uint32_t engineClass, const uint32_t engineInstance )
    {
        TEngineParams_1_9 engine               = {};
        engine.EngineId.Type                   = ENGINE_ID_TYPE_CLASS_INSTANCE;
        engine.EngineId.ClassInstance.Class    = engineClass;
        engine.EngineId.ClassInstance.Instance = engineInstance;

        m_engines.push_back( engine );

        return TCompletionCode::CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDeviceEngines
    //
    // Method:
    //     GetEngineParams
    //
    // Input:
    //      uint32_t engineIndex - engine index.
    //
    // Output:
    //      TEngineParams_1_9    - engine parameters
    //
    // Description:
    //     Returns engine parameters.
    //
    //////////////////////////////////////////////////////////////////////////////
    TEngineParams_1_9 CSubDeviceEngines::GetEngineParams( const uint32_t engineIndex )
    {
        MD_ASSERT( engineIndex < m_engines.size() );

        return m_engines[engineIndex];
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDeviceEngines
    //
    // Method:
    //     GetTbsEngineParams
    //
    // Output:
    //      TEngineParams_1_9    - tbs engine parameters
    //      TCompletionCode      - operation status
    //
    // Description:
    //     Returns engine parameters that can be used with tbs.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSubDeviceEngines::GetTbsEngineParams( TEngineParams_1_9& engineParams )
    {
        for( uint32_t i = 0; i < m_engines.size(); ++i )
        {
            const bool isRenderEngine  = m_engines[i].EngineId.ClassInstance.Class == I915_ENGINE_CLASS_RENDER;
            const bool isComputeEngine = m_engines[i].EngineId.ClassInstance.Class == PRELIM_I915_ENGINE_CLASS_COMPUTE;

            if( isRenderEngine || isComputeEngine )
            {
                engineParams = m_engines[i];
                return CC_OK;
            }
        }

        return CC_ERROR_GENERAL;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevice
    //
    // Method:
    //     GetEnginesCount
    //
    // Output:
    //      uint32_t - engines count
    //
    // Description:
    //     Returns engines count.
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CSubDeviceEngines::GetEnginesCount()
    {
        return m_engines.size();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     CSubDevices
    //
    // Description:
    //     CSubDevice constructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    CSubDevices::CSubDevices( CAdapter& adapter )
        : m_adapter( adapter )
        , m_subDevicesSupported( false )
    {
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     ~CSubDevices
    //
    // Description:
    //     CSubDevice destructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    CSubDevices::~CSubDevices()
    {
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     GetAdapterParams
    //
    // Description:
    //     Returns sub device parameters related to adapter.
    //
    // Output:
    //     TAdapterParams_1_9& params   - adapter parameters
    //     TCompletionCode              - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSubDevices::GetAdapterParams( TAdapterParams_1_9& params )
    {
        params.SubDevicesCount = m_subDeviceEngines.size();

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     GetSubDeviceParams
    //
    // Description:
    //     Returns sub device parameters.
    //
    // Input:
    //     const uint32_t index          - sub device index
    //
    // Output:
    //     TSubDeviceParams_1_9& params  - sub device parameters
    //     TCompletionCode               - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSubDevices::GetSubDeviceParams(
        const uint32_t        index,
        TSubDeviceParams_1_9& params )
    {
        MD_CHECK_CC_RET( index < m_subDeviceEngines.size() ? CC_OK : CC_ERROR_INVALID_PARAMETER );

        params.EnginesCount = m_subDeviceEngines[index].GetEnginesCount();

        return TCompletionCode::CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     GetEngineParams
    //
    // Description:
    //     Returns engine parameters.
    //
    // Input:
    //     const uint32_t subDeviceIndex - sub device index
    //     const uint32_t engineIndex    - engine index
    //
    // Output:
    //     TEngineParams_1_9& params     - engine parameters
    //     TCompletionCode               - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSubDevices::GetEngineParams(
        const uint32_t     subDeviceIndex,
        const uint32_t     engineIndex,
        TEngineParams_1_9& params )
    {
        MD_CHECK_CC_RET( subDeviceIndex < m_subDeviceEngines.size() ? CC_OK : CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_CC_RET( engineIndex < m_subDeviceEngines[subDeviceIndex].GetEnginesCount() ? CC_OK : CC_ERROR_INVALID_PARAMETER );

        params = m_subDeviceEngines[subDeviceIndex].GetEngineParams( engineIndex );

        return TCompletionCode::CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     GetTbsEngineParams
    //
    // Description:
    //     Returns engine parameters compatible with tbs.
    //
    // Input:
    //     const uint32_t subDeviceIndex - sub device index
    //
    // Output:
    //     TEngineParams_1_9& params     - tbs engine parameters
    //     TCompletionCode               - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSubDevices::GetTbsEngineParams(
        const uint32_t     subDeviceIndex,
        TEngineParams_1_9& params )
    {
        MD_CHECK_CC_RET( subDeviceIndex < m_subDeviceEngines.size() ? CC_OK : CC_ERROR_INVALID_PARAMETER );

        return m_subDeviceEngines[subDeviceIndex].GetTbsEngineParams( params );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     GetCount
    //
    // Description:
    //     Returns number of opened sub devices.
    //
    // Output:
    //     uint32_t  - sub device count
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CSubDevices::GetDeviceCount()
    {
        uint32_t count = 0;

        for( uint32_t i = 0; i < m_subDevices.size(); ++i )
        {
            count += ( m_subDevices[i] != nullptr )
                ? 1
                : 0;
        }

        return count;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     FindDevice
    //
    // Description:
    //     Checks if given sub device exists.
    //
    // Input:
    //     const CMetricsDevice* metricsDevice  - sub device
    //
    // Output:
    //     bool                                 - sub device pointer
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CSubDevices::FindDevice( const CMetricsDevice* metricsDevice )
    {
        return std::find( m_subDevices.begin(), m_subDevices.end(), metricsDevice ) != m_subDevices.end();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     GetDevice
    //
    // Description:
    //     Returns metrics sub device.
    //
    // Input:
    //     const uint32_t index - sub device index
    //
    // Output:
    //     CMetricDevice*       - opened metrics sub device
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricsDevice* CSubDevices::GetDevice( const uint32_t index )
    {
        MD_ASSERT( index < m_subDevices.size() );

        return index < m_subDevices.size()
            ? m_subDevices[index]
            : nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     Open
    //
    // Description:
    //     Opens metrics sub device.
    //
    // Input:
    //     const uint32_t index - sub device index
    //
    // Output:
    //     CMetricDevice*       - opened metrics sub device
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricsDevice* CSubDevices::OpenDevice( const uint32_t index )
    {
        MD_ASSERT( index < m_subDevices.size() );
        MD_ASSERT( m_subDevices[index] == nullptr );

        CMetricsDevice* metricsDevice = nullptr;

        // Open metrics device and set sub device index
        TCompletionCode result = m_adapter.OpenMetricsDeviceByIndex( &metricsDevice, index );

        if( metricsDevice )
        {
            m_subDevices[index] = metricsDevice;
        }

        return m_subDevices[index];
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     Open
    //
    // Description:
    //     Opens metrics sub device from file.
    //
    // Input:
    //     const uint32_t index      - sub device index
    //     const char*    filename   - custom metric file name
    //     void*          parameters - open parameters
    //
    // Output:
    //     CMetricDevice*            - opened metrics sub device
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricsDevice* CSubDevices::OpenDeviceFromFile( const uint32_t index, const char* filename, void* parameters )
    {
        MD_ASSERT( index < m_subDevices.size() );
        MD_ASSERT( m_subDevices[index] == nullptr );

        CMetricsDevice* metricDevice = nullptr;

        // Open metrics device from file and set sub device index
        TCompletionCode result = m_adapter.OpenMetricsDeviceFromFileByIndex( filename, parameters, &metricDevice, index );

        if( metricDevice )
        {
            m_subDevices[index] = metricDevice;
        }

        return m_subDevices[index];
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     RemoveDevice
    //
    // Description:
    //     Removes sub device.
    //
    // Input:
    //     const CMetricsDevice* metricsDevice - sub device
    //
    //////////////////////////////////////////////////////////////////////////////
    void CSubDevices::RemoveDevice( const CMetricsDevice* metricsDevice )
    {
        // Removes device from cache, metricsDevice instance
        // will be removed by original CloseMetricsDevice.
        for( uint32_t i = 0; i < m_subDevices.size(); ++i )
        {
            if( m_subDevices[i] == metricsDevice )
            {
                m_subDevices[i] = nullptr;
            }
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     IsSupported
    //
    // Description:
    //     Check sub device support.
    //
    // Output:
    //     bool - true if supported
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CSubDevices::IsSupported()
    {
        return m_subDevicesSupported;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     Enumerate
    //
    // Description:
    //     Detects available sub devices.
    //
    // Output:
    //     TCompletionCode - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSubDevices::Enumerate()
    {
        auto driver        = reinterpret_cast<CDriverInterfaceLinuxPerf*>( m_adapter.GetDriverInterface() );
        auto engines       = std::vector<prelim_drm_i915_engine_info>();
        auto regions       = std::vector<prelim_drm_i915_memory_region_info>();
        auto distances     = std::vector<prelim_drm_i915_query_distance_info>();
        auto escape        = GTDIDeviceInfoParamExtOut{};
        auto validPlatform = false;

        // Check driver interface support.
        MD_CHECK_PTR_RET( driver, TCompletionCode::CC_ERROR_NO_MEMORY );

        // Check sub device support.
        m_subDevicesSupported = driver->IsSubDeviceSupported();

        // Obtain platform information.
        MD_CHECK_CC_RET( driver->SendDeviceInfoParamEscape( GTDI_DEVICE_PARAM_PLATFORM_INDEX, &escape ) );

        switch( escape.ValueUint32 )
        {
            case GENERATION_XEHP_SDV:
                validPlatform = true;
                break;
        }

        if( validPlatform && m_subDevicesSupported )
        {
            // Enumerate engines.
            MD_CHECK_CC_RET( GetEngines( *driver, engines ) );

            // Enumerate memory regions.
            MD_CHECK_CC_RET( GetMemoryRegions( *driver, regions ) );

            // Enumerate engine distances.
            MD_CHECK_CC_RET( GetEngineDistances( *driver, engines, regions, distances ) );

            // Enumerate sub device engines.
            MD_CHECK_CC_RET( GetSubDeviceEngines( distances ) );

            // Make space for CMetricDevices.
            m_subDevices.resize( m_subDeviceEngines.size(), nullptr );

            MD_LOG( LOG_DEBUG, "Sub devices count %u", m_subDeviceEngines.size() );
        }
        else
        {
            MD_LOG( LOG_DEBUG, "Platform without sub devices" );
        }

        return TCompletionCode::CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
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
    //     std::vector<prelim_drm_i915_engine_info>& engines - available engines
    //     TCompletionCode                            - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSubDevices::GetEngines( CDriverInterfaceLinuxPerf& driver, std::vector<prelim_drm_i915_engine_info>& engines )
    {
        auto buffer = std::vector<uint8_t>();

        MD_CHECK_CC_RET( driver.QueryDrm( PRELIM_DRM_I915_QUERY_ENGINE_INFO, buffer ) );
        MD_CHECK_CC_RET( buffer.size() ? CC_OK : CC_ERROR_GENERAL );

        // Copy engine data.
        auto enginesData = reinterpret_cast<prelim_drm_i915_query_engine_info*>( buffer.data() );

        for( uint32_t i = 0; i < enginesData->num_engines; ++i )
        {
            engines.push_back( enginesData->engines[i] );
        }

        MD_ASSERT( engines.size() );

        return engines.size()
            ? TCompletionCode::CC_OK
            : TCompletionCode::CC_ERROR_GENERAL;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
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
    //     std::vector<prelim_drm_i915_memory_region_info>& regions - available memory regions
    //     TCompletionCode                                   - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSubDevices::GetMemoryRegions( CDriverInterfaceLinuxPerf& driver, std::vector<prelim_drm_i915_memory_region_info>& regions )
    {
        // Obtain memory regions.
        auto buffer = std::vector<uint8_t>();

        MD_CHECK_CC_RET( driver.QueryDrm( PRELIM_DRM_I915_QUERY_MEMORY_REGIONS, buffer ) );
        MD_CHECK_CC_RET( buffer.size() ? CC_OK : CC_ERROR_GENERAL );

        // Legacy version check.
        auto regionsData = reinterpret_cast<prelim_drm_i915_query_memory_regions*>( buffer.data() );

        for( uint32_t i = 0; i < regionsData->num_regions; ++i )
        {
            regions.push_back( regionsData->regions[i] );
        }

        MD_ASSERT( regions.size() );

        return regions.size()
            ? TCompletionCode::CC_OK
            : TCompletionCode::CC_ERROR_GENERAL;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     GetEngineDistances
    //
    // Description:
    //     Returns engine distances.
    //
    // Input:
    //     CDriverInterfaceLinuxPerf& driver                       - driver interface
    //     const std::vector<prelim_drm_i915_engine_info>& engines        - available engines
    //     const std::vector<prelim_drm_i915_memory_region_info>& regions - available memory regions
    //
    // Output:
    //     std::vector<prelim_drm_i915_query_distance_info>& distances    - engine distances
    //     TCompletionCode                                         - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSubDevices::GetEngineDistances(
        CDriverInterfaceLinuxPerf&                             driver,
        const std::vector<prelim_drm_i915_engine_info>&        engines,
        const std::vector<prelim_drm_i915_memory_region_info>& regions,
        std::vector<prelim_drm_i915_query_distance_info>&      distances )
    {
        auto items = std::vector<drm_i915_query_item>();
        auto query = drm_i915_query{};

        // Prepare distance information.
        for( uint32_t i = 0; i < regions.size(); ++i )
        {
            if( PRELIM_I915_MEMORY_CLASS_DEVICE == regions[i].region.memory_class )
            {
                auto distance                   = prelim_drm_i915_query_distance_info{};
                distance.region.memory_class    = PRELIM_I915_MEMORY_CLASS_DEVICE;
                distance.region.memory_instance = regions[i].region.memory_instance;

                for( uint32_t j = 0; j < engines.size(); ++j )
                {
                    auto engine = engines[j];

                    switch( engine.engine.engine_class )
                    {
                        case I915_ENGINE_CLASS_RENDER:
                        case I915_ENGINE_CLASS_COPY:
                        case PRELIM_I915_ENGINE_CLASS_COMPUTE:
                            distance.engine = engine.engine;
                            distances.push_back( distance );
                        default:
                            break;
                    }
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

        return driver.QueryDrm( query );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
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
    TCompletionCode CSubDevices::GetSubDeviceEngines( const std::vector<prelim_drm_i915_query_distance_info>& distances )
    {
        for( uint32_t i = 0; i < distances.size(); ++i )
        {
            auto       engine        = distances[i].engine;
            const bool validDistance = distances[i].distance == 0;
            const bool newDevice     = ( i > 0 ) && ( distances[i].region.memory_instance != distances[i - 1].region.memory_instance );

            if( ( i == 0 ) || newDevice )
            {
                m_subDeviceEngines.emplace_back( CSubDeviceEngines{} );
            }

            if( validDistance )
            {
                switch( engine.engine_class )
                {
                    case I915_ENGINE_CLASS_RENDER:
                    case PRELIM_I915_ENGINE_CLASS_COMPUTE:
                    case I915_ENGINE_CLASS_COPY:
                        MD_LOG( LOG_DEBUG, "Sub device %u / engine %u:%u", m_subDeviceEngines.size() - 1, engine.engine_class, engine.engine_instance );
                        m_subDeviceEngines.back().AddEngine( engine.engine_class, engine.engine_instance );
                        break;

                    default:
                        MD_LOG( LOG_ERROR, "Unknown engine type" );
                        MD_ASSERT( 0 );
                        break;
                }
            }
        }

        MD_ASSERT( m_subDeviceEngines.size() );

        return m_subDeviceEngines.size()
            ? TCompletionCode::CC_OK
            : TCompletionCode::CC_ERROR_GENERAL;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     GetGpuCpuTimestamps
    //
    // Description:
    //     Reads gpu and cpu timestamps in ns from given sub device.
    //
    // Input:
    //     uint32_t subDeviceIndex        - (IN) Sub device index
    //     uint64_t gpuTimestampFrequency - (IN) Gpu timestamp frequency
    //
    // Output:
    //     uint64_t& gpuTimestampNs       - (OUT) Gpu timestamp in ns
    //     uint64_t& cpuTimestampNs       - (OUT) Cpu timestamp in ns
    //     TCompletionCode                - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSubDevices::GetGpuCpuTimestamps(
        const uint32_t subDeviceIndex,
        const uint64_t gpuTimestampFrequency,
        uint64_t&      gpuTimestampNs,
        uint64_t&      cpuTimestampNs )
    {
        auto     driver               = reinterpret_cast<CDriverInterfaceLinuxPerf*>( m_adapter.GetDriverInterface() );
        auto     query                = drm_i915_query{};
        auto     queryItem            = drm_i915_query_item{};
        auto     queryTimestamp       = prelim_drm_i915_query_cs_cycles{};
        auto     engine               = TEngineParams_1_9{};
        auto     result               = GetTbsEngineParams( subDeviceIndex, engine );
        uint64_t oaGpuTimestampNs     = 0;
        uint64_t oaGpuTimestampCycles = 0;

        MD_CHECK_PTR_RET( driver, TCompletionCode::CC_ERROR_NO_MEMORY );
        MD_CHECK_CC_RET( result );

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
        MD_CHECK_CC_RET( result = driver->QueryDrm( query ) );

        // Return cpu and gpu timestamp information.
        oaGpuTimestampNs = ( queryTimestamp.cs_cycles & MD_GPU_TIMESTAMP_MASK ) * MD_SECOND_IN_NS / gpuTimestampFrequency;
        gpuTimestampNs   = oaGpuTimestampNs;
        cpuTimestampNs   = queryTimestamp.cpu_timestamp;

        return result;
    }
} // namespace MetricsDiscoveryInternal
