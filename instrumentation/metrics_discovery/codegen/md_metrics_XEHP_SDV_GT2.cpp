/*========================== begin_copyright_notice ============================

Copyright (C) 2021-2023 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_metrics_XEHP_SDV_GT2.cpp

//     Abstract:   C++ automated generated file to stack metrics meta data

#include "md_per_platform_preamble.h"
#include "md_metric_sets_XEHP_SDV_GT2.h"

#if( ( !defined( MD_INCLUDE_XEHP_SDV_GT2_METRICS ) && MD_INCLUDE_ALL_METRICS ) || MD_INCLUDE_XEHP_SDV_GT2_METRICS )

using namespace MetricsDiscoveryInternal;

TCompletionCode CreateMetricTreeXEHP_SDV_GT2_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup )
{
    const uint32_t adapterId = OBTAIN_ADAPTER_ID( metricsDevice );

    MD_LOG_ENTER_A( adapterId );
    MD_CHECK_PTR_RET_A( adapterId, metricsDevice, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET_A( adapterId, concurrentGroup, CC_ERROR_INVALID_PARAMETER );

    CMetricSet*      metricSet                                               = nullptr;
    uint8_t          platformMaskByteArray[MD_PLATFORM_MASK_BYTE_ARRAY_SIZE] = {};
    TByteArrayLatest platformMask                                            = { MD_PLATFORM_MASK_BYTE_ARRAY_SIZE, platformMaskByteArray };

    MD_CHECK_CC( SetPlatformMask( adapterId, &platformMask, nullptr, false, GENERATION_XEHP_SDV ) );

    if( metricsDevice->IsPlatformTypeOf( &platformMask, GT_TYPE_GT2 ) )
    {
        MetricSets_XEHP_SDV_GT2_OA::AddInformationSet( concurrentGroup );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_XEHP_SDV_GT2_OA::CRenderBasicMetricSet>( "RenderBasic", "Render Basic Metrics", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_XEHP_SDV_GT2_OA::CComputeBasicMetricSet>( "ComputeBasic", "Compute Basic Metrics", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_XEHP_SDV_GT2_OA::CEuActivity1MetricSet>( "EuActivity1", "EuActivity1", API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_XEHP_SDV_GT2_OA::CEuActivity2MetricSet>( "EuActivity2", "EuActivity2", API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_XEHP_SDV_GT2_OA::CEuActivity3MetricSet>( "EuActivity3", "EuActivity3", API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_XEHP_SDV_GT2_OA::CEuActivity4MetricSet>( "EuActivity4", "EuActivity4", API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_XEHP_SDV_GT2_OA::CEuActivity5MetricSet>( "EuActivity5", "EuActivity5", API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_XEHP_SDV_GT2_OA::CEuActivity6MetricSet>( "EuActivity6", "EuActivity6", API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_XEHP_SDV_GT2_OA::CEuActivity7MetricSet>( "EuActivity7", "EuActivity7", API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_XEHP_SDV_GT2_OA::CEuActivity8MetricSet>( "EuActivity8", "EuActivity8", API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_XEHP_SDV_GT2_OA::CGpuBusynessMetricSet>( "GpuBusyness", "GpuBusyness", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_XEHP_SDV_GT2_OA::CTestOaMetricSet>( "TestOa", "Test Metrics", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_MEDIA | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );
    }

    MD_LOG_EXIT_A( adapterId );
    return CC_OK;

exception:
    MD_LOG_EXIT_A( adapterId );
    return CC_ERROR_NO_MEMORY;
}
#endif
