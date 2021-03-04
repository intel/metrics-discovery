//////////////////////////////////////////////////////////////////////////////
//
//  Copyright © 2021, Intel Corporation
//
//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included
//  in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
//  IN THE SOFTWARE.
//
//  File Name:  md_sub_devices_linux_.h
//
//  Abstract:   C++ sub devices implementation for Linux
//
//////////////////////////////////////////////////////////////////////////////
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
