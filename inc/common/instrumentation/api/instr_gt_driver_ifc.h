/*========================== begin_copyright_notice ============================

Copyright (C) 2019-2023 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  instr_gt_driver_ifc.h

// Interface for communication between driver and GPA 2.2

#ifndef __GTDI_DRIVER_INTERFACE_H_
#define __GTDI_DRIVER_INTERFACE_H_

/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/* Interface version:                                                         */
/******************************************************************************/
#define GTDI_MAKE_IFC_VER( major, minor ) ( ( ( major ) << 8 ) | ( minor ) )
#define GTDI_GET_MAJOR_IFC_VER( ver )     ( ver >> 8 )
#define GTDI_GET_MINOR_IFC_VER( ver )     ( ver & 0xFF )

/******************************************************************************/
/* Escapecodes:                                                               */
/******************************************************************************/
#define GTDI_ESCAPE_CODE_XP    0x00504349
#define GTDI_ESCAPE_CODE_VISTA 12

/******************************************************************************/
/* Shared memory magic:                                                       */
/******************************************************************************/
#define GTDI_MEMORY_MAGIC 0x12344321

/******************************************************************************/
/* Maximum string length:                                                     */
/******************************************************************************/
#define GTDI_PATH_LENGTH 1024

/******************************************************************************/
/* Maximum array length:                                                      */
/******************************************************************************/
#define GTDI_BYTE_ARRAY_LENGTH 2048

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
#define METRIC_TYPE_NUMBER           0x00000000 // winperf PERF_TYPE_NUMBER
#define METRIC_TYPE_SIZE_LARGE       0x00000100 // winperf PERF_SIZE_LARGE
#define METRIC_TYPE_COUNTER          0x00000400 // winperf PERF_TYPE_COUNTER
#define METRIC_TYPE_COUNTER_RATE     0x00010000 // winperf PERF_COUNTER_RATE
#define METRIC_TYPE_COUNTER_FRACTION 0x00020000 // winperf PERF_COUNTER_FRACTION
#define METRIC_TYPE_DELTA_COUNTER    0x00400000 // winperf PERF_DELTA_COUNTER

/******************************************************************************/
/* Display types:                                                             */
/******************************************************************************/
#define METRIC_TYPE_DISPLAY_PER_SEC 0x10000000 // winperf PERF_DISPLAY_PER_SEC
#define METRIC_TYPE_DISPLAY_PERCENT 0x20000000 // winperf PERF_DISPLAY_PERCENT
#define METRIC_TYPE_DISPLAY_SECONDS 0x30000000 // winperf PERF_DISPLAY_SECONDS
#define METRIC_TYPE_DISPLAY_KBS     0x50000000 // added - not present in winperf

/******************************************************************************/
/* GTDI_MAX_PM_REGS:                                                          */
/******************************************************************************/
#define GTDI_MAX_PM_REGS 4096

/******************************************************************************/
/* GTDI_MAX_PM_REGS_3_36 that is used in old drivers such as 3.36 or earlier  */
/* versions (may also be used for config size optimization)                   */
/******************************************************************************/
#define GTDI_MAX_PM_REGS_3_36 256

/******************************************************************************/
/* GTDI_MAX_PM_REGS_3_13 that is used in old drivers such as 3.13 or earlier  */
/* versions                                                                   */
/******************************************************************************/
#define GTDI_MAX_PM_REGS_3_13 128

/******************************************************************************/
/* GTDI_MAX_READ_REGS:                                                        */
/******************************************************************************/
#define GTDI_MAX_READ_REGS 16

/******************************************************************************/
/* GTDI_CAPABILITY:                                                           */
/******************************************************************************/
#define GTDI_CAPABILITY_MMIO_BROKEN                      0x0001
#define GTDI_CAPABILITY_VAR_RC                           0x0002 // TBD: propose better name
#define GTDI_CAPABILITY_ME_SM_LOCK                       0x0004
#define GTDI_CAPABILITY_MIN_MAX_FREQ_REPORTING           0x0008
#define GTDI_CAPABILITY_PAVP_DISABLED                    0x0010
#define GTDI_CAPABILITY_SLICE_SHUTDOWN                   0x0020
#define GTDI_CAPABILITY_STREAM_EXCEPTION_FLAGS_REPORTING 0x0040
#define GTDI_CAPABILITY_INTERNAL_DRV                     0x0080

/******************************************************************************/
/* GTDI_NUM_CHAP_REGISTERS                                                    */
/******************************************************************************/
#define GTDI_NUM_CHAP_REGISTERS 8

/******************************************************************************/
/* MMIO registers                                                             */
/******************************************************************************/
#define GTDI_NUM_MMIO_REGISTERS_GEN_CTGELK 9
#define GTDI_NUM_MMIO_REGISTERS_GEN_ILK    9

/******************************************************************************/
/* Single proprietary query max counters count (obsolete)                     */
/******************************************************************************/
#define GTDI_QUERY_METRIC_COUNT_MAX 32

/******************************************************************************/
/* Macro to set pointer in GTDIPointer structure.                             */
/******************************************************************************/
#define GTDI_SET_POINTER( GTDIPtr, val ) \
    ( GTDIPtr ).UmBufferOffset64 = 0;    \
    ( GTDIPtr ).Pointer          = val;

/******************************************************************************/
/* Macros related to KI API.                                                  */
/******************************************************************************/
#define GTDI_MAX_KI_OFFSETS              26
#define GTDI_MAX_KI_AGGREGATED_OFFSETS   20
#define GTDI_MAX_KI_BUILD_CONFIGURATIONS 16

/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
/* ENUMS                                                                      */
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/* Interface version:                                                         */
/******************************************************************************/
typedef enum
{
    GTDI_IFC_VERSION_2         = 0x00,
    GTDI_IFC_VERSION_3         = 0x03,
    GTDI_IFC_VERSION_MAJOR_MAX = 0xFFFFFFFF
} GTDI_IFC_VERSION_MAJOR;

typedef enum
{
    GTDI_IFC_VERSION_2_0     = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_2, 1 ),
    GTDI_IFC_VERSION_2_1     = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_2, 2 ),
    GTDI_IFC_VERSION_2_2     = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_2, 3 ),
    GTDI_IFC_VERSION_3_0     = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 0 ),
    GTDI_IFC_VERSION_3_1     = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 1 ),
    GTDI_IFC_VERSION_3_2     = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 2 ),
    GTDI_IFC_VERSION_3_3     = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 3 ),
    GTDI_IFC_VERSION_3_4     = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 4 ),
    GTDI_IFC_VERSION_3_5     = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 5 ),
    GTDI_IFC_VERSION_3_6     = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 6 ),
    GTDI_IFC_VERSION_3_7     = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 7 ),
    GTDI_IFC_VERSION_3_8     = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 8 ),
    GTDI_IFC_VERSION_3_9     = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 9 ),
    GTDI_IFC_VERSION_3_10    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 10 ),
    GTDI_IFC_VERSION_3_11    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 11 ),
    GTDI_IFC_VERSION_3_12    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 12 ),
    GTDI_IFC_VERSION_3_13    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 13 ),
    GTDI_IFC_VERSION_3_14    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 14 ),
    GTDI_IFC_VERSION_3_15    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 15 ), // VLV: clock counter on B3
    GTDI_IFC_VERSION_3_16    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 16 ), // VLV: PerfMon memory metrics
    GTDI_IFC_VERSION_3_17    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 17 ), // OCL: PerfCounters unification
    GTDI_IFC_VERSION_3_18    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 18 ), // BDW: Query overrides support
    GTDI_IFC_VERSION_3_19    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 19 ), // Core clock override
    GTDI_IFC_VERSION_3_20    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 20 ), // HW perf counters report layout fix (IVB/HSW)
    GTDI_IFC_VERSION_3_21    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 21 ), // New device params: OA buffer sizes, GPU timestamp freq
    GTDI_IFC_VERSION_3_22    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 22 ), // Registers dump feature (internal drivers only)
    GTDI_IFC_VERSION_3_23    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 23 ), // SKL/BXT/CNL base support
    GTDI_IFC_VERSION_3_24    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 24 ), // HSW NOA static cfg update
    GTDI_IFC_VERSION_3_25    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 25 ), // Internal capability flag
    GTDI_IFC_VERSION_3_26    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 26 ), // ValidatePmRegsCfg escape
    GTDI_IFC_VERSION_3_27    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 27 ), // ForceWake device param has been added (set operation only)
    GTDI_IFC_VERSION_3_28    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 28 ), // Cull at BC & PSD for Gen7_5+
    GTDI_IFC_VERSION_3_29    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 29 ), // Support for permanent override
    GTDI_IFC_VERSION_3_30    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 30 ), // Support for next 7 throttling overrides
    GTDI_IFC_VERSION_3_31    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 31 ), // Slice/Unslice frequencies in SKL+ perf counters queries
    GTDI_IFC_VERSION_3_32    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 32 ), // Selective force wake override
    GTDI_IFC_VERSION_3_33    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 33 ), // DMA sampling
    GTDI_IFC_VERSION_3_34    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 34 ), // Mid query events info
    GTDI_IFC_VERSION_3_35    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 35 ), // Byte array added to GTDI_DEVICE_PARAM_VALUE_TYPE
    GTDI_IFC_VERSION_3_36    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 36 ), // New exception flags added to GTDI_FNC_READ_COUNTER_STREAM
    GTDI_IFC_VERSION_3_37    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 37 ), // GTDISetPmRegsCfgExtIn added with bigger register capacity
    GTDI_IFC_VERSION_3_38    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 38 ), // GTDI_FNC_GET_OVERRIDES_INFO has been added, the shared files API withdrawing
    GTDI_IFC_VERSION_3_39    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 39 ), // Improved overrides protection
    GTDI_IFC_VERSION_3_40    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 40 ), // GTDI_DEVICE_PARAM_OA_BUFFER_ACTIVE
    GTDI_IFC_VERSION_3_41    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 41 ), // Stream-related API improvement
    GTDI_IFC_VERSION_3_42    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 42 ), // Maximums which bound all supported GT
    GTDI_IFC_VERSION_3_43    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 43 ), // Separate clocks for OA and CS timestamps
    GTDI_IFC_VERSION_3_44    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 44 ), // Total system and video memory
    GTDI_IFC_VERSION_3_45    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 45 ), // New error code has been introduced
    GTDI_IFC_VERSION_3_46    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 46 ), // GTDIGetGpuCpuTimestampsExtOut added with timestamp correlation indicator
    GTDI_IFC_VERSION_3_47    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 47 ), // MTL base support
    GTDI_IFC_VERSION_3_48    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 48 ),
    GTDI_IFC_VERSION_3_49    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 49 ), // Samedia support
    GTDI_IFC_VERSION_3_50    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 50 ), // New device parameters related to OA buffer
    GTDI_IFC_VERSION_3_51    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 51 ), // Removal of support of some IOstream read exceptions
    GTDI_IFC_VERSION_3_52    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 52 ), // New escapes: GTDI_FNC_SET_PM_REGS_CFG_BY_TYPE & GTDI_FNC_TIMER_MODE_ENABLE_BY_TYPE
    GTDI_IFC_VERSION_3_53    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 53 ), // New device params: L3 Bank, L3 Node and Sqidi count
    GTDI_IFC_VERSION_3_54    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 54 ), // Deprecated DMA sampling
    GTDI_IFC_VERSION_3_55    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 55 ), // New device param: Platform Version
    GTDI_IFC_VERSION_3_56    = GTDI_MAKE_IFC_VER( GTDI_IFC_VERSION_3, 56 ), // New device params: compute and copy engines count
    GTDI_IFC_VERSION_CURRENT = GTDI_IFC_VERSION_3_56,
    GTDI_IFC_VERSION_MAX     = 0xFFFFFFFF
} GTDI_IFC_VERSION;

