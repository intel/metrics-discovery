///////////////////////////////////////////////////////////////////////////////
//
//  Copyright © 2019-2021, Intel Corporation
//
//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included
//  in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
//  IN THE SOFTWARE.
//
//  File Name:  iu_debug.c
//
//  Abstract:   Instrumentation Utils common debug routines and structures.
//
///////////////////////////////////////////////////////////////////////////////
#include "iu_debug.h"
#include "iu_std.h"
#include "iu_os.h"

#include <stdarg.h>

///////////////////////////////////////////////////////////////////////////////
// GLOBAL VAR: g_IuLogsControl - default debug logs settings
//
// LogLevel.severity - for debug & info logs don't forget to enable
///////////////////////////////////////////////////////////////////////////////
IU_LOGS_CONTROL g_IuLogsControl = {

#if defined( _DEBUG )

    true,                                       // AssertEnable
    IU_DBG_LAYER_ALL,                           // LogLayerEnable
    IU_DBG_SEV_ERROR | IU_DBG_SEV_CRITICAL | 0, // LogLevel.severity & LogLevel.show_flags
    IU_ADAPTER_ID_DEFAULT,                      // AdapterId

#elif defined( _RELEASE_INTERNAL )

    false,                                                                                          // AssertEnable
    IU_DBG_LAYER_ALL,                                                                               // LogLayerEnable
    IU_DBG_SEV_WARNING | IU_DBG_SEV_ERROR | IU_DBG_SEV_CRITICAL | IU_DBG_SHOW_ALL | IU_DBG_ALIGNED, // LogLevel.severity & LogLevel.show_flags
    IU_ADAPTER_ID_DEFAULT,                                                                          // AdapterId

#else // RELEASE

    false,                                               // AssertEnable
    IU_DBG_LAYER_ALL,                                    // LogLayerEnable
    IU_DBG_SEV_ERROR | IU_DBG_SHOW_TAG | IU_DBG_ALIGNED, // LogLevel.severity & LogLevel.show_flags
    IU_ADAPTER_ID_DEFAULT,                               // AdapterId

#endif

};

///////////////////////////////////////////////////////////////////////////////
// FUNCTION: IuLogCheckLayer
///////////////////////////////////////////////////////////////////////////////
bool IuLogCheckLayer( const uint32_t layer )
{
    return g_IuLogsControl.LogLayerEnable & layer;
}

///////////////////////////////////////////////////////////////////////////////
// FUNCTION: IuLogCheckLevel
///////////////////////////////////////////////////////////////////////////////
bool IuLogCheckLevel(
    const uint32_t dbgLevel,
    const uint32_t layer )
{
    uint32_t dbgLevelSet = 0;

    const bool isLayerEnabled = IuLogCheckLayer( layer );

    if( !isLayerEnabled )
    {
        return false;
    }

    dbgLevelSet = g_IuLogsControl.LogLevel;
    if( ( dbgLevel & IU_DBG_CONSOLE_DUMP ) || ( dbgLevelSet & dbgLevel & IU_DBG_SEV_MASK ) )
    {
        return true;
    }

    return false;
}

///////////////////////////////////////////////////////////////////////////////
// FUNCTION: IuLogCheckShowMode
///////////////////////////////////////////////////////////////////////////////
bool IuLogCheckShowMode(
    const uint32_t showMode )
{
    return ( g_IuLogsControl.LogLevel & showMode );
}

