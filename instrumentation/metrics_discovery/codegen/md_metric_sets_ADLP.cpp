/*========================== begin_copyright_notice ============================

Copyright (C) 2023 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_metric_sets_ADLP.cpp
//
//     Abstract:   C++ automated generated file that defines Metric Sets
//                 for each Concurrent Group

#include "md_metric_sets_ADLP.h"
#include <algorithm>

#if MD_INCLUDE_ADLP_METRICS

namespace MetricsDiscoveryInternal::MetricSets_ADLP_PipelineStatistics
{
    CPipelineStatsMetricSet::CPipelineStatsMetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CPipelineStatsMetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "", 0, 0, 0x80000206, 0, 0, "", 0, "Intel_Raw_Pipeline_Statistics_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "IAVertices", "Input vertices",
                          "The total number of vertices that entered the 3D Pipeline.",
                          "3D Pipe/Input Assembler", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_IA * 0x10000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_OGL | API_TYPE_OGL4_X,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "vertices", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "IAPrimitives", "Input primitives",
                          "The total number of rendering primitives assembled and put into the input assembly stage of the 3D Pipeline.",
                          "3D Pipe/Input Assembler", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_IA * 0x10000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_OGL | API_TYPE_OGL4_X,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "triangles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsInvocations", "VS per vertex invocations",
                          "The total number of times a vertex shader was invoked. 3D rendering invokes the vertex shader once per vertex.",
                          "3D Pipe/Vertex Shader", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_OGL | API_TYPE_OGL4_X,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsInvocations", "HS invocations",
                          "The total number of times a hull shader was invoked.",
                          "3D Pipe/Hull Shader", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_OGL | API_TYPE_OGL4_X,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", nullptr, 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsInvocations", "DS invocations",
                          "The total number of times a domain shader was invoked.",
                          "3D Pipe/Domain Shader", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_OGL | API_TYPE_OGL4_X,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", nullptr, 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsInvocations", "GS per triangle invocations",
                          "The total number of times a geometry shader was invoked per triangle.",
                          "3D Pipe/Geometry Shader", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_OGL | API_TYPE_OGL4_X,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsPrimitives", "Post-GS primitives",
                          "The total number of primitives that flowed through from GS to the clipper if GS was enabled.",
                          "3D Pipe/Geometry Shader", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_OGL | API_TYPE_OGL4_X,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "triangles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ClipperInvocations", "Clipper invocations",
                          "The total number of primitives sent to the Clipper.",
                          "3D Pipe/Clipper", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CL * 0x10000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_OGL | API_TYPE_OGL4_X,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "triangles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ClipperPrimitives", "Clipper primitives",
                          "The total number of primitives that flowed out of the Clipper.",
                          "3D Pipe/Clipper", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CL * 0x10000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_OGL | API_TYPE_OGL4_X,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "triangles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsInvocations", "PS invocations",
                          "The total number of times a pixel shader was invoked. 3D rendering invokes a pixel shader once per pixel or subsample.",
                          "3D Pipe/Pixel Shader", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_OGL | API_TYPE_OGL4_X,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", nullptr, 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsInvocations", "CS invocations",
                          "The total number of times a compute shader was invoked.",
                          "3D Pipe/Compute Shader", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_OGL | API_TYPE_OGL4_X,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x50" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CpsInvocations", "CPS invocations",
                          "The total number of times a coarse shader was invoked.",
                          "3D Pipe/Compute Shader", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_OGL | API_TYPE_OGL4_X,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "invocations", 0, 0, HW_UNIT_GPU, availabilityEquation, "PS|FS", nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x58" ) ) );
        }

        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
} // namespace MetricsDiscoveryInternal::MetricSets_ADLP_PipelineStatistics

namespace MetricsDiscoveryInternal::MetricSets_ADLP_OA
{
    void AddInformationSet( CConcurrentGroup* concurrentGroup )
    {
        CInformation* information = nullptr;
        information               = concurrentGroup->AddInformation( "QueryBeginTime", "Query Begin Time", "The measurement begin time.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM | API_TYPE_MEDIA, INFORMATION_TYPE_TIMESTAMP, "ns", nullptr, 0 );
        if( information )
        {
            information->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" );
            information->SetDeltaReportReadEquation( "qw@0x1b0" );
            information->SetOverflowFunction( "NS_TIME" );
        }

        information = concurrentGroup->AddInformation( "CoreFrequencyMHz", "GPU Core Frequency", "The last GPU core (unslice) frequency in the measurement.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM, INFORMATION_TYPE_VALUE, "MHz", nullptr, 1 );
        if( information )
        {
            information->SetSnapshotReportReadEquation( "dw@0x0 0x1ff AND 16666 UMUL 1000 UDIV" );
            information->SetDeltaReportReadEquation( "qw@0x208 1000000 UDIV" );
        }

        information = concurrentGroup->AddInformation( "EuSliceFrequencyMHz", "EU Slice Frequency", "The last GPU Execution Unit slice frequency in the measurement.", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_VALUE, "MHz", nullptr, 2 );
        if( information )
        {
            information->SetSnapshotReportReadEquation( "dw@0x0 25 >> dw@0x0 9 >> 0x3 AND OR 16666 UMUL 1000 UDIV" );
        }

        information = concurrentGroup->AddInformation( "ReportReason", "Report Reason", "The reason of the report.", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_REPORT_REASON, nullptr, nullptr, 3 );
        if( information )
        {
            information->SetSnapshotReportReadEquation( "dw@0x0 19 >> 0x3f AND" );
        }

        information = concurrentGroup->AddInformation( "ContextIdValid", "Context ID Valid", "When set indicates render context is valid", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_FLAG, nullptr, nullptr, 4 );
        if( information )
        {
            information->SetSnapshotReportReadEquation( "dw@0x0 16 >> 0x1 AND" );
        }

        information = concurrentGroup->AddInformation( "ContextId", "Context ID", "The context tag in which report has been taken.", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_CONTEXT_ID_TAG, nullptr, nullptr, 5 );
        if( information )
        {
            information->SetSnapshotReportReadEquation( "dw@0x08 0xffbfffff AND dw@0x0 16 >> 0x1 AND UMUL" );
        }

        information = concurrentGroup->AddInformation( "CoreFrequencyChanged", "GPU Core Frequency Changed", "The flag indicating that GPU core frequency has changed.", "Exception", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 6 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x204" );
        }

        information = concurrentGroup->AddInformation( "QuerySplitOccurred", "Query Split Occurred", "The flag indicating that query has been split during execution on the GPU.", "Exception", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 7 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x200" );
        }

        information = concurrentGroup->AddInformation( "ReportId", "Query report id", "Query report identification number.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_VALUE, nullptr, nullptr, 8 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x210" );
        }

        information = concurrentGroup->AddInformation( "ReportsCount", "Query reports count", "The number of available query reports.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_VALUE, nullptr, nullptr, 9 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x214" );
        }

        information = concurrentGroup->AddInformation( "OverrunOccured", "Query Overrun Occurred", "The flag indicating that Oa buffer has been overran.", "Exception", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 10 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x1cc" );
        }

        information = concurrentGroup->AddInformation( "SampleSequence", "Sample sequence", "Number identifying report sequence.", "Report Meta Data", API_TYPE_BBSTREAM, INFORMATION_TYPE_VALUE, nullptr, nullptr, 11 );
        if( information )
        {
            information->SetSnapshotReportReadEquation( "dw@0x0 0x7f AND" );
        }

        information = concurrentGroup->AddInformation( "SamplePhase", "Sample phase", "Buffer execution phase.", "Report Meta Data", API_TYPE_BBSTREAM, INFORMATION_TYPE_SAMPLE_PHASE, nullptr, nullptr, 12 );
        if( information )
        {
            information->SetSnapshotReportReadEquation( "dw@0x0 7 >> 0x01 AND" );
        }

        information = concurrentGroup->AddInformation( "GpuNode", "Gpu node", "GPU node buffer was sent to.", "Report Meta Data", API_TYPE_BBSTREAM, INFORMATION_TYPE_GPU_NODE, nullptr, nullptr, 13 );
        if( information )
        {
            information->SetSnapshotReportReadEquation( "dw@0x0 8 >> 0x07 AND" );
        }

        information = concurrentGroup->AddInformation( "MidQueryTimer", "Mid Query Timer", "The flag indicating that timer report was detected during query.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 14 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x1c8 0x01 AND" );
        }

        information = concurrentGroup->AddInformation( "MidQueryProgramming", "Mid Query Programming", "The flag indicating that counter programming report was detected during query.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 15 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x1c8 0x02 AND" );
        }

        information = concurrentGroup->AddInformation( "MidQueryMarker", "Mid Query Marker", "The flag indicating that query marker report was detected during query.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 16 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x1c8 0x04 AND" );
        }

        information = concurrentGroup->AddInformation( "MidQueryCtxSwitch", "Mid Query Context Switch", "The flag indicating that context switch report was detected during query.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 17 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x1c8 0x08 AND" );
        }

        information = concurrentGroup->AddInformation( "MidQueryC6", "Mid Query C6", "The flag indicating that C6 report was detected during query.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 18 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x1c8 0x10 AND" );
        }

        information = concurrentGroup->AddInformation( "MidQueryFreqChange", "Mid Query Freq Change", "The flag indicating that frequency change report was detected during query.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 19 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x1c8 0x20 AND" );
        }

        information = concurrentGroup->AddInformation( "ReportError", "Query report error", "An error in the query execution, the received report should be ignored.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 20 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x29c 0x13 AND" );
        }

        information = concurrentGroup->AddInformation( "ReportLost", "Query report lost", "Begin or end query report has not been triggered due to hw limitations.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 21 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x29c 0x01 AND" );
        }

        information = concurrentGroup->AddInformation( "ReportInconsistent", "Query report inconsistent", "The contextId inconsistency in the Oa buffer within the query window.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 22 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x29c 0x02 AND" );
        }

        information = concurrentGroup->AddInformation( "ReportCtxSwitchLost", "Query report context switch lost", "Oa buffer has not been browsed to find context switch reports to filter out unfamiliar contexts from the query report.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 23 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x29c 0x08 AND" );
        }

        information = concurrentGroup->AddInformation( "ReportWithoutWorkload", "Query report missing workload", "Missing workload between query begin and query end.", "Report Meta Data", API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL, INFORMATION_TYPE_FLAG, nullptr, nullptr, 24 );
        if( information )
        {
            information->SetDeltaReportReadEquation( "dw@0x29c 0x10 AND" );
        }
    }

    CRenderBasicMetricSet::CRenderBasicMetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CRenderBasicMetricSet::Initialize()
    {
        TCompletionCode ret                             = CC_OK;
        CMetric*        metric                          = nullptr;
        CInformation*   information                     = nullptr;
        const char*     availabilityEquation            = nullptr;
        const uint32_t  concurrentGroupInformationCount = m_concurrentGroup->GetInformationCount();
        m_params_1_0.InformationCount                   = concurrentGroupInformationCount;
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuActive", "EU Active",
                          "The percentage of time in which the Execution Units were actively processing.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuStall", "EU Stall",
                          "The percentage of time in which the Execution Units were stalled.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
                          "The percentage of time in which hardware threads occupied EUs.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "8 rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "8 qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 1 AND";
        metric               = AddMetric( "Sampler00Busy", "Sampler00 Busy",
                          "The percentage of time in which Slice0 Sampler0 has been processing EU requests.",
                          "Sampler", ( METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_BATCH | USAGE_FLAG_FRAME | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, nullptr, nullptr, 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x130" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 1 AND";
        metric               = AddMetric( "Sampler00Bottleneck", "Sampler Slice0 Dualsubslice0 is bottleneck",
                          "The percentage of time when sampler slice0 dualsubslice0 is bottleneck",
                          "GPU/Sampler", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SAMPLER * 0x10000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, nullptr, nullptr, 14 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x138" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 1 AND";
        metric               = AddMetric( "SamplersBusy", "Samplers Busy",
                          "The percentage of time in which samplers have been processing EU requests.",
                          "Sampler", ( METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 15 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$$Sampler00Busy" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 1 AND";
        metric               = AddMetric( "SamplerBottleneck", "Samplers Bottleneck",
                          "The percentage of time in which samplers have been slowing down the pipe when processing EU requests.",
                          "Sampler", ( METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_INDICATE | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 16 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$$Sampler00Bottleneck" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "RasterizedPixels", "Rasterized Pixels",
                          "The total number of rasterized pixels.",
                          "3D Pipe/Rasterizer", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_WM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,pixel|fragment", "oa.fixed", 17 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xb8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
                          "The total number of pixels dropped on early hierarchical depth test.",
                          "3D Pipe/Rasterizer/Hi-Depth Test", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_WM * 0x10000 ) | ( METRIC_GROUP_NAME_ID_HZ * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "pixel|fragment", "oa.fixed", 18 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xc0" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
                          "The total number of pixels dropped on early depth test.",
                          "3D Pipe/Rasterizer/Early Depth Test", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_WM * 0x10000 ) | ( METRIC_GROUP_NAME_ID_IZ * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "pixel|fragment", "oa.fixed", 19 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xc8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
                          "The total number of samples or pixels dropped in pixel shaders.",
                          "3D Pipe/Pixel Shader", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_4 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 20 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xd0" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
                          "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
                          "3D Pipe/Output Merger", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_OM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 21 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xd8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplesWritten", "Samples Written",
                          "The total number of samples or pixels written to all render targets.",
                          "3D Pipe/Output Merger", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_OM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "pixel|fragment", "oa.fixed", 22 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xe0" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplesBlended", "Samples Blended",
                          "The total number of blended samples or pixels written to all render targets.",
                          "3D Pipe/Output Merger", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_OM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "pixel|fragment", "oa.fixed", 23 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xe8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplerTexels", "Sampler Texels",
                          "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
                          "Sampler/Sampler Input", ( METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 24 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xf0" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
                          "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
                          "Sampler/Sampler Cache", ( METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_BATCH | USAGE_FLAG_FRAME | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 25 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xf8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SlmBytesRead", "SLM Bytes Read",
                          "The total number of GPU memory bytes read from shared local memory.",
                          "L3/Data Port/SLM", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ) | ( METRIC_GROUP_NAME_ID_SLM * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 26 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x100" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 64 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 128 UMUL $EuDualSubslicesTotalCount UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SlmBytesWritten", "SLM Bytes Written",
                          "The total number of GPU memory bytes written into shared local memory.",
                          "L3/Data Port/SLM", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ) | ( METRIC_GROUP_NAME_ID_SLM * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 27 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x108" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 64 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 128 UMUL $EuDualSubslicesTotalCount UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
                          "The total number of shader memory accesses to L3.",
                          "L3/Data Port", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 28 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x90" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x110" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
                          "The total number of shader atomic memory accesses.",
                          "L3/Data Port/Atomics", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ) | ( METRIC_GROUP_NAME_ID_ATOMICS * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 29 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x98" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x120" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
                          "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
                          "L3/Data Port", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 30 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$$ShaderMemoryAccesses 64 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuDualSubslicesTotalCount UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ShaderBarriers", "Shader Barrier Messages",
                          "The total number of shader barrier messages.",
                          "EU Array/Barrier", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 31 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x9c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x128" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GtiReadThroughput", "GTI Read Throughput",
                          "The total number of GPU memory bytes read from GTI.",
                          "GTI", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 32 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xf4 dw@0xf0 UADD dw@0xec UADD dw@0xe8 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x198 qw@0x190 UADD qw@0x188 UADD qw@0x180 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "64 $Self UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GtiWriteThroughput", "GTI Write Throughput",
                          "The total number of GPU memory bytes written to GTI.",
                          "GTI", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 33 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe4 dw@0xe0 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x178 qw@0x170 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "64 $Self UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ) ) );
        }

        information = AddInformation( "StreamMarker", "Stream marker", "Stream marker value.", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_VALUE, nullptr, nullptr, concurrentGroupInformationCount + 0 );
        if( information )
        {
            information->SetSnapshotReportReadEquation( "dw@0x5c dw@0x0 19 >> 0x4 AND 0x4 == UMUL" );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x14150001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x16150020, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x12124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10138000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c130e00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00150050, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06157000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08157151, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10150000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18150000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c150000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18004000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x36000490, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c058000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2405002a, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05151d47, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09151536, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05351c00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09351400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x41104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5b1050bb, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5d102c01, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17144000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d1402a0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0f124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x11124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x13124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f150137, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01150000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0f168000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d350137, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03350147, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07350136, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01350000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0f364000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x47101000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4d100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4f100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x51100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x55101210, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x57100002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x49101212, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4b100212, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x30800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc40, 0x00030000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd940, 0x00000018, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd944, 0x0000fffc, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc00, 0x00000018, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc04, 0x0000fffc, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd948, 0x00000060, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd94c, 0x0000fff3, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc08, 0x00000060, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc0c, 0x0000fff3, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00804704, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a04904, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00805705, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a05905, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00808708, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a08908, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe65c, 0xffffffff, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CComputeBasicMetricSet::CComputeBasicMetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CComputeBasicMetricSet::Initialize()
    {
        TCompletionCode ret                             = CC_OK;
        CMetric*        metric                          = nullptr;
        CInformation*   information                     = nullptr;
        const char*     availabilityEquation            = nullptr;
        const uint32_t  concurrentGroupInformationCount = m_concurrentGroup->GetInformationCount();
        m_params_1_0.InformationCount                   = concurrentGroupInformationCount;
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuActive", "EU Active",
                          "The percentage of time in which the Execution Units were actively processing.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuStall", "EU Stall",
                          "The percentage of time in which the Execution Units were stalled.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
                          "The percentage of time in which hardware threads occupied EUs.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "8 rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "8 qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "RasterizedPixels", "Rasterized Pixels",
                          "The total number of rasterized pixels.",
                          "3D Pipe/Rasterizer", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_WM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,pixel|fragment", "oa.fixed", 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xb8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
                          "The total number of pixels dropped on early hierarchical depth test.",
                          "3D Pipe/Rasterizer/Hi-Depth Test", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_WM * 0x10000 ) | ( METRIC_GROUP_NAME_ID_HZ * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "pixel|fragment", "oa.fixed", 14 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xc0" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
                          "The total number of pixels dropped on early depth test.",
                          "3D Pipe/Rasterizer/Early Depth Test", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_WM * 0x10000 ) | ( METRIC_GROUP_NAME_ID_IZ * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "pixel|fragment", "oa.fixed", 15 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xc8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
                          "The total number of samples or pixels dropped in pixel shaders.",
                          "3D Pipe/Pixel Shader", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_4 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 16 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xd0" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
                          "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
                          "3D Pipe/Output Merger", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_OM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 17 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xd8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplesWritten", "Samples Written",
                          "The total number of samples or pixels written to all render targets.",
                          "3D Pipe/Output Merger", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_OM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "pixel|fragment", "oa.fixed", 18 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xe0" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplesBlended", "Samples Blended",
                          "The total number of blended samples or pixels written to all render targets.",
                          "3D Pipe/Output Merger", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_OM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "pixel|fragment", "oa.fixed", 19 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xe8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplerTexels", "Sampler Texels",
                          "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
                          "Sampler/Sampler Input", ( METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 20 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xf0" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
                          "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
                          "Sampler/Sampler Cache", ( METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_BATCH | USAGE_FLAG_FRAME | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 21 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xf8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SlmBytesRead", "SLM Bytes Read",
                          "The total number of GPU memory bytes read from shared local memory.",
                          "L3/Data Port/SLM", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ) | ( METRIC_GROUP_NAME_ID_SLM * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 22 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x100" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 64 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 128 UMUL $EuDualSubslicesTotalCount UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SlmBytesWritten", "SLM Bytes Written",
                          "The total number of GPU memory bytes written into shared local memory.",
                          "L3/Data Port/SLM", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ) | ( METRIC_GROUP_NAME_ID_SLM * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 23 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x108" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 64 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 128 UMUL $EuDualSubslicesTotalCount UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
                          "The total number of shader memory accesses to L3.",
                          "L3/Data Port", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 24 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x90" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x110" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
                          "The total number of shader atomic memory accesses.",
                          "L3/Data Port/Atomics", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ) | ( METRIC_GROUP_NAME_ID_ATOMICS * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 25 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x98" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x120" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
                          "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
                          "L3/Data Port", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 26 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$$ShaderMemoryAccesses 64 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuDualSubslicesTotalCount UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ShaderBarriers", "Shader Barrier Messages",
                          "The total number of shader barrier messages.",
                          "EU Array/Barrier", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 27 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x9c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x128" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GtiReadThroughput", "GTI Read Throughput",
                          "The total number of GPU memory bytes read from GTI.",
                          "GTI", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 28 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xfc dw@0xf8 UADD dw@0xf4 UADD dw@0xf0 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1a8 qw@0x1a0 UADD qw@0x198 UADD qw@0x190 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "64 $Self UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GtiWriteThroughput", "GTI Write Throughput",
                          "The total number of GPU memory bytes written to GTI.",
                          "GTI", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 29 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xec dw@0xe8 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x188 qw@0x180 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "64 $Self UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ) ) );
        }

        information = AddInformation( "StreamMarker", "Stream marker", "Stream marker value.", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_VALUE, nullptr, nullptr, concurrentGroupInformationCount + 0 );
        if( information )
        {
            information->SetSnapshotReportReadEquation( "dw@0x5c dw@0x0 19 >> 0x4 AND 0x4 == UMUL" );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05151d37, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09151547, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05351c00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09351400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5b100bbb, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0d150136, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01150000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03350137, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07350147, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0b350136, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01350000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x47100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x49100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4b100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4d100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc40, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00804704, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a04904, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00805705, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a05905, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00808708, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a08908, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe65c, 0xffffffff, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CRenderPipeProfileMetricSet::CRenderPipeProfileMetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CRenderPipeProfileMetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuActive", "EU Active",
                          "The percentage of time in which the Execution Units were actively processing.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuStall", "EU Stall",
                          "The percentage of time in which the Execution Units were stalled.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
                          "The percentage of time in which hardware threads occupied EUs.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "8 rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "8 qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "RasterizedPixels", "Rasterized Pixels",
                          "The total number of rasterized pixels.",
                          "3D Pipe/Rasterizer", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_WM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,pixel|fragment", "oa.fixed", 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xb8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
                          "The total number of pixels dropped on early hierarchical depth test.",
                          "3D Pipe/Rasterizer/Hi-Depth Test", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_WM * 0x10000 ) | ( METRIC_GROUP_NAME_ID_HZ * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "pixel|fragment", "oa.fixed", 14 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xc0" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
                          "The total number of pixels dropped on early depth test.",
                          "3D Pipe/Rasterizer/Early Depth Test", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_WM * 0x10000 ) | ( METRIC_GROUP_NAME_ID_IZ * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "pixel|fragment", "oa.fixed", 15 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xc8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
                          "The total number of samples or pixels dropped in pixel shaders.",
                          "3D Pipe/Pixel Shader", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_4 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 16 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xd0" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
                          "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
                          "3D Pipe/Output Merger", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_OM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 17 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xd8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplesWritten", "Samples Written",
                          "The total number of samples or pixels written to all render targets.",
                          "3D Pipe/Output Merger", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_OM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "pixel|fragment", "oa.fixed", 18 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xe0" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplesBlended", "Samples Blended",
                          "The total number of blended samples or pixels written to all render targets.",
                          "3D Pipe/Output Merger", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_OM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "pixel|fragment", "oa.fixed", 19 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xe8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplerTexels", "Sampler Texels",
                          "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
                          "Sampler/Sampler Input", ( METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 20 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xf0" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
                          "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
                          "Sampler/Sampler Cache", ( METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_BATCH | USAGE_FLAG_FRAME | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 21 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xf8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SlmBytesRead", "SLM Bytes Read",
                          "The total number of GPU memory bytes read from shared local memory.",
                          "L3/Data Port/SLM", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ) | ( METRIC_GROUP_NAME_ID_SLM * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 22 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x100" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 64 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 128 UMUL $EuDualSubslicesTotalCount UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SlmBytesWritten", "SLM Bytes Written",
                          "The total number of GPU memory bytes written into shared local memory.",
                          "L3/Data Port/SLM", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ) | ( METRIC_GROUP_NAME_ID_SLM * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 23 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x108" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 64 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 128 UMUL $EuDualSubslicesTotalCount UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
                          "The total number of shader memory accesses to L3.",
                          "L3/Data Port", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 24 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x90" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x110" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
                          "The total number of shader atomic memory accesses.",
                          "L3/Data Port/Atomics", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ) | ( METRIC_GROUP_NAME_ID_ATOMICS * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 25 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x98" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x120" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
                          "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
                          "L3/Data Port", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 26 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$$ShaderMemoryAccesses 64 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuDualSubslicesTotalCount UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ShaderBarriers", "Shader Barrier Messages",
                          "The total number of shader barrier messages.",
                          "EU Array/Barrier", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 27 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x9c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x128" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VfBottleneck", "VF Bottleneck",
                          "The percentage of time in which vertex fetch pipeline stage was slowing down the 3D pipeline.",
                          "3D Pipe/Input Assembler", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_IA * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_INDICATE | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 28 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xfc" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1a8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsBottleneck", "VS Bottleneck",
                          "The percentage of time in which vertex shader pipeline stage was slowing down the 3D pipeline.",
                          "3D Pipe/Vertex Shader", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_INDICATE | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 10, 30, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 29 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xf8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1a0" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsBottleneck", "HS Bottleneck",
                          "The percentage of time in which hull shader pipeline stage was slowing down the 3D pipeline.",
                          "3D Pipe/Hull Shader", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_INDICATE | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 3, 9, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", nullptr, 30 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xd4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x158" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsBottleneck", "DS Bottleneck",
                          "The percentage of time in which domain shader pipeline stage was slowing down the 3D pipeline.",
                          "3D Pipe/Domain Shader", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_INDICATE | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", nullptr, 31 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xf4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x198" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsBottleneck", "GS Bottleneck",
                          "The percentage of time in which geometry shader pipeline stage was slowing down the 3D pipeline.",
                          "3D Pipe/Geometry Shader", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_INDICATE | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 32 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xd0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x150" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SoBottleneck", "SO Bottleneck",
                          "The percentage of time in which stream output pipeline stage was slowing down the 3D pipeline.",
                          "3D Pipe/Stream Output", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SO * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_INDICATE | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 33 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xf0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x190" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ClBottleneck", "Clipper Bottleneck",
                          "The percentage of time in which clipper pipeline stage was slowing down the 3D pipeline.",
                          "3D Pipe/Clipper", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CL * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_INDICATE | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 10, 30, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 34 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xec" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x188" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SfBottleneck", "Strip-Fans Bottleneck",
                          "The percentage of time in which strip-fans pipeline stage was slowing down the 3D pipeline.",
                          "3D Pipe/Rasterizer/Strip-Fans", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_WM * 0x10000 ) | ( METRIC_GROUP_NAME_ID_SF * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_INDICATE | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 10, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 35 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x180" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HiDepthBottleneck", "Hi-Depth Bottleneck",
                          "The percentage of time in which early hierarchical depth test pipeline stage was slowing down the 3D pipeline.",
                          "3D Pipe/Rasterizer/Hi-Depth Test", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_WM * 0x10000 ) | ( METRIC_GROUP_NAME_ID_HZ * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_INDICATE | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 36 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xcc" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x148" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "BcBottleneck", "BC Bottleneck",
                          "The percentage of time in which barycentric coordinates calculation pipeline stage was slowing down the 3D pipeline.",
                          "3D Pipe/Rasterizer/Barycentric Calc", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_WM * 0x10000 ) | ( METRIC_GROUP_NAME_ID_BC * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_INDICATE | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 5, 15, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 37 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x178" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsStall", "HS Stall",
                          "The percentage of time in which hull stall pipeline stage was stalled.",
                          "3D Pipe/Hull Shader", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_4 | USAGE_FLAG_CORRELATE | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", nullptr, 38 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x140" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsStall", "DS Stall",
                          "The percentage of time in which domain shader pipeline stage was stalled.",
                          "3D Pipe/Domain Shader", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_4 | USAGE_FLAG_CORRELATE | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", nullptr, 39 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x170" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SoStall", "SO Stall",
                          "The percentage of time in which stream-output pipeline stage was stalled.",
                          "3D Pipe/Stream Output", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SO * 0x10000 ), USAGE_FLAG_TIER_4 | USAGE_FLAG_CORRELATE | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 40 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xdc" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x168" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ClStall", "CL Stall",
                          "The percentage of time in which clipper pipeline stage was stalled.",
                          "3D Pipe/Clipper", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CL * 0x10000 ), USAGE_FLAG_TIER_4 | USAGE_FLAG_CORRELATE | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 41 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x138" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SfStall", "SF Stall",
                          "The percentage of time in which strip-fans pipeline stage was stalled.",
                          "3D Pipe/Rasterizer/Strip-Fans", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_WM * 0x10000 ) | ( METRIC_GROUP_NAME_ID_SF * 0x100 ), USAGE_FLAG_TIER_4 | USAGE_FLAG_CORRELATE | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 42 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xd8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x160" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00123e00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x060b00b3, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x140b3c00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c0b0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x120c8320, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x040dbe00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x000d0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x280d0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2c0e7c00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10087c00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e120002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x20120000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e130002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e0b0031, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x180b0092, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a0b00b1, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x020b0093, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x040b0033, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x000b0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a0c0022, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0c0030, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c0c8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x140c8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x160c8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x100dc017, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x160d0013, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c0d0081, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x080d0082, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a0d8102, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x140d0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c0d0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e0d4000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x120d0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x060dc000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c0ec1c5, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x180e0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e0e8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x100e4000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x120ec000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x140ec000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x160e4000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x080e8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a0ec000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c0f5555, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0f0554, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x14104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x16104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e024000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10024000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2c024000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2e020055, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02024000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04024000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06024000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08024000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a024000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c024000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a032000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c032000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2a035500, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2c030001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02034000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04034000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06034000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08034000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a034000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18032000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x360036db, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x380026db, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a006000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c006000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e006000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x34001b00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x26050002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x100a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x120a4000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x140a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x160a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x180a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x020a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x040a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x060a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x080a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08081000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5b105555, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5d101555, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d14aaaa, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f14002a, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1b14aa00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0f124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x11124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x13124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x15124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x19124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1b124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0b124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0d124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4d100604, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4f101400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x51100203, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x53100004, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x55101400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x57100001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x47100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x49100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4b100400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc40, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00804704, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a04904, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00805705, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a05905, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00808708, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a08908, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CHDCAndSFMetricSet::CHDCAndSFMetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CHDCAndSFMetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuActive", "EU Active",
                          "The percentage of time in which the Execution Units were actively processing.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuStall", "EU Stall",
                          "The percentage of time in which the Execution Units were stalled.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
                          "The percentage of time in which hardware threads occupied EUs.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "8 rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "8 qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "RasterizedPixels", "Rasterized Pixels",
                          "The total number of rasterized pixels.",
                          "3D Pipe/Rasterizer", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_WM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,pixel|fragment", "oa.fixed", 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xb8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
                          "The total number of pixels dropped on early hierarchical depth test.",
                          "3D Pipe/Rasterizer/Hi-Depth Test", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_WM * 0x10000 ) | ( METRIC_GROUP_NAME_ID_HZ * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "pixel|fragment", "oa.fixed", 14 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xc0" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
                          "The total number of pixels dropped on early depth test.",
                          "3D Pipe/Rasterizer/Early Depth Test", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_WM * 0x10000 ) | ( METRIC_GROUP_NAME_ID_IZ * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "pixel|fragment", "oa.fixed", 15 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xc8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
                          "The total number of samples or pixels dropped in pixel shaders.",
                          "3D Pipe/Pixel Shader", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_4 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 16 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xd0" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
                          "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
                          "3D Pipe/Output Merger", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_OM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 17 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xd8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplesWritten", "Samples Written",
                          "The total number of samples or pixels written to all render targets.",
                          "3D Pipe/Output Merger", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_OM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "pixel|fragment", "oa.fixed", 18 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xe0" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplesBlended", "Samples Blended",
                          "The total number of blended samples or pixels written to all render targets.",
                          "3D Pipe/Output Merger", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_OM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "pixel|fragment", "oa.fixed", 19 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xe8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplerTexels", "Sampler Texels",
                          "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
                          "Sampler/Sampler Input", ( METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 20 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xf0" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
                          "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
                          "Sampler/Sampler Cache", ( METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_BATCH | USAGE_FLAG_FRAME | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 21 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xf8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SlmBytesRead", "SLM Bytes Read",
                          "The total number of GPU memory bytes read from shared local memory.",
                          "L3/Data Port/SLM", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ) | ( METRIC_GROUP_NAME_ID_SLM * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 22 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x100" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 64 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 128 UMUL $EuDualSubslicesTotalCount UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SlmBytesWritten", "SLM Bytes Written",
                          "The total number of GPU memory bytes written into shared local memory.",
                          "L3/Data Port/SLM", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ) | ( METRIC_GROUP_NAME_ID_SLM * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 23 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x108" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 64 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 128 UMUL $EuDualSubslicesTotalCount UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
                          "The total number of shader memory accesses to L3.",
                          "L3/Data Port", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 24 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x90" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x110" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
                          "The total number of shader atomic memory accesses.",
                          "L3/Data Port/Atomics", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ) | ( METRIC_GROUP_NAME_ID_ATOMICS * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 25 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x98" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x120" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
                          "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
                          "L3/Data Port", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 26 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$$ShaderMemoryAccesses 64 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuDualSubslicesTotalCount UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ShaderBarriers", "Shader Barrier Messages",
                          "The total number of shader barrier messages.",
                          "EU Array/Barrier", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 27 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x9c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x128" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 1 AND";
        metric               = AddMetric( "NonSamplerShader00AccessStalledOnL3", "Slice0 Dualsubslice0 Non-sampler Shader Access Stalled On L3",
                          "Percentage of time when HDC has messages to L3, but it's stalled due to lack of credits (Slice0 Dualsubslice0)",
                          "GPU/Data Port", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, nullptr, nullptr, 28 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x140" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 2 AND";
        metric               = AddMetric( "NonSamplerShader01AccessStalledOnL3", "Slice0 Dualsubslice1 Non-sampler Shader Access Stalled On L3",
                          "Percentage of time when HDC has messages to L3, but it's stalled due to lack of credits (Slice0 Dualsubslice1)",
                          "GPU/Data Port", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, nullptr, nullptr, 29 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xcc" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x148" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 4 AND";
        metric               = AddMetric( "NonSamplerShader02AccessStalledOnL3", "Slice0 Dualsubslice2 Non-sampler Shader Access Stalled On L3",
                          "Percentage of time when HDC has messages to L3, but it's stalled due to lack of credits (Slice0 Dualsubslice2)",
                          "GPU/Data Port", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, nullptr, nullptr, 30 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xd0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x150" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 8 AND";
        metric               = AddMetric( "NonSamplerShader03AccessStalledOnL3", "Slice0 Dualsubslice3 Non-sampler Shader Access Stalled On L3",
                          "Percentage of time when HDC has messages to L3, but it's stalled due to lack of credits (Slice0 Dualsubslice3)",
                          "GPU/Data Port", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, nullptr, nullptr, 31 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xd4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x158" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 16 AND";
        metric               = AddMetric( "NonSamplerShader04AccessStalledOnL3", "Slice0 Dualsubslice4 Non-sampler Shader Access Stalled On L3",
                          "Percentage of time when HDC has messages to L3, but it's stalled due to lack of credits (Slice0 Dualsubslice4)",
                          "GPU/Data Port", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, nullptr, nullptr, 32 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x138" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 32 AND";
        metric               = AddMetric( "NonSamplerShader05AccessStalledOnL3", "Slice0 Dualsubslice5 Non-sampler Shader Access Stalled On L3",
                          "Percentage of time when HDC has messages to L3, but it's stalled due to lack of credits (Slice0 Dualsubslice5)",
                          "GPU/Data Port", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, nullptr, nullptr, 33 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x130" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PolyDataReady", "Polygon Data Ready",
                          "The percentage of time in which geometry pipeline output is ready",
                          "GPU/3D Pipe/Strip-Fans", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000 ) | ( METRIC_GROUP_NAME_ID_SF * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 34 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xd8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x160" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x14112400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x14312400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x14512474, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x14712400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x14912400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x14b12400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x240a0019, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c07c000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x24070002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10110074, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08110000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10128000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c130400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x12310074, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10310000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08310000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x12328000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c330800, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10510000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a510000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x14528000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c531000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x16710074, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10710000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a710000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x16728000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c732000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e910074, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10910000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06910000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e928000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c930200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00b10074, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10b10000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00b28000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10b38000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0f0020, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x16104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2e020001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2a030600, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18002000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x36003488, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x3800001b, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00014000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a012000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x24050038, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x24060080, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x180a00f7, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x200a0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x140a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x160a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x41104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5b105000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5d100055, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17144000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d14aaa0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0f124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x11124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x13124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x15124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x19124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x47100600, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4d100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4f100806, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x51100408, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x53100310, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0xf0800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x70800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc40, 0x007f0000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd940, 0x00000002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd944, 0x0000fffe, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc00, 0x00000002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc04, 0x0000fffe, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd948, 0x00000002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd94c, 0x0000fffd, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc08, 0x00000002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc0c, 0x0000fffd, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd950, 0x00000002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd954, 0x0000fffb, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc10, 0x00000002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc14, 0x0000fffb, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd958, 0x00000002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd95c, 0x0000fff7, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc18, 0x00000002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc1c, 0x0000fff7, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd960, 0x00000002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd964, 0x0000ffef, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc20, 0x00000002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc24, 0x0000ffef, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd968, 0x00000002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd96c, 0x0000ffdf, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc28, 0x00000002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc2c, 0x0000ffdf, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd970, 0x00000002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd974, 0x0000ffbf, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc30, 0x00000002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc34, 0x0000ffbf, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00804704, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a04904, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00805705, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a05905, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00808708, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a08908, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CRasterizerAndPixelBackendMetricSet::CRasterizerAndPixelBackendMetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CRasterizerAndPixelBackendMetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuActive", "EU Active",
                          "The percentage of time in which the Execution Units were actively processing.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuStall", "EU Stall",
                          "The percentage of time in which the Execution Units were stalled.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
                          "The percentage of time in which hardware threads occupied EUs.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "8 rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "8 qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "RasterizedPixels", "Rasterized Pixels",
                          "The total number of rasterized pixels.",
                          "3D Pipe/Rasterizer", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_WM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,pixel|fragment", "oa.fixed", 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x64:0xb5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xb8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HiDepthTestFails", "Early Hi-Depth Test Fails",
                          "The total number of pixels dropped on early hierarchical depth test.",
                          "3D Pipe/Rasterizer/Hi-Depth Test", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_WM * 0x10000 ) | ( METRIC_GROUP_NAME_ID_HZ * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "pixel|fragment", "oa.fixed", 14 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x68:0xb6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xc0" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EarlyDepthTestFails", "Early Depth Test Fails",
                          "The total number of pixels dropped on early depth test.",
                          "3D Pipe/Rasterizer/Early Depth Test", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_WM * 0x10000 ) | ( METRIC_GROUP_NAME_ID_IZ * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "pixel|fragment", "oa.fixed", 15 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x6c:0xb7" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xc8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplesKilledInPs", "Samples Killed in PS",
                          "The total number of samples or pixels dropped in pixel shaders.",
                          "3D Pipe/Pixel Shader", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_4 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 16 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x70:0xb8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xd0" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PixelsFailingPostPsTests", "Pixels Failing Tests",
                          "The total number of pixels dropped on post-PS alpha, stencil, or depth tests.",
                          "3D Pipe/Output Merger", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_OM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 17 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x74:0xb9" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xd8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplesWritten", "Samples Written",
                          "The total number of samples or pixels written to all render targets.",
                          "3D Pipe/Output Merger", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_OM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "pixel|fragment", "oa.fixed", 18 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x78:0xba" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xe0" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplesBlended", "Samples Blended",
                          "The total number of blended samples or pixels written to all render targets.",
                          "3D Pipe/Output Merger", ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_OM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "pixels", 0, 0, HW_UNIT_GPU, availabilityEquation, "pixel|fragment", "oa.fixed", 19 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x7c:0xbb" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xe8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplerTexels", "Sampler Texels",
                          "The total number of texels seen on input (with 2x2 accuracy) in all sampler units.",
                          "Sampler/Sampler Input", ( METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SAMPLER_IN * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 20 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x80:0xbc" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xf0" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SamplerTexelMisses", "Sampler Texels Misses",
                          "The total number of texels lookups (with 2x2 accuracy) that missed L1 sampler cache.",
                          "Sampler/Sampler Cache", ( METRIC_GROUP_NAME_ID_SAMPLER * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SAMPLER_CACHE * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_BATCH | USAGE_FLAG_FRAME | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "texels", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 21 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x84:0xbd" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0xf8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 4 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SlmBytesRead", "SLM Bytes Read",
                          "The total number of GPU memory bytes read from shared local memory.",
                          "L3/Data Port/SLM", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ) | ( METRIC_GROUP_NAME_ID_SLM * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 22 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x88:0xbe" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x100" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 64 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 128 UMUL $EuDualSubslicesTotalCount UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "SlmBytesWritten", "SLM Bytes Written",
                          "The total number of GPU memory bytes written into shared local memory.",
                          "L3/Data Port/SLM", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ) | ( METRIC_GROUP_NAME_ID_SLM * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 23 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x8c:0xbf" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x108" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$Self 64 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 128 UMUL $EuDualSubslicesTotalCount UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ShaderMemoryAccesses", "Shader Memory Accesses",
                          "The total number of shader memory accesses to L3.",
                          "L3/Data Port", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 24 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x90" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x110" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ShaderAtomics", "Shader Atomic Memory Accesses",
                          "The total number of shader atomic memory accesses.",
                          "L3/Data Port/Atomics", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ) | ( METRIC_GROUP_NAME_ID_ATOMICS * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 25 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x98" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x120" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "L3ShaderThroughput", "L3 Shader Throughput",
                          "The total number of GPU memory bytes transferred between shaders and L3 caches w/o URB.",
                          "L3/Data Port", ( METRIC_GROUP_NAME_ID_L3 * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DATA_PORT * 0x10000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 26 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$$ShaderMemoryAccesses 64 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL $EuDualSubslicesTotalCount UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ShaderBarriers", "Shader Barrier Messages",
                          "The total number of shader barrier messages.",
                          "EU Array/Barrier", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_EU_BARRIER * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "messages", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 27 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x9c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x128" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = "$SliceMask 1 AND";
        metric               = AddMetric( "Rasterizer0InputAvailable", "Slice0 Rasterizer Input Available",
                          "The percentage of time in which slice0 rasterizer input is available",
                          "GPU/Rasterizer", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_WM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 28 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x130" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$SliceMask 1 AND";
        metric               = AddMetric( "Rasterizer0OutputReady", "Slice0 Rasterizer Output Ready",
                          "The percentage of time in which slice0 rasterizer output is ready",
                          "GPU/Rasterizer", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_WM * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 29 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xec" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x188" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PixelData00Ready", "Slice0 Pipe0 Post-EarlyZ Pixel Data Ready",
                          "The percentage of time in which slice0  pipe0 post-EarlyZ pixel data is ready (after early Z tests have been applied)",
                          "GPU/Rasterizer/Early Depth Test", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_WM * 0x10000 ) | ( METRIC_GROUP_NAME_ID_IZ * 0x100 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, "Pixel|Fragment,pixel|fragment", nullptr, 30 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x138" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PSOutput00Available", "Slice0 Pipe0 PS Output Available",
                          "The percentage of time in which slice0 pipe0 PS output is available",
                          "GPU/3D Pipe", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, "PS|FS", nullptr, 31 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x180" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PSOutput01Available", "Slice0 Pipe1 PS Output Available",
                          "The percentage of time in which slice0 pipe1 PS output is available",
                          "GPU/3D Pipe", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, "PS|FS", nullptr, 32 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x178" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PSOutput02Available", "Slice0 Pipe2 PS Output Available",
                          "The percentage of time in which slice0 pipe2 PS output is available",
                          "GPU/3D Pipe", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, "PS|FS", nullptr, 33 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x170" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PixelValues00Ready", "Slice0 Pipe0 Pixel Values Ready",
                          "The percentage of time in which slice0 pipe0 pixel values are ready",
                          "GPU/3D Pipe", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, "Pixel|Fragment,pixel|fragment", nullptr, 34 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xdc" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x168" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PixelValues01Ready", "Slice0 Pipe1 Pixel Values Ready",
                          "The percentage of time in which slice0 pipe1 pixel values are ready",
                          "GPU/3D Pipe", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, "Pixel|Fragment,pixel|fragment", nullptr, 35 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xd8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x160" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PixelValues02Ready", "Slice0 Pipe2 Pixel Values Ready",
                          "The percentage of time in which slice0 pipe2 pixel values are ready",
                          "GPU/3D Pipe", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_3D_PIPE * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, "Pixel|Fragment,pixel|fragment", nullptr, 36 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xd4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x158" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GTRequestQueue00Full", "SQ00 is full",
                          "The percentage of time when IDI0 SQ0 is filled above a threshold (usually 48 entries)",
                          "GTI", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 37 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xf0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x190" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GTRequestQueue01Full", "SQ01 is full",
                          "The percentage of time when IDI0 SQ1 is filled above a threshold (usually 48 entries)",
                          "GTI", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 38 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xf4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x198" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GTRequestQueue10Full", "SQ10 is full",
                          "The percentage of time when IDI1 SQ0 is filled above a threshold (usually 48 entries)",
                          "GTI", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 39 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xf8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1a0" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GTRequestQueue11Full", "SQ11 is full",
                          "The percentage of time when IDI1 SQ1 is filled above a threshold (usually 48 entries)",
                          "GTI", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 40 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xfc" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1a8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e075000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a0700c0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e055000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a0500c0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e065000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a0600c0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2a0a7300, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2c0a0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x120800a0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a07c000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e070027, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10070000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x24070000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2a032000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2c030008, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18006000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x360036d8, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x38003299, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a004000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c006000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2a010400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2c010001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c05c000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00052700, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10050000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x24050000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x22050000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c0600c0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e062700, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10060000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x24060000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x26060000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x000a0144, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e0a0145, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x100a0156, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x040a014f, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x200a0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x120a4000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x140a4000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x180a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08081980, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a080032, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10080000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x31152800, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x331500a0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x31352800, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x333500a0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x41104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5b105fa5, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5d101555, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17144000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d14aaa0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f14002a, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1b140a00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0f124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x11124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x13124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x15124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x19124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1b124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07150016, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09150096, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01150000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03168000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0b350016, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0d350096, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01350000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07364000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x47100400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4d100010, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4f100404, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x51100202, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x53100002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x55100204, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x57100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x49101404, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4b101010, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x30800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc40, 0x00030000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd940, 0x00000038, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd944, 0x0000fff8, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc00, 0x00000038, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc04, 0x0000fff8, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd948, 0x000000c0, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd94c, 0x0000ffe7, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc08, 0x000000c0, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc0c, 0x0000ffe7, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00804704, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a04904, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00805705, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a05905, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00808708, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a08908, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CL3_1MetricSet::CL3_1MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CL3_1MetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuActive", "EU Active",
                          "The percentage of time in which the Execution Units were actively processing.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuStall", "EU Stall",
                          "The percentage of time in which the Execution Units were stalled.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
                          "The percentage of time in which hardware threads occupied EUs.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "8 rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "8 qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = "$SliceMask 1 AND";
        metric               = AddMetric( "L30Bank0InputAvailable", "Slice0 L3 Bank0 Input Available",
                          "The percentage of time in which slice0 L3 bank0 has input available",
                          "GTI/L3", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_L3 * 0x10000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xfc dw@0xf8 FADD dw@0xf4 FADD dw@0xf0 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1a8 qw@0x1a0 FADD qw@0x198 FADD qw@0x190 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$SliceMask 1 AND";
        metric               = AddMetric( "L30Bank1InputAvailable", "Slice0 L3 Bank1 Input Available",
                          "The percentage of time in which slice0 L3 bank1 has input available",
                          "GTI/L3", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_L3 * 0x10000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 14 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xec dw@0xe8 FADD dw@0xe4 FADD dw@0xe0 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x188 qw@0x180 FADD qw@0x178 FADD qw@0x170 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$SliceMask 1 AND";
        metric               = AddMetric( "L30Bank4InputAvailable", "Slice0 L3 Bank4 Input Available",
                          "The percentage of time in which slice0 L3 bank4 has input available",
                          "GTI/L3", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_L3 * 0x10000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 15 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xcc dw@0xc8 FADD dw@0xc4 FADD dw@0xc0 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x148 qw@0x140 FADD qw@0x138 FADD qw@0x130 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$SliceMask 1 AND";
        metric               = AddMetric( "L30Bank5InputAvailable", "Slice0 L3 Bank5 Input Available",
                          "The percentage of time in which slice0 L3 bank5 has input available",
                          "GTI/L3", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_L3 * 0x10000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 16 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xdc dw@0xd8 FADD dw@0xd4 FADD dw@0xd0 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x168 qw@0x160 FADD qw@0x158 FADD qw@0x150 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04022000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06022800, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04002827, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0600202c, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00020024, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e020025, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10020026, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x12020027, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1402002c, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1602002d, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1802002e, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a02002f, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2e020000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2c020000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00034000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a032000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c032000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e032000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2a035500, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c000024, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e000025, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02000026, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0800002d, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a00002e, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c00002f, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x360036d8, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18006000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x380000db, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x34000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x000a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x100a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x120a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x140a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x160a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x180a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x41104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5b105555, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5d101555, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17144000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d14aaaa, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f14002a, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1b14aa00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0f124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x11124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x13124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x15124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x19124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1b124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0b124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0d124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x47100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4d100606, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4f100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x51100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x53100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x55100600, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x57100006, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x49100606, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4b100606, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc40, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00804704, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a04904, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00805705, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a05905, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00808708, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a08908, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CL3_2MetricSet::CL3_2MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CL3_2MetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuActive", "EU Active",
                          "The percentage of time in which the Execution Units were actively processing.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuStall", "EU Stall",
                          "The percentage of time in which the Execution Units were stalled.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
                          "The percentage of time in which hardware threads occupied EUs.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "8 rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "8 qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$SliceMask 1 AND";
        metric               = AddMetric( "L30Bank2InputAvailable", "Slice0 L3 Bank2 Input Available",
                          "The percentage of time in which slice0 L3 bank2 has input available",
                          "GTI/L3", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_L3 * 0x10000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xcc dw@0xc8 FADD dw@0xc4 FADD dw@0xc0 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x148 qw@0x140 FADD qw@0x138 FADD qw@0x130 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$SliceMask 1 AND";
        metric               = AddMetric( "L30Bank3InputAvailable", "Slice0 L3 Bank3 Input Available",
                          "The percentage of time in which slice0 L3 bank3 has input available",
                          "GTI/L3", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_L3 * 0x10000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 14 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xdc dw@0xd8 FADD dw@0xd4 FADD dw@0xd0 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x168 qw@0x160 FADD qw@0x158 FADD qw@0x150 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$SliceMask 1 AND";
        metric               = AddMetric( "L30Bank6InputAvailable", "Slice0 L3 Bank6 Input Available",
                          "The percentage of time in which slice0 L3 bank6 has input available",
                          "GTI/L3", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_L3 * 0x10000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 15 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xec dw@0xe8 FADD dw@0xe4 FADD dw@0xe0 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x188 qw@0x180 FADD qw@0x178 FADD qw@0x170 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$SliceMask 1 AND";
        metric               = AddMetric( "L30Bank7InputAvailable", "Slice0 L3 Bank7 Input Available",
                          "The percentage of time in which slice0 L3 bank7 has input available",
                          "GTI/L3", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_L3 * 0x10000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 16 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xfc dw@0xf8 FADD dw@0xf4 FADD dw@0xf0 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1a8 qw@0x1a0 FADD qw@0x198 FADD qw@0x190 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04023027, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0602382c, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04003000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06003800, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c020024, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e020025, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02020026, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0802002d, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a02002e, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c02002f, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2e020000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2c030005, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02034000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04034000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06034000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08034000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a034000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18032000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00000024, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e000025, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10000026, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x12000027, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1400002c, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1600002d, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1800002e, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a00602f, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x36000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x38003600, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c006000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e006000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x34001b00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x020a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x040a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x060a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x080a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x41104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5b105555, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5d101555, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17144000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d14aaaa, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f14002a, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1b14aa00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0f124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x11124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x13124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x15124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x19124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1b124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0b124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0d124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x47100600, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4d100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4f100606, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x51100606, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x53100606, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x55100006, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x57100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x49100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4b100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc40, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00804704, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a04904, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00805705, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a05905, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00808708, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a08908, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CL3_3MetricSet::CL3_3MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CL3_3MetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuActive", "EU Active",
                          "The percentage of time in which the Execution Units were actively processing.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuStall", "EU Stall",
                          "The percentage of time in which the Execution Units were stalled.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
                          "The percentage of time in which hardware threads occupied EUs.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "8 rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "8 qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$SliceMask 1 AND";
        metric               = AddMetric( "L30Bank0OutputReady", "Slice0 L3 Bank0 Output Ready",
                          "The percentage of time in which slice0 L3 bank0 output is ready",
                          "GTI/L3", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_L3 * 0x10000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xfc dw@0xf8 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1a8 qw@0x1a0 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$SliceMask 1 AND";
        metric               = AddMetric( "L30Bank4OutputReady", "Slice0 L3 Bank4 Output Ready",
                          "The percentage of time in which slice0 L3 bank4 output is ready",
                          "GTI/L3", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_L3 * 0x10000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 14 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xf4 dw@0xf0 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x198 qw@0x190 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04020200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06020020, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08020028, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2e020000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06034000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08034000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a000020, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c000028, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x36000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e006000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x34000300, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x060a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x080a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5b100550, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1b14a000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d14000a, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0b124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0d124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x49100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4b100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4d100606, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc40, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00804704, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a04904, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00805705, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a05905, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00808708, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a08908, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CL3_4MetricSet::CL3_4MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CL3_4MetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuActive", "EU Active",
                          "The percentage of time in which the Execution Units were actively processing.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuStall", "EU Stall",
                          "The percentage of time in which the Execution Units were stalled.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
                          "The percentage of time in which hardware threads occupied EUs.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "8 rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "8 qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$SliceMask 1 AND";
        metric               = AddMetric( "L30Bank1OutputReady", "Slice0 L3 Bank1 Output Ready",
                          "The percentage of time in which slice0 L3 bank1 output is ready",
                          "GTI/L3", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_L3 * 0x10000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xf4 dw@0xf0 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x198 qw@0x190 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$SliceMask 1 AND";
        metric               = AddMetric( "L30Bank5OutputReady", "Slice0 L3 Bank5 Output Ready",
                          "The percentage of time in which slice0 L3 bank5 output is ready",
                          "GTI/L3", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_L3 * 0x10000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 14 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xfc dw@0xf8 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1a8 qw@0x1a0 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04020a00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06020800, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04000a00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06000820, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a020020, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c020028, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2e020000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a034000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18032000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08000028, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x36000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x34001800, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5b100550, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1b14a000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d14000a, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0b124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0d124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x49100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4b100606, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4d100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc40, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00804704, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a04904, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00805705, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a05905, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00808708, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a08908, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CL3_5MetricSet::CL3_5MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CL3_5MetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuActive", "EU Active",
                          "The percentage of time in which the Execution Units were actively processing.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuStall", "EU Stall",
                          "The percentage of time in which the Execution Units were stalled.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
                          "The percentage of time in which hardware threads occupied EUs.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "8 rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "8 qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$SliceMask 1 AND";
        metric               = AddMetric( "L30Bank2OutputReady", "Slice0 L3 Bank2 Output Ready",
                          "The percentage of time in which slice0 L3 bank2 output is ready",
                          "GTI/L3", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_L3 * 0x10000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xf4 dw@0xf0 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x198 qw@0x190 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$SliceMask 1 AND";
        metric               = AddMetric( "L30Bank6OutputReady", "Slice0 L3 Bank6 Output Ready",
                          "The percentage of time in which slice0 L3 bank6 output is ready",
                          "GTI/L3", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_L3 * 0x10000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 14 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xfc dw@0xf8 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1a8 qw@0x1a0 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04021200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06021000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04001200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06001020, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a020020, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c020028, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2e020000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a034000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18032000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08000028, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x36000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x34001800, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5b100550, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1b14a000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d14000a, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0b124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0d124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x49100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4b100606, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4d100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc40, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00804704, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a04904, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00805705, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a05905, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00808708, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a08908, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CL3_6MetricSet::CL3_6MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CL3_6MetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuActive", "EU Active",
                          "The percentage of time in which the Execution Units were actively processing.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuStall", "EU Stall",
                          "The percentage of time in which the Execution Units were stalled.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
                          "The percentage of time in which hardware threads occupied EUs.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "8 rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "8 qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$SliceMask 1 AND";
        metric               = AddMetric( "L30Bank3OutputReady", "Slice0 L3 Bank3 Output Ready",
                          "The percentage of time in which slice0 L3 bank3 output is ready",
                          "GTI/L3", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_L3 * 0x10000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xf4 dw@0xf0 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x198 qw@0x190 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$SliceMask 1 AND";
        metric               = AddMetric( "L30Bank7OutputReady", "Slice0 L3 Bank7 Output Ready",
                          "The percentage of time in which slice0 L3 bank7 output is ready",
                          "GTI/L3", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_L3 * 0x10000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SLICE, availabilityEquation, nullptr, nullptr, 14 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xfc dw@0xf8 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1a8 qw@0x1a0 FADD 4 FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04021a00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06021800, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04001a00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06001820, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a020020, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c020028, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2e020000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a034000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18032000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08000028, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x36000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x34001800, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5b100550, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1b14a000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d14000a, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0b124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0d124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x49100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4b100606, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4d100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc40, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00804704, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a04904, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00805705, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a05905, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00808708, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a08908, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CSampler_1MetricSet::CSampler_1MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CSampler_1MetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuActive", "EU Active",
                          "The percentage of time in which the Execution Units were actively processing.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuStall", "EU Stall",
                          "The percentage of time in which the Execution Units were stalled.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
                          "The percentage of time in which hardware threads occupied EUs.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "8 rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "8 qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 1 AND";
        metric               = AddMetric( "Sampler00InputAvailable", "Slice0 DualSubslice0 Input Available",
                          "The percentage of time in which slice0 dualsubslice0 sampler input is available",
                          "GPU/Sampler", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SAMPLER * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xd4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x158" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 2 AND";
        metric               = AddMetric( "Sampler01InputAvailable", "Slice0 DualSubslice1 Input Available",
                          "The percentage of time in which slice0 dualsubslice1 sampler input is available",
                          "GPU/Sampler", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SAMPLER * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 14 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xd0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x150" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 4 AND";
        metric               = AddMetric( "Sampler02InputAvailable", "Slice0 DualSubslice2 Input Available",
                          "The percentage of time in which slice0 dualsubslice2 sampler input is available",
                          "GPU/Sampler", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SAMPLER * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 15 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xcc" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x148" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 8 AND";
        metric               = AddMetric( "Sampler03InputAvailable", "Slice0 DualSubslice3 Input Available",
                          "The percentage of time in which slice0 dualsubslice3 sampler input is available",
                          "GPU/Sampler", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SAMPLER * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 16 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x140" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 16 AND";
        metric               = AddMetric( "Sampler04InputAvailable", "Slice0 DualSubslice4 Input Available",
                          "The percentage of time in which slice0 dualsubslice4 sampler input is available",
                          "GPU/Sampler", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SAMPLER * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 17 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x138" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 32 AND";
        metric               = AddMetric( "Sampler05InputAvailable", "Slice0 DualSubslice5 Input Available",
                          "The percentage of time in which slice0 dualsubslice5 sampler input is available",
                          "GPU/Sampler", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SAMPLER * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 18 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x130" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c121600, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18141600, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c325600, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18341600, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c521600, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x185416a6, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c721600, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18741600, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c921600, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18941600, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1cb21600, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18b41600, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c07c000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2407002b, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04120086, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x20120000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x12138000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x14138000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x021400a6, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10140000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00140000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a150020, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e320086, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x20320000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e330003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c3400a6, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10340000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e340000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c358000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a520086, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x20520000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18524000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c53c000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10540000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c540000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c550800, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x16720086, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x20720000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x14724000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c733000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x147400a6, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10740000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a740000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c750080, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x12920086, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x20920000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10924000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c930c00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x109400a6, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08940000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c950008, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0eb20086, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x20b20000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00b24000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10b38000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1cb30200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00b400a6, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10b40000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18b58000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0f0028, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x14104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x16104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2c024000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2e020001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2a03a500, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18002000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x36003248, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x380024db, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a004000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c004000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00014000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a012000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c012000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e012000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2405c000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x26050003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x220500a0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x24062800, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x140a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x160a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x180a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x41104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5b105005, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5d101555, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17144000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d14aaa0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f14002a, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1b140a00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0f124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x11124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x13124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x15124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x19124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1b124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x47100600, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4d100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4f10060a, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5110000a, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x53100404, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x55101808, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x57100001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x49100118, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0xf0800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x30800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc40, 0x003f0000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd940, 0x00000018, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd944, 0x0000fffc, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc00, 0x00000018, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc04, 0x0000fffc, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd948, 0x00000060, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd94c, 0x0000fff3, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc08, 0x00000060, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc0c, 0x0000fff3, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd950, 0x00000180, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd954, 0x0000ffcf, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc10, 0x00000180, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc14, 0x0000ffcf, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd958, 0x00000600, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd95c, 0x0000ff3f, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc18, 0x00000600, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc1c, 0x0000ff3f, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd960, 0x00001800, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd964, 0x0000fcff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc20, 0x00001800, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc24, 0x0000fcff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd968, 0x00006000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd96c, 0x0000f3ff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc28, 0x00006000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc2c, 0x0000f3ff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00804704, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a04904, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00805705, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a05905, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00808708, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a08908, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CSampler_2MetricSet::CSampler_2MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CSampler_2MetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuActive", "EU Active",
                          "The percentage of time in which the Execution Units were actively processing.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuStall", "EU Stall",
                          "The percentage of time in which the Execution Units were stalled.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
                          "The percentage of time in which hardware threads occupied EUs.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "8 rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "8 qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 1 AND";
        metric               = AddMetric( "Sampler00OutputReady", "Slice0 DualSubslice0 Sampler Output Ready",
                          "The percentage of time in which slice0 dualsubslice0 sampler output is ready",
                          "GPU/Sampler", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SAMPLER * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, nullptr, nullptr, 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xd4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x158" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 2 AND";
        metric               = AddMetric( "Sampler01OutputReady", "Slice0 DualSubslice1 Sampler Output Ready",
                          "The percentage of time in which slice0 dualsubslice1 sampler output is ready",
                          "GPU/Sampler", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SAMPLER * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, nullptr, nullptr, 14 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xd0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x150" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 4 AND";
        metric               = AddMetric( "Sampler02OutputReady", "Slice0 DualSubslice2 Sampler Output Ready",
                          "The percentage of time in which slice0 dualsubslice2 sampler output is ready",
                          "GPU/Sampler", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SAMPLER * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, nullptr, nullptr, 15 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xcc" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x148" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 8 AND";
        metric               = AddMetric( "Sampler03OutputReady", "Slice0 DualSubslice3 Sampler Output Ready",
                          "The percentage of time in which slice0 dualsubslice3 sampler output is ready",
                          "GPU/Sampler", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SAMPLER * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, nullptr, nullptr, 16 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x140" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 16 AND";
        metric               = AddMetric( "Sampler04OutputReady", "Slice0 DualSubslice4 Sampler Output Ready",
                          "The percentage of time in which slice0 dualsubslice4 sampler output is ready",
                          "GPU/Sampler", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SAMPLER * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, nullptr, nullptr, 17 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x138" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 32 AND";
        metric               = AddMetric( "Sampler05OutputReady", "Slice0 DualSubslice5 Sampler Output Ready",
                          "The percentage of time in which slice0 dualsubslice5 sampler output is ready",
                          "GPU/Sampler", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_SAMPLER * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_SUBSLICE, availabilityEquation, nullptr, nullptr, 18 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x130" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c123e00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04143e00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c323e00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04343e00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c523e00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04543e00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c723e00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04743e00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c923e00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04943e00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0cb23e00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04b43e00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c07c000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2407002b, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04120033, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x20120000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x12138000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x14138000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02140013, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10140000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00140000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a150020, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e320033, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x20320000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c324000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e330003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c340013, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10340000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e340000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c358000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a520033, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x20520000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18524000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c53c000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18540013, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10540000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c540000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c550800, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x16720033, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x20720000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x14724000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c733000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x14740013, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10740000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a740000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c750080, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x12920033, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x20920000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10924000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c930c00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10940013, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08940000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c950008, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0eb20033, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x20b20000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00b24000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10b38000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1cb30200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00b40013, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10b40000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18b58000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0f0028, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x14104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x16104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2c024000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2e020001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2a03a500, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18002000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x36003248, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x380024db, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a004000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c004000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00014000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a012000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c012000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e012000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2405c000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x26050003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x220500a0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x24062800, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x140a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x160a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x180a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x41104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5b105005, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5d101555, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17144000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d14aaa0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f14002a, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1b140a00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0f124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x11124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x13124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x15124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x19124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1b124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x47100600, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4d100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4f10060a, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5110000a, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x53100404, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x55101808, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x57100001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x49100118, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0xf0800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x30800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc40, 0x003f0000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd940, 0x00000018, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd944, 0x0000fffc, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc00, 0x00000018, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc04, 0x0000fffc, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd948, 0x00000060, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd94c, 0x0000fff3, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc08, 0x00000060, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc0c, 0x0000fff3, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd950, 0x00000180, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd954, 0x0000ffcf, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc10, 0x00000180, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc14, 0x0000ffcf, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd958, 0x00000600, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd95c, 0x0000ff3f, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc18, 0x00000600, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc1c, 0x0000ff3f, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd960, 0x00001800, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd964, 0x0000fcff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc20, 0x00001800, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc24, 0x0000fcff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd968, 0x00006000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd96c, 0x0000f3ff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc28, 0x00006000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc2c, 0x0000f3ff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00804704, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a04904, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00805705, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a05905, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00808708, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a08908, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CTDL_1MetricSet::CTDL_1MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CTDL_1MetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuActive", "EU Active",
                          "The percentage of time in which the Execution Units were actively processing.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuStall", "EU Stall",
                          "The percentage of time in which the Execution Units were stalled.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
                          "The percentage of time in which hardware threads occupied EUs.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "8 rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "8 qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 1 AND";
        metric               = AddMetric( "NonPSThread00ReadyForDispatch", "Non-PS Thread Ready For Dispatch on Slice0 DualSubslice0 Thread Dispatcher",
                          "The percentage of time in which non-PS thread is ready for dispatch on slice0 dualsubslice0 thread dispatcher",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, "PS|FS", nullptr, 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xd4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x158" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 2 AND";
        metric               = AddMetric( "NonPSThread01ReadyForDispatch", "Non-PS Thread Ready For Dispatch on Slice0 DualSubslice1 Thread Dispatcher",
                          "The percentage of time in which non-PS thread is ready for dispatch on slice0 dualsubslice1 thread dispatcher",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, "PS|FS", nullptr, 14 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xd0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x150" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 4 AND";
        metric               = AddMetric( "NonPSThread02ReadyForDispatch", "Non-PS Thread Ready For Dispatch on Slice0 DualSubslice2 Thread Dispatcher",
                          "The percentage of time in which non-PS thread is ready for dispatch on slice0 dualsubslice2 thread dispatcher",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, "PS|FS", nullptr, 15 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xcc" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x148" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 8 AND";
        metric               = AddMetric( "NonPSThread03ReadyForDispatch", "Non-PS Thread Ready For Dispatch on Slice0 DualSubslice3 Thread Dispatcher",
                          "The percentage of time in which non-PS thread is ready for dispatch on slice0 dualsubslice3 thread dispatcher",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, "PS|FS", nullptr, 16 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x140" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 16 AND";
        metric               = AddMetric( "NonPSThread04ReadyForDispatch", "Non-PS Thread Ready For Dispatch on Slice0 DualSubslice4 Thread Dispatcher",
                          "The percentage of time in which non-PS thread is ready for dispatch on slice0 dualsubslice4 thread dispatcher",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, "PS|FS", nullptr, 17 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x138" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 32 AND";
        metric               = AddMetric( "NonPSThread05ReadyForDispatch", "Non-PS Thread Ready For Dispatch on Slice0 DualSubslice5 Thread Dispatcher",
                          "The percentage of time in which non-PS thread is ready for dispatch on slice0 dualsubslice5 thread dispatcher",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, "PS|FS", nullptr, 18 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x130" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 1 AND";
        metric               = AddMetric( "ThreadHeader00ReadyPort0", "Thread Header Ready on Slice0 DualSubslice0 Thread Dispatcher Port 0",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice0 thread dispatcher port 0",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 19 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x170" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 1 AND";
        metric               = AddMetric( "ThreadHeader00ReadyPort1", "Thread Header Ready on Slice0 DualSubslice0 Thread Dispatcher Port 1",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice0 thread dispatcher port 1",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 20 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x178" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 1 AND";
        metric               = AddMetric( "ThreadHeader00ReadyPort2", "Thread Header Ready on Slice0 DualSubslice0 Thread Dispatcher Port 2",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice0 thread dispatcher port 2",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 21 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x180" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 1 AND";
        metric               = AddMetric( "ThreadHeader00ReadyPort3", "Thread Header Ready on Slice0 DualSubslice0 Thread Dispatcher Port 3",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice0 thread dispatcher port 3",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 22 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xec" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x188" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 2 AND";
        metric               = AddMetric( "ThreadHeader01ReadyPort0", "Thread Header Ready on Slice0 DualSubslice1 Thread Dispatcher Port 0",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice1 thread dispatcher port 0",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 23 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xf0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x190" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 2 AND";
        metric               = AddMetric( "ThreadHeader01ReadyPort1", "Thread Header Ready on Slice0 DualSubslice1 Thread Dispatcher Port 1",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice1 thread dispatcher port 1",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 24 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xf4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x198" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 2 AND";
        metric               = AddMetric( "ThreadHeader01ReadyPort2", "Thread Header Ready on Slice0 DualSubslice1 Thread Dispatcher Port 2",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice1 thread dispatcher port 2",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 25 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xf8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1a0" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 2 AND";
        metric               = AddMetric( "ThreadHeader01ReadyPort3", "Thread Header Ready on Slice0 DualSubslice1 Thread Dispatcher Port 3",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice1 thread dispatcher port 3",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 26 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xfc" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1a8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 1 AND";
        metric               = AddMetric( "ThreadHeader00Ready", "Thread Header Ready on Slice0 DualSubslice0 Thread Dispatcher",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice0 thread dispatcher",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 27 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xd8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x160" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 2 AND";
        metric               = AddMetric( "ThreadHeader01Ready", "Thread Header Ready on Slice0 DualSubslice1 Thread Dispatcher",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice1 thread dispatcher",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 28 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xdc" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x168" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2611001c, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2631001c, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2651001c, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2671001c, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2691001c, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x26b1001c, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c07c000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x24070002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x16110103, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c110104, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e110105, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02110106, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04110107, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10110000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a110000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e110000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00110000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x16128000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c128000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e128000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02128000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04128000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c132000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e130003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x12138000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x14138000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x14310103, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06310104, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08310105, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a310106, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c310107, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10310000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02310000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04310000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x14328000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06328000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08328000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a328000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c328000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c331100, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x16338000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18338000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a338000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x12510103, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10510000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08510000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x12528000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c530800, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10710103, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08710000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10728000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c730400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e910103, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10910000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06910000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e928000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c930200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00b10103, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10b10000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00b28000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10b38000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c0f8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10024000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c032000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e034000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18002000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x360026ca, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x38002402, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a004000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c004000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e004000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x34001200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00014000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a012000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x240582c0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x26050002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2205ffa0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x24060020, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x100a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x120a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x41104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5b105555, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5d101415, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17144000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d142aaa, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f140028, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1b14aa00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0f124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x11124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x13124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x15124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0b124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0d124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x47100600, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4d100808, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4f100006, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x51100804, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x53100008, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x55100800, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x57100008, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x49100808, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4b100808, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0xf0800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0xf0800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc40, 0x00ff0000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd940, 0x00000002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd944, 0x0000fffe, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc00, 0x00000002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc04, 0x0000fffe, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd948, 0x00000002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd94c, 0x0000fffd, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc08, 0x00000002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc0c, 0x0000fffd, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd950, 0x00000002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd954, 0x0000fffb, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc10, 0x00000002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc14, 0x0000fffb, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd958, 0x00000002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd95c, 0x0000fff7, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc18, 0x00000002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc1c, 0x0000fff7, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd960, 0x00000002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd964, 0x0000ffef, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc20, 0x00000002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc24, 0x0000ffef, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd968, 0x00000002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd96c, 0x0000ffdf, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc28, 0x00000002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc2c, 0x0000ffdf, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd970, 0x00007800, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd974, 0x0000f0ff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc30, 0x00007800, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc34, 0x0000f0ff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd978, 0x00078000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd97c, 0x00000fff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc38, 0x00078000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc3c, 0x00000fff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00804704, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a04904, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00805705, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a05905, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00808708, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a08908, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CTDL_2MetricSet::CTDL_2MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CTDL_2MetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuActive", "EU Active",
                          "The percentage of time in which the Execution Units were actively processing.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuStall", "EU Stall",
                          "The percentage of time in which the Execution Units were stalled.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
                          "The percentage of time in which hardware threads occupied EUs.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "8 rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "8 qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 1 AND";
        metric               = AddMetric( "PSThread00ReadyForDispatch", "PS Thread Ready For Dispatch on Slice0 Dualsubslice0 Thread Dispatcher",
                          "The percentage of time in which PS thread is ready for dispatch on slice0 dualsubslice0 thread dispatcher",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, "PS|FS", nullptr, 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xd4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x158" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 2 AND";
        metric               = AddMetric( "PSThread01ReadyForDispatch", "PS Thread Ready For Dispatch on Slice0 Dualsubslice1 Thread Dispatcher",
                          "The percentage of time in which PS thread is ready for dispatch on slice0 dualsubslice1 thread dispatcher",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, "PS|FS", nullptr, 14 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xd0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x150" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 4 AND";
        metric               = AddMetric( "PSThread02ReadyForDispatch", "PS Thread Ready For Dispatch on Slice0 Dualsubslice2 Thread Dispatcher",
                          "The percentage of time in which PS thread is ready for dispatch on slice0 dualsubslice2 thread dispatcher",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, "PS|FS", nullptr, 15 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xcc" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x148" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 8 AND";
        metric               = AddMetric( "PSThread03ReadyForDispatch", "PS Thread Ready For Dispatch on Slice0 Dualsubslice3 Thread Dispatcher",
                          "The percentage of time in which PS thread is ready for dispatch on slice0 dualsubslice3 thread dispatcher",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, "PS|FS", nullptr, 16 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x140" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 16 AND";
        metric               = AddMetric( "PSThread04ReadyForDispatch", "PS Thread Ready For Dispatch on Slice0 Dualsubslice4 Thread Dispatcher",
                          "The percentage of time in which PS thread is ready for dispatch on slice0 dualsubslice4 thread dispatcher",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, "PS|FS", nullptr, 17 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x138" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 32 AND";
        metric               = AddMetric( "PSThread05ReadyForDispatch", "PS Thread Ready For Dispatch on Slice0 Dualsubslice5 Thread Dispatcher",
                          "The percentage of time in which PS thread is ready for dispatch on slice0 dualsubslice5 thread dispatcher",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, "PS|FS", nullptr, 18 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x130" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 32 AND";
        metric               = AddMetric( "ThreadHeader05Ready", "Thread Header Ready on Slice0 DualSubslice5 Thread Dispatcher",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice5 thread dispatcher",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 19 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xd8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x160" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 32 AND";
        metric               = AddMetric( "ThreadHeader05ReadyPort0", "Thread Header Ready on Slice0 DualSubslice5 Thread Dispatcher Port 0",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice5 thread dispatcher port 0",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 20 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xf0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x190" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 32 AND";
        metric               = AddMetric( "ThreadHeader05ReadyPort1", "Thread Header Ready on Slice0 DualSubslice5 Thread Dispatcher Port 1",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice5 thread dispatcher port 1",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 21 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xf4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x198" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 32 AND";
        metric               = AddMetric( "ThreadHeader05ReadyPort2", "Thread Header Ready on Slice0 DualSubslice5 Thread Dispatcher Port 2",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice5 thread dispatcher port 2",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 22 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xf8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1a0" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 32 AND";
        metric               = AddMetric( "ThreadHeader05ReadyPort3", "Thread Header Ready on Slice0 DualSubslice5 Thread Dispatcher Port 3",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice5 thread dispatcher port 3",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 23 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xfc" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1a8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x24110340, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x24310340, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x24510340, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x24710340, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x24910340, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x24b10340, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x26b1001c, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c07c000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2407002b, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2207ff00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x021100f3, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x041100f2, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10110000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00110000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02128000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04128000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x12138000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x14138000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c3100f3, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e3100f2, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10310000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e310000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c328000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e328000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e330003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x185100f3, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a5100f2, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10510000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c510000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18528000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a528000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c53c000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x147100f3, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x167100f2, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10710000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a710000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x14728000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x16728000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c733000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x109100f3, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x129100f2, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08910000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10928000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x12928000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c930c00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00b100f3, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0eb100f2, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06b10104, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08b10105, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0ab10106, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0cb10107, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10b10000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02b10000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04b10000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00b28000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0eb28000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06b28000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08b28000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0ab28000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0cb28000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10b38000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1cb30300, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x16b38000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18b38000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1ab38000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0f0028, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x14104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x16104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2c024000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2e020001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2a03a500, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18002000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x36003249, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x380024db, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a004000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c004000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e002000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x34000900, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00014000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a012000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c012000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e012000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06014000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08014000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a014000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18012000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2405c000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x26050003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x220500a0, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x24062800, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x140a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x160a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x180a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x41104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5b105555, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5d101555, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17144000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d14aaaa, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f14002a, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1b14aa00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0f124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x11124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x13124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x15124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x19124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1b124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0b124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0d124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x47100600, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4d100606, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4f100606, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x51100006, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x53100400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x55100804, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x57100008, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x49100808, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4b100606, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0xf0800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x70800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc40, 0x007f0000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd940, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd944, 0x0000fffc, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc00, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc04, 0x0000fffc, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd948, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd94c, 0x0000fff3, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc08, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc0c, 0x0000fff3, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd950, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd954, 0x0000ffcf, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc10, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc14, 0x0000ffcf, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd958, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd95c, 0x0000ff3f, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc18, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc1c, 0x0000ff3f, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd960, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd964, 0x0000fcff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc20, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc24, 0x0000fcff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd968, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd96c, 0x0000f3ff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc28, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc2c, 0x0000f3ff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd970, 0x00078000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd974, 0x00000fff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc30, 0x00078000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc34, 0x00000fff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00804704, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a04904, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00805705, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a05905, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00808708, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a08908, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CTDL_3MetricSet::CTDL_3MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CTDL_3MetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuActive", "EU Active",
                          "The percentage of time in which the Execution Units were actively processing.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuStall", "EU Stall",
                          "The percentage of time in which the Execution Units were stalled.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
                          "The percentage of time in which hardware threads occupied EUs.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "8 rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "8 qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 4 AND";
        metric               = AddMetric( "ThreadHeader02Ready", "Thread Header Ready on Slice0 DualSubslice2 Thread Dispatcher",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice2 thread dispatcher",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x130" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 8 AND";
        metric               = AddMetric( "ThreadHeader03Ready", "Thread Header Ready on Slice0 DualSubslice3 Thread Dispatcher",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice3 thread dispatcher",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 14 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x138" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 16 AND";
        metric               = AddMetric( "ThreadHeader04Ready", "Thread Header Ready on Slice0 DualSubslice4 Thread Dispatcher",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice4 thread dispatcher",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 15 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x140" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 4 AND";
        metric               = AddMetric( "ThreadHeader02ReadyPort0", "Thread Header Ready on Slice0 DualSubslice2 Thread Dispatcher Port 0",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice2 thread dispatcher port 0",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 16 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xfc" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1a8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 4 AND";
        metric               = AddMetric( "ThreadHeader02ReadyPort1", "Thread Header Ready on Slice0 DualSubslice2 Thread Dispatcher Port 1",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice2 thread dispatcher port 1",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 17 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xf8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1a0" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 4 AND";
        metric               = AddMetric( "ThreadHeader02ReadyPort2", "Thread Header Ready on Slice0 DualSubslice2 Thread Dispatcher Port 2",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice2 thread dispatcher port 2",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 18 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xf4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x198" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 4 AND";
        metric               = AddMetric( "ThreadHeader02ReadyPort3", "Thread Header Ready on Slice0 DualSubslice2 Thread Dispatcher Port 3",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice2 thread dispatcher port 3",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 19 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xf0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x190" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 8 AND";
        metric               = AddMetric( "ThreadHeader03ReadyPort0", "Thread Header Ready on Slice0 DualSubslice3 Thread Dispatcher Port 0",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice3 thread dispatcher port 0",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 20 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xec" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x188" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 8 AND";
        metric               = AddMetric( "ThreadHeader03ReadyPort1", "Thread Header Ready on Slice0 DualSubslice3 Thread Dispatcher Port 1",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice3 thread dispatcher port 1",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 21 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x180" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 8 AND";
        metric               = AddMetric( "ThreadHeader03ReadyPort2", "Thread Header Ready on Slice0 DualSubslice3 Thread Dispatcher Port 2",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice3 thread dispatcher port 2",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 22 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x178" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 8 AND";
        metric               = AddMetric( "ThreadHeader03ReadyPort3", "Thread Header Ready on Slice0 DualSubslice3 Thread Dispatcher Port 3",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice3 thread dispatcher port 3",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 23 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x170" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 16 AND";
        metric               = AddMetric( "ThreadHeader04ReadyPort0", "Thread Header Ready on Slice0 DualSubslice4 Thread Dispatcher Port 0",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice4 thread dispatcher port 0",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 24 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xdc" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x168" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 16 AND";
        metric               = AddMetric( "ThreadHeader04ReadyPort1", "Thread Header Ready on Slice0 DualSubslice4 Thread Dispatcher Port 1",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice4 thread dispatcher port 1",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 25 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xd8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x160" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 16 AND";
        metric               = AddMetric( "ThreadHeader04ReadyPort2", "Thread Header Ready on Slice0 DualSubslice4 Thread Dispatcher Port 2",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice4 thread dispatcher port 2",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 26 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xd4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x158" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = "$DualSubsliceMask 16 AND";
        metric               = AddMetric( "ThreadHeader04ReadyPort3", "Thread Header Ready on Slice0 DualSubslice4 Thread Dispatcher Port 3",
                          "The percentage of time in which thread header is ready on slice0 dualsubslice4 thread dispatcher port 3",
                          "GPU/Thread Dispatcher", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_TD * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_DUALSUBSLICE, availabilityEquation, nullptr, nullptr, 27 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xd0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x150" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2651001c, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2671001c, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2691001c, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x24072a80, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06510107, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08510106, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a510105, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c510104, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10510000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02510000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04510000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06528000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08528000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a528000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c528000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x16538000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18538000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a538000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c530100, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c710107, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e710106, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02710105, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04710104, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10710000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e710000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x00710000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c728000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e728000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02728000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04728000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e730003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x12738000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x14738000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x14910107, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x16910106, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18910105, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a910104, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x10910000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a910000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c910000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x14928000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x16928000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18928000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a928000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c93f000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0f2800, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c0f000a, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2e020140, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02024000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04024000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2c030005, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x02034000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04034000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x06038000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08038000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a038000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x18034000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x36001003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x38003649, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1a006000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c006000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e006000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x34001b00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2a015500, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2206aa00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x020a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x040a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x060a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x080a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5d101554, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5b100555, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d14a80a, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f14002a, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1b14aa00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x15124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x19124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1b124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0b124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0d124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x51100600, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x53100606, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x55100006, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x57100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x47100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x49100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4b100404, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4d100404, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x70800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc40, 0x00070000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd940, 0x00078000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd944, 0x00000fff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc00, 0x00078000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc04, 0x00000fff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd948, 0x00007800, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd94c, 0x0000f0ff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc08, 0x00007800, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc0c, 0x0000f0ff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd950, 0x00000780, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd954, 0x0000ff0f, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc10, 0x00000780, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc14, 0x0000ff0f, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00804704, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a04904, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00805705, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a05905, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00808708, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a08908, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CGpuBusynessMetricSet::CGpuBusynessMetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CGpuBusynessMetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuActive", "EU Active",
                          "The percentage of time in which the Execution Units were actively processing.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuStall", "EU Stall",
                          "The percentage of time in which the Execution Units were stalled.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
                          "The percentage of time in which hardware threads occupied EUs.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "8 rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "8 qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "RenderBusy", "Render Ring Busy",
                          "The percentage of time when render command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xf8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1a0" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ComputeBusy", "Compute Ring Busy",
                          "The percentage of time when render command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 14 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xec" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x188" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PoshEngineBusy", "Posh Ring Busy",
                          "The percentage of time when posh command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 15 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xf4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x198" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "BlitterBusy", "Blitter Ring Busy",
                          "The percentage of time when blitter command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 16 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xf0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x190" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VeboxBusy", "Vebox Ring Busy",
                          "The percentage of time when vebox command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 17 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xfc" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1a8" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "Vdbox0Busy", "Vdbox0 Ring Busy",
                          "The percentage of time when Vdbox0 command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 18 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x180" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "Vdbox1Busy", "Vdbox1 Ring Busy",
                          "The percentage of time when Vdbox1 command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 19 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x178" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "RenderAndComputeBusy", "Render and compute engines are simultaneously busy",
                          "The percentage of time when render and compute engines are simultaneously busy",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 20 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x130" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AnyEngineBusy", "Any Engine Busy",
                          "The percentage of time when any command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 21 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x138" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e0e1200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x220e0009, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e101200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x040e0043, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a0e00b3, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x180e0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0c0e0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c0f0104, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08100053, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x20100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04024000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08024000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a024000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x04034000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x08034000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a034000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c006000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x34001b00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x040a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x080a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0a0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x15102400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x23010120, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x15182400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x23210120, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17100023, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x11100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5d101000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5b100545, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1b148800, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d140002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x61112000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5f110401, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f128000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03128000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0b124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0d128000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01008000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x13028000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x030100d3, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x21010000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x071800a3, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x11180000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x21180400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x23180000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0f208000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x21222000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f2100d3, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x21210000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x55100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x57100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x47100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x49101007, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4b10040a, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4d100210, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x30800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc40, 0x00030000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd940, 0x00024002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd944, 0x0000b7ff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc00, 0x00024002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc04, 0x0000b7ff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd948, 0x0007f000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd94c, 0x000001ff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc08, 0x0007f000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc0c, 0x000001ff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00804704, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a04904, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00805705, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a05905, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00808708, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a08908, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CEuActivity1MetricSet::CEuActivity1MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CEuActivity1MetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "RenderBusy", "Render Ring Busy",
                          "The percentage of time when render command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x178" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ComputeBusy", "Compute Ring Busy",
                          "The percentage of time when render command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x170" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "RenderAndComputeBusy", "Render and compute engines are simultaneously busy",
                          "The percentage of time when render and compute engines are simultaneously busy",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x130" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GtiReadThroughput", "GTI Read Throughput",
                          "The total number of GPU memory bytes read from GTI.",
                          "GTI", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xfc dw@0xf8 UADD dw@0xf4 UADD dw@0xf0 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1a8 qw@0x1a0 UADD qw@0x198 UADD qw@0x190 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "64 $Self UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GtiWriteThroughput", "GTI Write Throughput",
                          "The total number of GPU memory bytes written to GTI.",
                          "GTI", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 14 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xec dw@0xe8 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x188 qw@0x180 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "64 $Self UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsFpuActive", "VS FPU Pipe Active",
                          "The percentage of time in which EU FPU pipeline was actively processing a vertex shader instruction.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 15 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsFpuActive", "PS FPU Pipe Active",
                          "The percentage of time in which EU FPU pipeline was actively processing a pixel shader instruction.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", nullptr, 16 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuSendActive", "EU Send Pipe Active",
                          "The percentage of time in which EU send pipeline was actively processing.",
                          "EU Array/Pipes", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 17 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e0e1200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x220e0009, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c0e0043, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0e00b3, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x180e0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x160e0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0f1400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2e020140, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2c030005, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x38003600, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05151d37, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09151547, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05351c00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09351400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5d101400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5b100bbb, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f140028, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0d150136, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01150000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03350137, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07350147, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0b350136, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01350000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x55100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x57100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x47101000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x49101616, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4b101616, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4d100616, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x10800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc40, 0x00010000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd940, 0x00001802, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd944, 0x0000fcff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc00, 0x00001802, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc04, 0x0000fcff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00810710, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a10910, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00850750, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a50950, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00802702, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a02902, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CEuActivity2MetricSet::CEuActivity2MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CEuActivity2MetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "RenderBusy", "Render Ring Busy",
                          "The percentage of time when render command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x178" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ComputeBusy", "Compute Ring Busy",
                          "The percentage of time when render command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x170" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "RenderAndComputeBusy", "Render and compute engines are simultaneously busy",
                          "The percentage of time when render and compute engines are simultaneously busy",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x130" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GtiReadThroughput", "GTI Read Throughput",
                          "The total number of GPU memory bytes read from GTI.",
                          "GTI", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xfc dw@0xf8 UADD dw@0xf4 UADD dw@0xf0 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1a8 qw@0x1a0 UADD qw@0x198 UADD qw@0x190 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "64 $Self UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GtiWriteThroughput", "GTI Write Throughput",
                          "The total number of GPU memory bytes written to GTI.",
                          "GTI", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 14 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xec dw@0xe8 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x188 qw@0x180 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "64 $Self UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsEmActive", "CS EM Pipe Active",
                          "The percentage of time in which EU FPU1 pipeline was actively processing a compute shader instruction.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 15 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsFpuActive", "CS FPU Pipe Active",
                          "The percentage of time in which EU FPU pipeline was actively processing a compute shader instruction.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 16 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsSendActive", "CS Send Pipeline Active",
                          "The percentage of time in which EU send pipeline was actively processing a compute shader instruction.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 17 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e0e1200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x220e0009, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c0e0043, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0e00b3, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x180e0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x160e0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0f1400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2e020140, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2c030005, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x38003600, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05151d37, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09151547, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05351c00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09351400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5d101400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5b100bbb, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f140028, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0d150136, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01150000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03350137, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07350147, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0b350136, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01350000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x55100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x57100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x47101000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x49101616, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4b101616, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4d100616, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x10800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc40, 0x00010000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd940, 0x00001802, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd944, 0x0000fcff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc00, 0x00001802, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc04, 0x0000fcff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00862762, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a62962, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00860760, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a60960, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00861761, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a61961, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CEuActivity3MetricSet::CEuActivity3MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CEuActivity3MetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "RenderBusy", "Render Ring Busy",
                          "The percentage of time when render command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x178" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ComputeBusy", "Compute Ring Busy",
                          "The percentage of time when render command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x170" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "RenderAndComputeBusy", "Render and compute engines are simultaneously busy",
                          "The percentage of time when render and compute engines are simultaneously busy",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x130" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GtiReadThroughput", "GTI Read Throughput",
                          "The total number of GPU memory bytes read from GTI.",
                          "GTI", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xfc dw@0xf8 UADD dw@0xf4 UADD dw@0xf0 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1a8 qw@0x1a0 UADD qw@0x198 UADD qw@0x190 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "64 $Self UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GtiWriteThroughput", "GTI Write Throughput",
                          "The total number of GPU memory bytes written to GTI.",
                          "GTI", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 14 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xec dw@0xe8 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x188 qw@0x180 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "64 $Self UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsEmActive", "VS EM Pipe Active",
                          "The percentage of time in which EU EM pipeline was actively processing a vertex shader instruction.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 15 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsEmActive", "PS EM Pipe Active",
                          "The percentage of time in which EU EM pipeline was actively processing a pixel shader instruction.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", nullptr, 16 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsSendActive", "PS Send Pipeline Active",
                          "The percentage of time in which EU send pipeline was actively processing a pixel shader instruction.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", nullptr, 17 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e0e1200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x220e0009, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c0e0043, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0e00b3, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x180e0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x160e0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0f1400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2e020140, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2c030005, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x38003600, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05151d37, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09151547, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05351c00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09351400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5d101400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5b100bbb, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f140028, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0d150136, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01150000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03350137, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07350147, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0b350136, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01350000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x55100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x57100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x47101000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x49101616, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4b101616, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4d100616, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x10800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc40, 0x00010000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd940, 0x00001802, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd944, 0x0000fcff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc00, 0x00001802, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc04, 0x0000fcff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00811711, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a11911, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00851751, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a51951, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00852752, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a52952, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CEuActivity4MetricSet::CEuActivity4MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CEuActivity4MetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "RenderBusy", "Render Ring Busy",
                          "The percentage of time when render command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x178" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ComputeBusy", "Compute Ring Busy",
                          "The percentage of time when render command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x170" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "RenderAndComputeBusy", "Render and compute engines are simultaneously busy",
                          "The percentage of time when render and compute engines are simultaneously busy",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x130" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GtiReadThroughput", "GTI Read Throughput",
                          "The total number of GPU memory bytes read from GTI.",
                          "GTI", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xfc dw@0xf8 UADD dw@0xf4 UADD dw@0xf0 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1a8 qw@0x1a0 UADD qw@0x198 UADD qw@0x190 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "64 $Self UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GtiWriteThroughput", "GTI Write Throughput",
                          "The total number of GPU memory bytes written to GTI.",
                          "GTI", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 14 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xec dw@0xe8 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x188 qw@0x180 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "64 $Self UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsFpuActive", "HS FPU Pipe Active",
                          "The percentage of time in which EU FPU pipeline was actively processing a hull shader instruction.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", nullptr, 15 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsFpuActive", "DS FPU Pipe Active",
                          "The percentage of time in which EU FPU pipeline was actively processing a domain shader instructions.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", nullptr, 16 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsSendActive", "VS Send Pipe Active",
                          "The percentage of time in which EU send pipeline was actively processing a vertex shader instruction.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 17 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e0e1200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x220e0009, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c0e0043, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0e00b3, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x180e0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x160e0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0f1400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2e020140, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2c030005, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x38003600, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05151d37, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09151547, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05351c00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09351400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5d101400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5b100bbb, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f140028, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0d150136, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01150000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03350137, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07350147, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0b350136, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01350000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x55100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x57100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x47101000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x49101616, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4b101616, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4d100616, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x10800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc40, 0x00010000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd940, 0x00001802, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd944, 0x0000fcff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc00, 0x00001802, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc04, 0x0000fcff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00820720, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a20920, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00830730, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a30930, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00812712, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a12912, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CEuActivity5MetricSet::CEuActivity5MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CEuActivity5MetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "RenderBusy", "Render Ring Busy",
                          "The percentage of time when render command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x178" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ComputeBusy", "Compute Ring Busy",
                          "The percentage of time when render command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x170" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "RenderAndComputeBusy", "Render and compute engines are simultaneously busy",
                          "The percentage of time when render and compute engines are simultaneously busy",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x130" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GtiReadThroughput", "GTI Read Throughput",
                          "The total number of GPU memory bytes read from GTI.",
                          "GTI", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xfc dw@0xf8 UADD dw@0xf4 UADD dw@0xf0 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1a8 qw@0x1a0 UADD qw@0x198 UADD qw@0x190 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "64 $Self UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GtiWriteThroughput", "GTI Write Throughput",
                          "The total number of GPU memory bytes written to GTI.",
                          "GTI", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 14 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xec dw@0xe8 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x188 qw@0x180 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "64 $Self UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsEmActive", "HS EM Pipe Active",
                          "The percentage of time in which EU EM pipeline was actively processing a hull shader instructions.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", nullptr, 15 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsEmActive", "DS EM Pipe Active",
                          "The percentage of time in which EU EM pipeline was actively processing a domain shader instructions.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", nullptr, 16 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsSendActive", "HS Send Pipe Active",
                          "The percentage of time in which EU send pipeline was actively processing a hull shader instruction.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", nullptr, 17 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e0e1200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x220e0009, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c0e0043, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0e00b3, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x180e0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x160e0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0f1400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2e020140, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2c030005, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x38003600, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05151d37, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09151547, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05351c00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09351400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5d101400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5b100bbb, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f140028, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0d150136, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01150000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03350137, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07350147, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0b350136, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01350000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x55100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x57100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x47101000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x49101616, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4b101616, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4d100616, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x10800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc40, 0x00010000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd940, 0x00001802, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd944, 0x0000fcff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc00, 0x00001802, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc04, 0x0000fcff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00821721, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a21921, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00831731, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a31931, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00822722, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a22922, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CEuActivity6MetricSet::CEuActivity6MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CEuActivity6MetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "RenderBusy", "Render Ring Busy",
                          "The percentage of time when render command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x178" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ComputeBusy", "Compute Ring Busy",
                          "The percentage of time when render command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x170" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "RenderAndComputeBusy", "Render and compute engines are simultaneously busy",
                          "The percentage of time when render and compute engines are simultaneously busy",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x130" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GtiReadThroughput", "GTI Read Throughput",
                          "The total number of GPU memory bytes read from GTI.",
                          "GTI", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xfc dw@0xf8 UADD dw@0xf4 UADD dw@0xf0 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1a8 qw@0x1a0 UADD qw@0x198 UADD qw@0x190 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "64 $Self UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GtiWriteThroughput", "GTI Write Throughput",
                          "The total number of GPU memory bytes written to GTI.",
                          "GTI", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 14 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xec dw@0xe8 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x188 qw@0x180 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "64 $Self UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsFpuActive", "GS FPU Pipe Active",
                          "The percentage of time in which EU FPU pipeline was actively processing a geometry shader instructions.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 15 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsEmActive", "GS EM Pipe Active",
                          "The percentage of time in which EU EM pipeline was actively processing a geometry shader instructions.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 16 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsSendActive", "GS Send Pipe Active",
                          "The percentage of time in which EU send pipeline was actively processing a geometry shader instruction.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 17 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e0e1200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x220e0009, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c0e0043, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0e00b3, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x180e0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x160e0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0f1400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2e020140, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2c030005, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x38003600, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05151d37, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09151547, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05351c00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09351400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5d101400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5b100bbb, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f140028, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0d150136, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01150000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03350137, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07350147, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0b350136, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01350000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x55100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x57100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x47101000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x49101616, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4b101616, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4d100616, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x10800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc40, 0x00010000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd940, 0x00001802, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd944, 0x0000fcff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc00, 0x00001802, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc04, 0x0000fcff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00840740, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a40940, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00841741, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a41941, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00842742, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a42942, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CEuActivity7MetricSet::CEuActivity7MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CEuActivity7MetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "FpuActive", "EU FPU Pipe Active",
                          "The percentage of time in which EU FPU pipeline was actively processing.",
                          "EU Array/Pipes", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x3c:0xab rd40@0x40:0xac FADD rd40@0x44:0xad FADD rd40@0x48:0xae FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x68 qw@0x70 FADD qw@0x78 FADD qw@0x80 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EmActive", "EM Pipe Active",
                          "The percentage of time in which EU EM pipeline was actively processing.",
                          "EU Array/Pipes", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x4c:0xaf rd40@0x50:0xb0 FADD rd40@0x54:0xb1 FADD rd40@0x58:0xb2 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x88 qw@0x90 FADD qw@0x98 FADD qw@0xa0 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuFpuEmActive", "EU FPU And EM Pipes Active",
                          "The percentage of time in which EU FPU and EM pipelines were actively processing.",
                          "EU Array/Pipes", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuAvgIpcRate", "EU AVG IPC Rate",
                          "The average rate of IPC calculated for 2 FPU pipelines.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_4 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_RATIO, RESULT_FLOAT, "number", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$EuFpuEmActive $FpuActive $EmActive FADD $EuFpuEmActive FSUB FDIV 1 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "2" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "RenderBusy", "Render Ring Busy",
                          "The percentage of time when render command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 14 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x178" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ComputeBusy", "Compute Ring Busy",
                          "The percentage of time when render command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 15 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x170" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "RenderAndComputeBusy", "Render and compute engines are simultaneously busy",
                          "The percentage of time when render and compute engines are simultaneously busy",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 16 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x130" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GtiReadThroughput", "GTI Read Throughput",
                          "The total number of GPU memory bytes read from GTI.",
                          "GTI", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 17 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xfc dw@0xf8 UADD dw@0xf4 UADD dw@0xf0 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1a8 qw@0x1a0 UADD qw@0x198 UADD qw@0x190 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "64 $Self UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GtiWriteThroughput", "GTI Write Throughput",
                          "The total number of GPU memory bytes written to GTI.",
                          "GTI", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 18 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xec dw@0xe8 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x188 qw@0x180 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "64 $Self UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e0e1200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x220e0009, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c0e0043, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0e00b3, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x180e0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x160e0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0f1400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2e020140, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2c030005, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x38003600, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05151d37, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09151547, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05351c00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09351400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5d101400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5b100bbb, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f140028, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0d150136, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01150000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03350137, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07350147, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0b350136, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01350000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x55100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x57100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x47101000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x49101616, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4b101616, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4d100616, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x10800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc40, 0x00010000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd940, 0x00001802, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd944, 0x0000fcff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc00, 0x00001802, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc04, 0x0000fcff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00803703, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a03903, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00800700, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00a00900, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00801701, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00a01901, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CEuActivity8MetricSet::CEuActivity8MetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CEuActivity8MetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "RenderBusy", "Render Ring Busy",
                          "The percentage of time when render command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x178" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "ComputeBusy", "Compute Ring Busy",
                          "The percentage of time when render command streamer was busy.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x170" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "RenderAndComputeBusy", "Render and compute engines are simultaneously busy",
                          "The percentage of time when render and compute engines are simultaneously busy",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x130" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GtiReadThroughput", "GTI Read Throughput",
                          "The total number of GPU memory bytes read from GTI.",
                          "GTI", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xfc dw@0xf8 UADD dw@0xf4 UADD dw@0xf0 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x1a8 qw@0x1a0 UADD qw@0x198 UADD qw@0x190 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "64 $Self UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GtiWriteThroughput", "GTI Write Throughput",
                          "The total number of GPU memory bytes written to GTI.",
                          "GTI", ( METRIC_GROUP_NAME_ID_GTI * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_THROUGHPUT, RESULT_UINT64, "bytes", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 14 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xec dw@0xe8 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x188 qw@0x180 UADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "64 $Self UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "$GpuCoreClocks 64 UMUL" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsSendActive", "DS Send Pipe Active",
                          "The percentage of time in which EU send pipeline was actively processing a domain shader instruction.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", nullptr, 15 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x2c:0xa7 rd40@0x30:0xa8 FADD rd40@0x34:0xa9 FADD rd40@0x38:0xaa FADD" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x48 qw@0x50 FADD qw@0x58 FADD qw@0x60 FADD" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0e0e1200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x220e0009, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c0e0043, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0e00b3, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x180e0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x160e0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0f1400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2e020140, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2c030005, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x38003600, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1c0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05151d37, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09151547, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05351c00, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x09351400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5d101400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5b100bbb, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f140028, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0d150136, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01150000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07164000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03350137, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x07350147, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x0b350136, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01350000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x03368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x05368000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x55100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x57100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x47101000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x49101616, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4b101616, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x4d100616, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x10800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc40, 0x00010000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd940, 0x00001802, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd944, 0x0000fcff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc00, 0x00001802, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc04, 0x0000fcff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00832732, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00a32932, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CTestOaMetricSet::CTestOaMetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CTestOaMetricSet::Initialize()
    {
        TCompletionCode ret                             = CC_OK;
        CMetric*        metric                          = nullptr;
        CInformation*   information                     = nullptr;
        const char*     availabilityEquation            = nullptr;
        const uint32_t  concurrentGroupInformationCount = m_concurrentGroup->GetInformationCount();
        m_params_1_0.InformationCount                   = concurrentGroupInformationCount;
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "Counter0", "TestCounter0",
                          "HW test counter 0. Factor: 0.0",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x130" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "Counter1", "TestCounter1",
                          "HW test counter 1. Factor: 1.0",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x138" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "Counter2", "TestCounter2",
                          "HW test counter 2. Factor: 1.0",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xc8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x140" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "Counter3", "TestCounter3",
                          "HW test counter 3. Factor: 0.5",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xcc" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x148" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "Counter4", "TestCounter4",
                          "HW test counter 4. Factor: 0.3333",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xd0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x150" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "Counter5", "TestCounter5",
                          "HW test counter 5. Factor: 0.3333",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xd4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x158" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "Counter6", "TestCounter6",
                          "HW test counter 6. Factor: 0.16666",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xd8" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x160" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "Counter7", "TestCounter7",
                          "HW test counter 7. Factor: 0.6666",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xdc" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x168" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "Counter8", "TestCounter8",
                          "HW test counter 8. Should be equal to 1 in IOStream or in OAG query mode",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x170" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "Counter9", "TestCounter9 - OAR enable",
                          "HW test counter 9. Should be equal to 1 in query.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_VULKAN | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "events", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0xe4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x178" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        information = AddInformation( "StreamMarker", "Stream marker", "Stream marker value.", "Report Meta Data", API_TYPE_IOSTREAM, INFORMATION_TYPE_VALUE, nullptr, nullptr, concurrentGroupInformationCount + 0 );
        if( information )
        {
            information->SetSnapshotReportReadEquation( "dw@0x5c dw@0x0 19 >> 0x4 AND 0x4 == UMUL" );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0x0d04, 0x00000200, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9840, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x280e0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0e0147, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x180e0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x160e0000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0f1000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e104000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2e020100, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x2c030004, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x38003000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1e0a8000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x49110000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x5d101400, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f140020, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d1103b3, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x01110000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x61110000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1d128000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x1f124000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x17100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x55100510, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x57100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x31100000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000003, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x65100002, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9884, 0x00000000, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0x9888, 0x42000001, REGISTER_TYPE_NOA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0xf0800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0xf0800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc40, 0x00ff0000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd940, 0x00000004, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd944, 0x0000ffff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc00, 0x00000004, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc04, 0x0000ffff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd948, 0x00000003, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd94c, 0x0000ffff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc08, 0x00000003, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc0c, 0x0000ffff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd950, 0x00000007, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd954, 0x0000ffff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc10, 0x00000007, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc14, 0x0000ffff, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd958, 0x00100002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd95c, 0x0000fff7, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc18, 0x00100002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc1c, 0x0000fff7, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd960, 0x00100002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd964, 0x0000ffcf, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc20, 0x00100002, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc24, 0x0000ffcf, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd968, 0x00100082, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd96c, 0x0000ffef, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc28, 0x00100082, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc2c, 0x0000ffef, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd970, 0x001000c2, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd974, 0x0000ffe7, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc30, 0x001000c2, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc34, 0x0000ffe7, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd978, 0x00100001, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd97c, 0x0000ffe7, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc38, 0x00100001, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc3c, 0x0000ffe7, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe65c, 0xffffffff, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
    CCoarseAsyncComputeMetricSet::CCoarseAsyncComputeMetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, TByteArrayLatest* platformMask, uint32_t gtMask /*= GT_TYPE_ALL*/, bool isCustom /*= false*/ )
        : CMetricSet( device, concurrentGroup, symbolicName, shortName, apiMask, category, snapshotReportSize, deltaReportSize, reportType, platformMask, gtMask, isCustom )
    {
    }
    TCompletionCode CCoarseAsyncComputeMetricSet::Initialize()
    {
        TCompletionCode ret                  = CC_OK;
        CMetric*        metric               = nullptr;
        CInformation*   information          = nullptr;
        const char*     availabilityEquation = nullptr;
        m_params_1_0.InformationCount        = m_concurrentGroup->GetInformationCount();
        MD_CHECK_CC( SetApiSpecificId( "GPAV", 0, 0x40000000, 0x80000203, 0, 0, "Intel Performance Counters for GT Set Dynamic", 0, "Intel_Raw_Hardware_Counters_Set_0_Query", 0 ) );

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuTime", "GPU Time Elapsed",
                          "Time elapsed on the GPU during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_UINT64, "ns", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 0 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x04 1000000000 UMUL $GpuTimestampFrequency UDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x00" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "NS_TIME" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuCoreClocks", "GPU Core Clocks",
                          "The total number of GPU core clocks elapsed during the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "cycles", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 1 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "dw@0x0c" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x08" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 32" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "AvgGpuCoreFrequencyMHz", "AVG GPU Core Frequency",
                          "Average GPU Core Frequency in the measurement.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "MHz", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 2 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "$GpuCoreClocks 1000 UMUL $$GpuTime UDIV" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GpuBusy", "GPU Busy",
                          "The percentage of time in which the GPU has been processing GPU commands.",
                          "GPU", ( METRIC_GROUP_NAME_ID_GPU * 0x1000000 ), USAGE_FLAG_TIER_1 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 3 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x10:0xa0" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x10" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "GpuDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsThreads", "VS Threads Dispatched",
                          "The total number of vertex shader hardware threads dispatched.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 4 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x14:0xa1" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x18" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "HsThreads", "HS Threads Dispatched",
                          "The total number of hull shader hardware threads dispatched.",
                          "EU Array/Hull Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_HS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Hull|Control,hull|control,HS|TCS", "oa.fixed", 5 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x18:0xa2" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x20" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "DsThreads", "DS Threads Dispatched",
                          "The total number of domain shader hardware threads dispatched.",
                          "EU Array/Domain Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_DS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Domain|Evaluation,domain|evaluation,DS|TES", "oa.fixed", 6 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x1c:0xa3" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x28" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "GsThreads", "GS Threads Dispatched",
                          "The total number of geometry shader hardware threads dispatched.",
                          "EU Array/Geometry Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_GS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 7 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x24:0xa5" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x38" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsThreads", "PS Threads Dispatched",
                          "The total number of pixel shader hardware threads dispatched.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", "oa.fixed", 8 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x28:0xa6" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x40" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsThreads", "CS Threads Dispatched",
                          "The total number of compute shader hardware threads dispatched.",
                          "EU Array/Compute Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_CS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_EVENT, RESULT_UINT64, "threads", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, "oa.fixed", 9 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "rd40@0x20:0xa4" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "qw@0x30" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "FpuActive", "EU FPU Pipe Active",
                          "The percentage of time in which EU FPU pipeline was actively processing.",
                          "EU Array/Pipes", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 10 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "4 rd40@0x34:0xa9 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "4 qw@0x58 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsFpuActive", "VS FPU Pipe Active",
                          "The percentage of time in which EU FPU pipeline was actively processing a vertex shader instruction.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 11 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "4 rd40@0x44:0xad UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "4 qw@0x78 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsFpuActive", "PS FPU Pipe Active",
                          "The percentage of time in which EU FPU pipeline was actively processing a pixel shader instruction.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", nullptr, 12 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "4 rd40@0x3c:0xab UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "4 qw@0x68 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsFpuActive", "CS FPU Pipe Active",
                          "The percentage of time in which EU FPU pipeline was actively processing a compute shader instruction.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 13 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "4 rd40@0x4c:0xaf UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "4 qw@0x88 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EmActive", "EM Pipe Active",
                          "The percentage of time in which EU EM pipeline was actively processing.",
                          "EU Array/Pipes", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_EU_PIPES * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 14 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "4 rd40@0x38:0xaa UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "4 qw@0x60 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "VsEmActive", "VS EM Pipe Active",
                          "The percentage of time in which EU EM pipeline was actively processing a vertex shader instruction.",
                          "EU Array/Vertex Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_VS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 15 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "4 rd40@0x48:0xae UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "4 qw@0x80 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "PsEmActive", "PS EM Pipe Active",
                          "The percentage of time in which EU EM pipeline was actively processing a pixel shader instruction.",
                          "EU Array/Pixel Shader", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ) | ( METRIC_GROUP_NAME_ID_PS * 0x10000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, "Pixel|Fragment,PS|FS,pixel|fragment", nullptr, 16 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "4 rd40@0x40:0xac UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "4 qw@0x70 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "CsEmActive", "CS EM Pipe Active",
                          "The percentage of time in which EU FPU1 pipeline was actively processing a compute shader instruction.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_3 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 17 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "4 rd40@0x50:0xb0 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "4 qw@0x90 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuThreadOccupancy", "EU Thread Occupancy",
                          "The percentage of time in which hardware threads occupied EUs.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 18 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "32 rd40@0x54:0xb1 FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "32 qw@0x98 FMUL $EuThreadsCount FDIV" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuActive", "EU Active",
                          "The percentage of time in which the Execution Units were actively processing.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 19 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "4 rd40@0x2c:0xa7 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "4 qw@0x48 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        metric               = AddMetric( "EuStall", "EU Stall",
                          "The percentage of time in which the Execution Units were stalled.",
                          "EU Array", ( METRIC_GROUP_NAME_ID_EU_ARRAY * 0x1000000 ), USAGE_FLAG_TIER_2 | USAGE_FLAG_OVERVIEW | USAGE_FLAG_SYSTEM | USAGE_FLAG_FRAME | USAGE_FLAG_BATCH | USAGE_FLAG_DRAW, API_TYPE_DX9 | API_TYPE_DX10 | API_TYPE_DX11 | API_TYPE_DX12 | API_TYPE_OGL | API_TYPE_OGL4_X | API_TYPE_OGL4_X | API_TYPE_OCL | API_TYPE_VULKAN | API_TYPE_MEDIA | API_TYPE_IOSTREAM,
                          METRIC_TYPE_DURATION, RESULT_FLOAT, "percent", 0, 0, HW_UNIT_GPU, availabilityEquation, nullptr, nullptr, 20 );
        if( metric )
        {
            MD_CHECK_CC( ( metric->SetSnapshotReportReadEquation( "4 rd40@0x30:0xa8 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetDeltaReportReadEquation( "4 qw@0x50 UMUL" ) ) );
            MD_CHECK_CC( ( metric->SetNormalizationEquation( "EuAggrDuration" ) ) );
            MD_CHECK_CC( ( metric->SetSnapshotReportDeltaFunction( "DELTA 40" ) ) );
            MD_CHECK_CC( ( metric->SetMaxValueEquation( "100" ) ) );
        }

        availabilityEquation = nullptr;
        if( AddStartRegisterSet( 0, 0, availabilityEquation ) == CC_OK )
        {
            AddStartConfigRegister( 0xd900, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd904, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd910, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd914, 0x00800000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xd920, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xdc40, 0x00000000, REGISTER_TYPE_OA );
            AddStartConfigRegister( 0xe458, 0x00705704, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe558, 0x00701700, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe658, 0x00751750, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe758, 0x00711710, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe45c, 0x00761760, REGISTER_TYPE_FLEX );
            AddStartConfigRegister( 0xe55c, 0x00000708, REGISTER_TYPE_FLEX );
        }
        RefreshConfigRegisters();
        return CC_OK;

    exception:
        return ret;
    }
} // namespace MetricsDiscoveryInternal::MetricSets_ADLP_OA

#endif
