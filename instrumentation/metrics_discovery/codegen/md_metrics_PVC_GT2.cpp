/*========================== begin_copyright_notice ============================

Copyright (C) 2021-2023 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_metrics_PVC_GT2.cpp

//     Abstract:   C++ automated generated file to stack metrics meta data

#include "md_per_platform_preamble.h"
#include "md_metric_sets_PVC_GT2.h"

#if( ( !defined( MD_INCLUDE_PVC_GT2_METRICS ) && MD_INCLUDE_ALL_METRICS ) || MD_INCLUDE_PVC_GT2_METRICS )

using namespace MetricsDiscoveryInternal;

TCompletionCode CreateMetricTreePVC_GT2_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup )
{
    const uint32_t adapterId = OBTAIN_ADAPTER_ID( metricsDevice );

    MD_LOG_ENTER_A( adapterId );
    MD_CHECK_PTR_RET_A( adapterId, metricsDevice, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET_A( adapterId, concurrentGroup, CC_ERROR_INVALID_PARAMETER );

    CMetricSet*      metricSet                                               = nullptr;
    uint8_t          platformMaskByteArray[MD_PLATFORM_MASK_BYTE_ARRAY_SIZE] = {};
    TByteArrayLatest platformMask                                            = { MD_PLATFORM_MASK_BYTE_ARRAY_SIZE, platformMaskByteArray };

    MD_CHECK_CC( SetPlatformMask( adapterId, &platformMask, nullptr, false, GENERATION_PVC ) );

    if( metricsDevice->IsPlatformTypeOf( &platformMask, GT_TYPE_GT2 ) )
    {
        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_PipelineStatistics::CPipelineStatsMetricSet>( "PipelineStats", "Pipeline Statistics for OGL4", API_TYPE_OGL | API_TYPE_OGL4_X,
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

#if( ( !defined( MD_INCLUDE_PVC_GT2_METRICS ) && MD_INCLUDE_ALL_METRICS ) || MD_INCLUDE_PVC_GT2_METRICS )

using namespace MetricsDiscoveryInternal;

TCompletionCode CreateMetricTreePVC_GT2_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup )
{
    const uint32_t adapterId = OBTAIN_ADAPTER_ID( metricsDevice );

    MD_LOG_ENTER_A( adapterId );
    MD_CHECK_PTR_RET_A( adapterId, metricsDevice, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET_A( adapterId, concurrentGroup, CC_ERROR_INVALID_PARAMETER );

    CMetricSet*      metricSet                                               = nullptr;
    uint8_t          platformMaskByteArray[MD_PLATFORM_MASK_BYTE_ARRAY_SIZE] = {};
    TByteArrayLatest platformMask                                            = { MD_PLATFORM_MASK_BYTE_ARRAY_SIZE, platformMaskByteArray };

    MD_CHECK_CC( SetPlatformMask( adapterId, &platformMask, nullptr, false, GENERATION_PVC ) );

    if( metricsDevice->IsPlatformTypeOf( &platformMask, GT_TYPE_GT2 ) )
    {
        MetricSets_PVC_GT2_OA::AddInformationSet( concurrentGroup );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CComputeBasicMetricSet>( "ComputeBasic", "Compute Basic", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CGpuOffloadMetricSet>( "GpuOffload", "GpuOffload", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemProfileMetricSet>( "MemProfile", "MemProfile", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataportProfileMetricSet>( "DataportProfile", "DataportProfile", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1ProfileReadsMetricSet_XeCore0>( "L1ProfileReads", "L1ProfileReads", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$GtSlice0XeCore0 $GtSlice1XeCore0 UADD $GtSlice2XeCore0 UADD $GtSlice3XeCore0 UADD $GtSlice4XeCore0 UADD $GtSlice5XeCore0 UADD $GtSlice6XeCore0 UADD $GtSlice7XeCore0 UADD $GtSlice0XeCore4 $GtSlice1XeCore4 UADD $GtSlice2XeCore4 UADD $GtSlice3XeCore4 UADD $GtSlice4XeCore4 UADD $GtSlice5XeCore4 UADD $GtSlice6XeCore4 UADD $GtSlice7XeCore4 UADD UGTE", GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1ProfileReadsMetricSet_XeCore4>( "L1ProfileReads", "L1ProfileReads", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$GtSlice0XeCore0 $GtSlice1XeCore0 UADD $GtSlice2XeCore0 UADD $GtSlice3XeCore0 UADD $GtSlice4XeCore0 UADD $GtSlice5XeCore0 UADD $GtSlice6XeCore0 UADD $GtSlice7XeCore0 UADD $GtSlice0XeCore4 $GtSlice1XeCore4 UADD $GtSlice2XeCore4 UADD $GtSlice3XeCore4 UADD $GtSlice4XeCore4 UADD $GtSlice5XeCore4 UADD $GtSlice6XeCore4 UADD $GtSlice7XeCore4 UADD ULT", GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1ProfileSlmBankConflictsMetricSet_XeCore0>( "L1ProfileSlmBankConflicts", "L1ProfileSlmBankConflicts", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$GtSlice0XeCore0 $GtSlice1XeCore0 UADD $GtSlice2XeCore0 UADD $GtSlice3XeCore0 UADD $GtSlice4XeCore0 UADD $GtSlice5XeCore0 UADD $GtSlice6XeCore0 UADD $GtSlice7XeCore0 UADD $GtSlice0XeCore4 $GtSlice1XeCore4 UADD $GtSlice2XeCore4 UADD $GtSlice3XeCore4 UADD $GtSlice4XeCore4 UADD $GtSlice5XeCore4 UADD $GtSlice6XeCore4 UADD $GtSlice7XeCore4 UADD UGTE", GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1ProfileSlmBankConflictsMetricSet_XeCore4>( "L1ProfileSlmBankConflicts", "L1ProfileSlmBankConflicts", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$GtSlice0XeCore0 $GtSlice1XeCore0 UADD $GtSlice2XeCore0 UADD $GtSlice3XeCore0 UADD $GtSlice4XeCore0 UADD $GtSlice5XeCore0 UADD $GtSlice6XeCore0 UADD $GtSlice7XeCore0 UADD $GtSlice0XeCore4 $GtSlice1XeCore4 UADD $GtSlice2XeCore4 UADD $GtSlice3XeCore4 UADD $GtSlice4XeCore4 UADD $GtSlice5XeCore4 UADD $GtSlice6XeCore4 UADD $GtSlice7XeCore4 UADD ULT", GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1ProfileWritesMetricSet_XeCore0>( "L1ProfileWrites", "L1ProfileWrites", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$GtSlice0XeCore0 $GtSlice1XeCore0 UADD $GtSlice2XeCore0 UADD $GtSlice3XeCore0 UADD $GtSlice4XeCore0 UADD $GtSlice5XeCore0 UADD $GtSlice6XeCore0 UADD $GtSlice7XeCore0 UADD $GtSlice0XeCore4 $GtSlice1XeCore4 UADD $GtSlice2XeCore4 UADD $GtSlice3XeCore4 UADD $GtSlice4XeCore4 UADD $GtSlice5XeCore4 UADD $GtSlice6XeCore4 UADD $GtSlice7XeCore4 UADD UGTE", GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1ProfileWritesMetricSet_XeCore4>( "L1ProfileWrites", "L1ProfileWrites", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, "$GtSlice0XeCore0 $GtSlice1XeCore0 UADD $GtSlice2XeCore0 UADD $GtSlice3XeCore0 UADD $GtSlice4XeCore0 UADD $GtSlice5XeCore0 UADD $GtSlice6XeCore0 UADD $GtSlice7XeCore0 UADD $GtSlice0XeCore4 $GtSlice1XeCore4 UADD $GtSlice2XeCore4 UADD $GtSlice3XeCore4 UADD $GtSlice4XeCore4 UADD $GtSlice5XeCore4 UADD $GtSlice6XeCore4 UADD $GtSlice7XeCore4 UADD ULT", GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CTestOaMetricSet>( "TestOa", "Metric set TestOa", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport1MetricSet>( "Dataport1", "Dataport1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport2MetricSet>( "Dataport2", "Dataport2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport3MetricSet>( "Dataport3", "Dataport3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport4MetricSet>( "Dataport4", "Dataport4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport5MetricSet>( "Dataport5", "Dataport5", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport6MetricSet>( "Dataport6", "Dataport6", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport7MetricSet>( "Dataport7", "Dataport7", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport8MetricSet>( "Dataport8", "Dataport8", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport9MetricSet>( "Dataport9", "Dataport9", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport10MetricSet>( "Dataport10", "Dataport10", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport11MetricSet>( "Dataport11", "Dataport11", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport12MetricSet>( "Dataport12", "Dataport12", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport13MetricSet>( "Dataport13", "Dataport13", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport14MetricSet>( "Dataport14", "Dataport14", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport15MetricSet>( "Dataport15", "Dataport15", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport16MetricSet>( "Dataport16", "Dataport16", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport17MetricSet>( "Dataport17", "Dataport17", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport18MetricSet>( "Dataport18", "Dataport18", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport19MetricSet>( "Dataport19", "Dataport19", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport20MetricSet>( "Dataport20", "Dataport20", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport21MetricSet>( "Dataport21", "Dataport21", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport22MetricSet>( "Dataport22", "Dataport22", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport23MetricSet>( "Dataport23", "Dataport23", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport24MetricSet>( "Dataport24", "Dataport24", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport25MetricSet>( "Dataport25", "Dataport25", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport26MetricSet>( "Dataport26", "Dataport26", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport27MetricSet>( "Dataport27", "Dataport27", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport28MetricSet>( "Dataport28", "Dataport28", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport29MetricSet>( "Dataport29", "Dataport29", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport30MetricSet>( "Dataport30", "Dataport30", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport31MetricSet>( "Dataport31", "Dataport31", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport32MetricSet>( "Dataport32", "Dataport32", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport33MetricSet>( "Dataport33", "Dataport33", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport34MetricSet>( "Dataport34", "Dataport34", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport35MetricSet>( "Dataport35", "Dataport35", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport36MetricSet>( "Dataport36", "Dataport36", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport37MetricSet>( "Dataport37", "Dataport37", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport38MetricSet>( "Dataport38", "Dataport38", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport39MetricSet>( "Dataport39", "Dataport39", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport40MetricSet>( "Dataport40", "Dataport40", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport41MetricSet>( "Dataport41", "Dataport41", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport42MetricSet>( "Dataport42", "Dataport42", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport43MetricSet>( "Dataport43", "Dataport43", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport44MetricSet>( "Dataport44", "Dataport44", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport45MetricSet>( "Dataport45", "Dataport45", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport46MetricSet>( "Dataport46", "Dataport46", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport47MetricSet>( "Dataport47", "Dataport47", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport48MetricSet>( "Dataport48", "Dataport48", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport49MetricSet>( "Dataport49", "Dataport49", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport50MetricSet>( "Dataport50", "Dataport50", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport51MetricSet>( "Dataport51", "Dataport51", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport52MetricSet>( "Dataport52", "Dataport52", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport53MetricSet>( "Dataport53", "Dataport53", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport54MetricSet>( "Dataport54", "Dataport54", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport55MetricSet>( "Dataport55", "Dataport55", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CDataport56MetricSet>( "Dataport56", "Dataport56", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CFrontEnd1MetricSet>( "FrontEnd1", "FrontEnd1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CFrontEnd2MetricSet>( "FrontEnd2", "FrontEnd2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache1MetricSet>( "L1Cache1", "L1Cache1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache2MetricSet>( "L1Cache2", "L1Cache2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache3MetricSet>( "L1Cache3", "L1Cache3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache4MetricSet>( "L1Cache4", "L1Cache4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache5MetricSet>( "L1Cache5", "L1Cache5", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache6MetricSet>( "L1Cache6", "L1Cache6", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache7MetricSet>( "L1Cache7", "L1Cache7", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache8MetricSet>( "L1Cache8", "L1Cache8", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache9MetricSet>( "L1Cache9", "L1Cache9", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache10MetricSet>( "L1Cache10", "L1Cache10", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache11MetricSet>( "L1Cache11", "L1Cache11", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache12MetricSet>( "L1Cache12", "L1Cache12", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache13MetricSet>( "L1Cache13", "L1Cache13", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache14MetricSet>( "L1Cache14", "L1Cache14", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache15MetricSet>( "L1Cache15", "L1Cache15", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache16MetricSet>( "L1Cache16", "L1Cache16", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache17MetricSet>( "L1Cache17", "L1Cache17", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache18MetricSet>( "L1Cache18", "L1Cache18", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache19MetricSet>( "L1Cache19", "L1Cache19", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache20MetricSet>( "L1Cache20", "L1Cache20", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache21MetricSet>( "L1Cache21", "L1Cache21", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache22MetricSet>( "L1Cache22", "L1Cache22", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache23MetricSet>( "L1Cache23", "L1Cache23", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache24MetricSet>( "L1Cache24", "L1Cache24", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache25MetricSet>( "L1Cache25", "L1Cache25", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache26MetricSet>( "L1Cache26", "L1Cache26", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache27MetricSet>( "L1Cache27", "L1Cache27", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache28MetricSet>( "L1Cache28", "L1Cache28", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache29MetricSet>( "L1Cache29", "L1Cache29", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache30MetricSet>( "L1Cache30", "L1Cache30", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache31MetricSet>( "L1Cache31", "L1Cache31", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache32MetricSet>( "L1Cache32", "L1Cache32", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache33MetricSet>( "L1Cache33", "L1Cache33", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache34MetricSet>( "L1Cache34", "L1Cache34", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache35MetricSet>( "L1Cache35", "L1Cache35", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache36MetricSet>( "L1Cache36", "L1Cache36", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache37MetricSet>( "L1Cache37", "L1Cache37", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache38MetricSet>( "L1Cache38", "L1Cache38", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache39MetricSet>( "L1Cache39", "L1Cache39", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache40MetricSet>( "L1Cache40", "L1Cache40", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache41MetricSet>( "L1Cache41", "L1Cache41", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache42MetricSet>( "L1Cache42", "L1Cache42", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache43MetricSet>( "L1Cache43", "L1Cache43", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache44MetricSet>( "L1Cache44", "L1Cache44", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache45MetricSet>( "L1Cache45", "L1Cache45", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache46MetricSet>( "L1Cache46", "L1Cache46", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache47MetricSet>( "L1Cache47", "L1Cache47", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache48MetricSet>( "L1Cache48", "L1Cache48", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache49MetricSet>( "L1Cache49", "L1Cache49", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache50MetricSet>( "L1Cache50", "L1Cache50", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache51MetricSet>( "L1Cache51", "L1Cache51", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache52MetricSet>( "L1Cache52", "L1Cache52", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache53MetricSet>( "L1Cache53", "L1Cache53", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache54MetricSet>( "L1Cache54", "L1Cache54", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache55MetricSet>( "L1Cache55", "L1Cache55", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache56MetricSet>( "L1Cache56", "L1Cache56", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache57MetricSet>( "L1Cache57", "L1Cache57", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache58MetricSet>( "L1Cache58", "L1Cache58", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache59MetricSet>( "L1Cache59", "L1Cache59", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache60MetricSet>( "L1Cache60", "L1Cache60", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache61MetricSet>( "L1Cache61", "L1Cache61", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache62MetricSet>( "L1Cache62", "L1Cache62", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache63MetricSet>( "L1Cache63", "L1Cache63", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache64MetricSet>( "L1Cache64", "L1Cache64", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache65MetricSet>( "L1Cache65", "L1Cache65", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache66MetricSet>( "L1Cache66", "L1Cache66", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache67MetricSet>( "L1Cache67", "L1Cache67", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache68MetricSet>( "L1Cache68", "L1Cache68", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache69MetricSet>( "L1Cache69", "L1Cache69", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache70MetricSet>( "L1Cache70", "L1Cache70", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache71MetricSet>( "L1Cache71", "L1Cache71", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache72MetricSet>( "L1Cache72", "L1Cache72", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache73MetricSet>( "L1Cache73", "L1Cache73", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache74MetricSet>( "L1Cache74", "L1Cache74", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache75MetricSet>( "L1Cache75", "L1Cache75", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache76MetricSet>( "L1Cache76", "L1Cache76", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache77MetricSet>( "L1Cache77", "L1Cache77", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache78MetricSet>( "L1Cache78", "L1Cache78", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache79MetricSet>( "L1Cache79", "L1Cache79", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache80MetricSet>( "L1Cache80", "L1Cache80", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache81MetricSet>( "L1Cache81", "L1Cache81", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache82MetricSet>( "L1Cache82", "L1Cache82", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache83MetricSet>( "L1Cache83", "L1Cache83", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache84MetricSet>( "L1Cache84", "L1Cache84", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache85MetricSet>( "L1Cache85", "L1Cache85", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache86MetricSet>( "L1Cache86", "L1Cache86", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache87MetricSet>( "L1Cache87", "L1Cache87", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache88MetricSet>( "L1Cache88", "L1Cache88", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache89MetricSet>( "L1Cache89", "L1Cache89", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache90MetricSet>( "L1Cache90", "L1Cache90", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache91MetricSet>( "L1Cache91", "L1Cache91", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache92MetricSet>( "L1Cache92", "L1Cache92", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache93MetricSet>( "L1Cache93", "L1Cache93", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache94MetricSet>( "L1Cache94", "L1Cache94", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache95MetricSet>( "L1Cache95", "L1Cache95", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache96MetricSet>( "L1Cache96", "L1Cache96", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache97MetricSet>( "L1Cache97", "L1Cache97", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache98MetricSet>( "L1Cache98", "L1Cache98", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache99MetricSet>( "L1Cache99", "L1Cache99", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache100MetricSet>( "L1Cache100", "L1Cache100", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache101MetricSet>( "L1Cache101", "L1Cache101", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache102MetricSet>( "L1Cache102", "L1Cache102", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache103MetricSet>( "L1Cache103", "L1Cache103", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache104MetricSet>( "L1Cache104", "L1Cache104", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache105MetricSet>( "L1Cache105", "L1Cache105", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache106MetricSet>( "L1Cache106", "L1Cache106", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache107MetricSet>( "L1Cache107", "L1Cache107", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache108MetricSet>( "L1Cache108", "L1Cache108", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache109MetricSet>( "L1Cache109", "L1Cache109", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache110MetricSet>( "L1Cache110", "L1Cache110", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache111MetricSet>( "L1Cache111", "L1Cache111", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache112MetricSet>( "L1Cache112", "L1Cache112", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache113MetricSet>( "L1Cache113", "L1Cache113", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache114MetricSet>( "L1Cache114", "L1Cache114", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache115MetricSet>( "L1Cache115", "L1Cache115", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache116MetricSet>( "L1Cache116", "L1Cache116", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache117MetricSet>( "L1Cache117", "L1Cache117", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache118MetricSet>( "L1Cache118", "L1Cache118", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache119MetricSet>( "L1Cache119", "L1Cache119", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache120MetricSet>( "L1Cache120", "L1Cache120", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache121MetricSet>( "L1Cache121", "L1Cache121", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache122MetricSet>( "L1Cache122", "L1Cache122", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache123MetricSet>( "L1Cache123", "L1Cache123", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache124MetricSet>( "L1Cache124", "L1Cache124", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache125MetricSet>( "L1Cache125", "L1Cache125", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache126MetricSet>( "L1Cache126", "L1Cache126", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache127MetricSet>( "L1Cache127", "L1Cache127", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache128MetricSet>( "L1Cache128", "L1Cache128", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache129MetricSet>( "L1Cache129", "L1Cache129", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache130MetricSet>( "L1Cache130", "L1Cache130", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache131MetricSet>( "L1Cache131", "L1Cache131", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache132MetricSet>( "L1Cache132", "L1Cache132", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache133MetricSet>( "L1Cache133", "L1Cache133", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache134MetricSet>( "L1Cache134", "L1Cache134", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache135MetricSet>( "L1Cache135", "L1Cache135", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache136MetricSet>( "L1Cache136", "L1Cache136", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache137MetricSet>( "L1Cache137", "L1Cache137", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache138MetricSet>( "L1Cache138", "L1Cache138", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache139MetricSet>( "L1Cache139", "L1Cache139", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache140MetricSet>( "L1Cache140", "L1Cache140", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache141MetricSet>( "L1Cache141", "L1Cache141", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache142MetricSet>( "L1Cache142", "L1Cache142", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache143MetricSet>( "L1Cache143", "L1Cache143", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache144MetricSet>( "L1Cache144", "L1Cache144", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache145MetricSet>( "L1Cache145", "L1Cache145", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache146MetricSet>( "L1Cache146", "L1Cache146", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache147MetricSet>( "L1Cache147", "L1Cache147", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache148MetricSet>( "L1Cache148", "L1Cache148", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache149MetricSet>( "L1Cache149", "L1Cache149", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache150MetricSet>( "L1Cache150", "L1Cache150", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache151MetricSet>( "L1Cache151", "L1Cache151", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache152MetricSet>( "L1Cache152", "L1Cache152", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache153MetricSet>( "L1Cache153", "L1Cache153", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache154MetricSet>( "L1Cache154", "L1Cache154", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache155MetricSet>( "L1Cache155", "L1Cache155", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache156MetricSet>( "L1Cache156", "L1Cache156", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache157MetricSet>( "L1Cache157", "L1Cache157", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache158MetricSet>( "L1Cache158", "L1Cache158", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache159MetricSet>( "L1Cache159", "L1Cache159", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache160MetricSet>( "L1Cache160", "L1Cache160", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache161MetricSet>( "L1Cache161", "L1Cache161", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache162MetricSet>( "L1Cache162", "L1Cache162", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache163MetricSet>( "L1Cache163", "L1Cache163", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache164MetricSet>( "L1Cache164", "L1Cache164", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache165MetricSet>( "L1Cache165", "L1Cache165", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache166MetricSet>( "L1Cache166", "L1Cache166", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache167MetricSet>( "L1Cache167", "L1Cache167", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache168MetricSet>( "L1Cache168", "L1Cache168", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache169MetricSet>( "L1Cache169", "L1Cache169", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache170MetricSet>( "L1Cache170", "L1Cache170", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache171MetricSet>( "L1Cache171", "L1Cache171", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache172MetricSet>( "L1Cache172", "L1Cache172", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache173MetricSet>( "L1Cache173", "L1Cache173", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache174MetricSet>( "L1Cache174", "L1Cache174", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache175MetricSet>( "L1Cache175", "L1Cache175", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache176MetricSet>( "L1Cache176", "L1Cache176", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL1Cache177MetricSet>( "L1Cache177", "L1Cache177", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache1MetricSet>( "L3Cache1", "L3Cache1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache2MetricSet>( "L3Cache2", "L3Cache2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache3MetricSet>( "L3Cache3", "L3Cache3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache4MetricSet>( "L3Cache4", "L3Cache4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache5MetricSet>( "L3Cache5", "L3Cache5", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache6MetricSet>( "L3Cache6", "L3Cache6", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache7MetricSet>( "L3Cache7", "L3Cache7", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache8MetricSet>( "L3Cache8", "L3Cache8", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache9MetricSet>( "L3Cache9", "L3Cache9", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache10MetricSet>( "L3Cache10", "L3Cache10", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache11MetricSet>( "L3Cache11", "L3Cache11", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache12MetricSet>( "L3Cache12", "L3Cache12", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache13MetricSet>( "L3Cache13", "L3Cache13", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache14MetricSet>( "L3Cache14", "L3Cache14", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache15MetricSet>( "L3Cache15", "L3Cache15", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache16MetricSet>( "L3Cache16", "L3Cache16", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache17MetricSet>( "L3Cache17", "L3Cache17", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache18MetricSet>( "L3Cache18", "L3Cache18", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache19MetricSet>( "L3Cache19", "L3Cache19", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache20MetricSet>( "L3Cache20", "L3Cache20", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache21MetricSet>( "L3Cache21", "L3Cache21", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache22MetricSet>( "L3Cache22", "L3Cache22", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache23MetricSet>( "L3Cache23", "L3Cache23", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache24MetricSet>( "L3Cache24", "L3Cache24", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache25MetricSet>( "L3Cache25", "L3Cache25", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache26MetricSet>( "L3Cache26", "L3Cache26", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache27MetricSet>( "L3Cache27", "L3Cache27", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache28MetricSet>( "L3Cache28", "L3Cache28", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache29MetricSet>( "L3Cache29", "L3Cache29", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache30MetricSet>( "L3Cache30", "L3Cache30", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache31MetricSet>( "L3Cache31", "L3Cache31", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache32MetricSet>( "L3Cache32", "L3Cache32", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache33MetricSet>( "L3Cache33", "L3Cache33", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache34MetricSet>( "L3Cache34", "L3Cache34", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache35MetricSet>( "L3Cache35", "L3Cache35", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache36MetricSet>( "L3Cache36", "L3Cache36", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache37MetricSet>( "L3Cache37", "L3Cache37", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache38MetricSet>( "L3Cache38", "L3Cache38", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache39MetricSet>( "L3Cache39", "L3Cache39", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache40MetricSet>( "L3Cache40", "L3Cache40", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache41MetricSet>( "L3Cache41", "L3Cache41", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache42MetricSet>( "L3Cache42", "L3Cache42", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache43MetricSet>( "L3Cache43", "L3Cache43", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache44MetricSet>( "L3Cache44", "L3Cache44", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache45MetricSet>( "L3Cache45", "L3Cache45", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache46MetricSet>( "L3Cache46", "L3Cache46", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache47MetricSet>( "L3Cache47", "L3Cache47", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache48MetricSet>( "L3Cache48", "L3Cache48", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache49MetricSet>( "L3Cache49", "L3Cache49", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache50MetricSet>( "L3Cache50", "L3Cache50", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache51MetricSet>( "L3Cache51", "L3Cache51", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache52MetricSet>( "L3Cache52", "L3Cache52", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache53MetricSet>( "L3Cache53", "L3Cache53", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache54MetricSet>( "L3Cache54", "L3Cache54", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache55MetricSet>( "L3Cache55", "L3Cache55", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache56MetricSet>( "L3Cache56", "L3Cache56", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache57MetricSet>( "L3Cache57", "L3Cache57", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache58MetricSet>( "L3Cache58", "L3Cache58", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache59MetricSet>( "L3Cache59", "L3Cache59", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache60MetricSet>( "L3Cache60", "L3Cache60", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache61MetricSet>( "L3Cache61", "L3Cache61", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache62MetricSet>( "L3Cache62", "L3Cache62", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache63MetricSet>( "L3Cache63", "L3Cache63", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache64MetricSet>( "L3Cache64", "L3Cache64", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache65MetricSet>( "L3Cache65", "L3Cache65", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache66MetricSet>( "L3Cache66", "L3Cache66", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache67MetricSet>( "L3Cache67", "L3Cache67", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache68MetricSet>( "L3Cache68", "L3Cache68", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache69MetricSet>( "L3Cache69", "L3Cache69", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache70MetricSet>( "L3Cache70", "L3Cache70", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache71MetricSet>( "L3Cache71", "L3Cache71", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CL3Cache72MetricSet>( "L3Cache72", "L3Cache72", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory1MetricSet>( "Memory1", "Memory1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory2MetricSet>( "Memory2", "Memory2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory3MetricSet>( "Memory3", "Memory3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory4MetricSet>( "Memory4", "Memory4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory5MetricSet>( "Memory5", "Memory5", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory6MetricSet>( "Memory6", "Memory6", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory7MetricSet>( "Memory7", "Memory7", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory8MetricSet>( "Memory8", "Memory8", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory9MetricSet>( "Memory9", "Memory9", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory10MetricSet>( "Memory10", "Memory10", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory11MetricSet>( "Memory11", "Memory11", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory12MetricSet>( "Memory12", "Memory12", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory13MetricSet>( "Memory13", "Memory13", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory14MetricSet>( "Memory14", "Memory14", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory15MetricSet>( "Memory15", "Memory15", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory16MetricSet>( "Memory16", "Memory16", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory17MetricSet>( "Memory17", "Memory17", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory18MetricSet>( "Memory18", "Memory18", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory19MetricSet>( "Memory19", "Memory19", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory20MetricSet>( "Memory20", "Memory20", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory21MetricSet>( "Memory21", "Memory21", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory22MetricSet>( "Memory22", "Memory22", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory23MetricSet>( "Memory23", "Memory23", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory24MetricSet>( "Memory24", "Memory24", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory25MetricSet>( "Memory25", "Memory25", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory26MetricSet>( "Memory26", "Memory26", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory27MetricSet>( "Memory27", "Memory27", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory28MetricSet>( "Memory28", "Memory28", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory29MetricSet>( "Memory29", "Memory29", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory30MetricSet>( "Memory30", "Memory30", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CMemory31MetricSet>( "Memory31", "Memory31", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing1MetricSet>( "RayTracing1", "RayTracing1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing2MetricSet>( "RayTracing2", "RayTracing2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing3MetricSet>( "RayTracing3", "RayTracing3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing4MetricSet>( "RayTracing4", "RayTracing4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing5MetricSet>( "RayTracing5", "RayTracing5", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing6MetricSet>( "RayTracing6", "RayTracing6", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing7MetricSet>( "RayTracing7", "RayTracing7", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing8MetricSet>( "RayTracing8", "RayTracing8", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing9MetricSet>( "RayTracing9", "RayTracing9", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing10MetricSet>( "RayTracing10", "RayTracing10", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing11MetricSet>( "RayTracing11", "RayTracing11", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing12MetricSet>( "RayTracing12", "RayTracing12", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing13MetricSet>( "RayTracing13", "RayTracing13", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing14MetricSet>( "RayTracing14", "RayTracing14", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing15MetricSet>( "RayTracing15", "RayTracing15", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing16MetricSet>( "RayTracing16", "RayTracing16", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing17MetricSet>( "RayTracing17", "RayTracing17", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing18MetricSet>( "RayTracing18", "RayTracing18", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing19MetricSet>( "RayTracing19", "RayTracing19", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing20MetricSet>( "RayTracing20", "RayTracing20", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing21MetricSet>( "RayTracing21", "RayTracing21", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing22MetricSet>( "RayTracing22", "RayTracing22", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing23MetricSet>( "RayTracing23", "RayTracing23", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing24MetricSet>( "RayTracing24", "RayTracing24", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing25MetricSet>( "RayTracing25", "RayTracing25", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing26MetricSet>( "RayTracing26", "RayTracing26", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing27MetricSet>( "RayTracing27", "RayTracing27", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing28MetricSet>( "RayTracing28", "RayTracing28", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing29MetricSet>( "RayTracing29", "RayTracing29", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing30MetricSet>( "RayTracing30", "RayTracing30", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing31MetricSet>( "RayTracing31", "RayTracing31", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing32MetricSet>( "RayTracing32", "RayTracing32", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing33MetricSet>( "RayTracing33", "RayTracing33", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing34MetricSet>( "RayTracing34", "RayTracing34", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing35MetricSet>( "RayTracing35", "RayTracing35", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing36MetricSet>( "RayTracing36", "RayTracing36", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing37MetricSet>( "RayTracing37", "RayTracing37", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing38MetricSet>( "RayTracing38", "RayTracing38", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing39MetricSet>( "RayTracing39", "RayTracing39", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing40MetricSet>( "RayTracing40", "RayTracing40", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing41MetricSet>( "RayTracing41", "RayTracing41", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing42MetricSet>( "RayTracing42", "RayTracing42", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing43MetricSet>( "RayTracing43", "RayTracing43", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing44MetricSet>( "RayTracing44", "RayTracing44", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing45MetricSet>( "RayTracing45", "RayTracing45", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing46MetricSet>( "RayTracing46", "RayTracing46", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing47MetricSet>( "RayTracing47", "RayTracing47", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing48MetricSet>( "RayTracing48", "RayTracing48", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing49MetricSet>( "RayTracing49", "RayTracing49", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing50MetricSet>( "RayTracing50", "RayTracing50", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing51MetricSet>( "RayTracing51", "RayTracing51", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing52MetricSet>( "RayTracing52", "RayTracing52", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing53MetricSet>( "RayTracing53", "RayTracing53", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing54MetricSet>( "RayTracing54", "RayTracing54", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing55MetricSet>( "RayTracing55", "RayTracing55", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing56MetricSet>( "RayTracing56", "RayTracing56", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing57MetricSet>( "RayTracing57", "RayTracing57", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing58MetricSet>( "RayTracing58", "RayTracing58", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing59MetricSet>( "RayTracing59", "RayTracing59", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing60MetricSet>( "RayTracing60", "RayTracing60", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing61MetricSet>( "RayTracing61", "RayTracing61", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing62MetricSet>( "RayTracing62", "RayTracing62", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing63MetricSet>( "RayTracing63", "RayTracing63", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing64MetricSet>( "RayTracing64", "RayTracing64", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing65MetricSet>( "RayTracing65", "RayTracing65", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing66MetricSet>( "RayTracing66", "RayTracing66", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing67MetricSet>( "RayTracing67", "RayTracing67", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing68MetricSet>( "RayTracing68", "RayTracing68", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing69MetricSet>( "RayTracing69", "RayTracing69", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing70MetricSet>( "RayTracing70", "RayTracing70", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing71MetricSet>( "RayTracing71", "RayTracing71", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing72MetricSet>( "RayTracing72", "RayTracing72", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing73MetricSet>( "RayTracing73", "RayTracing73", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing74MetricSet>( "RayTracing74", "RayTracing74", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing75MetricSet>( "RayTracing75", "RayTracing75", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing76MetricSet>( "RayTracing76", "RayTracing76", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing77MetricSet>( "RayTracing77", "RayTracing77", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing78MetricSet>( "RayTracing78", "RayTracing78", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing79MetricSet>( "RayTracing79", "RayTracing79", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing80MetricSet>( "RayTracing80", "RayTracing80", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing81MetricSet>( "RayTracing81", "RayTracing81", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing82MetricSet>( "RayTracing82", "RayTracing82", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing83MetricSet>( "RayTracing83", "RayTracing83", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing84MetricSet>( "RayTracing84", "RayTracing84", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing85MetricSet>( "RayTracing85", "RayTracing85", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing86MetricSet>( "RayTracing86", "RayTracing86", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing87MetricSet>( "RayTracing87", "RayTracing87", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing88MetricSet>( "RayTracing88", "RayTracing88", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing89MetricSet>( "RayTracing89", "RayTracing89", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing90MetricSet>( "RayTracing90", "RayTracing90", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing91MetricSet>( "RayTracing91", "RayTracing91", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing92MetricSet>( "RayTracing92", "RayTracing92", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing93MetricSet>( "RayTracing93", "RayTracing93", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing94MetricSet>( "RayTracing94", "RayTracing94", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing95MetricSet>( "RayTracing95", "RayTracing95", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing96MetricSet>( "RayTracing96", "RayTracing96", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing97MetricSet>( "RayTracing97", "RayTracing97", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing98MetricSet>( "RayTracing98", "RayTracing98", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing99MetricSet>( "RayTracing99", "RayTracing99", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing100MetricSet>( "RayTracing100", "RayTracing100", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing101MetricSet>( "RayTracing101", "RayTracing101", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing102MetricSet>( "RayTracing102", "RayTracing102", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing103MetricSet>( "RayTracing103", "RayTracing103", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CRayTracing104MetricSet>( "RayTracing104", "RayTracing104", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher1MetricSet>( "ThreadDispatcher1", "ThreadDispatcher1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher2MetricSet>( "ThreadDispatcher2", "ThreadDispatcher2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher3MetricSet>( "ThreadDispatcher3", "ThreadDispatcher3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher4MetricSet>( "ThreadDispatcher4", "ThreadDispatcher4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher5MetricSet>( "ThreadDispatcher5", "ThreadDispatcher5", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher6MetricSet>( "ThreadDispatcher6", "ThreadDispatcher6", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher7MetricSet>( "ThreadDispatcher7", "ThreadDispatcher7", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher8MetricSet>( "ThreadDispatcher8", "ThreadDispatcher8", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher9MetricSet>( "ThreadDispatcher9", "ThreadDispatcher9", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher10MetricSet>( "ThreadDispatcher10", "ThreadDispatcher10", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher11MetricSet>( "ThreadDispatcher11", "ThreadDispatcher11", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher12MetricSet>( "ThreadDispatcher12", "ThreadDispatcher12", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher13MetricSet>( "ThreadDispatcher13", "ThreadDispatcher13", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher14MetricSet>( "ThreadDispatcher14", "ThreadDispatcher14", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher15MetricSet>( "ThreadDispatcher15", "ThreadDispatcher15", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher16MetricSet>( "ThreadDispatcher16", "ThreadDispatcher16", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher17MetricSet>( "ThreadDispatcher17", "ThreadDispatcher17", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher18MetricSet>( "ThreadDispatcher18", "ThreadDispatcher18", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher19MetricSet>( "ThreadDispatcher19", "ThreadDispatcher19", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher20MetricSet>( "ThreadDispatcher20", "ThreadDispatcher20", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher21MetricSet>( "ThreadDispatcher21", "ThreadDispatcher21", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher22MetricSet>( "ThreadDispatcher22", "ThreadDispatcher22", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher23MetricSet>( "ThreadDispatcher23", "ThreadDispatcher23", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher24MetricSet>( "ThreadDispatcher24", "ThreadDispatcher24", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher25MetricSet>( "ThreadDispatcher25", "ThreadDispatcher25", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher26MetricSet>( "ThreadDispatcher26", "ThreadDispatcher26", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher27MetricSet>( "ThreadDispatcher27", "ThreadDispatcher27", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher28MetricSet>( "ThreadDispatcher28", "ThreadDispatcher28", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher29MetricSet>( "ThreadDispatcher29", "ThreadDispatcher29", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher30MetricSet>( "ThreadDispatcher30", "ThreadDispatcher30", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher31MetricSet>( "ThreadDispatcher31", "ThreadDispatcher31", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher32MetricSet>( "ThreadDispatcher32", "ThreadDispatcher32", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher33MetricSet>( "ThreadDispatcher33", "ThreadDispatcher33", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher34MetricSet>( "ThreadDispatcher34", "ThreadDispatcher34", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher35MetricSet>( "ThreadDispatcher35", "ThreadDispatcher35", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher36MetricSet>( "ThreadDispatcher36", "ThreadDispatcher36", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher37MetricSet>( "ThreadDispatcher37", "ThreadDispatcher37", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher38MetricSet>( "ThreadDispatcher38", "ThreadDispatcher38", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher39MetricSet>( "ThreadDispatcher39", "ThreadDispatcher39", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher40MetricSet>( "ThreadDispatcher40", "ThreadDispatcher40", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher41MetricSet>( "ThreadDispatcher41", "ThreadDispatcher41", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher42MetricSet>( "ThreadDispatcher42", "ThreadDispatcher42", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher43MetricSet>( "ThreadDispatcher43", "ThreadDispatcher43", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher44MetricSet>( "ThreadDispatcher44", "ThreadDispatcher44", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher45MetricSet>( "ThreadDispatcher45", "ThreadDispatcher45", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher46MetricSet>( "ThreadDispatcher46", "ThreadDispatcher46", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher47MetricSet>( "ThreadDispatcher47", "ThreadDispatcher47", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher48MetricSet>( "ThreadDispatcher48", "ThreadDispatcher48", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher49MetricSet>( "ThreadDispatcher49", "ThreadDispatcher49", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher50MetricSet>( "ThreadDispatcher50", "ThreadDispatcher50", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher51MetricSet>( "ThreadDispatcher51", "ThreadDispatcher51", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher52MetricSet>( "ThreadDispatcher52", "ThreadDispatcher52", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher53MetricSet>( "ThreadDispatcher53", "ThreadDispatcher53", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher54MetricSet>( "ThreadDispatcher54", "ThreadDispatcher54", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher55MetricSet>( "ThreadDispatcher55", "ThreadDispatcher55", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher56MetricSet>( "ThreadDispatcher56", "ThreadDispatcher56", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher57MetricSet>( "ThreadDispatcher57", "ThreadDispatcher57", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher58MetricSet>( "ThreadDispatcher58", "ThreadDispatcher58", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher59MetricSet>( "ThreadDispatcher59", "ThreadDispatcher59", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher60MetricSet>( "ThreadDispatcher60", "ThreadDispatcher60", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher61MetricSet>( "ThreadDispatcher61", "ThreadDispatcher61", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher62MetricSet>( "ThreadDispatcher62", "ThreadDispatcher62", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher63MetricSet>( "ThreadDispatcher63", "ThreadDispatcher63", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher64MetricSet>( "ThreadDispatcher64", "ThreadDispatcher64", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher65MetricSet>( "ThreadDispatcher65", "ThreadDispatcher65", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher66MetricSet>( "ThreadDispatcher66", "ThreadDispatcher66", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher67MetricSet>( "ThreadDispatcher67", "ThreadDispatcher67", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher68MetricSet>( "ThreadDispatcher68", "ThreadDispatcher68", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher69MetricSet>( "ThreadDispatcher69", "ThreadDispatcher69", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher70MetricSet>( "ThreadDispatcher70", "ThreadDispatcher70", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher71MetricSet>( "ThreadDispatcher71", "ThreadDispatcher71", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher72MetricSet>( "ThreadDispatcher72", "ThreadDispatcher72", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher73MetricSet>( "ThreadDispatcher73", "ThreadDispatcher73", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher74MetricSet>( "ThreadDispatcher74", "ThreadDispatcher74", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher75MetricSet>( "ThreadDispatcher75", "ThreadDispatcher75", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher76MetricSet>( "ThreadDispatcher76", "ThreadDispatcher76", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher77MetricSet>( "ThreadDispatcher77", "ThreadDispatcher77", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher78MetricSet>( "ThreadDispatcher78", "ThreadDispatcher78", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher79MetricSet>( "ThreadDispatcher79", "ThreadDispatcher79", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher80MetricSet>( "ThreadDispatcher80", "ThreadDispatcher80", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher81MetricSet>( "ThreadDispatcher81", "ThreadDispatcher81", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher82MetricSet>( "ThreadDispatcher82", "ThreadDispatcher82", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher83MetricSet>( "ThreadDispatcher83", "ThreadDispatcher83", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher84MetricSet>( "ThreadDispatcher84", "ThreadDispatcher84", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher85MetricSet>( "ThreadDispatcher85", "ThreadDispatcher85", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher86MetricSet>( "ThreadDispatcher86", "ThreadDispatcher86", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher87MetricSet>( "ThreadDispatcher87", "ThreadDispatcher87", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher88MetricSet>( "ThreadDispatcher88", "ThreadDispatcher88", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher89MetricSet>( "ThreadDispatcher89", "ThreadDispatcher89", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher90MetricSet>( "ThreadDispatcher90", "ThreadDispatcher90", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher91MetricSet>( "ThreadDispatcher91", "ThreadDispatcher91", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher92MetricSet>( "ThreadDispatcher92", "ThreadDispatcher92", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher93MetricSet>( "ThreadDispatcher93", "ThreadDispatcher93", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher94MetricSet>( "ThreadDispatcher94", "ThreadDispatcher94", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher95MetricSet>( "ThreadDispatcher95", "ThreadDispatcher95", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher96MetricSet>( "ThreadDispatcher96", "ThreadDispatcher96", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher97MetricSet>( "ThreadDispatcher97", "ThreadDispatcher97", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher98MetricSet>( "ThreadDispatcher98", "ThreadDispatcher98", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher99MetricSet>( "ThreadDispatcher99", "ThreadDispatcher99", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher100MetricSet>( "ThreadDispatcher100", "ThreadDispatcher100", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher101MetricSet>( "ThreadDispatcher101", "ThreadDispatcher101", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher102MetricSet>( "ThreadDispatcher102", "ThreadDispatcher102", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher103MetricSet>( "ThreadDispatcher103", "ThreadDispatcher103", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher104MetricSet>( "ThreadDispatcher104", "ThreadDispatcher104", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher105MetricSet>( "ThreadDispatcher105", "ThreadDispatcher105", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher106MetricSet>( "ThreadDispatcher106", "ThreadDispatcher106", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher107MetricSet>( "ThreadDispatcher107", "ThreadDispatcher107", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher108MetricSet>( "ThreadDispatcher108", "ThreadDispatcher108", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher109MetricSet>( "ThreadDispatcher109", "ThreadDispatcher109", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher110MetricSet>( "ThreadDispatcher110", "ThreadDispatcher110", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher111MetricSet>( "ThreadDispatcher111", "ThreadDispatcher111", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher112MetricSet>( "ThreadDispatcher112", "ThreadDispatcher112", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher113MetricSet>( "ThreadDispatcher113", "ThreadDispatcher113", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher114MetricSet>( "ThreadDispatcher114", "ThreadDispatcher114", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher115MetricSet>( "ThreadDispatcher115", "ThreadDispatcher115", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher116MetricSet>( "ThreadDispatcher116", "ThreadDispatcher116", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher117MetricSet>( "ThreadDispatcher117", "ThreadDispatcher117", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher118MetricSet>( "ThreadDispatcher118", "ThreadDispatcher118", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher119MetricSet>( "ThreadDispatcher119", "ThreadDispatcher119", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher120MetricSet>( "ThreadDispatcher120", "ThreadDispatcher120", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher121MetricSet>( "ThreadDispatcher121", "ThreadDispatcher121", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher122MetricSet>( "ThreadDispatcher122", "ThreadDispatcher122", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher123MetricSet>( "ThreadDispatcher123", "ThreadDispatcher123", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher124MetricSet>( "ThreadDispatcher124", "ThreadDispatcher124", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher125MetricSet>( "ThreadDispatcher125", "ThreadDispatcher125", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher126MetricSet>( "ThreadDispatcher126", "ThreadDispatcher126", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher127MetricSet>( "ThreadDispatcher127", "ThreadDispatcher127", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CThreadDispatcher128MetricSet>( "ThreadDispatcher128", "ThreadDispatcher128", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine1MetricSet>( "VectorEngine1", "VectorEngine1", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine2MetricSet>( "VectorEngine2", "VectorEngine2", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine3MetricSet>( "VectorEngine3", "VectorEngine3", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine4MetricSet>( "VectorEngine4", "VectorEngine4", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine5MetricSet>( "VectorEngine5", "VectorEngine5", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine6MetricSet>( "VectorEngine6", "VectorEngine6", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine7MetricSet>( "VectorEngine7", "VectorEngine7", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine8MetricSet>( "VectorEngine8", "VectorEngine8", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine9MetricSet>( "VectorEngine9", "VectorEngine9", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine10MetricSet>( "VectorEngine10", "VectorEngine10", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine11MetricSet>( "VectorEngine11", "VectorEngine11", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine12MetricSet>( "VectorEngine12", "VectorEngine12", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine13MetricSet>( "VectorEngine13", "VectorEngine13", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine14MetricSet>( "VectorEngine14", "VectorEngine14", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine15MetricSet>( "VectorEngine15", "VectorEngine15", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine16MetricSet>( "VectorEngine16", "VectorEngine16", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine17MetricSet>( "VectorEngine17", "VectorEngine17", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine18MetricSet>( "VectorEngine18", "VectorEngine18", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine19MetricSet>( "VectorEngine19", "VectorEngine19", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine20MetricSet>( "VectorEngine20", "VectorEngine20", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine21MetricSet>( "VectorEngine21", "VectorEngine21", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine22MetricSet>( "VectorEngine22", "VectorEngine22", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine23MetricSet>( "VectorEngine23", "VectorEngine23", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine24MetricSet>( "VectorEngine24", "VectorEngine24", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine25MetricSet>( "VectorEngine25", "VectorEngine25", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine26MetricSet>( "VectorEngine26", "VectorEngine26", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine27MetricSet>( "VectorEngine27", "VectorEngine27", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine28MetricSet>( "VectorEngine28", "VectorEngine28", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine29MetricSet>( "VectorEngine29", "VectorEngine29", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine30MetricSet>( "VectorEngine30", "VectorEngine30", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine31MetricSet>( "VectorEngine31", "VectorEngine31", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine32MetricSet>( "VectorEngine32", "VectorEngine32", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine33MetricSet>( "VectorEngine33", "VectorEngine33", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine34MetricSet>( "VectorEngine34", "VectorEngine34", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine35MetricSet>( "VectorEngine35", "VectorEngine35", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine36MetricSet>( "VectorEngine36", "VectorEngine36", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine37MetricSet>( "VectorEngine37", "VectorEngine37", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine38MetricSet>( "VectorEngine38", "VectorEngine38", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine39MetricSet>( "VectorEngine39", "VectorEngine39", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine40MetricSet>( "VectorEngine40", "VectorEngine40", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine41MetricSet>( "VectorEngine41", "VectorEngine41", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine42MetricSet>( "VectorEngine42", "VectorEngine42", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine43MetricSet>( "VectorEngine43", "VectorEngine43", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine44MetricSet>( "VectorEngine44", "VectorEngine44", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine45MetricSet>( "VectorEngine45", "VectorEngine45", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine46MetricSet>( "VectorEngine46", "VectorEngine46", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine47MetricSet>( "VectorEngine47", "VectorEngine47", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine48MetricSet>( "VectorEngine48", "VectorEngine48", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine49MetricSet>( "VectorEngine49", "VectorEngine49", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine50MetricSet>( "VectorEngine50", "VectorEngine50", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine51MetricSet>( "VectorEngine51", "VectorEngine51", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine52MetricSet>( "VectorEngine52", "VectorEngine52", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine53MetricSet>( "VectorEngine53", "VectorEngine53", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine54MetricSet>( "VectorEngine54", "VectorEngine54", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine55MetricSet>( "VectorEngine55", "VectorEngine55", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine56MetricSet>( "VectorEngine56", "VectorEngine56", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine57MetricSet>( "VectorEngine57", "VectorEngine57", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine58MetricSet>( "VectorEngine58", "VectorEngine58", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine59MetricSet>( "VectorEngine59", "VectorEngine59", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine60MetricSet>( "VectorEngine60", "VectorEngine60", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine61MetricSet>( "VectorEngine61", "VectorEngine61", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine62MetricSet>( "VectorEngine62", "VectorEngine62", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine63MetricSet>( "VectorEngine63", "VectorEngine63", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine64MetricSet>( "VectorEngine64", "VectorEngine64", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine65MetricSet>( "VectorEngine65", "VectorEngine65", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine66MetricSet>( "VectorEngine66", "VectorEngine66", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine67MetricSet>( "VectorEngine67", "VectorEngine67", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine68MetricSet>( "VectorEngine68", "VectorEngine68", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine69MetricSet>( "VectorEngine69", "VectorEngine69", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine70MetricSet>( "VectorEngine70", "VectorEngine70", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine71MetricSet>( "VectorEngine71", "VectorEngine71", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine72MetricSet>( "VectorEngine72", "VectorEngine72", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine73MetricSet>( "VectorEngine73", "VectorEngine73", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine74MetricSet>( "VectorEngine74", "VectorEngine74", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine75MetricSet>( "VectorEngine75", "VectorEngine75", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine76MetricSet>( "VectorEngine76", "VectorEngine76", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine77MetricSet>( "VectorEngine77", "VectorEngine77", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine78MetricSet>( "VectorEngine78", "VectorEngine78", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine79MetricSet>( "VectorEngine79", "VectorEngine79", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine80MetricSet>( "VectorEngine80", "VectorEngine80", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine81MetricSet>( "VectorEngine81", "VectorEngine81", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine82MetricSet>( "VectorEngine82", "VectorEngine82", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine83MetricSet>( "VectorEngine83", "VectorEngine83", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine84MetricSet>( "VectorEngine84", "VectorEngine84", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine85MetricSet>( "VectorEngine85", "VectorEngine85", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine86MetricSet>( "VectorEngine86", "VectorEngine86", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine87MetricSet>( "VectorEngine87", "VectorEngine87", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine88MetricSet>( "VectorEngine88", "VectorEngine88", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine89MetricSet>( "VectorEngine89", "VectorEngine89", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine90MetricSet>( "VectorEngine90", "VectorEngine90", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine91MetricSet>( "VectorEngine91", "VectorEngine91", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine92MetricSet>( "VectorEngine92", "VectorEngine92", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine93MetricSet>( "VectorEngine93", "VectorEngine93", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine94MetricSet>( "VectorEngine94", "VectorEngine94", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine95MetricSet>( "VectorEngine95", "VectorEngine95", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine96MetricSet>( "VectorEngine96", "VectorEngine96", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine97MetricSet>( "VectorEngine97", "VectorEngine97", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine98MetricSet>( "VectorEngine98", "VectorEngine98", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine99MetricSet>( "VectorEngine99", "VectorEngine99", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine100MetricSet>( "VectorEngine100", "VectorEngine100", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine101MetricSet>( "VectorEngine101", "VectorEngine101", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine102MetricSet>( "VectorEngine102", "VectorEngine102", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine103MetricSet>( "VectorEngine103", "VectorEngine103", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine104MetricSet>( "VectorEngine104", "VectorEngine104", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine105MetricSet>( "VectorEngine105", "VectorEngine105", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine106MetricSet>( "VectorEngine106", "VectorEngine106", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine107MetricSet>( "VectorEngine107", "VectorEngine107", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine108MetricSet>( "VectorEngine108", "VectorEngine108", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine109MetricSet>( "VectorEngine109", "VectorEngine109", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine110MetricSet>( "VectorEngine110", "VectorEngine110", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine111MetricSet>( "VectorEngine111", "VectorEngine111", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine112MetricSet>( "VectorEngine112", "VectorEngine112", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine113MetricSet>( "VectorEngine113", "VectorEngine113", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine114MetricSet>( "VectorEngine114", "VectorEngine114", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine115MetricSet>( "VectorEngine115", "VectorEngine115", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine116MetricSet>( "VectorEngine116", "VectorEngine116", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine117MetricSet>( "VectorEngine117", "VectorEngine117", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine118MetricSet>( "VectorEngine118", "VectorEngine118", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine119MetricSet>( "VectorEngine119", "VectorEngine119", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine120MetricSet>( "VectorEngine120", "VectorEngine120", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine121MetricSet>( "VectorEngine121", "VectorEngine121", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine122MetricSet>( "VectorEngine122", "VectorEngine122", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine123MetricSet>( "VectorEngine123", "VectorEngine123", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine124MetricSet>( "VectorEngine124", "VectorEngine124", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine125MetricSet>( "VectorEngine125", "VectorEngine125", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine126MetricSet>( "VectorEngine126", "VectorEngine126", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine127MetricSet>( "VectorEngine127", "VectorEngine127", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine128MetricSet>( "VectorEngine128", "VectorEngine128", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine129MetricSet>( "VectorEngine129", "VectorEngine129", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine130MetricSet>( "VectorEngine130", "VectorEngine130", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine131MetricSet>( "VectorEngine131", "VectorEngine131", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine132MetricSet>( "VectorEngine132", "VectorEngine132", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine133MetricSet>( "VectorEngine133", "VectorEngine133", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine134MetricSet>( "VectorEngine134", "VectorEngine134", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine135MetricSet>( "VectorEngine135", "VectorEngine135", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine136MetricSet>( "VectorEngine136", "VectorEngine136", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine137MetricSet>( "VectorEngine137", "VectorEngine137", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
            GPU_RENDER | GPU_COMPUTE | GPU_GENERIC, 256, 688, OA_REPORT_TYPE_256B_A45_NOA16, &platformMask, nullptr, GT_TYPE_GT2 );
        MD_CHECK_PTR( metricSet );

        metricSet = concurrentGroup->AddMetricSetExplicit<MetricSets_PVC_GT2_OA::CVectorEngine138MetricSet>( "VectorEngine138", "VectorEngine138", API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
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
