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

    File Name:  iu_std_linux.cpp

    Abstract:   Instrumentation Utils implementation with Linux/Android specific functions

\*****************************************************************************/
#include "iu_std.h"
#include "iu_debug.h"

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>

#if !defined(ANDROID) && defined(__linux__)
#include <memory.h>
#endif

extern "C" {

/*****************************************************************************\

Group:
    Instrumentation Utils Standard OS Specific Functions

Method:
    iu_memcpy_s

Description:
    Check for NULLs and whether destination memory size is not too small.

Input:
    void*       dest        - destination memory
    size_t      destSize    - size of the destination memory
    const void* src         - source memory
    size_t      count       - number of bytes to copy

Output:
    bool - true if success

\*****************************************************************************/
bool iu_memcpy_s( void* dest, size_t destSize, const void* src, size_t count )
{
    if( dest == NULL || src == NULL || count > destSize )
    {
        IU_ASSERT( false );
        return false;
    }

    memcpy( dest, src, count );
    return true;
}

/*****************************************************************************\

Group:
    Instrumentation Utils Standard OS Specific Functions

Method:
    iu_strcpy_s

Description:
    Check for NULLs and whether destination memory size is not too small.

Input:
    char*       destStr     - destination cstring
    size_t      destSize    - size of the destination cstring
    const char* srcStr      - source cstring

Output:
    bool - true if success

\*****************************************************************************/
bool iu_strcpy_s( char* destStr, size_t destSize, const char* srcStr )
{
    if( destStr == NULL || srcStr == NULL || (strlen(srcStr) + 1) > destSize )
    {
        IU_ASSERT( false );
        return false;
    }

    strcpy( destStr, srcStr );
    return true;
}

/*****************************************************************************\

Group:
    Instrumentation Utils Standard OS Specific Functions

Method:
    iu_strncpy_s

Description:
    Check for NULLs and whether destination memory size is not too small. It appends
    null-terminating character to the end of destStr.

Input:
    char*       destStr     - destination cstring
    size_t      destSize    - size of the destination cstring
    const char* srcStr      - source cstring
    size_t      count       - number of characters to copy

Output:
    bool - true if success

\*****************************************************************************/
bool iu_strncpy_s( char* destStr, size_t destSize, const char* srcStr, size_t count )
{
    if( destStr == NULL || srcStr == NULL || destSize == 0 )
    {
        IU_ASSERT( false );
        return false;
    }
    size_t srcLen = strlen(srcStr);
    if( count > srcLen )
    {
        count = srcLen;
    }
    if( destSize <= count )
    {
        // Buffer to small
        IU_ASSERT( false );
        return false;
    }

    strncpy( destStr, srcStr, count );
    destStr[ count ] = '\0';
    return true;
}

/*****************************************************************************\

Group:
    Instrumentation Utils Standard OS Specific Functions

Method:
    iu_strcat_s

Description:
    Check for NULLs and whether destination memory size is not too small.

Input:
    char*       destStr     - destination cstring
    size_t      destSize    - size of the destination cstring
    const char* srcStr      - source cstring

Output:
    bool - true if success

\*****************************************************************************/
bool iu_strcat_s( char* destStr, size_t destSize, const char* srcStr )
{
    if( destStr == NULL || srcStr == NULL || destSize == 0 )
    {
        IU_ASSERT( false );
        return false;
    }
    size_t srcLen  = strlen( srcStr );
    size_t destLen = strlen( destStr );
    if( (destSize - destLen) <= srcLen )
    {
        // Dest to small
        IU_ASSERT( false );
        return false;
    }

    strcat( destStr, srcStr );
    return true;
}

/*****************************************************************************\

Group:
    Instrumentation Utils Standard OS Specific Functions

Method:
    iu_strtok_s

Description:
    Calls strtok_r.

Input:
    char*       str         - cstring
    const char* delimiters  - delimeter characters
    char**      context     - (out) used to store pointer location

Output:
    char* - next token, or NULL if not found

\*****************************************************************************/
char* iu_strtok_s( char* str, const char* delimiters, char** context )
{
    return strtok_r( str, delimiters, context );
}

/*****************************************************************************\

Group:
    Instrumentation Utils Standard OS Specific Functions

Method:
    iu_strtoull

Description:
    Calls strtoull.

Input:
    const char* str     - cstring with number
    char**      endptr  - (out) pointer to the next character after numerical value
    int32_t     base    - numerical base

Output:
    uint64_t - converted value, 0 if error

\*****************************************************************************/
uint64_t iu_strtoull( const char* str, char** endptr, int32_t base )
{
    return strtoull( str, endptr, base );
}

/*****************************************************************************\

Group:
    Instrumentation Utils Standard OS Specific Functions

Method:
    iu_sprintf_s

Description:
    Check for NULLs and whether the destSize is not 0, then calls vsnprintf.

Input:
    char*       destStr     - destination cstring
    size_t      destSize    - size of destination cstring
    const char* format      - format
    ...                     - 

Output:
    int32_t - number of characters written, or -1 if error

\*****************************************************************************/
int32_t iu_sprintf_s( char* destStr, size_t destSize, const char * format, ... )
{
    if( destStr == NULL || format == NULL || destSize == 0 )
    {
        assert( false );
        return 0;
    }

    va_list ap;
    va_start( ap, format );
    int32_t ret = vsnprintf( destStr, destSize, format, ap );
    va_end( ap );

    return ret;
}

/*****************************************************************************\

Group:
    Instrumentation Utils Standard OS Specific Functions

Method:
    iu_fopen_s

Description:
    Check for NULLs.

Input:
    FILE**      pFile       - (out) pointer to the file
    const char* filename    - file name
    const char* mode        - open mode

Output:
    bool - true if success

\*****************************************************************************/
bool iu_fopen_s( FILE** pFile, const char* filename, const char* mode )
{
    if( pFile == NULL || filename == NULL || mode == NULL )
    {
        IU_ASSERT( false );
        return false;
    }

    *pFile = fopen( filename, mode );
    if( !(*pFile) )
    {
        return false;
    }

    return true;
}

/*****************************************************************************\

Group:
    Instrumentation Utils Standard OS Specific Functions

Method:
    iu_fread_s

Description:
    Check for NULLs and whether buffer size is not too small.

Input:
    void*  buff     - pointer to the buffer
    size_t buffSize - buffer size
    size_t elemSize - size of each element
    size_t count    - count of elements to read
    FILE*  stream   - file

Output:
    size_t - total number of elements successfully read

\*****************************************************************************/
size_t iu_fread_s( void* buff, size_t buffSize, size_t elemSize, size_t count, FILE* stream )
{
    if( buff == NULL || stream == NULL || buffSize < (elemSize * count) )
    {
        IU_ASSERT( false );
        return 0;
    }

    return fread( buff, elemSize, count, stream );
}

/*****************************************************************************\

Group:
    Instrumentation Utils Standard OS Specific Functions

Method:
    iu_snprintf

Description:
    Write formatted data from argument list to a string.

Input:
    char*       str    - destination cstring
    size_t      size   - size of destination cstring in bytes
    const char* format - format string
    ...                - 

Output:
    bool - true if no error occured

\*****************************************************************************/
bool iu_snprintf( char* str, size_t size, const char* format, ... )
{
    bool    bRet = false;
    va_list ap;

    va_start( ap, format );
    bRet = (-1 != vsnprintf( str, size, format, ap ));
    va_end( ap );

    return bRet;
}

/*****************************************************************************\

Group:
    Instrumentation Utils Standard OS Specific Functions

Method:
    iu_vsnprintf

Description:
    Calls vsnprintf.

Input:
    char*       str    - destination cstring
    size_t      size   - size of destination cstring in bytes
    const char* format - format string
    va_list     ap     - argument list

Output:
    bool - true if any characters was copied

\*****************************************************************************/
bool iu_vsnprintf( char* str, size_t size, const char* format, va_list ap )
{
    return ( vsnprintf( str, size, format, ap ) >= 0 );
}

/*****************************************************************************\

Group:
    Instrumentation Utils Standard OS Specific Functions

Method:
    iu_strlen

Description:
    Calls strnlen.

Input:
    const char* str     - cstring
    size_t      maxSize - in bytes

Output:
    size_t - length of a cstring in characters (without '\0')

\*****************************************************************************/
size_t iu_strlen( const char* str, size_t maxSize )
{
    return strnlen( str, maxSize / sizeof(char) );
}

} // extern "C"
