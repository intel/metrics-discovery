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

    File Name:  md_internal.h

    Abstract:   C++ Metrics Discovery internal header

\*****************************************************************************/
#pragma once

#include "metrics_discovery_internal_api.h"
#include "md_types.h"
#include "md_driver_ifc.h"
#include "md_utils.h"
#include "md_calculation.h"

#define MD_BYTE             8
#define MD_MBYTE            1048576
#define MD_MHERTZ           1000000
#define MD_NSEC_PER_SEC     1000000000ULL
#define MD_INTEL_VENDOR_ID  0x8086

#define MD_METRIC_GROUP_NAME_LEVEL_MAX 3

#define MD_METRICS_FILE_KEY "CUSTOM_METRICS_FILE\n"

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
    /* Forward declarations */
    class CSymbolSet;
    class CDriverInterface;
    class COverrride;
    class CConcurrentGroup;
    class COAConcurrentGroup;
    class CPerfMonConcurrentGroup;
    class CMetricSet;
    class CMetric;
    class CInformation;
    class CRegisterSet;
    class CEquation;

    /******************************************************************************/
    /* API versions:                                                              */
    /******************************************************************************/
    enum EApiVersion
    {
        API_VERSION_1_0 = 0,
    };

    /******************************************************************************/
    /* Symbol types:                                                              */
    /******************************************************************************/
    typedef enum ESymbolType
    {
        SYMBOL_TYPE_IMMEDIATE,
        SYMBOL_TYPE_DETECT,
    } TSymbolType;

    /******************************************************************************/
    /* OA report types:                                                           */
    /******************************************************************************/
    typedef enum EReportType
    {
        OA_REPORT_TYPE_128B_A13_NOA16 = 0,
        OA_REPORT_TYPE_192B_A29_NOA16,
        OA_REPORT_TYPE_256B_A45_NOA16,
        OA_REPORT_TYPE_64B_A13,
        OA_REPORT_TYPE_128B_A29,
        OA_REPORT_TYPE_64B_NOA12,
        OA_REPORT_TYPE_128B_A16_NOA12,
        OA_REPORT_TYPE_64B_NOA12_2,
        // ...
        OA_REPORT_TYPE_LAST,
    } TReportType;

    /******************************************************************************/
    /* Equation types:                                                            */
    /******************************************************************************/
    typedef enum EEquationType
    {
        EQUATION_IO_READ = 0,
        EQUATION_QUERY_READ,
        // ...
    } TEquationType;

    /******************************************************************************/
    /* Metric group id levels:                                                    */
    /******************************************************************************/
    typedef enum EMetricGroupLevel
    {
        METRIC_GROUP_LEVEL_0    = 0x1,
        METRIC_GROUP_LEVEL_1    = 0x2,
        METRIC_GROUP_LEVEL_2    = 0x4,
        METRIC_GROUP_LEVEL_3    = 0x8,
        // ...
        METRIC_GROUP_LEVEL_LAST = 0x100,
    } TMetricGroupLevel;

    /******************************************************************************/
    /* Global symbol:                                                             */
    /******************************************************************************/
    typedef struct SGlobalSymbol {
        EApiVersion           version;
        union {
            TGlobalSymbol_1_0 symbol_1_0;
        };
        TSymbolType           symbolType;
    } TGlobalSymbol;

    /******************************************************************************/
    /* Register set params:                                                       */
    /******************************************************************************/
    typedef struct SRegisterSetParams
    {
        uint32_t     ConfigId;
        uint32_t     ConfigPriority;
        TConfigType  ConfigType;
    } TRegisterSetParams;

    /******************************************************************************/
    /* PmRegs config info:                                                        */
    /******************************************************************************/
    typedef struct SPmRegsConfigInfo
    {
        bool         IsQueryConfig;
        uint32_t     OaConfigHandle;
        uint32_t     GpConfigHandle;
        uint32_t     RrConfigHandle;
    } TPmRegsConfigInfo;

    /******************************************************************************/
    /* Pair of group name and its id:                                             */
    /******************************************************************************/
    typedef struct SMetricGroupNameIdPair
    {
        const char*  Name;
        uint32_t     Id;
        uint32_t     LevelMask;
    } TMetricGroupNameIdPair;

    /******************************************************************************/
    /* Internal override parameters                                                */
    /******************************************************************************/
    typedef struct SOverrideInternalParams
    {
        uint32_t     QueryOverrideId;
    } TOverrideInternalParams;


