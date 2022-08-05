/*========================== begin_copyright_notice ============================

Copyright (C) 2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_metrics_ADLS.cpp

//     Abstract:   C++ automated generated file to stack metrics meta data

#include "md_per_platform_preamble.h"
#include "md_concurrent_group.h"
#include "md_equation.h"
#include "md_information.h"
#include "md_metric.h"
#include "md_metric_set.h"



#if ((!defined(MD_INCLUDE_ADLS_METRICS) && MD_INCLUDE_ALL_METRICS) || MD_INCLUDE_ADLS_METRICS)

using namespace MetricsDiscoveryInternal;

static TCompletionCode CreateMetricSet_ADLS_PipelineStats( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup, uint32_t platformMask )
{
    CMetricSet*   metricSet            = nullptr;
    CMetric*      metric               = nullptr;
    CInformation* information          = nullptr;
    const char*   availabilityEquation = nullptr;

    metricSet = concurrentGroup->AddMetricSet( "PipelineStats", "Pipeline Statistics for OGL4", API_TYPE_OGL|API_TYPE_OGL4_X,
        GPU_RENDER|GPU_COMPUTE, 0, 96, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, nullptr );
    MD_CHECK_PTR_RET( metricSet, CC_ERROR_GENERAL );

    MD_CHECK_CC_RET( metricSet->SetApiSpecificId(nullptr, 0, 0, 0x80000206, 0, 0,
        "", 0, "Intel_Raw_Pipeline_Statistics_Query", 0) );
  
    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "IAVertices", "Input vertices",
        "The total number of vertices that entered the 3D Pipeline.",
        "3D Pipe/Input Assembler", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_IA * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
        METRIC_TYPE_EVENT, RESULT_UINT64, "vertices", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 0 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x00" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "IAPrimitives", "Input primitives",
        "The total number of rendering primitives assembled and put into the input assembly stage of the 3D Pipeline.",
        "3D Pipe/Input Assembler", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_IA * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
        METRIC_TYPE_EVENT, RESULT_UINT64, "triangles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 1 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x08" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "VsInvocations", "VS per vertex invocations",
        "The total number of times a vertex shader was invoked. 3D rendering invokes the vertex shader once per vertex.",
        "3D Pipe/Vertex Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
        METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 2 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x10" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "HsInvocations", "HS invocations",
        "The total number of times a hull shader was invoked.",
        "3D Pipe/Hull Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
        METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", nullptr, 3 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "DsInvocations", "DS invocations",
        "The total number of times a domain shader was invoked.",
        "3D Pipe/Domain Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
        METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", nullptr, 4 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x48" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GsInvocations", "GS per triangle invocations",
        "The total number of times a geometry shader was invoked per triangle.",
        "3D Pipe/Geometry Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
        METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 5 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x18" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GsPrimitives", "Post-GS primitives",
        "The total number of primitives that flowed through from GS to the clipper if GS was enabled.",
        "3D Pipe/Geometry Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
        METRIC_TYPE_EVENT, RESULT_UINT64, "triangles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 6 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x20" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "ClipperInvocations", "Clipper invocations",
        "The total number of primitives sent to the Clipper.",
        "3D Pipe/Clipper", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_CL * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
        METRIC_TYPE_EVENT, RESULT_UINT64, "triangles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", nullptr, 7 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x28" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "ClipperPrimitives", "Clipper primitives",
        "The total number of primitives that flowed out of the Clipper.",
        "3D Pipe/Clipper", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_CL * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
        METRIC_TYPE_EVENT, RESULT_UINT64, "triangles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", nullptr, 8 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x30" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "PsInvocations", "PS invocations",
        "The total number of times a pixel shader was invoked. 3D rendering invokes a pixel shader once per pixel or subsample.",
        "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
        METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", nullptr, 9 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x38" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "CsInvocations", "CS invocations",
        "The total number of times a compute shader was invoked.",
        "3D Pipe/Compute Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
        METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x50" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "CpsInvocations", "CPS invocations",
        "The total number of times a coarse shader was invoked.",
        "3D Pipe/Compute Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
        METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, "PS|FS", nullptr, 11 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x58" ));
    }

    MD_CHECK_CC_RET( metricSet->RefreshConfigRegisters() );

    return CC_OK;
}

TCompletionCode CreateMetricTreeADLS_PipelineStatistics( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup )
{
    MD_LOG_ENTER();
    MD_CHECK_PTR_RET( metricsDevice, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( concurrentGroup, CC_ERROR_INVALID_PARAMETER );

    CMetricSet*   metricSet            = nullptr;
    CMetric*      metric               = nullptr;
    CInformation* information          = nullptr;
    const char*   availabilityEquation = nullptr;
    uint32_t      platformMask         = 0;

    platformMask = PLATFORM_ADLS;
    if( metricsDevice->IsPlatformTypeOf( platformMask ) )
    {

        MD_CHECK_CC( CreateMetricSet_ADLS_PipelineStats( metricsDevice, concurrentGroup, platformMask ) );

    MD_LOG_EXIT();
    }
    return CC_OK;

  exception:
    MD_LOG_EXIT();
    return CC_ERROR_NO_MEMORY;
}
#endif


#if ((!defined(MD_INCLUDE_ADLS_METRICS) && MD_INCLUDE_ALL_METRICS) || MD_INCLUDE_ADLS_METRICS)

using namespace MetricsDiscoveryInternal;

static TCompletionCode CreateMetricSet_ADLS_RenderBasic( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup, uint32_t platformMask )
{
    CMetricSet*   metricSet            = nullptr;
    CMetric*      metric               = nullptr;
    CInformation* information          = nullptr;
    const char*   availabilityEquation = nullptr;

    metricSet = concurrentGroup->AddMetricSet( "RenderBasic", "Render Metrics Basic Gen12", API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, nullptr );
    MD_CHECK_PTR_RET( metricSet, CC_ERROR_GENERAL );

    MD_CHECK_CC_RET( metricSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
        "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuTime", "GPU Time Elapsed",
        "Time elapsed on the GPU during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x00" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
        "The total number of GPU core clocks elapsed during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x0c" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x08" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
        "Average GPU Core Frequency in the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "VsThreads", "VS Threads Dispatched",
        "The total number of vertex shader hardware threads dispatched.",
        "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x18" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "HsThreads", "HS Threads Dispatched",
        "The total number of hull shader hardware threads dispatched.",
        "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 4 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x20" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "DsThreads", "DS Threads Dispatched",
        "The total number of domain shader hardware threads dispatched.",
        "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 5 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x28" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GsThreads", "GS Threads Dispatched",
        "The total number of geometry shader hardware threads dispatched.",
        "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 6 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x38" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "PsThreads", "PS Threads Dispatched",
        "The total number of pixel shader hardware threads dispatched.",
        "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 7 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x40" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "CsThreads", "CS Threads Dispatched",
        "The total number of compute shader hardware threads dispatched.",
        "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 8 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x30" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuBusy", "GPU Busy",
        "The percentage of time in which the GPU has been processing GPU commands.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x10" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuActive", "EU Active",
        "The percentage of time in which the Execution Units were actively processing.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x48" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuStall", "EU Stall",
        "The percentage of time in which the Execution Units were stalled.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x50" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
        "The percentage of time in which hardware threads occupied EUs.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "8 rd40@0x34:0xa9 FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "8 qw@0x58 FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$DualSubsliceMask 1 AND";
    metric = metricSet->AddMetric( "Sampler00Pipe0Busy", "Sampler00 Pipe0 Busy",
        "The percentage of time in which Slice0 Sampler0 Pipe0 has been processing EU requests.",
        "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, nullptr, nullptr, 13 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xfc" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x1a8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$DualSubsliceMask 1 AND";
    metric = metricSet->AddMetric( "Sampler00Pipe0Bottleneck", "Sampler00 Pipe0 Bottleneck",
        "The percentage of time in which Slice0 Sampler0 Pipe0 has been slowing down the pipe when processing EU requests.",
        "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_SUBSLICE, availabilityEquation, nullptr, nullptr, 14 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xf8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x1a0" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$DualSubsliceMask 1 AND";
    metric = metricSet->AddMetric( "SamplersBusy", "Samplers Busy",
        "The percentage of time in which samplers have been processing EU requests.",
        "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 15 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$$Sampler00Pipe0Busy" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$DualSubsliceMask 1 AND";
    metric = metricSet->AddMetric( "SamplerBottleneck", "Samplers Bottleneck",
        "The percentage of time in which samplers have been slowing down the pipe when processing EU requests.",
        "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_INDICATE|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 16 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$$Sampler00Pipe0Bottleneck" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
        "The total number of rasterized pixels.",
        "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 17 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xb8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
        "The total number of pixels dropped on early hierarchical depth test.",
        "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 18 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xc0" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
        "The total number of pixels dropped on early depth test.",
        "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 19 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xc8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
        "The total number of samples or pixels dropped in pixel shaders.",
        "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 20 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xd0" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
        "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
        "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 21 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xd8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SamplesWritten", "Samples Written",
        "The total number of samples or pixels written to all render targets.",
        "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 22 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xe0" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SamplesBlended", "Samples Blended",
        "The total number of blended samples or pixels written to all render targets.",
        "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 23 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xe8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SamplerTexels", "Sampler Texels",
        "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
        "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 24 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xf0" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
        "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
        "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 25 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xf8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
        "The total number of GPU memory bytes read from shared local memory.",
        "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 26 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x100" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 64 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
        "The total number of GPU memory bytes written into shared local memory.",
        "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 27 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x108" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 64 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
        "The total number of shader memory accesses to L3.",
        "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 28 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x90" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x110" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
        "The total number of shader atomic memory accesses.",
        "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 29 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x98" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x120" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
        "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
        "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 30 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten UADD $ShaderMemoryAccesses UADD 64 UMUL" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
        "The total number of shader barrier messages.",
        "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 31 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x9c" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x128" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GtiReadThroughput", "GTI Read Throughput",
        "The total number of GPU memory bytes read from GTI.",
        "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 32 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xf4 dw@0xf0 UADD dw@0xec UADD dw@0xe8 UADD" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x198 qw@0x190 UADD qw@0x188 UADD qw@0x180 UADD" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "64 $Self UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GtiWriteThroughput", "GTI Write Throughput",
        "The total number of GPU memory bytes written to GTI.",
        "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 33 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xe4 dw@0xe0 UADD" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x178 qw@0x170 UADD" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "64 $Self UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ));
    }

        uint32_t informationCount = concurrentGroup->GetInformationCount();

        information = metricSet->AddInformation( "StreamMarker", "Stream marker",
            "Stream marker value.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, nullptr, nullptr, informationCount++ );
        if( information )
        {
            MD_CHECK_CC_RET( information->SetSnapshotReportReadEquation( "dw@0x5c dw@0x0 19 >> 0x4 AND 0x4 == UMUL" ));
        }

        MD_CHECK_CC_RET( metricSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x14150001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a124000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0c124000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1a138000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1c130100, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x04155100, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x06150050, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x10150000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1a150000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a00c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0c00c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1a058000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1c054000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x080a8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a0a4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x05151d47, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x09151536, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x05351c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x09351400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5d102c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5b1005bb, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1b141800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5f110a00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1f150137, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x01150000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0f168000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x03164000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x05164000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1d350137, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x03350147, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x07350136, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x01350000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0f364000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x01368000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x03368000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x55101410, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x57100004, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x47101000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x49101414, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4b100414, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4d100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd904, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc40, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe65c, 0xffffffff, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe558, 0x00000008, REGISTER_TYPE_FLEX ));
  
    MD_CHECK_CC_RET( metricSet->RefreshConfigRegisters() );

    return CC_OK;
}

static TCompletionCode CreateMetricSet_ADLS_ComputeBasic( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup, uint32_t platformMask )
{
    CMetricSet*   metricSet            = nullptr;
    CMetric*      metric               = nullptr;
    CInformation* information          = nullptr;
    const char*   availabilityEquation = nullptr;

    metricSet = concurrentGroup->AddMetricSet( "ComputeBasic", "Compute Metrics Basic", API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, nullptr );
    MD_CHECK_PTR_RET( metricSet, CC_ERROR_GENERAL );

    MD_CHECK_CC_RET( metricSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
        "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuTime", "GPU Time Elapsed",
        "Time elapsed on the GPU during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x00" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
        "The total number of GPU core clocks elapsed during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x0c" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x08" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
        "Average GPU Core Frequency in the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuBusy", "GPU Busy",
        "The percentage of time in which the GPU has been processing GPU commands.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x10" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "VsThreads", "VS Threads Dispatched",
        "The total number of vertex shader hardware threads dispatched.",
        "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x18" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "HsThreads", "HS Threads Dispatched",
        "The total number of hull shader hardware threads dispatched.",
        "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x20" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "DsThreads", "DS Threads Dispatched",
        "The total number of domain shader hardware threads dispatched.",
        "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x28" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GsThreads", "GS Threads Dispatched",
        "The total number of geometry shader hardware threads dispatched.",
        "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x38" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "PsThreads", "PS Threads Dispatched",
        "The total number of pixel shader hardware threads dispatched.",
        "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x40" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "CsThreads", "CS Threads Dispatched",
        "The total number of compute shader hardware threads dispatched.",
        "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x30" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuActive", "EU Active",
        "The percentage of time in which the Execution Units were actively processing.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x48" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuStall", "EU Stall",
        "The percentage of time in which the Execution Units were stalled.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x50" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "FpuActive", "EU FPU Pipe Active",
        "The percentage of time in which EU FPU pipeline was actively processing.",
        "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x34:0xa9" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x58" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EmActive", "EM Pipe Active",
        "The percentage of time in which EU EM pipeline was actively processing.",
        "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 13 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x38:0xaa" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x60" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuFpuEmActive", "EU FPU And EM Pipes Active",
        "The percentage of time in which EU FPU and EM pipelines were actively processing.",
        "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 14 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x68" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuAvgIpcRate", "EU AVG IPC Rate",
        "The average rate of IPC calculated for 2 FPU pipelines.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_RATIO, RESULT_FLOAT, "number", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 15 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$EuFpuEmActive $FpuActive $EmActive FADD $EuFpuEmActive FSUB FDIV 1 FADD" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "2" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuSendActive", "EU Send Pipe Active",
        "The percentage of time in which EU send pipeline was actively processing.",
        "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 16 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x40:0xac" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x70" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
        "The percentage of time in which hardware threads occupied EUs.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 17 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "8 rd40@0x44:0xad FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "8 qw@0x78 FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
        "The total number of rasterized pixels.",
        "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 18 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xb8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
        "The total number of pixels dropped on early hierarchical depth test.",
        "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 19 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xc0" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
        "The total number of pixels dropped on early depth test.",
        "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 20 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xc8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
        "The total number of samples or pixels dropped in pixel shaders.",
        "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 21 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xd0" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
        "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
        "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 22 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xd8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SamplesWritten", "Samples Written",
        "The total number of samples or pixels written to all render targets.",
        "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 23 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xe0" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SamplesBlended", "Samples Blended",
        "The total number of blended samples or pixels written to all render targets.",
        "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 24 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xe8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SamplerTexels", "Sampler Texels",
        "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
        "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 25 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xf0" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
        "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
        "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 26 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xf8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
        "The total number of GPU memory bytes read from shared local memory.",
        "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 27 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x100" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 64 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
        "The total number of GPU memory bytes written into shared local memory.",
        "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 28 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x108" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 64 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
        "The total number of shader memory accesses to L3.",
        "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 29 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x90" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x110" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
        "The total number of shader atomic memory accesses.",
        "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 30 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x98" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x120" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
        "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
        "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 31 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten UADD $ShaderMemoryAccesses UADD 64 UMUL" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
        "The total number of shader barrier messages.",
        "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 32 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x9c" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x128" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GtiReadThroughput", "GTI Read Throughput",
        "The total number of GPU memory bytes read from GTI.",
        "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 33 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xfc dw@0xf8 UADD dw@0xf4 UADD dw@0xf0 UADD" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x1a8 qw@0x1a0 UADD qw@0x198 UADD qw@0x190 UADD" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "64 $Self UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GtiWriteThroughput", "GTI Write Throughput",
        "The total number of GPU memory bytes written to GTI.",
        "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 34 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xec dw@0xe8 UADD" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x188 qw@0x180 UADD" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "64 $Self UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ));
    }

        uint32_t informationCount = concurrentGroup->GetInformationCount();

        information = metricSet->AddInformation( "StreamMarker", "Stream marker",
            "Stream marker value.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, nullptr, nullptr, informationCount++ );
        if( information )
        {
            MD_CHECK_CC_RET( information->SetSnapshotReportReadEquation( "dw@0x5c dw@0x0 19 >> 0x4 AND 0x4 == UMUL" ));
        }

        MD_CHECK_CC_RET( metricSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x05151d37, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x09151547, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x05351c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x09351400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5b100bbb, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0d150136, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x01150000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x03164000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x05164000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x07164000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x03350137, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x07350147, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0b350136, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x01350000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x01368000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x03368000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x05368000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x47100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x49100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4b100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4d100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd904, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc40, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe65c, 0xffffffff, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe558, 0x00001000, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe658, 0x00002003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe758, 0x00000008, REGISTER_TYPE_FLEX ));
  
    MD_CHECK_CC_RET( metricSet->RefreshConfigRegisters() );

    return CC_OK;
}

static TCompletionCode CreateMetricSet_ADLS_AsyncCompute( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup, uint32_t platformMask )
{
    CMetricSet*   metricSet            = nullptr;
    CMetric*      metric               = nullptr;
    CInformation* information          = nullptr;
    const char*   availabilityEquation = nullptr;

    metricSet = concurrentGroup->AddMetricSet( "AsyncCompute", "AsyncCompute", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_VULKAN|API_TYPE_IOSTREAM,
        GPU_RENDER|GPU_COMPUTE|GPU_MEDIA|GPU_GENERIC, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, nullptr );
    MD_CHECK_PTR_RET( metricSet, CC_ERROR_GENERAL );

    MD_CHECK_CC_RET( metricSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
        "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuTime", "GPU Time Elapsed",
        "Time elapsed on the GPU during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_VULKAN|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x00" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
        "The total number of GPU core clocks elapsed during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_VULKAN|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x0c" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x08" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
        "Average GPU Core Frequency in the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_VULKAN|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuBusy", "GPU Busy",
        "The percentage of time in which the GPU has been processing GPU commands.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_VULKAN|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x10" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "VsThreads", "VS Threads Dispatched",
        "The total number of vertex shader hardware threads dispatched.",
        "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x18" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "HsThreads", "HS Threads Dispatched",
        "The total number of hull shader hardware threads dispatched.",
        "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x20" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "DsThreads", "DS Threads Dispatched",
        "The total number of domain shader hardware threads dispatched.",
        "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x28" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GsThreads", "GS Threads Dispatched",
        "The total number of geometry shader hardware threads dispatched.",
        "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x38" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "PsThreads", "PS Threads Dispatched",
        "The total number of pixel shader hardware threads dispatched.",
        "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x40" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "CsThreads", "CS Threads Dispatched",
        "The total number of compute shader hardware threads dispatched.",
        "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x30" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "FpuActive", "EU FPU Pipe Active",
        "The percentage of time in which EU FPU pipeline was actively processing.",
        "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_VULKAN|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x48" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "VsFpuActive", "VS FPU Pipe Active",
        "The percentage of time in which EU FPU pipeline was actively processing a vertex shader instruction.",
        "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x50" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "PsFpuActive", "PS FPU Pipe Active",
        "The percentage of time in which EU FPU pipeline was actively processing a pixel shader instruction.",
        "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", nullptr, 12 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x34:0xa9" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x58" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "CsFpuActive", "CS FPU Pipe Active",
        "The percentage of time in which EU FPU pipeline was actively processing a compute shader instruction.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 13 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x38:0xaa" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x60" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EmActive", "EM Pipe Active",
        "The percentage of time in which EU EM pipeline was actively processing.",
        "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_VULKAN|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 14 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x68" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "VsEmActive", "VS EM Pipe Active",
        "The percentage of time in which EU EM pipeline was actively processing a vertex shader instruction.",
        "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 15 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x40:0xac" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x70" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "PsEmActive", "PS EM Pipe Active",
        "The percentage of time in which EU EM pipeline was actively processing a pixel shader instruction.",
        "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", nullptr, 16 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x44:0xad" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x78" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "CsEmActive", "CS EM Pipe Active",
        "The percentage of time in which EU FPU1 pipeline was actively processing a compute shader instruction.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 17 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x48:0xae" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x80" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
        "The percentage of time in which hardware threads occupied EUs.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_VULKAN|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 18 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "8 rd40@0x4c:0xaf FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "8 qw@0x88 FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuActive", "EU Active",
        "The percentage of time in which the Execution Units were actively processing.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_VULKAN|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 19 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x50:0xb0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x90" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuStall", "EU Stall",
        "The percentage of time in which the Execution Units were stalled.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_VULKAN|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 20 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x54:0xb1" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x98" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

        MD_CHECK_CC_RET( metricSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd904, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc40, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe458, 0x00010000, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe558, 0x00060050, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe658, 0x00011001, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe758, 0x00061051, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe45c, 0x00004008, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe55c, 0x00000005, REGISTER_TYPE_FLEX ));
  
    MD_CHECK_CC_RET( metricSet->RefreshConfigRegisters() );

    return CC_OK;
}

static TCompletionCode CreateMetricSet_ADLS_XveActivity1( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup, uint32_t platformMask )
{
    CMetricSet*   metricSet            = nullptr;
    CMetric*      metric               = nullptr;
    CInformation* information          = nullptr;
    const char*   availabilityEquation = nullptr;

    metricSet = concurrentGroup->AddMetricSet( "XveActivity1", "XveActivity1", API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        GPU_RENDER|GPU_COMPUTE|GPU_MEDIA|GPU_GENERIC, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, nullptr );
    MD_CHECK_PTR_RET( metricSet, CC_ERROR_GENERAL );

    MD_CHECK_CC_RET( metricSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
        "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuTime", "GPU Time Elapsed",
        "Time elapsed on the GPU during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x00" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
        "The total number of GPU core clocks elapsed during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x0c" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x08" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
        "Average GPU Core Frequency in the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuBusy", "GPU Busy",
        "The percentage of time in which the GPU has been processing GPU commands.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x10" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "VsThreads", "VS Threads Dispatched",
        "The total number of vertex shader hardware threads dispatched.",
        "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x18" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "HsThreads", "HS Threads Dispatched",
        "The total number of hull shader hardware threads dispatched.",
        "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x20" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "DsThreads", "DS Threads Dispatched",
        "The total number of domain shader hardware threads dispatched.",
        "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x28" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GsThreads", "GS Threads Dispatched",
        "The total number of geometry shader hardware threads dispatched.",
        "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x38" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "PsThreads", "PS Threads Dispatched",
        "The total number of pixel shader hardware threads dispatched.",
        "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x40" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "CsThreads", "CS Threads Dispatched",
        "The total number of compute shader hardware threads dispatched.",
        "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x30" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "HsFpuActive", "HS FPU Pipe Active",
        "The percentage of time in which EU FPU pipeline was actively processing a hull shader instruction.",
        "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", nullptr, 10 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x48" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "DsFpuActive", "DS FPU Pipe Active",
        "The percentage of time in which EU FPU pipeline was actively processing a domain shader instructions.",
        "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", nullptr, 11 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x50" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GsFpuActive", "GS FPU Pipe Active",
        "The percentage of time in which EU FPU pipeline was actively processing a geometry shader instructions.",
        "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x34:0xa9" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x58" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "HsEmActive", "HS EM Pipe Active",
        "The percentage of time in which EU EM pipeline was actively processing a hull shader instructions.",
        "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", nullptr, 13 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x38:0xaa" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x60" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "DsEmActive", "DS EM Pipe Active",
        "The percentage of time in which EU EM pipeline was actively processing a domain shader instructions.",
        "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", nullptr, 14 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x68" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GsEmActive", "GS EM Pipe Active",
        "The percentage of time in which EU EM pipeline was actively processing a geometry shader instructions.",
        "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 15 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x40:0xac" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x70" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "HsSendActive", "HS Send Pipe Active",
        "The percentage of time in which EU send pipeline was actively processing a hull shader instruction.",
        "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", nullptr, 16 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x44:0xad" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x78" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "DsSendActive", "DS Send Pipe Active",
        "The percentage of time in which EU send pipeline was actively processing a domain shader instruction.",
        "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", nullptr, 17 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x48:0xae" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x80" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GsSendActive", "GS Send Pipe Active",
        "The percentage of time in which EU send pipeline was actively processing a geometry shader instruction.",
        "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 18 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x88" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "CsSendActive", "CS Send Pipeline Active",
        "The percentage of time in which EU send pipeline was actively processing a compute shader instruction.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 19 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x50:0xb0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x90" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

        MD_CHECK_CC_RET( metricSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd904, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc40, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe458, 0x00030020, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe558, 0x00021040, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe658, 0x00041031, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe758, 0x00032022, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe45c, 0x00062042, REGISTER_TYPE_FLEX ));
  
    MD_CHECK_CC_RET( metricSet->RefreshConfigRegisters() );

    return CC_OK;
}

static TCompletionCode CreateMetricSet_ADLS_GpuBusyness( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup, uint32_t platformMask )
{
    CMetricSet*   metricSet            = nullptr;
    CMetric*      metric               = nullptr;
    CInformation* information          = nullptr;
    const char*   availabilityEquation = nullptr;

    metricSet = concurrentGroup->AddMetricSet( "GpuBusyness", "GpuBusyness", API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        GPU_RENDER|GPU_COMPUTE|GPU_MEDIA|GPU_GENERIC, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, nullptr );
    MD_CHECK_PTR_RET( metricSet, CC_ERROR_GENERAL );

    MD_CHECK_CC_RET( metricSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
        "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuTime", "GPU Time Elapsed",
        "Time elapsed on the GPU during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x00" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
        "The total number of GPU core clocks elapsed during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x0c" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x08" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
        "Average GPU Core Frequency in the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuBusy", "GPU Busy",
        "The percentage of time in which the GPU has been processing GPU commands.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x10" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuActive", "EU Active",
        "The percentage of time in which the Execution Units were actively processing.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 4 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x48" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuStall", "EU Stall",
        "The percentage of time in which the Execution Units were stalled.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 5 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x50" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
        "The percentage of time in which hardware threads occupied EUs.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 6 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "8 rd40@0x34:0xa9 FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "8 qw@0x58 FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "VsThreads", "VS Threads Dispatched",
        "The total number of vertex shader hardware threads dispatched.",
        "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x18" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "HsThreads", "HS Threads Dispatched",
        "The total number of hull shader hardware threads dispatched.",
        "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 8 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x20" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "DsThreads", "DS Threads Dispatched",
        "The total number of domain shader hardware threads dispatched.",
        "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 9 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x28" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GsThreads", "GS Threads Dispatched",
        "The total number of geometry shader hardware threads dispatched.",
        "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 10 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x38" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "PsThreads", "PS Threads Dispatched",
        "The total number of pixel shader hardware threads dispatched.",
        "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 11 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x40" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "CsThreads", "CS Threads Dispatched",
        "The total number of compute shader hardware threads dispatched.",
        "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 12 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x30" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "RenderBusy", "Render Ring Busy",
        "The percentage of time when render command streamer was busy.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 13 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xf8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x1a0" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "ComputeBusy", "Compute Ring Busy",
        "The percentage of time when render command streamer was busy.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 14 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xec" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x188" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "PoshEngineBusy", "Posh Ring Busy",
        "The percentage of time when posh command streamer was busy.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 15 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xf4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x198" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "BlitterBusy", "Blitter Ring Busy",
        "The percentage of time when blitter command streamer was busy.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 16 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xf0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x190" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "VeboxBusy", "Vebox Ring Busy",
        "The percentage of time when vebox command streamer was busy.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 17 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xfc" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x1a8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "Vdbox0Busy", "Vdbox0 Ring Busy",
        "The percentage of time when Vdbox0 command streamer was busy.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 18 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xe4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x178" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "Vdbox1Busy", "Vdbox1 Ring Busy",
        "The percentage of time when Vdbox1 command streamer was busy.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH, API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 19 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xe8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x180" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "RenderAndComputeBusy", "Render and compute engines are simultaneously busy",
        "The percentage of time when render and compute engines are simultaneously busy",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 20 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xc0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x130" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "AnyEngineBusy", "Any Engine Busy",
        "The percentage of time when any command streamer was busy.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 21 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xc4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x138" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

        MD_CHECK_CC_RET( metricSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0e0e2400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x220e0009, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x220f0009, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x040b4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a0b4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x040e0043, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a0e00b3, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x200e0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x080f00a3, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x200f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x040f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a0f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x04004000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x08004000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a004000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x02014000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0401c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x15102400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x230b0120, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x15182400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x232b0120, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x17100023, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x11100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5d101000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5b100545, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x15148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1b140c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x61113000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5f110e89, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x05128000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x13138000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0f0d8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1f0b00d3, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x210b0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1b170002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0d174000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x071800a3, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x11180000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x012d8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x032b00d3, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x212b0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x55100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x57100008, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x47100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x49101004, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4b100406, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4d100a00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd904, 0x30800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc40, 0x00030000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd940, 0x00024002, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd944, 0x0000b7ff, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc00, 0x00024002, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc04, 0x0000b7ff, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd948, 0x0007f000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd94c, 0x000001ff, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc08, 0x0007f000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc0c, 0x000001ff, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe558, 0x00000008, REGISTER_TYPE_FLEX ));
  
    MD_CHECK_CC_RET( metricSet->RefreshConfigRegisters() );

    return CC_OK;
}

static TCompletionCode CreateMetricSet_ADLS_HDCAndSF( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup, uint32_t platformMask )
{
    CMetricSet*   metricSet            = nullptr;
    CMetric*      metric               = nullptr;
    CInformation* information          = nullptr;
    const char*   availabilityEquation = nullptr;

    metricSet = concurrentGroup->AddMetricSet( "HDCAndSF", "Metric set HDCAndSF", API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, nullptr );
    MD_CHECK_PTR_RET( metricSet, CC_ERROR_GENERAL );

    MD_CHECK_CC_RET( metricSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
        "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuTime", "GPU Time Elapsed",
        "Time elapsed on the GPU during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x00" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
        "The total number of GPU core clocks elapsed during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x0c" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x08" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
        "Average GPU Core Frequency in the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuBusy", "GPU Busy",
        "The percentage of time in which the GPU has been processing GPU commands.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x10" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "VsThreads", "VS Threads Dispatched",
        "The total number of vertex shader hardware threads dispatched.",
        "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x18" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "HsThreads", "HS Threads Dispatched",
        "The total number of hull shader hardware threads dispatched.",
        "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x20" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "DsThreads", "DS Threads Dispatched",
        "The total number of domain shader hardware threads dispatched.",
        "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x28" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GsThreads", "GS Threads Dispatched",
        "The total number of geometry shader hardware threads dispatched.",
        "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x38" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "PsThreads", "PS Threads Dispatched",
        "The total number of pixel shader hardware threads dispatched.",
        "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x40" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "CsThreads", "CS Threads Dispatched",
        "The total number of compute shader hardware threads dispatched.",
        "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x30" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuActive", "EU Active",
        "The percentage of time in which the Execution Units were actively processing.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x48" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuStall", "EU Stall",
        "The percentage of time in which the Execution Units were stalled.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x50" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
        "The percentage of time in which hardware threads occupied EUs.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "8 rd40@0x34:0xa9 FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "8 qw@0x58 FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
        "The total number of rasterized pixels.",
        "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 13 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xb8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
        "The total number of pixels dropped on early hierarchical depth test.",
        "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 14 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xc0" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
        "The total number of pixels dropped on early depth test.",
        "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 15 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xc8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
        "The total number of samples or pixels dropped in pixel shaders.",
        "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 16 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xd0" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
        "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
        "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 17 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xd8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SamplesWritten", "Samples Written",
        "The total number of samples or pixels written to all render targets.",
        "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 18 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xe0" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SamplesBlended", "Samples Blended",
        "The total number of blended samples or pixels written to all render targets.",
        "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 19 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xe8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SamplerTexels", "Sampler Texels",
        "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
        "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 20 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xf0" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
        "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
        "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 21 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xf8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
        "The total number of GPU memory bytes read from shared local memory.",
        "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 22 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x100" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 64 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
        "The total number of GPU memory bytes written into shared local memory.",
        "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 23 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x108" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 64 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
        "The total number of shader memory accesses to L3.",
        "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 24 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x90" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x110" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
        "The total number of shader atomic memory accesses.",
        "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 25 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x98" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x120" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
        "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
        "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 26 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten UADD $ShaderMemoryAccesses UADD 64 UMUL" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
        "The total number of shader barrier messages.",
        "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 27 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x9c" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x128" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = "$DualSubsliceMask 1 AND";
    metric = metricSet->AddMetric( "NonSamplerShader00AccessStalledOnL3", "Slice0 Dualsubslice0 Non-sampler Shader Access Stalled On L3",
        "Percentage of time when HDC has messages to L3, but it's stalled due to lack of credits (Slice0 Dualsubslice0)",
        "GPU/Data Port", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, nullptr, nullptr, 28 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xc0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x130" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$DualSubsliceMask 2 AND";
    metric = metricSet->AddMetric( "NonSamplerShader01AccessStalledOnL3", "Slice0 Dualsubslice1 Non-sampler Shader Access Stalled On L3",
        "Percentage of time when HDC has messages to L3, but it's stalled due to lack of credits (Slice0 Dualsubslice1)",
        "GPU/Data Port", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, nullptr, nullptr, 29 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xc4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x138" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "PolyDataReady", "Polygon Data Ready",
        "The percentage of time in which geometry pipeline output is ready",
        "GPU/3D Pipe/Strip-Fans", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000) | (METRIC_GROUP_NAME_ID_SF * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 30 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xc8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x140" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

        MD_CHECK_CC_RET( metricSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x14112600, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x14312600, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x240a0019, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x00110077, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x10110000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x00128000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x10138000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0e310077, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x10310000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x06310000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0e328000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1c330200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0e0b4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a0d8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0e0e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0e0f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0000c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0e004000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1000c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x06018000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x10058000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x100a00f7, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x140a0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x040a4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0c0a0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x41104000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5b105000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x11148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1b146000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4b114000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5f11a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x47100600, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4d100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4f100310, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd904, 0x70800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc40, 0x00070000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd940, 0x00000002, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd944, 0x0000fffe, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc00, 0x00000002, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc04, 0x0000fffe, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd948, 0x00000002, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd94c, 0x0000fffd, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc08, 0x00000002, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc0c, 0x0000fffd, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd950, 0x00000002, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd954, 0x0000fffb, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc10, 0x00000002, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc14, 0x0000fffb, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe558, 0x00000008, REGISTER_TYPE_FLEX ));
  
    MD_CHECK_CC_RET( metricSet->RefreshConfigRegisters() );

    return CC_OK;
}

static TCompletionCode CreateMetricSet_ADLS_L3_1( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup, uint32_t platformMask )
{
    CMetricSet*   metricSet            = nullptr;
    CMetric*      metric               = nullptr;
    CInformation* information          = nullptr;
    const char*   availabilityEquation = nullptr;

    metricSet = concurrentGroup->AddMetricSet( "L3_1", "Gen12LP L3_1", API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        GPU_RENDER|GPU_COMPUTE|GPU_MEDIA|GPU_GENERIC, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, nullptr );
    MD_CHECK_PTR_RET( metricSet, CC_ERROR_GENERAL );

    MD_CHECK_CC_RET( metricSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
        "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuTime", "GPU Time Elapsed",
        "Time elapsed on the GPU during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x00" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
        "The total number of GPU core clocks elapsed during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x0c" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x08" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
        "Average GPU Core Frequency in the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuBusy", "GPU Busy",
        "The percentage of time in which the GPU has been processing GPU commands.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x10" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuActive", "EU Active",
        "The percentage of time in which the Execution Units were actively processing.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 4 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x48" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuStall", "EU Stall",
        "The percentage of time in which the Execution Units were stalled.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 5 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x50" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
        "The percentage of time in which hardware threads occupied EUs.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 6 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "8 rd40@0x34:0xa9 FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "8 qw@0x58 FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "VsThreads", "VS Threads Dispatched",
        "The total number of vertex shader hardware threads dispatched.",
        "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x18" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "HsThreads", "HS Threads Dispatched",
        "The total number of hull shader hardware threads dispatched.",
        "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 8 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x20" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "DsThreads", "DS Threads Dispatched",
        "The total number of domain shader hardware threads dispatched.",
        "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 9 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x28" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GsThreads", "GS Threads Dispatched",
        "The total number of geometry shader hardware threads dispatched.",
        "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 10 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x38" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "PsThreads", "PS Threads Dispatched",
        "The total number of pixel shader hardware threads dispatched.",
        "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 11 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x40" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "CsThreads", "CS Threads Dispatched",
        "The total number of compute shader hardware threads dispatched.",
        "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 12 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x30" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = "$SliceMask 1 AND";
    metric = metricSet->AddMetric( "L30Bank0InputAvailable", "Slice0 L3 Bank0 Input Available",
        "The percentage of time in which slice0 L3 bank0 has input available",
        "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 13 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xfc dw@0xf8 FADD dw@0xf4 FADD dw@0xf0 FADD 4 FDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x1a8 qw@0x1a0 FADD qw@0x198 FADD qw@0x190 FADD 4 FDIV" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$SliceMask 1 AND";
    metric = metricSet->AddMetric( "L30Bank1InputAvailable", "Slice0 L3 Bank1 Input Available",
        "The percentage of time in which slice0 L3 bank1 has input available",
        "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 14 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xec dw@0xe8 FADD dw@0xe4 FADD dw@0xe0 FADD 4 FDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x188 qw@0x180 FADD qw@0x178 FADD qw@0x170 FADD 4 FDIV" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

        MD_CHECK_CC_RET( metricSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x04002827, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0600202c, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1c000024, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1e000025, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x02000026, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0800002d, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a00002e, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0c00002f, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x3a000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x34000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x36000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5d101400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5b100555, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1d140030, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x13148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x15148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x17148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1b141c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x61112800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5f110aaa, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x55100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x57100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x47100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x49100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4b100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4d100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd904, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc40, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe558, 0x00000008, REGISTER_TYPE_FLEX ));
  
    MD_CHECK_CC_RET( metricSet->RefreshConfigRegisters() );

    return CC_OK;
}

static TCompletionCode CreateMetricSet_ADLS_L3_2( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup, uint32_t platformMask )
{
    CMetricSet*   metricSet            = nullptr;
    CMetric*      metric               = nullptr;
    CInformation* information          = nullptr;
    const char*   availabilityEquation = nullptr;

    metricSet = concurrentGroup->AddMetricSet( "L3_2", "Gen12LP L3_2", API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        GPU_RENDER|GPU_COMPUTE|GPU_MEDIA|GPU_GENERIC, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, nullptr );
    MD_CHECK_PTR_RET( metricSet, CC_ERROR_GENERAL );

    MD_CHECK_CC_RET( metricSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
        "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuTime", "GPU Time Elapsed",
        "Time elapsed on the GPU during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x00" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
        "The total number of GPU core clocks elapsed during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x0c" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x08" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
        "Average GPU Core Frequency in the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuBusy", "GPU Busy",
        "The percentage of time in which the GPU has been processing GPU commands.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x10" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "VsThreads", "VS Threads Dispatched",
        "The total number of vertex shader hardware threads dispatched.",
        "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x18" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "HsThreads", "HS Threads Dispatched",
        "The total number of hull shader hardware threads dispatched.",
        "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x20" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "DsThreads", "DS Threads Dispatched",
        "The total number of domain shader hardware threads dispatched.",
        "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x28" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GsThreads", "GS Threads Dispatched",
        "The total number of geometry shader hardware threads dispatched.",
        "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x38" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "PsThreads", "PS Threads Dispatched",
        "The total number of pixel shader hardware threads dispatched.",
        "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x40" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "CsThreads", "CS Threads Dispatched",
        "The total number of compute shader hardware threads dispatched.",
        "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x30" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuActive", "EU Active",
        "The percentage of time in which the Execution Units were actively processing.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x48" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuStall", "EU Stall",
        "The percentage of time in which the Execution Units were stalled.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x50" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
        "The percentage of time in which hardware threads occupied EUs.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "8 rd40@0x34:0xa9 FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "8 qw@0x58 FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$SliceMask 1 AND";
    metric = metricSet->AddMetric( "L30Bank2InputAvailable", "Slice0 L3 Bank2 Input Available",
        "The percentage of time in which slice0 L3 bank2 has input available",
        "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 13 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xf0 dw@0xf4 FADD dw@0xf8 FADD dw@0xfc FADD 4 FDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x190 qw@0x198 FADD qw@0x1a0 FADD qw@0x1a8 FADD 4 FDIV" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$SliceMask 1 AND";
    metric = metricSet->AddMetric( "L30Bank3InputAvailable", "Slice0 L3 Bank3 Input Available",
        "The percentage of time in which slice0 L3 bank3 has input available",
        "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 14 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xe0 dw@0xe4 FADD dw@0xe8 FADD dw@0xec FADD 4 FDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x170 qw@0x178 FADD qw@0x180 FADD qw@0x188 FADD 4 FDIV" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

        MD_CHECK_CC_RET( metricSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x04003824, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0600302f, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1c000027, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1e000026, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x02000025, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0800002e, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a00002d, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0c00002c, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x3a000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x34000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x36000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5d101400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5b100555, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1d140030, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x13148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x15148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x17148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1b141c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x61112800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5f110aaa, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x55100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x57100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x47100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x49100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4b100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4d100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd904, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc40, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe558, 0x00000008, REGISTER_TYPE_FLEX ));
  
    MD_CHECK_CC_RET( metricSet->RefreshConfigRegisters() );

    return CC_OK;
}

static TCompletionCode CreateMetricSet_ADLS_L3_3( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup, uint32_t platformMask )
{
    CMetricSet*   metricSet            = nullptr;
    CMetric*      metric               = nullptr;
    CInformation* information          = nullptr;
    const char*   availabilityEquation = nullptr;

    metricSet = concurrentGroup->AddMetricSet( "L3_3", "Gen12LP L3_3", API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        GPU_RENDER|GPU_COMPUTE|GPU_MEDIA|GPU_GENERIC, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, nullptr );
    MD_CHECK_PTR_RET( metricSet, CC_ERROR_GENERAL );

    MD_CHECK_CC_RET( metricSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
        "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuTime", "GPU Time Elapsed",
        "Time elapsed on the GPU during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x00" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
        "The total number of GPU core clocks elapsed during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x0c" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x08" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
        "Average GPU Core Frequency in the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuBusy", "GPU Busy",
        "The percentage of time in which the GPU has been processing GPU commands.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x10" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "VsThreads", "VS Threads Dispatched",
        "The total number of vertex shader hardware threads dispatched.",
        "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x18" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "HsThreads", "HS Threads Dispatched",
        "The total number of hull shader hardware threads dispatched.",
        "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x20" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "DsThreads", "DS Threads Dispatched",
        "The total number of domain shader hardware threads dispatched.",
        "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x28" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GsThreads", "GS Threads Dispatched",
        "The total number of geometry shader hardware threads dispatched.",
        "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x38" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "PsThreads", "PS Threads Dispatched",
        "The total number of pixel shader hardware threads dispatched.",
        "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x40" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "CsThreads", "CS Threads Dispatched",
        "The total number of compute shader hardware threads dispatched.",
        "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x30" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuActive", "EU Active",
        "The percentage of time in which the Execution Units were actively processing.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x48" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuStall", "EU Stall",
        "The percentage of time in which the Execution Units were stalled.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x50" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
        "The percentage of time in which hardware threads occupied EUs.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "8 rd40@0x34:0xa9 FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "8 qw@0x58 FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$SliceMask 1 AND";
    metric = metricSet->AddMetric( "L30Bank0OutputReady", "Slice0 L3 Bank0 Output Ready",
        "The percentage of time in which slice0 L3 bank0 output is ready",
        "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 13 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xfc dw@0xf8 UADD" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x1a8 qw@0x1a0 UADD" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

        MD_CHECK_CC_RET( metricSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x04000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x06000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a000020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0c000028, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x3a000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5b100500, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1b141800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5f110a00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4b100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4d100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd904, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc40, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe558, 0x00000008, REGISTER_TYPE_FLEX ));
  
    MD_CHECK_CC_RET( metricSet->RefreshConfigRegisters() );

    return CC_OK;
}

static TCompletionCode CreateMetricSet_ADLS_L3_4( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup, uint32_t platformMask )
{
    CMetricSet*   metricSet            = nullptr;
    CMetric*      metric               = nullptr;
    CInformation* information          = nullptr;
    const char*   availabilityEquation = nullptr;

    metricSet = concurrentGroup->AddMetricSet( "L3_4", "Gen12LP L3_4", API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        GPU_RENDER|GPU_COMPUTE|GPU_MEDIA|GPU_GENERIC, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, nullptr );
    MD_CHECK_PTR_RET( metricSet, CC_ERROR_GENERAL );

    MD_CHECK_CC_RET( metricSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
        "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuTime", "GPU Time Elapsed",
        "Time elapsed on the GPU during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x00" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
        "The total number of GPU core clocks elapsed during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x0c" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x08" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
        "Average GPU Core Frequency in the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuBusy", "GPU Busy",
        "The percentage of time in which the GPU has been processing GPU commands.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x10" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "VsThreads", "VS Threads Dispatched",
        "The total number of vertex shader hardware threads dispatched.",
        "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x18" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "HsThreads", "HS Threads Dispatched",
        "The total number of hull shader hardware threads dispatched.",
        "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x20" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "DsThreads", "DS Threads Dispatched",
        "The total number of domain shader hardware threads dispatched.",
        "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x28" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GsThreads", "GS Threads Dispatched",
        "The total number of geometry shader hardware threads dispatched.",
        "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x38" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "PsThreads", "PS Threads Dispatched",
        "The total number of pixel shader hardware threads dispatched.",
        "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x40" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "CsThreads", "CS Threads Dispatched",
        "The total number of compute shader hardware threads dispatched.",
        "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x30" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuActive", "EU Active",
        "The percentage of time in which the Execution Units were actively processing.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x48" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuStall", "EU Stall",
        "The percentage of time in which the Execution Units were stalled.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x50" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
        "The percentage of time in which hardware threads occupied EUs.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "8 rd40@0x34:0xa9 FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "8 qw@0x58 FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$SliceMask 1 AND";
    metric = metricSet->AddMetric( "L30Bank1OutputReady", "Slice0 L3 Bank1 Output Ready",
        "The percentage of time in which slice0 L3 bank1 output is ready",
        "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 13 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xf8 dw@0xfc UADD" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x1a0 qw@0x1a8 UADD" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

        MD_CHECK_CC_RET( metricSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x04000800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x06000a00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a000020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0c000028, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x3a000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5b100500, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1b141800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5f110a00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4b100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4d100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd904, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc40, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe558, 0x00000008, REGISTER_TYPE_FLEX ));
  
    MD_CHECK_CC_RET( metricSet->RefreshConfigRegisters() );

    return CC_OK;
}

static TCompletionCode CreateMetricSet_ADLS_L3_5( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup, uint32_t platformMask )
{
    CMetricSet*   metricSet            = nullptr;
    CMetric*      metric               = nullptr;
    CInformation* information          = nullptr;
    const char*   availabilityEquation = nullptr;

    metricSet = concurrentGroup->AddMetricSet( "L3_5", "Gen12LP L3_5", API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        GPU_RENDER|GPU_COMPUTE|GPU_MEDIA|GPU_GENERIC, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, nullptr );
    MD_CHECK_PTR_RET( metricSet, CC_ERROR_GENERAL );

    MD_CHECK_CC_RET( metricSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
        "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuTime", "GPU Time Elapsed",
        "Time elapsed on the GPU during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x00" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
        "The total number of GPU core clocks elapsed during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x0c" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x08" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
        "Average GPU Core Frequency in the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuBusy", "GPU Busy",
        "The percentage of time in which the GPU has been processing GPU commands.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x10" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "VsThreads", "VS Threads Dispatched",
        "The total number of vertex shader hardware threads dispatched.",
        "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x18" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "HsThreads", "HS Threads Dispatched",
        "The total number of hull shader hardware threads dispatched.",
        "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x20" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "DsThreads", "DS Threads Dispatched",
        "The total number of domain shader hardware threads dispatched.",
        "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x28" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GsThreads", "GS Threads Dispatched",
        "The total number of geometry shader hardware threads dispatched.",
        "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x38" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "PsThreads", "PS Threads Dispatched",
        "The total number of pixel shader hardware threads dispatched.",
        "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x40" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "CsThreads", "CS Threads Dispatched",
        "The total number of compute shader hardware threads dispatched.",
        "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x30" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuActive", "EU Active",
        "The percentage of time in which the Execution Units were actively processing.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x48" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuStall", "EU Stall",
        "The percentage of time in which the Execution Units were stalled.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x50" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
        "The percentage of time in which hardware threads occupied EUs.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "8 rd40@0x34:0xa9 FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "8 qw@0x58 FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$SliceMask 1 AND";
    metric = metricSet->AddMetric( "L30Bank2OutputReady", "Slice0 L3 Bank2 Output Ready",
        "The percentage of time in which slice0 L3 bank2 output is ready",
        "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 13 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xf8 dw@0xfc UADD" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x1a0 qw@0x1a8 UADD" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

        MD_CHECK_CC_RET( metricSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x04001000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x06001200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a000020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0c000028, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x3a000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5b100500, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1b141800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5f110a00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4b100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4d100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd904, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc40, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe558, 0x00000008, REGISTER_TYPE_FLEX ));
  
    MD_CHECK_CC_RET( metricSet->RefreshConfigRegisters() );

    return CC_OK;
}

static TCompletionCode CreateMetricSet_ADLS_L3_6( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup, uint32_t platformMask )
{
    CMetricSet*   metricSet            = nullptr;
    CMetric*      metric               = nullptr;
    CInformation* information          = nullptr;
    const char*   availabilityEquation = nullptr;

    metricSet = concurrentGroup->AddMetricSet( "L3_6", "Gen12LP L3_6", API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        GPU_RENDER|GPU_COMPUTE|GPU_MEDIA|GPU_GENERIC, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, nullptr );
    MD_CHECK_PTR_RET( metricSet, CC_ERROR_GENERAL );

    MD_CHECK_CC_RET( metricSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
        "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuTime", "GPU Time Elapsed",
        "Time elapsed on the GPU during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x00" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
        "The total number of GPU core clocks elapsed during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x0c" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x08" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
        "Average GPU Core Frequency in the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuBusy", "GPU Busy",
        "The percentage of time in which the GPU has been processing GPU commands.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x10" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "VsThreads", "VS Threads Dispatched",
        "The total number of vertex shader hardware threads dispatched.",
        "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x18" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "HsThreads", "HS Threads Dispatched",
        "The total number of hull shader hardware threads dispatched.",
        "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x20" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "DsThreads", "DS Threads Dispatched",
        "The total number of domain shader hardware threads dispatched.",
        "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x28" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GsThreads", "GS Threads Dispatched",
        "The total number of geometry shader hardware threads dispatched.",
        "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x38" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "PsThreads", "PS Threads Dispatched",
        "The total number of pixel shader hardware threads dispatched.",
        "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x40" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "CsThreads", "CS Threads Dispatched",
        "The total number of compute shader hardware threads dispatched.",
        "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x30" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuActive", "EU Active",
        "The percentage of time in which the Execution Units were actively processing.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x48" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuStall", "EU Stall",
        "The percentage of time in which the Execution Units were stalled.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x50" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
        "The percentage of time in which hardware threads occupied EUs.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "8 rd40@0x34:0xa9 FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "8 qw@0x58 FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$SliceMask 1 AND";
    metric = metricSet->AddMetric( "L30Bank3OutputReady", "Slice0 L3 Bank3 Output Ready",
        "The percentage of time in which slice0 L3 bank3 output is ready",
        "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 13 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xf8 dw@0xfc UADD" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x1a0 qw@0x1a8 UADD" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

        MD_CHECK_CC_RET( metricSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x04001800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x06001a00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a000020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0c000028, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x3a000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5b100500, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1b141800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5f110a00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4b100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4d100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd904, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc40, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe558, 0x00000008, REGISTER_TYPE_FLEX ));
  
    MD_CHECK_CC_RET( metricSet->RefreshConfigRegisters() );

    return CC_OK;
}

static TCompletionCode CreateMetricSet_ADLS_RasterizerAndPixelBackend( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup, uint32_t platformMask )
{
    CMetricSet*   metricSet            = nullptr;
    CMetric*      metric               = nullptr;
    CInformation* information          = nullptr;
    const char*   availabilityEquation = nullptr;

    metricSet = concurrentGroup->AddMetricSet( "RasterizerAndPixelBackend", "Metric set RasterizerAndPixelBackend", API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, nullptr );
    MD_CHECK_PTR_RET( metricSet, CC_ERROR_GENERAL );

    MD_CHECK_CC_RET( metricSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
        "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuTime", "GPU Time Elapsed",
        "Time elapsed on the GPU during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x00" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
        "The total number of GPU core clocks elapsed during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x0c" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x08" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
        "Average GPU Core Frequency in the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuBusy", "GPU Busy",
        "The percentage of time in which the GPU has been processing GPU commands.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x10" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "VsThreads", "VS Threads Dispatched",
        "The total number of vertex shader hardware threads dispatched.",
        "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x18" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "HsThreads", "HS Threads Dispatched",
        "The total number of hull shader hardware threads dispatched.",
        "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x20" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "DsThreads", "DS Threads Dispatched",
        "The total number of domain shader hardware threads dispatched.",
        "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x28" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GsThreads", "GS Threads Dispatched",
        "The total number of geometry shader hardware threads dispatched.",
        "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x38" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "PsThreads", "PS Threads Dispatched",
        "The total number of pixel shader hardware threads dispatched.",
        "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x40" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "CsThreads", "CS Threads Dispatched",
        "The total number of compute shader hardware threads dispatched.",
        "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x30" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuActive", "EU Active",
        "The percentage of time in which the Execution Units were actively processing.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x48" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuStall", "EU Stall",
        "The percentage of time in which the Execution Units were stalled.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x50" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
        "The percentage of time in which hardware threads occupied EUs.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "8 rd40@0x34:0xa9 FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "8 qw@0x58 FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
        "The total number of rasterized pixels.",
        "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 13 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xb8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
        "The total number of pixels dropped on early hierarchical depth test.",
        "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 14 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xc0" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
        "The total number of pixels dropped on early depth test.",
        "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 15 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xc8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
        "The total number of samples or pixels dropped in pixel shaders.",
        "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 16 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xd0" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
        "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
        "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 17 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xd8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SamplesWritten", "Samples Written",
        "The total number of samples or pixels written to all render targets.",
        "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 18 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xe0" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SamplesBlended", "Samples Blended",
        "The total number of blended samples or pixels written to all render targets.",
        "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 19 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xe8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SamplerTexels", "Sampler Texels",
        "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
        "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 20 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xf0" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
        "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
        "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 21 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xf8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
        "The total number of GPU memory bytes read from shared local memory.",
        "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 22 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x100" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 64 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
        "The total number of GPU memory bytes written into shared local memory.",
        "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 23 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x108" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 64 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
        "The total number of shader memory accesses to L3.",
        "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 24 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x90" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x110" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
        "The total number of shader atomic memory accesses.",
        "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 25 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x98" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x120" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
        "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
        "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 26 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten UADD $ShaderMemoryAccesses UADD 64 UMUL" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
        "The total number of shader barrier messages.",
        "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 27 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x9c" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x128" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = "$SliceMask 1 AND";
    metric = metricSet->AddMetric( "Rasterizer0InputAvailable", "Slice0 Rasterizer Input Available",
        "The percentage of time in which slice0 rasterizer input is available",
        "GPU/Rasterizer", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 28 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xc0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x130" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$SliceMask 1 AND";
    metric = metricSet->AddMetric( "Rasterizer0OutputReady", "Slice0 Rasterizer Output Ready",
        "The percentage of time in which slice0 rasterizer output is ready",
        "GPU/Rasterizer", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 29 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xf4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x198" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "PixelData00Ready", "Slice0 Pipe0 Post-EarlyZ Pixel Data Ready",
        "The percentage of time in which slice0  pipe0 post-EarlyZ pixel data is ready (after early Z tests have been applied)",
        "GPU/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 30 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xc4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x138" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "PSOutput00Available", "Slice0 Pipe0 PS Output Available",
        "The percentage of time in which slice0 pipe0 PS output is available",
        "GPU/3D Pipe", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 31 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xf8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x1a0" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "PixelValues00Ready", "Slice0 Pipe0 Pixel Values Ready",
        "The percentage of time in which slice0 pipe0 pixel values are ready",
        "GPU/3D Pipe", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 32 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xfc" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x1a8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GTRequestQueue00Full", "SQ00 is full",
        "The percentage of time when IDI0 SQ0 is filled above a threshold (usually 48 entries)",
        "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 33 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xf0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x190" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GTRequestQueue01Full", "SQ01 is full",
        "The percentage of time when IDI0 SQ1 is filled above a threshold (usually 48 entries)",
        "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 34 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xec" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x188" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GTRequestQueue10Full", "SQ10 is full",
        "The percentage of time when IDI1 SQ0 is filled above a threshold (usually 48 entries)",
        "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 35 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xe8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x180" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GTRequestQueue11Full", "SQ11 is full",
        "The percentage of time when IDI1 SQ1 is filled above a threshold (usually 48 entries)",
        "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 36 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xe4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x178" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

        MD_CHECK_CC_RET( metricSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1e055000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1a0500c0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x2a0a7300, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x2c0a0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x120800a0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0000c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0e00c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1000c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x12008000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x34000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0800c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a00c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0c00c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x04052700, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x060500c0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x22050000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1c050000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x000a0144, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0e0a0145, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x100a0156, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x080a814f, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x140a0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x040a0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a0a4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0c0a0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x08081980, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a080032, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x10080000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x16080000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x31152800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x331500a0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x31352800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x333500a0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x41104000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5b10556b, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5d103005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x11148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1b14fc00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1d140001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4b114000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5f11aa80, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x6111000a, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x05150096, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x07150016, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x01150000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0316c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1f350096, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x03350016, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x01350000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0f368000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x01368000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x47100200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4d100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4f100202, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x51100202, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x55100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x57100009, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x49100909, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4b100209, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd904, 0x30800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc40, 0x00030000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd940, 0x00000038, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd944, 0x0000fff8, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc00, 0x00000038, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc04, 0x0000fff8, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd948, 0x000000c0, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd94c, 0x0000ffe7, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc08, 0x000000c0, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc0c, 0x0000ffe7, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe558, 0x00000008, REGISTER_TYPE_FLEX ));
  
    MD_CHECK_CC_RET( metricSet->RefreshConfigRegisters() );

    return CC_OK;
}

static TCompletionCode CreateMetricSet_ADLS_RenderPipeProfile( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup, uint32_t platformMask )
{
    CMetricSet*   metricSet            = nullptr;
    CMetric*      metric               = nullptr;
    CInformation* information          = nullptr;
    const char*   availabilityEquation = nullptr;

    metricSet = concurrentGroup->AddMetricSet( "RenderPipeProfile", "Render Metrics for 3D Pipeline Profile", API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        GPU_RENDER, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, nullptr );
    MD_CHECK_PTR_RET( metricSet, CC_ERROR_GENERAL );

    MD_CHECK_CC_RET( metricSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
        "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuTime", "GPU Time Elapsed",
        "Time elapsed on the GPU during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x00" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
        "The total number of GPU core clocks elapsed during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x0c" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x08" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
        "Average GPU Core Frequency in the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuBusy", "GPU Busy",
        "The percentage of time in which the GPU has been processing GPU commands.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x10" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "VsThreads", "VS Threads Dispatched",
        "The total number of vertex shader hardware threads dispatched.",
        "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x18" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "HsThreads", "HS Threads Dispatched",
        "The total number of hull shader hardware threads dispatched.",
        "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x20" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "DsThreads", "DS Threads Dispatched",
        "The total number of domain shader hardware threads dispatched.",
        "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x28" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GsThreads", "GS Threads Dispatched",
        "The total number of geometry shader hardware threads dispatched.",
        "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x38" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "PsThreads", "PS Threads Dispatched",
        "The total number of pixel shader hardware threads dispatched.",
        "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x40" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "CsThreads", "CS Threads Dispatched",
        "The total number of compute shader hardware threads dispatched.",
        "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x30" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuActive", "EU Active",
        "The percentage of time in which the Execution Units were actively processing.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x48" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuStall", "EU Stall",
        "The percentage of time in which the Execution Units were stalled.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x50" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
        "The percentage of time in which hardware threads occupied EUs.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "8 rd40@0x34:0xa9 FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "8 qw@0x58 FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
        "The total number of rasterized pixels.",
        "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 13 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xb8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
        "The total number of pixels dropped on early hierarchical depth test.",
        "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 14 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xc0" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
        "The total number of pixels dropped on early depth test.",
        "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 15 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xc8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
        "The total number of samples or pixels dropped in pixel shaders.",
        "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 16 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xd0" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
        "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
        "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 17 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xd8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SamplesWritten", "Samples Written",
        "The total number of samples or pixels written to all render targets.",
        "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 18 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xe0" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SamplesBlended", "Samples Blended",
        "The total number of blended samples or pixels written to all render targets.",
        "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 19 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xe8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SamplerTexels", "Sampler Texels",
        "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
        "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 20 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xf0" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
        "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
        "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 21 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0xf8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 4 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
        "The total number of GPU memory bytes read from shared local memory.",
        "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 22 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x100" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 64 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
        "The total number of GPU memory bytes written into shared local memory.",
        "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 23 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x108" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$Self 64 UMUL" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
        "The total number of shader memory accesses to L3.",
        "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 24 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x90" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x110" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
        "The total number of shader atomic memory accesses.",
        "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 25 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x98" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x120" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
        "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
        "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 26 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten UADD $ShaderMemoryAccesses UADD 64 UMUL" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
        "The total number of shader barrier messages.",
        "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 27 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x9c" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x128" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "VfBottleneck", "VF Bottleneck",
        "The percentage of time in which vertex fetch pipeline stage was slowing down the 3D pipeline.",
        "3D Pipe/Input Assembler", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_IA * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 28 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xfc" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x1a8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "VsBottleneck", "VS Bottleneck",
        "The percentage of time in which vertex shader pipeline stage was slowing down the 3D pipeline.",
        "3D Pipe/Vertex Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 10, 30, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 29 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xf8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x1a0" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "HsBottleneck", "HS Bottleneck",
        "The percentage of time in which hull shader pipeline stage was slowing down the 3D pipeline.",
        "3D Pipe/Hull Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 3, 9, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", nullptr, 30 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xd4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x158" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "DsBottleneck", "DS Bottleneck",
        "The percentage of time in which domain shader pipeline stage was slowing down the 3D pipeline.",
        "3D Pipe/Domain Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", nullptr, 31 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xf4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x198" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GsBottleneck", "GS Bottleneck",
        "The percentage of time in which geometry shader pipeline stage was slowing down the 3D pipeline.",
        "3D Pipe/Geometry Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 32 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xd0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x150" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SoBottleneck", "SO Bottleneck",
        "The percentage of time in which stream output pipeline stage was slowing down the 3D pipeline.",
        "3D Pipe/Stream Output", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_SO * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 33 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xf0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x190" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "ClBottleneck", "Clipper Bottleneck",
        "The percentage of time in which clipper pipeline stage was slowing down the 3D pipeline.",
        "3D Pipe/Clipper", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_CL * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 10, 30, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 34 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xec" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x188" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SfBottleneck", "Strip-Fans Bottleneck",
        "The percentage of time in which strip-fans pipeline stage was slowing down the 3D pipeline.",
        "3D Pipe/Rasterizer/Strip-Fans", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_SF * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 10, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 35 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xe8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x180" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "HiDepthBottleneck", "Hi-Depth Bottleneck",
        "The percentage of time in which early hierarchical depth test pipeline stage was slowing down the 3D pipeline.",
        "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 36 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xcc" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x148" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "BcBottleneck", "BC Bottleneck",
        "The percentage of time in which barycentric coordinates calculation pipeline stage was slowing down the 3D pipeline.",
        "3D Pipe/Rasterizer/Barycentric Calc", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_BC * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 37 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xe4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x178" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "HsStall", "HS Stall",
        "The percentage of time in which hull stall pipeline stage was stalled.",
        "3D Pipe/Hull Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_CORRELATE|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", nullptr, 38 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xc8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x140" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "DsStall", "DS Stall",
        "The percentage of time in which domain shader pipeline stage was stalled.",
        "3D Pipe/Domain Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_CORRELATE|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", nullptr, 39 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xe0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x170" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SoStall", "SO Stall",
        "The percentage of time in which stream-output pipeline stage was stalled.",
        "3D Pipe/Stream Output", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_SO * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_CORRELATE|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 40 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xdc" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x168" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "ClStall", "CL Stall",
        "The percentage of time in which clipper pipeline stage was stalled.",
        "3D Pipe/Clipper", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_CL * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_CORRELATE|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 41 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xc4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x138" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "SfStall", "SF Stall",
        "The percentage of time in which strip-fans pipeline stage was stalled.",
        "3D Pipe/Rasterizer/Strip-Fans", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_SF * 0x100), USAGE_FLAG_TIER_4|USAGE_FLAG_CORRELATE|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 42 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xd8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x160" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

        MD_CHECK_CC_RET( metricSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x00123e00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x060b00b3, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x140bbc00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1c0b4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x120c0320, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x040d3e00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x000d0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x280d0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x2c0e001f, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x10087c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1e120002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x20120000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1e130002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0e0b0031, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x180b0092, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1a0b00b1, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x020b0093, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x040b0033, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x200b0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x100b4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x160b4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x080b4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a0b4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0c0b4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a0c0022, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x100c0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x100d0017, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x160d0013, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1c0d0081, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x080d0082, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a0d0102, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x140d0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0c0d0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0e0d0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x120d0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0c0e0225, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x200e0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x100e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x160e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1c0e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x080e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a0e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0e0f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x100f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x140f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x160f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x180f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1a0f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1c0f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x020f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x040f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x060f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x080f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a0f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0c0f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0e004000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x10004000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x12008000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x34005540, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x36000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x02004000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x04004000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x06004000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x08004000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a004000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0c004000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0601c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x08014000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a01c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1801e000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x00018000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0201c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0401c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x22050800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x120a8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x08081000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x16080000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5b105555, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5d101555, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1b14fc00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1d14003f, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x13148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x15148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x17148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5f11aaaa, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x61112aaa, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4d100200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4f100004, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x51100208, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x53100400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x55100004, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x57100002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x47100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x49100404, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4b100004, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd904, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc40, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe558, 0x00000008, REGISTER_TYPE_FLEX ));
  
    MD_CHECK_CC_RET( metricSet->RefreshConfigRegisters() );

    return CC_OK;
}

static TCompletionCode CreateMetricSet_ADLS_Sampler( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup, uint32_t platformMask )
{
    CMetricSet*   metricSet            = nullptr;
    CMetric*      metric               = nullptr;
    CInformation* information          = nullptr;
    const char*   availabilityEquation = nullptr;

    metricSet = concurrentGroup->AddMetricSet( "Sampler", "Sampler", API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        GPU_RENDER|GPU_COMPUTE|GPU_MEDIA|GPU_GENERIC, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, nullptr );
    MD_CHECK_PTR_RET( metricSet, CC_ERROR_GENERAL );

    MD_CHECK_CC_RET( metricSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
        "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuTime", "GPU Time Elapsed",
        "Time elapsed on the GPU during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x00" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
        "The total number of GPU core clocks elapsed during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x0c" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x08" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
        "Average GPU Core Frequency in the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuBusy", "GPU Busy",
        "The percentage of time in which the GPU has been processing GPU commands.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x10" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "VsThreads", "VS Threads Dispatched",
        "The total number of vertex shader hardware threads dispatched.",
        "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x18" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "HsThreads", "HS Threads Dispatched",
        "The total number of hull shader hardware threads dispatched.",
        "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x20" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "DsThreads", "DS Threads Dispatched",
        "The total number of domain shader hardware threads dispatched.",
        "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x28" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GsThreads", "GS Threads Dispatched",
        "The total number of geometry shader hardware threads dispatched.",
        "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x38" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "PsThreads", "PS Threads Dispatched",
        "The total number of pixel shader hardware threads dispatched.",
        "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x40" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "CsThreads", "CS Threads Dispatched",
        "The total number of compute shader hardware threads dispatched.",
        "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x30" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuActive", "EU Active",
        "The percentage of time in which the Execution Units were actively processing.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x48" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuStall", "EU Stall",
        "The percentage of time in which the Execution Units were stalled.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x50" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
        "The percentage of time in which hardware threads occupied EUs.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "8 rd40@0x34:0xa9 FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "8 qw@0x58 FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$DualSubsliceMask 1 AND";
    metric = metricSet->AddMetric( "Sampler00InputAvailable", "Slice0 DualSubslice0 Input Available",
        "The percentage of time in which slice0 dualsubslice0 sampler input is available",
        "GPU/Sampler", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 13 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xc4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x138" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$DualSubsliceMask 2 AND";
    metric = metricSet->AddMetric( "Sampler01InputAvailable", "Slice0 DualSubslice1 Input Available",
        "The percentage of time in which slice0 dualsubslice1 sampler input is available",
        "GPU/Sampler", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 14 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xc0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x130" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$DualSubsliceMask 1 AND";
    metric = metricSet->AddMetric( "Sampler00OutputReady", "Slice0 DualSubslice0 Sampler Output Ready",
        "The percentage of time in which slice0 dualsubslice0 sampler output is ready",
        "GPU/Sampler", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, nullptr, nullptr, 15 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xc8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x140" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$DualSubsliceMask 2 AND";
    metric = metricSet->AddMetric( "Sampler01OutputReady", "Slice0 DualSubslice1 Sampler Output Ready",
        "The percentage of time in which slice0 dualsubslice1 sampler output is ready",
        "GPU/Sampler", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, nullptr, nullptr, 16 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xcc" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x148" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

        MD_CHECK_CC_RET( metricSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0c123e00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1c121600, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x04143e00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x18141600, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0c323e00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1c321600, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x04343e00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x18341613, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x12120086, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x16120033, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x20120000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x10124000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x14124000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1c133c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x101400a6, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x14140013, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x08140000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a140000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1c150088, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0e320086, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1a320033, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x20320000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x00324000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x18324000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x10338000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1c33c200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x003400a6, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x10340000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0c340000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x18358000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1c350800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x000b4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0e0b4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x180b4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1a0b4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x040d4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a0d8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x100dc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x000e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0e0e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x180e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1a0e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x000f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0e0f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x180f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1a0f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x00004000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0e004000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1000c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1200c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x340017c0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x00014000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x06018000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x18016000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x220500f0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0c0ac000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0e0ac000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x41104000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5b105000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5d100155, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x11148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1b14e000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1d14000f, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4b114000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5f11a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x611102aa, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x47100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4d100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4f100604, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5110060a, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5310000a, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x55100004, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd904, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc40, 0x000f0000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd940, 0x00000018, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd944, 0x0000fffc, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc00, 0x00000018, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc04, 0x0000fffc, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd948, 0x00000060, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd94c, 0x0000fff3, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc08, 0x00000060, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc0c, 0x0000fff3, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd950, 0x00000180, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd954, 0x0000ffcf, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc10, 0x00000180, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc14, 0x0000ffcf, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd958, 0x00000600, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd95c, 0x0000ff3f, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc18, 0x00000600, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc1c, 0x0000ff3f, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe558, 0x00000008, REGISTER_TYPE_FLEX ));
  
    MD_CHECK_CC_RET( metricSet->RefreshConfigRegisters() );

    return CC_OK;
}

static TCompletionCode CreateMetricSet_ADLS_TDL( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup, uint32_t platformMask )
{
    CMetricSet*   metricSet            = nullptr;
    CMetric*      metric               = nullptr;
    CInformation* information          = nullptr;
    const char*   availabilityEquation = nullptr;

    metricSet = concurrentGroup->AddMetricSet( "TDL", "TDL", API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        GPU_RENDER|GPU_COMPUTE|GPU_MEDIA|GPU_GENERIC, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, nullptr );
    MD_CHECK_PTR_RET( metricSet, CC_ERROR_GENERAL );

    MD_CHECK_CC_RET( metricSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
        "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuTime", "GPU Time Elapsed",
        "Time elapsed on the GPU during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x00" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
        "The total number of GPU core clocks elapsed during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x0c" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x08" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
        "Average GPU Core Frequency in the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuBusy", "GPU Busy",
        "The percentage of time in which the GPU has been processing GPU commands.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x10" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "VsThreads", "VS Threads Dispatched",
        "The total number of vertex shader hardware threads dispatched.",
        "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x18" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "HsThreads", "HS Threads Dispatched",
        "The total number of hull shader hardware threads dispatched.",
        "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x20" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "DsThreads", "DS Threads Dispatched",
        "The total number of domain shader hardware threads dispatched.",
        "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x28" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GsThreads", "GS Threads Dispatched",
        "The total number of geometry shader hardware threads dispatched.",
        "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x38" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "PsThreads", "PS Threads Dispatched",
        "The total number of pixel shader hardware threads dispatched.",
        "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x40" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "CsThreads", "CS Threads Dispatched",
        "The total number of compute shader hardware threads dispatched.",
        "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x30" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuActive", "EU Active",
        "The percentage of time in which the Execution Units were actively processing.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x48" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuStall", "EU Stall",
        "The percentage of time in which the Execution Units were stalled.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x50" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
        "The percentage of time in which hardware threads occupied EUs.",
        "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "8 rd40@0x34:0xa9 FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "8 qw@0x58 FMUL $EuThreadsCount FDIV" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "EuAggrDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$DualSubsliceMask 1 AND";
    metric = metricSet->AddMetric( "NonPSThread00ReadyForDispatch", "Non-PS Thread Ready For Dispatch on Slice0 DualSubslice0 Thread Dispatcher",
        "The percentage of time in which non-PS thread is ready for dispatch on slice0 dualsubslice0 thread dispatcher",
        "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 13 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xc4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x138" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$DualSubsliceMask 2 AND";
    metric = metricSet->AddMetric( "NonPSThread01ReadyForDispatch", "Non-PS Thread Ready For Dispatch on Slice0 DualSubslice1 Thread Dispatcher",
        "The percentage of time in which non-PS thread is ready for dispatch on slice0 dualsubslice1 thread dispatcher",
        "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 14 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xc0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x130" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$DualSubsliceMask 1 AND";
    metric = metricSet->AddMetric( "ThreadHeader00ReadyPort0", "Thread Header Ready on Slice0 DualSubslice0 Thread Dispatcher Port 0",
        "The percentage of time in which thread header is ready on slice0 dualsubslice0 thread dispatcher port 0",
        "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 15 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xfc" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x1a8" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$DualSubsliceMask 1 AND";
    metric = metricSet->AddMetric( "ThreadHeader00ReadyPort1", "Thread Header Ready on Slice0 DualSubslice0 Thread Dispatcher Port 1",
        "The percentage of time in which thread header is ready on slice0 dualsubslice0 thread dispatcher port 1",
        "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 16 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xf8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x1a0" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$DualSubsliceMask 1 AND";
    metric = metricSet->AddMetric( "ThreadHeader00ReadyPort2", "Thread Header Ready on Slice0 DualSubslice0 Thread Dispatcher Port 2",
        "The percentage of time in which thread header is ready on slice0 dualsubslice0 thread dispatcher port 2",
        "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 17 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xf4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x198" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$DualSubsliceMask 1 AND";
    metric = metricSet->AddMetric( "ThreadHeader00ReadyPort3", "Thread Header Ready on Slice0 DualSubslice0 Thread Dispatcher Port 3",
        "The percentage of time in which thread header is ready on slice0 dualsubslice0 thread dispatcher port 3",
        "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 18 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xf0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x190" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$DualSubsliceMask 2 AND";
    metric = metricSet->AddMetric( "ThreadHeader01ReadyPort0", "Thread Header Ready on Slice0 DualSubslice1 Thread Dispatcher Port 0",
        "The percentage of time in which thread header is ready on slice0 dualsubslice1 thread dispatcher port 0",
        "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 19 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xec" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x188" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$DualSubsliceMask 2 AND";
    metric = metricSet->AddMetric( "ThreadHeader01ReadyPort1", "Thread Header Ready on Slice0 DualSubslice1 Thread Dispatcher Port 1",
        "The percentage of time in which thread header is ready on slice0 dualsubslice1 thread dispatcher port 1",
        "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 20 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xe8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x180" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$DualSubsliceMask 2 AND";
    metric = metricSet->AddMetric( "ThreadHeader01ReadyPort2", "Thread Header Ready on Slice0 DualSubslice1 Thread Dispatcher Port 2",
        "The percentage of time in which thread header is ready on slice0 dualsubslice1 thread dispatcher port 2",
        "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 21 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xe4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x178" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$DualSubsliceMask 2 AND";
    metric = metricSet->AddMetric( "ThreadHeader01ReadyPort3", "Thread Header Ready on Slice0 DualSubslice1 Thread Dispatcher Port 3",
        "The percentage of time in which thread header is ready on slice0 dualsubslice1 thread dispatcher port 3",
        "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 22 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xe0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x170" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$DualSubsliceMask 1 AND";
    metric = metricSet->AddMetric( "ThreadHeader00Ready", "Thread Header Ready on Slice0 DualSubslice0 Thread Dispatcher",
        "The percentage of time in which thread header is ready on slice0 dualsubslice0 thread dispatcher",
        "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 23 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xc8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x140" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$DualSubsliceMask 2 AND";
    metric = metricSet->AddMetric( "ThreadHeader01Ready", "Thread Header Ready on Slice0 DualSubslice1 Thread Dispatcher",
        "The percentage of time in which thread header is ready on slice0 dualsubslice1 thread dispatcher",
        "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 24 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xcc" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x148" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$DualSubsliceMask 1 AND";
    metric = metricSet->AddMetric( "PSThread00ReadyForDispatch", "PS Thread Ready For Dispatch on Slice0 Dualsubslice0 Thread Dispatcher",
        "The percentage of time in which PS thread is ready for dispatch on slice0 dualsubslice0 thread dispatcher",
        "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 25 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xd0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x150" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

    availabilityEquation = "$DualSubsliceMask 2 AND";
    metric = metricSet->AddMetric( "PSThread01ReadyForDispatch", "PS Thread Ready For Dispatch on Slice0 Dualsubslice1 Thread Dispatcher",
        "The percentage of time in which PS thread is ready for dispatch on slice0 dualsubslice1 thread dispatcher",
        "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 26 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xd4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x158" ));
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "GpuDuration" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        MD_CHECK_CC_RET( metric->SetMaxValueEquation( "100" ));
    }

        MD_CHECK_CC_RET( metricSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x24110340, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x2611001c, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x24310340, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x2631001c, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0e110103, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x101100f3, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x121100f2, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x06110107, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x08110106, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a110105, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0c110104, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x02110000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x04110000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0e128000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x10128000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x12128000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x06128000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x08128000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a128000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0c128000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1c130f00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x16138000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x18138000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1a138000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x00310103, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x143100f3, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x163100f2, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1c310107, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1e310106, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x02310105, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x04310104, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x10310000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a310000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0e310000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x00328000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x14328000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x16328000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1c328000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1e328000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x02328000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x04328000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x10338000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1c333000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1e330003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x12338000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x14338000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x000b4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x140b4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x160b4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1c0b4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1e0b4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x020b4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x040b4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x040dc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0e0dc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x120dc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x060d4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x000e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x140e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x160e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1c0e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1e0e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x020e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x040e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x000f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x140f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x160f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1c0f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1e0f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x020f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x040f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x00004000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0e00c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1000c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1200c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x34004140, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x36000001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x02004000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x04004000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0600c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0800c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a00c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0c00c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0001c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a01c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x18018000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1a012000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x02014000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1c05c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x22050030, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x16058000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x18058000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1a058000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0a0ac000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x0c0ac000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x060a8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x080ac000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x41104000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5b105555, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5d101415, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x11148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1b14fc00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1d140033, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x13148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x15148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x17148000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4b114000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5f11aaaa, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x6111282a, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x47100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4d100606, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4f100606, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x51100006, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x53100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x55100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x57100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x49100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x4b100606, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd904, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd914, 0x30800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc40, 0x003f0000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd940, 0x00000002, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd944, 0x0000fffe, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc00, 0x00000002, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc04, 0x0000fffe, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd948, 0x00000002, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd94c, 0x0000fffd, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc08, 0x00000002, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc0c, 0x0000fffd, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd950, 0x00078000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd954, 0x00000fff, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc10, 0x00078000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc14, 0x00000fff, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd958, 0x00007800, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd95c, 0x0000f0ff, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc18, 0x00007800, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc1c, 0x0000f0ff, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd960, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd964, 0x0000fff3, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc20, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc24, 0x0000fff3, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd968, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd96c, 0x0000ffcf, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc28, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc2c, 0x0000ffcf, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe558, 0x00000008, REGISTER_TYPE_FLEX ));
  
    MD_CHECK_CC_RET( metricSet->RefreshConfigRegisters() );

    return CC_OK;
}

static TCompletionCode CreateMetricSet_ADLS_TestOa( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup, uint32_t platformMask )
{
    CMetricSet*   metricSet            = nullptr;
    CMetric*      metric               = nullptr;
    CInformation* information          = nullptr;
    const char*   availabilityEquation = nullptr;

    metricSet = concurrentGroup->AddMetricSet( "TestOa", "Metric set TestOa", API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, nullptr );
    MD_CHECK_PTR_RET( metricSet, CC_ERROR_GENERAL );

    MD_CHECK_CC_RET( metricSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
        "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuTime", "GPU Time Elapsed",
        "Time elapsed on the GPU during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x00" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
        "The total number of GPU core clocks elapsed during the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0x0c" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x08" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
        "Average GPU Core Frequency in the measurement.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
    if( metric )
    {
        
        MD_CHECK_CC_RET( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "Counter0", "TestCounter0",
        "HW test counter 0. Factor: 0.0",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 3 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xc0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x130" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "Counter1", "TestCounter1",
        "HW test counter 1. Factor: 1.0",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 4 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xc4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x138" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "Counter2", "TestCounter2",
        "HW test counter 2. Factor: 1.0",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 5 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xc8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x140" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "Counter3", "TestCounter3",
        "HW test counter 3. Factor: 0.5",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 6 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xcc" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x148" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "Counter4", "TestCounter4",
        "HW test counter 4. Factor: 0.3333",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 7 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xd0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x150" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "Counter5", "TestCounter5",
        "HW test counter 5. Factor: 0.3333",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 8 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xd4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x158" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "Counter6", "TestCounter6",
        "HW test counter 6. Factor: 0.16666",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 9 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xd8" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x160" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "Counter7", "TestCounter7",
        "HW test counter 7. Factor: 0.6666",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xdc" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x168" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "Counter8", "TestCounter8",
        "HW test counter 8. Should be equal to 1 in IOStream or in OAG query mode",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xe0" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x170" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

    availabilityEquation = nullptr;
    metric = metricSet->AddMetric( "Counter9", "TestCounter9 - OAR enable",
        "HW test counter 9. Should be equal to 1 in query.",
        "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
        METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
    if( metric )
    {
        MD_CHECK_CC_RET( metric->SetSnapshotReportReadEquation( "dw@0xe4" ));
        MD_CHECK_CC_RET( metric->SetDeltaReportReadEquation( "qw@0x178" ));
        MD_CHECK_CC_RET( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
    }

        uint32_t informationCount = concurrentGroup->GetInformationCount();

        information = metricSet->AddInformation( "StreamMarker", "Stream marker",
            "Stream marker value.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, nullptr, nullptr, informationCount++ );
        if( information )
        {
            MD_CHECK_CC_RET( information->SetSnapshotReportReadEquation( "dw@0x5c dw@0x0 19 >> 0x4 AND 0x4 == UMUL" ));
        }

        MD_CHECK_CC_RET( metricSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x040f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1e0f0017, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x200f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x36000001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1a012000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x49110000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x5d101400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1d140020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x1d1103a3, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x01110000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x61112000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x55100a00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x57100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd904, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd914, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc40, 0x00ff0000, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd940, 0x00000004, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd944, 0x0000ffff, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc00, 0x00000004, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc04, 0x0000ffff, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd948, 0x00000003, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd94c, 0x0000ffff, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc08, 0x00000003, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc0c, 0x0000ffff, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd950, 0x00000007, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd954, 0x0000ffff, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc10, 0x00000007, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc14, 0x0000ffff, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd958, 0x00100002, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd95c, 0x0000fff7, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc18, 0x00100002, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc1c, 0x0000fff7, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd960, 0x00100002, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd964, 0x0000ffcf, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc20, 0x00100002, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc24, 0x0000ffcf, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd968, 0x00100082, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd96c, 0x0000ffef, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc28, 0x00100082, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc2c, 0x0000ffef, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd970, 0x001000c2, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd974, 0x0000ffe7, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc30, 0x001000c2, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc34, 0x0000ffe7, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd978, 0x00100001, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xd97c, 0x0000ffe7, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc38, 0x00100001, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xdc3c, 0x0000ffe7, REGISTER_TYPE_OA ));
        MD_CHECK_CC_RET( metricSet->AddStartConfigRegister( 0xe65c, 0xffffffff, REGISTER_TYPE_FLEX ));
  
    MD_CHECK_CC_RET( metricSet->RefreshConfigRegisters() );

    return CC_OK;
}

TCompletionCode CreateMetricTreeADLS_OA( CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup )
{
    MD_LOG_ENTER();
    MD_CHECK_PTR_RET( metricsDevice, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( concurrentGroup, CC_ERROR_INVALID_PARAMETER );

    CMetricSet*   metricSet            = nullptr;
    CMetric*      metric               = nullptr;
    CInformation* information          = nullptr;
    const char*   availabilityEquation = nullptr;
    uint32_t      platformMask         = 0;

    platformMask = PLATFORM_ADLS;
    if( metricsDevice->IsPlatformTypeOf( platformMask ) )
    {

    uint32_t informationCount = 0;

        information = concurrentGroup->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", nullptr, informationCount++ );
        if( information )
        {
            MD_CHECK_CC_RET( information->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC_RET( information->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC_RET( information->SetOverflowFunction( "NS_TIME" ));
        }

        information = concurrentGroup->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", nullptr, informationCount++ );
        if( information )
        {
            MD_CHECK_CC_RET( information->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC_RET( information->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        information = concurrentGroup->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", nullptr, informationCount++ );
        if( information )
        {
            MD_CHECK_CC_RET( information->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        information = concurrentGroup->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, nullptr, nullptr, informationCount++ );
        if( information )
        {
            MD_CHECK_CC_RET( information->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        information = concurrentGroup->AddInformation( "ContextIdValid", "Context ID Valid",
            "When set indicates render context is valid",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_FLAG, nullptr, nullptr, informationCount++ );
        if( information )
        {
            MD_CHECK_CC_RET( information->SetSnapshotReportReadEquation( "dw@0x0 16 >> 0x1 AND" ));
        }

        information = concurrentGroup->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, nullptr, nullptr, informationCount++ );
        if( information )
        {
            MD_CHECK_CC_RET( information->SetSnapshotReportReadEquation( "dw@0x08 0xffbfffff AND dw@0x0 16 >> 0x1 AND UMUL" ));
        }

        information = concurrentGroup->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, nullptr, nullptr, informationCount++ );
        if( information )
        {
            MD_CHECK_CC_RET( information->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        information = concurrentGroup->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, nullptr, nullptr, informationCount++ );
        if( information )
        {
            MD_CHECK_CC_RET( information->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        information = concurrentGroup->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, nullptr, nullptr, informationCount++ );
        if( information )
        {
            MD_CHECK_CC_RET( information->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        information = concurrentGroup->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, nullptr, nullptr, informationCount++ );
        if( information )
        {
            MD_CHECK_CC_RET( information->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        information = concurrentGroup->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, nullptr, nullptr, informationCount++ );
        if( information )
        {
            MD_CHECK_CC_RET( information->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        information = concurrentGroup->AddInformation( "ReportError", "Query report error",
            "An error in the query execution, the received report should be ignored.",
            "Report Meta Data", API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, nullptr, nullptr, informationCount++ );
        if( information )
        {
            MD_CHECK_CC_RET( information->SetDeltaReportReadEquation( "dw@0x29c 0x13 AND" ));
        }

        information = concurrentGroup->AddInformation( "ReportLost", "Query report lost",
            "Begin or end query report has not been triggered due to hw limitations.",
            "Report Meta Data", API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, nullptr, nullptr, informationCount++ );
        if( information )
        {
            MD_CHECK_CC_RET( information->SetDeltaReportReadEquation( "dw@0x29c 0x01 AND" ));
        }

        information = concurrentGroup->AddInformation( "ReportInconsistent", "Query report inconsistent",
            "The contextId inconsistency in the Oa buffer within the query window.",
            "Report Meta Data", API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, nullptr, nullptr, informationCount++ );
        if( information )
        {
            MD_CHECK_CC_RET( information->SetDeltaReportReadEquation( "dw@0x29c 0x02 AND" ));
        }

        information = concurrentGroup->AddInformation( "ReportCtxSwitchLost", "Query report context switch lost",
            "Oa buffer has not been browsed to find context switch reports to filter out unfamiliar contexts from the query report.",
            "Report Meta Data", API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, nullptr, nullptr, informationCount++ );
        if( information )
        {
            MD_CHECK_CC_RET( information->SetDeltaReportReadEquation( "dw@0x29c 0x08 AND" ));
        }

        information = concurrentGroup->AddInformation( "ReportWithoutWorkload", "Query report missing workload",
            "Missing workload between query begin and query end.",
            "Report Meta Data", API_TYPE_VULKAN|API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, nullptr, nullptr, informationCount++ );
        if( information )
        {
            MD_CHECK_CC_RET( information->SetDeltaReportReadEquation( "dw@0x29c 0x10 AND" ));
        }

        MD_CHECK_CC( CreateMetricSet_ADLS_RenderBasic( metricsDevice, concurrentGroup, platformMask ) );

        MD_CHECK_CC( CreateMetricSet_ADLS_ComputeBasic( metricsDevice, concurrentGroup, platformMask ) );

        MD_CHECK_CC( CreateMetricSet_ADLS_AsyncCompute( metricsDevice, concurrentGroup, platformMask ) );

        MD_CHECK_CC( CreateMetricSet_ADLS_XveActivity1( metricsDevice, concurrentGroup, platformMask ) );

        MD_CHECK_CC( CreateMetricSet_ADLS_GpuBusyness( metricsDevice, concurrentGroup, platformMask ) );

        MD_CHECK_CC( CreateMetricSet_ADLS_HDCAndSF( metricsDevice, concurrentGroup, platformMask ) );

        MD_CHECK_CC( CreateMetricSet_ADLS_L3_1( metricsDevice, concurrentGroup, platformMask ) );

        MD_CHECK_CC( CreateMetricSet_ADLS_L3_2( metricsDevice, concurrentGroup, platformMask ) );

        MD_CHECK_CC( CreateMetricSet_ADLS_L3_3( metricsDevice, concurrentGroup, platformMask ) );

        MD_CHECK_CC( CreateMetricSet_ADLS_L3_4( metricsDevice, concurrentGroup, platformMask ) );

        MD_CHECK_CC( CreateMetricSet_ADLS_L3_5( metricsDevice, concurrentGroup, platformMask ) );

        MD_CHECK_CC( CreateMetricSet_ADLS_L3_6( metricsDevice, concurrentGroup, platformMask ) );

        MD_CHECK_CC( CreateMetricSet_ADLS_RasterizerAndPixelBackend( metricsDevice, concurrentGroup, platformMask ) );

        MD_CHECK_CC( CreateMetricSet_ADLS_RenderPipeProfile( metricsDevice, concurrentGroup, platformMask ) );

        MD_CHECK_CC( CreateMetricSet_ADLS_Sampler( metricsDevice, concurrentGroup, platformMask ) );

        MD_CHECK_CC( CreateMetricSet_ADLS_TDL( metricsDevice, concurrentGroup, platformMask ) );

        MD_CHECK_CC( CreateMetricSet_ADLS_TestOa( metricsDevice, concurrentGroup, platformMask ) );

    MD_LOG_EXIT();
    }
    return CC_OK;

  exception:
    MD_LOG_EXIT();
    return CC_ERROR_NO_MEMORY;
}
#endif