///////////////////////////////////////////////////////////////////////////////
// Function: __IuLogGetModuleInfo
///////////////////////////////////////////////////////////////////////////////
static char* __IuLogGetModuleInfo()
{
    static char* IU_EMPTY_MODULE_INFO = "";
    static char* pModuleInfo          = NULL;

    if( !pModuleInfo )
    {
        static char  moduleInfo[IU_MODULE_NAME_SIZE_MAX] = { 0 };
        static char* dlName                              = NULL;
        static char* processName                         = NULL;

        iu_zeromem( moduleInfo, sizeof( moduleInfo ) );

        IuOsGetModuleInfo( &dlName, &processName );

        if( ( processName ) && ( ( iu_strnlen_s( moduleInfo, IU_MODULE_NAME_SIZE_MAX ) + iu_strnlen_s( processName, IU_MODULE_NAME_SIZE_MAX ) + 1 ) // 1 => '\0'
                                 < IU_MODULE_NAME_SIZE_MAX ) )
        {
            iu_strcat_s( moduleInfo, sizeof( moduleInfo ), processName );
        }

        if( ( dlName ) && ( ( iu_strnlen_s( moduleInfo, IU_MODULE_NAME_SIZE_MAX ) + iu_strnlen_s( dlName, IU_MODULE_NAME_SIZE_MAX ) + 3 ) // 3 => '(' + ')' + '\0'
                            < IU_MODULE_NAME_SIZE_MAX ) )
        {
            iu_strcat_s( moduleInfo, sizeof( moduleInfo ), "(" );
            iu_strcat_s( moduleInfo, sizeof( moduleInfo ), dlName );
            iu_strcat_s( moduleInfo, sizeof( moduleInfo ), ")" );
        }

        if( iu_strnlen_s( moduleInfo, IU_MODULE_NAME_SIZE_MAX ) )
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

///////////////////////////////////////////////////////////////////////////////
// Function:       __IuLogPrint
//
// Description:    Outputs debug information.
///////////////////////////////////////////////////////////////////////////////
#pragma warning( push )
#pragma warning( disable : 4100 ) // unreferenced formal parameter

void __IuLogPrint(
    const char*    sevTag,
    const uint32_t level,
    const char*    layerTag,
    const char*    fncName, // this parameter isn't used in release driver
    const char*    inFormat,
    ... )
{
#define IU_BUF_SIZE    512
#define IU_FORMAT_SIZE 512

#define IU_TAG_ALIGNMENT      -7
#define IU_MODULE_ALIGNMENT   -14
#define IU_FUNCTION_ALIGNMENT -50

    va_list ap;

    char   buf[IU_BUF_SIZE];
    char   outFormat[IU_FORMAT_SIZE];
    size_t outFormatOffset = 0;

    // adapter Id
    iu_snprintf( outFormat + outFormatOffset, IU_FORMAT_SIZE, "(A%d)", g_IuLogsControl.AdapterId );

    // severity tag
    outFormatOffset = iu_strnlen_s( outFormat, sizeof( outFormat ) );
    iu_snprintf( outFormat + outFormatOffset, IU_FORMAT_SIZE, ":%s", sevTag );

    // layer tag
    if( g_IuLogsControl.LogLevel & IU_DBG_SHOW_TAG )
    {
        int32_t tagAlignment = ( g_IuLogsControl.LogLevel & IU_DBG_ALIGNED ) ? IU_TAG_ALIGNMENT : 0;
        outFormatOffset      = iu_strnlen_s( outFormat, sizeof( outFormat ) );
        iu_snprintf( outFormat + outFormatOffset, IU_FORMAT_SIZE - outFormatOffset, ":%*s", tagAlignment, layerTag );
    }

    // module name
    if( g_IuLogsControl.LogLevel & IU_DBG_SHOW_MODULE )
    {
        int32_t moduleAlignment = ( g_IuLogsControl.LogLevel & IU_DBG_ALIGNED ) ? IU_MODULE_ALIGNMENT : 0;
        outFormatOffset         = iu_strnlen_s( outFormat, sizeof( outFormat ) );
        iu_snprintf( outFormat + outFormatOffset, IU_FORMAT_SIZE - outFormatOffset, ":%*s", moduleAlignment, __IuLogGetModuleInfo() );
    }

#if IU_DEBUG_LOGS // function names strings cannot be compiled into a release drv

    // function name
    if( g_IuLogsControl.LogLevel & IU_DBG_SHOW_FUNCTION )
    {
        int32_t functionAlignment = ( g_IuLogsControl.LogLevel & IU_DBG_ALIGNED ) ? IU_FUNCTION_ALIGNMENT : 0;
        outFormatOffset           = iu_strnlen_s( outFormat, sizeof( outFormat ) );

        // TODO: The '*s' printf parameter doesn't work in KMD drv - used a hardcoded version instead
        //iu_snprintf(outFormat+outFormatOffset, IU_FORMAT_SIZE-outFormatOffset, ":%*s", functionAlignment, fncName);
        if( functionAlignment )
        {
            iu_snprintf( outFormat + outFormatOffset, IU_FORMAT_SIZE - outFormatOffset, ":%-50s", fncName );
        }
        else
        {
            iu_snprintf( outFormat + outFormatOffset, IU_FORMAT_SIZE - outFormatOffset, ":%s", fncName );
        }
    }

#endif

    // log body
    outFormatOffset = iu_strnlen_s( outFormat, sizeof( outFormat ) );
    iu_snprintf( outFormat + outFormatOffset, IU_FORMAT_SIZE - outFormatOffset, ": %s ", inFormat );

    // new line sign
    if( g_IuLogsControl.LogLevel & IU_DBG_EOL )
    {
        outFormatOffset = iu_strnlen_s( outFormat, sizeof( outFormat ) );
        iu_snprintf( outFormat + outFormatOffset, IU_BUF_SIZE - outFormatOffset, "%s", "\n" );
    }

    va_start( ap, inFormat );
    iu_vsnprintf( buf, IU_BUF_SIZE, outFormat, ap );
    va_end( ap );

    iu_log( buf );

    if( ( g_IuLogsControl.LogLevel & IU_DBG_CONSOLE_DUMP ) || ( level & IU_DBG_CONSOLE_DUMP ) )
    {
        iu_printf( buf, !( g_IuLogsControl.LogLevel & IU_DBG_EOL ) );
    }
}

#pragma warning( pop )

///////////////////////////////////////////////////////////////////////////////
// Function:    IuLogGetSettings
//
// Description: Overrides default (complied) log settings
///////////////////////////////////////////////////////////////////////////////
void IuLogGetSettings( const uint32_t adapterId )
{
    g_IuLogsControl.AdapterId = adapterId;

    IuOsLogGetSystemSettings(
        &g_IuLogsControl.AssertEnable,
        &g_IuLogsControl.LogLayerEnable,
        &g_IuLogsControl.LogLevel );

    IuOsLogGetLocalSettings(
        &g_IuLogsControl.AssertEnable,
        &g_IuLogsControl.LogLayerEnable,
        &g_IuLogsControl.LogLevel );

    IU_DBG_FUNCTION_INPUT( IU_DBG_SEV_INFO, adapterId );
    IU_DBG_PRINT( IU_DBG_SEV_INFO, "&g_IuLogsControl = %#010x", g_IuLogsControl );
}