/*****************************************************************************\

Class:
    CGlobalSymbolSet

Description:
    Collection of global symbols with methods to add them.

\*****************************************************************************/
    class CSymbolSet
    {
    protected:
        static const uint32_t SYMBOLS_VECTOR_INCREASE = 32;

    public:// Constructor & Destructor
        CSymbolSet();
        ~CSymbolSet();

    public:
        uint32_t           GetSymbolCount();
        TGlobalSymbol_1_0* GetSymbol( uint32_t index );
        TTypedValue_1_0*   GetSymbolValueByName( const char* name );
        TCompletionCode    AddSymbol( const char* name, TTypedValue_1_0 typedValue, TSymbolType symbolType );
        TCompletionCode    DetectSymbolValue( const char* name, TTypedValue_1_0* typedValue );
        TCompletionCode    AddSymbolUINT32( const char* name, uint32_t value, TSymbolType symbolType );
        TCompletionCode    AddSymbolUINT64( const char* name, uint64_t value, TSymbolType symbolType );
        TCompletionCode    AddSymbolBOOL( const char* name, bool value, TSymbolType symbolType );
        TCompletionCode    AddSymbolFLOAT( const char* name, float value, TSymbolType symbolType );
        TCompletionCode    AddSymbolCSTRING( const char* name, char* value, TSymbolType symbolType );
        TCompletionCode    WriteSymbolSetToFile( FILE* metricFile );
        bool               IsSymbolAlreadyAdded( const char* symbolName );
        TCompletionCode    RedetectSymbol( const char* name );

    private:
        bool               IsPavpDisabled( uint32_t capabilities );

    private: // Variables
        Vector<TGlobalSymbol*>* m_symbolVector;
        CDriverInterface*       m_driverInterface;
    };

/*****************************************************************************\

Class:
    CMetricsDevice

Description:
    GPU metrics root object. Stores all the concurrent groups and global symbols.

\*****************************************************************************/
    class CMetricsDevice: public IMetricsDevice_1_5
    {
    public: // IMetricsDevice_1_0
        virtual TMetricsDeviceParams_1_2* GetParams( void );
        // Child objects are of IConcurrentGroup
        virtual IConcurrentGroup_1_5*     GetConcurrentGroup( uint32_t index );
        virtual TGlobalSymbol_1_0*        GetGlobalSymbol( uint32_t index );
        virtual TTypedValue_1_0*          GetGlobalSymbolValueByName( const char* name );
        virtual TCompletionCode           GetLastError();
        virtual TCompletionCode           GetGpuCpuTimestamps( uint64_t* gpuTimestampNs, uint64_t* cpuTimestampNs, uint32_t* cpuId );
        // IMetricsDevice_1_2
        virtual IOverride_1_2*            GetOverride( uint32_t index );
        virtual IOverride_1_2*            GetOverrideByName( const char* symbolName );

    private:
        static const uint32_t GROUPS_VECTOR_INCREASE    = 16;
        static const uint32_t OVERRIDES_VECTOR_INCREASE = 8;

    public: // Constructor & Destructor
        CMetricsDevice();
        virtual ~CMetricsDevice();

    public:
        CConcurrentGroup* AddConcurrentGroup( const char* symbolicName, const char* shortName, uint32_t measurementTypeMask );
        TCompletionCode   AddOverrides();
        bool              IsPlatformTypeOf( uint32_t hwMask, uint32_t gtMask = GT_TYPE_ALL );
        bool              IsPavpDisabled( uint32_t capabilities );
        bool              IsAvailabilityEquationTrue( const char* availabilityEquation );

        TCompletionCode   SaveToFile( const char* fileName );
        TCompletionCode   OpenFromFile( const char* fileName, bool isInternalBuild );

        CConcurrentGroup* GetConcurrentGroupByName( const char* symbolicName );
        CDriverInterface* GetDriverInterface();
        CSymbolSet*       GetSymbolSet();
        TPlatformType     GetPlatformType();
        bool              IsOpenedFromFile();

    private:
        // Methods to read from file must be used in correct order
        TCompletionCode   ReadGlobalSymbolsFromFileBuffer( unsigned char** bufferPtr );
        TCompletionCode   ReadConcurrentGroupsFromFileBuffer( unsigned char** bufferPtr, bool isInternalBuild, SMetricsDeviceParams_1_0::SApiVersion* apiVersion );
        TCompletionCode   ReadMetricSetsFromFileBuffer( unsigned char** bufferPtr, CConcurrentGroup* group, bool isInternalBuild, SMetricsDeviceParams_1_0::SApiVersion* apiVersion );
        TCompletionCode   ReadMetricsFromFileBuffer( unsigned char** bufferPtr, CMetricSet* set, bool isSetDefault );
        TCompletionCode   ReadInformationFromFileBuffer( unsigned char** bufferPtr, CMetricSet* set );
        TCompletionCode   ReadRegistersFromFileBuffer( unsigned char** bufferPtr, CMetricSet* set );

        IOverride_1_2*    AddOverride( TOverrideType overrideType );
        bool              IsMetricsFileInPlainTextFormat( FILE* metricFile );

    private: // Variables
        TMetricsDeviceParams_1_2    m_params;

        Vector<CConcurrentGroup*>*  m_groupsVector;
        Vector<IOverride_1_2*>*     m_overridesVector;
        CSymbolSet                  m_symbolSet;

        CDriverInterface*           m_driverInterface;
        TPlatformType               m_platform;
        TGTType                     m_gtType;
        bool                        m_isOpenedFromFile;

    };

