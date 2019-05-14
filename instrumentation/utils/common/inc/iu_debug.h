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

    File Name:  iu_debug.h

    Abstract:   Instrumentation Utils debug macros and structures definitions.

\*****************************************************************************/
#pragma once

#include <stdint.h>
#include <stdbool.h>

#if defined(__cplusplus)
extern "C"
{
#endif

/*****************************************************************************\
MACRO: IU_DEBUG_LOGS - enabling debug & info logs
       The default logs settings are defined in g_IuLogsControl ->
       (feel free to adjust it according to your needs)
       Here is an example (all available logs with all details):
          AssertEnable   = false (assert are printed, but without breakpoints)
          LogLayerEnable = IU_DBG_LAYER_ALL,                   // MD & MDAPI & INSTR & IU & ML
          LogLevel       = IU_DBG_SEV_DEBUG | IU_DBG_SHOW_ALL, // severity <= DEBUG

\*****************************************************************************/
#if defined(_DEBUG) || defined(_RELEASE_INTERNAL)
#define IU_DEBUG_LOGS 1
#else
// Uncomment following line to compile debug & info logs also in release build
// Note, that it is not needed for critical & error logs - they are always included
//#define IU_DEBUG_LOGS 1
#endif

/*****************************************************************************\
MACRO: Log settings names in config files / registry
\*****************************************************************************/
#define IU_CONFIG_NAME_ASSERT_ENABLE        L"AssertEnable"
#define IU_CONFIG_NAME_LOG_LAYER_ENABLE     L"DebugEnable"
#define IU_CONFIG_NAME_LOG_LEVEL            L"DebugLevel"

/*****************************************************************************\
MACRO: Local log settings constants and helpers
\*****************************************************************************/
#define IU_CONFIG_FILE_PATH_SIZE_MAX 260
#define IU_CONFIG_FILE_LINE_SIZE_MAX 100
#define IU_CONFIG_FILE_LINE_LAYOUT   L"\"%99l[^\"]\"=dword:%99ls\n" // input  - '"ExampleKey"=dword:FFFFFFFF'
                                                                    // output - 'ExampleKey' and 'FFFFFFFF'
                                                                    // "\     - if a quotation mark occurred, start an expression matching
                                                                    // [^\"]  - continue matching the expression until the quotation mark reappears
#define IU_CONFIG_FILE_NAME          "iu.config"

/*****************************************************************************\
FUNCTION: IuCheckLogLevel (compares an incoming logLevel and layer to IU settings)
\*****************************************************************************/
bool IuCheckLogLevel(const uint32_t dbgLevel, const uint32_t layer);

/*****************************************************************************\
FUNCTION: IuLogGetSettings (to override default log settings)
\*****************************************************************************/
void IuLogGetSettings(void);

/*****************************************************************************\
FUNCTION: __IuLogPrint (for internal use only)
\*****************************************************************************/
void __IuLogPrint(const char* sevTag, const uint32_t level,
                  const char* layerTag, const char* fncName, const char* formatString, ...);

/*****************************************************************************\
STRUCT: IU_LOGS_CONTROL
\*****************************************************************************/
typedef struct IU_LOGS_CONTROL_REC
{
    // enabling real asserts, not applicable to the related logs
    bool     AssertEnable;

    // enabling debug output in selected layers (MDAPI/MD/INSTR/IU/ML)
    uint32_t LogLayerEnable;

    // selecting severity level of debug output
    // &
    // selecting which log fields are shown (tag, moduleName, functionName)
    uint32_t LogLevel;
} IU_LOGS_CONTROL;
extern IU_LOGS_CONTROL g_IuLogsControl;

/*****************************************************************************\
MACROS: related to debug severity, shown fields, debug layers
\*****************************************************************************/
// severity
#define IU_DBG_ALL                  0x000003FF
#define IU_DBG_OFF                  0x00000000

#define IU_DBG_SEV_CRITICAL         0x00000001 // unexpected unrecoverable errors, user for asserts only
#define IU_DBG_SEV_ERROR            0x00000002 // unexpected recoverable errors
#define IU_DBG_SEV_WARNING          0x00000004 // expected errors & warnings
#define IU_DBG_SEV_INFO             0x00000008 // information messages
#define IU_DBG_SEV_DEBUG            0x00000010 // debug messages

// ML exclusive severity
#define IU_DBG_SEV_TRAITS           0x00000020 // traits messages
#define IU_DBG_SEV_ENTERED          0x00000040 // entered a function
#define IU_DBG_SEV_EXITING          0x00000080 // exiting a function
#define IU_DBG_SEV_INPUT            0x00000100 // input parameter
#define IU_DBG_SEV_OUTPUT           0x00000200 // output parameter

#define IU_DBG_SEV_MASK             0x000003FF // severity mask

// if following flag is set, logs will be aligned in output
#define IU_DBG_ALIGNED              0x08000000

// shown fields
#define IU_DBG_SHOW_TAG             0x04000000
#define IU_DBG_SHOW_MODULE          0x02000000
#define IU_DBG_SHOW_FUNCTION        0x01000000
#define IU_DBG_SHOW_ALL            (IU_DBG_SHOW_TAG    |  \
                                    IU_DBG_SHOW_MODULE |  \
                                    IU_DBG_SHOW_FUNCTION)

