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
    {
        memset( &Element_1_0, 0x0, sizeof( Element_1_0 ) );
        SymbolNameInternal[0]  = 0;
        Element_1_0.SymbolName = SymbolNameInternal;
        MetricIndexInternal    = -1;
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
        Element_1_0 = element.Element_1_0;
        iu_memcpy_s( SymbolNameInternal, sizeof( SymbolNameInternal ), element.SymbolNameInternal, sizeof( SymbolNameInternal ) );
        Element_1_0.SymbolName = SymbolNameInternal;
        MetricIndexInternal    = element.MetricIndexInternal;
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
        Element_1_0 = element.Element_1_0;
        iu_memcpy_s( SymbolNameInternal, sizeof( SymbolNameInternal ), element.SymbolNameInternal, sizeof( SymbolNameInternal ) );
        Element_1_0.SymbolName = SymbolNameInternal;
        MetricIndexInternal    = element.MetricIndexInternal;
        return *this;
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
    //     CMetricsDevice* device - parent metric device
    //
    //////////////////////////////////////////////////////////////////////////////
    CEquation::CEquation( CMetricsDevice* device )
        : m_elementsVector()
        , m_device( device )
    {
        m_elementsVector.reserve( EQUATION_VECTOR_INCREASE );
        m_equationString = nullptr;
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
        , m_device( other.m_device )
    {
        m_equationString = GetCopiedCString( other.m_equationString, OBTAIN_ADAPTER_ID( m_device ) );
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
            return &( m_elementsVector[index].Element_1_0 );
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
        std::list<uint64_t> equationStack;
        uint64_t            qwordValue;
        uint32_t            algorithmCheck = 0;
        const uint32_t      adapterId      = OBTAIN_ADAPTER_ID( m_device );

        for( uint32_t i = 0; i < m_elementsVector.size(); i++ )
        {
            TEquationElement_1_0* element = &( m_elementsVector[i].Element_1_0 );
            switch( element->Type )
            {
                case EQUATION_ELEM_IMM_UINT64:
                    equationStack.push_back( element->ImmediateUInt64 );
                    algorithmCheck++;
                    break;

                case EQUATION_ELEM_LOCAL_COUNTER_SYMBOL:
                    // Push 0 to stack for unavailable unpacked mask symbol.
                    if( element->SymbolName != nullptr &&
                        strstr( element->SymbolName, "GtSlice" ) != nullptr &&
                        strstr( element->SymbolName, "Mask" ) == nullptr )
                    {
                        qwordValue = 0;
                        equationStack.push_back( qwordValue );
                        algorithmCheck++;
                    }
                    else
                    {
                        MD_LOG_A( adapterId, LOG_DEBUG, "Not allowed equation element type in availability equation: %u", element->Type );
                        MD_ASSERT_A( adapterId, false );
                        ClearList( equationStack );
                        return false;
                    }
                    break;

                case EQUATION_ELEM_GLOBAL_SYMBOL:
                {
                    TTypedValue_1_0* pValue = m_device->GetGlobalSymbolValueByName( element->SymbolName );

                    if( pValue && ( pValue->ValueType == VALUE_TYPE_UINT64 ) )
                    {
                        qwordValue = (uint64_t) pValue->ValueUInt64;
                    }
                    else if( pValue && ( pValue->ValueType == VALUE_TYPE_UINT32 ) )
                    {
                        qwordValue = (uint64_t) pValue->ValueUInt32;
                    }
                    else if( pValue && ( pValue->ValueType == VALUE_TYPE_BOOL ) )
                    {
                        qwordValue = (uint64_t) pValue->ValueBool;
                    }
                    else if( pValue && ( pValue->ValueType == VALUE_TYPE_BYTEARRAY ) )
                    {
                        // TODO: should be improved (the array can be bigger than 64bits)
                        qwordValue = *( reinterpret_cast<uint64_t*>( pValue->ValueByteArray->Data ) );
                    }
                    else
                    {
                        MD_ASSERT_A( adapterId, false );
                        qwordValue = 0;
                    }
                    equationStack.push_back( qwordValue );
                    algorithmCheck++;
                    break;
                }

                case EQUATION_ELEM_OPERATION:
                {
                    // Pop two values from stack
                    uint64_t valueLast = equationStack.back();
                    equationStack.pop_back();
                    algorithmCheck--;
                    uint64_t valuePrev = equationStack.back();
                    equationStack.pop_back();
                    algorithmCheck--;

                    switch( element->Operation )
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
                            MD_LOG_A( adapterId, LOG_DEBUG, "Not allowed equation element operation in availability equation: %u", element->Operation );
                            MD_ASSERT_A( adapterId, false );
                            ClearList( equationStack );
                            return false;
                    }
                    equationStack.push_back( qwordValue );
                    algorithmCheck++;
                    break;
                }

                default:
                    MD_LOG_A( adapterId, LOG_DEBUG, "Not allowed equation element type in availability equation: %u", element->Type );
                    MD_ASSERT_A( adapterId, false );
                    ClearList( equationStack );
                    return false;
            }
        }
        if( m_elementsVector.size() > 0 )
        {
            // here should be only 1 element on the list - the result (if the equation is fine)
            MD_ASSERT_A( adapterId, algorithmCheck == 1 );
            qwordValue = equationStack.back();
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
        if( ( equationString == nullptr ) || ( strcmp( equationString, "" ) == 0 ) )
        {
            m_equationString = nullptr;
            return false;
        }

        char *token = nullptr, *tokenNext = nullptr, *string = nullptr;

        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        string = GetCopiedCString( equationString, adapterId );
        MD_CHECK_PTR_RET_A( adapterId, string, false );

        token = iu_strtok_s( string, " ", &tokenNext );
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
    //     const CEquationElementInternal * element  - equation element to add
    //
    // Output:
    //     bool                                - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CEquation::AddEquationElement( const CEquationElementInternal* element )
    {
        m_elementsVector.push_back( *element );

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
    //     const char* element    - equation element string to parse;
    //                              expected to be nullptr-terminated
    //
    // Output:
    //     bool                   - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    bool CEquation::ParseEquationElement( const char* element )
    {
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        if( strcmp( element, "EuAggrDurationSlice" ) == 0 )
        {
            const uint32_t platformIndex = m_device->GetPlatformIndex();

            // Workaround for renamed EuCoresTotalCount
            bool platformXeHpPlus = IsPlatformMatch(
                platformIndex,
                GENERATION_MTL,
                GENERATION_ACM,
                GENERATION_PVC );

            return ParseEquationString( platformXeHpPlus ? "$Self $GpuSliceClocksCount $VectorEngineTotalCount UMUL FDIV 100 FMUL" : "$Self $GpuSliceClocksCount $EuCoresTotalCount UMUL FDIV 100 FMUL" );
        }
        else if( strcmp( element, "EuAggrDuration" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type = EQUATION_ELEM_STD_NORM_EU_AGGR_DURATION;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "GpuDurationSlice" ) == 0 )
        {
            return ParseEquationString( "$Self $GpuSliceClocksCount FDIV 100 FMUL" );
        }
        else if( strcmp( element, "GpuDuration" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type = EQUATION_ELEM_STD_NORM_GPU_DURATION;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "UADD" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_UADD;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "USUB" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_USUB;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "UMUL" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_UMUL;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "UDIV" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_UDIV;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "AND" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_AND;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "OR" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_OR;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "XNOR" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_XNOR;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "XOR" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_XOR;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "==" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_EQUALS;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "&&" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_AND_L;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "<<" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_LSHIFT;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, ">>" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_RSHIFT;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "FADD" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_FADD;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "FSUB" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_FSUB;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "FMUL" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_FMUL;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "FDIV" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_FDIV;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "UGTE" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_UGTE;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "ULTE" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_ULTE;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "UGT" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_UGT;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "ULT" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_ULT;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "FGTE" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_FGTE;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "FLTE" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_FLTE;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "FGT" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_FGT;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "FLT" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_FLT;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "UMIN" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_UMIN;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "UMAX" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_UMAX;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "FMIN" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_FMIN;
            return AddEquationElement( &anElement );
        }
        else if( strcmp( element, "FMAX" ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type      = EQUATION_ELEM_OPERATION;
            anElement.Element_1_0.Operation = EQUATION_OPER_FMAX;
            return AddEquationElement( &anElement );
        }
        else if( strncmp( element, "dw@", sizeof( "dw@" ) - 1 ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type                  = EQUATION_ELEM_RD_UINT32;
            anElement.Element_1_0.ReadParams.ByteOffset = strtoul( &element[3], nullptr, 0 );
            return AddEquationElement( &anElement );
        }
        else if( strncmp( element, "fl@", sizeof( "fl@" ) - 1 ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type                  = EQUATION_ELEM_RD_FLOAT;
            anElement.Element_1_0.ReadParams.ByteOffset = strtoul( &element[3], nullptr, 0 );
            return AddEquationElement( &anElement );
        }
        else if( strncmp( element, "qw@", sizeof( "qw@" ) - 1 ) == 0 )
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type                  = EQUATION_ELEM_RD_UINT64;
            anElement.Element_1_0.ReadParams.ByteOffset = strtoul( &element[3], nullptr, 0 );
            return AddEquationElement( &anElement );
        }
        else if( strncmp( element, "rd40@", sizeof( "rd40@" ) - 1 ) == 0 )
        {
            char*                    pEnd = (char*) &element[5];
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type                  = EQUATION_ELEM_RD_40BIT_CNTR;
            anElement.Element_1_0.ReadParams.ByteOffset = strtoul( pEnd, &pEnd, 0 );
            if( pEnd )
            {
                anElement.Element_1_0.ReadParams.ByteOffsetExt = strtoul( ++pEnd, &pEnd, 0 );
                return AddEquationElement( &anElement );
            }
            return false;
        }
        else if( strncmp( element, "bm@", sizeof( "bm@" ) - 1 ) == 0 )
        {
            char*                    pEnd = (char*) &element[3];
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type                  = EQUATION_ELEM_RD_BITFIELD;
            anElement.Element_1_0.ReadParams.ByteOffset = strtoul( pEnd, &pEnd, 0 );
            if( pEnd )
            {
                anElement.Element_1_0.ReadParams.BitOffset = strtoul( ++pEnd, &pEnd, 0 );
                if( pEnd )
                {
                    anElement.Element_1_0.ReadParams.BitsCount = strtoul( ++pEnd, &pEnd, 10 );
                    return AddEquationElement( &anElement );
                }
            }
            return false;
        }
        else if( strcmp( element, "$Self" ) == 0 )
        {
            CEquationElementInternal anElement;

            anElement.Element_1_0.Type = EQUATION_ELEM_SELF_COUNTER_VALUE;
            return AddEquationElement( &anElement );
        }
        else if( strncmp( element, "$$", sizeof( "$$" ) - 1 ) == 0 )
        {
            // Add element
            CEquationElementInternal anElement;

            iu_strncpy_s( anElement.SymbolNameInternal, sizeof( anElement.SymbolNameInternal ), &element[2], sizeof( anElement.SymbolNameInternal ) - 1 );
            // finish element
            anElement.Element_1_0.SymbolName = anElement.SymbolNameInternal;
            anElement.Element_1_0.Type       = EQUATION_ELEM_LOCAL_METRIC_SYMBOL;

            return AddEquationElement( &anElement );
        }
        else if( ( element[0] == '$' ) && ( element[1] != 0 ) )
        {
            CEquationElementInternal anElement;
            TTypedValue_1_0*         value = m_device->GetGlobalSymbolValueByName( &element[1] );

            iu_strncpy_s( anElement.SymbolNameInternal, sizeof( anElement.SymbolNameInternal ), &element[1], sizeof( anElement.SymbolNameInternal ) - 1 );
            anElement.Element_1_0.SymbolName = anElement.SymbolNameInternal;

            if( value == nullptr )
            {
                // Finish element as local counter symbol
                anElement.Element_1_0.Type = EQUATION_ELEM_LOCAL_COUNTER_SYMBOL;
            }
            else
            {
                // Finish element as global symbol
                anElement.Element_1_0.Type = EQUATION_ELEM_GLOBAL_SYMBOL;
            }
            return AddEquationElement( &anElement );
        }
        else if( strncmp( element, "i$", sizeof( "i$" ) - 1 ) == 0 )
        {
            // Add element
            CEquationElementInternal anElement;

            iu_strncpy_s( anElement.SymbolNameInternal, sizeof( anElement.SymbolNameInternal ), &element[2], sizeof( anElement.SymbolNameInternal ) - 1 );
            // finish element
            anElement.Element_1_0.SymbolName = anElement.SymbolNameInternal;
            anElement.Element_1_0.Type       = EQUATION_ELEM_INFORMATION_SYMBOL;

            return AddEquationElement( &anElement );
        }
        else if( strchr( element, '.' ) != nullptr ) // assume float number
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type           = EQUATION_ELEM_IMM_FLOAT;
            anElement.Element_1_0.ImmediateFloat = (float) atof( element );
            return AddEquationElement( &anElement );
        }
        else if( strncmp( element, "0x", sizeof( "0x" ) - 1 ) == 0 ) // assume hex integer 64
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type            = EQUATION_ELEM_IMM_UINT64;
            anElement.Element_1_0.ImmediateUInt64 = strtoull( element, nullptr, 0 );
            return AddEquationElement( &anElement );
        }
        else if( element[0] >= '0' && element[0] <= '9' ) // assume decimal integer 64
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type            = EQUATION_ELEM_IMM_UINT64;
            anElement.Element_1_0.ImmediateUInt64 = strtoull( element, nullptr, 10 );
            return AddEquationElement( &anElement );
        }
        else if( strncmp( element, "mask$", sizeof( "mask$" ) - 1 ) == 0 ) // assume hex integer 64
        {
            CEquationElementInternal anElement;
            anElement.Element_1_0.Type = EQUATION_ELEM_MASK;
            anElement.Element_1_0.Mask = GetByteArrayFromCStringMask( element + sizeof( "mask$" ) - 1, adapterId );
            MD_CHECK_PTR_RET_A( adapterId, anElement.Element_1_0.Mask.Data, false )
            return AddEquationElement( &anElement );
        }

        MD_LOG_A( adapterId, LOG_ERROR, "Unknown equation element: %s", element );
        return false;
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
        const uint32_t adapterId = OBTAIN_ADAPTER_ID( m_device );

        if( metricFile == nullptr )
        {
            MD_ASSERT_A( adapterId, metricFile != nullptr );
            return CC_ERROR_INVALID_PARAMETER;
        }

        WriteCStringToFile( m_equationString, metricFile, adapterId );

        return CC_OK;
    }
} // namespace MetricsDiscoveryInternal
