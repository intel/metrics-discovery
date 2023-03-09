/*========================== begin_copyright_notice ============================

Copyright (C) 2019-2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_calculation.h
//
//     Abstract:   C++ metrics discovery metrics calculation features header.

#pragma once

#include "metrics_discovery_api.h"
#include "md_metrics_calculator.h"

#include <stack>

#define MD_SAVED_REPORT_NUMBER 0xFFFFFFFF

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    // Forward declarations //
    class CMetricsDevice;
    class CMetricSet;
    class CEquation;

    ///////////////////////////////////////////////////////////////////////////////
    //      * Common calculation context:
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
        TTypedValue_1_0* OutPtr;      // Required
        TTypedValue_1_0* OutMaxValuesPtr;

    } TCommonCalculationContext;

    ///////////////////////////////////////////////////////////////////////////////
    //      * Stream specific calculation context:
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
    //      * Query specific calculation context:
    //////////////////////////////////////////////////////////////////////////////
    typedef struct SQueryCalculationContext : public TCommonCalculationContext
    {
        // Calculation
        const uint8_t* RawDataPtr;

    } TQueryCalculationContext;

    ///////////////////////////////////////////////////////////////////////////////
    //      * Union with all of calculation contexts:
    //////////////////////////////////////////////////////////////////////////////
    typedef union SCalculationContext
    {
        TCommonCalculationContext CommonCalculationContext;
        TStreamCalculationContext StreamCalculationContext;
        TQueryCalculationContext  QueryCalculationContext;
    } TCalculationContext;

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
        virtual ~CCalculationManager(){};
        virtual void            ResetContext( TCalculationContext& context )        = 0;
        virtual TCompletionCode PrepareContext( TCalculationContext& context )      = 0;
        virtual bool            CalculateNextReport( TCalculationContext& context ) = 0;
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
        virtual void            ResetContext( TCalculationContext& context );
        virtual TCompletionCode PrepareContext( TCalculationContext& context );
        virtual bool            CalculateNextReport( TCalculationContext& context );

    private:
        int32_t GetInformationIndex( const char* symbolName, CMetricSet* set );
    };
} // namespace MetricsDiscoveryInternal
