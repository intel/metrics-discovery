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

#include <cstdio>
#include <vector>
#include <list>

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    ///////////////////////////////////////////////////////////////////////////////
    // Forward declarations:                                                     //
    ///////////////////////////////////////////////////////////////////////////////
    class CInformation;
    class CMetricSet;

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
        virtual TConcurrentGroupParams_1_0* GetParams( void );
        virtual IMetricSetLatest*           GetMetricSet( uint32_t index );

        // Internal API (IInternalConcurrentGroup):
        virtual IMetricSetLatest* AddCustomMetricSet( TAddCustomMetricSetParams* params, IMetricSetLatest* referenceMetricSet, bool copyInformationOnly );

    public:
        // Constructor & Destructor:
        CConcurrentGroup( CMetricsDevice* device, const char* name, const char* longName, uint32_t measurementTypeMask );
        virtual ~CConcurrentGroup();

        // Non-API:
        CMetricSet* AddMetricSet( const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t categoryMask, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, uint32_t platformMask, const char* availabilityEquation = nullptr, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );
        CMetricSet* GetMatchingMetricSet( const char* symbolName, uint32_t platformMask, uint32_t gtMask, bool findWithTrueAvailabilityEquation = false );

        CInformation*       AddInformation( const char* symbolName, const char* shortName, const char* longName, const char* groupName, uint32_t apiMask, TInformationType informationType, const char* informationUnits, const char* availabilityEquation, uint32_t informationXmlId );
        CInformation*       AddInformation( CInformation* information );
        IInformationLatest* GetInformation( uint32_t index );
        uint32_t            GetInformationCount();

        CMetricsDevice* GetMetricsDevice();

        TCompletionCode Lock();
        TCompletionCode Unlock();
        TCompletionCode WriteCConcurrentGroupToFile( FILE* metricFile );

    protected:
        IMetricSetLatest* AddCustomMetricSet( CMetricSet* referenceMetricSet, const char* signalName, const char* symbolName, const char* shortName, uint32_t apiMask, uint32_t categoryMask, uint32_t platformMask, uint32_t gtMask, uint32_t rawReportSize, uint32_t queryReportSize, const char* complementarySetsList, TApiSpecificId_1_0 apiSpecificId, TRegisterSet* startRegSets, uint32_t startRegSetsCount, const char* availabilityEquation, TReportType reportType, bool copyInformationOnly = false );
        bool              MatchingSetExists( const char* symbolName, uint32_t platformMask, uint32_t gtMask );
        bool              AreMetricSetParamsValid( const char* symbolName, const char* shortName, uint32_t platformMask, uint32_t gtMask, TRegisterSet* startRegSets, uint32_t startRegSetsCount );
        uint32_t          GetCustomSetCount();
        TCompletionCode   FillLockSemaphoreName( char* name, size_t size );

        CMetricSet* FindSameMetricSetForPlatform( CMetricSet* metricSet, uint32_t platformMask );

    public:
        bool m_isAvailabile;

    protected:
        // Variables:
        TConcurrentGroupParamsLatest m_params_1_0;
        void*                        m_semaphore;

        std::vector<CMetricSet*> m_setsVector;
        std::list<CMetricSet*>   m_otherSetsList; // List of sets unavailable on current platform

        std::vector<CInformation*> m_informationVector;
        std::vector<CInformation*> m_otherInformationVector;
        uint32_t                   m_informationCount;

        CMetricsDevice* m_device;

    protected:
        // Static variables:
        static const uint32_t    SETS_VECTOR_INCREASE           = 16;
        static const uint32_t    INFORMATION_VECTOR_INCREASE    = 16;
        static const TReportType DEFAULT_METRIC_SET_REPORT_TYPE = OA_REPORT_TYPE_256B_A45_NOA16;
    };

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     COAConcurrentGroup
    //
    // Description:
    //     The OA metrics groups that can be collected concurrently to another group.
    //     Stores metric sets. It has IO Stream implemented.
    //
    //////////////////////////////////////////////////////////////////////////////
    class COAConcurrentGroup : public CConcurrentGroup
    {
    public:
        // API 1.3:
        virtual TCompletionCode SetIoStreamSamplingType( TSamplingType type );

        // API 1.0:
        virtual TCompletionCode OpenIoStream( IMetricSet_1_0* metricSet, uint32_t processId, uint32_t* nsTimerPeriod, uint32_t* oaBufferSize );
        virtual TCompletionCode ReadIoStream( uint32_t* reportCount, char* reportData, uint32_t readFlags );
        virtual TCompletionCode CloseIoStream( void );
        virtual TCompletionCode WaitForReports( uint32_t milliseconds );
        IInformation_1_0*       GetIoMeasurementInformation( uint32_t index );
        IInformation_1_0*       GetIoGpuContextInformation( uint32_t index );

        // Internal API (IInternalConcurrentGroup):
        virtual IMetricSetLatest* AddCustomMetricSet( TAddCustomMetricSetParams* params, IMetricSetLatest* referenceMetricSet, bool copyInformationOnly = false );

    public:
        // Constructor & Destructor:
        COAConcurrentGroup( CMetricsDevice* device, const char* name, const char* longName, uint32_t measurementTypeMask );
        virtual ~COAConcurrentGroup();

    protected:
        CInformation*   AddIoMeasurementInformation( const char* name, const char* shortName, const char* longName, const char* group, TInformationType informationType, const char* informationUnits );
        void            AddIoMeasurementInfoPredefined( void );
        CInformation*   AddIoGpuContextInformation( const char* name, const char* shortName, const char* longName, const char* group, TInformationType informationType, const char* informationUnits );
        void            SetIoMeasurementInfoPredefined( TIoMeasurementInfoType ioMeasurementInfoType, uint32_t value, uint32_t* index );
        TCompletionCode ReadGpuContextIdTags( void );
        TCompletionCode TryReadGpuCtxTags( void );

    protected:
        // Variables:
        TStreamType                m_streamType;
        CMetricSet*                m_ioMetricSet;
        bool                       m_contextTagsEnabled;
        uint32_t                   m_processId;
        void*                      m_streamEventHandle;
        std::vector<CInformation*> m_ioMeasurementInfoVector;
        std::vector<CInformation*> m_ioGpuContextInfoVector;

    protected:
        // Static variables:
        static const uint32_t EXCEPTIONS_VECTOR_INCREASE   = 16;
        static const uint32_t GPU_CONTEXTS_VECTOR_INCREASE = 16;
    };

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CPerfMonConcurrentGroup
    //
    // Description:
    //     The PerfMon metrics groups that can be collected concurrently to another group.
    //     Stores metric sets. It has Sys IO Stream implemented.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CPerfMonConcurrentGroup : public COAConcurrentGroup
    {
    public:
        // API 1.0:
        TCompletionCode OpenIoStream( IMetricSet_1_0* metricSet, uint32_t processId, uint32_t* nsTimerPeriod, uint32_t* sysBufferSize );
        TCompletionCode ReadIoStream( uint32_t* reportCount, char* reportData, uint32_t readFlags );
        TCompletionCode CloseIoStream( void );
        TCompletionCode WaitForReports( uint32_t milliseconds );

    public:
        // Constructor & Destructor:
        CPerfMonConcurrentGroup( CMetricsDevice* device, const char* name, const char* description, uint32_t measurementTypeMask );
    };
} // namespace MetricsDiscoveryInternal
