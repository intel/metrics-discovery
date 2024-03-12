/*========================== begin_copyright_notice ============================

Copyright (C) 2022-2024 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_metrics_ACM_GT1.cpp

//     Abstract:   C++ automated generated file to stack metrics meta data

#include "md_per_platform_preamble.h"
#include "md_metric_sets_ACM_GT1.h"

#if( ( !defined( MD_INCLUDE_ACM_GT1_METRICS ) && MD_INCLUDE_ALL_METRICS ) || MD_INCLUDE_ACM_GT1_METRICS )

using namespace MetricsDiscoveryInternal;

TCompletionCode CreateMetricTreeACM_GT1_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup )
{
    const uint32_t adapterId = OBTAIN_ADAPTER_ID( metricsDevice );

    MD_LOG_ENTER_A( adapterId );
    MD_CHECK_PTR_RET_A( adapterId, metricsDevice, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET_A( adapterId, concurrentGroup, CC_ERROR_INVALID_PARAMETER );

    CMetricSet*      metricSet                                               = nullptr;
    uint8_t          platformMaskByteArray[MD_PLATFORM_MASK_BYTE_ARRAY_SIZE] = {};
    TByteArrayLatest platformMask                                            = { MD_PLATFORM_MASK_BYTE_ARRAY_SIZE, platformMaskByteArray };

    MD_CHECK_CC( SetPlatformMask( adapterId, &platformMask, nullptr, false, GENERATION_ACM ) );

    if( metricsDevice->IsPlatformTypeOf( &platformMask, GT_TYPE_GT1 ) )
    {
        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_PipelineStatistics::CPipelineStatsMetricSet>( "PipelineStats", "Pipeline Statistics for OGL4", API_TYPE_OGL | API_TYPE_OGL4_X,
            GPU_RENDER | GPU_COMPUTE, 0, 96, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );
    }

    MD_LOG_EXIT_A( adapterId );
    return CC_OK;

exception:
    MD_LOG_EXIT_A( adapterId );
    return CC_ERROR_NO_MEMORY;
}
#endif

#if( ( !defined( MD_INCLUDE_ACM_GT1_METRICS ) && MD_INCLUDE_ALL_METRICS ) || MD_INCLUDE_ACM_GT1_METRICS )

using namespace MetricsDiscoveryInternal;

TCompletionCode CreateMetricTreeACM_GT1_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup )
{
    const uint32_t adapterId = OBTAIN_ADAPTER_ID( metricsDevice );

    MD_LOG_ENTER_A( adapterId );
    MD_CHECK_PTR_RET_A( adapterId, metricsDevice, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET_A( adapterId, concurrentGroup, CC_ERROR_INVALID_PARAMETER );

    CMetricSet*      metricSet                                               = nullptr;
    uint8_t          platformMaskByteArray[MD_PLATFORM_MASK_BYTE_ARRAY_SIZE] = {};
    TByteArrayLatest platformMask                                            = { MD_PLATFORM_MASK_BYTE_ARRAY_SIZE, platformMaskByteArray };

    MD_CHECK_CC( SetPlatformMask( adapterId, &platformMask, nullptr, false, GENERATION_ACM ) );

    if( metricsDevice->IsPlatformTypeOf( &platformMask, GT_TYPE_GT1 ) )
    {
        MetricSets_ACM_GT1_OA::AddInformationSet( concurrentGroup );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CRenderBasicMetricSet_Refresh>( "RenderBasic", "Render Metrics Basic - aggregation approximation", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CComputeBasicMetricSet_Refresh>( "ComputeBasic", "Compute Metrics Basic", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CAsyncComputeMetricSet_Refresh>( "AsyncCompute", "AsyncCompute", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CXveActivity1MetricSet_Refresh>( "XveActivity1", "XveActivity1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CGpuBusynessMetricSet_Refresh>( "GpuBusyness", "GpuBusyness", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CRenderBasicMetricSet_AsyncWA>( "RenderBasic", "Render Metrics Basic - aggregation approximation", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CComputeBasicMetricSet_AsyncWA>( "ComputeBasic", "Compute Metrics Basic", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CThreadsAndRast1MetricSet_AsyncWA>( "ThreadsAndRast1", "ThreadsAndRast1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CThreadsAndRast2MetricSet_AsyncWA>( "ThreadsAndRast2", "ThreadsAndRast2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CThreadsAndRast3MetricSet_AsyncWA>( "ThreadsAndRast3", "ThreadsAndRast3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CThreadsAndRast4MetricSet_AsyncWA>( "ThreadsAndRast4", "ThreadsAndRast4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CAsyncComputeMetricSet_AsyncWA>( "AsyncCompute", "AsyncCompute", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CXveActivity1MetricSet_AsyncWA>( "XveActivity1", "XveActivity1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CGpuBusynessMetricSet_AsyncWA>( "GpuBusyness", "GpuBusyness", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CRenderPipeProfile1MetricSet>( "RenderPipeProfile1", "Render Metrics for 3D Pipeline Profile", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CRenderPipeProfile2MetricSet>( "RenderPipeProfile2", "Render Metrics for 3D Pipeline Profile", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CL3MetricSet>( "L3", "L3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CSamplerMetricSet>( "Sampler", "Sampler_Slice23", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CHDCAndSF1MetricSet>( "HDCAndSF1", "Metric set HDCAndSF1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CHDCAndSF2MetricSet>( "HDCAndSF2", "Metric set HDCAndSF2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CRasterizerAndPixelBackend1MetricSet>( "RasterizerAndPixelBackend1", "Metric set RasterizerAndPixelBackend1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CRasterizerAndPixelBackend2MetricSet>( "RasterizerAndPixelBackend2", "Metric set RasterizerAndPixelBackend2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CTDL1MetricSet>( "TDL1", "TDL1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CTDL2MetricSet>( "TDL2", "TDL2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CTDL3MetricSet>( "TDL3", "TDL3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CTDL4MetricSet>( "TDL4", "TDL4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CTestOaMetricSet>( "TestOa", "Metric set TestOa", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CComputeOverviewMetricSet>( "ComputeOverview", "ComputeOverview", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CL1ProfileReadsMetricSet_XeCore0>( "L1ProfileReads", "L1ProfileReads", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$GtSlice0XeCore0 $GtSlice1XeCore0 UADD $GtSlice2XeCore0 UADD $GtSlice3XeCore0 UADD $GtSlice4XeCore0 UADD $GtSlice5XeCore0 UADD $GtSlice6XeCore0 UADD $GtSlice7XeCore0 UADD $GtSlice0XeCore3 $GtSlice1XeCore3 UADD $GtSlice2XeCore3 UADD $GtSlice3XeCore3 UADD $GtSlice4XeCore3 UADD $GtSlice5XeCore3 UADD $GtSlice6XeCore3 UADD $GtSlice7XeCore3 UADD UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CL1ProfileReadsMetricSet_XeCore3>( "L1ProfileReads", "L1ProfileReads", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$GtSlice0XeCore0 $GtSlice1XeCore0 UADD $GtSlice2XeCore0 UADD $GtSlice3XeCore0 UADD $GtSlice4XeCore0 UADD $GtSlice5XeCore0 UADD $GtSlice6XeCore0 UADD $GtSlice7XeCore0 UADD $GtSlice0XeCore3 $GtSlice1XeCore3 UADD $GtSlice2XeCore3 UADD $GtSlice3XeCore3 UADD $GtSlice4XeCore3 UADD $GtSlice5XeCore3 UADD $GtSlice6XeCore3 UADD $GtSlice7XeCore3 UADD ULT", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CL1ProfileSlmBankConflictsMetricSet_XeCore0>( "L1ProfileSlmBankConflicts", "L1ProfileSlmBankConflicts", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$GtSlice0XeCore0 $GtSlice1XeCore0 UADD $GtSlice2XeCore0 UADD $GtSlice3XeCore0 UADD $GtSlice4XeCore0 UADD $GtSlice5XeCore0 UADD $GtSlice6XeCore0 UADD $GtSlice7XeCore0 UADD $GtSlice0XeCore3 $GtSlice1XeCore3 UADD $GtSlice2XeCore3 UADD $GtSlice3XeCore3 UADD $GtSlice4XeCore3 UADD $GtSlice5XeCore3 UADD $GtSlice6XeCore3 UADD $GtSlice7XeCore3 UADD UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CL1ProfileSlmBankConflictsMetricSet_XeCore3>( "L1ProfileSlmBankConflicts", "L1ProfileSlmBankConflicts", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$GtSlice0XeCore0 $GtSlice1XeCore0 UADD $GtSlice2XeCore0 UADD $GtSlice3XeCore0 UADD $GtSlice4XeCore0 UADD $GtSlice5XeCore0 UADD $GtSlice6XeCore0 UADD $GtSlice7XeCore0 UADD $GtSlice0XeCore3 $GtSlice1XeCore3 UADD $GtSlice2XeCore3 UADD $GtSlice3XeCore3 UADD $GtSlice4XeCore3 UADD $GtSlice5XeCore3 UADD $GtSlice6XeCore3 UADD $GtSlice7XeCore3 UADD ULT", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CL1ProfileWritesMetricSet_XeCore0>( "L1ProfileWrites", "L1ProfileWrites", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$GtSlice0XeCore0 $GtSlice1XeCore0 UADD $GtSlice2XeCore0 UADD $GtSlice3XeCore0 UADD $GtSlice4XeCore0 UADD $GtSlice5XeCore0 UADD $GtSlice6XeCore0 UADD $GtSlice7XeCore0 UADD $GtSlice0XeCore3 $GtSlice1XeCore3 UADD $GtSlice2XeCore3 UADD $GtSlice3XeCore3 UADD $GtSlice4XeCore3 UADD $GtSlice5XeCore3 UADD $GtSlice6XeCore3 UADD $GtSlice7XeCore3 UADD UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CL1ProfileWritesMetricSet_XeCore3>( "L1ProfileWrites", "L1ProfileWrites", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$GtSlice0XeCore0 $GtSlice1XeCore0 UADD $GtSlice2XeCore0 UADD $GtSlice3XeCore0 UADD $GtSlice4XeCore0 UADD $GtSlice5XeCore0 UADD $GtSlice6XeCore0 UADD $GtSlice7XeCore0 UADD $GtSlice0XeCore3 $GtSlice1XeCore3 UADD $GtSlice2XeCore3 UADD $GtSlice3XeCore3 UADD $GtSlice4XeCore3 UADD $GtSlice5XeCore3 UADD $GtSlice6XeCore3 UADD $GtSlice7XeCore3 UADD ULT", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CDataportReadsMetricSet>( "DataportReads", "DataportReads", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CDataportWritesMetricSet>( "DataportWrites", "DataportWrites", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt1MetricSet>( "Ext1", "Ext1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt2MetricSet>( "Ext2", "Ext2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt3MetricSet>( "Ext3", "Ext3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt4MetricSet>( "Ext4", "Ext4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt5MetricSet>( "Ext5", "Ext5", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt6MetricSet>( "Ext6", "Ext6", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt7MetricSet>( "Ext7", "Ext7", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt8MetricSet>( "Ext8", "Ext8", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt9MetricSet>( "Ext9", "Ext9", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt10MetricSet>( "Ext10", "Ext10", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt11MetricSet>( "Ext11", "Ext11", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt12MetricSet>( "Ext12", "Ext12", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt13MetricSet>( "Ext13", "Ext13", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt14MetricSet>( "Ext14", "Ext14", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt15MetricSet>( "Ext15", "Ext15", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt16MetricSet>( "Ext16", "Ext16", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt17MetricSet>( "Ext17", "Ext17", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt18MetricSet>( "Ext18", "Ext18", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt19MetricSet>( "Ext19", "Ext19", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt20MetricSet>( "Ext20", "Ext20", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt21MetricSet>( "Ext21", "Ext21", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt22MetricSet>( "Ext22", "Ext22", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt23MetricSet>( "Ext23", "Ext23", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt24MetricSet>( "Ext24", "Ext24", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt25MetricSet>( "Ext25", "Ext25", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt26MetricSet>( "Ext26", "Ext26", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt27MetricSet>( "Ext27", "Ext27", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt28MetricSet>( "Ext28", "Ext28", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt29MetricSet>( "Ext29", "Ext29", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt30MetricSet>( "Ext30", "Ext30", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt31MetricSet>( "Ext31", "Ext31", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt32MetricSet>( "Ext32", "Ext32", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt33MetricSet>( "Ext33", "Ext33", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt34MetricSet>( "Ext34", "Ext34", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt35MetricSet>( "Ext35", "Ext35", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt36MetricSet>( "Ext36", "Ext36", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt37MetricSet>( "Ext37", "Ext37", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt38MetricSet>( "Ext38", "Ext38", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt39MetricSet>( "Ext39", "Ext39", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt40MetricSet>( "Ext40", "Ext40", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt41MetricSet>( "Ext41", "Ext41", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt42MetricSet>( "Ext42", "Ext42", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt43MetricSet>( "Ext43", "Ext43", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt44MetricSet>( "Ext44", "Ext44", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt45MetricSet>( "Ext45", "Ext45", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt46MetricSet>( "Ext46", "Ext46", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt47MetricSet>( "Ext47", "Ext47", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt48MetricSet>( "Ext48", "Ext48", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt49MetricSet>( "Ext49", "Ext49", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt50MetricSet>( "Ext50", "Ext50", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt51MetricSet>( "Ext51", "Ext51", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt52MetricSet>( "Ext52", "Ext52", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt53MetricSet>( "Ext53", "Ext53", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt54MetricSet>( "Ext54", "Ext54", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt55MetricSet>( "Ext55", "Ext55", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt56MetricSet>( "Ext56", "Ext56", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt57MetricSet>( "Ext57", "Ext57", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt58MetricSet>( "Ext58", "Ext58", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt59MetricSet>( "Ext59", "Ext59", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt60MetricSet>( "Ext60", "Ext60", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt61MetricSet>( "Ext61", "Ext61", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt62MetricSet>( "Ext62", "Ext62", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt63MetricSet>( "Ext63", "Ext63", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt64MetricSet>( "Ext64", "Ext64", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt65MetricSet>( "Ext65", "Ext65", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt66MetricSet>( "Ext66", "Ext66", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt67MetricSet>( "Ext67", "Ext67", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt68MetricSet>( "Ext68", "Ext68", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt69MetricSet>( "Ext69", "Ext69", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt70MetricSet>( "Ext70", "Ext70", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt71MetricSet>( "Ext71", "Ext71", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt72MetricSet>( "Ext72", "Ext72", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt73MetricSet>( "Ext73", "Ext73", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt74MetricSet>( "Ext74", "Ext74", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt75MetricSet>( "Ext75", "Ext75", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt76MetricSet>( "Ext76", "Ext76", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt77MetricSet>( "Ext77", "Ext77", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt78MetricSet>( "Ext78", "Ext78", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt79MetricSet>( "Ext79", "Ext79", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt80MetricSet>( "Ext80", "Ext80", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt81MetricSet>( "Ext81", "Ext81", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt82MetricSet>( "Ext82", "Ext82", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt83MetricSet>( "Ext83", "Ext83", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt84MetricSet>( "Ext84", "Ext84", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt85MetricSet>( "Ext85", "Ext85", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt86MetricSet>( "Ext86", "Ext86", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt87MetricSet>( "Ext87", "Ext87", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt88MetricSet>( "Ext88", "Ext88", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt91MetricSet>( "Ext91", "Ext91", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt92MetricSet>( "Ext92", "Ext92", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt93MetricSet>( "Ext93", "Ext93", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt94MetricSet>( "Ext94", "Ext94", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt95MetricSet>( "Ext95", "Ext95", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt96MetricSet>( "Ext96", "Ext96", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt97MetricSet>( "Ext97", "Ext97", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt98MetricSet>( "Ext98", "Ext98", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt99MetricSet>( "Ext99", "Ext99", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt100MetricSet>( "Ext100", "Ext100", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt101MetricSet>( "Ext101", "Ext101", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt102MetricSet>( "Ext102", "Ext102", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt103MetricSet>( "Ext103", "Ext103", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt104MetricSet>( "Ext104", "Ext104", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt105MetricSet>( "Ext105", "Ext105", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt106MetricSet>( "Ext106", "Ext106", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt107MetricSet>( "Ext107", "Ext107", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt108MetricSet>( "Ext108", "Ext108", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt109MetricSet>( "Ext109", "Ext109", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt110MetricSet>( "Ext110", "Ext110", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt111MetricSet>( "Ext111", "Ext111", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt112MetricSet>( "Ext112", "Ext112", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt113MetricSet>( "Ext113", "Ext113", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt114MetricSet>( "Ext114", "Ext114", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt115MetricSet>( "Ext115", "Ext115", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt116MetricSet>( "Ext116", "Ext116", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt117MetricSet>( "Ext117", "Ext117", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt118MetricSet>( "Ext118", "Ext118", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt119MetricSet>( "Ext119", "Ext119", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt120MetricSet_FirstVersion>( "Ext120", "Ext120", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt121MetricSet_FirstVersion>( "Ext121", "Ext121", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt120MetricSet_Refresh>( "Ext120", "Ext120", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt121MetricSet_Refresh>( "Ext121", "Ext121", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt122MetricSet>( "Ext122", "Ext122", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt123MetricSet>( "Ext123", "Ext123", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt124MetricSet>( "Ext124", "Ext124", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt125MetricSet>( "Ext125", "Ext125", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt126MetricSet>( "Ext126", "Ext126", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt127MetricSet>( "Ext127", "Ext127", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt128MetricSet>( "Ext128", "Ext128", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt129MetricSet>( "Ext129", "Ext129", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt130MetricSet>( "Ext130", "Ext130", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt131MetricSet>( "Ext131", "Ext131", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt132MetricSet>( "Ext132", "Ext132", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt133MetricSet>( "Ext133", "Ext133", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt134MetricSet>( "Ext134", "Ext134", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt135MetricSet>( "Ext135", "Ext135", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt136MetricSet>( "Ext136", "Ext136", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt137MetricSet>( "Ext137", "Ext137", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt138MetricSet>( "Ext138", "Ext138", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt139MetricSet>( "Ext139", "Ext139", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt140MetricSet>( "Ext140", "Ext140", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt141MetricSet>( "Ext141", "Ext141", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt142MetricSet>( "Ext142", "Ext142", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt143MetricSet>( "Ext143", "Ext143", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt144MetricSet>( "Ext144", "Ext144", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt145MetricSet>( "Ext145", "Ext145", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt146MetricSet>( "Ext146", "Ext146", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt147MetricSet>( "Ext147", "Ext147", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt148MetricSet>( "Ext148", "Ext148", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt149MetricSet>( "Ext149", "Ext149", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt150MetricSet>( "Ext150", "Ext150", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt151MetricSet>( "Ext151", "Ext151", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt152MetricSet>( "Ext152", "Ext152", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt153MetricSet>( "Ext153", "Ext153", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt154MetricSet>( "Ext154", "Ext154", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt155MetricSet>( "Ext155", "Ext155", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt156MetricSet>( "Ext156", "Ext156", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt157MetricSet>( "Ext157", "Ext157", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt158MetricSet>( "Ext158", "Ext158", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt159MetricSet>( "Ext159", "Ext159", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt160MetricSet>( "Ext160", "Ext160", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt161MetricSet>( "Ext161", "Ext161", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt162MetricSet>( "Ext162", "Ext162", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt163MetricSet>( "Ext163", "Ext163", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt164MetricSet>( "Ext164", "Ext164", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt165MetricSet>( "Ext165", "Ext165", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt166MetricSet>( "Ext166", "Ext166", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt167MetricSet>( "Ext167", "Ext167", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt168MetricSet>( "Ext168", "Ext168", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt169MetricSet>( "Ext169", "Ext169", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt170MetricSet>( "Ext170", "Ext170", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt171MetricSet>( "Ext171", "Ext171", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt172MetricSet>( "Ext172", "Ext172", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt173MetricSet_FirstVersion>( "Ext173", "Ext173", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt174MetricSet_FirstVersion>( "Ext174", "Ext174", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt175MetricSet_FirstVersion>( "Ext175", "Ext175", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt176MetricSet_FirstVersion>( "Ext176", "Ext176", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt177MetricSet_FirstVersion>( "Ext177", "Ext177", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt178MetricSet_FirstVersion>( "Ext178", "Ext178", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt179MetricSet_FirstVersion>( "Ext179", "Ext179", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt180MetricSet_FirstVersion>( "Ext180", "Ext180", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt173MetricSet_Refresh>( "Ext173", "Ext173", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt174MetricSet_Refresh>( "Ext174", "Ext174", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt175MetricSet_Refresh>( "Ext175", "Ext175", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt176MetricSet_Refresh>( "Ext176", "Ext176", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt177MetricSet_Refresh>( "Ext177", "Ext177", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt178MetricSet_Refresh>( "Ext178", "Ext178", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt179MetricSet_Refresh>( "Ext179", "Ext179", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt180MetricSet_Refresh>( "Ext180", "Ext180", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt181MetricSet>( "Ext181", "Ext181", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt182MetricSet>( "Ext182", "Ext182", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt183MetricSet>( "Ext183", "Ext183", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt184MetricSet>( "Ext184", "Ext184", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt185MetricSet>( "Ext185", "Ext185", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt186MetricSet>( "Ext186", "Ext186", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt187MetricSet>( "Ext187", "Ext187", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt188MetricSet>( "Ext188", "Ext188", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt189MetricSet>( "Ext189", "Ext189", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt190MetricSet>( "Ext190", "Ext190", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt191MetricSet>( "Ext191", "Ext191", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt192MetricSet>( "Ext192", "Ext192", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt193MetricSet_FirstVersion>( "Ext193", "Ext193", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt194MetricSet_FirstVersion>( "Ext194", "Ext194", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt193MetricSet_Refresh>( "Ext193", "Ext193", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt194MetricSet_Refresh>( "Ext194", "Ext194", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt195MetricSet>( "Ext195", "Ext195", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt196MetricSet>( "Ext196", "Ext196", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt197MetricSet>( "Ext197", "Ext197", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt198MetricSet>( "Ext198", "Ext198", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt199MetricSet>( "Ext199", "Ext199", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt200MetricSet>( "Ext200", "Ext200", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt201MetricSet>( "Ext201", "Ext201", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt202MetricSet>( "Ext202", "Ext202", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt203MetricSet>( "Ext203", "Ext203", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$SkuRevisionId 0x04 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt204MetricSet>( "Ext204", "Ext204", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$SkuRevisionId 0x04 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt205MetricSet>( "Ext205", "Ext205", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$SkuRevisionId 0x04 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt206MetricSet>( "Ext206", "Ext206", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$SkuRevisionId 0x04 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt207MetricSet>( "Ext207", "Ext207", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$SkuRevisionId 0x04 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt208MetricSet>( "Ext208", "Ext208", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$SkuRevisionId 0x04 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt209MetricSet>( "Ext209", "Ext209", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$SkuRevisionId 0x04 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt210MetricSet>( "Ext210", "Ext210", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$SkuRevisionId 0x04 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt211MetricSet>( "Ext211", "Ext211", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$SkuRevisionId 0x04 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt212MetricSet>( "Ext212", "Ext212", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$SkuRevisionId 0x04 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt213MetricSet>( "Ext213", "Ext213", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$SkuRevisionId 0x04 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt214MetricSet>( "Ext214", "Ext214", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$SkuRevisionId 0x04 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt215MetricSet>( "Ext215", "Ext215", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$SkuRevisionId 0x04 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt216MetricSet>( "Ext216", "Ext216", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$SkuRevisionId 0x04 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt217MetricSet>( "Ext217", "Ext217", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$SkuRevisionId 0x04 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt218MetricSet>( "Ext218", "Ext218", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$SkuRevisionId 0x04 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt219MetricSet>( "Ext219", "Ext219", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$SkuRevisionId 0x04 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt220MetricSet>( "Ext220", "Ext220", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$SkuRevisionId 0x04 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt221MetricSet>( "Ext221", "Ext221", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$SkuRevisionId 0x04 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt222MetricSet>( "Ext222", "Ext222", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt223MetricSet>( "Ext223", "Ext223", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt224MetricSet>( "Ext224", "Ext224", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt225MetricSet>( "Ext225", "Ext225", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt226MetricSet>( "Ext226", "Ext226", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt227MetricSet>( "Ext227", "Ext227", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt228MetricSet>( "Ext228", "Ext228", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt229MetricSet>( "Ext229", "Ext229", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt230MetricSet>( "Ext230", "Ext230", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt231MetricSet>( "Ext231", "Ext231", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt232MetricSet>( "Ext232", "Ext232", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt233MetricSet>( "Ext233", "Ext233", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt234MetricSet>( "Ext234", "Ext234", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt235MetricSet>( "Ext235", "Ext235", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt236MetricSet>( "Ext236", "Ext236", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt237MetricSet>( "Ext237", "Ext237", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt238MetricSet>( "Ext238", "Ext238", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt239MetricSet>( "Ext239", "Ext239", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt240MetricSet>( "Ext240", "Ext240", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt500MetricSet>( "Ext500", "Ext500", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt501MetricSet>( "Ext501", "Ext501", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt502MetricSet>( "Ext502", "Ext502", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt503MetricSet>( "Ext503", "Ext503", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt508MetricSet>( "Ext508", "Ext508", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt509MetricSet>( "Ext509", "Ext509", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt510MetricSet>( "Ext510", "Ext510", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt511MetricSet>( "Ext511", "Ext511", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt512MetricSet>( "Ext512", "Ext512", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt513MetricSet>( "Ext513", "Ext513", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt514MetricSet>( "Ext514", "Ext514", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt515MetricSet>( "Ext515", "Ext515", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt516MetricSet>( "Ext516", "Ext516", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt517MetricSet>( "Ext517", "Ext517", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt518MetricSet>( "Ext518", "Ext518", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt519MetricSet>( "Ext519", "Ext519", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt520MetricSet>( "Ext520", "Ext520", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt521MetricSet>( "Ext521", "Ext521", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt522MetricSet>( "Ext522", "Ext522", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt523MetricSet>( "Ext523", "Ext523", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt524MetricSet>( "Ext524", "Ext524", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt525MetricSet>( "Ext525", "Ext525", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt526MetricSet>( "Ext526", "Ext526", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt527MetricSet>( "Ext527", "Ext527", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt528MetricSet>( "Ext528", "Ext528", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt529MetricSet>( "Ext529", "Ext529", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt530MetricSet>( "Ext530", "Ext530", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt531MetricSet>( "Ext531", "Ext531", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt532MetricSet>( "Ext532", "Ext532", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt533MetricSet>( "Ext533", "Ext533", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt534MetricSet>( "Ext534", "Ext534", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt535MetricSet>( "Ext535", "Ext535", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt536MetricSet>( "Ext536", "Ext536", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt537MetricSet>( "Ext537", "Ext537", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt538MetricSet>( "Ext538", "Ext538", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt539MetricSet>( "Ext539", "Ext539", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt540MetricSet>( "Ext540", "Ext540", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt541MetricSet>( "Ext541", "Ext541", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt542MetricSet>( "Ext542", "Ext542", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt543MetricSet>( "Ext543", "Ext543", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt544MetricSet>( "Ext544", "Ext544", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt545MetricSet>( "Ext545", "Ext545", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt546MetricSet>( "Ext546", "Ext546", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt547MetricSet>( "Ext547", "Ext547", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt548MetricSet>( "Ext548", "Ext548", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt549MetricSet>( "Ext549", "Ext549", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt550MetricSet>( "Ext550", "Ext550", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt551MetricSet>( "Ext551", "Ext551", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt552MetricSet>( "Ext552", "Ext552", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt553MetricSet>( "Ext553", "Ext553", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt554MetricSet>( "Ext554", "Ext554", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt555MetricSet>( "Ext555", "Ext555", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt556MetricSet>( "Ext556", "Ext556", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt557MetricSet>( "Ext557", "Ext557", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt558MetricSet>( "Ext558", "Ext558", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt559MetricSet>( "Ext559", "Ext559", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt560MetricSet>( "Ext560", "Ext560", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt561MetricSet>( "Ext561", "Ext561", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt562MetricSet>( "Ext562", "Ext562", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt563MetricSet>( "Ext563", "Ext563", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt564MetricSet>( "Ext564", "Ext564", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt565MetricSet>( "Ext565", "Ext565", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt566MetricSet>( "Ext566", "Ext566", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt567MetricSet>( "Ext567", "Ext567", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt568MetricSet>( "Ext568", "Ext568", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt569MetricSet>( "Ext569", "Ext569", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt570MetricSet>( "Ext570", "Ext570", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt571MetricSet>( "Ext571", "Ext571", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt572MetricSet_Refresh>( "Ext572", "Ext572", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt573MetricSet_Refresh>( "Ext573", "Ext573", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt1000MetricSet>( "Ext1000", "Ext1000", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt1001MetricSet>( "Ext1001", "Ext1001", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt1002MetricSet>( "Ext1002", "Ext1002", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt1004MetricSet>( "Ext1004", "Ext1004", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt1005MetricSet>( "Ext1005", "Ext1005", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt1006MetricSet>( "Ext1006", "Ext1006", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt1007MetricSet>( "Ext1007", "Ext1007", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt1010MetricSet_FirstVersion>( "Ext1010", "Ext1010", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT1_OA::CExt1010MetricSet_Refresh>( "Ext1010", "Ext1010", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT1 );
        MD_CHECK_PTR( metricSet );
    }

    MD_LOG_EXIT_A( adapterId );
    return CC_OK;

exception:
    MD_LOG_EXIT_A( adapterId );
    return CC_ERROR_NO_MEMORY;
}
#endif
