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

    File Name:  md_main_HSW.cpp

    Abstract:   C++ automated generated file to stack metrics meta data

\*****************************************************************************/

#include "md_per_platform_preamble.h"




#if ((!defined(MD_INCLUDE_HSW_METRICS) && MD_INCLUDE_ALL_METRICS) || MD_INCLUDE_HSW_METRICS)
TCompletionCode CreateObjectTreeHSW_OA( CConcurrentGroup* aGroup )
{
    MD_LOG_ENTER();
    MD_CHECK_PTR_RET(g_MetricsDevice, CC_ERROR_GENERAL);
    MD_CHECK_PTR_RET(aGroup, CC_ERROR_INVALID_PARAMETER);

    CMetricSet*       aSet         = NULL;
    CMetric*          aMetric      = NULL;
    CInformation*     aInformation = NULL;
    const char*       availabilityEquation = NULL;
    uint32_t          platformMask = 0;
  
    platformMask = PLATFORM_HSW;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "RenderBasic", "Render Metrics Basic Gen7.5", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER, 256, 536, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
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
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1c0" ));
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
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x20" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x34" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x48" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x80" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x70" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x84" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x5c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xa8" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has being processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xb0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x150" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x10" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsEuActive", "VS EU Active",
            "The percentage of time in which vertex shaders were processed actively on the EUs.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x14" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsEuActivePerThread", "VS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which vertex shaders were processed actively on the EUs.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x14" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $VsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsEuStallPerThread", "VS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which vertex shaders were stalled on the EUs.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x18" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $VsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsEuStall", "VS EU Stall",
            "The percentage of time in which vertex shaders were stalled on the EUs.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x18" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsEuActive", "HS EU Active",
            "The percentage of time in which hull shaders were processed actively on the EUs.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x28" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsEuActivePerThread", "HS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which hull shaders were processed actively on the EUs.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x28" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $HsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsEuStallPerThread", "HS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which hull shaders were stalled on the EUs.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x2c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $HsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsEuStall", "HS EU Stall",
            "The percentage of time in which hull shaders were stalled on the EUs.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x2c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsEuActive", "DS EU Active",
            "The percentage of time in which domain shaders were processed actively on the EUs.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x3c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsEuActivePerThread", "DS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which domain shaders were processed actively on the EUs.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x3c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $DsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsEuStallPerThread", "DS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which domain shaders were stalled on the EUs.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x40" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $DsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsEuStall", "DS EU Stall",
            "The percentage of time in which domain shaders were stalled on the EUs.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x40" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsEuActive", "GS EU Active",
            "The percentage of time in which geometry shaders were processed actively on the EUs.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x64" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsEuActivePerThread", "GS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which geometry shaders were processed actively on the EUs.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x64" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $GsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsEuStallPerThread", "GS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which geometry shaders were stalled on the EUs.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x68" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $GsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsEuStall", "GS EU Stall",
            "The percentage of time in which geometry shaders were stalled on the EUs.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x68" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsEuActive", "CS EU Active",
            "The percentage of time in which compute shaders were processed actively on the EUs.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x50" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsEuActivePerThread", "CS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which compute shaders were processed actively on the EUs.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x50" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $CsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsEuStallPerThread", "CS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which compute shaders were stalled on the EUs.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x54" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $CsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsEuStall", "CS EU Stall",
            "The percentage of time in which compute shaders were stalled on the EUs.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x54" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuActive", "PS EU Active",
            "The percentage of time in which pixel shaders were processed actively on the EUs.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x78" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuActivePerThread", "PS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which pixel shaders were processed actively on the EUs.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x78" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $PsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuStallPerThread", "PS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which pixel shaders were stalled on the EUs.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x7c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $PsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuStall", "PS EU Stall",
            "The percentage of time in which pixel shaders were stalled on the EUs.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x7c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = "$SubsliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler0Busy", "Sampler 0 Busy",
                "The percentage of time in which sampler 0 was busy.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x170" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x2 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler1Busy", "Sampler 1 Busy",
                "The percentage of time in which sampler 1 was busy.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x178" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplersBusy", "Samplers Busy",
            "The percentage of time in which samplers were busy.",
            "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Sampler0Busy $Sampler1Busy UADD $GpuCoreClocks FDIV 2 FDIV 100 FMUL" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = "$SubsliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler0Bottleneck", "Sampler 0 Bottleneck",
                "The percentage of time in which sampler 0 was bottlenecks.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x180" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x2 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler1Bottleneck", "Sampler 1 Bottleneck",
                "The percentage of time in which sampler 1 was bottlenecks.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xcc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x188" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler0Texels", "Sampler 0 Texels LOD0",
                "The total number of texels lookups in LOD0 in sampler 0 unit.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x2 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler1Texels", "Sampler 1 Texels LOD0",
                "The total number of texels lookups in LOD0 in sampler 1 unit.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels LOD0",
            "The total number of texels lookups in LOD0 in all sampler units.",
            "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$Sampler0Texels $$Sampler1Texels UADD $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "L3SamplerThroughput", "L3 Sampler Throughput",
            "The total number of GPU memory bytes transferred between samplers and L3 caches.",
            "L3/Sampler", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd8 dw@0xdc UADD 2 UMUL" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0 qw@0x1a8 UADD 2 UMUL" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $EuSlicesTotalCount UMUL 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AlphaTestFails", "Alpha Test Fails",
            "The total number of pixels dropped on post-PS alpha test.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PostPsStencilTestFails", "Late Stencil Test Fails",
            "The total number of pixels dropped on post-PS stencil test.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PostPsDepthTestFails", "Late Depth Test Fails",
            "The total number of pixels dropped on post-PS depth test.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $SamplesKilledInPs USUB" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xac" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1d8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $EuSlicesTotalCount 4 UMUL UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiVfThroughput", "GTI Fixed Pipe Throughput",
            "The total number of GPU memory bytes transferred between 3D Pipeline (Command Dispatch, Input Assembly and Stream Output) and GTI.",
            "GTI/3D Pipe", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000), USAGE_FLAG_TIER_2|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1b8" ));
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
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1b0" ));
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
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xec" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1c8" ));
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
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1d0" ));
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
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1e0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 128 UMUL" ));
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
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1e8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 32 UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "LlcAccesses", "LLC GPU Accesses",
            "The total number of LLC cache lookups done from the GPU (64b reads, 32B writes).",
            "LLC", (METRIC_GROUP_NAME_ID_LLC * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f0" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "LlcHits", "LLC GPU Hits",
            "The total number of successful LLC cache lookups done from the GPU.",
            "LLC", (METRIC_GROUP_NAME_ID_LLC * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f8" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "LlcGpuThroughput", "LLC GPU Throughput",
            "The total number of GPU memory bytes transferred between GPU and LLC.",
            "LLC", (METRIC_GROUP_NAME_ID_LLC * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f0 qw@0x1e8 USUB" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 64 UMUL" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DramLlcThroughput", "DRAM LLC Throughput",
            "The approximated amount of GPU memory bytes transferred between LLC and DRAM controller.",
            "LLC", (METRIC_GROUP_NAME_ID_LLC * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$LlcHits $$LlcAccesses FDIV $$LlcGpuThroughput FMUL 1 UMUL" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$MemoryPeakThroghputMB 1048576 UMUL 1000000000 FDIV $GpuTime UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsDuration", "PS Duration",
            "Total Pixel Shader GPU duration.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_DURATION, RESULT_UINT64, "us", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$PsEuActive $EuActive UMUL $VsEuActive $HsEuActive UADD $DsEuActive UADD $CsEuActive UADD $GsEuActive UADD $PsEuActive UADD UDIV $PsEuStall $EuStall UMUL $VsEuStall $HsEuStall UADD $DsEuStall UADD $CsEuStall UADD $GsEuStall UADD $PsEuStall UADD UDIV UADD $GpuTime UMUL $GpuCoreClocks $EuCoresTotalCount UMUL 1000 UMUL UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsDuration", "VS Duration",
            "Total Vertex Shader GPU duration.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_DURATION, RESULT_UINT64, "us", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$VsEuActive $EuActive UMUL $VsEuActive $HsEuActive UADD $DsEuActive UADD $CsEuActive UADD $GsEuActive UADD $PsEuActive UADD UDIV $VsEuStall $EuStall UMUL $VsEuStall $HsEuStall UADD $DsEuStall UADD $CsEuStall UADD $GsEuStall UADD $PsEuStall UADD UDIV UADD $GpuTime UMUL $GpuCoreClocks $EuCoresTotalCount UMUL 1000 UMUL UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsDuration", "GS Duration",
            "Total Geometry Shader GPU duration.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_DURATION, RESULT_UINT64, "us", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GsEuActive $EuActive UMUL $VsEuActive $HsEuActive UADD $DsEuActive UADD $CsEuActive UADD $GsEuActive UADD $PsEuActive UADD UDIV $GsEuStall $EuStall UMUL $VsEuStall $HsEuStall UADD $DsEuStall UADD $CsEuStall UADD $GsEuStall UADD $PsEuStall UADD UDIV UADD $GpuTime UMUL $GpuCoreClocks $EuCoresTotalCount UMUL 1000 UMUL UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsDuration", "DS Duration",
            "Total Domain Shader GPU duration.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_DURATION, RESULT_UINT64, "us", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$DsEuActive $EuActive UMUL $VsEuActive $HsEuActive UADD $DsEuActive UADD $CsEuActive UADD $GsEuActive UADD $PsEuActive UADD UDIV $DsEuStall $EuStall UMUL $VsEuStall $HsEuStall UADD $DsEuStall UADD $CsEuStall UADD $GsEuStall UADD $PsEuStall UADD UDIV UADD $GpuTime UMUL $GpuCoreClocks $EuCoresTotalCount UMUL 1000 UMUL UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsDuration", "HS Duration",
            "Total Hull Shader GPU duration.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_DURATION, RESULT_UINT64, "us", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$HsEuActive $EuActive UMUL $VsEuActive $HsEuActive UADD $DsEuActive UADD $CsEuActive UADD $GsEuActive UADD $PsEuActive UADD UDIV $HsEuStall $EuStall UMUL $VsEuStall $HsEuStall UADD $DsEuStall UADD $CsEuStall UADD $GsEuStall UADD $PsEuStall UADD UDIV UADD $GpuTime UMUL $GpuCoreClocks $EuCoresTotalCount UMUL 1000 UMUL UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsDuration", "CS Duration",
            "Total Compute Shader GPU duration.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_DURATION, RESULT_UINT64, "us", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$CsEuActive $EuActive UMUL $VsEuActive $HsEuActive UADD $DsEuActive UADD $CsEuActive UADD $GsEuActive UADD $PsEuActive UADD UDIV $CsEuStall $EuStall UMUL $VsEuStall $HsEuStall UADD $DsEuStall UADD $CsEuStall UADD $GsEuStall UADD $PsEuStall UADD UDIV UADD $GpuTime UMUL $GpuCoreClocks $EuCoresTotalCount UMUL 1000 UMUL UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerBottleneck", "Sampler Bottleneck",
            "The percentage of time in which samplers were bottlenecks.",
            "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_INDICATE|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$Sampler0Bottleneck $$Sampler1Bottleneck FMAX" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuIdle", "EU Idle",
            "The percentage of time in which the Execution Units were idle.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "100 $$EuActive $$EuStall FADD FSUB" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x168" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last core frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 16 >> 0x3 AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "Core Frequency Changed",
            "The flag indicating that core frequency has changed.",
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

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x253A4, 0x01600000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25440, 0x00100000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25128, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2691C, 0x00000800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26AA0, 0x01500000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26B9C, 0x00006000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2791C, 0x00000800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27AA0, 0x01500000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27B9C, 0x00006000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2641C, 0x00000400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25380, 0x00000010, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2538C, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25384, 0x0800AAAA, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25400, 0x00000004, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2540C, 0x06029000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25410, 0x00000002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25404, 0x5C30FFFF, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25100, 0x00000016, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25110, 0x00000400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25104, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26804, 0x00001211, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26884, 0x00000100, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26900, 0x00000002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26908, 0x00700000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26904, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26984, 0x00001022, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26A04, 0x00000011, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26A80, 0x00000006, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26A88, 0x00000C02, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26A84, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26B04, 0x00001000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26B80, 0x00000002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26B8C, 0x00000007, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26B84, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27804, 0x00004844, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27884, 0x00000400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27900, 0x00000002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27908, 0x0E000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27904, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27984, 0x00004088, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27A04, 0x00000044, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27A80, 0x00000006, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27A88, 0x00018040, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27A84, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27B04, 0x00004000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27B80, 0x00000002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27B8C, 0x000000E0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27B84, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26104, 0x00002222, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26184, 0x0C006666, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26284, 0x04000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26304, 0x04000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26400, 0x00000002, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26410, 0x000000A0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26404, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25420, 0x04108020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25424, 0x1284A420, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2541C, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25428, 0x00042049, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x91bc, 0xe0400000, REGISTER_TYPE_PM ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x91c4, 0xe4500000, REGISTER_TYPE_PM ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_HSW;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "ComputeBasic", "Compute Metrics Basic Gen7.5", API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 536, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId(NULL, 0, 0x40000000, 0x80000203, 0, 0,
            "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0) );
  
        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuTime", "GPU Time Elapsed",
            "Time elapsed on the GPU during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
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
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1c0" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
            "Average GPU Core Frequency in the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $GpuTime UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GpuBusy", "GPU Busy",
            "The percentage of time in which the GPU has being processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xb0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x150" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x20" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x34" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x48" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x80" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x70" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x84" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x5c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xa8" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x10" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsEuActive", "VS EU Active",
            "The percentage of time in which vertex shaders were processed actively on the EUs.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x14" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsEuActivePerThread", "VS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which vertex shaders were processed actively on the EUs.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x14" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $VsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsEuStall", "VS EU Stall",
            "The percentage of time in which vertex shaders were stalled on the EUs.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x18" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsEuStallPerThread", "VS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which vertex shaders were stalled on the EUs.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x18" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $VsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuActive", "PS EU Active",
            "The percentage of time in which pixel shaders were processed actively on the EUs.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x78" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsEuActive", "HS EU Active",
            "The percentage of time in which hull shaders were processed actively on the EUs.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x28" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsEuActivePerThread", "HS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which hull shaders were processed actively on the EUs.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x28" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $HsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsEuStall", "HS EU Stall",
            "The percentage of time in which hull shaders were stalled on the EUs.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x2c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsEuStallPerThread", "HS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which hull shaders were stalled on the EUs.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x2c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $HsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsEuActive", "DS EU Active",
            "The percentage of time in which domain shaders were processed actively on the EUs.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x3c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsEuActivePerThread", "DS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which domain shaders were processed actively on the EUs.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x3c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $DsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsEuStall", "DS EU Stall",
            "The percentage of time in which domain shaders were stalled on the EUs.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x40" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsEuStallPerThread", "DS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which domain shaders were stalled on the EUs.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x40" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $DsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsEuActive", "GS EU Active",
            "The percentage of time in which geometry shaders were processed actively on the EUs.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x64" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsEuActivePerThread", "GS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which geometry shaders were processed actively on the EUs.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x64" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $GsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsEuStall", "GS EU Stall",
            "The percentage of time in which geometry shaders were stalled on the EUs.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x68" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsEuStallPerThread", "GS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which geometry shaders were stalled on the EUs.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x68" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $GsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsEuActive", "CS EU Active",
            "The percentage of time in which compute shaders were processed actively on the EUs.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x50" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsEuActivePerThread", "CS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which compute shaders were processed actively on the EUs.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x50" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $CsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsEuStall", "CS EU Stall",
            "The percentage of time in which compute shaders were stalled on the EUs.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x54" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsEuStallPerThread", "CS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which compute shaders were stalled on the EUs.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x54" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $CsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuActivePerThread", "PS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which pixel shaders were processed actively on the EUs.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x78" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $PsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuStall", "PS EU Stall",
            "The percentage of time in which pixel shaders were stalled on the EUs.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x7c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuStallPerThread", "PS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which pixel shaders were stalled on the EUs.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x7c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $PsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AlphaTestFails", "Alpha Test Fails",
            "The total number of pixels dropped on post-PS alpha test.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PostPsStencilTestFails", "Late Stencil Test Fails",
            "The total number of pixels dropped on post-PS stencil test.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PostPsDepthTestFails", "Late Depth Test Fails",
            "The total number of pixels dropped on post-PS depth test.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $SamplesKilledInPs USUB" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xac" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "TypedBytesRead", "Typed Bytes Read",
            "The total number of typed memory bytes read via Data Port.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd0 dw@0xd4 UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190 qw@0x198 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $EuSlicesTotalCount 64 UMUL UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "TypedBytesWritten", "Typed Bytes Written",
            "The total number of untyped memory bytes written via Data Port.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd8 dw@0xdc UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0 qw@0x1a8 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $EuSlicesTotalCount 64 UMUL UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "TypedAtomics", "Typed Atomics",
            "The total number of typed atomics.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe0 dw@0xe4 UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1b0 qw@0x1b8 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $EuSlicesTotalCount UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "UntypedBytesRead", "Untyped Bytes Read",
            "The total number of typed memory bytes read via Data Port.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0 dw@0xc4 UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x170 qw@0x178 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $EuSlicesTotalCount 64 UMUL UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "UntypedBytesWritten", "Untyped Writes",
            "The total number of untyped memory bytes written via Data Port.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8 dw@0xcc UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x180 qw@0x188 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $EuSlicesTotalCount 64 UMUL UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesRead", "SLM Bytes Read",
            "The total number of GPU memory bytes read from shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8 dw@0xfc UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1e0 qw@0x1e8 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $EuSlicesTotalCount 64 UMUL UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SlmBytesWritten", "SLM Bytes Written",
            "The total number of byten written into shared local memory.",
            "L3/Data Port/SLM", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000) | (METRIC_GROUP_NAME_ID_SLM * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0 dw@0xf4 UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1d0 qw@0x1d8 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $EuSlicesTotalCount 64 UMUL UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuSlicesTotalCount UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "LlcAccesses", "LLC GPU Accesses",
            "The total number of LLC cache lookups done from the GPU (64b reads, 32B writes).",
            "LLC", (METRIC_GROUP_NAME_ID_LLC * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f0" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "LlcHits", "LLC GPU Hits",
            "The total number of successful LLC cache lookups done from the GPU.",
            "LLC", (METRIC_GROUP_NAME_ID_LLC * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f8" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x168" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last core frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 16 >> 0x3 AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "Core Frequency Changed",
            "The flag indicating that core frequency has changed.",
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

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x253A4, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2681C, 0x01F00800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26820, 0x00001000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2781C, 0x01F00800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26520, 0x00000007, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x265A0, 0x00000007, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25380, 0x00000010, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2538C, 0x00300000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25384, 0xAA8AAAAA, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25404, 0xFFFFFFFF, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26800, 0x00004202, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26808, 0x00605817, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2680C, 0x10001005, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26804, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27800, 0x00000102, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27808, 0x0C0701E0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780C, 0x000200A0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27804, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26484, 0x44000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26704, 0x44000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26500, 0x00000006, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26510, 0x00000001, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26504, 0x88000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26580, 0x00000006, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26590, 0x00000020, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26584, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26104, 0x55822222, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26184, 0xAA866666, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25420, 0x08320C83, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25424, 0x06820C83, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2541C, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25428, 0x00000C03, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2718, 0xAAAAAAAA, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x271C, 0xAAAAAAAA, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2728, 0xAAAAAAAA, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x272C, 0xAAAAAAAA, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2744, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2748, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x274C, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2750, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2754, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2758, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x275C, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x91bc, 0xe0400000, REGISTER_TYPE_PM ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x91c4, 0xe4500000, REGISTER_TYPE_PM ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_HSW;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "ComputeExtended", "Compute Metrics Extended Gen7.5", API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_COMPUTE, 256, 536, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
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
        aMetric = aSet->AddMetric( "GpuClocks", "GPU Core Clocks",
            "The total number of GPU core clocks elapsed during the measurement.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xdc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x5c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xa8" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuUntypedReads0", "EuUntypedReads0",
            "The subslice 0 EU Untyped Reads subslice 0.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x170" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuTypedReads0", "EuTypedReads0",
            "The subslice 0 EU Typed Reads subslice 0.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x180" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuUntypedWrites0", "EuUntypedWrites0",
            "The subslice 0 EU Untyped Writes subslice 0.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x178" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuTypedWrites0", "EuTypedWrites0",
            "The subslice 0 EU Typed Writes subslice 0.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xcc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x188" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuUntypedAtomics0", "EuUntypedAtomics0",
            "The subslice 0 EU Untyped Atomics subslice 0.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuTypedAtomics0", "EuTypedAtomics0",
            "The subslice 0 EU Typed Atomics subslice 0.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuUrbAtomics0", "EuUrbAtomics0",
            "The subslice 0 EU URB Atomics subslice 0.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "TypedReads0", "Typed Reads 0",
            "The subslice 0 typed reads.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1c0" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "TypedWrites0", "Typed Writes 0",
            "The subslice 0 typed writes.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1b0" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "UntypedReads0", "Untyped Reads 0",
            "The subslice 0 untyped reads (including SLM reads).",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xec" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1c8" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "UntypedWrites0", "Untyped Writes 0",
            "The subslice 0 untyped writes (including SLM writes).",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1b8" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "TypedAtomics0", "Typed Atomics 0",
            "The subslice 0 typed atomics.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1d0" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "TypedReadsPerCacheLine", "TypedReadsPerCacheLine",
            "The ratio of EU typed read requests to L3 cache line reads.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_RATIO, RESULT_FLOAT, "EU sends to L3 cache lines", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$EuTypedReads0 $$TypedReads0 FDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "TypedWritesPerCacheLine", "TypedWritesPerCacheLine",
            "The ratio of EU typed write requests to L3 cache line writes.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_RATIO, RESULT_FLOAT, "EU sends to L3 cache lines", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$EuTypedWrites0 $$TypedWrites0 FDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "UntypedReadsPerCacheLine", "UntypedReadsPerCacheLine",
            "The ratio of EU untyped read requests to L3 cache line reads.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_RATIO, RESULT_FLOAT, "EU sends to L3 cache lines", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$EuUntypedReads0 $$UntypedReads0 FDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "UntypedWritesPerCacheLine", "UntypedWritesPerCacheLine",
            "The ratio of EU untyped write requests to L3 cache line writes.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_RATIO, RESULT_FLOAT, "EU sends to L3 cache lines", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$EuUntypedWrites0 $$UntypedWrites0 FDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "TypedAtomicsPerCacheLine", "TypedAtomicsPerCacheLine",
            "The ratio of EU typed atomics requests to L3 cache line writes.",
            "L3/Data Port", (METRIC_GROUP_NAME_ID_L3 * 0x1000000) | (METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_RATIO, RESULT_FLOAT, "EU sends to L3 cache lines", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$EuTypedAtomics0 $$TypedAtomics0 FDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "LlcAccesses", "LLC GPU Accesses",
            "The total number of LLC cache lookups done from the GPU (64b reads, 32B writes).",
            "LLC", (METRIC_GROUP_NAME_ID_LLC * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f0" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "LlcHits", "LLC GPU Hits",
            "The total number of successful LLC cache lookups done from the GPU.",
            "LLC", (METRIC_GROUP_NAME_ID_LLC * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f8" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x168" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last core frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 16 >> 0x3 AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "Core Frequency Changed",
            "The flag indicating that core frequency has changed.",
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

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2681C, 0x3EB00800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26820, 0x00900000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25384, 0x02AAAAAA, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25404, 0x03FFFFFF, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26800, 0x00142284, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26808, 0x0E629062, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2680C, 0x3F6F55CB, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26810, 0x00000014, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26804, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26104, 0x02AAAAAA, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26184, 0x02AAAAAA, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25420, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25424, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2541C, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25428, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x0007fe2a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000ff00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x0007fe6a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x0000ff00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x0007fe92, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x0000ff00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2788, 0x0007fea2, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x278c, 0x0000ff00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2790, 0x0007fe32, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2794, 0x0000ff00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2798, 0x0007fe9a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x279c, 0x0000ff00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a0, 0x0007ff23, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a4, 0x0000ff00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a8, 0x0007fff3, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27ac, 0x0000fffe, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x91bc, 0xe0400000, REGISTER_TYPE_PM ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x91c4, 0xe4500000, REGISTER_TYPE_PM ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_HSW;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "RenderBalance", "Render Metrics Slice Balance Gen7.5", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER, 256, 536, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
        MD_CHECK_PTR( aSet );
        
        MD_CHECK_CC( aSet->SetApiSpecificId("GT03", 0, 0x40000003, 0x80000207, 0, 3,
            "Intel Performance Counters for GT Set 3", 0, "Intel_Raw_Hardware_Counters_Set_3_Query", 0) );
  
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
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1c0" ));
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
            "The percentage of time in which the GPU has being processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xb0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x150" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x20" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x34" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x48" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x80" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x70" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x84" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x5c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xa8" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x10" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsEuActive", "VS EU Active",
            "The percentage of time in which vertex shaders were processed actively on the EUs.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x14" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsEuActivePerThread", "VS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which vertex shaders were processed actively on the EUs.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x14" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $VsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsEuStall", "VS EU Stall",
            "The percentage of time in which vertex shaders were stalled on the EUs.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x18" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsEuStallPerThread", "VS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which vertex shaders were stalled on the EUs.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x18" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $VsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsEuActive", "HS EU Active",
            "The percentage of time in which hull shaders were processed actively on the EUs.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x28" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsEuActivePerThread", "HS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which hull shaders were processed actively on the EUs.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x28" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $HsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsEuStall", "HS EU Stall",
            "The percentage of time in which hull shaders were stalled on the EUs.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x2c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsEuStallPerThread", "HS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which hull shaders were stalled on the EUs.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x2c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $HsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsEuActive", "DS EU Active",
            "The percentage of time in which domain shaders were processed actively on the EUs.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x3c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsEuActivePerThread", "DS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which domain shaders were processed actively on the EUs.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x3c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $DsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsEuStall", "DS EU Stall",
            "The percentage of time in which domain shaders were stalled on the EUs.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x40" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsEuStallPerThread", "DS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which domain shaders were stalled on the EUs.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x40" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $DsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsEuActive", "GS EU Active",
            "The percentage of time in which geometry shaders were processed actively on the EUs.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x64" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsEuActivePerThread", "GS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which geometry shaders were processed actively on the EUs.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x64" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $GsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsEuStall", "GS EU Stall",
            "The percentage of time in which geometry shaders were stalled on the EUs.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x68" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsEuStallPerThread", "GS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which geometry shaders were stalled on the EUs.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x68" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $GsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsEuActive", "CS EU Active",
            "The percentage of time in which compute shaders were processed actively on the EUs.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x50" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsEuActivePerThread", "CS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which compute shaders were processed actively on the EUs.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x50" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $CsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsEuStall", "CS EU Stall",
            "The percentage of time in which compute shaders were stalled on the EUs.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x54" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsEuStallPerThread", "CS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which compute shaders were stalled on the EUs.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x54" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $CsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuActive", "PS EU Active",
            "The percentage of time in which pixel shaders were processed actively on the EUs.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x78" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuActivePerThread", "PS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which pixel shaders were processed actively on the EUs.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x78" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $PsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuStall", "PS EU Stall",
            "The percentage of time in which pixel shaders were stalled on the EUs.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x7c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuStallPerThread", "PS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which pixel shaders were stalled on the EUs.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x7c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $PsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AlphaTestFails", "Alpha Test Fails",
            "The total number of pixels dropped on post-PS alpha test.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PostPsStencilTestFails", "Late Stencil Test Fails",
            "The total number of pixels dropped on post-PS stencil test.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PostPsDepthTestFails", "Late Depth Test Fails",
            "The total number of pixels dropped on post-PS depth test.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $SamplesKilledInPs USUB" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xac" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesBlended", "Samples Blended",
            "The total number of blended samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4 dw@0xf8 UADD" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1d8 qw@0x1e0 UADD" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = "$SubsliceMask 0x01 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler0Texels", "Sampler 0 Texels",
                "The total number of texels processed by Sampler 0 unit.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x02 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler1Texels", "Sampler 1 Texels",
                "The total number of texels processed by Sampler 1 unit.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x04 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler2Texels", "Sampler 2 Texels",
                "The total number of texels processed by Sampler 2 unit.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x08 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler3Texels", "Sampler 3 Texels",
                "The total number of texels processed by Sampler 3 unit.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xdc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 4 UMUL" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerTexels", "Sampler Texels",
            "The total number of texels read in samplers.",
            "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Sampler0Texels $Sampler1Texels $Sampler2Texels $Sampler3Texels UADD UADD UADD 4 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = "$SubsliceMask 0x01 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler0Busy", "Sampler 0 Busy",
                "The percentage of time in which Sampler 0 has been processing EU requests.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x170" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x02 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler1Busy", "Sampler 1 Busy",
                "The percentage of time in which Sampler 1 has been processing EU requests.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x178" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x04 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler2Busy", "Sampler 2 Busy",
                "The percentage of time in which Sampler 2 has been processing EU requests.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x180" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x08 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler3Busy", "Sampler 3 Busy",
                "The percentage of time in which Sampler 3 has been processing EU requests.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_BATCH|USAGE_FLAG_FRAME|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xcc" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x188" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplersBusy", "Samplers Busy",
            "The average percentage of time in which samplers have being processing EU requests.",
            "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Sampler0Busy $Sampler1Busy $Sampler2Busy $Sampler3Busy UADD UADD UADD $GpuCoreClocks FDIV $SamplersTotalCount FDIV 100 FMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = "$SubsliceMask 0x01 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler0Bottleneck", "Sampler 0 Bottleneck",
                "The percentage of time in which Sampler 0 has been slowing down.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1b0" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x02 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler1Bottleneck", "Sampler 1 Bottleneck",
                "The percentage of time in which Sampler 1 has been slowing down.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe4" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1b8" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x04 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler2Bottleneck", "Sampler 2 Bottleneck",
                "The percentage of time in which Sampler 2 has been slowing down.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xec" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1c8" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x08 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler3Bottleneck", "Sampler 3 Bottleneck",
                "The percentage of time in which Sampler 3 has been slowing down.",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_INDICATE|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1d0" ));
                MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
                MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplerBottleneck", "Sampler Bottleneck",
            "The percentage of time in which samplers were bottlenecks.",
            "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_INDICATE|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Sampler0Bottleneck $Sampler1Bottleneck $Sampler2Bottleneck $Sampler3Bottleneck UADD UADD UADD $GpuCoreClocks FDIV $SamplersTotalCount FDIV 100 FMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "LlcAccesses", "LLC GPU Accesses",
            "The total number of LLC cache lookups done from the GPU (64b reads, 32B writes).",
            "LLC", (METRIC_GROUP_NAME_ID_LLC * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f0" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "LlcHits", "LLC GPU Hits",
            "The total number of successful LLC cache lookups done from the GPU.",
            "LLC", (METRIC_GROUP_NAME_ID_LLC * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f8" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x168" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last core frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 16 >> 0x3 AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "Core Frequency Changed",
            "The flag indicating that core frequency has changed.",
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

        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_HSW;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "MemoryReads", "Memory Reads Distribution Gen7.5", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 536, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
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
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1e8" ));
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
            "The percentage of time in which the GPU has being processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xb0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x150" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x20" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x34" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x48" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x80" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x70" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x84" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x5c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xa8" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x10" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsEuActive", "VS EU Active",
            "The percentage of time in which vertex shaders were processed actively on the EUs.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x14" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsEuActivePerThread", "VS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which vertex shaders were processed actively on the EUs.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x14" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $VsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsEuStall", "VS EU Stall",
            "The percentage of time in which vertex shaders were stalled on the EUs.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x18" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsEuStallPerThread", "VS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which vertex shaders were stalled on the EUs.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x18" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $VsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsEuActive", "HS EU Active",
            "The percentage of time in which hull shaders were processed actively on the EUs.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x28" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsEuActivePerThread", "HS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which hull shaders were processed actively on the EUs.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x28" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $HsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsEuStall", "HS EU Stall",
            "The percentage of time in which hull shaders were stalled on the EUs.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x2c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsEuStallPerThread", "HS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which hull shaders were stalled on the EUs.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x2c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $HsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsEuActive", "DS EU Active",
            "The percentage of time in which domain shaders were processed actively on the EUs.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x3c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsEuActivePerThread", "DS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which domain shaders were processed actively on the EUs.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x3c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $DsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsEuStall", "DS EU Stall",
            "The percentage of time in which domain shaders were stalled on the EUs.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x40" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsEuStallPerThread", "DS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which domain shaders were stalled on the EUs.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x40" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $DsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsEuActive", "GS EU Active",
            "The percentage of time in which geometry shaders were processed actively on the EUs.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x64" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsEuActivePerThread", "GS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which geometry shaders were processed actively on the EUs.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x64" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $GsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsEuStall", "GS EU Stall",
            "The percentage of time in which geometry shaders were stalled on the EUs.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x68" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsEuStallPerThread", "GS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which geometry shaders were stalled on the EUs.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x68" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $GsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsEuActive", "CS EU Active",
            "The percentage of time in which compute shaders were processed actively on the EUs.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x50" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsEuActivePerThread", "CS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which compute shaders were processed actively on the EUs.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x50" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $CsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsEuStall", "CS EU Stall",
            "The percentage of time in which compute shaders were stalled on the EUs.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x54" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsEuStallPerThread", "CS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which compute shaders were stalled on the EUs.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x54" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $CsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuActive", "PS EU Active",
            "The percentage of time in which pixel shaders were processed actively on the EUs.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x78" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuActivePerThread", "PS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which pixel shaders were processed actively on the EUs.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x78" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $PsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuStall", "PS EU Stall",
            "The percentage of time in which pixel shaders were stalled on the EUs.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x7c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuStallPerThread", "PS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which pixel shaders were stalled on the EUs.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x7c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $PsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AlphaTestFails", "Alpha Test Fails",
            "The total number of pixels dropped on post-PS alpha test.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PostPsStencilTestFails", "Late Stencil Test Fails",
            "The total number of pixels dropped on post-PS stencil test.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PostPsDepthTestFails", "Late Depth Test Fails",
            "The total number of pixels dropped on post-PS depth test.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $SamplesKilledInPs USUB" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xac" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiCmdStreamerMemoryReads", "GtiCmdStreamerMemoryReads",
            "The total number of GTI memory reads from Command Streamer.",
            "GTI/3D Pipe/Command Streamer", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000) | (METRIC_GROUP_NAME_ID_RCS * 0x100), USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x170" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiRsMemoryReads", "GtiRsMemoryReads",
            "The total number of GTI memory reads from Resource Streamer.",
            "GTI/3D Pipe/Resource Streamer", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000) | (METRIC_GROUP_NAME_ID_RS * 0x100), USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x180" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiVfMemoryReads", "GtiVfMemoryReads",
            "The total number of GTI memory reads from Vertex Fetch.",
            "GTI/3D Pipe/Vertex Fetch", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000) | (METRIC_GROUP_NAME_ID_VF * 0x100), USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x178" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiRccMemoryReads", "GtiRccMemoryReads",
            "The total number of GTI memory reads from Render Color Cache (Render Color Cache misses).",
            "GTI/Color Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCC * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xcc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x188" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiMscMemoryReads", "GtiMscMemoryReads",
            "The total number of GTI memory reads from Multisampling Color Cache (Multisampling Color Cache misses).",
            "GTI/Color Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCC * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiHiDepthMemoryReads", "GtiHiDepthMemoryReads",
            "The total number of GTI memory reads from Hierarchical Depth Cache.",
            "GTI/Depth Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCZ * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiStcMemoryReads", "GtiStcMemoryReads",
            "The total number of GTI memory reads from Stencil Cache.",
            "GTI/Depth Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCZ * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiRczMemoryReads", "GtiRczMemoryReads",
            "The total number of GTI memory reads from Render Depth Cache.",
            "GTI/Depth Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCZ * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xdc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiL3Reads", "GtiL3Reads",
            "The total number of GTI memory reads from L3 (L3 misses).",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1d0" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiMemoryReads", "GtiMemoryReads",
            "The total number of GTI memory reads (64B each).",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1d8" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "LlcReadAccesses", "LLC GPU Read Accesses",
            "The total number of LLC cache lookups for reads done from the GPU.",
            "LLC", (METRIC_GROUP_NAME_ID_LLC * 0x1000000), USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1e0" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "LlcAccesses", "LLC GPU Accesses",
            "The total number of LLC cache lookups done from the GPU (64b reads, 32B writes).",
            "LLC", (METRIC_GROUP_NAME_ID_LLC * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f0" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "LlcHits", "LLC GPU Hits",
            "The total number of successful LLC cache lookups done from the GPU.",
            "LLC", (METRIC_GROUP_NAME_ID_LLC * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f8" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x168" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last core frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 16 >> 0x3 AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "Core Frequency Changed",
            "The flag indicating that core frequency has changed.",
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

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x253A4, 0x34300000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25440, 0x2D800000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25444, 0x00000008, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25128, 0x0E600000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25380, 0x00000450, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25390, 0x00052C43, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25384, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25400, 0x00006144, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25408, 0x0A418820, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2540C, 0x000820E6, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25404, 0xFF500000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25100, 0x000005D6, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2510C, 0x0EF00000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25104, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25420, 0x02108421, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25424, 0x00008421, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2541C, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25428, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x274c, 0x76543298, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2748, 0x98989898, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2744, 0x000000e4, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x275c, 0x98a98a98, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2758, 0x88888888, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2754, 0x000c5500, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2750, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x0007f81a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000fc00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x0007f82a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x0000fc00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x0007f872, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x0000fc00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2788, 0x0007f8ba, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x278c, 0x0000fc00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2790, 0x0007f87a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2794, 0x0000fc00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2798, 0x0007f8ea, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x279c, 0x0000fc00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a0, 0x0007f8e2, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a4, 0x0000fc00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a8, 0x0007f8f2, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27ac, 0x0000fc00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x91bc, 0xe0400000, REGISTER_TYPE_PM ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x91c4, 0xe4500000, REGISTER_TYPE_PM ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_HSW;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "MemoryWrites", "Memory Writes Distribution Gen7.5", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER|GPU_COMPUTE, 256, 536, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
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
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1e8" ));
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
            "The percentage of time in which the GPU has being processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xb0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x150" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x20" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x34" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x48" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x80" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x70" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x84" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x5c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xa8" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x10" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsEuActive", "VS EU Active",
            "The percentage of time in which vertex shaders were processed actively on the EUs.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x14" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsEuActivePerThread", "VS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which vertex shaders were processed actively on the EUs.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x14" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $VsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsEuStall", "VS EU Stall",
            "The percentage of time in which vertex shaders were stalled on the EUs.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x18" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsEuStallPerThread", "VS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which vertex shaders were stalled on the EUs.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x18" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $VsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsEuActive", "HS EU Active",
            "The percentage of time in which hull shaders were processed actively on the EUs.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x28" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsEuActivePerThread", "HS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which hull shaders were processed actively on the EUs.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x28" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $HsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsEuStall", "HS EU Stall",
            "The percentage of time in which hull shaders were stalled on the EUs.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x2c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsEuStallPerThread", "HS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which hull shaders were stalled on the EUs.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x2c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $HsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsEuActive", "DS EU Active",
            "The percentage of time in which domain shaders were processed actively on the EUs.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x3c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsEuActivePerThread", "DS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which domain shaders were processed actively on the EUs.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x3c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $DsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsEuStall", "DS EU Stall",
            "The percentage of time in which domain shaders were stalled on the EUs.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x40" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsEuStallPerThread", "DS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which domain shaders were stalled on the EUs.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x40" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $DsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsEuActive", "GS EU Active",
            "The percentage of time in which geometry shaders were processed actively on the EUs.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x64" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsEuActivePerThread", "GS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which geometry shaders were processed actively on the EUs.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x64" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $GsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsEuStall", "GS EU Stall",
            "The percentage of time in which geometry shaders were stalled on the EUs.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x68" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsEuStallPerThread", "GS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which geometry shaders were stalled on the EUs.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x68" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $GsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsEuActive", "CS EU Active",
            "The percentage of time in which compute shaders were processed actively on the EUs.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x50" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsEuActivePerThread", "CS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which compute shaders were processed actively on the EUs.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x50" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $CsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsEuStall", "CS EU Stall",
            "The percentage of time in which compute shaders were stalled on the EUs.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x54" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsEuStallPerThread", "CS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which compute shaders were stalled on the EUs.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x54" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $CsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuActive", "PS EU Active",
            "The percentage of time in which pixel shaders were processed actively on the EUs.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x78" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuActivePerThread", "PS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which pixel shaders were processed actively on the EUs.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x78" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $PsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuStall", "PS EU Stall",
            "The percentage of time in which pixel shaders were stalled on the EUs.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x7c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuStallPerThread", "PS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which pixel shaders were stalled on the EUs.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x7c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $PsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AlphaTestFails", "Alpha Test Fails",
            "The total number of pixels dropped on post-PS alpha test.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PostPsStencilTestFails", "Late Stencil Test Fails",
            "The total number of pixels dropped on post-PS stencil test.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PostPsDepthTestFails", "Late Depth Test Fails",
            "The total number of pixels dropped on post-PS depth test.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $SamplesKilledInPs USUB" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xac" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiCmdStreamerMemoryWrites", "GtiCmdStreamerMemoryWrites",
            "The total number of GTI memory writes from Command Streamer.",
            "GTI/3D Pipe/Command Streamer", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000) | (METRIC_GROUP_NAME_ID_RCS * 0x100), USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x170" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiSoMemoryWrites", "GtiSoMemoryWrites",
            "The total number of GTI memory writes from Stream Output.",
            "GTI/3D Pipe/Stream Output", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000) | (METRIC_GROUP_NAME_ID_SO * 0x100), USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xc8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x180" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiRccMemoryWrites", "GtiRccMemoryWrites",
            "The total number of GTI memory writes from Render Color Cache (Render Color Cache invalidations).",
            "GTI/Color Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCC * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xcc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x188" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiMscMemoryWrites", "GtiMscMemoryWrites",
            "The total number of GTI memory writes from Multisampling Color Cache (Multisampling Color Cache invalidations).",
            "GTI/Color Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCC * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x190" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiHizMemoryWrites", "GtiHizMemoryWrites",
            "The total number of GTI memory writes from Hierarchical Depth Cache.",
            "GTI/Depth Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCZ * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x198" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiStcMemoryWrites", "GtiStcMemoryWrites",
            "The total number of GTI memory writes from Stencil Cache.",
            "GTI/Depth Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCZ * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xd8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a0" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiRczMemoryWrites", "GtiRczMemoryWrites",
            "The total number of GTI memory writes from Render Depth Cache.",
            "GTI/Depth Cache", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_RCZ * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xdc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiL3Writes", "GtiL3Writes",
            "The total number of GTI memory writes from L3 (L3 invalidations).",
            "GTI/L3", (METRIC_GROUP_NAME_ID_GTI * 0x1000000) | (METRIC_GROUP_NAME_ID_L3 * 0x10000), USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1d0" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GtiMemoryWrites", "GtiMemoryWrites",
            "The total number of GTI memory writes (64B each).",
            "GTI", (METRIC_GROUP_NAME_ID_GTI * 0x1000000), USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1d8" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "LlcWrAccesses", "LLC GPU Write Accesses",
            "The total number of LLC cache lookups for write done from the GPU (32B writes).",
            "LLC", (METRIC_GROUP_NAME_ID_LLC * 0x1000000), USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1e0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self 2 UMUL" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "LlcAccesses", "LLC GPU Accesses",
            "The total number of LLC cache lookups done from the GPU (64b reads, 32B writes).",
            "LLC", (METRIC_GROUP_NAME_ID_LLC * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f0" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "LlcHits", "LLC GPU Hits",
            "The total number of successful LLC cache lookups done from the GPU.",
            "LLC", (METRIC_GROUP_NAME_ID_LLC * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f8" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "LlcGpuThroughput", "LLC GPU Throughput",
            "The total number of GPU memory bytes transferred between GPU and LLC.",
            "LLC", (METRIC_GROUP_NAME_ID_LLC * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $$LlcWrAccesses USUB 64 UMUL $$LlcWrAccesses 32 UMUL UADD" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DramLlcThroughput", "DRAM LLC Throughput",
            "The approximated amount of GPU memory bytes transferred between LLC and DRAM controller.",
            "LLC", (METRIC_GROUP_NAME_ID_LLC * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$$LlcHits $$LlcAccesses FDIV $$LlcGpuThroughput FMUL 1 UMUL" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "$MemoryPeakThroghputMB 1048576 UMUL 1000000000 FDIV $GpuTime UMUL" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x168" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last core frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 16 >> 0x3 AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "Core Frequency Changed",
            "The flag indicating that core frequency has changed.",
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

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x253A4, 0x34300000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25440, 0x01500000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25444, 0x00000120, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25128, 0x0C200000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25380, 0x00000450, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25390, 0x00052C43, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25384, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25400, 0x00007184, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25408, 0x0A418820, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2540C, 0x000820E6, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25404, 0xFF500000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25100, 0x000005D6, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2510C, 0x1E700000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25104, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25420, 0x02108421, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25424, 0x00008421, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2541C, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25428, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0xf0800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x274c, 0x76543298, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2748, 0x98989898, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2744, 0x000000e4, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x275c, 0xbabababa, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2758, 0x88888888, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2754, 0x000c5500, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2750, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2770, 0x0007f81a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2774, 0x0000fc00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2778, 0x0007f82a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x277c, 0x0000fc00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2780, 0x0007f822, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2784, 0x0000fc00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2788, 0x0007f8ba, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x278c, 0x0000fc00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2790, 0x0007f87a, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2794, 0x0000fc00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2798, 0x0007f8ea, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x279c, 0x0000fc00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a0, 0x0007f8e2, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a4, 0x0000fc00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27a8, 0x0007f8f2, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27ac, 0x0000fc00, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x91bc, 0xe0400000, REGISTER_TYPE_PM ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x91c4, 0xe4500000, REGISTER_TYPE_PM ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    platformMask = PLATFORM_HSW;
    if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsPlatformTypeOf( platformMask ) )
    {
        aSet = aGroup->AddMetricSet( "SamplerBalance", "Metric set SamplerBalance", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
           GPU_RENDER, 256, 536, OA_REPORT_TYPE_256B_A45_NOA16, platformMask );
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
            METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xdc" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1a8" ));
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
            "The percentage of time in which the GPU has being processing GPU commands.",
            "GPU", (METRIC_GROUP_NAME_ID_GPU * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xb0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x150" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "GpuDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsThreads", "VS Threads Dispatched",
            "The total number of vertex shader hardware threads dispatched.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x20" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x30" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsThreads", "HS Threads Dispatched",
            "The total number of hull shader hardware threads dispatched.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x34" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x58" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsThreads", "DS Threads Dispatched",
            "The total number of domain shader hardware threads dispatched.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x48" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x80" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsThreads", "GS Threads Dispatched",
            "The total number of geometry shader hardware threads dispatched.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x70" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xd0" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsThreads", "PS Threads Dispatched",
            "The total number of pixel shader hardware threads dispatched.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x84" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xf8" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsThreads", "CS Threads Dispatched",
            "The total number of compute shader hardware threads dispatched.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x5c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xa8" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuActive", "EU Active",
            "The percentage of time in which the Execution Units were actively processing.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x0c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x08" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuStall", "EU Stall",
            "The percentage of time in which the Execution Units were stalled.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x10" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x10" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsEuActive", "VS EU Active",
            "The percentage of time in which vertex shaders were processed actively on the EUs.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x14" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsEuActivePerThread", "VS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which vertex shaders were processed actively on the EUs.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x14" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x18" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $VsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsEuStall", "VS EU Stall",
            "The percentage of time in which vertex shaders were stalled on the EUs.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x18" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsEuStallPerThread", "VS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which vertex shaders were stalled on the EUs.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x18" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x20" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $VsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsEuActive", "HS EU Active",
            "The percentage of time in which hull shaders were processed actively on the EUs.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x28" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsEuActivePerThread", "HS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which hull shaders were processed actively on the EUs.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x28" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x40" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $HsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsEuStall", "HS EU Stall",
            "The percentage of time in which hull shaders were stalled on the EUs.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x2c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsEuStallPerThread", "HS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which hull shaders were stalled on the EUs.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x2c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x48" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $HsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsEuActive", "DS EU Active",
            "The percentage of time in which domain shaders were processed actively on the EUs.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x3c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsEuActivePerThread", "DS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which domain shaders were processed actively on the EUs.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x3c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x68" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $DsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsEuStall", "DS EU Stall",
            "The percentage of time in which domain shaders were stalled on the EUs.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x40" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsEuStallPerThread", "DS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which domain shaders were stalled on the EUs.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x40" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x70" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $DsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsEuActive", "GS EU Active",
            "The percentage of time in which geometry shaders were processed actively on the EUs.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x64" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsEuActivePerThread", "GS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which geometry shaders were processed actively on the EUs.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x64" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xb8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $GsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsEuStall", "GS EU Stall",
            "The percentage of time in which geometry shaders were stalled on the EUs.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x68" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsEuStallPerThread", "GS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which geometry shaders were stalled on the EUs.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x68" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xc0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $GsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsEuActive", "CS EU Active",
            "The percentage of time in which compute shaders were processed actively on the EUs.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x50" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsEuActivePerThread", "CS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which compute shaders were processed actively on the EUs.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x50" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x90" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $CsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsEuStall", "CS EU Stall",
            "The percentage of time in which compute shaders were stalled on the EUs.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x54" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsEuStallPerThread", "CS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which compute shaders were stalled on the EUs.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x54" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x98" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $CsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuActive", "PS EU Active",
            "The percentage of time in which pixel shaders were processed actively on the EUs.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x78" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuActivePerThread", "PS AVG Active per Thread",
            "The average number of cycles per hardware thread run in which pixel shaders were processed actively on the EUs.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x78" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe0" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $PsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuStall", "PS EU Stall",
            "The percentage of time in which pixel shaders were stalled on the EUs.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x7c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "EuAggrDuration" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsEuStallPerThread", "PS AVG Stall per Thread",
            "The average number of cycles per hardware thread run in which pixel shaders were stalled on the EUs.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x7c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0xe8" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $PsThreads UDIV" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
            "The total number of pixels dropped on early hierarchical depth test.",
            "3D Pipe/Rasterizer/Hi-Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_HZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x90" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x110" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
            "The total number of pixels dropped on early depth test.",
            "3D Pipe/Rasterizer/Early Depth Test", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_WM * 0x10000) | (METRIC_GROUP_NAME_ID_IZ * 0x100), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x98" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x120" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
            "The total number of samples or pixels dropped in pixel shaders.",
            "3D Pipe/Pixel Shader", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_4|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0x9c" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x128" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "AlphaTestFails", "Alpha Test Fails",
            "The total number of pixels dropped on post-PS alpha test.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xa0" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x130" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PostPsStencilTestFails", "Late Stencil Test Fails",
            "The total number of pixels dropped on post-PS stencil test.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xa4" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x138" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PostPsDepthTestFails", "Late Depth Test Fails",
            "The total number of pixels dropped on post-PS depth test.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xa8" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x140" ));
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$Self $SamplesKilledInPs USUB" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "SamplesWritten", "Samples Written",
            "The total number of samples or pixels written to all render targets.",
            "3D Pipe/Output Merger", (METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000) | (METRIC_GROUP_NAME_ID_OM * 0x10000), USAGE_FLAG_TIER_3|USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xac" ));
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x148" ));
            MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "PsDuration", "PS Duration",
            "Total Pixel Shader GPU duration.",
            "EU Array/Pixel Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_PS * 0x10000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_DURATION, RESULT_UINT64, "us", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$PsEuActive $EuActive UMUL $VsEuActive $HsEuActive UADD $DsEuActive UADD $CsEuActive UADD $GsEuActive UADD $PsEuActive UADD UDIV $PsEuStall $EuStall UMUL $VsEuStall $HsEuStall UADD $DsEuStall UADD $CsEuStall UADD $GsEuStall UADD $PsEuStall UADD UDIV UADD $GpuTime UMUL $GpuCoreClocks $EuCoresTotalCount UMUL 1000 UMUL UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "VsDuration", "VS Duration",
            "Total Vertex Shader GPU duration.",
            "EU Array/Vertex Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_VS * 0x10000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_DURATION, RESULT_UINT64, "us", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$VsEuActive $EuActive UMUL $VsEuActive $HsEuActive UADD $DsEuActive UADD $CsEuActive UADD $GsEuActive UADD $PsEuActive UADD UDIV $VsEuStall $EuStall UMUL $VsEuStall $HsEuStall UADD $DsEuStall UADD $CsEuStall UADD $GsEuStall UADD $PsEuStall UADD UDIV UADD $GpuTime UMUL $GpuCoreClocks $EuCoresTotalCount UMUL 1000 UMUL UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "GsDuration", "GS Duration",
            "Total Geometry Shader GPU duration.",
            "EU Array/Geometry Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_GS * 0x10000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_DURATION, RESULT_UINT64, "us", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$GsEuActive $EuActive UMUL $VsEuActive $HsEuActive UADD $DsEuActive UADD $CsEuActive UADD $GsEuActive UADD $PsEuActive UADD UDIV $GsEuStall $EuStall UMUL $VsEuStall $HsEuStall UADD $DsEuStall UADD $CsEuStall UADD $GsEuStall UADD $PsEuStall UADD UDIV UADD $GpuTime UMUL $GpuCoreClocks $EuCoresTotalCount UMUL 1000 UMUL UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "DsDuration", "DS Duration",
            "Total Domain Shader GPU duration.",
            "EU Array/Domain Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_DS * 0x10000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_DURATION, RESULT_UINT64, "us", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,DS|TES", "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$DsEuActive $EuActive UMUL $VsEuActive $HsEuActive UADD $DsEuActive UADD $CsEuActive UADD $GsEuActive UADD $PsEuActive UADD UDIV $DsEuStall $EuStall UMUL $VsEuStall $HsEuStall UADD $DsEuStall UADD $CsEuStall UADD $GsEuStall UADD $PsEuStall UADD UDIV UADD $GpuTime UMUL $GpuCoreClocks $EuCoresTotalCount UMUL 1000 UMUL UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "HsDuration", "HS Duration",
            "Total Hull Shader GPU duration.",
            "EU Array/Hull Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_HS * 0x10000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_DURATION, RESULT_UINT64, "us", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,HS|TCS", "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$HsEuActive $EuActive UMUL $VsEuActive $HsEuActive UADD $DsEuActive UADD $CsEuActive UADD $GsEuActive UADD $PsEuActive UADD UDIV $HsEuStall $EuStall UMUL $VsEuStall $HsEuStall UADD $DsEuStall UADD $CsEuStall UADD $GsEuStall UADD $PsEuStall UADD UDIV UADD $GpuTime UMUL $GpuCoreClocks $EuCoresTotalCount UMUL 1000 UMUL UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "CsDuration", "CS Duration",
            "Total Compute Shader GPU duration.",
            "EU Array/Compute Shader", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000) | (METRIC_GROUP_NAME_ID_CS * 0x10000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_DURATION, RESULT_UINT64, "us", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "$CsEuActive $EuActive UMUL $VsEuActive $HsEuActive UADD $DsEuActive UADD $CsEuActive UADD $GsEuActive UADD $PsEuActive UADD UDIV $CsEuStall $EuStall UMUL $VsEuStall $HsEuStall UADD $DsEuStall UADD $CsEuStall UADD $GsEuStall UADD $PsEuStall UADD UDIV UADD $GpuTime UMUL $GpuCoreClocks $EuCoresTotalCount UMUL 1000 UMUL UDIV" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "EuIdle", "EU Idle",
            "The percentage of time in which the Execution Units were idle.",
            "EU Array", (METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000), USAGE_FLAG_TIER_2|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, "oa.fixed" );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetNormalizationEquation( "100 $$EuActive $$EuStall FADD FSUB" ));
            MD_CHECK_CC( aMetric->SetMaxValueEquation( "100" ));
        }

        availabilityEquation = "";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "SamplerL2CacheMisses", "Sampler L2 cache misses",
                "Number of sampler L2 cache misses",
                "Sampler", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000), USAGE_FLAG_OVERVIEW|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc dw@0xf8 UADD dw@0xf4 UADD dw@0xf0 UADD dw@0xec UADD dw@0xe8 UADD dw@0xe4 UADD dw@0xe0 UADD" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1e8 qw@0x1e0 UADD qw@0x1d8 UADD qw@0x1d0 UADD qw@0x1c8 UADD qw@0x1c0 UADD qw@0x1b8 UADD qw@0x1b0 UADD" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x1 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler0L2CacheMisses", "Sampler L2 cache misses (ss0)",
                "Number of sampler L2 cache misses (ss0)",
                "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xfc dw@0xf8 UADD" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1e8 qw@0x1e0 UADD" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x2 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler1L2CacheMisses", "Sampler L2 cache misses (ss1)",
                "Number of sampler L2 cache misses (ss1)",
                "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xf4 dw@0xf0 UADD" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1d8 qw@0x1d0 UADD" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x4 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler2L2CacheMisses", "Sampler L2 cache misses (ss2)",
                "Number of sampler L2 cache misses (ss2)",
                "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xec dw@0xe8 UADD" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1c8 qw@0x1c0 UADD" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = "$SubsliceMask 0x8 AND";
        if( MD_IS_INTERNAL_BUILD || g_MetricsDevice->IsAvailabilityEquationTrue( availabilityEquation ) )
        {
            aMetric = aSet->AddMetric( "Sampler3L2CacheMisses", "Sampler L2 cache misses (ss3)",
                "Number of sampler L2 cache misses (ss3)",
                "Sampler/Sampler Cache", (METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000) | (METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000), USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
                METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, NULL, NULL );
            if( aMetric )
            {
                MD_CHECK_CC( aMetric->SetSnapshotReportReadEquation( "dw@0xe4 dw@0xe0 UADD" ));
                MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1b8 qw@0x1b0 UADD" ));
                MD_CHECK_CC( aMetric->SetSnapshotReportDeltaFunction( "DELTA 32" ));
            }
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "LlcAccesses", "LLC GPU Accesses",
            "The total number of LLC cache lookups done from the GPU (64b reads, 32B writes).",
            "LLC", (METRIC_GROUP_NAME_ID_LLC * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f0" ));
        }

        availabilityEquation = NULL;
        aMetric = aSet->AddMetric( "LlcHits", "LLC GPU Hits",
            "The total number of successful LLC cache lookups done from the GPU.",
            "LLC", (METRIC_GROUP_NAME_ID_LLC * 0x1000000), USAGE_FLAG_TIER_1|USAGE_FLAG_OVERVIEW|USAGE_FLAG_SYSTEM|USAGE_FLAG_FRAME|USAGE_FLAG_BATCH|USAGE_FLAG_DRAW, API_TYPE_OGL4_X,
            METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, NULL, NULL );
        if( aMetric )
        {
            
            MD_CHECK_CC( aMetric->SetDeltaReportReadEquation( "qw@0x1f8" ));
        }

        aInformation = aSet->AddInformation( "QueryBeginTime", "Query Begin Time",
            "The measurement begin time.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X|API_TYPE_IOSTREAM,
            INFORMATION_TYPE_TIMESTAMP, "ns", NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ));
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x168" ));
            MD_CHECK_CC( aInformation->SetOverflowFunction( "NS_TIME" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency",
            "The last core frequency in the measurement.",
            "Report Meta Data", API_TYPE_OGL|API_TYPE_OGL4_X,
            INFORMATION_TYPE_VALUE, "MHz", NULL );
        if( aInformation )
        {
            
            MD_CHECK_CC( aInformation->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" ));
        }

        aInformation = aSet->AddInformation( "ReportReason", "Report Reason",
            "The reason of the report.",
            "Report Meta Data", API_TYPE_IOSTREAM,
            INFORMATION_TYPE_REPORT_REASON, NULL, NULL );
        if( aInformation )
        {
            MD_CHECK_CC( aInformation->SetSnapshotReportReadEquation( "dw@0x0 16 >> 0x3 AND" ));
        }

        aInformation = aSet->AddInformation( "CoreFrequencyChanged", "Core Frequency Changed",
            "The flag indicating that core frequency has changed.",
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

        MD_CHECK_CC( aSet->AddStartRegisterSet( 0, 0 ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x9840, 0x00000080, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2eb9c, 0x01906400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2fb9c, 0x01906400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x253a4, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26b9c, 0x01906400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27b9c, 0x01906400, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27104, 0x00a00000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27184, 0x00a50000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2e804, 0x00500000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2e984, 0x00500000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2eb04, 0x00500000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2eb80, 0x00000084, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2eb8c, 0x14200000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2eb84, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2f804, 0x00050000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2f984, 0x00050000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2fb04, 0x00050000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2fb80, 0x00000084, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2fb8c, 0x00050800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2fb84, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25380, 0x00000010, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2538c, 0x000000c0, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25384, 0xaa550000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25404, 0xffffc000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26804, 0x50000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26984, 0x50000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26b04, 0x50000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26b80, 0x00000084, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26b90, 0x00050800, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26b84, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27804, 0x05000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27984, 0x05000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27b04, 0x05000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27b80, 0x00000084, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27b90, 0x00000142, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x27b84, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26104, 0xa0000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x26184, 0xa5000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25424, 0x00008620, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2541c, 0x00000000, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x25428, 0x0004a54a, REGISTER_TYPE_NOA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2740, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2744, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2710, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2714, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2720, 0x00000000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x2724, 0x00800000, REGISTER_TYPE_OA ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x91bc, 0xe0400000, REGISTER_TYPE_PM ));
        MD_CHECK_CC( aSet->AddStartConfigRegister( 0x91c4, 0xe4500000, REGISTER_TYPE_PM ));
  
        MD_CHECK_CC( aSet->RefreshConfigRegisters() );
    }
     
    MD_LOG_EXIT();
    return CC_OK;

  exception:
    MD_LOG_EXIT();
    return CC_ERROR_NO_MEMORY;
}
#endif
