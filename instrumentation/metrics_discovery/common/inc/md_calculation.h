/*****************************************************************************\

    Copyright © 2019, Intel Corporation

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.

    File Name:  md_calculation.h

    Abstract:   C++ metrics discovery metrics calculation features header.

\*****************************************************************************/
#include "metrics_discovery_api.h"
#include "md_utils.h"

#define MD_SAVED_REPORT_NUMBER 0xFFFFFFFF

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    /* Forward declarations */
    class CMetricsCalculator;

    /******************************************************************************\
     * Common calculation context:
     ******************************************************************************/
    typedef struct SCommonCalculationContext
    {
        // MetricsCalculator
        CMetricsCalculator*  Calculator;            // Required

        // MetricSet
        IMetricSet_1_1*      MetricSet;             // Required
        uint32_t             MetricsAndInformationCount;

        // Input
        const unsigned char* RawData;               // Required
        uint32_t             RawReportCount;        // Required
        uint32_t             RawReportSize;

        // Output
        TTypedValue_1_0*     Out;                   // Required
        uint32_t             OutReportCount;
        TTypedValue_1_0*     OutMaxValues;

        // Calculation
        TTypedValue_1_0*     DeltaValues;           // Required
        TTypedValue_1_0*     OutPtr;                // Required
        TTypedValue_1_0*     OutMaxValuesPtr;

    } TCommonCalculationContext;

    /******************************************************************************\
     * Stream specific calculation context:
     ******************************************************************************/
    typedef struct SStreamCalculationContext : public TCommonCalculationContext
    {
        // MetricSet
        int32_t              ReportReasonIdx;
        int32_t              ContextIdIdx;

        // ContextFiltering
        bool                 DoContextFiltering;    // Required - not supported

        // Calculation
        const unsigned char* PrevRawDataPtr;
        uint32_t             PrevRawReportNumber;
        const unsigned char* LastRawDataPtr;
        uint32_t             LastRawReportNumber;

    } TStreamCalculationContext;

    /******************************************************************************\
     * Query specific calculation context:
     ******************************************************************************/
    typedef struct SQueryCalculationContext : public TCommonCalculationContext
    {
        // Calculation
        const unsigned char* RawDataPtr;

    } TQueryCalculationContext;

    /******************************************************************************\
     * Union with all of calculation contexts:
     ******************************************************************************/
    typedef union SCalculationContext
    {
        TCommonCalculationContext CommonCalculationContext;
        TStreamCalculationContext StreamCalculationContext;
        TQueryCalculationContext  QueryCalculationContext;
    } TCalculationContext;

/*****************************************************************************\

Class:
    CCalculationManager

Description:
    Base pure virtual class used for calculations.

\*****************************************************************************/
    class CCalculationManager
    {
    public:
        virtual ~CCalculationManager() { };
        virtual void ResetContext( TCalculationContext& context ) = 0;
        virtual TCompletionCode PrepareContext( TCalculationContext& context ) = 0;
        virtual bool CalculateNextReport( TCalculationContext& context ) = 0;
    };

/*****************************************************************************\

Class:
    CMetricsCalculationManager

Description:
    Template class used for complete metrics calculations.

\*****************************************************************************/
    template <TMeasurementType measurementType> class CMetricsCalculationManager : public CCalculationManager
    {
    public:
        virtual void ResetContext( TCalculationContext& context );
        virtual TCompletionCode PrepareContext( TCalculationContext& context );
        virtual bool CalculateNextReport( TCalculationContext& context );

    private:
        bool FindIoReportOfInterest( TStreamCalculationContext* sc, bool isPrevReport );
        int32_t GetInformationIndex( const char* symbolName, IMetricSet_1_1* set );
    };

