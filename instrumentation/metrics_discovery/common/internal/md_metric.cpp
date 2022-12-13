/*========================== begin_copyright_notice ============================

Copyright (C) 2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_metric.h

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
    //     CMetricsDevice*   device          -
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
    CMetric::CMetric( CMetricsDevice* device, uint32_t id, const char* name, const char* shortName, const char* longName, const char* group, uint32_t groupId, uint32_t usageFlagsMask, uint32_t apiMask, TMetricType metricType, TMetricResultType resultType, const char* units, int64_t loWatermark, int64_t hiWatermark, THwUnitType hwType, const char* alias, const char* signalName, bool isCustom )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( device );

        m_params_1_0.IdInSet           = id; // filtered id, equal to original on creation
        m_id                           = id; // id in original set, equal to filtered on creation
        m_params_1_0.SymbolName        = GetCopiedCString( name, adapterId );
        m_params_1_0.ShortName         = GetCopiedCString( shortName, adapterId );
        m_params_1_0.LongName          = GetCopiedCString( longName, adapterId );
        m_params_1_0.GroupName         = GetCopiedCString( group, adapterId );
        m_params_1_0.DxToOglAlias      = GetCopiedCString( alias, adapterId );
        m_params_1_0.GroupId           = groupId;
        m_params_1_0.UsageFlagsMask    = usageFlagsMask;
        m_params_1_0.ApiMask           = apiMask;
        m_params_1_0.MetricType        = metricType;
        m_params_1_0.ResultType        = resultType;
        m_params_1_0.MetricResultUnits = GetCopiedCString( units, adapterId );
        m_params_1_0.LowWatermark      = loWatermark;
        m_params_1_0.HighWatermark     = hiWatermark;
        m_params_1_0.HwUnitType        = hwType;
        m_signalName                   = GetCopiedCString( signalName, adapterId );

        m_params_1_0.DeltaFunction.FunctionType = DELTA_FUNCTION_NULL;
        m_params_1_0.DeltaFunction.BitsCount    = 0;
        m_params_1_0.IoReadEquation             = nullptr;
        m_params_1_0.QueryReadEquation          = nullptr;
        m_params_1_0.NormEquation               = nullptr;
        m_params_1_0.MaxValueEquation           = nullptr;
        m_availabilityEquation                  = nullptr;

        m_normEquation      = nullptr;
        m_ioReadEquation    = nullptr;
        m_queryReadEquation = nullptr;
        m_maxValueEquation  = nullptr;

        m_device   = device;
        m_isCustom = isCustom;
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
        : m_device( other.m_device )
    {
        memset( &m_params_1_0, 0, sizeof( m_params_1_0 ) );
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        m_params_1_0.IdInSet           = other.m_params_1_0.IdInSet; // id after filterings
        m_id                           = other.m_id;                 // initial id before filterings
        m_params_1_0.GroupId           = other.m_params_1_0.GroupId;
        m_params_1_0.SymbolName        = GetCopiedCString( other.m_params_1_0.SymbolName, adapterId );
        m_params_1_0.ShortName         = GetCopiedCString( other.m_params_1_0.ShortName, adapterId );
        m_params_1_0.GroupName         = GetCopiedCString( other.m_params_1_0.GroupName, adapterId );
        m_params_1_0.LongName          = GetCopiedCString( other.m_params_1_0.LongName, adapterId );
        m_params_1_0.DxToOglAlias      = GetCopiedCString( other.m_params_1_0.DxToOglAlias, adapterId );
        m_params_1_0.UsageFlagsMask    = other.m_params_1_0.UsageFlagsMask;
        m_params_1_0.ApiMask           = other.m_params_1_0.ApiMask;
        m_params_1_0.ResultType        = other.m_params_1_0.ResultType;
        m_params_1_0.MetricResultUnits = GetCopiedCString( other.m_params_1_0.MetricResultUnits, adapterId );
        m_params_1_0.MetricType        = other.m_params_1_0.MetricType;
        m_params_1_0.LowWatermark      = other.m_params_1_0.LowWatermark;
        m_params_1_0.HighWatermark     = other.m_params_1_0.HighWatermark;
        m_params_1_0.HwUnitType        = other.m_params_1_0.HwUnitType;
        m_params_1_0.DeltaFunction     = other.m_params_1_0.DeltaFunction;
        m_signalName                   = GetCopiedCString( other.m_signalName, adapterId );
        m_isCustom                     = other.m_isCustom;

        m_availabilityEquation = ( other.m_availabilityEquation ) ? new( std::nothrow ) CEquation( *other.m_availabilityEquation ) : nullptr;
        m_ioReadEquation       = ( other.m_ioReadEquation ) ? new( std::nothrow ) CEquation( *other.m_ioReadEquation ) : nullptr;
        m_queryReadEquation    = ( other.m_queryReadEquation ) ? new( std::nothrow ) CEquation( *other.m_queryReadEquation ) : nullptr;
        m_normEquation         = ( other.m_normEquation ) ? new( std::nothrow ) CEquation( *other.m_normEquation ) : nullptr;
        m_maxValueEquation     = ( other.m_maxValueEquation ) ? new( std::nothrow ) CEquation( *other.m_maxValueEquation ) : nullptr;

        m_params_1_0.IoReadEquation    = (IEquation_1_0*) m_ioReadEquation;
        m_params_1_0.QueryReadEquation = (IEquation_1_0*) m_queryReadEquation;
        m_params_1_0.NormEquation      = (IEquation_1_0*) m_normEquation;
        m_params_1_0.MaxValueEquation  = (IEquation_1_0*) m_maxValueEquation;
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
        MD_SAFE_DELETE_ARRAY( m_params_1_0.SymbolName );
        MD_SAFE_DELETE_ARRAY( m_params_1_0.ShortName );
        MD_SAFE_DELETE_ARRAY( m_params_1_0.LongName );
        MD_SAFE_DELETE_ARRAY( m_params_1_0.GroupName );
        MD_SAFE_DELETE_ARRAY( m_params_1_0.MetricResultUnits );
        MD_SAFE_DELETE_ARRAY( m_params_1_0.DxToOglAlias );
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
    //     TMetricParams_1_0*  - pointer to metric params.
    //
    //////////////////////////////////////////////////////////////////////////////
    TMetricParams_1_0* CMetric::GetParams( void )
    {
        return &m_params_1_0;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     GetMetricValue
    //
    // Description:
    //     Decodes and returns value from the string which may be a symbol.
    //     Empty string is equal to zero.
    //
    // Input:
    //     const char* valueString     - value string
    //
    // Output:
    //     uint64_t            - read value
    //
    //////////////////////////////////////////////////////////////////////////////
    uint64_t CMetric::GetMetricValue( const char* valueString )
    {
        uint64_t ret = 0LL;

        if( ( valueString == nullptr ) || ( strcmp( valueString, "" ) == 0 ) )
        {
            return 0LL;
        }

        if( ( valueString[0] == '$' ) && ( valueString[1] != 0 ) )
        {
            TTypedValue_1_0* pValue = m_device->GetGlobalSymbolValueByName( &valueString[1] );
            if( pValue && ( pValue->ValueType == VALUE_TYPE_UINT64 ) )
            {
                ret = (uint64_t) pValue->ValueUInt64;
            }
            else if( pValue && ( pValue->ValueType == VALUE_TYPE_UINT32 ) )
            {
                ret = (uint64_t) pValue->ValueUInt32;
            }
            else
            {
                MD_ASSERT_A( OBTAIN_ADAPTER_ID( m_device ), false );
            }
        }
        else
        {
            ret = (uint64_t) atol( valueString );
        }

        return ret;
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
        TCompletionCode ret         = SetEquation( m_device, m_ioReadEquation, equationString );
        m_params_1_0.IoReadEquation = (IEquation_1_0*) m_ioReadEquation;
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
        TCompletionCode ret = SetEquation( m_device, m_queryReadEquation, equationString );

        m_params_1_0.QueryReadEquation = (IEquation_1_0*) m_queryReadEquation;
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
        TCompletionCode ret = SetEquation( m_device, m_normEquation, equationString );

        m_params_1_0.NormEquation = (IEquation_1_0*) m_normEquation;
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
        TCompletionCode ret = SetEquation( m_device, m_maxValueEquation, equationString );

        m_params_1_0.MaxValueEquation = (IEquation_1_0*) m_maxValueEquation;
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
        m_params_1_0.IdInSet = id;
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
        return SetDeltaFunction( equationString, &m_params_1_0.DeltaFunction, OBTAIN_ADAPTER_ID( m_device ) );
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
        m_params_1_0.DeltaFunction = deltaFunction;

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
    //     WriteCMetricToFile
    //
    // Description:
    //     Writes the metric object to file.
    //
    // Input:
    //     FILE* metricFile - handle to a metric file
    //
    // Output:
    //     TCompletionCode  - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CMetric::WriteCMetricToFile( FILE* metricFile )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        if( metricFile == nullptr )
        {
            MD_ASSERT_A( adapterId, metricFile != nullptr );
            return CC_ERROR_INVALID_PARAMETER;
        }

        // m_params_1_0
        fwrite( &m_params_1_0.GroupId, sizeof( m_params_1_0.GroupId ), 1, metricFile );
        WriteCStringToFile( m_params_1_0.SymbolName, metricFile, adapterId );
        WriteCStringToFile( m_params_1_0.ShortName, metricFile, adapterId );
        WriteCStringToFile( m_params_1_0.GroupName, metricFile, adapterId );
        WriteCStringToFile( m_params_1_0.LongName, metricFile, adapterId );
        WriteCStringToFile( m_params_1_0.DxToOglAlias, metricFile, adapterId );
        fwrite( &m_params_1_0.UsageFlagsMask, sizeof( m_params_1_0.UsageFlagsMask ), 1, metricFile );
        fwrite( &m_params_1_0.ApiMask, sizeof( m_params_1_0.ApiMask ), 1, metricFile );
        fwrite( &m_params_1_0.ResultType, sizeof( m_params_1_0.ResultType ), 1, metricFile );
        WriteCStringToFile( m_params_1_0.MetricResultUnits, metricFile, adapterId );
        fwrite( &m_params_1_0.MetricType, sizeof( m_params_1_0.MetricType ), 1, metricFile );
        fwrite( &m_params_1_0.HwUnitType, sizeof( m_params_1_0.HwUnitType ), 1, metricFile );
        fwrite( &m_params_1_0.LowWatermark, sizeof( m_params_1_0.LowWatermark ), 1, metricFile );
        fwrite( &m_params_1_0.HighWatermark, sizeof( m_params_1_0.HighWatermark ), 1, metricFile );

        WriteCStringToFile( m_signalName, metricFile, adapterId );

        // Availability equation
        WriteEquationToFile( m_availabilityEquation, metricFile, adapterId );
        // DeltaFunction
        fwrite( &m_params_1_0.DeltaFunction.FunctionType, sizeof( m_params_1_0.DeltaFunction.FunctionType ), 1, metricFile );
        fwrite( &m_params_1_0.DeltaFunction.BitsCount, sizeof( m_params_1_0.DeltaFunction.BitsCount ), 1, metricFile );

        // Equations
        WriteEquationToFile( m_ioReadEquation, metricFile, adapterId );
        WriteEquationToFile( m_queryReadEquation, metricFile, adapterId );
        WriteEquationToFile( m_normEquation, metricFile, adapterId );

        WriteEquationToFile( m_maxValueEquation, metricFile, adapterId );

        return CC_OK;
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
} // namespace MetricsDiscoveryInternal
