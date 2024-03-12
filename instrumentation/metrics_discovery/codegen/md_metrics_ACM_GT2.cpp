/*========================== begin_copyright_notice ============================

Copyright (C) 2022-2024 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_metrics_ACM_GT2.cpp

//     Abstract:   C++ automated generated file to stack metrics meta data

#include "md_per_platform_preamble.h"
#include "md_metric_sets_ACM_GT2.h"

#if( ( !defined( MD_INCLUDE_ACM_GT2_METRICS ) && MD_INCLUDE_ALL_METRICS ) || MD_INCLUDE_ACM_GT2_METRICS )

using namespace MetricsDiscoveryInternal;

TCompletionCode CreateMetricTreeACM_GT2_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup )
{
    const uint32_t adapterId = OBTAIN_ADAPTER_ID( metricsDevice );

    MD_LOG_ENTER_A( adapterId );
    MD_CHECK_PTR_RET_A( adapterId, metricsDevice, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET_A( adapterId, concurrentGroup, CC_ERROR_INVALID_PARAMETER );

    CMetricSet*      metricSet                                               = nullptr;
    uint8_t          platformMaskByteArray[MD_PLATFORM_MASK_BYTE_ARRAY_SIZE] = {};
    TByteArrayLatest platformMask                                            = { MD_PLATFORM_MASK_BYTE_ARRAY_SIZE, platformMaskByteArray };

    MD_CHECK_CC( SetPlatformMask( adapterId, &platformMask, nullptr, false, GENERATION_ACM ) );

    if( metricsDevice->IsPlatformTypeOf( &platformMask, GT_TYPE_GT2 ) )
    {
        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_PipelineStatistics::CPipelineStatsMetricSet>( "PipelineStats", "Pipeline Statistics for OGL4", API_TYPE_OGL | API_TYPE_OGL4_X,
            GPU_RENDER | GPU_COMPUTE, 0, 96, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );
    }

    MD_LOG_EXIT_A( adapterId );
    return CC_OK;

exception:
    MD_LOG_EXIT_A( adapterId );
    return CC_ERROR_NO_MEMORY;
}
#endif

#if( ( !defined( MD_INCLUDE_ACM_GT2_METRICS ) && MD_INCLUDE_ALL_METRICS ) || MD_INCLUDE_ACM_GT2_METRICS )

using namespace MetricsDiscoveryInternal;

TCompletionCode CreateMetricTreeACM_GT2_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup )
{
    const uint32_t adapterId = OBTAIN_ADAPTER_ID( metricsDevice );

    MD_LOG_ENTER_A( adapterId );
    MD_CHECK_PTR_RET_A( adapterId, metricsDevice, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET_A( adapterId, concurrentGroup, CC_ERROR_INVALID_PARAMETER );

    CMetricSet*      metricSet                                               = nullptr;
    uint8_t          platformMaskByteArray[MD_PLATFORM_MASK_BYTE_ARRAY_SIZE] = {};
    TByteArrayLatest platformMask                                            = { MD_PLATFORM_MASK_BYTE_ARRAY_SIZE, platformMaskByteArray };

    MD_CHECK_CC( SetPlatformMask( adapterId, &platformMask, nullptr, false, GENERATION_ACM ) );

    if( metricsDevice->IsPlatformTypeOf( &platformMask, GT_TYPE_GT2 ) )
    {
        MetricSets_ACM_GT2_OA::AddInformationSet( concurrentGroup );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRenderBasicMetricSet>( "RenderBasic", "Render Metrics Basic - aggregation approximation", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CComputeBasicMetricSet>( "ComputeBasic", "Compute Metrics Basic", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CAsyncComputeMetricSet>( "AsyncCompute", "AsyncCompute", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CXveActivity1MetricSet>( "XveActivity1", "XveActivity1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CGpuBusynessMetricSet>( "GpuBusyness", "GpuBusyness", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRenderPipeProfile1MetricSet>( "RenderPipeProfile1", "Render Metrics for 3D Pipeline Profile", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRenderPipeProfile2MetricSet>( "RenderPipeProfile2", "Render Metrics for 3D Pipeline Profile", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRenderPipeProfile3MetricSet>( "RenderPipeProfile3", "Render Metrics for 3D Pipeline Profile", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRenderPipeProfile4MetricSet>( "RenderPipeProfile4", "Render Metrics for 3D Pipeline Profile", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL3_1MetricSet>( "L3_1", "L3_1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL3_2MetricSet>( "L3_2", "L3_2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CSampler_1MetricSet>( "Sampler_1", "Sampler_1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CSampler_2MetricSet>( "Sampler_2", "Sampler_2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CHDCAndSF1MetricSet>( "HDCAndSF1", "Metric set HDCAndSF1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CHDCAndSF2MetricSet>( "HDCAndSF2", "Metric set HDCAndSF2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CHDCAndSF3MetricSet>( "HDCAndSF3", "HDCAndSF3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRasterizerAndPixelBackend1MetricSet>( "RasterizerAndPixelBackend1", "Metric set RasterizerAndPixelBackend1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRasterizerAndPixelBackend2MetricSet>( "RasterizerAndPixelBackend2", "Metric set RasterizerAndPixelBackend2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRasterizerAndPixelBackend3MetricSet>( "RasterizerAndPixelBackend3", "RasterizerAndPixelBackend3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CTDL1MetricSet>( "TDL1", "TDL1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CTDL2MetricSet>( "TDL2", "TDL2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CTDL3MetricSet>( "TDL3", "TDL3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CTDL4MetricSet>( "TDL4", "TDL4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CTDL5MetricSet>( "TDL5", "TDL5", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CTDL6MetricSet>( "TDL6", "TDL6", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CTDL7MetricSet>( "TDL7", "TDL7", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CTDL8MetricSet>( "TDL8", "TDL8", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CTestOaMetricSet>( "TestOa", "Metric set TestOa", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CComputeOverviewMetricSet>( "ComputeOverview", "ComputeOverview", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1ProfileReadsMetricSet_XeCore0>( "L1ProfileReads", "L1ProfileReads", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$GtSlice0XeCore0 $GtSlice1XeCore0 UADD $GtSlice2XeCore0 UADD $GtSlice3XeCore0 UADD $GtSlice4XeCore0 UADD $GtSlice5XeCore0 UADD $GtSlice6XeCore0 UADD $GtSlice7XeCore0 UADD $GtSlice0XeCore3 $GtSlice1XeCore3 UADD $GtSlice2XeCore3 UADD $GtSlice3XeCore3 UADD $GtSlice4XeCore3 UADD $GtSlice5XeCore3 UADD $GtSlice6XeCore3 UADD $GtSlice7XeCore3 UADD UGTE", GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1ProfileReadsMetricSet_XeCore3>( "L1ProfileReads", "L1ProfileReads", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$GtSlice0XeCore0 $GtSlice1XeCore0 UADD $GtSlice2XeCore0 UADD $GtSlice3XeCore0 UADD $GtSlice4XeCore0 UADD $GtSlice5XeCore0 UADD $GtSlice6XeCore0 UADD $GtSlice7XeCore0 UADD $GtSlice0XeCore3 $GtSlice1XeCore3 UADD $GtSlice2XeCore3 UADD $GtSlice3XeCore3 UADD $GtSlice4XeCore3 UADD $GtSlice5XeCore3 UADD $GtSlice6XeCore3 UADD $GtSlice7XeCore3 UADD ULT", GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1ProfileSlmBankConflictsMetricSet_XeCore0>( "L1ProfileSlmBankConflicts", "L1ProfileSlmBankConflicts", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$GtSlice0XeCore0 $GtSlice1XeCore0 UADD $GtSlice2XeCore0 UADD $GtSlice3XeCore0 UADD $GtSlice4XeCore0 UADD $GtSlice5XeCore0 UADD $GtSlice6XeCore0 UADD $GtSlice7XeCore0 UADD $GtSlice0XeCore3 $GtSlice1XeCore3 UADD $GtSlice2XeCore3 UADD $GtSlice3XeCore3 UADD $GtSlice4XeCore3 UADD $GtSlice5XeCore3 UADD $GtSlice6XeCore3 UADD $GtSlice7XeCore3 UADD UGTE", GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1ProfileSlmBankConflictsMetricSet_XeCore3>( "L1ProfileSlmBankConflicts", "L1ProfileSlmBankConflicts", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$GtSlice0XeCore0 $GtSlice1XeCore0 UADD $GtSlice2XeCore0 UADD $GtSlice3XeCore0 UADD $GtSlice4XeCore0 UADD $GtSlice5XeCore0 UADD $GtSlice6XeCore0 UADD $GtSlice7XeCore0 UADD $GtSlice0XeCore3 $GtSlice1XeCore3 UADD $GtSlice2XeCore3 UADD $GtSlice3XeCore3 UADD $GtSlice4XeCore3 UADD $GtSlice5XeCore3 UADD $GtSlice6XeCore3 UADD $GtSlice7XeCore3 UADD ULT", GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1ProfileWritesMetricSet_XeCore0>( "L1ProfileWrites", "L1ProfileWrites", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$GtSlice0XeCore0 $GtSlice1XeCore0 UADD $GtSlice2XeCore0 UADD $GtSlice3XeCore0 UADD $GtSlice4XeCore0 UADD $GtSlice5XeCore0 UADD $GtSlice6XeCore0 UADD $GtSlice7XeCore0 UADD $GtSlice0XeCore3 $GtSlice1XeCore3 UADD $GtSlice2XeCore3 UADD $GtSlice3XeCore3 UADD $GtSlice4XeCore3 UADD $GtSlice5XeCore3 UADD $GtSlice6XeCore3 UADD $GtSlice7XeCore3 UADD UGTE", GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1ProfileWritesMetricSet_XeCore3>( "L1ProfileWrites", "L1ProfileWrites", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$GtSlice0XeCore0 $GtSlice1XeCore0 UADD $GtSlice2XeCore0 UADD $GtSlice3XeCore0 UADD $GtSlice4XeCore0 UADD $GtSlice5XeCore0 UADD $GtSlice6XeCore0 UADD $GtSlice7XeCore0 UADD $GtSlice0XeCore3 $GtSlice1XeCore3 UADD $GtSlice2XeCore3 UADD $GtSlice3XeCore3 UADD $GtSlice4XeCore3 UADD $GtSlice5XeCore3 UADD $GtSlice6XeCore3 UADD $GtSlice7XeCore3 UADD ULT", GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataportReadsMetricSet>( "DataportReads", "DataportReads", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataportWritesMetricSet>( "DataportWrites", "DataportWrites", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CAMFS1MetricSet>( "AMFS1", "AMFS1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CAMFS2MetricSet>( "AMFS2", "AMFS2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CAMFS3MetricSet>( "AMFS3", "AMFS3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CAMFS4MetricSet>( "AMFS4", "AMFS4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CAMFS5MetricSet>( "AMFS5", "AMFS5", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CColorPipe1MetricSet>( "ColorPipe1", "ColorPipe1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CColorPipe2MetricSet>( "ColorPipe2", "ColorPipe2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CColorPipe3MetricSet>( "ColorPipe3", "ColorPipe3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CColorPipe4MetricSet>( "ColorPipe4", "ColorPipe4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CColorPipe5MetricSet>( "ColorPipe5", "ColorPipe5", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CColorPipe6MetricSet>( "ColorPipe6", "ColorPipe6", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CColorPipe7MetricSet>( "ColorPipe7", "ColorPipe7", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CColorPipe8MetricSet>( "ColorPipe8", "ColorPipe8", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CColorPipe9MetricSet>( "ColorPipe9", "ColorPipe9", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CColorPipe10MetricSet>( "ColorPipe10", "ColorPipe10", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CColorPipe11MetricSet>( "ColorPipe11", "ColorPipe11", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CColorPipe12MetricSet>( "ColorPipe12", "ColorPipe12", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CColorPipe13MetricSet>( "ColorPipe13", "ColorPipe13", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CColorPipe14MetricSet>( "ColorPipe14", "ColorPipe14", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CColorPipe15MetricSet>( "ColorPipe15", "ColorPipe15", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CColorPipe16MetricSet>( "ColorPipe16", "ColorPipe16", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CColorPipe17MetricSet>( "ColorPipe17", "ColorPipe17", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport1MetricSet>( "Dataport1", "Dataport1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport2MetricSet>( "Dataport2", "Dataport2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport3MetricSet>( "Dataport3", "Dataport3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport4MetricSet>( "Dataport4", "Dataport4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport5MetricSet>( "Dataport5", "Dataport5", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport6MetricSet>( "Dataport6", "Dataport6", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport7MetricSet>( "Dataport7", "Dataport7", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport8MetricSet>( "Dataport8", "Dataport8", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport9MetricSet>( "Dataport9", "Dataport9", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport10MetricSet>( "Dataport10", "Dataport10", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport11MetricSet>( "Dataport11", "Dataport11", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport12MetricSet>( "Dataport12", "Dataport12", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport13MetricSet>( "Dataport13", "Dataport13", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport14MetricSet>( "Dataport14", "Dataport14", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport15MetricSet>( "Dataport15", "Dataport15", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport16MetricSet>( "Dataport16", "Dataport16", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport17MetricSet>( "Dataport17", "Dataport17", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport18MetricSet>( "Dataport18", "Dataport18", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport19MetricSet>( "Dataport19", "Dataport19", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport20MetricSet>( "Dataport20", "Dataport20", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport21MetricSet>( "Dataport21", "Dataport21", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport22MetricSet>( "Dataport22", "Dataport22", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport23MetricSet>( "Dataport23", "Dataport23", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport24MetricSet>( "Dataport24", "Dataport24", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport25MetricSet>( "Dataport25", "Dataport25", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport26MetricSet>( "Dataport26", "Dataport26", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport27MetricSet>( "Dataport27", "Dataport27", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport28MetricSet>( "Dataport28", "Dataport28", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport29MetricSet>( "Dataport29", "Dataport29", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport30MetricSet>( "Dataport30", "Dataport30", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport31MetricSet>( "Dataport31", "Dataport31", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport32MetricSet>( "Dataport32", "Dataport32", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport33MetricSet>( "Dataport33", "Dataport33", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport34MetricSet>( "Dataport34", "Dataport34", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport35MetricSet>( "Dataport35", "Dataport35", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport36MetricSet>( "Dataport36", "Dataport36", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport37MetricSet>( "Dataport37", "Dataport37", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport38MetricSet>( "Dataport38", "Dataport38", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport39MetricSet>( "Dataport39", "Dataport39", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport40MetricSet>( "Dataport40", "Dataport40", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDataport41MetricSet>( "Dataport41", "Dataport41", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe1MetricSet>( "DepthPipe1", "DepthPipe1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe2MetricSet>( "DepthPipe2", "DepthPipe2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe3MetricSet>( "DepthPipe3", "DepthPipe3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe4MetricSet>( "DepthPipe4", "DepthPipe4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe5MetricSet>( "DepthPipe5", "DepthPipe5", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe6MetricSet>( "DepthPipe6", "DepthPipe6", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe7MetricSet>( "DepthPipe7", "DepthPipe7", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe8MetricSet>( "DepthPipe8", "DepthPipe8", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe9MetricSet>( "DepthPipe9", "DepthPipe9", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe10MetricSet>( "DepthPipe10", "DepthPipe10", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe11MetricSet>( "DepthPipe11", "DepthPipe11", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe12MetricSet>( "DepthPipe12", "DepthPipe12", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe13MetricSet>( "DepthPipe13", "DepthPipe13", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe14MetricSet>( "DepthPipe14", "DepthPipe14", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe15MetricSet>( "DepthPipe15", "DepthPipe15", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe16MetricSet>( "DepthPipe16", "DepthPipe16", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe17MetricSet>( "DepthPipe17", "DepthPipe17", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe18MetricSet>( "DepthPipe18", "DepthPipe18", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe19MetricSet>( "DepthPipe19", "DepthPipe19", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe20MetricSet>( "DepthPipe20", "DepthPipe20", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe21MetricSet>( "DepthPipe21", "DepthPipe21", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe22MetricSet>( "DepthPipe22", "DepthPipe22", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe23MetricSet>( "DepthPipe23", "DepthPipe23", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe24MetricSet>( "DepthPipe24", "DepthPipe24", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe25MetricSet>( "DepthPipe25", "DepthPipe25", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe26MetricSet>( "DepthPipe26", "DepthPipe26", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe27MetricSet>( "DepthPipe27", "DepthPipe27", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe28MetricSet>( "DepthPipe28", "DepthPipe28", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe29MetricSet>( "DepthPipe29", "DepthPipe29", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe30MetricSet>( "DepthPipe30", "DepthPipe30", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe31MetricSet>( "DepthPipe31", "DepthPipe31", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe32MetricSet>( "DepthPipe32", "DepthPipe32", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe33MetricSet>( "DepthPipe33", "DepthPipe33", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe34MetricSet>( "DepthPipe34", "DepthPipe34", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe35MetricSet>( "DepthPipe35", "DepthPipe35", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe36MetricSet>( "DepthPipe36", "DepthPipe36", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe37MetricSet>( "DepthPipe37", "DepthPipe37", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe38MetricSet>( "DepthPipe38", "DepthPipe38", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe39MetricSet>( "DepthPipe39", "DepthPipe39", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe40MetricSet>( "DepthPipe40", "DepthPipe40", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe41MetricSet>( "DepthPipe41", "DepthPipe41", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe42MetricSet>( "DepthPipe42", "DepthPipe42", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe43MetricSet>( "DepthPipe43", "DepthPipe43", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe44MetricSet>( "DepthPipe44", "DepthPipe44", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe45MetricSet>( "DepthPipe45", "DepthPipe45", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe46MetricSet>( "DepthPipe46", "DepthPipe46", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe47MetricSet>( "DepthPipe47", "DepthPipe47", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe48MetricSet>( "DepthPipe48", "DepthPipe48", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe49MetricSet>( "DepthPipe49", "DepthPipe49", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CDepthPipe50MetricSet>( "DepthPipe50", "DepthPipe50", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CFrontEnd1MetricSet>( "FrontEnd1", "FrontEnd1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CGeometry1MetricSet>( "Geometry1", "Geometry1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CGeometry2MetricSet>( "Geometry2", "Geometry2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CGeometry3MetricSet>( "Geometry3", "Geometry3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CGeometry4MetricSet>( "Geometry4", "Geometry4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CGeometry5MetricSet>( "Geometry5", "Geometry5", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache1MetricSet>( "L1Cache1", "L1Cache1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache2MetricSet>( "L1Cache2", "L1Cache2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache3MetricSet>( "L1Cache3", "L1Cache3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache4MetricSet>( "L1Cache4", "L1Cache4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache5MetricSet>( "L1Cache5", "L1Cache5", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache6MetricSet>( "L1Cache6", "L1Cache6", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache7MetricSet>( "L1Cache7", "L1Cache7", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache8MetricSet>( "L1Cache8", "L1Cache8", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache9MetricSet>( "L1Cache9", "L1Cache9", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache10MetricSet>( "L1Cache10", "L1Cache10", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache11MetricSet>( "L1Cache11", "L1Cache11", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache12MetricSet>( "L1Cache12", "L1Cache12", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache13MetricSet>( "L1Cache13", "L1Cache13", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache14MetricSet>( "L1Cache14", "L1Cache14", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache15MetricSet>( "L1Cache15", "L1Cache15", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache16MetricSet>( "L1Cache16", "L1Cache16", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache17MetricSet>( "L1Cache17", "L1Cache17", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache18MetricSet>( "L1Cache18", "L1Cache18", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache19MetricSet>( "L1Cache19", "L1Cache19", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache20MetricSet>( "L1Cache20", "L1Cache20", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache21MetricSet>( "L1Cache21", "L1Cache21", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache22MetricSet>( "L1Cache22", "L1Cache22", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache23MetricSet>( "L1Cache23", "L1Cache23", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache24MetricSet>( "L1Cache24", "L1Cache24", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache25MetricSet>( "L1Cache25", "L1Cache25", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache26MetricSet>( "L1Cache26", "L1Cache26", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache27MetricSet>( "L1Cache27", "L1Cache27", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache28MetricSet>( "L1Cache28", "L1Cache28", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache29MetricSet>( "L1Cache29", "L1Cache29", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache30MetricSet>( "L1Cache30", "L1Cache30", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache31MetricSet>( "L1Cache31", "L1Cache31", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache32MetricSet>( "L1Cache32", "L1Cache32", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache33MetricSet>( "L1Cache33", "L1Cache33", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache34MetricSet>( "L1Cache34", "L1Cache34", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache35MetricSet>( "L1Cache35", "L1Cache35", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache36MetricSet>( "L1Cache36", "L1Cache36", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache37MetricSet>( "L1Cache37", "L1Cache37", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache38MetricSet>( "L1Cache38", "L1Cache38", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache39MetricSet>( "L1Cache39", "L1Cache39", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache40MetricSet>( "L1Cache40", "L1Cache40", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache41MetricSet>( "L1Cache41", "L1Cache41", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache42MetricSet>( "L1Cache42", "L1Cache42", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache43MetricSet>( "L1Cache43", "L1Cache43", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache44MetricSet>( "L1Cache44", "L1Cache44", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache45MetricSet>( "L1Cache45", "L1Cache45", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache46MetricSet>( "L1Cache46", "L1Cache46", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache47MetricSet>( "L1Cache47", "L1Cache47", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache48MetricSet>( "L1Cache48", "L1Cache48", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache49MetricSet>( "L1Cache49", "L1Cache49", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache50MetricSet>( "L1Cache50", "L1Cache50", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache51MetricSet>( "L1Cache51", "L1Cache51", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache52MetricSet>( "L1Cache52", "L1Cache52", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache53MetricSet>( "L1Cache53", "L1Cache53", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache54MetricSet>( "L1Cache54", "L1Cache54", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache55MetricSet>( "L1Cache55", "L1Cache55", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache56MetricSet>( "L1Cache56", "L1Cache56", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache57MetricSet>( "L1Cache57", "L1Cache57", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache58MetricSet>( "L1Cache58", "L1Cache58", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache59MetricSet>( "L1Cache59", "L1Cache59", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache60MetricSet>( "L1Cache60", "L1Cache60", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache61MetricSet>( "L1Cache61", "L1Cache61", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache62MetricSet>( "L1Cache62", "L1Cache62", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache63MetricSet>( "L1Cache63", "L1Cache63", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache64MetricSet>( "L1Cache64", "L1Cache64", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache65MetricSet>( "L1Cache65", "L1Cache65", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache66MetricSet>( "L1Cache66", "L1Cache66", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache67MetricSet>( "L1Cache67", "L1Cache67", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache68MetricSet>( "L1Cache68", "L1Cache68", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache69MetricSet>( "L1Cache69", "L1Cache69", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache70MetricSet>( "L1Cache70", "L1Cache70", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache71MetricSet>( "L1Cache71", "L1Cache71", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache72MetricSet>( "L1Cache72", "L1Cache72", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache73MetricSet>( "L1Cache73", "L1Cache73", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache74MetricSet>( "L1Cache74", "L1Cache74", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache75MetricSet>( "L1Cache75", "L1Cache75", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache76MetricSet>( "L1Cache76", "L1Cache76", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache77MetricSet>( "L1Cache77", "L1Cache77", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache78MetricSet>( "L1Cache78", "L1Cache78", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache79MetricSet>( "L1Cache79", "L1Cache79", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache80MetricSet>( "L1Cache80", "L1Cache80", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache81MetricSet>( "L1Cache81", "L1Cache81", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache82MetricSet>( "L1Cache82", "L1Cache82", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache83MetricSet>( "L1Cache83", "L1Cache83", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache84MetricSet>( "L1Cache84", "L1Cache84", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache85MetricSet>( "L1Cache85", "L1Cache85", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache86MetricSet>( "L1Cache86", "L1Cache86", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache87MetricSet>( "L1Cache87", "L1Cache87", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache88MetricSet>( "L1Cache88", "L1Cache88", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache89MetricSet>( "L1Cache89", "L1Cache89", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache90MetricSet>( "L1Cache90", "L1Cache90", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache91MetricSet>( "L1Cache91", "L1Cache91", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache92MetricSet>( "L1Cache92", "L1Cache92", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache93MetricSet>( "L1Cache93", "L1Cache93", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache94MetricSet>( "L1Cache94", "L1Cache94", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache95MetricSet>( "L1Cache95", "L1Cache95", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache96MetricSet>( "L1Cache96", "L1Cache96", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache97MetricSet>( "L1Cache97", "L1Cache97", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache98MetricSet>( "L1Cache98", "L1Cache98", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache99MetricSet>( "L1Cache99", "L1Cache99", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache100MetricSet>( "L1Cache100", "L1Cache100", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache101MetricSet>( "L1Cache101", "L1Cache101", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache102MetricSet>( "L1Cache102", "L1Cache102", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache103MetricSet>( "L1Cache103", "L1Cache103", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache104MetricSet>( "L1Cache104", "L1Cache104", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache105MetricSet>( "L1Cache105", "L1Cache105", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache106MetricSet>( "L1Cache106", "L1Cache106", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache107MetricSet>( "L1Cache107", "L1Cache107", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache108MetricSet>( "L1Cache108", "L1Cache108", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache109MetricSet>( "L1Cache109", "L1Cache109", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache110MetricSet>( "L1Cache110", "L1Cache110", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache111MetricSet>( "L1Cache111", "L1Cache111", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache112MetricSet>( "L1Cache112", "L1Cache112", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache113MetricSet>( "L1Cache113", "L1Cache113", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache114MetricSet>( "L1Cache114", "L1Cache114", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache115MetricSet>( "L1Cache115", "L1Cache115", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache116MetricSet>( "L1Cache116", "L1Cache116", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache117MetricSet>( "L1Cache117", "L1Cache117", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache118MetricSet>( "L1Cache118", "L1Cache118", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache119MetricSet>( "L1Cache119", "L1Cache119", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache120MetricSet>( "L1Cache120", "L1Cache120", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache121MetricSet>( "L1Cache121", "L1Cache121", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache122MetricSet>( "L1Cache122", "L1Cache122", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache123MetricSet>( "L1Cache123", "L1Cache123", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache124MetricSet>( "L1Cache124", "L1Cache124", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache125MetricSet>( "L1Cache125", "L1Cache125", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache126MetricSet>( "L1Cache126", "L1Cache126", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache127MetricSet>( "L1Cache127", "L1Cache127", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache128MetricSet>( "L1Cache128", "L1Cache128", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache129MetricSet>( "L1Cache129", "L1Cache129", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache130MetricSet>( "L1Cache130", "L1Cache130", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache131MetricSet>( "L1Cache131", "L1Cache131", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache132MetricSet>( "L1Cache132", "L1Cache132", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache133MetricSet>( "L1Cache133", "L1Cache133", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache134MetricSet>( "L1Cache134", "L1Cache134", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache135MetricSet>( "L1Cache135", "L1Cache135", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache136MetricSet>( "L1Cache136", "L1Cache136", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache137MetricSet>( "L1Cache137", "L1Cache137", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache138MetricSet>( "L1Cache138", "L1Cache138", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache139MetricSet>( "L1Cache139", "L1Cache139", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache140MetricSet>( "L1Cache140", "L1Cache140", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache141MetricSet>( "L1Cache141", "L1Cache141", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache142MetricSet>( "L1Cache142", "L1Cache142", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache143MetricSet>( "L1Cache143", "L1Cache143", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache144MetricSet>( "L1Cache144", "L1Cache144", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache145MetricSet>( "L1Cache145", "L1Cache145", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache146MetricSet>( "L1Cache146", "L1Cache146", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache147MetricSet>( "L1Cache147", "L1Cache147", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache148MetricSet>( "L1Cache148", "L1Cache148", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache149MetricSet>( "L1Cache149", "L1Cache149", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache150MetricSet>( "L1Cache150", "L1Cache150", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache151MetricSet>( "L1Cache151", "L1Cache151", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache152MetricSet>( "L1Cache152", "L1Cache152", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache153MetricSet>( "L1Cache153", "L1Cache153", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache154MetricSet>( "L1Cache154", "L1Cache154", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache155MetricSet>( "L1Cache155", "L1Cache155", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL1Cache156MetricSet>( "L1Cache156", "L1Cache156", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL3Cache1MetricSet>( "L3Cache1", "L3Cache1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL3Cache2MetricSet>( "L3Cache2", "L3Cache2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL3Cache3MetricSet>( "L3Cache3", "L3Cache3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL3Cache4MetricSet>( "L3Cache4", "L3Cache4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL3Cache5MetricSet>( "L3Cache5", "L3Cache5", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL3Cache6MetricSet>( "L3Cache6", "L3Cache6", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL3Cache7MetricSet>( "L3Cache7", "L3Cache7", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL3Cache8MetricSet>( "L3Cache8", "L3Cache8", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL3Cache9MetricSet>( "L3Cache9", "L3Cache9", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL3Cache10MetricSet>( "L3Cache10", "L3Cache10", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL3Cache11MetricSet>( "L3Cache11", "L3Cache11", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL3Cache12MetricSet>( "L3Cache12", "L3Cache12", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL3Cache13MetricSet>( "L3Cache13", "L3Cache13", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL3Cache14MetricSet>( "L3Cache14", "L3Cache14", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL3Cache15MetricSet>( "L3Cache15", "L3Cache15", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL3Cache16MetricSet>( "L3Cache16", "L3Cache16", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL3Cache17MetricSet>( "L3Cache17", "L3Cache17", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL3Cache18MetricSet>( "L3Cache18", "L3Cache18", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL3Cache19MetricSet>( "L3Cache19", "L3Cache19", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL3Cache20MetricSet>( "L3Cache20", "L3Cache20", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL3Cache21MetricSet>( "L3Cache21", "L3Cache21", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CL3Cache22MetricSet>( "L3Cache22", "L3Cache22", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CMemory1MetricSet>( "Memory1", "Memory1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CMemory2MetricSet>( "Memory2", "Memory2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CMemory3MetricSet>( "Memory3", "Memory3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CMemory4MetricSet>( "Memory4", "Memory4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CMemory5MetricSet>( "Memory5", "Memory5", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CMemory6MetricSet>( "Memory6", "Memory6", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CMemory7MetricSet>( "Memory7", "Memory7", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CMemory8MetricSet>( "Memory8", "Memory8", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CMemory9MetricSet>( "Memory9", "Memory9", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CMemory10MetricSet>( "Memory10", "Memory10", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CMemory11MetricSet>( "Memory11", "Memory11", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CMemory12MetricSet>( "Memory12", "Memory12", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CMemory13MetricSet>( "Memory13", "Memory13", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CMemory14MetricSet>( "Memory14", "Memory14", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRasterizer1MetricSet>( "Rasterizer1", "Rasterizer1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRasterizer2MetricSet>( "Rasterizer2", "Rasterizer2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing1MetricSet>( "RayTracing1", "RayTracing1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing2MetricSet>( "RayTracing2", "RayTracing2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing3MetricSet>( "RayTracing3", "RayTracing3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing4MetricSet>( "RayTracing4", "RayTracing4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing5MetricSet>( "RayTracing5", "RayTracing5", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing6MetricSet>( "RayTracing6", "RayTracing6", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing7MetricSet>( "RayTracing7", "RayTracing7", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing8MetricSet>( "RayTracing8", "RayTracing8", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing9MetricSet>( "RayTracing9", "RayTracing9", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing10MetricSet>( "RayTracing10", "RayTracing10", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing11MetricSet>( "RayTracing11", "RayTracing11", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing12MetricSet>( "RayTracing12", "RayTracing12", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing13MetricSet>( "RayTracing13", "RayTracing13", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing14MetricSet>( "RayTracing14", "RayTracing14", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing15MetricSet>( "RayTracing15", "RayTracing15", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing16MetricSet>( "RayTracing16", "RayTracing16", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing17MetricSet>( "RayTracing17", "RayTracing17", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing18MetricSet>( "RayTracing18", "RayTracing18", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing19MetricSet>( "RayTracing19", "RayTracing19", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing20MetricSet>( "RayTracing20", "RayTracing20", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing21MetricSet>( "RayTracing21", "RayTracing21", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing22MetricSet>( "RayTracing22", "RayTracing22", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing23MetricSet>( "RayTracing23", "RayTracing23", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing24MetricSet>( "RayTracing24", "RayTracing24", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing25MetricSet>( "RayTracing25", "RayTracing25", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing26MetricSet>( "RayTracing26", "RayTracing26", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing27MetricSet>( "RayTracing27", "RayTracing27", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing28MetricSet>( "RayTracing28", "RayTracing28", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing29MetricSet>( "RayTracing29", "RayTracing29", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing30MetricSet>( "RayTracing30", "RayTracing30", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing31MetricSet>( "RayTracing31", "RayTracing31", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing32MetricSet>( "RayTracing32", "RayTracing32", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing33MetricSet>( "RayTracing33", "RayTracing33", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing34MetricSet>( "RayTracing34", "RayTracing34", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing35MetricSet>( "RayTracing35", "RayTracing35", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing36MetricSet>( "RayTracing36", "RayTracing36", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing37MetricSet>( "RayTracing37", "RayTracing37", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing38MetricSet>( "RayTracing38", "RayTracing38", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing39MetricSet>( "RayTracing39", "RayTracing39", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing40MetricSet>( "RayTracing40", "RayTracing40", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing41MetricSet>( "RayTracing41", "RayTracing41", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing42MetricSet>( "RayTracing42", "RayTracing42", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing43MetricSet>( "RayTracing43", "RayTracing43", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing44MetricSet>( "RayTracing44", "RayTracing44", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing45MetricSet>( "RayTracing45", "RayTracing45", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing46MetricSet>( "RayTracing46", "RayTracing46", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing47MetricSet>( "RayTracing47", "RayTracing47", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing48MetricSet>( "RayTracing48", "RayTracing48", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing49MetricSet>( "RayTracing49", "RayTracing49", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing50MetricSet>( "RayTracing50", "RayTracing50", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing51MetricSet>( "RayTracing51", "RayTracing51", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing52MetricSet>( "RayTracing52", "RayTracing52", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing53MetricSet>( "RayTracing53", "RayTracing53", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing54MetricSet>( "RayTracing54", "RayTracing54", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing55MetricSet>( "RayTracing55", "RayTracing55", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing56MetricSet>( "RayTracing56", "RayTracing56", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing57MetricSet>( "RayTracing57", "RayTracing57", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing58MetricSet>( "RayTracing58", "RayTracing58", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing59MetricSet>( "RayTracing59", "RayTracing59", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing60MetricSet>( "RayTracing60", "RayTracing60", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing61MetricSet>( "RayTracing61", "RayTracing61", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing62MetricSet>( "RayTracing62", "RayTracing62", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing63MetricSet>( "RayTracing63", "RayTracing63", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing64MetricSet>( "RayTracing64", "RayTracing64", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing65MetricSet>( "RayTracing65", "RayTracing65", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing66MetricSet>( "RayTracing66", "RayTracing66", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing67MetricSet>( "RayTracing67", "RayTracing67", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing68MetricSet>( "RayTracing68", "RayTracing68", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing69MetricSet>( "RayTracing69", "RayTracing69", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing70MetricSet>( "RayTracing70", "RayTracing70", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing71MetricSet>( "RayTracing71", "RayTracing71", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing72MetricSet>( "RayTracing72", "RayTracing72", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing73MetricSet>( "RayTracing73", "RayTracing73", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing74MetricSet>( "RayTracing74", "RayTracing74", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing75MetricSet>( "RayTracing75", "RayTracing75", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing76MetricSet>( "RayTracing76", "RayTracing76", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing77MetricSet>( "RayTracing77", "RayTracing77", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CRayTracing78MetricSet>( "RayTracing78", "RayTracing78", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CSampler1MetricSet>( "Sampler1", "Sampler1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CSampler2MetricSet>( "Sampler2", "Sampler2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CSampler3MetricSet>( "Sampler3", "Sampler3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CSampler4MetricSet>( "Sampler4", "Sampler4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CSampler5MetricSet>( "Sampler5", "Sampler5", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CSampler6MetricSet>( "Sampler6", "Sampler6", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CSampler7MetricSet>( "Sampler7", "Sampler7", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CSampler8MetricSet>( "Sampler8", "Sampler8", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CSampler9MetricSet>( "Sampler9", "Sampler9", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CSampler10MetricSet>( "Sampler10", "Sampler10", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CSampler11MetricSet>( "Sampler11", "Sampler11", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher1MetricSet>( "ThreadDispatcher1", "ThreadDispatcher1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher2MetricSet>( "ThreadDispatcher2", "ThreadDispatcher2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher3MetricSet>( "ThreadDispatcher3", "ThreadDispatcher3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher4MetricSet>( "ThreadDispatcher4", "ThreadDispatcher4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher5MetricSet>( "ThreadDispatcher5", "ThreadDispatcher5", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher6MetricSet>( "ThreadDispatcher6", "ThreadDispatcher6", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher7MetricSet>( "ThreadDispatcher7", "ThreadDispatcher7", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher8MetricSet>( "ThreadDispatcher8", "ThreadDispatcher8", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher9MetricSet>( "ThreadDispatcher9", "ThreadDispatcher9", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher10MetricSet>( "ThreadDispatcher10", "ThreadDispatcher10", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher11MetricSet>( "ThreadDispatcher11", "ThreadDispatcher11", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher12MetricSet>( "ThreadDispatcher12", "ThreadDispatcher12", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher13MetricSet>( "ThreadDispatcher13", "ThreadDispatcher13", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher14MetricSet>( "ThreadDispatcher14", "ThreadDispatcher14", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher15MetricSet>( "ThreadDispatcher15", "ThreadDispatcher15", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher16MetricSet>( "ThreadDispatcher16", "ThreadDispatcher16", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher17MetricSet>( "ThreadDispatcher17", "ThreadDispatcher17", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher18MetricSet>( "ThreadDispatcher18", "ThreadDispatcher18", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher19MetricSet>( "ThreadDispatcher19", "ThreadDispatcher19", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher20MetricSet>( "ThreadDispatcher20", "ThreadDispatcher20", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher21MetricSet>( "ThreadDispatcher21", "ThreadDispatcher21", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher22MetricSet>( "ThreadDispatcher22", "ThreadDispatcher22", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher23MetricSet>( "ThreadDispatcher23", "ThreadDispatcher23", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher24MetricSet>( "ThreadDispatcher24", "ThreadDispatcher24", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher25MetricSet>( "ThreadDispatcher25", "ThreadDispatcher25", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher26MetricSet>( "ThreadDispatcher26", "ThreadDispatcher26", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher27MetricSet>( "ThreadDispatcher27", "ThreadDispatcher27", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher28MetricSet>( "ThreadDispatcher28", "ThreadDispatcher28", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher29MetricSet>( "ThreadDispatcher29", "ThreadDispatcher29", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher30MetricSet>( "ThreadDispatcher30", "ThreadDispatcher30", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher31MetricSet>( "ThreadDispatcher31", "ThreadDispatcher31", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher32MetricSet>( "ThreadDispatcher32", "ThreadDispatcher32", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher33MetricSet>( "ThreadDispatcher33", "ThreadDispatcher33", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher34MetricSet>( "ThreadDispatcher34", "ThreadDispatcher34", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher35MetricSet>( "ThreadDispatcher35", "ThreadDispatcher35", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher36MetricSet>( "ThreadDispatcher36", "ThreadDispatcher36", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher37MetricSet>( "ThreadDispatcher37", "ThreadDispatcher37", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher38MetricSet>( "ThreadDispatcher38", "ThreadDispatcher38", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher39MetricSet>( "ThreadDispatcher39", "ThreadDispatcher39", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher40MetricSet>( "ThreadDispatcher40", "ThreadDispatcher40", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher41MetricSet>( "ThreadDispatcher41", "ThreadDispatcher41", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher42MetricSet>( "ThreadDispatcher42", "ThreadDispatcher42", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher43MetricSet>( "ThreadDispatcher43", "ThreadDispatcher43", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher44MetricSet>( "ThreadDispatcher44", "ThreadDispatcher44", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher45MetricSet>( "ThreadDispatcher45", "ThreadDispatcher45", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CThreadDispatcher46MetricSet>( "ThreadDispatcher46", "ThreadDispatcher46", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CURB1MetricSet>( "URB1", "URB1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CURB2MetricSet>( "URB2", "URB2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CURB3MetricSet>( "URB3", "URB3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CURB4MetricSet>( "URB4", "URB4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine1MetricSet>( "VectorEngine1", "VectorEngine1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine2MetricSet>( "VectorEngine2", "VectorEngine2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine3MetricSet>( "VectorEngine3", "VectorEngine3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine4MetricSet>( "VectorEngine4", "VectorEngine4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine5MetricSet>( "VectorEngine5", "VectorEngine5", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine6MetricSet>( "VectorEngine6", "VectorEngine6", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine7MetricSet>( "VectorEngine7", "VectorEngine7", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine8MetricSet>( "VectorEngine8", "VectorEngine8", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine9MetricSet>( "VectorEngine9", "VectorEngine9", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine10MetricSet>( "VectorEngine10", "VectorEngine10", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine11MetricSet>( "VectorEngine11", "VectorEngine11", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine12MetricSet>( "VectorEngine12", "VectorEngine12", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine13MetricSet>( "VectorEngine13", "VectorEngine13", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine14MetricSet>( "VectorEngine14", "VectorEngine14", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine15MetricSet>( "VectorEngine15", "VectorEngine15", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine16MetricSet>( "VectorEngine16", "VectorEngine16", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine17MetricSet>( "VectorEngine17", "VectorEngine17", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine18MetricSet>( "VectorEngine18", "VectorEngine18", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine19MetricSet>( "VectorEngine19", "VectorEngine19", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine20MetricSet>( "VectorEngine20", "VectorEngine20", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine21MetricSet>( "VectorEngine21", "VectorEngine21", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine22MetricSet>( "VectorEngine22", "VectorEngine22", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine23MetricSet>( "VectorEngine23", "VectorEngine23", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine24MetricSet>( "VectorEngine24", "VectorEngine24", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine25MetricSet>( "VectorEngine25", "VectorEngine25", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine26MetricSet>( "VectorEngine26", "VectorEngine26", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine27MetricSet>( "VectorEngine27", "VectorEngine27", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine28MetricSet>( "VectorEngine28", "VectorEngine28", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine29MetricSet>( "VectorEngine29", "VectorEngine29", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine30MetricSet>( "VectorEngine30", "VectorEngine30", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine31MetricSet>( "VectorEngine31", "VectorEngine31", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine32MetricSet>( "VectorEngine32", "VectorEngine32", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine33MetricSet>( "VectorEngine33", "VectorEngine33", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine34MetricSet>( "VectorEngine34", "VectorEngine34", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine35MetricSet>( "VectorEngine35", "VectorEngine35", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine36MetricSet>( "VectorEngine36", "VectorEngine36", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine37MetricSet>( "VectorEngine37", "VectorEngine37", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine38MetricSet>( "VectorEngine38", "VectorEngine38", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine39MetricSet>( "VectorEngine39", "VectorEngine39", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine40MetricSet>( "VectorEngine40", "VectorEngine40", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT2_OA::CVectorEngine41MetricSet>( "VectorEngine41", "VectorEngine41", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );
    }

    MD_LOG_EXIT_A( adapterId );
    return CC_OK;

exception:
    MD_LOG_EXIT_A( adapterId );
    return CC_ERROR_NO_MEMORY;
}
#endif
