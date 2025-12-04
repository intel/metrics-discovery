/*========================== begin_copyright_notice ============================

Copyright (C) 2024-2025 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_metric_prototype_manager.h

//     Abstract:   C++ Metrics Discovery internal metric prototype manager header

#pragma once

#include "md_events.h"
#include "md_metrics_device.h"

#include <vector>

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    ///////////////////////////////////////////////////////////////////////////////
    // Forward declarations:                                                     //
    ///////////////////////////////////////////////////////////////////////////////
    class CMetricPrototype;

    ///////////////////////////////////////////////////////////////////////////////
    // Metric prototype manager types:                                           //
    ///////////////////////////////////////////////////////////////////////////////
    typedef enum EMetricPrototypeManagerType
    {
        METRIC_PROTOTYPE_MANAGER_TYPE_OA  = 0,
        METRIC_PROTOTYPE_MANAGER_TYPE_OAM = 1,
    } TMetricPrototypeManagerType;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CPrototypeManager
    //
    // Description:
    //     Manages metric prototype constrains that vary on different HW.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CPrototypeManager
    {
    public:
        // Methods:
        CPrototypeManager( CMetricsDevice& device, CMetricSet& metricSet );
        virtual ~CPrototypeManager() {};

        TCompletionCode         AddPrototype( CMetricPrototype& prototype );
        TCompletionCode         RemovePrototype( CMetricPrototype& prototype );
        virtual TCompletionCode CreateMetricsFromPrototypes();
        void                    DecreasePrototypesReferenceCounters();
        bool                    IsEmpty();
        virtual bool            IsSupported() = 0;

    protected:
        // Methods:
        using THwEventPair         = std::pair<const THwEvent*, uint32_t>;
        using THwEventPairVector   = std::vector<THwEventPair>;
        using THwEventPairIterator = THwEventPairVector::iterator;

        TCompletionCode AddHwEvent( CMetricPrototype& prototype );
        TCompletionCode RemoveHwEvent( CMetricPrototype& prototype );
        bool            IsPrototypeAlreadyAdded( const CMetricPrototype& prototype );
        bool            AddHwEvent( THwEventPairVector& group, const uint32_t maxSize, const THwEvent& hwEvent );
        bool            RemoveHwEvent( const THwEvent& hwEvent );

        THwEventPairIterator  GetHwEventIteratorFromGroup( THwEventPairVector& group, const THwEvent& hwEvent );
        virtual THwEventGroup GetHwEventGroup( const THwEvent& hwEvent ) = 0;

        CMetric*                AddMetricToSet( const CMetricPrototype& prototype, const uint32_t metricIndex );
        TCompletionCode         AddEquations( CMetricPrototype& prototype, CMetric& metric, const uint32_t snapshotReportOffset, const uint32_t deltaReportOffset );
        TCompletionCode         AppendNormalizationsAndWorkarounds( CMetricPrototype& prototype, CMetric& metric, std::stringstream& snapshotReportReadEquation, std::stringstream& deltaReportReadEquation );
        virtual TCompletionCode AppendPesConfiguration( const THwEvent& hwEvent, const uint64_t pesProgramming, std::vector<bool>& pesProgrammed, uint32_t flexProgramming[], uint32_t& snapshotReportOffsets, uint32_t& deltaReportOffsets ) = 0;
        virtual TCompletionCode AppendFlexConfiguration( const uint32_t flexProgramming[] )                                                                                                                                                   = 0;
        virtual uint32_t        GetMaxPesCount()                                                                                                                                                                                              = 0;
        virtual uint32_t        GetGroupMaxSize( const THwEventGroup group )                                                                                                                                                                  = 0;

        // Members:
        CMetricsDevice&                m_device;
        CMetricSet&                    m_set;
        const uint32_t                 m_deltaCounterSize;
        const uint32_t                 m_snapshotCounterSize;
        THwEventPairVector             m_firstEventGroup;
        THwEventPairVector             m_secondEventGroup;
        THwEventPairVector             m_flexEventGroup;
        std::vector<CMetricPrototype*> m_metricPrototypes;
    };

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototypeManager
    //
    // Description:
    //     Manages metric prototype constrains that vary on different HW
    //     and OA units.
    //
    //////////////////////////////////////////////////////////////////////////////
    template <TMetricPrototypeManagerType managerType>
    class CMetricPrototypeManager : public CPrototypeManager
    {
    public:
        // Methods:
        CMetricPrototypeManager( CMetricsDevice& device, CMetricSet& metricSet );
        virtual ~CMetricPrototypeManager() {};

        virtual bool IsSupported();

    private:
        // Methods:
        uint32_t GetMediaPesOffset( CConcurrentGroup& concurrentGroup );

        virtual THwEventGroup GetHwEventGroup( const THwEvent& hwEvent );

        virtual TCompletionCode AppendPesConfiguration( const THwEvent& hwEvent, const uint64_t pesProgramming, std::vector<bool>& pesProgrammed, uint32_t flexProgramming[], uint32_t& snapshotReportOffsets, uint32_t& deltaReportOffsets );
        virtual TCompletionCode AppendFlexConfiguration( const uint32_t flexProgramming[] );

        virtual uint32_t GetMaxPesCount();
        virtual uint32_t GetGroupMaxSize( const THwEventGroup group );

        // Members:
        const uint32_t m_mediaPesOffset;

        // Static members:
        static constexpr bool     m_isOa                             = ( managerType == METRIC_PROTOTYPE_MANAGER_TYPE_OA );
        static constexpr uint32_t m_snapshotReportOffsetStart        = 32;              // header size: 32 bytes.
        static constexpr uint32_t m_deltaReportOffsetStart           = m_isOa ? 16 : 0; // header size: 16 bytes.
        static constexpr uint32_t m_maxPesCount                      = m_isOa ? 64 : 8;
        static constexpr uint32_t FIRST_EVENT_GROUP_VECTOR_INCREASE  = m_isOa ? 18 : 8;
        static constexpr uint32_t SECOND_EVENT_GROUP_VECTOR_INCREASE = m_isOa ? 32 : 0;
        static constexpr uint32_t FLEX_EVENT_GROUP_VECTOR_INCREASE   = m_isOa ? 14 : 0;
        static constexpr uint32_t METRIC_PROTOTYPES_VECTOR_INCREASE  = m_isOa ? 64 : 8;
    };

    // Explicit instantiation:
    template <>
    uint32_t CMetricPrototypeManager<METRIC_PROTOTYPE_MANAGER_TYPE_OAM>::GetMediaPesOffset( CConcurrentGroup& concurrentGroup );

} // namespace MetricsDiscoveryInternal
