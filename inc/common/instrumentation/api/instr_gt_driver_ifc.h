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

    File Name:  instr_gt_driver_ifc.h

    Abstract:   Interface for communication between driver and GPA 2.2

    Notes:

\*****************************************************************************/
#ifndef __GTDI_DRIVER_INTERFACE_H_
#define __GTDI_DRIVER_INTERFACE_H_


/******************************************************************************/
/* Escapecodes:                                                               */
/******************************************************************************/
#define GTDI_ESCAPE_CODE_XP     0x00504349
#define GTDI_ESCAPE_CODE_VISTA  12

/******************************************************************************/
/* Shared memory magic:                                                       */
/******************************************************************************/
#define GTDI_MEMORY_MAGIC 0x12344321

/******************************************************************************/
/* Maximum string length:                                                     */
/******************************************************************************/
#define GTDI_PATH_LENGTH    1024

/******************************************************************************/
/* URI size:                                                                  */
/******************************************************************************/
#define GTDI_URI_SIZE 256

/******************************************************************************/
/* Name size:                                                                 */
/******************************************************************************/
#define GTDI_NAME_SIZE 1024

/******************************************************************************/
/* Description size:                                                          */
/******************************************************************************/
#define GTDI_DESC_SIZE 1024

/******************************************************************************/
/* Number of bytes the enable/disable flag utilizes                           */
/******************************************************************************/
#define ENABLE_FLAG_SIZE 4


/******************************************************************************/
/* Metric types:                                                              */
/******************************************************************************/
#define METRIC_TYPE_NUMBER             0x00000000  // winperf PERF_TYPE_NUMBER
#define METRIC_TYPE_SIZE_LARGE         0x00000100  // winperf PERF_SIZE_LARGE
#define METRIC_TYPE_COUNTER            0x00000400  // winperf PERF_TYPE_COUNTER
#define METRIC_TYPE_COUNTER_RATE       0x00010000  // winperf PERF_COUNTER_RATE
#define METRIC_TYPE_COUNTER_FRACTION   0x00020000  // winperf PERF_COUNTER_FRACTION
#define METRIC_TYPE_DELTA_COUNTER      0x00400000  // winperf PERF_DELTA_COUNTER


/******************************************************************************/
/* Display types:                                                             */
/******************************************************************************/
#define METRIC_TYPE_DISPLAY_PER_SEC    0x10000000  // winperf PERF_DISPLAY_PER_SEC
#define METRIC_TYPE_DISPLAY_PERCENT    0x20000000  // winperf PERF_DISPLAY_PERCENT
#define METRIC_TYPE_DISPLAY_SECONDS    0x30000000  // winperf PERF_DISPLAY_SECONDS
#define METRIC_TYPE_DISPLAY_KBS        0x50000000  // added - not present in winperf


/******************************************************************************/
/* bool32_t:                                                                  */
/* 4 bytes long type to represent bool32ean value                             */
/******************************************************************************/
typedef uint32_t bool32_t;

/******************************************************************************/
/* Return codes:                                                              */
/******************************************************************************/
typedef enum GTDI_RETURN_CODE_ENUM
{
    GTDI_RET_OK = 0,
    GTDI_RET_FAILED,
    GTDI_RET_NOT_CONNECTED,
    GTDI_RET_HW_METRICS_NOT_ENABLED,
    GTDI_RET_CONTEXT_ID_MISMATCH,
    GTDI_RET_NOT_SUPPORTED,
    GTDI_RET_PENDING,
    GTDI_RET_INVALID_CONFIGURATION,
    GTDI_RET_CONCURRENT_API_ENABLED,
    GTDI_RET_NO_INFORMATION,     // for GTDI_FNC_GET_ERROR_INFO escape only
    // ...
    GTDI_RET_MAX = 0xFFFFFFFF
} GTDI_RETURN_CODE;


/******************************************************************************/
/* Escape commands/functions:                                                 */
/******************************************************************************/
typedef enum GTDI_ESCAPE_FUNCTION_ENUM
{
    // All GenX architectures
    GTDI_FNC_DEVICE_INFO                = 0,  // Get device information
    GTDI_FNC_IGPA_SUPPORT_ENABLE        = 1,  // Initialize drv instrumentation
    GTDI_FNC_HW_METRICS_ENABLE          = 2,  // Initialize HW metrics support
    GTDI_FNC_CONNECT                    = 3,  // Connect
    GTDI_FNC_DISCONNECT                 = 4,  // Disconnect
    GTDI_FNC_GET_HW_METRIC_SAMPLE       = 5,  // Get HW metrics sample (with optional CHAP reconfiguration) - OBSOLETE FROM GEN6!!!
    GTDI_FNC_SET_CHAP_CFG               = 6,  // Set CHAP configuration - OBSOLETE FROM GEN6!!!
    GTDI_FNC_SET_OVERRIDE_CFG           = 7,  // Enable/disable a particular override

    GTDI_FNC_DEVICE_INFO_EXT            = 8,  // Get extended device information. Processing may take up to 0.5s.

    // Gen5.75 only functions to retrieve extended metrics
    GTDI_FNC_GET_HW_METRIC_SAMPLE_EXT   = 9,  // Get HW metrics sample (with optional CHAP reconfiguration)

    // All GenX architectures (NEW)
    GTDI_FNC_OVERRIDES_SUPPORT_ENABLE   = 10, // Request Null HW override support for selected context

    // Gen6 - Gen7 only functions to retrieve hw metrics
    GTDI_FNC_OPEN_COUNTER_STREAM        = 11, // Open UM application stream for reading from OA buffer
    GTDI_FNC_CLOSE_COUNTER_STREAM       = 12, // Close UM application stream for reading from OA buffer
    GTDI_FNC_SET_PM_REGS_CFG            = 13, // Set registers for dynamic configuration
    GTDI_FNC_GET_EU_CORES_INFO          = 14, // GET EU specific information
    GTDI_FNC_TIMER_MODE_ENABLE          = 15, // Turn timer mode on. Must be called with HardwareAccess flag set to 1.
    GTDI_FNC_EVENT_MODE_ENABLE          = 16, // Turn event mode on. Must be called with HardwareAccess flag set to 1.
    GTDI_FNC_READ_COUNTER_STREAM        = 17, // Request asynchronous read from OA buffer providing UM application buffer to copy data to.

    // Gen7+ function to set Kernel Instrumentation options
    GTDI_FNC_SET_KI_QUERY_CFG           = 18, // Sets query configuration for kernel instrumentation
    GTDI_FNC_SET_KI_BUILD_CFG           = 19, // Sets build configuration for kernel instrumentation

    GTDI_FNC_SET_OVERRIDE_EU_CFG        = 20, // Overridden limit of threads(per EU) and EU cores used by thread dispatcher.

    // Gen7+ Workarounds settings escape
    GTDI_FNC_SET_WORKAROUNDS            = 21,

    GTDI_FNC_SET_KI_QUERY_CFG_EX        = 22, // Sets extended query configuration for kernel instrumentation
    GTDI_FNC_SET_KI_BUILD_CFG_EX        = 23, // Sets extended build configuration for kernel instrumentation
    GTDI_FNC_SET_KERNEL_DUMP_TYPE       = 24, // Sets the result type of Kernel Dump Query (IL/ISA)

    GTDI_FNC_GET_GPU_CPU_TIMESTAMPS     = 25, // Dedicated function for retrieving GPU and CPU timestamps at the same moment
    GTDI_FNC_GET_KI_BUILD_INFO          = 26, // Returns kernel instrumentation build description

    GTDI_FNC_GET_ERROR_INFO             = 27, // extended error information
    GTDI_FNC_DEVICE_INFO_PARAM          = 28,
    GTDI_FNC_SET_DEVICE_PARAM           = 29,
    GTDI_FNC_READ_REGS_CFG              = 30, // Get current values from specified registers
    GTDI_FNC_GET_CTX_ID_TAGS            = 31, // NOT AVAILABLE (removed)
    GTDI_FNC_VALIDATE_PM_REGS_CFG       = 32, // NOT AVAILABLE (removed)
    GTDI_FNC_DMA_MODE_ENABLE            = 33, // Turn per DMA sampling mode on. Must be called with HardwareAccess flag set to 1.

    // ...
    GTDI_FNC_MAX = 0xFFFFFFFF
} GTDI_ESCAPE_FUNCTION;


/******************************************************************************/
/* Interface version:                                                         */
/******************************************************************************/
#define GTDI_MAKE_IFC_VER(major, minor)   (((major) << 8) | (minor))
#define GTDI_GET_MAJOR_IFC_VER(ver)       (ver >> 8)
#define GTDI_GET_MINOR_IFC_VER(ver)       (ver & 0xFF)


typedef enum
{
    GTDI_IFC_VERSION_2        = 0x00,
    GTDI_IFC_VERSION_3        = 0x03,
    // ...
    GTDI_IFC_VERSION_MAJOR_MAX = 0xFFFFFFFF
} GTDI_IFC_VERSION_MAJOR;