/*****************************************************************************\

Class:
    CMetricsCalculator

Description:
    Class wrapping operations like raw values read or normalization on a single report.

\*****************************************************************************/
    class CMetricsCalculator
    {
    public:
        CMetricsCalculator( IMetricsDevice_1_1* metricsDevice );
        ~CMetricsCalculator();

        void               Reset( uint32_t rawReportSize = 0 );

        TCompletionCode    ReadMetricsFromQueryReport(
            const unsigned char*   rawData,
            TTypedValue_1_0*       outValues,
            IMetricSet_1_1*        metricSet );

        TCompletionCode    ReadMetricsFromIoReport(
            const unsigned char*   reportRaportLast,
            const unsigned char*   reportRaportPrev,
            TTypedValue_1_0*       outValues,
            IMetricSet_1_1*        metricSet );

        void                NormalizeMetrics(
            TTypedValue_1_0*       deltaValues,
            TTypedValue_1_0*       outValues,
            IMetricSet_1_1*        metricSet );

        void                ReadInformation(
            const unsigned char*   rawData,
            TTypedValue_1_0*       outValues,
            IMetricSet_1_1*        metricSet );

        void                ReadIoMeasurementInformation(
            IConcurrentGroup_1_1*  concurrentGroup,
            TTypedValue_1_0*       outValues );

        void                CalculateMaxValues(
            TTypedValue_1_0*       deltaMetricValues,
            TTypedValue_1_0*       outMetricValues,
            TTypedValue_1_0*       outMaxValues,
            IMetricSet_1_1*        metricSet );

        TCompletionCode     SaveReport( const unsigned char* lastReport );
        bool                SavedReportPresent();
        unsigned char*      GetSavedReport();
        void                DiscardSavedReport();

    private:
        TTypedValue_1_0     CalculateReadEquation(
            IEquation_1_0*         equation,
            const unsigned char*   rawReport );

        TTypedValue_1_0     CalculateReadEquationAndDelta(
            IEquation_1_0*         equation,
            TDeltaFunction_1_0     deltaFunction,
            const unsigned char*   pRawReportLast,
            const unsigned char*   pRawReportPrev );

        TTypedValue_1_0     CalculateDeltaFunction(
            TDeltaFunction_1_0     deltaFunction,
            const TTypedValue_1_0& lastValue,
            const TTypedValue_1_0& previousValue );

        TTypedValue_1_0     CalculateLocalNormalizationEquation(
            IEquation_1_0*         equation,
            TTypedValue_1_0*       deltaValues,
            TTypedValue_1_0*       results,
            IMetricSet_1_1*        metricSet,
            uint32_t               metricIndex );

        TTypedValue_1_0     CalculateEquationElemOperation(
            TEquationOperation     operation,
            const TTypedValue_1_0& valuePrev,
            const TTypedValue_1_0& valueLast );

        void                ReadSingleInformation(
            const unsigned char*   rawReport,
            IInformation_1_0*      information,
            uint32_t               apiMask,
            TTypedValue_1_0*       result );

        uint64_t            CastToUInt64(
            const TTypedValue_1_0& value );

        float               CastToFloat(
            const TTypedValue_1_0& value );

        uint64_t            ReadBitfield(
            const unsigned char*   rawReport,
            uint32_t               bitOffset,
            uint32_t               bitCount );

        TTypedValue_1_0*    GetGlobalSymbolValue(
            const char*            symbolName );

        // Inline function
        bool inline EquationStackPush(
            Stack<TTypedValue_1_0>& stack,
            TTypedValue_1_0&        value,
            uint32_t&               algorithmCheck )
        {
            stack.push( value );
            algorithmCheck++;
            return (stack.size() == algorithmCheck);
        }

    private:
        Stack<TTypedValue_1_0>  m_equationStack;
        uint64_t                m_gpuCoreClocks;
        uint32_t                m_euCoresCount;
        uint32_t                m_savedReportSize;
        unsigned char*          m_savedReport;
        bool                    m_savedReportPresent;
        IMetricsDevice_1_1*     m_device;
    };

}
