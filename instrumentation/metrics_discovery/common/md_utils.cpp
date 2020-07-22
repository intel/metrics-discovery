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

    File Name:  md_utils.cpp

    Abstract:   C++ metrics discovery utils implementation.

\*****************************************************************************/
#include "md_utils.h"
#include "md_internal.h"

#include <string.h>
#include <stdlib.h>

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{
/*****************************************************************************\

Group:
    Metrics Discovery Utils

Method:
    GetNamedSemaphore

Description:
    Creates / Opens semaphore and waits 1s if needed. *CC_OK* if wait was successful.

Input:
    const char* semaphoreName - semaphore name
    void**      semaphorePtr  - (out) pointer to the newly created sempahore

Output:
    TCompletionCode           - result, *CC_OK* means success

\*****************************************************************************/
TCompletionCode GetNamedSemaphore( const char* semaphoreName, void** semaphorePtr )
{
    MD_LOG_ENTER();
    MD_CHECK_PTR_RET( semaphoreName, CC_ERROR_INVALID_PARAMETER );
    MD_CHECK_PTR_RET( semaphorePtr, CC_ERROR_INVALID_PARAMETER );

    TCompletionCode retVal = CC_OK;

    if( !(*semaphorePtr) )
    {
        if( CDriverInterface::SemaphoreCreate( semaphoreName, semaphorePtr ) != CC_OK )
        {
            MD_LOG( LOG_ERROR, "semaphore create failed" );
            return CC_ERROR_GENERAL;
        }
    }

    TSemaphoreWaitResult result = CDriverInterface::SemaphoreWait( 1000L, *semaphorePtr ); // Wait 1 sec
    switch( result )
    {
        case WAIT_RESULT_SUCCESSFUL: // The semaphore object was signaled
            MD_LOG( LOG_DEBUG, "semaphore wait successful" );
            retVal = CC_OK;
            break;

        case WAIT_RESULT_TIMEOUT: // A time-out occurred
            MD_LOG( LOG_DEBUG, "semaphore wait timeout" );
            retVal = CC_ERROR_GENERAL;
            break;

        default:
            retVal = CC_ERROR_GENERAL;
            MD_LOG( LOG_ERROR, "semaphore wait error" );
            break;
    }

    MD_LOG_EXIT();
    return retVal;
}

/*****************************************************************************\

Group:
    Metrics Discovery Utils

Method:
    ReleaseNamedSemaphore

Description:
    Releases semaphore.

Input:
    void** semaphorePtr - pointer to the semaphore

Output:
    TCompletionCode     - result, *CC_OK* means success

\*****************************************************************************/
TCompletionCode ReleaseNamedSemaphore( void** semaphorePtr )
{
    MD_LOG_ENTER();

    if( CDriverInterface::SemaphoreRelease( semaphorePtr ) != CC_OK )
    {
        // Error while releasing semaphore
        MD_LOG( LOG_ERROR, "semaphore release failed" );
        return CC_ERROR_GENERAL;
    }

    MD_LOG_EXIT();
    return CC_OK;
}

/*****************************************************************************\

Group:
    Metrics Discovery Utils

Function:
    GetFileSize

Description:
    Obtains file size.

Output:
    int32_t - file size

\*****************************************************************************/
int32_t GetFileSize( FILE* pFile )
{
    int32_t lSize = 0;
    if( !fseek( pFile , 0 , SEEK_END ) )
    {
        lSize = ftell( pFile );
        rewind( pFile );
    }
    else
    {
        MD_LOG( LOG_ERROR, "fseek failed" );
    }

    return lSize;
}

/*****************************************************************************\

Group:
    Metrics Discovery Utils

Function:
    GetCopiedCString

Description:
    Allocates memory and copies given cstring. Copy is returned.
    It HAVE TO be deleted later.

Input:
    const char* cstring - cstring to be copied

Output:
    char*               - copied cstring

\*****************************************************************************/
char* GetCopiedCString( const char* cstring )
{
    if( cstring == NULL )
    {
        return NULL;
    }

    size_t strLength     = strlen( cstring ) + 1;
    char*  copiedCString = new (std::nothrow) char[strLength](); // Initialize all to 0
    MD_CHECK_PTR_RET( copiedCString, NULL );

    iu_strcpy_s( copiedCString, strLength, cstring );

    return copiedCString;
}

/*****************************************************************************\

Group:
    Metrics Discovery Utils

Function:
    GetCopiedByteArray

Description:
    Allocates memory and copies given byte array (of fixed size).
    It HAVE TO be deleted later.

Input:
    const TByteArray_1_0* byteArray - byte array to be copied

Output:
    TByteArray_1_0*                 - copied byteArray

\*****************************************************************************/
TByteArray_1_0* GetCopiedByteArray( const TByteArray_1_0* byteArray )
{
    if( byteArray == NULL )
    {
        return NULL;
    }

    TByteArray_1_0* copiedByteArray = new( std::nothrow ) TByteArray_1_0;
    MD_CHECK_PTR_RET( copiedByteArray, NULL );

    copiedByteArray->Size = byteArray->Size;
    copiedByteArray->Data = new( std::nothrow ) uint8_t[copiedByteArray->Size](); // Initialize all to 0
    if( copiedByteArray->Data == NULL )
    {
        MD_SAFE_DELETE( copiedByteArray );
        MD_LOG( LOG_DEBUG, "ERROR: null pointer: copiedByteArray->Data" );
        MD_LOG_EXIT();
        return NULL;
    }
    iu_memcpy_s( copiedByteArray->Data, copiedByteArray->Size, byteArray->Data, byteArray->Size );

    return copiedByteArray;
}

/*****************************************************************************\

Group:
    Metrics Discovery Utils

Function:
    GetCopiedCStringFromWcString

Description:
    Allocates memory and copies given wide-char cstring. Copy is returned.
    It HAVE TO be deleted later.

Input:
    const wchar_t* wcstring - wide-char cstring to be copied

Output:
    char*                   - copied cstring

\*****************************************************************************/
char* GetCopiedCStringFromWcString( const wchar_t* wcstring )
{
    if( wcstring == NULL )
    {
        return NULL;
    }

    size_t wstrLength    = wcslen( wcstring );
    char*  copiedCString = new (std::nothrow) char[wstrLength + 1](); // One more for '\0', initialize all to 0
    MD_CHECK_PTR_RET( copiedCString, NULL );

    iu_wstrtombs_s( copiedCString, wstrLength + 1, wcstring, wstrLength );

    return copiedCString;
}

/*****************************************************************************\
Group:
    Metrics Discovery Utils

Function:
    GetByteArrayFromMask

Description:
    Converts string into byte array

Input:
    const char* cstring - cstring to be converted

Output:
    TByteArray_1_0     - byte array

\*****************************************************************************/
TByteArray_1_0 GetByteArrayFromMask( const char* cstring )
{
    TByteArray_1_0 byteArray = {};

    if( cstring != NULL )
    {
        size_t strLength = strlen( cstring );
        if( strncmp( cstring, "0x", 2 ) == 0 )
        {
            // skip hex marker, if exist
            strLength -= 2;
            cstring += 2;
        }

        byteArray.Data = new( std::nothrow ) uint8_t[strLength](); // Initialize all to 0
        MD_CHECK_PTR_RET( byteArray.Data, byteArray );
        byteArray.Size = strLength;

        char strChar[2]; // container for single character + /0
        for( size_t i = 0; i < byteArray.Size; i++ )
        {
            iu_snprintf( strChar, sizeof( strChar ), "%c", cstring[i] );
            byteArray.Data[i] = (uint8_t) strtol( strChar, NULL, 16 );
        }
    }

    return byteArray;
}

/*****************************************************************************\

Group:
    Metrics Discovery Utils

Function:
    WriteCStringToFile

Description:
    Writes null-character ended cstring to file.

Input:
    const char* cstring - cstring to be written
    FILE* pFile         - handle to file

\*****************************************************************************/
void WriteCStringToFile( const char* cstring, FILE* pFile )
{
    if( pFile == NULL )
    {
        MD_ASSERT( pFile != NULL );
        return;
    }
    const char* cstr = ( cstring == NULL ) ? "" : cstring;

    size_t strLength = strlen( cstr ) + 1;
    fwrite( cstr, 1, strLength, pFile );
}

/*****************************************************************************\

Group:
    Metrics Discovery Utils

Function:
    WriteTTypedValueToFile

Description:
    Writes TTypedValue struct to file.

Input:
    TTypedValue_1_0* typedValue - TypedValue to be written
    FILE* pFile                 - handle to file

\*****************************************************************************/
void WriteTTypedValueToFile( TTypedValue_1_0* typedValue, FILE* pFile )
{
    if( pFile == NULL || typedValue == NULL )
    {
        MD_ASSERT( pFile != NULL );
        MD_ASSERT( typedValue != NULL );
        return;
    }

    fwrite( &typedValue->ValueType, sizeof( typedValue->ValueType ), 1, pFile );
    if( typedValue->ValueType == VALUE_TYPE_UINT32 )
    {
        fwrite( &typedValue->ValueUInt32, sizeof( typedValue->ValueUInt32 ), 1, pFile );
    }
    else if( typedValue->ValueType == VALUE_TYPE_UINT64 )
    {
        fwrite( &typedValue->ValueUInt64, sizeof( typedValue->ValueUInt64 ), 1, pFile );
    }
    else if( typedValue->ValueType == VALUE_TYPE_FLOAT )
    {
        fwrite( &typedValue->ValueFloat, sizeof( typedValue->ValueFloat ), 1, pFile );
    }
    else if( typedValue->ValueType == VALUE_TYPE_BOOL )
    {
        fwrite( &typedValue->ValueBool, sizeof( typedValue->ValueBool ), 1, pFile );
    }
    else if( typedValue->ValueType == VALUE_TYPE_CSTRING )
    {
        WriteCStringToFile( typedValue->ValueCString, pFile );
    }
    else
    {
        MD_ASSERT( false );
        return;
    }
}

/*****************************************************************************\

Group:
    Metrics Discovery Utils

Function:
    ReadCStringFromFileBuffer

Description:
    Reads null-character ended cstring from file buffer. Function DOES NOT COPY the cstring.
    It only advances the fileBuffer pointer and returns a pointer to cstring in buffer.

Input:
    unsigned char** fileBuffer  - pointer to the binary file buffer array

Output:
    char*                       - pointer to the cstring in buffer (not copied)

\*****************************************************************************/
char* ReadCStringFromFileBuffer( unsigned char** fileBuffer )
{
    if( fileBuffer == NULL || *fileBuffer == NULL )
    {
        MD_ASSERT( fileBuffer != NULL );
        MD_ASSERT( *fileBuffer != NULL );
        return (char*)"";
    }

    char* cstring = (char*)*fileBuffer;
    size_t cstringLength = strlen( cstring );

    if ( cstringLength == 0 )
    {
        cstring = (char*)"";
    }

    *fileBuffer += cstringLength + 1;

    return cstring;
}

/*****************************************************************************\

Group:
    Metrics Discovery Utils

Function:
    ReadUInt32FromFileBuffer

Description:
    Reads uint32_t from file buffer.

Input:
    unsigned char** fileBuffer  - pointer to the binary file buffer array

Output:
    uint32_t                    - read uint32_t

\*****************************************************************************/
uint32_t ReadUInt32FromFileBuffer( unsigned char** fileBuffer )
{
    if( fileBuffer == NULL || *fileBuffer == NULL )
    {
        MD_ASSERT( fileBuffer != NULL );
        MD_ASSERT( *fileBuffer != NULL );
        return 0;
    }

    uint32_t value = *( (uint32_t*)*fileBuffer );
    *fileBuffer += sizeof( uint32_t );

    return value;
}

/*****************************************************************************\

Group:
    Metrics Discovery Utils

Function:
    ReadInt64FromFileBuffer

Description:
    Reads int64_t int from file buffer.

Input:
    unsigned char** fileBuffer  - pointer to the binary file buffer array

Output:
    int64_t                     - read int64_t

\*****************************************************************************/
int64_t ReadInt64FromFileBuffer( unsigned char** fileBuffer )
{
    if( fileBuffer == NULL || *fileBuffer == NULL )
    {
        MD_ASSERT( fileBuffer != NULL );
        MD_ASSERT( *fileBuffer != NULL );
        return 0;
    }

    int64_t value = *( (int64_t*)*fileBuffer );
    *fileBuffer += sizeof( int64_t );

    return value;
}

/*****************************************************************************\

Group:
    Metrics Discovery Utils

Function:
    ReadTTypedValueFromFileBuffer

Description:
    Reads TTypedValue struct from file buffer.

Input:
    unsigned char** fileBuffer  - pointer to the binary file buffer array

Output:
    TTypedValue_1_0             - read TTypedValue

\*****************************************************************************/
TTypedValue_1_0 ReadTTypedValueFromFileBuffer( unsigned char** fileBuffer )
{
    TTypedValue_1_0 typedValue;
    typedValue.ValueType    = VALUE_TYPE_UINT32;
    typedValue.ValueUInt32  = 0;

    if( fileBuffer == NULL || *fileBuffer == NULL )
    {
        MD_ASSERT( fileBuffer != NULL );
        MD_ASSERT( *fileBuffer != NULL );
        return typedValue;
    }

    typedValue.ValueType = ( *(TValueType*)*fileBuffer );
    *fileBuffer += sizeof( TValueType );

    if( typedValue.ValueType == VALUE_TYPE_UINT32 )
    {
        typedValue.ValueUInt32 = *( (uint32_t*)*fileBuffer );
        *fileBuffer += sizeof( uint32_t );
    }
    else if( typedValue.ValueType == VALUE_TYPE_UINT64 )
    {
        typedValue.ValueUInt64 = *( (uint64_t*)*fileBuffer );
        *fileBuffer += sizeof( uint64_t );
    }
    else if( typedValue.ValueType == VALUE_TYPE_FLOAT )
    {
        typedValue.ValueFloat = *( (float*)*fileBuffer );
        *fileBuffer += sizeof( float );
    }
    else if( typedValue.ValueType == VALUE_TYPE_BOOL )
    {
        typedValue.ValueBool = *( (bool*)*fileBuffer );
        *fileBuffer += sizeof( bool );
    }
    else if( typedValue.ValueType == VALUE_TYPE_CSTRING )
    {
        typedValue.ValueCString = ReadCStringFromFileBuffer( fileBuffer );
        *fileBuffer += sizeof( bool );
    }
    else
    {
        MD_ASSERT( false );
    }

    return typedValue;
}

/*****************************************************************************\

Group:
    Metrics Discovery Utils

Function:
    ReadEquationStringFromFile

Description:
    Reads equation string from file buffer.

Input:
    unsigned char** fileBuffer  - pointer to the binary file buffer array

Output:
    char*                       - if not empty, pointer to the cstring in buffer (not copied)

\*****************************************************************************/
char* ReadEquationStringFromFile( unsigned char** fileBuffer )
{
    if( fileBuffer == NULL || *fileBuffer == NULL )
    {
        MD_ASSERT( fileBuffer != NULL );
        MD_ASSERT( *fileBuffer != NULL );
        return (char*)"";
    }

    char* ret = NULL;

    if( ( **fileBuffer ) == 0xFF )
    {
        ret = (char*)"";
        ( *fileBuffer )++;
    }
    else
    {
        ret = ReadCStringFromFileBuffer( fileBuffer );
    }

    return ret;
}

// Explicit Instantiation
template class Vector<TGlobalSymbol*>;
template class Vector<CConcurrentGroup*>;
template class Vector<CMetricSet*>;
template class Vector<CMetric*>;
template class Vector<CInformation*>;
template class Vector<TRegister>;
template class Vector<CEquationElementInternal>;
template class Vector<const char*>;
template class List<uint64_t>;
template class List<CMetric*>;

}