typedef enum
{
    GTDI_IFC_VERSION_2_0      = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_2, 1),
    GTDI_IFC_VERSION_2_1      = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_2, 2),
    GTDI_IFC_VERSION_2_2      = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_2, 3),
    GTDI_IFC_VERSION_3_0      = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 0),
    GTDI_IFC_VERSION_3_1      = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 1),
    GTDI_IFC_VERSION_3_2      = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 2),
    GTDI_IFC_VERSION_3_3      = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 3),
    GTDI_IFC_VERSION_3_4      = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 4),
    GTDI_IFC_VERSION_3_5      = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 5),
    GTDI_IFC_VERSION_3_6      = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 6),
    GTDI_IFC_VERSION_3_7      = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 7),
    GTDI_IFC_VERSION_3_8      = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 8),
    GTDI_IFC_VERSION_3_9      = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 9),
    GTDI_IFC_VERSION_3_10     = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 10),
    GTDI_IFC_VERSION_3_11     = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 11),
    GTDI_IFC_VERSION_3_12     = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 12),
    GTDI_IFC_VERSION_3_13     = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 13),
    GTDI_IFC_VERSION_3_14     = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 14),
    GTDI_IFC_VERSION_3_15     = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 15),  // VLV: clock counter on B3
    GTDI_IFC_VERSION_3_16     = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 16),  // VLV: PerfMon memory metrics
    GTDI_IFC_VERSION_3_17     = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 17),  // OCL: PerfCounters unification
    GTDI_IFC_VERSION_3_18     = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 18),  // BDW: Query overrides support
    GTDI_IFC_VERSION_3_19     = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 19),  // Core clock override
    GTDI_IFC_VERSION_3_20     = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 20),  // HW perf counters report layout fix (IVB/HSW)
    GTDI_IFC_VERSION_3_21     = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 21),  // New device params: OA buffer sizes, GPU timestamp freq
    GTDI_IFC_VERSION_3_22     = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 22),  // Registers dump feature (internal drivers only)
    GTDI_IFC_VERSION_3_23     = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 23),  // SKL/BXT base support
    GTDI_IFC_VERSION_3_24     = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 24),  // HSW NOA static cfg update
    GTDI_IFC_VERSION_3_25     = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 25),  // Internal capability flag
    GTDI_IFC_VERSION_3_26     = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 26),  // ValidatePmRegsCfg escape
    GTDI_IFC_VERSION_3_27     = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 27),  // ForceWake device param has been added (set operation only)
    GTDI_IFC_VERSION_3_28     = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 28),  // Cull at BC & PSD for Gen7_5+
    GTDI_IFC_VERSION_3_29     = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 29),  // Support for permanent override
    GTDI_IFC_VERSION_3_30     = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 30),  // Support for next 7 throttling overrides
    GTDI_IFC_VERSION_3_31     = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 31),  // Slice/Unslice frequencies in SKL+ perf counters queries
    GTDI_IFC_VERSION_3_32     = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 32),  // Selective force wake override
    GTDI_IFC_VERSION_3_33     = GTDI_MAKE_IFC_VER(GTDI_IFC_VERSION_3, 33),  // DMA sampling
    // ...
    GTDI_IFC_VERSION_CURRENT  = GTDI_IFC_VERSION_3_33,
    // ...
    GTDI_IFC_VERSION_MAX = 0xFFFFFFFF
} GTDI_IFC_VERSION;

/******************************************************************************/
/* EU Configuration entry type:                                               */
/******************************************************************************/
typedef enum
{
    GTDI_EU_CONFIG_THREADS_PER_EU = 0,
    GTDI_EU_CONFIG_EXECUTION_MASK,
    // ...
    GTDI_EU_CONFIG_MAX = 0xFFFFFFFF
} GTDI_EU_CONFIG_ENTRY_TYPE;


/******************************************************************************/
/* Pipeline stages (used in EU configuration):                                */
/******************************************************************************/
typedef enum
{
    GTDI_VF_VS = 0,
    GTDI_HS,            // IVB+ only
    GTDI_DS,            // IVB+ only
    GTDI_GS,
    GTDI_WIZ,
    GTDI_TS,
    GTDI_CPS,           // TODO: to be verified...
    // ...
    GTDI_MAX_PIPELINE_STAGES,
    // ...
   GTDI_PIPELINE_STAGE_MAX = 0xFFFFFFFF
} GTDI_PIPELINE_STAGE;

/******************************************************************************/
/* GT partition  identifiers (used in EU configuration):                      */
/******************************************************************************/
typedef enum
{
    GTDI_PARTITION_0 = 0,
    GTDI_PARTITION_1,
    GTDI_PARTITION_2,
    GTDI_PARTITION_3,
    GTDI_PARTITION_4,
    GTDI_PARTITION_5,
    GTDI_PARTITION_6,
    // ...
    GTDI_PARTITION_MAX = 0xFFFFFFFF
} GTDI_PARTITION_ID;

/******************************************************************************/
/* GTDIPointer - structure to store user pointer information.                 */
/******************************************************************************/
typedef union
{
    void             *Pointer;          // Pointer value
    uint64_t          UmBufferOffset64; // Placeholder
} GTDIPointer;

/******************************************************************************/
/* Macro to set pointer in GTDIPointer structure.                             */
/******************************************************************************/
#define GTDI_SET_POINTER(GTDIPtr, val) \
    (GTDIPtr).UmBufferOffset64 = 0;    \
    (GTDIPtr).Pointer = val;

/******************************************************************************/
/* GTDIBaseIn:                                                                */
/******************************************************************************/
typedef struct GTDIBaseInStruct
{
    GTDI_ESCAPE_FUNCTION    Function;
} GTDIHeaderIn;


/******************************************************************************/
/* GTDIBaseOut:                                                               */
/******************************************************************************/
typedef struct GTDIBaseOutStruct
{
    GTDI_RETURN_CODE        RetCode; // Result of the operation
} GTDIHeaderOut;


/******************************************************************************/
/* GTDI_PLATFORM_INDEX                                                        */
/******************************************************************************/
typedef enum
{
    // 0-4 reserved
    GENERATION_HSW = 5,
    GENERATION_BDW,
    GENERATION_SKL,
    // 8-9 reserved
    GENERATION_BXT = 10,
    // 11 reserved
    GENERATION_KBL = 12,
    // 13-18 reserved
    // ...
    GTDI_PLATFORM_MAX = 0xFFFFFFF
} GTDI_PLATFORM_INDEX;


/******************************************************************************/
/* GTDI_WORKAROUND_ID                                                         */
/******************************************************************************/
typedef enum
{
    GTDI_IVB_COUNTERS_FREEZE_ON_REPORTING_OFF,  // IVB C0+
    GTDI_WA_ENABLE_IA_FREQUENCY_LIMITER,
    GTDI_HSW_ENABLE_SLICE_SHUTDOWN,
    // ...
    GTDI_WORKAROUND_ID_MAX = 0xFFFFFFFF
} GTDI_WORKAROUND_ID;

#define GTDI_CAPABILITY_MMIO_BROKEN                         0x0001
#define GTDI_CAPABILITY_VAR_RC                              0x0002   // TBD: propose better name
#define GTDI_CAPABILITY_ME_SM_LOCK                          0x0004
#define GTDI_CAPABILITY_MIN_MAX_FREQ_REPORTING              0x0008
#define GTDI_CAPABILITY_PAVP_DISABLED                       0x0010
#define GTDI_CAPABILITY_SLICE_SHUTDOWN                      0x0020
#define GTDI_CAPABILITY_STREAM_EXCEPTION_FLAGS_REPORTING    0x0040
#define GTDI_CAPABILITY_INTERNAL_DRV                        0x0080

/******************************************************************************/
/* GTDI_FNC_DEVICE_INFO function structure definitions                        */
/******************************************************************************/
/******************************************************************************/
/* GTDIDeviceInfoIn:                                                          */
/******************************************************************************/
typedef struct GTDIDeviceInfoInStruct
{
    GTDI_ESCAPE_FUNCTION  Function;
} GTDIDeviceInfoIn;


typedef struct GTDIDeviceInfoExtInStruct
{
    GTDI_ESCAPE_FUNCTION  Function;
} GTDIDeviceInfoExtIn;


/******************************************************************************/
/* GTDIDeviceInfoOut:                                                         */
/******************************************************************************/
typedef struct GTDIDeviceInfoOutStruct
{
    GTDI_RETURN_CODE RetCode;     // Result of the operation
    uint32_t InterfaceVersion;    // Version of the interface supported
    uint32_t PCIDeviceID;         // The DeviceId of the current adapter
    uint32_t RevisionID;          // Steping of the HW.
    uint32_t DisplayFreq;         // Frequency of the Display Controller
    uint32_t CoreFreq;            // Core Frequency
    uint32_t SamplerFreq;         // Sampler Frequency
    uint32_t MemoryFreq;          // Memory Frequency

    uint32_t ApertureSize;        // Size of the Aperture.
    GTDI_PLATFORM_INDEX Platform; // Platform type (determines the union choice)

    union
    {
        struct
        {
            uint32_t FSBFreq;     // FSBFrequency - Cantiga, Eaglelake
        } GenCtgElkT;

        struct
        {
            uint32_t CSIFreq;     // Ironlake
        } GenIlkT;
    };

} GTDIDeviceInfoOut;