/******************************************************************************/
/* GTDI_KI_KERNEL_TYPE_MASK_ENUM                                              */
/******************************************************************************/
typedef enum GTDI_KERNEL_TYPE_MASK_ENUM
{
    GTDI_NONE_KERNEL_PROGRAM     = 0,
    GTDI_VERTEX_KERNEL_PROGRAM   = 1 << 0,
    GTDI_GEOMETRY_KERNEL_PROGRAM = 1 << 1,
    GTDI_PIXEL_KERNEL_PROGRAM    = 1 << 2,
    GTDI_HULL_KERNEL_PROGRAM     = 1 << 3,
    GTDI_DOMAIN_KERNEL_PROGRAM   = 1 << 4,
    GTDI_COMPUTE_KERNEL_PROGRAM  = 1 << 5,
    GTDI_ALL_KERNEL_PROGRAMS     = GTDI_VERTEX_KERNEL_PROGRAM | GTDI_PIXEL_KERNEL_PROGRAM | GTDI_GEOMETRY_KERNEL_PROGRAM | GTDI_HULL_KERNEL_PROGRAM | GTDI_DOMAIN_KERNEL_PROGRAM | GTDI_COMPUTE_KERNEL_PROGRAM,
    GTDI_KI_KERNEL_TYPE_MASK_MAX = 0xFFFFFFFF
} GTDI_KI_KERNEL_TYPE_MASK;

/******************************************************************************/
/* GTDI_KERNEL_BUILD_FLAGS_ENUM                                               */
/******************************************************************************/
typedef enum GTDI_KERNEL_BUILD_FLAGS_ENUM
{
    GTDI_EU_THREAD_MASKS_SUPPORTED       = 1 << 0,
    GTDI_GPU_TIMESTAMP_READING_SUPPORTED = 1 << 1,
    GTDI_KERNEL_BUILD_FLAGS_MAX          = 0xFFFFFFFF
} GTDI_KERNEL_BUILD_FLAGS;

/******************************************************************************/
/* GTDI_KERNEL_PROFILING_POINT_TYPE_ENUM                                      */
/******************************************************************************/
typedef enum GTDI_KERNEL_PROFILING_POINT_TYPE_ENUM
{
    GTDI_PROFILING_POINT_TIMESTAMP_INTEL         = 1 << 0,
    GTDI_PROFILING_POINT_STALL_COUNTER_INTEL     = 1 << 1,
    GTDI_PROFILING_POINT_SAMPLER_MESSAGE_INTEL   = 1 << 2,
    GTDI_PROFILING_POINT_DATA_PORT_MESSAGE_INTEL = 1 << 3,
    GTDI_PROFILING_POINT_WORKGROUP_ID_X_INTEL    = 1 << 4,
    GTDI_PROFILING_POINT_WORKGROUP_ID_Y_INTEL    = 1 << 5,
    GTDI_PROFILING_POINT_WORKGROUP_ID_Z_INTEL    = 1 << 6,
    GTDI_PROFILING_POINT_EXECUTION_MASK_INTEL    = 1 << 7,
    GTDI_PROFILING_POINT_HIT_COUNTER_INTEL       = 1 << 8
} GTDI_KERNEL_PROFILING_POINT_TYPE;

/******************************************************************************/
/* GTDI_KERNEL_DUMP_TYPE_ENUM                                                 */
/******************************************************************************/
typedef enum GTDI_KERNEL_DUMP_TYPE_ENUM
{
    GTDI_KERNEL_DUMP_IL         = 0,
    GTDI_KERNEL_DUMP_ISA        = 1,
    GTDI_KERNEL_DUMP_ISA2IL_MAP = 2,
    GTDI_KERNEL_DUMP_MAX        = 0xFFFFFFFF
} GTDI_KERNEL_DUMP_TYPE;

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
    GTDI_RET_NO_INFORMATION, // for GTDI_FNC_GET_ERROR_INFO escape only
    GTDI_RET_INVALID_PARAMETER,
    GTDI_RET_HW_FAILURE,
    GTDI_RET_ACCESS_DENIED, // designed to control access to OA
    GTDI_RET_MAX = 0xFFFFFFFF
} GTDI_RETURN_CODE;

/******************************************************************************/
/* Escape commands/functions:                                                 */
/******************************************************************************/
typedef enum GTDI_ESCAPE_FUNCTION_ENUM
{
    // All GenX architectures
    GTDI_FNC_DEVICE_INFO                  = 0,  // Get device information
    GTDI_FNC_IGPA_SUPPORT_ENABLE          = 1,  // Initialize drv instrumentation
    GTDI_FNC_HW_METRICS_ENABLE            = 2,  // Initialize HW metrics support
    GTDI_FNC_CONNECT                      = 3,  // Connect
    GTDI_FNC_DISCONNECT                   = 4,  // Disconnect
    GTDI_FNC_GET_HW_METRIC_SAMPLE         = 5,  // Get HW metrics sample (with optional CHAP reconfiguration) - OBSOLETE FROM GEN6!!!
    GTDI_FNC_SET_CHAP_CFG                 = 6,  // Set CHAP configuration - OBSOLETE FROM GEN6!!!
    GTDI_FNC_SET_OVERRIDE_CFG             = 7,  // Enable/disable a particular override
    GTDI_FNC_DEVICE_INFO_EXT              = 8,  // Get extended device information. Processing may take up to 0.5s.
    GTDI_FNC_GET_HW_METRIC_SAMPLE_EXT     = 9,  // Get HW metrics sample (with optional CHAP reconfiguration) - OBSOLETE FROM GEN6!!!
    GTDI_FNC_OVERRIDES_SUPPORT_ENABLE     = 10, // Request Null HW override support for selected context
    GTDI_FNC_OPEN_COUNTER_STREAM          = 11, // Open UM application stream for reading from (active) OA buffer
    GTDI_FNC_CLOSE_COUNTER_STREAM         = 12, // Close UM application stream for reading from (active) OA buffer
    GTDI_FNC_SET_PM_REGS_CFG              = 13, // Set registers for dynamic configuration
    GTDI_FNC_GET_EU_CORES_INFO            = 14, // GET EU specific information
    GTDI_FNC_TIMER_MODE_ENABLE            = 15, // Turn timer mode on. Must be called with HardwareAccess flag set to 1.
    GTDI_FNC_EVENT_MODE_ENABLE            = 16, // obsolete - no longer supported
    GTDI_FNC_READ_COUNTER_STREAM          = 17, // Request asynchronous read from (active) OA buffer providing UM application buffer to copy data to.
    GTDI_FNC_SET_KI_QUERY_CFG             = 18, // obsolete - no longer supported
    GTDI_FNC_SET_KI_BUILD_CFG             = 19, // obsolete - no longer supported
    GTDI_FNC_SET_OVERRIDE_EU_CFG          = 20, // Overridden limit of threads(per EU) and EU cores used by thread dispatcher.
    GTDI_FNC_SET_WORKAROUNDS              = 21, // Gen7+ Workarounds settings escape
    GTDI_FNC_SET_KI_QUERY_CFG_EX          = 22, // obsolete - no longer supported
    GTDI_FNC_SET_KI_BUILD_CFG_EX          = 23, // obsolete - no longer supported
    GTDI_FNC_SET_KERNEL_DUMP_TYPE         = 24, // obsolete - no longer supported
    GTDI_FNC_GET_GPU_CPU_TIMESTAMPS       = 25, // Dedicated function for retrieving GPU and CPU timestamps at the same moment
    GTDI_FNC_GET_KI_BUILD_INFO            = 26, // obsolete - no longer supported
    GTDI_FNC_GET_ERROR_INFO               = 27, // extended error information
    GTDI_FNC_DEVICE_INFO_PARAM            = 28,
    GTDI_FNC_SET_DEVICE_PARAM             = 29,
    GTDI_FNC_READ_REGS_CFG                = 30, // Get current values from specified registers
    GTDI_FNC_GET_CTX_ID_TAGS              = 31, // NOT AVAILABLE (removed)
    GTDI_FNC_VALIDATE_PM_REGS_CFG         = 32, // NOT AVAILABLE (removed)
    GTDI_FNC_DMA_MODE_ENABLE              = 33, // obsolete - no longer supported
    GTDI_FNC_GET_OVERRIDES_INFO           = 34, // Allows to get the overrides list
    GTDI_FNC_OPEN_COUNTER_STREAM_BY_TYPE  = 35, // Open UM application stream for reading from OA buffer (identified by its type)
    GTDI_FNC_CLOSE_COUNTER_STREAM_BY_TYPE = 36, // Close UM application stream for reading from OA buffer (identified by its type)
    GTDI_FNC_READ_COUNTER_STREAM_BY_TYPE  = 37, // Request asynchronous read from OA buffer (identified by its type) providing UM application buffer to copy data to.
    GTDI_FNC_SET_PM_REGS_CFG_BY_TYPE      = 38, // Set registers for dynamic configuration to given OA buffer (identified by its type).
    GTDI_FNC_TIMER_MODE_ENABLE_BY_TYPE    = 39, // Enable timer mode in the given OA buffer (identified by its type)
    GTDI_FNC_MAX                          = 0xFFFFFFFF
} GTDI_ESCAPE_FUNCTION;

