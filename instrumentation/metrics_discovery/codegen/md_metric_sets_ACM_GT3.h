/*========================== begin_copyright_notice ============================

Copyright (C) 2023 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_metric_sets_ACM_GT3.h
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

#if MD_INCLUDE_ACM_GT3_METRICS

namespace MetricsDiscoveryInternal::MetricSets_ACM_GT3_PipelineStatistics
{
    class CPipelineStatsMetricSet : public CMetricSet
    {
    public:
        CPipelineStatsMetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

} // namespace MetricsDiscoveryInternal::MetricSets_ACM_GT3_PipelineStatistics

namespace MetricsDiscoveryInternal::MetricSets_ACM_GT3_OA
{
    void AddInformationSet( CConcurrentGroup* concurrentGroup );

    class CRenderBasicMetricSet : public CMetricSet
    {
    public:
        CRenderBasicMetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CComputeBasicMetricSet : public CMetricSet
    {
    public:
        CComputeBasicMetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CAsyncComputeMetricSet : public CMetricSet
    {
    public:
        CAsyncComputeMetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CXveActivity1MetricSet : public CMetricSet
    {
    public:
        CXveActivity1MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CGpuBusynessMetricSet : public CMetricSet
    {
    public:
        CGpuBusynessMetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CTestOaMetricSet : public CMetricSet
    {
    public:
        CTestOaMetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CHDCAndSF_Slice01MetricSet : public CMetricSet
    {
    public:
        CHDCAndSF_Slice01MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CHDCAndSF_Slice23MetricSet : public CMetricSet
    {
    public:
        CHDCAndSF_Slice23MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CHDCAndSF_Slice45MetricSet : public CMetricSet
    {
    public:
        CHDCAndSF_Slice45MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CHDCAndSF_Slice67MetricSet : public CMetricSet
    {
    public:
        CHDCAndSF_Slice67MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CHDCAndSF1MetricSet : public CMetricSet
    {
    public:
        CHDCAndSF1MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CL3_Slice01MetricSet : public CMetricSet
    {
    public:
        CL3_Slice01MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CL3_Slice23MetricSet : public CMetricSet
    {
    public:
        CL3_Slice23MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CL3_Slice45MetricSet : public CMetricSet
    {
    public:
        CL3_Slice45MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CL3_Slice67MetricSet : public CMetricSet
    {
    public:
        CL3_Slice67MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CRasterizerAndPixelBackend1MetricSet : public CMetricSet
    {
    public:
        CRasterizerAndPixelBackend1MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CRasterizerAndPixelBackend2MetricSet : public CMetricSet
    {
    public:
        CRasterizerAndPixelBackend2MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CRasterizerAndPixelBackend3MetricSet : public CMetricSet
    {
    public:
        CRasterizerAndPixelBackend3MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CRasterizerAndPixelBackend4MetricSet : public CMetricSet
    {
    public:
        CRasterizerAndPixelBackend4MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CRasterizerAndPixelBackend5MetricSet : public CMetricSet
    {
    public:
        CRasterizerAndPixelBackend5MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CRenderPipeProfile_Slice0MetricSet : public CMetricSet
    {
    public:
        CRenderPipeProfile_Slice0MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CRenderPipeProfile_Slice1MetricSet : public CMetricSet
    {
    public:
        CRenderPipeProfile_Slice1MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CRenderPipeProfile_Slice2MetricSet : public CMetricSet
    {
    public:
        CRenderPipeProfile_Slice2MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CRenderPipeProfile_Slice3MetricSet : public CMetricSet
    {
    public:
        CRenderPipeProfile_Slice3MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CRenderPipeProfile_Slice4MetricSet : public CMetricSet
    {
    public:
        CRenderPipeProfile_Slice4MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CRenderPipeProfile_Slice5MetricSet : public CMetricSet
    {
    public:
        CRenderPipeProfile_Slice5MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CRenderPipeProfile_Slice6MetricSet : public CMetricSet
    {
    public:
        CRenderPipeProfile_Slice6MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CRenderPipeProfile_Slice7MetricSet : public CMetricSet
    {
    public:
        CRenderPipeProfile_Slice7MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CSampler_Slice01MetricSet : public CMetricSet
    {
    public:
        CSampler_Slice01MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CSampler_Slice23MetricSet : public CMetricSet
    {
    public:
        CSampler_Slice23MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CSampler_Slice45MetricSet : public CMetricSet
    {
    public:
        CSampler_Slice45MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CSampler_Slice67MetricSet : public CMetricSet
    {
    public:
        CSampler_Slice67MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CTDL_Slice01_1MetricSet : public CMetricSet
    {
    public:
        CTDL_Slice01_1MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CTDL_Slice01_2MetricSet : public CMetricSet
    {
    public:
        CTDL_Slice01_2MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CTDL_Slice01_3MetricSet : public CMetricSet
    {
    public:
        CTDL_Slice01_3MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CTDL_Slice01_4MetricSet : public CMetricSet
    {
    public:
        CTDL_Slice01_4MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CTDL_Slice23_1MetricSet : public CMetricSet
    {
    public:
        CTDL_Slice23_1MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CTDL_Slice23_2MetricSet : public CMetricSet
    {
    public:
        CTDL_Slice23_2MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CTDL_Slice23_3MetricSet : public CMetricSet
    {
    public:
        CTDL_Slice23_3MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CTDL_Slice23_4MetricSet : public CMetricSet
    {
    public:
        CTDL_Slice23_4MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CTDL_Slice45_1MetricSet : public CMetricSet
    {
    public:
        CTDL_Slice45_1MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CTDL_Slice45_2MetricSet : public CMetricSet
    {
    public:
        CTDL_Slice45_2MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CTDL_Slice45_3MetricSet : public CMetricSet
    {
    public:
        CTDL_Slice45_3MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CTDL_Slice45_4MetricSet : public CMetricSet
    {
    public:
        CTDL_Slice45_4MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CTDL_Slice67_1MetricSet : public CMetricSet
    {
    public:
        CTDL_Slice67_1MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CTDL_Slice67_2MetricSet : public CMetricSet
    {
    public:
        CTDL_Slice67_2MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CTDL_Slice67_3MetricSet : public CMetricSet
    {
    public:
        CTDL_Slice67_3MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CTDL_Slice67_4MetricSet : public CMetricSet
    {
    public:
        CTDL_Slice67_4MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CComputeOverviewMetricSet : public CMetricSet
    {
    public:
        CComputeOverviewMetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CL1ProfileReadsMetricSet_XeCore0 : public CMetricSet
    {
    public:
        CL1ProfileReadsMetricSet_XeCore0( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CL1ProfileReadsMetricSet_XeCore3 : public CMetricSet
    {
    public:
        CL1ProfileReadsMetricSet_XeCore3( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CL1ProfileSlmBankConflictsMetricSet_XeCore0 : public CMetricSet
    {
    public:
        CL1ProfileSlmBankConflictsMetricSet_XeCore0( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CL1ProfileSlmBankConflictsMetricSet_XeCore3 : public CMetricSet
    {
    public:
        CL1ProfileSlmBankConflictsMetricSet_XeCore3( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CL1ProfileWritesMetricSet_XeCore0 : public CMetricSet
    {
    public:
        CL1ProfileWritesMetricSet_XeCore0( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CL1ProfileWritesMetricSet_XeCore3 : public CMetricSet
    {
    public:
        CL1ProfileWritesMetricSet_XeCore3( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CDataportReadsMetricSet : public CMetricSet
    {
    public:
        CDataportReadsMetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CDataportWritesMetricSet : public CMetricSet
    {
    public:
        CDataportWritesMetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt1MetricSet : public CMetricSet
    {
    public:
        CExt1MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt2MetricSet : public CMetricSet
    {
    public:
        CExt2MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt3MetricSet : public CMetricSet
    {
    public:
        CExt3MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt4MetricSet : public CMetricSet
    {
    public:
        CExt4MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt5MetricSet : public CMetricSet
    {
    public:
        CExt5MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt6MetricSet : public CMetricSet
    {
    public:
        CExt6MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt7MetricSet : public CMetricSet
    {
    public:
        CExt7MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt8MetricSet : public CMetricSet
    {
    public:
        CExt8MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt9MetricSet : public CMetricSet
    {
    public:
        CExt9MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt10MetricSet : public CMetricSet
    {
    public:
        CExt10MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt11MetricSet : public CMetricSet
    {
    public:
        CExt11MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt12MetricSet : public CMetricSet
    {
    public:
        CExt12MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt13MetricSet : public CMetricSet
    {
    public:
        CExt13MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt14MetricSet : public CMetricSet
    {
    public:
        CExt14MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt15MetricSet : public CMetricSet
    {
    public:
        CExt15MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt16MetricSet : public CMetricSet
    {
    public:
        CExt16MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt17MetricSet : public CMetricSet
    {
    public:
        CExt17MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt18MetricSet : public CMetricSet
    {
    public:
        CExt18MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt19MetricSet : public CMetricSet
    {
    public:
        CExt19MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt20MetricSet : public CMetricSet
    {
    public:
        CExt20MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt21MetricSet : public CMetricSet
    {
    public:
        CExt21MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt22MetricSet : public CMetricSet
    {
    public:
        CExt22MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt23MetricSet : public CMetricSet
    {
    public:
        CExt23MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt24MetricSet : public CMetricSet
    {
    public:
        CExt24MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt27MetricSet : public CMetricSet
    {
    public:
        CExt27MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt28MetricSet : public CMetricSet
    {
    public:
        CExt28MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt29MetricSet : public CMetricSet
    {
    public:
        CExt29MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt30MetricSet : public CMetricSet
    {
    public:
        CExt30MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt31MetricSet : public CMetricSet
    {
    public:
        CExt31MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt32MetricSet : public CMetricSet
    {
    public:
        CExt32MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt33MetricSet : public CMetricSet
    {
    public:
        CExt33MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt34MetricSet : public CMetricSet
    {
    public:
        CExt34MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt35MetricSet : public CMetricSet
    {
    public:
        CExt35MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt36MetricSet : public CMetricSet
    {
    public:
        CExt36MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt37MetricSet : public CMetricSet
    {
    public:
        CExt37MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt38MetricSet : public CMetricSet
    {
    public:
        CExt38MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt39MetricSet : public CMetricSet
    {
    public:
        CExt39MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt40MetricSet : public CMetricSet
    {
    public:
        CExt40MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt41MetricSet : public CMetricSet
    {
    public:
        CExt41MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt42MetricSet : public CMetricSet
    {
    public:
        CExt42MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt43MetricSet : public CMetricSet
    {
    public:
        CExt43MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt44MetricSet : public CMetricSet
    {
    public:
        CExt44MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt45MetricSet : public CMetricSet
    {
    public:
        CExt45MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt46MetricSet : public CMetricSet
    {
    public:
        CExt46MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt47MetricSet : public CMetricSet
    {
    public:
        CExt47MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt48MetricSet : public CMetricSet
    {
    public:
        CExt48MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt49MetricSet : public CMetricSet
    {
    public:
        CExt49MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt50MetricSet : public CMetricSet
    {
    public:
        CExt50MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt51MetricSet : public CMetricSet
    {
    public:
        CExt51MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt52MetricSet : public CMetricSet
    {
    public:
        CExt52MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt53MetricSet : public CMetricSet
    {
    public:
        CExt53MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt54MetricSet : public CMetricSet
    {
    public:
        CExt54MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt55MetricSet : public CMetricSet
    {
    public:
        CExt55MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt56MetricSet : public CMetricSet
    {
    public:
        CExt56MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt57MetricSet : public CMetricSet
    {
    public:
        CExt57MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt58MetricSet : public CMetricSet
    {
    public:
        CExt58MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt59MetricSet : public CMetricSet
    {
    public:
        CExt59MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt60MetricSet : public CMetricSet
    {
    public:
        CExt60MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt61MetricSet : public CMetricSet
    {
    public:
        CExt61MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt62MetricSet : public CMetricSet
    {
    public:
        CExt62MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt63MetricSet : public CMetricSet
    {
    public:
        CExt63MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt64MetricSet : public CMetricSet
    {
    public:
        CExt64MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt65MetricSet : public CMetricSet
    {
    public:
        CExt65MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt66MetricSet : public CMetricSet
    {
    public:
        CExt66MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt67MetricSet : public CMetricSet
    {
    public:
        CExt67MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt68MetricSet : public CMetricSet
    {
    public:
        CExt68MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt69MetricSet : public CMetricSet
    {
    public:
        CExt69MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt70MetricSet : public CMetricSet
    {
    public:
        CExt70MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt71MetricSet : public CMetricSet
    {
    public:
        CExt71MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt72MetricSet : public CMetricSet
    {
    public:
        CExt72MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt73MetricSet : public CMetricSet
    {
    public:
        CExt73MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt74MetricSet : public CMetricSet
    {
    public:
        CExt74MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt75MetricSet : public CMetricSet
    {
    public:
        CExt75MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt76MetricSet : public CMetricSet
    {
    public:
        CExt76MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt77MetricSet : public CMetricSet
    {
    public:
        CExt77MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt78MetricSet : public CMetricSet
    {
    public:
        CExt78MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt79MetricSet : public CMetricSet
    {
    public:
        CExt79MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt80MetricSet : public CMetricSet
    {
    public:
        CExt80MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt81MetricSet : public CMetricSet
    {
    public:
        CExt81MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt82MetricSet : public CMetricSet
    {
    public:
        CExt82MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt83MetricSet : public CMetricSet
    {
    public:
        CExt83MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt84MetricSet : public CMetricSet
    {
    public:
        CExt84MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt85MetricSet : public CMetricSet
    {
    public:
        CExt85MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt86MetricSet : public CMetricSet
    {
    public:
        CExt86MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt87MetricSet : public CMetricSet
    {
    public:
        CExt87MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt88MetricSet : public CMetricSet
    {
    public:
        CExt88MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt89MetricSet : public CMetricSet
    {
    public:
        CExt89MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt90MetricSet : public CMetricSet
    {
    public:
        CExt90MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt91MetricSet : public CMetricSet
    {
    public:
        CExt91MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt92MetricSet : public CMetricSet
    {
    public:
        CExt92MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt93MetricSet : public CMetricSet
    {
    public:
        CExt93MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt94MetricSet : public CMetricSet
    {
    public:
        CExt94MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt95MetricSet : public CMetricSet
    {
    public:
        CExt95MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt96MetricSet : public CMetricSet
    {
    public:
        CExt96MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt97MetricSet : public CMetricSet
    {
    public:
        CExt97MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt98MetricSet : public CMetricSet
    {
    public:
        CExt98MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt99MetricSet : public CMetricSet
    {
    public:
        CExt99MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt100MetricSet : public CMetricSet
    {
    public:
        CExt100MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt101MetricSet : public CMetricSet
    {
    public:
        CExt101MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt102MetricSet : public CMetricSet
    {
    public:
        CExt102MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt103MetricSet : public CMetricSet
    {
    public:
        CExt103MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt104MetricSet : public CMetricSet
    {
    public:
        CExt104MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt105MetricSet : public CMetricSet
    {
    public:
        CExt105MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt106MetricSet : public CMetricSet
    {
    public:
        CExt106MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt107MetricSet : public CMetricSet
    {
    public:
        CExt107MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt108MetricSet : public CMetricSet
    {
    public:
        CExt108MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt109MetricSet : public CMetricSet
    {
    public:
        CExt109MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt110MetricSet : public CMetricSet
    {
    public:
        CExt110MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt111MetricSet : public CMetricSet
    {
    public:
        CExt111MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt112MetricSet : public CMetricSet
    {
    public:
        CExt112MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt113MetricSet : public CMetricSet
    {
    public:
        CExt113MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt114MetricSet : public CMetricSet
    {
    public:
        CExt114MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt115MetricSet : public CMetricSet
    {
    public:
        CExt115MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt116MetricSet : public CMetricSet
    {
    public:
        CExt116MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt117MetricSet : public CMetricSet
    {
    public:
        CExt117MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt118MetricSet : public CMetricSet
    {
    public:
        CExt118MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt119MetricSet : public CMetricSet
    {
    public:
        CExt119MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt120MetricSet : public CMetricSet
    {
    public:
        CExt120MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt121MetricSet : public CMetricSet
    {
    public:
        CExt121MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt122MetricSet : public CMetricSet
    {
    public:
        CExt122MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt123MetricSet : public CMetricSet
    {
    public:
        CExt123MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt124MetricSet : public CMetricSet
    {
    public:
        CExt124MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt125MetricSet : public CMetricSet
    {
    public:
        CExt125MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt126MetricSet : public CMetricSet
    {
    public:
        CExt126MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt127MetricSet : public CMetricSet
    {
    public:
        CExt127MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt128MetricSet : public CMetricSet
    {
    public:
        CExt128MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt129MetricSet : public CMetricSet
    {
    public:
        CExt129MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt130MetricSet : public CMetricSet
    {
    public:
        CExt130MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt131MetricSet : public CMetricSet
    {
    public:
        CExt131MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt132MetricSet : public CMetricSet
    {
    public:
        CExt132MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt133MetricSet : public CMetricSet
    {
    public:
        CExt133MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt134MetricSet : public CMetricSet
    {
    public:
        CExt134MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt135MetricSet : public CMetricSet
    {
    public:
        CExt135MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt136MetricSet : public CMetricSet
    {
    public:
        CExt136MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt137MetricSet : public CMetricSet
    {
    public:
        CExt137MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt138MetricSet : public CMetricSet
    {
    public:
        CExt138MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt139MetricSet : public CMetricSet
    {
    public:
        CExt139MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt140MetricSet : public CMetricSet
    {
    public:
        CExt140MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt141MetricSet : public CMetricSet
    {
    public:
        CExt141MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt142MetricSet : public CMetricSet
    {
    public:
        CExt142MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt143MetricSet : public CMetricSet
    {
    public:
        CExt143MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt144MetricSet : public CMetricSet
    {
    public:
        CExt144MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt145MetricSet : public CMetricSet
    {
    public:
        CExt145MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt146MetricSet : public CMetricSet
    {
    public:
        CExt146MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt147MetricSet : public CMetricSet
    {
    public:
        CExt147MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt148MetricSet : public CMetricSet
    {
    public:
        CExt148MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt149MetricSet : public CMetricSet
    {
    public:
        CExt149MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt150MetricSet : public CMetricSet
    {
    public:
        CExt150MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt151MetricSet : public CMetricSet
    {
    public:
        CExt151MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt152MetricSet : public CMetricSet
    {
    public:
        CExt152MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt153MetricSet : public CMetricSet
    {
    public:
        CExt153MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt154MetricSet : public CMetricSet
    {
    public:
        CExt154MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt155MetricSet : public CMetricSet
    {
    public:
        CExt155MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt156MetricSet : public CMetricSet
    {
    public:
        CExt156MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt157MetricSet : public CMetricSet
    {
    public:
        CExt157MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt158MetricSet : public CMetricSet
    {
    public:
        CExt158MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt159MetricSet : public CMetricSet
    {
    public:
        CExt159MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt160MetricSet : public CMetricSet
    {
    public:
        CExt160MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt161MetricSet : public CMetricSet
    {
    public:
        CExt161MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt162MetricSet : public CMetricSet
    {
    public:
        CExt162MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt163MetricSet : public CMetricSet
    {
    public:
        CExt163MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt164MetricSet : public CMetricSet
    {
    public:
        CExt164MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt165MetricSet : public CMetricSet
    {
    public:
        CExt165MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt166MetricSet : public CMetricSet
    {
    public:
        CExt166MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt167MetricSet : public CMetricSet
    {
    public:
        CExt167MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt168MetricSet : public CMetricSet
    {
    public:
        CExt168MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt169MetricSet : public CMetricSet
    {
    public:
        CExt169MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt170MetricSet : public CMetricSet
    {
    public:
        CExt170MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt171MetricSet : public CMetricSet
    {
    public:
        CExt171MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt172MetricSet : public CMetricSet
    {
    public:
        CExt172MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt173MetricSet : public CMetricSet
    {
    public:
        CExt173MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt174MetricSet : public CMetricSet
    {
    public:
        CExt174MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt175MetricSet : public CMetricSet
    {
    public:
        CExt175MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt176MetricSet : public CMetricSet
    {
    public:
        CExt176MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt177MetricSet : public CMetricSet
    {
    public:
        CExt177MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt178MetricSet : public CMetricSet
    {
    public:
        CExt178MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt179MetricSet : public CMetricSet
    {
    public:
        CExt179MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt180MetricSet : public CMetricSet
    {
    public:
        CExt180MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt181MetricSet : public CMetricSet
    {
    public:
        CExt181MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt182MetricSet : public CMetricSet
    {
    public:
        CExt182MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt183MetricSet : public CMetricSet
    {
    public:
        CExt183MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt184MetricSet : public CMetricSet
    {
    public:
        CExt184MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt185MetricSet : public CMetricSet
    {
    public:
        CExt185MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt186MetricSet : public CMetricSet
    {
    public:
        CExt186MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt187MetricSet : public CMetricSet
    {
    public:
        CExt187MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt188MetricSet : public CMetricSet
    {
    public:
        CExt188MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt189MetricSet : public CMetricSet
    {
    public:
        CExt189MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt190MetricSet : public CMetricSet
    {
    public:
        CExt190MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt191MetricSet : public CMetricSet
    {
    public:
        CExt191MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt192MetricSet : public CMetricSet
    {
    public:
        CExt192MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt193MetricSet : public CMetricSet
    {
    public:
        CExt193MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt194MetricSet : public CMetricSet
    {
    public:
        CExt194MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt195MetricSet : public CMetricSet
    {
    public:
        CExt195MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt196MetricSet : public CMetricSet
    {
    public:
        CExt196MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt197MetricSet : public CMetricSet
    {
    public:
        CExt197MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt198MetricSet : public CMetricSet
    {
    public:
        CExt198MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt199MetricSet : public CMetricSet
    {
    public:
        CExt199MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt200MetricSet : public CMetricSet
    {
    public:
        CExt200MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt201MetricSet : public CMetricSet
    {
    public:
        CExt201MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt202MetricSet : public CMetricSet
    {
    public:
        CExt202MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt203MetricSet : public CMetricSet
    {
    public:
        CExt203MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt204MetricSet : public CMetricSet
    {
    public:
        CExt204MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt205MetricSet : public CMetricSet
    {
    public:
        CExt205MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt206MetricSet : public CMetricSet
    {
    public:
        CExt206MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt207MetricSet : public CMetricSet
    {
    public:
        CExt207MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt208MetricSet : public CMetricSet
    {
    public:
        CExt208MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt209MetricSet : public CMetricSet
    {
    public:
        CExt209MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt210MetricSet : public CMetricSet
    {
    public:
        CExt210MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt211MetricSet : public CMetricSet
    {
    public:
        CExt211MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt212MetricSet : public CMetricSet
    {
    public:
        CExt212MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt213MetricSet : public CMetricSet
    {
    public:
        CExt213MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt214MetricSet : public CMetricSet
    {
    public:
        CExt214MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt215MetricSet : public CMetricSet
    {
    public:
        CExt215MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt216MetricSet : public CMetricSet
    {
    public:
        CExt216MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt217MetricSet : public CMetricSet
    {
    public:
        CExt217MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt218MetricSet : public CMetricSet
    {
    public:
        CExt218MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt219MetricSet : public CMetricSet
    {
    public:
        CExt219MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt220MetricSet : public CMetricSet
    {
    public:
        CExt220MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt221MetricSet : public CMetricSet
    {
    public:
        CExt221MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt222MetricSet : public CMetricSet
    {
    public:
        CExt222MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt223MetricSet : public CMetricSet
    {
    public:
        CExt223MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt224MetricSet : public CMetricSet
    {
    public:
        CExt224MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt225MetricSet : public CMetricSet
    {
    public:
        CExt225MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt226MetricSet : public CMetricSet
    {
    public:
        CExt226MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt227MetricSet : public CMetricSet
    {
    public:
        CExt227MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt228MetricSet : public CMetricSet
    {
    public:
        CExt228MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt229MetricSet : public CMetricSet
    {
    public:
        CExt229MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt230MetricSet : public CMetricSet
    {
    public:
        CExt230MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt231MetricSet : public CMetricSet
    {
    public:
        CExt231MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt232MetricSet : public CMetricSet
    {
    public:
        CExt232MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt233MetricSet : public CMetricSet
    {
    public:
        CExt233MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt234MetricSet : public CMetricSet
    {
    public:
        CExt234MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt235MetricSet : public CMetricSet
    {
    public:
        CExt235MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt236MetricSet : public CMetricSet
    {
    public:
        CExt236MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt237MetricSet : public CMetricSet
    {
    public:
        CExt237MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt238MetricSet : public CMetricSet
    {
    public:
        CExt238MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt239MetricSet : public CMetricSet
    {
    public:
        CExt239MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt240MetricSet : public CMetricSet
    {
    public:
        CExt240MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt241MetricSet : public CMetricSet
    {
    public:
        CExt241MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt242MetricSet : public CMetricSet
    {
    public:
        CExt242MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt243MetricSet : public CMetricSet
    {
    public:
        CExt243MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt244MetricSet : public CMetricSet
    {
    public:
        CExt244MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt245MetricSet : public CMetricSet
    {
    public:
        CExt245MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt246MetricSet : public CMetricSet
    {
    public:
        CExt246MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt247MetricSet : public CMetricSet
    {
    public:
        CExt247MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt248MetricSet : public CMetricSet
    {
    public:
        CExt248MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt249MetricSet : public CMetricSet
    {
    public:
        CExt249MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt250MetricSet : public CMetricSet
    {
    public:
        CExt250MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt251MetricSet : public CMetricSet
    {
    public:
        CExt251MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt252MetricSet : public CMetricSet
    {
    public:
        CExt252MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt253MetricSet : public CMetricSet
    {
    public:
        CExt253MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt254MetricSet : public CMetricSet
    {
    public:
        CExt254MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt255MetricSet : public CMetricSet
    {
    public:
        CExt255MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt256MetricSet : public CMetricSet
    {
    public:
        CExt256MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt257MetricSet : public CMetricSet
    {
    public:
        CExt257MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt258MetricSet : public CMetricSet
    {
    public:
        CExt258MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt259MetricSet : public CMetricSet
    {
    public:
        CExt259MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt260MetricSet : public CMetricSet
    {
    public:
        CExt260MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt261MetricSet : public CMetricSet
    {
    public:
        CExt261MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt262MetricSet : public CMetricSet
    {
    public:
        CExt262MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt263MetricSet : public CMetricSet
    {
    public:
        CExt263MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt264MetricSet : public CMetricSet
    {
    public:
        CExt264MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt265MetricSet : public CMetricSet
    {
    public:
        CExt265MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt266MetricSet : public CMetricSet
    {
    public:
        CExt266MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt267MetricSet : public CMetricSet
    {
    public:
        CExt267MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt268MetricSet : public CMetricSet
    {
    public:
        CExt268MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt269MetricSet : public CMetricSet
    {
    public:
        CExt269MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt270MetricSet : public CMetricSet
    {
    public:
        CExt270MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt271MetricSet : public CMetricSet
    {
    public:
        CExt271MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt272MetricSet : public CMetricSet
    {
    public:
        CExt272MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt273MetricSet : public CMetricSet
    {
    public:
        CExt273MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt274MetricSet : public CMetricSet
    {
    public:
        CExt274MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt275MetricSet : public CMetricSet
    {
    public:
        CExt275MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt276MetricSet : public CMetricSet
    {
    public:
        CExt276MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt277MetricSet : public CMetricSet
    {
    public:
        CExt277MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt278MetricSet : public CMetricSet
    {
    public:
        CExt278MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt279MetricSet : public CMetricSet
    {
    public:
        CExt279MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt280MetricSet : public CMetricSet
    {
    public:
        CExt280MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt281MetricSet : public CMetricSet
    {
    public:
        CExt281MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt282MetricSet : public CMetricSet
    {
    public:
        CExt282MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt283MetricSet : public CMetricSet
    {
    public:
        CExt283MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt284MetricSet : public CMetricSet
    {
    public:
        CExt284MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt285MetricSet : public CMetricSet
    {
    public:
        CExt285MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt286MetricSet : public CMetricSet
    {
    public:
        CExt286MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt288MetricSet : public CMetricSet
    {
    public:
        CExt288MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt289MetricSet : public CMetricSet
    {
    public:
        CExt289MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt290MetricSet : public CMetricSet
    {
    public:
        CExt290MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt291MetricSet : public CMetricSet
    {
    public:
        CExt291MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt292MetricSet : public CMetricSet
    {
    public:
        CExt292MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt293MetricSet : public CMetricSet
    {
    public:
        CExt293MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt294MetricSet : public CMetricSet
    {
    public:
        CExt294MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt295MetricSet : public CMetricSet
    {
    public:
        CExt295MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt296MetricSet : public CMetricSet
    {
    public:
        CExt296MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt297MetricSet : public CMetricSet
    {
    public:
        CExt297MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt298MetricSet : public CMetricSet
    {
    public:
        CExt298MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt299MetricSet : public CMetricSet
    {
    public:
        CExt299MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt300MetricSet : public CMetricSet
    {
    public:
        CExt300MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt301MetricSet : public CMetricSet
    {
    public:
        CExt301MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt302MetricSet : public CMetricSet
    {
    public:
        CExt302MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt303MetricSet : public CMetricSet
    {
    public:
        CExt303MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt304MetricSet : public CMetricSet
    {
    public:
        CExt304MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt305MetricSet : public CMetricSet
    {
    public:
        CExt305MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt306MetricSet : public CMetricSet
    {
    public:
        CExt306MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt307MetricSet : public CMetricSet
    {
    public:
        CExt307MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt308MetricSet : public CMetricSet
    {
    public:
        CExt308MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt309MetricSet : public CMetricSet
    {
    public:
        CExt309MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt310MetricSet : public CMetricSet
    {
    public:
        CExt310MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt311MetricSet : public CMetricSet
    {
    public:
        CExt311MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt312MetricSet : public CMetricSet
    {
    public:
        CExt312MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt313MetricSet : public CMetricSet
    {
    public:
        CExt313MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt314MetricSet : public CMetricSet
    {
    public:
        CExt314MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt315MetricSet : public CMetricSet
    {
    public:
        CExt315MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt316MetricSet : public CMetricSet
    {
    public:
        CExt316MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt317MetricSet : public CMetricSet
    {
    public:
        CExt317MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt318MetricSet : public CMetricSet
    {
    public:
        CExt318MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt319MetricSet : public CMetricSet
    {
    public:
        CExt319MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt320MetricSet : public CMetricSet
    {
    public:
        CExt320MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt321MetricSet : public CMetricSet
    {
    public:
        CExt321MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt322MetricSet : public CMetricSet
    {
    public:
        CExt322MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt323MetricSet : public CMetricSet
    {
    public:
        CExt323MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt324MetricSet : public CMetricSet
    {
    public:
        CExt324MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt325MetricSet : public CMetricSet
    {
    public:
        CExt325MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt326MetricSet : public CMetricSet
    {
    public:
        CExt326MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt327MetricSet : public CMetricSet
    {
    public:
        CExt327MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt328MetricSet : public CMetricSet
    {
    public:
        CExt328MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt329MetricSet : public CMetricSet
    {
    public:
        CExt329MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt330MetricSet : public CMetricSet
    {
    public:
        CExt330MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt331MetricSet : public CMetricSet
    {
    public:
        CExt331MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt332MetricSet : public CMetricSet
    {
    public:
        CExt332MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt333MetricSet : public CMetricSet
    {
    public:
        CExt333MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt334MetricSet : public CMetricSet
    {
    public:
        CExt334MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt335MetricSet : public CMetricSet
    {
    public:
        CExt335MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt342MetricSet : public CMetricSet
    {
    public:
        CExt342MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt343MetricSet : public CMetricSet
    {
    public:
        CExt343MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt344MetricSet : public CMetricSet
    {
    public:
        CExt344MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt345MetricSet : public CMetricSet
    {
    public:
        CExt345MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt346MetricSet : public CMetricSet
    {
    public:
        CExt346MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt347MetricSet : public CMetricSet
    {
    public:
        CExt347MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt348MetricSet : public CMetricSet
    {
    public:
        CExt348MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt349MetricSet : public CMetricSet
    {
    public:
        CExt349MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt350MetricSet : public CMetricSet
    {
    public:
        CExt350MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt351MetricSet : public CMetricSet
    {
    public:
        CExt351MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt352MetricSet : public CMetricSet
    {
    public:
        CExt352MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt353MetricSet : public CMetricSet
    {
    public:
        CExt353MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt354MetricSet : public CMetricSet
    {
    public:
        CExt354MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt355MetricSet : public CMetricSet
    {
    public:
        CExt355MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt356MetricSet : public CMetricSet
    {
    public:
        CExt356MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt357MetricSet : public CMetricSet
    {
    public:
        CExt357MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt358MetricSet : public CMetricSet
    {
    public:
        CExt358MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt359MetricSet : public CMetricSet
    {
    public:
        CExt359MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt360MetricSet : public CMetricSet
    {
    public:
        CExt360MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt361MetricSet : public CMetricSet
    {
    public:
        CExt361MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt362MetricSet : public CMetricSet
    {
    public:
        CExt362MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt363MetricSet : public CMetricSet
    {
    public:
        CExt363MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt364MetricSet : public CMetricSet
    {
    public:
        CExt364MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt365MetricSet : public CMetricSet
    {
    public:
        CExt365MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt366MetricSet : public CMetricSet
    {
    public:
        CExt366MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt367MetricSet : public CMetricSet
    {
    public:
        CExt367MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt368MetricSet : public CMetricSet
    {
    public:
        CExt368MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt369MetricSet : public CMetricSet
    {
    public:
        CExt369MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt370MetricSet : public CMetricSet
    {
    public:
        CExt370MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt371MetricSet : public CMetricSet
    {
    public:
        CExt371MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt372MetricSet : public CMetricSet
    {
    public:
        CExt372MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt373MetricSet : public CMetricSet
    {
    public:
        CExt373MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt374MetricSet : public CMetricSet
    {
    public:
        CExt374MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt375MetricSet : public CMetricSet
    {
    public:
        CExt375MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt376MetricSet : public CMetricSet
    {
    public:
        CExt376MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt377MetricSet : public CMetricSet
    {
    public:
        CExt377MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt378MetricSet : public CMetricSet
    {
    public:
        CExt378MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt379MetricSet : public CMetricSet
    {
    public:
        CExt379MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt380MetricSet : public CMetricSet
    {
    public:
        CExt380MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt381MetricSet : public CMetricSet
    {
    public:
        CExt381MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt382MetricSet : public CMetricSet
    {
    public:
        CExt382MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt383MetricSet : public CMetricSet
    {
    public:
        CExt383MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt384MetricSet : public CMetricSet
    {
    public:
        CExt384MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt385MetricSet : public CMetricSet
    {
    public:
        CExt385MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt386MetricSet : public CMetricSet
    {
    public:
        CExt386MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt387MetricSet : public CMetricSet
    {
    public:
        CExt387MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt388MetricSet : public CMetricSet
    {
    public:
        CExt388MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt389MetricSet : public CMetricSet
    {
    public:
        CExt389MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt390MetricSet : public CMetricSet
    {
    public:
        CExt390MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt391MetricSet : public CMetricSet
    {
    public:
        CExt391MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt392MetricSet : public CMetricSet
    {
    public:
        CExt392MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt393MetricSet : public CMetricSet
    {
    public:
        CExt393MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt394MetricSet : public CMetricSet
    {
    public:
        CExt394MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt395MetricSet : public CMetricSet
    {
    public:
        CExt395MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt396MetricSet : public CMetricSet
    {
    public:
        CExt396MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt397MetricSet : public CMetricSet
    {
    public:
        CExt397MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt398MetricSet : public CMetricSet
    {
    public:
        CExt398MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt399MetricSet : public CMetricSet
    {
    public:
        CExt399MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt400MetricSet : public CMetricSet
    {
    public:
        CExt400MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt401MetricSet : public CMetricSet
    {
    public:
        CExt401MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt402MetricSet : public CMetricSet
    {
    public:
        CExt402MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt403MetricSet : public CMetricSet
    {
    public:
        CExt403MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt404MetricSet : public CMetricSet
    {
    public:
        CExt404MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt405MetricSet : public CMetricSet
    {
    public:
        CExt405MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt406MetricSet : public CMetricSet
    {
    public:
        CExt406MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt407MetricSet : public CMetricSet
    {
    public:
        CExt407MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt408MetricSet : public CMetricSet
    {
    public:
        CExt408MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt409MetricSet : public CMetricSet
    {
    public:
        CExt409MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt410MetricSet : public CMetricSet
    {
    public:
        CExt410MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt411MetricSet : public CMetricSet
    {
    public:
        CExt411MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt412MetricSet : public CMetricSet
    {
    public:
        CExt412MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt413MetricSet : public CMetricSet
    {
    public:
        CExt413MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt414MetricSet : public CMetricSet
    {
    public:
        CExt414MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt415MetricSet : public CMetricSet
    {
    public:
        CExt415MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt416MetricSet : public CMetricSet
    {
    public:
        CExt416MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt417MetricSet : public CMetricSet
    {
    public:
        CExt417MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt418MetricSet : public CMetricSet
    {
    public:
        CExt418MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt419MetricSet : public CMetricSet
    {
    public:
        CExt419MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt420MetricSet : public CMetricSet
    {
    public:
        CExt420MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt421MetricSet : public CMetricSet
    {
    public:
        CExt421MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt422MetricSet : public CMetricSet
    {
    public:
        CExt422MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt423MetricSet : public CMetricSet
    {
    public:
        CExt423MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt424MetricSet : public CMetricSet
    {
    public:
        CExt424MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt425MetricSet : public CMetricSet
    {
    public:
        CExt425MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt426MetricSet : public CMetricSet
    {
    public:
        CExt426MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt427MetricSet : public CMetricSet
    {
    public:
        CExt427MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt428MetricSet : public CMetricSet
    {
    public:
        CExt428MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt429MetricSet : public CMetricSet
    {
    public:
        CExt429MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt430MetricSet : public CMetricSet
    {
    public:
        CExt430MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt431MetricSet : public CMetricSet
    {
    public:
        CExt431MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt432MetricSet : public CMetricSet
    {
    public:
        CExt432MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt433MetricSet : public CMetricSet
    {
    public:
        CExt433MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt434MetricSet : public CMetricSet
    {
    public:
        CExt434MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt435MetricSet : public CMetricSet
    {
    public:
        CExt435MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt436MetricSet : public CMetricSet
    {
    public:
        CExt436MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt437MetricSet : public CMetricSet
    {
    public:
        CExt437MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt438MetricSet : public CMetricSet
    {
    public:
        CExt438MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt439MetricSet : public CMetricSet
    {
    public:
        CExt439MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt440MetricSet : public CMetricSet
    {
    public:
        CExt440MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt441MetricSet : public CMetricSet
    {
    public:
        CExt441MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt442MetricSet : public CMetricSet
    {
    public:
        CExt442MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt443MetricSet : public CMetricSet
    {
    public:
        CExt443MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt444MetricSet : public CMetricSet
    {
    public:
        CExt444MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt445MetricSet : public CMetricSet
    {
    public:
        CExt445MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt446MetricSet : public CMetricSet
    {
    public:
        CExt446MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt447MetricSet : public CMetricSet
    {
    public:
        CExt447MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt448MetricSet : public CMetricSet
    {
    public:
        CExt448MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt449MetricSet : public CMetricSet
    {
    public:
        CExt449MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt450MetricSet : public CMetricSet
    {
    public:
        CExt450MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt451MetricSet : public CMetricSet
    {
    public:
        CExt451MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt452MetricSet : public CMetricSet
    {
    public:
        CExt452MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt453MetricSet : public CMetricSet
    {
    public:
        CExt453MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt454MetricSet : public CMetricSet
    {
    public:
        CExt454MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt455MetricSet : public CMetricSet
    {
    public:
        CExt455MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt456MetricSet : public CMetricSet
    {
    public:
        CExt456MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt457MetricSet : public CMetricSet
    {
    public:
        CExt457MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt458MetricSet : public CMetricSet
    {
    public:
        CExt458MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt459MetricSet : public CMetricSet
    {
    public:
        CExt459MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt460MetricSet : public CMetricSet
    {
    public:
        CExt460MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt461MetricSet : public CMetricSet
    {
    public:
        CExt461MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt462MetricSet : public CMetricSet
    {
    public:
        CExt462MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt463MetricSet : public CMetricSet
    {
    public:
        CExt463MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt464MetricSet : public CMetricSet
    {
    public:
        CExt464MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt465MetricSet : public CMetricSet
    {
    public:
        CExt465MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt466MetricSet : public CMetricSet
    {
    public:
        CExt466MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt467MetricSet : public CMetricSet
    {
    public:
        CExt467MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt468MetricSet : public CMetricSet
    {
    public:
        CExt468MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt469MetricSet : public CMetricSet
    {
    public:
        CExt469MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt470MetricSet : public CMetricSet
    {
    public:
        CExt470MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt471MetricSet : public CMetricSet
    {
    public:
        CExt471MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt472MetricSet : public CMetricSet
    {
    public:
        CExt472MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt473MetricSet : public CMetricSet
    {
    public:
        CExt473MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt474MetricSet : public CMetricSet
    {
    public:
        CExt474MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt475MetricSet : public CMetricSet
    {
    public:
        CExt475MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt476MetricSet : public CMetricSet
    {
    public:
        CExt476MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt477MetricSet : public CMetricSet
    {
    public:
        CExt477MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt478MetricSet : public CMetricSet
    {
    public:
        CExt478MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt479MetricSet : public CMetricSet
    {
    public:
        CExt479MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt480MetricSet : public CMetricSet
    {
    public:
        CExt480MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt481MetricSet : public CMetricSet
    {
    public:
        CExt481MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt482MetricSet : public CMetricSet
    {
    public:
        CExt482MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt483MetricSet : public CMetricSet
    {
    public:
        CExt483MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt484MetricSet : public CMetricSet
    {
    public:
        CExt484MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt485MetricSet : public CMetricSet
    {
    public:
        CExt485MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt486MetricSet : public CMetricSet
    {
    public:
        CExt486MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt487MetricSet : public CMetricSet
    {
    public:
        CExt487MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt488MetricSet : public CMetricSet
    {
    public:
        CExt488MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt489MetricSet : public CMetricSet
    {
    public:
        CExt489MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt490MetricSet : public CMetricSet
    {
    public:
        CExt490MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt491MetricSet : public CMetricSet
    {
    public:
        CExt491MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt492MetricSet : public CMetricSet
    {
    public:
        CExt492MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt493MetricSet : public CMetricSet
    {
    public:
        CExt493MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt494MetricSet : public CMetricSet
    {
    public:
        CExt494MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt495MetricSet : public CMetricSet
    {
    public:
        CExt495MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt496MetricSet : public CMetricSet
    {
    public:
        CExt496MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt497MetricSet : public CMetricSet
    {
    public:
        CExt497MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt498MetricSet : public CMetricSet
    {
    public:
        CExt498MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt499MetricSet : public CMetricSet
    {
    public:
        CExt499MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt500MetricSet : public CMetricSet
    {
    public:
        CExt500MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt501MetricSet : public CMetricSet
    {
    public:
        CExt501MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt502MetricSet : public CMetricSet
    {
    public:
        CExt502MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt503MetricSet : public CMetricSet
    {
    public:
        CExt503MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt504MetricSet : public CMetricSet
    {
    public:
        CExt504MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt505MetricSet : public CMetricSet
    {
    public:
        CExt505MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt506MetricSet : public CMetricSet
    {
    public:
        CExt506MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt507MetricSet : public CMetricSet
    {
    public:
        CExt507MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt508MetricSet : public CMetricSet
    {
    public:
        CExt508MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt509MetricSet : public CMetricSet
    {
    public:
        CExt509MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt510MetricSet : public CMetricSet
    {
    public:
        CExt510MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt511MetricSet : public CMetricSet
    {
    public:
        CExt511MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt512MetricSet : public CMetricSet
    {
    public:
        CExt512MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt513MetricSet : public CMetricSet
    {
    public:
        CExt513MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt514MetricSet : public CMetricSet
    {
    public:
        CExt514MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt515MetricSet : public CMetricSet
    {
    public:
        CExt515MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt516MetricSet : public CMetricSet
    {
    public:
        CExt516MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt517MetricSet : public CMetricSet
    {
    public:
        CExt517MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt518MetricSet : public CMetricSet
    {
    public:
        CExt518MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt519MetricSet : public CMetricSet
    {
    public:
        CExt519MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt520MetricSet : public CMetricSet
    {
    public:
        CExt520MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt521MetricSet : public CMetricSet
    {
    public:
        CExt521MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt522MetricSet : public CMetricSet
    {
    public:
        CExt522MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt523MetricSet : public CMetricSet
    {
    public:
        CExt523MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt524MetricSet : public CMetricSet
    {
    public:
        CExt524MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt525MetricSet : public CMetricSet
    {
    public:
        CExt525MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt526MetricSet : public CMetricSet
    {
    public:
        CExt526MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt527MetricSet : public CMetricSet
    {
    public:
        CExt527MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt528MetricSet : public CMetricSet
    {
    public:
        CExt528MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt529MetricSet : public CMetricSet
    {
    public:
        CExt529MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt530MetricSet : public CMetricSet
    {
    public:
        CExt530MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt531MetricSet : public CMetricSet
    {
    public:
        CExt531MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt532MetricSet : public CMetricSet
    {
    public:
        CExt532MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt533MetricSet : public CMetricSet
    {
    public:
        CExt533MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt534MetricSet : public CMetricSet
    {
    public:
        CExt534MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt535MetricSet : public CMetricSet
    {
    public:
        CExt535MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt536MetricSet : public CMetricSet
    {
    public:
        CExt536MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt537MetricSet : public CMetricSet
    {
    public:
        CExt537MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt538MetricSet : public CMetricSet
    {
    public:
        CExt538MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt539MetricSet : public CMetricSet
    {
    public:
        CExt539MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt540MetricSet : public CMetricSet
    {
    public:
        CExt540MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt541MetricSet : public CMetricSet
    {
    public:
        CExt541MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt542MetricSet : public CMetricSet
    {
    public:
        CExt542MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt543MetricSet : public CMetricSet
    {
    public:
        CExt543MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt544MetricSet : public CMetricSet
    {
    public:
        CExt544MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt545MetricSet : public CMetricSet
    {
    public:
        CExt545MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt546MetricSet : public CMetricSet
    {
    public:
        CExt546MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt547MetricSet : public CMetricSet
    {
    public:
        CExt547MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt548MetricSet : public CMetricSet
    {
    public:
        CExt548MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt549MetricSet : public CMetricSet
    {
    public:
        CExt549MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt550MetricSet : public CMetricSet
    {
    public:
        CExt550MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt551MetricSet : public CMetricSet
    {
    public:
        CExt551MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt552MetricSet : public CMetricSet
    {
    public:
        CExt552MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt553MetricSet : public CMetricSet
    {
    public:
        CExt553MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt554MetricSet : public CMetricSet
    {
    public:
        CExt554MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt555MetricSet : public CMetricSet
    {
    public:
        CExt555MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt556MetricSet : public CMetricSet
    {
    public:
        CExt556MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt557MetricSet : public CMetricSet
    {
    public:
        CExt557MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt558MetricSet : public CMetricSet
    {
    public:
        CExt558MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt559MetricSet : public CMetricSet
    {
    public:
        CExt559MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt560MetricSet : public CMetricSet
    {
    public:
        CExt560MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt561MetricSet : public CMetricSet
    {
    public:
        CExt561MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt562MetricSet : public CMetricSet
    {
    public:
        CExt562MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt563MetricSet : public CMetricSet
    {
    public:
        CExt563MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt564MetricSet : public CMetricSet
    {
    public:
        CExt564MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt565MetricSet : public CMetricSet
    {
    public:
        CExt565MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt566MetricSet : public CMetricSet
    {
    public:
        CExt566MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt567MetricSet : public CMetricSet
    {
    public:
        CExt567MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt568MetricSet : public CMetricSet
    {
    public:
        CExt568MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt569MetricSet : public CMetricSet
    {
    public:
        CExt569MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt570MetricSet : public CMetricSet
    {
    public:
        CExt570MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt571MetricSet : public CMetricSet
    {
    public:
        CExt571MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt572MetricSet : public CMetricSet
    {
    public:
        CExt572MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt573MetricSet : public CMetricSet
    {
    public:
        CExt573MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt574MetricSet : public CMetricSet
    {
    public:
        CExt574MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt575MetricSet : public CMetricSet
    {
    public:
        CExt575MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt576MetricSet : public CMetricSet
    {
    public:
        CExt576MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt577MetricSet : public CMetricSet
    {
    public:
        CExt577MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt578MetricSet : public CMetricSet
    {
    public:
        CExt578MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt579MetricSet : public CMetricSet
    {
    public:
        CExt579MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt580MetricSet : public CMetricSet
    {
    public:
        CExt580MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt581MetricSet : public CMetricSet
    {
    public:
        CExt581MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt582MetricSet : public CMetricSet
    {
    public:
        CExt582MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt583MetricSet : public CMetricSet
    {
    public:
        CExt583MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt584MetricSet : public CMetricSet
    {
    public:
        CExt584MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt585MetricSet : public CMetricSet
    {
    public:
        CExt585MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt586MetricSet : public CMetricSet
    {
    public:
        CExt586MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt587MetricSet : public CMetricSet
    {
    public:
        CExt587MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt588MetricSet : public CMetricSet
    {
    public:
        CExt588MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt589MetricSet : public CMetricSet
    {
    public:
        CExt589MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt590MetricSet : public CMetricSet
    {
    public:
        CExt590MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt591MetricSet : public CMetricSet
    {
    public:
        CExt591MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt592MetricSet : public CMetricSet
    {
    public:
        CExt592MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt593MetricSet : public CMetricSet
    {
    public:
        CExt593MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt594MetricSet : public CMetricSet
    {
    public:
        CExt594MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt595MetricSet : public CMetricSet
    {
    public:
        CExt595MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt596MetricSet : public CMetricSet
    {
    public:
        CExt596MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt597MetricSet : public CMetricSet
    {
    public:
        CExt597MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt598MetricSet : public CMetricSet
    {
    public:
        CExt598MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt599MetricSet : public CMetricSet
    {
    public:
        CExt599MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt600MetricSet : public CMetricSet
    {
    public:
        CExt600MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt601MetricSet : public CMetricSet
    {
    public:
        CExt601MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt602MetricSet : public CMetricSet
    {
    public:
        CExt602MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt603MetricSet : public CMetricSet
    {
    public:
        CExt603MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt604MetricSet : public CMetricSet
    {
    public:
        CExt604MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt605MetricSet : public CMetricSet
    {
    public:
        CExt605MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt606MetricSet : public CMetricSet
    {
    public:
        CExt606MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt607MetricSet : public CMetricSet
    {
    public:
        CExt607MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt608MetricSet : public CMetricSet
    {
    public:
        CExt608MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt609MetricSet : public CMetricSet
    {
    public:
        CExt609MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt610MetricSet : public CMetricSet
    {
    public:
        CExt610MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt611MetricSet : public CMetricSet
    {
    public:
        CExt611MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt612MetricSet : public CMetricSet
    {
    public:
        CExt612MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt613MetricSet : public CMetricSet
    {
    public:
        CExt613MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt614MetricSet : public CMetricSet
    {
    public:
        CExt614MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt615MetricSet : public CMetricSet
    {
    public:
        CExt615MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt616MetricSet : public CMetricSet
    {
    public:
        CExt616MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt617MetricSet : public CMetricSet
    {
    public:
        CExt617MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt618MetricSet : public CMetricSet
    {
    public:
        CExt618MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt619MetricSet : public CMetricSet
    {
    public:
        CExt619MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt620MetricSet : public CMetricSet
    {
    public:
        CExt620MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt621MetricSet : public CMetricSet
    {
    public:
        CExt621MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt622MetricSet : public CMetricSet
    {
    public:
        CExt622MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt623MetricSet : public CMetricSet
    {
    public:
        CExt623MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt624MetricSet : public CMetricSet
    {
    public:
        CExt624MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt625MetricSet : public CMetricSet
    {
    public:
        CExt625MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt626MetricSet : public CMetricSet
    {
    public:
        CExt626MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt627MetricSet : public CMetricSet
    {
    public:
        CExt627MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt628MetricSet : public CMetricSet
    {
    public:
        CExt628MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt629MetricSet : public CMetricSet
    {
    public:
        CExt629MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt630MetricSet : public CMetricSet
    {
    public:
        CExt630MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt631MetricSet : public CMetricSet
    {
    public:
        CExt631MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt632MetricSet : public CMetricSet
    {
    public:
        CExt632MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt633MetricSet : public CMetricSet
    {
    public:
        CExt633MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt634MetricSet : public CMetricSet
    {
    public:
        CExt634MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt635MetricSet : public CMetricSet
    {
    public:
        CExt635MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt636MetricSet : public CMetricSet
    {
    public:
        CExt636MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt637MetricSet : public CMetricSet
    {
    public:
        CExt637MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt638MetricSet : public CMetricSet
    {
    public:
        CExt638MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt639MetricSet : public CMetricSet
    {
    public:
        CExt639MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt640MetricSet : public CMetricSet
    {
    public:
        CExt640MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt641MetricSet : public CMetricSet
    {
    public:
        CExt641MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt642MetricSet : public CMetricSet
    {
    public:
        CExt642MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt643MetricSet : public CMetricSet
    {
    public:
        CExt643MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt644MetricSet : public CMetricSet
    {
    public:
        CExt644MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt645MetricSet : public CMetricSet
    {
    public:
        CExt645MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt646MetricSet : public CMetricSet
    {
    public:
        CExt646MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt647MetricSet : public CMetricSet
    {
    public:
        CExt647MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt648MetricSet : public CMetricSet
    {
    public:
        CExt648MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt649MetricSet : public CMetricSet
    {
    public:
        CExt649MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt650MetricSet : public CMetricSet
    {
    public:
        CExt650MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt651MetricSet : public CMetricSet
    {
    public:
        CExt651MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt652MetricSet : public CMetricSet
    {
    public:
        CExt652MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt653MetricSet : public CMetricSet
    {
    public:
        CExt653MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt654MetricSet : public CMetricSet
    {
    public:
        CExt654MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt655MetricSet : public CMetricSet
    {
    public:
        CExt655MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt656MetricSet : public CMetricSet
    {
    public:
        CExt656MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt657MetricSet : public CMetricSet
    {
    public:
        CExt657MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt658MetricSet : public CMetricSet
    {
    public:
        CExt658MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt659MetricSet : public CMetricSet
    {
    public:
        CExt659MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt660MetricSet : public CMetricSet
    {
    public:
        CExt660MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt661MetricSet : public CMetricSet
    {
    public:
        CExt661MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt662MetricSet : public CMetricSet
    {
    public:
        CExt662MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt663MetricSet : public CMetricSet
    {
    public:
        CExt663MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt664MetricSet : public CMetricSet
    {
    public:
        CExt664MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt665MetricSet : public CMetricSet
    {
    public:
        CExt665MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt666MetricSet : public CMetricSet
    {
    public:
        CExt666MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt667MetricSet : public CMetricSet
    {
    public:
        CExt667MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt668MetricSet : public CMetricSet
    {
    public:
        CExt668MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt669MetricSet : public CMetricSet
    {
    public:
        CExt669MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt670MetricSet : public CMetricSet
    {
    public:
        CExt670MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt671MetricSet : public CMetricSet
    {
    public:
        CExt671MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt672MetricSet : public CMetricSet
    {
    public:
        CExt672MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt673MetricSet : public CMetricSet
    {
    public:
        CExt673MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt674MetricSet : public CMetricSet
    {
    public:
        CExt674MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt675MetricSet : public CMetricSet
    {
    public:
        CExt675MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt676MetricSet : public CMetricSet
    {
    public:
        CExt676MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt677MetricSet : public CMetricSet
    {
    public:
        CExt677MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt678MetricSet : public CMetricSet
    {
    public:
        CExt678MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt679MetricSet : public CMetricSet
    {
    public:
        CExt679MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt680MetricSet : public CMetricSet
    {
    public:
        CExt680MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt681MetricSet : public CMetricSet
    {
    public:
        CExt681MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt682MetricSet : public CMetricSet
    {
    public:
        CExt682MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt683MetricSet : public CMetricSet
    {
    public:
        CExt683MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt684MetricSet : public CMetricSet
    {
    public:
        CExt684MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt685MetricSet : public CMetricSet
    {
    public:
        CExt685MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt686MetricSet : public CMetricSet
    {
    public:
        CExt686MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt687MetricSet : public CMetricSet
    {
    public:
        CExt687MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt688MetricSet : public CMetricSet
    {
    public:
        CExt688MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt689MetricSet : public CMetricSet
    {
    public:
        CExt689MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt690MetricSet : public CMetricSet
    {
    public:
        CExt690MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt691MetricSet : public CMetricSet
    {
    public:
        CExt691MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt692MetricSet : public CMetricSet
    {
    public:
        CExt692MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt693MetricSet : public CMetricSet
    {
    public:
        CExt693MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt694MetricSet : public CMetricSet
    {
    public:
        CExt694MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt695MetricSet : public CMetricSet
    {
    public:
        CExt695MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt696MetricSet : public CMetricSet
    {
    public:
        CExt696MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt697MetricSet : public CMetricSet
    {
    public:
        CExt697MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt698MetricSet : public CMetricSet
    {
    public:
        CExt698MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt699MetricSet : public CMetricSet
    {
    public:
        CExt699MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt700MetricSet : public CMetricSet
    {
    public:
        CExt700MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt701MetricSet : public CMetricSet
    {
    public:
        CExt701MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt702MetricSet : public CMetricSet
    {
    public:
        CExt702MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt703MetricSet : public CMetricSet
    {
    public:
        CExt703MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt704MetricSet : public CMetricSet
    {
    public:
        CExt704MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt705MetricSet : public CMetricSet
    {
    public:
        CExt705MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt706MetricSet : public CMetricSet
    {
    public:
        CExt706MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt707MetricSet : public CMetricSet
    {
    public:
        CExt707MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt708MetricSet : public CMetricSet
    {
    public:
        CExt708MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt709MetricSet : public CMetricSet
    {
    public:
        CExt709MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt710MetricSet : public CMetricSet
    {
    public:
        CExt710MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt711MetricSet : public CMetricSet
    {
    public:
        CExt711MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt712MetricSet : public CMetricSet
    {
    public:
        CExt712MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt713MetricSet : public CMetricSet
    {
    public:
        CExt713MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt714MetricSet : public CMetricSet
    {
    public:
        CExt714MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt715MetricSet : public CMetricSet
    {
    public:
        CExt715MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt716MetricSet : public CMetricSet
    {
    public:
        CExt716MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt717MetricSet : public CMetricSet
    {
    public:
        CExt717MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt718MetricSet : public CMetricSet
    {
    public:
        CExt718MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt719MetricSet : public CMetricSet
    {
    public:
        CExt719MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt720MetricSet : public CMetricSet
    {
    public:
        CExt720MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt721MetricSet : public CMetricSet
    {
    public:
        CExt721MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt722MetricSet : public CMetricSet
    {
    public:
        CExt722MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt723MetricSet : public CMetricSet
    {
    public:
        CExt723MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt724MetricSet : public CMetricSet
    {
    public:
        CExt724MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt725MetricSet : public CMetricSet
    {
    public:
        CExt725MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt726MetricSet : public CMetricSet
    {
    public:
        CExt726MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt727MetricSet : public CMetricSet
    {
    public:
        CExt727MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt728MetricSet : public CMetricSet
    {
    public:
        CExt728MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt729MetricSet : public CMetricSet
    {
    public:
        CExt729MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt730MetricSet : public CMetricSet
    {
    public:
        CExt730MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt731MetricSet : public CMetricSet
    {
    public:
        CExt731MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt732MetricSet : public CMetricSet
    {
    public:
        CExt732MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt733MetricSet : public CMetricSet
    {
    public:
        CExt733MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt734MetricSet : public CMetricSet
    {
    public:
        CExt734MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt735MetricSet : public CMetricSet
    {
    public:
        CExt735MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt736MetricSet : public CMetricSet
    {
    public:
        CExt736MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt737MetricSet : public CMetricSet
    {
    public:
        CExt737MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt738MetricSet : public CMetricSet
    {
    public:
        CExt738MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt739MetricSet : public CMetricSet
    {
    public:
        CExt739MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt740MetricSet : public CMetricSet
    {
    public:
        CExt740MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt741MetricSet : public CMetricSet
    {
    public:
        CExt741MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt742MetricSet : public CMetricSet
    {
    public:
        CExt742MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt743MetricSet : public CMetricSet
    {
    public:
        CExt743MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt744MetricSet : public CMetricSet
    {
    public:
        CExt744MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt745MetricSet : public CMetricSet
    {
    public:
        CExt745MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt746MetricSet : public CMetricSet
    {
    public:
        CExt746MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt747MetricSet : public CMetricSet
    {
    public:
        CExt747MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt748MetricSet : public CMetricSet
    {
    public:
        CExt748MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt749MetricSet : public CMetricSet
    {
    public:
        CExt749MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt750MetricSet : public CMetricSet
    {
    public:
        CExt750MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt751MetricSet : public CMetricSet
    {
    public:
        CExt751MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt752MetricSet : public CMetricSet
    {
    public:
        CExt752MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt753MetricSet : public CMetricSet
    {
    public:
        CExt753MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt754MetricSet : public CMetricSet
    {
    public:
        CExt754MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt755MetricSet : public CMetricSet
    {
    public:
        CExt755MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt756MetricSet : public CMetricSet
    {
    public:
        CExt756MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt757MetricSet : public CMetricSet
    {
    public:
        CExt757MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt758MetricSet : public CMetricSet
    {
    public:
        CExt758MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt759MetricSet : public CMetricSet
    {
    public:
        CExt759MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt760MetricSet : public CMetricSet
    {
    public:
        CExt760MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt761MetricSet : public CMetricSet
    {
    public:
        CExt761MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt762MetricSet : public CMetricSet
    {
    public:
        CExt762MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt763MetricSet : public CMetricSet
    {
    public:
        CExt763MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt764MetricSet : public CMetricSet
    {
    public:
        CExt764MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt765MetricSet : public CMetricSet
    {
    public:
        CExt765MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt766MetricSet : public CMetricSet
    {
    public:
        CExt766MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt767MetricSet : public CMetricSet
    {
    public:
        CExt767MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt768MetricSet : public CMetricSet
    {
    public:
        CExt768MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt769MetricSet : public CMetricSet
    {
    public:
        CExt769MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt770MetricSet : public CMetricSet
    {
    public:
        CExt770MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt771MetricSet : public CMetricSet
    {
    public:
        CExt771MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt772MetricSet : public CMetricSet
    {
    public:
        CExt772MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt773MetricSet : public CMetricSet
    {
    public:
        CExt773MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt774MetricSet : public CMetricSet
    {
    public:
        CExt774MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt775MetricSet : public CMetricSet
    {
    public:
        CExt775MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt776MetricSet : public CMetricSet
    {
    public:
        CExt776MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt777MetricSet : public CMetricSet
    {
    public:
        CExt777MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt778MetricSet : public CMetricSet
    {
    public:
        CExt778MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt779MetricSet : public CMetricSet
    {
    public:
        CExt779MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt780MetricSet : public CMetricSet
    {
    public:
        CExt780MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt781MetricSet : public CMetricSet
    {
    public:
        CExt781MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt782MetricSet : public CMetricSet
    {
    public:
        CExt782MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt783MetricSet : public CMetricSet
    {
    public:
        CExt783MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt784MetricSet : public CMetricSet
    {
    public:
        CExt784MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt785MetricSet : public CMetricSet
    {
    public:
        CExt785MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt786MetricSet : public CMetricSet
    {
    public:
        CExt786MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt787MetricSet : public CMetricSet
    {
    public:
        CExt787MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt788MetricSet : public CMetricSet
    {
    public:
        CExt788MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt789MetricSet : public CMetricSet
    {
    public:
        CExt789MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt790MetricSet : public CMetricSet
    {
    public:
        CExt790MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt791MetricSet : public CMetricSet
    {
    public:
        CExt791MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt792MetricSet : public CMetricSet
    {
    public:
        CExt792MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt793MetricSet : public CMetricSet
    {
    public:
        CExt793MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt794MetricSet : public CMetricSet
    {
    public:
        CExt794MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt795MetricSet : public CMetricSet
    {
    public:
        CExt795MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt796MetricSet : public CMetricSet
    {
    public:
        CExt796MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt797MetricSet : public CMetricSet
    {
    public:
        CExt797MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt798MetricSet : public CMetricSet
    {
    public:
        CExt798MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt799MetricSet : public CMetricSet
    {
    public:
        CExt799MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt800MetricSet : public CMetricSet
    {
    public:
        CExt800MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt801MetricSet : public CMetricSet
    {
    public:
        CExt801MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt802MetricSet : public CMetricSet
    {
    public:
        CExt802MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt803MetricSet : public CMetricSet
    {
    public:
        CExt803MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt804MetricSet : public CMetricSet
    {
    public:
        CExt804MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt805MetricSet : public CMetricSet
    {
    public:
        CExt805MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt806MetricSet : public CMetricSet
    {
    public:
        CExt806MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt807MetricSet : public CMetricSet
    {
    public:
        CExt807MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt808MetricSet : public CMetricSet
    {
    public:
        CExt808MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt809MetricSet : public CMetricSet
    {
    public:
        CExt809MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt810MetricSet : public CMetricSet
    {
    public:
        CExt810MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt811MetricSet : public CMetricSet
    {
    public:
        CExt811MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt812MetricSet : public CMetricSet
    {
    public:
        CExt812MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt813MetricSet : public CMetricSet
    {
    public:
        CExt813MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt814MetricSet : public CMetricSet
    {
    public:
        CExt814MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt815MetricSet : public CMetricSet
    {
    public:
        CExt815MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt816MetricSet : public CMetricSet
    {
    public:
        CExt816MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt817MetricSet : public CMetricSet
    {
    public:
        CExt817MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt818MetricSet : public CMetricSet
    {
    public:
        CExt818MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt819MetricSet : public CMetricSet
    {
    public:
        CExt819MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt820MetricSet : public CMetricSet
    {
    public:
        CExt820MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt821MetricSet : public CMetricSet
    {
    public:
        CExt821MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt822MetricSet : public CMetricSet
    {
    public:
        CExt822MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt823MetricSet : public CMetricSet
    {
    public:
        CExt823MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt824MetricSet : public CMetricSet
    {
    public:
        CExt824MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt825MetricSet : public CMetricSet
    {
    public:
        CExt825MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt826MetricSet : public CMetricSet
    {
    public:
        CExt826MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt827MetricSet : public CMetricSet
    {
    public:
        CExt827MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt828MetricSet : public CMetricSet
    {
    public:
        CExt828MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt829MetricSet : public CMetricSet
    {
    public:
        CExt829MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt830MetricSet : public CMetricSet
    {
    public:
        CExt830MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt831MetricSet : public CMetricSet
    {
    public:
        CExt831MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt832MetricSet : public CMetricSet
    {
    public:
        CExt832MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt833MetricSet : public CMetricSet
    {
    public:
        CExt833MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt834MetricSet : public CMetricSet
    {
    public:
        CExt834MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt835MetricSet : public CMetricSet
    {
    public:
        CExt835MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt836MetricSet : public CMetricSet
    {
    public:
        CExt836MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt837MetricSet : public CMetricSet
    {
    public:
        CExt837MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt838MetricSet : public CMetricSet
    {
    public:
        CExt838MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt839MetricSet : public CMetricSet
    {
    public:
        CExt839MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt840MetricSet : public CMetricSet
    {
    public:
        CExt840MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt841MetricSet : public CMetricSet
    {
    public:
        CExt841MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt842MetricSet : public CMetricSet
    {
    public:
        CExt842MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt843MetricSet : public CMetricSet
    {
    public:
        CExt843MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt844MetricSet : public CMetricSet
    {
    public:
        CExt844MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt845MetricSet : public CMetricSet
    {
    public:
        CExt845MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt846MetricSet : public CMetricSet
    {
    public:
        CExt846MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt847MetricSet : public CMetricSet
    {
    public:
        CExt847MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt848MetricSet : public CMetricSet
    {
    public:
        CExt848MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt849MetricSet : public CMetricSet
    {
    public:
        CExt849MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt850MetricSet : public CMetricSet
    {
    public:
        CExt850MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt851MetricSet : public CMetricSet
    {
    public:
        CExt851MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt852MetricSet : public CMetricSet
    {
    public:
        CExt852MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt853MetricSet : public CMetricSet
    {
    public:
        CExt853MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt854MetricSet : public CMetricSet
    {
    public:
        CExt854MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt855MetricSet : public CMetricSet
    {
    public:
        CExt855MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt856MetricSet : public CMetricSet
    {
    public:
        CExt856MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt857MetricSet : public CMetricSet
    {
    public:
        CExt857MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt858MetricSet : public CMetricSet
    {
    public:
        CExt858MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt859MetricSet : public CMetricSet
    {
    public:
        CExt859MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt860MetricSet : public CMetricSet
    {
    public:
        CExt860MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt861MetricSet : public CMetricSet
    {
    public:
        CExt861MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt862MetricSet : public CMetricSet
    {
    public:
        CExt862MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt863MetricSet : public CMetricSet
    {
    public:
        CExt863MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt864MetricSet : public CMetricSet
    {
    public:
        CExt864MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt865MetricSet : public CMetricSet
    {
    public:
        CExt865MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt866MetricSet : public CMetricSet
    {
    public:
        CExt866MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt867MetricSet : public CMetricSet
    {
    public:
        CExt867MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt868MetricSet : public CMetricSet
    {
    public:
        CExt868MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt869MetricSet : public CMetricSet
    {
    public:
        CExt869MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt870MetricSet : public CMetricSet
    {
    public:
        CExt870MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt871MetricSet : public CMetricSet
    {
    public:
        CExt871MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt872MetricSet : public CMetricSet
    {
    public:
        CExt872MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt873MetricSet : public CMetricSet
    {
    public:
        CExt873MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt874MetricSet : public CMetricSet
    {
    public:
        CExt874MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt875MetricSet : public CMetricSet
    {
    public:
        CExt875MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt876MetricSet : public CMetricSet
    {
    public:
        CExt876MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt877MetricSet : public CMetricSet
    {
    public:
        CExt877MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt878MetricSet : public CMetricSet
    {
    public:
        CExt878MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt879MetricSet : public CMetricSet
    {
    public:
        CExt879MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt880MetricSet : public CMetricSet
    {
    public:
        CExt880MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt881MetricSet : public CMetricSet
    {
    public:
        CExt881MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt882MetricSet : public CMetricSet
    {
    public:
        CExt882MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt883MetricSet : public CMetricSet
    {
    public:
        CExt883MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt884MetricSet : public CMetricSet
    {
    public:
        CExt884MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt885MetricSet : public CMetricSet
    {
    public:
        CExt885MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt886MetricSet : public CMetricSet
    {
    public:
        CExt886MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt887MetricSet : public CMetricSet
    {
    public:
        CExt887MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt888MetricSet : public CMetricSet
    {
    public:
        CExt888MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt889MetricSet : public CMetricSet
    {
    public:
        CExt889MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt890MetricSet : public CMetricSet
    {
    public:
        CExt890MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt891MetricSet : public CMetricSet
    {
    public:
        CExt891MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt892MetricSet : public CMetricSet
    {
    public:
        CExt892MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt893MetricSet : public CMetricSet
    {
    public:
        CExt893MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt894MetricSet : public CMetricSet
    {
    public:
        CExt894MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt895MetricSet : public CMetricSet
    {
    public:
        CExt895MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt896MetricSet : public CMetricSet
    {
    public:
        CExt896MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt897MetricSet : public CMetricSet
    {
    public:
        CExt897MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt898MetricSet : public CMetricSet
    {
    public:
        CExt898MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt899MetricSet : public CMetricSet
    {
    public:
        CExt899MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt900MetricSet : public CMetricSet
    {
    public:
        CExt900MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt901MetricSet : public CMetricSet
    {
    public:
        CExt901MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt902MetricSet : public CMetricSet
    {
    public:
        CExt902MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt903MetricSet : public CMetricSet
    {
    public:
        CExt903MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt904MetricSet : public CMetricSet
    {
    public:
        CExt904MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt905MetricSet : public CMetricSet
    {
    public:
        CExt905MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt906MetricSet : public CMetricSet
    {
    public:
        CExt906MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt907MetricSet : public CMetricSet
    {
    public:
        CExt907MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt908MetricSet : public CMetricSet
    {
    public:
        CExt908MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt909MetricSet : public CMetricSet
    {
    public:
        CExt909MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt910MetricSet : public CMetricSet
    {
    public:
        CExt910MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt911MetricSet : public CMetricSet
    {
    public:
        CExt911MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt912MetricSet : public CMetricSet
    {
    public:
        CExt912MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt913MetricSet : public CMetricSet
    {
    public:
        CExt913MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt914MetricSet : public CMetricSet
    {
    public:
        CExt914MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt915MetricSet : public CMetricSet
    {
    public:
        CExt915MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt916MetricSet : public CMetricSet
    {
    public:
        CExt916MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt917MetricSet : public CMetricSet
    {
    public:
        CExt917MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt918MetricSet : public CMetricSet
    {
    public:
        CExt918MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt919MetricSet : public CMetricSet
    {
    public:
        CExt919MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt920MetricSet : public CMetricSet
    {
    public:
        CExt920MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt921MetricSet : public CMetricSet
    {
    public:
        CExt921MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt922MetricSet : public CMetricSet
    {
    public:
        CExt922MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt923MetricSet : public CMetricSet
    {
    public:
        CExt923MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt924MetricSet : public CMetricSet
    {
    public:
        CExt924MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt925MetricSet : public CMetricSet
    {
    public:
        CExt925MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt926MetricSet : public CMetricSet
    {
    public:
        CExt926MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt927MetricSet : public CMetricSet
    {
    public:
        CExt927MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt928MetricSet : public CMetricSet
    {
    public:
        CExt928MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt929MetricSet : public CMetricSet
    {
    public:
        CExt929MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt930MetricSet : public CMetricSet
    {
    public:
        CExt930MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt931MetricSet : public CMetricSet
    {
    public:
        CExt931MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt932MetricSet : public CMetricSet
    {
    public:
        CExt932MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt933MetricSet : public CMetricSet
    {
    public:
        CExt933MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt934MetricSet : public CMetricSet
    {
    public:
        CExt934MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt935MetricSet : public CMetricSet
    {
    public:
        CExt935MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt936MetricSet : public CMetricSet
    {
    public:
        CExt936MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt937MetricSet : public CMetricSet
    {
    public:
        CExt937MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt938MetricSet : public CMetricSet
    {
    public:
        CExt938MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt939MetricSet : public CMetricSet
    {
    public:
        CExt939MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt940MetricSet : public CMetricSet
    {
    public:
        CExt940MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt941MetricSet : public CMetricSet
    {
    public:
        CExt941MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt942MetricSet : public CMetricSet
    {
    public:
        CExt942MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt943MetricSet : public CMetricSet
    {
    public:
        CExt943MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt944MetricSet : public CMetricSet
    {
    public:
        CExt944MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt945MetricSet : public CMetricSet
    {
    public:
        CExt945MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt946MetricSet : public CMetricSet
    {
    public:
        CExt946MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt947MetricSet : public CMetricSet
    {
    public:
        CExt947MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt948MetricSet : public CMetricSet
    {
    public:
        CExt948MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt949MetricSet : public CMetricSet
    {
    public:
        CExt949MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt950MetricSet : public CMetricSet
    {
    public:
        CExt950MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt951MetricSet : public CMetricSet
    {
    public:
        CExt951MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt952MetricSet : public CMetricSet
    {
    public:
        CExt952MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt953MetricSet : public CMetricSet
    {
    public:
        CExt953MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt954MetricSet : public CMetricSet
    {
    public:
        CExt954MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt955MetricSet : public CMetricSet
    {
    public:
        CExt955MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt956MetricSet : public CMetricSet
    {
    public:
        CExt956MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt957MetricSet : public CMetricSet
    {
    public:
        CExt957MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt958MetricSet : public CMetricSet
    {
    public:
        CExt958MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt959MetricSet : public CMetricSet
    {
    public:
        CExt959MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt960MetricSet : public CMetricSet
    {
    public:
        CExt960MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt961MetricSet : public CMetricSet
    {
    public:
        CExt961MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt962MetricSet : public CMetricSet
    {
    public:
        CExt962MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt963MetricSet : public CMetricSet
    {
    public:
        CExt963MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt964MetricSet : public CMetricSet
    {
    public:
        CExt964MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt965MetricSet : public CMetricSet
    {
    public:
        CExt965MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt966MetricSet : public CMetricSet
    {
    public:
        CExt966MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt967MetricSet : public CMetricSet
    {
    public:
        CExt967MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt968MetricSet : public CMetricSet
    {
    public:
        CExt968MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt969MetricSet : public CMetricSet
    {
    public:
        CExt969MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt970MetricSet : public CMetricSet
    {
    public:
        CExt970MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt971MetricSet : public CMetricSet
    {
    public:
        CExt971MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt972MetricSet : public CMetricSet
    {
    public:
        CExt972MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt973MetricSet : public CMetricSet
    {
    public:
        CExt973MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt974MetricSet : public CMetricSet
    {
    public:
        CExt974MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt975MetricSet : public CMetricSet
    {
    public:
        CExt975MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt976MetricSet : public CMetricSet
    {
    public:
        CExt976MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt977MetricSet : public CMetricSet
    {
    public:
        CExt977MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt978MetricSet : public CMetricSet
    {
    public:
        CExt978MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt979MetricSet : public CMetricSet
    {
    public:
        CExt979MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt980MetricSet : public CMetricSet
    {
    public:
        CExt980MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt981MetricSet : public CMetricSet
    {
    public:
        CExt981MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt982MetricSet : public CMetricSet
    {
    public:
        CExt982MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt983MetricSet : public CMetricSet
    {
    public:
        CExt983MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt984MetricSet : public CMetricSet
    {
    public:
        CExt984MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt985MetricSet : public CMetricSet
    {
    public:
        CExt985MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt986MetricSet : public CMetricSet
    {
    public:
        CExt986MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt987MetricSet : public CMetricSet
    {
    public:
        CExt987MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt1000MetricSet : public CMetricSet
    {
    public:
        CExt1000MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt1001MetricSet : public CMetricSet
    {
    public:
        CExt1001MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt1002MetricSet : public CMetricSet
    {
    public:
        CExt1002MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt1004MetricSet : public CMetricSet
    {
    public:
        CExt1004MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt1005MetricSet : public CMetricSet
    {
    public:
        CExt1005MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt1006MetricSet : public CMetricSet
    {
    public:
        CExt1006MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt1007MetricSet : public CMetricSet
    {
    public:
        CExt1007MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CExt1010MetricSet : public CMetricSet
    {
    public:
        CExt1010MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

} // namespace MetricsDiscoveryInternal::MetricSets_ACM_GT3_OA

#endif