typedef struct GTDIDeviceInfoOutExtStruct
{
    GTDI_RETURN_CODE RetCode;     // Result of the operation
    uint32_t InterfaceVersion;    // Version of the interface supported
    uint32_t PCIDeviceID;         // The DeviceId of the current adapter
    uint32_t RevisionID;          // Stepping of the HW.
    uint32_t DisplayFreq;         // Frequency of the Display Controller
    uint32_t CoreFreq;            // Core Frequency
    uint32_t SamplerFreq;         // Sampler Frequency
    uint32_t MemoryFreq;          // Memory Frequency

    uint32_t ApertureSize;        // Size of the Aperture.
    GTDI_PLATFORM_INDEX Platform; // Platform type (determines the union choice)
    uint32_t Capabilities;

    union
    {
        struct
        {
            uint32_t FSBFreq;     // FSBFrequency - Cantiga, Eaglelake
        } GenCtgElkT;

        struct
        {
            uint64_t CSIFreq;     // Ironlake
        } GenIlkT;

        struct
        {
            uint32_t MinGPUFreqMHz;   // Sandy Bridge/Ivy Bridge/ Haswell minimal turbo freq in MHz
            uint32_t MaxGPUFreqMHz;   // Sandy Bridge/Ivy Bridge/ Haswell maximal turbo freq in MHz
        } GenGtT;

    };

} GTDIDeviceInfoExtOut;

/******************************************************************************/
/* GTDI_FNC_DEVICE_INFO_PARAM function structure definitions                  */
/******************************************************************************/
/******************************************************************************/
/* GTDI_DEVICE_PARAM:                                                          */
/******************************************************************************/
typedef enum GTDI_DEVICE_PARAM_ENUM
{
    GTDI_DEVICE_PARAM_INTERFACE_VERSION = 0,
    GTDI_DEVICE_PARAM_PCI_DEVICE_ID,
    GTDI_DEVICE_PARAM_REVISION_ID,
    GTDI_DEVICE_PARAM_DISPLAY_FREQUENCY,
    GTDI_DEVICE_PARAM_GPU_CORE_MIN_FREQUENCY,
    GTDI_DEVICE_PARAM_GPU_CORE_MAX_FREQUENCY,
    GTDI_DEVICE_PARAM_GPU_CORE_FREQUENCY,
    GTDI_DEVICE_PARAM_DRAM_FREQUENCY,
    GTDI_DEVICE_PARAM_DRAM_PEAK_THROUGHTPUT,
    GTDI_DEVICE_PARAM_DRAM_MIN_STOLEN_VIDEO_MEMORY,
    GTDI_DEVICE_PARAM_DRAM_CURRENT_VIDEO_MEMORY,
    GTDI_DEVICE_PARAM_APERTURE_SIZE,
    GTDI_DEVICE_PARAM_PLATFORM_INDEX,
    GTDI_DEVICE_PARAM_CAPABILITIES,

    GTDI_DEVICE_PARAM_EU_THREADS_COUNT,
    GTDI_DEVICE_PARAM_EU_CORES_TOTAL_COUNT,
    GTDI_DEVICE_PARAM_EU_CORES_PER_SLICE_COUNT,
    GTDI_DEVICE_PARAM_EU_CORES_PER_SUBSLICE_COUNT,
    GTDI_DEVICE_PARAM_EU_CORES_PER_SUBSLICE_MASK,

    GTDI_DEVICE_PARAM_SLICES_COUNT,
    GTDI_DEVICE_PARAM_SLICES_MASK,

    GTDI_DEVICE_PARAM_SUBSLICES_TOTAL_COUNT,
    GTDI_DEVICE_PARAM_SUBSLICES_PER_SLICE_COUNT,
    GTDI_DEVICE_PARAM_SUBSLICES_MASK,

    GTDI_DEVICE_PARAM_SAMPLERS_COUNT,
    GTDI_DEVICE_PARAM_SAMPLERS_MASK,

    GTDI_DEVICE_PARAM_EU_PARTITIONS_COUNT, // Partition is an abstraction for EU container with max 32 EUs
    GTDI_DEVICE_PARAM_EU_CORES_PER_PARTITION_COUNT,
    GTDI_DEVICE_PARAM_EU_CORES_PER_PARTITION_MASK,

    GTDI_DEVICE_PARAM_NUMBER_OF_RENDER_OUTPUT_UNITS,
    GTDI_DEVICE_PARAM_NUMBER_OF_SHADING_UNITS,

    GTDI_DEVICE_PARAM_GPU_STATIC_FREQUENCY_OVERRIDE,
    GTDI_DEVICE_PARAM_GPU_TURBO_FREQUENCY_OVERRIDE,

    GTDI_DEVICE_PARAM_GPU_TIMESTAMP_FREQUENCY,
    GTDI_DEVICE_PARAM_OA_BUFFER_SIZE_MIN,
    GTDI_DEVICE_PARAM_OA_BUFFER_SIZE_MAX,

    GTDI_DEVICE_PARAM_GPU_FORCE_WAKE_OVERRIDE,

    GTDI_DEVICE_PARAM_PERFORMANCE_MODE,
    GTDI_DEVICE_PARAM_GT_TYPE,

    // Note: This is not implemented on Windows
    GTDI_DEVICE_PARAM_GPU_TIMESTAMP,

    // ...
    GTDI_DEVICE_PARAM_EDRAM_SIZE,
    GTDI_DEVICE_PARAM_LLC_SIZE,
    GTDI_DEVICE_PARAM_L3_SIZE,
    GTDI_DEVICE_PARAM_OA_BUFFER_EDGE_TRIGGERING_OVERRIDE,
    GTDI_DEVICE_PARAM_MAX = 0xFFFFFFFF

} GTDI_DEVICE_PARAM;

/******************************************************************************/
/* GTDI_GTDI_GPU_FORCE_WAKE:                                                          */
/******************************************************************************/
typedef enum GTDI_GPU_FORCE_WAKE_ENUM
{
    GTDI_FORCEWAKE_NONE    = 0,
    GTDI_FORCEWAKE_ALL     = 1,
    GTDI_FORCEWAKE_MEDIA   = 2,
    GTDI_FORCEWAKE_BLITTER = 3,
    GTDI_FORCEWAKE_RENDER  = 4
} GTDI_GTDI_GPU_FORCE_WAKE;


/******************************************************************************/
/* GTDIDeviceInfoParamIn:                                                     */
/******************************************************************************/
typedef struct GTDIDeviceInfoParamInStruct
{
    GTDI_ESCAPE_FUNCTION    Function;
    GTDI_DEVICE_PARAM       Param;    // Identifies parameter to get
    uint32_t                Slice;    // slice id
    uint32_t                SubSlice; // subslice id

} GTDIDeviceInfoParamIn;

/******************************************************************************/
/* GTDI_DEVICE_PARAM_VALUE_TYPE:                                              */
/******************************************************************************/
typedef enum GTDI_DEVICE_PARAM_VALUE_TYPE_ENUM
{
    GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32,
    GTDI_DEVICE_PARAM_VALUE_TYPE_UINT64,
    GTDI_DEVICE_PARAM_VALUE_TYPE_FLOAT,
    GTDI_DEVICE_PARAM_VALUE_TYPE_STRING, // Write only
} GTDI_DEVICE_PARAM_VALUE_TYPE;

/******************************************************************************/
/* GTDIDeviceInfoParamOut:                                                    */
/******************************************************************************/
typedef struct GTDIDeviceInfoParamOutStruct
{
    GTDI_RETURN_CODE RetCode;    // Result of the operation
    GTDI_DEVICE_PARAM_VALUE_TYPE ValueType;// Type of value passed as result
    union
    {
        uint32_t ValueUint32;
        uint64_t ValueUint64;
        float    ValueFloat;
    };
} GTDIDeviceInfoParamOut;

/******************************************************************************/
/* GTDIDeviceInfoParamExtOut: structure intended for string                   */
/******************************************************************************/
typedef struct GTDIDeviceInfoParamExtOutStruct
{
    GTDI_RETURN_CODE RetCode;               // Result of the operation
    GTDI_DEVICE_PARAM_VALUE_TYPE ValueType; // Type of value passed as result
    union
    {
        wchar_t ValueString[GTDI_PATH_LENGTH];
    };
} GTDIDeviceInfoParamExtOut;

/******************************************************************************/
/* GTDISetDeviceParamIn:                                                      */
/******************************************************************************/
typedef struct GTDISetDeviceParamInStruct
{
    GTDI_ESCAPE_FUNCTION         Function;
    uint32_t                     Pid;       // Process ID
    GTDI_DEVICE_PARAM            Param;     // Identifies parameter to set
    GTDI_DEVICE_PARAM_VALUE_TYPE ValueType; // Value type
    union
    {
        uint32_t ValueUint32;
        uint64_t ValueUint64;
        float    ValueFloat;
    };

} GTDISetDeviceParamIn;

/******************************************************************************/
/* GTDISetDeviceParamExtIn: structure intended for string                     */
/******************************************************************************/
typedef struct GTDISetDeviceParamExtInStruct
{
    GTDI_ESCAPE_FUNCTION         Function;
    uint32_t                     Pid;       // Process ID
    GTDI_DEVICE_PARAM            Param;     // Identifies parameter to set
    GTDI_DEVICE_PARAM_VALUE_TYPE ValueType; // Value type
    union
    {
        wchar_t ValueString[GTDI_PATH_LENGTH];
    };

} GTDISetDeviceParamExtIn;

