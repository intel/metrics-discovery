/*========================== begin_copyright_notice ============================

Copyright (C) 2019-2025 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_calculation.cpp

//     Abstract:   C++ metrics discovery metrics calculation features implementation.

#include "md_calculation.h"
#include "md_adapter.h"
#include "md_metrics_device.h"
#include "md_metric_set.h"
#include "md_metrics.h"
#include "md_information.h"
#include "md_equation.h"
#include "md_metrics_calculator.h"
#include "md_types.h"
#include "md_utils.h"
#include <algorithm>
#include <cstring>

namespace MetricsDiscoveryInternal
{
    // Forward declarations //
    template <>
    int32_t CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>::GetInformationIndex( const char* symbolName, CMetricSet* metricSet );
    template <>
    void CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>::ProcessCalculation( TStreamCalculationContext* sc, bool async, uint32_t adapterId );

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
        context.StreamCalculationContext              = {};
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
        context.QueryCalculationContext = {};
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

        const uint32_t adapterId = sc->Calculator->GetMetricsDevice().GetAdapter().GetAdapterId();

        if( !sc->AggregationEnabled )
        {
            // Find required indices for context filtering, report filtering and PreviousContextId information
            sc->ContextIdIdx    = GetInformationIndex( "ContextId", sc->MetricSet );
            sc->ReportReasonIdx = GetInformationIndex( "ReportReason", sc->MetricSet );

            if( sc->DoContextFiltering && sc->ContextIdIdx < 0 )
            {
                MD_LOG_A( adapterId, LOG_ERROR, "error: can't find required information for context filtering" );
                MD_LOG_EXIT_A( adapterId );
                return CC_ERROR_INVALID_PARAMETER;
            }
        }

        if( sc->RawData )
        {
            sc->OutReportCount      = 0;
            sc->PrevRawDataPtr      = sc->RawData;
            sc->PrevRawReportNumber = 0;
            sc->LastRawDataPtr      = sc->RawData;
            sc->LastRawReportNumber = 0;
        }

        auto& metricSetParams = *sc->MetricSet->GetParams();

        sc->MetricsAndInformationCount = metricSetParams.MetricsCount + metricSetParams.InformationCount;
        sc->RawReportSize              = metricSetParams.RawReportSize;

        sc->Calculator->Reset( sc->RawReportSize, sc->MetricsAndInformationCount );

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

        const uint32_t adapterId = qc->Calculator->GetMetricsDevice().GetAdapter().GetAdapterId();

        qc->Calculator->Reset();

        auto& metricSetParams = *qc->MetricSet->GetParams();

        qc->MetricsAndInformationCount = metricSetParams.MetricsCount + metricSetParams.InformationCount;
        qc->RawReportSize              = metricSetParams.QueryReportSize;

        if( qc->RawData )
        {
            qc->OutReportCount = 0;
        }

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

        const uint32_t adapterId = sc->Calculator->GetMetricsDevice().GetAdapter().GetAdapterId();

        const bool isSavedReport  = sc->Calculator->SavedReportPresent();
        const bool isSingleReport = sc->RawReportCount == 1;

        // Save first report if there are no other reports
        // or if the report is the last one.
        if( ( !isSavedReport && isSingleReport ) ||
            ( ( !isSavedReport && !isSingleReport ) && ( sc->LastRawReportNumber >= sc->RawReportCount || sc->PrevRawReportNumber >= sc->RawReportCount - 1 ) ) )
        {
            // Nothing to be calculated
            MD_LOG_A( adapterId, LOG_DEBUG, "Calculation complete" );
            if( CC_OK != sc->Calculator->SaveReport( sc->LastRawDataPtr ) )
            {
                MD_LOG_A( adapterId, LOG_DEBUG, "Unable to store last raw report for reuse." );
            }

            return false;
        }

        if( isSavedReport && sc->PrevRawReportNumber == 0 )
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
        sc->Calculator->NormalizeMetrics( sc->DeltaValues, sc->Out, *sc->MetricSet );
        // INFORMATION
        sc->Calculator->ReadInformation( sc->LastRawDataPtr, sc->Out + sc->MetricSet->GetParams()->MetricsCount, *sc->MetricSet, sc->ContextIdIdx );
        // MAX VALUES
        if( sc->OutMaxValues )
        {
            sc->Calculator->CalculateMaxValues( sc->DeltaValues, sc->Out, sc->OutMaxValues, *sc->MetricSet );
            sc->OutMaxValues += sc->MetricSet->GetParams()->MetricsCount;
        }

        // Save calculated report for reuse
        if( CC_OK != sc->Calculator->SaveCalculatedReport( sc->Out ) )
        {
            MD_LOG_A( adapterId, LOG_DEBUG, "Unable to store previous calculated report for reuse." );
        }

        sc->Out += sc->MetricsAndInformationCount;
        sc->OutReportCount++;

        // Prev is now Last
        sc->PrevRawDataPtr      = sc->LastRawDataPtr;
        sc->PrevRawReportNumber = sc->LastRawReportNumber;

        if( isSingleReport )
        {
            // If there is a single report in calculation, do not discard saved report and save the current report.
            if( CC_OK != sc->Calculator->SaveReport( sc->LastRawDataPtr ) )
            {
                MD_LOG_A( adapterId, LOG_DEBUG, "Unable to store last raw report for reuse." );
            }

            return false;
        }

        if( isSavedReport )
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
        const uint32_t adapterId = qc->Calculator->GetMetricsDevice().GetAdapter().GetAdapterId();

        if( qc->OutReportCount >= qc->RawReportCount )
        {
            // Nothing to be calculated
            MD_LOG_A( adapterId, LOG_DEBUG, "Calculation complete" );
            return false;
        }

        const uint32_t metricsCount = qc->MetricSet->GetParams()->MetricsCount;

        // METRICS
        qc->Calculator->ReadMetricsFromQueryReport( qc->RawData, qc->DeltaValues, *qc->MetricSet );
        // NORMALIZATION
        qc->Calculator->NormalizeMetrics( qc->DeltaValues, qc->Out, *qc->MetricSet );
        // INFORMATION
        qc->Calculator->ReadInformation( qc->RawData, qc->Out + metricsCount, *qc->MetricSet, -1 );
        // MAX VALUES
        if( qc->OutMaxValues )
        {
            qc->Calculator->CalculateMaxValues( qc->DeltaValues, qc->Out, qc->OutMaxValues, *qc->MetricSet );
            qc->OutMaxValues += metricsCount;
        }

        qc->RawData += qc->RawReportSize;
        qc->Out += qc->MetricsAndInformationCount;

        qc->OutReportCount++;

        return true;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>
    //
    // Method:
    //     CalculateNextAsyncReport
    //
    // Description:
    //     Calculates a single report for a IoStream measurements using raw data and
    //     other state variables stored in the given calculation context.
    //     Timer reports are not calculated. First calculated async report has deltas
    //     equal to 0.
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
    bool CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>::CalculateNextAsyncReport( TCalculationContext& context )
    {
        TStreamCalculationContext* sc = &context.StreamCalculationContext;
        MD_CHECK_PTR_RET( sc->Calculator, false );

        const uint64_t reportReason = sc->Calculator->ReadInformationByIndex( sc->LastRawDataPtr, *sc->MetricSet, sc->ReportReasonIdx );

        const uint32_t adapterId = sc->Calculator->GetMetricsDevice().GetAdapter().GetAdapterId();

        const bool isSavedReport = sc->Calculator->SavedReportPresent();

        sc->LastRawReportNumber++;

        // Calculate and save first report if there are no other reports or if the report is the last one.
        if( sc->LastRawReportNumber >= sc->RawReportCount )
        {
            if( ( reportReason & REPORT_REASON_INTERNAL_TIMER ) == 0 ) // Calculate every report except timer reports.
            {
                if( isSavedReport )
                {
                    sc->PrevRawDataPtr = sc->Calculator->GetSavedReport();
                }

                ProcessCalculation( sc, true, adapterId );
            }

            return false;
        }

        // Calculation of multiple reports. From the first to the penultimate.
        if( ( reportReason & REPORT_REASON_INTERNAL_TIMER ) != 0 )
        {
            sc->LastRawDataPtr += sc->RawReportSize;

            if( !isSavedReport )
            {
                // Prev is now Last
                sc->PrevRawDataPtr = sc->LastRawDataPtr;
            }

            // Skip timer reports in async calculation
            return true;
        }

        if( isSavedReport )
        {
            sc->PrevRawDataPtr = sc->Calculator->GetSavedReport();
            MD_ASSERT_A( adapterId, sc->PrevRawDataPtr != nullptr );
        }

        ProcessCalculation( sc, true, adapterId );

        sc->LastRawDataPtr += sc->RawReportSize;

        return true;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculationManager<MEASUREMENT_TYPE_DELTA_QUERY>
    //
    // Method:
    //     CalculateNextAsyncReport
    //
    // Description:
    //     Async calculation is only for IoStream measurements.
    //
    // Input:
    //     TCalculationContext& context - (IN/OUT) calculation context
    //
    // Output:
    //     bool - always false, as async calculation is not supported for Query measurements
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    bool CMetricsCalculationManager<MEASUREMENT_TYPE_DELTA_QUERY>::CalculateNextAsyncReport( TCalculationContext& context )
    {
        return false;
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
    //     int32_t - given information index in MetricSet, -1 if not found or error
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    int32_t CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>::GetInformationIndex( const char* symbolName, CMetricSet* metricSet )
    {
        MD_CHECK_PTR_RET( metricSet, -1 );

        const uint32_t adapterId = metricSet->GetMetricsDevice().GetAdapter().GetAdapterId();

        MD_CHECK_PTR_RET_A( adapterId, symbolName, -1 );

        const uint32_t count = metricSet->GetParams()->InformationCount;
        for( uint32_t i = 0; i < count; ++i )
        {
            auto information = metricSet->GetInformation( i );
            MD_ASSERT_A( adapterId, information != nullptr );

            auto informationParams = information->GetParams();
            if( informationParams->SymbolName && strcmp( informationParams->SymbolName, symbolName ) == 0 )
            {
                return i;
            }
        }

        MD_LOG_A( adapterId, LOG_DEBUG, "can't find information index: %s", symbolName );
        return -1;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>
    //
    // Method:
    //     ProcessAsyncCalculation
    //
    // Description:
    //     Processes async calculation for IoStream measurements using the provided
    //     calculation context. This method reads and normalizes metric values,
    //     reads information values, calculates max values if required, and saves
    //     both the raw and calculated reports for future use.
    //
    // Input:
    //     bool     async     - Indicates whether the calculation is only for async reports or not.
    //     uint32_t adapterId - The adapter ID used for logging and assertion purposes.
    //
    // [In,Out]:
    //     TStreamCalculationContext* sc - Pointer to the stream calculation context containing all state and data
    //     required for processing async calculation.
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    void CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>::ProcessCalculation( TStreamCalculationContext* sc, bool async, uint32_t adapterId )
    {
        const uint32_t metricsCount = sc->MetricSet->GetParams()->MetricsCount;

        // METRICS
        sc->Calculator->ReadMetricsFromIoReport( sc->LastRawDataPtr, sc->PrevRawDataPtr, sc->DeltaValues, *sc->MetricSet );
        // NORMALIZATION
        sc->Calculator->NormalizeMetrics( sc->DeltaValues, sc->Out, *sc->MetricSet );
        // INFORMATION
        sc->Calculator->ReadInformation( sc->LastRawDataPtr, sc->Out + metricsCount, *sc->MetricSet, sc->ContextIdIdx );
        // MAX VALUES
        if( sc->OutMaxValues )
        {
            sc->Calculator->CalculateMaxValues( sc->DeltaValues, sc->Out, sc->OutMaxValues, *sc->MetricSet );
            sc->OutMaxValues += metricsCount;
        }

        if( async )
        {
            if( CC_OK != sc->Calculator->SaveReport( sc->LastRawDataPtr ) )
            {
                MD_LOG_A( adapterId, LOG_DEBUG, "Unable to store last raw report for reuse." );
            }
        }

        // Save calculated report for reuse
        if( CC_OK != sc->Calculator->SaveCalculatedReport( sc->Out ) )
        {
            MD_LOG_A( adapterId, LOG_DEBUG, "Unable to store previous calculated report for reuse." );
        }

        sc->Out += sc->MetricsAndInformationCount;
        sc->OutReportCount++;
    }
} // namespace MetricsDiscoveryInternal
