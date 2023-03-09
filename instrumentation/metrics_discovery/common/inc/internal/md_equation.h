/*========================== begin_copyright_notice ============================

Copyright (C) 2022 Intel Corporation

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
    class CEquationElementInternal
    {
    public:
        CEquationElementInternal();
        CEquationElementInternal( const CEquationElementInternal& element );
        CEquationElementInternal& operator=( const CEquationElementInternal& element );

        TEquationElement_1_0 Element_1_0;
        char                 SymbolNameInternal[32];
        int32_t              MetricIndexInternal;
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
    private:
    public:
        // API 1.0:
        virtual uint32_t              GetEquationElementsCount();
        virtual TEquationElement_1_0* GetEquationElement( uint32_t index );

    public:
        // Constructor and Destructor:
        CEquation( CMetricsDevice* device );
        explicit CEquation( const CEquation& other );
        virtual ~CEquation();

        // Non-API:
        bool SolveBooleanEquation( void ); // Used only for availability equations
        bool ParseEquationString( const char* equationString );
        bool AddEquationElement( const CEquationElementInternal* element );
        bool ParseEquationElement( const char* element );

        TCompletionCode WriteCEquationToFile( FILE* metricFile );

        // Inline function.
        inline std::vector<CEquationElementInternal>& GetElementsVector()
        {
            return m_elementsVector;
        }

    private:
        // Variables:
        std::vector<CEquationElementInternal> m_elementsVector;
        const char*                           m_equationString;
        CMetricsDevice*                       m_device;

    private:
        // Static variables:
        static constexpr uint32_t EQUATION_VECTOR_INCREASE = 32;
    };
} // namespace MetricsDiscoveryInternal
