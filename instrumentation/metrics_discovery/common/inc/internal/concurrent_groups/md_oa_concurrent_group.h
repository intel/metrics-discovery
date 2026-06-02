/*========================== begin_copyright_notice ============================

Copyright (C) 2022-2026 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_oa_concurrent_group.h

//     Abstract:   C++ Metrics Discovery oa concurrent group header

#pragma once

#include "md_concurrent_group.h"

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
        // API 1.15:
        virtual TCompletionCode OpenIoStream( IMetricSet_1_13* metricSet, uint32_t processId, uint32_t* nsTimerPeriod, uint32_t* oaBufferSize, TIoStreamState state ) final;
        virtual TCompletionCode ChangeIoStreamState( TIoStreamState state, uint32_t* nsTimerPeriod ) final;

        // API 1.13:
        virtual IMetricEnumerator_1_13* GetMetricEnumerator( void ) override;
        virtual IMetricEnumerator_1_13* GetMetricEnumeratorFromFile( const char* fileName ) final;
        virtual IMetricSet_1_13*        AddMetricSet( const char* symbolName, const char* shortName ) override;
        virtual TCompletionCode         RemoveMetricSet( IMetricSet_1_13* metricSet ) final;

        // API 1.3:
        virtual TCompletionCode SetIoStreamSamplingType( TSamplingType samplingType ) final;

        // API 1.0:
        virtual TCompletionCode   OpenIoStream( IMetricSet_1_0* metricSet, uint32_t processId, uint32_t* nsTimerPeriod, uint32_t* oaBufferSize ) final;
        virtual TCompletionCode   ReadIoStream( uint32_t* reportCount, char* reportData, uint32_t readFlags ) final;
        virtual TCompletionCode   CloseIoStream( void ) final;
        virtual TCompletionCode   WaitForReports( uint32_t milliseconds ) final;
        virtual IInformation_1_0* GetIoMeasurementInformation( uint32_t index ) final;
        virtual IInformation_1_0* GetIoGpuContextInformation( uint32_t index ) final;

        // Internal API (IInternalConcurrentGroup):
        virtual IMetricSetLatest* AddCustomMetricSet( TAddCustomMetricSetParams* params, IMetricSetLatest* referenceMetricSet, bool copyInformationOnly = false ) final;

    public:
        // Constructor & Destructor:
        COAConcurrentGroup( CMetricsDevice& device, const char* name, const char* longName, const uint32_t measurementTypeMask );
        virtual ~COAConcurrentGroup();

        COAConcurrentGroup( const COAConcurrentGroup& )            = delete; // Delete copy-constructor
        COAConcurrentGroup& operator=( const COAConcurrentGroup& ) = delete; // Delete assignment operator

        CMetricSet*         GetIoMetricSet();
        TStreamType         GetStreamType() const;
        GTDI_OA_BUFFER_TYPE GetOaBufferType() const;

        void* GetStreamEventHandle();
        void  SetStreamEventHandle( void* streamEventHandle );

        std::vector<TArchEvent*>& GetArchEvents();

    protected:
        // Constructor:
        COAConcurrentGroup( CMetricsDevice& device, const char* name, const char* description, const uint32_t measurementTypeMask, const TStreamType streamType, const GTDI_OA_BUFFER_TYPE oaBufferType );

        TCompletionCode OpenIoStream( CMetricSet* metricSet, uint32_t processId, uint32_t* nsTimerPeriod, uint32_t* oaBufferSize, TIoStreamState state );

        TCompletionCode RemoveMetricSetInternal( CMetricSet* metricSet );

        TCompletionCode SetIoMetricSet( IMetricSet_1_0* metricSet );

        CInformation*   AddIoMeasurementInformation( const char* name, const char* shortName, const char* longName, const char* group, TInformationType informationType, const char* informationUnits );
        void            AddIoMeasurementInfoPredefined( void );
        void            SetIoMeasurementInfoPredefined( const TIoMeasurementInfoType ioMeasurementInfoType, const uint32_t value, uint32_t& index );
        TCompletionCode GetStreamTypeFromSamplingType( const TSamplingType samplingType, TStreamType& streamType ) const;

        CMetricEnumerator* GetMetricEnumerator( const uint32_t oaReportingTypeMask );

    protected:
        // Variables:
        TStreamType                     m_streamType;
        const GTDI_OA_BUFFER_TYPE       m_oaBufferType;
        CMetricSet*                     m_ioMetricSet;
        bool                            m_contextTagsEnabled;
        uint32_t                        m_processId;
        void*                           m_streamEventHandle;
        std::vector<CInformation*>      m_ioMeasurementInfoVector;
        std::vector<CInformation*>      m_ioGpuContextInfoVector;
        std::vector<CMetricEnumerator*> m_metricEnumeratorVector;
        std::vector<TArchEvent*>        m_archEventVector;
    };

} // namespace MetricsDiscoveryInternal
