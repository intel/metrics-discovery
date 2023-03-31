/*========================== begin_copyright_notice ============================

Copyright (C) 2019-2023 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  iu_std.cpp

//     Abstract:   Instrumentation Utils implementation with Linux/Android specific functions

//  Note:          Some functions from the header may be unimplemented - they weren't
//                 needed in Linux version at the moment.

#include "iu_std.h"
#include "iu_debug.h"

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <wchar.h>

#if defined( __linux__ )
    #include <memory.h>
    #include <syslog.h>
#endif

extern "C"
{
    ///////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Instrumentation Utils Standard OS Specific Functions
    //
    // Function:
    //     iu_zeromem
    //
    // Description:
    //     Fills the given memory with zeros.
    //
    // Input:
    //     void*  dest     - memory
    //     size_t destSize - in bytes
    //
    // Output:
    //     bool - true if success
    //
    ///////////////////////////////////////////////////////////////////////////////
    bool iu_zeromem( void* dest, size_t destSize )
    {
        return memset( dest, 0, destSize ) != NULL;
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Instrumentation Utils Standard OS Specific Functions
    //
    // Function:
    //     iu_memset
    //
    // Description:
    //     Fills the first 'count' bytes of the memory 'dest' with 'value'
    //
    // Input:
    //     void*   dest  - momory to fill
    //     int32_t value - value to be written
    //     size_t  count - number of bytes to be written
    //
    // Output:
    //     bool - true if success
    //
    ///////////////////////////////////////////////////////////////////////////////
    bool iu_memset( void* dest, int32_t value, size_t count )
    {
        return memset( dest, value, count ) != NULL;
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Instrumentation Utils Standard OS Specific Functions
    //
    // Method:
    //     iu_memcpy_s
    //
    // Description:
    //     Check for NULLs and whether destination memory size is not too small.
    //
    // Input:
    //     void*       dest        - destination memory
    //     size_t      destSize    - size of the destination memory
    //     const void* src         - source memory
    //     size_t      count       - number of bytes to copy
    //
    // Output:
    //     bool - true if success
    //
    ///////////////////////////////////////////////////////////////////////////////
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

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Instrumentation Utils Standard OS Specific Functions
    //
    // Function:
    //     iu_memcmp
    //
    // Description:
    //     Compares the first given number of bytes of the two memory blocks pointed
    //     by 'ptr1' and 'ptr2'.
    //
    // Input:
    //     const void* ptr1      - memory block 1
    //     const void* ptr2      - memory block 2
    //     size_t bytesToCompare - number of bytes to compare
    //
    // Output:
    //     bool - true if equal
    //
    ///////////////////////////////////////////////////////////////////////////////
    bool iu_memcmp( const void* ptr1, const void* ptr2, size_t bytesToCompare )
    {
        return memcmp( ptr1, ptr2, bytesToCompare ) == 0;
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Instrumentation Utils Standard OS Specific Functions
    //
    // Method:
    //     iu_strcpy_s
    //
    // Description:
    //     Check for NULLs and whether destination memory size is not too small.
    //
    // Input:
    //     char*       destStr     - destination cstring
    //     size_t      destSize    - size of the destination cstring
    //     const char* srcStr      - source cstring
    //
    // Output:
    //     bool - true if success
    //
    ///////////////////////////////////////////////////////////////////////////////
    bool iu_strcpy_s( char* destStr, size_t destSize, const char* srcStr )
    {
        if( destStr == NULL || srcStr == NULL || ( strlen( srcStr ) + 1 ) > destSize )
        {
            IU_ASSERT( false );
            return false;
        }

        strcpy( destStr, srcStr );
        return true;
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Instrumentation Utils Standard OS Specific Functions
    //
    // Method:
    //     iu_strncpy_s
    //
    // Description:
    //     Check for NULLs and whether destination memory size is not too small. It appends
    //     null-terminating character to the end of destStr.
    //
    // Input:
    //     char*       destStr     - destination cstring
    //     size_t      destSize    - size of the destination cstring
    //     const char* srcStr      - source cstring
    //     size_t      count       - number of characters to copy
    //
    // Output:
    //     bool - true if success
    //
    ///////////////////////////////////////////////////////////////////////////////
    bool iu_strncpy_s( char* destStr, size_t destSize, const char* srcStr, size_t count )
    {
        if( destStr == NULL || srcStr == NULL || destSize == 0 )
        {
            IU_ASSERT( false );
            return false;
        }
        if( destSize <= count )
        {
            // Buffer too small
            IU_ASSERT( false );
            return false;
        }

        strncpy( destStr, srcStr, count );
        destStr[count] = '\0';
        return true;
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Instrumentation Utils Standard OS Specific Functions
    //
    // Method:
    //     iu_strcat_s
    //
    // Description:
    //     Check for NULLs and whether destination memory size is not too small.
    //
    // Input:
    //     char*       destStr     - destination cstring
    //     size_t      destSize    - size of the destination cstring
    //     const char* srcStr      - source cstring
    //
    // Output:
    //     bool - true if success
    //
    ///////////////////////////////////////////////////////////////////////////////
    bool iu_strcat_s( char* destStr, size_t destSize, const char* srcStr )
    {
        if( destStr == NULL || srcStr == NULL || destSize == 0 )
        {
            IU_ASSERT( false );
            return false;
        }
        size_t srcLen  = strlen( srcStr );
        size_t destLen = strlen( destStr );
        if( ( destSize - destLen ) <= srcLen )
        {
            // Dest too small
            IU_ASSERT( false );
            return false;
        }

        strcat( destStr, srcStr );
        return true;
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Instrumentation Utils Standard OS Specific Functions
    //
    // Method:
    //     iu_strtok_s
    //
    // Description:
    //     Calls strtok_r.
    //
    // Input:
    //     char*       str         - cstring
    //     const char* delimiters  - delimeter characters
    //     char**      context     - (out) used to store pointer location
    //
    // Output:
    //     char* - next token, or NULL if not found
    //
    ///////////////////////////////////////////////////////////////////////////////
    char* iu_strtok_s( char* str, const char* delimiters, char** context )
    {
        return strtok_r( str, delimiters, context );
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Instrumentation Utils Standard OS Specific Functions
    //
    // Function:
    //     iu_strnlen_s
    //
    // Description:
    //     Returns length of the given cstring, without '\0'.
    //
    // Input:
    //     const char* str     - cstring
    //     size_t      strSize - in bytes
    //
    // Output:
    //     size_t - length of a cstring in characters (without '\0')
    //
    ///////////////////////////////////////////////////////////////////////////////
    size_t iu_strnlen_s( const char* str, size_t strSize )
    {
        return ( str != NULL ) ? strnlen( str, strSize / sizeof( char ) )
                               : 0;
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Instrumentation Utils Standard OS Specific Functions
    //
    // Function:
    //     iu_strncmp
    //
    // Description:
    //     Compares up to 'count' characters of the cstring 'str1' to those of the 'str2'.
    //
    // Input:
    //     const char* str1  - cstring to compare
    //     const char* str2  - cstring to compare
    //     size_t      count - in characters
    //
    // Output:
    //     int32_t - relationship between strings. 0 means equal strings up to 'count' chars
    //
    ///////////////////////////////////////////////////////////////////////////////
    int32_t iu_strncmp( const char* str1, const char* str2, size_t count )
    {
        return strncmp( str1, str2, count );
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Instrumentation Utils Standard OS Specific Functions
    //
    // Function:
    //     iu_wstrcat_s
    //
    // Description:
    //     Appends 'srcWstr' to 'destWstr'.
    //
    // Input:
    //     wchar_t*       destWstr - null-terminated destination wide-char cstring
    //     size_t         destSize - size of the destination wide-char cstring (in bytes)
    //     const wchar_t* srcWstr  - null-terminated source wide-char cstring
    //
    // Output:
    //     bool - true if success
    //
    ///////////////////////////////////////////////////////////////////////////////
    bool iu_wstrcat_s( wchar_t* destWstr, size_t destSize, const wchar_t* srcWstr )
    {
        if( destWstr == NULL || srcWstr == NULL || destSize == 0 )
        {
            IU_ASSERT( false );
            return false;
        }

        size_t destSizeInWideChars = destSize / sizeof( wchar_t );
        size_t srcLen              = wcslen( srcWstr );
        size_t destLen             = wcslen( destWstr );
        if( ( destSizeInWideChars - destLen ) <= srcLen )
        {
            // Dest too small
            IU_ASSERT( false );
            return false;
        }

        return wcscat( destWstr, srcWstr ) != NULL;
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Instrumentation Utils Standard OS Specific Functions
    //
    // Function:
    //     iu_wstrncpy_s
    //
    // Description:
    //     Check for NULLs and whether destination memory size is not too small. It appends
    //     null-terminating character to the end of destWstr.
    //
    // Input:
    //     char*       destWstr - destination wide-char cstring
    //     size_t      destSize - size of the destination wide-char cstring in wide characters
    //     const char* srcWstr  - source wide-char cstring
    //     size_t      count    - number of wide-chars to copy
    //
    // Output:
    //     bool - true if success
    //
    ///////////////////////////////////////////////////////////////////////////////
    bool iu_wstrncpy_s( wchar_t* destWstr, size_t destSize, const wchar_t* srcWstr, size_t count )
    {
        if( destWstr == NULL || srcWstr == NULL || destSize == 0 )
        {
            IU_ASSERT( false );
            return false;
        }
        if( destSize <= count )
        {
            // Buffer too small
            IU_ASSERT( false );
            return false;
        }

        wcsncpy( destWstr, srcWstr, count );
        destWstr[count] = '\0';
        return true;
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Instrumentation Utils Standard OS Specific Functions
    //
    // Function:
    //     iu_wstrncat_s
    //
    // Description:
    //     Appends 'srcWstr' to 'destWstr' up to 'maxAppend' wide characters.
    //
    // Input:
    //     wchar_t*       destWstr  - null-terminated destination wide-char cstring
    //     size_t         destSize  - size of the destination wide-char cstring (in bytes)
    //     const wchar_t* srcWstr   - null-terminated source wide-char cstring
    //     size_t         maxAppend - max number of wide-chars to append
    //
    // Output:
    //     bool - true if success
    //
    ///////////////////////////////////////////////////////////////////////////////
    bool iu_wstrncat_s( wchar_t* destWstr, size_t destSize, const wchar_t* srcWstr, size_t maxAppend )
    {
        if( destWstr == NULL || srcWstr == NULL || destSize == 0 )
        {
            IU_ASSERT( false );
            return false;
        }

        return wcsncat( destWstr, srcWstr, maxAppend ) != NULL;
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Instrumentation Utils Standard OS Specific Functions
    //
    // Function:
    //     iu_wstrnlen
    //
    // Description:
    //     Returns length of the given wide-char cstring, without '\0'.
    //
    // Input:
    //     const wchar_t* wstr     - wide-char cstring
    //     size_t         wstrSize - in bytes
    //
    // Output:
    //     size_t - length of a cstring in characters (without '\0')
    //
    ///////////////////////////////////////////////////////////////////////////////
    size_t iu_wstrnlen( const wchar_t* wstr, size_t wstrSize )
    {
        if( wstr == NULL )
        {
            IU_ASSERT( false );
            return 0;
        }

        return wcsnlen( wstr, wstrSize / sizeof( wchar_t ) );
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Instrumentation Utils Standard OS Specific Functions
    //
    // Function:
    //     iu_wstrtombs
    //
    // Description:
    //     Converts wide-char cstring 'srcWstr' to standard cstring 'destStr'.
    //
    // Input:
    //     char*          destStr  - destination cstring
    //     size_t         destSize - 'destStr' buffer size
    //     const wchar_t* wstr2    - wide-char cstring to convert
    //     size_t         count    - in wide characters
    //
    // Output:
    //     size_t - number of converted chars
    //
    ///////////////////////////////////////////////////////////////////////////////
    size_t iu_wstrtombs_s( char* destStr, size_t destSize, const wchar_t* srcWstr, size_t count )
    {
        if( destStr == NULL || destSize == 0 || srcWstr == NULL )
        {
            IU_ASSERT( false );
            return 0;
        }
        if( destSize <= count )
        {
            // Buffer too small
            IU_ASSERT( false );
            return 0;
        }

        size_t convertedChars = wcstombs( destStr, srcWstr, count );
        if( convertedChars && convertedChars < destSize )
        {
            destStr[convertedChars - 1] = '\0'; // Add null-character at the end
        }
        return convertedChars;
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Instrumentation Utils Standard OS Specific Functions
    //
    // Function:
    //     iu_mbstowstr_s
    //
    // Description:
    //     Converts standard cstring 'srcStr' to wide-char cstring 'destWstr'.
    //
    // Input:
    //     wchar_t*       destWstr - destination cstring
    //     size_t         destSize - 'destStr' buffer size
    //     const char*    srcStr   - wide-char cstring to convert
    //     size_t         count    - in characters
    //
    // Output:
    //     size_t - number of converted chars
    //
    ///////////////////////////////////////////////////////////////////////////////
    size_t iu_mbstowstr_s( wchar_t* destWstr, size_t destSize, const char* srcStr, size_t count )
    {
        if( destWstr == NULL || destSize == 0 || srcStr == NULL )
        {
            IU_ASSERT( false );
            return 0;
        }
        if( destSize <= count )
        {
            // Buffer too small
            IU_ASSERT( false );
            return 0;
        }

        size_t convertedChars = mbstowcs( destWstr, srcStr, count );
        if( convertedChars && convertedChars < destSize )
        {
            destWstr[convertedChars - 1] = L'\0'; // Add null-character at the end
        }
        return convertedChars;
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Instrumentation Utils Standard OS Specific Functions
    //
    // Method:
    //     iu_sprintf_s
    //
    // Description:
    //     Check for NULLs and whether the destSize is not 0, then calls vsnprintf.
    //
    // Input:
    //     char*       destStr     - destination cstring
    //     size_t      destSize    - size of destination cstring
    //     const char* format      - format
    //     ...                     -
    //
    // Output:
    //     int32_t - number of characters written, or -1 if error
    //
    ///////////////////////////////////////////////////////////////////////////////
    int32_t iu_sprintf_s( char* destStr, size_t destSize, const char* format, ... )
    {
        if( destStr == NULL || format == NULL || destSize == 0 )
        {
            IU_ASSERT( false );
            return 0;
        }

        va_list ap;
        va_start( ap, format );
        int32_t ret = vsnprintf( destStr, destSize, format, ap );
        va_end( ap );

        return ret;
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Instrumentation Utils Standard OS Specific Functions
    //
    // Method:
    //     iu_snprintf
    //
    // Description:
    //     Write formatted data from argument list to a string.
    //
    // Input:
    //     char*       str    - destination cstring
    //     size_t      size   - size of destination cstring in bytes
    //     const char* format - format string
    //     ...                -
    //
    // Output:
    //     bool - true if no error occurred
    //
    ///////////////////////////////////////////////////////////////////////////////
    bool iu_snprintf( char* str, size_t size, const char* format, ... )
    {
        bool    bRet = false;
        va_list ap;

        va_start( ap, format );
        bRet = ( -1 != vsnprintf( str, size, format, ap ) );
        va_end( ap );

        return bRet;
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Instrumentation Utils Standard OS Specific Functions
    //
    // Method:
    //     iu_vsnprintf
    //
    // Description:
    //     Calls vsnprintf.
    //
    // Input:
    //     char*       str    - destination cstring
    //     size_t      size   - size of destination cstring in bytes
    //     const char* format - format string
    //     va_list     ap     - argument list
    //
    // Output:
    //     bool - true if any characters was copied
    //
    ///////////////////////////////////////////////////////////////////////////////
    bool iu_vsnprintf( char* str, size_t size, const char* format, va_list ap )
    {
        return ( vsnprintf( str, size, format, ap ) >= 0 );
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Instrumentation Utils Standard OS Specific Functions
    //
    // Function:
    //     iu_log
    //
    // Description:
    //     Prints debug log using OS frameworks.
    //
    // Input:
    //     const char* msg - message to print
    //
    ///////////////////////////////////////////////////////////////////////////////
    void iu_log( const char* msg )
    {
#if defined( __linux__ )
        syslog( LOG_USER | LOG_ERR, "%s", msg );
#endif
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Instrumentation Utils Standard OS Specific Functions
    //
    // Function:
    //     iu_printf
    //
    // Description:
    //     Debug log printf.
    //
    // Input:
    //     const char* msg    - message to print
    //     const bool  addEOL - add a new line sign at the end of the message
    //     const bool  flush  - flush buffer
    //
    ///////////////////////////////////////////////////////////////////////////////
    void iu_printf( const char* msg, const bool addEOL, const bool flush )
    {
        if( addEOL )
        {
            printf( "%s\n", msg );
        }
        else
        {
            printf( "%s", msg );
        }
        if( flush )
        {
            fflush( stdout );
        }
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Instrumentation Utils Standard OS Specific Functions
    //
    // Method:
    //     iu_fopen_s
    //
    // Description:
    //     Check for NULLs.
    //
    // Input:
    //     FILE**      pFile       - (out) pointer to the file
    //     const char* filename    - file name
    //     const char* mode        - open mode
    //
    // Output:
    //     bool - true if success
    //
    ///////////////////////////////////////////////////////////////////////////////
    bool iu_fopen_s( FILE** pFile, const char* filename, const char* mode )
    {
        if( pFile == NULL || filename == NULL || mode == NULL )
        {
            IU_ASSERT( false );
            return false;
        }

        *pFile = fopen( filename, mode );
        if( !( *pFile ) )
        {
            return false;
        }

        return true;
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Instrumentation Utils Standard OS Specific Functions
    //
    // Method:
    //     iu_fread_s
    //
    // Description:
    //     Check for NULLs and whether buffer size is not too small.
    //
    // Input:
    //     void*  buff     - pointer to the buffer
    //     size_t buffSize - buffer size
    //     size_t elemSize - size of each element
    //     size_t count    - count of elements to read
    //     FILE*  stream   - file
    //
    // Output:
    //     size_t - total number of elements successfully read
    //
    ///////////////////////////////////////////////////////////////////////////////
    size_t iu_fread_s( void* buff, size_t buffSize, size_t elemSize, size_t count, FILE* stream )
    {
        if( buff == NULL || stream == NULL || buffSize < ( elemSize * count ) )
        {
            IU_ASSERT( false );
            return 0;
        }

        return fread( buff, elemSize, count, stream );
    }

    ///////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Instrumentation Utils Standard OS Specific Functions
    //
    // Function:
    //     iu_dupenv_s
    //
    // Description:
    //     Duplicates env variable
    //
    // Input:
    //     const char* varName - environment variable name
    //
    // Output:
    //     Pointer to allocated env variable duplicate, or nullptr if not found
    //
    ///////////////////////////////////////////////////////////////////////////////
    const char* iu_dupenv_s( const char* varName )
    {
        const char* var = getenv( varName );
        if( var == nullptr )
        {
            return nullptr;
        }

        return strdup( var );
    }

} // extern "C"