/******************************************************************************/
/* EU Configuration entry type:                                               */
/******************************************************************************/
typedef enum
{
    GTDI_EU_CONFIG_THREADS_PER_EU = 0,
    GTDI_EU_CONFIG_EXECUTION_MASK,
    GTDI_EU_CONFIG_MAX = 0xFFFFFFFF
} GTDI_EU_CONFIG_ENTRY_TYPE;

/******************************************************************************/
/* Pipeline stages (used in EU configuration):                                */
/******************************************************************************/
typedef enum
{
    GTDI_VF_VS = 0,
    GTDI_HS, // IVB+ only
    GTDI_DS, // IVB+ only
    GTDI_GS,
    GTDI_WIZ,
    GTDI_TS,
    GTDI_CPS, // CNL+ only -> TODO: to be verified...
    GTDI_MAX_PIPELINE_STAGES,
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
    GTDI_PARTITION_MAX = 0xFFFFFFFF
} GTDI_PARTITION_ID;

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
    GTDI_CONFIGURATION_SET_MAX = 0xFFFFFFFF
} GTDI_CONFIGURATION_SET;

/******************************************************************************/
/* Enumeration to choose high or low resolution sampling type                 */
/******************************************************************************/
typedef enum GTDI_SAMPLING_TYPE_ENUM
{
    GTDI_QUERY_MULTI_SAMPLES_TYPE = 0,
    GTDI_IOSTREAM_TYPE,
    GTDI_QUERY_EXTENDED_TYPE,
    GTDI_SAMPLING_TYPE_MAX = 0xFFFFFFFF
} GTDI_SAMPLING_TYPE;

/******************************************************************************/
/* Enumeration to choose large or small report size.                          */
/******************************************************************************/
typedef enum GTDI_REPORT_TYPE_ENUM
{
    GTDI_REPORT_TYPE_OA_SHIFT  = 0,          // 2 ^ 0 - render & dma related report types start from this value
    GTDI_REPORT_TYPE_OAM_SHIFT = 8,          // 2 ^ 8 - media related report types start from this value
    GTDI_REPORT_TYPE_OAC_SHIFT = 12,         // 2 ^ 12 - compute related report types start from this value
    GTDI_REPORT_TYPE_OA_MASK   = 0x000000FF, // render & dma related report types range
    GTDI_REPORT_TYPE_OAM_MASK  = 0x00000F00, // media related report types range
    GTDI_REPORT_TYPE_OAC_MASK  = 0x0000F000, // compute related report types range

    // 3D (OA/OAG) report types
    GTDI_REPORT_TYPE_128B_A13_NOA16 = 0 << GTDI_REPORT_TYPE_OA_SHIFT, //
    GTDI_REPORT_TYPE_192B_A29_NOA16 = 1 << GTDI_REPORT_TYPE_OA_SHIFT, //
    GTDI_REPORT_TYPE_256B_A45_NOA16 = 2 << GTDI_REPORT_TYPE_OA_SHIFT,
    GTDI_REPORT_TYPE_64B_A13        = 3 << GTDI_REPORT_TYPE_OA_SHIFT, //
    GTDI_REPORT_TYPE_128B_A29       = 4 << GTDI_REPORT_TYPE_OA_SHIFT, //
    GTDI_REPORT_TYPE_64B_NOA12      = 5 << GTDI_REPORT_TYPE_OA_SHIFT, //
    GTDI_REPORT_TYPE_128B_A16_NOA12 = 6 << GTDI_REPORT_TYPE_OA_SHIFT, //
    GTDI_REPORT_TYPE_64B_NOA12_2    = 7 << GTDI_REPORT_TYPE_OA_SHIFT, //
    // DMA sampling only
    GTDI_REPORT_TYPE_FULL      = 100 << GTDI_REPORT_TYPE_OA_SHIFT, // all counters
    GTDI_REPORT_TYPE_TIMESTAMP = 101 << GTDI_REPORT_TYPE_OA_SHIFT, // timestamp only
    GTDI_REPORT_TYPE_PERFMONS  = 102 << GTDI_REPORT_TYPE_OA_SHIFT, // 2 QWORD perfmon counters only
    GTDI_REPORT_TYPE_MC        = 103 << GTDI_REPORT_TYPE_OA_SHIFT, // memory counters only
    GTDI_REPORT_TYPE_USER      = 104 << GTDI_REPORT_TYPE_OA_SHIFT, // 16 user defined uint32_t counters only
    // media (OAM) report types
    GTDI_REPORT_TYPE_128B_OAM = 1 << GTDI_REPORT_TYPE_OAM_SHIFT,

    GTDI_REPORT_TYPE_MAX = 0xFFFFFFFF,
} GTDI_REPORT_TYPE;

/******************************************************************************/
/* GTDI_REGISTER_CONFIG_TYPE                                                  */
/******************************************************************************/
typedef enum GTDI_REGISTER_CONFIG_TYPE_ENUM
{
    CFG_TYPE_EVENT = 0,
    CFG_TYPE_NOA,
    CFG_TYPE_CHAP,
    CFG_TYPE_MAX = 0xFFFFFFFF
} GTDI_REGISTER_CONFIG_TYPE;

/******************************************************************************/
/* MMIO_REGISTER_INDEX                                                        */
/******************************************************************************/
typedef enum
{
    IA_VERTICES_COUNT = 0,
    IA_PRIMITIVES_COUNT,
    VS_INVOCATION_COUNT,
    GS_INVOCATION_COUNT,
    GS_PRIMITIVES_COUNT,
    CL_INVOCATION_COUNT,
    CL_PRIMITIVES_COUNT,
    PS_INVOCATION_COUNT,
    PS_DEPTH_COUNT,
    MMIO_REGISTER_INDEX_MAX = 0xFFFFFFFF
} MMIO_REGISTER_INDEX;

/******************************************************************************/
/* GTDI_PLATFORM_INDEX                                                        */
/******************************************************************************/
typedef enum
{
    // 0-4 reserved
    GENERATION_HSW      = 5,
    GENERATION_BDW,
    GENERATION_SKL,
    // 8-9 reserved
    GENERATION_BXT      = 10,
    // 11 reserved
    GENERATION_KBL      = 12,
    GENERATION_GLK      = 13,
    GENERATION_ICL      = 14,
    // 15-16 reserved
    GENERATION_TGL      = 17,
    GENERATION_CFL      = 18,
    GENERATION_EHL      = 19,
    // 20 reserved
    GENERATION_DG1      = 21,
    GENERATION_XEHP_SDV = 22,
    GENERATION_RKL      = 23,
    GENERATION_ACM      = 24,
    GENERATION_PVC      = 25,
    GENERATION_ADLP     = 26,
    GENERATION_MTL      = 27,
    // 28 reserved
    GENERATION_ADLS     = 29,
    GENERATION_ADLN     = 30,
    // ...
    // DO NOT CHANGE ORDER OF THIS ENUM, ADD NEW PLATFORMS AT THE END!
    // It has to be synchronized with metric_discovery_internal_api.h file.
    GTDI_PLATFORM_MAX = 0xFFFFFFF
} GTDI_PLATFORM_INDEX;

/******************************************************************************/
/* GTDI_WORKAROUND_ID                                                         */
/******************************************************************************/
typedef enum
{
    GTDI_IVB_COUNTERS_FREEZE_ON_REPORTING_OFF, // IVB C0+
    GTDI_WA_ENABLE_IA_FREQUENCY_LIMITER,
    GTDI_HSW_ENABLE_SLICE_SHUTDOWN,
    GTDI_WORKAROUND_ID_MAX = 0xFFFFFFFF
} GTDI_WORKAROUND_ID;

