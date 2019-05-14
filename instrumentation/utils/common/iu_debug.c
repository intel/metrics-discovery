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

    File Name:  iu_debug.c

    Abstract:   Instrumentation Utils common debug routines and structures.

\*****************************************************************************/
#include "iu_debug.h"
#include "iu_std.h"
#include "iu_os.h"

#include <stdarg.h>

/*****************************************************************************\
GLOBAL VAR: g_IuLogsControl - default debug logs settings
\*****************************************************************************/
IU_LOGS_CONTROL g_IuLogsControl =
{

#if defined(_DEBUG)

    // AssertEnable
    true,
    // LogLayerEnable
    IU_DBG_LAYER_ALL,
    // LogLevel.severity
    IU_DBG_SEV_WARNING |
    // LogLevel.show
    IU_DBG_SHOW_ALL | IU_DBG_ALIGNED,

#elif defined(_RELEASE_INTERNAL)

    // AssertEnable
    false,
    // LogLayerEnable
    IU_DBG_LAYER_ALL,
    // LogLevel.severity
    IU_DBG_SEV_WARNING |
    // LogLevel.show
    IU_DBG_SHOW_ALL | IU_DBG_ALIGNED,

#else // RELEASE

    // AssertEnable
    false,
    // LogLayerEnable
    IU_DBG_LAYER_ALL,
    // LogLevel.severity - for debug & info logs don't forget to enable
    //                     IU_DEBUG_LOGS (in iu_debug.h)
    IU_DBG_SEV_ERROR |
    //IU_DBG_SEV_DEBUG |
    // LogLevel.show
    IU_DBG_SHOW_TAG | IU_DBG_ALIGNED,
    //IU_DBG_SHOW_TAG | IU_DBG_SHOW_FUNCTION | IU_DBG_ALIGNED,

#endif

};

/*****************************************************************************\
FUNCTION: IuCheckLogLevel
\*****************************************************************************/
bool IuCheckLogLevel(
    const uint32_t dbgLevel,
    const uint32_t layer)
{
    uint32_t dbgLevelSet = 0;

    if (!(g_IuLogsControl.LogLayerEnable & layer))
    {
        return false;
    }

    dbgLevelSet = g_IuLogsControl.LogLevel;
    if ((dbgLevel & IU_DBG_CONSOLE_DUMP) ||
        (dbgLevelSet & dbgLevel & IU_DBG_SEV_MASK))
    {
        return true;
    }

    return false;
}

/*****************************************************************************\
Function: IuDebugGetModInfo
\*****************************************************************************/
static char* __IuLogGetModInfo()
{
    static char* IU_EMPTY_MODULE_INFO = "";
    static char* pModuleInfo          = NULL;

    if (!pModuleInfo)
    {
        static char  moduleInfo[IU_MODULE_NAME_SIZE_MAX] = {0,};
        static char* dlName      = NULL;
        static char* processName = NULL;

        iu_zeromem(moduleInfo, sizeof(moduleInfo));

        IuGetModuleInfo(&dlName, &processName);

        if ((processName) &&
            ((iu_strnlen_s(moduleInfo, IU_MODULE_NAME_SIZE_MAX) +
               iu_strnlen_s(processName, IU_MODULE_NAME_SIZE_MAX) + 1 ) // 1 => '\0'
              < IU_MODULE_NAME_SIZE_MAX))
        {
            iu_strcat_s(moduleInfo, sizeof(moduleInfo), processName);
        }

        if ((dlName) &&
            ((iu_strnlen_s(moduleInfo, IU_MODULE_NAME_SIZE_MAX) +
               iu_strnlen_s(dlName, IU_MODULE_NAME_SIZE_MAX) +
               3) // 3 => '(' + ')' + '\0'
              < IU_MODULE_NAME_SIZE_MAX))
        {
            iu_strcat_s(moduleInfo, sizeof(moduleInfo), "(" );
            iu_strcat_s(moduleInfo, sizeof(moduleInfo), dlName);
            iu_strcat_s(moduleInfo, sizeof(moduleInfo), ")" );
        }

        if (iu_strnlen_s(moduleInfo, IU_MODULE_NAME_SIZE_MAX))
        {
            pModuleInfo = moduleInfo;
        }
        else
        {
            pModuleInfo = IU_EMPTY_MODULE_INFO;
        }
    }

    return pModuleInfo;
}

