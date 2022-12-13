/*========================== begin_copyright_notice ============================

Copyright (C) 2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_sub_devices_linux.h

//     Abstract:   C++ sub devices implementation for Linux

#pragma once

#include "metrics_discovery_api.h"
#include <vector>

#define __user
#include "i915_drm.h"

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    //////////////////////////////////////////////////////////////////////////////
    //
    // Description:
    //     Forward declaration.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CAdapter;
    class CDriverInterfaceLinuxPerf;
    class CMetricsDevice;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDeviceEngines
    //
    // Description:
    //     Keeps information related to sub device.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CSubDeviceEngines
    {
    public:
        TCompletionCode   AddEngine( const uint32_t engineClass, const uint32_t engineInstance );
        TEngineParams_1_9 GetEngineParams( const uint32_t engineIndex );
        TCompletionCode   GetTbsEngineParams( TEngineParams_1_9& engineParams, const uint32_t requestedInstance = -1, const bool isOam = false );
        TCompletionCode   UpdateTbsEngineParams( std::vector<uint64_t>& properties );
        bool              IsTbsEngineValid( const TEngineParams_1_9& engineParams, const uint32_t requestedInstance = -1, const bool isOam = false ) const;
        uint32_t          GetEnginesCount();

    private:
        std::vector<TEngineParams_1_9> m_engines;
    };

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Description:
    //     Keeps information related to sub devices.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CSubDevices
    {
    public:
        CSubDevices( CAdapter& adapter );
        virtual ~CSubDevices();

        bool            IsSupported();
        TCompletionCode Enumerate();

        TCompletionCode GetAdapterParams( TAdapterParams_1_9& params );
        TCompletionCode GetSubDeviceParams( const uint32_t subDeviceIndex, TSubDeviceParams_1_9& params );
        TCompletionCode GetEngineParams( const uint32_t subDeviceIndex, const uint32_t engineIndex, TEngineParams_1_9& params );
        TCompletionCode GetTbsEngineParams( const uint32_t subDeviceIndex, TEngineParams_1_9& params, const uint32_t requestedEngineInstance = -1, const bool isOam = false );
        TCompletionCode UpdateTbsEngineParams( const uint32_t subDeviceIndex, std::vector<uint64_t>& properties );
        uint32_t        GetClassInstancesCount( const uint32_t subDeviceIndex, const uint32_t requestedEngineClass );
        TCompletionCode GetGpuCpuTimestamps( const uint32_t subDeviceIndex, const uint64_t gpuTimestampFrequency, uint64_t& gpuTimestampNs, uint64_t& cpuTimestampNs );

        uint32_t        GetDeviceCount();
        CMetricsDevice* GetDevice( const uint32_t index );
        bool            FindDevice( const CMetricsDevice* metricsDevice );

        CMetricsDevice* OpenDevice( const uint32_t index );
        CMetricsDevice* OpenDeviceFromFile( const uint32_t index, const char* filename, void* parameters );
        void            SetRootDevice( CMetricsDevice* metricsDevice );
        void            RemoveDevice( const CMetricsDevice* metricsDevice );

    private:
        CAdapter&                      m_adapter;
        std::vector<CMetricsDevice*>   m_subDevices;
        std::vector<CSubDeviceEngines> m_subDeviceEngines;
        bool                           m_subDevicesSupported;

    private:
        TCompletionCode GetEngines( CDriverInterfaceLinuxPerf& driver, std::vector<drm_i915_engine_info>& engines );
        TCompletionCode GetMemoryRegions( CDriverInterfaceLinuxPerf& driver, std::vector<drm_i915_memory_region_info>& regions );
        TCompletionCode GetEngineDistances( CDriverInterfaceLinuxPerf& driver, const std::vector<drm_i915_engine_info>& engines, const std::vector<drm_i915_memory_region_info>& regions, std::vector<prelim_drm_i915_query_distance_info>& distances );
        TCompletionCode GetSubDeviceEngines( const std::vector<prelim_drm_i915_query_distance_info>& distances );
    };
}; // namespace MetricsDiscoveryInternal
