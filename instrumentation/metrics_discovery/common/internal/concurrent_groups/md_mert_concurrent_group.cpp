/*========================== begin_copyright_notice ============================

Copyright (C) 2025 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_mert_concurrent_group.cpp

//     Abstract:   C++ Metrics Discovery mert concurrent group implementation

#include "md_mert_concurrent_group.h"
#include "md_events.h"
#include "md_adapter.h"
#include "md_metrics_device.h"
#include "md_metric_enumerator.h"
#include "md_metric_set.h"
#include "md_driver_ifc.h"
#include "md_utils.h"

#include <cstring>

namespace MetricsDiscoveryInternal
{
    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMERTConcurrentGroup
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
    IMetricEnumerator_1_13* CMERTConcurrentGroup::GetMetricEnumerator( void )
    {
        return COAConcurrentGroup::GetMetricEnumerator( OA_REPORTING_MERT );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMERTConcurrentGroup
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
    IMetricSet_1_13* CMERTConcurrentGroup::AddMetricSet( const char* symbolName, const char* shortName )
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
            case GENERATION_CRI:
                reportFormat = OA_REPORT_TYPE_192B_MERT_PEC8LL;
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
    //     CMERTConcurrentGroup
    //
    // Method:
    //     CMERTConcurrentGroup constructor
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
    CMERTConcurrentGroup::CMERTConcurrentGroup( CMetricsDevice& device, const char* name, const char* description, const uint32_t measurementTypeMask )
        : COAConcurrentGroup( device, name, description, measurementTypeMask, STREAM_TYPE_OAMERT, GTDI_OA_BUFFER_TYPE_MERT )
    {
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMERTConcurrentGroup
    //
    // Method:
    //     GetStreamTypeFromSamplingType
    //
    // Description:
    //     Returns stream type based on given sampling type.
    //
    // Input:
    //     const TSamplingType samplingType - sampling type
    //     TStreamType&        streamType   - (out) stream type
    //
    // Output:
    //     TCompletionCode                  - result of operation (*CC_OK* is OK)
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMERTConcurrentGroup::GetStreamTypeFromSamplingType( const TSamplingType samplingType, TStreamType& streamType ) const
    {
        if( samplingType == SAMPLING_TYPE_OAMERT_TIMER )
        {
            streamType = STREAM_TYPE_OAMERT;
            return CC_OK;
        }

        return CC_ERROR_NOT_SUPPORTED;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMERTConcurrentGroup
    //
    // Method:
    //     IsSupported
    //
    // Description:
    //     Checks if MERT concurrent group is supported on current platform.
    //
    // Input:
    //     CMetricsDevice& device - metrics device
    //
    // Output:
    //     bool - true if supported
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMERTConcurrentGroup::IsSupported( CMetricsDevice& device )
    {
        return ( device.GetOaBufferMask() & GTDI_OA_BUFFER_MASK_MERT ) != 0;
    }
} // namespace MetricsDiscoveryInternal
