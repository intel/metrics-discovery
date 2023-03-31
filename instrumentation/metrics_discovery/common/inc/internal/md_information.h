/*========================== begin_copyright_notice ============================

Copyright (C) 2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_information.h

//     Abstract:   C++ Metrics Discovery internal information header

#pragma once

#include "md_types.h"

#include <cstdio>

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    ///////////////////////////////////////////////////////////////////////////////
    // Forward declarations:                                                     //
    ///////////////////////////////////////////////////////////////////////////////
    class CMetricsDevice;

    ///////////////////////////////////////////////////////////////////////////////
    // Equation types:                                                           //
    ///////////////////////////////////////////////////////////////////////////////
    typedef enum EEquationType
    {
        EQUATION_IO_READ = 0,
        EQUATION_QUERY_READ,
        // ...
    } TEquationType;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CInformation
    //
    // Description:
    //     The measurement information parameter.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CInformation : public IInformationLatest
    {
    public:
        // API 1.0:
        virtual TInformationParamsLatest* GetParams( void );

    public:
        // Constructor & Destructor:
        CInformation( CMetricsDevice* device, uint32_t id, const char* name, const char* shortName, const char* longName, const char* group, uint32_t apiMask, TInformationType informationType, const char* informationUnits );
        explicit CInformation( const CInformation& other );
        virtual ~CInformation();

        // Non-API:
        TCompletionCode SetSnapshotReportReadEquation( const char* equationString );
        TCompletionCode SetDeltaReportReadEquation( const char* equationString );
        TCompletionCode SetAvailabilityEquation( const char* equationString );
        bool            IsAvailabilityEquationTrue();

        TCompletionCode SetOverflowFunction( const char* equationString );
        TCompletionCode SetOverflowFunction( TDeltaFunction_1_0 overflowFunction );

        TCompletionCode WriteCInformationToFile( FILE* metricFile );
        TCompletionCode SetInformationValue( const uint32_t value, const TEquationType equationType );
        void            SetIdInSetParam( uint32_t id );

        // Variables:
        uint32_t m_id; // Position in set before any filterings (SetApiFiltering, AvailableEquation check)

    private:
        // Variables:
        TInformationParamsLatest m_params_1_0;
        CEquation*               m_ioReadEquation;
        CEquation*               m_availabilityEquation;
        CEquation*               m_queryReadEquation;
        CMetricsDevice*          m_device;
    };
} // namespace MetricsDiscoveryInternal
