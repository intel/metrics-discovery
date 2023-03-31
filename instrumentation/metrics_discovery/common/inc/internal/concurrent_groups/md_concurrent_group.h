/*========================== begin_copyright_notice ============================

Copyright (C) 2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_concurrent_group.h

//     Abstract:   C++ Metrics Discovery internal concurrent group header

#pragma once

#include "md_utils.h"

#include "md_adapter.h"
#include "md_metrics_device.h"
#include "md_metric_set.h"

#include <cstdio>
#include <vector>
#include <list>

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
    class CInformation;

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
        // API 1.0:
        virtual TConcurrentGroupParamsLatest* GetParams( void );
        virtual IMetricSetLatest*             GetMetricSet( uint32_t index );

        // Internal API (IInternalConcurrentGroup):
        virtual IMetricSetLatest* AddCustomMetricSet( TAddCustomMetricSetParams* params, IMetricSetLatest* referenceMetricSet, bool copyInformationOnly );

    public:
        // Constructor & Destructor:
        CConcurrentGroup( CMetricsDevice* device, const char* name, const char* longName, const uint32_t measurementTypeMask );
        virtual ~CConcurrentGroup();

        // Non-API:
        CMetricSet* AddMetricSet( const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t categoryMask, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, const char* availabilityEquation = nullptr, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );
        CMetricSet* GetMatchingMetricSet( const char* symbolName, TByteArrayLatest* platformMask, uint32_t gtMask, bool findWithTrueAvailabilityEquation = false );

        CInformation*       AddInformation( const char* symbolName, const char* shortName, const char* longName, const char* groupName, uint32_t apiMask, TInformationType informationType, const char* informationUnits, const char* availabilityEquation, uint32_t informationXmlId );
        CInformation*       AddInformation( CInformation* information );
        IInformationLatest* GetInformation( uint32_t index );
        uint32_t            GetInformationCount();
        CMetricsDevice*     GetMetricsDevice();

        template <typename TMetricSet>
        TMetricSet* AddMetricSetExplicit( const char* symbolicName, const char* shortName, const uint32_t apiMask, const uint32_t categoryMask, const uint32_t snapshotReportSize, const uint32_t deltaReportSize, const TReportType reportType, TByteArrayLatest* platformMask, const char* availabilityEquation = nullptr, const uint32_t gtMask = GT_TYPE_ALL, const bool isCustom = false )
        {
            TCompletionCode ret             = CC_OK;
            const uint32_t  adapterId       = OBTAIN_ADAPTER_ID( m_device );
            CMetricSet*     alreadyAddedSet = nullptr;
            TMetricSet*     set             = new( std::nothrow ) TMetricSet( m_device, this, symbolicName, shortName, apiMask, categoryMask, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom );
            MD_CHECK_PTR_RET_A( adapterId, set, nullptr );

            if( set->Initialize() != CC_OK )
            {
                MD_LOG_A( adapterId, LOG_ERROR, "Error initializing metrics" );
                MD_SAFE_DELETE( set );
                return nullptr;
            }

            if( set->SetAvailabilityEquation( availabilityEquation ) != CC_OK )
            {
                MD_LOG_A( adapterId, LOG_ERROR, "Error setting metric set equations" );
                MD_SAFE_DELETE( set );
                return nullptr;
            }

            bool isSuitablePlatform = m_device->IsPlatformTypeOf( platformMask, gtMask ) && set->IsAvailabilityEquationTrue();
            if( isSuitablePlatform )
            {
                // Check if metric set is already present in m_setsVector or m_otherSetsList.
                alreadyAddedSet = GetMatchingMetricSet( symbolicName, platformMask, gtMask, true );
                if( alreadyAddedSet != nullptr )
                {
                    // If metric set present in m_setsVector it should be move to m_otherSetsList.
                    // Metric set compared to alreadyAddedSet will be added in else section as unavailable on this platform.
                    auto iterator = std::find( m_setsVector.begin(), m_setsVector.end(), alreadyAddedSet );
                    if( iterator != m_setsVector.end() )
                    {
                        MD_LOG_A( adapterId, LOG_WARNING, "Attempt to add metric set [%s] with the same name and true availability equation.", alreadyAddedSet->GetParams()->SymbolName );

                        m_setsVector.erase( iterator );
                        m_params.MetricSetsCount = m_setsVector.size();

                        m_otherSetsList.push_back( alreadyAddedSet );
                    }
                }
            }

            if( isSuitablePlatform && alreadyAddedSet == nullptr )
            {
                m_setsVector.push_back( set );
                m_params.MetricSetsCount = m_setsVector.size();
                MD_LOG_A( adapterId, LOG_INFO, "%s - added", set->GetParams()->SymbolName );
            }
            else
            {
                MD_LOG_A( adapterId, LOG_INFO, "%s - not available", set->GetParams()->SymbolName );
                m_otherSetsList.push_back( set );
            }

            return set;
        }

        TCompletionCode Lock();
        TCompletionCode Unlock();
        TCompletionCode WriteCConcurrentGroupToFile( FILE* metricFile );

    protected:
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

        CMetricsDevice* m_device;

    protected:
        // Static variables:
        static constexpr uint32_t    SETS_VECTOR_INCREASE           = 16;
        static constexpr uint32_t    INFORMATION_VECTOR_INCREASE    = 16;
        static constexpr TReportType DEFAULT_METRIC_SET_REPORT_TYPE = OA_REPORT_TYPE_256B_A45_NOA16;
    };

} // namespace MetricsDiscoveryInternal
