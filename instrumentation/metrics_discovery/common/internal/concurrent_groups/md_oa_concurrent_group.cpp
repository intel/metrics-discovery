/*========================== begin_copyright_notice ============================

Copyright (C) 2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_oa_concurrent_group.cpp

//     Abstract:   C++ Metrics Discovery oa concurrent group implementation

#include "md_oa_concurrent_group.h"
#include "md_information.h"
#include "md_calculation.h"
#include "md_driver_ifc.h"

#include <cstring>

namespace MetricsDiscoveryInternal
{

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     SetIoStreamSamplingType
    //
    // Description:
    //     Sets stream sampling type.
    //
    // Input:
    //     TSamplingType type - requested IO Stream Sampling Type
    //
    // Output:
    //     TCompletionCode - result of operation (*CC_OK* is ok)
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode COAConcurrentGroup::SetIoStreamSamplingType( TSamplingType samplingType )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );
        MD_LOG_ENTER_A( adapterId );

        TStreamType     streamType = STREAM_TYPE_OA;
        TCompletionCode ret        = GetStreamTypeFromSamplingType( samplingType, streamType );

        if( m_streamType == streamType )
        {
            MD_LOG_A( adapterId, LOG_DEBUG, "Stream sampling type is already set to: %u", m_streamType );
        }
        else if( ret == CC_OK )
        {
            // change is disallowed if stream is already opened
            if( m_ioMetricSet != nullptr )
            {
                MD_LOG_A( adapterId, LOG_ERROR, "Failed to set IoStream sampling type" );
                ret = CC_ERROR_GENERAL;
            }
            else
            {
                MD_LOG_A( adapterId, LOG_DEBUG, "Stream sampling type changed from %u to %u", m_streamType, streamType );
                m_streamType = streamType;
            }
        }

        MD_LOG_EXIT_A( adapterId );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     OpenIoStream
    //
    // Description:
    //     Opens IO Stream for given metric set.
    //     (Enables Timer Mode and opens Counter Stream)
    //
    // Input:
    //     IMetricSet_1_0*      metricSet           - metric set
    //     uint32_t             processId           - PID of the measured app (0 is global context)
    //     uint32_t*            nsTimerPeriod       - (in/out) requested/set sampling period time in nanoseconds
    //     uint32_t*            oaBufferSize        - (in/out) requested/set OA Buffer size in bytes
    //
    // Output:
    //     TCompletionCode                          - result of operation (*CC_OK* is OK)
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode COAConcurrentGroup::OpenIoStream( IMetricSet_1_0* metricSet, uint32_t processId, uint32_t* nsTimerPeriod, uint32_t* oaBufferSize )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );
        MD_LOG_ENTER_A( adapterId );
        MD_CHECK_PTR_RET_A( adapterId, nsTimerPeriod, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, oaBufferSize, CC_ERROR_INVALID_PARAMETER );

        TCompletionCode ret = SetIoMetricSet( metricSet );
        MD_CHECK_CC_RET_A( adapterId, ret );

        CDriverInterface& driverInterface = m_device->GetDriverInterface();
        ret                               = driverInterface.OpenIoStream( *this, processId, *nsTimerPeriod, *oaBufferSize );
        MD_CHECK_CC_RET_A( adapterId, ret );
        MD_LOG_A( adapterId, LOG_DEBUG, "Stream opened using type: %u", m_streamType );

        m_processId            = processId;
        m_contextTagsEnabled   = m_ioMetricSet->HasInformation( "ContextId" );
        CMetricsCalculator* mc = m_ioMetricSet->GetMetricsCalculator();
        // In case of stream reopen
        ClearVector( m_ioGpuContextInfoVector );
        m_params.IoGpuContextInformationCount = 0;
        if( mc != nullptr )
        {
            mc->DiscardSavedReport();
        }

        MD_LOG_EXIT_A( adapterId );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     ReadIoStream
    //
    // Description:
    //     Reads data from previously opened IO Stream. Returns *CC_READ_PENDING* if not all
    //     data was read. Additionally, at the end of ReadIoStream GpuContextIds are read and updated.
    //
    // Input:
    //     uint32_t        reportCount - (in/out) requested number of reports to read / reports read from the stream
    //     char*           reportData  - (out) pointer to the read data
    //     uint32_t        readFlags   - read flags (see TIoReadFlag enum), 0 is ok
    //
    // Output:
    //     TCompletionCode - result of operation (*CC_OK* or *CC_READ_PENDING* is ok)
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode COAConcurrentGroup::ReadIoStream( uint32_t* reportCount, char* reportData, uint32_t readFlags )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        MD_CHECK_PTR_RET_A( adapterId, m_device, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, reportData, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, reportCount, CC_ERROR_INVALID_PARAMETER );

        if( m_ioMetricSet == nullptr )
        {
            *reportCount = 0;
            MD_LOG_A( adapterId, LOG_ERROR, "stream not opened" );
            return CC_ERROR_GENERAL;
        }
        if( *reportCount == 0 )
        {
            MD_LOG_A( adapterId, LOG_DEBUG, "0 reports to read" );
            return CC_OK;
        }

        TCompletionCode                 ret             = CC_OK;
        CDriverInterface&               driverInterface = m_device->GetDriverInterface();
        uint32_t                        frequency       = 0;
        GTDIReadCounterStreamExceptions exceptions      = {};

        ret = driverInterface.ReadIoStream( *this, readFlags, reportData, *reportCount, frequency, exceptions );
        if( ret == CC_OK || ret == CC_READ_PENDING )
        {
            driverInterface.HandleIoStreamExceptions( *this, m_processId, *reportCount, exceptions );

            // Order (indices) should be in sync with AddIoMeasurementInfoPredefined()
            uint32_t index = 0;
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_CORE_FREQUENCY_MHZ, frequency, index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_FREQUENCY_CHANGED, exceptions.FrequencyChanged, index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_FREQUENCY_CHANGED_INVALID, exceptions.FrequencyChangedInvalid, index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_SLICE_SHUTDOWN, exceptions.SliceShutdown, index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_REPORT_LOST, exceptions.ReportLost, index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_DATA_OUTSTANDING, exceptions.DataOutstanding, index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_BUFFER_OVERFLOW, exceptions.BufferOverflow, index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_BUFFER_OVERRUN, exceptions.BufferOverrun, index );
            SetIoMeasurementInfoPredefined( IO_MEASUREMENT_INFO_COUNTERS_OVERFLOW, exceptions.CountersOverflow, index );

            m_params.IoMeasurementInformationCount = m_ioMeasurementInfoVector.size();
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     CloseIoStream
    //
    // Description:
    //     Closes IO Stream.
    //     (Closes Counter Stream and disables Timer Mode)
    //
    // Output:
    //     TCompletionCode - result of operation (*CC_OK* is ok)
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode COAConcurrentGroup::CloseIoStream( void )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );
        MD_LOG_ENTER_A( adapterId );
        MD_CHECK_PTR_RET_A( adapterId, m_ioMetricSet, CC_ERROR_GENERAL );

        TCompletionCode   ret             = CC_OK;
        CDriverInterface& driverInterface = m_device->GetDriverInterface();

        ret = driverInterface.CloseIoStream( *this );
        if( ret != CC_OK )
        {
            MD_LOG_EXIT_A( adapterId );
            return ret;
        }

        // m_processId is not cleared after close to define if context filtering was used.
        // Stream reopen will override m_processId
        m_ioMetricSet = nullptr;
        MD_LOG_EXIT_A( adapterId );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     WaitForReports
    //
    // Description:
    //     Waits the given number of milliseconds for reports from IoStream.
    //     Returns *CC_OK* if wait was successful (data waiting in the buffer was signaled).
    //
    // Input:
    //     uint32_t     milliseconds   - number of milliseconds to wait
    //
    // Output:
    //     TCompletionCode             - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode COAConcurrentGroup::WaitForReports( uint32_t milliseconds )
    {
        auto& driverInterface = m_device->GetDriverInterface();

        return driverInterface.WaitForIoStreamReports( *this, milliseconds );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     GetIoMeasurementInformation
    //
    // Description:
    //     Returns measurement information of given index. Measurement information values
    //     are set after successful ReadIoStream.
    //
    // Input:
    //     uint32_t     index  - index of the measurement information
    //
    // Output:
    //     IInformation_1_0*   - measurement information, nullptr if count is 0
    //
    //////////////////////////////////////////////////////////////////////////////
    IInformation_1_0* COAConcurrentGroup::GetIoMeasurementInformation( uint32_t index )
    {
        if( m_params.IoMeasurementInformationCount != 0 && index < m_ioMeasurementInfoVector.size() )
        {
            return static_cast<IInformation_1_0*>( m_ioMeasurementInfoVector[index] );
        }
        else
        {
            return nullptr;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     GetIoGpuContextInformation
    //
    // Description:
    //     Returns GPU context id information of given index. GPU context id information values
    //     are set after successful ReadIoStream if IO_READ_FLAG_GET_CONTEXT_ID_TAGS was set.
    //
    // Input:
    //     uint32_t     index  - index of the GPU context information
    //
    // Output:
    //     IInformation_1_0*   - GPU context information, nullptr if count is 0
    //
    //////////////////////////////////////////////////////////////////////////////
    IInformation_1_0* COAConcurrentGroup::GetIoGpuContextInformation( uint32_t index )
    {
        if( m_params.IoGpuContextInformationCount != 0 && index < m_ioGpuContextInfoVector.size() )
        {
            return static_cast<IInformation_1_0*>( m_ioGpuContextInfoVector[index] );
        }
        else
        {
            return nullptr;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     AddCustomMetricSet
    //
    // Description:
    //     Wrapper function for adding custom metric sets with the given parameters.
    //
    // Input:
    //     TAddCustomMetricSetParams*  params               - params
    //     IMetricSetLatest*           referenceMetricSet   - (optional) metric set from which copy metrics and information
    //     bool                        copyInformationOnly  - Copy information without metrics from reference set
    //
    // Output:
    //     IMetricSetLatest* - added metric set
    //
    //////////////////////////////////////////////////////////////////////////////
    IMetricSetLatest* COAConcurrentGroup::AddCustomMetricSet( TAddCustomMetricSetParams* params, IMetricSetLatest* referenceMetricSet, bool copyInformationOnly /*= false*/ )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        MD_CHECK_PTR_RET_A( adapterId, m_device, nullptr );
        MD_CHECK_PTR_RET_A( adapterId, params, nullptr );

        IMetricSetLatest* set        = nullptr;
        TReportType       reportType = DEFAULT_METRIC_SET_REPORT_TYPE;

        if( params->Type == METRIC_SET_CUSTOM_PARAMS_1_0 )
        {
            auto platformMask = GetByteArrayFromPlatformType( MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).PlatformMask, MD_PLATFORM_MASK_BYTE_ARRAY_SIZE, adapterId );

            set = CConcurrentGroup::AddCustomMetricSet(
                static_cast<CMetricSet*>( referenceMetricSet ),
                "oa.fixed", // inherit metrics with signalName containing this string
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).SymbolName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).ShortName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).ApiMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).CategoryMask,
                platformMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).GtMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).RawReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).QueryReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).ComplementarySetsList,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).ApiSpecificId,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).StartConfigRegSets,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_0 ).StartConfigRegSetsCount,
                nullptr,
                reportType,
                copyInformationOnly );

            DeleteByteArray( platformMask, adapterId );
        }
        else if( params->Type == METRIC_SET_CUSTOM_PARAMS_1_1 )
        {
            auto platformMask = GetByteArrayFromPlatformType( MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).PlatformMask, MD_PLATFORM_MASK_BYTE_ARRAY_SIZE, adapterId );

            set = CConcurrentGroup::AddCustomMetricSet(
                static_cast<CMetricSet*>( referenceMetricSet ),
                "oa.fixed", // inherit metrics with signalName containing this string
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).SymbolName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).ShortName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).ApiMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).CategoryMask,
                platformMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).GtMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).RawReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).QueryReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).ComplementarySetsList,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).ApiSpecificId,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).StartConfigRegSets,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).StartConfigRegSetsCount,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_1 ).AvailabilityEquation,
                reportType,
                copyInformationOnly );

            DeleteByteArray( platformMask, adapterId );
        }
        else if( params->Type == METRIC_SET_CUSTOM_PARAMS_1_2 )
        {
            if( MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).ReportType < OA_REPORT_TYPE_LAST )
            {
                reportType = static_cast<TReportType>( MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).ReportType );
            }

            auto platformMask = GetByteArrayFromPlatformType( MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).PlatformMask, MD_PLATFORM_MASK_BYTE_ARRAY_SIZE, adapterId );

            set = CConcurrentGroup::AddCustomMetricSet(
                static_cast<CMetricSet*>( referenceMetricSet ),
                "oa.fixed", // inherit metrics with signalName containing this string
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).SymbolName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).ShortName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).ApiMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).CategoryMask,
                platformMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).GtMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).RawReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).QueryReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).ComplementarySetsList,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).ApiSpecificId,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).StartConfigRegSets,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).StartConfigRegSetsCount,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_2 ).AvailabilityEquation,
                reportType,
                copyInformationOnly );

            DeleteByteArray( platformMask, adapterId );
        }
        else if( params->Type == METRIC_SET_CUSTOM_PARAMS_1_3 )
        {
            if( MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).ReportType < OA_REPORT_TYPE_LAST )
            {
                reportType = static_cast<TReportType>( MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).ReportType );
            }

            set = CConcurrentGroup::AddCustomMetricSet(
                static_cast<CMetricSet*>( referenceMetricSet ),
                "oa.fixed", // inherit metrics with signalName containing this string
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).SymbolName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).ShortName,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).ApiMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).CategoryMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).PlatformMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).GtMask,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).RawReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).QueryReportSize,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).ComplementarySetsList,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).ApiSpecificId,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).StartConfigRegSets,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).StartConfigRegSetsCount,
                MD_CUSTOM_METRIC_SET_PARAMS( params, 1_3 ).AvailabilityEquation,
                reportType,
                copyInformationOnly );
        }

        return set;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     COAConcurrentGroup constructor
    //
    // Description:
    //     Constructor.
    //
    // Input:
    //     CMetricsDevice* device                 - parent metrics device
    //     const char*     name                   - concurrent group name
    //     const char*     description            - concurrent group description
    //     const uint32_t  measurementTypeMask    - measurement type mask
    //
    //////////////////////////////////////////////////////////////////////////////
    COAConcurrentGroup::COAConcurrentGroup( CMetricsDevice* device, const char* name, const char* description, const uint32_t measurementTypeMask )
        : COAConcurrentGroup( device, name, description, measurementTypeMask, STREAM_TYPE_OA, GTDI_OA_BUFFER_TYPE_DEFAULT )
    {
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     SetIoMetricSet
    //
    // Description:
    //     Sets input/ouput metric set.
    //
    // Input:
    //     IMetricSet_1_0* metricSet - metric set
    //
    // Output:
    //     TCompletionCode           - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode COAConcurrentGroup::SetIoMetricSet( IMetricSet_1_0* metricSet )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );
        MD_CHECK_PTR_RET_A( adapterId, metricSet, CC_ERROR_INVALID_PARAMETER );

        auto metricSetInternal = static_cast<CMetricSet*>( metricSet );
        if( metricSetInternal->GetConcurrentGroup() != this )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "Error: Given metric set belongs to another concurrent group." );
            return CC_ERROR_INVALID_PARAMETER;
        }

        m_ioMetricSet = metricSetInternal;

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     COAConcurrentGroup destructor
    //
    // Description:
    //     Deallocates memory.
    //
    //////////////////////////////////////////////////////////////////////////////
    COAConcurrentGroup::~COAConcurrentGroup()
    {
        if( m_ioMetricSet )
        {
            CloseIoStream();
        }

        ClearVector( m_ioMeasurementInfoVector );
        ClearVector( m_ioGpuContextInfoVector );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     GetIoMetricSet
    //
    // Description:
    //     Returns input/output metric set.
    //
    // Output:
    //     CMetricSet* - metric set
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetricSet* COAConcurrentGroup::GetIoMetricSet()
    {
        return m_ioMetricSet;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     GetStreamType
    //
    // Description:
    //     Returns stream type.
    //
    // Output:
    //     const TStreamType - stream type
    //
    //////////////////////////////////////////////////////////////////////////////
    const TStreamType COAConcurrentGroup::GetStreamType() const
    {
        return m_streamType;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     GetOaBufferType
    //
    // Description:
    //     Returns oa buffer type.
    //
    // Output:
    //     const GTDI_OA_BUFFER_TYPE - oa buffer type
    //
    //////////////////////////////////////////////////////////////////////////////
    const GTDI_OA_BUFFER_TYPE COAConcurrentGroup::GetOaBufferType() const
    {
        return m_oaBufferType;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     GetStreamEventHandle
    //
    // Description:
    //     Returns stream event handle.
    //
    // Output:
    //     void* -
    //
    //////////////////////////////////////////////////////////////////////////////
    void* COAConcurrentGroup::GetStreamEventHandle()
    {
        return m_streamEventHandle;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     SetStreamEventHandle
    //
    // Description:
    //     Sets stream event handle.
    //
    //////////////////////////////////////////////////////////////////////////////
    void COAConcurrentGroup::SetStreamEventHandle( void* streamEventHandle )
    {
        m_streamEventHandle = streamEventHandle;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     COAConcurrentGroup constructor
    //
    // Description:
    //     Constructor.
    //
    // Input:
    //     CMetricsDevice*           device                 - parent metrics device
    //     const char*               name                   - concurrent group name
    //     const char*               description            - concurrent group description
    //     const uint32_t            measurementTypeMask    - measurement type mask
    //     const TStreamType         streamType             - stream type
    //     const GTDI_OA_BUFFER_TYPE oaBufferType           - oa buffer type
    //
    //////////////////////////////////////////////////////////////////////////////
    COAConcurrentGroup::COAConcurrentGroup( CMetricsDevice* device, const char* name, const char* description, const uint32_t measurementTypeMask, const TStreamType streamType, const GTDI_OA_BUFFER_TYPE oaBufferType )
        : CConcurrentGroup( device, name, description, measurementTypeMask )
        , m_streamType( streamType )
        , m_oaBufferType( oaBufferType )
        , m_ioMetricSet( nullptr )
        , m_contextTagsEnabled( false )
        , m_processId( 0 )
        , m_streamEventHandle( nullptr )
        , m_ioMeasurementInfoVector()
        , m_ioGpuContextInfoVector()
    {
        AddIoMeasurementInfoPredefined();

        m_ioMeasurementInfoVector.reserve( EXCEPTIONS_VECTOR_INCREASE );
        m_ioGpuContextInfoVector.reserve( GPU_CONTEXTS_VECTOR_INCREASE );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     AddIoMeasurementInformation
    //
    // Description:
    //     Adds new measurement information to the *m_ioMeasurementInfoVector*. The value will be stored
    //     as a SnapshotReportReadEquation. To set use SetInformationValue() from CInformation class.
    //
    // Input:
    //     const char*         name                -
    //     const char*         shortName           -
    //     const char*         longName            -
    //     const char*         group               -
    //     TInformationType    informationType     -
    //     const char*         informationUnits    -
    //
    // Output:
    //     CInformation*   - pointer to the newly added measurement information. nullptr if error.
    //
    //////////////////////////////////////////////////////////////////////////////
    CInformation* COAConcurrentGroup::AddIoMeasurementInformation( const char* name, const char* shortName, const char* longName, const char* group, TInformationType informationType, const char* informationUnits )
    {
        const uint32_t adapterId       = OBTAIN_ADAPTER_ID( m_device );
        CInformation*  measurementInfo = new( std::nothrow ) CInformation( m_device, m_ioMeasurementInfoVector.size(), name, shortName, longName, group, API_TYPE_IOSTREAM | API_TYPE_BBSTREAM, informationType, informationUnits );

        MD_CHECK_PTR_RET_A( adapterId, measurementInfo, nullptr );

        measurementInfo->SetSnapshotReportReadEquation( "0" );
        measurementInfo->SetDeltaReportReadEquation( "0" );

        m_ioMeasurementInfoVector.push_back( measurementInfo );
        return measurementInfo;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     AddAllIoMeasurementInformation
    //
    // Description:
    //     Adds exceptions from GTDIReadCounterStreamExceptions struct and Frequency from
    //     GTDIReadCounterStreamExtOut struct.
    //
    //////////////////////////////////////////////////////////////////////////////
    void COAConcurrentGroup::AddIoMeasurementInfoPredefined( void )
    {
        CDriverInterface& driverInterface = m_device->GetDriverInterface();

        if( driverInterface.IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_CORE_FREQUENCY_MHZ ) )
        {
            AddIoMeasurementInformation( "CoreFrequencyMHz", "Core Frequency in MHz", "The last core frequency in the measurement.", "Report Meta Data", INFORMATION_TYPE_VALUE, "megahertz" );
        }
        if( driverInterface.IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_FREQUENCY_CHANGED ) )
        {
            AddIoMeasurementInformation( "FrequencyChanged", "Core Frequency Changed", "The flag indicating that core frequency has changed.", "Exception", INFORMATION_TYPE_FLAG, nullptr );
        }
        if( driverInterface.IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_FREQUENCY_CHANGED_INVALID ) )
        {
            AddIoMeasurementInformation( "FrequencyChangedInvalid", "Core Frequency Changed Invalid", "The flag indicating inability to report freq change due to delayed read.", "Exception", INFORMATION_TYPE_FLAG, nullptr );
        }
        if( driverInterface.IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_SLICE_SHUTDOWN ) )
        {
            AddIoMeasurementInformation( "SliceShutdown", "Slice Shutdown Occurred", "The flag indicating that the Slice Shutdown has occurred.", "Exception", INFORMATION_TYPE_FLAG, nullptr );
        }
        if( driverInterface.IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_REPORT_LOST ) )
        {
            AddIoMeasurementInformation( "ReportLost", "Report Lost reported by HW", "The flag indicating that some samples were lost since last Read.", "Exception", INFORMATION_TYPE_FLAG, nullptr );
        }
        if( driverInterface.IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_DATA_OUTSTANDING ) )
        {
            AddIoMeasurementInformation( "DataOutstanding", "Data Outstanding", "The flag indicating that there are still some outstanding data.", "Report Meta Data", INFORMATION_TYPE_FLAG, nullptr );
        }
        if( driverInterface.IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_BUFFER_OVERFLOW ) )
        {
            AddIoMeasurementInformation( "BufferOverflow", "Buffer Overflow", "The flag indicating that some reports have been overwritten.", "Report Meta Data", INFORMATION_TYPE_FLAG, nullptr );
        }
        if( driverInterface.IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_BUFFER_OVERRUN ) )
        {
            AddIoMeasurementInformation( "BufferOverrun", "Buffer Overrun", "The flag indicating that the buffer is full (n-1 reports).", "Report Meta Data", INFORMATION_TYPE_FLAG, nullptr );
        }
        if( driverInterface.IsIoMeasurementInfoAvailable( IO_MEASUREMENT_INFO_COUNTERS_OVERFLOW ) )
        {
            AddIoMeasurementInformation( "CountersOverflow", "Counters Overflow", "The flag indicating that counters overflows occurred between two consecutive readings.", "Report Meta Data", INFORMATION_TYPE_FLAG, nullptr );
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     AddIoGpuContextInformation
    //
    // Description:
    //     Adds new GPU context information to the *m_ioGpuContextInfoVector*. The value will be stored
    //     as a SnapshotReportReadEquation.
    //
    // Input:
    //     const char*         name                -
    //     const char*         shortName           -
    //     const char*         longName            -
    //     const char*         group               -
    //     TInformationType    informationType     -
    //     const char*         informationUnits    -
    //
    // Output:
    //     CInformation*   - pointer to the newly added GPU context information. nullptr if error.
    //
    //////////////////////////////////////////////////////////////////////////////
    CInformation* COAConcurrentGroup::AddIoGpuContextInformation( const char* name, const char* shortName, const char* longName, const char* group, TInformationType informationType, const char* informationUnits )
    {
        const uint32_t adapterId      = OBTAIN_ADAPTER_ID( m_device );
        CInformation*  gpuContextInfo = new( std::nothrow ) CInformation( m_device, m_ioGpuContextInfoVector.size(), name, shortName, longName, group, API_TYPE_IOSTREAM | 0x0, informationType, informationUnits );

        MD_CHECK_PTR_RET_A( adapterId, gpuContextInfo, nullptr );

        gpuContextInfo->SetSnapshotReportReadEquation( "" );
        gpuContextInfo->SetDeltaReportReadEquation( "" );

        m_ioGpuContextInfoVector.push_back( gpuContextInfo );
        return gpuContextInfo;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     SetIoMeasurementInfoPredefined
    //
    // Description:
    //     Sets value of the previously defined IoMeasurementInformation identified by
    //     the given type.
    //     Used indices should be in sync with AddIoMeasurementInfoPredefined() (right order).
    //
    // Input:
    //     const TIoMeasurementInfoType ioMeasurementInfoType - IO measurement information type
    //     const uint32_t               value                 - value to set
    //     uint32_t&                    index                 - IO measurement information index (should be in sync with AddIoMeasurementInfoPredefined())
    //
    //////////////////////////////////////////////////////////////////////////////
    void COAConcurrentGroup::SetIoMeasurementInfoPredefined( const TIoMeasurementInfoType ioMeasurementInfoType, const uint32_t value, uint32_t& index )
    {
        if( index < m_ioMeasurementInfoVector.size() )
        {
            CDriverInterface& driverInterface = m_device->GetDriverInterface();

            // Set information if available
            if( driverInterface.IsIoMeasurementInfoAvailable( ioMeasurementInfoType ) )
            {
                m_ioMeasurementInfoVector[index++]->SetInformationValue( value, EQUATION_IO_READ );
            }
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Method:
    //     GetStreamTypeFromSamplingType
    //
    // Description:
    //     Returns stream type basing on given sampling type.
    //
    // Input:
    //     const TSamplingType samplingTyp - sampling type
    //     TStreamType&        streamType  - (out) stream type
    //
    // Output:
    //     TCompletionCode                 - result of operation (*CC_OK* is OK)
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode COAConcurrentGroup::GetStreamTypeFromSamplingType( const TSamplingType samplingType, TStreamType& streamType ) const
    {
        if( samplingType == SAMPLING_TYPE_OA_TIMER )
        {
            streamType = STREAM_TYPE_OA;
            return CC_OK;
        }

        return CC_ERROR_NOT_SUPPORTED;
    }

} // namespace MetricsDiscoveryInternal
