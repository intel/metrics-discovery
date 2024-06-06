/*========================== begin_copyright_notice ============================

Copyright (C) 2024 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_metric_sets_ARL_GT1.h
//
//     Abstract:   C++ automated generated file to define specific for HW
//                 MetricSet classes inherited from CMetricSet

#pragma once
#include "md_calculation.h"
#include "md_concurrent_group.h"
#include "md_equation.h"
#include "md_information.h"
#include "md_metric.h"
#include "md_metric_set.h"

#if MD_INCLUDE_ARL_GT1_METRICS

namespace MetricsDiscoveryInternal::MetricSets_ARL_GT1_PipelineStatistics
{
    class CPipelineStatsMetricSet final : public CMetricSet
    {
    public:
        CPipelineStatsMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

} // namespace MetricsDiscoveryInternal::MetricSets_ARL_GT1_PipelineStatistics

namespace MetricsDiscoveryInternal::MetricSets_ARL_GT1_OA
{
    void AddInformationSet( CConcurrentGroup* concurrentGroup );

    class CRenderBasicMetricSet final : public CMetricSet
    {
    public:
        CRenderBasicMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CComputeBasicMetricSet final : public CMetricSet
    {
    public:
        CComputeBasicMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CAsyncComputeMetricSet final : public CMetricSet
    {
    public:
        CAsyncComputeMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CXveActivityMetricSet final : public CMetricSet
    {
    public:
        CXveActivityMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CGpuBusynessMetricSet final : public CMetricSet
    {
    public:
        CGpuBusynessMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CHDCAndSFMetricSet final : public CMetricSet
    {
    public:
        CHDCAndSFMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CL3MetricSet final : public CMetricSet
    {
    public:
        CL3MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CRasterizerAndPixelBackend1MetricSet final : public CMetricSet
    {
    public:
        CRasterizerAndPixelBackend1MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CRasterizerAndPixelBackend2MetricSet final : public CMetricSet
    {
    public:
        CRasterizerAndPixelBackend2MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CRenderPipeProfileMetricSet final : public CMetricSet
    {
    public:
        CRenderPipeProfileMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CSamplerMetricSet final : public CMetricSet
    {
    public:
        CSamplerMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CTDL1MetricSet final : public CMetricSet
    {
    public:
        CTDL1MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CTDL2MetricSet final : public CMetricSet
    {
    public:
        CTDL2MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CTestOaMetricSet final : public CMetricSet
    {
    public:
        CTestOaMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CComputeOverviewMetricSet final : public CMetricSet
    {
    public:
        CComputeOverviewMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CDataportReadsMetricSet final : public CMetricSet
    {
    public:
        CDataportReadsMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CDataportWritesMetricSet final : public CMetricSet
    {
    public:
        CDataportWritesMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CL1ProfileSlmBankConflictsMetricSet final : public CMetricSet
    {
    public:
        CL1ProfileSlmBankConflictsMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CLoadStoreCacheProfileMetricSet_XeCore0 final : public CMetricSet
    {
    public:
        CLoadStoreCacheProfileMetricSet_XeCore0( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CLoadStoreCacheProfileMetricSet_XeCore3 final : public CMetricSet
    {
    public:
        CLoadStoreCacheProfileMetricSet_XeCore3( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CSLMProfileMetricSet_XeCore0 final : public CMetricSet
    {
    public:
        CSLMProfileMetricSet_XeCore0( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CSLMProfileMetricSet_XeCore3 final : public CMetricSet
    {
    public:
        CSLMProfileMetricSet_XeCore3( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt1MetricSet final : public CMetricSet
    {
    public:
        CExt1MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt4MetricSet final : public CMetricSet
    {
    public:
        CExt4MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt5MetricSet final : public CMetricSet
    {
    public:
        CExt5MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt7MetricSet final : public CMetricSet
    {
    public:
        CExt7MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt8MetricSet final : public CMetricSet
    {
    public:
        CExt8MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt10MetricSet final : public CMetricSet
    {
    public:
        CExt10MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt11MetricSet final : public CMetricSet
    {
    public:
        CExt11MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt12MetricSet final : public CMetricSet
    {
    public:
        CExt12MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt13MetricSet final : public CMetricSet
    {
    public:
        CExt13MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt14MetricSet final : public CMetricSet
    {
    public:
        CExt14MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt17MetricSet final : public CMetricSet
    {
    public:
        CExt17MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt21MetricSet final : public CMetricSet
    {
    public:
        CExt21MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt23MetricSet final : public CMetricSet
    {
    public:
        CExt23MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt28MetricSet final : public CMetricSet
    {
    public:
        CExt28MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt31MetricSet final : public CMetricSet
    {
    public:
        CExt31MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt35MetricSet final : public CMetricSet
    {
    public:
        CExt35MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt39MetricSet final : public CMetricSet
    {
    public:
        CExt39MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt43MetricSet final : public CMetricSet
    {
    public:
        CExt43MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt45MetricSet final : public CMetricSet
    {
    public:
        CExt45MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt51MetricSet final : public CMetricSet
    {
    public:
        CExt51MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt53MetricSet final : public CMetricSet
    {
    public:
        CExt53MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt57MetricSet final : public CMetricSet
    {
    public:
        CExt57MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt61MetricSet final : public CMetricSet
    {
    public:
        CExt61MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt65MetricSet final : public CMetricSet
    {
    public:
        CExt65MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt66MetricSet final : public CMetricSet
    {
    public:
        CExt66MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt73MetricSet final : public CMetricSet
    {
    public:
        CExt73MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt74MetricSet final : public CMetricSet
    {
    public:
        CExt74MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt77MetricSet final : public CMetricSet
    {
    public:
        CExt77MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt79MetricSet final : public CMetricSet
    {
    public:
        CExt79MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt80MetricSet final : public CMetricSet
    {
    public:
        CExt80MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt83MetricSet final : public CMetricSet
    {
    public:
        CExt83MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt85MetricSet final : public CMetricSet
    {
    public:
        CExt85MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt87MetricSet final : public CMetricSet
    {
    public:
        CExt87MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt91MetricSet final : public CMetricSet
    {
    public:
        CExt91MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt93MetricSet final : public CMetricSet
    {
    public:
        CExt93MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt94MetricSet final : public CMetricSet
    {
    public:
        CExt94MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt97MetricSet final : public CMetricSet
    {
    public:
        CExt97MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt98MetricSet final : public CMetricSet
    {
    public:
        CExt98MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt100MetricSet final : public CMetricSet
    {
    public:
        CExt100MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt101MetricSet final : public CMetricSet
    {
    public:
        CExt101MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt102MetricSet final : public CMetricSet
    {
    public:
        CExt102MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt104MetricSet final : public CMetricSet
    {
    public:
        CExt104MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt105MetricSet final : public CMetricSet
    {
    public:
        CExt105MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt106MetricSet final : public CMetricSet
    {
    public:
        CExt106MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt107MetricSet final : public CMetricSet
    {
    public:
        CExt107MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt113MetricSet final : public CMetricSet
    {
    public:
        CExt113MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt116MetricSet final : public CMetricSet
    {
    public:
        CExt116MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt118MetricSet final : public CMetricSet
    {
    public:
        CExt118MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt120MetricSet final : public CMetricSet
    {
    public:
        CExt120MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt122MetricSet final : public CMetricSet
    {
    public:
        CExt122MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt123MetricSet final : public CMetricSet
    {
    public:
        CExt123MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt124MetricSet final : public CMetricSet
    {
    public:
        CExt124MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt126MetricSet final : public CMetricSet
    {
    public:
        CExt126MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt128MetricSet final : public CMetricSet
    {
    public:
        CExt128MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt130MetricSet final : public CMetricSet
    {
    public:
        CExt130MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt131MetricSet final : public CMetricSet
    {
    public:
        CExt131MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt134MetricSet final : public CMetricSet
    {
    public:
        CExt134MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt135MetricSet final : public CMetricSet
    {
    public:
        CExt135MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt138MetricSet final : public CMetricSet
    {
    public:
        CExt138MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt139MetricSet final : public CMetricSet
    {
    public:
        CExt139MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt142MetricSet final : public CMetricSet
    {
    public:
        CExt142MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt143MetricSet final : public CMetricSet
    {
    public:
        CExt143MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt146MetricSet final : public CMetricSet
    {
    public:
        CExt146MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt147MetricSet final : public CMetricSet
    {
    public:
        CExt147MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt150MetricSet final : public CMetricSet
    {
    public:
        CExt150MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt151MetricSet final : public CMetricSet
    {
    public:
        CExt151MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt154MetricSet final : public CMetricSet
    {
    public:
        CExt154MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt155MetricSet final : public CMetricSet
    {
    public:
        CExt155MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt158MetricSet final : public CMetricSet
    {
    public:
        CExt158MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt159MetricSet final : public CMetricSet
    {
    public:
        CExt159MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt161MetricSet final : public CMetricSet
    {
    public:
        CExt161MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt163MetricSet final : public CMetricSet
    {
    public:
        CExt163MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt165MetricSet final : public CMetricSet
    {
    public:
        CExt165MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt167MetricSet final : public CMetricSet
    {
    public:
        CExt167MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt169MetricSet final : public CMetricSet
    {
    public:
        CExt169MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt171MetricSet final : public CMetricSet
    {
    public:
        CExt171MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt173MetricSet final : public CMetricSet
    {
    public:
        CExt173MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt174MetricSet final : public CMetricSet
    {
    public:
        CExt174MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt175MetricSet final : public CMetricSet
    {
    public:
        CExt175MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt176MetricSet final : public CMetricSet
    {
    public:
        CExt176MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt177MetricSet final : public CMetricSet
    {
    public:
        CExt177MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt181MetricSet final : public CMetricSet
    {
    public:
        CExt181MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt182MetricSet final : public CMetricSet
    {
    public:
        CExt182MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt184MetricSet final : public CMetricSet
    {
    public:
        CExt184MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt188MetricSet final : public CMetricSet
    {
    public:
        CExt188MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt190MetricSet final : public CMetricSet
    {
    public:
        CExt190MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt192MetricSet final : public CMetricSet
    {
    public:
        CExt192MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt195MetricSet final : public CMetricSet
    {
    public:
        CExt195MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt200MetricSet final : public CMetricSet
    {
    public:
        CExt200MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt201MetricSet final : public CMetricSet
    {
    public:
        CExt201MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt202MetricSet final : public CMetricSet
    {
    public:
        CExt202MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt203MetricSet final : public CMetricSet
    {
    public:
        CExt203MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt204MetricSet final : public CMetricSet
    {
    public:
        CExt204MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt205MetricSet final : public CMetricSet
    {
    public:
        CExt205MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt212MetricSet final : public CMetricSet
    {
    public:
        CExt212MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt214MetricSet final : public CMetricSet
    {
    public:
        CExt214MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt220MetricSet final : public CMetricSet
    {
    public:
        CExt220MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt223MetricSet final : public CMetricSet
    {
    public:
        CExt223MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt225MetricSet final : public CMetricSet
    {
    public:
        CExt225MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt227MetricSet final : public CMetricSet
    {
    public:
        CExt227MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt229MetricSet final : public CMetricSet
    {
    public:
        CExt229MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt231MetricSet final : public CMetricSet
    {
    public:
        CExt231MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt237MetricSet final : public CMetricSet
    {
    public:
        CExt237MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt238MetricSet final : public CMetricSet
    {
    public:
        CExt238MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt239MetricSet final : public CMetricSet
    {
    public:
        CExt239MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt240MetricSet final : public CMetricSet
    {
    public:
        CExt240MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt300MetricSet final : public CMetricSet
    {
    public:
        CExt300MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt301MetricSet final : public CMetricSet
    {
    public:
        CExt301MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt500MetricSet final : public CMetricSet
    {
    public:
        CExt500MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt501MetricSet final : public CMetricSet
    {
    public:
        CExt501MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt502MetricSet final : public CMetricSet
    {
    public:
        CExt502MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt503MetricSet final : public CMetricSet
    {
    public:
        CExt503MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt508MetricSet final : public CMetricSet
    {
    public:
        CExt508MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt509MetricSet final : public CMetricSet
    {
    public:
        CExt509MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt510MetricSet final : public CMetricSet
    {
    public:
        CExt510MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt511MetricSet final : public CMetricSet
    {
    public:
        CExt511MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt516MetricSet final : public CMetricSet
    {
    public:
        CExt516MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt517MetricSet final : public CMetricSet
    {
    public:
        CExt517MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt518MetricSet final : public CMetricSet
    {
    public:
        CExt518MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt519MetricSet final : public CMetricSet
    {
    public:
        CExt519MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt520MetricSet final : public CMetricSet
    {
    public:
        CExt520MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt521MetricSet final : public CMetricSet
    {
    public:
        CExt521MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt522MetricSet final : public CMetricSet
    {
    public:
        CExt522MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt523MetricSet final : public CMetricSet
    {
    public:
        CExt523MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt540MetricSet final : public CMetricSet
    {
    public:
        CExt540MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt541MetricSet final : public CMetricSet
    {
    public:
        CExt541MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt542MetricSet final : public CMetricSet
    {
    public:
        CExt542MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt543MetricSet final : public CMetricSet
    {
    public:
        CExt543MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt580MetricSet final : public CMetricSet
    {
    public:
        CExt580MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt581MetricSet final : public CMetricSet
    {
    public:
        CExt581MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt604MetricSet final : public CMetricSet
    {
    public:
        CExt604MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt1000MetricSet final : public CMetricSet
    {
    public:
        CExt1000MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt1001MetricSet final : public CMetricSet
    {
    public:
        CExt1001MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt1002MetricSet final : public CMetricSet
    {
    public:
        CExt1002MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt1003MetricSet final : public CMetricSet
    {
    public:
        CExt1003MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt1004MetricSet final : public CMetricSet
    {
    public:
        CExt1004MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt1005MetricSet final : public CMetricSet
    {
    public:
        CExt1005MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt1006MetricSet final : public CMetricSet
    {
    public:
        CExt1006MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt1007MetricSet final : public CMetricSet
    {
    public:
        CExt1007MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt1010MetricSet final : public CMetricSet
    {
    public:
        CExt1010MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

} // namespace MetricsDiscoveryInternal::MetricSets_ARL_GT1_OA

namespace MetricsDiscoveryInternal::MetricSets_ARL_GT1_OAM0
{
    void AddInformationSet( CConcurrentGroup* concurrentGroup );

    class CMediaSet1MetricSet final : public CMetricSet
    {
    public:
        CMediaSet1MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CMediaSet2MetricSet final : public CMetricSet
    {
    public:
        CMediaSet2MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CTestOamMetricSet final : public CMetricSet
    {
    public:
        CTestOamMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

} // namespace MetricsDiscoveryInternal::MetricSets_ARL_GT1_OAM0

#endif
