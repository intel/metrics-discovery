/*========================== begin_copyright_notice ============================

Copyright (C) 2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_information.h

//     Abstract:   C++ Metrics Discovery internal information implementation

#include "md_information.h"
#include "md_adapter.h"
#include "md_equation.h"
#include "md_metrics_device.h"

#include "md_utils.h"

namespace MetricsDiscoveryInternal
{

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CInformation
    //
    // Method:
    //     CInformation constructor
    //
    // Description:
    //     Constructor.
    //
    // Input:
    //     CMetricsDevice*  device           -
    //     uint32_t         id               -
    //     const char*      name             -
    //     const char*      shortName        -
    //     const char*      longName         -
    //     const char*      group            -
    //     uint32_t         apiMask          -
    //     TInformationType informationType  -
    //     const char       informationUnits -
    //
    //////////////////////////////////////////////////////////////////////////////
    CInformation::CInformation( CMetricsDevice* device, uint32_t id, const char* name, const char* shortName, const char* longName, const char* group, uint32_t apiMask, TInformationType informationType, const char* informationUnits )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( device );

        m_params_1_0.IdInSet    = id; // filtered, equal to original on creation
        m_id                    = id; // original, equal to filtered on creation
        m_params_1_0.SymbolName = GetCopiedCString( name, adapterId );
        m_params_1_0.ShortName  = GetCopiedCString( shortName, adapterId );
        m_params_1_0.LongName   = GetCopiedCString( longName, adapterId );
        m_params_1_0.GroupName  = GetCopiedCString( group, adapterId );
        m_params_1_0.ApiMask    = apiMask;
        m_params_1_0.InfoType   = informationType;
        m_params_1_0.InfoUnits  = GetCopiedCString( informationUnits, adapterId );

        m_params_1_0.OverflowFunction.FunctionType = DELTA_FUNCTION_NULL;

        m_params_1_0.IoReadEquation    = nullptr;
        m_params_1_0.QueryReadEquation = nullptr;

        m_availabilityEquation = nullptr;
        m_ioReadEquation       = nullptr;
        m_queryReadEquation    = nullptr;

        m_device = device;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CInformation
    //
    // Method:
    //     CInformation copy constructor
    //
    // Description:
    //     Copy constructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    CInformation::CInformation( const CInformation& other )
        : m_device( other.m_device )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        m_params_1_0.IdInSet    = other.m_params_1_0.IdInSet; // id after filterings
        m_id                    = other.m_id;                 // initial id before filterings
        m_params_1_0.SymbolName = GetCopiedCString( other.m_params_1_0.SymbolName, adapterId );
        m_params_1_0.ShortName  = GetCopiedCString( other.m_params_1_0.ShortName, adapterId );
        m_params_1_0.GroupName  = GetCopiedCString( other.m_params_1_0.GroupName, adapterId );
        m_params_1_0.LongName   = GetCopiedCString( other.m_params_1_0.LongName, adapterId );
        m_params_1_0.ApiMask    = other.m_params_1_0.ApiMask;
        m_params_1_0.InfoType   = other.m_params_1_0.InfoType;
        m_params_1_0.InfoUnits  = GetCopiedCString( other.m_params_1_0.InfoUnits, adapterId );

        m_params_1_0.OverflowFunction = other.m_params_1_0.OverflowFunction;

        m_availabilityEquation = ( other.m_availabilityEquation ) ? new( std::nothrow ) CEquation( *other.m_availabilityEquation ) : nullptr;
        m_ioReadEquation       = ( other.m_ioReadEquation ) ? new( std::nothrow ) CEquation( *other.m_ioReadEquation ) : nullptr;
        m_queryReadEquation    = ( other.m_queryReadEquation ) ? new( std::nothrow ) CEquation( *other.m_queryReadEquation ) : nullptr;

        m_params_1_0.IoReadEquation    = (IEquation_1_0*) m_ioReadEquation;
        m_params_1_0.QueryReadEquation = (IEquation_1_0*) m_queryReadEquation;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CInformation
    //
    // Method:
    //     ~CInformation destructor
    //
    // Description:
    //     Deallocates memory.
    //
    //////////////////////////////////////////////////////////////////////////////
    CInformation::~CInformation()
    {
        MD_SAFE_DELETE_ARRAY( m_params_1_0.SymbolName );
        MD_SAFE_DELETE_ARRAY( m_params_1_0.ShortName );
        MD_SAFE_DELETE_ARRAY( m_params_1_0.LongName );
        MD_SAFE_DELETE_ARRAY( m_params_1_0.GroupName );
        MD_SAFE_DELETE_ARRAY( m_params_1_0.InfoUnits );
        MD_SAFE_DELETE( m_availabilityEquation );
        MD_SAFE_DELETE( m_ioReadEquation );
        MD_SAFE_DELETE( m_queryReadEquation );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CInformation
    //
    // Method:
    //     GetParams
    //
    // Description:
    //     Returns the information params.
    //
    // Output:
    //     TInformationParams_1_0* - pointer to the information params
    //
    //////////////////////////////////////////////////////////////////////////////
    TInformationParams_1_0* CInformation::GetParams( void )
    {
        return &m_params_1_0;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CInformation
    //
    // Method:
    //     SetSnapshotReportReadEquation
    //
    // Description:
    //     Sets the snapshot (IO) read equation in the information.
    //
    // Input:
    //     const char * equationString - equation string, could be empty
    //
    // Output:
    //     TCompletionCode             - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CInformation::SetSnapshotReportReadEquation( const char* equationString )
    {
        TCompletionCode ret = SetEquation( m_device, m_ioReadEquation, equationString );

        m_params_1_0.IoReadEquation = static_cast<IEquation_1_0*>( m_ioReadEquation );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CInformation
    //
    // Method:
    //     SetDeltaReportReadEquation
    //
    // Description:
    //     Sets the delta (query) read equation in the information.
    //
    // Input:
    //     const char * equationString - equation string, could be empty
    //
    // Output:
    //     TCompletionCode             - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CInformation::SetDeltaReportReadEquation( const char* equationString )
    {
        TCompletionCode ret = SetEquation( m_device, m_queryReadEquation, equationString );

        m_params_1_0.QueryReadEquation = static_cast<IEquation_1_0*>( m_queryReadEquation );
        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CInformation
    //
    // Method:
    //     SetAvailabilityEquation
    //
    // Description:
    //     Sets the availability equation in the information. It's used to determine if
    //     the information is available on the current platform.
    //
    // Input:
    //     const char * equationString - equation string, could be empty
    //
    // Output:
    //     TCompletionCode             - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CInformation::SetAvailabilityEquation( const char* equationString )
    {
        return SetEquation( m_device, m_availabilityEquation, equationString );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CInformation
    //
    // Method:
    //     IsAvailabilityEquationTrue
    //
    // Description:
    //     Solves the given information availability equation.
    //
    // Output:
    //     bool - result of solving availability equation.
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CInformation::IsAvailabilityEquationTrue()
    {
        return !m_availabilityEquation || m_availabilityEquation->SolveBooleanEquation();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     SetOverflowFunction
    //
    // Description:
    //     Sets the overflow delta equation in the information.
    //     It's an equation to calculate whether the overflow occurs.
    //
    // Input:
    //     const char* equationString - equation string, could be empty
    //
    // Output:
    //     TCompletionCode            - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CInformation::SetOverflowFunction( const char* equationString )
    {
        return SetDeltaFunction( equationString, &m_params_1_0.OverflowFunction, OBTAIN_ADAPTER_ID( m_device ) );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetric
    //
    // Method:
    //     SetOverflowFunction
    //
    // Description:
    //     Sets the overflow delta equation in the information.
    //     It's an equation to calculate whether the overflow occurs.
    //
    // Input:
    //     const char* equationString - equation string, could be empty
    //
    // Output:
    //     TCompletionCode            - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CInformation::SetOverflowFunction( TDeltaFunction_1_0 overflowFunction )
    {
        m_params_1_0.OverflowFunction = overflowFunction;

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CInformation
    //
    // Method:
    //     WriteCInformationToFile
    //
    // Description:
    //     Write the information object to file.
    //
    // Input:
    //     FILE* metricFile - handle to metric file
    //
    // Output:
    //     TCompletionCode  - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CInformation::WriteCInformationToFile( FILE* metricFile )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        if( metricFile == nullptr )
        {
            MD_ASSERT_A( adapterId, metricFile != nullptr );
            return CC_ERROR_INVALID_PARAMETER;
        }

        // m_params_1_0
        WriteCStringToFile( m_params_1_0.SymbolName, metricFile, adapterId );
        WriteCStringToFile( m_params_1_0.ShortName, metricFile, adapterId );
        WriteCStringToFile( m_params_1_0.GroupName, metricFile, adapterId );
        WriteCStringToFile( m_params_1_0.LongName, metricFile, adapterId );
        fwrite( &m_params_1_0.ApiMask, sizeof( m_params_1_0.ApiMask ), 1, metricFile );
        fwrite( &m_params_1_0.InfoType, sizeof( m_params_1_0.InfoType ), 1, metricFile );
        WriteCStringToFile( m_params_1_0.InfoUnits, metricFile, adapterId );

        // Availability equation
        WriteEquationToFile( m_availabilityEquation, metricFile, adapterId );

        // OverflowFunction
        fwrite( &m_params_1_0.OverflowFunction.FunctionType, sizeof( m_params_1_0.OverflowFunction.FunctionType ), 1, metricFile );
        fwrite( &m_params_1_0.OverflowFunction.BitsCount, sizeof( m_params_1_0.OverflowFunction.BitsCount ), 1, metricFile );

        // Equations
        WriteEquationToFile( m_ioReadEquation, metricFile, adapterId );
        WriteEquationToFile( m_queryReadEquation, metricFile, adapterId );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CInformation
    //
    // Method:
    //     SetInformationValue
    //
    // Description:
    //     Sets the value for the information as a given equation.
    //
    // Input:
    //     const uint32_t      value        - information value
    //     const TEquationType equationType - equation to be set
    //
    // Output:
    //     TCompletionCode                  - result of operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CInformation::SetInformationValue( const uint32_t value, const TEquationType equationType )
    {
        CEquation* equation = ( equationType == EQUATION_IO_READ )
            ? m_ioReadEquation
            : ( equationType == EQUATION_QUERY_READ )
            ? m_queryReadEquation
            : nullptr;

        if( equation != nullptr &&
            equation->GetEquationElementsCount() == 1 &&
            equation->GetEquationElement( 0 )->Type == EQUATION_ELEM_IMM_UINT64 )
        {
            equation->GetEquationElement( 0 )->ImmediateUInt64 = value;
        }
        else
        {
            return CC_ERROR_INVALID_PARAMETER;
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CInformation
    //
    // Method:
    //     SetIdInSetParam
    //
    // Description:
    //     Updates IdInSet parameter in the information element.
    //
    // Input:
    //     uint32_t id - id in current information set
    //
    // Output:
    //     void        - return values is absent
    //
    //////////////////////////////////////////////////////////////////////////////
    void CInformation::SetIdInSetParam( uint32_t id )
    {
        m_params_1_0.IdInSet = id;
    }
} // namespace MetricsDiscoveryInternal
