/*****************************************************************************\

    Copyright © 2019, Intel Corporation

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.

    File Name:  md_metrics.cpp

    Abstract:   C++ automated generated file to stack metrics meta data

\*****************************************************************************/
#include "md_metrics.h"
#include "metrics_discovery_api.h"
#include "md_internal.h"
#include "md_per_platform_preamble.h"


#if (!defined(MD_INCLUDE_HSW_METRICS) && MD_INCLUDE_ALL_METRICS) || MD_INCLUDE_HSW_METRICS
#define MD_CALL_HSW_METRICS 1
    TCompletionCode CreateMetricTreeHSW_OA(CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup);
#endif

#if (!defined(MD_INCLUDE_BDW_METRICS) && MD_INCLUDE_ALL_METRICS) || MD_INCLUDE_BDW_METRICS
#define MD_CALL_BDW_METRICS 1
    TCompletionCode CreateMetricTreeBDW_OA(CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup);
#endif

#if (!defined(MD_INCLUDE_SKL_GT2_METRICS) && MD_INCLUDE_ALL_METRICS) || MD_INCLUDE_SKL_GT2_METRICS
#define MD_CALL_SKL_GT2_METRICS 1
    TCompletionCode CreateMetricTreeSKL_GT2_OA(CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup);
#endif

#if (!defined(MD_INCLUDE_SKL_GT3_METRICS) && MD_INCLUDE_ALL_METRICS) || MD_INCLUDE_SKL_GT3_METRICS
#define MD_CALL_SKL_GT3_METRICS 1
    TCompletionCode CreateMetricTreeSKL_GT3_OA(CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup);
#endif

#if (!defined(MD_INCLUDE_SKL_GT4_METRICS) && MD_INCLUDE_ALL_METRICS) || MD_INCLUDE_SKL_GT4_METRICS
#define MD_CALL_SKL_GT4_METRICS 1
    TCompletionCode CreateMetricTreeSKL_GT4_OA(CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup);
#endif

#if (!defined(MD_INCLUDE_BXT_METRICS) && MD_INCLUDE_ALL_METRICS) || MD_INCLUDE_BXT_METRICS
#define MD_CALL_BXT_METRICS 1
    TCompletionCode CreateMetricTreeBXT_OA(CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup);
#endif

#if (!defined(MD_INCLUDE_KBL_GT2_METRICS) && MD_INCLUDE_ALL_METRICS) || MD_INCLUDE_KBL_GT2_METRICS
#define MD_CALL_KBL_GT2_METRICS 1
    TCompletionCode CreateMetricTreeKBL_GT2_OA(CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup);
#endif

#if (!defined(MD_INCLUDE_KBL_GT3_METRICS) && MD_INCLUDE_ALL_METRICS) || MD_INCLUDE_KBL_GT3_METRICS
#define MD_CALL_KBL_GT3_METRICS 1
    TCompletionCode CreateMetricTreeKBL_GT3_OA(CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup);
#endif

#if (!defined(MD_INCLUDE_CFL_GT2_METRICS) && MD_INCLUDE_ALL_METRICS) || MD_INCLUDE_CFL_GT2_METRICS
#define MD_CALL_CFL_GT2_METRICS 1
    TCompletionCode CreateMetricTreeCFL_GT2_OA(CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup);
#endif

#if (!defined(MD_INCLUDE_CFL_GT3_METRICS) && MD_INCLUDE_ALL_METRICS) || MD_INCLUDE_CFL_GT3_METRICS
#define MD_CALL_CFL_GT3_METRICS 1
    TCompletionCode CreateMetricTreeCFL_GT3_OA(CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup);
#endif

#if (!defined(MD_INCLUDE_GLK_METRICS) && MD_INCLUDE_ALL_METRICS) || MD_INCLUDE_GLK_METRICS
#define MD_CALL_GLK_METRICS 1
    TCompletionCode CreateMetricTreeGLK_OA(CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup);
#endif

