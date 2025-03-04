/*========================== begin_copyright_notice ============================

Copyright (C) 2022-2025 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_oam_concurrent_group.cpp

//     Abstract:   C++ Metrics Discovery oam concurrent group implementation

#include "md_oam_concurrent_group.h"
#include "md_events.h"
#include "md_metric_enumerator.h"
#include "md_calculation.h"
#include "md_driver_ifc.h"

#include <cstring>

namespace MetricsDiscoveryInternal
{
    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     GetMetricEnumerator
    //
    // Description:
    //     Returns metrics enumerator.
    //
    // Output:
    //     IMetricEnumerator_1_13* - a pointer to a metric enumerator object.
    //
    //////////////////////////////////////////////////////////////////////////////
    IMetricEnumerator_1_13* COAMConcurrentGroup::GetMetricEnumerator( void )
    {
        return COAConcurrentGroup::GetMetricEnumerator( OA_REPORTING_MEDIA );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAMConcurrentGroup
    //
    // Method:
    //     AddMetricSet
    //
    // Description:
    //     Adds a metric set to the concurrent group.
    //
    // Input:
    //     const char* symbolName - metric set symbol name.
    //     const char* shortName  - metric set short name.
    //
    // Output:
    //     IMetricSet_1_13*       - a pointer to a created metric set.
    //
    //////////////////////////////////////////////////////////////////////////////
    IMetricSet_1_13* COAMConcurrentGroup::AddMetricSet( const char* symbolName, const char* shortName )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();
        MD_CHECK_PTR_RET_A( adapterId, symbolName, nullptr );
        MD_CHECK_PTR_RET_A( adapterId, shortName, nullptr );

        constexpr uint32_t deltaReportSize    = 0;
        constexpr uint32_t snapshotReportSize = 128;
        const uint32_t     platformIndex      = m_device.GetPlatformIndex();
        TReportType        reportFormat       = OA_REPORT_TYPE_LAST;

        switch( platformIndex )
        {
            case GENERATION_MTL:
            case GENERATION_ARL:
            case GENERATION_BMG:
            case GENERATION_LNL:
            case GENERATION_PTL:
                reportFormat = OA_REPORT_TYPE_128B_MPEC8_NOA16;
                break;

            default:
                return nullptr;
        }

        uint8_t          platformMaskByteArray[MD_PLATFORM_MASK_BYTE_ARRAY_SIZE] = {};
        TByteArrayLatest platformMask                                            = { MD_PLATFORM_MASK_BYTE_ARRAY_SIZE, platformMaskByteArray };

        auto ret = SetPlatformMask( adapterId, &platformMask, nullptr, false, platformIndex );
        if( ret != CC_OK )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "ERROR: Cannot set platform mask!" );
            return nullptr;
        }

        auto metricSet = CConcurrentGroup::AddMetricSet(
            symbolName,
            shortName,
            API_TYPE_IOSTREAM,
            GPU_GENERIC,
            snapshotReportSize,
            deltaReportSize,
            reportFormat,
            &platformMask,                        // platformMask
            nullptr,                              // availabilityEquation
            static_cast<uint32_t>( GT_TYPE_ALL ), // gtMask
            true                                  // isCustom
        );

        MD_CHECK_PTR_RET_A( adapterId, metricSet, nullptr );

        metricSet->SetToFlexible();

        return metricSet;
    }

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
    //     CMetricsDevice& device                 - parent metrics device
    //     const char*     name                   - concurrent group name
    //     const char*     description            - concurrent group description
    //     const uint32_t  measurementTypeMask    - measurement type mask
    //
    //////////////////////////////////////////////////////////////////////////////
    COAMConcurrentGroup::COAMConcurrentGroup( CMetricsDevice& device, const char* name, const char* description, const uint32_t measurementTypeMask )
        : COAConcurrentGroup( device, name, description, measurementTypeMask, STREAM_TYPE_OAM, GetOaBufferTypeFromName( name, device ) )
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
    //     const char*     symbolName - concurrent group symbol name
    //     CMetricsDevice& device     - metrics device
    //
    // Output:
    //     bool                       - true if supported
    //
    //////////////////////////////////////////////////////////////////////////////
    bool COAMConcurrentGroup::IsSupported( const char* symbolName, CMetricsDevice& device )
    {
        return GetOaBufferTypeFromName( symbolName, device ) != GTDI_OA_BUFFER_TYPE_DEFAULT;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAMConcurrentGroup
    //
    // Method:
    //     IsValidSymbolName
    //
    // Description:
    //     Checks if OAM concurrent group symbol name is valid.
    //
    // Input:
    //     const char* symbolName - concurrent group symbol name
    //
    // Output:
    //     bool                   - true if valid
    //
    //////////////////////////////////////////////////////////////////////////////
    bool COAMConcurrentGroup::IsValidSymbolName( const char* symbolName )
    {
        return strlen( symbolName ) == 4 && strstr( symbolName, "OAM" ) != nullptr;
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
    //     Gets oa buffer type from concurrent group symbol name.
    //
    // Input:
    //     const char*     symbolName - concurrent group symbol name
    //     CMetricsDevice& device     - metrics device
    //
    // Output:
    //     GTDI_OA_BUFFER_TYPE        - oa buffer type
    //
    //////////////////////////////////////////////////////////////////////////////
    GTDI_OA_BUFFER_TYPE COAMConcurrentGroup::GetOaBufferTypeFromName( const char* symbolName, CMetricsDevice& device )
    {
        if( IsValidSymbolName( symbolName ) )
        {
            const uint32_t oaBuferCount = device.GetOaBufferCount();

            if( symbolName[3] == 'G' ) // OAMG
            {
                return static_cast<GTDI_OA_BUFFER_TYPE>( oaBuferCount - 1 );
            }
            else
            {
                const uint32_t oamBufferType = symbolName[3] - '0' + 1;
                if( oamBufferType >= GTDI_OA_BUFFER_TYPE_OAM_SLICE_0 && oamBufferType < oaBuferCount )
                {
                    return static_cast<GTDI_OA_BUFFER_TYPE>( oamBufferType );
                }

                const uint32_t adapterId = device.GetAdapter().GetAdapterId();
                MD_LOG_A( adapterId, LOG_DEBUG, "ERROR: Cannot get oa buffer type for OAM. Given symbol name: %s, OA buffer count: %u", symbolName, oaBuferCount );
            }
        }

        return GTDI_OA_BUFFER_TYPE_DEFAULT;
    }

} // namespace MetricsDiscoveryInternal
