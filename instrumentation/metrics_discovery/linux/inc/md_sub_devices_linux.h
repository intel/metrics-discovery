/*========================== begin_copyright_notice ============================

Copyright (C) 2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_sub_devices_linux.h

//     Abstract:   C++ sub devices implementation for Linux

#pragma once

#include "metrics_discovery_api.h"
#include "md_utils.h"

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
    class CDriverInterface;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevice
    //
    // Description:
    //     Represents a GPU sub device.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CSubDevices
    {
    public:
        CSubDevices( CAdapter& adapter );

        bool            IsSupported();
        TCompletionCode Enumerate();

        TCompletionCode GetAdapterParams( TAdapterParams_1_9& params );
        TCompletionCode GetSubDeviceParams( const uint32_t subDeviceIndex, TSubDeviceParams_1_9& params );
        TCompletionCode GetEngineParams( const uint32_t subDeviceIndex, const uint32_t engineIndex, TEngineParams_1_9& params );
        TCompletionCode GetTbsEngineParams( const uint32_t subDeviceIndex, TEngineParams_1_9& engineParams );

        CMetricsDevice* GetDevice( const uint32_t index );
        uint32_t        GetDeviceCount();
        bool            FindDevice( const IMetricsDevice_1_5* metricsDevice );

        CMetricsDevice* OpenDevice( const uint32_t index );
        CMetricsDevice* OpenDeviceFromFile( const uint32_t index, const char* filename, void* parameters );
        void            RemoveDevice( const IMetricsDevice_1_5* metricsDevice );
    };
}; // namespace MetricsDiscoveryInternal
