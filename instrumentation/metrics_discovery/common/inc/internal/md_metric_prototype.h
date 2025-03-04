/*========================== begin_copyright_notice ============================

Copyright (C) 2024-2025 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_metric_prototype.h
//
//     Abstract:   C++ Metrics Discovery internal metric prototype header

#pragma once

#include "metrics_discovery_api.h"
#include "md_events.h"

#include <vector>

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    ///////////////////////////////////////////////////////////////////////////////
    // Forward declarations:                                                     //
    ///////////////////////////////////////////////////////////////////////////////
    class CMetricEnumerator;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricPrototype
    //
    // Description:
    //     The metric prototype that is sampled. Stores all metric prototype
    //     information.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CMetricPrototype : public IMetricPrototypeLatest
    {
    public:
        // API 1.13:
        virtual const TMetricPrototypeParams_1_13*           GetParams( void ) const;
        virtual IMetricPrototype_1_13*                       Clone( void );
        virtual const TMetricPrototypeOptionDescriptor_1_13* GetOptionDescriptor( uint32_t index ) const;
        virtual TCompletionCode                              SetOption( const TOptionDescriptorType optionType, const TTypedValue_1_0* typedValue );
        virtual TCompletionCode                              ChangeNames( const char* symbolName, const char* shortName, const char* longName, const char* resultUnits );

    public:
        // Constructor & Destructor:
        CMetricPrototype( CMetricEnumerator& metricEnumerator, THwEvent&& hwEvent, const CMetricPrototype* parent = nullptr, const bool canBeDeleted = true );
        virtual ~CMetricPrototype();

        CMetricPrototype( const CMetricPrototype& )            = delete; // Delete copy-constructor
        CMetricPrototype& operator=( const CMetricPrototype& ) = delete; // Delete assignment operator

        // Non-API:
        TCompletionCode                           Initialize();
        void                                      IncreaseReferenceCounter();
        void                                      DecreaseReferenceCounter();
        uint32_t                                  GetReferenceCounter() const;
        bool                                      CanBeDeleted() const;
        const CMetricPrototype*                   GetParent() const;
        TCompletionCode                           UpdateParent( const CMetricPrototype* parent );
        THwEvent&                                 GetHwEvent();
        const std::vector<TOptionDescriptorType>& GetAppliedOptions() const;
        CMetricEnumerator&                        GetMetricEnumerator() const;

    private:
        void        UpdateDescription( std::string& longName, std::string& suffix, const TOptionDescriptorType optionType ) const;
        void        UpdateNames( std::string& symbolName, std::string& shortName, const TOptionDescriptorType optionType ) const;
        void        DeleteSuffixFromName( std::string& name, std::string& nameLowerCase, const std::string_view suffix ) const;
        std::string GetSuffix( std::string& suffix ) const;
        std::string GetDisaggregationName( const TDisaggregationMode mode ) const;

    private:
        // Variables:
        CMetricEnumerator&                                   m_metricEnumerator;
        THwEvent                                             m_hwEvent;
        std::vector<TMetricPrototypeOptionDescriptorLatest*> m_optionsDescriptor;
        const CMetricPrototype*                              m_parent;
        TMetricPrototypeParams_1_13                          m_params_1_13;
        std::vector<TMetricPrototypeOptionDescriptorLatest*> m_availableOptions;
        std::vector<TOptionDescriptorType>                   m_appliedOptions;
        uint32_t                                             m_referenceCounter;
        char                                                 m_symbolNameSeparator;
        bool                                                 m_canBeDeleted; // From metric set.
    };
} // namespace MetricsDiscoveryInternal
