/*========================== begin_copyright_notice ============================

Copyright (C) 2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_oam_concurrent_group.cpp

//     Abstract:   C++ Metrics Discovery oam concurrent group implementation

#include "md_oam_concurrent_group.h"
#include "md_calculation.h"
#include "md_driver_ifc.h"

#include <cstring>

namespace MetricsDiscoveryInternal
{

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAMConcurrentGroup
    //
    // Method:
    //     COAMConcurrentGroup constructor
    //
    // Description:
    //     Constructor.
    //
    // Input:
    //     CMetricsDevice* device                 - parent metrics device
    //     const char*     name                   - concurrent group name
    //     const char*     description            - concurrent group description
    //     const uint32_t  measurementTypeMask    - measurement type mask
    //
    //////////////////////////////////////////////////////////////////////////////
    COAMConcurrentGroup::COAMConcurrentGroup( CMetricsDevice* device, const char* name, const char* description, const uint32_t measurementTypeMask )
        : COAConcurrentGroup( device, name, description, measurementTypeMask, STREAM_TYPE_OAM, GetOaBufferTypeFromName( name, OBTAIN_ADAPTER_ID( device ) ) )
    {
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAMConcurrentGroup
    //
    // Method:
    //     GetStreamTypeFromSamplingType
    //
    // Description:
    //     Returns stream type basing on given sampling type.
    //
    // Input:
    //     const TSamplingType samplingTyp - sampling type
    //     TStreamType&        streamType  - (out) stream type
    //
    // Output:
    //     TCompletionCode                 - result of operation (*CC_OK* is OK)
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode COAMConcurrentGroup::GetStreamTypeFromSamplingType( const TSamplingType samplingType, TStreamType& streamType ) const
    {
        if( samplingType == SAMPLING_TYPE_OAM_TIMER )
        {
            streamType = STREAM_TYPE_OAM;
            return CC_OK;
        }

        return CC_ERROR_NOT_SUPPORTED;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAMConcurrentGroup
    //
    // Method:
    //     IsSupported
    //
    // Description:
    //     Checks if OAM concurrent groups is supported on current platform.
    //
    // Input:
    //    const char*     symbolicName  - concurrent group symbolic name
    //    CMetricsDevice& metricsDevice - metrics device
    //
    // Output:
    //     bool                         - true if supported
    //
    //////////////////////////////////////////////////////////////////////////////
    bool COAMConcurrentGroup::IsSupported( const char* symbolicName, CMetricsDevice& metricsDevice )
    {
        const uint32_t            adapterId    = metricsDevice.GetAdapter().GetAdapterId();
        const GTDI_OA_BUFFER_TYPE oaBufferType = GetOaBufferTypeFromName( symbolicName, adapterId );

        if( oaBufferType == GTDI_OA_BUFFER_TYPE_DEFAULT )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "Error: Incorrect oa buffer type for OAM" );
            return false;
        }

        auto& driverInterface = metricsDevice.GetDriverInterface();

        return driverInterface.IsOaBufferSupported( oaBufferType, &metricsDevice );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAMConcurrentGroup
    //
    // Method:
    //     GetOaBufferTypeFromName
    //
    // Description:
    //     Gets oa buffer type from concurrent group symbolic name.
    //
    // Input:
    //     const char*    symbolicName - concurrent group symbolic name
    //     const uint32_t adapterId    - adapter id
    //
    // Output:
    //     GTDI_OA_BUFFER_TYPE         - oa buffer type
    //
    //////////////////////////////////////////////////////////////////////////////
    GTDI_OA_BUFFER_TYPE COAMConcurrentGroup::GetOaBufferTypeFromName( const char* symbolicName, const uint32_t adapterId )
    {
        if( strlen( symbolicName ) > 3 && strstr( symbolicName, "OAM" ) != nullptr )
        {
            const uint32_t oamBufferType = symbolicName[3] - '0' + 1;
            if( oamBufferType >= GTDI_OA_BUFFER_TYPE_OAM_SLICE_0 && oamBufferType <= GTDI_OA_BUFFER_TYPE_OAM_SLICE_5 )
            {
                return static_cast<GTDI_OA_BUFFER_TYPE>( oamBufferType );
            }
        }

        MD_LOG_A( adapterId, LOG_ERROR, "ERROR: Cannot get oa buffer type for OAM. Given symbolic name: %s", symbolicName );

        return GTDI_OA_BUFFER_TYPE_DEFAULT;
    }

} // namespace MetricsDiscoveryInternal