/*****************************************************************************\

Class:
    COverrideCommon

Description:
    Common class representing a device override.

\*****************************************************************************/
    class COverrideCommon : public IOverride_1_2
    {
    public:
        const TOverrideInternalParams* GetParamsInternal( void );

    protected:  // Constructor
        COverrideCommon( void );

    protected: // Variables
        TOverrideInternalParams m_internalParams;
    };

/*****************************************************************************\

Class:
    COverride

Description:
    Class representing a single device override.

\*****************************************************************************/
    template <TOverrideType overrideType>
    class COverride : public COverrideCommon
    {
    public: // IOverride_1_2
        virtual TOverrideParams_1_2*      GetParams( void );
        virtual TCompletionCode           SetOverride( TSetOverrideParams_1_2* params, uint32_t paramsSize );

    public: // Constructor & Destructor
        COverride( CMetricsDevice *device );
        virtual ~COverride();

    private: // Variables
        TOverrideParams_1_2    m_params;
        CMetricsDevice*        m_device;
    };

/*****************************************************************************\

Class:
    CConcurrentGroup

Description:
    The metrics groups that can be collected concurrently to another group.
    Stores metric sets.

\*****************************************************************************/
    class CConcurrentGroup: public IInternalConcurrentGroup
    {
    public: // IConcurrentGroup_1_0
        virtual TConcurrentGroupParams_1_0* GetParams( void );
        virtual IMetricSet_1_5*             GetMetricSet( uint32_t index );
            // IInternalConcurrentGroup
        virtual IMetricSet_1_5*             AddCustomMetricSet( TAddCustomMetricSetParams* params, IMetricSet_1_0* referenceMetricSet, bool copyInformationOnly );

    protected:
        static const uint32_t     SETS_VECTOR_INCREASE           = 16;
        static const TReportType  DEFAULT_METRIC_SET_REPORT_TYPE = OA_REPORT_TYPE_256B_A45_NOA16;

    public: // Constructor & Destructor
        CConcurrentGroup( CMetricsDevice *device, const char* name, const char* longName, uint32_t measurementTypeMask );
        virtual ~CConcurrentGroup();

    public: // Functions parsed from XML
        CMetricSet*     AddMetricSet( const char* symbolicName, const char* shortName, uint32_t apiMask, uint32_t categoryMask,
            uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, uint32_t platformMask,
            uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );
        CMetricSet*     GetMetricSetByName( const char* symbolName );

        TCompletionCode Lock();
        TCompletionCode Unlock();
        TCompletionCode WriteCConcurrentGroupToFile( FILE* metricFile );

    protected:
        IMetricSet_1_5* AddCustomMetricSet( CMetricSet* referenceMetricSet, const char* signalName, const char* symbolName,
            const char* shortName, uint32_t apiMask, uint32_t categoryMask, uint32_t platformMask, uint32_t gtMask, uint32_t rawReportSize,
            uint32_t queryReportSize, const char* complementarySetsList, TApiSpecificId_1_0 apiSpecificId, TRegisterSet* startRegSets,
            uint32_t startRegSetsCount, bool copyInformationOnly = false );
        bool            MatchingSetExists( const char* symbolName, uint32_t platformMask, uint32_t gtMask );
        bool            AreMetricSetParamsValid( const char* symbolName, const char* shortName, uint32_t platformMask, uint32_t gtMask, TRegisterSet* startRegSets,
            uint32_t startRegSetsCount );
        uint32_t        GetCustomSetCount();

        CMetricSet*     FindSameMetricSetForPlatform(CMetricSet* metricSet, uint32_t platformMask);

    protected: // Variables
        TConcurrentGroupParams_1_0  m_params_1_0;
        void*                       m_semaphore;

        Vector<CMetricSet*>*        m_setsVector;
        // List of sets unavailable on current platform
        List<CMetricSet*>*          m_otherSetsList;

        CMetricsDevice*             m_device;
    };

