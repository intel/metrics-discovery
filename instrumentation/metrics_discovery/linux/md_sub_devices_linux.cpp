//////////////////////////////////////////////////////////////////////////////
//
//  Copyright © 2019-2021, Intel Corporation
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
//////////////////////////////////////////////////////////////////////////////

//     File Name:  md_sub_devices_linux.cpp

//     Abstract:   C++ sub devices implementation for Linux

#include "md_sub_devices_linux.h"
#include "md_driver_ifc.h"

namespace MetricsDiscoveryInternal
{
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
    {
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
        return false;
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
    //     Enumerates sub devices.
    //
    // Output:
    //     TCompletionCode - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSubDevices::Enumerate()
    {
        return TCompletionCode::CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     OpenDevice
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
        return nullptr;
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
        return nullptr;
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
        return nullptr;
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
    //     const IMetricsDevice_1_5* metricsDevice
    //
    //////////////////////////////////////////////////////////////////////////////
    void CSubDevices::RemoveDevice( const IMetricsDevice_1_5* metricsDevice )
    {
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CSubDevices
    //
    // Method:
    //     GetDeviceCount
    //
    // Description:
    //     Returns sub devices count.
    //
    // Output:
    //     uint32_t - number of sub devices
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CSubDevices::GetDeviceCount()
    {
        return 0;
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
    //     const IMetricsDevice_1_5* metricsDevice  - sub device
    //
    // Output:
    //     bool                                     - sub device pointer
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CSubDevices::FindDevice( const IMetricsDevice_1_5* metricsDevice )
    {
        return false;
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
        params.SubDevicesCount = 0;

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
    //     const uint32_t subDeviceIndex - sub device index
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
        params = {};

        return TCompletionCode::CC_ERROR_NOT_SUPPORTED;
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
    //     const uint32_t subDeviceIndex   - sub device index
    //     const uint32_t engineIndex      - engine index
    //
    // Output:
    //     TEngineParams_1_9& engineParams - engine parameters
    //     TCompletionCode                 - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSubDevices::GetEngineParams(
        const uint32_t     subDeviceIndex,
        const uint32_t     engineIndex,
        TEngineParams_1_9& engineParams )
    {
        engineParams = {};

        return TCompletionCode::CC_ERROR_NOT_SUPPORTED;
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
    //     TEngineParams_1_9& params     - engine parameters
    //     TCompletionCode               - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CSubDevices::GetTbsEngineParams( const uint32_t subDeviceIndex, TEngineParams_1_9& engineParams )
    {
        engineParams = {};

        return TCompletionCode::CC_ERROR_NOT_SUPPORTED;
    }

}; // namespace MetricsDiscoveryInternal
