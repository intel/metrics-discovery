/*========================== begin_copyright_notice ============================

Copyright (C) 2026 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_calculation_context.h

//     Abstract:   C++ Metrics Discovery internal calculation context header

#pragma once

#include "metrics_discovery_internal_api.h"
#include "md_calculation.h"

#include <string_view>

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    ///////////////////////////////////////////////////////////////////////////////
    // Forward declarations:                                                     //
    ///////////////////////////////////////////////////////////////////////////////
    class CCalculationManager;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Description:
    //     Calculation context class.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CCalculationContext : public ICalculationContextLatest
    {
    public:
        // API 1.16:
        virtual const TCalculationContextParamsLatest* GetParams( void ) const final;
        virtual IMetricLatest*                         GetMetric( uint32_t index ) final;
        virtual IInformationLatest*                    GetInformation( uint32_t index ) final;

        virtual TCompletionCode AggregateData( const uint8_t** rawData, const uint32_t* rawDataSizes, uint8_t* outAggregatedRawData, uint32_t* outAggregatedRawDataSize, bool lastDataPortion ) final;
        virtual TCompletionCode CalculateMetrics( const uint8_t* rawData, uint32_t rawDataSize, TTypedValue_1_0* out, uint32_t outSize, uint32_t* outReportCount, TTypedValue_1_0* outMaxValues, uint32_t outMaxValuesSize ) final;
        virtual TCompletionCode CalculateSingleWindowMetrics( const uint8_t** rawData, const uint32_t* rawDataSizes, uint32_t* outProcessedRawDataCount, TTypedValue_1_0* out, uint32_t outSize, TTypedValue_1_0* outMaxValues, uint32_t outMaxValuesSize, bool lastDataPortion ) final;

        //  Constructor & Destructor:
        CCalculationContext();
        virtual ~CCalculationContext();

        TCompletionCode Initialize( TCalculationContextDescriptorLatest& calculationContextDescriptor );

        static TCompletionCode ValidateCalculationContextDescriptor( TCalculationContextDescriptorLatest& calculationContextDescriptor );

    private:
        CCalculationContext( const CCalculationContext& )            = delete; // Delete copy-constructor
        CCalculationContext& operator=( const CCalculationContext& ) = delete; // Delete assignment operator

        TCompletionCode        AggregateSingleWindow( const uint8_t** rawData, const uint32_t* rawDataSizes, uint8_t* outAggregatedRawData, uint32_t* outProcessedRawDataCount, bool lastDataPortion );
        TCompletionCode        AggregateStreamData( const uint8_t** rawData, const uint32_t* rawDataSizes, uint8_t* outAggregatedRawData, uint32_t* outAggregatedRawDataSize, bool lastDataPortion );
        void                   InitializeCalculationManager( const bool init );
        TCompletionCode        InitializeCalculationContext( const bool init );
        TCompletionCode        InitializeAggregationContext( const bool init );
        void                   DestroyContexts();
        TCompletionCode        CreateInternalMetricSet( CMetricSet* baseMetricSet );
        TCompletionCode        ValidateCalculateMetricsParams( TMetricSetParamsLatest* params, uint32_t rawDataSize, uint32_t rawReportSize, uint32_t outSize, uint32_t rawReportCount, uint32_t outMaxValuesSize );
        static TCompletionCode AreMetricsEqual( TMetricParamsLatest* baseParams, TMetricParamsLatest* metricParams, TCalculationContextType calculationContextType );
        static TCompletionCode ValidateApiMask( TCalculationContextType calculationContextType, uint32_t apiMask );
        static TCompletionCode ValidateTimeWindows( TCalculationContextDescriptorLatest& calculationContextDescriptor );
        static TCompletionCode ValidateMetricEquations( IEquationLatest* baseEquation, IEquationLatest* metricEquation );
        static TCompletionCode ValidateMetricParams( const char* baseValue, const char* metricValue, const char* fieldName );
        template <typename T>
        static TCompletionCode ValidateMetricParams( const T& baseValue, const T& metricValue, const char* fieldName );
        template <bool timerMode>
        bool            EnsureDataAtTimestamp( uint64_t timestamp );
        TCompletionCode FilterReport( uint32_t dataSetIndex, bool isTimerMode );
        uint64_t        GetMaxCurrentTimestamp() const;
        uint64_t        GetMinCurrentTimestamp() const;
        bool            IsEnoughData() const;
        void            UpdateAggregationWindowStop();
        void            Interpolate( uint64_t timestamp );
        TCompletionCode CacheRemainingReports();

    private:
        // Members:
        CCalculationManager*              m_calculationManager;
        TCalculationContext               m_calculationContext;
        TAggregationContext               m_aggregationContext;
        CMetricSet*                       m_metricSet;
        CMetricSet*                       m_baseMetricSet;
        TCalculationContextParamsLatest   m_params;
        TCalculationContextType           m_type;
        uint32_t                          m_dataSetCount;
        int64_t*                          m_timeOffsets;
        bool                              m_aggregationEnabled;
        TCalculationContextState          m_state;
        TCalculationContextStateTimerMode m_timerModeState;
    };
} // namespace MetricsDiscoveryInternal
