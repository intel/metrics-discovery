/*========================== begin_copyright_notice ============================

Copyright (C) 2019-2026 Intel Corporation

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
#include <functional>

namespace MetricsDiscoveryInternal
{
    // Forward declarations //
    template <>
    int32_t CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>::GetInformationIndex( const char* symbolName, CMetricSet* metricSet );

    template <>
    void CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>::AggregateCounters( TAggregationContext& context );

    template <>
    void CMetricsCalculationManager<MEASUREMENT_TYPE_DELTA_QUERY>::AggregateCounters( TAggregationContext& context );

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

        bool calculateReport = true;

        // If not using saved report
        if( sc->PrevRawReportNumber != MD_SAVED_REPORT_NUMBER )
        {
            sc->LastRawDataPtr      = sc->PrevRawDataPtr + sc->RawReportSize;
            sc->LastRawReportNumber = sc->PrevRawReportNumber + 1;

            const uint64_t reportId = *reinterpret_cast<const uint64_t*>( sc->LastRawDataPtr );

            if( reportId == MD_REPORT_ID_SKIP_CALCULATION )
            {
                calculateReport = false;
            }
        }

        if( calculateReport )
        {
            ProcessCalculation( sc, false, adapterId );
        }

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
    bool CMetricsCalculationManager<MEASUREMENT_TYPE_DELTA_QUERY>::CalculateNextAsyncReport( [[maybe_unused]] TCalculationContext& context )
    {
        return false;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>
    //
    // Method:
    //     ResetContext
    //
    // Description:
    //     Resets aggregation context for io stream to the initial (zero) state.
    //
    // Input:
    //     TAggregationContext& context - (IN/OUT) aggregation context
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    void CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>::ResetContext( TAggregationContext& context )
    {
        context.StreamAggregationContext                   = {};
        context.StreamAggregationContext.ReportReasonIdx   = -1;
        context.StreamAggregationContext.BeginTimestampIdx = -1;
        context.StreamAggregationContext.TimeWindowIdx     = -1;
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
    //     Resets aggregation context for query to the initial (zero) state.
    //
    // Input:
    //     TAggregationContext& context - (IN/OUT) aggregation context
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    void CMetricsCalculationManager<MEASUREMENT_TYPE_DELTA_QUERY>::ResetContext( TAggregationContext& context )
    {
        context.QueryAggregationContext = {};
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
    //     Prepares aggregation context for io stream for calculations. Sets all the necessary
    //     fields that could be determined using user provided ones.
    //
    // Input:
    //     TAggregationContext& context - (IN/OUT) aggregation context
    //
    // Output:
    //     TCompletionCode              - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    TCompletionCode CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>::PrepareContext( TAggregationContext& context )
    {
        bool                       allocationFailed = false;
        TStreamAggregationContext& sa               = context.StreamAggregationContext;

        sa.ReportReasonIdx   = GetInformationIndex( "ReportReason", sa.BaseMetricSet );
        sa.BeginTimestampIdx = GetInformationIndex( "QueryBeginTime", sa.MetricSet );
        sa.RawReportSize     = sa.MetricSet->GetParams()->RawReportSize;

        sa.RawData                 = new( std::nothrow ) const uint8_t*[sa.DataSetCount]();
        sa.PrevRawDataPtrs         = new( std::nothrow ) const uint8_t*[sa.DataSetCount]();
        sa.LastRawDataPtrs         = new( std::nothrow ) const uint8_t*[sa.DataSetCount]();
        sa.PrevSavedReportPtrs     = new( std::nothrow ) uint8_t*[sa.DataSetCount]();
        sa.LastSavedReportPtrs     = new( std::nothrow ) uint8_t*[sa.DataSetCount]();
        sa.CachedReportPtrsBase    = new( std::nothrow ) uint8_t*[sa.DataSetCount]();
        sa.CachedReportPtrs        = new( std::nothrow ) uint8_t*[sa.DataSetCount]();
        sa.InterpolatedReportPtrs  = new( std::nothrow ) uint8_t*[sa.DataSetCount]();
        sa.OutAggregatedRawDataPtr = new( std::nothrow ) uint8_t[sa.RawReportSize * 2]();
        sa.RawReportCount          = new( std::nothrow ) uint32_t[sa.DataSetCount]();
        sa.OutReportCount          = new( std::nothrow ) uint32_t[sa.DataSetCount]();
        sa.CurrentTs               = new( std::nothrow ) uint64_t[sa.DataSetCount]();
        sa.NeedReport              = new( std::nothrow ) bool[sa.DataSetCount]();
        sa.IsCachedReport          = new( std::nothrow ) bool[sa.DataSetCount]();
        sa.CachedReportPtrsSize    = new( std::nothrow ) uint32_t[sa.DataSetCount]();
        sa.IsPrevRawDataPresent    = new( std::nothrow ) bool[sa.DataSetCount]();
        sa.IsLastRawDataPresent    = new( std::nothrow ) bool[sa.DataSetCount]();
        sa.SkipReportAfterRc6      = new( std::nothrow ) bool[sa.DataSetCount]();

        if( sa.OutReportCount &&
            sa.RawReportCount &&
            sa.LastRawDataPtrs &&
            sa.PrevRawDataPtrs &&
            sa.PrevSavedReportPtrs &&
            sa.LastSavedReportPtrs &&
            sa.RawData &&
            sa.CachedReportPtrsBase &&
            sa.CachedReportPtrs &&
            sa.InterpolatedReportPtrs &&
            sa.OutAggregatedRawDataPtr &&
            sa.CurrentTs &&
            sa.NeedReport &&
            sa.IsCachedReport &&
            sa.CachedReportPtrsSize &&
            sa.IsPrevRawDataPresent &&
            sa.IsLastRawDataPresent &&
            sa.SkipReportAfterRc6 )
        {
            for( uint32_t i = 0; i < sa.DataSetCount; ++i )
            {
                sa.PrevSavedReportPtrs[i]    = new( std::nothrow ) uint8_t[sa.RawReportSize]();
                sa.LastSavedReportPtrs[i]    = new( std::nothrow ) uint8_t[sa.RawReportSize]();
                sa.InterpolatedReportPtrs[i] = new( std::nothrow ) uint8_t[sa.RawReportSize]();
                sa.NeedReport[i]             = false;
                sa.IsCachedReport[i]         = false;
                sa.IsPrevRawDataPresent[i]   = false;
                sa.IsLastRawDataPresent[i]   = false;
                sa.SkipReportAfterRc6[i]     = false;
                sa.CachedReportPtrsSize[i]   = 0;

                if( !sa.PrevSavedReportPtrs[i] || !sa.LastSavedReportPtrs[i] || !sa.InterpolatedReportPtrs[i] )
                {
                    allocationFailed = true;
                    break;
                }
            }
        }
        else
        {
            allocationFailed = true;
        }

        return ( sa.ReportReasonIdx != -1 && sa.BeginTimestampIdx != -1 && !allocationFailed ) ? CC_OK : CC_ERROR_GENERAL;
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
    //     Prepares aggregation context for query for calculations. Sets all the necessary
    //     fields that could be determined using user provided ones.
    //
    // Input:
    //     TAggregationContext& context - (IN/OUT) aggregation context
    //
    // Output:
    //     TCompletionCode              - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    TCompletionCode CMetricsCalculationManager<MEASUREMENT_TYPE_DELTA_QUERY>::PrepareContext( TAggregationContext& context )
    {
        TQueryAggregationContext& qa = context.QueryAggregationContext;

        qa.RawReportSize = qa.MetricSet->GetParams()->QueryReportSize;

        qa.RawData        = new( std::nothrow ) const uint8_t*[qa.DataSetCount]();
        qa.RawReportCount = new( std::nothrow ) uint32_t[qa.DataSetCount]();
        qa.OutReportCount = new( std::nothrow ) uint32_t[qa.DataSetCount]();

        return ( qa.RawData != nullptr && qa.RawReportCount != nullptr && qa.OutReportCount != nullptr ) ? CC_OK : CC_ERROR_GENERAL;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>
    //
    // Method:
    //     AggregateNextReport
    //
    // Description:
    //     Not used for io stream.
    //
    // Input:
    //     TAggregationContext& context - aggregation context
    //
    // Output:
    //     bool - false
    //////////////////////////////////////////////////////////////////////////////
    template <>
    bool CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>::AggregateNextReport( [[maybe_unused]] TAggregationContext& context )
    {
        return false;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculationManager<MEASUREMENT_TYPE_DELTA_QUERY>
    //
    // Method:
    //     AggregateNextReport
    //
    // Description:
    //     Aggregates next reports from multiple sources for query in the given calculation context.
    //
    // Input:
    //     TAggregationContext& context - aggregation context
    //
    // Output:
    //     bool - true, if aggregation is not yet completed, false otherwise
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    bool CMetricsCalculationManager<MEASUREMENT_TYPE_DELTA_QUERY>::AggregateNextReport( TAggregationContext& context )
    {
        TQueryAggregationContext& qa = context.QueryAggregationContext;

        // Skip base data set.
        if( qa.CurrentDataSetIdx != qa.BaseDataSetIdx )
        {
            if( qa.OutReportCount[qa.CurrentDataSetIdx] >= qa.RawReportCount[qa.CurrentDataSetIdx] )
            {
                // Nothing to be aggregated
                MD_LOG( LOG_DEBUG, "Aggregation complete" );
                return false;
            }

            // Process all query reports in the current data set.
            AggregateCounters( context );
        }

        // Move to the next data source.
        return ( ++qa.CurrentDataSetIdx < qa.DataSetCount );
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>
    //
    // Method:
    //     GetRequiredSize
    //
    // Description:
    //     Calculates and returns the required size (in bytes) of the output buffer for IO stream
    //     aggregation, based on the provided raw data sizes and aggregation window configuration.
    //     In timer mode (no aggregation window), the required size is determined by the smallest
    //     raw data buffer among all data sets. In windowed aggregation mode, the method computes
    //     the number of aggregation windows based on the timestamps in the input data and the
    //     aggregation window size, and returns the total size needed to store all aggregated reports.
    //
    // Input:
    //     TAggregationContext& context      - Reference to the aggregation context.
    //
    // Output:
    //     uint32_t - Required size (in bytes) of the output buffer for aggregation.
    //
    ////////////////////////////////////////////////////////////////////////////////
    template <>
    uint32_t CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>::GetRequiredSize( TAggregationContext& context )
    {
        TStreamAggregationContext& sa = context.StreamAggregationContext;

        if( !sa.NsTimeAggregationWindow )
        {
            uint32_t minSizeOfReports = sa.RawReportCount[0];

            for( uint32_t i = 1; i < sa.DataSetCount; ++i )
            {
                if( sa.RawReportCount[i] < minSizeOfReports )
                {
                    minSizeOfReports = sa.RawReportCount[i];
                }
            }

            return minSizeOfReports * sa.RawReportSize;
        }
        else
        {
            constexpr uint32_t timestampOffset = 8;
            uint64_t           startTimestamp  = 0;

            if( sa.TimeWindowCount > 0 )
            {
                startTimestamp = sa.TimeWindows[0].Start;
            }
            else
            {
                for( uint32_t i = 0; i < sa.DataSetCount; ++i )
                {
                    if( sa.RawReportCount[i] == 0 )
                    {
                        continue;
                    }

                    const uint8_t* firstReport = sa.RawData[i];
                    const uint64_t timestamp   = *reinterpret_cast<const uint64_t*>( firstReport + timestampOffset );

                    if( timestamp > startTimestamp )
                    {
                        startTimestamp = timestamp;
                    }
                }
            }

            uint64_t lastTimestamp = std::numeric_limits<uint64_t>::max();

            for( uint32_t i = 0; i < sa.DataSetCount; ++i )
            {
                if( sa.RawReportCount[i] == 0 )
                {
                    continue;
                }

                const uint32_t reportCount = sa.RawReportCount[i];
                const uint8_t* lastReport  = sa.RawData[i] + static_cast<size_t>( reportCount - 1 ) * sa.RawReportSize;
                const uint64_t timestamp   = *reinterpret_cast<const uint64_t*>( lastReport + timestampOffset );

                if( timestamp < lastTimestamp )
                {
                    lastTimestamp = timestamp;
                }
            }

            const uint64_t totalTime   = ( lastTimestamp >= startTimestamp ) ? lastTimestamp - startTimestamp : 0;
            const uint64_t windows     = totalTime / sa.NsTimeAggregationWindow;
            const uint64_t bytesNeeded = ( windows + 2 ) * static_cast<uint64_t>( sa.RawReportSize ); // +2 because of the possibility of extra report on last data portion

            if( bytesNeeded > std::numeric_limits<uint32_t>::max() )
            {
                MD_LOG_A( sa.Calculator->GetMetricsDevice().GetAdapter().GetAdapterId(), LOG_WARNING, "Required size for aggregation exceeds uint32_t limit." );
                return 0;
            }

            return static_cast<uint32_t>( bytesNeeded );
        }
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculationManager<MEASUREMENT_TYPE_DELTA_QUERY>
    //
    // Method:
    //     GetRequiredSize
    //
    // Description:
    //     Calculates and returns the required size (in bytes) of the output buffer for query
    //     aggregation. The required size is determined by multiplying the size of a single
    //     query report by the number of reports in the base data set. This ensures the output
    //     buffer is large enough to store all aggregated reports for the query context.
    //
    // Input:
    //     TAggregationContext& context      - Reference to the aggregation context.
    //
    // Output:
    //     uint32_t - Required size (in bytes) of the output buffer for query aggregation.
    //
    ////////////////////////////////////////////////////////////////////////////////
    template <>
    uint32_t CMetricsCalculationManager<MEASUREMENT_TYPE_DELTA_QUERY>::GetRequiredSize( TAggregationContext& context )
    {
        TQueryAggregationContext& qa = context.QueryAggregationContext;

        return qa.RawReportSize * qa.RawReportCount[0];
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>
    //
    // Method:
    //     AggregateCounters
    //
    // Description:
    //     Aggregates counters from multiple raw data sources for io stream.
    //
    // Input:
    //     TAggregationContext& context - aggregation context
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    void CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>::AggregateCounters( TAggregationContext& context )
    {
        TStreamAggregationContext& sa = context.StreamAggregationContext;

        constexpr uint32_t headerSizeBytes = 4u * 8u; // 4 header fields * 8 bytes each

        uint32_t pecCount     = 0;
        uint32_t pecElemBytes = 0; // 4 or 8
        uint32_t noaCount     = 0; // NOA (32-bit) counters
        bool     isSupported  = true;

        switch( sa.MetricSet->GetReportType() )
        {
            case OA_REPORT_TYPE_576B_PEC64LL:
                pecCount     = 64;
                pecElemBytes = 8;
                break;

            case OA_REPORT_TYPE_640B_PEC64LL_NOA16:
                pecCount     = 64;
                pecElemBytes = 8;
                noaCount     = 16;
                break;

            case OA_REPORT_TYPE_192B_MPEC8LL_NOA16:
                pecCount     = 8;
                pecElemBytes = 8;
                noaCount     = 16;
                break;

            case OA_REPORT_TYPE_128B_MPEC8_NOA16:
                pecCount     = 8;
                pecElemBytes = 4;
                noaCount     = 16;
                break;

            case OA_REPORT_TYPE_128B_MERT_PEC8:
                pecCount     = 8;
                pecElemBytes = 4;
                break;

            case OA_REPORT_TYPE_192B_MERT_PEC8LL:
                pecCount     = 8;
                pecElemBytes = 8;
                break;

            case OA_REPORT_TYPE_256B_A45_NOA16: // not implemented
            case OA_REPORT_TYPE_320B_PEC64:     // not implemented
                isSupported = false;
                break;

            default:
                isSupported = false;
                break;
        }

        if( !isSupported )
        {
            MD_LOG_A( sa.Calculator->GetMetricsDevice().GetAdapter().GetAdapterId(), LOG_WARNING, "Unsupported or unimplemented report type for aggregation." );
            return;
        }

        // Copy first (base) interpolated report as aggregation target.
        uint8_t* outReport = sa.Out + sa.OutAggregatedRawDataSize;
        iu_memcpy_s( outReport, sa.RawReportSize, sa.InterpolatedReportPtrs[0], sa.RawReportSize );

        uint8_t* basePayload = outReport + headerSizeBytes;

        // Aggregate remaining data sets.
        for( uint32_t i = 1; i < sa.DataSetCount; ++i )
        {
            const uint8_t* src        = sa.InterpolatedReportPtrs[i];
            const uint8_t* srcPayload = src + headerSizeBytes;

            // Aggregate PEC counters.
            if( pecElemBytes == 8 )
            {
                auto*       dstPec = reinterpret_cast<uint64_t*>( basePayload );
                const auto* srcPec = reinterpret_cast<const uint64_t*>( srcPayload );
                std::transform( srcPec, srcPec + pecCount, dstPec, dstPec, std::plus<uint64_t>() );
            }
            else
            {
                auto*       dstPec = reinterpret_cast<uint32_t*>( basePayload );
                const auto* srcPec = reinterpret_cast<const uint32_t*>( srcPayload );
                std::transform( srcPec, srcPec + pecCount, dstPec, dstPec, std::plus<uint32_t>() );
            }

            // Aggregate NOA counters if present.
            if( noaCount != 0 )
            {
                const uint32_t noaOffset = pecCount * pecElemBytes;

                auto*       dstNoa = reinterpret_cast<uint32_t*>( basePayload + noaOffset );
                const auto* srcNoa = reinterpret_cast<const uint32_t*>( srcPayload + noaOffset );

                std::transform( srcNoa, srcNoa + noaCount, dstNoa, dstNoa, std::plus<uint32_t>() );
            }
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculationManager<MEASUREMENT_TYPE_DELTA_QUERY>
    //
    // Method:
    //     AggregateCounters
    //
    // Description:
    //     Aggregates counters from multiple raw data sources for query.
    //
    // Input:
    //     TAggregationContext& context - aggregation context
    //
    //////////////////////////////////////////////////////////////////////////////
    template <>
    void CMetricsCalculationManager<MEASUREMENT_TYPE_DELTA_QUERY>::AggregateCounters( TAggregationContext& context )
    {
        TQueryAggregationContext& qa = context.QueryAggregationContext;

        switch( qa.MetricSet->GetReportType() )
        {
            case OA_REPORT_TYPE_256B_A45_NOA16:
                // Not supported yet.
                break;

            case OA_REPORT_TYPE_320B_PEC64:
                // Not supported yet.
                break;

            case OA_REPORT_TYPE_576B_PEC64LL:
            case OA_REPORT_TYPE_640B_PEC64LL_NOA16:
            {
                uint8_t* out = qa.Out;

                for( uint32_t i = 0; i < qa.RawReportCount[qa.CurrentDataSetIdx]; ++i )
                {
                    uint64_t&      baseTotalTime      = reinterpret_cast<uint64_t*>( out )[0];
                    uint64_t&      baseBeginTimestamp = reinterpret_cast<uint64_t*>( out )[2 + 64 + 16];
                    const uint64_t baseEndTimestamp   = baseBeginTimestamp + baseTotalTime;

                    const uint64_t currentTotalTime      = reinterpret_cast<const uint64_t*>( qa.RawData[qa.CurrentDataSetIdx] )[0];
                    const uint64_t currentBeginTimestamp = reinterpret_cast<const uint64_t*>( qa.RawData[qa.CurrentDataSetIdx] )[2 + 64 + 16];
                    const uint64_t currentEndTimestamp   = currentBeginTimestamp + currentTotalTime;

                    if( currentBeginTimestamp < baseBeginTimestamp )
                    {
                        // If the current begin timestamp is less than the base begin timestamp, we need to update it.
                        baseBeginTimestamp = currentBeginTimestamp;
                    }

                    if( currentEndTimestamp >= baseEndTimestamp )
                    {
                        // Update total time if the current end timestamp is greater than or equal to the base end timestamp.
                        baseTotalTime = currentEndTimestamp - baseBeginTimestamp;
                    }

                    uint64_t&      gpuTicks        = reinterpret_cast<uint64_t*>( out )[1];
                    const uint64_t currentGpuTicks = reinterpret_cast<const uint64_t*>( qa.RawData[qa.CurrentDataSetIdx] )[1];

                    if( currentGpuTicks > gpuTicks )
                    {
                        // Update GPU ticks if the current value is greater than the base value.
                        gpuTicks = currentGpuTicks;
                    }

                    for( uint32_t j = 0; j < 64; ++j )
                    {
                        uint64_t& pec = reinterpret_cast<uint64_t*>( out )[j + 2];
                        pec += reinterpret_cast<const uint64_t*>( qa.RawData[qa.CurrentDataSetIdx] )[j + 2];
                    }

                    for( uint32_t j = 0; j < 16; ++j )
                    {
                        uint64_t& visa = reinterpret_cast<uint64_t*>( out )[j + 2 + 64];
                        visa += reinterpret_cast<const uint64_t*>( qa.RawData[qa.CurrentDataSetIdx] )[j + 2 + 64];
                    }

                    uint64_t&      midQueryEventsAndOverrun        = reinterpret_cast<uint64_t*>( out )[2 + 64 + 16 + 3];
                    const uint64_t currentMidQueryEventsAndOverrun = reinterpret_cast<const uint64_t*>( qa.RawData[qa.CurrentDataSetIdx] )[2 + 64 + 16 + 3];

                    midQueryEventsAndOverrun |= currentMidQueryEventsAndOverrun;

                    uint64_t&      splitOccurredAndFreqChanged        = reinterpret_cast<uint64_t*>( out )[2 + 64 + 16 + 3 + 5];
                    const uint64_t currentSplitOccurredAndFreqChanged = reinterpret_cast<const uint64_t*>( qa.RawData[qa.CurrentDataSetIdx] )[2 + 64 + 16 + 3 + 5];

                    splitOccurredAndFreqChanged |= currentSplitOccurredAndFreqChanged;

                    for( uint32_t j = 0; j < 16; ++j )
                    {
                        uint64_t& userCounter = reinterpret_cast<uint64_t*>( out )[2 + 64 + 16 + 3 + 8 + j];
                        userCounter += reinterpret_cast<const uint64_t*>( qa.RawData[qa.CurrentDataSetIdx] )[2 + 64 + 16 + 3 + 8 + j];
                    }

                    uint32_t&      flags        = reinterpret_cast<uint32_t*>( out )[( 2 + 64 + 16 + 3 + 8 + 16 ) * 2 + 1];
                    const uint32_t currentFlags = reinterpret_cast<const uint32_t*>( qa.RawData[qa.CurrentDataSetIdx] )[( 2 + 64 + 16 + 3 + 8 + 16 ) * 2 + 1];

                    flags |= currentFlags; // Combine flags from the current report with the base report.

                    out += qa.RawReportSize; // Move to the next output report.
                    qa.RawData[qa.CurrentDataSetIdx] += qa.RawReportSize;
                    qa.OutReportCount[qa.CurrentDataSetIdx]++;
                }

                break;
            }

            case OA_REPORT_TYPE_192B_MPEC8LL_NOA16:
                // Not supported yet.
                break;

            case OA_REPORT_TYPE_128B_MPEC8_NOA16:
                // Not supported yet.
                break;

            default:
                break;
        }
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