/*****************************************************************************\

Class:
    COAConcurrentGroup

Description:
    The OA metrics groups that can be collected concurrently to another group.
    Stores metric sets. It has IO Stream implemented.

\*****************************************************************************/
    class COAConcurrentGroup: public CConcurrentGroup
    {
    protected:
        static const uint32_t EXCEPTIONS_VECTOR_INCREASE   = 16;
        static const uint32_t GPU_CONTEXTS_VECTOR_INCREASE = 16;

    public:// Constructor & Destructor
        COAConcurrentGroup( CMetricsDevice *device, const char* name, const char* longName, uint32_t measurementTypeMask );
        virtual ~COAConcurrentGroup();

    public:
        virtual IMetricSet_1_5*   AddCustomMetricSet( TAddCustomMetricSetParams* params, IMetricSet_1_0* referenceMetricSet, bool copyInformationOnly = false );
        virtual TCompletionCode   SetIoStreamSamplingType( TSamplingType type );
        virtual TCompletionCode   OpenIoStream( IMetricSet_1_0* metricSet, uint32_t processId, uint32_t* nsTimerPeriod, uint32_t* oaBufferSize );
        virtual TCompletionCode   ReadIoStream( uint32_t* reportCount, char* reportData, uint32_t readFlags );
        virtual TCompletionCode   CloseIoStream( void );
        virtual TCompletionCode   WaitForReports( uint32_t milliseconds );
        IInformation_1_0*         GetIoMeasurementInformation( uint32_t index );
        IInformation_1_0*         GetIoGpuContextInformation( uint32_t index );

    protected:
        CInformation*             AddIoMeasurementInformation( const char* name, const char* shortName, const char* longName, const char* group,
            TInformationType informationType, const char* informationUnits );
        void                      AddIoMeasurementInfoPredefined( void );
        CInformation*             AddIoGpuContextInformation( const char* name, const char* shortName, const char* longName, const char* group,
            TInformationType informationType, const char* informationUnits );
        void                      SetIoMeasurementInfoPredefined( TIoMeasurementInfoType ioMeasurementInfoType, uint32_t value, uint32_t* index );
        TCompletionCode           ReadGpuContextIdTags( void );
        TCompletionCode           TryReadGpuCtxTags( void );
        TCompletionCode           ProcessGpuContextTags( TContextTag* tags, uint32_t tagCount );

    protected: // Variables
        TStreamType             m_streamType;
        CMetricSet*             m_ioMetricSet;
        bool                    m_contextTagsEnabled;
        uint32_t                m_processId;
        void*                   m_streamEventHandle;
        Vector<CInformation*>*  m_ioMeasurementInfoVector;
        Vector<CInformation*>*  m_ioGpuContextInfoVector;
    };