/******************************************************************************/
/* GTDI_DEVICE_PARAM:                                                         */
/******************************************************************************/
typedef enum GTDI_DEVICE_PARAM_ENUM
{
    GTDI_DEVICE_PARAM_INTERFACE_VERSION                  = 0,
    GTDI_DEVICE_PARAM_PCI_DEVICE_ID                      = 1,
    GTDI_DEVICE_PARAM_REVISION_ID                        = 2,
    GTDI_DEVICE_PARAM_DISPLAY_FREQUENCY                  = 3,
    GTDI_DEVICE_PARAM_GPU_CORE_MIN_FREQUENCY             = 4,
    GTDI_DEVICE_PARAM_GPU_CORE_MAX_FREQUENCY             = 5,
    GTDI_DEVICE_PARAM_GPU_CORE_FREQUENCY                 = 6,
    GTDI_DEVICE_PARAM_DRAM_FREQUENCY                     = 7,
    GTDI_DEVICE_PARAM_DRAM_PEAK_THROUGHTPUT              = 8,
    GTDI_DEVICE_PARAM_DRAM_MIN_STOLEN_VIDEO_MEMORY       = 9,
    GTDI_DEVICE_PARAM_DRAM_CURRENT_VIDEO_MEMORY          = 10,
    GTDI_DEVICE_PARAM_APERTURE_SIZE                      = 11,
    GTDI_DEVICE_PARAM_PLATFORM_INDEX                     = 12,
    GTDI_DEVICE_PARAM_CAPABILITIES                       = 13,
    GTDI_DEVICE_PARAM_EU_THREADS_COUNT                   = 14,
    GTDI_DEVICE_PARAM_EU_CORES_TOTAL_COUNT               = 15,
    GTDI_DEVICE_PARAM_EU_CORES_PER_SLICE_COUNT           = 16,
    GTDI_DEVICE_PARAM_EU_CORES_PER_SUBSLICE_COUNT        = 17,
    GTDI_DEVICE_PARAM_EU_CORES_PER_SUBSLICE_MASK         = 18,
    GTDI_DEVICE_PARAM_SLICES_COUNT                       = 19,
    GTDI_DEVICE_PARAM_SLICES_MASK                        = 20,
    GTDI_DEVICE_PARAM_SUBSLICES_TOTAL_COUNT              = 21,
    GTDI_DEVICE_PARAM_SUBSLICES_PER_SLICE_COUNT          = 22,
    GTDI_DEVICE_PARAM_SUBSLICES_MASK                     = 23,
    GTDI_DEVICE_PARAM_SAMPLERS_COUNT                     = 24,
    GTDI_DEVICE_PARAM_SAMPLERS_MASK                      = 25,
    GTDI_DEVICE_PARAM_EU_PARTITIONS_COUNT                = 26, // Partition is an abstraction for EU container with max 32 EUs
    GTDI_DEVICE_PARAM_EU_CORES_PER_PARTITION_COUNT       = 27,
    GTDI_DEVICE_PARAM_EU_CORES_PER_PARTITION_MASK        = 28,
    GTDI_DEVICE_PARAM_NUMBER_OF_RENDER_OUTPUT_UNITS      = 29,
    GTDI_DEVICE_PARAM_NUMBER_OF_SHADING_UNITS            = 30,
    GTDI_DEVICE_PARAM_GPU_STATIC_FREQUENCY_OVERRIDE      = 31,
    GTDI_DEVICE_PARAM_GPU_TURBO_FREQUENCY_OVERRIDE       = 32,
    GTDI_DEVICE_PARAM_GPU_TIMESTAMP_FREQUENCY            = 33, // From OA timestamp frequency domain
    GTDI_DEVICE_PARAM_OA_BUFFER_SIZE_MIN                 = 34,
    GTDI_DEVICE_PARAM_OA_BUFFER_SIZE_MAX                 = 35,
    GTDI_DEVICE_PARAM_GPU_FORCE_WAKE_OVERRIDE            = 36,
    GTDI_DEVICE_PARAM_PERFORMANCE_MODE                   = 37,
    GTDI_DEVICE_PARAM_GT_TYPE                            = 38,
    GTDI_DEVICE_PARAM_GPU_TIMESTAMP                      = 39,
    GTDI_DEVICE_PARAM_EDRAM_SIZE                         = 40,
    GTDI_DEVICE_PARAM_LLC_SIZE                           = 41,
    GTDI_DEVICE_PARAM_L3_SIZE                            = 42,
    GTDI_DEVICE_PARAM_OA_BUFFER_EDGE_TRIGGERING_OVERRIDE = 43,
    GTDI_DEVICE_PARAM_DUALSUBSLICES_TOTAL_COUNT          = 44,
    GTDI_DEVICE_PARAM_DUALSUBSLICES_MASK                 = 45,
    GTDI_DEVICE_PARAM_OA_BUFFER_ACTIVE                   = 46,
    GTDI_DEVICE_PARAM_GPU_CS_TIMESTAMP_FREQUENCY         = 47, // From CS timestamp frequency domain
    GTDI_DEVICE_PARAM_DRAM_TOTAL_VIDEO_MEMORY            = 48,
    GTDI_DEVICE_PARAM_TOTAL_SYSTEM_MEMORY                = 49,
    GTDI_DEVICE_PARAM_OS_ADAPTER_ID                      = 50, // OS dependent adapter ID
    GTDI_DEVICE_PARAM_OA_BUFFER_SIZE                     = 51,
    GTDI_DEVICE_PARAM_OA_BUFFER_TIMER_PERIOD             = 52,
    GTDI_DEVICE_PARAM_OA_BUFFERS_COUNT                   = 53,
    GTDI_DEVICE_PARAM_L3_BANK_TOTAL_COUNT                = 54,
    GTDI_DEVICE_PARAM_L3_NODE_TOTAL_COUNT                = 55,
    GTDI_DEVICE_PARAM_SQIDI_TOTAL_COUNT                  = 56,
    GTDI_DEVICE_PARAM_PLATFORM_VERSION                   = 57,
    GTDI_DEVICE_PARAM_COMPUTE_ENGINE_TOTAL_COUNT         = 58,
    GTDI_DEVICE_PARAM_COPY_ENGINE_TOTAL_COUNT            = 59,

    // Maximums which bound all supported GT. The values will change as needed with new GT.
    // These params are intended for internal use only.
    GTDI_DEVICE_PARAM_MAX_SLICE                  = 1000,
    GTDI_DEVICE_PARAM_MAX_SUBSLICE_PER_SLICE     = 1001,
    GTDI_DEVICE_PARAM_MAX_SUBSLICE_PER_DSS       = 1002,
    GTDI_DEVICE_PARAM_MAX_DUALSUBSLICE_PER_SLICE = 1003,

    GTDI_DEVICE_PARAM_MAX = 0xFFFFFFFF
} GTDI_DEVICE_PARAM;

/******************************************************************************/
/* GTDI_GTDI_GPU_FORCE_WAKE:                                                  */
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
/* GTDI_OA_BUFFER_TYPE:                                                       */
/******************************************************************************/
typedef enum GTDI_OA_BUFFER_TYPE_ENUM
{
    // HW resource
    GTDI_OA_BUFFER_TYPE_DEFAULT     = 0,
    GTDI_OA_BUFFER_TYPE_OA          = GTDI_OA_BUFFER_TYPE_DEFAULT, // preGen12
    GTDI_OA_BUFFER_TYPE_OAG         = GTDI_OA_BUFFER_TYPE_DEFAULT, // Gen12+
    GTDI_OA_BUFFER_TYPE_OAM_SLICE_0 = 1,
    GTDI_OA_BUFFER_TYPE_OAM_SLICE_1 = 2,
    GTDI_OA_BUFFER_TYPE_OAM_SLICE_2 = 3,
    GTDI_OA_BUFFER_TYPE_OAM_SLICE_3 = 4,
    GTDI_OA_BUFFER_TYPE_OAM_SLICE_4 = 5,
    GTDI_OA_BUFFER_TYPE_OAM_SLICE_5 = 6,
    GTDI_OA_BUFFER_TYPE_COUNT,
    GTDI_OA_BUFFER_TYPE_ALL     = GTDI_OA_BUFFER_TYPE_COUNT,
    GTDI_OA_BUFFER_TYPE_INVALID = GTDI_OA_BUFFER_TYPE_ALL,
} GTDI_OA_BUFFER_TYPE;

/******************************************************************************/
/* GTDI_DEVICE_PARAM_VALUE_TYPE:                                              */
/******************************************************************************/
typedef enum GTDI_DEVICE_PARAM_VALUE_TYPE_ENUM
{
    GTDI_DEVICE_PARAM_VALUE_TYPE_UINT32,
    GTDI_DEVICE_PARAM_VALUE_TYPE_UINT64,
    GTDI_DEVICE_PARAM_VALUE_TYPE_FLOAT,
    GTDI_DEVICE_PARAM_VALUE_TYPE_STRING, // Write only
    GTDI_DEVICE_PARAM_VALUE_TYPE_BYTE_ARRAY,
} GTDI_DEVICE_PARAM_VALUE_TYPE;

/******************************************************************************/
/* GTDI_STALL_LEVEL:                                                          */
/* (obsolete - enum is useful for limited set of used overrides only)         */
/******************************************************************************/
typedef enum
{
    GTDI_STALL_LEVEL_NO_STALL,   // No throttling
    GTDI_STALL_LEVEL_50_PERCENT, // Stall every other cycle
    GTDI_STALL_LEVEL_33_PERCENT, // Stall every third cycle
    GTDI_STALL_LEVEL_25_PERCENT, // Stall every fourth cycle
    GTDI_STALL_LEVEL_20_PERCENT, // Stall every fifth cycle
    GTDI_STALL_LEVEL_16_PERCENT, // Stall every sixth cycle
    GTDI_STALL_LEVEL_14_PERCENT, // Stall every seventh cycle
    GTDI_STALL_LEVEL_12_PERCENT, // Stall every eight cycle
} GTDI_STALL_LEVEL;

/******************************************************************************/
/* GTDI_KI_BUILD_TYPE_ENUM                                                    */
/******************************************************************************/
typedef enum GTDI_KI_BUILD_TYPE_ENUM
{
    GTDI_KERNEL_REGULAR                = 0, // Use that value to switch off kernel build override
    GTDI_KERNEL_TRACE                  = 1,
    GTDI_KERNEL_PROFILE                = 2,
    GTDI_KERNEL_ISA_PROFILE            = 3,
    GTDI_KERNEL_PROFILE_AGGREGATED     = 4,
    GTDI_KERNEL_ISA_PROFILE_AGGREGATED = 5,
    GTDI_KERNEL_ISA_COUNTERS           = 6, // internal user usage
    GTDI_KERNEL_GT_PIN_COMPILER        = 7, // internal user usage
    GTDI_KERNEL_GPGPU_TRACE            = 8,
    GTDI_NUM_KERNEL_PROFILING_TYPES    = 9,
    GTDI_KI_BUILD_TYPE_MAX             = 0xFFFFFFFF
} GTDI_KI_BUILD_TYPE;

