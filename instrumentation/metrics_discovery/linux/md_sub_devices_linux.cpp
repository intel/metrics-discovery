/*========================== begin_copyright_notice ============================

Copyright (C) 2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

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
    //     const CMetricsDevice* metricsDevice - sub device
    //
    //////////////////////////////////////////////////////////////////////////////
    void CSubDevices::RemoveDevice( const CMetricsDevice* metricsDevice )
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
    //     const CMetricsDevice* metricsDevice  - sub device
    //
    // Output:
    //     bool                                 - sub device pointer
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CSubDevices::FindDevice( const CMetricsDevice* metricsDevice )
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
