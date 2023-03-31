/*========================== begin_copyright_notice ============================

Copyright (C) 2019-2023 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_metrics.cpp

//     Abstract:   C++ automated generated file to stack metrics meta data

#include "md_metrics.h"
#include "md_per_platform_preamble.h"
#include "md_metric_sets_common.h"

using namespace MetricsDiscoveryInternal;

#if MD_INCLUDE_HSW_METRICS
    #define MD_CALL_HSW_METRICS 1
TCompletionCode CreateMetricTreeHSW_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_BDW_METRICS
    #define MD_CALL_BDW_METRICS 1
TCompletionCode CreateMetricTreeBDW_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_SKL_GT2_METRICS
    #define MD_CALL_SKL_GT2_METRICS 1
TCompletionCode CreateMetricTreeSKL_GT2_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_SKL_GT3_METRICS
    #define MD_CALL_SKL_GT3_METRICS 1
TCompletionCode CreateMetricTreeSKL_GT3_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_SKL_GT4_METRICS
    #define MD_CALL_SKL_GT4_METRICS 1
TCompletionCode CreateMetricTreeSKL_GT4_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_BXT_METRICS
    #define MD_CALL_BXT_METRICS 1
TCompletionCode CreateMetricTreeBXT_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_KBL_GT2_METRICS
    #define MD_CALL_KBL_GT2_METRICS 1
TCompletionCode CreateMetricTreeKBL_GT2_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_KBL_GT3_METRICS
    #define MD_CALL_KBL_GT3_METRICS 1
TCompletionCode CreateMetricTreeKBL_GT3_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_CFL_GT2_METRICS
    #define MD_CALL_CFL_GT2_METRICS 1
TCompletionCode CreateMetricTreeCFL_GT2_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_CFL_GT3_METRICS
    #define MD_CALL_CFL_GT3_METRICS 1
TCompletionCode CreateMetricTreeCFL_GT3_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_GLK_METRICS
    #define MD_CALL_GLK_METRICS 1
TCompletionCode CreateMetricTreeGLK_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_ICL_METRICS
    #define MD_CALL_ICL_METRICS 1
TCompletionCode CreateMetricTreeICL_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_EHL_METRICS
    #define MD_CALL_EHL_METRICS 1
TCompletionCode CreateMetricTreeEHL_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_TGL_GT1_METRICS
    #define MD_CALL_TGL_GT1_METRICS 1
TCompletionCode CreateMetricTreeTGL_GT1_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_TGL_GT2_METRICS
    #define MD_CALL_TGL_GT2_METRICS 1
TCompletionCode CreateMetricTreeTGL_GT2_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_DG1_METRICS
    #define MD_CALL_DG1_METRICS 1
TCompletionCode CreateMetricTreeDG1_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_RKL_METRICS
    #define MD_CALL_RKL_METRICS 1
TCompletionCode CreateMetricTreeRKL_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_XEHP_SDV_GT1_GT2_METRICS
    #define MD_CALL_XEHP_SDV_GT1_GT2_METRICS 1
TCompletionCode CreateMetricTreeXEHP_SDV_GT1_GT2_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_ACM_GT1_METRICS
    #define MD_CALL_ACM_GT1_METRICS 1
TCompletionCode CreateMetricTreeACM_GT1_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_ACM_GT2_METRICS
    #define MD_CALL_ACM_GT2_METRICS 1
TCompletionCode CreateMetricTreeACM_GT2_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_ACM_GT3_METRICS
    #define MD_CALL_ACM_GT3_METRICS 1
TCompletionCode CreateMetricTreeACM_GT3_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_PVC_GT1_METRICS
    #define MD_CALL_PVC_GT1_METRICS 1
TCompletionCode CreateMetricTreePVC_GT1_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_PVC_GT2_METRICS
    #define MD_CALL_PVC_GT2_METRICS 1
TCompletionCode CreateMetricTreePVC_GT2_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_ADLP_METRICS
    #define MD_CALL_ADLP_METRICS 1
TCompletionCode CreateMetricTreeADLP_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_ADLS_METRICS
    #define MD_CALL_ADLS_METRICS 1
TCompletionCode CreateMetricTreeADLS_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_ADLN_METRICS
    #define MD_CALL_ADLN_METRICS 1
TCompletionCode CreateMetricTreeADLN_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_MTL_GT2_METRICS
    #define MD_CALL_MTL_GT2_METRICS 1
TCompletionCode CreateMetricTreeMTL_GT2_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_MTL_GT3_METRICS
    #define MD_CALL_MTL_GT3_METRICS 1
TCompletionCode CreateMetricTreeMTL_GT3_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_HSW_METRICS
    #define MD_CALL_HSW_METRICS 1
TCompletionCode CreateMetricTreeHSW_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_BDW_METRICS
    #define MD_CALL_BDW_METRICS 1
TCompletionCode CreateMetricTreeBDW_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_SKL_GT2_METRICS
    #define MD_CALL_SKL_GT2_METRICS 1
TCompletionCode CreateMetricTreeSKL_GT2_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_SKL_GT3_METRICS
    #define MD_CALL_SKL_GT3_METRICS 1
TCompletionCode CreateMetricTreeSKL_GT3_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_SKL_GT4_METRICS
    #define MD_CALL_SKL_GT4_METRICS 1
TCompletionCode CreateMetricTreeSKL_GT4_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_BXT_METRICS
    #define MD_CALL_BXT_METRICS 1
TCompletionCode CreateMetricTreeBXT_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_KBL_GT2_METRICS
    #define MD_CALL_KBL_GT2_METRICS 1
TCompletionCode CreateMetricTreeKBL_GT2_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_KBL_GT3_METRICS
    #define MD_CALL_KBL_GT3_METRICS 1
TCompletionCode CreateMetricTreeKBL_GT3_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_CFL_GT2_METRICS
    #define MD_CALL_CFL_GT2_METRICS 1
TCompletionCode CreateMetricTreeCFL_GT2_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_CFL_GT3_METRICS
    #define MD_CALL_CFL_GT3_METRICS 1
TCompletionCode CreateMetricTreeCFL_GT3_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_GLK_METRICS
    #define MD_CALL_GLK_METRICS 1
TCompletionCode CreateMetricTreeGLK_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_ICL_METRICS
    #define MD_CALL_ICL_METRICS 1
TCompletionCode CreateMetricTreeICL_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_EHL_METRICS
    #define MD_CALL_EHL_METRICS 1
TCompletionCode CreateMetricTreeEHL_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_TGL_GT1_METRICS
    #define MD_CALL_TGL_GT1_METRICS 1
TCompletionCode CreateMetricTreeTGL_GT1_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_TGL_GT2_METRICS
    #define MD_CALL_TGL_GT2_METRICS 1
TCompletionCode CreateMetricTreeTGL_GT2_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_DG1_METRICS
    #define MD_CALL_DG1_METRICS 1
TCompletionCode CreateMetricTreeDG1_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_RKL_METRICS
    #define MD_CALL_RKL_METRICS 1
TCompletionCode CreateMetricTreeRKL_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_XEHP_SDV_GT1_GT2_METRICS
    #define MD_CALL_XEHP_SDV_GT1_GT2_METRICS 1
TCompletionCode CreateMetricTreeXEHP_SDV_GT1_GT2_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_XEHP_SDV_GT1_METRICS
    #define MD_CALL_XEHP_SDV_GT1_METRICS 1
TCompletionCode CreateMetricTreeXEHP_SDV_GT1_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_XEHP_SDV_GT2_METRICS
    #define MD_CALL_XEHP_SDV_GT2_METRICS 1
TCompletionCode CreateMetricTreeXEHP_SDV_GT2_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_ACM_GT1_METRICS
    #define MD_CALL_ACM_GT1_METRICS 1
TCompletionCode CreateMetricTreeACM_GT1_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_ACM_GT2_METRICS
    #define MD_CALL_ACM_GT2_METRICS 1
TCompletionCode CreateMetricTreeACM_GT2_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_ACM_GT3_METRICS
    #define MD_CALL_ACM_GT3_METRICS 1
TCompletionCode CreateMetricTreeACM_GT3_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_PVC_GT1_METRICS
    #define MD_CALL_PVC_GT1_METRICS 1
TCompletionCode CreateMetricTreePVC_GT1_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_PVC_GT2_METRICS
    #define MD_CALL_PVC_GT2_METRICS 1
TCompletionCode CreateMetricTreePVC_GT2_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_ADLP_METRICS
    #define MD_CALL_ADLP_METRICS 1
TCompletionCode CreateMetricTreeADLP_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_ADLS_METRICS
    #define MD_CALL_ADLS_METRICS 1
TCompletionCode CreateMetricTreeADLS_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_ADLN_METRICS
    #define MD_CALL_ADLN_METRICS 1
TCompletionCode CreateMetricTreeADLN_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_MTL_GT2_METRICS
    #define MD_CALL_MTL_GT2_METRICS 1
TCompletionCode CreateMetricTreeMTL_GT2_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_MTL_GT3_METRICS
    #define MD_CALL_MTL_GT3_METRICS 1
TCompletionCode CreateMetricTreeMTL_GT3_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_MTL_GT2_METRICS
    #define MD_CALL_MTL_GT2_METRICS 1
TCompletionCode CreateMetricTreeMTL_GT2_OAM0( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

#if MD_INCLUDE_MTL_GT3_METRICS
    #define MD_CALL_MTL_GT3_METRICS 1
TCompletionCode CreateMetricTreeMTL_GT3_OAM0( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup );
#endif

inline TCompletionCode AddGlobalSymbols( CMetricsDevice* metricsDevice )
{
    const uint32_t adapterId = OBTAIN_ADAPTER_ID( metricsDevice );
    MD_CHECK_PTR_RET_A( adapterId, metricsDevice, CC_ERROR_INVALID_PARAMETER );

    TCompletionCode ret       = CC_OK;
    auto            symbolSet = metricsDevice->GetSymbolSet();
    MD_CHECK_PTR_RET_A( adapterId, symbolSet, CC_ERROR_INVALID_PARAMETER );

    ret = symbolSet->AddSymbolUINT32( "EuCoresTotalCount", 60, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "EuCoresPerSubsliceCount", 10, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "EuSubslicesTotalCount", 6, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "EuDualSubslicesTotalCount", 0, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "EuSlicesTotalCount", 2, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "EuThreadsCount", 8, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "SliceMask", 0x7, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT64( "SubsliceMask", 0x1FF, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT64( "DualSubsliceMask", 0x0, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolBYTEARRAY( "GtSliceMask", nullptr, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolBYTEARRAY( "GtSubsliceMask", nullptr, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolBYTEARRAY( "GtDualSubsliceMask", nullptr, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "SamplersTotalCount", 6, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "MemoryPeakThroghputMB", 25600, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "GpuMinFrequencyMHz", 650, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "GpuMaxFrequencyMHz", 1250, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "GpuCurrentFrequencyMHz", 1250, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "PciDeviceId", 0, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "SkuRevisionId", 0, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "PlatformIndex", 0, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "ApertureSize", 0, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "Capabilities", 0, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolBOOL( "PavpDisabled", false, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "NumberOfRenderOutputUnits", 0, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "NumberOfShadingUnits", 0, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "OABufferMinSize", 16384, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "OABufferMaxSize", 131072, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "MediaOABufferMinSize", 16384, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "MediaOABufferMaxSize", 16384, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "GpuTimestampFrequency", 12500000, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "EdramSize", 0, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "LLCSize", 0, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "L3Size", 0, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT64( "MaxTimestamp", 0, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "VectorEngineTotalCount", 60, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "VectorEnginePerXeCoreCount", 10, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "XeCoreTotalCount", 0, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "SliceTotalCount", 2, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "VectorEngineThreadsCount", 8, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT64( "XeCoreMask", 0x0, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolBYTEARRAY( "GtXeCoreMask", nullptr, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "L3BankTotalCount", 0, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "L3NodeTotalCount", 0, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "SqidiTotalCount", 0, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "PlatformVersion", 0, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "ComputeEngineTotalCount", 0, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    ret = symbolSet->AddSymbolUINT32( "CopyEngineTotalCount", 0, SYMBOL_TYPE_DETECT );
    MD_CHECK_CC_RET_A( adapterId, ret );

    metricsDevice->GetParams()->GlobalSymbolsCount = symbolSet->GetSymbolCount();

    return ret;
}

TCompletionCode CreateMetricTree( CMetricsDevice* metricsDevice )
{
    const uint32_t adapterId = OBTAIN_ADAPTER_ID( metricsDevice );

    MD_LOG_ENTER_A( adapterId );
    MD_CHECK_PTR_RET_A( adapterId, metricsDevice, CC_ERROR_INVALID_PARAMETER );

    CConcurrentGroup* concurrentGroup                                         = nullptr;
    bool              isSupported                                             = false;
    CMetricSet*       metricSet                                               = nullptr;
    uint8_t           platformMaskByteArray[MD_PLATFORM_MASK_BYTE_ARRAY_SIZE] = {};
    TByteArrayLatest  platformMask                                            = { MD_PLATFORM_MASK_BYTE_ARRAY_SIZE, platformMaskByteArray };

    MD_CHECK_CC( SetAllBitsPlatformMask( adapterId, &platformMask ) );
    MD_CHECK_CC( AddGlobalSymbols( metricsDevice ) );

    concurrentGroup = metricsDevice->AddConcurrentGroup( "OcclusionQueryStats", "Occlusion Query Statistics", MEASUREMENT_TYPE_DELTA_QUERY, isSupported );
    if( isSupported )
    {
        MD_CHECK_PTR( concurrentGroup );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_OcclusionQueryStats::CRenderedPixelsStatsMetricSet>( "RenderedPixelsStats", "Rendered Pixels Statistics", API_TYPE_VULKAN | API_TYPE_OGL4_X,
            GPU_RENDER, 0, 8, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_OcclusionQueryStats::CRenderedFragmentsStatsMetricSet>( "RenderedFragmentsStats", "Rendered Fragments Statistics", API_TYPE_OGL | API_TYPE_OGL4_X,
            GPU_RENDER, 0, 8, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr );
        MD_CHECK_PTR( metricSet );
    }
    else
    {
        MD_LOG_A( adapterId, LOG_INFO, "OcclusionQueryStats concurrent group is not supported!" );
    }

    concurrentGroup = metricsDevice->AddConcurrentGroup( "TimestampQuery", "Timestamp Query", MEASUREMENT_TYPE_SNAPSHOT_QUERY, isSupported );
    if( isSupported )
    {
        MD_CHECK_PTR( concurrentGroup );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_TimestampQuery::CGPUTimestampMetricSet>( "GPUTimestamp", "GPU Timestamp", API_TYPE_VULKAN | API_TYPE_OGL4_X,
            GPU_GENERIC, 8, 0, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr );
        MD_CHECK_PTR( metricSet );
    }
    else
    {
        MD_LOG_A( adapterId, LOG_INFO, "TimestampQuery concurrent group is not supported!" );
    }

    concurrentGroup = metricsDevice->AddConcurrentGroup( "PipelineStatistics", "Pipeline Statistics", MEASUREMENT_TYPE_DELTA_QUERY, isSupported );
    if( isSupported )
    {
        MD_CHECK_PTR( concurrentGroup );

        // Add platform specific metric sets
#if MD_CALL_HSW_METRICS
        MD_CHECK_CC( CreateMetricTreeHSW_PipelineStatistics( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_BDW_METRICS
        MD_CHECK_CC( CreateMetricTreeBDW_PipelineStatistics( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_SKL_GT2_METRICS
        MD_CHECK_CC( CreateMetricTreeSKL_GT2_PipelineStatistics( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_SKL_GT3_METRICS
        MD_CHECK_CC( CreateMetricTreeSKL_GT3_PipelineStatistics( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_SKL_GT4_METRICS
        MD_CHECK_CC( CreateMetricTreeSKL_GT4_PipelineStatistics( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_BXT_METRICS
        MD_CHECK_CC( CreateMetricTreeBXT_PipelineStatistics( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_KBL_GT2_METRICS
        MD_CHECK_CC( CreateMetricTreeKBL_GT2_PipelineStatistics( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_KBL_GT3_METRICS
        MD_CHECK_CC( CreateMetricTreeKBL_GT3_PipelineStatistics( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_CFL_GT2_METRICS
        MD_CHECK_CC( CreateMetricTreeCFL_GT2_PipelineStatistics( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_CFL_GT3_METRICS
        MD_CHECK_CC( CreateMetricTreeCFL_GT3_PipelineStatistics( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_GLK_METRICS
        MD_CHECK_CC( CreateMetricTreeGLK_PipelineStatistics( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_ICL_METRICS
        MD_CHECK_CC( CreateMetricTreeICL_PipelineStatistics( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_EHL_METRICS
        MD_CHECK_CC( CreateMetricTreeEHL_PipelineStatistics( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_TGL_GT1_METRICS
        MD_CHECK_CC( CreateMetricTreeTGL_GT1_PipelineStatistics( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_TGL_GT2_METRICS
        MD_CHECK_CC( CreateMetricTreeTGL_GT2_PipelineStatistics( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_DG1_METRICS
        MD_CHECK_CC( CreateMetricTreeDG1_PipelineStatistics( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_RKL_METRICS
        MD_CHECK_CC( CreateMetricTreeRKL_PipelineStatistics( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_XEHP_SDV_GT1_GT2_METRICS
        MD_CHECK_CC( CreateMetricTreeXEHP_SDV_GT1_GT2_PipelineStatistics( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_ACM_GT1_METRICS
        MD_CHECK_CC( CreateMetricTreeACM_GT1_PipelineStatistics( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_ACM_GT2_METRICS
        MD_CHECK_CC( CreateMetricTreeACM_GT2_PipelineStatistics( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_ACM_GT3_METRICS
        MD_CHECK_CC( CreateMetricTreeACM_GT3_PipelineStatistics( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_PVC_GT1_METRICS
        MD_CHECK_CC( CreateMetricTreePVC_GT1_PipelineStatistics( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_PVC_GT2_METRICS
        MD_CHECK_CC( CreateMetricTreePVC_GT2_PipelineStatistics( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_ADLP_METRICS
        MD_CHECK_CC( CreateMetricTreeADLP_PipelineStatistics( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_ADLS_METRICS
        MD_CHECK_CC( CreateMetricTreeADLS_PipelineStatistics( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_ADLN_METRICS
        MD_CHECK_CC( CreateMetricTreeADLN_PipelineStatistics( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_MTL_GT2_METRICS
        MD_CHECK_CC( CreateMetricTreeMTL_GT2_PipelineStatistics( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_MTL_GT3_METRICS
        MD_CHECK_CC( CreateMetricTreeMTL_GT3_PipelineStatistics( metricsDevice, concurrentGroup ) );
#endif
    }
    else
    {
        MD_LOG_A( adapterId, LOG_INFO, "PipelineStatistics concurrent group is not supported!" );
    }

    concurrentGroup = metricsDevice->AddConcurrentGroup( "OA", "OA Unit Metrics", MEASUREMENT_TYPE_DELTA_QUERY | MEASUREMENT_TYPE_SNAPSHOT_IO, isSupported );
    if( isSupported )
    {
        MD_CHECK_PTR( concurrentGroup );

        // Add platform specific metric sets
#if MD_CALL_HSW_METRICS
        MD_CHECK_CC( CreateMetricTreeHSW_OA( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_BDW_METRICS
        MD_CHECK_CC( CreateMetricTreeBDW_OA( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_SKL_GT2_METRICS
        MD_CHECK_CC( CreateMetricTreeSKL_GT2_OA( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_SKL_GT3_METRICS
        MD_CHECK_CC( CreateMetricTreeSKL_GT3_OA( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_SKL_GT4_METRICS
        MD_CHECK_CC( CreateMetricTreeSKL_GT4_OA( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_BXT_METRICS
        MD_CHECK_CC( CreateMetricTreeBXT_OA( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_KBL_GT2_METRICS
        MD_CHECK_CC( CreateMetricTreeKBL_GT2_OA( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_KBL_GT3_METRICS
        MD_CHECK_CC( CreateMetricTreeKBL_GT3_OA( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_CFL_GT2_METRICS
        MD_CHECK_CC( CreateMetricTreeCFL_GT2_OA( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_CFL_GT3_METRICS
        MD_CHECK_CC( CreateMetricTreeCFL_GT3_OA( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_GLK_METRICS
        MD_CHECK_CC( CreateMetricTreeGLK_OA( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_ICL_METRICS
        MD_CHECK_CC( CreateMetricTreeICL_OA( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_EHL_METRICS
        MD_CHECK_CC( CreateMetricTreeEHL_OA( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_TGL_GT1_METRICS
        MD_CHECK_CC( CreateMetricTreeTGL_GT1_OA( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_TGL_GT2_METRICS
        MD_CHECK_CC( CreateMetricTreeTGL_GT2_OA( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_DG1_METRICS
        MD_CHECK_CC( CreateMetricTreeDG1_OA( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_RKL_METRICS
        MD_CHECK_CC( CreateMetricTreeRKL_OA( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_XEHP_SDV_GT1_GT2_METRICS
        MD_CHECK_CC( CreateMetricTreeXEHP_SDV_GT1_GT2_OA( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_XEHP_SDV_GT1_METRICS
        MD_CHECK_CC( CreateMetricTreeXEHP_SDV_GT1_OA( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_XEHP_SDV_GT2_METRICS
        MD_CHECK_CC( CreateMetricTreeXEHP_SDV_GT2_OA( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_ACM_GT1_METRICS
        MD_CHECK_CC( CreateMetricTreeACM_GT1_OA( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_ACM_GT2_METRICS
        MD_CHECK_CC( CreateMetricTreeACM_GT2_OA( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_ACM_GT3_METRICS
        MD_CHECK_CC( CreateMetricTreeACM_GT3_OA( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_PVC_GT1_METRICS
        MD_CHECK_CC( CreateMetricTreePVC_GT1_OA( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_PVC_GT2_METRICS
        MD_CHECK_CC( CreateMetricTreePVC_GT2_OA( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_ADLP_METRICS
        MD_CHECK_CC( CreateMetricTreeADLP_OA( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_ADLS_METRICS
        MD_CHECK_CC( CreateMetricTreeADLS_OA( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_ADLN_METRICS
        MD_CHECK_CC( CreateMetricTreeADLN_OA( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_MTL_GT2_METRICS
        MD_CHECK_CC( CreateMetricTreeMTL_GT2_OA( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_MTL_GT3_METRICS
        MD_CHECK_CC( CreateMetricTreeMTL_GT3_OA( metricsDevice, concurrentGroup ) );
#endif
    }
    else
    {
        MD_LOG_A( adapterId, LOG_INFO, "OA concurrent group is not supported!" );
    }

    concurrentGroup = metricsDevice->AddConcurrentGroup( "OAM0", "OAM0 Unit Metrics", MEASUREMENT_TYPE_SNAPSHOT_IO, isSupported );
    if( isSupported )
    {
        MD_CHECK_PTR( concurrentGroup );

        // Add platform specific metric sets
#if MD_CALL_MTL_GT2_METRICS
        MD_CHECK_CC( CreateMetricTreeMTL_GT2_OAM0( metricsDevice, concurrentGroup ) );
#endif

#if MD_CALL_MTL_GT3_METRICS
        MD_CHECK_CC( CreateMetricTreeMTL_GT3_OAM0( metricsDevice, concurrentGroup ) );
#endif
    }
    else
    {
        MD_LOG_A( adapterId, LOG_INFO, "OAM0 concurrent group is not supported!" );
    }

    MD_CHECK_CC( metricsDevice->AddOverrides() );
    MD_LOG_EXIT_A( adapterId );
    return CC_OK;

exception:
    MD_LOG_A( adapterId, LOG_ERROR, "Creating metric tree failed" );
    MD_LOG_EXIT_A( adapterId );
    return CC_ERROR_NO_MEMORY;
}