// if following flag is set, logs will be additionally printed on console
#define IU_DBG_CONSOLE_DUMP         0x80000000

// layers
#define IU_DBG_LAYER_INSTR          0x00000001
#define IU_DBG_LAYER_MD             0x00000002
#define IU_DBG_LAYER_MDAPI          0x00000004
#define IU_DBG_LAYER_IU             0x00000008
#define IU_DBG_LAYER_ML             0x00000010
#define IU_DBG_LAYER_ALL           (IU_DBG_LAYER_INSTR |   \
                                    IU_DBG_LAYER_MD    |   \
                                    IU_DBG_LAYER_MDAPI |   \
                                    IU_DBG_LAYER_IU    |   \
                                    IU_DBG_LAYER_ML)

/*****************************************************************************\
MACROS: related to logs printing
\*****************************************************************************/
// error & warning logs are available in any driver
#define F_IU_DBG_SEV_CRITICAL(level, layer, ...)    if(IuCheckLogLevel(level, layer)) __IuLogPrint("C", level, __VA_ARGS__)
#define F_IU_DBG_SEV_ERROR(level, layer, ...)       if(IuCheckLogLevel(level, layer)) __IuLogPrint("E", level, __VA_ARGS__)
#define F_IU_DBG_SEV_WARNING(level, layer, ...)     if(IuCheckLogLevel(level, layer)) __IuLogPrint("W", level, __VA_ARGS__)
// debug logs are not available in release driver
#if IU_DEBUG_LOGS
    #define F_IU_DBG_SEV_INFO(level, layer, ...)    if(IuCheckLogLevel(level, layer)) __IuLogPrint("I", level, __VA_ARGS__)
    #define F_IU_DBG_SEV_DEBUG(level, layer, ...)   if(IuCheckLogLevel(level, layer)) __IuLogPrint("D", level, __VA_ARGS__)
    #define F_IU_DBG_SEV_TRAITS(level, layer, ...)  if(IuCheckLogLevel(level, layer)) __IuLogPrint("T", level, __VA_ARGS__)
    #define F_IU_DBG_SEV_ENTERED(level, layer, ...) if(IuCheckLogLevel(level, layer)) __IuLogPrint(">", level, __VA_ARGS__)
    #define F_IU_DBG_SEV_EXITING(level, layer, ...) if(IuCheckLogLevel(level, layer)) __IuLogPrint("<", level, __VA_ARGS__)
    #define F_IU_DBG_SEV_INPUT(level, layer, ...)   if(IuCheckLogLevel(level, layer)) __IuLogPrint(">", level, __VA_ARGS__)
    #define F_IU_DBG_SEV_OUTPUT(level, layer, ...)  if(IuCheckLogLevel(level, layer)) __IuLogPrint("<", level, __VA_ARGS__)
#else
    #define F_IU_DBG_SEV_INFO(level, layer, ...)
    #define F_IU_DBG_SEV_DEBUG(level, layer, ...)
    #define F_IU_DBG_SEV_TRAITS(level, layer, ...)
    #define F_IU_DBG_SEV_ENTERED(level, layer, ...)
    #define F_IU_DBG_SEV_EXITING(level, layer, ...)
    #define F_IU_DBG_SEV_INPUT(level, layer, ...)
    #define F_IU_DBG_SEV_OUTPUT(level, layer, ...)
#endif

// generic
#define _IU_LOG(F, level, layer, ...) F(level, layer, __VA_ARGS__)
#define IU_DBG_PRINT_TAGGED(level,layer,tag,function,...) _IU_LOG(F_##level, level, layer, tag, function, __VA_ARGS__, "")

/*****************************************************************************\
 compiler-dependent definitions for debug macros
\*****************************************************************************/
// intrinsic functions to cause debug break
#if defined(_MSC_VER)
    #define IU_DBG_BREAK __debugbreak()
