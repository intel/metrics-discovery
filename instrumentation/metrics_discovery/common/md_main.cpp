/*========================== begin_copyright_notice ============================

Copyright (C) 2019-2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_main.cpp

//     Abstract:   Metrics Discovery main file

#include "metrics_discovery_api.h"
#include "md_adapter.h"
#include "md_adapter_group.h"
#include "md_exports.h"
#include "md_metrics.h"
#include "md_per_platform_preamble.h"
#include "md_utils.h"

using namespace MetricsDiscoveryInternal;

#ifdef __cplusplus
extern "C"
{
#endif

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     API Entry
    //
    // Function:
    //     OpenAdapterGroup
    //
    // Description:
    //     Opens main MDAPI root object - adapter group or retrieves an instance
    //     opened before. Only one instance of adapter group may be created, all
    //     Open() calls are reference counted.
    //
    // Input:
    //     IAdapterGroupLatest** adapterGroup - [out] created / retrieved adapter group
    //
    // Output:
    //     TCompletionCode                    - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode OpenAdapterGroup( IAdapterGroupLatest** adapterGroup )
    {
        MD_LOG_ENTER();
        MD_CHECK_PTR_RET( adapterGroup, CC_ERROR_INVALID_PARAMETER );

        TCompletionCode retVal = CAdapterGroup::Open( (CAdapterGroup**) adapterGroup );

        MD_LOG_EXIT();
        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     API Entry
    //
    // Function:
    //     OpenMetricsDevice
    //
    // Description:
    //     Opens metrics device or retrieves an instance opened before. Only one
    //     instance per adapter may exist. All OpenMetricsDevice() calls are
    //     reference counted.
    //
    //     List of operations:
    //         1. Get AdapterGroup
    //             - Create one if null
    //         2. Get default adapter
    //         3. OpenMetricsDevice on it
    //         4. Destroy anything that was created if error
    //
    // Input:
    //     IMetricsDeviceLatest** metricsDevice - [out] created / retrieved metrics device
    //
    // Output:
    //     TCompletionCode                      - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode OpenMetricsDevice( IMetricsDeviceLatest** metricsDevice )
    {
        MD_LOG_ENTER();
        MD_CHECK_PTR_RET( metricsDevice, CC_ERROR_INVALID_PARAMETER );

        CAdapterGroup* adapterGroup = nullptr;

        TCompletionCode retVal = CAdapterGroup::Open( &adapterGroup );
        if( retVal != CC_OK && retVal != CC_ALREADY_INITIALIZED )
        {
            MD_LOG( LOG_ERROR, "Failed to open group device" );
            MD_LOG_EXIT();
            return retVal;
        }
        MD_CHECK_PTR_RET( adapterGroup, CC_ERROR_GENERAL );

        CAdapter* defaultAdapter = adapterGroup->GetDefaultAdapter();
        if( !defaultAdapter )
        {
            MD_LOG( LOG_ERROR, "No adapters available" );
            adapterGroup->Close();
            MD_LOG_EXIT();
            return CC_ERROR_NOT_SUPPORTED;
        }

        retVal = defaultAdapter->OpenMetricsDevice( metricsDevice );
        if( retVal != CC_OK && retVal != CC_ALREADY_INITIALIZED )
        {
            adapterGroup->Close();
        }

        MD_LOG_EXIT_A( defaultAdapter->GetAdapterId() );
        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     API Entry
    //
    // Function:
    //     OpenMetricsDeviceFromFile
    //
    // Description:
    //     Opens metrics device or uses an instance opened before (just like OpenMetricsDevice),
    //     then loads custom metric sets / metrics from a file and merged them into the 'standard'
    //     metrics device.
    //
    //     List of operations:
    //         1. Get AdapterGroup
    //             - Create one if null
    //         2. Get default adapter
    //         3. OpenMetricsDeviceFromFile on it
    //         4. Destroy anything that was created if error
    //
    // Input:
    //     const char*             fileName       - custom metric file
    //     void*                   openParams     - open params
    //     IMetricsDeviceLatest**  metricsDevice  - [out] created / retrieved metrics device
    //
    // Output:
    //     TCompletionCode                        - CC_OK or CC_ALREADY_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode OpenMetricsDeviceFromFile( const char* fileName, void* openParams, IMetricsDeviceLatest** metricsDevice )
    {
        MD_LOG_ENTER();
        MD_CHECK_PTR_RET( metricsDevice, CC_ERROR_INVALID_PARAMETER );

        CAdapterGroup* adapterGroup = nullptr;

        TCompletionCode retVal = CAdapterGroup::Open( &adapterGroup );
        if( retVal != CC_OK && retVal != CC_ALREADY_INITIALIZED )
        {
            MD_LOG( LOG_ERROR, "Failed to open adapter group" );
            MD_LOG_EXIT();
            return retVal;
        }
        MD_CHECK_PTR_RET( adapterGroup, CC_ERROR_GENERAL );

        CAdapter* defaultAdapter = adapterGroup->GetDefaultAdapter();
        if( !defaultAdapter )
        {
            adapterGroup->Close();
            MD_LOG( LOG_ERROR, "No adapters available" );
            MD_LOG_EXIT();
            return CC_ERROR_NOT_SUPPORTED;
        }

        retVal = defaultAdapter->OpenMetricsDeviceFromFile( fileName, openParams, metricsDevice );
        if( retVal != CC_OK && retVal != CC_ALREADY_INITIALIZED )
        {
            adapterGroup->Close();
        }

        MD_LOG_EXIT_A( defaultAdapter->GetAdapterId() );
        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     API Entry
    //
    // Function:
    //     CloseMetricsDevice
    //
    // Description:
    //     Decreases metrics device reference counter and closes it (frees up recourses)
    //     if the counter reaches 0.
    //
    //     List of operations:
    //         1. Get AdapterGroup
    //             - Return error if null
    //         2. Get default adapter
    //         3. CloseMetricsDevice on it
    //
    // Input:
    //     IMetricsDeviceLatest* metricsDevice - metrics device to close
    //
    // Output:
    //     TCompletionCode                     - CC_OK or CC_STILL_INITIALIZED means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CloseMetricsDevice( IMetricsDeviceLatest* metricsDevice )
    {
        MD_LOG_ENTER();
        MD_CHECK_PTR_RET( metricsDevice, CC_ERROR_INVALID_PARAMETER );

        CAdapterGroup* adapterGroup = CAdapterGroup::Get();
        if( !adapterGroup )
        {
            MD_LOG( LOG_ERROR, "Adapter group not found" );
            return CC_ERROR_NOT_SUPPORTED;
        }

        CAdapter* defaultAdapter = adapterGroup->GetDefaultAdapter();
        if( !defaultAdapter )
        {
            MD_LOG( LOG_ERROR, "No adapters available" );
            MD_LOG_EXIT();
            return CC_ERROR_NOT_SUPPORTED;
        }

        TCompletionCode retVal = defaultAdapter->CloseMetricsDevice( metricsDevice );
        if( retVal == CC_OK || retVal == CC_STILL_INITIALIZED )
        {
            // Close adapter group only if metrics device existed before calling this API call
            adapterGroup->Close();
        }

        MD_LOG_EXIT();
        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     API Entry
    //
    // Function:
    //     SaveMetricsDeviceToFile
    //
    // Description:
    //     Creates custom metric file containing only custom metrics - standard ones
    //     aren't saved.
    //
    //     List of operations:
    //         1. Get AdapterGroup
    //             - Error if null
    //         2. Get default adapter
    //         3. SaveMetricsDeviceToFile on it
    //
    // Input:
    //     const char*           fileName       - target file name
    //     void*                 saveParams     - save params
    //     IMetricsDeviceLatest* metricsDevice  - target metrics device
    //
    // Output:
    //     TCompletionCode                      - CC_OK means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode SaveMetricsDeviceToFile( const char* fileName, void* saveParams, IMetricsDeviceLatest* metricsDevice )
    {
        MD_LOG_ENTER();
        MD_CHECK_PTR_RET( fileName, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( metricsDevice, CC_ERROR_INVALID_PARAMETER );

        CAdapterGroup* adapterGroup = CAdapterGroup::Get();
        if( !adapterGroup )
        {
            MD_LOG( LOG_ERROR, "Adapter group not found" );
            return CC_ERROR_NOT_SUPPORTED;
        }

        CAdapter* defaultAdapter = adapterGroup->GetDefaultAdapter();
        if( !defaultAdapter )
        {
            MD_LOG( LOG_ERROR, "No adapters available" );
            MD_LOG_EXIT();
            return CC_ERROR_NOT_SUPPORTED;
        }

        TCompletionCode retVal = defaultAdapter->SaveMetricsDeviceToFile( fileName, saveParams, metricsDevice );

        MD_LOG_EXIT_A( defaultAdapter->GetAdapterId() );
        return retVal;
    }

#ifdef __cplusplus
}
#endif
