/*========================== begin_copyright_notice ============================

Copyright (C) 2022-2025 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_concurrent_group.h

//     Abstract:   C++ Metrics Discovery internal concurrent group header

#pragma once

#include "metrics_discovery_internal_api.h"
#include "md_types.h"

#include <cstdio>
#include <vector>
#include <list>
#include <string>

//////////////////////////////////////////////////////////////////////////////
// Helper macro to get CustomMetricSetParams
//////////////////////////////////////////////////////////////////////////////
#define MD_CUSTOM_METRIC_SET_PARAMS( params, version ) ( params )->CustomMetricSetParams_##version

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    ///////////////////////////////////////////////////////////////////////////////
    // Forward declarations:                                                     //
    ///////////////////////////////////////////////////////////////////////////////
    class CMetricsDevice;
    class CMetricSet;
    class CInformation;

    struct SArchEvent;
    using TArchEvent = SArchEvent;

    class CMetricEnumerator;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CConcurrentGroup
    //
    // Description:
    //     The metrics groups that can be collected concurrently to another group.
    //     Stores metric sets.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CConcurrentGroup : public IInternalConcurrentGroup
    {
    public:
        // API 1.13:
        using IConcurrentGroup_1_13::AddMetricSet; // To avoid hiding by 1.13 interface function

        virtual TConcurrentGroupParamsLatest* GetParams( void );
        virtual IMetricSetLatest*             GetMetricSet( uint32_t index );

        // Internal API (IInternalConcurrentGroup):
        virtual IMetricSetLatest* AddCustomMetricSet( TAddCustomMetricSetParams* params, IMetricSetLatest* referenceMetricSet, bool copyInformationOnly );

    public:
        // Constructor & Destructor:
        CConcurrentGroup( CMetricsDevice& device, const char* name, const char* longName, const uint32_t measurementTypeMask );
        virtual ~CConcurrentGroup();

        CConcurrentGroup( const CConcurrentGroup& )            = delete; // Delete copy-constructor
        CConcurrentGroup& operator=( const CConcurrentGroup& ) = delete; // Delete assignment operator

        // Non-API:
        CMetricSet* AddMetricSet( const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t categoryMask, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, const char* availabilityEquation = nullptr, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );
        CMetricSet* GetMatchingMetricSet( const char* symbolName, TByteArrayLatest* platformMask, uint32_t gtMask, bool findWithTrueAvailabilityEquation = false );

        CInformation*       AddInformation( const char* symbolName, const char* shortName, const char* longName, const char* groupName, uint32_t apiMask, TInformationType informationType, const char* informationUnits, const char* availabilityEquation, uint32_t informationXmlId );
        CInformation*       AddInformation( CInformation* information );
        IInformationLatest* GetInformation( uint32_t index );
        uint32_t            GetInformationCount();

        CMetricsDevice& GetMetricsDevice();

        template <typename TMetricSet>
        TMetricSet* AddMetricSetExplicit( const char* symbolicName, const char* shortName, const uint32_t apiMask, const uint32_t categoryMask, const uint32_t snapshotReportSize, const uint32_t deltaReportSize, const TReportType reportType, TByteArrayLatest* platformMask, const char* availabilityEquation = nullptr, const uint32_t gtMask = GT_TYPE_ALL, const bool isCustom = false )
        {
            TMetricSet* set = new( std::nothrow ) TMetricSet( m_device, this, symbolicName, shortName, apiMask, categoryMask, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom );

            return static_cast<TMetricSet*>( InitializeMetricSet( set, platformMask, availabilityEquation, gtMask ) );
        }

        TCompletionCode Lock();
        TCompletionCode Unlock();
        TCompletionCode WriteCConcurrentGroupToBuffer( uint8_t* buffer, uint32_t& bufferSize, uint32_t& bufferOffset, IMetricSet_1_13** metricSets, uint32_t metricSetCount );

    protected:
        CMetricSet*       InitializeMetricSet( CMetricSet* set, TByteArrayLatest* platformMask, const char* availabilityEquation, const uint32_t gtMask );
        IMetricSetLatest* AddCustomMetricSet( CMetricSet* referenceMetricSet, const char* signalName, const char* symbolName, const char* shortName, uint32_t apiMask, uint32_t categoryMask, TByteArrayLatest* platformMask, uint32_t gtMask, uint32_t rawReportSize, uint32_t queryReportSize, const char* complementarySetsList, TApiSpecificId_1_0 apiSpecificId, TRegisterSet* startRegSets, uint32_t startRegSetsCount, const char* availabilityEquation, TReportType reportType, bool copyInformationOnly = false );
        bool              MatchingSetExists( const char* symbolName, TByteArrayLatest* platformMask, uint32_t gtMask );
        bool              AreMetricSetParamsValid( const char* symbolName, const char* shortName, TByteArrayLatest* platformMask, uint32_t gtMask, TRegisterSet* startRegSets, uint32_t startRegSetsCount );
        uint32_t          GetCustomSetCount();
        TCompletionCode   FillLockSemaphoreName( char* name, size_t size );

        CMetricSet* FindSameMetricSetForPlatform( CMetricSet* metricSet, const TByteArrayLatest* platformMask, const uint32_t gtMask );

    protected:
        // Variables:
        TConcurrentGroupParamsLatest m_params;
        void*                        m_semaphore;

        std::vector<CMetricSet*> m_setsVector;
        std::list<CMetricSet*>   m_otherSetsList; // List of sets unavailable on current platform

        std::vector<CInformation*> m_informationVector;
        std::vector<CInformation*> m_otherInformationVector;
        uint32_t                   m_informationCount;

        CMetricsDevice& m_device;

    protected:
        // Static variables:
        static constexpr TReportType DEFAULT_METRIC_SET_REPORT_TYPE     = OA_REPORT_TYPE_256B_A45_NOA16;
        static constexpr TReportType DEFAULT_METRIC_SET_REPORT_TYPE_XE2 = OA_REPORT_TYPE_576B_PEC64LL;
    };

} // namespace MetricsDiscoveryInternal
