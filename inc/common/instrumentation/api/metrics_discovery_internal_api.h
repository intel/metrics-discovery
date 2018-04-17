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

    File Name:  metrics_discovery_internal_api.h

    Abstract:   Internal interface for metrics discovery DLL

    Notes:

\*****************************************************************************/
#pragma once

#include "metrics_discovery_api.h"

namespace MetricsDiscovery
{
/******************************************************************************
   Platform types:
 ******************************************************************************/
    typedef enum EPlatformType
    {
        PLATFORM_UNKNOWN = 0,
        // 4 reserved
        PLATFORM_HSW = 1 << 5  /*GENERATION_HSW*/,
        PLATFORM_BDW = 1 << 6  /*GENERATION_BDW*/,
        PLATFORM_SKL = 1 << 7  /*GENERATION_SKL*/,
        // 8-9 reserved
        PLATFORM_BXT = 1 << 10 /*GENERATION_BXT*/,
        // 11 reserved
        PLATFORM_KBL = 1 << 12 /*GENERATION_KBL*/,
        // 13-18 reserved
        // ...
        PLATFORM_ALL = 0xFFFFFFFF,
    } TPlatformType;

/******************************************************************************
   GT types: aligned with struct from Intel driver
 ******************************************************************************/
    typedef enum EGTType
    {
        GT_TYPE_UNKNOWN            = 0,
        GT_TYPE_GT1                = 1,
        GT_TYPE_GT2                = 1 << 1,
        // 2-8 reserved
        GT_TYPE_GT3                = 1 << 9,
        GT_TYPE_GT4                = 1 << 10,
        GT_TYPE_GT0                = 1 << 11,
        // 12-16 reserved
        // ...
        GT_TYPE_ALL                = 0xFFFFFFFF,
    } TGTType;

/******************************************************************************
   AddCustomMetricSetParam types:
 ******************************************************************************/
    typedef enum EAddCustomMetricSetParamsType
    {
        METRIC_SET_CUSTOM_PARAMS_1_0,
    } TAddCustomMetricSetParamsType;

/******************************************************************************
   AddCustomMetricParam types:
 ******************************************************************************/
    typedef enum EAddCustomMetricParamsType
    {
        METRIC_CUSTOM_PARAMS_1_0,
    } TAddCustomMetricParamsType;

/******************************************************************************
   Register types:
 ******************************************************************************/
    typedef enum ERegisterType
    {
        REGISTER_TYPE_UNKNOWN = 0,
        REGISTER_TYPE_OA,
        REGISTER_TYPE_NOA,
        REGISTER_TYPE_FLEX,
        REGISTER_TYPE_PM,
        REGISTER_TYPE_MMIO,
        // ...

        REGISTER_TYPE_LAST,
    } TRegisterType;

/******************************************************************************
   Metric Group Name IDs: order defines the way metrics are displayed later
   e.g. in GPA, numbers may change w/o notice
 ******************************************************************************/
    typedef enum EMetricGroupNameId
    {
        METRIC_GROUP_NAME_ID_INVALID        = 0,
        METRIC_GROUP_NAME_ID_GPU            = 1,
        METRIC_GROUP_NAME_ID_GTI            = 5,
        METRIC_GROUP_NAME_ID_LLC            = 8,
        METRIC_GROUP_NAME_ID_EDRAM          = 9,
        METRIC_GROUP_NAME_ID_DRAM           = 15,
        METRIC_GROUP_NAME_ID_EU_ARRAY       = 20,
        METRIC_GROUP_NAME_ID_RCZ            = 22,
        METRIC_GROUP_NAME_ID_STC            = 24,
        METRIC_GROUP_NAME_ID_RCC            = 26,
        METRIC_GROUP_NAME_ID_L3             = 28,
        METRIC_GROUP_NAME_ID_SAMPLER        = 30,
        METRIC_GROUP_NAME_ID_TD             = 35,
        METRIC_GROUP_NAME_ID_DATA_PORT      = 40,
        METRIC_GROUP_NAME_ID_3D_PIPE        = 50,
        METRIC_GROUP_NAME_ID_VE_PIPE        = 55,
        METRIC_GROUP_NAME_ID_VD_PIPE        = 58,
        METRIC_GROUP_NAME_ID_VME_PIPE       = 60,
        METRIC_GROUP_NAME_ID_WD_PIPE        = 62,

        METRIC_GROUP_NAME_ID_IME_PIPE       = 70,
        METRIC_GROUP_NAME_ID_CRE_PIPE       = 72,

        METRIC_GROUP_NAME_UNCORE            = 80,
        METRIC_GROUP_NAME_UNCORE_MC         = 81,

        METRIC_GROUP_NAME_ID_IA             = 112,
        METRIC_GROUP_NAME_ID_RCS            = 116,
        METRIC_GROUP_NAME_ID_RS             = 118,
        METRIC_GROUP_NAME_ID_VF             = 120,
        METRIC_GROUP_NAME_ID_VS             = 124,
        METRIC_GROUP_NAME_ID_HS             = 126,
        METRIC_GROUP_NAME_ID_TE             = 128,
        METRIC_GROUP_NAME_ID_DS             = 130,
        METRIC_GROUP_NAME_ID_GS             = 132,
        METRIC_GROUP_NAME_ID_SO             = 134,
        METRIC_GROUP_NAME_ID_CL             = 136,
        METRIC_GROUP_NAME_ID_WM             = 138,
        METRIC_GROUP_NAME_ID_SF             = 140,
        METRIC_GROUP_NAME_ID_HZ             = 142,
        METRIC_GROUP_NAME_ID_IZ             = 144,
        METRIC_GROUP_NAME_ID_BC             = 146,
        METRIC_GROUP_NAME_ID_PS             = 148,
        METRIC_GROUP_NAME_ID_OM             = 150,
        METRIC_GROUP_NAME_ID_CS             = 156,

        METRIC_GROUP_NAME_ID_L3_TAG         = 160,
        METRIC_GROUP_NAME_ID_URB            = 164,
        METRIC_GROUP_NAME_ID_SLM            = 168,
        METRIC_GROUP_NAME_ID_ATOMICS        = 170,
        METRIC_GROUP_NAME_ID_IC             = 174,

        METRIC_GROUP_NAME_ID_SAMPLER_IN     = 178,
        METRIC_GROUP_NAME_ID_SAMPLER_CACHE  = 180,
        METRIC_GROUP_NAME_ID_SAMPLER_FL     = 184,
        METRIC_GROUP_NAME_ID_SAMPLER_OUT    = 188,

        METRIC_GROUP_NAME_ID_EU_PIPES       = 200,
        METRIC_GROUP_NAME_ID_EU_INSTR       = 204,
        METRIC_GROUP_NAME_ID_EU_BARRIER     = 208,

    } TMetricGroupNameId;
/******************************************************************************
   Config register methods:
 ******************************************************************************/
    typedef enum EConfigType
    {
        CONFIG_TYPE_COMMON = 0,
        CONFIG_TYPE_QUERY,
        // ...
    } TConfigType;

/******************************************************************************
   Register:
 ******************************************************************************/
    typedef struct SRegister
    {
        uint32_t      offset;
        uint32_t      value;
        TRegisterType type;
    } TRegister;

/******************************************************************************
   RegisterSet:
 ******************************************************************************/
    typedef struct SRegisterSet
    {
        TRegister*   StartConfigRegs;
        uint32_t     StartConfigRegsCount;
        const char*  AvailabilityEquation;   // Optional
        uint32_t     ConfigId;
        uint32_t     ConfigPriority;
        TConfigType  ConfigType;
    } TRegisterSet;

/******************************************************************************
   AddCustomMetricSet parameters:
 ******************************************************************************/
    typedef struct SAddCustomMetricSetParams
    {
        TAddCustomMetricSetParamsType Type;
        union
        {
            struct
            {
                const char*         SymbolName;            // For example "Dx11Tessellation"
                const char*         ShortName;             // For example "DX11 Tessellation Metrics Set"

                uint32_t            ApiMask;
                uint32_t            CategoryMask;
                uint32_t            PlatformMask;

                uint32_t            RawReportSize;         // As in HW
                uint32_t            QueryReportSize;       // As in Query API

                const char*         ComplementarySetsList; // Comma separated list of complementary sets

                TApiSpecificId_1_0  ApiSpecificId;

                TRegisterSet*       StartConfigRegSets;    // Optional
                uint32_t            StartConfigRegSetsCount;
                uint32_t            GtMask;

            } CustomMetricSetParams_1_0;

            struct
            {
                uint32_t reserved[32];
            } Padding;
        };

    } TAddCustomMetricSetParams;

/******************************************************************************
   AddCustomMetricSet parameters:
 ******************************************************************************/
    typedef struct SAddCustomMetricParams
    {
        TAddCustomMetricParamsType Type;
        union
        {
            struct
            {
                const char*             SymbolName;
                const char*             ShortName;
                const char*             GroupName;
                const char*             LongName;
                const char*             DxToOglAlias;

                uint32_t                UsageFlagsMask;
                uint32_t                ApiMask;

                TMetricResultType       ResultType;
                const char*             MetricResultUnits;
                TMetricType             MetricType;

                int64_t                 LowWatermark;
                int64_t                 HighWatermark;

                THwUnitType             HwUnitType;

                const char*             IoReadEquation;
                const char*             QueryReadEquation;
                const char*             DeltaFunction;
                const char*             NormEquation;
                const char*             MaxValueEquation;

                const char*             SignalName;
                const char*             AvailabilityEquation;
            } CustomMetricParams_1_0;

            struct
            {
                uint32_t reserved[32];
            } Padding;
        };
    } TAddCustomMetricParams;


/*****************************************************************************\

Class:
    IInternalConcurrentGroup

Description:
    Abstract internal interface for the metrics groups that can be collected
    concurrently to another group.

\*****************************************************************************/
    class IInternalConcurrentGroup : public IConcurrentGroup_1_5
    {
    public:
        virtual ~IInternalConcurrentGroup();

        virtual IMetricSet_1_5* AddCustomMetricSet( TAddCustomMetricSetParams* params, IMetricSet_1_0* referenceMetricSet, bool copyInformationOnly = false );
    };

/*****************************************************************************\

Class:
    IInternalMetricSet

Description:
    Abstract internal interface for the metric sets mapping to different HW configuration
    that should be used exclusively to each other metric set in the concurrent group.

\*****************************************************************************/
    class IInternalMetricSet : public IMetricSet_1_5
    {
    public:
        virtual ~IInternalMetricSet();

        virtual IMetric_1_0* AddCustomMetric( TAddCustomMetricParams* params );
    };

};

