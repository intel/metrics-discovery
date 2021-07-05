//////////////////////////////////////////////////////////////////////////////
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
//  File Name:  iu_os.cpp
//
//  Abstract:   Instrumentation Utils implementation with OS specific non-standard
//              functions for Linux / Android.
//
//////////////////////////////////////////////////////////////////////////////
#include "iu_os.h"
#include "iu_debug.h"
#include "iu_std.h"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#if defined( ANDROID )
    #include <time.h> // for clock_gettime
#elif defined( __linux )
    #include <sys/time.h> // for gettimeofday
#endif

extern "C"
{
    ///////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Instrumentation Utils Non-Standard OS Specific Functions
    //
    // Method:
    //     IuOsQueryPerformanceCounter
    //
    // Description:
    //     Retrieves high resolution timestamp (in ticks) and it's frequency.
    //
    // Input:
    //     uint64_t* outFrequency - performance counter frequency (ticks per second)
    //
    // Output:
    //     uint64_t               - performance counter value (timestamp in ticks)
    //
    ///////////////////////////////////////////////////////////////////////////////
    uint64_t IuOsQueryPerformanceCounter( uint64_t* outFrequency )
    {
        uint64_t frequency = 0;
        uint64_t counter   = 0;

#if defined( ANDROID )
        timespec currentTime;
        clock_gettime( CLOCK_MONOTONIC, &currentTime );
        counter   = (uint64_t) currentTime.tv_sec * IU_SECOND_IN_NS + currentTime.tv_nsec; // convert to ns
        frequency = IU_SECOND_IN_NS;                                                       // unit is nanosecond
#elif defined( __linux__ )
        timeval currentTime;
        gettimeofday( &currentTime, 0 );
        counter   = (uint64_t) currentTime.tv_sec * IU_SECOND_IN_US + currentTime.tv_usec; // convert to us
        frequency = IU_SECOND_IN_US;                                                       // unit is microsecond
#endif

        if( outFrequency )
        {
            *outFrequency = frequency;
        }

        IU_DBG_FUNCTION_OUTPUT64( IU_DBG_SEV_DEBUG, counter );
        IU_DBG_FUNCTION_OUTPUT64( IU_DBG_SEV_DEBUG, frequency );

        return counter;
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Instrumentation Utils Non-Standard OS Specific Functions
    //
    // Method:
    //     IuOsGetModuleInfo
    //
    // Description:
    //     Returns information on current module. Used for debug logs.
    //
    // Input:
    //     char** dlName      - (OUT)
    //     char** processName - (OUT)
    //
    ///////////////////////////////////////////////////////////////////////////////
    void IuOsGetModuleInfo( char** dlName, char** processName )
    {
        static char fullProcessName[IU_MODULE_NAME_SIZE_MAX] = { 0 };

        // Get an executable path. If the function fails, it shall return a value of -1.
        if( readlink( "/proc/self/exe", fullProcessName, IU_MODULE_NAME_SIZE_MAX ) == -1 )
        {
            IU_DBG_PRINT( IU_DBG_SEV_ERROR, "Couldn't find an executable, exiting" );
            return;
        }

        *processName = strrchr( fullProcessName, '/' ) + 1;
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Instrumentation Utils Non-Standard OS Specific Functions
    //
    // Method:
    //     IuOsLogGetSystemSettings
    //
    // Description:
    //     Reads system-wide instrumentation log settings.
    //
    // Input:
    //     bool*     assertEnable   - (OUT) read AssertEnable value
    //     uint32_t* logLayerEnable - (OUT) read LogLayerEnable value
    //     uint32_t* logLevel       - (OUT) read LogLevel value
    //
    ///////////////////////////////////////////////////////////////////////////////
    void IuOsLogGetSystemSettings(
        bool*     assertEnable,
        uint32_t* logLayerEnable,
        uint32_t* logLevel )
    {
        // To be implemented.
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Instrumentation Utils Non-Standard OS Specific Functions
    //
    // Method:
    //     IuOsLogGetLocalSettings
    //
    // Description:
    //     Reads local instrumentation log settings.
    //
    // Input:
    //     bool*     assertEnable   - (OUT) read AssertEnable value
    //     uint32_t* logLayerEnable - (OUT) read LogLayerEnable value
    //     uint32_t* logLevel       - (OUT) read LogLevel value
    //
    ///////////////////////////////////////////////////////////////////////////////
    void IuOsLogGetLocalSettings(
        bool*     assertEnable,
        uint32_t* logLayerEnable,
        uint32_t* logLevel )
    {
        // Get an executable path. If the function fails, it shall return a value of -1.
        char filePath[IU_CONFIG_FILE_PATH_SIZE_MAX] = { 0 };
        if( readlink( "/proc/self/exe", filePath, IU_CONFIG_FILE_PATH_SIZE_MAX ) == -1 )
        {
            IU_DBG_PRINT( IU_DBG_SEV_ERROR, "Couldn't find an executable, exiting" );
            return;
        }

        // Remove an executable filename from the path.
        uint32_t filePathSize = (uint32_t) iu_strnlen_s( filePath, IU_CONFIG_FILE_PATH_SIZE_MAX );
        for( uint32_t i = filePathSize; i > 0; --i )
        {
            if( filePath[i] == '/' )
            {
                filePath[i + 1] = '\0';
                break;
            }
        }

        // Join the config filename and the path.
        const char* fileName = IU_CONFIG_FILE_NAME;
        if( !iu_strcat_s( filePath, IU_CONFIG_FILE_PATH_SIZE_MAX, fileName ) )
        {
            IU_DBG_PRINT( IU_DBG_SEV_ERROR, "Failed to join the configuration filename and the path, exiting" );
            return;
        }

        // Open the config file.
        FILE* file = NULL;
        if( !iu_fopen_s( &file, filePath, "r" ) || !file )
        {
            IU_DBG_PRINT( IU_DBG_SEV_INFO, "Failed to open the configuration file, exiting" );
            return;
        }

        // Iterate through the config file.
        wchar_t  line[IU_CONFIG_FILE_LINE_SIZE_MAX]        = { 0 };
        wchar_t  name[IU_CONFIG_FILE_LINE_SIZE_MAX]        = { 0 };
        wchar_t  stringValue[IU_CONFIG_FILE_LINE_SIZE_MAX] = { 0 };
        uint32_t intValue                                  = 0;
        while( fgetws( line, IU_CONFIG_FILE_LINE_SIZE_MAX, file ) )
        {
            // Find a config name and its value.
            if( swscanf( line, IU_CONFIG_FILE_LINE_LAYOUT, name, stringValue ) == 2 )
            {
                // Convert the string literal to an unsigned integer.
                intValue = wcstoul( stringValue, NULL, 16 );

                // If the config name matches one of the globally defined config names, assign its value to it.
                if( wcscmp( name, IU_CONFIG_NAME_ASSERT_ENABLE ) == 0 )
                {
                    *assertEnable = ( intValue > 0 ) ? true : false;
                }
                else if( wcscmp( name, IU_CONFIG_NAME_LOG_LAYER_ENABLE ) == 0 )
                {
                    *logLayerEnable = intValue;
                }
                else if( wcscmp( name, IU_CONFIG_NAME_LOG_LEVEL ) == 0 )
                {
                    *logLevel = intValue;
                }
            }
        }

        fclose( file );
        file = NULL;
    }

} // extern "C"