/******************************************************************************/
/* GTDISetDeviceParamOut:                                                    */
/******************************************************************************/
typedef struct GTDISetDeviceParamOutStruct
{
    GTDI_RETURN_CODE RetCode;    // Result of the operation
} GTDISetDeviceParamOut;

/******************************************************************************/
/* GTDI_FNC_IGPA_SUPPORT_ENABLE function structure definitions                */
/******************************************************************************/
/******************************************************************************/
/* GTDIIGPASupportEnableIn:                                                   */
/******************************************************************************/
typedef struct GTDIIGPASupportEnableInStruct
{
    GTDI_ESCAPE_FUNCTION    Function;
    bool32_t                Enable;  // Flag: True = Enable, False = Disable

    // The directory where shared memory files will be stored.
    // Driver need to know that value at this stage to create shared memory
    // files with configuration. Typically the value would be %TEMP% environment
    // variable.
    wchar_t                 SharedMemoryBaseDirectory[GTDI_PATH_LENGTH];
} GTDIIGPASupportEnableIn;


/******************************************************************************/
/* GTDIIGPASupportEnableOut:                                                  */
/******************************************************************************/
typedef struct GTDIIGPASupportEnableOutStruct
{
    GTDI_RETURN_CODE   RetCode; // Result of the operation

    // Name of the file which contains the metric/overrides/events definition
    // The name is relative to the path given in the GTDIIGPASupportEnableInStruct
    // The file is intended to be written by the driver and read by the IGPA
     wchar_t           SystemFileName[GTDI_PATH_LENGTH];

    // Name of the shared memory file which contains the metric/events
    // configuration. The name is relative to the path given in the
    // GTDIIGPASupportEnableInStruct. The file is intended to be written by
    // IGPA to configure proper driver behavior
     wchar_t           SharedMemoryConfigFileName[GTDI_PATH_LENGTH];

} GTDIIGPASupportEnableOut;


/******************************************************************************/
/* GTDI_FNC_SET_OVERRIDE_CFG function structure definitions                   */
/******************************************************************************/
/******************************************************************************/
/* GTDISetOverrideCfgIn:                                                      */
/* OBSOLETE - enum is useful for limited set of used overrides only           */
/******************************************************************************/
typedef enum
{
    GTDI_STALL_LEVEL_NO_STALL,    // No throttling
    GTDI_STALL_LEVEL_50_PERCENT,  // Stall every other cycle
    GTDI_STALL_LEVEL_33_PERCENT,  // Stall every third cycle
    GTDI_STALL_LEVEL_25_PERCENT,  // Stall every fourth cycle
    GTDI_STALL_LEVEL_20_PERCENT,  // Stall every fifth cycle
    GTDI_STALL_LEVEL_16_PERCENT,  // Stall every sixth cycle
    GTDI_STALL_LEVEL_14_PERCENT,  // Stall every seventh cycle
    GTDI_STALL_LEVEL_12_PERCENT,  // Stall every eight cycle

} GTDI_STALL_LEVEL;

typedef struct GTDISetOverrideCfgInStruct
{
    GTDI_ESCAPE_FUNCTION    Function;
    struct
    {
        uint32_t            OverrideId   : 16; // Id of the override to configure
        uint32_t            Reserved     : 14;
        uint32_t            Permanent    : 1;  // 0 - override is enabled/disabled
                                               // per each command buffer separately
                                               // 1 - override state is controlled
                                               // by escape calls only -> DANGEROUS:
                                               // can lead to system  freeze if given
                                               // override is located in the global
                                               // registers
        uint32_t            QueryControl : 1;  // Determines if override setting
    };                                         // is for immediate execution
                                               // (value of 0) or to be applied
                                               // when override control query
                                               // begins (value of 1).
    union
    {
        bool32_t            Enable;     // Flag: True = Enable, False = Disable
        GTDI_STALL_LEVEL    StallLevel; // OBSOLETE
        uint32_t            Value;      // Warning: most significant byte is
                                        // reserved for internal driver use
                                        //
                                        // Available values for given override are
                                        // described in its description. To use given
                                        // value its index should be used instead
                                        // Example:
                                        // "Throttling values: 100%/50%/25%" -> index: 0/1/2
    };
} GTDISetOverrideCfgIn;

/******************************************************************************/
/* GTDISetOverrideCfgOut:                                                     */
/******************************************************************************/
typedef struct GTDISetOverrideCfgOutStruct
{
    GTDI_RETURN_CODE   RetCode; // Result of the operation
} GTDISetOverrideCfgOut;


/******************************************************************************/
/* GTDI_FNC_CONNECT function structure definitions                            */
/******************************************************************************/
/******************************************************************************/
/* GTDIConnectIn:                                                             */
/******************************************************************************/
typedef struct GTDIConnectInStruct
{
    GTDI_ESCAPE_FUNCTION  Function;
    uint32_t PID;                               // Process id of the application
                                                // to be profiled
} GTDIConnectIn;


/******************************************************************************/
/* GTDIConnectOut:                                                            */
/******************************************************************************/
typedef struct GTDIConnectOutStruct
{
    GTDI_RETURN_CODE RetCode;       // Result of the call

    // Name of the shared memory file used for collecting driver metrics and
    // query results (relative to the path given in IGPASupportEnable)
    wchar_t     SharedMemoryContextFileName[GTDI_PATH_LENGTH];

    uint32_t    ContextId;       // Driver id of the context being requested.
} GTDIConnectOut;


/******************************************************************************/
/* GTDI_FNC_DISCONNECT function structure definitions                         */
/******************************************************************************/
/******************************************************************************/
/* GTDIDisconnectIn:                                                          */
/******************************************************************************/
typedef struct GTDIDisconnectInStruct
{
    GTDI_ESCAPE_FUNCTION  Function;
    uint32_t PID;                               // Process id of the profiled
                                                // application
} GTDIDisconnectIn;

/******************************************************************************/
/* GTDIDisconnectOut:                                                         */
/******************************************************************************/
typedef struct GTDIDisconnectOutStruct
{
    GTDI_RETURN_CODE RetCode; // Result of the call
} GTDIDisconnectOut;


/******************************************************************************/
/* Enumeration to distinguish PM configurations                               */
/******************************************************************************/
typedef enum GTDI_CONFIGURATION_SET
{
    GTDI_CONFIGURATION_SET_DYNAMIC = 0,
    GTDI_CONFIGURATION_SET_1,
    GTDI_CONFIGURATION_SET_2,
    GTDI_CONFIGURATION_SET_3,
    GTDI_CONFIGURATION_SET_4,
    GTDI_CONFIGURATION_SET_COUNT,
    // ...
    GTDI_CONFIGURATION_SET_MAX = 0xFFFFFFFF
} GTDI_CONFIGURATION_SET;

/******************************************************************************/
/* GTDI_MAX_PM_REGS:                                                          */
/******************************************************************************/
#define GTDI_MAX_PM_REGS 256

/******************************************************************************/
/* GTDI_MAX_PM_REGS_3_13 that is used in old drivers such as 3.13 or earlier  */
/* versions                                                                   */
/******************************************************************************/
#define GTDI_MAX_PM_REGS_3_13 128

/******************************************************************************/
/* GTDI_MAX_READ_REGS:                                                          */
/******************************************************************************/
#define GTDI_MAX_READ_REGS 16

/******************************************************************************/
/* GTDI_FNC_SET_PM_REGS_CFG function structures definitions                   */
/******************************************************************************/
/******************************************************************************/
/* GTDISetPmRegsCfgIn:                                                        */
/******************************************************************************/
typedef struct GTDISetPmRegsCfgInStruct
{
    GTDI_ESCAPE_FUNCTION  Function;

    // if offset is set to 0 the corresponding NOA value is ignored
    uint32_t RegOffsets[GTDI_MAX_PM_REGS];
    uint32_t RegValues[GTDI_MAX_PM_REGS];

} GTDISetPmRegsCfgIn;

/*******************************************************************************/
/* GTDISetPmRegsCfgIn_3_13 that is used in old drivers such as 3.13 or earlier */
/* versions                                                                    */
/*******************************************************************************/
typedef struct GTDISetPmRegsCfgInStruct_3_13
{
    GTDI_ESCAPE_FUNCTION  Function;

    // if offset is set to 0 the corresponding NOA value is ignored
    uint32_t RegOffsets[GTDI_MAX_PM_REGS_3_13];
    uint32_t RegValues[GTDI_MAX_PM_REGS_3_13];

} GTDISetPmRegsCfgIn_3_13;

/******************************************************************************/
/* GTDISetPmRegsCfgOut:                                                       */
/******************************************************************************/
typedef GTDIHeaderOut GTDISetPmRegsCfgOut;


/******************************************************************************/
/* GTDI_FNC_GET_PM_REGS_CFG function structures definitions                   */
/******************************************************************************/
/******************************************************************************/
/* GTDIReadRegsCfgIn:                                                         */
/******************************************************************************/
typedef struct GTDIReadRegsCfgInStruct
{
    GTDI_ESCAPE_FUNCTION  Function;

    uint32_t RegOffsets[GTDI_MAX_READ_REGS];
    uint32_t RegBitSizes[GTDI_MAX_READ_REGS];
} GTDIReadRegsCfgIn;