/*****************************************************************************\

Class:
    CPerfMonConcurrentGroup

Description:
    The PerfMon metrics groups that can be collected concurrently to another group.
    Stores metric sets. It has Sys IO Stream implemented.

\*****************************************************************************/
    class CPerfMonConcurrentGroup: public COAConcurrentGroup
    {
    public: // Constructor & Destructor
        CPerfMonConcurrentGroup( CMetricsDevice *device, const char* name, const char* description, uint32_t measurementTypeMask );

    public:
        TCompletionCode   OpenIoStream( IMetricSet_1_0* metricSet, uint32_t processId, uint32_t* nsTimerPeriod, uint32_t* sysBufferSize );
        TCompletionCode   ReadIoStream( uint32_t* reportCount, char* reportData, uint32_t readFlags );
        TCompletionCode   CloseIoStream( void );
        TCompletionCode   WaitForReports( uint32_t milliseconds );
    };

/*****************************************************************************\

Class:
    CMetricSet

Description:
    The metric sets mapping to different HW configuration that should be used
    exclusively to each other metric set in the concurrent group.
    Stores metrics, information, complementary metric sets, start configurations.

\*****************************************************************************/
    class CMetricSet: public IInternalMetricSet
    {
    public: // IMetricSet_1_0
        virtual TMetricSetParams_1_4* GetParams( void );
        virtual IMetric_1_0*          GetMetric( uint32_t index );
        virtual IInformation_1_0*     GetInformation( uint32_t index );
        virtual IMetricSet_1_5*       GetComplementaryMetricSet( uint32_t index );

        // To enable this configuration before query instance is created or IO stream is opened
        virtual TCompletionCode Activate( void );
        // To disable this configuration after query instance is created or IO stream is closed
        virtual TCompletionCode Deactivate( void );

        virtual IMetric_1_0*    AddCustomMetric(
            const char* symbolName, const char* shortName, const char* groupName, const char* longName, const char* dxToOglAlias,
            uint32_t usageFlagsMask, uint32_t apiMask, TMetricResultType resultType, const char* resultUnits, TMetricType metricType,
            int64_t loWatermark, int64_t hiWatermark, THwUnitType hwType, const char* ioReadEquation, const char* deltaFunction,
	        const char* queryReadEquation, const char* normalizationEquation, const char* maxValueEquation, const char* signalName );
        virtual IMetric_1_0*    AddCustomMetric( TAddCustomMetricParams* params ); // IInternalMetricSet

        // IMetricSet_1_1
        virtual TCompletionCode SetApiFiltering( uint32_t apiMask );
        virtual TCompletionCode CalculateMetrics( const unsigned char* rawData, uint32_t rawDataSize, TTypedValue_1_0* out,
            uint32_t outSize, uint32_t* outReportCount, bool enableContextFiltering );
        virtual TCompletionCode CalculateIoMeasurementInformation( TTypedValue_1_0* out, uint32_t outSize );

        // IMetricSet_1_5
        virtual TCompletionCode CalculateMetrics( const unsigned char* rawData, uint32_t rawDataSize, TTypedValue_1_0* out,
            uint32_t outSize, uint32_t* outReportCount, TTypedValue_1_0* outMaxValues, uint32_t outMaxValuesSize );

    private: // Constants
        static const uint32_t METRICS_VECTOR_INCREASE            = 64;
        static const uint32_t INFORMATION_VECTOR_INCREASE        = 16;
        static const uint32_t COMPLEMENTARY_SETS_VECTOR_INCREASE = 16;
        static const uint32_t START_REGS_VECTOR_INCREASE         = 128;
        static const uint32_t START_REGS_QUERY_VECTOR_INCREASE   = 16;
        static const uint32_t STOP_REGS_VECTOR_INCREASE          = 32;

    public: // Constructor & Destructor
        CMetricSet( CMetricsDevice* device, CConcurrentGroup* concurrentGroup, const char* symbolicName, const char* shortName, uint32_t apiMask,
            uint32_t category, uint32_t snapshotReportSize, uint32_t deltaReportSize, TReportType reportType, uint32_t platformMask,
            uint32_t gtMask = GT_TYPE_ALL, bool isCustom = false );
        virtual ~CMetricSet();

    public:
        TCompletionCode     SetApiSpecificId( const char* dx9Fourcc, uint32_t dx9QueryId, uint32_t dx10Counter, uint32_t oglQuery,
            uint32_t ocl, uint32_t hwConfig, const char* dx10CounterName, uint32_t dx10QueryId, const char* oglQueryName, uint32_t oglQueryARB );
        TCompletionCode     SetApiSpecificId( TApiSpecificId_1_0 apiSepcificId );

        CMetric*            AddMetric( const char* symbolName, const char* shortName, const char* longName, const char* groupName,
            uint32_t groupId, uint32_t usageFlagsMask, uint32_t apiMask, TMetricType metricType, TMetricResultType resultType,
            const char* units, int64_t loWatermark, int64_t hiWatermark, THwUnitType hwType, const char* availabilityEquation,
            const char* alias, const char* signalName, bool isCustom = false );
        CMetric*            AddMetric( CMetric* metric );

        CInformation*       AddInformation( const char* symbolName, const char* shortName, const char* longName,
            const char* groupName, uint32_t apiMask, TInformationType informationType, const char* informationUnits,
            const char* availabilityEquation );
        CInformation*       AddInformation( CInformation* information );
        bool                HasInformation( const char* symbolName );

        TCompletionCode     AddComplementaryMetricSet( const char* complementaryMetricSetSymbolicName );
        TCompletionCode     AddComplementaryMetricSets( const char* complementarySetsList );

        TCompletionCode     AddStartRegisterSet( uint32_t configId, uint32_t configPriority, const char* availabilityEquation = NULL,
            TConfigType configType = CONFIG_TYPE_COMMON );
        TCompletionCode     AddStartConfigRegister( uint32_t offset, uint32_t value, TRegisterType type );
        TCompletionCode     RefreshConfigRegisters();
        TRegister**         GetStartConfiguration( uint32_t* count );
        TCompletionCode     SendStartConfiguration( bool sendQueryConfigFlag );
        void                AppendToConfiguration( Vector<TRegister*>* sourceRegs, Vector<TRegister*>* outPmRegs, Vector<TRegister*>* outReadRegs );
        bool                CheckSendConfigRequired( bool sendQueryConfigFlag );

        TCompletionCode     ActivateInternal( bool sendConfigFlag, bool sendQueryConfigFlag );

        TReportType         GetReportType();
        TCompletionCode     InheritFromMetricSet( CMetricSet* referenceMetricSet, const char* signalName, bool copyInformationOnly );
        TCompletionCode     WriteCMetricSetToFile( FILE* metricFile );
        bool                IsMetricAlreadyAdded( const char* symbolName );
        bool                IsCustom();
        CMetricsCalculator* GetMetricsCalculator();

    private:
        // API filtering
        bool                IsApiFilteringMaskValid( uint32_t apiMask );
        void                EnableApiFiltering( uint32_t apiMask, bool enable );
        void                UseApiFilteredVariables( bool enable );
        void                RefreshCachedMetricsAndInformation();
        void                ClearCachedMetricsAndInformation();
        TCompletionCode     ValidateCalculateMetricsParams( uint32_t rawDataSize, uint32_t rawReportSize, uint32_t outSize,
            uint32_t rawReportCount, uint32_t outMaxValuesSize );
        void                InitializeCalculationManager( TMeasurementType measurementType, CCalculationManager** calculationManager, bool init );
        TCompletionCode     InitializeCalculationContext( TCalculationContext& context, CCalculationManager* calculationManager, TMeasurementType measurementType,
            TTypedValue_1_0* out, TTypedValue_1_0* outMaxValues, const unsigned char* rawData, uint32_t rawReportCount, bool init );

        bool                AreMetricParamsValid( const char* symbolName, const char* shortName, const char* description, const char* groupName,
            TMetricType metricType, TMetricResultType resultType, const char* units, THwUnitType hwType, const char* alias );

        uint32_t            MetricGroupNameToId( const char* groupName );
        uint32_t            GetPartialGroupId( char* groupName, uint32_t tokenNo );
        bool                GetStartRegSetHiPriority( uint32_t id, CRegisterSet** registerSet );
        bool                CheckNoaProgrammingExists( Vector<TRegister*>* regVector );

    private: // Variables
        TMetricSetParams_1_4    m_params_1_0;
        TReportType             m_reportType;

        Vector<CMetric*>*       m_metricsVector;
        Vector<CInformation*>*  m_informationVector;
        Vector<const char*>*    m_complementarySetsVector;
        Vector<TRegister*>*     m_startRegsVector;           // Stores only references
        Vector<TRegister*>*     m_startRegsQueryVector;      // Stores only references

        List<CRegisterSet*>*    m_startRegisterSetList;

        // List of unavailable metrics and information
        List<CMetric*>*         m_otherMetricsList;
        List<CInformation*>*    m_otherInformationList;

        CMetricsDevice*         m_device;
        CConcurrentGroup*       m_concurrentGroup;

        // References to the currently used params/collections - filtered or not
        TMetricSetParams_1_4*   m_currentParams;
        Vector<CMetric*>*       m_currentMetricsVector;
        Vector<CInformation*>*  m_currentInformationVector;

        // API filtered params/collections
        TMetricSetParams_1_4    m_filteredParams;
        Vector<CMetric*>*       m_filteredMetricsVector;     // Stores only references
        Vector<CInformation*>*  m_filteredInformationVector; // Stores only references

        // Runtime state
        bool                    m_isFiltered;                // if true then 'filtered' variables are used
        bool                    m_isCustom;                  // if true then it has custom metrics or it's a custom set
        bool                    m_isReadRegsCfgSet;          // if true then read regs config will be cleared on Deactivate; determined during Activate
        TPmRegsConfigInfo       m_pmRegsConfigInfo;
        CMetricsCalculator*     m_metricsCalculator;
    };

