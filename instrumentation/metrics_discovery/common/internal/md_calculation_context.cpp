/*========================== begin_copyright_notice ============================

Copyright (C) 2026 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_calculation_context.cpp

//     Abstract:   C++ Metrics Discovery internal calculation context implementation

#include "md_calculation_context.h"
#include "md_metrics_device.h"
#include "md_concurrent_group.h"
#include "md_metric_set.h"
#include "md_metrics_calculator.h"
#include "md_utils.h"

#include <functional>

namespace MetricsDiscoveryInternal
{
    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     CCalculationContext
    //
    // Description:
    //     Constructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    CCalculationContext::CCalculationContext()
        : m_metricsCalculator( nullptr )
        , m_calculationManager( nullptr )
        , m_calculationContext{}
        , m_aggregationContext{}
        , m_metricSet( nullptr )
        , m_baseMetricSet( nullptr )
        , m_params{}
        , m_type( CALCULATION_CONTEXT_TYPE_LAST )
        , m_dataSetCount( 0 )
        , m_timeOffsets( nullptr )
        , m_aggregationEnabled( false )
        , m_state( CALCULATION_CONTEXT_STATE_INITIAL )
        , m_timerModeState( CALCULATION_CONTEXT_STATE_TIMER_MODE_INITIAL )
    {
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     ~CCalculationContext
    //
    // Description:
    //     Destructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    CCalculationContext::~CCalculationContext()
    {
        MD_LOG_ENTER();

        DestroyContexts();

        MD_SAFE_DELETE_ARRAY( m_timeOffsets );
        MD_SAFE_DELETE( m_calculationManager );
        MD_SAFE_DELETE( m_metricsCalculator );
        MD_SAFE_DELETE( m_metricSet );

        MD_LOG_EXIT();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     GetParams
    //
    // Description:
    //     Returns calculation context params.
    //
    // Output:
    //     const TCalculationContextParamsLatest* - calculation context params
    //
    //////////////////////////////////////////////////////////////////////////////
    const TCalculationContextParamsLatest* CCalculationContext::GetParams( void ) const
    {
        return &m_params;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     GetMetricsCalculator
    //
    // Description:
    //     Returns metrics calculator.
    //
    // Output:
    //     CMetricsCalculator* - metrics calculator or *nullptr* if error
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricsCalculator* CCalculationContext::GetMetricsCalculator()
    {
        return m_metricsCalculator;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     GetApiMask
    //
    // Description:
    //     Returns the filtered API mask the context was built with.
    //
    // Output:
    //     uint32_t - filtered API mask
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CCalculationContext::GetApiMask() const
    {
        return m_metricSet ? m_metricSet->GetParams()->ApiMask : 0;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     GetType
    //
    // Description:
    //     Returns the calculation context type the context was built with.
    //
    // Output:
    //     TCalculationContextType - calculation context type
    //
    //////////////////////////////////////////////////////////////////////////////
    TCalculationContextType CCalculationContext::GetType() const
    {
        return m_type;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     GetMetric
    //
    // Description:
    //     Returns the chosen metric or nullptr if the index is out of range.
    //
    // Input:
    //     uint32_t index - index of a metric
    //
    // Output:
    //     IMetricLatest* - chosen metric or nullptr
    //
    //////////////////////////////////////////////////////////////////////////////
    IMetricLatest* CCalculationContext::GetMetric( uint32_t index )
    {
        return m_metricSet->GetMetric( index );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     GetInformation
    //
    // Description:
    //     Returns the chosen information or nullptr if the index is out of range.
    //
    // Input:
    //     uint32_t index      - index of an information
    //
    // Output:
    //     IInformationLatest* - chosen information or nullptr
    //
    //////////////////////////////////////////////////////////////////////////////
    IInformationLatest* CCalculationContext::GetInformation( uint32_t index )
    {
        return m_metricSet->GetInformation( index );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     DestroyContexts
    //
    // Description:
    //     Releases all dynamically allocated memory and resets the fields
    //     of the provided calculation context to their default values.
    //     This function is used to clean up the context before reuse or
    //     destruction, ensuring no memory leaks or dangling pointers remain.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CCalculationContext::DestroyContexts()
    {
        MD_SAFE_DELETE_ARRAY( m_calculationContext.CommonCalculationContext.DeltaValues );
        MD_SAFE_DELETE_ARRAY( m_aggregationContext.CommonAggregationContext.RawData );
        MD_SAFE_DELETE_ARRAY( m_aggregationContext.CommonAggregationContext.RawReportCount );
        MD_SAFE_DELETE_ARRAY( m_aggregationContext.CommonAggregationContext.OutReportCount );

        if( m_type == CALCULATION_CONTEXT_TYPE_IO_STREAM )
        {
            if( m_aggregationContext.StreamAggregationContext.InterpolatedReportPtrs )
            {
                for( uint32_t i = 0; i < m_aggregationContext.CommonAggregationContext.DataSetCount; ++i )
                {
                    MD_SAFE_DELETE_ARRAY( m_aggregationContext.StreamAggregationContext.InterpolatedReportPtrs[i] );
                }
            }

            if( m_aggregationContext.StreamAggregationContext.CachedReportPtrsBase )
            {
                for( uint32_t i = 0; i < m_aggregationContext.CommonAggregationContext.DataSetCount; ++i )
                {
                    MD_SAFE_DELETE_ARRAY( m_aggregationContext.StreamAggregationContext.CachedReportPtrsBase[i] );
                }
            }

            if( m_aggregationContext.StreamAggregationContext.PrevSavedReportPtrs )
            {
                for( uint32_t i = 0; i < m_aggregationContext.CommonAggregationContext.DataSetCount; ++i )
                {
                    MD_SAFE_DELETE_ARRAY( m_aggregationContext.StreamAggregationContext.PrevSavedReportPtrs[i] );
                }
            }

            if( m_aggregationContext.StreamAggregationContext.LastSavedReportPtrs )
            {
                for( uint32_t i = 0; i < m_aggregationContext.CommonAggregationContext.DataSetCount; ++i )
                {
                    MD_SAFE_DELETE_ARRAY( m_aggregationContext.StreamAggregationContext.LastSavedReportPtrs[i] );
                }
            }

            MD_SAFE_DELETE_ARRAY( m_aggregationContext.StreamAggregationContext.TimeWindows );
            MD_SAFE_DELETE_ARRAY( m_aggregationContext.StreamAggregationContext.LastRawDataPtrs );
            MD_SAFE_DELETE_ARRAY( m_aggregationContext.StreamAggregationContext.PrevRawDataPtrs );
            MD_SAFE_DELETE_ARRAY( m_aggregationContext.StreamAggregationContext.PrevSavedReportPtrs );
            MD_SAFE_DELETE_ARRAY( m_aggregationContext.StreamAggregationContext.LastSavedReportPtrs );
            MD_SAFE_DELETE_ARRAY( m_aggregationContext.StreamAggregationContext.CachedReportPtrsBase );
            MD_SAFE_DELETE_ARRAY( m_aggregationContext.StreamAggregationContext.CachedReportPtrs );
            MD_SAFE_DELETE_ARRAY( m_aggregationContext.StreamAggregationContext.InterpolatedReportPtrs );
            MD_SAFE_DELETE_ARRAY( m_aggregationContext.StreamAggregationContext.OutAggregatedRawDataPtr );
            MD_SAFE_DELETE_ARRAY( m_aggregationContext.StreamAggregationContext.CurrentTs );
            MD_SAFE_DELETE_ARRAY( m_aggregationContext.StreamAggregationContext.NeedReport );
            MD_SAFE_DELETE_ARRAY( m_aggregationContext.StreamAggregationContext.IsCachedReport );
            MD_SAFE_DELETE_ARRAY( m_aggregationContext.StreamAggregationContext.CachedReportPtrsSize );
            MD_SAFE_DELETE_ARRAY( m_aggregationContext.StreamAggregationContext.IsPrevRawDataPresent );
            MD_SAFE_DELETE_ARRAY( m_aggregationContext.StreamAggregationContext.IsLastRawDataPresent );
            MD_SAFE_DELETE_ARRAY( m_aggregationContext.StreamAggregationContext.SkipReportAfterRc6 );
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     Initialize
    //
    // Description:
    //     Initializes the calculation context for metrics calculations.
    //     This method sets up the calculation manager and calculation context
    //     based on the provided calculation context descriptor. It determines
    //     the measurement type (IO stream or delta query) from the metric set
    //     parameters, allocates and initializes the calculation manager, and
    //     prepares the calculation context for use. If initialization fails,
    //     it ensures proper cleanup of allocated resources.
    //
    // Input:
    //     TCalculationContextDescriptorLatest& calculationContextDescriptor - Reference to the calculation context descriptor
    //                                                                         containing metric sets and configuration information.
    //
    // Output:
    //     TCompletionCode - *CC_OK* on success, or an appropriate error code on failure.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CCalculationContext::Initialize( TCalculationContextDescriptorLatest& calculationContextDescriptor )
    {
        MD_LOG_ENTER();

        m_aggregationEnabled =
            calculationContextDescriptor.DataSetCount > 1 ||                             // Aggregation across sub devices.
            calculationContextDescriptor.IoStreamDescriptor.NsTimeAggregationWindow > 0; // Aggregation over time.

        m_type         = calculationContextDescriptor.Type;
        m_dataSetCount = calculationContextDescriptor.DataSetCount;

        auto ret = CreateInternalMetricSet( (CMetricSet*) calculationContextDescriptor.MetricSets[0] );
        MD_CHECK_CC_RET( ret );

        std::vector<std::reference_wrapper<CMetricsDevice>> devices;

        for( uint32_t i = 0; i < m_dataSetCount; ++i )
        {
            auto& device = ( (CMetricSet*) calculationContextDescriptor.MetricSets[i] )->GetMetricsDevice();
            devices.push_back( device );
        }

        ret = InitializeMetricsCalculator( devices );
        MD_CHECK_CC_RET( ret );

        InitializeCalculationManager( true );
        MD_CHECK_PTR_RET( m_calculationManager, CC_ERROR_NO_MEMORY );

        if( m_aggregationEnabled )
        {
            ret = InitializeAggregationContext( true );
            if( ret != CC_OK )
            {
                InitializeCalculationManager( false );
            }
        }

        if( ret == CC_OK )
        {
            ret = InitializeCalculationContext( true );
            if( ret != CC_OK )
            {
                if( m_aggregationEnabled )
                {
                    InitializeAggregationContext( false );
                }
                InitializeCalculationManager( false );
            }
        }

        MD_CHECK_CC_RET( ret );

        TStreamAggregationContext& sa = m_aggregationContext.StreamAggregationContext;

        if( m_type == CALCULATION_CONTEXT_TYPE_IO_STREAM &&
            ( calculationContextDescriptor.IoStreamDescriptor.TimeWindowCount > 0 || m_aggregationEnabled ) )
        {
            sa.TimeWindowCount = calculationContextDescriptor.IoStreamDescriptor.TimeWindowCount;

            auto& device = devices[0].get();

            TTypedValueLatest* freqValue = {};
            freqValue                    = device.GetGlobalSymbolValueByName( "GpuTimestampFrequency" );

            MD_CHECK_PTR_RET( freqValue, CC_ERROR_INVALID_PARAMETER );

            const uint64_t gpuTimestampFrequency = freqValue->ValueUInt32;

            if( sa.TimeWindowCount > 0 )
            {
                sa.TimeWindows = new( std::nothrow ) TTimeWindowLatest[sa.TimeWindowCount];
                MD_CHECK_PTR_RET( sa.TimeWindows, CC_ERROR_NO_MEMORY );

                // Convert each time window from ns to GPU timestamp ticks
                for( uint32_t i = 0; i < sa.TimeWindowCount; ++i )
                {
                    const TTimeWindowLatest& nsTimestamp    = calculationContextDescriptor.IoStreamDescriptor.TimeWindows[i];
                    TTimeWindowLatest&       ticksTimestamp = sa.TimeWindows[i];
                    ticksTimestamp.Start                    = device.ConvertNsToGpuTimestamp( nsTimestamp.Start, gpuTimestampFrequency );
                    ticksTimestamp.End                      = device.ConvertNsToGpuTimestamp( nsTimestamp.End, gpuTimestampFrequency );
                }
            }

            // Convert aggregation window from ns to GPU timestamp ticks
            sa.NsTimeAggregationWindow     = device.ConvertNsToGpuTimestamp( calculationContextDescriptor.IoStreamDescriptor.NsTimeAggregationWindow, gpuTimestampFrequency );
            sa.MaxAggregationWindowInTicks = device.ConvertNsToGpuTimestamp( std::numeric_limits<uint64_t>::max(), gpuTimestampFrequency );
        }

        if( calculationContextDescriptor.TimeOffsets )
        {
            m_timeOffsets = new( std::nothrow ) int64_t[m_dataSetCount];
            MD_CHECK_PTR_RET( m_timeOffsets, CC_ERROR_NO_MEMORY );

            const uint32_t timeOffsetsSize = sizeof( int64_t ) * m_dataSetCount;

            iu_memcpy_s( m_timeOffsets, timeOffsetsSize, calculationContextDescriptor.TimeOffsets, timeOffsetsSize );
        }

        MD_LOG_EXIT();
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     Reinitialize
    //
    // Description:
    //     Reinitializes the calculation context for metrics calculations.
    //     This method destroys any existing calculation context and then
    //     initializes a new calculation context based on the provided
    //     calculation context descriptor. It ensures proper cleanup of
    //     allocated resources before reinitialization.
    //
    // Input:
    //     TCalculationContextDescriptorLatest& calculationContextDescriptor - Reference to the calculation context descriptor
    //                                                                         containing metric sets and configuration information.
    //
    // Output:
    //     TCompletionCode - *CC_OK* on success, or an appropriate error code on failure.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CCalculationContext::Reinitialize( TCalculationContextDescriptorLatest& calculationContextDescriptor )
    {
        DestroyContexts();

        MD_SAFE_DELETE_ARRAY( m_timeOffsets );
        MD_SAFE_DELETE( m_calculationManager );
        MD_SAFE_DELETE( m_metricsCalculator );
        MD_SAFE_DELETE( m_metricSet );

        return Initialize( calculationContextDescriptor );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     InitializeMetricsCalculator
    //
    // Description:
    //     Initializes metrics calculator if not already initialized.
    //
    // Input:
    //    std::vector<std::reference_wrapper<CMetricsDevice>>& devices - vector of metrics devices, used to get symbols
    //
    // Output:
    //     TCompletionCode - *CC_OK* if metrics calculator has been initialized successfully, *CC_ERROR_NO_MEMORY* if memory allocation failed.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CCalculationContext::InitializeMetricsCalculator( std::vector<std::reference_wrapper<CMetricsDevice>>& devices )
    {
        if( m_metricsCalculator == nullptr )
        {
            m_metricsCalculator = ( devices.size() == 1 )
                ? new( std::nothrow ) CMetricsCalculator( devices[0].get() )
                : new( std::nothrow ) CMetricsCalculator( devices );

            if( m_metricsCalculator == nullptr )
            {
                MD_LOG_A( devices[0].get().GetAdapter().GetAdapterId(), LOG_ERROR, "ERROR: Cannot allocate memory for CMetricsCalculator" );
                return CC_ERROR_NO_MEMORY;
            }
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     InitializeCalculationManager
    //
    // Description:
    //     Creates or destroys CalculationManager adequate to the given calculation context type.
    //
    // Input:
    //     const bool init - if true initialization, otherwise deinitialization
    //
    //////////////////////////////////////////////////////////////////////////////
    void CCalculationContext::InitializeCalculationManager( const bool init )
    {
        if( !init )
        {
            MD_SAFE_DELETE( m_calculationManager );
            MD_LOG( LOG_DEBUG, "calculation manager deinitialization" );
            return;
        }

        MD_ASSERT( m_calculationManager == nullptr );

        switch( m_type )
        {
            case CALCULATION_CONTEXT_TYPE_IO_STREAM:
                m_calculationManager = new( std::nothrow ) CMetricsCalculationManager<MEASUREMENT_TYPE_SNAPSHOT_IO>();
                MD_LOG( LOG_DEBUG, "ioStream calculation manager created" );
                return;

            case CALCULATION_CONTEXT_TYPE_QUERY:
                m_calculationManager = new( std::nothrow ) CMetricsCalculationManager<MEASUREMENT_TYPE_DELTA_QUERY>();
                MD_LOG( LOG_DEBUG, "query calculation manager created" );
                return;

            default:
                m_calculationManager = nullptr;
                MD_LOG( LOG_ERROR, "not supported calculation context type" );
                return;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     InitializeCalculationContext
    //
    // Description:
    //     Resets calculation context and initializes it with user provided data.
    //     After execution the context is ready for metrics calculations.
    //
    // Input:
    //     const bool init - if true initialization, otherwise deinitialization
    //
    // Output:
    //     TCompletionCode - *CC_OK* on success, or an appropriate error code on failure.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CCalculationContext::InitializeCalculationContext( const bool init )
    {
        MD_LOG_ENTER();

        if( !init )
        {
            MD_SAFE_DELETE_ARRAY( m_calculationContext.CommonCalculationContext.DeltaValues );
            MD_LOG( LOG_DEBUG, "calculation context deinitialization" );
            MD_LOG_EXIT();
            return CC_OK;
        }

        // Initialize context
        m_calculationManager->ResetContext( m_calculationContext );
        m_calculationContext.CommonCalculationContext.DeltaValues = new( std::nothrow ) TTypedValue_1_0[m_metricSet->GetParams()->MetricsCount];
        MD_CHECK_PTR_RET( m_calculationContext.CommonCalculationContext.DeltaValues, CC_ERROR_NO_MEMORY );
        m_calculationContext.CommonCalculationContext.Calculator         = m_metricsCalculator;
        m_calculationContext.CommonCalculationContext.MetricSet          = m_metricSet;
        m_calculationContext.CommonCalculationContext.AggregationEnabled = m_aggregationEnabled;
        m_calculationContext.CommonCalculationContext.ConcurrentGroup    = m_metricSet->GetConcurrentGroup();
        if( m_type == CALCULATION_CONTEXT_TYPE_IO_STREAM )
        {
            m_calculationContext.StreamCalculationContext.DoContextFiltering = false;
        }
        if( m_calculationManager->PrepareContext( m_calculationContext ) != CC_OK )
        {
            // Deinitialize and return error
            InitializeCalculationContext( false );
            MD_LOG_EXIT();
            return CC_ERROR_GENERAL;
        }

        MD_LOG( LOG_DEBUG, "calculation context initialized" );
        MD_LOG( LOG_DEBUG, "metricSet: %s", m_metricSet->GetParams()->ShortName );
        MD_LOG_EXIT();
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     InitializeAggregationContext
    //
    // Description:
    //     Resets aggregation context and initializes it with user provided data.
    //     After execution the context is ready for metrics aggregation.
    //
    // Input:
    //     const bool init - if true initialization, otherwise deinitialization
    //
    // Output:
    //     TCompletionCode - *CC_OK* on success, or an appropriate error code on failure.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CCalculationContext::InitializeAggregationContext( const bool init )
    {
        MD_LOG_ENTER();

        TCompletionCode ret = CC_OK;
        m_calculationManager->ResetContext( m_aggregationContext );

        if( init )
        {
            m_aggregationContext.CommonAggregationContext.MetricSet     = m_metricSet;
            m_aggregationContext.CommonAggregationContext.BaseMetricSet = m_baseMetricSet;
            m_aggregationContext.CommonAggregationContext.DataSetCount  = m_dataSetCount;

            if( m_type == CALCULATION_CONTEXT_TYPE_IO_STREAM )
            {
                TStreamAggregationContext& sa = m_aggregationContext.StreamAggregationContext;

                sa.Calculator                  = m_metricsCalculator;
                sa.TimeOffsets                 = m_timeOffsets;
                sa.MaxAggregationWindowInTicks = 0;
                sa.CalculationWindowIndex      = 0;
                sa.NsTimeAggregationWindowStop = 0;
                sa.NsTimeFirstReport           = 0;
                sa.LastAggregatedTimestamp     = 0;
                sa.IsNewCalculationWindow      = false;
            }

            if( m_calculationManager->PrepareContext( m_aggregationContext ) != CC_OK )
            {
                InitializeAggregationContext( false );
                ret = CC_ERROR_GENERAL;
            }
        }
        else
        {
            DestroyContexts();
            MD_LOG( LOG_DEBUG, "aggregation context deinitialization" );
        }

        MD_LOG_EXIT();
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     CreateInternalMetricSet
    //
    // Description:
    //     Creates an internal metric set needed to perform aggregation and calculation.
    //
    // Input:
    //     CMetricSet* baseMetricSet - a pointer to the base metric set
    //
    // Output:
    //     TCompletionCode - *CC_OK* on success, or an appropriate error code on failure.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CCalculationContext::CreateInternalMetricSet( CMetricSet* baseMetricSet )
    {
        MD_LOG_ENTER();
        MD_CHECK_PTR_RET( baseMetricSet, CC_ERROR_INVALID_PARAMETER );

        TMetricSetParamsLatest* baseMetricSetParams = baseMetricSet->GetParams();
        MD_CHECK_PTR_RET( baseMetricSetParams, CC_ERROR_INVALID_PARAMETER );

        // Copy metric set to internal metric set.
        // This is needed to be able to use the same metric sets in multiple contexts.
        std::string internalMetricSetName = std::string( baseMetricSetParams->SymbolName ) + "_internal";

        m_metricSet = new( std::nothrow ) CMetricSet(
            baseMetricSet->GetMetricsDevice(),
            baseMetricSet->GetConcurrentGroup(),
            internalMetricSetName.c_str(),
            baseMetricSetParams->ShortName,
            baseMetricSetParams->ApiMask,
            baseMetricSetParams->CategoryMask,
            baseMetricSetParams->RawReportSize,
            baseMetricSetParams->QueryReportSize,
            baseMetricSet->GetReportType(),
            baseMetricSet->GetPlatformMask(),
            baseMetricSetParams->GtMask,
            baseMetricSet->IsCustom(),
            m_aggregationEnabled );
        MD_CHECK_PTR_RET( m_metricSet, CC_ERROR_NO_MEMORY );

        auto ret = m_metricSet->InheritFromMetricSet( baseMetricSet, nullptr, false );
        if( ret != CC_OK )
        {
            MD_SAFE_DELETE( m_metricSet );
            MD_LOG_EXIT();
            return ret;
        }

        m_metricSet->SetApiFiltering( baseMetricSetParams->ApiMask );

        TMetricSetParamsLatest* metricSetParams = m_metricSet->GetParams();
        MD_CHECK_PTR_RET( metricSetParams, CC_ERROR_NO_MEMORY );

        m_params.MetricsCount     = metricSetParams->MetricsCount;
        m_params.InformationCount = metricSetParams->InformationCount;

        m_baseMetricSet = baseMetricSet;

        MD_LOG_EXIT();
        return ret;
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     AggregateData
    //
    // Description:
    //     Aggregates raw data from multiple sources into a single output buffer for both IO stream
    //     and query calculation contexts. For IO stream contexts, this method validates input buffers,
    //     prepares the aggregation context, and delegates aggregation to AggregateStreamData, handling
    //     both timer mode and windowed aggregation. For query contexts, it validates input buffers,
    //     ensures all data sets have matching report counts, prepares the aggregation context, and
    //     performs aggregation using the base data set and AggregateNextReport. The output buffer size
    //     is updated to reflect the total size of the aggregated data. If the last portion of data is
    //     indicated, the method finalizes aggregation for the current window.
    //
    // Input:
    //     const uint8_t** rawData                  - Array of pointers to raw data buffers to be aggregated.
    //     const uint32_t* rawDataSizes             - Array of sizes (in bytes) for each raw data buffer.
    //     uint8_t*        outAggregatedRawData     - Pointer to the output buffer where aggregated data will be stored.
    //     uint32_t*       outAggregatedRawDataSize - Pointer to a variable that will receive the size of the aggregated data.
    //     bool            lastDataPortion          - Indicates if this is the last portion of data.
    //
    // Output:
    //     TCompletionCode - CC_OK on success, or an appropriate error code on failure.
    //
    ////////////////////////////////////////////////////////////////////////////////
    TCompletionCode CCalculationContext::AggregateData( const uint8_t** rawData, const uint32_t* rawDataSizes, uint8_t* outAggregatedRawData, uint32_t* outAggregatedRawDataSize, bool lastDataPortion )
    {
        MD_LOG_ENTER();

        MD_CHECK_PTR_RET( m_calculationContext.CommonCalculationContext.Calculator, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( m_calculationContext.CommonCalculationContext.MetricSet, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( rawData, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( rawDataSizes, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( outAggregatedRawDataSize, CC_ERROR_INVALID_PARAMETER );

        MD_CHECK_PTR_RET( m_metricSet, CC_ERROR_INVALID_PARAMETER );

        if( !m_metricSet->IsFiltered() )
        {
            MD_LOG( LOG_ERROR, "error: API filtering must be enabled first" );
            MD_LOG_EXIT();
            return CC_ERROR_GENERAL;
        }

        TMetricSetParamsLatest* params = m_metricSet->GetParams();
        MD_CHECK_PTR_RET( params, CC_ERROR_INVALID_PARAMETER );

        if( ( params->MetricsCount + params->InformationCount ) == 0 )
        {
            // May happen when unsupported API is used in MetricSet filtering
            MD_LOG( LOG_WARNING, "nothing to aggregate, empty MetricSet" );
            MD_LOG_EXIT();
            return CC_OK;
        }

        TCompletionCode ret = CC_OK;

        if( *outAggregatedRawDataSize != 0 )
        {
            MD_CHECK_PTR_RET( outAggregatedRawData, CC_ERROR_INVALID_PARAMETER );
        }

        // Validate raw data sets
        for( uint32_t i = 0; i < m_dataSetCount; ++i )
        {
            if( rawDataSizes[i] == 0 && m_type == CALCULATION_CONTEXT_TYPE_QUERY )
            {
                MD_LOG( LOG_DEBUG, "nothing to aggregate, rawDataSizes[%u]: 0", i );
                MD_LOG_EXIT();
                return CC_NOT_ENOUGH_DATA;
            }

            MD_CHECK_PTR_RET( rawData[i], CC_ERROR_INVALID_PARAMETER );
        }

        if( m_type == CALCULATION_CONTEXT_TYPE_IO_STREAM )
        {
            TStreamAggregationContext& sa = m_aggregationContext.StreamAggregationContext;

            for( uint32_t i = 0; i < m_dataSetCount; ++i )
            {
                sa.RawData[i]        = rawData[i];
                sa.RawReportCount[i] = rawDataSizes[i] / sa.RawReportSize;
                sa.OutReportCount[i] = 0;
            }

            if( *outAggregatedRawDataSize == 0 )
            {
                *outAggregatedRawDataSize = m_calculationManager->GetRequiredSize( m_aggregationContext );
                MD_LOG_EXIT();
                return CC_OK;
            }

            ret = AggregateStreamData( rawData, rawDataSizes, outAggregatedRawData, outAggregatedRawDataSize, lastDataPortion );
        }
        else if( m_type == CALCULATION_CONTEXT_TYPE_QUERY )
        {
            TQueryAggregationContext& qa = m_aggregationContext.QueryAggregationContext;
            qa.RawReportCount[0]         = rawDataSizes[0] / qa.RawReportSize;

            for( uint32_t i = 1; i < m_dataSetCount; ++i )
            {
                qa.RawReportCount[i] = rawDataSizes[i] / qa.RawReportSize;

                if( qa.RawReportCount[i] != qa.RawReportCount[0] )
                {
                    MD_LOG_EXIT();
                    return CC_NOT_ENOUGH_DATA;
                }
            }

            if( *outAggregatedRawDataSize == 0 )
            {
                *outAggregatedRawDataSize = m_calculationManager->GetRequiredSize( m_aggregationContext );
                MD_LOG_EXIT();
                return CC_OK;
            }

            qa.Out     = outAggregatedRawData;
            qa.OutSize = *outAggregatedRawDataSize;

            for( uint32_t i = 0; i < m_dataSetCount; ++i )
            {
                qa.RawData[i]        = rawData[i];
                qa.RawReportCount[i] = rawDataSizes[i] / qa.RawReportSize;
                qa.OutReportCount[i] = 0;
            }

            qa.BaseDataSetIdx = 0;

            iu_memcpy_s( qa.Out, rawDataSizes[qa.BaseDataSetIdx], rawData[qa.BaseDataSetIdx], rawDataSizes[qa.BaseDataSetIdx] );

            while( m_calculationManager->AggregateNextReport( m_aggregationContext ) )
            {
            }
        }

        MD_LOG_EXIT();
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     AggregateSingleWindow
    //
    // Description:
    //     Aggregates raw data from multiple sources into a single output buffer for a single aggregation window.
    //     This method processes the provided raw data buffers, combines them according to the
    //     aggregation rules defined in the calculation context, and fills the output buffer
    //     with the aggregated data for a single aggregation window. It also updates the size of the output buffer
    //     to reflect the total size of the aggregated data for that window.
    //
    // Input:
    //     const uint8_t** rawData                  - pointer to an array of pointers to raw data buffers to be aggregated.
    //     const uint32_t* rawDataSizes             - pointer to an array of sizes corresponding to each raw data buffer.
    //     uint8_t*        outAggregatedRawData     - pointer to the output buffer where aggregated data will be stored.
    //     bool            lastDataPortion          - Indicates if this is the last portion of data.
    //
    // Output:
    //     TCompletionCode                          - CC_OK on success, or an appropriate error code on failure.
    //     uint32_t*       outProcessedRawDataCount - pointer to an array that will receive the count of processed raw data for each data set.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CCalculationContext::AggregateSingleWindow( const uint8_t** rawData, const uint32_t* rawDataSizes, uint8_t* outAggregatedRawData, uint32_t* outProcessedRawDataCount, bool lastDataPortion )
    {
        MD_LOG_ENTER();

        TStreamAggregationContext& sa = m_aggregationContext.StreamAggregationContext;

        if( m_type == CALCULATION_CONTEXT_TYPE_QUERY )
        {
            // Query does not support a single window aggregation.
            MD_LOG_EXIT();
            return CC_ERROR_NOT_SUPPORTED;
        }

        if( m_state == CALCULATION_CONTEXT_STATE_FINISHED )
        {
            sa.OutAggregatedRawDataSize = 0;
            MD_LOG_EXIT();
            return CC_OK;
        }

        MD_CHECK_PTR_RET( m_calculationContext.CommonCalculationContext.Calculator, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( m_calculationContext.CommonCalculationContext.MetricSet, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( rawData, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( rawDataSizes, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( outAggregatedRawData, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( outProcessedRawDataCount, CC_ERROR_INVALID_PARAMETER );

        // Validate raw data sets
        for( uint32_t i = 0; i < m_dataSetCount; ++i )
        {
            if( rawDataSizes[i] != 0 )
            {
                MD_CHECK_PTR_RET( rawData[i], CC_ERROR_INVALID_PARAMETER );
            }
        }

        MD_CHECK_PTR_RET( m_metricSet, CC_ERROR_INVALID_PARAMETER );

        if( !m_metricSet->IsFiltered() )
        {
            MD_LOG( LOG_ERROR, "error: API filtering must be enabled first" );
            MD_LOG_EXIT();
            return CC_ERROR_GENERAL;
        }

        TMetricSetParamsLatest* params = m_metricSet->GetParams();
        MD_CHECK_PTR_RET( params, CC_ERROR_INVALID_PARAMETER );

        if( ( params->MetricsCount + params->InformationCount ) == 0 )
        {
            // May happen when unsupported API is used in MetricSet filtering
            MD_LOG( LOG_WARNING, "nothing to aggregate, empty MetricSet" );
            MD_LOG_EXIT();
            return CC_OK;
        }

        sa.Out                      = outAggregatedRawData;
        sa.OutAggregatedRawDataSize = 0;

        for( uint32_t i = 0; i < m_dataSetCount; ++i )
        {
            sa.RawData[i]        = rawData[i];
            sa.RawReportCount[i] = rawDataSizes[i] / sa.RawReportSize;
            sa.OutReportCount[i] = 0;

            sa.PrevRawDataPtrs[i] = sa.IsPrevRawDataPresent[i] ? sa.PrevSavedReportPtrs[i] : nullptr;
            sa.LastRawDataPtrs[i] = sa.IsLastRawDataPresent[i] ? sa.LastSavedReportPtrs[i] : nullptr;
        }

        TCompletionCode ret        = CC_OK;
        bool            needReport = false;

        do
        {
            for( uint32_t i = 0; i < m_dataSetCount; ++i )
            {
                if( sa.NeedReport[i] )
                {
                    if( sa.LastRawDataPtrs[i] != nullptr )
                    {
                        sa.PrevRawDataPtrs[i]      = sa.LastRawDataPtrs[i];
                        sa.IsPrevRawDataPresent[i] = false;
                    }

                    TCompletionCode getReport = FilterReport( i, false );

                    if( getReport == CC_OK )
                    {
                        if( sa.IsCachedReport[i] )
                        {
                            sa.LastRawDataPtrs[i] = sa.CachedReportPtrs[i];
                            sa.CurrentTs[i]       = *reinterpret_cast<const uint64_t*>( sa.CachedReportPtrs[i] + 8 );
                        }
                        else
                        {
                            sa.LastRawDataPtrs[i] = sa.RawData[i];
                            sa.CurrentTs[i]       = *reinterpret_cast<const uint64_t*>( sa.RawData[i] + 8 );
                        }

                        sa.IsLastRawDataPresent[i] = false;
                        sa.NeedReport[i]           = false;

                        if( ( sa.OutReportCount[i] < sa.RawReportCount[i] ) || ( sa.RawReportCount[i] == 0 && sa.IsCachedReport[i] ) )
                        {
                            if( sa.IsCachedReport[i] )
                            {
                                sa.CachedReportPtrsSize[i] -= sa.RawReportSize;

                                if( sa.CachedReportPtrsSize[i] == 0 )
                                {
                                    MD_LOG( LOG_DEBUG, "No more cached reports available for dataSetCount: %u", i );
                                    sa.IsCachedReport[i] = false;
                                }
                                else
                                {
                                    sa.CachedReportPtrs[i] += sa.RawReportSize;
                                }
                            }
                            else
                            {
                                sa.RawData[i] += sa.RawReportSize;
                            }
                        }
                    }
                    else
                    {
                        continue;
                    }
                }
            }

            for( uint32_t i = 0; i < m_dataSetCount; ++i )
            {
                if( sa.NeedReport[i] )
                {
                    needReport = true;
                    break;
                }
            }

            if( needReport )
            {
                if( lastDataPortion )
                {
                    if( m_state == CALCULATION_CONTEXT_STATE_SEEK_AGGREGATION_WINDOW )
                    {
                        uint64_t minTimestamp = GetMinCurrentTimestamp();
                        if( sa.LastAggregatedTimestamp != minTimestamp )
                        {
                            Interpolate( minTimestamp );
                            m_calculationManager->AggregateCounters( m_aggregationContext );
                            sa.OutAggregatedRawDataSize += sa.RawReportSize;
                        }
                    }

                    m_state = CALCULATION_CONTEXT_STATE_FINISHED;
                    ret     = CC_OK;
                    break;
                }

                ret = CacheRemainingReports();
                MD_CHECK_CC_RET( ret );

                ret = CC_NOT_ENOUGH_DATA;
                break;
            }

            if( m_state == CALCULATION_CONTEXT_STATE_INITIAL )
            {
                for( uint32_t i = 0; i < m_dataSetCount; ++i )
                {
                    sa.NeedReport[i] = true;
                }

                m_state = CALCULATION_CONTEXT_STATE_LOAD_CALCULATION_WINDOW;
                continue;
            }

            if( m_state == CALCULATION_CONTEXT_STATE_LOAD_CALCULATION_WINDOW )
            {
                if( sa.TimeWindowCount == 0 )
                {
                    sa.TimeWindows = new( std::nothrow ) TTimeWindowLatest[1];
                    MD_CHECK_PTR_RET( sa.TimeWindows, CC_ERROR_NO_MEMORY );

                    sa.TimeWindows[0].Start = GetMaxCurrentTimestamp();

                    sa.TimeWindows[0].End = ( sa.NsTimeAggregationWindow == sa.MaxAggregationWindowInTicks )
                        ? sa.MaxAggregationWindowInTicks
                        : sa.TimeWindows[0].Start + sa.NsTimeAggregationWindow;

                    sa.TimeWindowCount             = 1;
                    sa.NsTimeAggregationWindowStop = sa.TimeWindows[0].Start;

                    for( uint32_t i = 0; i < m_dataSetCount; ++i )
                    {
                        if( sa.CurrentTs[i] == sa.TimeWindows[0].Start )
                        {
                            sa.PrevRawDataPtrs[i]      = sa.LastRawDataPtrs[i];
                            sa.IsPrevRawDataPresent[i] = false;
                        }
                    }

                    m_state = CALCULATION_CONTEXT_STATE_CALCULATION_WINDOW_LOADED;
                }
                else if( sa.CalculationWindowIndex == sa.TimeWindowCount )
                {
                    m_state = CALCULATION_CONTEXT_STATE_FINISHED;
                    ret     = CC_OK;
                    break;
                }
                else
                {
                    sa.NsTimeAggregationWindowStop = sa.TimeWindows[sa.CalculationWindowIndex].Start;
                    m_state                        = CALCULATION_CONTEXT_STATE_CALCULATION_WINDOW_LOADED;
                }
            }

            if( m_state == CALCULATION_CONTEXT_STATE_CALCULATION_WINDOW_LOADED )
            {
                if( !EnsureDataAtTimestamp<false>( sa.TimeWindows[sa.CalculationWindowIndex].Start ) )
                {
                    continue;
                }

                UpdateAggregationWindowStop();

                if( IsEnoughData() )
                {
                    // all streams started before the first calculation window
                    Interpolate( sa.TimeWindows[sa.CalculationWindowIndex].Start );
                    m_calculationManager->AggregateCounters( m_aggregationContext );

                    sa.OutAggregatedRawDataSize += sa.RawReportSize;
                    m_state = CALCULATION_CONTEXT_STATE_SEEK_AGGREGATION_WINDOW;
                }
                else
                {
                    uint64_t firstSampleTimestamp = 0;

                    for( uint32_t i = 0; i < m_dataSetCount; ++i )
                    {
                        if( sa.PrevRawDataPtrs[i] )
                        {
                            continue;
                        }

                        if( sa.CurrentTs[i] > firstSampleTimestamp )
                        {
                            firstSampleTimestamp = sa.CurrentTs[i];
                        }
                    }

                    sa.NsTimeFirstReport = firstSampleTimestamp;
                    m_state              = CALCULATION_CONTEXT_STATE_AGGREGATION_WINDOW_START_REACHED;
                }
            }

            if( m_state == CALCULATION_CONTEXT_STATE_AGGREGATION_WINDOW_START_REACHED )
            {
                if( sa.NsTimeFirstReport < sa.NsTimeAggregationWindowStop )
                {
                    if( !EnsureDataAtTimestamp<false>( sa.NsTimeFirstReport ) )
                    {
                        continue;
                    }

                    Interpolate( sa.NsTimeFirstReport );
                    m_calculationManager->AggregateCounters( m_aggregationContext );

                    sa.OutAggregatedRawDataSize += sa.RawReportSize;
                    m_state = CALCULATION_CONTEXT_STATE_SEEK_AGGREGATION_WINDOW;
                }
                else
                {
                    UpdateAggregationWindowStop();

                    ret = CC_OK; // no data
                    break;
                }
            }

            if( m_state == CALCULATION_CONTEXT_STATE_SEEK_AGGREGATION_WINDOW )
            {
                if( !EnsureDataAtTimestamp<false>( sa.NsTimeAggregationWindowStop ) )
                {
                    continue;
                }

                Interpolate( sa.NsTimeAggregationWindowStop );
                m_calculationManager->AggregateCounters( m_aggregationContext );

                sa.OutAggregatedRawDataSize += sa.RawReportSize;

                if( lastDataPortion )
                {
                    m_state = CALCULATION_CONTEXT_STATE_FINISHED;
                }
                else if( sa.NsTimeAggregationWindowStop >= sa.TimeWindows[sa.CalculationWindowIndex].End )
                {
                    sa.CalculationWindowIndex++;
                    sa.IsNewCalculationWindow = true;

                    m_state = CALCULATION_CONTEXT_STATE_LOAD_CALCULATION_WINDOW;
                }
                else
                {
                    UpdateAggregationWindowStop();
                }

                ret = CC_OK;
                break;
            }
        }
        while( m_state != CALCULATION_CONTEXT_STATE_FINISHED );

        for( uint32_t i = 0; i < m_dataSetCount; ++i )
        {
            outProcessedRawDataCount[i] = static_cast<uint32_t>( sa.OutReportCount[i] * sa.RawReportSize );

            if( sa.LastRawDataPtrs[i] != nullptr && !sa.IsLastRawDataPresent[i] )
            {
                iu_memcpy_s( sa.LastSavedReportPtrs[i], sa.RawReportSize, sa.LastRawDataPtrs[i], sa.RawReportSize );
                sa.IsLastRawDataPresent[i] = true;
            }
            if( sa.PrevRawDataPtrs[i] != nullptr && !sa.IsPrevRawDataPresent[i] )
            {
                iu_memcpy_s( sa.PrevSavedReportPtrs[i], sa.RawReportSize, sa.PrevRawDataPtrs[i], sa.RawReportSize );
                sa.IsPrevRawDataPresent[i] = true;
            }
        }

        MD_LOG_EXIT();
        return ret;
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     AggregateStreamData
    //
    // Description:
    //     Aggregates raw data from multiple sources into a single output buffer for IO stream
    //     calculation contexts. This method processes the provided raw data buffers, combines
    //     them according to the aggregation rules defined in the calculation context, and fills
    //     the output buffer with the aggregated data. It supports both timer mode
    //     (aggregation windows not defined) and mode with defined aggregation windows,
    //     handling report filtering, interpolation, and caching of remaining reports
    //     as needed. The method also updates the output buffer size to reflect the total size of
    //     the aggregated data. If the last portion of data is indicated, it finalizes aggregation
    //     for the current window.
    //
    // Input:
    //     const uint8_t** rawData                  - Array of pointers to raw data buffers to be aggregated.
    //     const uint32_t* rawDataSizes             - Array of sizes (in bytes) for each raw data buffer.
    //     uint8_t*        outAggregatedRawData     - Pointer to the output buffer where aggregated data will be stored.
    //     uint32_t*       outAggregatedRawDataSize - Pointer to a variable that will receive the size of the aggregated data.
    //     bool            lastDataPortion          - Indicates if this is the last portion of data.
    //
    // Output:
    //     TCompletionCode - CC_OK on success, or an appropriate error code on failure.
    //
    ////////////////////////////////////////////////////////////////////////////////
    TCompletionCode CCalculationContext::AggregateStreamData( const uint8_t** rawData, const uint32_t* rawDataSizes, uint8_t* outAggregatedRawData, uint32_t* outAggregatedRawDataSize, bool lastDataPortion )
    {
        MD_LOG_ENTER();

        TStreamAggregationContext& sa = m_aggregationContext.StreamAggregationContext;

        if( m_type == CALCULATION_CONTEXT_TYPE_QUERY )
        {
            // Query does not support AggregateStreamData
            MD_LOG_EXIT();
            return CC_ERROR_NOT_SUPPORTED;
        }

        if( m_state == CALCULATION_CONTEXT_STATE_FINISHED || m_timerModeState == CALCULATION_CONTEXT_STATE_TIMER_MODE_FINISHED )
        {
            sa.OutAggregatedRawDataSize = 0;
            MD_LOG_EXIT();
            return CC_OK;
        }

        MD_CHECK_PTR_RET( m_calculationContext.CommonCalculationContext.Calculator, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( m_calculationContext.CommonCalculationContext.MetricSet, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( rawData, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( rawDataSizes, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( outAggregatedRawData, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( outAggregatedRawDataSize, CC_ERROR_INVALID_PARAMETER );

        // Validate raw data sets
        for( uint32_t i = 0; i < m_dataSetCount; ++i )
        {
            if( rawDataSizes[i] != 0 )
            {
                MD_CHECK_PTR_RET( rawData[i], CC_ERROR_INVALID_PARAMETER );
            }
        }

        MD_CHECK_PTR_RET( m_metricSet, CC_ERROR_INVALID_PARAMETER );

        if( !m_metricSet->IsFiltered() )
        {
            MD_LOG( LOG_ERROR, "error: API filtering must be enabled first" );
            MD_LOG_EXIT();
            return CC_ERROR_GENERAL;
        }

        TMetricSetParamsLatest* params = m_metricSet->GetParams();
        MD_CHECK_PTR_RET( params, CC_ERROR_INVALID_PARAMETER );

        if( ( params->MetricsCount + params->InformationCount ) == 0 )
        {
            // May happen when unsupported API is used in MetricSet filtering
            MD_LOG( LOG_WARNING, "nothing to aggregate, empty MetricSet" );
            MD_LOG_EXIT();
            return CC_OK;
        }

        sa.Out                      = outAggregatedRawData;
        sa.OutAggregatedRawDataSize = 0;

        for( uint32_t i = 0; i < m_dataSetCount; ++i )
        {
            sa.RawData[i]        = rawData[i];
            sa.RawReportCount[i] = rawDataSizes[i] / sa.RawReportSize;
            sa.OutReportCount[i] = 0;

            sa.PrevRawDataPtrs[i] = sa.IsPrevRawDataPresent[i] ? sa.PrevSavedReportPtrs[i] : nullptr;
            sa.LastRawDataPtrs[i] = sa.IsLastRawDataPresent[i] ? sa.LastSavedReportPtrs[i] : nullptr;
        }

        TCompletionCode ret = CC_OK;

        // For timer mode
        const uint32_t baseStream          = 0;
        uint64_t       baseSampleTimestamp = 0;

        if( !sa.NsTimeAggregationWindow )
        {
            bool notEnoughData = false;
            do
            {
                for( uint32_t i = 0; i < m_dataSetCount; ++i )
                {
                    if( sa.NeedReport[i] )
                    {
                        if( sa.LastRawDataPtrs[i] != nullptr )
                        {
                            sa.PrevRawDataPtrs[i]      = sa.LastRawDataPtrs[i];
                            sa.IsPrevRawDataPresent[i] = false;
                        }

                        ret = ( i == baseStream ) ? FilterReport( i, true ) : FilterReport( i, false );

                        if( ret == CC_OK )
                        {
                            if( sa.IsCachedReport[i] )
                            {
                                sa.LastRawDataPtrs[i] = sa.CachedReportPtrs[i];
                                sa.CurrentTs[i]       = *reinterpret_cast<const uint64_t*>( sa.CachedReportPtrs[i] + 8 );
                            }
                            else
                            {
                                sa.LastRawDataPtrs[i] = sa.RawData[i];
                                sa.CurrentTs[i]       = *reinterpret_cast<const uint64_t*>( sa.RawData[i] + 8 );
                            }

                            sa.IsLastRawDataPresent[i] = false;
                            sa.NeedReport[i]           = false;

                            if( ( sa.OutReportCount[i] < sa.RawReportCount[i] ) || ( sa.RawReportCount[i] == 0 && sa.IsCachedReport[i] ) )
                            {
                                if( sa.IsCachedReport[i] )
                                {
                                    sa.CachedReportPtrsSize[i] -= sa.RawReportSize;

                                    if( sa.CachedReportPtrsSize[i] == 0 )
                                    {
                                        MD_LOG( LOG_DEBUG, "No more cached reports available for dataSetCount: %u", i );
                                        sa.IsCachedReport[i] = false;
                                    }
                                    else
                                    {
                                        sa.CachedReportPtrs[i] += sa.RawReportSize;
                                    }
                                }
                                else
                                {
                                    sa.RawData[i] += sa.RawReportSize;
                                }
                            }
                        }
                        else
                        {
                            notEnoughData = true;
                            continue;
                        }
                    }
                }

                if( notEnoughData )
                {
                    ret = CacheRemainingReports();
                    MD_CHECK_CC_RET( ret );

                    break;
                }

                if( m_timerModeState == CALCULATION_CONTEXT_STATE_TIMER_MODE_INITIAL )
                {
                    for( uint32_t i = 0; i < m_dataSetCount; ++i )
                    {
                        sa.NeedReport[i] = true;
                    }

                    m_timerModeState = CALCULATION_CONTEXT_STATE_TIMER_MODE_SEEK_DATA_START;
                    continue;
                }

                if( m_timerModeState == CALCULATION_CONTEXT_STATE_TIMER_MODE_SEEK_DATA_START )
                {
                    baseSampleTimestamp = sa.CurrentTs[baseStream];

                    for( uint32_t i = 0; i < m_dataSetCount; ++i )
                    {
                        if( i == baseStream )
                        {
                            continue;
                        }

                        if( sa.CurrentTs[i] > baseSampleTimestamp )
                        {
                            sa.NeedReport[baseStream] = true;
                            break;
                        }
                    }

                    if( sa.NeedReport[baseStream] )
                    {
                        continue;
                    }

                    m_timerModeState = CALCULATION_CONTEXT_STATE_TIMER_MODE_LOAD_CALCULATION_WINDOW;
                }

                if( m_timerModeState == CALCULATION_CONTEXT_STATE_TIMER_MODE_LOAD_CALCULATION_WINDOW )
                {
                    if( sa.TimeWindowCount == 0 )
                    {
                        sa.TimeWindows = new( std::nothrow ) TTimeWindowLatest[1];
                        MD_CHECK_PTR_RET( sa.TimeWindows, CC_ERROR_NO_MEMORY );

                        sa.TimeWindows[0].Start = 0;
                        sa.TimeWindows[0].End   = sa.MaxAggregationWindowInTicks;
                        sa.TimeWindowCount      = 1;

                        m_timerModeState = CALCULATION_CONTEXT_STATE_TIMER_MODE_SEEK_NEXT_SAMPLE;
                    }
                    else if( sa.CalculationWindowIndex == sa.TimeWindowCount )
                    {
                        m_timerModeState = CALCULATION_CONTEXT_STATE_TIMER_MODE_FINISHED;
                        ret              = CC_OK;
                        break;
                    }
                    else
                    {
                        m_timerModeState = CALCULATION_CONTEXT_STATE_TIMER_MODE_SEEK_NEXT_SAMPLE;
                    }
                }

                if( m_timerModeState == CALCULATION_CONTEXT_STATE_TIMER_MODE_SEEK_NEXT_SAMPLE )
                {
                    baseSampleTimestamp = sa.CurrentTs[baseStream];

                    if( baseSampleTimestamp > sa.TimeWindows[sa.CalculationWindowIndex].End )
                    {
                        sa.CalculationWindowIndex++;
                        sa.IsNewCalculationWindow = true;
                        m_timerModeState          = CALCULATION_CONTEXT_STATE_TIMER_MODE_LOAD_CALCULATION_WINDOW;
                        continue;
                    }
                    else if( baseSampleTimestamp < sa.TimeWindows[sa.CalculationWindowIndex].Start )
                    {
                        sa.NeedReport[baseStream] = true;
                        continue;
                    }

                    m_timerModeState = CALCULATION_CONTEXT_STATE_TIMER_MODE_SEEK_BASE_SAMPLE;
                }

                if( m_timerModeState == CALCULATION_CONTEXT_STATE_TIMER_MODE_SEEK_BASE_SAMPLE )
                {
                    baseSampleTimestamp = sa.CurrentTs[baseStream];

                    if( !EnsureDataAtTimestamp<true>( baseSampleTimestamp ) )
                    {
                        continue;
                    }

                    Interpolate( baseSampleTimestamp );
                    m_calculationManager->AggregateCounters( m_aggregationContext );

                    sa.OutAggregatedRawDataSize += sa.RawReportSize;
                    sa.NeedReport[baseStream] = true;
                    m_timerModeState          = CALCULATION_CONTEXT_STATE_TIMER_MODE_SEEK_NEXT_SAMPLE;
                }
            }
            while( m_timerModeState != CALCULATION_CONTEXT_STATE_TIMER_MODE_FINISHED );
        }
        else
        {
            bool needReport = false;

            do
            {
                for( uint32_t i = 0; i < m_dataSetCount; ++i )
                {
                    if( sa.NeedReport[i] )
                    {
                        if( sa.LastRawDataPtrs[i] != nullptr )
                        {
                            sa.PrevRawDataPtrs[i]      = sa.LastRawDataPtrs[i];
                            sa.IsPrevRawDataPresent[i] = false;
                        }

                        TCompletionCode getReport = FilterReport( i, false );

                        if( getReport == CC_OK )
                        {
                            if( sa.IsCachedReport[i] )
                            {
                                sa.LastRawDataPtrs[i] = sa.CachedReportPtrs[i];
                                sa.CurrentTs[i]       = *reinterpret_cast<const uint64_t*>( sa.CachedReportPtrs[i] + 8 );
                            }
                            else
                            {
                                sa.LastRawDataPtrs[i] = sa.RawData[i];
                                sa.CurrentTs[i]       = *reinterpret_cast<const uint64_t*>( sa.RawData[i] + 8 );
                            }

                            sa.IsLastRawDataPresent[i] = false;
                            sa.NeedReport[i]           = false;

                            if( ( sa.OutReportCount[i] < sa.RawReportCount[i] ) || ( sa.RawReportCount[i] == 0 && sa.IsCachedReport[i] ) )
                            {
                                if( sa.IsCachedReport[i] )
                                {
                                    sa.CachedReportPtrsSize[i] -= sa.RawReportSize;

                                    if( sa.CachedReportPtrsSize[i] == 0 )
                                    {
                                        MD_LOG( LOG_DEBUG, "No more cached reports available for dataSetCount: %u", i );
                                        sa.IsCachedReport[i] = false;
                                    }
                                    else
                                    {
                                        sa.CachedReportPtrs[i] += sa.RawReportSize;
                                    }
                                }
                                else
                                {
                                    sa.RawData[i] += sa.RawReportSize;
                                }
                            }
                        }
                        else
                        {
                            continue;
                        }
                    }
                }

                for( uint32_t i = 0; i < m_dataSetCount; ++i )
                {
                    if( sa.NeedReport[i] )
                    {
                        needReport = true;
                        break;
                    }
                }

                if( needReport )
                {
                    if( lastDataPortion )
                    {
                        if( m_state == CALCULATION_CONTEXT_STATE_SEEK_AGGREGATION_WINDOW )
                        {
                            uint64_t minTimestamp = GetMinCurrentTimestamp();
                            if( sa.LastAggregatedTimestamp != minTimestamp )
                            {
                                Interpolate( minTimestamp );
                                m_calculationManager->AggregateCounters( m_aggregationContext );
                                sa.OutAggregatedRawDataSize += sa.RawReportSize;
                            }
                        }

                        m_state = CALCULATION_CONTEXT_STATE_FINISHED;
                        ret     = CC_OK;
                        break;
                    }

                    ret = CacheRemainingReports();
                    MD_CHECK_CC_RET( ret );

                    break;
                }

                if( m_state == CALCULATION_CONTEXT_STATE_INITIAL )
                {
                    for( uint32_t i = 0; i < m_dataSetCount; ++i )
                    {
                        sa.NeedReport[i] = true;
                    }

                    m_state = CALCULATION_CONTEXT_STATE_LOAD_CALCULATION_WINDOW;
                    continue;
                }

                if( m_state == CALCULATION_CONTEXT_STATE_LOAD_CALCULATION_WINDOW )
                {
                    if( sa.TimeWindowCount == 0 )
                    {
                        sa.TimeWindows = new( std::nothrow ) TTimeWindowLatest[1];
                        MD_CHECK_PTR_RET( sa.TimeWindows, CC_ERROR_NO_MEMORY );

                        sa.TimeWindows[0].Start = GetMaxCurrentTimestamp();

                        sa.TimeWindows[0].End = ( sa.NsTimeAggregationWindow == sa.MaxAggregationWindowInTicks )
                            ? sa.MaxAggregationWindowInTicks
                            : sa.TimeWindows[0].Start + sa.NsTimeAggregationWindow;

                        sa.TimeWindowCount             = 1;
                        sa.NsTimeAggregationWindowStop = sa.TimeWindows[0].Start;

                        for( uint32_t i = 0; i < m_dataSetCount; ++i )
                        {
                            if( sa.CurrentTs[i] == sa.TimeWindows[0].Start )
                            {
                                sa.PrevRawDataPtrs[i]      = sa.LastRawDataPtrs[i];
                                sa.IsPrevRawDataPresent[i] = false;
                            }
                        }

                        m_state = CALCULATION_CONTEXT_STATE_CALCULATION_WINDOW_LOADED;
                    }
                    else if( sa.CalculationWindowIndex == sa.TimeWindowCount )
                    {
                        m_state = CALCULATION_CONTEXT_STATE_FINISHED;
                        ret     = CC_OK;
                        break;
                    }
                    else
                    {
                        sa.NsTimeAggregationWindowStop = sa.TimeWindows[sa.CalculationWindowIndex].Start;
                        m_state                        = CALCULATION_CONTEXT_STATE_CALCULATION_WINDOW_LOADED;
                    }
                }

                if( m_state == CALCULATION_CONTEXT_STATE_CALCULATION_WINDOW_LOADED )
                {
                    if( !EnsureDataAtTimestamp<false>( sa.TimeWindows[sa.CalculationWindowIndex].Start ) )
                    {
                        continue;
                    }

                    UpdateAggregationWindowStop();

                    if( IsEnoughData() )
                    {
                        // all streams started before the first calculation window
                        Interpolate( sa.TimeWindows[sa.CalculationWindowIndex].Start );
                        m_calculationManager->AggregateCounters( m_aggregationContext );

                        sa.OutAggregatedRawDataSize += sa.RawReportSize;
                        m_state = CALCULATION_CONTEXT_STATE_SEEK_AGGREGATION_WINDOW;
                    }
                    else
                    {
                        uint64_t firstSampleTimestamp = 0;

                        for( uint32_t i = 0; i < m_dataSetCount; ++i )
                        {
                            if( sa.PrevRawDataPtrs[i] )
                            {
                                continue;
                            }

                            if( sa.CurrentTs[i] > firstSampleTimestamp )
                            {
                                firstSampleTimestamp = sa.CurrentTs[i];
                            }
                        }

                        sa.NsTimeFirstReport = firstSampleTimestamp;
                        m_state              = CALCULATION_CONTEXT_STATE_AGGREGATION_WINDOW_START_REACHED;
                    }
                }

                if( m_state == CALCULATION_CONTEXT_STATE_AGGREGATION_WINDOW_START_REACHED )
                {
                    if( sa.NsTimeFirstReport < sa.NsTimeAggregationWindowStop )
                    {
                        if( !EnsureDataAtTimestamp<false>( sa.NsTimeFirstReport ) )
                        {
                            continue;
                        }

                        Interpolate( sa.NsTimeFirstReport );
                        m_calculationManager->AggregateCounters( m_aggregationContext );

                        sa.OutAggregatedRawDataSize += sa.RawReportSize;
                        m_state = CALCULATION_CONTEXT_STATE_SEEK_AGGREGATION_WINDOW;
                    }
                    else
                    {
                        UpdateAggregationWindowStop();
                    }
                }

                if( m_state == CALCULATION_CONTEXT_STATE_SEEK_AGGREGATION_WINDOW )
                {
                    if( !EnsureDataAtTimestamp<false>( sa.NsTimeAggregationWindowStop ) )
                    {
                        continue;
                    }

                    Interpolate( sa.NsTimeAggregationWindowStop );
                    m_calculationManager->AggregateCounters( m_aggregationContext );

                    sa.OutAggregatedRawDataSize += sa.RawReportSize;

                    if( sa.NsTimeAggregationWindowStop >= sa.TimeWindows[sa.CalculationWindowIndex].End )
                    {
                        sa.CalculationWindowIndex++;
                        sa.IsNewCalculationWindow = true;

                        m_state = CALCULATION_CONTEXT_STATE_LOAD_CALCULATION_WINDOW;
                    }
                    else
                    {
                        UpdateAggregationWindowStop();
                    }
                }
            }
            while( m_state != CALCULATION_CONTEXT_STATE_FINISHED );
        }

        if( m_type == CALCULATION_CONTEXT_TYPE_IO_STREAM )
        {
            *outAggregatedRawDataSize = sa.OutAggregatedRawDataSize;

            for( uint32_t i = 0; i < m_dataSetCount; ++i )
            {
                if( sa.LastRawDataPtrs[i] != nullptr && !sa.IsLastRawDataPresent[i] )
                {
                    iu_memcpy_s( sa.LastSavedReportPtrs[i], sa.RawReportSize, sa.LastRawDataPtrs[i], sa.RawReportSize );
                    sa.IsLastRawDataPresent[i] = true;
                }
                if( sa.PrevRawDataPtrs[i] != nullptr && !sa.IsPrevRawDataPresent[i] )
                {
                    iu_memcpy_s( sa.PrevSavedReportPtrs[i], sa.RawReportSize, sa.PrevRawDataPtrs[i], sa.RawReportSize );
                    sa.IsPrevRawDataPresent[i] = true;
                }
            }
        }

        MD_LOG_EXIT();
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     CalculateMetrics
    //
    // Description:
    //     This method processes the provided raw data buffer and calculates metric values
    //     according to the current calculation context and metric set configuration.
    //     It supports both IO stream and delta query measurement types, validates input
    //     parameters, and fills the output buffer with calculated metric values.
    //     Optionally, it can also compute maximum values for each metric if the
    //     corresponding buffer is provided.
    //
    // Input:
    //     const uint8_t*   rawData          - Pointer to the buffer containing raw report data.
    //     uint32_t         rawDataSize      - Size (in bytes) of the raw report data buffer.
    //     TTypedValue_1_0* out              - Pointer to the buffer where calculated metric values will be stored.
    //     uint32_t         outSize          - Size (in bytes) of the output buffer.
    //     uint32_t*        outReportCount   - Pointer to a variable that will receive the number of calculated reports (can be nullptr).
    //     TTypedValue_1_0* outMaxValues     - Pointer to the buffer where maximum metric values will be stored (can be nullptr).
    //     uint32_t         outMaxValuesSize - Size (in bytes) of the max values output buffer.
    //
    // Output:
    //     TCompletionCode - *CC_OK* on success, or an appropriate error code on failure.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CCalculationContext::CalculateMetrics( const uint8_t* rawData, uint32_t rawDataSize, TTypedValue_1_0* out, uint32_t outSize, uint32_t* outReportCount, TTypedValue_1_0* outMaxValues, uint32_t outMaxValuesSize )
    {
        return CalculateMetricsInternal<false>( rawData, rawDataSize, out, outSize, outReportCount, outMaxValues, outMaxValuesSize );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     CalculateMetricsInternal
    //
    // Description:
    //     This method processes the provided raw data buffer and calculates metric values
    //     according to the current calculation context and metric set configuration.
    //     It supports both IO stream and delta query measurement types, validates input
    //     parameters, and fills the output buffer with calculated metric values.
    //     Optionally, it can also compute maximum values for each metric if the
    //     corresponding buffer is provided.
    //
    // Input:
    //     const uint8_t*   rawData          - Pointer to the buffer containing raw report data.
    //     uint32_t         rawDataSize      - Size (in bytes) of the raw report data buffer.
    //     TTypedValue_1_0* out              - Pointer to the buffer where calculated metric values will be stored.
    //     uint32_t         outSize          - Size (in bytes) of the output buffer.
    //     uint32_t*        outReportCount   - Pointer to a variable that will receive the number of calculated reports (can be nullptr).
    //     TTypedValue_1_0* outMaxValues     - Pointer to the buffer where maximum metric values will be stored (can be nullptr).
    //     uint32_t         outMaxValuesSize - Size (in bytes) of the max values output buffer.
    //
    // Output:
    //     TCompletionCode - *CC_OK* on success, or an appropriate error code on failure.
    //
    //////////////////////////////////////////////////////////////////////////////
    template <bool async>
    TCompletionCode CCalculationContext::CalculateMetricsInternal( const uint8_t* rawData, uint32_t rawDataSize, TTypedValue_1_0* out, uint32_t outSize, uint32_t* outReportCount, TTypedValue_1_0* outMaxValues, uint32_t outMaxValuesSize )
    {
        MD_LOG_ENTER();

        if constexpr( async )
        {
            if( m_type != CALCULATION_CONTEXT_TYPE_IO_STREAM )
            {
                MD_LOG( LOG_ERROR, "Async metrics calculation is only supported for IoStream measurements" );
                MD_LOG_EXIT();
                return CC_ERROR_NOT_SUPPORTED;
            }
        }

        MD_CHECK_PTR_RET( m_calculationContext.CommonCalculationContext.Calculator, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( m_calculationContext.CommonCalculationContext.MetricSet, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( rawData, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET( out, CC_ERROR_INVALID_PARAMETER );

        if( !rawDataSize )
        {
            MD_LOG( LOG_DEBUG, "nothing to calculate, rawDataSize: 0" );
            MD_LOG_EXIT();
            return CC_OK;
        }
        if( !outMaxValues || !outMaxValuesSize )
        {
            MD_LOG( LOG_DEBUG, "max values won't be calculated, outMaxValues: %p, outMaxValuesSize: %u", outMaxValues, outMaxValuesSize );
            outMaxValues     = nullptr;
            outMaxValuesSize = 0;
        }

        MD_CHECK_PTR_RET( m_metricSet, CC_ERROR_INVALID_PARAMETER );

        if( !m_metricSet->IsFiltered() )
        {
            MD_LOG( LOG_ERROR, "error: API filtering must be enabled first" );
            MD_LOG_EXIT();
            return CC_ERROR_GENERAL;
        }

        TMetricSetParamsLatest* params = m_metricSet->GetParams();
        MD_CHECK_PTR_RET( params, CC_ERROR_INVALID_PARAMETER );

        if( ( params->MetricsCount + params->InformationCount ) == 0 )
        {
            // May happen when unsupported API is used in MetricSet filtering
            MD_LOG( LOG_WARNING, "nothing to calculate, empty MetricSet" );
            MD_LOG_EXIT();
            return CC_OK;
        }

        const uint32_t rawReportSize  = m_calculationContext.CommonCalculationContext.RawReportSize;
        const uint32_t rawReportCount = rawDataSize / rawReportSize;

        // Validation
        auto ret = ValidateCalculateMetricsParams( params, rawDataSize, rawReportSize, rawReportCount, outSize, outMaxValuesSize );
        MD_CHECK_CC_RET( ret );

        m_calculationContext.CommonCalculationContext.Out            = out;
        m_calculationContext.CommonCalculationContext.OutMaxValues   = outMaxValues;
        m_calculationContext.CommonCalculationContext.RawData        = rawData;
        m_calculationContext.CommonCalculationContext.RawReportCount = rawReportCount;
        m_calculationContext.CommonCalculationContext.OutReportCount = 0;

        if( m_type == CALCULATION_CONTEXT_TYPE_IO_STREAM )
        {
            TStreamCalculationContext& sc = m_calculationContext.StreamCalculationContext;

            sc.PrevRawDataPtr      = sc.RawData;
            sc.PrevRawReportNumber = 0;
            sc.LastRawDataPtr      = sc.RawData;
            sc.LastRawReportNumber = 0;
        }

        MD_LOG( LOG_DEBUG, "about to calculate %u raw reports", rawReportCount );

        // CALCULATE METRICS
        if constexpr( async )
        {
            while( m_calculationManager->CalculateNextAsyncReport( m_calculationContext ) )
            { // void
            }
        }
        else
        {
            while( m_calculationManager->CalculateNextReport( m_calculationContext ) )
            { // void
            }
        }

        MD_LOG( LOG_DEBUG, "calculated %u out reports", m_calculationContext.CommonCalculationContext.OutReportCount );
        MD_LOG( LOG_DEBUG, "max values%s calculated", outMaxValues ? "" : " not" );

        if( outReportCount )
        {
            *outReportCount = m_calculationContext.CommonCalculationContext.OutReportCount;
        }

        MD_LOG_EXIT();
        return CC_OK;
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     CalculateSingleWindowMetrics
    //
    // Description:
    //     Calculates metrics for a single aggregation window using the provided raw data sets.
    //     This method aggregates raw reports from multiple data sets into a single output buffer
    //     for one aggregation window, then calculates metric values and optional maximum values
    //     for the aggregated data.
    //
    // Input:
    //     const uint8_t**  rawData                  - Array of pointers to raw data buffers for each data set.
    //     const uint32_t*  rawDataSizes             - Array of sizes (in bytes) for each raw data buffer.
    //     uint32_t*        outProcessedRawDataCount - Array to receive the count of processed raw data for each data set.
    //     TTypedValue_1_0* out                      - Buffer to store calculated metric values.
    //     uint32_t         outSize                  - Size (in bytes) of the output buffer for metric values.
    //     TTypedValue_1_0* outMaxValues             - Buffer to store calculated maximum metric values (optional).
    //     uint32_t         outMaxValuesSize         - Size (in bytes) of the output buffer for max values.
    //     bool             lastDataPortion          - Indicates if this is the last portion of data.
    //
    // Output:
    //     TCompletionCode - CC_OK on success, or an appropriate error code on failure.
    //
    ///////////////////////////////////////////////////////////////////////////////
    TCompletionCode CCalculationContext::CalculateSingleWindowMetrics( const uint8_t** rawData, const uint32_t* rawDataSizes, uint32_t* outProcessedRawDataCount, TTypedValue_1_0* out, uint32_t outSize, TTypedValue_1_0* outMaxValues, uint32_t outMaxValuesSize, bool lastDataPortion )
    {
        MD_LOG_ENTER();

        TCompletionCode            ret = CC_OK;
        TStreamAggregationContext& sa  = m_aggregationContext.StreamAggregationContext;

        uint32_t size = sa.OutAggregatedRawDataSize;

        ret = AggregateSingleWindow( rawData, rawDataSizes, sa.OutAggregatedRawDataPtr + sa.OutAggregatedRawDataSize, outProcessedRawDataCount, lastDataPortion );

        if( !sa.OutAggregatedRawDataSize && ret == CC_OK )
        {
            // Could not aggregate any data
            ret = CC_NO_RESULT;
        }

        sa.OutAggregatedRawDataSize += size;

        MD_CHECK_CC_RET( ret );

        ret = CalculateMetrics( sa.OutAggregatedRawDataPtr, sa.OutAggregatedRawDataSize, out, outSize, nullptr, outMaxValues, outMaxValuesSize );
        MD_CHECK_CC_RET( ret );

        if( sa.OutAggregatedRawDataSize != 0 )
        {
            iu_memset( sa.OutAggregatedRawDataPtr, 0x00, sa.RawReportSize * 2 );
            sa.OutAggregatedRawDataSize = 0;
        }

        MD_LOG_EXIT();
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     ValidateCalculateMetricsParams
    //
    // Description:
    //     Validates the parameters required for metric calculation to ensure buffer sizes and counts are correct.
    //     Checks that the raw data buffer, output buffer, and max values buffer (if provided) are properly sized
    //     and aligned with the metric set's configuration. Returns an error code if any validation fails.
    //
    // Input:
    //     TMetricSetParamsLatest* params           - Pointer to the metric set parameters structure.
    //     uint32_t                rawDataSize      - Size (in bytes) of the raw report data buffer.
    //     uint32_t                rawReportSize    - Size (in bytes) of a single raw report.
    //     uint32_t                rawReportCount   - Number of raw reports in the input buffer.
    //     uint32_t                outSize          - Size (in bytes) of the output buffer.
    //     uint32_t                outMaxValuesSize - Size (in bytes) of the output buffer for max values
    //
    // Output:
    //     TCompletionCode - *CC_OK* if all parameters are valid, or an appropriate error code if validation fails.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CCalculationContext::ValidateCalculateMetricsParams( TMetricSetParamsLatest* params, uint32_t rawDataSize, uint32_t rawReportSize, uint32_t rawReportCount, uint32_t outSize, uint32_t outMaxValuesSize )
    {
        // Size of one individual calculated report in bytes
        uint32_t outReportSize = ( params->MetricsCount + params->InformationCount ) * sizeof( TTypedValue_1_0 );
        // Size of one individual calculated max values report in bytes
        uint32_t maxValuesReportSize = params->MetricsCount * sizeof( TTypedValue_1_0 );

        MD_ASSERT( rawReportSize != 0 );

        if( rawDataSize % rawReportSize != 0 )
        {
            MD_LOG( LOG_ERROR, "error: input buffer has incorrect size" );
            MD_LOG( LOG_DEBUG, "rawDataSize: %u, rawReportSize: %u", rawDataSize, rawReportSize );
            return CC_ERROR_INVALID_PARAMETER;
        }
        if( outReportSize == 0 )
        {
            MD_LOG( LOG_DEBUG, "outReportSize: 0. Nothing to calculate." );
            return CC_OK;
        }
        if( outSize % outReportSize != 0 )
        {
            MD_LOG( LOG_ERROR, "error: output buffer has incorrect size" );
            MD_LOG( LOG_DEBUG, "outSize: %u, outReportSize: %u", outSize, outReportSize );
            return CC_ERROR_INVALID_PARAMETER;
        }

        // IO stream calculates one less report when no saved report is present yet.
        const bool     noReportPresent      = ( m_type == CALCULATION_CONTEXT_TYPE_IO_STREAM ) && !m_calculationContext.StreamCalculationContext.Calculator->SavedReportPresent();
        const uint32_t outReportCapacity    = ( noReportPresent ) ? ( outSize / outReportSize ) + 1 : ( outSize / outReportSize );
        const uint32_t outMaxValuesCapacity = ( maxValuesReportSize == 0 ) ? 0 : ( noReportPresent ) ? ( outMaxValuesSize / maxValuesReportSize ) + 1
                                                                                                     : ( outMaxValuesSize / maxValuesReportSize );

        if( rawReportCount > outReportCapacity )
        {
            MD_LOG( LOG_ERROR, "error: output buffer too small" );
            MD_LOG( LOG_DEBUG, "rawReportCount: %u, outSize: %u, outReportSize: %u", rawReportCount, outSize, outReportSize );
            return CC_ERROR_INVALID_PARAMETER;
        }
        if( outMaxValuesSize && maxValuesReportSize && rawReportCount > outMaxValuesCapacity )
        {
            MD_LOG( LOG_ERROR, "error: maxValues buffer too small" );
            MD_LOG( LOG_DEBUG, "rawReportCount: %u, outMaxValuesSize: %u, maxValueReportSize: %u", rawReportCount, outMaxValuesSize, maxValuesReportSize );
            return CC_ERROR_INVALID_PARAMETER;
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     ValidateCalculationContextDescriptor
    //
    // Description:
    //     Validates the provided calculation context descriptor by ensuring that:
    //     - The descriptor is not null and contains valid metric sets.
    //     - All metric sets and concurrent groups have consistent names.
    //     - The API mask is compatible with the calculation context type (e.g., IO Stream or Query).
    //
    // Input:
    //     TCalculationContextDescriptorLatest& calculationContextDescriptor - Reference to the calculation context descriptor
    //
    // Output:
    //     TCompletionCode - CC_OK if the descriptor is valid, otherwise returns CC_ERROR_INVALID_PARAMETER
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CCalculationContext::ValidateCalculationContextDescriptor( TCalculationContextDescriptorLatest& calculationContextDescriptor )
    {
        MD_LOG_ENTER();

        if( calculationContextDescriptor.DataSetCount == 0 )
        {
            MD_LOG( LOG_ERROR, "DataSetCount is 0" );
            return CC_ERROR_INVALID_PARAMETER;
        }

        auto ret = ValidateTimeWindows( calculationContextDescriptor );
        MD_CHECK_CC_RET( ret );

        // Retrieve the first metric set for comparison
        CMetricSet* baseMetricSet = (CMetricSet*) ( calculationContextDescriptor.MetricSets[0] );
        MD_CHECK_PTR_RET( baseMetricSet, CC_ERROR_INVALID_PARAMETER );

        const TMetricSetParamsLatest* baseMetricSetParams     = baseMetricSet->GetParams();
        const std::string_view        baseMetricSetName       = baseMetricSetParams->SymbolName;
        const uint32_t                baseMetricsCount        = baseMetricSetParams->MetricsCount;
        const uint32_t                baseInformationCount    = baseMetricSetParams->InformationCount;
        const std::string_view        baseConcurrentGroupName = baseMetricSet->GetConcurrentGroup()->GetParams()->SymbolName;
        const uint32_t                baseApiMask             = baseMetricSetParams->ApiMask;
        const TCalculationContextType calculationContextType  = calculationContextDescriptor.Type;

        ret = ValidateApiMask( calculationContextType, baseApiMask );
        MD_CHECK_CC_RET( ret );

        for( uint32_t i = 1; i < calculationContextDescriptor.DataSetCount; ++i )
        {
            CMetricSet* metricSet = (CMetricSet*) ( calculationContextDescriptor.MetricSets[i] );
            MD_CHECK_PTR_RET( metricSet, CC_ERROR_INVALID_PARAMETER );

            // Validate API mask based on calculation context type
            const TMetricSetParamsLatest* params  = metricSet->GetParams();
            const uint32_t                apiMask = params->ApiMask;

            ret = ValidateApiMask( calculationContextType, apiMask );
            MD_CHECK_CC_RET( ret );

            // Validate metric set and concurrent group names/counts
            const std::string_view metricSetName       = params->SymbolName;
            const uint32_t         metricsCount        = params->MetricsCount;
            const uint32_t         informationCount    = params->InformationCount;
            const std::string_view concurrentGroupName = metricSet->GetConcurrentGroup()->GetParams()->SymbolName;

            if( metricsCount != baseMetricsCount )
            {
                MD_LOG( LOG_INFO, "Metric set metrics count mismatch: %u vs %u", metricsCount, baseMetricsCount );
                return CC_ERROR_INVALID_PARAMETER;
            }
            if( informationCount != baseInformationCount )
            {
                MD_LOG( LOG_INFO, "Metric set information count mismatch: %u vs %u", informationCount, baseInformationCount );
                return CC_ERROR_INVALID_PARAMETER;
            }
            if( baseMetricSetName != metricSetName )
            {
                MD_LOG( LOG_INFO, "Metric set names are not the same: MetricSet[0]:%.*s, MetricSet[%u]: %.*s", static_cast<uint32_t>( baseMetricSetName.length() ), baseMetricSetName.data(), i, static_cast<uint32_t>( metricSetName.length() ), metricSetName.data() );
                return CC_ERROR_INVALID_PARAMETER;
            }
            if( baseConcurrentGroupName != concurrentGroupName )
            {
                MD_LOG( LOG_INFO, "Concurrent Groups are not the same: ConcurrentGroup[0]:%.*s, ConcurrentGroup[%u]: %.*s", static_cast<uint32_t>( baseConcurrentGroupName.length() ), baseConcurrentGroupName.data(), i, static_cast<uint32_t>( concurrentGroupName.length() ), concurrentGroupName.data() );
                return CC_ERROR_INVALID_PARAMETER;
            }

            // Additional check: for each metric in firstMetricSet, ensure it exists in metricSet and equations match
            for( uint32_t j = 0; j < baseMetricsCount; ++j )
            {
                IMetricLatest* baseMetric = baseMetricSet->GetMetric( j );
                MD_CHECK_PTR_RET( baseMetric, CC_ERROR_INVALID_PARAMETER );
                TMetricParamsLatest*   baseParams     = baseMetric->GetParams();
                const std::string_view baseMetricName = baseParams->SymbolName;
                bool                   found          = false;

                for( uint32_t k = 0; k < metricsCount; ++k )
                {
                    IMetricLatest* metric = metricSet->GetMetric( k );
                    MD_CHECK_PTR_RET( metric, CC_ERROR_INVALID_PARAMETER );
                    TMetricParamsLatest*   metricParams = metric->GetParams();
                    const std::string_view metricName   = metricParams->SymbolName;

                    if( baseMetricName == metricName )
                    {
                        ret = AreMetricsEqual( baseParams, metricParams, calculationContextType );
                        MD_CHECK_CC_RET( ret );

                        found = true;
                        break;
                    }
                }
                if( !found )
                {
                    MD_LOG( LOG_INFO, "Metric %.*s not found in metric set %.*s", static_cast<uint32_t>( baseMetricName.length() ), baseMetricName.data(), static_cast<uint32_t>( metricSetName.length() ), metricSetName.data() );
                    return CC_ERROR_INVALID_PARAMETER;
                }
            }
        }

        MD_LOG_EXIT();
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     ValidateTimeWindows
    //
    // Description:
    //     Validates the time windows specified in the calculation context descriptor for IO stream aggregation.
    //     This method checks that each time window has a start time less than or equal to its end time
    //     and that the sequence of time windows is strictly increasing and non-overlapping.
    //
    // Input:
    //     TCalculationContextDescriptorLatest& calculationContextDescriptor - Reference to the calculation context descriptor
    //                                                                         containing the time windows to validate.
    //
    // Output:
    //     TCompletionCode - CC_OK if all time windows are valid or not present; otherwise, returns CC_ERROR_INVALID_PARAMETER.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CCalculationContext::ValidateTimeWindows( TCalculationContextDescriptorLatest& calculationContextDescriptor )
    {
        if( calculationContextDescriptor.IoStreamDescriptor.TimeWindowCount > 0 )
        {
            MD_CHECK_PTR_RET( calculationContextDescriptor.IoStreamDescriptor.TimeWindows, CC_ERROR_INVALID_PARAMETER );
        }

        if( const auto timeWindows = calculationContextDescriptor.IoStreamDescriptor.TimeWindows;
            timeWindows )
        {
            // Validate if time windows are increasing
            if( timeWindows[0].Start > timeWindows[0].End )
            {
                MD_LOG( LOG_INFO, "Start time is greater than end time. Start time = %llu, End time = %llu", timeWindows[0].Start, timeWindows[0].End );
                return CC_ERROR_INVALID_PARAMETER;
            }

            for( uint32_t i = 1; i < calculationContextDescriptor.IoStreamDescriptor.TimeWindowCount; ++i )
            {
                const auto& previous = timeWindows[i - 1];
                const auto& current  = timeWindows[i];

                if( !( previous.End <= current.Start && current.Start < current.End ) )
                {
                    MD_LOG( LOG_INFO, "Invalid time window: previous.End = %llu, current.Start = %llu, current.End = %llu", previous.End, current.Start, current.End );
                    return CC_ERROR_INVALID_PARAMETER;
                }
            }
        }
        else
        {
            MD_LOG( LOG_INFO, "Time windows are not provided" );
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     ValidateApiMask
    //
    // Description:
    //     Validates that the provided API mask is compatible with the specified calculation context type.
    //     This method checks that each time window has a start time less than or equal to its end time
    //     and that the sequence of time windows is strictly increasing and non-overlapping.
    //
    // Input:
    //     TCalculationContextType calculationContextType - The type of calculation context (e.g., IO stream or Query).
    //     uint32_t                apiMask                - The API mask to validate.
    //
    // Output:
    //     TCompletionCode - CC_OK if the API mask is valid for the context type; otherwise, returns CC_ERROR_INVALID_PARAMETER.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CCalculationContext::ValidateApiMask( TCalculationContextType calculationContextType, uint32_t apiMask )
    {
        switch( calculationContextType )
        {
            case CALCULATION_CONTEXT_TYPE_IO_STREAM:
                if( ( apiMask & API_TYPE_IOSTREAM ) == 0 )
                {
                    MD_LOG( LOG_INFO, "Calculation context type is IO_STREAM but API_TYPE_IOSTREAM is not set in apiMask: %u", apiMask );
                    return CC_ERROR_INVALID_PARAMETER;
                }
                break;

            case CALCULATION_CONTEXT_TYPE_QUERY:
                if( ( apiMask & MD_QUERY_API_MASK ) == 0 )
                {
                    MD_LOG( LOG_INFO, "Calculation context type is QUERY but MD_QUERY_API_MASK is not set in apiMask: %u", apiMask );
                    return CC_ERROR_INVALID_PARAMETER;
                }
                break;

            default:
                MD_LOG( LOG_INFO, "Unsupported calculation context type: %u", calculationContextType );
                return CC_ERROR_INVALID_PARAMETER;
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     AreMetricsEqual
    //
    // Description:
    //     Compares two metric parameter structures to determine if they are functionally
    //     equivalent for the given calculation context type.
    //
    // Input:
    //     TMetricParamsLatest*    baseParams             - Pointer to the base metric parameters.
    //     TMetricParamsLatest*    metricParams           - Pointer to the metric parameters to compare.
    //     TCalculationContextType calculationContextType - Calculation context type (IO stream or query).
    //
    // Output:
    //     TCompletionCode - CC_OK if all parameters and equations match or CC_ERROR_INVALID_PARAMETER if any mismatch is found.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CCalculationContext::AreMetricsEqual( TMetricParamsLatest* baseParams, TMetricParamsLatest* metricParams, TCalculationContextType calculationContextType )
    {
        TCompletionCode ret = CC_OK;

        ret = ValidateMetricParams( baseParams->GroupId, metricParams->GroupId, "GroupId" );
        MD_CHECK_CC_RET( ret );

        ret = ValidateMetricParams( baseParams->ShortName, metricParams->ShortName, "ShortName" );
        MD_CHECK_CC_RET( ret );

        ret = ValidateMetricParams( baseParams->GroupName, metricParams->GroupName, "GroupName" );
        MD_CHECK_CC_RET( ret );

        ret = ValidateMetricParams( baseParams->LongName, metricParams->LongName, "LongName" );
        MD_CHECK_CC_RET( ret );

        ret = ValidateMetricParams( baseParams->DxToOglAlias, metricParams->DxToOglAlias, "DxToOglAlias" );
        MD_CHECK_CC_RET( ret );

        ret = ValidateMetricParams( baseParams->UsageFlagsMask, metricParams->UsageFlagsMask, "UsageFlagsMask" );
        MD_CHECK_CC_RET( ret );

        ret = ValidateMetricParams( baseParams->ApiMask, metricParams->ApiMask, "ApiMask" );
        MD_CHECK_CC_RET( ret );

        ret = ValidateMetricParams( baseParams->ResultType, metricParams->ResultType, "ResultType" );
        MD_CHECK_CC_RET( ret );

        ret = ValidateMetricParams( baseParams->MetricResultUnits, metricParams->MetricResultUnits, "MetricResultUnits" );
        MD_CHECK_CC_RET( ret );

        ret = ValidateMetricParams( baseParams->MetricType, metricParams->MetricType, "MetricType" );
        MD_CHECK_CC_RET( ret );

        ret = ValidateMetricParams( baseParams->LowWatermark, metricParams->LowWatermark, "LowWatermark" );
        MD_CHECK_CC_RET( ret );

        ret = ValidateMetricParams( baseParams->HighWatermark, metricParams->HighWatermark, "HighWatermark" );
        MD_CHECK_CC_RET( ret );

        ret = ValidateMetricParams( baseParams->HwUnitType, metricParams->HwUnitType, "HwUnitType" );
        MD_CHECK_CC_RET( ret );

        ret = ValidateMetricParams( baseParams->QueryModeMask, metricParams->QueryModeMask, "QueryModeMask" );
        MD_CHECK_CC_RET( ret );

        if( calculationContextType == CALCULATION_CONTEXT_TYPE_IO_STREAM )
        {
            if( baseParams->DeltaFunction.BitsCount != metricParams->DeltaFunction.BitsCount ||
                baseParams->DeltaFunction.FunctionType != metricParams->DeltaFunction.FunctionType )
            {
                MD_LOG( LOG_INFO, "Delta function mismatch" );
                return CC_ERROR_INVALID_PARAMETER;
            }

            ret = ValidateMetricEquations( baseParams->IoReadEquation, metricParams->IoReadEquation );
            MD_CHECK_CC_RET( ret );
        }
        else if( calculationContextType == CALCULATION_CONTEXT_TYPE_QUERY )
        {
            ret = ValidateMetricEquations( baseParams->QueryReadEquation, metricParams->QueryReadEquation );
            MD_CHECK_CC_RET( ret );
        }

        ret = ValidateMetricEquations( baseParams->NormEquation, metricParams->NormEquation );
        MD_CHECK_CC_RET( ret );

        ret = ValidateMetricEquations( baseParams->MaxValueEquation, metricParams->MaxValueEquation );
        MD_CHECK_CC_RET( ret );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     ValidateMetricEquations
    //
    // Description:
    //     Compares two metric equations element-by-element to ensure they are functionally equivalent.
    //     This method checks that both equations are either null or non-null, have the same number of elements
    //     mask size and data, operation type, read parameters, and symbol name).
    //
    // Input:
    //     IEquationLatest* baseEquation   - Pointer to the reference equation.
    //     IEquationLatest* metricEquation - Pointer to the equation to validate against the reference.
    //
    // Output:
    //     TCompletionCode - CC_OK if the equations are equivalent or both are null. CC_ERROR_INVALID_PARAMETER if any mismatch is found.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CCalculationContext::ValidateMetricEquations( IEquationLatest* baseEquation, IEquationLatest* metricEquation )
    {
        if( baseEquation && metricEquation )
        {
            const uint32_t baseEquationCount   = baseEquation->GetEquationElementsCount();
            const uint32_t metricEquationCount = metricEquation->GetEquationElementsCount();

            if( baseEquationCount != metricEquationCount )
            {
                MD_LOG( LOG_INFO, "Equation element count mismatch: %u vs %u", baseEquationCount, metricEquationCount );
                return CC_ERROR_INVALID_PARAMETER;
            }

            for( uint32_t i = 0; i < baseEquationCount; ++i )
            {
                const auto baseElement = baseEquation->GetEquationElement( i );
                MD_CHECK_PTR_RET( baseElement, CC_ERROR_INVALID_PARAMETER );
                const auto metricElement = metricEquation->GetEquationElement( i );
                MD_CHECK_PTR_RET( metricElement, CC_ERROR_INVALID_PARAMETER );

                if( baseElement->Type != metricElement->Type )
                {
                    MD_LOG( LOG_INFO, "Equation type mismatch" );
                    return CC_ERROR_INVALID_PARAMETER;
                }

                switch( baseElement->Type )
                {
                    case EQUATION_ELEM_IMM_UINT64:
                        if( baseElement->ImmediateUInt64 != metricElement->ImmediateUInt64 )
                        {
                            MD_LOG( LOG_INFO, "ImmediateUInt64 mismatch" );
                            return CC_ERROR_INVALID_PARAMETER;
                        }
                        break;

                    case EQUATION_ELEM_IMM_FLOAT:
                        if( baseElement->ImmediateFloat != metricElement->ImmediateFloat )
                        {
                            MD_LOG( LOG_INFO, "ImmediateFloat mismatch" );
                            return CC_ERROR_INVALID_PARAMETER;
                        }
                        break;

                    case EQUATION_ELEM_RD_BITFIELD:
                    case EQUATION_ELEM_RD_UINT8:
                    case EQUATION_ELEM_RD_UINT16:
                    case EQUATION_ELEM_RD_UINT32:
                    case EQUATION_ELEM_RD_UINT64:
                    case EQUATION_ELEM_RD_FLOAT:
                    case EQUATION_ELEM_RD_40BIT_CNTR:
                        if( baseElement->ReadParams.ByteOffset != metricElement->ReadParams.ByteOffset ||
                            baseElement->ReadParams.BitOffset != metricElement->ReadParams.BitOffset ||
                            baseElement->ReadParams.BitsCount != metricElement->ReadParams.BitsCount ||
                            baseElement->ReadParams.ByteOffsetExt != metricElement->ReadParams.ByteOffsetExt )
                        {
                            MD_LOG( LOG_INFO, "ReadParams mismatch" );
                            return CC_ERROR_INVALID_PARAMETER;
                        }
                        break;

                    case EQUATION_ELEM_MASK:
                        if( baseElement->Mask.Size != metricElement->Mask.Size )
                        {
                            MD_LOG( LOG_INFO, "Mask size mismatch" );
                            return CC_ERROR_INVALID_PARAMETER;
                        }

                        if( !iu_memcmp( baseElement->Mask.Data, metricElement->Mask.Data, baseElement->Mask.Size ) )
                        {
                            MD_LOG( LOG_INFO, "Mask data mismatch" );
                            return CC_ERROR_INVALID_PARAMETER;
                        }
                        break;

                    case EQUATION_ELEM_OPERATION:
                        if( baseElement->Operation != metricElement->Operation )
                        {
                            MD_LOG( LOG_INFO, "Operation mismatch" );
                            return CC_ERROR_INVALID_PARAMETER;
                        }
                        break;

                    case EQUATION_ELEM_GLOBAL_SYMBOL:
                    case EQUATION_ELEM_LOCAL_COUNTER_SYMBOL:
                    case EQUATION_ELEM_OTHER_SET_COUNTER_SYMBOL:
                    case EQUATION_ELEM_LOCAL_METRIC_SYMBOL:
                    case EQUATION_ELEM_OTHER_SET_METRIC_SYMBOL:
                    case EQUATION_ELEM_INFORMATION_SYMBOL:
                    case EQUATION_ELEM_PREV_METRIC_SYMBOL:
                        if( static_cast<std::string_view>( baseElement->SymbolName ) != metricElement->SymbolName )
                        {
                            MD_LOG( LOG_INFO, "Symbol name mismatch" );
                            return CC_ERROR_INVALID_PARAMETER;
                        }
                        break;

                    case EQUATION_ELEM_SELF_COUNTER_VALUE:
                    case EQUATION_ELEM_STD_NORM_GPU_DURATION:
                    case EQUATION_ELEM_STD_NORM_EU_AGGR_DURATION:
                        break;

                    default:
                        MD_LOG( LOG_INFO, "Unrecognized element type: %u", baseElement->Type );
                        return CC_ERROR_INVALID_PARAMETER;
                }
            }
        }
        else
        {
            if( baseEquation || metricEquation )
            {
                MD_LOG( LOG_INFO, "Equation mismatch" );
                return CC_ERROR_INVALID_PARAMETER;
            }
            // Both equations could be nullptr
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     ValidateMetricParams
    //
    // Description:
    //     Compares two metric character string values for equality. If both are non-null,
    //     checks if their contents are equal. If only one is non-null or the contents differ,
    //     logs a mismatch with the provided field name and returns CC_ERROR_INVALID_PARAMETER.
    //     Returns CC_OK if both are null or both are non-null and equal.
    //
    // Input:
    //     const char* baseValue   - Pointer to the reference string value to compare.
    //     const char* metricValue - Pointer to the string value to validate against the reference.
    //     const char* fieldName   - The name of the field being compared, used for logging.
    //
    // Output:
    //     TCompletionCode - CC_OK if values match, CC_ERROR_INVALID_PARAMETER otherwise.
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CCalculationContext::ValidateMetricParams( const char* baseValue, const char* metricValue, [[maybe_unused]] const char* fieldName )
    {
        if( baseValue && metricValue )
        {
            if( static_cast<std::string_view>( baseValue ) != metricValue )
            {
                MD_LOG( LOG_INFO, "%s mismatch: %s vs %s", fieldName, baseValue, metricValue );
                return CC_ERROR_INVALID_PARAMETER;
            }
        }
        else if( baseValue || metricValue )
        {
            MD_LOG( LOG_INFO, "%s mismatch", fieldName );
            return CC_ERROR_INVALID_PARAMETER;
        }
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     ValidateMetricParams
    //
    // Description:
    //     Compares two metric parameter values of any type for equality.
    //     If the values are not equal, logs a mismatch with the provided
    //     field name and returns CC_ERROR_INVALID_PARAMETER. Returns CC_OK
    //     if the values are equal.
    //
    // Input:
    //     const T& baseValue    - Reference to the reference value to compare.
    //     const T& metricValue  - Reference to the value to validate against the reference.
    //     const char* fieldName - The name of the field being compared, used for logging.
    //
    // Output:
    //     TCompletionCode - CC_OK if values match, CC_ERROR_INVALID_PARAMETER otherwise.
    //
    //////////////////////////////////////////////////////////////////////////////
    template <typename T>
    TCompletionCode CCalculationContext::ValidateMetricParams( const T& baseValue, const T& metricValue, const char* fieldName )
    {
        // In template methods [[maybe_unused]] is ignored by older GCC versions.
        (void) fieldName;

        if( baseValue != metricValue )
        {
            MD_LOG( LOG_INFO, "%s mismatch", fieldName );
            return CC_ERROR_INVALID_PARAMETER;
        }

        return CC_OK;
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     EnsureDataAtTimestamp
    //
    // Description:
    //     Checks whether all data sets in the stream aggregation context have reached the specified
    //     target timestamp, with behavior determined by the timerMode template parameter.
    //     - In timer mode (timerMode = true), marks each data set as needing a report if its current
    //       timestamp is less than the target timestamp. Returns false if any data set requires a report
    //       update, true otherwise.
    //     - If aggregation windows are defined (timerMode = false), finds the minimum current timestamp among
    //       all data sets and marks only those streams at the minimum timestamp as needing a report if they are
    //       less than the target timestamp. Returns false if any such data set requires a report update, true otherwise.
    //
    // Input:
    //     uint64_t timestamp - The target timestamp to check against.
    //
    // Output:
    //     bool - true if all required data sets have reached the target timestamp, false if any need a report.
    //
    ////////////////////////////////////////////////////////////////////////////////
    template <bool timerMode>
    bool CCalculationContext::EnsureDataAtTimestamp( const uint64_t timestamp )
    {
        TStreamAggregationContext& sa         = m_aggregationContext.StreamAggregationContext;
        bool                       needReport = false;

        if constexpr( timerMode )
        {
            // Timer mode: every data set must reach (>=) target timestamp
            for( uint32_t i = 0; i < m_dataSetCount; ++i )
            {
                sa.NeedReport[i] = ( sa.CurrentTs[i] < timestamp );
                if( sa.NeedReport[i] )
                {
                    needReport = true;
                }
            }
        }
        else
        {
            // Aggregation windows defined: advance only those streams that are at the current minimum timestamp
            uint64_t minTimestamp = sa.CurrentTs[0];
            for( uint32_t i = 1; i < m_dataSetCount; ++i )
            {
                if( sa.CurrentTs[i] < minTimestamp )
                {
                    minTimestamp = sa.CurrentTs[i];
                }
            }

            for( uint32_t i = 0; i < m_dataSetCount; ++i )
            {
                if( sa.CurrentTs[i] == minTimestamp && sa.CurrentTs[i] < timestamp )
                {
                    sa.NeedReport[i] = true;
                    needReport       = true;
                }
            }
        }

        return !needReport;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     FilterReport
    //
    // Description:
    //     Filters and selects the next valid raw report for a given data set index in the stream
    //     aggregation context, applying RC6 skip logic and timer-only mode if enabled.
    //
    //     - If RC6 skip mode is active (SkipReportAfterRc6 is true), the method skips reports until
    //       a programming report (REPORT_REASON_INTERNAL_TRIGGER1) is found, then advances to the next
    //       report and clears the skip flag. If timer-only mode is not enabled, returns CC_OK immediately
    //       after clearing the skip flag. If timer-only mode is enabled, continues to filter for timer reports.
    //
    //     - If timer-only mode (isTimerMode) is enabled, the method skips all non-timer reports
    //       (i.e., only reports with REPORT_REASON_INTERNAL_TIMER are selected).
    //
    //     - If an RC6 report (REPORT_REASON_INTERNAL_GO) is encountered, sets the skip flag for the next
    //       call and returns CC_OK.
    //
    //     - Returns CC_OK if a valid report is found, or CC_NOT_ENOUGH_DATA if no more valid reports are
    //       available after applying all filters.
    //
    // Input:
    //     uint32_t dataSetIdx - Index of the data set to filter.
    //     bool     isTimerMode - If true, only timer reports are selected.
    //
    // Output:
    //     TCompletionCode - CC_OK if a valid report is found, CC_NOT_ENOUGH_DATA if no more reports are available.
    //
    ////////////////////////////////////////////////////////////////////////////////
    TCompletionCode CCalculationContext::FilterReport( uint32_t dataSetIdx, bool isTimerMode )
    {
        TStreamAggregationContext& sa           = m_aggregationContext.StreamAggregationContext;
        uint64_t                   reportReason = 0;

        // Helper lambda to advance to next report
        auto advanceReport = [&]()
        {
            if( sa.IsCachedReport[dataSetIdx] )
            {
                sa.CachedReportPtrs[dataSetIdx] += sa.RawReportSize;
                sa.CachedReportPtrsSize[dataSetIdx] -= sa.RawReportSize;

                if( sa.CachedReportPtrsSize[dataSetIdx] == 0 )
                {
                    sa.IsCachedReport[dataSetIdx] = false;
                    return false;
                }

                reportReason = sa.Calculator->ReadInformationByIndex( sa.CachedReportPtrs[dataSetIdx], *sa.BaseMetricSet, sa.ReportReasonIdx );
            }
            else
            {
                sa.RawData[dataSetIdx] += sa.RawReportSize;
                sa.OutReportCount[dataSetIdx]++;

                if( sa.OutReportCount[dataSetIdx] > sa.RawReportCount[dataSetIdx] )
                {
                    return false;
                }

                reportReason = sa.Calculator->ReadInformationByIndex( sa.RawData[dataSetIdx], *sa.BaseMetricSet, sa.ReportReasonIdx );
            }
            return true;
        };

        // If we are in skip mode, skip until after programming report
        if( sa.SkipReportAfterRc6[dataSetIdx] )
        {
            while( advanceReport() )
            {
                if( reportReason & REPORT_REASON_INTERNAL_TRIGGER1 )
                {
                    // Found programming report, now take the next report
                    if( !advanceReport() )
                    {
                        MD_LOG( LOG_DEBUG, "No more reports available after programming for dataSetIdx: %u", dataSetIdx );
                        return CC_NOT_ENOUGH_DATA;
                    }

                    sa.SkipReportAfterRc6[dataSetIdx] = false;

                    if( !isTimerMode )
                    {
                        return CC_OK; // Return CC_OK if not timer mode
                    }

                    break; // Timer mode: continue to timer filtering
                }
            }

            if( sa.SkipReportAfterRc6[dataSetIdx] )
            {
                MD_LOG( LOG_DEBUG, "No more reports available while skipping after RC6 for dataSetIdx: %u", dataSetIdx );
                return CC_NOT_ENOUGH_DATA;
            }
        }

        if( ( sa.OutReportCount[dataSetIdx] == sa.RawReportCount[dataSetIdx] ) && !sa.IsCachedReport[dataSetIdx] )
        {
            MD_LOG( LOG_DEBUG, "No more reports available for dataSetIdx: %u", dataSetIdx );
            return CC_NOT_ENOUGH_DATA;
        }

        // Read current report
        if( sa.IsCachedReport[dataSetIdx] )
        {
            reportReason = sa.Calculator->ReadInformationByIndex( sa.CachedReportPtrs[dataSetIdx], *sa.BaseMetricSet, sa.ReportReasonIdx );
        }
        else
        {
            reportReason = sa.Calculator->ReadInformationByIndex( sa.RawData[dataSetIdx], *sa.BaseMetricSet, sa.ReportReasonIdx );
            sa.OutReportCount[dataSetIdx]++;
        }

        // If timer mode only, skip non-timer reports
        if( isTimerMode )
        {
            // Only take timer reports, skip others
            while( ( reportReason & REPORT_REASON_INTERNAL_TIMER ) == 0 )
            {
                // Advance to next report
                if( !advanceReport() )
                {
                    MD_LOG( LOG_DEBUG, "No more timer reports available for dataSetIdx: %u", dataSetIdx );
                    return CC_NOT_ENOUGH_DATA;
                }
                // Check if the new report is a timer report
                if( sa.IsCachedReport[dataSetIdx] )
                {
                    reportReason = sa.Calculator->ReadInformationByIndex( sa.CachedReportPtrs[dataSetIdx], *sa.BaseMetricSet, sa.ReportReasonIdx );
                }
                else
                {
                    reportReason = sa.Calculator->ReadInformationByIndex( sa.RawData[dataSetIdx], *sa.BaseMetricSet, sa.ReportReasonIdx );
                    sa.OutReportCount[dataSetIdx]++;
                }
            }
        }

        // If RC6 report, set skip mode for next call
        if( reportReason & REPORT_REASON_INTERNAL_GO )
        {
            sa.SkipReportAfterRc6[dataSetIdx] = true;
            return CC_OK; // Take RC6 report
        }

        // Otherwise, take the report
        return CC_OK;
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     GetMaxCurrentTimestamp
    //
    // Description:
    //     Returns the maximum timestamp value among all data sets in the stream aggregation context.
    //     Iterates over the CurrentTs array and finds the largest timestamp for the current aggregation window.
    //
    // Output:
    //     uint64_t - Maximum timestamp value found across all data sets.
    //
    ///////////////////////////////////////////////////////////////////////////////
    uint64_t CCalculationContext::GetMaxCurrentTimestamp() const
    {
        const TStreamAggregationContext& sa    = m_aggregationContext.StreamAggregationContext;
        uint64_t                         maxTs = 0;

        for( uint32_t i = 0; i < m_dataSetCount; ++i )
        {
            if( sa.CurrentTs[i] > maxTs )
            {
                maxTs = sa.CurrentTs[i];
            }
        }

        return maxTs;
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     GetMinCurrentTimestamp
    //
    // Description:
    //     Returns the minimum timestamp value among all data sets in the stream aggregation context.
    //     Iterates over the CurrentTs array and finds the smallest timestamp for the current aggregation window.
    //
    // Output:
    //     uint64_t - Minimum timestamp value found across all data sets.
    //
    ///////////////////////////////////////////////////////////////////////////////
    uint64_t CCalculationContext::GetMinCurrentTimestamp() const
    {
        const TStreamAggregationContext& sa    = m_aggregationContext.StreamAggregationContext;
        uint64_t                         minTs = sa.MaxAggregationWindowInTicks;

        for( uint32_t i = 0; i < m_dataSetCount; ++i )
        {
            if( sa.CurrentTs[i] < minTs )
            {
                minTs = sa.CurrentTs[i];
            }
        }

        return minTs;
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     IsEnoughData
    //
    // Description:
    //     Checks whether all data sets have both previous and last raw data pointers available.
    //     Returns true if every PrevRawDataPtrs[i] and LastRawDataPtrs[i] in the stream aggregation
    //     context are not nullptr. Returns false if any required pointer is missing.
    //
    // Output:
    //     bool - true if all required data pointers are available, false otherwise.
    //
    ///////////////////////////////////////////////////////////////////////////////
    bool CCalculationContext::IsEnoughData() const
    {
        const TStreamAggregationContext& sa = m_aggregationContext.StreamAggregationContext;
        for( uint32_t i = 0; i < m_dataSetCount; ++i )
        {
            if( sa.PrevRawDataPtrs[i] == nullptr || sa.LastRawDataPtrs[i] == nullptr )
            {
                return false;
            }
        }
        return true;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     UpdateAggregationWindowStop
    //
    // Description:
    //     Updates the aggregation window stop timestamp in the stream aggregation context.
    //     This method advances the NsTimeAggregationWindowStop value by the aggregation window size,
    //     or sets it to the maximum value if the window size is unlimited. It also ensures that
    //     the stop timestamp does not exceed the end of the current time window.
    //
    ////////////////////////////////////////////////////////////////////////////////
    void CCalculationContext::UpdateAggregationWindowStop()
    {
        TStreamAggregationContext& sa = m_aggregationContext.StreamAggregationContext;

        if( sa.NsTimeAggregationWindow == sa.MaxAggregationWindowInTicks )
        {
            sa.NsTimeAggregationWindowStop = sa.NsTimeAggregationWindow;
        }
        else
        {
            sa.NsTimeAggregationWindowStop += sa.NsTimeAggregationWindow;
        }

        if( sa.NsTimeAggregationWindowStop > sa.TimeWindows[sa.CalculationWindowIndex].End )
        {
            sa.NsTimeAggregationWindowStop = sa.TimeWindows[sa.CalculationWindowIndex].End;
        }
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     Interpolate
    //
    // Description:
    //     Generates interpolated raw reports for each data set at the specified timestamp.
    //     For each data set, this method linearly interpolates the GpuTicks field and all
    //     PEC and NOA counters between the previous and last reports, according to the
    //     report type and field sizes. The report header fields (ReportId, Timestamp, ContextId)
    //     are set appropriately. If the timestamp matches the last report, the last report is
    //     copied directly. Any remaining bytes in the report are copied from the previous report.
    //     The resulting interpolated reports are written to sa.InterpolatedReportPtrs for each data set.
    //
    // Input:
    //     uint64_t timestamp - The timestamp at which to interpolate the report data.
    //
    // Output:
    //     The interpolated reports are written directly to sa.InterpolatedReportPtrs for each data set.
    //
    ////////////////////////////////////////////////////////////////////////////////
    void CCalculationContext::Interpolate( uint64_t timestamp )
    {
        TStreamAggregationContext& sa            = m_aggregationContext.StreamAggregationContext;
        const uint32_t             rawReportSize = sa.RawReportSize;
        constexpr uint32_t         headerSize    = 4 * sizeof( uint64_t ); // 4 header fields, 8 bytes each

        const bool newCalculationWindow = sa.IsNewCalculationWindow;

        // Reset saved report if starting a new calculation window
        if( sa.IsNewCalculationWindow )
        {
            sa.Calculator->DiscardSavedReport();
            sa.IsNewCalculationWindow = false;
        }

        sa.LastAggregatedTimestamp = timestamp;

        // Determine PEC/NOA sizes based on report type
        uint32_t pecCount    = 0;
        uint32_t pecElemSize = 0;
        uint32_t noaCount    = 0;
        uint32_t noaElemSize = 0;

        switch( sa.MetricSet->GetReportType() )
        {
            case OA_REPORT_TYPE_576B_PEC64LL:
                pecCount    = 64;
                pecElemSize = sizeof( uint64_t );
                break;

            case OA_REPORT_TYPE_640B_PEC64LL_NOA16:
                pecCount    = 64;
                pecElemSize = sizeof( uint64_t );
                noaCount    = 16;
                noaElemSize = sizeof( uint32_t );
                break;

            case OA_REPORT_TYPE_192B_MPEC8LL_NOA16:
                pecCount    = 8;
                pecElemSize = sizeof( uint64_t );
                noaCount    = 16;
                noaElemSize = sizeof( uint32_t );
                break;

            case OA_REPORT_TYPE_128B_MPEC8_NOA16:
                pecCount    = 8;
                pecElemSize = sizeof( uint32_t );
                noaCount    = 16;
                noaElemSize = sizeof( uint32_t );
                break;

            case OA_REPORT_TYPE_128B_MERT_PEC8:
                pecCount    = 8;
                pecElemSize = sizeof( uint32_t );
                break;

            case OA_REPORT_TYPE_192B_MERT_PEC8LL:
                pecCount    = 8;
                pecElemSize = sizeof( uint64_t );
                break;

            default:
                for( uint32_t i = 0; i < m_dataSetCount; ++i )
                {
                    iu_memcpy_s( sa.InterpolatedReportPtrs[i], rawReportSize, sa.LastRawDataPtrs[i], rawReportSize );
                }
                return;
        }

        const uint32_t pecSize = pecCount * pecElemSize;

        for( uint32_t i = 0; i < m_dataSetCount; ++i )
        {
            uint8_t*       interpolatedReport = sa.InterpolatedReportPtrs[i];
            const uint8_t* prev               = sa.PrevRawDataPtrs[i];
            const uint8_t* last               = sa.LastRawDataPtrs[i];
            const uint64_t tsLast             = *reinterpret_cast<const uint64_t*>( last + 8 );

            if( timestamp == tsLast )
            {
                iu_memcpy_s( interpolatedReport, rawReportSize, last, rawReportSize );
                *reinterpret_cast<uint64_t*>( interpolatedReport + 0 )  = newCalculationWindow ? MD_REPORT_ID_SKIP_CALCULATION : 0; // ReportId
                *reinterpret_cast<uint64_t*>( interpolatedReport + 16 ) = 0;                                                        // ContextId
                continue;
            }

            // Header fields
            *reinterpret_cast<uint64_t*>( interpolatedReport + 0 )  = newCalculationWindow ? MD_REPORT_ID_SKIP_CALCULATION : 0; // ReportId
            *reinterpret_cast<uint64_t*>( interpolatedReport + 8 )  = timestamp;                                                // Timestamp
            *reinterpret_cast<uint64_t*>( interpolatedReport + 16 ) = 0;                                                        // ContextId

            const uint64_t tsPrev = *reinterpret_cast<const uint64_t*>( prev + 8 );

            // Compute alpha once
            double alpha = ( tsLast != tsPrev )
                ? static_cast<double>( timestamp - tsPrev ) / static_cast<double>( tsLast - tsPrev )
                : 1.0;

            // GpuTicks interpolation
            const uint64_t prevGpuTicks = *reinterpret_cast<const uint64_t*>( prev + 24 );
            const uint64_t lastGpuTicks = *reinterpret_cast<const uint64_t*>( last + 24 );
            const uint64_t gpuTicks     = ( lastGpuTicks >= prevGpuTicks )
                    ? prevGpuTicks + static_cast<uint64_t>( ( lastGpuTicks - prevGpuTicks ) * alpha )
                    : prevGpuTicks + static_cast<uint64_t>( ( lastGpuTicks + ( std::numeric_limits<uint64_t>::max() - prevGpuTicks + 1 ) ) * alpha ); // Handle overflow case

            *reinterpret_cast<uint64_t*>( interpolatedReport + 24 ) = gpuTicks;

            // PEC interpolation
            const uint8_t* prevPec = prev + headerSize;
            const uint8_t* lastPec = last + headerSize;

            for( uint32_t m = 0; m < pecCount; ++m )
            {
                uint32_t offset = headerSize + m * pecElemSize;

                if( pecElemSize == sizeof( uint64_t ) )
                {
                    const uint64_t valuePrev    = *reinterpret_cast<const uint64_t*>( prevPec + m * sizeof( uint64_t ) );
                    const uint64_t valueLast    = *reinterpret_cast<const uint64_t*>( lastPec + m * sizeof( uint64_t ) );
                    const uint64_t interpolated = ( valueLast >= valuePrev )
                        ? valuePrev + static_cast<uint64_t>( ( valueLast - valuePrev ) * alpha )
                        : valuePrev + static_cast<uint64_t>( ( valueLast + ( std::numeric_limits<uint64_t>::max() - valuePrev + 1 ) ) * alpha ); // Handle overflow case

                    *reinterpret_cast<uint64_t*>( interpolatedReport + offset ) = interpolated;
                }
                else
                {
                    const uint32_t valuePrev    = *reinterpret_cast<const uint32_t*>( prevPec + m * sizeof( uint32_t ) );
                    const uint32_t valueLast    = *reinterpret_cast<const uint32_t*>( lastPec + m * sizeof( uint32_t ) );
                    const uint32_t interpolated = ( valueLast >= valuePrev )
                        ? valuePrev + static_cast<uint32_t>( ( valueLast - valuePrev ) * alpha )
                        : valuePrev + static_cast<uint32_t>( ( valueLast + ( std::numeric_limits<uint32_t>::max() - valuePrev + 1 ) ) * alpha ); // Handle overflow case

                    *reinterpret_cast<uint32_t*>( interpolatedReport + offset ) = interpolated;
                }
            }

            // NOA interpolation (if present)
            if( noaCount > 0 )
            {
                const uint8_t* prevNoa = prevPec + pecSize;
                const uint8_t* lastNoa = lastPec + pecSize;
                for( uint32_t m = 0; m < noaCount; ++m )
                {
                    uint32_t       offset       = headerSize + pecSize + m * noaElemSize;
                    const uint32_t valuePrev    = *reinterpret_cast<const uint32_t*>( prevNoa + m * noaElemSize );
                    const uint32_t valueLast    = *reinterpret_cast<const uint32_t*>( lastNoa + m * noaElemSize );
                    const uint32_t interpolated = ( valueLast >= valuePrev )
                        ? valuePrev + static_cast<uint32_t>( ( valueLast - valuePrev ) * alpha )
                        : valuePrev + static_cast<uint32_t>( ( valueLast + ( std::numeric_limits<uint32_t>::max() - valuePrev + 1 ) ) * alpha ); // Handle overflow case

                    *reinterpret_cast<uint32_t*>( interpolatedReport + offset ) = interpolated;
                }
            }
        }
    }

    ////////////////////////////////////////////////////////////////////////////////
    //
    //
    // Class:
    //     CCalculationContext
    //
    // Method:
    //     CacheRemainingReports
    //
    // Description:
    //     Caches any remaining raw reports for each data set in the stream aggregation context
    //     that have not yet been processed. For each data set, if additional reports are available
    //     and not needed for immediate processing, this method allocates a new buffer to store both
    //     previously cached reports and the remaining raw reports from the current call. It then
    //     updates the cached pointers and sizes accordingly, marks the data set as having cached
    //     reports, and increments the output report count. This ensures that all unprocessed reports
    //     are preserved for future aggregation or interpolation steps, preventing data loss across
    //     multiple aggregation windows.
    //
    // Output:
    //     TCompletionCode - CC_OK on success, or CC_ERROR_NO_MEMORY if allocation fails.
    //
    ////////////////////////////////////////////////////////////////////////////////
    TCompletionCode CCalculationContext::CacheRemainingReports()
    {
        TStreamAggregationContext& sa = m_aggregationContext.StreamAggregationContext;

        for( uint32_t i = 0; i < m_dataSetCount; ++i )
        {
            uint32_t remainingReportCount = sa.RawReportCount[i] - sa.OutReportCount[i];

            if( !sa.NeedReport[i] && remainingReportCount > 0 )
            {
                const uint32_t remainingRawDataSize = remainingReportCount * sa.RawReportSize;    // remaining raw data size from this call
                const uint32_t cachedReportPtrSize  = sa.CachedReportPtrsSize[i];                 // cached report size from previous calls
                const uint32_t sumCachedReportSize  = cachedReportPtrSize + remainingRawDataSize; // total cached report size

                uint8_t* newCachedReportPtrs = new( std::nothrow ) uint8_t[sumCachedReportSize]();
                MD_CHECK_PTR_RET( newCachedReportPtrs, CC_ERROR_NO_MEMORY );

                if( sa.CachedReportPtrsBase[i] != nullptr && cachedReportPtrSize != 0 )
                {
                    iu_memcpy_s( newCachedReportPtrs, cachedReportPtrSize, sa.CachedReportPtrsBase[i], cachedReportPtrSize );
                    MD_SAFE_DELETE_ARRAY( sa.CachedReportPtrsBase[i] );
                }

                iu_memcpy_s( newCachedReportPtrs + cachedReportPtrSize, remainingRawDataSize, sa.RawData[i], remainingRawDataSize );
                sa.CachedReportPtrs[i]     = newCachedReportPtrs;
                sa.CachedReportPtrsBase[i] = newCachedReportPtrs;

                if( sa.CachedReportPtrsSize[i] > 0 )
                {
                    sa.CachedReportPtrsSize[i] += remainingRawDataSize;
                }
                else
                {
                    sa.CachedReportPtrsSize[i] = remainingRawDataSize;
                }

                sa.IsCachedReport[i] = true;
                sa.OutReportCount[i] += remainingReportCount;
            }
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    // Explicit template instantiations of CalculateMetricsInternal so that other
    // translation units (e.g. md_metric_set.cpp) can link against the async (<true>)
    // and sync (<false>) specializations defined in this file.
    //////////////////////////////////////////////////////////////////////////////
    template TCompletionCode CCalculationContext::CalculateMetricsInternal<false>( const uint8_t* rawData, uint32_t rawDataSize, TTypedValue_1_0* out, uint32_t outSize, uint32_t* outReportCount, TTypedValue_1_0* outMaxValues, uint32_t outMaxValuesSize );
    template TCompletionCode CCalculationContext::CalculateMetricsInternal<true>( const uint8_t* rawData, uint32_t rawDataSize, TTypedValue_1_0* out, uint32_t outSize, uint32_t* outReportCount, TTypedValue_1_0* outMaxValues, uint32_t outMaxValuesSize );

} // namespace MetricsDiscoveryInternal
