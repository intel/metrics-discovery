/*========================== begin_copyright_notice ============================

Copyright (C) 2022-2024 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_metrics_ACM_GT3.cpp

//     Abstract:   C++ automated generated file to stack metrics meta data

#include "md_per_platform_preamble.h"
#include "md_metric_sets_ACM_GT3.h"

using namespace MetricsDiscoveryInternal;

#if( ( !defined( MD_INCLUDE_ACM_GT3_METRICS ) && MD_INCLUDE_ALL_METRICS ) || MD_INCLUDE_ACM_GT3_METRICS )

TCompletionCode CreateMetricTreeACM_GT3_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup )
{
    const uint32_t adapterId = OBTAIN_ADAPTER_ID( metricsDevice );

    MD_LOG_ENTER_A( adapterId );
    MD_CHECK_PTR_RET_A( adapterId, metricsDevice, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET_A( adapterId, concurrentGroup, CC_ERROR_INVALID_PARAMETER );

    CMetricSet*      metricSet                                               = nullptr;
    uint8_t          platformMaskByteArray[MD_PLATFORM_MASK_BYTE_ARRAY_SIZE] = {};
    TByteArrayLatest platformMask                                            = { MD_PLATFORM_MASK_BYTE_ARRAY_SIZE, platformMaskByteArray };

    MD_CHECK_CC( SetPlatformMask( adapterId, &platformMask, nullptr, false, GENERATION_ACM ) );

    if( metricsDevice->IsPlatformTypeOf( &platformMask, GT_TYPE_GT3 ) )
    {
        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_PipelineStatistics::CPipelineStatsMetricSet>( "PipelineStats", "Pipeline Statistics for OGL4", API_TYPE_OGL | API_TYPE_OGL4_X,
            GPU_RENDER | GPU_COMPUTE, 0, 96, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );
    }

    MD_LOG_EXIT_A( adapterId );
    return CC_OK;

exception:
    MD_LOG_EXIT_A( adapterId );
    return CC_ERROR_NO_MEMORY;
}
#endif

#if( ( !defined( MD_INCLUDE_ACM_GT3_METRICS ) && MD_INCLUDE_ALL_METRICS ) || MD_INCLUDE_ACM_GT3_METRICS )

TCompletionCode CreateMetricTreeACM_GT3_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup )
{
    const uint32_t adapterId = OBTAIN_ADAPTER_ID( metricsDevice );

    MD_LOG_ENTER_A( adapterId );
    MD_CHECK_PTR_RET_A( adapterId, metricsDevice, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET_A( adapterId, concurrentGroup, CC_ERROR_INVALID_PARAMETER );

    CMetricSet*      metricSet                                               = nullptr;
    uint8_t          platformMaskByteArray[MD_PLATFORM_MASK_BYTE_ARRAY_SIZE] = {};
    TByteArrayLatest platformMask                                            = { MD_PLATFORM_MASK_BYTE_ARRAY_SIZE, platformMaskByteArray };

    MD_CHECK_CC( SetPlatformMask( adapterId, &platformMask, nullptr, false, GENERATION_ACM ) );

    if( metricsDevice->IsPlatformTypeOf( &platformMask, GT_TYPE_GT3 ) )
    {
        MetricSets_ACM_GT3_OA::AddInformationSet( concurrentGroup );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CRenderBasicMetricSet>( "RenderBasic", "Render Metrics Basic", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CComputeBasicMetricSet>( "ComputeBasic", "Compute Metrics Basic", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CAsyncComputeMetricSet>( "AsyncCompute", "AsyncCompute", API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_VULKAN | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CXveActivity1MetricSet>( "XveActivity1", "XveActivity1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CGpuBusynessMetricSet>( "GpuBusyness", "GpuBusyness", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CTestOaMetricSet>( "TestOa", "Metric set TestOa", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CHDCAndSF_Slice01MetricSet>( "HDCAndSF_Slice01", "Metric set HDCAndSF for Slice01", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CHDCAndSF_Slice23MetricSet>( "HDCAndSF_Slice23", "Metric set HDCAndSF for Slice23", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CHDCAndSF_Slice45MetricSet>( "HDCAndSF_Slice45", "Metric set HDCAndSF for Slice45", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CHDCAndSF_Slice67MetricSet>( "HDCAndSF_Slice67", "Metric set HDCAndSF for Slice67", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CHDCAndSF1MetricSet>( "HDCAndSF1", "Metric set HDCAndSF1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CL3_Slice01MetricSet>( "L3_Slice01", "L3_Slice01", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CL3_Slice23MetricSet>( "L3_Slice23", "L3_Slice23", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CL3_Slice45MetricSet>( "L3_Slice45", "L3_Slice45", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CL3_Slice67MetricSet>( "L3_Slice67", "L3_Slice67", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CRasterizerAndPixelBackend1MetricSet>( "RasterizerAndPixelBackend1", "Metric set RasterizerAndPixelBackend1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CRasterizerAndPixelBackend2MetricSet>( "RasterizerAndPixelBackend2", "Metric set RasterizerAndPixelBackend2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CRasterizerAndPixelBackend3MetricSet>( "RasterizerAndPixelBackend3", "Metric set RasterizerAndPixelBackend3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CRasterizerAndPixelBackend4MetricSet>( "RasterizerAndPixelBackend4", "Metric set RasterizerAndPixelBackend4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CRasterizerAndPixelBackend5MetricSet>( "RasterizerAndPixelBackend5", "RasterizerAndPixelBackend5", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CRenderPipeProfile_Slice0MetricSet>( "RenderPipeProfile_Slice0", "Render Metrics for 3D Pipeline Profile", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CRenderPipeProfile_Slice1MetricSet>( "RenderPipeProfile_Slice1", "Render Metrics for 3D Pipeline Profile", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CRenderPipeProfile_Slice2MetricSet>( "RenderPipeProfile_Slice2", "Render Metrics for 3D Pipeline Profile", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CRenderPipeProfile_Slice3MetricSet>( "RenderPipeProfile_Slice3", "Render Metrics for 3D Pipeline Profile", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CRenderPipeProfile_Slice4MetricSet>( "RenderPipeProfile_Slice4", "Render Metrics for 3D Pipeline Profile", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CRenderPipeProfile_Slice5MetricSet>( "RenderPipeProfile_Slice5", "Render Metrics for 3D Pipeline Profile", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CRenderPipeProfile_Slice6MetricSet>( "RenderPipeProfile_Slice6", "Render Metrics for 3D Pipeline Profile", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CRenderPipeProfile_Slice7MetricSet>( "RenderPipeProfile_Slice7", "Render Metrics for 3D Pipeline Profile", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CSampler_Slice01MetricSet>( "Sampler_Slice01", "Sampler_Slice01", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CSampler_Slice23MetricSet>( "Sampler_Slice23", "Sampler_Slice23", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CSampler_Slice45MetricSet>( "Sampler_Slice45", "Sampler_Slice45", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CSampler_Slice67MetricSet>( "Sampler_Slice67", "Sampler_Slice67", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CTDL_Slice01_1MetricSet>( "TDL_Slice01_1", "TDL_Slice01_1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CTDL_Slice01_2MetricSet>( "TDL_Slice01_2", "TDL_Slice01_2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CTDL_Slice01_3MetricSet>( "TDL_Slice01_3", "TDL_Slice01_3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CTDL_Slice01_4MetricSet>( "TDL_Slice01_4", "TDL_Slice01_4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CTDL_Slice23_1MetricSet>( "TDL_Slice23_1", "TDL_Slice23_1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CTDL_Slice23_2MetricSet>( "TDL_Slice23_2", "TDL_Slice23_2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CTDL_Slice23_3MetricSet>( "TDL_Slice23_3", "TDL_Slice23_3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CTDL_Slice23_4MetricSet>( "TDL_Slice23_4", "TDL_Slice23_4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CTDL_Slice45_1MetricSet>( "TDL_Slice45_1", "TDL_Slice45_1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CTDL_Slice45_2MetricSet>( "TDL_Slice45_2", "TDL_Slice45_2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CTDL_Slice45_3MetricSet>( "TDL_Slice45_3", "TDL_Slice45_3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CTDL_Slice45_4MetricSet>( "TDL_Slice45_4", "TDL_Slice45_4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CTDL_Slice67_1MetricSet>( "TDL_Slice67_1", "TDL_Slice67_1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CTDL_Slice67_2MetricSet>( "TDL_Slice67_2", "TDL_Slice67_2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CTDL_Slice67_3MetricSet>( "TDL_Slice67_3", "TDL_Slice67_3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CTDL_Slice67_4MetricSet>( "TDL_Slice67_4", "TDL_Slice67_4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CComputeOverviewMetricSet>( "ComputeOverview", "ComputeOverview", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CL1ProfileReadsMetricSet_XeCore0>( "L1ProfileReads", "L1ProfileReads", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$GtSlice0XeCore0 $GtSlice1XeCore0 UADD $GtSlice2XeCore0 UADD $GtSlice3XeCore0 UADD $GtSlice4XeCore0 UADD $GtSlice5XeCore0 UADD $GtSlice6XeCore0 UADD $GtSlice7XeCore0 UADD $GtSlice0XeCore3 $GtSlice1XeCore3 UADD $GtSlice2XeCore3 UADD $GtSlice3XeCore3 UADD $GtSlice4XeCore3 UADD $GtSlice5XeCore3 UADD $GtSlice6XeCore3 UADD $GtSlice7XeCore3 UADD UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CL1ProfileReadsMetricSet_XeCore3>( "L1ProfileReads", "L1ProfileReads", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$GtSlice0XeCore0 $GtSlice1XeCore0 UADD $GtSlice2XeCore0 UADD $GtSlice3XeCore0 UADD $GtSlice4XeCore0 UADD $GtSlice5XeCore0 UADD $GtSlice6XeCore0 UADD $GtSlice7XeCore0 UADD $GtSlice0XeCore3 $GtSlice1XeCore3 UADD $GtSlice2XeCore3 UADD $GtSlice3XeCore3 UADD $GtSlice4XeCore3 UADD $GtSlice5XeCore3 UADD $GtSlice6XeCore3 UADD $GtSlice7XeCore3 UADD ULT", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CL1ProfileSlmBankConflictsMetricSet_XeCore0>( "L1ProfileSlmBankConflicts", "L1ProfileSlmBankConflicts", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$GtSlice0XeCore0 $GtSlice1XeCore0 UADD $GtSlice2XeCore0 UADD $GtSlice3XeCore0 UADD $GtSlice4XeCore0 UADD $GtSlice5XeCore0 UADD $GtSlice6XeCore0 UADD $GtSlice7XeCore0 UADD $GtSlice0XeCore3 $GtSlice1XeCore3 UADD $GtSlice2XeCore3 UADD $GtSlice3XeCore3 UADD $GtSlice4XeCore3 UADD $GtSlice5XeCore3 UADD $GtSlice6XeCore3 UADD $GtSlice7XeCore3 UADD UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CL1ProfileSlmBankConflictsMetricSet_XeCore3>( "L1ProfileSlmBankConflicts", "L1ProfileSlmBankConflicts", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$GtSlice0XeCore0 $GtSlice1XeCore0 UADD $GtSlice2XeCore0 UADD $GtSlice3XeCore0 UADD $GtSlice4XeCore0 UADD $GtSlice5XeCore0 UADD $GtSlice6XeCore0 UADD $GtSlice7XeCore0 UADD $GtSlice0XeCore3 $GtSlice1XeCore3 UADD $GtSlice2XeCore3 UADD $GtSlice3XeCore3 UADD $GtSlice4XeCore3 UADD $GtSlice5XeCore3 UADD $GtSlice6XeCore3 UADD $GtSlice7XeCore3 UADD ULT", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CL1ProfileWritesMetricSet_XeCore0>( "L1ProfileWrites", "L1ProfileWrites", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$GtSlice0XeCore0 $GtSlice1XeCore0 UADD $GtSlice2XeCore0 UADD $GtSlice3XeCore0 UADD $GtSlice4XeCore0 UADD $GtSlice5XeCore0 UADD $GtSlice6XeCore0 UADD $GtSlice7XeCore0 UADD $GtSlice0XeCore3 $GtSlice1XeCore3 UADD $GtSlice2XeCore3 UADD $GtSlice3XeCore3 UADD $GtSlice4XeCore3 UADD $GtSlice5XeCore3 UADD $GtSlice6XeCore3 UADD $GtSlice7XeCore3 UADD UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CL1ProfileWritesMetricSet_XeCore3>( "L1ProfileWrites", "L1ProfileWrites", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$GtSlice0XeCore0 $GtSlice1XeCore0 UADD $GtSlice2XeCore0 UADD $GtSlice3XeCore0 UADD $GtSlice4XeCore0 UADD $GtSlice5XeCore0 UADD $GtSlice6XeCore0 UADD $GtSlice7XeCore0 UADD $GtSlice0XeCore3 $GtSlice1XeCore3 UADD $GtSlice2XeCore3 UADD $GtSlice3XeCore3 UADD $GtSlice4XeCore3 UADD $GtSlice5XeCore3 UADD $GtSlice6XeCore3 UADD $GtSlice7XeCore3 UADD ULT", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CDataportReadsMetricSet>( "DataportReads", "DataportReads", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CDataportWritesMetricSet>( "DataportWrites", "DataportWrites", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1MetricSet>( "Ext1", "Ext1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt2MetricSet>( "Ext2", "Ext2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt3MetricSet>( "Ext3", "Ext3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt4MetricSet>( "Ext4", "Ext4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt5MetricSet>( "Ext5", "Ext5", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt6MetricSet>( "Ext6", "Ext6", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt7MetricSet>( "Ext7", "Ext7", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt8MetricSet>( "Ext8", "Ext8", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt9MetricSet>( "Ext9", "Ext9", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt10MetricSet>( "Ext10", "Ext10", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt11MetricSet>( "Ext11", "Ext11", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt12MetricSet>( "Ext12", "Ext12", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt13MetricSet>( "Ext13", "Ext13", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt14MetricSet>( "Ext14", "Ext14", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt15MetricSet>( "Ext15", "Ext15", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt16MetricSet>( "Ext16", "Ext16", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt17MetricSet>( "Ext17", "Ext17", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt18MetricSet>( "Ext18", "Ext18", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt19MetricSet>( "Ext19", "Ext19", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt20MetricSet>( "Ext20", "Ext20", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt21MetricSet>( "Ext21", "Ext21", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt22MetricSet>( "Ext22", "Ext22", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt23MetricSet>( "Ext23", "Ext23", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt24MetricSet>( "Ext24", "Ext24", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt27MetricSet>( "Ext27", "Ext27", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt28MetricSet>( "Ext28", "Ext28", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt29MetricSet>( "Ext29", "Ext29", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt30MetricSet>( "Ext30", "Ext30", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt31MetricSet>( "Ext31", "Ext31", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt32MetricSet>( "Ext32", "Ext32", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt33MetricSet>( "Ext33", "Ext33", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt34MetricSet>( "Ext34", "Ext34", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt35MetricSet>( "Ext35", "Ext35", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt36MetricSet>( "Ext36", "Ext36", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt37MetricSet>( "Ext37", "Ext37", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt38MetricSet>( "Ext38", "Ext38", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt39MetricSet>( "Ext39", "Ext39", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt40MetricSet>( "Ext40", "Ext40", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt41MetricSet>( "Ext41", "Ext41", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt42MetricSet>( "Ext42", "Ext42", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt43MetricSet>( "Ext43", "Ext43", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt44MetricSet>( "Ext44", "Ext44", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt45MetricSet>( "Ext45", "Ext45", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt46MetricSet>( "Ext46", "Ext46", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt47MetricSet>( "Ext47", "Ext47", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt48MetricSet>( "Ext48", "Ext48", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt49MetricSet>( "Ext49", "Ext49", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt50MetricSet>( "Ext50", "Ext50", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt51MetricSet>( "Ext51", "Ext51", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt52MetricSet>( "Ext52", "Ext52", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt53MetricSet>( "Ext53", "Ext53", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt54MetricSet>( "Ext54", "Ext54", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt55MetricSet>( "Ext55", "Ext55", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt56MetricSet>( "Ext56", "Ext56", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt57MetricSet>( "Ext57", "Ext57", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt58MetricSet>( "Ext58", "Ext58", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt59MetricSet>( "Ext59", "Ext59", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt60MetricSet>( "Ext60", "Ext60", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt61MetricSet>( "Ext61", "Ext61", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt62MetricSet>( "Ext62", "Ext62", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt63MetricSet>( "Ext63", "Ext63", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt64MetricSet>( "Ext64", "Ext64", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt65MetricSet>( "Ext65", "Ext65", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt66MetricSet>( "Ext66", "Ext66", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt67MetricSet>( "Ext67", "Ext67", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt68MetricSet>( "Ext68", "Ext68", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt69MetricSet>( "Ext69", "Ext69", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt70MetricSet>( "Ext70", "Ext70", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt71MetricSet>( "Ext71", "Ext71", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt72MetricSet>( "Ext72", "Ext72", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt73MetricSet>( "Ext73", "Ext73", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt74MetricSet>( "Ext74", "Ext74", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt75MetricSet>( "Ext75", "Ext75", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt76MetricSet>( "Ext76", "Ext76", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt77MetricSet>( "Ext77", "Ext77", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt78MetricSet>( "Ext78", "Ext78", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt79MetricSet>( "Ext79", "Ext79", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt80MetricSet>( "Ext80", "Ext80", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt81MetricSet>( "Ext81", "Ext81", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt82MetricSet>( "Ext82", "Ext82", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt83MetricSet>( "Ext83", "Ext83", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt84MetricSet>( "Ext84", "Ext84", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt85MetricSet>( "Ext85", "Ext85", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt86MetricSet>( "Ext86", "Ext86", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt87MetricSet>( "Ext87", "Ext87", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt88MetricSet>( "Ext88", "Ext88", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt89MetricSet>( "Ext89", "Ext89", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt90MetricSet>( "Ext90", "Ext90", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt91MetricSet>( "Ext91", "Ext91", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt92MetricSet>( "Ext92", "Ext92", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt93MetricSet>( "Ext93", "Ext93", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt94MetricSet>( "Ext94", "Ext94", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt95MetricSet>( "Ext95", "Ext95", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt96MetricSet>( "Ext96", "Ext96", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt97MetricSet>( "Ext97", "Ext97", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt98MetricSet>( "Ext98", "Ext98", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt99MetricSet>( "Ext99", "Ext99", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt100MetricSet>( "Ext100", "Ext100", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt101MetricSet>( "Ext101", "Ext101", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt102MetricSet>( "Ext102", "Ext102", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt103MetricSet>( "Ext103", "Ext103", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt104MetricSet>( "Ext104", "Ext104", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt105MetricSet>( "Ext105", "Ext105", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt106MetricSet>( "Ext106", "Ext106", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt107MetricSet>( "Ext107", "Ext107", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt108MetricSet>( "Ext108", "Ext108", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt109MetricSet>( "Ext109", "Ext109", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt110MetricSet>( "Ext110", "Ext110", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt111MetricSet>( "Ext111", "Ext111", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt112MetricSet>( "Ext112", "Ext112", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt113MetricSet>( "Ext113", "Ext113", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt114MetricSet>( "Ext114", "Ext114", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt115MetricSet>( "Ext115", "Ext115", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt116MetricSet>( "Ext116", "Ext116", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt117MetricSet>( "Ext117", "Ext117", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt118MetricSet>( "Ext118", "Ext118", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt119MetricSet>( "Ext119", "Ext119", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt120MetricSet>( "Ext120", "Ext120", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt121MetricSet>( "Ext121", "Ext121", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt122MetricSet>( "Ext122", "Ext122", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt123MetricSet>( "Ext123", "Ext123", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt124MetricSet>( "Ext124", "Ext124", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt125MetricSet>( "Ext125", "Ext125", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt126MetricSet>( "Ext126", "Ext126", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt127MetricSet>( "Ext127", "Ext127", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt128MetricSet>( "Ext128", "Ext128", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt129MetricSet>( "Ext129", "Ext129", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt130MetricSet>( "Ext130", "Ext130", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt131MetricSet>( "Ext131", "Ext131", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt132MetricSet>( "Ext132", "Ext132", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt133MetricSet>( "Ext133", "Ext133", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt134MetricSet>( "Ext134", "Ext134", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt135MetricSet>( "Ext135", "Ext135", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt136MetricSet>( "Ext136", "Ext136", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt137MetricSet>( "Ext137", "Ext137", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt138MetricSet>( "Ext138", "Ext138", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt139MetricSet>( "Ext139", "Ext139", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt140MetricSet>( "Ext140", "Ext140", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt141MetricSet>( "Ext141", "Ext141", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt142MetricSet>( "Ext142", "Ext142", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt143MetricSet>( "Ext143", "Ext143", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt144MetricSet>( "Ext144", "Ext144", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt145MetricSet>( "Ext145", "Ext145", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt146MetricSet>( "Ext146", "Ext146", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt147MetricSet>( "Ext147", "Ext147", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt148MetricSet>( "Ext148", "Ext148", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt149MetricSet>( "Ext149", "Ext149", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt150MetricSet>( "Ext150", "Ext150", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt151MetricSet>( "Ext151", "Ext151", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt152MetricSet>( "Ext152", "Ext152", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt153MetricSet>( "Ext153", "Ext153", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt154MetricSet>( "Ext154", "Ext154", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt155MetricSet>( "Ext155", "Ext155", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt156MetricSet>( "Ext156", "Ext156", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt157MetricSet>( "Ext157", "Ext157", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt158MetricSet>( "Ext158", "Ext158", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt159MetricSet>( "Ext159", "Ext159", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt160MetricSet>( "Ext160", "Ext160", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt161MetricSet>( "Ext161", "Ext161", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt162MetricSet>( "Ext162", "Ext162", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt163MetricSet>( "Ext163", "Ext163", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt164MetricSet>( "Ext164", "Ext164", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt165MetricSet>( "Ext165", "Ext165", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt166MetricSet>( "Ext166", "Ext166", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt167MetricSet>( "Ext167", "Ext167", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt168MetricSet>( "Ext168", "Ext168", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt169MetricSet>( "Ext169", "Ext169", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt170MetricSet>( "Ext170", "Ext170", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt171MetricSet>( "Ext171", "Ext171", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt172MetricSet>( "Ext172", "Ext172", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt173MetricSet>( "Ext173", "Ext173", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt174MetricSet>( "Ext174", "Ext174", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt175MetricSet>( "Ext175", "Ext175", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt176MetricSet>( "Ext176", "Ext176", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt177MetricSet>( "Ext177", "Ext177", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt178MetricSet>( "Ext178", "Ext178", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt179MetricSet>( "Ext179", "Ext179", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt180MetricSet>( "Ext180", "Ext180", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt181MetricSet>( "Ext181", "Ext181", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt182MetricSet>( "Ext182", "Ext182", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt183MetricSet>( "Ext183", "Ext183", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt184MetricSet>( "Ext184", "Ext184", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt185MetricSet>( "Ext185", "Ext185", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt186MetricSet>( "Ext186", "Ext186", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt187MetricSet>( "Ext187", "Ext187", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt188MetricSet>( "Ext188", "Ext188", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt189MetricSet>( "Ext189", "Ext189", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt190MetricSet>( "Ext190", "Ext190", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt191MetricSet>( "Ext191", "Ext191", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt192MetricSet>( "Ext192", "Ext192", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt193MetricSet>( "Ext193", "Ext193", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt194MetricSet>( "Ext194", "Ext194", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt195MetricSet>( "Ext195", "Ext195", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt196MetricSet>( "Ext196", "Ext196", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt197MetricSet>( "Ext197", "Ext197", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt198MetricSet>( "Ext198", "Ext198", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt199MetricSet>( "Ext199", "Ext199", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt200MetricSet>( "Ext200", "Ext200", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt201MetricSet>( "Ext201", "Ext201", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt202MetricSet>( "Ext202", "Ext202", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt203MetricSet>( "Ext203", "Ext203", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt204MetricSet>( "Ext204", "Ext204", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt205MetricSet>( "Ext205", "Ext205", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt206MetricSet>( "Ext206", "Ext206", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt207MetricSet>( "Ext207", "Ext207", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt208MetricSet>( "Ext208", "Ext208", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt209MetricSet>( "Ext209", "Ext209", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt210MetricSet>( "Ext210", "Ext210", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt211MetricSet>( "Ext211", "Ext211", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt212MetricSet>( "Ext212", "Ext212", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt213MetricSet>( "Ext213", "Ext213", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt214MetricSet>( "Ext214", "Ext214", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt215MetricSet>( "Ext215", "Ext215", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt216MetricSet>( "Ext216", "Ext216", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt217MetricSet>( "Ext217", "Ext217", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt218MetricSet>( "Ext218", "Ext218", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt219MetricSet>( "Ext219", "Ext219", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt220MetricSet>( "Ext220", "Ext220", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt221MetricSet>( "Ext221", "Ext221", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt222MetricSet>( "Ext222", "Ext222", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt223MetricSet>( "Ext223", "Ext223", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt224MetricSet>( "Ext224", "Ext224", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt225MetricSet>( "Ext225", "Ext225", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt226MetricSet>( "Ext226", "Ext226", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt227MetricSet>( "Ext227", "Ext227", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt228MetricSet>( "Ext228", "Ext228", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt229MetricSet>( "Ext229", "Ext229", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt230MetricSet>( "Ext230", "Ext230", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt231MetricSet>( "Ext231", "Ext231", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt232MetricSet>( "Ext232", "Ext232", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt233MetricSet>( "Ext233", "Ext233", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt234MetricSet>( "Ext234", "Ext234", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt235MetricSet>( "Ext235", "Ext235", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt236MetricSet>( "Ext236", "Ext236", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt237MetricSet>( "Ext237", "Ext237", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt238MetricSet>( "Ext238", "Ext238", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt239MetricSet>( "Ext239", "Ext239", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt240MetricSet>( "Ext240", "Ext240", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt241MetricSet>( "Ext241", "Ext241", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt242MetricSet>( "Ext242", "Ext242", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt243MetricSet>( "Ext243", "Ext243", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt244MetricSet>( "Ext244", "Ext244", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt245MetricSet>( "Ext245", "Ext245", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt246MetricSet>( "Ext246", "Ext246", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt247MetricSet>( "Ext247", "Ext247", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt248MetricSet>( "Ext248", "Ext248", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt249MetricSet>( "Ext249", "Ext249", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt250MetricSet>( "Ext250", "Ext250", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt251MetricSet>( "Ext251", "Ext251", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt252MetricSet>( "Ext252", "Ext252", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt253MetricSet>( "Ext253", "Ext253", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt254MetricSet>( "Ext254", "Ext254", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt255MetricSet>( "Ext255", "Ext255", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt256MetricSet>( "Ext256", "Ext256", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt257MetricSet>( "Ext257", "Ext257", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt258MetricSet>( "Ext258", "Ext258", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt259MetricSet>( "Ext259", "Ext259", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt260MetricSet>( "Ext260", "Ext260", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt261MetricSet>( "Ext261", "Ext261", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt262MetricSet>( "Ext262", "Ext262", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt263MetricSet>( "Ext263", "Ext263", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt264MetricSet>( "Ext264", "Ext264", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt265MetricSet>( "Ext265", "Ext265", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt266MetricSet>( "Ext266", "Ext266", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt267MetricSet>( "Ext267", "Ext267", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt268MetricSet>( "Ext268", "Ext268", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt269MetricSet>( "Ext269", "Ext269", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt270MetricSet>( "Ext270", "Ext270", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt271MetricSet>( "Ext271", "Ext271", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt272MetricSet>( "Ext272", "Ext272", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt273MetricSet>( "Ext273", "Ext273", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt274MetricSet>( "Ext274", "Ext274", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt275MetricSet>( "Ext275", "Ext275", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt276MetricSet>( "Ext276", "Ext276", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt277MetricSet>( "Ext277", "Ext277", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt278MetricSet>( "Ext278", "Ext278", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt279MetricSet>( "Ext279", "Ext279", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt280MetricSet>( "Ext280", "Ext280", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt281MetricSet>( "Ext281", "Ext281", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt282MetricSet>( "Ext282", "Ext282", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt283MetricSet>( "Ext283", "Ext283", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt284MetricSet>( "Ext284", "Ext284", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt285MetricSet>( "Ext285", "Ext285", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt286MetricSet>( "Ext286", "Ext286", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt288MetricSet>( "Ext288", "Ext288", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt289MetricSet>( "Ext289", "Ext289", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt290MetricSet>( "Ext290", "Ext290", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt291MetricSet>( "Ext291", "Ext291", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt292MetricSet>( "Ext292", "Ext292", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt293MetricSet>( "Ext293", "Ext293", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt294MetricSet>( "Ext294", "Ext294", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt295MetricSet>( "Ext295", "Ext295", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt296MetricSet>( "Ext296", "Ext296", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt297MetricSet>( "Ext297", "Ext297", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt298MetricSet>( "Ext298", "Ext298", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt299MetricSet>( "Ext299", "Ext299", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt300MetricSet>( "Ext300", "Ext300", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt301MetricSet>( "Ext301", "Ext301", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt302MetricSet>( "Ext302", "Ext302", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt303MetricSet>( "Ext303", "Ext303", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt304MetricSet>( "Ext304", "Ext304", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt305MetricSet>( "Ext305", "Ext305", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt306MetricSet>( "Ext306", "Ext306", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt307MetricSet>( "Ext307", "Ext307", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt308MetricSet>( "Ext308", "Ext308", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt309MetricSet>( "Ext309", "Ext309", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt310MetricSet>( "Ext310", "Ext310", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt311MetricSet>( "Ext311", "Ext311", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt312MetricSet>( "Ext312", "Ext312", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt313MetricSet>( "Ext313", "Ext313", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt314MetricSet>( "Ext314", "Ext314", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt315MetricSet>( "Ext315", "Ext315", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt316MetricSet>( "Ext316", "Ext316", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt317MetricSet>( "Ext317", "Ext317", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt318MetricSet>( "Ext318", "Ext318", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt319MetricSet>( "Ext319", "Ext319", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt320MetricSet>( "Ext320", "Ext320", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt321MetricSet>( "Ext321", "Ext321", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt322MetricSet>( "Ext322", "Ext322", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt323MetricSet>( "Ext323", "Ext323", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt324MetricSet>( "Ext324", "Ext324", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt325MetricSet>( "Ext325", "Ext325", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt326MetricSet>( "Ext326", "Ext326", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt327MetricSet>( "Ext327", "Ext327", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt328MetricSet>( "Ext328", "Ext328", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt329MetricSet>( "Ext329", "Ext329", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt330MetricSet>( "Ext330", "Ext330", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt331MetricSet>( "Ext331", "Ext331", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt332MetricSet>( "Ext332", "Ext332", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt333MetricSet>( "Ext333", "Ext333", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt334MetricSet>( "Ext334", "Ext334", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt335MetricSet>( "Ext335", "Ext335", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt342MetricSet>( "Ext342", "Ext342", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt343MetricSet>( "Ext343", "Ext343", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt344MetricSet>( "Ext344", "Ext344", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt345MetricSet>( "Ext345", "Ext345", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt346MetricSet>( "Ext346", "Ext346", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt347MetricSet>( "Ext347", "Ext347", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt348MetricSet>( "Ext348", "Ext348", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt349MetricSet>( "Ext349", "Ext349", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt350MetricSet>( "Ext350", "Ext350", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt351MetricSet>( "Ext351", "Ext351", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt352MetricSet>( "Ext352", "Ext352", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt353MetricSet>( "Ext353", "Ext353", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt354MetricSet>( "Ext354", "Ext354", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt355MetricSet>( "Ext355", "Ext355", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt356MetricSet>( "Ext356", "Ext356", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt357MetricSet>( "Ext357", "Ext357", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt358MetricSet>( "Ext358", "Ext358", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt359MetricSet>( "Ext359", "Ext359", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt360MetricSet>( "Ext360", "Ext360", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt361MetricSet>( "Ext361", "Ext361", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt362MetricSet>( "Ext362", "Ext362", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt363MetricSet>( "Ext363", "Ext363", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt364MetricSet>( "Ext364", "Ext364", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt365MetricSet>( "Ext365", "Ext365", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt366MetricSet>( "Ext366", "Ext366", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt367MetricSet>( "Ext367", "Ext367", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt368MetricSet>( "Ext368", "Ext368", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt369MetricSet>( "Ext369", "Ext369", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt370MetricSet>( "Ext370", "Ext370", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt371MetricSet>( "Ext371", "Ext371", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt372MetricSet>( "Ext372", "Ext372", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt373MetricSet>( "Ext373", "Ext373", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt374MetricSet>( "Ext374", "Ext374", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt375MetricSet>( "Ext375", "Ext375", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt376MetricSet>( "Ext376", "Ext376", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt377MetricSet>( "Ext377", "Ext377", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt378MetricSet>( "Ext378", "Ext378", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt379MetricSet>( "Ext379", "Ext379", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt380MetricSet>( "Ext380", "Ext380", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt381MetricSet>( "Ext381", "Ext381", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt382MetricSet>( "Ext382", "Ext382", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt383MetricSet>( "Ext383", "Ext383", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt384MetricSet>( "Ext384", "Ext384", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt385MetricSet>( "Ext385", "Ext385", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt386MetricSet>( "Ext386", "Ext386", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt387MetricSet>( "Ext387", "Ext387", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt388MetricSet>( "Ext388", "Ext388", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt389MetricSet>( "Ext389", "Ext389", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt390MetricSet>( "Ext390", "Ext390", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt391MetricSet>( "Ext391", "Ext391", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt392MetricSet>( "Ext392", "Ext392", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt393MetricSet>( "Ext393", "Ext393", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt394MetricSet>( "Ext394", "Ext394", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt395MetricSet>( "Ext395", "Ext395", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt396MetricSet>( "Ext396", "Ext396", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt397MetricSet>( "Ext397", "Ext397", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt398MetricSet>( "Ext398", "Ext398", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt399MetricSet>( "Ext399", "Ext399", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt400MetricSet>( "Ext400", "Ext400", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt401MetricSet>( "Ext401", "Ext401", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt402MetricSet>( "Ext402", "Ext402", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt403MetricSet>( "Ext403", "Ext403", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt404MetricSet>( "Ext404", "Ext404", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt405MetricSet>( "Ext405", "Ext405", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt406MetricSet>( "Ext406", "Ext406", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt407MetricSet>( "Ext407", "Ext407", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt408MetricSet>( "Ext408", "Ext408", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt409MetricSet>( "Ext409", "Ext409", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt410MetricSet>( "Ext410", "Ext410", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt411MetricSet>( "Ext411", "Ext411", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt412MetricSet>( "Ext412", "Ext412", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt413MetricSet>( "Ext413", "Ext413", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt414MetricSet>( "Ext414", "Ext414", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt415MetricSet>( "Ext415", "Ext415", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt416MetricSet>( "Ext416", "Ext416", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt417MetricSet>( "Ext417", "Ext417", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt418MetricSet>( "Ext418", "Ext418", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt419MetricSet>( "Ext419", "Ext419", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt420MetricSet>( "Ext420", "Ext420", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt421MetricSet>( "Ext421", "Ext421", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt422MetricSet>( "Ext422", "Ext422", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt423MetricSet>( "Ext423", "Ext423", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt424MetricSet>( "Ext424", "Ext424", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt425MetricSet>( "Ext425", "Ext425", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt426MetricSet>( "Ext426", "Ext426", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt427MetricSet>( "Ext427", "Ext427", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt428MetricSet>( "Ext428", "Ext428", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt429MetricSet>( "Ext429", "Ext429", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt430MetricSet>( "Ext430", "Ext430", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt431MetricSet>( "Ext431", "Ext431", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt432MetricSet>( "Ext432", "Ext432", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt433MetricSet>( "Ext433", "Ext433", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt434MetricSet>( "Ext434", "Ext434", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt435MetricSet>( "Ext435", "Ext435", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt436MetricSet>( "Ext436", "Ext436", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt437MetricSet>( "Ext437", "Ext437", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt438MetricSet>( "Ext438", "Ext438", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt439MetricSet>( "Ext439", "Ext439", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt440MetricSet>( "Ext440", "Ext440", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt441MetricSet>( "Ext441", "Ext441", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt442MetricSet>( "Ext442", "Ext442", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt443MetricSet>( "Ext443", "Ext443", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt444MetricSet>( "Ext444", "Ext444", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt445MetricSet>( "Ext445", "Ext445", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt446MetricSet>( "Ext446", "Ext446", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt447MetricSet>( "Ext447", "Ext447", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt448MetricSet>( "Ext448", "Ext448", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt449MetricSet>( "Ext449", "Ext449", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt450MetricSet>( "Ext450", "Ext450", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt451MetricSet>( "Ext451", "Ext451", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt452MetricSet>( "Ext452", "Ext452", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt453MetricSet>( "Ext453", "Ext453", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt454MetricSet>( "Ext454", "Ext454", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt455MetricSet>( "Ext455", "Ext455", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt456MetricSet>( "Ext456", "Ext456", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt457MetricSet>( "Ext457", "Ext457", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt458MetricSet>( "Ext458", "Ext458", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt459MetricSet>( "Ext459", "Ext459", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt460MetricSet>( "Ext460", "Ext460", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt461MetricSet>( "Ext461", "Ext461", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt462MetricSet>( "Ext462", "Ext462", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt463MetricSet>( "Ext463", "Ext463", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt464MetricSet>( "Ext464", "Ext464", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt465MetricSet>( "Ext465", "Ext465", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt466MetricSet>( "Ext466", "Ext466", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt467MetricSet>( "Ext467", "Ext467", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt468MetricSet>( "Ext468", "Ext468", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt469MetricSet>( "Ext469", "Ext469", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt470MetricSet>( "Ext470", "Ext470", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt471MetricSet>( "Ext471", "Ext471", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt472MetricSet>( "Ext472", "Ext472", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt473MetricSet>( "Ext473", "Ext473", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt474MetricSet>( "Ext474", "Ext474", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt475MetricSet>( "Ext475", "Ext475", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt476MetricSet>( "Ext476", "Ext476", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt477MetricSet>( "Ext477", "Ext477", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt478MetricSet>( "Ext478", "Ext478", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt479MetricSet>( "Ext479", "Ext479", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt480MetricSet>( "Ext480", "Ext480", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt481MetricSet>( "Ext481", "Ext481", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt482MetricSet>( "Ext482", "Ext482", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt483MetricSet>( "Ext483", "Ext483", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt484MetricSet>( "Ext484", "Ext484", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt485MetricSet>( "Ext485", "Ext485", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt486MetricSet>( "Ext486", "Ext486", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt487MetricSet>( "Ext487", "Ext487", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt488MetricSet>( "Ext488", "Ext488", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt489MetricSet>( "Ext489", "Ext489", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt490MetricSet>( "Ext490", "Ext490", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt491MetricSet>( "Ext491", "Ext491", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt492MetricSet>( "Ext492", "Ext492", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt493MetricSet>( "Ext493", "Ext493", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt494MetricSet>( "Ext494", "Ext494", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt495MetricSet>( "Ext495", "Ext495", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt496MetricSet>( "Ext496", "Ext496", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt497MetricSet>( "Ext497", "Ext497", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt498MetricSet>( "Ext498", "Ext498", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt499MetricSet>( "Ext499", "Ext499", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt500MetricSet>( "Ext500", "Ext500", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt501MetricSet>( "Ext501", "Ext501", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt502MetricSet>( "Ext502", "Ext502", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt503MetricSet>( "Ext503", "Ext503", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt504MetricSet>( "Ext504", "Ext504", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt505MetricSet>( "Ext505", "Ext505", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt506MetricSet>( "Ext506", "Ext506", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt507MetricSet>( "Ext507", "Ext507", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt508MetricSet>( "Ext508", "Ext508", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt509MetricSet>( "Ext509", "Ext509", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt510MetricSet>( "Ext510", "Ext510", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt511MetricSet>( "Ext511", "Ext511", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt512MetricSet>( "Ext512", "Ext512", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt513MetricSet>( "Ext513", "Ext513", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt514MetricSet>( "Ext514", "Ext514", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt515MetricSet>( "Ext515", "Ext515", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt516MetricSet>( "Ext516", "Ext516", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt517MetricSet>( "Ext517", "Ext517", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt518MetricSet>( "Ext518", "Ext518", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt519MetricSet>( "Ext519", "Ext519", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt520MetricSet>( "Ext520", "Ext520", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt521MetricSet>( "Ext521", "Ext521", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt522MetricSet>( "Ext522", "Ext522", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt523MetricSet>( "Ext523", "Ext523", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt524MetricSet>( "Ext524", "Ext524", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt525MetricSet>( "Ext525", "Ext525", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt526MetricSet>( "Ext526", "Ext526", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt527MetricSet>( "Ext527", "Ext527", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt528MetricSet>( "Ext528", "Ext528", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt529MetricSet>( "Ext529", "Ext529", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt530MetricSet>( "Ext530", "Ext530", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt531MetricSet>( "Ext531", "Ext531", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt532MetricSet>( "Ext532", "Ext532", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt533MetricSet>( "Ext533", "Ext533", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt534MetricSet>( "Ext534", "Ext534", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt535MetricSet>( "Ext535", "Ext535", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt536MetricSet>( "Ext536", "Ext536", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt537MetricSet>( "Ext537", "Ext537", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt538MetricSet>( "Ext538", "Ext538", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt539MetricSet>( "Ext539", "Ext539", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt540MetricSet>( "Ext540", "Ext540", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt541MetricSet>( "Ext541", "Ext541", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt542MetricSet>( "Ext542", "Ext542", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt543MetricSet>( "Ext543", "Ext543", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt544MetricSet>( "Ext544", "Ext544", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt545MetricSet>( "Ext545", "Ext545", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt546MetricSet>( "Ext546", "Ext546", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt547MetricSet>( "Ext547", "Ext547", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt548MetricSet>( "Ext548", "Ext548", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt549MetricSet>( "Ext549", "Ext549", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt550MetricSet>( "Ext550", "Ext550", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt551MetricSet>( "Ext551", "Ext551", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt552MetricSet>( "Ext552", "Ext552", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt553MetricSet>( "Ext553", "Ext553", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt554MetricSet>( "Ext554", "Ext554", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt555MetricSet>( "Ext555", "Ext555", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt556MetricSet>( "Ext556", "Ext556", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt557MetricSet>( "Ext557", "Ext557", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt558MetricSet>( "Ext558", "Ext558", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt559MetricSet>( "Ext559", "Ext559", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt560MetricSet>( "Ext560", "Ext560", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt561MetricSet>( "Ext561", "Ext561", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt562MetricSet>( "Ext562", "Ext562", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt563MetricSet>( "Ext563", "Ext563", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt564MetricSet>( "Ext564", "Ext564", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt565MetricSet>( "Ext565", "Ext565", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt566MetricSet>( "Ext566", "Ext566", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt567MetricSet>( "Ext567", "Ext567", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt568MetricSet>( "Ext568", "Ext568", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt569MetricSet>( "Ext569", "Ext569", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt570MetricSet>( "Ext570", "Ext570", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt571MetricSet>( "Ext571", "Ext571", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt572MetricSet>( "Ext572", "Ext572", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt573MetricSet>( "Ext573", "Ext573", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt574MetricSet>( "Ext574", "Ext574", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt575MetricSet>( "Ext575", "Ext575", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt576MetricSet>( "Ext576", "Ext576", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt577MetricSet>( "Ext577", "Ext577", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt578MetricSet>( "Ext578", "Ext578", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt579MetricSet>( "Ext579", "Ext579", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt580MetricSet>( "Ext580", "Ext580", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt581MetricSet>( "Ext581", "Ext581", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt582MetricSet>( "Ext582", "Ext582", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt583MetricSet>( "Ext583", "Ext583", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt584MetricSet>( "Ext584", "Ext584", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt585MetricSet>( "Ext585", "Ext585", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt586MetricSet>( "Ext586", "Ext586", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt587MetricSet>( "Ext587", "Ext587", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt588MetricSet>( "Ext588", "Ext588", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt589MetricSet>( "Ext589", "Ext589", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt590MetricSet>( "Ext590", "Ext590", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt591MetricSet_Refresh>( "Ext591", "Ext591", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt592MetricSet_Refresh>( "Ext592", "Ext592", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt593MetricSet_Refresh>( "Ext593", "Ext593", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt594MetricSet_Refresh>( "Ext594", "Ext594", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt595MetricSet_Refresh>( "Ext595", "Ext595", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt596MetricSet_Refresh>( "Ext596", "Ext596", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt597MetricSet_Refresh>( "Ext597", "Ext597", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt598MetricSet_Refresh>( "Ext598", "Ext598", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt591MetricSet_FirstVersion>( "Ext591", "Ext591", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt592MetricSet_FirstVersion>( "Ext592", "Ext592", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt593MetricSet_FirstVersion>( "Ext593", "Ext593", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt594MetricSet_FirstVersion>( "Ext594", "Ext594", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt595MetricSet_FirstVersion>( "Ext595", "Ext595", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt596MetricSet_FirstVersion>( "Ext596", "Ext596", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt597MetricSet_FirstVersion>( "Ext597", "Ext597", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt598MetricSet_FirstVersion>( "Ext598", "Ext598", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt599MetricSet>( "Ext599", "Ext599", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt600MetricSet>( "Ext600", "Ext600", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt601MetricSet>( "Ext601", "Ext601", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt602MetricSet>( "Ext602", "Ext602", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt603MetricSet>( "Ext603", "Ext603", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt604MetricSet>( "Ext604", "Ext604", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt605MetricSet>( "Ext605", "Ext605", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt606MetricSet>( "Ext606", "Ext606", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt607MetricSet>( "Ext607", "Ext607", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt608MetricSet>( "Ext608", "Ext608", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt609MetricSet>( "Ext609", "Ext609", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt610MetricSet>( "Ext610", "Ext610", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt611MetricSet>( "Ext611", "Ext611", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt612MetricSet>( "Ext612", "Ext612", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt613MetricSet>( "Ext613", "Ext613", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt614MetricSet>( "Ext614", "Ext614", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt615MetricSet>( "Ext615", "Ext615", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt616MetricSet>( "Ext616", "Ext616", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt617MetricSet>( "Ext617", "Ext617", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt618MetricSet>( "Ext618", "Ext618", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt619MetricSet>( "Ext619", "Ext619", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt620MetricSet>( "Ext620", "Ext620", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt621MetricSet>( "Ext621", "Ext621", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt622MetricSet>( "Ext622", "Ext622", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt623MetricSet>( "Ext623", "Ext623", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt624MetricSet>( "Ext624", "Ext624", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt625MetricSet>( "Ext625", "Ext625", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt626MetricSet>( "Ext626", "Ext626", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt627MetricSet>( "Ext627", "Ext627", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt628MetricSet>( "Ext628", "Ext628", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt629MetricSet>( "Ext629", "Ext629", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt630MetricSet>( "Ext630", "Ext630", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt631MetricSet>( "Ext631", "Ext631", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt632MetricSet>( "Ext632", "Ext632", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt633MetricSet>( "Ext633", "Ext633", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt634MetricSet>( "Ext634", "Ext634", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt635MetricSet>( "Ext635", "Ext635", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt636MetricSet>( "Ext636", "Ext636", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt637MetricSet_Refresh>( "Ext637", "Ext637", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt638MetricSet_Refresh>( "Ext638", "Ext638", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt639MetricSet_Refresh>( "Ext639", "Ext639", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt640MetricSet_Refresh>( "Ext640", "Ext640", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt641MetricSet_Refresh>( "Ext641", "Ext641", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt642MetricSet_Refresh>( "Ext642", "Ext642", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt643MetricSet_Refresh>( "Ext643", "Ext643", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt644MetricSet_Refresh>( "Ext644", "Ext644", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt645MetricSet_Refresh>( "Ext645", "Ext645", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt646MetricSet_Refresh>( "Ext646", "Ext646", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt647MetricSet_Refresh>( "Ext647", "Ext647", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt648MetricSet_Refresh>( "Ext648", "Ext648", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt649MetricSet_Refresh>( "Ext649", "Ext649", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt650MetricSet_Refresh>( "Ext650", "Ext650", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt651MetricSet_Refresh>( "Ext651", "Ext651", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt652MetricSet_Refresh>( "Ext652", "Ext652", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt653MetricSet_Refresh>( "Ext653", "Ext653", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt654MetricSet_Refresh>( "Ext654", "Ext654", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt655MetricSet_Refresh>( "Ext655", "Ext655", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt656MetricSet_Refresh>( "Ext656", "Ext656", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt657MetricSet_Refresh>( "Ext657", "Ext657", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt658MetricSet_Refresh>( "Ext658", "Ext658", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt659MetricSet_Refresh>( "Ext659", "Ext659", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt660MetricSet_Refresh>( "Ext660", "Ext660", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt661MetricSet_Refresh>( "Ext661", "Ext661", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt662MetricSet_Refresh>( "Ext662", "Ext662", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt663MetricSet_Refresh>( "Ext663", "Ext663", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt664MetricSet_Refresh>( "Ext664", "Ext664", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt665MetricSet_Refresh>( "Ext665", "Ext665", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt666MetricSet_Refresh>( "Ext666", "Ext666", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt667MetricSet_Refresh>( "Ext667", "Ext667", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt668MetricSet_Refresh>( "Ext668", "Ext668", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt637MetricSet_FirstVersion>( "Ext637", "Ext637", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt638MetricSet_FirstVersion>( "Ext638", "Ext638", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt639MetricSet_FirstVersion>( "Ext639", "Ext639", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt640MetricSet_FirstVersion>( "Ext640", "Ext640", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt641MetricSet_FirstVersion>( "Ext641", "Ext641", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt642MetricSet_FirstVersion>( "Ext642", "Ext642", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt643MetricSet_FirstVersion>( "Ext643", "Ext643", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt644MetricSet_FirstVersion>( "Ext644", "Ext644", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt645MetricSet_FirstVersion>( "Ext645", "Ext645", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt646MetricSet_FirstVersion>( "Ext646", "Ext646", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt647MetricSet_FirstVersion>( "Ext647", "Ext647", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt648MetricSet_FirstVersion>( "Ext648", "Ext648", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt649MetricSet_FirstVersion>( "Ext649", "Ext649", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt650MetricSet_FirstVersion>( "Ext650", "Ext650", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt651MetricSet_FirstVersion>( "Ext651", "Ext651", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt652MetricSet_FirstVersion>( "Ext652", "Ext652", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt653MetricSet_FirstVersion>( "Ext653", "Ext653", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt654MetricSet_FirstVersion>( "Ext654", "Ext654", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt655MetricSet_FirstVersion>( "Ext655", "Ext655", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt656MetricSet_FirstVersion>( "Ext656", "Ext656", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt657MetricSet_FirstVersion>( "Ext657", "Ext657", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt658MetricSet_FirstVersion>( "Ext658", "Ext658", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt659MetricSet_FirstVersion>( "Ext659", "Ext659", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt660MetricSet_FirstVersion>( "Ext660", "Ext660", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt661MetricSet_FirstVersion>( "Ext661", "Ext661", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt662MetricSet_FirstVersion>( "Ext662", "Ext662", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt663MetricSet_FirstVersion>( "Ext663", "Ext663", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt664MetricSet_FirstVersion>( "Ext664", "Ext664", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt665MetricSet_FirstVersion>( "Ext665", "Ext665", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt666MetricSet_FirstVersion>( "Ext666", "Ext666", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt667MetricSet_FirstVersion>( "Ext667", "Ext667", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt668MetricSet_FirstVersion>( "Ext668", "Ext668", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt669MetricSet>( "Ext669", "Ext669", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt670MetricSet>( "Ext670", "Ext670", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt671MetricSet>( "Ext671", "Ext671", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt672MetricSet>( "Ext672", "Ext672", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt673MetricSet>( "Ext673", "Ext673", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt674MetricSet>( "Ext674", "Ext674", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt675MetricSet>( "Ext675", "Ext675", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt676MetricSet>( "Ext676", "Ext676", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt677MetricSet>( "Ext677", "Ext677", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt678MetricSet>( "Ext678", "Ext678", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt679MetricSet>( "Ext679", "Ext679", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt680MetricSet>( "Ext680", "Ext680", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt681MetricSet>( "Ext681", "Ext681", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt682MetricSet>( "Ext682", "Ext682", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt683MetricSet>( "Ext683", "Ext683", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt684MetricSet>( "Ext684", "Ext684", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt685MetricSet>( "Ext685", "Ext685", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt686MetricSet>( "Ext686", "Ext686", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt687MetricSet>( "Ext687", "Ext687", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt688MetricSet>( "Ext688", "Ext688", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt689MetricSet>( "Ext689", "Ext689", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt690MetricSet>( "Ext690", "Ext690", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt691MetricSet>( "Ext691", "Ext691", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt692MetricSet>( "Ext692", "Ext692", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt693MetricSet>( "Ext693", "Ext693", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt694MetricSet>( "Ext694", "Ext694", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt695MetricSet>( "Ext695", "Ext695", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt696MetricSet>( "Ext696", "Ext696", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt697MetricSet>( "Ext697", "Ext697", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt698MetricSet>( "Ext698", "Ext698", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt699MetricSet>( "Ext699", "Ext699", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt700MetricSet>( "Ext700", "Ext700", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt701MetricSet>( "Ext701", "Ext701", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt702MetricSet>( "Ext702", "Ext702", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt703MetricSet>( "Ext703", "Ext703", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt704MetricSet>( "Ext704", "Ext704", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt705MetricSet>( "Ext705", "Ext705", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt706MetricSet>( "Ext706", "Ext706", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt707MetricSet>( "Ext707", "Ext707", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt708MetricSet>( "Ext708", "Ext708", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt709MetricSet>( "Ext709", "Ext709", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt710MetricSet>( "Ext710", "Ext710", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt711MetricSet>( "Ext711", "Ext711", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt712MetricSet>( "Ext712", "Ext712", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt713MetricSet>( "Ext713", "Ext713", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt714MetricSet>( "Ext714", "Ext714", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt715MetricSet>( "Ext715", "Ext715", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt716MetricSet>( "Ext716", "Ext716", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt717MetricSet>( "Ext717", "Ext717", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt718MetricSet>( "Ext718", "Ext718", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt719MetricSet>( "Ext719", "Ext719", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt720MetricSet>( "Ext720", "Ext720", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt721MetricSet>( "Ext721", "Ext721", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt722MetricSet>( "Ext722", "Ext722", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt723MetricSet>( "Ext723", "Ext723", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt724MetricSet>( "Ext724", "Ext724", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt725MetricSet>( "Ext725", "Ext725", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt726MetricSet>( "Ext726", "Ext726", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt727MetricSet>( "Ext727", "Ext727", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt728MetricSet>( "Ext728", "Ext728", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt729MetricSet>( "Ext729", "Ext729", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt730MetricSet>( "Ext730", "Ext730", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt731MetricSet>( "Ext731", "Ext731", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt732MetricSet>( "Ext732", "Ext732", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt733MetricSet>( "Ext733", "Ext733", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt734MetricSet>( "Ext734", "Ext734", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt735MetricSet>( "Ext735", "Ext735", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt736MetricSet>( "Ext736", "Ext736", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt737MetricSet>( "Ext737", "Ext737", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt738MetricSet>( "Ext738", "Ext738", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt739MetricSet>( "Ext739", "Ext739", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt740MetricSet>( "Ext740", "Ext740", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt741MetricSet>( "Ext741", "Ext741", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt742MetricSet>( "Ext742", "Ext742", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt743MetricSet>( "Ext743", "Ext743", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt744MetricSet>( "Ext744", "Ext744", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt745MetricSet>( "Ext745", "Ext745", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt746MetricSet>( "Ext746", "Ext746", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt747MetricSet>( "Ext747", "Ext747", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt748MetricSet>( "Ext748", "Ext748", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt749MetricSet>( "Ext749", "Ext749", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt750MetricSet>( "Ext750", "Ext750", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt751MetricSet>( "Ext751", "Ext751", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt752MetricSet>( "Ext752", "Ext752", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt753MetricSet>( "Ext753", "Ext753", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt754MetricSet>( "Ext754", "Ext754", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt755MetricSet>( "Ext755", "Ext755", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt756MetricSet>( "Ext756", "Ext756", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt757MetricSet>( "Ext757", "Ext757", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt758MetricSet>( "Ext758", "Ext758", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt759MetricSet>( "Ext759", "Ext759", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt760MetricSet>( "Ext760", "Ext760", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt761MetricSet>( "Ext761", "Ext761", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt762MetricSet>( "Ext762", "Ext762", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt763MetricSet>( "Ext763", "Ext763", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt764MetricSet>( "Ext764", "Ext764", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt765MetricSet>( "Ext765", "Ext765", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt766MetricSet>( "Ext766", "Ext766", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt767MetricSet>( "Ext767", "Ext767", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt768MetricSet>( "Ext768", "Ext768", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt769MetricSet>( "Ext769", "Ext769", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt770MetricSet>( "Ext770", "Ext770", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt771MetricSet>( "Ext771", "Ext771", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt772MetricSet>( "Ext772", "Ext772", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt773MetricSet>( "Ext773", "Ext773", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt774MetricSet>( "Ext774", "Ext774", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt775MetricSet>( "Ext775", "Ext775", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt776MetricSet>( "Ext776", "Ext776", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt777MetricSet>( "Ext777", "Ext777", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt778MetricSet>( "Ext778", "Ext778", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt779MetricSet>( "Ext779", "Ext779", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt780MetricSet>( "Ext780", "Ext780", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt781MetricSet>( "Ext781", "Ext781", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt782MetricSet>( "Ext782", "Ext782", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt783MetricSet>( "Ext783", "Ext783", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt784MetricSet>( "Ext784", "Ext784", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt785MetricSet>( "Ext785", "Ext785", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt786MetricSet>( "Ext786", "Ext786", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt787MetricSet>( "Ext787", "Ext787", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt788MetricSet>( "Ext788", "Ext788", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt789MetricSet>( "Ext789", "Ext789", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt790MetricSet>( "Ext790", "Ext790", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt791MetricSet>( "Ext791", "Ext791", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt792MetricSet>( "Ext792", "Ext792", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt793MetricSet>( "Ext793", "Ext793", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt794MetricSet>( "Ext794", "Ext794", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt795MetricSet>( "Ext795", "Ext795", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt796MetricSet>( "Ext796", "Ext796", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt797MetricSet>( "Ext797", "Ext797", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt798MetricSet>( "Ext798", "Ext798", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt799MetricSet>( "Ext799", "Ext799", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt800MetricSet>( "Ext800", "Ext800", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt801MetricSet>( "Ext801", "Ext801", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt802MetricSet>( "Ext802", "Ext802", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt803MetricSet>( "Ext803", "Ext803", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt804MetricSet>( "Ext804", "Ext804", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt805MetricSet>( "Ext805", "Ext805", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt806MetricSet>( "Ext806", "Ext806", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt807MetricSet>( "Ext807", "Ext807", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt808MetricSet>( "Ext808", "Ext808", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt809MetricSet>( "Ext809", "Ext809", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt810MetricSet>( "Ext810", "Ext810", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt811MetricSet>( "Ext811", "Ext811", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt812MetricSet>( "Ext812", "Ext812", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt813MetricSet>( "Ext813", "Ext813", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt814MetricSet>( "Ext814", "Ext814", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt815MetricSet>( "Ext815", "Ext815", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt816MetricSet>( "Ext816", "Ext816", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt817MetricSet>( "Ext817", "Ext817", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt818MetricSet>( "Ext818", "Ext818", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt819MetricSet>( "Ext819", "Ext819", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt820MetricSet>( "Ext820", "Ext820", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt821MetricSet>( "Ext821", "Ext821", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt822MetricSet>( "Ext822", "Ext822", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt823MetricSet>( "Ext823", "Ext823", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt824MetricSet>( "Ext824", "Ext824", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt825MetricSet>( "Ext825", "Ext825", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt826MetricSet>( "Ext826", "Ext826", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt827MetricSet>( "Ext827", "Ext827", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt828MetricSet>( "Ext828", "Ext828", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt829MetricSet>( "Ext829", "Ext829", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt830MetricSet>( "Ext830", "Ext830", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt831MetricSet>( "Ext831", "Ext831", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt832MetricSet>( "Ext832", "Ext832", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt833MetricSet>( "Ext833", "Ext833", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt834MetricSet>( "Ext834", "Ext834", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt835MetricSet>( "Ext835", "Ext835", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt836MetricSet>( "Ext836", "Ext836", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt837MetricSet>( "Ext837", "Ext837", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt838MetricSet>( "Ext838", "Ext838", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt839MetricSet>( "Ext839", "Ext839", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt840MetricSet>( "Ext840", "Ext840", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt841MetricSet>( "Ext841", "Ext841", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt842MetricSet>( "Ext842", "Ext842", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt843MetricSet>( "Ext843", "Ext843", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt844MetricSet>( "Ext844", "Ext844", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt845MetricSet>( "Ext845", "Ext845", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt846MetricSet>( "Ext846", "Ext846", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt847MetricSet>( "Ext847", "Ext847", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt848MetricSet>( "Ext848", "Ext848", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt849MetricSet>( "Ext849", "Ext849", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt850MetricSet>( "Ext850", "Ext850", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt851MetricSet>( "Ext851", "Ext851", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt852MetricSet>( "Ext852", "Ext852", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt853MetricSet>( "Ext853", "Ext853", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt854MetricSet>( "Ext854", "Ext854", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt855MetricSet>( "Ext855", "Ext855", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt856MetricSet>( "Ext856", "Ext856", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt857MetricSet>( "Ext857", "Ext857", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt858MetricSet>( "Ext858", "Ext858", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt859MetricSet>( "Ext859", "Ext859", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt860MetricSet>( "Ext860", "Ext860", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt861MetricSet>( "Ext861", "Ext861", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt862MetricSet>( "Ext862", "Ext862", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt863MetricSet>( "Ext863", "Ext863", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt864MetricSet>( "Ext864", "Ext864", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt865MetricSet>( "Ext865", "Ext865", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt866MetricSet>( "Ext866", "Ext866", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt867MetricSet>( "Ext867", "Ext867", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt868MetricSet>( "Ext868", "Ext868", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt869MetricSet>( "Ext869", "Ext869", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt870MetricSet>( "Ext870", "Ext870", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt871MetricSet>( "Ext871", "Ext871", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt872MetricSet>( "Ext872", "Ext872", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt873MetricSet>( "Ext873", "Ext873", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt874MetricSet>( "Ext874", "Ext874", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt875MetricSet>( "Ext875", "Ext875", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt876MetricSet>( "Ext876", "Ext876", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt877MetricSet>( "Ext877", "Ext877", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt878MetricSet>( "Ext878", "Ext878", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt879MetricSet>( "Ext879", "Ext879", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt880MetricSet>( "Ext880", "Ext880", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt881MetricSet>( "Ext881", "Ext881", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt882MetricSet>( "Ext882", "Ext882", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt883MetricSet>( "Ext883", "Ext883", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt884MetricSet>( "Ext884", "Ext884", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt885MetricSet>( "Ext885", "Ext885", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt886MetricSet>( "Ext886", "Ext886", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt887MetricSet>( "Ext887", "Ext887", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt888MetricSet>( "Ext888", "Ext888", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt889MetricSet>( "Ext889", "Ext889", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt890MetricSet>( "Ext890", "Ext890", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt891MetricSet>( "Ext891", "Ext891", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt892MetricSet>( "Ext892", "Ext892", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt893MetricSet>( "Ext893", "Ext893", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt894MetricSet>( "Ext894", "Ext894", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt895MetricSet>( "Ext895", "Ext895", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt896MetricSet>( "Ext896", "Ext896", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt897MetricSet>( "Ext897", "Ext897", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt898MetricSet>( "Ext898", "Ext898", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt899MetricSet>( "Ext899", "Ext899", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt900MetricSet>( "Ext900", "Ext900", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt901MetricSet>( "Ext901", "Ext901", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt902MetricSet>( "Ext902", "Ext902", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt903MetricSet>( "Ext903", "Ext903", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt904MetricSet>( "Ext904", "Ext904", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt905MetricSet>( "Ext905", "Ext905", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt906MetricSet>( "Ext906", "Ext906", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt907MetricSet>( "Ext907", "Ext907", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt908MetricSet>( "Ext908", "Ext908", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt909MetricSet>( "Ext909", "Ext909", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt910MetricSet>( "Ext910", "Ext910", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt911MetricSet>( "Ext911", "Ext911", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt912MetricSet>( "Ext912", "Ext912", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt913MetricSet>( "Ext913", "Ext913", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt914MetricSet>( "Ext914", "Ext914", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt915MetricSet>( "Ext915", "Ext915", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt916MetricSet>( "Ext916", "Ext916", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt917MetricSet>( "Ext917", "Ext917", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt918MetricSet>( "Ext918", "Ext918", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt919MetricSet>( "Ext919", "Ext919", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt920MetricSet>( "Ext920", "Ext920", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt921MetricSet>( "Ext921", "Ext921", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt922MetricSet>( "Ext922", "Ext922", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt923MetricSet>( "Ext923", "Ext923", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt924MetricSet>( "Ext924", "Ext924", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt925MetricSet>( "Ext925", "Ext925", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt926MetricSet>( "Ext926", "Ext926", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt927MetricSet>( "Ext927", "Ext927", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt928MetricSet>( "Ext928", "Ext928", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt929MetricSet>( "Ext929", "Ext929", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt930MetricSet>( "Ext930", "Ext930", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt931MetricSet>( "Ext931", "Ext931", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt932MetricSet>( "Ext932", "Ext932", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt933MetricSet>( "Ext933", "Ext933", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt934MetricSet>( "Ext934", "Ext934", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt935MetricSet>( "Ext935", "Ext935", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt936MetricSet>( "Ext936", "Ext936", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt937MetricSet>( "Ext937", "Ext937", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt938MetricSet>( "Ext938", "Ext938", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt939MetricSet>( "Ext939", "Ext939", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt940MetricSet>( "Ext940", "Ext940", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt941MetricSet>( "Ext941", "Ext941", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt942MetricSet>( "Ext942", "Ext942", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt943MetricSet>( "Ext943", "Ext943", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt944MetricSet>( "Ext944", "Ext944", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt945MetricSet>( "Ext945", "Ext945", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt946MetricSet>( "Ext946", "Ext946", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt947MetricSet>( "Ext947", "Ext947", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt948MetricSet>( "Ext948", "Ext948", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt949MetricSet>( "Ext949", "Ext949", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt950MetricSet>( "Ext950", "Ext950", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt951MetricSet>( "Ext951", "Ext951", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt952MetricSet>( "Ext952", "Ext952", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt953MetricSet>( "Ext953", "Ext953", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt954MetricSet>( "Ext954", "Ext954", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt955MetricSet>( "Ext955", "Ext955", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt956MetricSet>( "Ext956", "Ext956", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt957MetricSet>( "Ext957", "Ext957", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt958MetricSet>( "Ext958", "Ext958", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt959MetricSet>( "Ext959", "Ext959", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt960MetricSet>( "Ext960", "Ext960", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt961MetricSet>( "Ext961", "Ext961", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt962MetricSet>( "Ext962", "Ext962", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt963MetricSet>( "Ext963", "Ext963", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt964MetricSet>( "Ext964", "Ext964", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt965MetricSet>( "Ext965", "Ext965", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt966MetricSet>( "Ext966", "Ext966", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt967MetricSet>( "Ext967", "Ext967", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt968MetricSet>( "Ext968", "Ext968", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt969MetricSet>( "Ext969", "Ext969", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt970MetricSet>( "Ext970", "Ext970", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt971MetricSet>( "Ext971", "Ext971", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt972MetricSet>( "Ext972", "Ext972", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt973MetricSet>( "Ext973", "Ext973", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt974MetricSet>( "Ext974", "Ext974", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt975MetricSet>( "Ext975", "Ext975", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt976MetricSet>( "Ext976", "Ext976", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt977MetricSet>( "Ext977", "Ext977", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt978MetricSet>( "Ext978", "Ext978", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt979MetricSet>( "Ext979", "Ext979", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt980MetricSet>( "Ext980", "Ext980", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt981MetricSet>( "Ext981", "Ext981", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt982MetricSet>( "Ext982", "Ext982", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt983MetricSet>( "Ext983", "Ext983", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt984MetricSet>( "Ext984", "Ext984", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt985MetricSet>( "Ext985", "Ext985", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt986MetricSet>( "Ext986", "Ext986", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt987MetricSet>( "Ext987", "Ext987", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt990MetricSet_Refresh>( "Ext990", "Ext990", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt991MetricSet_Refresh>( "Ext991", "Ext991", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt992MetricSet_Refresh>( "Ext992", "Ext992", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt993MetricSet_Refresh>( "Ext993", "Ext993", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt994MetricSet_Refresh>( "Ext994", "Ext994", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt995MetricSet_Refresh>( "Ext995", "Ext995", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt996MetricSet_Refresh>( "Ext996", "Ext996", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt997MetricSet_Refresh>( "Ext997", "Ext997", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1000MetricSet>( "Ext1000", "Ext1000", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1001MetricSet>( "Ext1001", "Ext1001", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1002MetricSet>( "Ext1002", "Ext1002", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1004MetricSet>( "Ext1004", "Ext1004", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1005MetricSet>( "Ext1005", "Ext1005", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1006MetricSet>( "Ext1006", "Ext1006", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1007MetricSet>( "Ext1007", "Ext1007", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1010MetricSet_Refresh>( "Ext1010", "Ext1010", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1010MetricSet_FirstVersion>( "Ext1010", "Ext1010", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1100MetricSet_Refresh>( "Ext1100", "Ext1100", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1101MetricSet_Refresh>( "Ext1101", "Ext1101", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1102MetricSet_Refresh>( "Ext1102", "Ext1102", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1103MetricSet_Refresh>( "Ext1103", "Ext1103", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1104MetricSet_Refresh>( "Ext1104", "Ext1104", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1105MetricSet_Refresh>( "Ext1105", "Ext1105", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1106MetricSet_Refresh>( "Ext1106", "Ext1106", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1107MetricSet_Refresh>( "Ext1107", "Ext1107", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 UGTE", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1100MetricSet_FirstVersion>( "Ext1100", "Ext1100", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1101MetricSet_FirstVersion>( "Ext1101", "Ext1101", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1102MetricSet_FirstVersion>( "Ext1102", "Ext1102", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1103MetricSet_FirstVersion>( "Ext1103", "Ext1103", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1104MetricSet_FirstVersion>( "Ext1104", "Ext1104", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1105MetricSet_FirstVersion>( "Ext1105", "Ext1105", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1106MetricSet_FirstVersion>( "Ext1106", "Ext1106", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1107MetricSet_FirstVersion>( "Ext1107", "Ext1107", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$PlatformVersion 1 ULT", GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1208MetricSet>( "Ext1208", "Ext1208", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1209MetricSet>( "Ext1209", "Ext1209", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1210MetricSet>( "Ext1210", "Ext1210", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1211MetricSet>( "Ext1211", "Ext1211", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1212MetricSet>( "Ext1212", "Ext1212", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1213MetricSet>( "Ext1213", "Ext1213", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1214MetricSet>( "Ext1214", "Ext1214", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1215MetricSet>( "Ext1215", "Ext1215", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1216MetricSet>( "Ext1216", "Ext1216", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1217MetricSet>( "Ext1217", "Ext1217", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1218MetricSet>( "Ext1218", "Ext1218", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1219MetricSet>( "Ext1219", "Ext1219", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1220MetricSet>( "Ext1220", "Ext1220", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1221MetricSet>( "Ext1221", "Ext1221", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1222MetricSet>( "Ext1222", "Ext1222", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_ACM_GT3_OA::CExt1223MetricSet>( "Ext1223", "Ext1223", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT3 );
        MD_CHECK_PTR( metricSet );
    }

    MD_LOG_EXIT_A( adapterId );
    return CC_OK;

exception:
    MD_LOG_EXIT_A( adapterId );
    return CC_ERROR_NO_MEMORY;
}
#endif
