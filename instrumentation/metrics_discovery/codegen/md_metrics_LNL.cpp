/*========================== begin_copyright_notice ============================

Copyright (C) 2024 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_metrics_LNL.cpp

//     Abstract:   C++ automated generated file to stack metrics meta data

#include "md_per_platform_preamble.h"
#include "md_metric_sets_LNL.h"

using namespace MetricsDiscoveryInternal;

#if( ( !defined( MD_INCLUDE_LNL_METRICS ) && MD_INCLUDE_ALL_METRICS ) || MD_INCLUDE_LNL_METRICS )

TCompletionCode CreateMetricTreeLNL_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup )
{
    const uint32_t adapterId = OBTAIN_ADAPTER_ID( metricsDevice );

    MD_LOG_ENTER_A( adapterId );
    MD_CHECK_PTR_RET_A( adapterId, metricsDevice, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET_A( adapterId, concurrentGroup, CC_ERROR_INVALID_PARAMETER );

    CMetricSet*      metricSet                                               = nullptr;
    uint8_t          platformMaskByteArray[MD_PLATFORM_MASK_BYTE_ARRAY_SIZE] = {};
    TByteArrayLatest platformMask                                            = { MD_PLATFORM_MASK_BYTE_ARRAY_SIZE, platformMaskByteArray };

    MD_CHECK_CC( SetPlatformMask( adapterId, &platformMask, nullptr, false, GENERATION_LNL ) );

    if( metricsDevice->IsPlatformTypeOf( &platformMask ) )
    {
        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_LNL_PipelineStatistics::CPipelineStatsMetricSet>( "PipelineStats", "Pipeline Statistics for OGL4", API_TYPE_OGL | API_TYPE_OGL4_X,
            GPU_RENDER | GPU_COMPUTE, 0, 96, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr );
        MD_CHECK_PTR( metricSet );
    }

    MD_LOG_EXIT_A( adapterId );
    return CC_OK;

exception:
    MD_LOG_EXIT_A( adapterId );
    return CC_ERROR_NO_MEMORY;
}
#endif

#if( ( !defined( MD_INCLUDE_LNL_METRICS ) && MD_INCLUDE_ALL_METRICS ) || MD_INCLUDE_LNL_METRICS )

TCompletionCode CreateMetricTreeLNL_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup )
{
    const uint32_t adapterId = OBTAIN_ADAPTER_ID( metricsDevice );

    MD_LOG_ENTER_A( adapterId );
    MD_CHECK_PTR_RET_A( adapterId, metricsDevice, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET_A( adapterId, concurrentGroup, CC_ERROR_INVALID_PARAMETER );

    CMetricSet*      metricSet                                               = nullptr;
    uint8_t          platformMaskByteArray[MD_PLATFORM_MASK_BYTE_ARRAY_SIZE] = {};
    TByteArrayLatest platformMask                                            = { MD_PLATFORM_MASK_BYTE_ARRAY_SIZE, platformMaskByteArray };

    MD_CHECK_CC( SetPlatformMask( adapterId, &platformMask, nullptr, false, GENERATION_LNL ) );

    if( metricsDevice->IsPlatformTypeOf( &platformMask ) )
    {
        MetricSets_LNL_OA::AddInformationSet( concurrentGroup );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_LNL_OA::CRenderBasicMetricSet>( "RenderBasic", "RenderBasic", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 576, 880, OA_REPORT_TYPE_576B_PEC64LL, &platformMask, nullptr );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_LNL_OA::CComputeBasicMetricSet>( "ComputeBasic", "ComputeBasic", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 576, 880, OA_REPORT_TYPE_576B_PEC64LL, &platformMask, nullptr );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_LNL_OA::CDepthProfileMetricSet>( "DepthProfile", "DepthProfile", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 576, 880, OA_REPORT_TYPE_576B_PEC64LL, &platformMask, nullptr );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_LNL_OA::CDeviceCacheProfileMetricSet>( "DeviceCacheProfile", "DeviceCacheProfile", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 576, 880, OA_REPORT_TYPE_576B_PEC64LL, &platformMask, nullptr );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_LNL_OA::CMemoryProfileMetricSet>( "MemoryProfile", "MemoryProfile", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 576, 880, OA_REPORT_TYPE_576B_PEC64LL, &platformMask, nullptr );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_LNL_OA::CRenderPipeProfileMetricSet>( "RenderPipeProfile", "RenderPipeProfile", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 576, 880, OA_REPORT_TYPE_576B_PEC64LL, &platformMask, nullptr );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_LNL_OA::CRTProfileMetricSet>( "RTProfile", "RTProfile", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 576, 880, OA_REPORT_TYPE_576B_PEC64LL, &platformMask, nullptr );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_LNL_OA::CVectorEngineProfileMetricSet>( "VectorEngineProfile", "VectorEngineProfile", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 576, 880, OA_REPORT_TYPE_576B_PEC64LL, &platformMask, nullptr );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_LNL_OA::CVectorEngineStallsMetricSet>( "VectorEngineStalls", "VectorEngineStalls", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 576, 880, OA_REPORT_TYPE_576B_PEC64LL, &platformMask, nullptr );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_LNL_OA::CTestOaMetricSet>( "TestOa", "TestOa", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 576, 880, OA_REPORT_TYPE_576B_PEC64LL, &platformMask, nullptr );
        MD_CHECK_PTR( metricSet );
    }

    MD_LOG_EXIT_A( adapterId );
    return CC_OK;

exception:
    MD_LOG_EXIT_A( adapterId );
    return CC_ERROR_NO_MEMORY;
}
#endif

#if( ( !defined( MD_INCLUDE_LNL_METRICS ) && MD_INCLUDE_ALL_METRICS ) || MD_INCLUDE_LNL_METRICS )

TCompletionCode CreateMetricTreeLNL_OAM0( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup )
{
    const uint32_t adapterId = OBTAIN_ADAPTER_ID( metricsDevice );

    MD_LOG_ENTER_A( adapterId );
    MD_CHECK_PTR_RET_A( adapterId, metricsDevice, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET_A( adapterId, concurrentGroup, CC_ERROR_INVALID_PARAMETER );

    CMetricSet*      metricSet                                               = nullptr;
    uint8_t          platformMaskByteArray[MD_PLATFORM_MASK_BYTE_ARRAY_SIZE] = {};
    TByteArrayLatest platformMask                                            = { MD_PLATFORM_MASK_BYTE_ARRAY_SIZE, platformMaskByteArray };

    MD_CHECK_CC( SetPlatformMask( adapterId, &platformMask, nullptr, false, GENERATION_LNL ) );

    if( metricsDevice->IsPlatformTypeOf( &platformMask ) )
    {
        MetricSets_LNL_OAM0::AddInformationSet( concurrentGroup );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_LNL_OAM0::CMediaSet1MetricSet>( "MediaSet1", "MediaSet1", API_TYPE_IOSTREAM,
            GPU_MEDIA | GPU_GENERIC, 128, 0, OA_REPORT_TYPE_128B_MPEC8_NOA16, &platformMask, nullptr );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_LNL_OAM0::CMediaSet2MetricSet>( "MediaSet2", "MediaSet2", API_TYPE_IOSTREAM,
            GPU_MEDIA | GPU_GENERIC, 128, 0, OA_REPORT_TYPE_128B_MPEC8_NOA16, &platformMask, nullptr );
        MD_CHECK_PTR( metricSet );
    }

    MD_LOG_EXIT_A( adapterId );
    return CC_OK;

exception:
    MD_LOG_EXIT_A( adapterId );
    return CC_ERROR_NO_MEMORY;
}
#endif

#if( ( !defined( MD_INCLUDE_LNL_METRICS ) && MD_INCLUDE_ALL_METRICS ) || MD_INCLUDE_LNL_METRICS )

TCompletionCode CreateMetricTreeLNL_OAMG( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup )
{
    const uint32_t adapterId = OBTAIN_ADAPTER_ID( metricsDevice );

    MD_LOG_ENTER_A( adapterId );
    MD_CHECK_PTR_RET_A( adapterId, metricsDevice, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET_A( adapterId, concurrentGroup, CC_ERROR_INVALID_PARAMETER );

    CMetricSet*      metricSet                                               = nullptr;
    uint8_t          platformMaskByteArray[MD_PLATFORM_MASK_BYTE_ARRAY_SIZE] = {};
    TByteArrayLatest platformMask                                            = { MD_PLATFORM_MASK_BYTE_ARRAY_SIZE, platformMaskByteArray };

    MD_CHECK_CC( SetPlatformMask( adapterId, &platformMask, nullptr, false, GENERATION_LNL ) );

    if( metricsDevice->IsPlatformTypeOf( &platformMask ) )
    {
        MetricSets_LNL_OAMG::AddInformationSet( concurrentGroup );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_LNL_OAMG::CMediaSet1MetricSet>( "MediaSet1", "MediaSet1", API_TYPE_IOSTREAM,
            GPU_MEDIA | GPU_GENERIC, 128, 0, OA_REPORT_TYPE_128B_MPEC8_NOA16, &platformMask, nullptr );
        MD_CHECK_PTR( metricSet );
    }

    MD_LOG_EXIT_A( adapterId );
    return CC_OK;

exception:
    MD_LOG_EXIT_A( adapterId );
    return CC_ERROR_NO_MEMORY;
}
#endif