/******************************************************************************/
/* GTDIGetPmRegsCfgOut:                                                       */
/******************************************************************************/
typedef struct GTDIReadRegsCfgOutStruct
{
    GTDI_RETURN_CODE        RetCode; // Result of the operation
    uint32_t                UserCntrCfgId;
} GTDIReadRegsCfgOut;

/******************************************************************************/
/* GTDI_FNC_GET_EU_CORES_INFO function structures definitions                 */
/******************************************************************************/
/******************************************************************************/
/* GTDIGetEuCoresInfoIn:                                                      */
/******************************************************************************/
typedef GTDIHeaderIn GTDIGetEuCoresInfoIn;

/******************************************************************************/
/* GTDIGetEuCoresInfoOut:                                                     */
/******************************************************************************/
typedef struct GTDIGetEuCoresInfoOutStruct
{
    GTDI_RETURN_CODE RetCode;         // Result of the call
    uint32_t         PerformanceMode;
    uint32_t         EUCount;
    uint32_t         ThreadsCount;
} GTDIGetEuCoresInfoOut;


/******************************************************************************/
/* Enumeration to choose high or low resolution sampling type                 */
/******************************************************************************/
typedef enum GTDI_SAMPLING_TYPE_ENUM
{
    GTDI_QUERY_MULTI_SAMPLES_TYPE = 0,
    GTDI_IOSTREAM_TYPE,
    GTDI_QUERY_EXTENDED_TYPE,
    // ...
    GTDI_SAMPLING_TYPE_MAX = 0xFFFFFFFF
} GTDI_SAMPLING_TYPE;


/******************************************************************************/
/* Enumeration to choose large or small report size.                          */
/******************************************************************************/
typedef enum GTDI_REPORT_TYPE_ENUM
{
    // PerfCounters report types
    GTDI_REPORT_TYPE_128B_A13_NOA16 = 0,    // report format is
                                            //    GTDI_IVB_REPORT_128B_A13_NOA16 or
                                            //    GTDI_HSW_REPORT_128B_A13_NOA16
    GTDI_REPORT_TYPE_192B_A29_NOA16,        // OBSOLETE report format is
                                            //    GTDI_IVB_REPORT_192B_A29_NOA16 or
                                            //    GTDI_HSW_REPORT_192B_A29_NOA16
    GTDI_REPORT_TYPE_256B_A45_NOA16,        // report format is
                                            //    GTDI_IVB_REPORT_256B_A45_NOA16 or
                                            //    GTDI_HSW_REPORT_256B_A45_NOA16
    GTDI_REPORT_TYPE_64B_A13,               // report format is
                                            //     GTDI_HSW_REPORT_64B_A13
    GTDI_REPORT_TYPE_128B_A29,              // report format is
                                            //     GTDI_HSW_REPORT_128B_A29
    GTDI_REPORT_TYPE_64B_NOA12,             // report format is
                                            //     GTDI_HSW_REPORT_64B_NOA12
    GTDI_REPORT_TYPE_128B_A16_NOA12,        // report format is
                                            //     GTDI_HSW_REPORT_128B_A16_NOA12
    GTDI_REPORT_TYPE_64B_NOA12_2,           // report format is
                                            //     GTDI_HSW_REPORT_64B_NOA12_2
    // Extended report types (used in DMA sampling)
    GTDI_REPORT_TYPE_FULL = 100,            // combo format (timestamp & oa256 & perfmons & mc * user)
    GTDI_REPORT_TYPE_TIMESTAMP,             // timestamp
    GTDI_REPORT_TYPE_PERFMONS,              // 2 QWORD perfmon counters
    GTDI_REPORT_TYPE_MC,                    // memory counters
    GTDI_REPORT_TYPE_USER,                  // 8 user defined uint32_t counters



    GTDI_REPORT_TYPE_MAX = 0xFFFFFFFF
} GTDI_REPORT_TYPE;



/******************************************************************************/
/* GTDI_FNC_TIMER_MODE_ENABLE function structures definitions                 */
/******************************************************************************/

/******************************************************************************/
/* GTDITimerModeEnableIn:                                                     */
/******************************************************************************/
typedef struct GTDITimerModeEnableInStruct
{
    GTDI_ESCAPE_FUNCTION    Function;
    bool32_t                Enable;
    GTDI_SAMPLING_TYPE      SamplingType;
    GTDI_REPORT_TYPE        ReportType;
    uint32_t                TimerPeriod;// proposed timer period in nanoseconds
                                        // hardware will set the most near value
                                        // allowed in hw not exceeding the proposed
    uint32_t                OaBufferSize; // proposed OA buffer size
    GTDI_CONFIGURATION_SET  ConfigurationId; // used only in IOSTREAM sampling type
} GTDITimerModeEnableIn;

/******************************************************************************/
/* GTDITimerModeEnableOut:                                                    */
/******************************************************************************/
typedef struct GTDITimerModeEnableOutStruct
{
    GTDI_RETURN_CODE        RetCode;       // Result of the call
    uint32_t                TimerPeriod;   // Timer period in nanoseconds that has been
                                           // set in hardware
    uint32_t                OaBufferSize;  // OA buffer size that has been set in hardware. Used only in IOSTREAM sampling type
} GTDITimerModeEnableOut;


/******************************************************************************/
/* GTDI_FNC_EVENT_MODE_ENABLE function structures definitions                 */
/******************************************************************************/

/******************************************************************************/
/* GTDIEventModeEnableIn:                                                     */
/******************************************************************************/
typedef struct GTDIEventModeEnableInStruct
{
    GTDI_ESCAPE_FUNCTION    Function;
    bool32_t                Enable;
    GTDI_SAMPLING_TYPE      SamplingType;
    GTDI_REPORT_TYPE        ReportType;
    uint32_t                OaBufferSize;    // proposed OA buffer size. Used only in IOSTREAM sampling type
    GTDI_CONFIGURATION_SET  ConfigurationId; // used only in IOSTREAM sampling type

} GTDIEventModeEnableIn;

/******************************************************************************/
/* GTDIEventModeEnableOut:                                                    */
/******************************************************************************/
typedef struct GTDIEventModeEnableOutStruct
{
    GTDI_RETURN_CODE        RetCode;       // Result of the call
    uint32_t                OaBufferSize;  // OA buffer size that has been set in hardware
} GTDIEventModeEnableOut;


/******************************************************************************/
/* GTDI_FNC_DMA_MODE_ENABLE function structures definitions                   */
/******************************************************************************/

/******************************************************************************/
/* GTDIDmaModeEnableIn:                                                       */
/******************************************************************************/
typedef struct GTDIDmaModeEnableInStruct
{
    GTDI_ESCAPE_FUNCTION    Function;
    bool32_t                Enable;
    GTDI_SAMPLING_TYPE      SamplingType;    // only GTDI_IOSTREAM_TYPE allowed
    GTDI_REPORT_TYPE        ReportType;
    uint32_t                BufferSize;      // proposed buffer size.
    GTDI_CONFIGURATION_SET  ConfigurationId;
} GTDIDmaModeEnableIn;

/******************************************************************************/
/* GTDIDmaModeEnableOut:                                                    */
/******************************************************************************/
typedef struct GTDIDmaModeEnableOutStruct
{
    GTDI_RETURN_CODE        RetCode;       // Result of the call
    uint32_t                BufferSize;    // Buffer size that has been set in the hardware
} GTDIDmaModeEnableOut;

/******************************************************************************/
/* GTDI_FNC_HW_METRICS_ENABLE function structure definitions                  */
/******************************************************************************/
/******************************************************************************/
/* GTDIHWMetricsEnableIn:                                                     */
/******************************************************************************/
typedef struct GTDIHWMetricsEnableInStruct
{
   GTDI_ESCAPE_FUNCTION  Function;
   bool32_t Enable;      // Flag: True = Enable, False = Disable
} GTDIHWMetricsEnableIn;

/******************************************************************************/
/* GTDIHWMetricsEnableOut                                                     */
/******************************************************************************/
typedef struct GTDIHWMetricsEnableOutStruct
{
    GTDI_RETURN_CODE RetCode; // Result of the call
} GTDIHWMetricsEnableOut;

/******************************************************************************/
/* GTDI_FNC_SET_CHAP_CFG function structure definitions                       */
/******************************************************************************/
/******************************************************************************/
/* GTDI_REGISTER_CONFIG_TYPE                                                  */
/******************************************************************************/
typedef enum GTDI_REGISTER_CONFIG_TYPE_ENUM
{
    CFG_TYPE_EVENT = 0,
    CFG_TYPE_NOA,
    CFG_TYPE_CHAP,
    // ...
    CFG_TYPE_MAX = 0xFFFFFFFF
} GTDI_REGISTER_CONFIG_TYPE;

/******************************************************************************/
/* GTDIRegisterConfig                                                         */
/******************************************************************************/
typedef struct GTDIRegisterConfigStruct
{
    GTDI_REGISTER_CONFIG_TYPE Type;
    uint32_t   Offset;
    uint32_t   Value;
} GTDIRegisterConfig;

/******************************************************************************/
/* GTDISetHWMetricConfigurationIn                                             */
/******************************************************************************/
typedef struct GTDISetHWMetricConfigurationInStruct
{
    GTDI_ESCAPE_FUNCTION  Function;
    uint32_t RegisterCount;
    // Followed by RegisterCount number of GTDIRegisterConfig records
} GTDISetHWMetricConfigurationIn;


