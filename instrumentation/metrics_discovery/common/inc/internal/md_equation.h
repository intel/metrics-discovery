/*========================== begin_copyright_notice ============================

Copyright (C) 2022-2025 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_equation.h

//     Abstract:   C++ Metrics Discovery internal equation header

#pragma once

#include "metrics_discovery_api.h"

#include <cstdio>
#include <vector>

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    ///////////////////////////////////////////////////////////////////////////////
    // Forward declarations:                                                     //
    ///////////////////////////////////////////////////////////////////////////////
    class CMetricsDevice;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquationElementInternal
    //
    // Description:
    //     Class which represents equation element.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CEquationElementInternal : public TEquationElementLatest
    {
    public:
        CEquationElementInternal();
        CEquationElementInternal( const CEquationElementInternal& element );
        CEquationElementInternal( CEquationElementInternal&& element );
        CEquationElementInternal& operator=( const CEquationElementInternal& element );
        CEquationElementInternal& operator=( CEquationElementInternal&& element );
        virtual ~CEquationElementInternal();

        int32_t MetricIndexInternal;

    private:
        void SetMembers( const CEquationElementInternal& element );
        void CopyMembers( const CEquationElementInternal& element );
        void MoveMembers( CEquationElementInternal& element );
    };

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CEquation
    //
    // Description:
    //     Class that stores all the equation information.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CEquation : public IEquationLatest
    {
    public:
        // API 1.0:
        virtual uint32_t              GetEquationElementsCount();
        virtual TEquationElement_1_0* GetEquationElement( uint32_t index );

    public:
        // Constructor and Destructor:
        CEquation( CMetricsDevice& device );
        explicit CEquation( const CEquation& other );
        virtual ~CEquation();

        CEquation& operator=( const CEquation& ) = delete; // Delete assignment operator

        // Non-API:
        bool SolveBooleanEquation( void ); // Used only for availability equations
        bool ParseEquationString( const char* equationString );
        bool ParseEquationElement( const char* equationString );

        TCompletionCode WriteCEquationToBuffer( uint8_t* buffer, uint32_t& bufferSize, uint32_t& bufferOffset );

        // Inline function.
        inline std::vector<CEquationElementInternal>& GetElementsVector()
        {
            return m_elementsVector;
        }

    private:
        // Non-API:
        bool IsLegacyMaskGlobalSymbol( const char* symbolName );

    private:
        // Variables:
        std::vector<CEquationElementInternal> m_elementsVector;
        const char*                           m_equationString;
        CMetricsDevice&                       m_device;
    };
} // namespace MetricsDiscoveryInternal