/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
/* STRUCTURES                                                                 */
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/* bool32_t:                                                                  */
/* 4 bytes long type to represent 32-bit boolean value                        */
/******************************************************************************/
typedef uint32_t bool32_t;

/******************************************************************************/
/* GTDIPointer - structure to store user pointer information.                 */
/******************************************************************************/
typedef union
{
    void* Pointer;             // Pointer value
                               //
    uint64_t UmBufferOffset64; // Placeholder
} GTDIPointer;

/******************************************************************************/
/* Escape headers structure definitions                                       */
/******************************************************************************/
/******************************************************************************/
/* GTDIHeaderIn:                                                              */
/******************************************************************************/
typedef struct GTDIBaseInStruct
{
    GTDI_ESCAPE_FUNCTION Function;
} GTDIHeaderIn;

/******************************************************************************/
/* GTDIHeaderOut:                                                             */
/******************************************************************************/
typedef struct GTDIBaseOutStruct
{
    GTDI_RETURN_CODE RetCode; // Result of the operation
} GTDIHeaderOut;

/******************************************************************************/
/* GTDI_FNC_DEVICE_INFO function structure definitions                        */
/******************************************************************************/
/******************************************************************************/
/* GTDIDeviceInfoIn:                                                          */
/******************************************************************************/
typedef GTDIHeaderIn GTDIDeviceInfoIn;
typedef GTDIHeaderIn GTDIDeviceInfoExtIn;

/******************************************************************************/
/* GTDIDeviceInfoOut:                                                         */
/******************************************************************************/
typedef struct GTDIDeviceInfoOutStruct
{
    GTDI_RETURN_CODE    RetCode;          // Result of the operation
    uint32_t            InterfaceVersion; // Version of the interface supported
    uint32_t            PCIDeviceID;      // The DeviceId of the current adapter
    uint32_t            RevisionID;       // Steping of the HW.
    uint32_t            DisplayFreq;      // Frequency of the Display Controller
    uint32_t            CoreFreq;         // Core Frequency
    uint32_t            SamplerFreq;      // Sampler Frequency
    uint32_t            MemoryFreq;       // Memory Frequency
    uint32_t            ApertureSize;     // Size of the Aperture.
    GTDI_PLATFORM_INDEX Platform;         // Platform type (determines the union choice)
    union
    {
        struct
        {
            uint32_t FSBFreq; // FSBFrequency - Cantiga, Eaglelake
        } GenCtgElkT;

        struct
        {
            uint32_t CSIFreq; // Ironlake
        } GenIlkT;
    };
} GTDIDeviceInfoOut;

typedef struct GTDIDeviceInfoOutExtStruct
{
    GTDI_RETURN_CODE    RetCode;          // Result of the operation
    uint32_t            InterfaceVersion; // Version of the interface supported
    uint32_t            PCIDeviceID;      // The DeviceId of the current adapter
    uint32_t            RevisionID;       // Stepping of the HW.
    uint32_t            DisplayFreq;      // Frequency of the Display Controller
    uint32_t            CoreFreq;         // Core Frequency
    uint32_t            SamplerFreq;      // Sampler Frequency
    uint32_t            MemoryFreq;       // Memory Frequency
    uint32_t            ApertureSize;     // Size of the Aperture.
    GTDI_PLATFORM_INDEX Platform;         // Platform type (determines the union choice)
    uint32_t            Capabilities;
    union
    {
        struct
        {
            uint32_t FSBFreq; // FSBFrequency - Cantiga, Eaglelake
        } GenCtgElkT;

        struct
        {
            uint64_t CSIFreq; // Ironlake
        } GenIlkT;

        struct
        {
            uint32_t MinGPUFreqMHz; // Sandy Bridge/Ivy Bridge/ Haswell minimal turbo freq in MHz
            uint32_t MaxGPUFreqMHz; // Sandy Bridge/Ivy Bridge/ Haswell maximal turbo freq in MHz
        } GenGtT;
    };
} GTDIDeviceInfoExtOut;

/******************************************************************************/
/* GTDIDeviceInfoParamIn:                                                     */
/******************************************************************************/
typedef struct GTDIDeviceInfoParamInStruct
{
    GTDI_ESCAPE_FUNCTION Function;
    GTDI_DEVICE_PARAM    Param;    // Identifies parameter to get
    uint32_t             Slice;    // slice id
    uint32_t             SubSlice; // subslice id
} GTDIDeviceInfoParamIn;

/******************************************************************************/
/* GTDIDeviceInfoParamOut:                                                    */
/******************************************************************************/
typedef struct GTDIDeviceInfoParamOutStruct
{
    GTDI_RETURN_CODE             RetCode;   // Result of the operation
    GTDI_DEVICE_PARAM_VALUE_TYPE ValueType; // Type of value passed as result
    union
    {
        uint32_t ValueUint32;

        uint64_t ValueUint64;

        float ValueFloat;
    };
} GTDIDeviceInfoParamOut;