/*****************************************************************************\

Class:
    CMetric

Description:
    The metric that is sampled. Stores all metric information.

\*****************************************************************************/
    class CMetric: public IMetric_1_0
    {
    public: // IMetric_1_0
        virtual TMetricParams_1_0* GetParams( void );

    public: // Constructor & Destructor
        CMetric( CMetricsDevice* device, uint32_t id, const char* name, const char* shortName, const char* longName,
            const char* group, uint32_t groupId, uint32_t usageFlagsMask, uint32_t apiMask, TMetricType metricType,
            TMetricResultType resultType, const char* units, int64_t loWatermark, int64_t hiWatermark, THwUnitType hwType,
            const char* alias, const char* signalName );
        explicit CMetric(const CMetric& other);
        virtual ~CMetric();

    public: // Functions parsed from XML
        TCompletionCode SetSnapshotReportReadEquation( const char* equationSting );
        TCompletionCode SetDeltaReportReadEquation( const char* equationSting );
        TCompletionCode SetNormalizationEquation( const char* equationSting );
        TCompletionCode SetSnapshotReportDeltaFunction( const char* equationSting );
        TCompletionCode SetAvailabilityEquation( const char* equationSting );
        TCompletionCode SetMaxValueEquation( const char* equationSting );

        TCompletionCode WriteCMetricToFile( FILE* metricFile );
        TCompletionCode SetSnapshotReportDeltaFunction( TDeltaFunction_1_0 deltaFunction );
        const char*     GetSignalName();

    private:
        uint64_t        GetMetricValue( const char* valueString );

    private: // Variables
        TMetricParams_1_0    m_params_1_0;
        const char*          m_signalName;
        CEquation*           m_availabilityEquation;
        CEquation*           m_ioReadEquation;
        CEquation*           m_queryReadEquation;
        CEquation*           m_normEquation;
        CEquation*           m_maxValueEquation;
        CMetricsDevice*      m_device;
    };