#if (!defined(MD_INCLUDE_ICL_METRICS) && MD_INCLUDE_ALL_METRICS) || MD_INCLUDE_ICL_METRICS
#define MD_CALL_ICL_METRICS 1
    TCompletionCode CreateMetricTreeICL_OA(CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup);
#endif

#if (!defined(MD_INCLUDE_EHL_METRICS) && MD_INCLUDE_ALL_METRICS) || MD_INCLUDE_EHL_METRICS
#define MD_CALL_EHL_METRICS 1
    TCompletionCode CreateMetricTreeEHL_OA(CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup);
#endif

#if (!defined(MD_INCLUDE_TGL_METRICS) && MD_INCLUDE_ALL_METRICS) || MD_INCLUDE_TGL_METRICS
#define MD_CALL_TGL_METRICS 1
    TCompletionCode CreateMetricTreeTGL_OA(CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup);
#endif

#if (!defined(MD_INCLUDE_DG1_METRICS) && MD_INCLUDE_ALL_METRICS) || MD_INCLUDE_DG1_METRICS
#define MD_CALL_DG1_METRICS 1
    TCompletionCode CreateMetricTreeDG1_OA(CMetricsDevice* metricsDevice, CConcurrentGroup* concurrentGroup);
#endif


TCompletionCode AddGlobalSymbols( CSymbolSet* globalSymbolSet )
{
    MD_CHECK_PTR_RET( globalSymbolSet, CC_ERROR_INVALID_PARAMETER );
    
    globalSymbolSet->AddSymbolUINT32( "EuCoresTotalCount", 60, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolUINT32( "EuCoresPerSubsliceCount", 10, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolUINT32( "EuSubslicesTotalCount", 6, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolUINT32( "EuSubslicesPerSliceCount", 3, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolUINT32( "EuDualSubslicesTotalCount", 0, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolUINT32( "EuSlicesTotalCount", 2, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolUINT32( "EuThreadsCount", 8, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolUINT64( "SubsliceMask", 0x1FF, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolUINT64( "DualSubsliceMask", 0x0, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolUINT32( "SliceMask", 0x7, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolUINT32( "SamplersTotalCount", 6, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolUINT32( "MemoryPeakThroghputMB", 25600, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolUINT32( "MemoryFrequencyMHz", 1600, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolUINT32( "GpuMinFrequencyMHz", 650, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolUINT32( "GpuMaxFrequencyMHz", 1250, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolUINT32( "GpuCurrentFrequencyMHz", 1250, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolUINT32( "PciDeviceId", 0, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolUINT32( "SkuRevisionId", 0, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolUINT32( "PlatformIndex", 0, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolUINT32( "ApertureSize", 0, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolUINT32( "Capabilities", 0, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolBOOL( "PavpDisabled", false, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolUINT32( "NumberOfRenderOutputUnits", 0, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolUINT32( "NumberOfShadingUnits", 0, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolUINT32( "OABufferMinSize", 16384, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolUINT32( "OABufferMaxSize", 131072, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolUINT32( "GpuTimestampFrequency", 12500000, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolUINT32( "EdramSize", 0, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolUINT32( "LLCSize", 0, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolUINT32( "L3Size", 0, SYMBOL_TYPE_DETECT );

    globalSymbolSet->AddSymbolUINT64( "MaxTimestamp", 0, SYMBOL_TYPE_DETECT );

    return CC_OK;
}

TCompletionCode CreateMetricTree( CMetricsDevice* metricsDevice )
{
    MD_LOG_ENTER();
    MD_CHECK_PTR_RET( metricsDevice, CC_ERROR_INVALID_PARAMETER );

    CConcurrentGroup* concurrentGroup      = NULL;
    CMetricSet*       metricSet            = NULL;
    CMetric*          metric               = NULL;
    CInformation*     information          = NULL;
    const char*       availabilityEquation = NULL;
    uint32_t          platformMask         = 0;

    information = NULL; // To omit warning C4189 - local variable is initialized but not referenced

    CSymbolSet* symbolSet = metricsDevice->GetSymbolSet();
    MD_CHECK_PTR( symbolSet );
    AddGlobalSymbols( symbolSet );
    metricsDevice->GetParams()->GlobalSymbolsCount = symbolSet->GetSymbolCount();
  
    concurrentGroup = metricsDevice->AddConcurrentGroup( "OcclusionQueryStats", "Occlusion Query Statistics", MEASUREMENT_TYPE_DELTA_QUERY );
    MD_CHECK_PTR( concurrentGroup );
    
    platformMask = PLATFORM_HSW|PLATFORM_BDW|PLATFORM_SKL|PLATFORM_BXT|PLATFORM_GLK|PLATFORM_KBL|PLATFORM_CFL|PLATFORM_ICL|PLATFORM_EHL|PLATFORM_TGL|PLATFORM_DG1;
    if( MD_IS_INTERNAL_BUILD || metricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        metricSet = concurrentGroup->AddMetricSet( "RenderedPixelsStats", "Rendered Pixels Statistics", API_TYPE_OGL4_X,
           GPU_RENDER, 0, 8, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( metricSet );
        
        MD_CHECK_CC( metricSet->SetApiSpecificId(NULL, 9, 0, 0, 0, 0,
            "", 1, "", 0) );
  
        availabilityEquation = NULL;
        metric = metricSet->AddMetric( "PixelsRendered", "Depth passed pixels",
            "The total number of pixels that passed depth test. Note: not all rendered pixels are necessarily written to render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( metric )
        {
            
            MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x00" ));
        }

        MD_CHECK_CC( metricSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_HSW|PLATFORM_BDW|PLATFORM_SKL|PLATFORM_BXT|PLATFORM_GLK|PLATFORM_KBL|PLATFORM_CFL|PLATFORM_ICL|PLATFORM_EHL|PLATFORM_TGL|PLATFORM_DG1;
    if( MD_IS_INTERNAL_BUILD || metricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        metricSet = concurrentGroup->AddMetricSet( "RenderedFragmentsStats", "Rendered Fragments Statistics", API_TYPE_OGL|API_TYPE_OGL4_X,
           GPU_RENDER, 0, 8, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( metricSet );
        
        MD_CHECK_CC( metricSet->SetApiSpecificId(NULL, 0, 0, 0, 0, 0,
            "", 0, "", 0x8C2F) );
  
        availabilityEquation = NULL;
        metric = metricSet->AddMetric( "PixelsRendered", "Depth passed fragments",
            "The total number of fragments that passed depth test. Note: not all rendered fragments are necessarily written to render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "fragments", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( metric )
        {
            
            MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x00" ));
        }

        MD_CHECK_CC( metricSet->RefreshConfigRegisters() );
    }
     
    concurrentGroup = metricsDevice->AddConcurrentGroup( "TimestampQuery", "Timestamp Query", MEASUREMENT_TYPE_SNAPSHOT_QUERY );
    MD_CHECK_PTR( concurrentGroup );
    
    platformMask = PLATFORM_HSW|PLATFORM_BDW|PLATFORM_SKL|PLATFORM_BXT|PLATFORM_GLK|PLATFORM_KBL|PLATFORM_CFL|PLATFORM_ICL|PLATFORM_EHL|PLATFORM_TGL|PLATFORM_DG1;
    if( MD_IS_INTERNAL_BUILD || metricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        metricSet = concurrentGroup->AddMetricSet( "GPUTimestamp", "GPU Timestamp", API_TYPE_OGL4_X,
           GPU_GENERIC, 8, 0, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( metricSet );
        
        MD_CHECK_CC( metricSet->SetApiSpecificId(NULL, 10, 0, 0, 0, 0,
            "", 2, "", 0x88BF) );
  
        availabilityEquation = NULL;
        metric = metricSet->AddMetric( "GpuDuration", "GPU Duration",
            "Total GPU duration for selected work items.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( metric )
        {
            MD_CHECK_CC( metric->SetSnapshotReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( metric->SetNormalizationEquation( "$Self 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( metric->SetSnapshotReportDeltaFunction( "DELTA 64" ));
        }

        MD_CHECK_CC( metricSet->RefreshConfigRegisters() );
    }
     
    concurrentGroup = metricsDevice->AddConcurrentGroup( "PipelineStatistics", "Pipeline Statistics", MEASUREMENT_TYPE_DELTA_QUERY );
    MD_CHECK_PTR( concurrentGroup );
    
    platformMask = PLATFORM_HSW|PLATFORM_BDW|PLATFORM_SKL|PLATFORM_BXT|PLATFORM_GLK|PLATFORM_KBL|PLATFORM_CFL;
    if( MD_IS_INTERNAL_BUILD || metricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        metricSet = concurrentGroup->AddMetricSet( "PipelineStats", "Pipeline Statistics for OGL4", API_TYPE_OGL|API_TYPE_OGL4_X,
           GPU_RENDER|GPU_COMPUTE, 0, 88, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( metricSet );
        
        MD_CHECK_CC( metricSet->SetApiSpecificId(NULL, 0, 0, 0x80000206, 0, 0,
            "", 0, "Intel_Raw_Pipeline_Statistics_Query", 0) );
  
        availabilityEquation = NULL;
        metric = metricSet->AddMetric( "IAVertices", "Input vertices",
            "The total number of vertices that entered the 3D Pipeline.",
            "3D Pipe/Input Assembler", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_IA * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "vertices", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( metric )
        {
            
            MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x00" ));
        }

        availabilityEquation = NULL;
        metric = metricSet->AddMetric( "IAPrimitives", "Input primitives",
            "The total number of rendering primitives assembled and put into the input assembly stage of the 3D Pipeline.",
            "3D Pipe/Input Assembler", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_IA * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "triangles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( metric )
        {
            
            MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x08" ));
        }

        availabilityEquation = NULL;
        metric = metricSet->AddMetric( "VsInvocations", "VS per vertex invocations",
            "The total number of times a vertex shader was invoked. 3D rendering invokes the vertex shader once per vertex.",
            "3D Pipe/Vertex Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( metric )
        {
            
            MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x10" ));
        }

        availabilityEquation = NULL;
        metric = metricSet->AddMetric( "HsInvocations", "HS invocations",
            "The total number of times a hull shader was invoked.",
            "3D Pipe/Hull Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", NULL );
        if( metric )
        {
            
            MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x40" ));
        }

        availabilityEquation = NULL;
        metric = metricSet->AddMetric( "DsInvocations", "DS invocations",
            "The total number of times a domain shader was invoked.",
            "3D Pipe/Domain Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", NULL );
        if( metric )
        {
            
            MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x48" ));
        }

        availabilityEquation = NULL;
        metric = metricSet->AddMetric( "GsInvocations", "GS per triangle invocations",
            "The total number of times a geometry shader was invoked per triangle.",
            "3D Pipe/Geometry Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( metric )
        {
            
            MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x18" ));
        }

        availabilityEquation = NULL;
        metric = metricSet->AddMetric( "GsPrimitives", "Post-GS primitives",
            "The total number of primitives that flowed through from GS to the clipper if GS was enabled.",
            "3D Pipe/Geometry Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "triangles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( metric )
        {
            
            MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x20" ));
        }

        availabilityEquation = NULL;
        metric = metricSet->AddMetric( "ClipperInvocations", "Clipper invocations",
            "The total number of primitives sent to the Clipper.",
            "3D Pipe/Clipper", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_CL * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "triangles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( metric )
        {
            
            MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x28" ));
        }

        availabilityEquation = NULL;
        metric = metricSet->AddMetric( "ClipperPrimitives", "Clipper primitives",
            "The total number of primitives that flowed out of the Clipper.",
            "3D Pipe/Clipper", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_CL * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "triangles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( metric )
        {
            
            MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x30" ));
        }

        availabilityEquation = NULL;
        metric = metricSet->AddMetric( "PsInvocations", "PS invocations",
            "The total number of times a pixel shader was invoked. 3D rendering invokes a pixel shader once per pixel or subsample.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( metric )
        {
            
            MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x38" ));
        }

        availabilityEquation = NULL;
        metric = metricSet->AddMetric( "CsInvocations", "CS invocations",
            "The total number of times a compute shader was invoked.",
            "3D Pipe/Compute Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( metric )
        {
            
            MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x50" ));
        }

        MD_CHECK_CC( metricSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_ICL|PLATFORM_EHL|PLATFORM_TGL|PLATFORM_DG1;
    if( MD_IS_INTERNAL_BUILD || metricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        metricSet = concurrentGroup->AddMetricSet( "PipelineStats", "Pipeline Statistics for OGL4", API_TYPE_OGL|API_TYPE_OGL4_X,
           GPU_RENDER|GPU_COMPUTE, 0, 96, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( metricSet );
        
        MD_CHECK_CC( metricSet->SetApiSpecificId(NULL, 0, 0, 0x80000206, 0, 0,
            "", 0, "Intel_Raw_Pipeline_Statistics_Query", 0) );
  
        availabilityEquation = NULL;
        metric = metricSet->AddMetric( "IAVertices", "Input vertices",
            "The total number of vertices that entered the 3D Pipeline.",
            "3D Pipe/Input Assembler", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_IA * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "vertices", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( metric )
        {
            
            MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x00" ));
        }

        availabilityEquation = NULL;
        metric = metricSet->AddMetric( "IAPrimitives", "Input primitives",
            "The total number of rendering primitives assembled and put into the input assembly stage of the 3D Pipeline.",
            "3D Pipe/Input Assembler", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_IA * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "triangles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( metric )
        {
            
            MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x08" ));
        }

        availabilityEquation = NULL;
        metric = metricSet->AddMetric( "VsInvocations", "VS per vertex invocations",
            "The total number of times a vertex shader was invoked. 3D rendering invokes the vertex shader once per vertex.",
            "3D Pipe/Vertex Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( metric )
        {
            
            MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x10" ));
        }

        availabilityEquation = NULL;
        metric = metricSet->AddMetric( "HsInvocations", "HS invocations",
            "The total number of times a hull shader was invoked.",
            "3D Pipe/Hull Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", NULL );
        if( metric )
        {
            
            MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x40" ));
        }

        availabilityEquation = NULL;
        metric = metricSet->AddMetric( "DsInvocations", "DS invocations",
            "The total number of times a domain shader was invoked.",
            "3D Pipe/Domain Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", NULL );
        if( metric )
        {
            
            MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x48" ));
        }

        availabilityEquation = NULL;
        metric = metricSet->AddMetric( "GsInvocations", "GS per triangle invocations",
            "The total number of times a geometry shader was invoked per triangle.",
            "3D Pipe/Geometry Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( metric )
        {
            
            MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x18" ));
        }

        availabilityEquation = NULL;
        metric = metricSet->AddMetric( "GsPrimitives", "Post-GS primitives",
            "The total number of primitives that flowed through from GS to the clipper if GS was enabled.",
            "3D Pipe/Geometry Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "triangles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( metric )
        {
            
            MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x20" ));
        }

        availabilityEquation = NULL;
        metric = metricSet->AddMetric( "ClipperInvocations", "Clipper invocations",
            "The total number of primitives sent to the Clipper.",
            "3D Pipe/Clipper", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_CL * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "triangles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( metric )
        {
            
            MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x28" ));
        }

        availabilityEquation = NULL;
        metric = metricSet->AddMetric( "ClipperPrimitives", "Clipper primitives",
            "The total number of primitives that flowed out of the Clipper.",
            "3D Pipe/Clipper", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_CL * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "triangles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( metric )
        {
            
            MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x30" ));
        }

        availabilityEquation = NULL;
        metric = metricSet->AddMetric( "PsInvocations", "PS invocations",
            "The total number of times a pixel shader was invoked. 3D rendering invokes a pixel shader once per pixel or subsample.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( metric )
        {
            
            MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x38" ));
        }

        availabilityEquation = NULL;
        metric = metricSet->AddMetric( "CsInvocations", "CS invocations",
            "The total number of times a compute shader was invoked.",
            "3D Pipe/Compute Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( metric )
        {
            
            MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x50" ));
        }

        availabilityEquation = NULL;
        metric = metricSet->AddMetric( "CpsInvocations", "CPS invocations",
            "The total number of times a coarse shader was invoked.",
            "3D Pipe/Compute Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, "PS|FS", NULL );
        if( metric )
        {
            
            MD_CHECK_CC( metric->SetDeltaReportReadEquation( "qw@0x58" ));
        }

        MD_CHECK_CC( metricSet->RefreshConfigRegisters() );
    }
     
    concurrentGroup = metricsDevice->AddConcurrentGroup( "OA", "OA Unit Metrics", MEASUREMENT_TYPE_DELTA_QUERY|MEASUREMENT_TYPE_SNAPSHOT_IO );
    MD_CHECK_PTR( concurrentGroup );
    
    // Add platform specific metric sets
#if MD_CALL_HSW_METRICS
    MD_CHECK_CC( CreateMetricTreeHSW_OA(metricsDevice, concurrentGroup) );
#endif

#if MD_CALL_BDW_METRICS
    MD_CHECK_CC( CreateMetricTreeBDW_OA(metricsDevice, concurrentGroup) );
#endif

#if MD_CALL_SKL_GT2_METRICS
    MD_CHECK_CC( CreateMetricTreeSKL_GT2_OA(metricsDevice, concurrentGroup) );
#endif

#if MD_CALL_SKL_GT3_METRICS
    MD_CHECK_CC( CreateMetricTreeSKL_GT3_OA(metricsDevice, concurrentGroup) );
#endif

#if MD_CALL_SKL_GT4_METRICS
    MD_CHECK_CC( CreateMetricTreeSKL_GT4_OA(metricsDevice, concurrentGroup) );
#endif

#if MD_CALL_BXT_METRICS
    MD_CHECK_CC( CreateMetricTreeBXT_OA(metricsDevice, concurrentGroup) );
#endif

#if MD_CALL_KBL_GT2_METRICS
    MD_CHECK_CC( CreateMetricTreeKBL_GT2_OA(metricsDevice, concurrentGroup) );
#endif

#if MD_CALL_KBL_GT3_METRICS
    MD_CHECK_CC( CreateMetricTreeKBL_GT3_OA(metricsDevice, concurrentGroup) );
#endif

#if MD_CALL_CFL_GT2_METRICS
    MD_CHECK_CC( CreateMetricTreeCFL_GT2_OA(metricsDevice, concurrentGroup) );
#endif

#if MD_CALL_CFL_GT3_METRICS
    MD_CHECK_CC( CreateMetricTreeCFL_GT3_OA(metricsDevice, concurrentGroup) );
#endif

#if MD_CALL_GLK_METRICS
    MD_CHECK_CC( CreateMetricTreeGLK_OA(metricsDevice, concurrentGroup) );
#endif

#if MD_CALL_ICL_METRICS
    MD_CHECK_CC( CreateMetricTreeICL_OA(metricsDevice, concurrentGroup) );
#endif

#if MD_CALL_EHL_METRICS
    MD_CHECK_CC( CreateMetricTreeEHL_OA(metricsDevice, concurrentGroup) );
#endif

#if MD_CALL_TGL_METRICS
    MD_CHECK_CC( CreateMetricTreeTGL_OA(metricsDevice, concurrentGroup) );
#endif

#if MD_CALL_DG1_METRICS
    MD_CHECK_CC( CreateMetricTreeDG1_OA(metricsDevice, concurrentGroup) );
#endif


    MD_CHECK_CC( metricsDevice->AddOverrides() );

    MD_LOG_EXIT();
    return CC_OK;

  exception:
    MD_LOG( LOG_ERROR, "Creating metric tree failed" );
    MD_LOG_EXIT();
    return CC_ERROR_NO_MEMORY;
}