#elif defined(__GNUC__)
    #define IU_DBG_BREAK __builtin_trap()
#else
    #include <assert.h>
    #define IU_DBG_BREAK assert(false)
#endif

/*****************************************************************************\
MACRO: IU_IS_ASSERT_ENABLED
\*****************************************************************************/
#define IU_IS_ASSERT_ENABLED (g_IuLogsControl.AssertEnable)

/*****************************************************************************\
MACRO: IU_ASSERT
\*****************************************************************************/
// generic
#if IU_DEBUG_LOGS
    #define IU_ASSERT_TAGGED(expr,layer,tag)    \
        if( !(expr) )                           \
    {                                           \
        IU_DBG_PRINT_TAGGED(IU_DBG_SEV_CRITICAL, layer, tag, __FUNCTION__, "!!! ASSERTION FAILURE: !!! -> %s:%d", __FILE__, __LINE__ );       \
        IU_DBG_PRINT_TAGGED(IU_DBG_SEV_CRITICAL, layer, tag, __FUNCTION__, "!!! ASSERTION DETAILS: !!! -> %s(): (" #expr ")", __FUNCTION__ ); \
        if( IU_IS_ASSERT_ENABLED )              \
        {                                       \
            IU_DBG_BREAK;                       \
        }                                       \
    }
#else
    #define IU_ASSERT_TAGGED(expr,layer,tag)
#endif

/*****************************************************************************\
MACROS: print function enter/exit
\*****************************************************************************/
// generic
#define IU_DBG_FUNCTION_ENTER_TAGGED(level,layer,tag) IU_DBG_PRINT_TAGGED(_##level, layer, tag, __FUNCTION__, "ENTERED >>>")
#define IU_DBG_FUNCTION_EXIT_TAGGED(level,layer,tag)  IU_DBG_PRINT_TAGGED(_##level, layer, tag, __FUNCTION__, "EXITING <<<");


/*****************************************************************************\
 INSTRUMENTATION UTILS LAYER LOGS
\*****************************************************************************/
// Tag to prefix log messages with
#if !defined(IU_LOG_TAG)
    #define IU_LOG_TAG "[IU]"
#endif

#define IU_ASSERT(expr)                    IU_ASSERT_TAGGED            (expr,    IU_DBG_LAYER_IU, IU_LOG_TAG)
#define IU_DBG_PRINT(level, ...)           IU_DBG_PRINT_TAGGED         (_##level, IU_DBG_LAYER_IU, IU_LOG_TAG, __FUNCTION__, __VA_ARGS__)
#define IU_DBG_FUNCTION_ENTER(level)       IU_DBG_FUNCTION_ENTER_TAGGED(_##level, IU_DBG_LAYER_IU, IU_LOG_TAG);
#define IU_DBG_FUNCTION_EXIT(level)        IU_DBG_FUNCTION_EXIT_TAGGED (_##level, IU_DBG_LAYER_IU, IU_LOG_TAG);
#define IU_DBG_FUNCTION_OUTPUT(level, x)   IU_DBG_PRINT                (_##level, "OUT: %s = %#018llx = %llu", #x, x, x );
#define IU_DBG_FUNCTION_OUTPUT64(level, x) IU_DBG_PRINT                (_##level, "OUT: %s = %#08x = %u", #x, x, x );

/*****************************************************************************\
MACROS: following macros are required for compatibility with compilers on
        different systems.
        Example: GCC doesn't allow concatenation with empty strings - has to be
        '_##level' instead of '##level'.
\*****************************************************************************/
#define _IU_DBG_SEV_CRITICAL                        IU_DBG_SEV_CRITICAL
#define _IU_DBG_SEV_ERROR                           IU_DBG_SEV_ERROR
#define _IU_DBG_SEV_WARNING                         IU_DBG_SEV_WARNING
#define _IU_DBG_SEV_INFO                            IU_DBG_SEV_INFO
#define _IU_DBG_SEV_DEBUG                           IU_DBG_SEV_DEBUG
#define _IU_DBG_SEV_TRAITS                          IU_DBG_SEV_TRAITS
#define _IU_DBG_SEV_ENTERED                         IU_DBG_SEV_ENTERED
#define _IU_DBG_SEV_EXITING                         IU_DBG_SEV_EXITING
#define _IU_DBG_SEV_INPUT                           IU_DBG_SEV_INPUT
#define _IU_DBG_SEV_OUTPUT                          IU_DBG_SEV_OUTPUT
#define _IU_DBG_CONSOLE_DUMP                        IU_DBG_CONSOLE_DUMP

#define __IU_DBG_SEV_CRITICAL                       IU_DBG_SEV_CRITICAL
#define __IU_DBG_SEV_ERROR                          IU_DBG_SEV_ERROR
#define __IU_DBG_SEV_WARNING                        IU_DBG_SEV_WARNING
#define __IU_DBG_SEV_INFO                           IU_DBG_SEV_INFO
#define __IU_DBG_SEV_DEBUG                          IU_DBG_SEV_DEBUG
#define __IU_DBG_SEV_TRAITS                         IU_DBG_SEV_TRAITS
#define __IU_DBG_SEV_ENTERED                        IU_DBG_SEV_ENTERED
#define __IU_DBG_SEV_EXITING                        IU_DBG_SEV_EXITING
#define __IU_DBG_SEV_INPUT                          IU_DBG_SEV_INPUT
#define __IU_DBG_SEV_OUTPUT                         IU_DBG_SEV_OUTPUT
#define __IU_DBG_CONSOLE_DUMP                       IU_DBG_CONSOLE_DUMP

#define F__IU_DBG_SEV_CRITICAL(level, layer, ...)   F_IU_DBG_SEV_CRITICAL(level, layer, __VA_ARGS__)
#define F__IU_DBG_SEV_ERROR(level, layer, ...)      F_IU_DBG_SEV_ERROR(level, layer, __VA_ARGS__)
#define F__IU_DBG_SEV_WARNING(level, layer, ...)    F_IU_DBG_SEV_WARNING(level, layer, __VA_ARGS__)
#define F__IU_DBG_SEV_INFO(level, layer, ...)       F_IU_DBG_SEV_INFO(level, layer, __VA_ARGS__)
#define F__IU_DBG_SEV_DEBUG(level, layer, ...)      F_IU_DBG_SEV_DEBUG(level, layer, __VA_ARGS__)
#define F__IU_DBG_SEV_TRAITS(level, layer, ...)     F_IU_DBG_SEV_TRAITS(level, layer, __VA_ARGS__)
#define F__IU_DBG_SEV_ENTERED(level, layer, ...)    F_IU_DBG_SEV_ENTERED(level, layer, __VA_ARGS__)
#define F__IU_DBG_SEV_EXITING(level, layer, ...)    F_IU_DBG_SEV_EXITING(level, layer, __VA_ARGS__)
#define F__IU_DBG_SEV_INPUT(level, layer, ...)      F_IU_DBG_SEV_INPUT(level, layer, __VA_ARGS__)
#define F__IU_DBG_SEV_OUTPUT(level, layer, ...)     F_IU_DBG_SEV_OUTPUT(level, layer, __VA_ARGS__)
#define F__IU_DBG_CONSOLE_DUMP(level, layer, ...)   F_IU_DBG_SEV_DEBUG(level, layer, __VA_ARGS__)

#define F___IU_DBG_SEV_CRITICAL(level, layer, ...)  F_IU_DBG_SEV_CRITICAL(level, layer, __VA_ARGS__)
#define F___IU_DBG_SEV_ERROR(level, layer, ...)     F_IU_DBG_SEV_ERROR(level, layer, __VA_ARGS__)
#define F___IU_DBG_SEV_WARNING(level, layer, ...)   F_IU_DBG_SEV_WARNING(level, layer, __VA_ARGS__)
#define F___IU_DBG_SEV_INFO(level, layer, ...)      F_IU_DBG_SEV_INFO(level, layer, __VA_ARGS__)
#define F___IU_DBG_SEV_DEBUG(level, layer, ...)     F_IU_DBG_SEV_DEBUG(level, layer, __VA_ARGS__)
#define F___IU_DBG_SEV_TRAITS(level, layer, ...)    F_IU_DBG_SEV_TRAITS(level, layer, __VA_ARGS__)
#define F___IU_DBG_SEV_ENTERED(level, layer, ...)   F_IU_DBG_SEV_ENTERED(level, layer, __VA_ARGS__)
#define F___IU_DBG_SEV_EXITING(level, layer, ...)   F_IU_DBG_SEV_EXITING(level, layer, __VA_ARGS__)
#define F___IU_DBG_SEV_INPUT(level, layer, ...)     F_IU_DBG_SEV_INPUT(level, layer, __VA_ARGS__)
#define F___IU_DBG_SEV_OUTPUT(level, layer, ...)    F_IU_DBG_SEV_OUTPUT(level, layer, __VA_ARGS__)
#define F___IU_DBG_CONSOLE_DUMP(level, layer, ...)  F_IU_DBG_SEV_DEBUG(level, layer, __VA_ARGS__)

#if defined(__cplusplus)
}
#endif

