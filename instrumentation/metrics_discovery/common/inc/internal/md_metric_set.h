/*========================== begin_copyright_notice ============================

Copyright (C) 2022 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_metric_set.h

//     Abstract:   C++ Metrics Discovery internal metric set header

#pragma once

#include "md_types.h"

#include <cstdio>
#include <vector>
#include <list>

#define MD_METRIC_GROUP_NAME_LEVEL_MAX 3

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    ///////////////////////////////////////////////////////////////////////////////
    // Forward declarations:                                                     //
    ///////////////////////////////////////////////////////////////////////////////
    class CCalculationManager;
    class CConcurrentGroup;
    class CEquation;
    class CInformation;
    class CMetric;
    class CMetricsCalculator;
    class CMetricsDevice;
    class CRegisterSet;

    union SCalculationContext;
    using TCalculationContext = SCalculationContext;

    ///////////////////////////////////////////////////////////////////////////////
    // Metric group id levels:                                                   //
    ///////////////////////////////////////////////////////////////////////////////
    typedef enum EMetricGroupLevel
    {
        METRIC_GROUP_LEVEL_0 = 0x1,
        METRIC_GROUP_LEVEL_1 = 0x2,
        METRIC_GROUP_LEVEL_2 = 0x4,
        METRIC_GROUP_LEVEL_3 = 0x8,
        // ...
        METRIC_GROUP_LEVEL_LAST = 0x100,
    } TMetricGroupLevel;

    ///////////////////////////////////////////////////////////////////////////////
    // Pair of group name and its id:                                            //
    ///////////////////////////////////////////////////////////////////////////////
    typedef struct SMetricGroupNameIdPair
    {
        const char* Name;
        uint32_t    Id;
        uint32_t    LevelMask;
    } TMetricGroupNameIdPair;

    constexpr TMetricGroupNameIdPair GroupNamePairs[] = {
        { "GPU", METRIC_GROUP_NAME_ID_GPU, METRIC_GROUP_LEVEL_0 },
        { "GTI", METRIC_GROUP_NAME_ID_GTI, METRIC_GROUP_LEVEL_0 },
        { "LLC", METRIC_GROUP_NAME_ID_LLC, METRIC_GROUP_LEVEL_0 },
        { "EDRAM", METRIC_GROUP_NAME_ID_EDRAM, METRIC_GROUP_LEVEL_0 },
        { "DRAM", METRIC_GROUP_NAME_ID_DRAM, METRIC_GROUP_LEVEL_0 },
        { "EU Array", METRIC_GROUP_NAME_ID_EU_ARRAY, METRIC_GROUP_LEVEL_0 },
        { "Sampler", METRIC_GROUP_NAME_ID_SAMPLER, METRIC_GROUP_LEVEL_0 },
        { "Uncore", METRIC_GROUP_NAME_UNCORE, METRIC_GROUP_LEVEL_0 },
        { "Memory Controller", METRIC_GROUP_NAME_UNCORE_MC, METRIC_GROUP_LEVEL_0 },
        { "3D Pipe", METRIC_GROUP_NAME_ID_3D_PIPE, METRIC_GROUP_LEVEL_0 | METRIC_GROUP_LEVEL_1 },
        { "VE Pipe", METRIC_GROUP_NAME_ID_VE_PIPE, METRIC_GROUP_LEVEL_0 | METRIC_GROUP_LEVEL_1 },
        { "VD Pipe", METRIC_GROUP_NAME_ID_VD_PIPE, METRIC_GROUP_LEVEL_0 | METRIC_GROUP_LEVEL_1 },
        { "WD Pipe", METRIC_GROUP_NAME_ID_WD_PIPE, METRIC_GROUP_LEVEL_0 | METRIC_GROUP_LEVEL_1 },
        { "VME Pipe", METRIC_GROUP_NAME_ID_VME_PIPE, METRIC_GROUP_LEVEL_0 | METRIC_GROUP_LEVEL_1 },
        { "L3", METRIC_GROUP_NAME_ID_L3, METRIC_GROUP_LEVEL_0 | METRIC_GROUP_LEVEL_1 },
        { "Thread Dispatcher", METRIC_GROUP_NAME_ID_TD, METRIC_GROUP_LEVEL_1 },
        { "Rasterizer", METRIC_GROUP_NAME_ID_WM, METRIC_GROUP_LEVEL_1 },
        { "Data Port", METRIC_GROUP_NAME_ID_DATA_PORT, METRIC_GROUP_LEVEL_1 },
        { "IME Pipe", METRIC_GROUP_NAME_ID_IME_PIPE, METRIC_GROUP_LEVEL_1 },
        { "CRE Pipe", METRIC_GROUP_NAME_ID_CRE_PIPE, METRIC_GROUP_LEVEL_1 },
        { "Instruction Cache", METRIC_GROUP_NAME_ID_IC, METRIC_GROUP_LEVEL_1 },
        { "IC", METRIC_GROUP_NAME_ID_IC, METRIC_GROUP_LEVEL_1 },
        { "Sampler", METRIC_GROUP_NAME_ID_SAMPLER, METRIC_GROUP_LEVEL_1 },
        { "Pipes", METRIC_GROUP_NAME_ID_EU_PIPES, METRIC_GROUP_LEVEL_1 },
        { "Color Cache", METRIC_GROUP_NAME_ID_RCC, METRIC_GROUP_LEVEL_1 },
        { "Sampler Input", METRIC_GROUP_NAME_ID_SAMPLER_IN, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Sampler Cache", METRIC_GROUP_NAME_ID_SAMPLER_CACHE, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Sampler Filter", METRIC_GROUP_NAME_ID_SAMPLER_FL, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Sampler Output", METRIC_GROUP_NAME_ID_SAMPLER_OUT, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "TAG", METRIC_GROUP_NAME_ID_L3_TAG, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Instructions", METRIC_GROUP_NAME_ID_EU_INSTR, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Barrier", METRIC_GROUP_NAME_ID_EU_BARRIER, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Input Assembler", METRIC_GROUP_NAME_ID_IA, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Vertex Shader", METRIC_GROUP_NAME_ID_VS, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Hull Shader", METRIC_GROUP_NAME_ID_HS, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Control Shader", METRIC_GROUP_NAME_ID_HS, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Tesselator", METRIC_GROUP_NAME_ID_TE, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Domain Shader", METRIC_GROUP_NAME_ID_DS, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Evaluation Shader", METRIC_GROUP_NAME_ID_DS, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Geometry Shader", METRIC_GROUP_NAME_ID_GS, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Stream Output", METRIC_GROUP_NAME_ID_SO, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Clipper", METRIC_GROUP_NAME_ID_CL, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Pixel Shader", METRIC_GROUP_NAME_ID_PS, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Fragment Shader", METRIC_GROUP_NAME_ID_PS, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Output Merger", METRIC_GROUP_NAME_ID_OM, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Compute Shader", METRIC_GROUP_NAME_ID_CS, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "SLM", METRIC_GROUP_NAME_ID_SLM, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "URB", METRIC_GROUP_NAME_ID_URB, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Depth Cache", METRIC_GROUP_NAME_ID_RCZ, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Stencil Cache", METRIC_GROUP_NAME_ID_STC, METRIC_GROUP_LEVEL_1 | METRIC_GROUP_LEVEL_2 },
        { "Atomics", METRIC_GROUP_NAME_ID_ATOMICS, METRIC_GROUP_LEVEL_2 },
        { "Strip-Fans", METRIC_GROUP_NAME_ID_SF, METRIC_GROUP_LEVEL_2 },
        { "Early Depth Test", METRIC_GROUP_NAME_ID_IZ, METRIC_GROUP_LEVEL_2 },
        { "Hi-Depth Test", METRIC_GROUP_NAME_ID_HZ, METRIC_GROUP_LEVEL_2 },
        { "Barycentric Calc", METRIC_GROUP_NAME_ID_BC, METRIC_GROUP_LEVEL_2 },
        { "Command Streamer", METRIC_GROUP_NAME_ID_RCS, METRIC_GROUP_LEVEL_2 },
        { "Resource Streamer", METRIC_GROUP_NAME_ID_RS, METRIC_GROUP_LEVEL_2 },
        { "Vertex Fetch", METRIC_GROUP_NAME_ID_VF, METRIC_GROUP_LEVEL_2 }
    };

    ///////////////////////////////////////////////////////////////////////////////
    // PmRegs config info:                                                       //
    ///////////////////////////////////////////////////////////////////////////////
    typedef struct SPmRegsConfigInfo
    {
        bool     IsQueryConfig;
        uint32_t OaConfigHandle;
        uint32_t GpConfigHandle;
        uint32_t RrConfigHandle;
    } TPmRegsConfigInfo;

    //////////////////////////////////////////////////////////////////////////////
    //
    // Class:
    //     CMetricSet
    //
    // Description:
    //     The metric sets mapping to different HW configuration that should be used
    //     exclusively to each other metric set in the concurrent group.
    //     Stores metrics, information, complementary metric sets, start configurations.
    //
    //////////////////////////////////////////////////////////////////////////////
    class CMetricSet : public IInternalMetricSet
    {
    public:
        // API 1.11:
        virtual TMetricSetParams_1_11* GetParams( void );

        // API 1.5:
        virtual TCompletionCode CalculateMetrics( const uint8_t* rawData, uint32_t rawDataSize, TTypedValue_1_0* out, uint32_t outSize, uint32_t* outReportCount, TTypedValue_1_0* outMaxValues, uint32_t outMaxValuesSize );

        // API 1.1:
        virtual TCompletionCode SetApiFiltering( uint32_t apiMask );
        virtual TCompletionCode CalculateMetrics( const uint8_t* rawData, uint32_t rawDataSize, TTypedValue_1_0* out, uint32_t outSize, uint32_t* outReportCount, bool enableContextFiltering );
        virtual TCompletionCode CalculateIoMeasurementInformation( TTypedValue_1_0* out, uint32_t outSize );

        // API 1.0:
        virtual IMetric_1_0*      GetMetric( uint32_t index );
        virtual IInformation_1_0* GetInformation( uint32_t index );
        virtual IMetricSet_1_11*  GetComplementaryMetricSet( uint32_t index );
        virtual TCompletionCode   Activate( void );   // To enable this configuration before query instance is created or IO stream is opened
        virtual TCompletionCode   Deactivate( void ); // To disable this configuration after query instance is created or IO stream is closed
        virtual IMetric_1_0*      AddCustomMetric(
                 const char*       symbolName,
                 const char*       shortName,
                 const char*       groupName,
                 const char*       longName,
                 const char*       dxToOglAlias,
                 uint32_t          usageFlagsMask,
                 uint32_t          apiMask,
                 TMetricResultType resultType,
                 const char*       resultUnits,
                 TMetricType       metricType,
                 int64_t           loWatermark,
                 int64_t           hiWatermark,
                 THwUnitType       hwType,
                 const char*       ioReadEquation,
                 const char*       deltaFunction,
                 const char*       queryReadEquation,
                 const char*       normalizationEquation,
                 const char*       maxValueEquation,
                 const char*       signalName );

        // Internal API (IInternalMetricSet):
        virtual IMetricLatest* AddCustomMetric( TAddCustomMetricParams* params );

    public:
        // Constructor & Destructor:
        CMetricSet(
            CMetricsDevice*   device,
            CConcurrentGroup* concurrentGroup,
            const char*       symbolicName,
            const char*       shortName,
            uint32_t          apiMask,
            uint32_t          categoryMask,
            uint32_t          snapshotReportSize,
            uint32_t          deltaReportSize,
            TReportType       reportType,
            TByteArrayLatest* platformMask,
            uint32_t          gtMask   = GT_TYPE_ALL,
            bool              isCustom = false );
        virtual ~CMetricSet();

        // Non-API:
        TCompletionCode SetApiSpecificId( const char* dx9Fourcc, uint32_t dx9QueryId, uint32_t dx10Counter, uint32_t oglQuery, uint32_t ocl, uint32_t hwConfig, const char* dx10CounterName, uint32_t dx10QueryId, const char* oglQueryName, uint32_t oglQueryARB );
        TCompletionCode SetApiSpecificId( TApiSpecificId_1_0 apiSepcificId );

        CMetric* AddMetric( const char* symbolName, const char* shortName, const char* longName, const char* groupName, uint32_t groupId, uint32_t usageFlagsMask, uint32_t apiMask, TMetricType metricType, TMetricResultType resultType, const char* units, int64_t loWatermark, int64_t hiWatermark, THwUnitType hwType, const char* availabilityEquation, const char* alias, const char* signalName, uint32_t metricXmlId, bool isCustom = false );
        CMetric* AddMetric( CMetric* metric );

        CInformation* AddInformation( const char* symbolName, const char* shortName, const char* longName, const char* groupName, uint32_t apiMask, TInformationType informationType, const char* informationUnits, const char* availabilityEquation, uint32_t informationXmlId );
        CInformation* AddInformation( CInformation* information );
        bool          HasInformation( const char* symbolName );

        TCompletionCode AddComplementaryMetricSet( const char* complementaryMetricSetSymbolicName );
        TCompletionCode AddComplementaryMetricSets( const char* complementarySetsList );

        TCompletionCode AddStartRegisterSet( uint32_t configId, uint32_t configPriority, const char* availabilityEquation = nullptr, TConfigType configType = CONFIG_TYPE_COMMON );
        TCompletionCode AddStartConfigRegister( uint32_t offset, uint32_t value, TRegisterType type );
        TCompletionCode RefreshConfigRegisters();
        TRegister**     GetStartConfiguration( uint32_t* count );
        TCompletionCode SendStartConfiguration( bool sendQueryConfigFlag );
        void            AppendToConfiguration( std::vector<TRegister*>& sourceRegs, std::vector<TRegister*>& outPmRegs, std::vector<TRegister*>& outReadRegs );
        bool            CheckSendConfigRequired( bool sendQueryConfigFlag );

        TCompletionCode ActivateInternal( bool sendConfigFlag, bool sendQueryConfigFlag );

        TReportType     GetReportType();
        TCompletionCode InheritFromMetricSet( CMetricSet* referenceMetricSet, const char* signalName, bool copyInformationOnly );
        TCompletionCode WriteCMetricSetToFile( FILE* metricFile );
        bool            IsMetricAlreadyAdded( const char* symbolName );
        bool            IsCustom();

        CConcurrentGroup*   GetConcurrentGroup();
        CMetricsCalculator* GetMetricsCalculator();
        CMetricsDevice*     GetMetricsDevice();
        TByteArrayLatest*   GetPlatformMask();

        TCompletionCode SetAvailabilityEquation( const char* equationString );
        bool            IsAvailabilityEquationTrue();

        // Inline function.
        inline CMetric* GetMetricExplicit( const uint32_t index )
        {
            if( m_currentMetricsVector != nullptr && index < m_currentMetricsVector->size() )
            {
                return ( *m_currentMetricsVector )[index];
            }

            return nullptr;
        }

    protected:
        CConcurrentGroup*      m_concurrentGroup;
        TMetricSetParamsLatest m_params_1_0;
        CMetricsDevice*        m_device;

    private:
        // API filtering:
        bool            IsApiFilteringMaskValid( uint32_t apiMask );
        void            EnableApiFiltering( uint32_t apiMask, bool enable );
        void            UpdateMetricIndicesInEquations();
        void            UseApiFilteredVariables( bool enable );
        void            RefreshCachedMetricsAndInformation();
        void            ClearCachedMetricsAndInformation();
        TCompletionCode ValidateCalculateMetricsParams( uint32_t rawDataSize, uint32_t rawReportSize, uint32_t outSize, uint32_t rawReportCount, uint32_t outMaxValuesSize );
        void            InitializeCalculationManager( TMeasurementType measurementType, CCalculationManager** calculationManager, bool init );
        TCompletionCode InitializeCalculationContext( TCalculationContext& context, CCalculationManager* calculationManager, TMeasurementType measurementType, TTypedValue_1_0* out, TTypedValue_1_0* outMaxValues, const uint8_t* rawData, uint32_t rawReportCount, bool init );

        bool AreMetricParamsValid( const char* symbolName, const char* shortName, const char* description, const char* groupName, TMetricType metricType, TMetricResultType resultType, const char* units, THwUnitType hwType, const char* alias );

        uint32_t MetricGroupNameToId( const char* groupName );
        uint32_t GetPartialGroupId( char* groupName, uint32_t tokenNo );
        bool     GetStartRegSetHiPriority( uint32_t id, CRegisterSet** registerSet );

    private:
        // Variables:
        TReportType m_reportType;

        std::vector<CMetric*>      m_metricsVector;
        std::vector<CInformation*> m_informationVector;
        std::vector<const char*>   m_complementarySetsVector;
        std::vector<TRegister*>    m_startRegsVector;      // Stores only references
        std::vector<TRegister*>    m_startRegsQueryVector; // Stores only references

        std::list<CRegisterSet*> m_startRegisterSetList;

        // List of unavailable metrics and information:
        std::vector<CMetric*>      m_otherMetricsVector;
        std::vector<CInformation*> m_otherInformationVector;

        TByteArrayLatest* m_platformMask;
        CEquation*        m_availabilityEquation;

        // References to the currently used params/collections - filtered or not:
        TMetricSetParamsLatest*     m_currentParams;
        std::vector<CMetric*>*      m_currentMetricsVector;
        std::vector<CInformation*>* m_currentInformationVector;

        // API filtered params/collections:
        TMetricSetParamsLatest     m_filteredParams;
        std::vector<CMetric*>      m_filteredMetricsVector;     // Stores only references
        std::vector<CInformation*> m_filteredInformationVector; // Stores only references

        // Runtime state:
        bool                m_isFiltered;       // if true then 'filtered' variables are used
        bool                m_isCustom;         // if true then it has custom metrics or it's a custom set
        bool                m_isReadRegsCfgSet; // if true then read regs config will be cleared on Deactivate; determined during Activate
        TPmRegsConfigInfo   m_pmRegsConfigInfo;
        CMetricsCalculator* m_metricsCalculator;

    private:
        // Static variables:
        static constexpr uint32_t METRICS_VECTOR_INCREASE            = 64;
        static constexpr uint32_t INFORMATION_VECTOR_INCREASE        = 16;
        static constexpr uint32_t COMPLEMENTARY_SETS_VECTOR_INCREASE = 16;
        static constexpr uint32_t START_REGS_VECTOR_INCREASE         = 128;
        static constexpr uint32_t START_REGS_QUERY_VECTOR_INCREASE   = 16;
        static constexpr uint32_t STOP_REGS_VECTOR_INCREASE          = 32;
    };
} // namespace MetricsDiscoveryInternal
