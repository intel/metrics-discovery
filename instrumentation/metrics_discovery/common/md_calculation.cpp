//////////////////////////////////////////////////////////////////////////////
//
//  Copyright © 2019-2020, Intel Corporation
//
//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included
//  in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
//  IN THE SOFTWARE.
//
//  File Name:  md_calculation.cpp
//
//  Abstract:   C++ metrics discovery metrics calculation features implementation.
//
//////////////////////////////////////////////////////////////////////////////
#include "md_calculation.h"
#include "md_utils.h"
#include "md_types.h"

#include <algorithm>
#include <string.h>

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    // Forward declarations //
    template <>
    bool CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>::FindIoReportOfInterest( TStreamCalculationContext* sc, bool isPrevReport );
    template <>
    int32_t CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>::GetInformationIndex( const char* symbolName, IMetricSet_1_1* metricSet );

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

        context.StreamCalculationContext.ReportReasonIdx = -1;
        context.StreamCalculationContext.ContextIdIdx    = -1;
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
        MD_CHECK_PTR_RET( sc->MetricSet, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( sc->RawData, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( sc->Out, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( sc->DeltaValues, CC_ERROR_INVALID_PARAMETER );

        if( sc->DoContextFiltering )
        {
            // Find required indices for context filtering using MetricSet
            sc->ReportReasonIdx = GetInformationIndex( "ReportReason", sc->MetricSet );
            sc->ReportReasonIdx = GetInformationIndex( "ContextId", sc->MetricSet );

            if( sc->ReportReasonIdx < 0 || sc->ContextIdIdx < 0 )
            {
                MD_LOG( LOG_ERROR, "error: can't find required information for context filtering" );
                MD_LOG_EXIT();
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
        MD_CHECK_PTR_RET( qc->MetricSet, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( qc->RawData, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( qc->Out, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( qc->DeltaValues, CC_ERROR_INVALID_PARAMETER );

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

        if( sc->LastRawReportNumber >= sc->RawReportCount || sc->PrevRawReportNumber >= sc->RawReportCount - 1 )
        {
            // Nothing to be calculated
            MD_LOG( LOG_DEBUG, "Calculation complete" );
            if( CC_OK != sc->Calculator->SaveReport( sc->LastRawDataPtr ) )
            {
                MD_LOG( LOG_DEBUG, "Unable to store last raw report for reuse." );
            }
            return false;
        }

        if( sc->Calculator->SavedReportPresent() && sc->PrevRawReportNumber == 0 )
        {
            // Use saved report as 'Prev', 0 offset report as "Last"
            sc->PrevRawDataPtr      = sc->Calculator->GetSavedReport();
            sc->PrevRawReportNumber = MD_SAVED_REPORT_NUMBER;
            MD_ASSERT( sc->PrevRawDataPtr != NULL );
        }

        // Find Prev report of interest
        bool prevFound = sc->DoContextFiltering ? FindIoReportOfInterest( sc, true ) : true;

        // If not using saved report
        if( sc->PrevRawReportNumber != MD_SAVED_REPORT_NUMBER )
        {
            sc->LastRawDataPtr      = sc->PrevRawDataPtr + sc->RawReportSize;
            sc->LastRawReportNumber = sc->PrevRawReportNumber + 1;
        }

        // Find Last report of interest
        bool lastFound = sc->DoContextFiltering ? FindIoReportOfInterest( sc, false ) : true;

        if( prevFound && lastFound )
        {
            // METRICS
            sc->Calculator->ReadMetricsFromIoReport( sc->LastRawDataPtr, sc->PrevRawDataPtr, sc->DeltaValues, sc->MetricSet );
            // NORMALIZATION
            sc->Calculator->NormalizeMetrics( sc->DeltaValues, sc->OutPtr, sc->MetricSet );
            // INFORMATION
            sc->Calculator->ReadInformation( sc->LastRawDataPtr, sc->OutPtr + sc->MetricSet->GetParams()->MetricsCount, sc->MetricSet );
            // MAX VALUES
            if( sc->OutMaxValues )
            {
                sc->Calculator->CalculateMaxValues( sc->DeltaValues, sc->OutPtr, sc->OutMaxValuesPtr, sc->MetricSet );
                sc->OutMaxValuesPtr += sc->MetricSet->GetParams()->MetricsCount;
            }

            // Prev is now Last
            sc->PrevRawDataPtr      = sc->LastRawDataPtr;
            sc->PrevRawReportNumber = sc->LastRawReportNumber;

            sc->OutPtr += sc->MetricsAndInformationCount;
            sc->OutReportCount++;

            if( sc->Calculator->SavedReportPresent() )
            {
                sc->Calculator->DiscardSavedReport();
            }
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

        if( qc->OutReportCount >= qc->RawReportCount )
        {
            // Nothing to be calculated
            MD_LOG( LOG_DEBUG, "Calculation complete" );
            return false;
        }

        // METRICS
        qc->Calculator->ReadMetricsFromQueryReport( qc->RawDataPtr, qc->DeltaValues, qc->MetricSet );
        // NORMALIZATION
        qc->Calculator->NormalizeMetrics( qc->DeltaValues, qc->OutPtr, qc->MetricSet );
        // INFORMATION
        qc->Calculator->ReadInformation( qc->RawDataPtr, qc->OutPtr + qc->MetricSet->GetParams()->MetricsCount, qc->MetricSet );
        // MAX VALUES
        if( qc->OutMaxValues )
        {
            qc->Calculator->CalculateMaxValues( qc->DeltaValues, qc->OutPtr, qc->OutMaxValuesPtr, qc->MetricSet );
            qc->OutMaxValuesPtr += qc->MetricSet->GetParams()->MetricsCount;
        }

        qc->RawDataPtr += qc->RawReportSize;
        qc->OutPtr += qc->MetricsAndInformationCount;

        qc->OutReportCount++;

        return true;
    }

    /*****************************************************************************\

Class:
    CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>

Method:
    FindIoReportOfInterest

Description:
    Used in IoStream context filtering. Finds the prev or next context matching report.

Input:
    TStreamCalculationContext* sc - stream calculation context
    bool isPrevReport             - true, if this is for 'Prev' report
                                    false for 'Last' report

Output:
    bool                          - true if found, false otherwise

\*****************************************************************************/
    template <>
    bool CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>::FindIoReportOfInterest( TStreamCalculationContext* sc, bool isPrevReport )
    {
        // Not implemented - intended
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
    //     int - given information index in MetricSet, -1 if not found or error
    //
    //////////////////////////////////////////////////////////////////////////////

    template <>
    int CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>::GetInformationIndex( const char* symbolName, IMetricSet_1_1* metricSet )
    {
        MD_CHECK_PTR_RET( symbolName, -1 );
        MD_CHECK_PTR_RET( metricSet, -1 );

        uint32_t count = metricSet->GetParams()->InformationCount;
        for( uint32_t i = 0; i < count; i++ )
        {
            IInformation_1_0* information = metricSet->GetInformation( i );
            MD_ASSERT( information != NULL );

            TInformationParams_1_0* informationParams = information->GetParams();
            if( informationParams->SymbolName && strcmp( informationParams->SymbolName, symbolName ) == 0 )
            {
                return i;
            }
        }

        MD_LOG( LOG_DEBUG, "can't find information index: %s", symbolName );
        return -1;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculator
    //
    // Method:
    //     CMetricsCalculator
    //
    // Description:
    //     CMetricsCalculator constructor.
    //
    // Input:
    //     IMetricsDevice_1_1* metricsDevice - MetricsDevice used for obtaining GlobalSymbols
    //                                         during calculations
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricsCalculator::CMetricsCalculator( IMetricsDevice_1_1* metricsDevice )
    {
        m_device             = metricsDevice;
        m_gpuCoreClocks      = 0;
        m_euCoresCount       = 0;
        m_savedReport        = NULL;
        m_savedReportSize    = 0;
        m_savedReportPresent = false;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculator
    //
    // Method:
    //     ~CMetricsCalculator
    //
    // Description:
    //     CMetricsCalculator destructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricsCalculator::~CMetricsCalculator()
    {
        MD_SAFE_DELETE_ARRAY( m_savedReport );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //    CMetricsCalculator
    //
    // Method:
    //     Reset
    //
    // Description:
    //     Reset Calculator to the initial state.
    //     Allocate memory to store last raw report for future calculation.
    //
    // Input:
    //     uint32_t rawReportSize - Raw report size to allocate memory for report to save.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricsCalculator::Reset( uint32_t rawReportSize /* = 0*/ )
    {
        TTypedValue_1_0* euCoresTotalCount = GetGlobalSymbolValue( "EuCoresTotalCount" );

        m_euCoresCount  = euCoresTotalCount ? euCoresTotalCount->ValueUInt32 : 0;
        m_gpuCoreClocks = 0;

        if( m_savedReportSize != rawReportSize && rawReportSize > 0 )
        {
            MD_SAFE_DELETE_ARRAY( m_savedReport );
            m_savedReport = new( std::nothrow ) uint8_t[rawReportSize];
            if( m_savedReport == NULL )
            {
                MD_LOG( LOG_ERROR, "error allocating saved report memory" );
                m_savedReportSize = 0;
            }
            else
            {
                m_savedReportSize = rawReportSize;
            }
            m_savedReportPresent = false;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //    CMetricsCalculator
    //
    // Method:
    //     SaveReport
    //
    // Description:
    //     Stores report for next calculations
    //
    // Input:
    //     const uint8_t* reportToSave - (IN) single raw report to save
    //
    // Output:
    //     TCompletionCode - CC_OK on success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricsCalculator::SaveReport( const uint8_t* reportToSave )
    {
        MD_CHECK_PTR_RET( m_savedReport, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( reportToSave, CC_ERROR_INVALID_PARAMETER );

        bool res = iu_memcpy_s( m_savedReport, m_savedReportSize, reportToSave, m_savedReportSize );
        if( res )
        {
            m_savedReportPresent = true;
        }

        return res ? CC_OK : CC_ERROR_GENERAL;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //    CMetricsCalculator
    //
    // Method:
    //     SavedReportPresent
    //
    // Description:
    //     Check if Calculator has saved report.
    //
    // Output:
    //     bool - true if report saved
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetricsCalculator::SavedReportPresent()
    {
        return m_savedReportPresent;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //    CMetricsCalculator
    //
    // Method:
    //     GetSavedReport
    //
    // Description:
    //     Getter for saved report pointer.
    //
    // Output:
    //     uint8_t* - saved report
    //
    //////////////////////////////////////////////////////////////////////////////
    uint8_t* CMetricsCalculator::GetSavedReport()
    {
        return m_savedReport;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //    CMetricsCalculator
    //
    // Method:
    //     DiscardSavedReport
    //
    // Description:
    //     Sets to false flag indicating report save.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricsCalculator::DiscardSavedReport()
    {
        m_savedReportPresent = false;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculator
    //
    // Method:
    //     ReadMetricsFromQueryReport
    //
    // Description:
    //     Reads metrics from a given metric set using raw report data.
    //
    // Input:
    //     const uint8_t* rawReport - (IN) single raw report
    //     TTypedValue_1_0*     outValues - (OUT) single output report
    //     IMetricSet_1_1*      metricSet - metric set for which the calculation will be conducted
    //
    // Output:
    //     TCompletionCode - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricsCalculator::ReadMetricsFromQueryReport( const uint8_t* rawReport, TTypedValue_1_0* outValues, IMetricSet_1_1* metricSet )
    {
        MD_CHECK_PTR_RET( rawReport, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( outValues, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( metricSet, CC_ERROR_INVALID_PARAMETER );

        m_gpuCoreClocks = 0;

        uint32_t metricsCount = metricSet->GetParams()->MetricsCount;
        for( uint32_t i = 0; i < metricsCount; i++ )
        {
            TMetricParams_1_0* metricParams = metricSet->GetMetric( i )->GetParams();
            IEquation_1_0*     equation     = metricParams->QueryReadEquation;

            if( equation )
            {
                outValues[i] = CalculateReadEquation( equation, rawReport );
            }
            else
            {
                outValues[i].ValueType   = VALUE_TYPE_UINT64;
                outValues[i].ValueUInt64 = 0ULL;
            }

            if( strcmp( metricParams->SymbolName, "GpuCoreClocks" ) == 0 )
            {
                m_gpuCoreClocks = outValues[i].ValueUInt64;
            }
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculator
    //
    // Method:
    //     ReadMetricsFromIoReport
    //
    // Description:
    //     Reads metrics from a given metric set using raw report data for prev and last report.
    //
    // Input:
    //     const uint8_t* rawRaportLast - (IN) last (next) single raw report
    //     const uint8_t* rawRaportPrev - (IN) previous single raw report
    //     TTypedValue_1_0*     outValues     - (OUT) read metric values
    //     IMetricSet_1_1*      metricSet     - MetricSet for calculations
    //
    // Output:
    //     TCompletionCode - *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetricsCalculator::ReadMetricsFromIoReport( const uint8_t* rawRaportLast, const uint8_t* rawRaportPrev, TTypedValue_1_0* outValues, IMetricSet_1_1* metricSet )
    {
        MD_CHECK_PTR_RET( rawRaportLast, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( rawRaportPrev, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( outValues, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( metricSet, CC_ERROR_INVALID_PARAMETER );

        m_gpuCoreClocks = 0;

        uint32_t metricsCount = metricSet->GetParams()->MetricsCount;
        for( uint32_t i = 0; i < metricsCount; i++ )
        {
            TMetricParams_1_0* metricParams = metricSet->GetMetric( i )->GetParams();
            IEquation_1_0*     equation     = metricParams->IoReadEquation;

            if( equation )
            {
                TDeltaFunction_1_0 deltaFunc = metricParams->DeltaFunction;
                outValues[i]                 = CalculateReadEquationAndDelta( equation, deltaFunc, rawRaportLast, rawRaportPrev );
            }
            else
            {
                outValues[i].ValueType   = VALUE_TYPE_UINT64;
                outValues[i].ValueUInt64 = 0ULL;
            }

            if( strcmp( metricParams->SymbolName, "GpuCoreClocks" ) == 0 )
            {
                m_gpuCoreClocks = outValues[i].ValueUInt64;
            }
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculator
    //
    // Method:
    //     NormalizeMetrics
    //
    // Description:
    //     Normalizes metrics from a given metric set using previously read data.
    //
    // Input:
    //     TTypedValue_1_0* deltaValues - (IN) previously read metric delta values
    //     TTypedValue_1_0* outValues   - (OUT) output normalized metric values
    //     IMetricSet_1_1*  metricSet   - MetricSet for calculations
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricsCalculator::NormalizeMetrics( TTypedValue_1_0* deltaValues, TTypedValue_1_0* outValues, IMetricSet_1_1* metricSet )
    {
        if( !deltaValues || !outValues || !metricSet )
        {
            MD_ASSERT( deltaValues != NULL );
            MD_ASSERT( outValues != NULL );
            MD_ASSERT( metricSet != NULL );
            MD_LOG( LOG_ERROR, "error: null params" );
            return;
        }

        uint32_t metricsCount = metricSet->GetParams()->MetricsCount;
        for( uint32_t i = 0; i < metricsCount; i++ )
        {
            TMetricParams_1_0* metricParams = metricSet->GetMetric( i )->GetParams();
            IEquation_1_0*     normEquation = metricParams->NormEquation;
            if( normEquation )
            {
                // do final calculation, may refer to global symbols, local delta results and local normalization results
                outValues[i] = CalculateLocalNormalizationEquation( normEquation, deltaValues, outValues, metricSet, i );
            }
            else
            {
                outValues[i] = deltaValues[i];
            }
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculator
    //
    // Method:
    //     ReadInformation
    //
    // Description:
    //     Reads information from a given metric set.
    //
    // Input:
    //     const uint8_t* rawData   - (IN) single raw report data
    //     TTypedValue_1_0*     outValues - (OUT) out values with calculated information
    //     IMetricSet_1_1*      metricSet - MetricSet for calculations
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricsCalculator::ReadInformation( const uint8_t* rawData, TTypedValue_1_0* outValues, IMetricSet_1_1* metricSet )
    {
        if( !rawData || !outValues || !metricSet )
        {
            MD_ASSERT( rawData != NULL );
            MD_ASSERT( outValues != NULL );
            MD_ASSERT( metricSet != NULL );
            MD_LOG( LOG_ERROR, "error: null params" );
            return;
        }

        IInformation_1_0* information      = NULL;
        uint32_t          informationCount = metricSet->GetParams()->InformationCount;
        for( uint32_t i = 0; i < informationCount; i++ )
        {
            information = metricSet->GetInformation( i );
            ReadSingleInformation( rawData, information, metricSet->GetParams()->ApiMask, &outValues[i] );
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculator
    //
    // Method:
    //     ReadIoMeasurementInformation
    //
    // Description:
    //     Calculates IoMeasurementInformation obtained on every ReadIoStream.
    //
    // Input:
    //     IConcurrentGroup_1_1* concurrentGroup - ConcurrentGroup which was used during ReadIoStream
    //     TTypedValue_1_0*      outValues       - (OUT) calculated values
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricsCalculator::ReadIoMeasurementInformation( IConcurrentGroup_1_1* concurrentGroup, TTypedValue_1_0* outValues )
    {
        if( !outValues || !concurrentGroup )
        {
            MD_ASSERT( outValues != NULL );
            MD_ASSERT( concurrentGroup != NULL );
            MD_LOG( LOG_ERROR, "error: null params" );
            return;
        }

        uint32_t measurementInfoCount = concurrentGroup->GetParams()->IoMeasurementInformationCount;
        for( uint32_t i = 0; i < measurementInfoCount; i++ )
        {
            IInformation_1_0* measurementInfo = concurrentGroup->GetIoMeasurementInformation( i );
            MD_ASSERT( measurementInfo != NULL );

            IEquation_1_0* equation = measurementInfo->GetParams()->IoReadEquation;
            if( equation )
            {
                outValues[i] = CalculateReadEquation( equation, NULL );
            }
            else
            {
                outValues[i].ValueUInt64 = 0ULL;
            }

            if( measurementInfo->GetParams()->InfoType == INFORMATION_TYPE_FLAG )
            {
                outValues[i].ValueType = VALUE_TYPE_BOOL;
            }
            else
            {
                outValues[i].ValueType = VALUE_TYPE_UINT64;
            }
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculator
    //
    // Method:
    //     CalculateMaxValues
    //
    // Description:
    //     Calculates max value for every metric, specified by MaxValueEquation.
    //     If the equation isn't present, current normalized metric value is used as max value.
    //
    // Input:
    //     TTypedValue_1_0* deltaMetricValues - (IN) previously read metric delta values
    //     TTypedValue_1_0* outMetricValues   - (IN) normalized metric values
    //     TTypedValue_1_0* outMaxValues      - (OUT) output max values
    //     IMetricSet_1_1*  metricSet         - MetricSet for calculations
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricsCalculator::CalculateMaxValues( TTypedValue_1_0* deltaMetricValues, TTypedValue_1_0* outMetricValues, TTypedValue_1_0* outMaxValues, IMetricSet_1_1* metricSet )
    {
        if( !deltaMetricValues || !outMetricValues || !outMaxValues || !metricSet )
        {
            MD_ASSERT( deltaMetricValues != NULL );
            MD_ASSERT( outMetricValues != NULL );
            MD_ASSERT( outMaxValues != NULL );
            MD_ASSERT( metricSet != NULL );
            MD_LOG( LOG_ERROR, "error: null params" );
            return;
        }

        uint32_t metricsCount = metricSet->GetParams()->MetricsCount;

        for( uint32_t i = 0; i < metricsCount; i++ )
        {
            TMetricParams_1_0* metricParams     = metricSet->GetMetric( i )->GetParams();
            IEquation_1_0*     maxValueEquation = metricParams->MaxValueEquation;

            if( maxValueEquation )
            {
                // Do final calculation, may refer to global symbols, local delta results and local normalization results.
                // Normalization equation function is used because NormalizationEquation has the same restrictions as MaxValueEquation.
                outMaxValues[i] = CalculateLocalNormalizationEquation( maxValueEquation, deltaMetricValues, outMetricValues, metricSet, i );
            }
            else
            {
                outMaxValues[i] = outMetricValues[i];
            }
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculator
    //
    // Method:
    //     CalculateReadEquation
    //
    // Description:
    //     Calculates the given read equation.
    //
    // Input:
    //     IEquation_1_0* equation  - read equation to calculate
    //     const unsigned char* rawReport - (IN) single raw report
    //
    // Output:
    //     TTypedValue_1_0 - output read value
    //
    //////////////////////////////////////////////////////////////////////////////
    TTypedValue_1_0 CMetricsCalculator::CalculateReadEquation( IEquation_1_0* equation, const uint8_t* rawReport )
    {
        TTypedValue_1_0 typedValue;
        bool            isValid        = true;
        uint32_t        algorithmCheck = 0;

        // Prepare the stack for calculations.
        isValid = m_equationStack.reserve( equation->GetEquationElementsCount() );
        m_equationStack.clear();

        for( uint32_t i = 0; i < equation->GetEquationElementsCount() && isValid; i++ )
        {
            TEquationElement_1_0* element = equation->GetEquationElement( i );
            switch( element->Type )
            {
                case EQUATION_ELEM_RD_BITFIELD:
                    typedValue.ValueUInt64 = ReadBitfield( (const uint8_t*) ( rawReport + element->ReadParams.ByteOffset ), element->ReadParams.BitOffset, element->ReadParams.BitsCount );
                    typedValue.ValueType   = VALUE_TYPE_UINT64;
                    isValid                = EquationStackPush( m_equationStack, typedValue, algorithmCheck );
                    break;

                case EQUATION_ELEM_RD_UINT8:
                {
                    uint8_t byteValue      = *( (const uint8_t*) ( rawReport + element->ReadParams.ByteOffset ) );
                    typedValue.ValueUInt64 = (uint64_t) byteValue;
                    typedValue.ValueType   = VALUE_TYPE_UINT64;
                    isValid                = EquationStackPush( m_equationStack, typedValue, algorithmCheck );
                    break;
                }

                case EQUATION_ELEM_RD_UINT16:
                {
                    unsigned short shortValue = *( (const unsigned short*) ( rawReport + element->ReadParams.ByteOffset ) );
                    typedValue.ValueUInt64    = (uint64_t) shortValue;
                    typedValue.ValueType      = VALUE_TYPE_UINT64;
                    isValid                   = EquationStackPush( m_equationStack, typedValue, algorithmCheck );
                    break;
                }

                case EQUATION_ELEM_RD_UINT32:
                {
                    uint32_t dwordValue    = *( (const uint32_t*) ( rawReport + element->ReadParams.ByteOffset ) );
                    typedValue.ValueUInt64 = (uint64_t) dwordValue;
                    typedValue.ValueType   = VALUE_TYPE_UINT64;
                    isValid                = EquationStackPush( m_equationStack, typedValue, algorithmCheck );
                    break;
                }

                case EQUATION_ELEM_RD_UINT64:
                    typedValue.ValueUInt64 = *( (const uint64_t*) ( rawReport + element->ReadParams.ByteOffset ) );
                    typedValue.ValueType   = VALUE_TYPE_UINT64;
                    isValid                = EquationStackPush( m_equationStack, typedValue, algorithmCheck );
                    break;

                case EQUATION_ELEM_RD_FLOAT:
                    typedValue.ValueFloat = *( (const float*) ( rawReport + element->ReadParams.ByteOffset ) );
                    typedValue.ValueType  = VALUE_TYPE_FLOAT;
                    isValid               = EquationStackPush( m_equationStack, typedValue, algorithmCheck );
                    break;

                case EQUATION_ELEM_RD_40BIT_CNTR:
                {
                    TLargeInteger largeValue;
                    largeValue.u.LowPart   = *( (const uint32_t*) ( rawReport + element->ReadParams.ByteOffset ) );
                    largeValue.u.HighPart  = ( uint32_t ) * ( (const uint8_t*) ( rawReport + element->ReadParams.ByteOffsetExt ) );
                    typedValue.ValueUInt64 = largeValue.QuadPart;
                    typedValue.ValueType   = VALUE_TYPE_UINT64;
                    isValid                = EquationStackPush( m_equationStack, typedValue, algorithmCheck );
                    break;
                }

                case EQUATION_ELEM_IMM_UINT64:
                    typedValue.ValueUInt64 = element->ImmediateUInt64;
                    typedValue.ValueType   = VALUE_TYPE_UINT64;
                    isValid                = EquationStackPush( m_equationStack, typedValue, algorithmCheck );
                    break;

                case EQUATION_ELEM_IMM_FLOAT:
                    typedValue.ValueFloat = element->ImmediateFloat;
                    typedValue.ValueType  = VALUE_TYPE_FLOAT;
                    isValid               = EquationStackPush( m_equationStack, typedValue, algorithmCheck );
                    break;

                case EQUATION_ELEM_GLOBAL_SYMBOL:
                {
                    TTypedValue_1_0* pValue = GetGlobalSymbolValue( element->SymbolName );
                    if( pValue )
                    {
                        typedValue = *pValue;
                    }
                    else
                    {
                        typedValue.ValueUInt64 = 0;
                        typedValue.ValueType   = VALUE_TYPE_UINT64;
                    }
                    isValid = EquationStackPush( m_equationStack, typedValue, algorithmCheck );
                    break;
                }

                case EQUATION_ELEM_OPERATION:
                {
                    // Pop two values from stack
                    TTypedValue_1_0 valueLast = m_equationStack.top();
                    m_equationStack.pop();
                    algorithmCheck--;
                    TTypedValue_1_0 valuePrev = m_equationStack.top();
                    m_equationStack.pop();
                    algorithmCheck--;

                    typedValue = CalculateEquationElemOperation( element->Operation, valuePrev, valueLast );
                    isValid    = EquationStackPush( m_equationStack, typedValue, algorithmCheck );
                    break;
                }

                default:
                    MD_ASSERT( false );
                    break;
            }
        }
        // Here should be only 1 element on the list - the result (if the equation is fine)
        MD_ASSERT( algorithmCheck == 1 );

        if( isValid && algorithmCheck == 1 )
        {
            typedValue = m_equationStack.top();
            m_equationStack.pop();
        }
        else
        {
            typedValue.ValueUInt64 = 0;
            typedValue.ValueType   = VALUE_TYPE_UINT64;
        }

        return typedValue;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculator
    //
    // Method:
    //     CalculateReadEquationAndDelta
    //
    // Description:
    //     Calculates the given read equation using delta function directly after reading
    //     raw offsets.
    //
    // Input:
    //     IEquation_1_0*     equation       - read equation to calculate
    //     TDeltaFunction_1_0 deltaFunction  - delta function to use during calculations
    //     const uint8_t*     pRawReportLast - (IN) last (next) single raw report
    //     const uint8_t*     pRawReportPrev - (IN) previous single raw report
    //
    // Output:
    //     TTypedValue_1_0 - output read value
    //
    //////////////////////////////////////////////////////////////////////////////
    TTypedValue_1_0 CMetricsCalculator::CalculateReadEquationAndDelta( IEquation_1_0* equation, TDeltaFunction_1_0 deltaFunction, const uint8_t* pRawReportLast, const uint8_t* pRawReportPrev )
    {
        TTypedValue_1_0    typedValue, typedValuePrev, typedValueLast;
        TDeltaFunction_1_0 readDeltaFunction;
        // As we calculate delta when reading operands DELTA_NS_TIME works as a normal DELTA_32
        if( deltaFunction.FunctionType == DELTA_NS_TIME )
        {
            readDeltaFunction.FunctionType = DELTA_N_BITS;
            readDeltaFunction.BitsCount    = 32;
        }
        else
        {
            readDeltaFunction = deltaFunction;
        }

        bool     isValid        = true;
        uint32_t algorithmCheck = 0;

        // Prepare the stack for calculations.
        isValid = m_equationStack.reserve( equation->GetEquationElementsCount() );
        m_equationStack.clear();

        for( uint32_t i = 0; i < equation->GetEquationElementsCount() && isValid; i++ )
        {
            TEquationElement_1_0* element = equation->GetEquationElement( i );
            switch( element->Type )
            {
                case EQUATION_ELEM_RD_BITFIELD:

                    typedValuePrev.ValueUInt64 = ReadBitfield( pRawReportPrev + element->ReadParams.ByteOffset, element->ReadParams.BitOffset, element->ReadParams.BitsCount );
                    typedValuePrev.ValueType   = VALUE_TYPE_UINT64;

                    typedValueLast.ValueUInt64 = ReadBitfield( pRawReportLast + element->ReadParams.ByteOffset, element->ReadParams.BitOffset, element->ReadParams.BitsCount );
                    typedValueLast.ValueType   = VALUE_TYPE_UINT64;

                    typedValue = CalculateDeltaFunction( readDeltaFunction, typedValueLast, typedValuePrev );
                    isValid    = EquationStackPush( m_equationStack, typedValue, algorithmCheck );
                    break;

                case EQUATION_ELEM_RD_UINT8:
                    typedValuePrev.ValueUInt64 =
                        ( uint64_t ) * ( (const uint8_t*) ( pRawReportPrev + element->ReadParams.ByteOffset ) );
                    typedValuePrev.ValueType = VALUE_TYPE_UINT64;

                    typedValueLast.ValueUInt64 =
                        ( uint64_t ) * ( (const uint8_t*) ( pRawReportLast + element->ReadParams.ByteOffset ) );
                    typedValueLast.ValueType = VALUE_TYPE_UINT64;

                    typedValue = CalculateDeltaFunction( readDeltaFunction, typedValueLast, typedValuePrev );
                    isValid    = EquationStackPush( m_equationStack, typedValue, algorithmCheck );
                    break;

                case EQUATION_ELEM_RD_UINT16:
                    typedValuePrev.ValueUInt64 =
                        ( uint64_t ) * ( (const unsigned short*) ( pRawReportPrev + element->ReadParams.ByteOffset ) );
                    typedValuePrev.ValueType = VALUE_TYPE_UINT64;

                    typedValueLast.ValueUInt64 =
                        ( uint64_t ) * ( (const unsigned short*) ( pRawReportLast + element->ReadParams.ByteOffset ) );
                    typedValueLast.ValueType = VALUE_TYPE_UINT64;

                    typedValue = CalculateDeltaFunction( readDeltaFunction, typedValueLast, typedValuePrev );
                    isValid    = EquationStackPush( m_equationStack, typedValue, algorithmCheck );
                    break;

                case EQUATION_ELEM_RD_UINT32:
                    typedValuePrev.ValueUInt64 =
                        ( uint64_t ) * ( (const uint32_t*) ( pRawReportPrev + element->ReadParams.ByteOffset ) );
                    typedValuePrev.ValueType = VALUE_TYPE_UINT64;

                    typedValueLast.ValueUInt64 =
                        ( uint64_t ) * ( (const uint32_t*) ( pRawReportLast + element->ReadParams.ByteOffset ) );
                    typedValueLast.ValueType = VALUE_TYPE_UINT64;

                    typedValue = CalculateDeltaFunction( readDeltaFunction, typedValueLast, typedValuePrev );
                    isValid    = EquationStackPush( m_equationStack, typedValue, algorithmCheck );
                    break;

                case EQUATION_ELEM_RD_UINT64:
                    typedValuePrev.ValueUInt64 = *( (const uint64_t*) ( pRawReportPrev + element->ReadParams.ByteOffset ) );
                    typedValuePrev.ValueType   = VALUE_TYPE_UINT64;

                    typedValueLast.ValueUInt64 = *( (const uint64_t*) ( pRawReportLast + element->ReadParams.ByteOffset ) );
                    typedValueLast.ValueType   = VALUE_TYPE_UINT64;

                    typedValue = CalculateDeltaFunction( readDeltaFunction, typedValueLast, typedValuePrev );
                    isValid    = EquationStackPush( m_equationStack, typedValue, algorithmCheck );
                    break;

                case EQUATION_ELEM_RD_FLOAT:
                    typedValuePrev.ValueFloat = *( (const float*) ( pRawReportPrev + element->ReadParams.ByteOffset ) );
                    typedValuePrev.ValueType  = VALUE_TYPE_FLOAT;

                    typedValueLast.ValueFloat = *( (const float*) ( pRawReportLast + element->ReadParams.ByteOffset ) );
                    typedValueLast.ValueType  = VALUE_TYPE_FLOAT;

                    typedValue = CalculateDeltaFunction( readDeltaFunction, typedValueLast, typedValuePrev );
                    isValid    = EquationStackPush( m_equationStack, typedValue, algorithmCheck );
                    break;

                case EQUATION_ELEM_RD_40BIT_CNTR:
                {
                    TLargeInteger largeValue;
                    largeValue.u.LowPart       = *( (const uint32_t*) ( pRawReportPrev + element->ReadParams.ByteOffset ) );
                    largeValue.u.HighPart      = ( uint32_t ) * ( (const uint8_t*) ( pRawReportPrev + element->ReadParams.ByteOffsetExt ) );
                    typedValuePrev.ValueUInt64 = largeValue.QuadPart;
                    typedValuePrev.ValueType   = VALUE_TYPE_UINT64;

                    largeValue.u.LowPart       = *( (const uint32_t*) ( pRawReportLast + element->ReadParams.ByteOffset ) );
                    largeValue.u.HighPart      = ( uint32_t ) * ( (const uint8_t*) ( pRawReportLast + element->ReadParams.ByteOffsetExt ) );
                    typedValueLast.ValueUInt64 = largeValue.QuadPart;
                    typedValueLast.ValueType   = VALUE_TYPE_UINT64;

                    typedValue = CalculateDeltaFunction( readDeltaFunction, typedValueLast, typedValuePrev );
                    isValid    = EquationStackPush( m_equationStack, typedValue, algorithmCheck );
                    break;
                }

                case EQUATION_ELEM_IMM_UINT64:
                    typedValue.ValueUInt64 = element->ImmediateUInt64;
                    typedValue.ValueType   = VALUE_TYPE_UINT64;
                    isValid                = EquationStackPush( m_equationStack, typedValue, algorithmCheck );
                    break;

                case EQUATION_ELEM_IMM_FLOAT:
                    typedValue.ValueFloat = element->ImmediateFloat;
                    typedValue.ValueType  = VALUE_TYPE_FLOAT;
                    isValid               = EquationStackPush( m_equationStack, typedValue, algorithmCheck );
                    break;

                case EQUATION_ELEM_GLOBAL_SYMBOL:
                {
                    TTypedValue_1_0* pValue = GetGlobalSymbolValue( element->SymbolName );
                    if( pValue )
                    {
                        typedValue = *pValue;
                    }
                    else
                    {
                        typedValue.ValueUInt64 = 0LL;
                        typedValue.ValueType   = VALUE_TYPE_UINT64;
                    }
                    isValid = EquationStackPush( m_equationStack, typedValue, algorithmCheck );
                    break;
                }

                case EQUATION_ELEM_OPERATION:
                {
                    // Pop two values from stack
                    TTypedValue_1_0 valueLast = m_equationStack.top();
                    m_equationStack.pop();
                    algorithmCheck--;
                    TTypedValue_1_0 valuePrev = m_equationStack.top();
                    m_equationStack.pop();
                    algorithmCheck--;

                    typedValue = CalculateEquationElemOperation( element->Operation, valuePrev, valueLast );
                    isValid    = EquationStackPush( m_equationStack, typedValue, algorithmCheck );
                    break;
                }

                default:
                    MD_ASSERT( false );
                    break;
            }
        }
        // here should be only 1 element on the list - the result (if the equation is fine)
        MD_ASSERT( algorithmCheck == 1 );

        if( isValid && algorithmCheck == 1 )
        {
            typedValue = m_equationStack.top();
            m_equationStack.pop();
        }
        else
        {
            typedValue.ValueUInt64 = 0LL;
            typedValue.ValueType   = VALUE_TYPE_UINT64;
        }

        return typedValue;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculator
    //
    // Method:
    //     CalculateDeltaFunction
    //
    // Description:
    //     Calculates the given delta function.
    //
    // Input:
    //     TDeltaFunction_1_0     deltaFunction  - delta function to be calculated
    //     const TTypedValue_1_0& lastValue     - (IN) last (next) value
    //     const TTypedValue_1_0& previousValue - (IN) previous value
    //
    // Output:
    //     TTypedValue_1_0 - output calculated delta value
    //
    //////////////////////////////////////////////////////////////////////////////
    TTypedValue_1_0 CMetricsCalculator::CalculateDeltaFunction( TDeltaFunction_1_0 deltaFunction, const TTypedValue_1_0& lastValue, const TTypedValue_1_0& previousValue )
    {
        TTypedValue_1_0 typedValue;

        switch( deltaFunction.FunctionType )
        {
            case DELTA_BOOL_OR:
                typedValue.ValueUInt64 = ( ( lastValue.ValueUInt64 | previousValue.ValueUInt64 ) != 0 ) ? 1LL : 0LL;
                typedValue.ValueType   = VALUE_TYPE_UINT64;
                return typedValue;

            case DELTA_BOOL_XOR:
                typedValue.ValueUInt64 = ( ( lastValue.ValueUInt64 ^ previousValue.ValueUInt64 ) != 0 ) ? 1LL : 0LL;
                typedValue.ValueType   = VALUE_TYPE_UINT64;
                return typedValue;

            case DELTA_GET_LAST:
                return lastValue;

            case DELTA_GET_PREVIOUS:
                return previousValue;

            case DELTA_NS_TIME:
                // No 'break' intentional - NS_TIME should be used only for overflow functions, here use as DELTA 32
                deltaFunction.BitsCount = 32;

            case DELTA_N_BITS:
                if( deltaFunction.BitsCount <= 64 )
                {
                    if( previousValue.ValueUInt64 > lastValue.ValueUInt64 )
                    {
                        uint64_t value         = lastValue.ValueUInt64 | 1LL << deltaFunction.BitsCount;
                        typedValue.ValueUInt64 = value - previousValue.ValueUInt64;
                        typedValue.ValueType   = VALUE_TYPE_UINT64;
                        return typedValue;
                    }
                    else
                    {
                        typedValue.ValueUInt64 = lastValue.ValueUInt64 - previousValue.ValueUInt64;
                        typedValue.ValueType   = VALUE_TYPE_UINT64;
                        return typedValue;
                    }
                }
                break;

            case DELTA_FUNCTION_NULL:
                typedValue.ValueUInt64 = 0;
                typedValue.ValueType   = VALUE_TYPE_UINT64;
                return typedValue;

            default:
                MD_ASSERT( false );
                break;
        }

        typedValue.ValueUInt64 = 0;
        typedValue.ValueType   = VALUE_TYPE_UINT64;

        return typedValue;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculator
    //
    // Method:
    //     CalculateLocalNormalizationEquation
    //
    // Description:
    //     Calculates the given normalization equation.
    //
    // Input:
    //     IEquation_1_0*   equation         - (IN) normalization equation to be calculated
    //     TTypedValue_1_0* deltaValues      - (IN) previously calculated / read delta values
    //     TTypedValue_1_0* outValues        - (IN) so far normalized values (metrics with lower indices)
    //     IMetricSet_1_1*  metricSet        - MetricSet for calculation
    //     uint32_t         currentMetricIdx - index of the currently calculated metric
    //
    // Output:
    //     TTypedValue_1_0 - output normalized value
    //
    //////////////////////////////////////////////////////////////////////////////
    TTypedValue_1_0 CMetricsCalculator::CalculateLocalNormalizationEquation( IEquation_1_0* equation, TTypedValue_1_0* deltaValues, TTypedValue_1_0* outValues, IMetricSet_1_1* metricSet, uint32_t currentMetricIdx )
    {
        TTypedValue_1_0 typedValue;
        bool            isValid        = true;
        uint32_t        algorithmCheck = 0;

        // Prepare the stack for calculations.
        isValid = m_equationStack.reserve( equation->GetEquationElementsCount() );
        m_equationStack.clear();

        for( uint32_t i = 0; i < equation->GetEquationElementsCount() && isValid; i++ )
        {
            TEquationElement_1_0* element = equation->GetEquationElement( i );
            switch( element->Type )
            {
                case EQUATION_ELEM_RD_BITFIELD:
                case EQUATION_ELEM_RD_UINT8:
                case EQUATION_ELEM_RD_UINT16:
                case EQUATION_ELEM_RD_UINT32:
                case EQUATION_ELEM_RD_UINT64:
                case EQUATION_ELEM_RD_FLOAT:
                case EQUATION_ELEM_RD_40BIT_CNTR:
                    // Not allowed in norm equation
                    break;

                case EQUATION_ELEM_IMM_FLOAT:
                    typedValue.ValueFloat = element->ImmediateFloat;
                    typedValue.ValueType  = VALUE_TYPE_FLOAT;
                    isValid               = EquationStackPush( m_equationStack, typedValue, algorithmCheck );
                    break;

                case EQUATION_ELEM_IMM_UINT64:
                    typedValue.ValueUInt64 = element->ImmediateUInt64;
                    typedValue.ValueType   = VALUE_TYPE_UINT64;
                    isValid                = EquationStackPush( m_equationStack, typedValue, algorithmCheck );
                    break;

                case EQUATION_ELEM_SELF_COUNTER_VALUE:
                    // Get result of delta equation
                    typedValue = deltaValues[currentMetricIdx];
                    isValid    = EquationStackPush( m_equationStack, typedValue, algorithmCheck );
                    break;

                case EQUATION_ELEM_LOCAL_COUNTER_SYMBOL:
                {
                    // Cast to get access to MetricsIndexInternal variable
                    CEquationElementInternal* internalElement = (CEquationElementInternal*) element;

                    // The index is higher than or equals 0 if the symbol name was found, otherwise it equals -1
                    if( internalElement->MetricIndexInternal >= 0 )
                    {
                        typedValue = deltaValues[internalElement->MetricIndexInternal];
                    }
                    else
                    {
                        typedValue.ValueUInt64 = 0;
                        typedValue.ValueType   = VALUE_TYPE_UINT64;
                    }

                    isValid = EquationStackPush( m_equationStack, typedValue, algorithmCheck );
                    break;
                }

                case EQUATION_ELEM_LOCAL_METRIC_SYMBOL:
                {
                    // Cast to get access to MetricsIndexInternal variable
                    CEquationElementInternal* internalElement = (CEquationElementInternal*) element;

                    // The index is higher than or equals 0 if the symbol name was found, otherwise it equals -1
                    if( internalElement->MetricIndexInternal >= 0 )
                    {
                        typedValue = outValues[internalElement->MetricIndexInternal];
                    }
                    else
                    {
                        typedValue.ValueUInt64 = 0;
                        typedValue.ValueType   = VALUE_TYPE_UINT64;
                    }

                    isValid = EquationStackPush( m_equationStack, typedValue, algorithmCheck );
                    break;
                }

                case EQUATION_ELEM_GLOBAL_SYMBOL:
                {
                    TTypedValue_1_0* pValue = GetGlobalSymbolValue( element->SymbolName );
                    if( pValue )
                    {
                        typedValue = *pValue;
                    }
                    else
                    {
                        typedValue.ValueUInt64 = 0;
                        typedValue.ValueType   = VALUE_TYPE_UINT64;
                    }
                    isValid = EquationStackPush( m_equationStack, typedValue, algorithmCheck );
                    break;
                }

                case EQUATION_ELEM_OPERATION:
                {
                    //pop two values from stack
                    TTypedValue_1_0 valueLast = m_equationStack.top();
                    m_equationStack.pop();
                    algorithmCheck--;
                    TTypedValue_1_0 valuePrev = m_equationStack.top();
                    m_equationStack.pop();
                    algorithmCheck--;

                    typedValue = CalculateEquationElemOperation( element->Operation, valuePrev, valueLast );
                    isValid    = EquationStackPush( m_equationStack, typedValue, algorithmCheck );
                    break;
                }

                case EQUATION_ELEM_STD_NORM_GPU_DURATION:
                    //equation stack should be empty
                    MD_ASSERT( algorithmCheck == 0 );

                    //compute $Self $gpuCoreClocks FDIV 100 FMUL
                    if( m_gpuCoreClocks != 0 )
                    {
                        float self          = CastToFloat( deltaValues[currentMetricIdx] );
                        float gpuCoreClocks = (float) m_gpuCoreClocks;

                        typedValue.ValueFloat = 100.0f * self / gpuCoreClocks;
                        typedValue.ValueType  = VALUE_TYPE_FLOAT;
                        return typedValue;
                    }
                    else
                    {
                        // Warning: GpuCoreClocks is 0
                        typedValue.ValueFloat = 0.0f;
                        typedValue.ValueType  = VALUE_TYPE_FLOAT;
                        return typedValue;
                    }

                case EQUATION_ELEM_STD_NORM_EU_AGGR_DURATION:
                    //equation stack should be empty
                    MD_ASSERT( algorithmCheck == 0 );

                    //compute $Self $gpuCoreClocks $EUsCount UMUL FDIV 100 FMUL
                    if( m_gpuCoreClocks != 0 )
                    {
                        float self          = CastToFloat( deltaValues[currentMetricIdx] );
                        float gpuCoreClocks = (float) ( m_gpuCoreClocks * m_euCoresCount );

                        typedValue.ValueFloat = 100.0f * self / gpuCoreClocks;
                        typedValue.ValueType  = VALUE_TYPE_FLOAT;
                        return typedValue;
                    }
                    else
                    {
                        // Warning: GpuCoreClocks is 0
                        typedValue.ValueFloat = 0.0f;
                        typedValue.ValueType  = VALUE_TYPE_FLOAT;
                        return typedValue;
                    }

                default:
                    break;
            }
        }
        // here should be only 1 element on the list - the result (if the equation is fine)
        MD_ASSERT( algorithmCheck == 1 );

        if( isValid && algorithmCheck == 1 )
        {
            typedValue = m_equationStack.top();
            m_equationStack.pop();
        }
        else
        {
            typedValue.ValueUInt64 = 0;
            typedValue.ValueType   = VALUE_TYPE_UINT64;
        }

        return typedValue;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculator
    //
    // Method:
    //     CalculateEquationElemOperation
    //
    // Description:
    //     Calculates the given equation operation.
    //
    // Input:
    //     TEquationOperation     operation - operation to be calculated
    //     const TTypedValue_1_0& valuePrev - (IN) previous value
    //     const TTypedValue_1_0& valueLast - (IN) last (next) value
    //
    // Output:
    //     TTypedValue_1_0 - output calculated value
    //
    //////////////////////////////////////////////////////////////////////////////
    TTypedValue_1_0 CMetricsCalculator::CalculateEquationElemOperation( TEquationOperation operation, const TTypedValue_1_0& valuePrev, const TTypedValue_1_0& valueLast )
    {
        TTypedValue_1_0 value;
        value.ValueUInt64 = 0;
        value.ValueType   = VALUE_TYPE_UINT64;

        switch( operation )
        {
            case EQUATION_OPER_AND:
                value.ValueUInt64 = CastToUInt64( valuePrev ) & CastToUInt64( valueLast );
                value.ValueType   = VALUE_TYPE_UINT64;
                break;

            case EQUATION_OPER_OR:
                value.ValueUInt64 = CastToUInt64( valuePrev ) | CastToUInt64( valueLast );
                value.ValueType   = VALUE_TYPE_UINT64;
                break;

            case EQUATION_OPER_RSHIFT:
                value.ValueUInt64 = CastToUInt64( valuePrev ) >> CastToUInt64( valueLast );
                value.ValueType   = VALUE_TYPE_UINT64;
                break;

            case EQUATION_OPER_LSHIFT:
                value.ValueUInt64 = CastToUInt64( valuePrev ) << CastToUInt64( valueLast );
                value.ValueType   = VALUE_TYPE_UINT64;
                break;

            case EQUATION_OPER_XOR:
                value.ValueUInt64 = CastToUInt64( valuePrev ) ^ CastToUInt64( valueLast );
                value.ValueType   = VALUE_TYPE_UINT64;
                break;

            case EQUATION_OPER_XNOR:
                value.ValueUInt64 = ~( CastToUInt64( valuePrev ) ^ CastToUInt64( valueLast ) );
                value.ValueType   = VALUE_TYPE_UINT64;
                break;

            case EQUATION_OPER_AND_L:
                value.ValueBool = CastToUInt64( valuePrev ) && CastToUInt64( valueLast );
                value.ValueType = VALUE_TYPE_BOOL;
                break;

            case EQUATION_OPER_EQUALS:
                value.ValueBool = CastToUInt64( valuePrev ) == CastToUInt64( valueLast );
                value.ValueType = VALUE_TYPE_BOOL;
                break;

            case EQUATION_OPER_UADD:
                value.ValueUInt64 = CastToUInt64( valuePrev ) + CastToUInt64( valueLast );
                value.ValueType   = VALUE_TYPE_UINT64;
                break;

            case EQUATION_OPER_USUB:
                value.ValueUInt64 = CastToUInt64( valuePrev ) - CastToUInt64( valueLast );
                value.ValueType   = VALUE_TYPE_UINT64;
                break;

            case EQUATION_OPER_UDIV:
                if( CastToUInt64( valueLast ) != 0LL )
                {
                    value.ValueUInt64 = CastToUInt64( valuePrev ) / CastToUInt64( valueLast );
                    value.ValueType   = VALUE_TYPE_UINT64;
                }
                else
                {
                    value.ValueUInt64 = 0ULL;
                    value.ValueType   = VALUE_TYPE_UINT64;
                }
                break;

            case EQUATION_OPER_UMUL:
                value.ValueUInt64 = CastToUInt64( valuePrev ) * CastToUInt64( valueLast );
                value.ValueType   = VALUE_TYPE_UINT64;
                break;

            case EQUATION_OPER_FADD:
                value.ValueFloat = CastToFloat( valuePrev ) + CastToFloat( valueLast );
                value.ValueType  = VALUE_TYPE_FLOAT;
                break;

            case EQUATION_OPER_FSUB:
                value.ValueFloat = CastToFloat( valuePrev ) - CastToFloat( valueLast );
                value.ValueType  = VALUE_TYPE_FLOAT;
                break;

            case EQUATION_OPER_FMUL:
                value.ValueFloat = CastToFloat( valuePrev ) * CastToFloat( valueLast );
                value.ValueType  = VALUE_TYPE_FLOAT;
                break;

            case EQUATION_OPER_FDIV:
                if( CastToFloat( valueLast ) != 0LL )
                {
                    value.ValueFloat = CastToFloat( valuePrev ) / CastToFloat( valueLast );
                    value.ValueType  = VALUE_TYPE_FLOAT;
                }
                else
                {
                    value.ValueFloat = 0.0f;
                    value.ValueType  = VALUE_TYPE_FLOAT;
                }
                break;

            case EQUATION_OPER_UGT:
                value.ValueBool = CastToUInt64( valuePrev ) > CastToUInt64( valueLast );
                value.ValueType = VALUE_TYPE_BOOL;
                break;

            case EQUATION_OPER_ULT:
                value.ValueBool = CastToUInt64( valuePrev ) < CastToUInt64( valueLast );
                value.ValueType = VALUE_TYPE_BOOL;
                break;

            case EQUATION_OPER_UGTE:
                value.ValueBool = CastToUInt64( valuePrev ) >= CastToUInt64( valueLast );
                value.ValueType = VALUE_TYPE_BOOL;
                break;

            case EQUATION_OPER_ULTE:
                value.ValueBool = CastToUInt64( valuePrev ) <= CastToUInt64( valueLast );
                value.ValueType = VALUE_TYPE_BOOL;
                break;

            case EQUATION_OPER_FGT:
                value.ValueBool = CastToFloat( valuePrev ) > CastToFloat( valueLast );
                value.ValueType = VALUE_TYPE_BOOL;
                break;

            case EQUATION_OPER_FLT:
                value.ValueBool = CastToFloat( valuePrev ) < CastToFloat( valueLast );
                value.ValueType = VALUE_TYPE_BOOL;
                break;

            case EQUATION_OPER_FGTE:
                value.ValueBool = CastToFloat( valuePrev ) >= CastToFloat( valueLast );
                value.ValueType = VALUE_TYPE_BOOL;
                break;

            case EQUATION_OPER_FLTE:
                value.ValueBool = CastToFloat( valuePrev ) <= CastToFloat( valueLast );
                value.ValueType = VALUE_TYPE_BOOL;
                break;

            case EQUATION_OPER_UMIN:
                // (std::min) - braces to bypass windows.h min/max errors
                value.ValueUInt64 = ( std::min )( CastToUInt64( valuePrev ), CastToUInt64( valueLast ) );
                value.ValueType   = VALUE_TYPE_UINT64;
                break;

            case EQUATION_OPER_UMAX:
                // (std::min) - braces to bypass windows.h min/max errors
                value.ValueUInt64 = ( std::max )( CastToUInt64( valuePrev ), CastToUInt64( valueLast ) );
                value.ValueType   = VALUE_TYPE_UINT64;
                break;

            case EQUATION_OPER_FMIN:
                // (std::min) - braces to bypass windows.h min/max errors
                value.ValueFloat = ( std::min )( CastToFloat( valuePrev ), CastToFloat( valueLast ) );
                value.ValueType  = VALUE_TYPE_FLOAT;
                break;

            case EQUATION_OPER_FMAX:
                // (std::min) - braces to bypass windows.h min/max errors
                value.ValueFloat = ( std::max )( CastToFloat( valuePrev ), CastToFloat( valueLast ) );
                value.ValueType  = VALUE_TYPE_FLOAT;
                break;

            default:
                value.ValueUInt64 = 0;
                value.ValueType   = VALUE_TYPE_UINT64;
                break;
        }

        return value;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculator
    //
    // Method:
    //     ReadSingleInformation
    //
    // Description:
    //     Reads single information.
    //
    // Input:
    //     const uint8_t*    rawReport   - single raw report
    //     IInformation_1_0* information - information to calculate
    //     uint32_t          apiMask     - API mask (needed for choosing proper equation)
    //     TTypedValue_1_0*  outValue    - (OUT) read information value
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetricsCalculator::ReadSingleInformation( const uint8_t* rawReport, IInformation_1_0* information, uint32_t apiMask, TTypedValue_1_0* outValue )
    {
        if( !rawReport || !information || !outValue )
        {
            MD_ASSERT( rawReport != NULL );
            MD_ASSERT( information != NULL );
            MD_ASSERT( outValue != NULL );
            MD_LOG( LOG_ERROR, "error: null params" );
            return;
        }

        uint32_t                streamMask        = API_TYPE_IOSTREAM | API_TYPE_BBSTREAM;
        TInformationParams_1_0* informationParams = information->GetParams();
        IEquation_1_0*          equation          = ( apiMask & streamMask ) ? informationParams->IoReadEquation : informationParams->QueryReadEquation;

        if( equation )
        {
            *outValue = CalculateReadEquation( equation, rawReport );
        }
        else
        {
            outValue->ValueUInt64 = 0ULL;
        }

        if( informationParams->InfoType == INFORMATION_TYPE_FLAG )
        {
            outValue->ValueType = VALUE_TYPE_BOOL;
        }
        else
        {
            outValue->ValueType = VALUE_TYPE_UINT64;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculator
    //
    // Method:
    //     CastToUInt64
    //
    // Description:
    //     Casts data to uint64.
    //
    // Input:
    //     const TTypedValue_1_0& value - typed value to cast
    //
    // Output:
    //     uint64_t - cast uint64 value
    //
    //////////////////////////////////////////////////////////////////////////////
    uint64_t CMetricsCalculator::CastToUInt64( const TTypedValue_1_0& value )
    {
        switch( value.ValueType )
        {
            case VALUE_TYPE_BOOL:
                return ( value.ValueBool ) ? 1LL : 0LL;

            case VALUE_TYPE_UINT32:
                return (uint64_t) value.ValueUInt32;

            case VALUE_TYPE_UINT64:
                return value.ValueUInt64;

            case VALUE_TYPE_FLOAT:
                return (uint64_t) value.ValueFloat;
            default:
                return 0LL;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculator
    //
    // Method:
    //     CastToFloat
    //
    // Description:
    //     Casts data to float.
    //
    // Input:
    //     const TTypedValue_1_0& value - typed value to cast
    //
    // Output:
    //     float - cast float value
    //
    //////////////////////////////////////////////////////////////////////////////
    float CMetricsCalculator::CastToFloat( const TTypedValue_1_0& value )
    {
        switch( value.ValueType )
        {
            case VALUE_TYPE_BOOL:
                return ( value.ValueBool ) ? 1.0f : 0.0f;

            case VALUE_TYPE_UINT32:
                return (float) value.ValueUInt32;

            case VALUE_TYPE_UINT64:
                return (float) value.ValueUInt64;

            case VALUE_TYPE_FLOAT:
                return value.ValueFloat;
            default:
                return 0.0f;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculator
    //
    // Method:
    //     ReadBitfield
    //
    // Description:
    //     Reads specified bitfield from a report.
    //
    // Input:
    //     const uint8_t* rawReport - single raw report data
    //     uint32_t       bitOffset - field offset
    //     uint32_t       bitCount  - bit count to read
    //
    // Output:
    //     uint64_t - read value
    //
    //////////////////////////////////////////////////////////////////////////////
    uint64_t CMetricsCalculator::ReadBitfield( const uint8_t* rawReport, uint32_t bitOffset, uint32_t bitCount )
    {
        if( !rawReport || ( bitCount > 32 ) || ( bitCount == 0 ) || ( bitCount + bitOffset > 32 ) )
        {
            MD_ASSERT( false );
            MD_LOG( LOG_ERROR, "error: invalid params" );
            return 0;
        }

        // Build mask
        uint32_t mask = MD_BITMASK_RANGE( bitOffset, bitOffset + bitCount );

        // Get integer in the way in is alignment safe
        uint32_t data = ( *rawReport ) | ( ( *( rawReport + 1 ) ) << 8 ) | ( ( *( rawReport + 2 ) ) << 16 ) | ( ( *( rawReport + 3 ) ) << 24 );

        return ( uint64_t )( ( data & mask ) >> bitOffset );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricsCalculator
    //
    // Method:
    //     GetGlobalSymbolValue
    //
    // Description:
    //     Returns global symbol of a given name. Uses MetricsDevice.
    //
    // Input:
    //     const char* symbolName - global symbol name
    //
    // Output:
    //     TTypedValue_1_0* - global symbol typed value, null if error
    //
    //////////////////////////////////////////////////////////////////////////////
    TTypedValue_1_0* CMetricsCalculator::GetGlobalSymbolValue( const char* symbolName )
    {
        MD_CHECK_PTR_RET( m_device, NULL );
        MD_CHECK_PTR_RET( symbolName, NULL );

        for( uint32_t i = 0; i < m_device->GetParams()->GlobalSymbolsCount; i++ )
        {
            TGlobalSymbol_1_0* symbol = m_device->GetGlobalSymbol( i );
            if( symbol && strcmp( symbol->SymbolName, symbolName ) == 0 )
            {
                return &( symbol->SymbolTypedValue );
            }
        }
        return NULL;
    }

} // namespace MetricsDiscoveryInternal
