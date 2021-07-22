/*========================== begin_copyright_notice ============================

Copyright (C) 2019-2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_calculation.h
//
//     Abstract:   C++ metrics discovery metrics calculation features header.

#pragma once

#include "metrics_discovery_api.h"
#include "md_utils.h"

#define MD_SAVED_REPORT_NUMBER 0xFFFFFFFF

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    // Forward declarations //
    class CMetricsCalculator;
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
        IConcurrentGroup_1_5* ConcurrentGroup;
        CMetricSet*           MetricSet; // Required
        uint32_t              MetricsAndInformationCount;

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

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculator
    //
    // Description:
    //     Class wrapping operations like raw values read or normalization on a single report.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CMetricsCalculator
    {
    public:
        CMetricsCalculator( CMetricsDevice* metricsDevice );
        ~CMetricsCalculator();

        void Reset( uint32_t rawReportSize = 0 );

        TCompletionCode ReadMetricsFromQueryReport(
            const uint8_t*   rawData,
            TTypedValue_1_0* outValues,
            CMetricSet&      metricSet );

        TCompletionCode ReadMetricsFromIoReport(
            const uint8_t*   reportRaportLast,
            const uint8_t*   reportRaportPrev,
            TTypedValue_1_0* outValues,
            CMetricSet&      metricSet );

        void NormalizeMetrics(
            TTypedValue_1_0* deltaValues,
            TTypedValue_1_0* outValues,
            CMetricSet&      metricSet );
        void ReadInformation(
            const uint8_t*   rawData,
            TTypedValue_1_0* outValues,
            CMetricSet&      metricSet,
            int32_t          contextIdIdx );

        void ReadContextIdInformation(
            const uint8_t* rawData,
            CMetricSet&    metricSet,
            int32_t        contextIdIdx );

        uint64_t ReadInformationByIndex(
            const uint8_t* rawData,
            CMetricSet&    metricSet,
            int32_t        informationIndex );

        void ReadSingleInformation(
            const uint8_t*    rawReport,
            IInformation_1_0* information,
            uint32_t          apiMask,
            TTypedValue_1_0*  result );

        void ReadIoMeasurementInformation(
            IConcurrentGroup_1_1& concurrentGroup,
            TTypedValue_1_0*      outValues );

        void CalculateMaxValues(
            TTypedValue_1_0* deltaMetricValues,
            TTypedValue_1_0* outMetricValues,
            TTypedValue_1_0* outMaxValues,
            CMetricSet&      metricSet );

        TCompletionCode SaveReport( const uint8_t* lastReport );
        bool            SavedReportPresent();
        uint8_t*        GetSavedReport();
        void            DiscardSavedReport();

        uint64_t CastToUInt64( const TTypedValue_1_0& value );
        float    CastToFloat( const TTypedValue_1_0& value );

        uint64_t ReadBitfield(
            const uint8_t* rawReport,
            uint32_t       bitOffset,
            uint32_t       bitCount );

    private:
        TTypedValue_1_0 CalculateDeltaFunction(
            TDeltaFunction_1_0     deltaFunction,
            const TTypedValue_1_0& lastValue,
            const TTypedValue_1_0& previousValue );

        TTypedValue_1_0* GetGlobalSymbolValue(
            const char* symbolName );

        TTypedValue_1_0 CalculateReadEquation(
            CEquation&     equation,
            const uint8_t* rawReport );

        TTypedValue_1_0 CalculateReadEquationAndDelta(
            CEquation&         equation,
            TDeltaFunction_1_0 deltaFunction,
            const uint8_t*     pRawReportLast,
            const uint8_t*     pRawReportPrev );

        TTypedValue_1_0 CalculateLocalNormalizationEquation(
            CEquation&       equation,
            TTypedValue_1_0* deltaValues,
            TTypedValue_1_0* results,
            uint32_t         metricIndex );

        TTypedValue_1_0 CalculateEquationElemOperation(
            TEquationOperation     operation,
            const TTypedValue_1_0& valuePrev,
            const TTypedValue_1_0& valueLast );

        // Inline function
        bool inline EquationStackPush(
            Stack<TTypedValue_1_0>& stack,
            TTypedValue_1_0&        value,
            uint32_t&               algorithmCheck )
        {
            stack.push( value );
            algorithmCheck++;
            return ( stack.size() == algorithmCheck );
        }

    private:
        Stack<TTypedValue_1_0> m_equationStack;
        uint64_t               m_gpuCoreClocks;
        uint32_t               m_euCoresCount;
        uint32_t               m_savedReportSize;
        uint8_t*               m_savedReport;
        bool                   m_savedReportPresent;
        uint64_t               m_contextIdPrev;
        CMetricsDevice*        m_device;
    };

} // namespace MetricsDiscoveryInternal
