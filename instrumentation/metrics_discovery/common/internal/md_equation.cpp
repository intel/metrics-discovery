/*========================== begin_copyright_notice ============================

Copyright (C) 2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_equation.h

//     Abstract:   C++ Metrics Discovery internal equation implementation

#include "md_equation.h"
#include "md_adapter.h"
#include "md_metrics_device.h"

#include "md_utils.h"

#include <cstring>

namespace MetricsDiscoveryInternal
{

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquationElementInternal
    //
    // Method:
    //     CEquationElementInternal constructor
    //
    // Description:
    //     Constructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    CEquationElementInternal::CEquationElementInternal()
        : SymbolNameInternal{ 0 }
        , MetricIndexInternal( static_cast<uint32_t>( -1 ) )
    {
        Type            = EQUATION_ELEM_LAST_1_0;
        ImmediateUInt64 = 0ULL;
        ImmediateFloat  = 0.0f;
        Mask            = { 0, nullptr };
        Operation       = EQUATION_OPER_LAST_1_0;
        ReadParams      = { 0, 0, 0, 0 };
        SymbolName      = SymbolNameInternal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquationElementInternal
    //
    // Method:
    //     CEquationElementInternal destructor
    //
    // Description:
    //     Destructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    CEquationElementInternal::~CEquationElementInternal()
    {
        if( Type == EQUATION_ELEM_MASK )
        {
            DeleteByteArray( Mask, IU_ADAPTER_ID_UNKNOWN );
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquationElementInternal
    //
    // Method:
    //     CEquationElementInternal copy constructor
    //
    // Description:
    //     CEquationElementInternal copy constructor
    //
    //////////////////////////////////////////////////////////////////////////////
    CEquationElementInternal::CEquationElementInternal( const CEquationElementInternal& element )
    {
        if( this != &element )
        {
            SetMembers( element );
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquationElementInternal
    //
    // Method:
    //     operator=
    //
    // Description:
    //     Assignment operator. Copies whole memory.
    //
    //////////////////////////////////////////////////////////////////////////////
    CEquationElementInternal& CEquationElementInternal::operator=( const CEquationElementInternal& element )
    {
        if( this != &element )
        {
            SetMembers( element );
        }

        return *this;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquationElementInternal
    //
    // Method:
    //     SetMembers
    //
    // Description:
    //     Sets all members.
    //
    //////////////////////////////////////////////////////////////////////////////
    void CEquationElementInternal::SetMembers( const CEquationElementInternal& element )
    {
        SymbolNameInternal[0] = '\0';
        SymbolName            = SymbolNameInternal;
        Type                  = element.Type;

        switch( Type )
        {
            case EQUATION_ELEM_IMM_UINT64:
                ImmediateUInt64 = element.ImmediateUInt64;
                break;

            case EQUATION_ELEM_IMM_FLOAT:
                ImmediateFloat = element.ImmediateFloat;
                break;

            case EQUATION_ELEM_MASK:
                if( const uint32_t byteArraySize = element.Mask.Size;
                    byteArraySize != 0 )
                {
                    if( element.Mask.Data == nullptr )
                    {
                        Mask.Size = 0;
                        Mask.Data = nullptr;
                        MD_LOG( LOG_WARNING, "Cannot copy null element's mask" );
                    }
                    else
                    {
                        Mask.Size = byteArraySize;
                        Mask.Data = new( std::nothrow ) uint8_t[byteArraySize]();
                    }
                    if( Mask.Data == nullptr )
                    {
                        MD_LOG( LOG_WARNING, "Cannot allocate memory for element's mask" );
                    }
                    else
                    {
                        iu_memcpy_s( &Mask.Data, byteArraySize, &element.Mask.Data, byteArraySize );
                    }
                }
                else
                {
                    MD_LOG( LOG_DEBUG, "Element's mask has size 0" );
                }
                break;

            case EQUATION_ELEM_OPERATION:
                Operation = element.Operation;
                break;

            case EQUATION_ELEM_RD_BITFIELD:
            case EQUATION_ELEM_RD_UINT8:
            case EQUATION_ELEM_RD_UINT16:
            case EQUATION_ELEM_RD_UINT32:
            case EQUATION_ELEM_RD_UINT64:
            case EQUATION_ELEM_RD_FLOAT:
            case EQUATION_ELEM_RD_40BIT_CNTR:
                ReadParams = element.ReadParams;
                break;

            case EQUATION_ELEM_GLOBAL_SYMBOL:
            case EQUATION_ELEM_LOCAL_COUNTER_SYMBOL:
            case EQUATION_ELEM_OTHER_SET_COUNTER_SYMBOL:
            case EQUATION_ELEM_LOCAL_METRIC_SYMBOL:
            case EQUATION_ELEM_OTHER_SET_METRIC_SYMBOL:
            case EQUATION_ELEM_INFORMATION_SYMBOL:
                iu_strcpy_s( SymbolNameInternal, sizeof( SymbolNameInternal ), element.SymbolNameInternal );
                SymbolName = SymbolNameInternal;
                break;

            case EQUATION_ELEM_SELF_COUNTER_VALUE:
            case EQUATION_ELEM_STD_NORM_GPU_DURATION:
            case EQUATION_ELEM_STD_NORM_EU_AGGR_DURATION:
                break;

            default:
                MD_LOG( LOG_ERROR, "Unrecognized element type: %u", Type );
                break;
        }

        MetricIndexInternal = element.MetricIndexInternal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquation
    //
    // Method:
    //     CEquation constructor
    //
    // Description:
    //     Constructor.
    //
    // Input:
    //     CMetricsDevice& device - parent metric device
    //
    //////////////////////////////////////////////////////////////////////////////
    CEquation::CEquation( CMetricsDevice& device )
        : m_elementsVector()
        , m_equationString( nullptr )
        , m_device( device )
    {
        m_elementsVector.reserve( EQUATION_VECTOR_INCREASE );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquation
    //
    // Method:
    //     CEquation copy constructor
    //
    // Description:
    //     Copy constructor.
    //
    //////////////////////////////////////////////////////////////////////////////
    CEquation::CEquation( const CEquation& other )
        : m_elementsVector( other.m_elementsVector )
        , m_equationString( GetCopiedCString( other.m_equationString, other.m_device.GetAdapter().GetAdapterId() ) )
        , m_device( other.m_device )
    {
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquation
    //
    // Method:
    //     CEquation destructor
    //
    // Description:
    //     Deallocates memory.
    //
    //////////////////////////////////////////////////////////////////////////////
    CEquation::~CEquation()
    {
        MD_SAFE_DELETE_ARRAY( m_equationString );
        ClearVector( m_elementsVector );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquation
    //
    // Method:
    //     GetEquationElementsCount
    //
    // Description:
    //     Returns equation elements count.
    //
    // Output:
    //     uint32_t  - equation elements count
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CEquation::GetEquationElementsCount()
    {
        return m_elementsVector.size();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquation
    //
    // Method:
    //     GetEquationElement
    //
    // Description:
    //     Returns the equation element with given index. Null if doesn't exist.
    //
    // Input:
    //     uint32_t     index      - equation element index
    //
    // Output:
    //     TEquationElement_1_0*   - pointer to the chosen element
    //
    //////////////////////////////////////////////////////////////////////////////
    TEquationElement_1_0* CEquation::GetEquationElement( uint32_t index )
    {
        if( index < m_elementsVector.size() )
        {
            return static_cast<TEquationElement_1_0*>( &m_elementsVector[index] );
        }
        return nullptr;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquation
    //
    // Method:
    //     SolveBooleanEquation
    //
    // Description:
    //     Used only for availability equations.
    //
    // Output:
    //     bool    -   result of the solved boolean equation
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CEquation::SolveBooleanEquation( void )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        std::list<uint64_t> equationStack  = {};
        uint64_t            qwordValue     = 0ULL;
        uint32_t            algorithmCheck = 0;

        for( uint32_t i = 0; i < m_elementsVector.size(); ++i )
        {
            const auto& element = m_elementsVector[i];
            switch( element.Type )
            {
                case EQUATION_ELEM_IMM_UINT64:
                    equationStack.push_back( element.ImmediateUInt64 );
                    algorithmCheck++;
                    break;

                case EQUATION_ELEM_LOCAL_COUNTER_SYMBOL:
                    // Push 0 to stack for unavailable unpacked mask symbol.
                    if( element.SymbolName != nullptr &&
                        strstr( element.SymbolName, "GtSlice" ) != nullptr &&
                        strstr( element.SymbolName, "Mask" ) == nullptr )
                    {
                        qwordValue = 0;
                        equationStack.push_back( qwordValue );
                        algorithmCheck++;
                    }
                    else
                    {
                        MD_LOG_A( adapterId, LOG_DEBUG, "Not allowed equation element type in availability equation: %u", element.Type );
                        MD_ASSERT_A( adapterId, false );
                        ClearList( equationStack );
                        return false;
                    }
                    break;

                case EQUATION_ELEM_GLOBAL_SYMBOL:
                {
                    const auto pValue = m_device.GetGlobalSymbolValueByName( element.SymbolName );
                    if( pValue && ( pValue->ValueType == VALUE_TYPE_UINT64 ) )
                    {
                        qwordValue = static_cast<uint64_t>( pValue->ValueUInt64 );
                    }
                    else if( pValue && ( pValue->ValueType == VALUE_TYPE_UINT32 ) )
                    {
                        qwordValue = static_cast<uint64_t>( pValue->ValueUInt32 );
                    }
                    else if( pValue && ( pValue->ValueType == VALUE_TYPE_BOOL ) )
                    {
                        qwordValue = static_cast<uint64_t>( pValue->ValueBool );
                    }
                    else if( pValue && ( pValue->ValueType == VALUE_TYPE_BYTEARRAY ) )
                    {
                        // TODO: should be improved (the array can be bigger than 64bits)
                        qwordValue = *reinterpret_cast<uint64_t*>( pValue->ValueByteArray->Data );
                    }
                    else
                    {
                        MD_ASSERT_A( adapterId, false );
                        qwordValue = 0ULL;
                    }

                    equationStack.push_back( qwordValue );
                    algorithmCheck++;
                    break;
                }

                case EQUATION_ELEM_OPERATION:
                {
                    if( equationStack.size() < 2 )
                    {
                        MD_LOG_A( adapterId, LOG_DEBUG, "Not enough elements in equationStack, size is less than 2." );
                        return false;
                    }
                    // Pop two values from stack
                    const uint64_t valueLast = equationStack.back();
                    equationStack.pop_back();
                    algorithmCheck--;
                    const uint64_t valuePrev = equationStack.back();
                    equationStack.pop_back();
                    algorithmCheck--;

                    switch( element.Operation )
                    {
                        case EQUATION_OPER_AND:
                            qwordValue = valuePrev & valueLast;
                            break;

                        case EQUATION_OPER_OR:
                            qwordValue = valuePrev | valueLast;
                            break;

                        case EQUATION_OPER_XOR:
                            qwordValue = valuePrev ^ valueLast;
                            break;

                        case EQUATION_OPER_XNOR:
                            qwordValue = ~( valuePrev ^ valueLast );
                            break;

                        case EQUATION_OPER_EQUALS:
                            qwordValue = valuePrev == valueLast;
                            break;

                        case EQUATION_OPER_AND_L:
                            qwordValue = valuePrev && valueLast;
                            break;

                        case EQUATION_OPER_RSHIFT:
                            qwordValue = valuePrev >> valueLast;
                            break;

                        case EQUATION_OPER_LSHIFT:
                            qwordValue = valuePrev << valueLast;
                            break;

                        case EQUATION_OPER_UADD:
                            qwordValue = valuePrev + valueLast;
                            break;

                        case EQUATION_OPER_USUB:
                            qwordValue = valuePrev - valueLast;
                            break;

                        case EQUATION_OPER_UDIV:
                            qwordValue = ( valueLast != 0 ) ? valuePrev / valueLast : 0;
                            break;

                        case EQUATION_OPER_UMUL:
                            qwordValue = valuePrev * valueLast;
                            break;

                        case EQUATION_OPER_UGT:
                            qwordValue = valuePrev > valueLast;
                            break;

                        case EQUATION_OPER_ULT:
                            qwordValue = valuePrev < valueLast;
                            break;

                        case EQUATION_OPER_UGTE:
                            qwordValue = valuePrev >= valueLast;
                            break;

                        case EQUATION_OPER_ULTE:
                            qwordValue = valuePrev <= valueLast;
                            break;

                        default:
                            MD_LOG_A( adapterId, LOG_DEBUG, "Not allowed equation element operation in availability equation: %u", element.Operation );
                            MD_ASSERT_A( adapterId, false );
                            ClearList( equationStack );
                            return false;
                    }
                    equationStack.push_back( qwordValue );
                    algorithmCheck++;
                    break;
                }

                default:
                    MD_LOG_A( adapterId, LOG_DEBUG, "Not allowed equation element type in availability equation: %u", element.Type );
                    MD_ASSERT_A( adapterId, false );
                    ClearList( equationStack );
                    return false;
            }
        }
        if( m_elementsVector.size() > 0 )
        {
            // here should be only 1 element on the list - the result (if the equation is fine)
            MD_ASSERT_A( adapterId, algorithmCheck == 1 );
            qwordValue = ( equationStack.size() > 0 ) ? equationStack.back() : 0LL;
        }
        else
        {
            qwordValue = 0LL;
        }
        ClearList( equationStack );

        return ( qwordValue != 0LL );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquation
    //
    // Method:
    //     ParseEquationString
    //
    // Description:
    //     Parses the equation string.
    //
    // Input:
    //     const char * equationString - equation string to parse
    //
    // Output:
    //     bool                        - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CEquation::ParseEquationString( const char* equationString )
    {
        if( equationString == nullptr || ( strcmp( equationString, "" ) == 0 ) )
        {
            m_equationString = nullptr;
            return false;
        }

        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        char* tokenNext = nullptr;

        char* string = GetCopiedCString( equationString, adapterId );
        MD_CHECK_PTR_RET_A( adapterId, string, false );

        char* token = iu_strtok_s( string, " ", &tokenNext );
        while( token != nullptr )
        {
            if( !ParseEquationElement( token ) )
            {
                delete[] string;
                return false;
            }
            token = iu_strtok_s( nullptr, " ", &tokenNext );
        }

        m_equationString = GetCopiedCString( equationString, adapterId );
        delete[] string;
        return true;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquation
    //
    // Method:
    //     AddEquationElement
    //
    // Description:
    //     Adds the element to the equation list.
    //
    // Input:
    //     const CEquationElementInternal& element - equation element to add
    //
    // Output:
    //     bool                                    - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CEquation::AddEquationElement( const CEquationElementInternal& element )
    {
        m_elementsVector.push_back( element );

        return true;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquation
    //
    // Method:
    //     ParseEquationElement
    //
    // Description:
    //     Parses and adds the element to the equation list.
    //
    // Input:
    //     const char* equationString - equation element string to parse;
    //                                  expected to be nullptr-terminated
    //
    // Output:
    //     bool                       - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CEquation::ParseEquationElement( const char* equationString )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        CEquationElementInternal element = {};

        if( strcmp( equationString, "EuAggrDurationSlice" ) == 0 )
        {
            const uint32_t platformIndex = m_device.GetPlatformIndex();

            // Workaround for renamed EuCoresTotalCount
            bool platformXeHpPlus = IsPlatformMatch(
                platformIndex,
                GENERATION_MTL,
                GENERATION_ACM,
                GENERATION_PVC );

            return ParseEquationString( platformXeHpPlus
                    ? "$Self $GpuSliceClocksCount $VectorEngineTotalCount UMUL FDIV 100 FMUL"
                    : "$Self $GpuSliceClocksCount $EuCoresTotalCount UMUL FDIV 100 FMUL" );
        }
        else if( strcmp( equationString, "EuAggrDuration" ) == 0 )
        {
            element.Type = EQUATION_ELEM_STD_NORM_EU_AGGR_DURATION;
        }
        else if( strcmp( equationString, "GpuDurationSlice" ) == 0 )
        {
            return ParseEquationString( "$Self $GpuSliceClocksCount FDIV 100 FMUL" );
        }
        else if( strcmp( equationString, "GpuDuration" ) == 0 )
        {
            element.Type = EQUATION_ELEM_STD_NORM_GPU_DURATION;
        }
        else if( strcmp( equationString, "UADD" ) == 0 )
        {
            element.Type      = EQUATION_ELEM_OPERATION;
            element.Operation = EQUATION_OPER_UADD;
        }
        else if( strcmp( equationString, "USUB" ) == 0 )
        {
            element.Type      = EQUATION_ELEM_OPERATION;
            element.Operation = EQUATION_OPER_USUB;
        }
        else if( strcmp( equationString, "UMUL" ) == 0 )
        {
            element.Type      = EQUATION_ELEM_OPERATION;
            element.Operation = EQUATION_OPER_UMUL;
        }
        else if( strcmp( equationString, "UDIV" ) == 0 )
        {
            element.Type      = EQUATION_ELEM_OPERATION;
            element.Operation = EQUATION_OPER_UDIV;
        }
        else if( strcmp( equationString, "AND" ) == 0 )
        {
            element.Type      = EQUATION_ELEM_OPERATION;
            element.Operation = EQUATION_OPER_AND;
        }
        else if( strcmp( equationString, "OR" ) == 0 )
        {
            element.Type      = EQUATION_ELEM_OPERATION;
            element.Operation = EQUATION_OPER_OR;
        }
        else if( strcmp( equationString, "XNOR" ) == 0 )
        {
            element.Type      = EQUATION_ELEM_OPERATION;
            element.Operation = EQUATION_OPER_XNOR;
        }
        else if( strcmp( equationString, "XOR" ) == 0 )
        {
            element.Type      = EQUATION_ELEM_OPERATION;
            element.Operation = EQUATION_OPER_XOR;
        }
        else if( strcmp( equationString, "==" ) == 0 )
        {
            element.Type      = EQUATION_ELEM_OPERATION;
            element.Operation = EQUATION_OPER_EQUALS;
        }
        else if( strcmp( equationString, "&&" ) == 0 )
        {
            element.Type      = EQUATION_ELEM_OPERATION;
            element.Operation = EQUATION_OPER_AND_L;
        }
        else if( strcmp( equationString, "<<" ) == 0 )
        {
            element.Type      = EQUATION_ELEM_OPERATION;
            element.Operation = EQUATION_OPER_LSHIFT;
        }
        else if( strcmp( equationString, ">>" ) == 0 )
        {
            element.Type      = EQUATION_ELEM_OPERATION;
            element.Operation = EQUATION_OPER_RSHIFT;
        }
        else if( strcmp( equationString, "FADD" ) == 0 )
        {
            element.Type      = EQUATION_ELEM_OPERATION;
            element.Operation = EQUATION_OPER_FADD;
        }
        else if( strcmp( equationString, "FSUB" ) == 0 )
        {
            element.Type      = EQUATION_ELEM_OPERATION;
            element.Operation = EQUATION_OPER_FSUB;
        }
        else if( strcmp( equationString, "FMUL" ) == 0 )
        {
            element.Type      = EQUATION_ELEM_OPERATION;
            element.Operation = EQUATION_OPER_FMUL;
        }
        else if( strcmp( equationString, "FDIV" ) == 0 )
        {
            element.Type      = EQUATION_ELEM_OPERATION;
            element.Operation = EQUATION_OPER_FDIV;
        }
        else if( strcmp( equationString, "UGTE" ) == 0 )
        {
            element.Type      = EQUATION_ELEM_OPERATION;
            element.Operation = EQUATION_OPER_UGTE;
        }
        else if( strcmp( equationString, "ULTE" ) == 0 )
        {
            element.Type      = EQUATION_ELEM_OPERATION;
            element.Operation = EQUATION_OPER_ULTE;
        }
        else if( strcmp( equationString, "UGT" ) == 0 )
        {
            element.Type      = EQUATION_ELEM_OPERATION;
            element.Operation = EQUATION_OPER_UGT;
        }
        else if( strcmp( equationString, "ULT" ) == 0 )
        {
            element.Type      = EQUATION_ELEM_OPERATION;
            element.Operation = EQUATION_OPER_ULT;
        }
        else if( strcmp( equationString, "FGTE" ) == 0 )
        {
            element.Type      = EQUATION_ELEM_OPERATION;
            element.Operation = EQUATION_OPER_FGTE;
        }
        else if( strcmp( equationString, "FLTE" ) == 0 )
        {
            element.Type      = EQUATION_ELEM_OPERATION;
            element.Operation = EQUATION_OPER_FLTE;
        }
        else if( strcmp( equationString, "FGT" ) == 0 )
        {
            element.Type      = EQUATION_ELEM_OPERATION;
            element.Operation = EQUATION_OPER_FGT;
        }
        else if( strcmp( equationString, "FLT" ) == 0 )
        {
            element.Type      = EQUATION_ELEM_OPERATION;
            element.Operation = EQUATION_OPER_FLT;
        }
        else if( strcmp( equationString, "UMIN" ) == 0 )
        {
            element.Type      = EQUATION_ELEM_OPERATION;
            element.Operation = EQUATION_OPER_UMIN;
        }
        else if( strcmp( equationString, "UMAX" ) == 0 )
        {
            element.Type      = EQUATION_ELEM_OPERATION;
            element.Operation = EQUATION_OPER_UMAX;
        }
        else if( strcmp( equationString, "FMIN" ) == 0 )
        {
            element.Type      = EQUATION_ELEM_OPERATION;
            element.Operation = EQUATION_OPER_FMIN;
        }
        else if( strcmp( equationString, "FMAX" ) == 0 )
        {
            element.Type      = EQUATION_ELEM_OPERATION;
            element.Operation = EQUATION_OPER_FMAX;
        }
        else if( strncmp( equationString, "dw@", sizeof( "dw@" ) - 1 ) == 0 )
        {
            element.Type                  = EQUATION_ELEM_RD_UINT32;
            element.ReadParams.ByteOffset = strtoul( &equationString[3], nullptr, 0 );
        }
        else if( strncmp( equationString, "fl@", sizeof( "fl@" ) - 1 ) == 0 )
        {
            element.Type = EQUATION_ELEM_RD_FLOAT;
        }
        else if( strncmp( equationString, "qw@", sizeof( "qw@" ) - 1 ) == 0 )
        {
            element.Type                  = EQUATION_ELEM_RD_UINT64;
            element.ReadParams.ByteOffset = strtoul( &equationString[3], nullptr, 0 );
        }
        else if( strncmp( equationString, "rd40@", sizeof( "rd40@" ) - 1 ) == 0 )
        {
            char* pEnd                    = (char*) &equationString[5];
            element.Type                  = EQUATION_ELEM_RD_40BIT_CNTR;
            element.ReadParams.ByteOffset = strtoul( pEnd, &pEnd, 0 );
            if( pEnd == nullptr )
            {
                return false;
            }
            element.ReadParams.ByteOffsetExt = strtoul( ++pEnd, &pEnd, 0 );
        }
        else if( strncmp( equationString, "bm@", sizeof( "bm@" ) - 1 ) == 0 )
        {
            char* pEnd                    = (char*) &equationString[3];
            element.Type                  = EQUATION_ELEM_RD_BITFIELD;
            element.ReadParams.ByteOffset = strtoul( pEnd, &pEnd, 0 );
            if( pEnd == nullptr )
            {
                return false;
            }
            element.ReadParams.BitOffset = strtoul( ++pEnd, &pEnd, 0 );
            if( pEnd == nullptr )
            {
                return false;
            }
            element.ReadParams.BitsCount = strtoul( ++pEnd, &pEnd, 10 );
        }
        else if( strcmp( equationString, "$Self" ) == 0 )
        {
            element.Type = EQUATION_ELEM_SELF_COUNTER_VALUE;
        }
        else if( strncmp( equationString, "$$", sizeof( "$$" ) - 1 ) == 0 )
        {
            iu_strncpy_s( element.SymbolNameInternal, sizeof( element.SymbolNameInternal ), &equationString[2], sizeof( element.SymbolNameInternal ) - 1 );
            element.SymbolName = element.SymbolNameInternal;
            element.Type       = EQUATION_ELEM_LOCAL_METRIC_SYMBOL;
        }
        else if( ( equationString[0] == '$' ) && ( equationString[1] != 0 ) )
        {
            auto value = m_device.GetGlobalSymbolValueByName( &equationString[1] );

            iu_strncpy_s( element.SymbolNameInternal, sizeof( element.SymbolNameInternal ), &equationString[1], sizeof( element.SymbolNameInternal ) - 1 );
            element.SymbolName = element.SymbolNameInternal;

            if( value == nullptr )
            {
                // Finish element as local counter symbol
                element.Type = EQUATION_ELEM_LOCAL_COUNTER_SYMBOL;
            }
            else
            {
                // Finish element as global symbol
                element.Type = EQUATION_ELEM_GLOBAL_SYMBOL;
            }
        }
        else if( strncmp( equationString, "i$", sizeof( "i$" ) - 1 ) == 0 )
        {
            iu_strncpy_s( element.SymbolNameInternal, sizeof( element.SymbolNameInternal ), &equationString[2], sizeof( element.SymbolNameInternal ) - 1 );
            element.SymbolName = element.SymbolNameInternal;
            element.Type       = EQUATION_ELEM_INFORMATION_SYMBOL;
        }
        else if( strchr( equationString, '.' ) != nullptr ) // assume float number
        {
            element.Type           = EQUATION_ELEM_IMM_FLOAT;
            element.ImmediateFloat = static_cast<float>( atof( equationString ) );
        }
        else if( strncmp( equationString, "0x", sizeof( "0x" ) - 1 ) == 0 ) // assume hex integer 64
        {
            element.Type            = EQUATION_ELEM_IMM_UINT64;
            element.ImmediateUInt64 = strtoull( equationString, nullptr, 0 );
        }
        else if( equationString[0] >= '0' && equationString[0] <= '9' ) // assume decimal integer 64
        {
            element.Type            = EQUATION_ELEM_IMM_UINT64;
            element.ImmediateUInt64 = strtoull( equationString, nullptr, 10 );
        }
        else if( strncmp( equationString, "mask$", sizeof( "mask$" ) - 1 ) == 0 ) // assume hex integer 64
        {
            element.Type = EQUATION_ELEM_MASK;
            element.Mask = GetByteArrayFromCStringMask( equationString + sizeof( "mask$" ) - 1, adapterId );
            MD_CHECK_PTR_RET_A( adapterId, element.Mask.Data, false )
        }
        else
        {
            MD_LOG_A( adapterId, LOG_ERROR, "Unknown equation element: %s", equationString );
            return false;
        }

        return AddEquationElement( element );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquation
    //
    // Method:
    //     WriteCEquationToFile
    //
    // Description:
    //     Writes equation string to file.
    //
    // Input:
    //     FILE* metricFile - handle to a metric file
    //
    // Output:
    //     TCompletionCode  - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode CEquation::WriteCEquationToFile( FILE* metricFile )
    {
        const uint32_t adapterId = m_device.GetAdapter().GetAdapterId();

        if( metricFile == nullptr )
        {
            MD_ASSERT_A( adapterId, metricFile != nullptr );
            return CC_ERROR_INVALID_PARAMETER;
        }

        WriteCStringToFile( m_equationString, metricFile, adapterId );

        return CC_OK;
    }
} // namespace MetricsDiscoveryInternal