/******************************************************************************/
/* GTDISetHWMetricConfigurationIn                                             */
/******************************************************************************/
typedef struct GTDISetHWMetricConfigurationOutStruct
{
    GTDI_RETURN_CODE RetCode; // Result of the call
}GTDISetHWMetricConfigurationOut;


/******************************************************************************/
/* GTDI_FNC_GET_HW_METRIC_SAMPLE function structure definitions               */
/******************************************************************************/
/******************************************************************************/
/* GTDI_NUM_CHAP_REGISTERS                                                    */
/******************************************************************************/
#define GTDI_NUM_CHAP_REGISTERS         8

/******************************************************************************/
/* MMIO registers                                                             */
/******************************************************************************/
#define GTDI_NUM_MMIO_REGISTERS_GEN_CTGELK  9 //
#define GTDI_NUM_MMIO_REGISTERS_GEN_ILK     9 //

typedef enum {
    IA_VERTICES_COUNT = 0,
    IA_PRIMITIVES_COUNT,
    VS_INVOCATION_COUNT,
    GS_INVOCATION_COUNT,
    GS_PRIMITIVES_COUNT,
    CL_INVOCATION_COUNT,
    CL_PRIMITIVES_COUNT,
    PS_INVOCATION_COUNT,
    PS_DEPTH_COUNT,
    // ...
    MMIO_REGISTER_INDEX_MAX = 0xFFFFFFFF
} MMIO_REGISTER_INDEX;

/******************************************************************************/
/* GTDIGetHWMetricSampleIn                                                    */
/******************************************************************************/
typedef struct GTDIGetHWMetricSampleInStruct
{
    GTDI_ESCAPE_FUNCTION  Function;
    uint32_t RegisterCount;   // If RegisterCount != 0 then new HW configuration is set
                           // after retrieving samples.

    // Followed by RegisterCount number of GTDIRegisterConfig records
} GTDIGetHWMetricSampleIn;

typedef struct GTDIGetHWMetricSampleExtInStruct
{
    GTDI_ESCAPE_FUNCTION  Function;
    uint32_t RegisterCount;   // If RegisterCount != 0 then new HW configuration is set
                              // after retrieving samples.

    // Followed by RegisterCount number of GTDIRegisterConfig records
} GTDIGetHWMetricSampleExtIn;

/******************************************************************************/
/* GTDIGGetHWMetricsSampleOutStruct                                            */
/******************************************************************************/
typedef struct GTDIGGetHWMetricsSampleOutStruct
{
    GTDI_RETURN_CODE RetCode;    // Result of the call
    uint64_t LatchTime;          // Timestamp the sample was latched
    uint32_t ContextId;          // Retrieved contextId value for MMIO metrics
    union
    {
        struct
        {
            uint32_t ChapValues[GTDI_NUM_CHAP_REGISTERS];
            uint64_t MMIOValues[GTDI_NUM_MMIO_REGISTERS_GEN_CTGELK];
        }GenCtgElk;
        struct
        {
            uint32_t ChapValues[GTDI_NUM_CHAP_REGISTERS];
            uint64_t MMIOValues[GTDI_NUM_MMIO_REGISTERS_GEN_ILK];
        } GenIlk;
    };
} GTDIGetHWMetricsSampleOut;


typedef struct GTDIGGetHWMetricsSampleExtOutStruct
{
    GTDI_RETURN_CODE RetCode;    // Result of the call
    uint64_t LatchTime;          // Timestamp the sample was latched
    uint32_t ContextId;          // Retrieved contextId value for MMIO metrics
    union
    {
        struct
        {
            uint32_t ChapValues[GTDI_NUM_CHAP_REGISTERS];
            uint64_t MMIOValues[GTDI_NUM_MMIO_REGISTERS_GEN_CTGELK];
            uint64_t CurrentCoreFreq;
            uint32_t  FreqContinuityCounter; // incremented each time render clock is changed
        }GenCtgElk;
        struct
        {
            uint32_t ChapValues[GTDI_NUM_CHAP_REGISTERS];
            uint64_t MMIOValues[GTDI_NUM_MMIO_REGISTERS_GEN_ILK];
            uint64_t CurrentCoreFreq;
            uint32_t  FreqContinuityCounter; // incremented each time render clock is changed
        } GenIlk;
    };
} GTDIGetHWMetricsSampleExtOut;

/******************************************************************************/
/* GTDI_FNC_OPEN_COUNTER_STREAM function structure definitions                */
/******************************************************************************/
/******************************************************************************/
/* GTDIOpenCounterStreamIn                                                    */
/******************************************************************************/
typedef struct GTDIOpenCounterStreamInStruct
{
    GTDI_ESCAPE_FUNCTION  Function;
    uint32_t              PID; // Process ID of application to collect metrics for.
                               // If set to 0, all contexts are measured.
    wchar_t               EventName[GTDI_PATH_LENGTH];  // Name of event object
                                                        // used by KMD do signal
                                                        // user when samples are
                                                        // available.
}
GTDIOpenCounterStreamIn;

/******************************************************************************/
/* GTDIOpenCounterStreamOut                                                   */
/******************************************************************************/
typedef struct GTDIOpenCounterStreamOutStruct
{
    GTDI_RETURN_CODE RetCode;    // Result of the call
}
GTDIOpenCounterStreamOut;

/******************************************************************************/
/* GTDI_FNC_READ_COUNTER_STREAM function structure definitions                */
/******************************************************************************/
/******************************************************************************/
/* GTDIReadCounterStreamIn                                                    */
/******************************************************************************/
typedef struct GTDIReadCounterStreamInStruct
{
    GTDI_ESCAPE_FUNCTION  Function;
    uint32_t              BytesToRead;     // Requested data size (in bytes)
                                           // of data copied to user samples buffer.
    GTDIPointer           UmBufferPointer; // Pointer to user samples buffer.
                                           // Use GTDI_SET_POINTER macro to
                                           // set this field.
}
GTDIReadCounterStreamIn;

/******************************************************************************/
/* GTDIReadCounterStreamOut                                                   */
/******************************************************************************/
typedef struct GTDIReadCounterStreamOutStruct
{
    GTDI_RETURN_CODE RetCode;    // Result of the call
    uint32_t         BytesWritten;
    bool32_t         WriteFinished;
}
GTDIReadCounterStreamOut;


/******************************************************************************/
/* GTDIReadCounterStreamExceptions                                            */
/******************************************************************************/
typedef struct GTDIReadCounterStreamExceptionsStruct {
    // Exception flags
    uint32_t FrequencyChanged        : 1;   // frequency change between first and last returned sample
    uint32_t FrequencyChangedInvalid : 1;   // Unable to report freq change due to delayed read. If this exception
                                            // occurs it will be reported until all available data is read from hardware
                                            // during current or following reads. Whether there is data outstanding
                                            // in the buffer after read is indicated by DataOutstanding flag.
    uint32_t SliceShutdown           : 1;   // slice shutdown occurred
    uint32_t ReportLost              : 1;   // Report lost reported by HW. This means that there were some samples lost
                                            // since last Read Stream (not between the first and the last returned sample).
    uint32_t DataOutstanding         : 1;   // Read Stream left some of the newest samples unread.
    uint32_t Reserved                : 27;
} GTDIReadCounterStreamExceptions;

/******************************************************************************/
/* GTDIReadCounterStreamExtOut                                                   */
/******************************************************************************/
typedef struct GTDIReadCounterStreamExtOutStruct
{
    GTDI_RETURN_CODE RetCode;    // Result of the call
    uint32_t         BytesWritten;
    bool32_t         WriteFinished;
    uint32_t         Frequency;   // in MHz

    GTDIReadCounterStreamExceptions Exceptions;
}
GTDIReadCounterStreamExtOut;

/******************************************************************************/
/* GTDI_FNC_CLOSE_COUNTER_STREAM function structure definitions               */
/******************************************************************************/
/******************************************************************************/
/* GTDICloseCounterStreamInStruct                                             */
/******************************************************************************/
typedef struct GTDICloseCounterStreamInStruct
{
    GTDI_ESCAPE_FUNCTION  Function;
}
GTDICloseCounterStreamIn;

/******************************************************************************/
/* GTDICloseCounterStreamOut                                                  */
/******************************************************************************/
typedef struct GTDICloseCounterStreamOutStruct
{
    GTDI_RETURN_CODE RetCode;    // Result of the call
}
GTDICloseCounterStreamOut;



/******************************************************************************/
/* GTDI_FUNC_SET_OVERRIDE_EU_CFG function structure definitions               */
/******************************************************************************/
/******************************************************************************/
/* GTDISetOverrideEUCfgIn                                                     */
/******************************************************************************/
typedef struct GTDISetOverrideEUCfgInStruct
{
    GTDI_ESCAPE_FUNCTION       Function;
    GTDI_EU_CONFIG_ENTRY_TYPE  ConfigEntryType;

    union
    {
        uint32_t ThreadCount; // Maximum number of threads spawned on single EU.
        uint32_t EUMask;      // Threads will execute on n-th core only if n-th
    };                        // bit of EUMask is 1. If there is fewer than 8
                              // cores per slice (e.g. SNB/IVB GT1), last core
                              // in each row is not available (mask 0x77 selects
                              // all available cores on single IVB/SNB GT1 slice).
                              // On SNB GT2 both ThreadCount and EUMask must have
                              // identical config on each slice - because of that
                              // last submitted configuration for any slice will
                              // be used for both slices during override enabling.


    GTDI_PIPELINE_STAGE   PipelineStage; // Which pipeline stage does EUMask affect. This is
                                         // for EU masking only.
    GTDI_PARTITION_ID     PartitionID;   // Which partition does EUMask or ThreadCount affect.
    uint32_t              Reserved;      // for backwards compatibility

} GTDISetOverrideEUCfgIn;


