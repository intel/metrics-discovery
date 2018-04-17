/*****************************************************************************\

    Copyright © 2018, Intel Corporation

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

    File Name:  md_main_SKL_GT2.cpp

    Abstract:   C++ automated generated file to stack metrics meta data

\*****************************************************************************/

#include "md_per_platform_preamble.h"




#if ((!defined(MD_INCLUDE_SKL_GT2_METRICS) && MD_INCLUDE_ALL_METRICS) || MD_INCLUDE_SKL_GT2_METRICS)
TCompletionCode CreateObjectTreeSKL_GT2_OA( CConcurrentGroup* aGroup )
{
    MD_LOG_ENTER();
    MD_CHECK_PTR_RET(g_MetricsDevice, CC_ERROR_GENERAL);
    MD_CHECK_PTR_RET(aGroup, CC_ERROR_INVALID_PARAMETER);

    CMetricSet*       aSet         = NULL;
    CMetric*          aMetric      = NULL;
    CInformation*     aInformation = NULL;
    const char*       availabilityEquation = NULL;
    uint32_t          platformMask = 0;
  
    platformMask = PLATFORM_SKL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask, GT_TYPE_GT2 ) )
    {
        aSet = aGroup->AddMetricSet( "RenderBasic", "Render Metrics Basic Gen9", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, GT_TYPE_GT2 );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuFpuBothActive", "EU Both FPU Pipes Active",
            "The percentage of time in which both EU FPU pipelines were actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x34:0xa9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu0Active", "VS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x38:0xaa" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x60" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu1Active", "VS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsSendActive", "VS Send Pipe Active",
            "The percentage of time in which EU send pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x40:0xac" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu0Active", "PS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x88" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x50:0xb0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsSendActive", "PS Send Pipeline Active",
            "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x54:0xb1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuBothFpuActive", "PS Both FPU Active",
            "The percentage of time in which pixel shaders were processed actively on the both FPUs.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x58:0xb2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xa0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = "$SubsliceMask 0x09 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler0Busy", "Sampler 0 Busy",
                "The percentage of time in which Sampler 0 has been processing EU requests.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x12 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler1Busy", "Sampler 1 Busy",
                "The percentage of time in which Sampler 1 has been processing EU requests.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplersBusy", "Samplers Busy",
            "The percentage of time in which samplers have been processing EU requests.",
            "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$Sampler0Busy $$Sampler1Busy FMAX" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = "$SubsliceMask 0x09 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler0Bottleneck", "Sampler 0 Bottleneck",
                "The percentage of time in which Sampler 0 has been slowing down the pipe when processing EU requests.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x12 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler1Bottleneck", "Sampler 1 Bottleneck",
                "The percentage of time in which Sampler 1 has been slowing down the pipe when processing EU requests.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xcc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
            "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerL1Misses", "Sampler Cache Misses",
            "The total number of sampler cache misses in all LODs in all sampler units.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd0 8 UMUL" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x150 8 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3Lookups", "L3 Lookup Accesses w/o IC",
            "The total number of L3 cache lookup accesses w/o IC.",
            "L3/TAG", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_L3_TAG * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$SamplerL1Misses $$ShaderMemoryAccesses UADD" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3Misses", "L3 Misses",
            "The total number of L3 misses.",
            "L3/TAG", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_L3_TAG * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3SamplerThroughput", "L3 Sampler Throughput",
            "The total number of GPU memory bytes transferred between samplers and L3 caches.",
            "L3/Sampler", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SamplerL1Misses 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
            "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten $ShaderMemoryAccesses 64 UMUL UADD UADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiVfThroughput", "GTI Fixed Pipe Throughput",
            "The total number of GPU memory bytes transferred between 3D Pipeline (Command Dispatch, Input Assembly and Stream Output) and GTI.",
            "GTI/3D Pipe", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd8 dw@0xdc UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x160 qw@0x168 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiDepthThroughput", "GTI Depth Throughput",
            "The total number of GPU memory bytes transferred between depth caches and GTI.",
            "GTI/Depth Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCZ * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe0 dw@0xe4 UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x170 qw@0x178 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiRccThroughput", "GTI RCC Throughput",
            "The total number of GPU memory bytes transferred between render color caches and GTI.",
            "GTI/Color Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCC * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe8 dw@0xec UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x180 qw@0x188 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiL3Throughput", "GTI L3 Throughput",
            "The total number of GPU memory bytes transferred between L3 caches and GTI.",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$L3Misses 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiHdcLookupsThroughput", "GTI HDC TLB Lookup Throughput",
            "The total number of GPU memory bytes transferred between GTI and HDC, when HDC is doing TLB lookups.",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiReadThroughput", "GTI Read Throughput",
            "The total number of GPU memory bytes read from GTI.",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiWriteThroughput", "GTI Write Throughput",
            "The total number of GPU memory bytes written to GTI.",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 32 UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerBottleneck", "Samplers Bottleneck",
            "The percentage of time in which samplers have been slowing down the pipe when processing EU requests.",
            "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_INDICATE|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$Sampler0Bottleneck $$Sampler1Bottleneck FMAX" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00010003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00012011, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00015014, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00051050, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00053052, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00055054, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
  
        availabilityEquation = "$SkuRevisionId 0x02 UGTE";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            MD_CHECK_CC( aSet->AddStartRegisterSet( 1, 1, availabilityEquation ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x166c01e0, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12170280, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12370280, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11930317, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x159303df, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3f900003, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a4e0080, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a6c0053, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x106c0000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c6c0000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a1b4000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c1c0001, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x002f1000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x042f1000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x004c4000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a4c8400, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x000d2000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x060d8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x080da000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a0d2000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c0f0400, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e0f6600, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x002c8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x162c2200, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x062d8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x082d8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00133000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08133000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00170020, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08170021, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10170000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0633c000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0833c000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06370800, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08370840, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10370000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0d933031, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0f933e3f, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x01933d00, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0393073c, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0593000e, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1d930000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x19930000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1b930000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1d900157, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1f900158, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x35900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x2b908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x2d908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x2f908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x31908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x15908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x17908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x19908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1b908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1190001f, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x51904400, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x41900020, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x55900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x45900c21, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x47900061, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x57904440, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x49900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x37900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x33900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4b900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x59900004, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x43900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x53904444, REGISTER_TYPE_NOA ));
  
        }
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_SKL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask, GT_TYPE_GT2 ) )
    {
        aSet = aGroup->AddMetricSet( "ComputeBasic", "Compute Metrics Basic Gen9", API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, GT_TYPE_GT2 );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuAvgIpcRate", "EU AVG IPC Rate",
            "The average rate of IPC calculated for 2 FPU pipelines.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_RATIO, RESULT_FLOAT, "number", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$EuFpuBothActive $Fpu0Active $Fpu1Active UADD $EuFpuBothActive USUB FDIV 1 FADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "2" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuFpuBothActive", "EU Both FPU Pipes Active",
            "The percentage of time in which both EU FPU pipelines were actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x34:0xa9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "Fpu0Active", "EU FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x38:0xaa" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x60" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "Fpu1Active", "EU FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuSendActive", "EU Send Pipe Active",
            "The percentage of time in which EU send pipeline was actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x40:0xac" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
            "The percentage of time in which hardware threads occupied EUs.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x44:0xad" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x78" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 8 UMUL $EuCoresTotalCount UDIV $EuThreadsCount UDIV 100 UMUL $GpuCoreClocks FDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
            "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
            "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten $ShaderMemoryAccesses 64 UMUL UADD UADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "TypedBytesRead", "Typed Bytes Read",
            "The total number of typed memory bytes read via Data Port.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0 dw@0xc4 dw@0xc8 UADD UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130 qw@0x138 qw@0x140 UADD UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $EuSlicesTotalCount 64 UMUL UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "TypedBytesWritten", "Typed Bytes Written",
            "The total number of untyped memory bytes written via Data Port.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xcc dw@0xd0 dw@0xd4 UADD UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148 qw@0x150 qw@0x158 UADD UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $EuSlicesTotalCount 64 UMUL UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "UntypedBytesRead", "Untyped Bytes Read",
            "The total number of typed memory bytes read via Data Port.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd8 dw@0xdc dw@0xe0 UADD UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x160 qw@0x168 qw@0x170 UADD UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $EuSlicesTotalCount 64 UMUL UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "UntypedBytesWritten", "Untyped Writes",
            "The total number of untyped memory bytes written via Data Port.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe4 dw@0xe8 dw@0xec UADD UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x178 qw@0x180 qw@0x188 UADD UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $EuSlicesTotalCount 64 UMUL UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiReadThroughput", "GTI Read Throughput",
            "The total number of GPU memory bytes read from GTI.",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiWriteThroughput", "GTI Write Throughput",
            "The total number of GPU memory bytes written to GTI.",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 32 UMUL" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00000003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00002001, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00778008, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00088078, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00808708, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00a08908, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
  
        availabilityEquation = "$SliceMask 0x01 AND $SkuRevisionId 0x02 ULT &&";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            MD_CHECK_CC( aSet->AddStartRegisterSet( 1, 0, availabilityEquation ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x000000A0, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x104F00E0, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x124F1C00, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x106C00E0, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x37906800, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3F901403, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x184E8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1A4E8200, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x044E8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x004F0DB2, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x064F0900, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x084F1880, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0A4F0011, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0C4F0E3C, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0E4F1D80, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x086C0002, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0A6C0100, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0E6C000C, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x026C000B, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1C6C0000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1A6C0000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x081B4000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0A1B8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0E1B4000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x021B4000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1A1C4000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1C1C0012, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x141C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x005BC000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x065B8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x085B8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0A5B4000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0C5BC000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0E5B8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x105C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1A5CA000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1C5C002D, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x125C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0A4C0800, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0C4C0082, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x084C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x000DA000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x060D8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x080DA000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0A0DA000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0C0DA000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0E0DA000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x020D2000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0C0F5400, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0E0F5500, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x100F0155, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x002CC000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0E2CC000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x162CBE00, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x182C00EF, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x022CC000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x042C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x19900157, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1B900167, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1D900105, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1F900103, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x35900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x0D28, 0x00000000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11900FFF, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x51900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x41900840, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x55900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x45900842, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x47900840, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x57900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x49900840, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x33900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4B900040, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x59900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x43900840, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x53901111, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
  
        }
  
        availabilityEquation = "$SliceMask 0x01 AND $SkuRevisionId 0x02 UGTE &&";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            MD_CHECK_CC( aSet->AddStartRegisterSet( 1, 0, availabilityEquation ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x000000A0, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x104F00E0, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x124F1C00, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x106C00E0, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x37906800, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x3F901403, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x004E8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A4E0820, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C4E0002, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x064F0900, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x084F0032, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A4F1810, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C4F0E00, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E4F003C, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x004F0D80, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x024F003B, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x006C0002, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x086C0000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C6C000C, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E6C0B00, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x186C0000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C6C0000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1E6C0000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x001B4000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x081B8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C1B4000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E1B8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x101C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A1C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C1C0024, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x065B8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x085B4000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A5BC000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C5B8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E5B4000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x005B8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x025B4000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A5C6000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C5C001B, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x125C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x145C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x004C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A4C2000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C4C0208, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x000DA000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x060D8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x080DA000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A0DA000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C0DA000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E0DA000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x020D2000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C0F5400, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E0F5500, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x100F0155, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x002C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E2CC000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x162CFB00, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x182C00BE, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x022CC000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x042CC000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19900157, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B900167, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D900105, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1F900103, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x35900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11900FFF, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x51900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x41900800, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x55900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x45900842, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x47900802, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x57900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x49900802, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x33900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4B900002, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x59900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x43900842, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x53901111, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
  
        }
  
        availabilityEquation = "$SliceMask 0x02 AND $SkuRevisionId 0x02 ULT &&";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            MD_CHECK_CC( aSet->AddStartRegisterSet( 1, 2, availabilityEquation ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA ));
  
        }
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_SKL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask, GT_TYPE_GT2 ) )
    {
        aSet = aGroup->AddMetricSet( "RenderDX1x", "Render Metrics DX1x Gen9", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, GT_TYPE_GT2 );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
            "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerL1Misses", "Sampler Cache Misses",
            "The total number of sampler cache misses in all LODs in all sampler units.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd0 8 UMUL" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x150 8 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3Lookups", "L3 Lookup Accesses w/o IC",
            "The total number of L3 cache lookup accesses w/o IC.",
            "L3/TAG", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_L3_TAG * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$SamplerL1Misses $$ShaderMemoryAccesses UADD" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3Misses", "L3 Misses",
            "The total number of L3 misses.",
            "L3/TAG", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_L3_TAG * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3SamplerThroughput", "L3 Sampler Throughput",
            "The total number of GPU memory bytes transferred between samplers and L3 caches.",
            "L3/Sampler", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SamplerL1Misses 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
            "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten $ShaderMemoryAccesses 64 UMUL UADD UADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = "$SubsliceMask 0x09 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler0Busy", "Sampler 0 Busy",
                "The percentage of time in which Sampler 0 has been processing EU requests.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x12 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler1Busy", "Sampler 1 Busy",
                "The percentage of time in which Sampler 1 has been processing EU requests.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplersBusy", "Samplers Busy",
            "The percentage of time in which samplers have been processing EU requests.",
            "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$Sampler0Busy $$Sampler1Busy FMAX" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = "$SubsliceMask 0x09 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler0Bottleneck", "Sampler 0 Bottleneck",
                "The percentage of time in which Sampler 0 has been slowing down the pipe when processing EU requests.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x12 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler1Bottleneck", "Sampler 1 Bottleneck",
                "The percentage of time in which Sampler 1 has been slowing down the pipe when processing EU requests.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xcc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerBottleneck", "Samplers Bottleneck",
            "The percentage of time in which samplers have been slowing down the pipe when processing EU requests.",
            "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_INDICATE|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$Sampler0Bottleneck $$Sampler1Bottleneck FMAX" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiVfThroughput", "GTI Fixed Pipe Throughput",
            "The total number of GPU memory bytes transferred between 3D Pipeline (Command Dispatch, Input Assembly and Stream Output) and GTI.",
            "GTI/3D Pipe", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd8 dw@0xdc UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x160 qw@0x168 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiDepthThroughput", "GTI Depth Throughput",
            "The total number of GPU memory bytes transferred between depth caches and GTI.",
            "GTI/Depth Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCZ * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe0 dw@0xe4 UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x170 qw@0x178 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiRccThroughput", "GTI RCC Throughput",
            "The total number of GPU memory bytes transferred between render color caches and GTI.",
            "GTI/Color Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCC * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe8 dw@0xec UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x180 qw@0x188 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiL3Throughput", "GTI L3 Throughput",
            "The total number of GPU memory bytes transferred between L3 caches and GTI.",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$L3Misses 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiHdcLookupsThroughput", "GTI HDC TLB Lookup Throughput",
            "The total number of GPU memory bytes transferred between GTI and HDC, when HDC is doing TLB lookups.",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiReadThroughput", "GTI Read Throughput",
            "The total number of GPU memory bytes read from GTI.",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiWriteThroughput", "GTI Write Throughput",
            "The total number of GPU memory bytes written to GTI.",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 32 UMUL" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00015014, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00025024, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00035034, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00045044, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00055054, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00065064, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
  
        availabilityEquation = "$SliceMask 0x01 AND $SkuRevisionId 0x02 UGTE &&";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            MD_CHECK_CC( aSet->AddStartRegisterSet( 1, 0, availabilityEquation ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x166c01e0, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12170280, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12370280, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11930317, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x159303df, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3f900003, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a4e0080, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a6c0053, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x106c0000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c6c0000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a1b4000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c1c0001, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x002f1000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x042f1000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x004c4000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a4c8400, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x000d2000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x060d8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x080da000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a0d2000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c0f0400, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e0f6600, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x002c8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x162c2200, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x062d8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x082d8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00133000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08133000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00170020, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08170021, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10170000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0633c000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0833c000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06370800, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08370840, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10370000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0d933031, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0f933e3f, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x01933d00, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0393073c, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0593000e, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1d930000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x19930000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1b930000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1d900157, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1f900158, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x35900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x2b908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x2d908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x2f908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x31908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x15908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x17908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x19908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1b908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1190001f, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x51904400, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x41900020, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x55900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x45900c21, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x47900061, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x57904440, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x49900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x37900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x33900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4b900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x59900004, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x43900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x53904444, REGISTER_TYPE_NOA ));
  
        }
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_SKL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask, GT_TYPE_GT2 ) )
    {
        aSet = aGroup->AddMetricSet( "RenderPipeProfile", "Render Metrics for 3D Pipeline Profile Gen9", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, GT_TYPE_GT2 );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
            "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
            "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten $ShaderMemoryAccesses 64 UMUL UADD UADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VfBottleneck", "VF Bottleneck",
            "The percentage of time in which vertex fetch pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Input Assembler", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_IA * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x170" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsBottleneck", "VS Bottleneck",
            "The percentage of time in which vertex shader pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Vertex Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 10, 30, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsBottleneck", "HS Bottleneck",
            "The percentage of time in which hull shader pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Hull Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 3, 9, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsBottleneck", "DS Bottleneck",
            "The percentage of time in which domain shader pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Domain Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsBottleneck", "GS Bottleneck",
            "The percentage of time in which geometry shader pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Geometry Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xcc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SoBottleneck", "SO Bottleneck",
            "The percentage of time in which stream output pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Stream Output", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_SO * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x150" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ClBottleneck", "Clipper Bottleneck",
            "The percentage of time in which clipper pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Clipper", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_CL * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 10, 30, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x158" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SfBottleneck", "Strip-Fans Bottleneck",
            "The percentage of time in which strip-fans pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Rasterizer/Strip-Fans", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_SF * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 10, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x160" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthBottleneck", "Hi-Depth Bottleneck",
            "The percentage of time in which early hierarchical depth test pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthBottleneck", "Early Depth Bottleneck",
            "The percentage of time in which early depth test pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 10, 30, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xdc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x168" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "BcBottleneck", "BC Bottleneck",
            "The percentage of time in which barycentric coordinates calculation pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Rasterizer/Barycentric Calc", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_BC * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsStall", "HS Stall",
            "The percentage of time in which hull stall pipeline stage was stalled.",
            "3D Pipe/Hull Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_CORRELATE|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x178" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsStall", "DS Stall",
            "The percentage of time in which domain shader pipeline stage was stalled.",
            "3D Pipe/Domain Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_CORRELATE|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x180" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SoStall", "SO Stall",
            "The percentage of time in which stream-output pipeline stage was stalled.",
            "3D Pipe/Stream Output", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_SO * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_CORRELATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xec" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x188" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ClStall", "CL Stall",
            "The percentage of time in which clipper pipeline stage was stalled.",
            "3D Pipe/Clipper", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_CL * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_CORRELATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SfStall", "SF Stall",
            "The percentage of time in which strip-fans pipeline stage was stalled.",
            "3D Pipe/Rasterizer/Strip-Fans", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_SF * 0x100), USAGE_FLAG_TIER_4|USAGE_FLAG_CORRELATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00015014, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00025024, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00035034, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00045044, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00055054, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00065064, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x0007ffea, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x00007ffc, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x0007affa, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x0000f5fd, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x00079ffa, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x0000f3fb, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2788, 0x0007bf7a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x278c, 0x0000f7e7, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2790, 0x0007fefa, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2794, 0x0000f7cf, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2798, 0x00077ffa, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x279c, 0x0000efdf, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a0, 0x0006fffa, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a4, 0x0000cfbf, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a8, 0x0003fffa, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27ac, 0x00005f7f, REGISTER_TYPE_OA ));
  
        availabilityEquation = "$SkuRevisionId 0x02 ULT";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            MD_CHECK_CC( aSet->AddStartRegisterSet( 1, 0, availabilityEquation ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x000000A0, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0C0E001F, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0A0F0000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10116800, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x178A03E0, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11824C00, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11830020, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x13840020, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11850019, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11860007, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x01870C40, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x17880000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x022F4000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0A4C0040, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0C0D8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x040D4000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x060D2000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x020E5400, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x000E0000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x080F0040, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x000F0000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x100F0000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0E0F0040, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0C2C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06104000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06110012, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06131000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x01898000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0D890100, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x03898000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x09808000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0B808000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0380C000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0F8A0075, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1D8A0000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x118A8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1B8A4000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x138A8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1D81A000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x15818000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x17818000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0B820030, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x07828000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0D824000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0F828000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x05824000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0D830003, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0583000C, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x09830000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x03838000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x07838000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0B840980, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x03844D80, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11840000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x09848000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x09850080, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x03850003, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x01850000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x07860000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0F860400, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x09870032, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x01888052, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11880000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x09884000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x15968000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x17968000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0F96C000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1F950011, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1D950014, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0592C000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0B928000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0D924000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0F924000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11928000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1392C000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x09924000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x01985000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x07988000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x09981000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0B982000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0D982000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0F989000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x05982000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x13904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x21904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x23904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x25908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x27904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x29908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x2B904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x2F904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x31904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x15904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x17908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x19908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1B904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0B978000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0F974000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11974000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x13978000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x09974000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x0D28, 0x00000000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1190C080, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x51900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x419010A0, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x55904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x45901000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x47900084, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x57904400, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x499000A5, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x37900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x33900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4B900081, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x59900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x439014A4, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x53900400, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
  
        }
  
        availabilityEquation = "$SkuRevisionId 0x02 UGTE";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            MD_CHECK_CC( aSet->AddStartRegisterSet( 1, 0, availabilityEquation ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x000000A0, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C0E001F, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A0F0000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x10116800, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x178A03E0, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11824C00, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11830020, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x13840020, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11850019, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11860007, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x01870C40, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x17880000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x022F4000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A4C0040, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C0D8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x040D4000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x060D2000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x020E5400, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x000E0000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x080F0040, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x000F0000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x100F0000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E0F0040, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C2C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x06104000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x06110012, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x06131000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x01898000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0D890100, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x03898000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x09808000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0B808000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0380C000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0F8A0075, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D8A0000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x118A8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B8A4000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x138A8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D81A000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x15818000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x17818000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0B820030, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x07828000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0D824000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0F828000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x05824000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0D830003, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0583000C, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x09830000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x03838000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x07838000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0B840980, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x03844D80, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11840000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x09848000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x09850080, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x03850003, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x01850000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x07860000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0F860400, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x09870032, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x01888052, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11880000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x09884000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B931001, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D930001, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19934000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B958000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D950094, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19958000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x05E5A000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x01E5C000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0592C000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0B928000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0D924000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0F924000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11928000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1392C000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x09924000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x01985000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x07988000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x09981000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0B982000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0D982000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0F989000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x05982000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x13904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x21904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x23904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x25908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x27904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x29908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2B904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2F904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x31904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x15904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x17908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1190C080, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x51900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x419010A0, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x55904000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x45901000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x47900084, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x57904400, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x499000A5, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x37900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x33900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4B900081, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x59900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x439014A4, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x53900400, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
  
        }
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_SKL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask, GT_TYPE_GT2 ) )
    {
        aSet = aGroup->AddMetricSet( "MemoryReads", "Memory Reads Distribution Gen9", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, GT_TYPE_GT2 );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
            "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiCmdStreamerMemoryReads", "GtiCmdStreamerMemoryReads",
            "The total number of GTI memory reads from Command Streamer.",
            "GTI/3D Pipe/Command Streamer", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000) | (METRIC_GROUP_NAME_ID_RCS * 0x100), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiRsMemoryReads", "GtiRsMemoryReads",
            "The total number of GTI memory reads from Resource Streamer.",
            "GTI/3D Pipe/Resource Streamer", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000) | (METRIC_GROUP_NAME_ID_RS * 0x100), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiVfMemoryReads", "GtiVfMemoryReads",
            "The total number of GTI memory reads from Vertex Fetch.",
            "GTI/3D Pipe/Vertex Fetch", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000) | (METRIC_GROUP_NAME_ID_VF * 0x100), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiRccMemoryReads", "GtiRccMemoryReads",
            "The total number of GTI memory reads from Render Color Cache (Render Color Cache misses).",
            "GTI/Color Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCC * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xcc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiMscMemoryReads", "GtiMscMemoryReads",
            "The total number of GTI memory reads from Multisampling Color Cache (Multisampling Color Cache misses).",
            "GTI/Color Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCC * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x150" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiHizMemoryReads", "GtiHizMemoryReads",
            "The total number of GTI memory reads from Hierarchical Depth Cache (Hi-Depth Cache misses).",
            "GTI/Depth Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCZ * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x158" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiStcMemoryReads", "GtiStcMemoryReads",
            "The total number of GTI memory reads from Stencil Cache (Stencil Cache misses).",
            "GTI/Depth Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCZ * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x160" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiRczMemoryReads", "GtiRczMemoryReads",
            "The total number of GTI memory reads from Render Depth Cache (Render Depth Cache misses).",
            "GTI/Depth Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCZ * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xdc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x168" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiMemoryReads", "GtiMemoryReads",
            "The total number of GTI memory reads.",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x170" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiL3Bank0Reads", "GtiL3Bank0Reads",
            "The total number of GTI memory reads from L3 Bank 0 (L3 Cache misses).",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiL3Bank1Reads", "GtiL3Bank1Reads",
            "The total number of GTI memory reads from L3 Bank 1 (L3 Cache misses).",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiL3Bank2Reads", "GtiL3Bank2Reads",
            "The total number of GTI memory reads from L3 Bank 2 (L3 Cache misses).",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiL3Bank3Reads", "GtiL3Bank3Reads",
            "The total number of GTI memory reads from L3 Bank 3 (L3 Cache misses).",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiL3Reads", "GtiL3Reads",
            "The total number of GTI memory reads from L3 (L3 Cache misses).",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$GtiL3Bank0Reads $$GtiL3Bank1Reads $$GtiL3Bank2Reads $$GtiL3Bank3Reads UADD UADD UADD" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiRingAccesses", "GtiRingAccesses",
            "The total number of all accesses from GTI to the ring.",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xec" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x188" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 2 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00015014, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00025024, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00035034, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00045044, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00055054, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00065064, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x272c, 0xffffffff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2728, 0xffffffff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x271c, 0xffffffff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2718, 0xffffffff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x274c, 0x86543210, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2748, 0x86543210, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2744, 0x00006667, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x275c, 0x86543210, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2758, 0x86543210, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2754, 0x00006465, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2750, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x0007f81a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x0007f82a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x0007f872, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2788, 0x0007f8ba, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x278c, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2790, 0x0007f87a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2794, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2798, 0x0007f8ea, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x279c, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a0, 0x0007f8e2, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a4, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a8, 0x0007f8f2, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27ac, 0x0000fe00, REGISTER_TYPE_OA ));
  
        availabilityEquation = "$SliceMask 0x01 AND $SkuRevisionId 0x02 ULT &&";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            MD_CHECK_CC( aSet->AddStartRegisterSet( 1, 0, availabilityEquation ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x000000A0, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11810C00, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1381001A, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x13946000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x37906800, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3F900003, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x03811300, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x05811B12, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0781001A, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1F810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x17810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x19810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1B810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1D810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0F968000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1196C000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x13964000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11938000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1B93FE00, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x01940010, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x07941100, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x09941312, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0B941514, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0D941716, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11940000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x19940000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1B940000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1D940000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1B954000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1D95A550, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1F9502AA, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x2F900157, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x31900105, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x15900103, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x17900101, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x35900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x13908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x21908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x23908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x25908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x27908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x29908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x2B908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x2D908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x19908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1B908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1D908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1F908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x0D28, 0x00000000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x51900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x41900C00, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x55900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x45900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x47900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x57900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x49900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x33900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4B900063, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x59900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x43900003, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x53900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
  
        }
  
        availabilityEquation = "$SkuRevisionId 0x05 ULT $SkuRevisionId 0x02 UGTE &&";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            MD_CHECK_CC( aSet->AddStartRegisterSet( 1, 0, availabilityEquation ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x000000A0, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11810C00, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1381001A, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x13946000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x15940016, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x37906800, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x03811300, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x05811B12, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0781001A, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1F810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x17810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19930800, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B93AA55, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D9300AA, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x01940010, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x07941100, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x09941312, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0B941514, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0D941716, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0F940018, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B940000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11940000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x01E58000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x03E57000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x31900105, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x15900103, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x17900101, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x35900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x13908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x21908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x23908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x25908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x27908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x29908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2B908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2D908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2F908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1F908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x51900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x41900C20, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x55900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x45900400, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x47900421, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x57900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x49900421, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x33900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4B900061, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x59900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x43900003, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x53900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
  
        }
  
        availabilityEquation = "$SkuRevisionId 0x05 UGTE";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            MD_CHECK_CC( aSet->AddStartRegisterSet( 1, 0, availabilityEquation ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009840, 0x00000080, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11810C00, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1381001A, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x37906800, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x3F900064, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x03811300, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x05811B12, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0781001A, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1F810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x17810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B930055, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x03E58000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x05E5C000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x07E54000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x13900150, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x21900151, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x23900152, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x25900153, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x27900154, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x29900155, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2B900156, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2D900157, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2F90015F, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x31900105, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x15900103, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x17900101, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x35900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1F908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x51900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x41900C60, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x55900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x45900C00, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x47900C63, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x57900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x49900C63, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x33900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4B900063, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x59900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x43900003, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x53900000, REGISTER_TYPE_NOA ));
  
        }
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_SKL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask, GT_TYPE_GT2 ) )
    {
        aSet = aGroup->AddMetricSet( "MemoryWrites", "Memory Writes Distribution Gen9", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, GT_TYPE_GT2 );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
            "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
            "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten $ShaderMemoryAccesses 64 UMUL UADD UADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiCmdStreamerMemoryWrites", "GtiCmdStreamerMemoryWrites",
            "The total number of GTI memory writes from Command Streamer.",
            "GTI/3D Pipe/Command Streamer", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000) | (METRIC_GROUP_NAME_ID_RCS * 0x100), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiSoMemoryWrites", "GtiSoMemoryWrites",
            "The total number of GTI memory writes from Stream Output.",
            "GTI/3D Pipe/Stream Output", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000) | (METRIC_GROUP_NAME_ID_SO * 0x100), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiRccMemoryWrites", "GtiRccMemoryWrites",
            "The total number of GTI memory writes from Render Color Cache (Render Color Cache invalidations).",
            "GTI/Color Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCC * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xcc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiMscMemoryWrites", "GtiMscMemoryWrites",
            "The total number of GTI memory writes from Multisampling Color Cache (Multisampling Color Cache invalidations).",
            "GTI/Color Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCC * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x150" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiHizMemoryWrites", "GtiHizMemoryWrites",
            "The total number of GTI memory writes from Hierarchical Depth Cache.",
            "GTI/Depth Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCZ * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x158" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiStcMemoryWrites", "GtiStcMemoryWrites",
            "The total number of GTI memory writes from Stencil Cache.",
            "GTI/Depth Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCZ * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x160" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiRczMemoryWrites", "GtiRczMemoryWrites",
            "The total number of GTI memory writes from Render Depth Cache.",
            "GTI/Depth Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCZ * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xdc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x168" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiMemoryWrites", "GtiMemoryWrites",
            "The total number of GTI memory writes.",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x170" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiL3Bank0Writes", "GtiL3Bank0Writes",
            "The total number of GTI memory writes from L3 Bank 0 (L3 Bank 0 invalidations).",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiL3Bank1Writes", "GtiL3Bank1Writes",
            "The total number of GTI memory writes from L3 Bank 1 (L3 Bank 1 invalidations).",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiL3Bank2Writes", "GtiL3Bank2Writes",
            "The total number of GTI memory writes from L3 Bank 2 (L3 Bank 2 invalidations).",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiL3Bank3Writes", "GtiL3Bank3Writes",
            "The total number of GTI memory writes from L3 Bank 3 (L3 Bank 3 invalidations).",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiL3Writes", "GtiL3Writes",
            "The total number of GTI memory writes from L3 (L3 invalidations).",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$GtiL3Bank0Writes $$GtiL3Bank1Writes $$GtiL3Bank2Writes $$GtiL3Bank3Writes UADD UADD UADD" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiRingAccesses", "GtiRingAccesses",
            "The total number of all GTI accesses to the ring.",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xec" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x188" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 2 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00015014, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00025024, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00035034, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00045044, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00055054, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00065064, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x272c, 0xffffffff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2728, 0xffffffff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x271c, 0xffffffff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2718, 0xffffffff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x274c, 0x86543210, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2748, 0x86543210, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2744, 0x00006667, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x275c, 0x86543210, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2758, 0x86543210, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2754, 0x00006465, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2750, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x0007f81a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x0007f82a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x0007f822, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2788, 0x0007f8ba, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x278c, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2790, 0x0007f87a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2794, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2798, 0x0007f8ea, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x279c, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a0, 0x0007f8e2, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a4, 0x0000fe00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a8, 0x0007f8f2, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27ac, 0x0000fe00, REGISTER_TYPE_OA ));
  
        availabilityEquation = "$SliceMask 0x01 AND $SkuRevisionId 0x02 ULT &&";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            MD_CHECK_CC( aSet->AddStartRegisterSet( 1, 0, availabilityEquation ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x000000A0, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11810C00, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1381001A, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x13945400, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x37906800, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x3F901400, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x03811300, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x05811B12, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0781001A, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1F810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x17810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x19810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1B810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1D810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0F968000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1196C000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x13964000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11938000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1B93FE00, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x01940010, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x07941100, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x09941312, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0B941514, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0D941716, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11940000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x19940000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1B940000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1D940000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1B954000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1D95A550, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1F9502AA, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x2F900167, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x31900105, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x15900103, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x17900101, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x35900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x13908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x21908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x23908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x25908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x27908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x29908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x2B908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x2D908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x19908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1B908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1D908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1F908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x0D28, 0x00000000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x51900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x41900C00, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x55900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x45900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x47900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x57900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x49900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x33900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4B900063, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x59900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x43900003, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x53900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
  
        }
  
        availabilityEquation = "$SkuRevisionId 0x05 ULT $SkuRevisionId 0x02 UGTE &&";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            MD_CHECK_CC( aSet->AddStartRegisterSet( 1, 0, availabilityEquation ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x000000A0, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11810C00, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1381001A, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x13945400, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x37906800, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x3F901400, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x03811300, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x05811B12, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0781001A, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1F810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x17810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19930800, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B93AA55, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D93002A, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x01940010, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x07941100, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x09941312, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0B941514, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0D941716, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B940000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11940000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x01E58000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x03E57000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2F900167, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x31900105, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x15900103, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x17900101, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x35900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x13908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x21908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x23908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x25908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x27908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x29908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2B908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2D908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1F908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x51900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x41900C20, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x55900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x45900400, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x47900421, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x57900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x49900421, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x33900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4B900063, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x59900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x43900003, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x53900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
  
        }
  
        availabilityEquation = "$SkuRevisionId 0x05 UGTE";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            MD_CHECK_CC( aSet->AddStartRegisterSet( 1, 0, availabilityEquation ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009840, 0x00000080, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11810C00, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1381001A, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x37906800, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x3F901000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x03811300, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x05811B12, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0781001A, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1F810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x17810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D810000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B930055, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x03E58000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x05E5C000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x07E54000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x13900160, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x21900161, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x23900162, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x25900163, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x27900164, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x29900165, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2B900166, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2D900167, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x2F900150, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x31900105, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x15900103, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x17900101, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x35900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1F908000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x51900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x41900C60, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x55900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x45900C00, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x47900C63, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x57900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x49900C63, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x33900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4B900063, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x59900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x43900003, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x53900000, REGISTER_TYPE_NOA ));
  
        }
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_SKL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask, GT_TYPE_GT2 ) )
    {
        aSet = aGroup->AddMetricSet( "ComputeExtended", "Compute Metrics Extended Gen9", API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, GT_TYPE_GT2 );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId(NULL, 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuAvgIpcRate", "EU AVG IPC Rate",
            "The average rate of IPC calculated for 2 FPU pipelines.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_RATIO, RESULT_FLOAT, "number", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$EuFpuBothActive $Fpu0Active $Fpu1Active UADD $EuFpuBothActive USUB FDIV 1 FADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "2" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuFpuBothActive", "EU Both FPU Pipes Active",
            "The percentage of time in which both EU FPU pipelines were actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x34:0xa9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "Fpu0Active", "EU FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x38:0xaa" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x60" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "Fpu1Active", "EU FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuSendActive", "EU Send Pipe Active",
            "The percentage of time in which EU send pipeline was actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x40:0xac" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
            "The percentage of time in which hardware threads occupied EUs.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x44:0xad" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x78" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 8 UMUL $EuCoresTotalCount UDIV $EuThreadsCount UDIV 100 UMUL $GpuCoreClocks FDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
            "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten $ShaderMemoryAccesses 64 UMUL UADD UADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuUntypedReads0", "EuUntypedReads0",
            "The subslice 0 EU Untyped Reads subslice 0.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuTypedReads0", "EuTypedReads0",
            "The subslice 0 EU Typed Reads subslice 0.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuUntypedWrites0", "EuUntypedWrites0",
            "The subslice 0 EU Untyped Writes subslice 0.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuTypedWrites0", "EuTypedWrites0",
            "The subslice 0 EU Typed Writes subslice 0.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xcc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuUntypedAtomics0", "EuUntypedAtomics0",
            "The subslice 0 EU Untyped Atomics subslice 0.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x150" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuTypedAtomics0", "EuTypedAtomics0",
            "The subslice 0 EU Typed Atomics subslice 0.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x158" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuA64UntypedReads0", "EuA64UntypedReads0",
            "The subslice 0 EU A64 Untyped Reads subslice 0.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x160" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuA64UntypedWrites0", "EuA64UntypedWrites0",
            "The subslice 0 EU A64 Untyped Writes subslice 0.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xdc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x168" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "TypedReads0", "Typed Reads 0",
            "The subslice 0 typed reads.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x180" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "TypedWrites0", "Typed Writes 0",
            "The subslice 0 typed writes.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x170" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "UntypedReads0", "Untyped Reads 0",
            "The subslice 0 untyped reads (including SLM reads).",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xec" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x188" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "UntypedWrites0", "Untyped Writes 0",
            "The subslice 0 untyped writes (including SLM writes).",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x178" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "TypedAtomics0", "Typed Atomics 0",
            "The subslice 0 typed atomics.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "TypedReadsPerCacheLine", "TypedReadsPerCacheLine",
            "The ratio of EU typed read requests to L3 cache line reads.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_RATIO, RESULT_FLOAT, "EU sends to L3 cache lines", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$EuTypedReads0 $$TypedReads0 FDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "TypedWritesPerCacheLine", "TypedWritesPerCacheLine",
            "The ratio of EU typed write requests to L3 cache line writes.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_RATIO, RESULT_FLOAT, "EU sends to L3 cache lines", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$EuTypedWrites0 $$TypedWrites0 FDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "UntypedReadsPerCacheLine", "UntypedReadsPerCacheLine",
            "The ratio of EU untyped read requests to L3 cache line reads.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_RATIO, RESULT_FLOAT, "EU sends to L3 cache lines", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$EuUntypedReads0 $$EuA64UntypedReads0 UADD $$UntypedReads0 FDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "UntypedWritesPerCacheLine", "UntypedWritesPerCacheLine",
            "The ratio of EU untyped write requests to L3 cache line writes.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_RATIO, RESULT_FLOAT, "EU sends to L3 cache lines", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$EuUntypedWrites0 $$EuA64UntypedWrites0 UADD $$UntypedWrites0 FDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "TypedAtomicsPerCacheLine", "TypedAtomicsPerCacheLine",
            "The ratio of EU typed atomics requests to L3 cache line writes.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_RATIO, RESULT_FLOAT, "EU sends to L3 cache lines", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$EuTypedAtomics0 $$TypedAtomics0 FDIV" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00000003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00002001, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00778008, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00088078, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00808708, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00a08908, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x0007fc2a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000bf00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x0007fc6a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x0000bf00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x0007fc92, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x0000bf00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2788, 0x0007fca2, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x278c, 0x0000bf00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2790, 0x0007fc32, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2794, 0x0000bf00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2798, 0x0007fc9a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x279c, 0x0000bf00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a0, 0x0007fe6a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a4, 0x0000bf00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a8, 0x0007fe7a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27ac, 0x0000bf00, REGISTER_TYPE_OA ));
  
        availabilityEquation = "$SubsliceMask 0x01 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            MD_CHECK_CC( aSet->AddStartRegisterSet( 1, 0, availabilityEquation ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x000000A0, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x106C00E0, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x141C8160, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x161C8015, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x181C0120, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x004E8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0E4E8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x184E8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1A4EAAA0, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1C4E0002, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x024E8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x044E8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x064E8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x084E8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0A4E8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0E6C0B01, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x006C0200, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x026C000C, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1C6C0000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1E6C0000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1A6C0000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0E1BC000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x001B8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x021BC000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x001C0041, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x061C4200, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x081C4443, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0A1C4645, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0C1C7647, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x041C7357, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1C1C0030, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x101C0000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1A1C0000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x121C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x004C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0A4CAA2A, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0C4C02AA, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x084CA000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x000DA000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x060D8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x080DA000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0A0DA000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0C0DA000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0E0DA000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x020DA000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x040DA000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0C0F5400, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0E0F5515, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x100F0155, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x002C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0E2C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x162CAA00, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x182C00AA, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x022C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x042C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x062C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x082C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0A2C8000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x0D28, 0x00000000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11907FFF, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x51900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x41900040, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x55900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x45900802, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x47900842, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x57900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x49900842, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x37900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x33900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4B900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x59900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x43900800, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x53900000, REGISTER_TYPE_NOA ));
            MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
  
        }
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_SKL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask, GT_TYPE_GT2 ) )
    {
        aSet = aGroup->AddMetricSet( "ComputeL3Cache", "Compute Metrics L3 Cache Gen9", API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, GT_TYPE_GT2 );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuAvgIpcRate", "EU AVG IPC Rate",
            "The average rate of IPC calculated for 2 FPU pipelines.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_RATIO, RESULT_FLOAT, "number", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$EuFpuBothActive $Fpu0Active $Fpu1Active UADD $EuFpuBothActive USUB FDIV 1 FADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "2" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuFpuBothActive", "EU Both FPU Pipes Active",
            "The percentage of time in which both EU FPU pipelines were actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x34:0xa9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "Fpu0Active", "EU FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x38:0xaa" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x60" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "Fpu1Active", "EU FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuSendActive", "EU Send Pipe Active",
            "The percentage of time in which EU send pipeline was actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x40:0xac" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuHybridFpu0Instruction", "EU FPU0 Hybrid Instruction",
            "The percentage of time in which execution units were actively processing hybrid instructions on FPU0.",
            "EU Array/Pipes/Instructions", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000) | (METRIC_GROUP_NAME_ID_EU_INSTR * 0x100), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x44:0xad" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x78" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuHybridFpu1Instruction", "EU FPU1 Hybrid Instruction",
            "The percentage of time in which execution units were actively processing hybrid instructions on FPU1.",
            "EU Array/Pipes/Instructions", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000) | (METRIC_GROUP_NAME_ID_EU_INSTR * 0x100), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x48:0xae" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x80" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuTernaryFpu0Instruction", "EU FPU0 Ternary Instruction",
            "The percentage of time in which execution units were actively processing ternary instructions on FPU0.",
            "EU Array/Pipes/Instructions", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000) | (METRIC_GROUP_NAME_ID_EU_INSTR * 0x100), USAGE_FLAG_TIER_4|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x88" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuTernaryFpu1Instruction", "EU FPU1 Ternary Instruction",
            "The percentage of time in which execution units were actively processing ternary instructions on FPU1.",
            "EU Array/Pipes/Instructions", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000) | (METRIC_GROUP_NAME_ID_EU_INSTR * 0x100), USAGE_FLAG_TIER_4|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x50:0xb0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuBinaryFpu0Instruction", "EU FPU0 Binary Instruction",
            "The percentage of time in which execution units were actively processing binary instructions on FPU0.",
            "EU Array/Pipes/Instructions", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000) | (METRIC_GROUP_NAME_ID_EU_INSTR * 0x100), USAGE_FLAG_TIER_4|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x54:0xb1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuBinaryFpu1Instruction", "EU FPU1 Binary Instruction",
            "The percentage of time in which execution units were actively processing binary instructions on FPU1.",
            "EU Array/Pipes/Instructions", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000) | (METRIC_GROUP_NAME_ID_EU_INSTR * 0x100), USAGE_FLAG_TIER_4|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x58:0xb2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xa0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuMoveFpu0Instruction", "EU FPU0 Move Instruction",
            "The percentage of time in which execution units were actively processing move instructions on FPU0.",
            "EU Array/Pipes/Instructions", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000) | (METRIC_GROUP_NAME_ID_EU_INSTR * 0x100), USAGE_FLAG_TIER_4|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x5c:0xb3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xa8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuMoveFpu1Instruction", "EU FPU1 Move Instruction",
            "The percentage of time in which execution units were actively processing move instructions on FPU1.",
            "EU Array/Pipes/Instructions", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000) | (METRIC_GROUP_NAME_ID_EU_INSTR * 0x100), USAGE_FLAG_TIER_4|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x60:0xb4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
            "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerAccesses", "Sampler Accesses",
            "The total number of messages send to samplers.",
            "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3Accesses", "L3 Accesses",
            "The total number of L3 accesses from all entities.",
            "L3", (METRIC_GROUP_NAME_ID_L3 * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe0 dw@0xe4 dw@0xc8 dw@0xcc UADD UADD UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x170 qw@0x178 qw@0x140 qw@0x148 UADD UADD UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 2 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderLookups", "L3 Shader Lookup Accesses",
            "The total number of L3 cache lookup accesses w/o IC.",
            "L3/TAG", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_L3_TAG * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$SamplerL1Misses $$ShaderMemoryAccesses UADD" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3Misses", "L3 Misses",
            "The total number of L3 misses.",
            "L3/TAG", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_L3_TAG * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0 dw@0xf4 UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190 qw@0x198 UADD" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3SamplerThroughput", "L3 Sampler Throughput",
            "The total number of GPU memory bytes transferred between samplers and L3 caches.",
            "L3/Sampler", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
            "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten $ShaderMemoryAccesses 64 UMUL UADD UADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3TotalThroughput", "L3 Total Throughput",
            "The total number of GPU memory bytes transferred via L3.",
            "L3", (METRIC_GROUP_NAME_ID_L3 * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$L3Accesses 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = "$SliceMask 0x01 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L3Bank00Accesses", "L3 Bank 00 Accesses",
                "The total number of accesses to L3 Bank 00.",
                "L3", (METRIC_GROUP_NAME_ID_L3 * 0x1000000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x170" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 2 UMUL" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SliceMask 0x01 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L3Bank01Accesses", "L3 Bank 01 Accesses",
                "The total number of accesses to L3 Bank 01.",
                "L3", (METRIC_GROUP_NAME_ID_L3 * 0x1000000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x178" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 2 UMUL" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SliceMask 0x01 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L3Bank02Accesses", "L3 Bank 02 Accesses",
                "The total number of accesses to L3 Bank 02.",
                "L3", (METRIC_GROUP_NAME_ID_L3 * 0x1000000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 2 UMUL" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SliceMask 0x01 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L3Bank03Accesses", "L3 Bank 03 Accesses",
                "The total number of accesses to L3 Bank 03.",
                "L3", (METRIC_GROUP_NAME_ID_L3 * 0x1000000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xcc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 2 UMUL" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SliceMask 0x01 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L3Bank00IcAccesses", "L3 Bank 00 IC Accesses",
                "The total number of accesses to L3 Bank 00 from IC cache.",
                "L3/IC", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_IC * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0 dw@0xc4 UADD" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130 qw@0x138 UADD" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 2 UMUL $$L3Bank00Accesses UMIN" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SliceMask 0x01 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L3Bank00IcHits", "L3 Bank 00 IC Hits",
                "The total number of hits in L3 Bank 00 from IC cache.",
                "L3/IC", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_IC * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 2 UMUL $$L3Bank00IcAccesses UMIN" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiL3Throughput", "GTI L3 Throughput",
            "The total number of GPU memory bytes transferred between L3 caches and GTI.",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0 dw@0xf4 UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190 qw@0x198 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiReadThroughput", "GTI Read Throughput",
            "The total number of GPU memory bytes read from GTI.",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiWriteThroughput", "GTI Write Throughput",
            "The total number of GPU memory bytes written to GTI.",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 32 UMUL" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x000000A0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x166C0760, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1593001E, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x3F901403, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x004E8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E4E8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x184E8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A4E8020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C4E0002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x006C0051, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x066C5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x086C5C5D, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E6C5E5F, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x106C0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x186C0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C6C0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1E6C0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x001B4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x061B8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x081BC000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E1BC000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x101C8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1A1CE000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1C1C0030, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x004C8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0A4C2A00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C4C0280, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x000D2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x060D8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x080DA000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E0DA000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0C0F0400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E0F1500, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x100F0140, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x002C8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x0E2C8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x162C0A00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x182C00A0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x03933300, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x05930032, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x11930000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B930000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1D900157, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1F900167, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x35900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x19908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1B908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x1190030F, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x51900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x41900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x55900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x45900042, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x47900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x37900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x33900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x57900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x4B900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x59900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x53901111, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x00009888, 0x43900420, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00000003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00002001, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00101100, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00201200, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00301300, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00401400, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x30800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x30800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x0007fffa, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000fefe, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x0007fffa, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x0000fefd, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2790, 0x0007fffa, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2794, 0x0000fbef, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2798, 0x0007fffa, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x279c, 0x0000fbdf, REGISTER_TYPE_OA ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_SKL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask, GT_TYPE_GT2 ) )
    {
        aSet = aGroup->AddMetricSet( "HDCAndSF", "Metric set HDCAndSF", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, GT_TYPE_GT2 );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuFpuBothActive", "EU Both FPU Pipes Active",
            "The percentage of time in which both EU FPU pipelines were actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x34:0xa9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu0Active", "VS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x38:0xaa" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x60" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu1Active", "VS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsSendActive", "VS Send Pipe Active",
            "The percentage of time in which EU send pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x40:0xac" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu0Active", "PS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x88" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x50:0xb0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsSendActive", "PS Send Pipeline Active",
            "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x54:0xb1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuBothFpuActive", "PS Both FPU Active",
            "The percentage of time in which pixel shaders were processed actively on the both FPUs.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x58:0xb2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xa0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
            "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
            "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten $ShaderMemoryAccesses 64 UMUL UADD UADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = "";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "PolyDataReady", "Polygon Data Ready",
                "The percentage of time in which geometry pipeline output is ready",
                "GPU/3D Pipe/Strip-Fans", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000) | (METRIC_GROUP_NAME_ID_SF * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "NonSamplerShader00AccessStalledOnL3", "HDC stalled by L3 (s0.ss0)",
                "Percentage of time when HDC has messges to L3, but it's stalled due to lack of credits (s0.ss0)",
                "GPU/Data Port", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc dw@0xf8 USUB" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8 qw@0x1a0 USUB" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x2 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "NonSamplerShader01AccessStalledOnL3", "HDC stalled by L3 (s0.ss1)",
                "Percentage of time when HDC has messges to L3, but it's stalled due to lack of credits (s0.ss1)",
                "GPU/Data Port", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4 dw@0xf0 USUB" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198 qw@0x190 USUB" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x4 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "NonSamplerShader02AccessStalledOnL3", "HDC stalled by L3 (s0.ss2)",
                "Percentage of time when HDC has messges to L3, but it's stalled due to lack of credits (s0.ss2)",
                "GPU/Data Port", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xec dw@0xe8 USUB" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x188 qw@0x180 USUB" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GTRequestQueueFull", "SQ is full",
            "The percentage of time when SQ is filled above a threshold (usually 48 entries)",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x000000a0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x104f0232, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x124f4640, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x106c0232, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11834400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a4e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c4e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x004f1880, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x024f08bb, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x044f001b, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x046c0100, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x066c000b, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a6c0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x041b8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x061b4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a1c1800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x005b8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x025bc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x045b4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x125c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x145c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x165c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x185c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a4c00a0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x000d8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x020da000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x040da000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x060d2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c0f5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e0f0055, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x022cc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x042cc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x062cc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x082cc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a2c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c2c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0f828000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0f8305c0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x09830000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x07830000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1d950080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x13928000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0f988000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x31904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1190fc00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x37900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x59900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4b9000a0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x51900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x41900800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x43900842, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x53900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x45900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x33900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2744, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x10800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x00000002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000fdff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00010003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00012011, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00015014, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00051050, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00053052, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00055054, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x91bc, 0xe0500000, REGISTER_TYPE_PM ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_SKL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask, GT_TYPE_GT2 ) )
    {
        aSet = aGroup->AddMetricSet( "L3_1", "Metric set L3_1", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, GT_TYPE_GT2 );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuFpuBothActive", "EU Both FPU Pipes Active",
            "The percentage of time in which both EU FPU pipelines were actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x34:0xa9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu0Active", "VS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x38:0xaa" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x60" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu1Active", "VS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsSendActive", "VS Send Pipe Active",
            "The percentage of time in which EU send pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x40:0xac" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu0Active", "PS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x88" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x50:0xb0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsSendActive", "PS Send Pipeline Active",
            "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x54:0xb1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuBothFpuActive", "PS Both FPU Active",
            "The percentage of time in which pixel shaders were processed actively on the both FPUs.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x58:0xb2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xa0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
            "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
            "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten $ShaderMemoryAccesses 64 UMUL UADD UADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = "$SliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L30Bank0Stalled", "Slice0 L3 Bank0 Stalled",
                "The percentage of time in which slice0 L3 bank0 is stalled",
                "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L30Bank1Stalled", "Slice0 L3 Bank1 Stalled",
                "The percentage of time in which slice0 L3 bank1 is stalled",
                "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x150" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L30Bank1Active", "Slice0 L3 Bank1 Active",
                "The percentage of time in which slice0 L3 bank1 is active",
                "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L30Bank0Active", "Slice0 L3 Bank0 Active",
                "The percentage of time in which slice0 L3 bank0 is active",
                "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GTRequestQueueFull", "SQ is full",
            "The percentage of time when SQ is filled above a threshold (usually 48 entries)",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x000000a0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x126c7b40, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x166c0020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a603444, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a613400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a4ea800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c4e0002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x024e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x044e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x064e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x084e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a4e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x064f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c6c5327, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e6c5425, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x006c2a00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x026c285b, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x046c005c, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x106c0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c6c0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1e6c0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a6c0800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c1bc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e1bc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x001b8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x021bc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x041bc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c1c003c, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x121c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x141c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x161c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x181c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a1c0800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x065b4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a5c1000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10600000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04600000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c610044, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10610000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06610000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c4c02a8, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x084ca000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a4c002a, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c0da000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e0da000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x000d8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x020da000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x040da000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x060d2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x100f0154, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c0f5000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e0f0055, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x182c00aa, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x022c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x042c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x062c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x082c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a2c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c2cc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1190ffc0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x57900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x49900420, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x37900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x33900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4b900021, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x59900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x51900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x41900400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x43900421, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x53900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x45900040, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2744, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x00100070, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000fff1, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x00014002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x0000c3ff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x00010002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x0000c7ff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2788, 0x00004002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x278c, 0x0000d3ff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2790, 0x00100700, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2794, 0x0000ff1f, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2798, 0x00001402, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x279c, 0x0000fc3f, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a0, 0x00001002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a4, 0x0000fc7f, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a8, 0x00000402, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27ac, 0x0000fd3f, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00010003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00012011, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00015014, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00051050, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00053052, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00055054, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x91bc, 0xe0500000, REGISTER_TYPE_PM ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_SKL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask, GT_TYPE_GT2 ) )
    {
        aSet = aGroup->AddMetricSet( "L3_2", "Metric set L3_2", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, GT_TYPE_GT2 );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuFpuBothActive", "EU Both FPU Pipes Active",
            "The percentage of time in which both EU FPU pipelines were actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x34:0xa9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu0Active", "VS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x38:0xaa" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x60" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu1Active", "VS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsSendActive", "VS Send Pipe Active",
            "The percentage of time in which EU send pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x40:0xac" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu0Active", "PS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x88" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x50:0xb0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsSendActive", "PS Send Pipeline Active",
            "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x54:0xb1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuBothFpuActive", "PS Both FPU Active",
            "The percentage of time in which pixel shaders were processed actively on the both FPUs.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x58:0xb2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xa0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
            "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
            "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten $ShaderMemoryAccesses 64 UMUL UADD UADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = "$SliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L30Bank2Stalled", "Slice0 L3 Bank2 Stalled",
                "The percentage of time in which slice0 L3 bank2 is stalled",
                "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L30Bank2Active", "Slice0 L3 Bank2 Active",
                "The percentage of time in which slice0 L3 bank2 is active",
                "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GTRequestQueueFull", "SQ is full",
            "The percentage of time when SQ is filled above a threshold (usually 48 entries)",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x000000a0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x126c02e0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x146c0001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a623400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x044e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x064e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x084e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a4e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x064f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x026c3324, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x046c3422, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x106c0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a6c0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x021bc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x041bc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x141c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x161c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x181c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a1c0800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x065b4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a5c1000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06614000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c620044, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10620000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06620000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x084c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a4c002a, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x020da000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x040da000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x060d2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c0f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e0f0055, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x042c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x062c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x082c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a2c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c2cc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1190f800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x37900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x51900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x43900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x53900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x45900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x33900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2744, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x00100070, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000fff1, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x00028002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x000087ff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x00020002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x00008fff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2788, 0x00008002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x278c, 0x0000a7ff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00010003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00012011, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00015014, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00051050, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00053052, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00055054, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x91bc, 0xe0500000, REGISTER_TYPE_PM ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_SKL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask, GT_TYPE_GT2 ) )
    {
        aSet = aGroup->AddMetricSet( "L3_3", "Metric set L3_3", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, GT_TYPE_GT2 );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuFpuBothActive", "EU Both FPU Pipes Active",
            "The percentage of time in which both EU FPU pipelines were actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x34:0xa9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu0Active", "VS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x38:0xaa" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x60" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu1Active", "VS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsSendActive", "VS Send Pipe Active",
            "The percentage of time in which EU send pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x40:0xac" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu0Active", "PS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x88" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x50:0xb0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsSendActive", "PS Send Pipeline Active",
            "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x54:0xb1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuBothFpuActive", "PS Both FPU Active",
            "The percentage of time in which pixel shaders were processed actively on the both FPUs.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x58:0xb2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xa0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
            "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
            "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten $ShaderMemoryAccesses 64 UMUL UADD UADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = "$SliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L30Bank3Stalled", "Slice0 L3 Bank3 Stalled",
                "The percentage of time in which slice0 L3 bank3 is stalled",
                "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "L30Bank3Active", "Slice0 L3 Bank3 Active",
                "The percentage of time in which slice0 L3 bank3 is active",
                "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GTRequestQueueFull", "SQ is full",
            "The percentage of time when SQ is filled above a threshold (usually 48 entries)",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x000000a0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x126c4e80, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x146c0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a633400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x044e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x064e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x084e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a4e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c4e8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x026c3321, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x046c342f, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x106c0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a6c2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x021bc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x041bc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x061b4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x141c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x161c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x181c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1a1c1800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06604000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c630044, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10630000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06630000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x084c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a4c00aa, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x020da000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x040da000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x060d2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c0f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e0f0055, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x042c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x062c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x082c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a2c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c2c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1190f800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x37900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x51900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x43900842, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x53900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x45900002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x33900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2744, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x00100070, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000fff1, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x00028002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x000087ff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x00020002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x00008fff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2788, 0x00008002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x278c, 0x0000a7ff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00010003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00012011, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00015014, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00051050, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00053052, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00055054, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x91bc, 0xe0500000, REGISTER_TYPE_PM ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_SKL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask, GT_TYPE_GT2 ) )
    {
        aSet = aGroup->AddMetricSet( "RasterizerAndPixelBackend", "Metric set RasterizerAndPixelBackend", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, GT_TYPE_GT2 );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuFpuBothActive", "EU Both FPU Pipes Active",
            "The percentage of time in which both EU FPU pipelines were actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x34:0xa9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu0Active", "VS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x38:0xaa" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x60" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu1Active", "VS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsSendActive", "VS Send Pipe Active",
            "The percentage of time in which EU send pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x40:0xac" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu0Active", "PS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x88" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x50:0xb0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsSendActive", "PS Send Pipeline Active",
            "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x54:0xb1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuBothFpuActive", "PS Both FPU Active",
            "The percentage of time in which pixel shaders were processed actively on the both FPUs.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x58:0xb2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xa0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
            "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
            "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten $ShaderMemoryAccesses 64 UMUL UADD UADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = "$SliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "PixelData0Ready", "Slice0 Post-EarlyZ Pixel Data Ready",
                "The percentage of time in which slice0 post-EarlyZ pixel data is ready (after early Z tests have been applied)",
                "GPU/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Rasterizer0InputAvailable", "Slice0 Rasterizer Input Available",
                "The percentage of time in which slice0 rasterizer input is available",
                "GPU/Rasterizer", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "PSOutput0Available", "Slice0 PS Output Available",
                "The percentage of time in which slice0 PS output is available",
                "GPU/3D Pipe", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "PixelValues0Ready", "Slice0 Pixel Values Ready",
                "The percentage of time in which slice0 pixel values are ready",
                "GPU/3D Pipe", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Rasterizer0OutputReady", "Slice0 Rasterizer Output Ready",
                "The percentage of time in which slice0 rasterizer output is ready",
                "GPU/Rasterizer", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GTRequestQueueFull", "SQ is full",
            "The percentage of time when SQ is filled above a threshold (usually 48 entries)",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x000000a0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x102f3800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x144d0500, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x120d03c0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x140d03cf, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c0f0004, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c4e4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x042f0480, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x082f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x022f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a4c0090, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x064d0027, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x004d0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x000d0d40, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x020d803f, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x040d8023, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x100d0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x060d2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x020f0010, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x000f0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e0f0050, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a2c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c2c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1190fc00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x37900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x51900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x41901400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x43901485, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x53900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x45900001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x33900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2744, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x30800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x00000002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000efff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x00006000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x0000f3ff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00010003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00012011, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00015014, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00051050, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00053052, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00055054, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x91bc, 0xe0500000, REGISTER_TYPE_PM ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_SKL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask, GT_TYPE_GT2 ) )
    {
        aSet = aGroup->AddMetricSet( "Sampler", "Metric set Sampler", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, GT_TYPE_GT2 );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuFpuBothActive", "EU Both FPU Pipes Active",
            "The percentage of time in which both EU FPU pipelines were actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x34:0xa9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu0Active", "VS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x38:0xaa" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x60" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu1Active", "VS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsSendActive", "VS Send Pipe Active",
            "The percentage of time in which EU send pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x40:0xac" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu0Active", "PS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x88" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x50:0xb0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsSendActive", "PS Send Pipeline Active",
            "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x54:0xb1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuBothFpuActive", "PS Both FPU Active",
            "The percentage of time in which pixel shaders were processed actively on the both FPUs.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x58:0xb2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xa0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
            "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
            "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten $ShaderMemoryAccesses 64 UMUL UADD UADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = "$SubsliceMask 0x2 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler01InputAvailable", "Slice0 Subslice1 Input Available",
                "The percentage of time in which slice0 subslice1 sampler input is available",
                "GPU/Sampler", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x4 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler02InputAvailable", "Slice0 Subslice2 Input Available",
                "The percentage of time in which slice0 subslice2 sampler input is available",
                "GPU/Sampler", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler00InputAvailable", "Slice0 Subslice0 Input Available",
                "The percentage of time in which slice0 subslice0 sampler input is available",
                "GPU/Sampler", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x4 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler02OutputReady", "Slice0 Subslice2 Sampler Output Ready",
                "The percentage of time in which slice0 subslice2 sampler output is ready",
                "GPU/Sampler", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler00OutputReady", "Slice0 Subslice0 Sampler Output Ready",
                "The percentage of time in which slice0 subslice0 sampler output is ready",
                "GPU/Sampler", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x2 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler01OutputReady", "Slice0 Subslice1 Sampler Output Ready",
                "The percentage of time in which slice0 subslice1 sampler output is ready",
                "GPU/Sampler", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GTRequestQueueFull", "SQ is full",
            "The percentage of time when SQ is filled above a threshold (usually 48 entries)",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x000000a0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14152c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16150005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x121600a0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14352c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16350005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x123600a0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14552c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16550005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x125600a0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x062f6000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x022f2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c4c0050, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a4c0010, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c0d8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e0da000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x000d8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x020da000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x040da000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x060d2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x100f0350, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c0fb000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e0f00da, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x182c0028, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a2c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x022dc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x042d4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c138000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e132000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0413c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c140018, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c157000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e150078, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10150000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04162180, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02160000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04174000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0233a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04333000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14348000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x16348000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02357870, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10350000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04360043, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02360000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04371000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e538000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00538000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06533000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1c540020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12548000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e557000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00557800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x10550000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06560043, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02560000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06571000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1190ff80, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x57900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x49900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x37900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x33900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4b900060, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x59900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x51900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x41900c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x43900842, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x53900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x45900060, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2744, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x70800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x0000c000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000e7ff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x00003000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x0000f9ff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x00000c00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x0000fe7f, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00010003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00012011, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00015014, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00051050, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00053052, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00055054, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x91bc, 0xe0500000, REGISTER_TYPE_PM ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_SKL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask, GT_TYPE_GT2 ) )
    {
        aSet = aGroup->AddMetricSet( "TDL_1", "Metric set TDL_1", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, GT_TYPE_GT2 );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuFpuBothActive", "EU Both FPU Pipes Active",
            "The percentage of time in which both EU FPU pipelines were actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x34:0xa9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu0Active", "VS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x38:0xaa" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x60" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu1Active", "VS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsSendActive", "VS Send Pipe Active",
            "The percentage of time in which EU send pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x40:0xac" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu0Active", "PS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x88" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x50:0xb0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsSendActive", "PS Send Pipeline Active",
            "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x54:0xb1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuBothFpuActive", "PS Both FPU Active",
            "The percentage of time in which pixel shaders were processed actively on the both FPUs.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x58:0xb2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xa0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
            "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
            "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten $ShaderMemoryAccesses 64 UMUL UADD UADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = "$SubsliceMask 0x2 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "NonPSThread01ReadyForDispatch", "NonPS Thread Ready For Dispatch on Slice0 Subslice1",
                "The percentage of time in which non-PS thread is ready for dispatch on slice0 subslice1 thread dispatcher",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "PSThread00ReadyForDispatch", "PS Thread Ready For Dispatch on Slice0 Subslice0",
                "The percentage of time in which PS thread is ready for dispatch on slice0 subslice0 thread dispatcher",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "NonPSThread00ReadyForDispatch", "NonPS Thread Ready For Dispatch on Slice0 Subslice0",
                "The percentage of time in which non-PS thread is ready for dispatch on slice0 subslice0 thread dispatcher",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x4 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "PSThread02ReadyForDispatch", "PS Thread Ready For Dispatch on Slice0 Subslice2",
                "The percentage of time in which PS thread is ready for dispatch on slice0 subslice2 thread dispatcher",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xcc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x4 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "NonPSThread02ReadyForDispatch", "NonPS Thread Ready For Dispatch on Slice0 Subslice2",
                "The percentage of time in which non-PS thread is ready for dispatch on slice0 subslice2 thread dispatcher",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x150" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x2 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "PSThread01ReadyForDispatch", "PS Thread Ready For Dispatch on Slice0 Subslice1",
                "The percentage of time in which PS thread is ready for dispatch on slice0 subslice1 thread dispatcher",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x158" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GTRequestQueueFull", "SQ is full",
            "The percentage of time when SQ is filled above a threshold (usually 48 entries)",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x000000a0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12120000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12320000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12520000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x002f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x022f3000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a4c0015, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c0d8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e0da000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x000d8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x020da000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x040da000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x060d2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x100f03a0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c0ff000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e0f0095, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x062c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x082c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a2c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c2d8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e2d4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x062d4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02108000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0410c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02118000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0411c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02121880, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x041219b5, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00120000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02134000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04135000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c308000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e304000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06304000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c318000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e314000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06314000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c321a80, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e320033, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06320031, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00320000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c334000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e331000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06331000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e508000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00508000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02504000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e518000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00518000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02514000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e521880, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00521a80, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02520033, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e534000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00534000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02531000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1190ff80, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x57900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x49900800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x37900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x33900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x4b900062, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x59900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x51900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x41900c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x43900003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x53900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x45900040, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2744, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x30800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x00000002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x00007fff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x00009fff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x00000002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x0000efff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2788, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x278c, 0x0000f3ff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2790, 0x00000002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2794, 0x0000fdff, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2798, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x279c, 0x0000fe7f, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00010003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00012011, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00015014, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00051050, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00053052, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00055054, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x91bc, 0xe0500000, REGISTER_TYPE_PM ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_SKL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask, GT_TYPE_GT2 ) )
    {
        aSet = aGroup->AddMetricSet( "TDL_2", "Metric set TDL_2", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, GT_TYPE_GT2 );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuFpuBothActive", "EU Both FPU Pipes Active",
            "The percentage of time in which both EU FPU pipelines were actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x34:0xa9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu0Active", "VS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x38:0xaa" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x60" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu1Active", "VS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsSendActive", "VS Send Pipe Active",
            "The percentage of time in which EU send pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x40:0xac" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu0Active", "PS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x88" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x50:0xb0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsSendActive", "PS Send Pipeline Active",
            "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x54:0xb1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuBothFpuActive", "PS Both FPU Active",
            "The percentage of time in which pixel shaders were processed actively on the both FPUs.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x58:0xb2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xa0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
            "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
            "Sampler/Sampler Input", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
            "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
            "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x100" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of GPU memory bytes written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x108" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
            "The total number of shader memory accesses to L3.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
            "The total number of shader atomic memory accesses.",
            "L3/Data Port/Atomics", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_ATOMICS * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
            "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$SlmBytesRead $SlmBytesWritten $ShaderMemoryAccesses 64 UMUL UADD UADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSubslicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "ShaderBarriers", "Shader Barrier Messages",
            "The total number of shader barrier messages.",
            "EU Array/Barrier", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = "$SubsliceMask 0x2 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "ThreadHeader01ReadyPort0", "Thread Header Ready on Slice0 Subslice1 Port 0",
                "The percentage of time in which thread header is ready on slice0 subslice1 thread dispatcher port 0",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "ThreadHeader00ReadyPort1", "Thread Header Ready on Slice0 Subslice0 Port 1",
                "The percentage of time in which thread header is ready on slice0 subslice0 thread dispatcher port 1",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "ThreadHeader00ReadyPort0", "Thread Header Ready on Slice0 Subslice0 Port 0",
                "The percentage of time in which thread header is ready on slice0 subslice0 thread dispatcher port 0",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x4 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "ThreadHeader02ReadyPort1", "Thread Header Ready on Slice0 Subslice2 Port 1",
                "The percentage of time in which thread header is ready on slice0 subslice2 thread dispatcher port 1",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x4 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "ThreadHeader02ReadyPort0", "Thread Header Ready on Slice0 Subslice2 Port 0",
                "The percentage of time in which thread header is ready on slice0 subslice2 thread dispatcher port 0",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xec" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x188" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x2 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "ThreadHeader01ReadyPort1", "Thread Header Ready on Slice0 Subslice1 Port 1",
                "The percentage of time in which thread header is ready on slice0 subslice1 thread dispatcher port 1",
                "GPU/Thread Dispatcher", (METRIC_GROUP_NAME_ID_GPU * 0x1000000) | (METRIC_GROUP_NAME_ID_TD * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x180" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GTRequestQueueFull", "SQ is full",
            "The percentage of time when SQ is filled above a threshold (usually 48 entries)",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x000000a0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12124d60, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12322e60, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12524d60, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x022f3000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a4c0014, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x000d8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x020da000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x040da000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x060d2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c0fe000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e0f0097, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x082c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a2c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x002d8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x062d4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0410c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0411c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04121fb7, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00120000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04135000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00308000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06304000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00318000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06314000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00321b80, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0632003f, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00334000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06331000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0250c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0251c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02521fb7, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00520000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02535000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1190fc00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x37900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x51900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x41900800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x43900063, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x53900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x45900040, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x33900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2744, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE558, 0x00010003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE658, 0x00012011, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE758, 0x00015014, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE45c, 0x00051050, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE55c, 0x00053052, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xE65c, 0x00055054, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x91bc, 0xe0500000, REGISTER_TYPE_PM ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_SKL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask, GT_TYPE_GT2 ) )
    {
        aSet = aGroup->AddMetricSet( "ComputeExtra", "Compute Metrics Extra Gen9", API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, GT_TYPE_GT2 );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "Fpu1Active", "EU FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "Fpu1ActiveAdjusted", "EU FPU1 Pipe Active including Ext Math",
            "The percentage of time in which EU FPU1 pipeline was actively processing including Extended Math processing",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc dw@0xf8 FADD dw@0xf4 FADD 8 FMUL" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8 qw@0x1a0 FADD qw@0x198 FADD 8 FMUL" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Fpu1Active $Self FADD 100 FMUL $EuCoresTotalCount FDIV $GpuCoreClocks FDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x121203e0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x123203e0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x125203e0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x022f4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a4c0040, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x040da000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x060d2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e0f006c, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c2c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x042d8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06104000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06114000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06120033, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00120000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06131000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04308000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04318000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04321980, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00320000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04334000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04504000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04514000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04520033, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00520000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04531000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1190e000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x37900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x53900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x43900c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x45900002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x33900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe458, 0x00001000, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe558, 0x00003002, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe658, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe758, 0x00011010, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe45c, 0x00050012, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe55c, 0x00052051, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe65c, 0x00000008, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2744, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_SKL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask, GT_TYPE_GT2 ) )
    {
        aSet = aGroup->AddMetricSet( "VMEPipe", "Media Vme Pipe Gen9", API_TYPE_IOSTREAM,
           GPU_MEDIA, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, GT_TYPE_GT2 );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuFpuBothActive", "EU Both FPU Pipes Active",
            "The percentage of time in which both EU FPU pipelines were actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x34:0xa9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
            "The percentage of time in which hardware threads occupied EUs.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "8 rd40@0x38:0xaa FMUL $EuThreadsCount FDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "8 qw@0x60 FMUL $EuThreadsCount FDIV" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VMEBusy", "VME Busy",
            "The percentage of time in which VME (IME or CRE) was actively processing data.",
            "VME Pipe", (METRIC_GROUP_NAME_ID_VME_PIPE * 0x1000000), USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_BATCH|USAGE_FLAG_TIER_2, API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0 dw@0xcc FADD 2 FDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130 qw@0x148 FADD 2 FDIV" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x141a5800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x161a00c0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12180240, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14180002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x143a5800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x163a00c0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x12380240, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x14380002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x002f1000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x022f8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x042f3000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x004c4000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a4c1500, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x000d2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x060d8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x080da000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a0da000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c0da000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c0f0400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e0f9500, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x100f002a, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x002c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0e2c8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x162c0a00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a2dc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c2dc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04193000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x081a28c1, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x001a0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00133000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0613c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0813f000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00172000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06178000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0817a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x00180037, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06180940, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08180000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x02180000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04183000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06393000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c3a28c1, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x003a0000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a33f000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c33f000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a37a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0c37a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0a380977, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x08380000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x04380000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x06383000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x119000ff, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x51900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x41900040, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x55900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x45900800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x47901000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x57900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x49900844, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x37900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x33900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x30800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x00100030, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000fff9, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x00000002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x0000fffc, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x00000002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x0000fff3, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2788, 0x00100180, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x278c, 0x0000ffcf, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2790, 0x00000002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2794, 0x0000ffcf, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2798, 0x00000002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x279c, 0x0000ff3f, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe558, 0x00008003, REGISTER_TYPE_FLEX ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_SKL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask, GT_TYPE_GT2 ) )
    {
        aSet = aGroup->AddMetricSet( "GpuBusyness", "Gpu Rings Busyness", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE|GPU_MEDIA|GPU_GENERIC, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, GT_TYPE_GT2 );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RenderBusy", "Render Ring Busy",
            "The percentage of time when render command streamer was busy.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "Vdbox0Busy", "Vdbox0 Ring Busy",
            "The percentage of time when Vdbox0 command streamer was busy.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VeboxBusy", "Vebox Ring Busy",
            "The percentage of time when vebox command streamer was busy.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "BlitterBusy", "Blitter Ring Busy",
            "The percentage of time when blitter command streamer was busy.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AnyRingBusy", "AnyRingBusy",
            "The percentage of time when any command streamer was busy.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x13805800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x05962c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x19950016, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x21c05800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x07800035, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11800000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1d810400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x07960025, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x21960000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0b964000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1b930062, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x17948000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1b940008, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x05950075, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1d950000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x07e54000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x09924000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x05982000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x19908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1b904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1d908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1f908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x09978000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0bc000a5, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11c00000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x05c00000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0bc54000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x37900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x53900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x43900c60, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x45900040, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x33900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x10800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x00078000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x00000fff, REGISTER_TYPE_OA ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_SKL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask, GT_TYPE_GT2 ) )
    {
        aSet = aGroup->AddMetricSet( "FfBottlenecks", "FF Bottlenecks", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, GT_TYPE_GT2 );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has been processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x28" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x38" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "RasterizedPixels", "Rasterized Pixels",
            "The total number of rasterized pixels.",
            "3D Pipe/Rasterizer", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
            "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x30:0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x50" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuFpuBothActive", "EU Both FPU Pipes Active",
            "The percentage of time in which both EU FPU pipelines were actively processing.",
            "EU Array/Pipes", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x34:0xa9" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
            "The percentage of time in which hardware threads occupied EUs.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "8 rd40@0x54:0xb1 FMUL $EuThreadsCount FDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "8 qw@0x98 FMUL $EuThreadsCount FDIV" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu0Active", "VS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x38:0xaa" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x60" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsFpu1Active", "VS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a vertex shader instruction.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu0Active", "PS FPU0 Pipe Active",
            "The percentage of time in which EU FPU0 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x44:0xad" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x78" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsFpu1Active", "PS FPU1 Pipe Active",
            "The percentage of time in which EU FPU1 pipeline was actively processing a pixel shader instruction.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "rd40@0x48:0xae" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x80" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 40" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsClBypass", "VS is sending vertices to CL",
            "The percentage of time in which VS is sending vertices to CL bypassing other pipeline stages.",
            "3D Pipe/Vertex Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW|USAGE_FLAG_TIER_3, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0 dw@0xd0 FADD 2 FDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130 qw@0x150 FADD 2 FDIV" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsBottleneck", "HS Bottleneck",
            "The percentage of time in which hull shader pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Hull Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 3, 9, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xcc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsBottleneck", "DS Bottleneck",
            "The percentage of time in which domain shader pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Domain Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc4 dw@0xd4 FADD 2 FDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138 qw@0x158 FADD 2 FDIV" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "TeBottleneck", "TE Bottleneck",
            "The percentage of time in which tesselation pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Geometry Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8 dw@0xd8 FADD 2 FDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140 qw@0x160 FADD 2 FDIV" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsBottleneck", "GS Bottleneck",
            "The percentage of time in which geometry shader pipeline stage was slowing down the 3D pipeline.",
            "3D Pipe/Geometry Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xdc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x168" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11850019, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11860007, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x19867c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x01870000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x15880000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x01898000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0b898000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0d890c00, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0d808000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x118a8000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1b8a2000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1d8a0003, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1f810002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0982c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0d824000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x05833000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x07831000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0d848000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0d850080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x01850000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x09860080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0d860080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x07870c80, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0b870c80, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x01880032, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0b888032, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11880000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x07888000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1d930010, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1d950013, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0de58000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x05924000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0b928000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0d92c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0f92c000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11928000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x01981000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x07984000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0998a000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0b985000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x0d982000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x13904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x21904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x23904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x25904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x27904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x29904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x2b904000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x2d908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x51900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x41900020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x55900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x45900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x47900400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x57900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x49900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x37900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x33900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe458, 0x00005004, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe558, 0x00010003, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe658, 0x00000011, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe758, 0x00051050, REGISTER_TYPE_FLEX ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0xe55c, 0x00000008, REGISTER_TYPE_FLEX ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_SKL;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask, GT_TYPE_GT2 ) )
    {
        aSet = aGroup->AddMetricSet( "TestOa", "MDAPI testing set Gen9", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 672, OA_REPORT_TYPE_256B_A45_NOA16, platformMask, GT_TYPE_GT2 );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GPAV", 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x00" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "NS_TIME" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuCoreClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = "";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Counter0", "TestCounter0",
                "HW test counter 0. Factor: 0.0",
                "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Counter1", "TestCounter1",
                "HW test counter 1. Factor: 1.0",
                "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Counter2", "TestCounter2",
                "HW test counter 2. Factor: 1.0",
                "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Counter3", "TestCounter3",
                "HW test counter 3. Factor: 0.5",
                "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xcc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Counter4", "TestCounter4",
                "HW test counter 4. Factor: 0.333",
                "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x150" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Counter5", "TestCounter5",
                "HW test counter 5. Factor: 0.333",
                "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x158" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Counter6", "TestCounter6",
                "HW test counter 6. Factor: 0.166",
                "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x160" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Counter7", "TestCounter7",
                "HW test counter 7. Factor: 0.666",
                "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xdc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x168" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Counter8", "TestCounter8",
                "HW test counter 8. Should be equal to 1.",
                "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last GPU core (unslice) frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency",
            "The last GPU Execution Unit slice frequency in the measurement.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" ));
        }

        aInformation = aSet->AddInformation( "ContextId", "Context ID",
            "The context tag in which report has been taken.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_CONTEXT_ID_TAG, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x08 0xfffff AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed",
            "The flag indicating that GPU core frequency has changed.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x204" ));
        }

        aInformation = aSet->AddInformation( "QuerySplitOccurred", "Query Split Occurred",
            "The flag indicating that query has been split during execution on the GPU.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x200" ));
        }

        aInformation = aSet->AddInformation( "ReportId", "Query report id",
            "Query report identification number.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x210" ));
        }

        aInformation = aSet->AddInformation( "ReportsCount", "Query reports count",
            "The number of available query reports.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x214" ));
        }

        aInformation = aSet->AddInformation( "OverrunOccured", "Query Overrun Occurred",
            "The flag indicating that Oa buffer has been overran.",
            "Exception", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_FLAG, NULL, NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "dw@0x1cc" ));
        }

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11810000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x07810016, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1f810000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1d810000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1b930040, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x07e54000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x1f908000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x11900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x37900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x53900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x45900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9888, 0x33900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x00000004, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x00000003, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x00000007, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2788, 0x00100002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x278c, 0x0000fff7, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2790, 0x00100002, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2794, 0x0000ffcf, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2798, 0x00100082, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x279c, 0x0000ffef, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a0, 0x001000c2, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a4, 0x0000ffe7, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a8, 0x00100001, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27ac, 0x0000ffe7, REGISTER_TYPE_OA ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    MD_LOG_EXIT();
    return CC_OK;

  exception:
    MD_LOG_EXIT();
    return CC_ERROR_NO_MEMORY;
}
#endif
