/*========================== begin_copyright_notice ============================

Copyright (C) 2024-2025 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_metric_sets_PTL.h
//
//     Abstract:   C++ automated generated file to define specific for HW
//                 MetricSet classes inherited from CMetricSet

#pragma once

#if MD_INCLUDE_PTL_METRICS

namespace MetricsDiscoveryInternal::MetricSets_PTL_PipelineStatistics
{
    class CPipelineStatsMetricSet final : public CMetricSet
    {
    public:
        CPipelineStatsMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

} // namespace MetricsDiscoveryInternal::MetricSets_PTL_PipelineStatistics

namespace MetricsDiscoveryInternal::MetricSets_PTL_OA
{
    TCompletionCode AddInformationSet( CConcurrentGroup* concurrentGroup );

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

    class CDepthProfileMetricSet final : public CMetricSet
    {
    public:
        CDepthProfileMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CDeviceCacheProfileMetricSet final : public CMetricSet
    {
    public:
        CDeviceCacheProfileMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CMemoryProfileMetricSet final : public CMetricSet
    {
    public:
        CMemoryProfileMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CRenderPipeProfileMetricSet final : public CMetricSet
    {
    public:
        CRenderPipeProfileMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CRTProfileMetricSet final : public CMetricSet
    {
    public:
        CRTProfileMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CVectorEngineProfileMetricSet final : public CMetricSet
    {
    public:
        CVectorEngineProfileMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CVectorEngineStallsMetricSet final : public CMetricSet
    {
    public:
        CVectorEngineStallsMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

    class CTestOaMetricSet final : public CMetricSet
    {
    public:
        CTestOaMetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

} // namespace MetricsDiscoveryInternal::MetricSets_PTL_OA

namespace MetricsDiscoveryInternal::MetricSets_PTL_OAM0
{
    TCompletionCode AddInformationSet( CConcurrentGroup* concurrentGroup );

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

} // namespace MetricsDiscoveryInternal::MetricSets_PTL_OAM0

namespace MetricsDiscoveryInternal::MetricSets_PTL_OAMG
{
    TCompletionCode AddInformationSet( CConcurrentGroup* concurrentGroup );

    class CMediaSet1MetricSet final : public CMetricSet
    {
    public:
        CMediaSet1MetricSet( CMetricsDevice& device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );

        TCompletionCode Initialize();
    };

} // namespace MetricsDiscoveryInternal::MetricSets_PTL_OAMG

#endif