/*****************************************************************************\
Function:       __IuLogPrint

Description:    Outputs debug information.
\*****************************************************************************/
void __IuLogPrint(
    const char*    sevTag,
    const uint32_t level,
    const char*    layerTag,
    const char*    fncName,
    const char*    inFormat, ...)
{
    #define IU_BUF_SIZE           512
    #define IU_FORMAT_SIZE        512

    #define IU_TAG_ALIGNMENT      -7
    #define IU_MODULE_ALIGNMENT   -14
    #define IU_FUNCTION_ALIGNMENT -30

    va_list ap;

    char buf[IU_BUF_SIZE];
    char outFormat[IU_FORMAT_SIZE];
    size_t outFormatOffset = 0;

    // severity tag
    iu_snprintf(outFormat, IU_FORMAT_SIZE, "%s",  sevTag);
    // layer tag
    if (g_IuLogsControl.LogLevel & IU_DBG_SHOW_TAG)
    {
        int32_t tagAlignment = (g_IuLogsControl.LogLevel & IU_DBG_ALIGNED) ? IU_TAG_ALIGNMENT : 0;
        outFormatOffset = iu_strnlen_s(outFormat, sizeof(outFormat));
        iu_snprintf(outFormat+outFormatOffset, IU_FORMAT_SIZE-outFormatOffset, ":%*s", tagAlignment, layerTag);
    }
    // module name
    if (g_IuLogsControl.LogLevel & IU_DBG_SHOW_MODULE)
    {
        int32_t moduleAlignment = (g_IuLogsControl.LogLevel & IU_DBG_ALIGNED) ? IU_MODULE_ALIGNMENT : 0;
        outFormatOffset = iu_strnlen_s(outFormat, sizeof(outFormat));
        iu_snprintf(outFormat+outFormatOffset, IU_FORMAT_SIZE-outFormatOffset, ":%*s", moduleAlignment, __IuLogGetModInfo());
    }
    // function name
    if (g_IuLogsControl.LogLevel & IU_DBG_SHOW_FUNCTION)
    {
        int32_t functionAlignment = (g_IuLogsControl.LogLevel & IU_DBG_ALIGNED) ? IU_FUNCTION_ALIGNMENT : 0;
        outFormatOffset = iu_strnlen_s(outFormat, sizeof(outFormat));
        iu_snprintf(outFormat+outFormatOffset, IU_FORMAT_SIZE-outFormatOffset, ":%*s", functionAlignment, fncName);
    }
    // log body
    outFormatOffset = iu_strnlen_s(outFormat, sizeof(outFormat));
    iu_snprintf(outFormat+outFormatOffset, IU_FORMAT_SIZE-outFormatOffset, ": %s ", inFormat);

    va_start(ap, inFormat);
    iu_vsnprintf(buf, IU_BUF_SIZE, outFormat, ap);
    va_end(ap);

    iu_log(buf);

    if ((g_IuLogsControl.LogLevel & IU_DBG_CONSOLE_DUMP) ||
        (level & IU_DBG_CONSOLE_DUMP))
    {
        iu_printfln(buf);
    }
}

/*****************************************************************************\
Function:    IuLogGetSettings

Description: Overrides default (complied) log settings
\*****************************************************************************/
void IuLogGetSettings()
{
    IuLogGetSystemSettings(
        &g_IuLogsControl.AssertEnable,
        &g_IuLogsControl.LogLayerEnable,
        &g_IuLogsControl.LogLevel);

    IuLogGetLocalSettings(
        &g_IuLogsControl.AssertEnable,
        &g_IuLogsControl.LogLayerEnable,
        &g_IuLogsControl.LogLevel);
}
