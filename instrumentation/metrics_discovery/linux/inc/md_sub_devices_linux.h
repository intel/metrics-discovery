/*========================== begin_copyright_notice ============================

Copyright (C) 2021-2025 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_sub_devices_linux.h

//     Abstract:   C++ sub devices implementation for Linux

#pragma once

#include "metrics_discovery_api.h"
#include <vector>

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
    class CMetricsDevice;
    class CSubDevices;

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
        CSubDeviceEngines( CSubDevices& subDevices );

        TCompletionCode     AddEngine( const uint32_t engineClass, const uint32_t engineInstance, const uint32_t gtId, const uint32_t oaUnit );
        TEngineParamsLatest GetEngineParams( const uint32_t engineIndex );
        TCompletionCode     GetTbsEngineParams( TEngineParamsLatest& engineParams, const uint32_t requestedInstance = -1, const bool isOam = false );
        uint32_t            GetEnginesCount();

    private:
        CSubDevices&                     m_subDevices;
        std::vector<TEngineParamsLatest> m_engines;
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
        ~CSubDevices() {};

        bool            IsSupported();
        TCompletionCode Enumerate();

        TCompletionCode GetAdapterParams( TAdapterParams_1_9& params );
        TCompletionCode GetSubDeviceParams( const uint32_t subDeviceIndex, TSubDeviceParams_1_9& params );
        TCompletionCode GetEngineParams( const uint32_t subDeviceIndex, const uint32_t engineIndex, TEngineParamsLatest& params );
        TCompletionCode GetTbsEngineParams( const uint32_t subDeviceIndex, TEngineParamsLatest& params, const uint32_t requestedEngineInstance = -1, const bool isOam = false );
        uint32_t        GetClassInstancesCount( const uint32_t subDeviceIndex, const uint32_t requestedEngineClass );
        bool            IsTbsEngineValid( const TEngineParamsLatest& engineParams, const uint32_t requestedInstance = -1, const bool isOam = false ) const;

        uint32_t        GetDeviceCount();
        CMetricsDevice* GetDevice( const uint32_t index );
        bool            FindDevice( const CMetricsDevice* metricsDevice );

        CMetricsDevice* OpenDevice( const uint32_t index );
        CMetricsDevice* OpenDeviceFromFile( const uint32_t index, const char* filename, void* parameters );
        void            SetRootDevice( CMetricsDevice* metricsDevice );
        void            RemoveDevice( const CMetricsDevice* metricsDevice );

        void            MakeSpaceForMetricsDevices();
        void            AppendSubDeviceEngine();
        uint32_t        GetAllEnginesCount();
        TCompletionCode AddEngine( const uint32_t engineClass, const uint32_t engineInstance, const uint32_t gtId, const uint32_t oaUnit );

    private:
        CAdapter&                      m_adapter;
        std::vector<CMetricsDevice*>   m_subDevices;
        std::vector<CSubDeviceEngines> m_subDeviceEngines;
    };
}; // namespace MetricsDiscoveryInternal