/******************************************************************************/
/* GTDISetOverrideEUCfgOut                                                    */
/******************************************************************************/
typedef struct GTDISetOverrideEUCfgOutStruct
{
    GTDI_RETURN_CODE    RetCode;
} GTDISetOverrideEUCfgOut;


/******************************************************************************/
/* GTDI_FNC_SET_WORKAROUNDS function structure definitions                    */
/******************************************************************************/
typedef struct GTDISetWorkaroundsInStruct
{
    GTDI_ESCAPE_FUNCTION   Function;
    bool32_t               Enable;       // Enable / disable workaround
    GTDI_WORKAROUND_ID     Id;           // Workaround id
}
GTDISetWorkaroundsIn;

typedef GTDIHeaderOut GTDISetWorkaroundsOut;

/******************************************************************************/
/* GTDIOverridesHandle:                                                       */
/******************************************************************************/
typedef struct
{
    uint32_t Low;
    uint32_t High;
    uint32_t D;
} GTDIOverridesHandle;

/******************************************************************************/
/* GTDIOverridesSupportEnableIn:                                              */
/******************************************************************************/
typedef struct
{
    GTDI_ESCAPE_FUNCTION  Function;
    bool32_t              Enable;
    GTDIOverridesHandle   Handle;
} GTDIOverridesSupportEnableIn;


/******************************************************************************/
/* GTDIOverridesSupportEnableOut:                                             */
/******************************************************************************/
typedef struct
{
    GTDI_RETURN_CODE    RetCode; // Result of the operation
} GTDIOverridesSupportEnableOut;



// Single proprietary query max counters count
#define GTDI_QUERY_METRIC_COUNT_MAX 32


//============================================================================//
//                     Shared memory part                                     //
//============================================================================//

//============================================================================//
// Configuration file structure                                               //
//============================================================================//

/******************************************************************************/
/* GTDI_CONFIG_MEMORY_FILE_HEADER_STRUCT                                      */
/******************************************************************************/
typedef struct GTDI_CONFIG_MEMORY_FILE_HEADER_STRUCT
{
    uint32_t Magic;
    uint32_t OffsetMetricEnable;    // Offset of the enable metrics flag block (in bytes)
    uint32_t MetricCount;           // Number of metrics
} GTDI_CONFIG_MEMORY_FILE_HEADER;


/******************************************************************************/
/* GTDI_CONFIG_MEMORY_FILE_STRUCT                                             */
/******************************************************************************/
typedef struct GTDI_CONFIG_MEMORY_FILE_STRUCT
{
    GTDI_CONFIG_MEMORY_FILE_HEADER    Header;
    // MetricCount * EnableFlagSize uint32_ts at OffsetMetricEnable offset
} GTDI_CONFIG_MEMORY_FILE;


//============================================================================//
// System (Metric definition) file structure                                  //
//============================================================================//

/******************************************************************************/
/* GTDI_METRIC_INFO                                                           */
/******************************************************************************/
typedef struct GTDI_METRIC_INFO_STRUCT
{
    wchar_t  URI[GTDI_URI_SIZE];           //
    wchar_t  Name[GTDI_NAME_SIZE];         //
    wchar_t  Description[GTDI_DESC_SIZE];  //
    uint32_t MetricType;                   // As defined in this header
    uint32_t CounterIndex;                 // Index
    uint64_t MaxValue;                     // Not used at this time. For future purpose.
} GTDI_METRIC_INFO;


/******************************************************************************/
/* GTDI_OVERRIDE_INFO                                                         */
/******************************************************************************/
typedef struct GTDI_OVERRIDE_INFO_STRUCT
{
    wchar_t URI[GTDI_URI_SIZE];     //
    wchar_t Name[GTDI_NAME_SIZE];   //
    wchar_t Desc[GTDI_DESC_SIZE];   //
    uint32_t Id;                    // Override id used to enable/disable it via
                                    // escape function
    bool32_t Dynamic;               // true - dynamic override
                                    // false - not dynamic
} GTDI_OVERRIDE_INFO;

/******************************************************************************/
/* GTDI_KI_BUILD_TYPE_ENUM                                                    */
/******************************************************************************/
typedef enum GTDI_KI_BUILD_TYPE_ENUM
{
    GTDI_KERNEL_REGULAR                 = 0,   //Use that value to switch off kernel build override
    GTDI_KERNEL_TRACE                   = 1,
    GTDI_KERNEL_PROFILE                 = 2,
    GTDI_KERNEL_ISA_PROFILE             = 3,
    GTDI_KERNEL_PROFILE_AGGREGATED      = 4,
    GTDI_KERNEL_ISA_PROFILE_AGGREGATED  = 5,
    GTDI_KERNEL_ISA_COUNTERS            = 6,   // internal user usage
    GTDI_KERNEL_GT_PIN_COMPILER         = 7,   // internal user usage
    GTDI_KERNEL_GPGPU_TRACE             = 8,
    GTDI_NUM_KERNEL_PROFILING_TYPES     = 9,
    // ...
    GTDI_KI_BUILD_TYPE_MAX = 0xFFFFFFFF
} GTDI_KI_BUILD_TYPE;

#define GTDI_MAX_KI_OFFSETS              26
#define GTDI_MAX_KI_AGGREGATED_OFFSETS   20
#define GTDI_MAX_KI_BUILD_CONFIGURATIONS 16

/******************************************************************************/
/* GTDI_KI_KERNEL_TYPE_MASK_ENUM                                                   */
/******************************************************************************/
typedef enum GTDI_KERNEL_TYPE_MASK_ENUM
{
    GTDI_NONE_KERNEL_PROGRAM        = 0,
    GTDI_VERTEX_KERNEL_PROGRAM      = 1 << 0,
    GTDI_GEOMETRY_KERNEL_PROGRAM    = 1 << 1,
    GTDI_PIXEL_KERNEL_PROGRAM       = 1 << 2,
    GTDI_HULL_KERNEL_PROGRAM        = 1 << 3,
    GTDI_DOMAIN_KERNEL_PROGRAM      = 1 << 4,
    GTDI_COMPUTE_KERNEL_PROGRAM     = 1 << 5,

    GTDI_ALL_KERNEL_PROGRAMS        = GTDI_VERTEX_KERNEL_PROGRAM | GTDI_PIXEL_KERNEL_PROGRAM | GTDI_GEOMETRY_KERNEL_PROGRAM |
                                      GTDI_HULL_KERNEL_PROGRAM | GTDI_DOMAIN_KERNEL_PROGRAM | GTDI_COMPUTE_KERNEL_PROGRAM,
    // ...
    GTDI_KI_KERNEL_TYPE_MASK_MAX = 0xFFFFFFFF
} GTDI_KI_KERNEL_TYPE_MASK;

/******************************************************************************/
/* GTDISetKIQueryCfgInStruct                                                  */
/******************************************************************************/
typedef struct GTDISetKIQueryCfgInStruct
{
    GTDI_ESCAPE_FUNCTION        Func;

    GTDI_KI_KERNEL_TYPE_MASK    KernelMask;
    uint32_t                    ReportCount;
    bool32_t                    GatherEUTimestampDispersion;
    GTDI_KI_BUILD_TYPE          QueryType;

} GTDISetKIQueryCfgIn;

/******************************************************************************/
/* GTDISetKIQueryCfgOutStruct                                                 */
/******************************************************************************/
typedef struct GTDISetKIQueryCfgOutStruct
{
    GTDI_RETURN_CODE RetCode; // Result of the call
} GTDISetKIQueryCfgOut;

/******************************************************************************/
/* GTDISetKIQueryCfgExInStruct                                                  */
/******************************************************************************/
typedef struct GTDISetKIQueryCfgExInStruct
{
    GTDI_ESCAPE_FUNCTION        Func;

    GTDI_KI_KERNEL_TYPE_MASK    KernelMask;
    uint32_t                    ReportCount;
    bool32_t                    GatherEUTimestampDispersion;
    GTDI_KI_BUILD_TYPE          QueryType;

    uint32_t                    VertexShaderID;
    uint32_t                    PixelShaderID;
    uint32_t                    GeometryShaderID;
    uint32_t                    HullShaderID;
    uint32_t                    DomainShaderID;
    uint32_t                    ComputeShaderID;

} GTDISetKIQueryCfgExIn;

/******************************************************************************/
/* GTDISetKIQueryCfgExOutStruct                                                 */
/******************************************************************************/
typedef struct GTDISetKIQueryCfgExOutStruct
{
    GTDI_RETURN_CODE RetCode; // Result of the call
} GTDISetKIQueryCfgExOut;

