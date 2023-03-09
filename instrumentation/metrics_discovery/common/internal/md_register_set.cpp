/*========================== begin_copyright_notice ============================

Copyright (C) 2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_register_set.h

//     Abstract:   C++ Metrics Discovery internal registry set implementation

#include "md_register_set.h"
#include "md_adapter.h"
#include "md_equation.h"
#include "md_metrics_device.h"

#include "md_utils.h"

namespace MetricsDiscoveryInternal
{

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CRegisterSet
    //
    // Method:
    //     CRegisterSet
    //
    // Description:
    //     CRegisterSet constructor.
    //
    // Input:
    //     CMetricsDevice* device         - metrics device
    //     uint32_t        configId       - config id
    //     uint32_t        configPriority - priority, lower more important
    //     TConfigType     configType     - e.g. COMMON, SNAPSHOT
    //
    //////////////////////////////////////////////////////////////////////////////
    CRegisterSet::CRegisterSet( CMetricsDevice* device, uint32_t configId, uint32_t configPriority, TConfigType configType )
        : m_regList()
        , m_availabilityEquation( nullptr )
        , m_device( device )
        , m_isAvailable( true )
    {
        m_params.ConfigId       = configId;
        m_params.ConfigPriority = configPriority;
        m_params.ConfigType     = configType;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CRegisterSet
    //
    // Method:
    //     ~CRegisterSet
    //
    // Description:
    //     CRegisterSet destructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    CRegisterSet::~CRegisterSet()
    {
        ClearList( m_regList );
        MD_SAFE_DELETE( m_availabilityEquation );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CRegisterSet
    //
    // Method:
    //     GetParams
    //
    // Description:
    //     Returns params.
    //
    // Output:
    //     TRegisterSetParams* - register set params
    //
    //////////////////////////////////////////////////////////////////////////////
    TRegisterSetParams* CRegisterSet::GetParams()
    {
        return &m_params;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CRegisterSet
    //
    // Method:
    //     SetAvailabilityEquation
    //
    // Description:
    //     Sets the availability equation in a register set. It's used to determine if the set
    //     is available on the current platform.
    //
    // Input:
    //     const char* equationString - equation string, could be empty
    //
    // Output:
    //     TCompletionCode            - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CRegisterSet::SetAvailabilityEquation( const char* equationString )
    {
        TCompletionCode ret = SetEquation( m_device, m_availabilityEquation, equationString );
        if( ret == CC_OK )
        {
            m_isAvailable = m_availabilityEquation ? m_availabilityEquation->SolveBooleanEquation() : true;
        }
        else
        {
            MD_LOG_A( OBTAIN_ADAPTER_ID( m_device ), LOG_ERROR, "Error setting availability equation" );
            m_isAvailable = false;
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CRegisterSet
    //
    // Method:
    //     AddConfigRegister
    //
    // Description:
    //     Adds config register to the register set.
    //
    // Input:
    //     uint32_t      offset - register offset
    //     uint32_t      value  - value
    //     TRegisterType type   - register type
    //
    // Output:
    //     TRegister* - added register
    //
    //////////////////////////////////////////////////////////////////////////////
    TRegister* CRegisterSet::AddConfigRegister( uint32_t offset, uint32_t value, TRegisterType type )
    {
        TRegister reg;
        reg.offset = offset;
        reg.value  = value;
        reg.type   = ( type > REGISTER_TYPE_UNKNOWN && type < REGISTER_TYPE_LAST ) ? type : REGISTER_TYPE_UNKNOWN;

        m_regList.push_back( std::move( reg ) );

        return &m_regList.back();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CRegisterSet
    //
    // Method:
    //     IsAvailable
    //
    // Description:
    //     True if register set is available on a current platform.
    //
    // Output:
    //     bool - true if available on current platform
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CRegisterSet::IsAvailable()
    {
        return m_isAvailable;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CRegisterSet
    //
    // Method:
    //     RegsToVector
    //
    // Description:
    //     Copies register pointers to a given vector.
    //     !!WATCH OUT FOR DOUBLE MEMORY FREEING!!
    //
    // Input:
    //     Vector<TRegister*>& regVector - destination vector
    //
    // Output:
    //     TCompletionCode - result, *CC_OK* is ok
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CRegisterSet::RegsToVector( std::vector<TRegister*>& regVector )
    {
        for( TRegister& registerNode : m_regList )
        {
            regVector.push_back( &registerNode );
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CRegisterSet
    //
    // Method:
    //     WriteCRegisterSetToFile
    //
    // Description:
    //     Writes CRegisterSet object to a file.
    //
    // Input:
    //     FILE* metricFile - handle to a metric file
    //
    // Output:
    //     TCompletionCode  - result of the operation, *CC_OK* is ok
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CRegisterSet::WriteCRegisterSetToFile( FILE* metricFile )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        MD_CHECK_PTR_RET_A( adapterId, metricFile, CC_ERROR_INVALID_PARAMETER );

        uint32_t count = 0;

        // m_params and availability equation
        fwrite( &m_params.ConfigId, sizeof( m_params.ConfigId ), 1, metricFile );
        fwrite( &m_params.ConfigPriority, sizeof( m_params.ConfigPriority ), 1, metricFile );
        fwrite( &m_params.ConfigType, sizeof( m_params.ConfigType ), 1, metricFile );
        WriteEquationToFile( m_availabilityEquation, metricFile, adapterId );

        // Registers
        count = m_regList.size();
        fwrite( &count, sizeof( uint32_t ), 1, metricFile );

        for( TRegister& reg : m_regList )
        {
            fwrite( &reg, sizeof( reg ), 1, metricFile );
        }

        return CC_OK;
    }
} // namespace MetricsDiscoveryInternal
