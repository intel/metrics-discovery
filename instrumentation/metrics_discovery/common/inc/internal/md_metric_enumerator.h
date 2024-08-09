/*========================== begin_copyright_notice ============================

Copyright (C) 2024 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_metric_enumerator.h
//
//     Abstract:   C++ Metrics Discovery internal metric enumerator header

#pragma once

#include "metrics_discovery_api.h"

#include "instr_gt_driver_ifc.h"

#include <vector>

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    ///////////////////////////////////////////////////////////////////////////////
    // Forward declarations:                                                     //
    ///////////////////////////////////////////////////////////////////////////////
    struct SHwEvent;
    using THwEvent = SHwEvent;

    class CMetricsDevice;
    class CMetricPrototype;
    class COAConcurrentGroup;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricEnumerator
    //
    // Description:
    //     The metric enumerator allows to get metric prototypes.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CMetricEnumerator : public IMetricEnumeratorLatest
    {
    public:
        // API 1.13:
        virtual uint32_t               GetMetricPrototypeCount( void );
        virtual IMetricPrototype_1_13* GetMetricPrototype( const uint32_t index );
        virtual TCompletionCode        GetMetricPrototypes( const uint32_t index, uint32_t* count, IMetricPrototype_1_13** metrics );
        virtual TCompletionCode        RemoveClonedMetricPrototype( IMetricPrototype_1_13* clonedPrototype );

    public:
        // Constructor & Destructor:
        CMetricEnumerator( COAConcurrentGroup& oaConcurrentGroup );
        virtual ~CMetricEnumerator();

        CMetricEnumerator( const CMetricEnumerator& )            = delete; // Delete copy-constructor
        CMetricEnumerator& operator=( const CMetricEnumerator& ) = delete; // Delete assignment operator

        // Non-API:
        bool                            IsInitialized() const;
        TCompletionCode                 Initialize( const uint32_t oaReportingTypeMask );
        std::vector<CMetricPrototype*>& GetMetricPrototypes();
        COAConcurrentGroup&             GetConcurrentGroup();
        CMetricsDevice&                 GetMetricsDevice();

    protected:
        std::vector<CMetricPrototype*> m_metricPrototypes;

    private:
        // Variables:
        COAConcurrentGroup& m_oaConcurrentGroup;
        CMetricsDevice&     m_device;
        bool                m_isInitialized;

        // Non-API:
        TCompletionCode     ReadEvents( const char* archEvents, const uint32_t archEventsSize, const char* hwEvents, const uint32_t hwEventsSize );
        TCompletionCode     ReadArchEvents( uint8_t* fileBuffer, const uint32_t fileSize );
        TCompletionCode     ReadHwEvents( uint8_t* fileBuffer, const uint32_t fileSize );
        TCompletionCode     ReadWorkarounds( uint8_t* fileBuffer, const uint32_t fileSize );
        TCompletionCode     ReadCsvRow( uint8_t*& fileBuffer, const uint32_t fileSize, std::vector<const char*>& rowValues );
        char*               ReadCsvValue( uint8_t* fileBuffer, const uint32_t fileSize, const uint32_t startIndex, uint32_t& endIndex, bool& endOfRow );
        void                GetColumnAndRowCount( uint8_t* fileBuffer, const uint32_t fileSize, uint32_t& columnCount, uint32_t& rowCount );
        TByteArrayLatest*   CStrToPlatformMask( const char* const platformString );
        GTDI_PLATFORM_INDEX CStrToPlatformIndex( const char* const platformString );
    };

} // namespace MetricsDiscoveryInternal
