/*========================== begin_copyright_notice ============================

Copyright (C) 2019-2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_calculation.cpp

//     Abstract:   C++ metrics discovery metrics calculation features implementation.

#include "md_calculation.h"
#include "md_adapter.h"
#include "md_equation.h"
#include "md_information.h"
#include "md_metric.h"
#include "md_metric_set.h"
#include "md_metrics_device.h"
#include "md_types.h"
#include <algorithm>
#include <cstring>

namespace MetricsDiscoveryInternal
{
    // Forward declarations //
    template <>
    int32_t CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>::GetInformationIndex( const char* symbolName, CMetricSet* metricSet );

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>
    //
    // Method:
    //     ResetContext
    //
    // Description:
    //     Resets IoStream calculation context to the initial (zero) state.
    //
    // Input:
    //     TCalculationContext& context - (IN/OUT) calculation context
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    void CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>::ResetContext( TCalculationContext& context )
    {
        memset( &context.StreamCalculationContext, 0, sizeof( context.StreamCalculationContext ) );

        context.StreamCalculationContext.ContextIdIdx = -1;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculationManager<MEASUREMENT_TYPE_DELTA_QUERY>
    //
    // Method:
    //     ResetContext
    //
    // Description:
    //     Resets Query calculation context to the initial (zero) state.
    //
    // Input:
    //     TCalculationContext& context - (IN/OUT) calculation context
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    void CMetricsCalculationManager<MEASUREMENT_TYPE_DELTA_QUERY>::ResetContext( TCalculationContext& context )
    {
        memset( &context.QueryCalculationContext, 0, sizeof( context.QueryCalculationContext ) );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>
    //
    // Method:
    //     PrepareContext
    //
    // Description:
    //     Prepares IoStream calculation context for calculations. Sets all the necessary
    //     fields that could be determined using user provided ones.
    //
    // Input:
    //     TCalculationContext& context - (IN/OUT) calculation context
    //
    // Output:
    //     TCompletionCode              - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    TCompletionCode CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>::PrepareContext( TCalculationContext& context )
    {
        TStreamCalculationContext* sc = &context.StreamCalculationContext;
        MD_CHECK_PTR_RET( sc->Calculator, CC_ERROR_INVALID_PARAMETER );

        const uint32_t adapterId = OBTAIN_ADAPTER_ID( sc->Calculator->GetMetricsDevice() );

        MD_CHECK_PTR_RET_A( adapterId, sc->MetricSet, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, sc->RawData, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, sc->Out, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, sc->DeltaValues, CC_ERROR_INVALID_PARAMETER );

        // Find required indices for context filtering, report filtering and PreviousContextId information
        sc->ContextIdIdx    = GetInformationIndex( "ContextId", sc->MetricSet );
        sc->ReportReasonIdx = GetInformationIndex( "ReportReason", sc->MetricSet );

        if( sc->DoContextFiltering )
        {
            if( sc->ContextIdIdx < 0 )
            {
                MD_LOG_A( adapterId, LOG_ERROR, "error: can't find required information for context filtering" );
                MD_LOG_EXIT_A( adapterId );
                return CC_ERROR_INVALID_PARAMETER;
            }
        }

        sc->MetricsAndInformationCount = sc->MetricSet->GetParams()->MetricsCount + sc->MetricSet->GetParams()->InformationCount;
        sc->RawReportSize              = sc->MetricSet->GetParams()->RawReportSize;

        sc->OutReportCount      = 0;
        sc->OutPtr              = sc->Out;
        sc->OutMaxValuesPtr     = sc->OutMaxValues;
        sc->PrevRawDataPtr      = sc->RawData;
        sc->PrevRawReportNumber = 0;
        sc->LastRawDataPtr      = sc->RawData;
        sc->LastRawReportNumber = 0;

        sc->Calculator->Reset( sc->RawReportSize );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculationManager<MEASUREMENT_TYPE_DELTA_QUERY>
    //
    // Method:
    //     PrepareContext
    //
    // Description:
    //     Prepares Query calculation context for calculations. Sets all the necessary
    //     fields that could be determined using user provided ones.
    //
    // Input:
    //     TCalculationContext& context - (IN/OUT) calculation context
    //
    // Output:
    //     TCompletionCode              - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    TCompletionCode CMetricsCalculationManager<MEASUREMENT_TYPE_DELTA_QUERY>::PrepareContext( TCalculationContext& context )
    {
        TQueryCalculationContext* qc = &context.QueryCalculationContext;
        MD_CHECK_PTR_RET( qc->Calculator, CC_ERROR_INVALID_PARAMETER );

        const uint32_t adapterId = OBTAIN_ADAPTER_ID( qc->Calculator->GetMetricsDevice() );

        MD_CHECK_PTR_RET_A( adapterId, qc->MetricSet, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, qc->RawData, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, qc->Out, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, qc->DeltaValues, CC_ERROR_INVALID_PARAMETER );

        qc->Calculator->Reset();

        qc->MetricsAndInformationCount = qc->MetricSet->GetParams()->MetricsCount + qc->MetricSet->GetParams()->InformationCount;
        qc->RawReportSize              = qc->MetricSet->GetParams()->QueryReportSize;

        qc->OutReportCount  = 0;
        qc->OutPtr          = qc->Out;
        qc->OutMaxValuesPtr = qc->OutMaxValues;
        qc->RawDataPtr      = qc->RawData;

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>
    //
    // Method:
    //     CalculateNextReport
    //
    // Description:
    //     Calculates a single report for a IoStream measurements using raw data and
    //     other state variables stored in the given calculation context.
    //     If context filtering is enabled calculation is performed only if starting raw report
    //     is from appropriate context id.
    //
    // Input:
    //     TCalculationContext& context - (IN/OUT) calculation context
    //
    // Output:
    //     bool - true, if report calculated
    //            false, if not - calculation complete for current context
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    bool CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>::CalculateNextReport( TCalculationContext& context )
    {
        TStreamCalculationContext* sc = &context.StreamCalculationContext;
        MD_CHECK_PTR_RET( sc->Calculator, false );

        const uint32_t adapterId = OBTAIN_ADAPTER_ID( sc->Calculator->GetMetricsDevice() );

        if( sc->LastRawReportNumber >= sc->RawReportCount || sc->PrevRawReportNumber >= sc->RawReportCount - 1 )
        {
            // Nothing to be calculated
            MD_LOG_A( adapterId, LOG_DEBUG, "Calculation complete" );
            if( CC_OK != sc->Calculator->SaveReport( sc->LastRawDataPtr ) )
            {
                MD_LOG_A( adapterId, LOG_DEBUG, "Unable to store last raw report for reuse." );
            }

            return false;
        }

        if( sc->Calculator->SavedReportPresent() && sc->PrevRawReportNumber == 0 )
        {
            // Use saved report as 'Prev', 0 offset report as "Last"
            sc->PrevRawDataPtr      = sc->Calculator->GetSavedReport();
            sc->PrevRawReportNumber = MD_SAVED_REPORT_NUMBER;
            MD_ASSERT_A( adapterId, sc->PrevRawDataPtr != nullptr );
        }

        // If not using saved report
        if( sc->PrevRawReportNumber != MD_SAVED_REPORT_NUMBER )
        {
            sc->LastRawDataPtr      = sc->PrevRawDataPtr + sc->RawReportSize;
            sc->LastRawReportNumber = sc->PrevRawReportNumber + 1;
        }

        // METRICS
        sc->Calculator->ReadMetricsFromIoReport( sc->LastRawDataPtr, sc->PrevRawDataPtr, sc->DeltaValues, *sc->MetricSet );
        // NORMALIZATION
        sc->Calculator->NormalizeMetrics( sc->DeltaValues, sc->OutPtr, *sc->MetricSet );
        // INFORMATION
        sc->Calculator->ReadInformation( sc->LastRawDataPtr, sc->OutPtr + sc->MetricSet->GetParams()->MetricsCount, *sc->MetricSet, sc->ContextIdIdx );
        // MAX VALUES
        if( sc->OutMaxValues )
        {
            sc->Calculator->CalculateMaxValues( sc->DeltaValues, sc->OutPtr, sc->OutMaxValuesPtr, *sc->MetricSet );
            sc->OutMaxValuesPtr += sc->MetricSet->GetParams()->MetricsCount;
        }

        sc->OutPtr += sc->MetricsAndInformationCount;
        sc->OutReportCount++;

        // Prev is now Last
        sc->PrevRawDataPtr      = sc->LastRawDataPtr;
        sc->PrevRawReportNumber = sc->LastRawReportNumber;

        if( sc->Calculator->SavedReportPresent() )
        {
            sc->Calculator->DiscardSavedReport();
        }

        return true;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculationManager<MEASUREMENT_TYPE_DELTA_QUERY>
    //
    // Method:
    //     CalculateNextReport
    //
    // Description:
    //     Calculates a single report for a Query measurements using raw delta data and
    //     other state variables stored in the given calculation context.
    //
    // Input:
    //     TCalculationContext& context - (IN/OUT) calculation context
    //
    // Output:
    //     bool - true, if report calculated
    //            false, if not - calculation complete for current context
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    bool CMetricsCalculationManager<MEASUREMENT_TYPE_DELTA_QUERY>::CalculateNextReport( TCalculationContext& context )
    {
        TQueryCalculationContext* qc = &context.QueryCalculationContext;
        MD_CHECK_PTR_RET( qc->Calculator, false );

        const uint32_t adapterId = OBTAIN_ADAPTER_ID( qc->Calculator->GetMetricsDevice() );

        if( qc->OutReportCount >= qc->RawReportCount )
        {
            // Nothing to be calculated
            MD_LOG_A( adapterId, LOG_DEBUG, "Calculation complete" );
            return false;
        }

        // METRICS
        qc->Calculator->ReadMetricsFromQueryReport( qc->RawDataPtr, qc->DeltaValues, *qc->MetricSet );
        // NORMALIZATION
        qc->Calculator->NormalizeMetrics( qc->DeltaValues, qc->OutPtr, *qc->MetricSet );
        // INFORMATION
        qc->Calculator->ReadInformation( qc->RawDataPtr, qc->OutPtr + qc->MetricSet->GetParams()->MetricsCount, *qc->MetricSet, -1 );
        // MAX VALUES
        if( qc->OutMaxValues )
        {
            qc->Calculator->CalculateMaxValues( qc->DeltaValues, qc->OutPtr, qc->OutMaxValuesPtr, *qc->MetricSet );
            qc->OutMaxValuesPtr += qc->MetricSet->GetParams()->MetricsCount;
        }

        qc->RawDataPtr += qc->RawReportSize;
        qc->OutPtr += qc->MetricsAndInformationCount;

        qc->OutReportCount++;

        return true;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>
    //
    // Method:
    //     GetInformationIndex
    //
    // Description:
    //     Returns the given information index in the given set. -1 if not found.
    //
    // Input:
    //     const char* symbolName - information symbol name to find
    //     CMetricSet* metricSet  - metric set
    //
    // Output:
    //     int - given information index in MetricSet, -1 if not found or error
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    int CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>::GetInformationIndex( const char* symbolName, CMetricSet* metricSet )
    {
        MD_CHECK_PTR_RET( metricSet, -1 );

        const uint32_t adapterId = OBTAIN_ADAPTER_ID( metricSet->GetMetricsDevice() );

        MD_CHECK_PTR_RET_A( adapterId, symbolName, -1 );

        uint32_t count = metricSet->GetParams()->InformationCount;
        for( uint32_t i = 0; i < count; i++ )
        {
            IInformation_1_0* information = metricSet->GetInformation( i );
            MD_ASSERT_A( adapterId, information != nullptr );

            TInformationParams_1_0* informationParams = information->GetParams();
            if( informationParams->SymbolName && strcmp( informationParams->SymbolName, symbolName ) == 0 )
            {
                return i;
            }
        }

        MD_LOG_A( adapterId, LOG_DEBUG, "can't find information index: %s", symbolName );
        return -1;
    }
} // namespace MetricsDiscoveryInternal
