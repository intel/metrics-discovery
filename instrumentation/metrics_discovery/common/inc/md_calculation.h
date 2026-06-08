/*========================== begin_copyright_notice ============================

Copyright (C) 2019-2026 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_calculation.h
//
//     Abstract:   C++ metrics discovery metrics calculation features header.

#pragma once

#include "metrics_discovery_api.h"

#include <stack>

#define MD_SAVED_REPORT_NUMBER        0xFFFFFFFF
#define MD_REPORT_ID_SKIP_CALCULATION 2048

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    // Forward declarations //
    class CMetricsDevice;
    class CMetricSet;
    class CEquation;
    class CMetricsCalculator;

    ///////////////////////////////////////////////////////////////////////////////
    // Common calculation context:
    //////////////////////////////////////////////////////////////////////////////
    typedef struct SCommonCalculationContext
    {
        // MetricsCalculator
        CMetricsCalculator* Calculator; // Required

        // ConcurrentGroup and MetricSet
        IConcurrentGroupLatest* ConcurrentGroup;
        CMetricSet*             MetricSet; // Required
        uint32_t                MetricsAndInformationCount;

        // Input
        const uint8_t* RawData;        // Required
        uint32_t       RawReportCount; // Required
        uint32_t       RawReportSize;

        // Output
        TTypedValue_1_0* Out; // Required
        uint32_t         OutReportCount;
        TTypedValue_1_0* OutMaxValues;

        // Calculation
        TTypedValue_1_0* DeltaValues; // Required

        // Aggregation
        bool AggregationEnabled;

    } TCommonCalculationContext;

    ///////////////////////////////////////////////////////////////////////////////
    // Stream specific calculation context:
    //////////////////////////////////////////////////////////////////////////////
    typedef struct SStreamCalculationContext : public TCommonCalculationContext
    {
        // MetricSet
        int32_t ContextIdIdx;
        int32_t ReportReasonIdx;

        // ContextFiltering
        bool DoContextFiltering; // Required - not supported

        // Calculation
        const uint8_t* PrevRawDataPtr;
        uint32_t       PrevRawReportNumber;
        const uint8_t* LastRawDataPtr;
        uint32_t       LastRawReportNumber;

    } TStreamCalculationContext;

    ///////////////////////////////////////////////////////////////////////////////
    // Query specific calculation context:
    //////////////////////////////////////////////////////////////////////////////
    typedef struct SQueryCalculationContext : public TCommonCalculationContext
    {
    } TQueryCalculationContext;

    ///////////////////////////////////////////////////////////////////////////////
    // Union with all of calculation contexts:
    //////////////////////////////////////////////////////////////////////////////
    typedef union SCalculationContext
    {
        TCommonCalculationContext CommonCalculationContext;
        TStreamCalculationContext StreamCalculationContext;
        TQueryCalculationContext  QueryCalculationContext;
    } TCalculationContext;

    ///////////////////////////////////////////////////////////////////////////////
    // Common aggregation context:
    //////////////////////////////////////////////////////////////////////////////
    typedef struct SCommonAggregationContext
    {
        // Metric set
        CMetricSet* MetricSet;
        CMetricSet* BaseMetricSet;

        // Input
        const uint8_t** RawData;
        uint32_t*       RawReportCount;
        uint32_t        DataSetCount;
        uint32_t        RawReportSize;

        // Multiple sources aggregation
        uint32_t BaseDataSetIdx;
        uint32_t CurrentDataSetIdx;

        // Output
        uint8_t*  Out;
        uint32_t  OutSize;
        uint32_t* OutReportCount;

    } TCommonAggregationContext;

    ///////////////////////////////////////////////////////////////////////////////
    // Stream specific aggregation context:
    //////////////////////////////////////////////////////////////////////////////
    typedef struct SStreamAggregationContext : public TCommonAggregationContext
    {
        // Metrics calculator
        CMetricsCalculator* Calculator;

        // Metric set
        int32_t ReportReasonIdx;
        int32_t BeginTimestampIdx;

        // Time offsets
        int64_t* TimeOffsets;

        // Over time aggregation
        int32_t            TimeWindowIdx;
        uint64_t           NsTimeWindowFirst;
        uint64_t           NsTimeWindowLast;
        uint32_t           TimeWindowCount;
        TTimeWindowLatest* TimeWindows;
        uint64_t           NsTimeAggregationWindow;
        uint64_t           MaxAggregationWindowInTicks;
        uint32_t           CalculationWindowIndex;
        uint64_t           NsTimeAggregationWindowStop;
        uint64_t           NsTimeFirstReport;
        uint64_t           LastAggregatedTimestamp;
        uint32_t           OutAggregatedRawDataSize;

        // Raw report pointers
        const uint8_t** PrevRawDataPtrs;
        const uint8_t** LastRawDataPtrs;

        // Saved report
        uint8_t** PrevSavedReportPtrs;
        uint8_t** LastSavedReportPtrs;

        // Cached report pointers
        uint8_t** CachedReportPtrsBase;
        uint8_t** CachedReportPtrs;

        // Interpolated report pointers
        uint8_t** InterpolatedReportPtrs;

        // Aggregated raw data pointer
        uint8_t* OutAggregatedRawDataPtr;

        // Multiple sources aggregation
        uint64_t* CurrentTs;
        bool*     NeedReport;
        bool*     IsCachedReport;
        uint32_t* CachedReportPtrsSize;
        bool      IsNewCalculationWindow;
        bool*     SkipReportAfterRc6;
        bool*     IsPrevRawDataPresent;
        bool*     IsLastRawDataPresent;

    } TStreamAggregationContext;

    ///////////////////////////////////////////////////////////////////////////////
    // Query specific aggregation context:
    //////////////////////////////////////////////////////////////////////////////
    typedef struct SQueryAggregationContext : public TCommonAggregationContext
    {
    } TQueryAggregationContext;

    ///////////////////////////////////////////////////////////////////////////////
    // Union with all of aggregation contexts:
    //////////////////////////////////////////////////////////////////////////////
    typedef union SAggregationContext
    {
        TCommonAggregationContext CommonAggregationContext;
        TStreamAggregationContext StreamAggregationContext;
        TQueryAggregationContext  QueryAggregationContext;
    } TAggregationContext;

    //////////////////////////////////////////////////////////////////////////////////
    // Calculation context states:
    //////////////////////////////////////////////////////////////////////////////////
    typedef enum ECalculationContextState
    {
        CALCULATION_CONTEXT_STATE_INITIAL,
        CALCULATION_CONTEXT_STATE_LOAD_CALCULATION_WINDOW,
        CALCULATION_CONTEXT_STATE_CALCULATION_WINDOW_LOADED,
        CALCULATION_CONTEXT_STATE_AGGREGATION_WINDOW_START_REACHED,
        CALCULATION_CONTEXT_STATE_SEEK_AGGREGATION_WINDOW,
        CALCULATION_CONTEXT_STATE_FINISHED
    } TCalculationContextState;

    //////////////////////////////////////////////////////////////////////////////////
    // Calculation context states for timer mode:
    //////////////////////////////////////////////////////////////////////////////////
    typedef enum ECalculationContextStateTimerMode
    {
        CALCULATION_CONTEXT_STATE_TIMER_MODE_INITIAL,
        CALCULATION_CONTEXT_STATE_TIMER_MODE_SEEK_DATA_START,
        CALCULATION_CONTEXT_STATE_TIMER_MODE_LOAD_CALCULATION_WINDOW,
        CALCULATION_CONTEXT_STATE_TIMER_MODE_SEEK_NEXT_SAMPLE,
        CALCULATION_CONTEXT_STATE_TIMER_MODE_SEEK_BASE_SAMPLE,
        CALCULATION_CONTEXT_STATE_TIMER_MODE_FINISHED
    } TCalculationContextStateTimerMode;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationManager
    //
    // Description:
    //     Base pure virtual class used for calculations.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CCalculationManager
    {
    public:
        virtual ~CCalculationManager() {};

        // Calculation.
        virtual void            ResetContext( TCalculationContext& context )             = 0;
        virtual TCompletionCode PrepareContext( TCalculationContext& context )           = 0;
        virtual bool            CalculateNextReport( TCalculationContext& context )      = 0;
        virtual bool            CalculateNextAsyncReport( TCalculationContext& context ) = 0;

        // Aggregation.
        virtual void            ResetContext( TAggregationContext& context )        = 0;
        virtual TCompletionCode PrepareContext( TAggregationContext& context )      = 0;
        virtual bool            AggregateNextReport( TAggregationContext& context ) = 0;
        virtual uint32_t        GetRequiredSize( TAggregationContext& context )     = 0;
        virtual void            AggregateCounters( TAggregationContext& context )   = 0;
    };

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculationManager
    //
    // Description:
    //     Template class used for complete metrics calculations.
    //
    //////////////////////////////////////////////////////////////////////////////
    template <TMeasurementType measurementType>
    class CMetricsCalculationManager : public CCalculationManager
    {
    public:
        // Calculation.
        virtual void            ResetContext( TCalculationContext& context ) final;
        virtual TCompletionCode PrepareContext( TCalculationContext& context ) final;
        virtual bool            CalculateNextReport( TCalculationContext& context ) final;
        virtual bool            CalculateNextAsyncReport( TCalculationContext& context ) final;

        // Aggregation.
        virtual void            ResetContext( TAggregationContext& context ) final;
        virtual TCompletionCode PrepareContext( TAggregationContext& context ) final;
        virtual bool            AggregateNextReport( TAggregationContext& context ) final;
        virtual uint32_t        GetRequiredSize( TAggregationContext& context ) final;
        virtual void            AggregateCounters( TAggregationContext& context ) final;

    private:
        int32_t GetInformationIndex( const char* symbolName, CMetricSet* set );
        void    ProcessCalculation( TStreamCalculationContext* sc, bool async, uint32_t adapterId );
    };
} // namespace MetricsDiscoveryInternal
