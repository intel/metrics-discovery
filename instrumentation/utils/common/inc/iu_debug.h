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

    File Name:  iu_debug.h

    Abstract:   Instrumentation Utils debug macros and structures definitions.

\*****************************************************************************/
#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <wchar.h>

#if defined(__cplusplus)
extern "C"
{
#endif

/*****************************************************************************\
MACRO: IU_DEBUG_LOGS - enabling debug & info logs
       The default logs settings are defined in g_IuLogsControl ->
       (feel free to adjust it according to your needs)
       Here is an example (all available logs with all details):
          AssertEnable   = FALSE (assert are printed, but without breakpoints)
          LogLayerEnable = IU_DBG_LAYER_ALL,                   // MD & MDAPI & INSTR & IU
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
FUNCTION: __IuLogPrint (for internal use only)
\*****************************************************************************/
void __IuLogPrint(const char* sevTag, uint32_t level, uint32_t layer,
                  const char* layerTag, const char* fncName, const char* formatString, ...);

/*****************************************************************************\
STRUCT: IU_LOGS_CONTROL
\*****************************************************************************/
typedef struct IU_LOGS_CONTROL_REC
{
    // enabling real asserts, not applicable to the related logs
    bool     AssertEnable;

    // enabling debug output in selected layers (MDAPI/MD/INSTR/IU)
    uint32_t LogLayerEnable;

    // selecting severity level of debug output
    // &
    // selecting which log fields are shown (tag, moduleName, functionName)
    uint32_t LogLevel;

    // Windows registry path (useful for Windows only)
    const wchar_t* RegistryPath;
} IU_LOGS_CONTROL;
extern IU_LOGS_CONTROL g_IuLogsControl;

/*****************************************************************************\
MACROS: related to debug severity, shown fields, debug layers
\*****************************************************************************/
// severity
#define IU_DBG_ALL                   0x0000000F
#define IU_DBG_OFF                   0x00000000

#define IU_DBG_SEV_CRITICAL          0x00000001 // unexpected unrecoverable errors, user for asserts only
#define IU_DBG_SEV_ERROR             0x00000002 // unexpected recoverable errors
#define IU_DBG_SEV_WARNING           0x00000004 // expected errors & warnings
#define IU_DBG_SEV_INFO              0x00000008 // information messages
#define IU_DBG_SEV_DEBUG             0x00000010 // debug messages
#define IU_DBG_SEV_MASK              0x0000001F // severity mask

// following macros are required for compatibility with current MD/MDAPI logs
#define _LOG_ERROR                   IU_DBG_SEV_ERROR
#define _LOG_WARNING                 IU_DBG_SEV_WARNING
#define _LOG_INFO                    IU_DBG_SEV_INFO
#define _LOG_DEBUG                   IU_DBG_SEV_DEBUG

#define __LOG_ERROR                  IU_DBG_SEV_ERROR
#define __LOG_WARNING                IU_DBG_SEV_WARNING
#define __LOG_INFO                   IU_DBG_SEV_INFO
#define __LOG_DEBUG                  IU_DBG_SEV_DEBUG

#define _IU_DBG_SEV_CRITICAL         IU_DBG_SEV_CRITICAL
#define _IU_DBG_SEV_ERROR            IU_DBG_SEV_ERROR
#define _IU_DBG_SEV_WARNING          IU_DBG_SEV_WARNING
#define _IU_DBG_SEV_INFO             IU_DBG_SEV_INFO
#define _IU_DBG_SEV_DEBUG            IU_DBG_SEV_DEBUG

#define __IU_DBG_SEV_CRITICAL        IU_DBG_SEV_CRITICAL
#define __IU_DBG_SEV_ERROR           IU_DBG_SEV_ERROR
#define __IU_DBG_SEV_WARNING         IU_DBG_SEV_WARNING
#define __IU_DBG_SEV_INFO            IU_DBG_SEV_INFO
#define __IU_DBG_SEV_DEBUG           IU_DBG_SEV_DEBUG

// if following flag is set, logs will be aligned in output
#define IU_DBG_ALIGNED               0x08000000

// shown fields
#define IU_DBG_SHOW_TAG              0x04000000
#define IU_DBG_SHOW_MODULE           0x02000000
#define IU_DBG_SHOW_FUNCTION         0x01000000
#define IU_DBG_SHOW_ALL             (IU_DBG_SHOW_TAG    |  \
                                     IU_DBG_SHOW_MODULE |  \
                                     IU_DBG_SHOW_FUNCTION)

// if following flag is set, logs will be additionally printed on console
#define IU_DBG_CONSOLE_DUMP          0x80000000

// layers
#define IU_DBG_LAYER_INSTR           0x00000001
#define IU_DBG_LAYER_MD              0x00000002
#define IU_DBG_LAYER_MDAPI           0x00000004
#define IU_DBG_LAYER_IU              0x00000008
#define IU_DBG_LAYER_ALL            (IU_DBG_LAYER_INSTR |   \
                                     IU_DBG_LAYER_MD    |   \
                                     IU_DBG_LAYER_MDAPI |   \
                                     IU_DBG_LAYER_IU)

/*****************************************************************************\
MACROS: related to logs printing
\*****************************************************************************/

