/*========================== begin_copyright_notice ============================

Copyright (C) 2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_adapter.h

//     Abstract:   C++ Metrics Discovery internal adapter header

#pragma once

#include "metrics_discovery_internal_api.h"
#include "md_sub_devices_linux.h"

#define MD_METRIC_EXTENSION "MD_METRIC_EXTENSION"

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    ///////////////////////////////////////////////////////////////////////////////
    // Forward declarations:                                                     //
    ///////////////////////////////////////////////////////////////////////////////
    class CAdapterGroup;
    class CAdapterHandle;
    class CDriverInterface;
    class CMetricsDevice;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CAdapter
    //
    // Description:
    //     Represents a single GPU adapter.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CAdapter : public IAdapterLatest
    {
    public:
        // API 1.11:
        // New.
        virtual TCompletionCode SaveMetricsDeviceToFile( const char* fileName, void* saveParams, IMetricsDevice_1_11* metricsDevice, const uint32_t minMajorApiVersion, const uint32_t minMinorApiVersion );
        // Updates.
        virtual TCompletionCode OpenMetricsDevice( IMetricsDevice_1_11** metricsDevice );
        virtual TCompletionCode OpenMetricsDeviceFromFile( const char* fileName, void* openParams, IMetricsDevice_1_11** metricsDevice );
        virtual TCompletionCode OpenMetricsSubDevice( const uint32_t subDeviceIndex, IMetricsDevice_1_11** metricsDevice );
        virtual TCompletionCode OpenMetricsSubDeviceFromFile( const uint32_t subDeviceIndex, const char* fileName, void* openParams, IMetricsDevice_1_11** metricsDevice );

        // API 1.10:
        // Updates.
        virtual TCompletionCode OpenMetricsDevice( IMetricsDevice_1_10** metricsDevice );
        virtual TCompletionCode OpenMetricsDeviceFromFile( const char* fileName, void* openParams, IMetricsDevice_1_10** metricsDevice );
        virtual TCompletionCode OpenMetricsSubDevice( const uint32_t subDeviceIndex, IMetricsDevice_1_10** metricsDevice );
        virtual TCompletionCode OpenMetricsSubDeviceFromFile( const uint32_t subDeviceIndex, const char* fileName, void* openParams, IMetricsDevice_1_10** metricsDevice );

        // API 1.9:
        // Updates.
        virtual const TAdapterParamsLatest*   GetParams() const;
        virtual const TSubDeviceParamsLatest* GetSubDeviceParams( const uint32_t subDeviceIndex );
        virtual const TEngineParamsLatest*    GetEngineParams( const uint32_t subDeviceIndex, const uint32_t engineIndex );
        virtual TCompletionCode               OpenMetricsSubDevice( const uint32_t subDeviceIndex, IMetricsDevice_1_5** metricsDevice );
        virtual TCompletionCode               OpenMetricsSubDeviceFromFile( const uint32_t subDeviceIndex, const char* fileName, void* openParams, IMetricsDevice_1_5** metricsDevice );

        // API 1.6:
        virtual TCompletionCode Reset();
        virtual TCompletionCode OpenMetricsDevice( IMetricsDevice_1_5** metricsDevice );
        virtual TCompletionCode OpenMetricsDeviceFromFile( const char* fileName, void* openParams, IMetricsDevice_1_5** metricsDevice );
        virtual TCompletionCode CloseMetricsDevice( IMetricsDevice_1_5* metricsDevice );
        virtual TCompletionCode SaveMetricsDeviceToFile( const char* fileName, void* saveParams, IMetricsDevice_1_5* metricsDevice );

    public:
        // Constructor & Destructor:
        CAdapter( CAdapterGroup& adapterGroup, const TAdapterParamsLatest& params, CAdapterHandle& adapterHandle );
        virtual ~CAdapter();

        CAdapter( const CAdapter& )            = delete; // Delete copy-constructor
        CAdapter& operator=( const CAdapter& ) = delete; // Delete assignment operator

        // Non-API:
        TCompletionCode OpenMetricsSubDevice( const uint32_t subDeviceIndex, CMetricsDevice** metricsDevice );
        TCompletionCode OpenMetricsSubDeviceFromFile( const uint32_t subDeviceIndex, const char* fileName, void* openParams, CMetricsDevice** metricsDevice );
        TCompletionCode CloseMetricsDevice( CMetricsDevice* metricsDevice );
        TCompletionCode SaveMetricsDeviceToFile( const char* fileName, void* saveParams, CMetricsDevice* metricsDevice, const uint32_t minMajorApiVersion, const uint32_t minMinorApiVersion );

        TCompletionCode OpenMetricsDeviceByIndex( CMetricsDevice** metricsDevice, const uint32_t subDeviceIndex );
        TCompletionCode OpenMetricsDeviceFromFileByIndex( const char* fileName, void* openParams, CMetricsDevice** metricsDevice, const uint32_t subDeviceIndex );

        CDriverInterface* GetDriverInterface();
        CSubDevices&      GetSubDevices();

        uint32_t GetAdapterId() const;

    private:
        // Driver interface:
        TCompletionCode CreateDriverInterface();
        void            DestroyDriverInterface();
        TCompletionCode EnableDriverSupport( bool enable );

        // Synchronization:
        TCompletionCode GetOpenCloseSemaphore();
        TCompletionCode ReleaseOpenCloseSemaphore();

        // Metrics device:
        TCompletionCode CreateMetricsDevice( CMetricsDevice** metricsDevice, const uint32_t subDeviceIndex = 0 );
        void            DestroyMetricsDevice();

    private:
        // Variables:
        uint32_t             m_adapterId;          // System-dependent adapter id
        TAdapterParamsLatest m_params;             // Adapter information
        CAdapterHandle*      m_adapterHandle;      // OS adapter handle which the given CAdapter object represents
        CDriverInterface*    m_driverInterface;    // Driver interface for this adapter
        CMetricsDevice*      m_metricsDevice;      // Metrics device opened on this adapter
        void*                m_openCloseSemaphore; // Semaphore used during metrics device operations

        // Sub devices.
        CSubDevices            m_subDevices;
        TSubDeviceParamsLatest m_subDeviceParams;
        TEngineParamsLatest    m_engineParams;

        CAdapterGroup& m_adapterGroup; // Parent adapter group
    };
} // namespace MetricsDiscoveryInternal
