/*========================== begin_copyright_notice ============================

Copyright (C) 2022-2025 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_metric.cpp

//     Abstract:   C++ Metrics Discovery internal metric implementation

#include "md_metric.h"
#include "md_adapter.h"
#include "md_equation.h"
#include "md_metrics_device.h"

#include "md_utils.h"

#include <cstring>

namespace MetricsDiscoveryInternal
{

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     CMetric constructor
    //
    // Description:
    //     Constructor.
    //
    // Input:
    //     CMetricsDevice&   device          -
    //     uint32_t          id              -
    //     const char*       name            -
    //     const char*       shortName       -
    //     const char*       longName        -
    //     const char*       group           -
    //     uint32_t          groupId         -
    //     uint32_t          usageFlagsMask  -
    //     uint32_t          apiMask         -
    //     TMetricType       metricType      -
    //     TMetricResultType resultType      -
    //     const char*       units           -
    //     int64_t           loWatermark     -
    //     int64_t           hiWatermark     -
    //     THwUnitType       hwType          -
    //     const char*       alias           -
    //     const char*       signalName      -
    //     bool              isCustom        - flag shows that metric was created from AddCustomMetric method
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetric::CMetric(
        CMetricsDevice&   device,
        uint32_t          id,
        const char*       name,
        const char*       shortName,
        const char*       longName,
        const char*       group,
        uint32_t          groupId,
        uint32_t          usageFlagsMask,
        uint32_t          apiMask,
        TMetricType       metricType,
        TMetricResultType resultType,
        const char*       units,
        int64_t           loWatermark,
        int64_t           hiWatermark,
        THwUnitType       hwType,
        const char*       alias,
        const char*       signalName,
        bool              isCustom )
        : m_params{}
        , m_id( id ) // id in original set, equal to filtered on creation
        , m_isCustom( isCustom )
        , m_availabilityEquation( nullptr )
        , m_ioReadEquation( nullptr )
        , m_queryReadEquation( nullptr )
        , m_normEquation( nullptr )
        , m_maxValueEquation( nullptr )
        , m_device( device )
    {
        const uint32_t adapterId = device.GetAdapter().GetAdapterId();

        m_signalName = GetCopiedCString( signalName, adapterId );

        m_params.IdInSet           = id; // filtered id, equal to original on creation
        m_params.SymbolName        = GetCopiedCString( name, adapterId );
        m_params.ShortName         = GetCopiedCString( shortName, adapterId );
        m_params.LongName          = GetCopiedCString( longName, adapterId );
        m_params.GroupName         = GetCopiedCString( group, adapterId );
        m_params.DxToOglAlias      = GetCopiedCString( alias, adapterId );
        m_params.GroupId           = groupId;
        m_params.UsageFlagsMask    = usageFlagsMask;
        m_params.ApiMask           = apiMask;
        m_params.MetricType        = metricType;
        m_params.ResultType        = resultType;
        m_params.MetricResultUnits = GetCopiedCString( units, adapterId );
        m_params.LowWatermark      = static_cast<uint64_t>( loWatermark );
        m_params.HighWatermark     = static_cast<uint64_t>( hiWatermark );
        m_params.HwUnitType        = hwType;
        m_params.QueryModeMask     = ( apiMask & MD_QUERY_API_MASK )
                ? static_cast<uint32_t>( QUERY_MODE_MASK_ALL )   // By default, a query metric supports all query modes
                : static_cast<uint32_t>( QUERY_MODE_MASK_NONE ); // By default, a tbs metric does not support any query modes
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     CMetric copy constructor
    //
    // Description:
    //     Copy constructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetric::CMetric( const CMetric& other )
        : m_params{}
        , m_id( other.m_id ) // initial id before filterings
        , m_isCustom( other.m_isCustom )
        , m_device( other.m_device )
    {
        const uint32_t adapterId = other.m_device.GetAdapter().GetAdapterId();

        m_signalName = GetCopiedCString( other.m_signalName, adapterId );

        m_params.IdInSet           = other.m_params.IdInSet; // id after filterings
        m_params.GroupId           = other.m_params.GroupId;
        m_params.SymbolName        = GetCopiedCString( other.m_params.SymbolName, adapterId );
        m_params.ShortName         = GetCopiedCString( other.m_params.ShortName, adapterId );
        m_params.GroupName         = GetCopiedCString( other.m_params.GroupName, adapterId );
        m_params.LongName          = GetCopiedCString( other.m_params.LongName, adapterId );
        m_params.DxToOglAlias      = GetCopiedCString( other.m_params.DxToOglAlias, adapterId );
        m_params.UsageFlagsMask    = other.m_params.UsageFlagsMask;
        m_params.ApiMask           = other.m_params.ApiMask;
        m_params.ResultType        = other.m_params.ResultType;
        m_params.MetricResultUnits = GetCopiedCString( other.m_params.MetricResultUnits, adapterId );
        m_params.MetricType        = other.m_params.MetricType;
        m_params.LowWatermark      = other.m_params.LowWatermark;
        m_params.HighWatermark     = other.m_params.HighWatermark;
        m_params.HwUnitType        = other.m_params.HwUnitType;
        m_params.DeltaFunction     = other.m_params.DeltaFunction;
        m_params.QueryModeMask     = other.m_params.QueryModeMask;

        m_availabilityEquation = ( other.m_availabilityEquation ) ? new( std::nothrow ) CEquation( *other.m_availabilityEquation ) : nullptr;
        m_ioReadEquation       = ( other.m_ioReadEquation ) ? new( std::nothrow ) CEquation( *other.m_ioReadEquation ) : nullptr;
        m_queryReadEquation    = ( other.m_queryReadEquation ) ? new( std::nothrow ) CEquation( *other.m_queryReadEquation ) : nullptr;
        m_normEquation         = ( other.m_normEquation ) ? new( std::nothrow ) CEquation( *other.m_normEquation ) : nullptr;
        m_maxValueEquation     = ( other.m_maxValueEquation ) ? new( std::nothrow ) CEquation( *other.m_maxValueEquation ) : nullptr;

        m_params.IoReadEquation    = static_cast<IEquation_1_0*>( m_ioReadEquation );
        m_params.QueryReadEquation = static_cast<IEquation_1_0*>( m_queryReadEquation );
        m_params.NormEquation      = static_cast<IEquation_1_0*>( m_normEquation );
        m_params.MaxValueEquation  = static_cast<IEquation_1_0*>( m_maxValueEquation );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     ~CMetric destructor
    //
    // Description:
    //     Deallocates memory.
    //
    //////////////////////////////////////////////////////////////////////////////
    CMetric::~CMetric()
    {
        MD_SAFE_DELETE_ARRAY( m_params.SymbolName );
        MD_SAFE_DELETE_ARRAY( m_params.ShortName );
        MD_SAFE_DELETE_ARRAY( m_params.LongName );
        MD_SAFE_DELETE_ARRAY( m_params.GroupName );
        MD_SAFE_DELETE_ARRAY( m_params.MetricResultUnits );
        MD_SAFE_DELETE_ARRAY( m_params.DxToOglAlias );
        MD_SAFE_DELETE_ARRAY( m_signalName );
        MD_SAFE_DELETE( m_availabilityEquation );
        MD_SAFE_DELETE( m_ioReadEquation );
        MD_SAFE_DELETE( m_queryReadEquation );
        MD_SAFE_DELETE( m_normEquation );
        MD_SAFE_DELETE( m_maxValueEquation );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     GetParams
    //
    // Description:
    //     Returns the metric params.
    //
    // Output:
    //     TMetricParamsLatest* - pointer to metric params.
    //
    //////////////////////////////////////////////////////////////////////////////
    TMetricParamsLatest* CMetric::GetParams( void )
    {
        return &m_params;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     SetSnapshotReportReadEquation
    //
    // Description:
    //     Sets the snapshot (IO) read equation in the metric.
    //
    // Input:
    //     const char * equationString - euqation string, could be empty
    //
    // Output:
    //     TCompletionCode             - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetric::SetSnapshotReportReadEquation( const char* equationString )
    {
        const auto ret          = SetEquation( m_device, m_ioReadEquation, equationString );
        m_params.IoReadEquation = static_cast<IEquation_1_0*>( m_ioReadEquation );

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     SetDeltaReportReadEquation
    //
    // Description:
    //     Sets the delta (query) read equation in the metric.
    //
    // Input:
    //     const char * equationString - equation string, could be empty
    //
    // Output:
    //     TCompletionCode             - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetric::SetDeltaReportReadEquation( const char* equationString )
    {
        const auto ret             = SetEquation( m_device, m_queryReadEquation, equationString );
        m_params.QueryReadEquation = static_cast<IEquation_1_0*>( m_queryReadEquation );

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     SetNormalizationEquation
    //
    // Description:
    //     Sets the normalization equation in the metric.
    //
    // Input:
    //     const char * equationString - equation string, could be empty
    //
    // Output:
    //     TCompletionCode             - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetric::SetNormalizationEquation( const char* equationString )
    {
        const auto ret        = SetEquation( m_device, m_normEquation, equationString );
        m_params.NormEquation = static_cast<IEquation_1_0*>( m_normEquation );

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     SetMaxValueEquation
    //
    // Description:
    //     Sets the max value equation in the metric.
    //
    // Input:
    //     const char * equationString - equation string, could be empty
    //
    // Output:
    //     TCompletionCode             - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetric::SetMaxValueEquation( const char* equationString )
    {
        const auto ret            = SetEquation( m_device, m_maxValueEquation, equationString );
        m_params.MaxValueEquation = static_cast<IEquation_1_0*>( m_maxValueEquation );

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     SetIdInSetParam
    //
    // Description:
    //     Updates IdInSet parameter in the metric.
    //
    // Input:
    //     uint32_t id - id in current metric set
    //
    // Output:
    //     void        - return values is absent
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetric::SetIdInSetParam( uint32_t id )
    {
        m_params.IdInSet = id;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     SetQueryModeMask
    //
    // Description:
    //     Updates QueryModeMask parameter in the metric.
    //
    // Input:
    //     const uint32_t queryModeMask - query mode mask
    //
    //////////////////////////////////////////////////////////////////////////////
    void CMetric::SetQueryModeMask( const uint32_t queryModeMask )
    {
        m_params.QueryModeMask = queryModeMask;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     SetSnapshotReportDeltaFunction
    //
    // Description:
    //     Sets the snapshot report delta equation in the metric.
    //     It's an equation to calculate delta values of to snapshot report values.
    //
    // Input:
    //     const char * equationString - equation string, could be empty
    //
    // Output:
    //     TCompletionCode             - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetric::SetSnapshotReportDeltaFunction( const char* equationString )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();
        return SetDeltaFunction( equationString, &m_params.DeltaFunction, adapterId );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     SetSnapshotReportDeltaFunction
    //
    // Description:
    //     Sets the snapshot report delta equation in the metric.
    //     It's an equation to calculate delta values of to snapshot report values.
    //
    // Input:
    //     TDeltaFunction_1_0 deltaFunction    - parsed equation
    //
    // Output:
    //     TCompletionCode                     - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetric::SetSnapshotReportDeltaFunction( TDeltaFunction_1_0 deltaFunction )
    {
        m_params.DeltaFunction = deltaFunction;

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     SetAvailabilityEquation
    //
    // Description:
    //     Sets the availability equation in the metric. It's used to determine if the metric
    //     is available on the current platform.
    //
    // Input:
    //     const char * equationString - equation string, could be empty
    //
    // Output:
    //     TCompletionCode             - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetric::SetAvailabilityEquation( const char* equationString )
    {
        return SetEquation( m_device, m_availabilityEquation, equationString );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     GetSignalName
    //
    // Description:
    //     Returns signal name, can be nullptr.
    //
    // Output:
    //     const char* - signal name
    //
    //////////////////////////////////////////////////////////////////////////////
    const char* CMetric::GetSignalName()
    {
        return m_signalName;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     GetId
    //
    // Description:
    //     Returns metric position in metric set.
    //
    // Output:
    //     uint32_t - id
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CMetric::GetId() const
    {
        return m_id;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     IsAvailabilityEquationTrue
    //
    // Description:
    //     Solves the given metric availability equation.
    //
    // Output:
    //     bool - result of solving availability equation.
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CMetric::IsAvailabilityEquationTrue()
    {
        return !m_availabilityEquation || m_availabilityEquation->SolveBooleanEquation();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     WriteCMetricToBuffer
    //
    // Description:
    //     Writes the metric object to buffer.
    //
    // Input:
    //     uint8_t*  buffer       - pointer to a buffer
    //     uint32_t& bufferSize   - size of the buffer
    //     uint32_t& bufferOffset - the current offset of the buffer
    //
    // Output:
    //     TCompletionCode        - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetric::WriteCMetricToBuffer( uint8_t* buffer, uint32_t& bufferSize, uint32_t& bufferOffset )
    {
        const uint32_t  adapterId = m_device.GetAdapter().GetAdapterId();
        TCompletionCode result    = CC_OK;

        // m_params
        result = WriteDataToBuffer( &m_params.GroupId, sizeof( m_params.GroupId ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteCStringToBuffer( m_params.SymbolName, buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteCStringToBuffer( m_params.ShortName, buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteCStringToBuffer( m_params.GroupName, buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteCStringToBuffer( m_params.LongName, buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteCStringToBuffer( m_params.DxToOglAlias, buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteDataToBuffer( &m_params.UsageFlagsMask, sizeof( m_params.UsageFlagsMask ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteDataToBuffer( &m_params.ApiMask, sizeof( m_params.ApiMask ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteDataToBuffer( &m_params.ResultType, sizeof( m_params.ResultType ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteCStringToBuffer( m_params.MetricResultUnits, buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteDataToBuffer( &m_params.MetricType, sizeof( m_params.MetricType ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteDataToBuffer( &m_params.HwUnitType, sizeof( m_params.HwUnitType ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteDataToBuffer( &m_params.LowWatermark, sizeof( m_params.LowWatermark ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteDataToBuffer( &m_params.HighWatermark, sizeof( m_params.HighWatermark ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteCStringToBuffer( m_signalName, buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        // Availability equation
        result = WriteEquationToBuffer( m_availabilityEquation, buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        // DeltaFunction
        result = WriteDataToBuffer( &m_params.DeltaFunction.FunctionType, sizeof( m_params.DeltaFunction.FunctionType ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteDataToBuffer( &m_params.DeltaFunction.BitsCount, sizeof( m_params.DeltaFunction.BitsCount ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        // Equations
        result = WriteEquationToBuffer( m_ioReadEquation, buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteEquationToBuffer( m_queryReadEquation, buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteEquationToBuffer( m_normEquation, buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteEquationToBuffer( m_maxValueEquation, buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        return CC_OK;
    }

} // namespace MetricsDiscoveryInternal