/******************************************************************************/
/* GTDI_KI_KERNEL_TYPE_MASK_ENUM                                              */
/******************************************************************************/
typedef enum GTDI_KERNEL_BUILD_FLAGS_ENUM
{
    GTDI_EU_THREAD_MASKS_SUPPORTED          = 1 << 0,
    GTDI_GPU_TIMESTAMP_READING_SUPPORTED    = 1 << 1,

    GTDI_KERNEL_BUILD_FLAGS_MAX = 0xFFFFFFFF
} GTDI_KERNEL_BUILD_FLAGS;

/******************************************************************************/
/* GTDI_KERNEL_PROFILING_POINT_TYPE_ENUM                                      */
/******************************************************************************/
typedef enum GTDI_KERNEL_PROFILING_POINT_TYPE_ENUM
{
    GTDI_PROFILING_POINT_TIMESTAMP_INTEL          =   1 << 0,
    GTDI_PROFILING_POINT_STALL_COUNTER_INTEL      =   1 << 1,
    GTDI_PROFILING_POINT_SAMPLER_MESSAGE_INTEL    =   1 << 2,
    GTDI_PROFILING_POINT_DATA_PORT_MESSAGE_INTEL  =   1 << 3,
    GTDI_PROFILING_POINT_WORKGROUP_ID_X_INTEL     =   1 << 4,
    GTDI_PROFILING_POINT_WORKGROUP_ID_Y_INTEL     =   1 << 5,
    GTDI_PROFILING_POINT_WORKGROUP_ID_Z_INTEL     =   1 << 6,
    GTDI_PROFILING_POINT_EXECUTION_MASK_INTEL     =   1 << 7,
    GTDI_PROFILING_POINT_HIT_COUNTER_INTEL        =   1 << 8
} GTDI_KERNEL_PROFILING_POINT_TYPE;

/******************************************************************************/
/* GTDISetKIBuildCfgInStruct                                               */
/******************************************************************************/
typedef struct GTDISetKIBuildCfgInStruct
{
    GTDI_ESCAPE_FUNCTION Func;

    uint32_t   InstrType;
    uint32_t   OffsetCount;
    uint32_t   Offsets[GTDI_MAX_KI_OFFSETS];
    uint32_t   Flags;
    uint32_t   PartitionCount;  // Number of partitions to use profiled kernels
    uint32_t   PartitionEUMask; // Mask of EUs in each partition to use profiled kernels
    uint32_t   ThreadCount;

} GTDISetKIBuildCfgIn;

/******************************************************************************/
/* GTDISetKIBuildCfgOutStruct                                                 */
/******************************************************************************/
typedef struct GTDISetKIBuildCfgOutStruct
{
    GTDI_RETURN_CODE RetCode; // Result of the call
} GTDISetKIBuildCfgOut;

/******************************************************************************/
/* GTDISetKIBuildCfgExInStruct                                               */
/******************************************************************************/
typedef struct GTDISetKIBuildCfgExInStruct
{
    GTDI_ESCAPE_FUNCTION Func;

    uint32_t   InstrType;
    uint32_t   OffsetCount;
    uint32_t   Offsets[GTDI_MAX_KI_OFFSETS];
    uint32_t   Flags;
    uint32_t   PartitionCount;  // Number of partitions to use profiled kernels
    uint32_t   PartitionEUMask; // Mask of EUs in each partition to use profiled kernels
    uint32_t   ThreadCount;
    uint32_t   CfgID;

} GTDISetKIBuildCfgExIn;

/******************************************************************************/
/* GTDI_KERNEL_DUMP_TYPE                                                 */
/******************************************************************************/
typedef enum GTDI_KERNEL_DUMP_TYPE_ENUM {
    GTDI_KERNEL_DUMP_IL         = 0,
    GTDI_KERNEL_DUMP_ISA        = 1,
    GTDI_KERNEL_DUMP_ISA2IL_MAP = 2,
    // ...
    GTDI_KERNEL_DUMP_MAX = 0xFFFFFFFF
}GTDI_KERNEL_DUMP_TYPE;

/******************************************************************************/
/* GTDISetKIBuildCfgExOutStruct                                                 */
/******************************************************************************/
typedef struct GTDISetKIBuildCfgExOutStruct
{
    GTDI_RETURN_CODE RetCode; // Result of the call
} GTDISetKIBuildCfgExOut;

/******************************************************************************/
/* GTDIGetKIBuildInfoInStruct                                                 */
/******************************************************************************/
typedef struct GTDIGetKIBuildInfoInStruct
{
    GTDI_ESCAPE_FUNCTION Function;
    GTDI_KI_BUILD_TYPE BuildType;
} GTDIGetKIBuildInfoIn;

/******************************************************************************/
/* GTDIGetKIBuildInfoOutStruct                                                */
/******************************************************************************/
typedef struct GTDIGetKIBuildInfoOutStruct
{
    GTDI_RETURN_CODE    RetCode; // Result of the call

    uint32_t   ReportSize;
    uint32_t   MaxOffsetCount;
    uint32_t   MaxPartitionCount;
    uint32_t   MaxEUsInPartition;
    uint32_t   MaxThreadCount;
    GTDI_KERNEL_BUILD_FLAGS             BuildFlags;
    GTDI_KERNEL_PROFILING_POINT_TYPE    ProfilingPointEnumMask;

} GTDIGetKIBuildInfoOut;

/******************************************************************************/
/* GTDISetKernelDumpTypeInStruct                                               */
/******************************************************************************/
typedef struct GTDISetKernelDumpTypeInStruct
{
    GTDI_ESCAPE_FUNCTION Func;
    GTDI_KERNEL_DUMP_TYPE KernelType;

} GTDISetKernelDumpTypeIn;

/******************************************************************************/
/* GTDISetKIBuildCfgExOutStruct                                                 */
/******************************************************************************/
typedef struct GTDISetKernelDumpTypeOutStruct
{
    GTDI_RETURN_CODE RetCode; // Result of the call
} GTDISetKernelDumpTypeOut;

/******************************************************************************/
/* GTDIGetGpuCpuTimestampsIn                                               */
/******************************************************************************/
typedef GTDIHeaderIn GTDIGetGpuCpuTimestampsIn;

/******************************************************************************/
/* GTDIGetGpuCpuTimestampsOut                                                 */
/******************************************************************************/
typedef struct GTDIGetGpuCpuTimestampsOutStruct
{
    GTDI_RETURN_CODE RetCode; // Result of the call
    uint64_t GpuPerfTicks;    // in GPU_timestamp_ticks
    uint64_t CpuPerfTicks;    // in CPU_timestamp_ticks
    uint64_t GpuPerfFreq;     // in GPU_timestamp_ticks/s
    uint64_t CpuPerfFreq;     // in CPU_timestamp_ticks/s
} GTDIGetGpuCpuTimestampsOut;

/******************************************************************************/
/* GTDIGetErrorInfoIn                                                         */
/******************************************************************************/
typedef struct GTDIGetErrorInfoInStruct
{
    GTDI_ESCAPE_FUNCTION Func;
    GTDI_RETURN_CODE     PreviousErrorCode;
} GTDIGetErrorInfoIn;

/******************************************************************************/
/* GTDIGetErrorInfoOut                                                        */
/******************************************************************************/
typedef struct GTDIGetErrorInfoOutStruct
{
    GTDI_RETURN_CODE    RetCode;  // Result of this call
    union ErrorInfo
    {
        struct
        {
            wchar_t Name[GTDI_NAME_SIZE];
        } ConcurrentAPI;

        // ...
    } Information;
} GTDIGetErrorInfoOut;

/******************************************************************************/
/* GTDI_SYSTEM_FILE_HEADER_STRUCT                                             */
/******************************************************************************/
typedef struct GTDI_SYSTEM_FILE_HEADER_STRUCT
{
    uint32_t Magic;
    uint32_t OffsetMetricInfo;     // Offset of the metrics info block (in bytes)
    uint32_t MetricCount;          // Number of metrics
    uint32_t OffsetOverrideInfo;   // Offset of the metrics info block (in bytes)
    uint32_t OverrideCount;        // Number of overrides
} GTDI_SYSTEM_FILE_HEADER;


/******************************************************************************/
/* GTDI_SYSTEM_FILE_STRUCT                                                    */
/******************************************************************************/
typedef struct GTDI_SYSTEM_FILE_STRUCT
{
    GTDI_SYSTEM_FILE_HEADER    Header;
    // MetricCount * sizeof(GTDI_METRIC_INFO) at OffsetMetricInfo offset
    // OverrideCount * sizeof(GTDI_OVERRIDE_INFO) at OffsetOverrideInfo offset
} GTDI_SYSTEM_FILE;



//============================================================================//
// Context shared memory file structure                                       //
//============================================================================//
//
//  |-------------------------------------------------------------------------|
//  |                    IGPA 2.0 STAT FILE                                   |
//  |-----------------------|-------------------------------------------------|
//  |   IGPA 2.0 HEADER     |      IGPA 1.5 .stat file structure              |
//  |-----------------------|-------------------------------------------------|

/******************************************************************************/
/* GTDI_STAT_FILE_HEADER_STRUCT                                               */
/******************************************************************************/
typedef struct GTDI_STAT_FILE_HEADER_STRUCT
{
    uint64_t Magic;
    uint32_t OffsetMetricCounters;    // Offset of the counters block (in bytes from
                                      // the beginning of file)
} GTDI_STAT_FILE_HEADER;

#endif // __GTDI_DRIVER_INTERFACE_H_