// error & warning logs are available in any driver
#define F_IU_DBG_SEV_CRITICAL(...)    __IuLogPrint("C", __VA_ARGS__)
#define F_IU_DBG_SEV_ERROR(...)       __IuLogPrint("E", __VA_ARGS__)
#define F_IU_DBG_SEV_WARNING(...)     __IuLogPrint("W", __VA_ARGS__)
// debug logs are not available in release driver
#if IU_DEBUG_LOGS
    #define F_IU_DBG_SEV_INFO(...)    __IuLogPrint("I", __VA_ARGS__)
    #define F_IU_DBG_SEV_DEBUG(...)   __IuLogPrint("D", __VA_ARGS__)
#else
    #define F_IU_DBG_SEV_INFO(...)
    #define F_IU_DBG_SEV_DEBUG(...)
#endif
// following macros are required for compatibility with current MD/MDAPI logs
#define F__LOG_ERROR(...)            F_IU_DBG_SEV_ERROR(__VA_ARGS__)
#define F__LOG_WARNING(...)          F_IU_DBG_SEV_WARNING(__VA_ARGS__)
#define F__LOG_INFO(...)             F_IU_DBG_SEV_INFO(__VA_ARGS__)
#define F__LOG_DEBUG(...)            F_IU_DBG_SEV_DEBUG(__VA_ARGS__)

#define F___LOG_ERROR(...)           F_IU_DBG_SEV_ERROR(__VA_ARGS__)
#define F___LOG_WARNING(...)         F_IU_DBG_SEV_WARNING(__VA_ARGS__)
#define F___LOG_INFO(...)            F_IU_DBG_SEV_INFO(__VA_ARGS__)
#define F___LOG_DEBUG(...)           F_IU_DBG_SEV_DEBUG(__VA_ARGS__)

#define F__IU_DBG_SEV_CRITICAL(...)  F_IU_DBG_SEV_CRITICAL(__VA_ARGS__)
#define F__IU_DBG_SEV_ERROR(...)     F_IU_DBG_SEV_ERROR(__VA_ARGS__)
#define F__IU_DBG_SEV_WARNING(...)   F_IU_DBG_SEV_WARNING(__VA_ARGS__)
#define F__IU_DBG_SEV_INFO(...)      F_IU_DBG_SEV_INFO(__VA_ARGS__)
#define F__IU_DBG_SEV_DEBUG(...)     F_IU_DBG_SEV_DEBUG(__VA_ARGS__)

#define F___IU_DBG_SEV_CRITICAL(...) F_IU_DBG_SEV_CRITICAL(__VA_ARGS__)
#define F___IU_DBG_SEV_ERROR(...)    F_IU_DBG_SEV_ERROR(__VA_ARGS__)
#define F___IU_DBG_SEV_WARNING(...)  F_IU_DBG_SEV_WARNING(__VA_ARGS__)
#define F___IU_DBG_SEV_INFO(...)     F_IU_DBG_SEV_INFO(__VA_ARGS__)
#define F___IU_DBG_SEV_DEBUG(...)    F_IU_DBG_SEV_DEBUG(__VA_ARGS__)

// generic
#define _IU_LOG(F, ...) F(__VA_ARGS__)
#define IU_DBG_PRINT_TAGGED(level,layer,tag,...) _IU_LOG(F_##level, level, layer, tag, __FUNCTION__, __VA_ARGS__, "")

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
    #define IU_ASSERT_TAGGED(expr,layer,tag)                               \
        if( !(expr) )                    \
    {                                    \
        IU_DBG_PRINT_TAGGED(IU_DBG_SEV_CRITICAL, layer, tag, "!!! ASSERTION FAILURE: !!! -> %s:%d", __FILE__, __LINE__ );       \
        IU_DBG_PRINT_TAGGED(IU_DBG_SEV_CRITICAL, layer, tag, "!!! ASSERTION DETAILS: !!! -> %s(): (" #expr ")", __FUNCTION__ ); \
        if( IU_IS_ASSERT_ENABLED )  \
        {                           \
            IU_DBG_BREAK;           \
        }                           \
    }
#else
    #define IU_ASSERT_TAGGED(expr,layer,tag)
#endif

/*****************************************************************************\
MACROS: print function enter/exit
\*****************************************************************************/
// generic
#define IU_DBG_FUNCTION_ENTER_TAGGED(level,layer,tag)   IU_DBG_PRINT_TAGGED(_##level, layer, tag, "ENTERED >>>")
#define IU_DBG_FUNCTION_EXIT_TAGGED(level,layer,tag)    IU_DBG_PRINT_TAGGED(_##level, layer, tag,  "EXITING <<<");

/*****************************************************************************\
MACRO: unreferenced parameter
\*****************************************************************************/
#define IU_UNREFERENCED_PARAMETER(p) (p)


/*****************************************************************************\
 INSTRUMENTATION UTILS LAYER LOGS
\*****************************************************************************/
#if !defined(IU_LOG_TAG)
#define IU_LOG_TAG "[IU]"
#endif

#define IU_DBG_PRINT(level, ...) IU_DBG_PRINT_TAGGED(_##level, IU_DBG_LAYER_IU, IU_LOG_TAG, __VA_ARGS__)
#define IU_ASSERT(expr) IU_ASSERT_TAGGED(expr, IU_DBG_LAYER_INSTR, IU_LOG_TAG)


#if defined(__cplusplus)
}
#endif