/*****************************************************************************\

Class:
    CInformation

Description:
    The measurement information parameter.

\*****************************************************************************/
    class CInformation: public IInformation_1_0
    {
    public: // IInformation_1_0
        virtual TInformationParams_1_0* GetParams( void );

    public: // Constructor & Destructor
        CInformation( CMetricsDevice* device, uint32_t id, const char* name, const char* shortName, const char* longName,
            const char* group, uint32_t apiMask, TInformationType informationType, const char* informationUnits );
        explicit CInformation(const CInformation& other);
        virtual ~CInformation();

    public: // Functions parsed from XML
        TCompletionCode SetSnapshotReportReadEquation( const char* equationSting );
        TCompletionCode SetDeltaReportReadEquation( const char* equationSting );
        TCompletionCode SetAvailabilityEquation( const char* equationSting );

        TCompletionCode SetOverflowFunction( const char* equationSting );
        TCompletionCode SetOverflowFunction( TDeltaFunction_1_0 overflowFunction );

        TCompletionCode WriteCInformationToFile( FILE* metricFile );
        TCompletionCode SetInformationValue( uint32_t value, TEquationType equationType );

    private: // Variables
        TInformationParams_1_0  m_params_1_0;
        CEquation*              m_ioReadEquation;
        CEquation*              m_availabilityEquation;
        CEquation*              m_queryReadEquation;
        CMetricsDevice*         m_device;
    };