/******************************************************************************/
/* GTDIDeviceInfoParamExtOut: structure intended for string                   */
/******************************************************************************/
typedef struct GTDIDeviceInfoParamExtOutStruct
{
    GTDI_RETURN_CODE             RetCode;   // Result of the operation
    GTDI_DEVICE_PARAM_VALUE_TYPE ValueType; // Type of value passed as result
    union
    {
        uint32_t ValueUint32;

        uint64_t ValueUint64;

        float ValueFloat;

        wchar_t ValueString[GTDI_PATH_LENGTH];

        uint8_t ValueByteArray[GTDI_BYTE_ARRAY_LENGTH];
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

        float ValueFloat;
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
    wchar_t                      ValueString[GTDI_PATH_LENGTH];
} GTDISetDeviceParamExtIn;

/******************************************************************************/
/* GTDISetDeviceParamOut:                                                    */
/******************************************************************************/
typedef GTDIHeaderOut GTDISetDeviceParamOut;

/******************************************************************************/
/* GTDI_FNC_IGPA_SUPPORT_ENABLE function structure definitions                */
/******************************************************************************/
/******************************************************************************/
/* GTDIIGPASupportEnableIn:                                                   */
/******************************************************************************/
typedef struct GTDIIGPASupportEnableInStruct
{
    GTDI_ESCAPE_FUNCTION Function;
    bool32_t             Enable;                                      // Flag: True = Enable, False = Disable
    wchar_t              SharedMemoryBaseDirectory[GTDI_PATH_LENGTH]; // The directory where shared memory files will be stored.

    // Driver need to know that value at this stage to create shared memory
    // files with configuration. Typically the value would be %TEMP% environment
    // variable.
} GTDIIGPASupportEnableIn;

/******************************************************************************/
/* GTDIIGPASupportEnableOut:                                                  */
/******************************************************************************/
typedef struct GTDIIGPASupportEnableOutStruct
{
    GTDI_RETURN_CODE RetCode;                                      // Result of the operation
    wchar_t          SystemFileName[GTDI_PATH_LENGTH];             // Name of the file which contains the metric/overrides/events definition
    wchar_t          SharedMemoryConfigFileName[GTDI_PATH_LENGTH]; // Name of the shared memory file which contains the metric/events configuration.
} GTDIIGPASupportEnableOut;

/******************************************************************************/
/* GTDI_FNC_SET_OVERRIDE_CFG function structure definitions                   */
/******************************************************************************/
/******************************************************************************/
/* GTDISetOverrideCfgIn:                                                      */
/******************************************************************************/
typedef struct GTDISetOverrideCfgInStruct
{
    GTDI_ESCAPE_FUNCTION Function;
    struct
    {
        uint32_t OverrideId : 16;    // Id of the override to configure
        uint32_t Reserved : 14;      //
        uint32_t Permanent : 1;      // 0 - override is enabled/disabled
                                     // per each command buffer separately
                                     // 1 - override state is controlled
                                     // by escape calls only -> DANGEROUS:
                                     // can lead to system  freeze if given
                                     // override is located in the global
                                     // registers
        uint32_t QueryControl : 1;   // Determines if override setting
    };                               // is for immediate execution
                                     // (value of 0) or to be applied
                                     // when override control query
                                     // begins (value of 1).
    union                            //
    {                                //
        bool32_t Enable;             // Flag: True = Enable, False = Disable
                                     //
        GTDI_STALL_LEVEL StallLevel; // OBSOLETE
                                     //
        uint32_t Value;              // Warning: most significant byte is
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
typedef GTDIHeaderOut GTDISetOverrideCfgOut;

/******************************************************************************/
/* GTDI_FNC_CONNECT function structure definitions                            */
/******************************************************************************/
/******************************************************************************/
/* GTDIConnectIn:                                                             */
/******************************************************************************/
typedef struct GTDIConnectInStruct
{
    GTDI_ESCAPE_FUNCTION Function;
    uint32_t             PID; // Process id of the application
                              // to be profiled
} GTDIConnectIn;

/******************************************************************************/
/* GTDIConnectOut:                                                            */
/******************************************************************************/
typedef struct GTDIConnectOutStruct
{
    GTDI_RETURN_CODE RetCode;                                       // Result of the call
    wchar_t          SharedMemoryContextFileName[GTDI_PATH_LENGTH]; // Name of the shared memory file used for collecting driver metrics
    uint32_t         ContextId;                                     // Driver id of the context being requested.
} GTDIConnectOut;

/******************************************************************************/
/* GTDI_FNC_DISCONNECT function structure definitions                         */
/******************************************************************************/
/******************************************************************************/
/* GTDIDisconnectIn:                                                          */
/******************************************************************************/
typedef struct GTDIDisconnectInStruct
{
    GTDI_ESCAPE_FUNCTION Function;
    uint32_t             PID; // Process id of the profiled
                              // application
} GTDIDisconnectIn;

/******************************************************************************/
/* GTDIDisconnectOut:                                                         */
/******************************************************************************/
typedef GTDIHeaderOut GTDIDisconnectOut;

/******************************************************************************/
/* GTDI_FNC_SET_PM_REGS_CFG function structures definitions                   */
/******************************************************************************/
/******************************************************************************/
/* GTDISetPmRegsCfgIn:                                                        */
/*      Warning: be careful when using, it's big and may cause stack overflow.*/
/******************************************************************************/
typedef struct GTDISetPmRegsCfgInStruct
{
    GTDI_ESCAPE_FUNCTION Function;
    uint32_t             RegOffsets[GTDI_MAX_PM_REGS]; // if offset is set to 0 the corresponding NOA value is ignored
    uint32_t             RegValues[GTDI_MAX_PM_REGS];

} GTDISetPmRegsCfgIn;

/******************************************************************************/
/* GTDI_MAX_PM_REGS_3_36 that is used in old drivers such as 3.36 or earlier  */
/* versions (may also be used for config size optimization)                   */
/******************************************************************************/
typedef struct GTDISetPmRegsCfgInStruct_3_36
{
    GTDI_ESCAPE_FUNCTION Function;
    uint32_t             RegOffsets[GTDI_MAX_PM_REGS_3_36]; // if offset is set to 0 the corresponding NOA value is ignored
    uint32_t             RegValues[GTDI_MAX_PM_REGS_3_36];

} GTDISetPmRegsCfgIn_3_36;

/*******************************************************************************/
/* GTDISetPmRegsCfgIn_3_13 that is used in old drivers such as 3.13 or earlier */
/* versions                                                                    */
/*******************************************************************************/
typedef struct GTDISetPmRegsCfgInStruct_3_13
{
    GTDI_ESCAPE_FUNCTION Function;
    uint32_t             RegOffsets[GTDI_MAX_PM_REGS_3_13]; // if offset is set to 0 the corresponding NOA value is ignored
    uint32_t             RegValues[GTDI_MAX_PM_REGS_3_13];

} GTDISetPmRegsCfgIn_3_13;

/******************************************************************************/
/* GTDISetPmRegsCfgOut:                                                       */
/******************************************************************************/
typedef GTDIHeaderOut GTDISetPmRegsCfgOut;

/******************************************************************************/
/* GTDISetPmRegsCfgByTypeIn:                                                  */
/*      Warning: be careful when using, it's big and may cause stack overflow.*/
/******************************************************************************/
typedef struct GTDISetPmRegsCfgByTypeInStruct
{
    GTDI_ESCAPE_FUNCTION Function;
    uint32_t             RegOffsets[GTDI_MAX_PM_REGS]; // if offset is set to 0 the corresponding NOA value is ignored
    uint32_t             RegValues[GTDI_MAX_PM_REGS];
    GTDI_OA_BUFFER_TYPE  OaBufferType;
} GTDISetPmRegsCfgByTypeIn;

/******************************************************************************/
/* GTDISetPmRegsCfgByTypeOut:                                                 */
/******************************************************************************/
typedef GTDISetPmRegsCfgOut GTDISetPmRegsCfgByTypeOut;

/******************************************************************************/
/* GTDI_FNC_GET_PM_REGS_CFG function structures definitions                   */
/******************************************************************************/
/******************************************************************************/
/* GTDIReadRegsCfgIn:                                                         */
/******************************************************************************/
typedef struct GTDIReadRegsCfgInStruct
{
    GTDI_ESCAPE_FUNCTION Function;
    uint32_t             RegOffsets[GTDI_MAX_READ_REGS];
    uint32_t             RegBitSizes[GTDI_MAX_READ_REGS];
} GTDIReadRegsCfgIn;

/******************************************************************************/
/* GTDIReadRegsCfgOut:                                                        */
/******************************************************************************/
typedef struct GTDIReadRegsCfgOutStruct
{
    GTDI_RETURN_CODE RetCode; // Result of the operation
    uint32_t         UserCntrCfgId;
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
    GTDI_RETURN_CODE RetCode; // Result of the call
    uint32_t         PerformanceMode;
    uint32_t         EUCount;
    uint32_t         ThreadsCount;
} GTDIGetEuCoresInfoOut;

/******************************************************************************/
/* GTDI_FNC_TIMER_MODE_ENABLE function structures definitions                 */
/******************************************************************************/

/******************************************************************************/
/* GTDITimerModeEnableIn:                                                     */
/******************************************************************************/
typedef struct GTDITimerModeEnableInStruct
{
    GTDI_ESCAPE_FUNCTION   Function;
    bool32_t               Enable;
    GTDI_SAMPLING_TYPE     SamplingType;
    GTDI_REPORT_TYPE       ReportType;      // multi report type
    uint32_t               TimerPeriod;     // proposed timer period in nanoseconds
    uint32_t               OaBufferSize;    // proposed OA buffer size
    GTDI_CONFIGURATION_SET ConfigurationId; // used only in IOSTREAM sampling type
} GTDITimerModeEnableIn;

/******************************************************************************/
/* GTDITimerModeEnableOut:                                                    */
/******************************************************************************/
typedef struct GTDITimerModeEnableOutStruct
{
    GTDI_RETURN_CODE RetCode;      // Result of the call
    uint32_t         TimerPeriod;  // Timer period in nanoseconds set in hardware (value from OAG)
    uint32_t         OaBufferSize; // OA buffer size that has been set in hardware. Used only in IOSTREAM sampling type (value from OAG)
} GTDITimerModeEnableOut;

/******************************************************************************/
/* GTDITimerModeEnableByTypeIn:                                               */
/******************************************************************************/
typedef struct GTDITimerModeEnableByTypeInStruct
{
    GTDI_ESCAPE_FUNCTION   Function;
    bool32_t               Enable;
    GTDI_SAMPLING_TYPE     SamplingType;
    GTDI_REPORT_TYPE       ReportType;      // multi report type
    uint32_t               TimerPeriod;     // proposed timer period in nanoseconds
    uint32_t               OaBufferSize;    // proposed OA buffer size
    GTDI_CONFIGURATION_SET ConfigurationId; // obsolete
    GTDI_OA_BUFFER_TYPE    OaBufferType;
} GTDITimerModeEnableByTypeIn;

/******************************************************************************/
/* GTDITimerModeEnableByTypeOut:                                              */
/******************************************************************************/
typedef GTDITimerModeEnableOut GTDITimerModeEnableByTypeOut;

/******************************************************************************/
/* GTDI_FNC_HW_METRICS_ENABLE function structure definitions                  */
/******************************************************************************/
/******************************************************************************/
/* GTDIHWMetricsEnableIn:                                                     */
/******************************************************************************/
typedef struct GTDIHWMetricsEnableInStruct
{
    GTDI_ESCAPE_FUNCTION Function;
    bool32_t             Enable; // Flag: True = Enable, False = Disable
} GTDIHWMetricsEnableIn;

/******************************************************************************/
/* GTDIHWMetricsEnableOut                                                     */
/******************************************************************************/
typedef GTDIHeaderOut GTDIHWMetricsEnableOut;

/******************************************************************************/
/* GTDI_FNC_SET_CHAP_CFG function structure definitions                       */
/******************************************************************************/
/******************************************************************************/
/* GTDIRegisterConfig                                                         */
/******************************************************************************/
typedef struct GTDIRegisterConfigStruct
{
    GTDI_REGISTER_CONFIG_TYPE Type;
    uint32_t                  Offset;
    uint32_t                  Value;
} GTDIRegisterConfig;

/******************************************************************************/
/* GTDISetHWMetricConfigurationIn                                             */
/******************************************************************************/
typedef struct GTDISetHWMetricConfigurationInStruct
{
    GTDI_ESCAPE_FUNCTION Function;
    uint32_t             RegisterCount;
    // Followed by RegisterCount number of GTDIRegisterConfig records
} GTDISetHWMetricConfigurationIn;

/******************************************************************************/
/* GTDISetHWMetricConfigurationIn                                             */
/******************************************************************************/
typedef GTDIHeaderOut GTDISetHWMetricConfigurationOut;

/******************************************************************************/
/* GTDI_FNC_GET_HW_METRIC_SAMPLE function structure definitions               */
/******************************************************************************/
/******************************************************************************/
/* GTDIGetHWMetricSampleIn                                                    */
/******************************************************************************/
typedef struct GTDIGetHWMetricSampleInStruct
{
    GTDI_ESCAPE_FUNCTION Function;
    uint32_t             RegisterCount; // If RegisterCount != 0 then new HW configuration is set
                                        // after retrieving samples.

    // Followed by RegisterCount number of GTDIRegisterConfig records
} GTDIGetHWMetricSampleIn;

typedef struct GTDIGetHWMetricSampleExtInStruct
{
    GTDI_ESCAPE_FUNCTION Function;
    uint32_t             RegisterCount; // If RegisterCount != 0 then new HW configuration is set
                                        // after retrieving samples.

    // Followed by RegisterCount number of GTDIRegisterConfig records
} GTDIGetHWMetricSampleExtIn;

/******************************************************************************/
/* GTDIGGetHWMetricsSampleOutStruct                                           */
/******************************************************************************/
typedef struct GTDIGGetHWMetricsSampleOutStruct
{
    GTDI_RETURN_CODE RetCode;   // Result of the call
    uint64_t         LatchTime; // Timestamp the sample was latched
    uint32_t         ContextId; // Retrieved contextId value for MMIO metrics
    union
    {
        struct
        {
            uint32_t ChapValues[GTDI_NUM_CHAP_REGISTERS];
            uint64_t MMIOValues[GTDI_NUM_MMIO_REGISTERS_GEN_CTGELK];
        } GenCtgElk;

        struct
        {
            uint32_t ChapValues[GTDI_NUM_CHAP_REGISTERS];
            uint64_t MMIOValues[GTDI_NUM_MMIO_REGISTERS_GEN_ILK];
        } GenIlk;
    };
} GTDIGetHWMetricsSampleOut;

typedef struct GTDIGGetHWMetricsSampleExtOutStruct
{
    GTDI_RETURN_CODE RetCode;   // Result of the call
    uint64_t         LatchTime; // Timestamp the sample was latched
    uint32_t         ContextId; // Retrieved contextId value for MMIO metrics
    union
    {
        struct
        {
            uint32_t ChapValues[GTDI_NUM_CHAP_REGISTERS];
            uint64_t MMIOValues[GTDI_NUM_MMIO_REGISTERS_GEN_CTGELK];
            uint64_t CurrentCoreFreq;
            uint32_t FreqContinuityCounter; // incremented each time render clock is changed
        } GenCtgElk;

        struct
        {
            uint32_t ChapValues[GTDI_NUM_CHAP_REGISTERS];
            uint64_t MMIOValues[GTDI_NUM_MMIO_REGISTERS_GEN_ILK];
            uint64_t CurrentCoreFreq;
            uint32_t FreqContinuityCounter; // incremented each time render clock is changed
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
    GTDI_ESCAPE_FUNCTION Function;
    uint32_t             PID;                         // Process ID of the measured app, for all apps use 0
    wchar_t              EventName[GTDI_PATH_LENGTH]; // Name of event object
                                                      // used by KMD to signal
                                                      // user when samples are
                                                      // available.
} GTDIOpenCounterStreamIn;

/******************************************************************************/
/* GTDIOpenCounterStreamOut                                                   */
/******************************************************************************/
typedef GTDIHeaderOut GTDIOpenCounterStreamOut;

/******************************************************************************/
/* GTDIOpenCounterStreamByTypeIn                                              */
/******************************************************************************/
typedef struct GTDIOpenCounterStreamByTypeInStruct
{
    GTDI_ESCAPE_FUNCTION Function;
    uint32_t             PID;                         // Process ID of the measured app, for all apps use 0
    wchar_t              EventName[GTDI_PATH_LENGTH]; // Name of event object
                                                      // used by KMD to signal
                                                      // user when samples are
                                                      // available.
    GTDI_OA_BUFFER_TYPE OaBufferType;                 //
} GTDIOpenCounterStreamByTypeIn;

/******************************************************************************/
/* GTDIOpenCounterStreamByTypeOut                                             */
/******************************************************************************/
typedef GTDIHeaderOut GTDIOpenCounterStreamByTypeOut;

/******************************************************************************/
/* GTDI_FNC_READ_COUNTER_STREAM function structure definitions                */
/******************************************************************************/
/******************************************************************************/
/* GTDIReadCounterStreamIn                                                    */
/******************************************************************************/
typedef struct GTDIReadCounterStreamInStruct
{
    GTDI_ESCAPE_FUNCTION Function;
    uint32_t             BytesToRead;     // Requested data size (in bytes)
    GTDIPointer          UmBufferPointer; // Pointer to user samples buffer (use GTDI_SET_POINTER macro)
} GTDIReadCounterStreamIn;

/******************************************************************************/
/* GTDIReadCounterStreamOut                                                   */
/******************************************************************************/
typedef struct GTDIReadCounterStreamOutStruct
{
    GTDI_RETURN_CODE RetCode; // Result of the call
    uint32_t         BytesWritten;
    bool32_t         WriteFinished;
} GTDIReadCounterStreamOut;

/******************************************************************************/
/* GTDIReadCounterStreamExceptions                                            */
/******************************************************************************/
typedef struct GTDIReadCounterStreamExceptionsStruct
{
    // Exception flags
    uint32_t FrequencyChanged : 1;        // (OBSOLETE) frequency change between first and last returned sample
    uint32_t FrequencyChangedInvalid : 1; // (OBSOLETE) Unable to report freq change due to delayed read. If this exception
                                          // occurs it will be reported until all available data is read from hardware
                                          // during current or following reads. Whether there is data outstanding
                                          // in the buffer after read is indicated by DataOutstanding flag.
    uint32_t SliceShutdown : 1;           // slice shutdown occurred
    uint32_t ReportLost : 1;              // Report lost reported by HW. This means that there were some samples lost
                                          // since last Read Stream (not between the first and the last returned sample).
    uint32_t DataOutstanding : 1;         // (OBSOLETE) Read Stream left some of the newest samples unread.
    uint32_t BufferOverflow : 1;          // This bit is set when some reports have been overwritten
    uint32_t BufferOverrun : 1;           // This means that the buffer is full (n-1 reports)
    uint32_t CountersOverflow : 1;        // This means that counters overflows occurred between two consecutive readings
    uint32_t HeadWrap : 1;
    uint32_t TailWrap : 1;
    uint32_t Reserved : 22;
} GTDIReadCounterStreamExceptions;

/******************************************************************************/
/* GTDIReadCounterStreamExtOut                                                */
/******************************************************************************/
typedef struct GTDIReadCounterStreamExtOutStruct
{
    GTDI_RETURN_CODE                RetCode; // Result of the call
    uint32_t                        BytesWritten;
    bool32_t                        WriteFinished;
    uint32_t                        Frequency; // in MHz
    GTDIReadCounterStreamExceptions Exceptions;
} GTDIReadCounterStreamExtOut;

/******************************************************************************/
/* GTDIReadCounterStreamByTypeIn                                              */
/******************************************************************************/
typedef struct GTDIReadCounterStreamByTypeInStruct
{
    GTDI_ESCAPE_FUNCTION Function;
    uint32_t             BytesToRead;     // Requested data size (in bytes)
    GTDIPointer          UmBufferPointer; // Pointer to user samples buffer (use GTDI_SET_POINTER macro)
    GTDI_OA_BUFFER_TYPE  OaBufferType;
} GTDIReadCounterStreamByTypeIn;

/******************************************************************************/
/* GTDIReadCounterStreamByTypeOut                                             */
/******************************************************************************/
typedef GTDIReadCounterStreamExtOut GTDIReadCounterStreamByTypeOut;

/******************************************************************************/
/* GTDI_FNC_CLOSE_COUNTER_STREAM function structure definitions               */
/******************************************************************************/
/******************************************************************************/
/* GTDICloseCounterStreamIn                                                   */
/******************************************************************************/
typedef GTDIHeaderIn GTDICloseCounterStreamIn;

/******************************************************************************/
/* GTDICloseCounterStreamOut                                                  */
/******************************************************************************/
typedef GTDIHeaderOut GTDICloseCounterStreamOut;

/******************************************************************************/
/* GTDICloseCounterStreamByTypeIn                                             */
/******************************************************************************/
typedef struct GTDICloseCounterStreamByTypeInStruct
{
    GTDI_ESCAPE_FUNCTION Function;
    GTDI_OA_BUFFER_TYPE  OaBufferType;
} GTDICloseCounterStreamByTypeIn;

/******************************************************************************/
/* GTDICloseCounterStreamByTypeOut                                            */
/******************************************************************************/
typedef GTDIHeaderOut GTDICloseCounterStreamByTypeOut;

/******************************************************************************/
/* GTDI_FNC_GET_OVERRIDES_INFO function structure definitions                 */
/******************************************************************************/
/******************************************************************************/
/* GTDIGetOverridesInfoIn                                                     */
/******************************************************************************/
typedef struct GTDIGetOverridesInfoInStruct
{
    GTDI_ESCAPE_FUNCTION Function;
    GTDIPointer          UmBufferPointer; // Pointer to the user buffer,
                                          // If NULL, only the data size is returned.
                                          // If not NULL, the user is expected to provide
                                          // enough memory to get all the information
                                          // in a single call.
} GTDIGetOverridesInfoIn;

/******************************************************************************/
/* GTDIGetOverridesInfoOut                                                    */
/******************************************************************************/
typedef struct GTDIGetOverridesInfoOutStruct
{
    GTDI_RETURN_CODE RetCode; // Result of the call
    uint32_t         DataSize;
} GTDIGetOverridesInfoOut;

/******************************************************************************/
/* GTDI_FUNC_SET_OVERRIDE_EU_CFG function structure definitions               */
/******************************************************************************/
/******************************************************************************/
/* GTDISetOverrideEUCfgIn                                                     */
/******************************************************************************/
typedef struct GTDISetOverrideEUCfgInStruct
{
    GTDI_ESCAPE_FUNCTION      Function;
    GTDI_EU_CONFIG_ENTRY_TYPE ConfigEntryType;
    union
    {
        uint32_t ThreadCount;          // Maximum number of threads spawned on single EU.
                                       //
        uint32_t EUMask;               // Threads will execute on n-th core only if n-th
    };                                 // bit of EUMask is 1. If there is fewer than 8
                                       // cores per slice (e.g. SNB/IVB GT1), last core
                                       // in each row is not available (mask 0x77 selects
                                       // all available cores on single IVB/SNB GT1 slice).
                                       // On SNB GT2 both ThreadCount and EUMask must have
                                       // identical config on each slice - because of that
                                       // last submitted configuration for any slice will
                                       // be used for both slices during override enabling.
    GTDI_PIPELINE_STAGE PipelineStage; // Which pipeline stage does EUMask affect.
    GTDI_PARTITION_ID   PartitionID;   // Which partition does EUMask or ThreadCount affect.
    uint32_t            Reserved;      // for backwards compatibility

} GTDISetOverrideEUCfgIn;

/******************************************************************************/
/* GTDISetOverrideEUCfgOut                                                    */
/******************************************************************************/
typedef GTDIHeaderOut GTDISetOverrideEUCfgOut;

/******************************************************************************/
/* GTDI_FNC_SET_WORKAROUNDS function structure definitions                    */
/******************************************************************************/
typedef struct GTDISetWorkaroundsInStruct
{
    GTDI_ESCAPE_FUNCTION Function;
    bool32_t             Enable; // Enable / disable workaround
    GTDI_WORKAROUND_ID   Id;     // Workaround id
} GTDISetWorkaroundsIn;

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
    GTDI_ESCAPE_FUNCTION Function;
    bool32_t             Enable;
    GTDIOverridesHandle  Handle;
} GTDIOverridesSupportEnableIn;

/******************************************************************************/
/* GTDIOverridesSupportEnableOut:                                             */
/******************************************************************************/
typedef GTDIHeaderOut GTDIOverridesSupportEnableOut;

/******************************************************************************/
/* GTDISetKIQueryCfgInStruct                                                  */
/******************************************************************************/
typedef struct GTDISetKIQueryCfgInStruct
{
    GTDI_ESCAPE_FUNCTION     Func;
    GTDI_KI_KERNEL_TYPE_MASK KernelMask;
    uint32_t                 ReportCount;
    bool32_t                 GatherEUTimestampDispersion;
    GTDI_KI_BUILD_TYPE       QueryType;
} GTDISetKIQueryCfgIn;

/******************************************************************************/
/* GTDISetKIQueryCfgOutStruct                                                 */
/******************************************************************************/
typedef GTDIHeaderOut GTDISetKIQueryCfgOut;

/******************************************************************************/
/* GTDISetKIQueryCfgExInStruct                                                */
/******************************************************************************/
typedef struct GTDISetKIQueryCfgExInStruct
{
    GTDI_ESCAPE_FUNCTION     Func;
    GTDI_KI_KERNEL_TYPE_MASK KernelMask;
    uint32_t                 ReportCount;
    bool32_t                 GatherEUTimestampDispersion;
    GTDI_KI_BUILD_TYPE       QueryType;
    uint32_t                 VertexShaderID;
    uint32_t                 PixelShaderID;
    uint32_t                 GeometryShaderID;
    uint32_t                 HullShaderID;
    uint32_t                 DomainShaderID;
    uint32_t                 ComputeShaderID;
} GTDISetKIQueryCfgExIn;

/******************************************************************************/
/* GTDISetKIQueryCfgExOutStruct                                               */
/******************************************************************************/
typedef GTDIHeaderOut GTDISetKIQueryCfgExOut;

/******************************************************************************/
/* GTDISetKIBuildCfgInStruct                                                  */
/******************************************************************************/
typedef struct GTDISetKIBuildCfgInStruct
{
    GTDI_ESCAPE_FUNCTION Func;
    uint32_t             InstrType;
    uint32_t             OffsetCount;
    uint32_t             Offsets[GTDI_MAX_KI_OFFSETS];
    uint32_t             Flags;
    uint32_t             PartitionCount;  // Number of partitions to use profiled kernels
    uint32_t             PartitionEUMask; // Mask of EUs in each partition to use profiled kernels
    uint32_t             ThreadCount;
} GTDISetKIBuildCfgIn;

/******************************************************************************/
/* GTDISetKIBuildCfgOutStruct                                                 */
/******************************************************************************/
typedef GTDIHeaderOut GTDISetKIBuildCfgOut;

/******************************************************************************/
/* GTDISetKIBuildCfgExInStruct                                               */
/******************************************************************************/
typedef struct GTDISetKIBuildCfgExInStruct
{
    GTDI_ESCAPE_FUNCTION Func;
    uint32_t             InstrType;
    uint32_t             OffsetCount;
    uint32_t             Offsets[GTDI_MAX_KI_OFFSETS];
    uint32_t             Flags;
    uint32_t             PartitionCount;  // Number of partitions to use profiled kernels
    uint32_t             PartitionEUMask; // Mask of EUs in each partition to use profiled kernels
    uint32_t             ThreadCount;
    uint32_t             CfgID;
} GTDISetKIBuildCfgExIn;

/******************************************************************************/
/* GTDISetKIBuildCfgExOutStruct                                               */
/******************************************************************************/
typedef GTDIHeaderOut GTDISetKIBuildCfgExOut;

/******************************************************************************/
/* GTDIGetKIBuildInfoInStruct                                                 */
/******************************************************************************/
typedef struct GTDIGetKIBuildInfoInStruct
{
    GTDI_ESCAPE_FUNCTION Function;
    GTDI_KI_BUILD_TYPE   BuildType;
} GTDIGetKIBuildInfoIn;

/******************************************************************************/
/* GTDIGetKIBuildInfoOutStruct                                                */
/******************************************************************************/
typedef struct GTDIGetKIBuildInfoOutStruct
{
    GTDI_RETURN_CODE                 RetCode; // Result of the call
    uint32_t                         ReportSize;
    uint32_t                         MaxOffsetCount;
    uint32_t                         MaxPartitionCount;
    uint32_t                         MaxEUsInPartition;
    uint32_t                         MaxThreadCount;
    GTDI_KERNEL_BUILD_FLAGS          BuildFlags;
    GTDI_KERNEL_PROFILING_POINT_TYPE ProfilingPointEnumMask;
} GTDIGetKIBuildInfoOut;

/******************************************************************************/
/* GTDISetKernelDumpTypeInStruct                                              */
/******************************************************************************/
typedef struct GTDISetKernelDumpTypeInStruct
{
    GTDI_ESCAPE_FUNCTION  Func;
    GTDI_KERNEL_DUMP_TYPE KernelType;
} GTDISetKernelDumpTypeIn;

/******************************************************************************/
/* GTDISetKIBuildCfgExOutStruct                                               */
/******************************************************************************/
typedef GTDIHeaderOut GTDISetKernelDumpTypeOut;

/******************************************************************************/
/* GTDIGetGpuCpuTimestampsIn                                                  */
/******************************************************************************/
typedef GTDIHeaderIn GTDIGetGpuCpuTimestampsIn;

/******************************************************************************/
/* GTDIGetGpuCpuTimestampsOut                                                 */
/******************************************************************************/
typedef struct GTDIGetGpuCpuTimestampsOutStruct
{
    GTDI_RETURN_CODE RetCode;      // Result of the call
    uint64_t         GpuPerfTicks; // in GPU_timestamp_ticks
    uint64_t         CpuPerfTicks; // in CPU_timestamp_ticks
    uint64_t         GpuPerfFreq;  // in GPU_timestamp_ticks/s
    uint64_t         CpuPerfFreq;  // in CPU_timestamp_ticks/s
} GTDIGetGpuCpuTimestampsOut;

/******************************************************************************/
/* GTDIGetGpuCpuTimestampsExtOut                                              */
/******************************************************************************/
typedef struct GTDIGetGpuCpuTimestampsExtOutStruct
{
    GTDI_RETURN_CODE RetCode;              // Result of the call
    uint64_t         GpuPerfTicks;         // in GPU_timestamp_ticks
    uint64_t         CpuPerfTicks;         // in CPU_timestamp_ticks;
    uint64_t         GpuPerfFreq;          // in GPU_timestamp_ticks/s
    uint64_t         CpuPerfFreq;          // in CPU_timestamp_ticks/s
    uint64_t         CorrelationIndicator; // in CPU_timestamp_ticks
} GTDIGetGpuCpuTimestampsExtOut;

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
    GTDI_RETURN_CODE RetCode; // Result of this call
    union ErrorInfo
    {
        struct
        {
            wchar_t Name[GTDI_NAME_SIZE];
        } ConcurrentAPI;
    } Information;
} GTDIGetErrorInfoOut;

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
    uint32_t OffsetMetricEnable; // Offset of the enable metrics flag block (in bytes)
    uint32_t MetricCount;        // Number of metrics
} GTDI_CONFIG_MEMORY_FILE_HEADER;

/******************************************************************************/
/* GTDI_CONFIG_MEMORY_FILE_STRUCT                                             */
/******************************************************************************/
typedef struct GTDI_CONFIG_MEMORY_FILE_STRUCT
{
    GTDI_CONFIG_MEMORY_FILE_HEADER Header;
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
    wchar_t  URI[GTDI_URI_SIZE];          //
    wchar_t  Name[GTDI_NAME_SIZE];        //
    wchar_t  Description[GTDI_DESC_SIZE]; //
    uint32_t MetricType;                  // As defined in this header
    uint32_t CounterIndex;                // Index
    uint64_t MaxValue;                    // Not used at this time. For future purpose.
} GTDI_METRIC_INFO;

/******************************************************************************/
/* GTDI_OVERRIDE_INFO                                                         */
/******************************************************************************/
typedef struct GTDI_OVERRIDE_INFO_STRUCT
{
    wchar_t  URI[GTDI_URI_SIZE];   //
    wchar_t  Name[GTDI_NAME_SIZE]; //
    wchar_t  Desc[GTDI_DESC_SIZE]; //
    uint32_t Id;                   // Override id used to enable/disable it via escape function
    bool32_t Dynamic;              // true - dynamic override
                                   // false - not dynamic
} GTDI_OVERRIDE_INFO;

/******************************************************************************/
/* GTDI_SYSTEM_FILE_HEADER_STRUCT                                             */
/******************************************************************************/
typedef struct GTDI_SYSTEM_FILE_HEADER_STRUCT
{
    uint32_t Magic;
    uint32_t OffsetMetricInfo;   // Offset of the metrics info block (in bytes)
    uint32_t MetricCount;        // Number of metrics
    uint32_t OffsetOverrideInfo; // Offset of the metrics info block (in bytes)
    uint32_t OverrideCount;      // Number of overrides
} GTDI_SYSTEM_FILE_HEADER;

/******************************************************************************/
/* GTDI_SYSTEM_FILE_STRUCT                                                    */
/******************************************************************************/
typedef struct GTDI_SYSTEM_FILE_STRUCT
{
    GTDI_SYSTEM_FILE_HEADER Header;
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
    uint32_t OffsetMetricCounters; // Offset of the counters block (in bytes from
                                   // the beginning of file)
} GTDI_STAT_FILE_HEADER;

#endif // __GTDI_DRIVER_INTERFACE_H_