/*****************************************************************************\

Class:
    CRegisterSet

Description:
    Stores configuration registers along with an availability equation and other
    information.

\*****************************************************************************/
    class CRegisterSet
    {
    public: // Constructor & Destructor
        CRegisterSet( CMetricsDevice* device, uint32_t configId, uint32_t configPriority, TConfigType configType );
        virtual ~CRegisterSet();

    public:
        TRegisterSetParams* GetParams();
        TCompletionCode     SetAvailabilityEquation( const char* equationSting );
        TRegister*          AddConfigRegister( uint32_t offset, uint32_t value, TRegisterType type );
        bool                IsAvailable();
        TCompletionCode     RegsToVector( Vector<TRegister*>* regVector );

        TCompletionCode     WriteCRegisterSetToFile( FILE* metricFile );

    private: // Variables
        List<TRegister>*    m_regList;
        TRegisterSetParams  m_params;
        CEquation*          m_availabilityEquation;
        CMetricsDevice*     m_device;

        bool                m_isAvailable;
    };

/*****************************************************************************\

Class:
    CEquationElementInternal

Description:
    Class which represents equation element.

\*****************************************************************************/
    class CEquationElementInternal
    {
    public:
        CEquationElementInternal();
        CEquationElementInternal( const CEquationElementInternal& element );
        CEquationElementInternal& operator = ( const CEquationElementInternal& element );

        TEquationElement_1_0 Element_1_0;
        char                 SymbolNameInternal[32];
    };

/*****************************************************************************\

Class:
    CEquation

Description:
    Class that stores all the equation information.

\*****************************************************************************/
    class CEquation: public IEquation_1_0
    {
    public: // IEquation_1_0
        virtual uint32_t              GetEquationElementsCount();
        virtual TEquationElement_1_0* GetEquationElement( uint32_t index );

    private:
        static const uint32_t EQUATION_VECTOR_INCREASE = 32;

    public: // Constructor and Destructor
        CEquation( CMetricsDevice* device );
        explicit CEquation( const CEquation& other );
        virtual ~CEquation();

    public: // Functions parsed from XML
        bool SolveBooleanEquation( void ); // Used only for availability equations
        bool ParseEquationString( const char* equationString );
        bool AddEquationElement(CEquationElementInternal* element);
        bool ParseEquationElement( const char* element );

        TCompletionCode WriteCEquationToFile( FILE* metricFile );

    private: // Variables
        Vector<CEquationElementInternal>* m_elementsVector;
        const char*                       m_equationString;
        CMetricsDevice*                   m_device;
    };

/******************************************************************************/
/* Helper functions:                                                          */
/******************************************************************************/
    TCompletionCode GetOpenCloseSemaphore( void** semaphorePtr );
    TCompletionCode ReleaseOpenCloseSemaphore( void** semaphorePtr );
    CDriverInterface* GetDriverIfc();
    void            DestroyDriverIfc();

};
