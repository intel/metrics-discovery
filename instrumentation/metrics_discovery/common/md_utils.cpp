/*========================== begin_copyright_notice ============================

Copyright (C) 2019-2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_utils.cpp

//     Abstract:   C++ metrics discovery utils implementation.

#include "md_utils.h"
#include "md_adapter.h"
#include "md_concurrent_group.h"
#include "md_driver_ifc.h"
#include "md_equation.h"
#include "md_information.h"
#include "md_metric.h"
#include "md_metric_set.h"
#include "md_register_set.h"

#include <cmath>
#include <cstring>
#include <cstdlib>
#include <sstream>

namespace MetricsDiscoveryInternal
{
    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Method:
    //     WriteEquationToFile
    //
    // Description:
    //     Writes CEquation class to file. If it's equal to null 0xFF will be written.
    //
    // Input:
    //     CEquation*     equation   - CEquation to be written
    //     FILE*          metricFile - handle to metric file
    //     const uint32_t adapterId  - adapter id for purpose of logging
    //
    // Output:
    //     TCompletionCode           - result
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode WriteEquationToFile( CEquation* equation, FILE* metricFile, const uint32_t adapterId )
    {
        if( metricFile == nullptr )
        {
            MD_ASSERT_A( adapterId, metricFile != nullptr );
            return CC_ERROR_INVALID_PARAMETER;
        }

        TCompletionCode ret = CC_OK;

        if( equation )
        {
            ret = equation->WriteCEquationToFile( metricFile );
        }
        else
        {
            fputc( 0xFF, metricFile );
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Method:
    //     SetDeltaFunction
    //
    // Description:
    //     Sets the delta function from parsed string.
    //
    // Input:
    //     const char*         equationString - equation string, could be empty
    //     TDeltaFunction_1_0* deltaFunction  - (out) delta function
    //     const uint32_t      adapterId      - adapter id for purpose of logging
    //
    // Output:
    //     TCompletionCode             - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode SetDeltaFunction( const char* equationString, TDeltaFunction_1_0* deltaFunction, const uint32_t adapterId )
    {
        if( equationString == nullptr || strcmp( equationString, "" ) == 0 )
        {
            deltaFunction->FunctionType = DELTA_FUNCTION_NULL;
            return CC_OK;
        }
        if( strncmp( equationString, "DELTA", sizeof( "DELTA" ) - 1 ) == 0 )
        {
            deltaFunction->FunctionType = DELTA_N_BITS;
            if( equationString[5] == ' ' )
            {
                deltaFunction->BitsCount = strtoul( (char*) &equationString[6], nullptr, 10 );
            }
            else
            {
                deltaFunction->BitsCount = strtoul( (char*) &equationString[5], nullptr, 10 );
            }
            return CC_OK;
        }
        if( strcmp( equationString, "OR" ) == 0 )
        {
            deltaFunction->FunctionType = DELTA_BOOL_OR;
            return CC_OK;
        }
        if( strcmp( equationString, "XOR" ) == 0 )
        {
            deltaFunction->FunctionType = DELTA_BOOL_XOR;
            return CC_OK;
        }
        if( strcmp( equationString, "PREV" ) == 0 )
        {
            deltaFunction->FunctionType = DELTA_GET_PREVIOUS;
            return CC_OK;
        }
        if( strcmp( equationString, "LAST" ) == 0 )
        {
            deltaFunction->FunctionType = DELTA_GET_LAST;
            return CC_OK;
        }
        if( strcmp( equationString, "NS_TIME" ) == 0 )
        {
            deltaFunction->FunctionType = DELTA_NS_TIME;
            return CC_OK;
        }

        MD_LOG_A( adapterId, LOG_ERROR, "Unknown delta function: %s", equationString );
        return CC_ERROR_GENERAL;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Method:
    //     SetEquation
    //
    // Description:
    //     Sets the given equation.
    //
    // Input:
    //     CMetricsDevice* device         - metric device
    //     CEquation*&     equation       - pointer to the equation to be set
    //     const char*     equationString - euqation string, could be empty or null
    //
    // Output:
    //     TCompletionCode            - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode SetEquation( CMetricsDevice* device, CEquation*& equation, const char* equationString )
    {
        const uint32_t  adapterId = OBTAIN_ADAPTER_ID( device );
        TCompletionCode ret       = CC_OK;

        MD_CHECK_PTR_RET_A( adapterId, device, CC_ERROR_INVALID_PARAMETER );

        // Delete previous equation if any
        MD_SAFE_DELETE( equation );

        // nullptr is fine condition for "" equations
        if( equationString != nullptr && strcmp( equationString, "" ) != 0 )
        {
            equation = new( std::nothrow ) CEquation( device );
            if( equation == nullptr )
            {
                ret = CC_ERROR_NO_MEMORY;
            }
            else if( !equation->ParseEquationString( equationString ) )
            {
                MD_SAFE_DELETE( equation );
                ret = CC_ERROR_GENERAL;
            }
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Method:
    //     GetNamedSemaphore
    //
    // Description:
    //     Creates / Opens semaphore and waits 1s if needed. *CC_OK* if wait was successful.
    //
    // Input:
    //     const char*    semaphoreName - semaphore name
    //     void**         semaphorePtr  - (out) pointer to the newly created sempahore
    //     const uint32_t adapterId     - adapter id for purpose of logging
    //
    // Output:
    //     TCompletionCode           - result, *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode GetNamedSemaphore( const char* semaphoreName, void** semaphorePtr, const uint32_t adapterId )
    {
        MD_LOG_ENTER_A( adapterId );
        MD_CHECK_PTR_RET_A( adapterId, semaphoreName, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, semaphorePtr, CC_ERROR_INVALID_PARAMETER );

        TCompletionCode retVal = CC_OK;

        if( !( *semaphorePtr ) )
        {
            if( CDriverInterface::SemaphoreCreate( semaphoreName, semaphorePtr, IU_ADAPTER_ID_UNKNOWN ) != CC_OK )
            {
                MD_LOG_A( adapterId, LOG_ERROR, "semaphore create failed" );
                return CC_ERROR_GENERAL;
            }
        }

        TSemaphoreWaitResult result = CDriverInterface::SemaphoreWait( 1000L, *semaphorePtr, IU_ADAPTER_ID_UNKNOWN ); // Wait 1 sec
        switch( result )
        {
            case WAIT_RESULT_SUCCESSFUL: // The semaphore object was signaled
                MD_LOG_A( adapterId, LOG_DEBUG, "semaphore wait successful" );
                retVal = CC_OK;
                break;

            case WAIT_RESULT_TIMEOUT: // A time-out occurred
                MD_LOG_A( adapterId, LOG_DEBUG, "semaphore wait timeout" );
                retVal = CC_ERROR_GENERAL;
                break;

            default:
                retVal = CC_ERROR_GENERAL;
                MD_LOG_A( adapterId, LOG_ERROR, "semaphore wait error" );
                break;
        }

        MD_LOG_EXIT_A( adapterId );
        return retVal;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Method:
    //     ReleaseNamedSemaphore
    //
    // Description:
    //     Releases semaphore.
    //
    // Input:
    //     void**         semaphorePtr - pointer to the semaphore
    //     const uint32_t adapterId    - adapter id for purpose of logging
    //
    // Output:
    //     TCompletionCode     - result, *CC_OK* means success
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode ReleaseNamedSemaphore( void** semaphorePtr, const uint32_t adapterId )
    {
        MD_LOG_ENTER_A( adapterId );

        if( CDriverInterface::SemaphoreRelease( semaphorePtr, IU_ADAPTER_ID_UNKNOWN ) != CC_OK )
        {
            // Error while releasing semaphore
            MD_LOG_A( adapterId, LOG_ERROR, "semaphore release failed" );
            return CC_ERROR_GENERAL;
        }

        MD_LOG_EXIT_A( adapterId );
        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     GetFileSize
    //
    // Description:
    //     Obtains file size.
    //
    // Input
    //     FILE*          pFile     - handle to file
    //     const uint32_t adapterId - adapter id for purpose of logging
    //
    // Output:
    //     int32_t - file size
    //
    //////////////////////////////////////////////////////////////////////////////
    int32_t GetFileSize( FILE* pFile, const uint32_t adapterId )
    {
        int32_t lSize = 0;
        if( !fseek( pFile, 0, SEEK_END ) )
        {
            lSize = ftell( pFile );
            rewind( pFile );
        }
        else
        {
            MD_LOG_A( adapterId, LOG_ERROR, "fseek failed" );
        }

        return lSize;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     GetCopiedByteArray
    //
    // Description:
    //     Allocates memory and copies given byte array (of fixed size).
    //     It HAVE TO be deleted later.
    //
    // Input:
    //     const TByteArrayLatest* byteArray - byte array to be copied
    //     const uint32_t          adapterId - adapter id for purpose of logging
    //
    // Output:
    //     TByteArrayLatest*                 - copied byte array
    //
    //////////////////////////////////////////////////////////////////////////////
    TByteArrayLatest* GetCopiedByteArray( const TByteArrayLatest* byteArray, const uint32_t adapterId )
    {
        MD_CHECK_PTR_RET_A( adapterId, byteArray, nullptr );
        MD_CHECK_PTR_RET_A( adapterId, byteArray->Data, nullptr );

        TByteArrayLatest* copiedByteArray = new( std::nothrow ) TByteArrayLatest();
        MD_CHECK_PTR_RET_A( adapterId, copiedByteArray, nullptr );

        copiedByteArray->Size = byteArray->Size;
        copiedByteArray->Data = new( std::nothrow ) uint8_t[copiedByteArray->Size](); // Initialize all to 0
        if( copiedByteArray->Data == nullptr )
        {
            MD_SAFE_DELETE( copiedByteArray );
            MD_LOG_A( adapterId, LOG_DEBUG, "ERROR: null pointer: copiedByteArray->Data" );
            MD_LOG_EXIT_A( adapterId );
            return nullptr;
        }

        iu_memcpy_s( copiedByteArray->Data, copiedByteArray->Size, byteArray->Data, byteArray->Size );

        return copiedByteArray;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     GetByteArrayFromCStringMask
    //
    // Description:
    //     Converts string into byte array
    //
    // Input:
    //     const char*    cstring   - cstring to be converted
    //     const uint32_t adapterId - adapter id for purpose of logging
    //
    // Output:
    //     TByteArrayLatest         - byte array
    //
    //////////////////////////////////////////////////////////////////////////////
    TByteArrayLatest GetByteArrayFromCStringMask( const char* cstring, const uint32_t adapterId )
    {
        auto byteArray = TByteArrayLatest{ 0, nullptr };

        MD_CHECK_PTR_RET_A( adapterId, cstring, byteArray );

        size_t strLength = strlen( cstring );
        if( strncmp( cstring, "0x", 2 ) == 0 )
        {
            // Skip hex marker, if exist
            strLength -= 2;
            cstring += 2;
        }

        bool strLengthIsOdd = false;
        if( strLength % 2 != 0 )
        {
            strLengthIsOdd = true;
            strLength++;
        }

        byteArray.Data = new( std::nothrow ) uint8_t[strLength / 2](); // Initialize all to 0
        MD_CHECK_PTR_RET_A( adapterId, byteArray.Data, byteArray );
        byteArray.Size = strLength / 2;

        char           strChar[3]; // container for two characters (one byte) + '/0'
        const uint32_t strCharLength = sizeof( strChar );

        for( uint32_t i = 0; i < byteArray.Size; ++i )
        {
            uint32_t j = 0;
            if( strLengthIsOdd )
            {
                strChar[0]     = '0';
                j              = 1;
                strLengthIsOdd = false;
            }

            for( ; j < strCharLength - 1; ++j )
            {
                strChar[j] = cstring[0];
                cstring++;
            }

            strChar[strCharLength - 1] = '\0';

            byteArray.Data[byteArray.Size - i - 1] = (uint8_t) strtol( strChar, nullptr, 16 );
        }

        return byteArray;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     GetByteArrayFromPlatformType
    //
    // Description:
    //     Converts uint32_t (TPlatformType) to byte array pointer.
    //
    // Input:
    //     const uint32_t platformType       - platform type to be converted
    //     const uint32_t byteArraySize      - byte array size
    //     const uint32_t adapterId          - adapter id
    //
    // Output:
    //     TByteArrayLatest*                 - created byteArray
    //
    //////////////////////////////////////////////////////////////////////////////
    TByteArrayLatest* GetByteArrayFromPlatformType( const uint32_t platformType, const uint32_t byteArraySize, const uint32_t adapterId )
    {
        if( byteArraySize == 0 )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "ERROR: Incorrect byte array size" );
            return nullptr;
        }

        auto platformMaskByteArray = new( std::nothrow ) TByteArrayLatest();
        MD_CHECK_PTR_RET_A( adapterId, platformMaskByteArray, nullptr );

        platformMaskByteArray->Size = byteArraySize;
        platformMaskByteArray->Data = new( std::nothrow ) uint8_t[platformMaskByteArray->Size]();

        if( platformMaskByteArray->Data == nullptr )
        {
            MD_SAFE_DELETE( platformMaskByteArray );

            MD_LOG_A( adapterId, LOG_DEBUG, "ERROR: null pointer: platformMaskByteArray->Data" );
            MD_LOG_EXIT_A( adapterId );
            return nullptr;
        }

        iu_memcpy_s( platformMaskByteArray->Data, platformMaskByteArray->Size, &platformType, sizeof( uint32_t ) );

        return platformMaskByteArray;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     GetPlatformTypeFromByteArray
    //
    // Description:
    //     Converts platform mask byte array to uint32_t (TPlatformType).
    //
    // Input:
    //     const TByteArrayLatest* platformMask - platform mask byte array
    //     const uint32_t          adapterId    - adapter id
    //
    // Output:
    //     TByteArrayLatest*                    - created byteArray
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t GetPlatformTypeFromByteArray( const TByteArrayLatest* platformMask, const uint32_t adapterId )
    {
        uint32_t platform = static_cast<uint32_t>( PLATFORM_UNKNOWN );
        MD_CHECK_PTR_RET_A( adapterId, platformMask, platform );

        if( platformMask->Size == 0 )
        {
            return platform;
        }

        for( uint32_t i = sizeof( uint32_t ); i < platformMask->Size; ++i )
        {
            if( platformMask->Data[i] != 0 )
            {
                return static_cast<uint32_t>( PLATFORM_FUTURE ); // Platform mask is bigger than uint32_t
            }
        }

        iu_memcpy_s( &platform, sizeof( platform ), platformMask->Data, sizeof( platform ) );

        return platform;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     GetStringFromByteArray
    //
    // Description:
    //     Converts byte array into std::string
    //
    // Input:
    //     const TByteArrayLatest* byteArray - byte array to be converted
    //     const uint32_t adapterId          - adapter id for purpose of logging
    //
    // Output:
    //     std::string                       - output string
    //
    //////////////////////////////////////////////////////////////////////////////
    std::string GetStringFromByteArray( const TByteArrayLatest* byteArray, const uint32_t adapterId )
    {
        MD_CHECK_PTR_RET_A( adapterId, byteArray, "" );
        MD_CHECK_PTR_RET_A( adapterId, byteArray->Data, "" );

        if( byteArray->Size == 0 )
        {
            MD_LOG_A( adapterId, LOG_WARNING, "WARNING: Byte array has size 0" );
            return "";
        }

        std::ostringstream stream;
        stream << "0x";

        for( uint32_t i = byteArray->Size; i > 0; --i )
        {
            // + is needed to print number instead of ASCII
            stream << std::hex << +byteArray->Data[i - 1];
        }

        return stream.str();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     GetCopiedCString
    //
    // Description:
    //     Allocates memory and copies given cstring. Copy is returned.
    //     It HAVE TO be deleted later.
    //
    // Input:
    //     const char*    cstring   - cstring to be copied
    //     const uint32_t adapterId - adapter id for purpose of logging
    //
    // Output:
    //     char*               - copied cstring
    //
    //////////////////////////////////////////////////////////////////////////////
    char* GetCopiedCString( const char* cstring, const uint32_t adapterId )
    {
        if( cstring == nullptr )
        {
            return nullptr;
        }

        size_t strLength     = strlen( cstring ) + 1;
        char*  copiedCString = new( std::nothrow ) char[strLength](); // Initialize all to 0
        MD_CHECK_PTR_RET_A( adapterId, copiedCString, nullptr );

        iu_strcpy_s( copiedCString, strLength, cstring );

        return copiedCString;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     GetCopiedCStringFromWcString
    //
    // Description:
    //     Allocates memory and copies given wide-char cstring. Copy is returned.
    //     It HAVE TO be deleted later.
    //
    // Input:
    //     const wchar_t* wcstring  - wide-char cstring to be copied
    //     const uint32_t adapterId - adapter id for purpose of logging
    //
    // Output:
    //     char*                   - copied cstring
    //
    //////////////////////////////////////////////////////////////////////////////
    char* GetCopiedCStringFromWcString( const wchar_t* wcstring, const uint32_t adapterId )
    {
        if( wcstring == nullptr )
        {
            return nullptr;
        }

        size_t wstrLength    = wcslen( wcstring );
        char*  copiedCString = new( std::nothrow ) char[wstrLength + 1](); // One more for '\0', initialize all to 0
        MD_CHECK_PTR_RET_A( adapterId, copiedCString, nullptr );

        iu_wstrtombs_s( copiedCString, wstrLength + 1, wcstring, wstrLength );

        return copiedCString;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     GetCStringFromStringView
    //
    // Description:
    //     Safety converts string_view to const char*.
    //
    // Input:
    //     std::string_view stringView - string view to be converted
    //
    // Output:
    //     const char*                 - converted string view
    //
    //////////////////////////////////////////////////////////////////////////////
    const char* GetCStringFromStringView( std::string_view stringView )
    {
        return ( "%.*s", stringView.length(), stringView.data() );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     WriteByteArrayToFile
    //
    // Description:
    //     Writes byte array to file.
    //
    // Input:
    //     const TByteArrayLatest* byteArray    - byte array to be written
    //     FILE*                   pFile        - handle to file
    //     const uint32_t          adapterId    - adapter id for purpose of logging
    //
    //////////////////////////////////////////////////////////////////////////////
    void WriteByteArrayToFile( const TByteArrayLatest* byteArray, FILE* pFile, const uint32_t adapterId )
    {
        MD_CHECK_PTR_RET_A( adapterId, byteArray, MD_EMPTY );
        MD_CHECK_PTR_RET_A( adapterId, byteArray->Data, MD_EMPTY );
        MD_CHECK_PTR_RET_A( adapterId, pFile, MD_EMPTY );

        const uint32_t magicNumber = MD_BYTE_ARRAY_MAGIC_NUMBER;

        fwrite( &magicNumber, sizeof( magicNumber ), 1, pFile );
        fwrite( &byteArray->Size, sizeof( byteArray->Size ), 1, pFile );
        fwrite( byteArray->Data, 1, byteArray->Size, pFile );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     WriteCStringToFile
    //
    // Description:
    //     Writes null-character ended cstring to file.
    //
    // Input:
    //     const char* cstring      - cstring to be written
    //     FILE* pFile              - handle to file
    //     const uint32_t adapterId - adapter id for purpose of logging
    //
    //////////////////////////////////////////////////////////////////////////////
    void WriteCStringToFile( const char* cstring, FILE* pFile, const uint32_t adapterId )
    {
        if( pFile == nullptr )
        {
            MD_ASSERT_A( adapterId, pFile != nullptr );
            return;
        }
        const char* cstr = ( cstring == nullptr ) ? "" : cstring;

        size_t strLength = strlen( cstr ) + 1;
        fwrite( cstr, 1, strLength, pFile );
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     WriteTTypedValueToFile
    //
    // Description:
    //     Writes TTypedValue struct to file.
    //
    // Input:
    //     TTypedValue_1_0* typedValue - TypedValue to be written
    //     FILE*            pFile      - handle to file
    //     const uint32_t   adapterId  - adapter id for purpose of logging
    //
    //////////////////////////////////////////////////////////////////////////////
    void WriteTTypedValueToFile( TTypedValue_1_0* typedValue, FILE* pFile, const uint32_t adapterId )
    {
        if( pFile == nullptr || typedValue == nullptr )
        {
            MD_ASSERT_A( adapterId, pFile != nullptr );
            MD_ASSERT_A( adapterId, typedValue != nullptr );
            return;
        }

        fwrite( &typedValue->ValueType, sizeof( typedValue->ValueType ), 1, pFile );

        switch( typedValue->ValueType )
        {
            case VALUE_TYPE_UINT32:
                fwrite( &typedValue->ValueUInt32, sizeof( typedValue->ValueUInt32 ), 1, pFile );
                break;

            case VALUE_TYPE_UINT64:
                fwrite( &typedValue->ValueUInt64, sizeof( typedValue->ValueUInt64 ), 1, pFile );
                break;

            case VALUE_TYPE_FLOAT:
                fwrite( &typedValue->ValueFloat, sizeof( typedValue->ValueFloat ), 1, pFile );
                break;

            case VALUE_TYPE_BOOL:
                fwrite( &typedValue->ValueBool, sizeof( typedValue->ValueBool ), 1, pFile );
                break;

            case VALUE_TYPE_CSTRING:
                MD_LOG_A( adapterId, LOG_DEBUG, "calling WriteCStringToFile()..." );
                WriteCStringToFile( typedValue->ValueCString, pFile, adapterId );
                break;

            case VALUE_TYPE_BYTEARRAY:
                MD_LOG_A( adapterId, LOG_DEBUG, "calling WriteByteArrayToFile()..." );
                WriteByteArrayToFile( typedValue->ValueByteArray, pFile, adapterId );
                break;

            default:
                MD_ASSERT_A( adapterId, false );
                break;
        }
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     ReadByteArrayFromFileBuffer
    //
    // Description:
    //     Read byte array from file buffer.
    //
    // Input:
    //     uint8_t**       fileBuffer - pointer to the binary file buffer array
    //     const uint32_t  adapterId  - adapter id for purpose of logging
    //
    // Output:
    //     TByteArrayLatest*          - pointer to the created TByteArrayLatest object
    //
    //////////////////////////////////////////////////////////////////////////////
    TByteArrayLatest* ReadByteArrayFromFileBuffer( uint8_t** fileBuffer, const uint32_t adapterId )
    {
        MD_CHECK_PTR_RET_A( adapterId, fileBuffer, nullptr );
        MD_CHECK_PTR_RET_A( adapterId, *fileBuffer, nullptr );

        auto magicNumber = *( (uint32_t*) *fileBuffer );
        if( magicNumber != MD_BYTE_ARRAY_MAGIC_NUMBER )
        {
            MD_LOG_A( adapterId, LOG_WARNING, "WARNING: Incorrect magic number or ByteArray is not present in fileBuffer." );
            return nullptr;
        }

        *fileBuffer += sizeof( uint32_t );
        auto byteArraySize = *( (uint32_t*) *fileBuffer );
        *fileBuffer += sizeof( uint32_t );

        auto byteArray = new( std::nothrow ) TByteArrayLatest();
        MD_CHECK_PTR_RET_A( adapterId, byteArray, nullptr );

        byteArray->Size = byteArraySize;
        if( byteArray->Size == 0 )
        {
            MD_LOG_A( adapterId, LOG_WARNING, "WARNING: Read ByteArray has size 0" );
            byteArray->Data = nullptr;
            return byteArray;
        }

        byteArray->Data = new( std::nothrow ) uint8_t[byteArray->Size]();
        if( byteArray->Data == nullptr )
        {
            MD_SAFE_DELETE( byteArray );

            MD_LOG_A( adapterId, LOG_DEBUG, "ERROR: null pointer: byteArray->Data" );
            MD_LOG_EXIT_A( adapterId );
            return nullptr;
        }

        iu_memcpy_s( byteArray->Data, byteArray->Size, *fileBuffer, byteArray->Size );
        *fileBuffer += byteArray->Size;

        return byteArray;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     ReadCStringFromFileBuffer
    //
    // Description:
    //     Reads null-character ended cstring from file buffer. Function DOES NOT COPY the cstring.
    //     It only advances the fileBuffer pointer and returns a pointer to cstring in buffer.
    //
    // Input:
    //     uint8_t**      fileBuffer - pointer to the binary file buffer array
    //     const uint32_t adapterId  - adapter id for purpose of logging
    //
    // Output:
    //     char*                 - pointer to the cstring in buffer (not copied)
    //
    //////////////////////////////////////////////////////////////////////////////
    char* ReadCStringFromFileBuffer( uint8_t** fileBuffer, const uint32_t adapterId )
    {
        if( fileBuffer == nullptr || *fileBuffer == nullptr )
        {
            MD_ASSERT_A( adapterId, fileBuffer != nullptr );
            MD_ASSERT_A( adapterId, *fileBuffer != nullptr );
            return (char*) "";
        }

        char*  cstring       = (char*) *fileBuffer;
        size_t cstringLength = strlen( cstring );

        if( cstringLength == 0 )
        {
            cstring = (char*) "";
        }

        *fileBuffer += cstringLength + 1;

        return cstring;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     ReadUInt32FromFileBuffer
    //
    // Description:
    //     Reads uint32_t from file buffer.
    //
    // Input:
    //     uint8_t**      fileBuffer - pointer to the binary file buffer array
    //     const uint32_t adapterId  - adapter id for purpose of logging
    //
    // Output:
    //     uint32_t              - read uint32_t
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t ReadUInt32FromFileBuffer( uint8_t** fileBuffer, const uint32_t adapterId )
    {
        if( fileBuffer == nullptr || *fileBuffer == nullptr )
        {
            MD_ASSERT_A( adapterId, fileBuffer != nullptr );
            MD_ASSERT_A( adapterId, *fileBuffer != nullptr );
            return 0;
        }

        uint32_t value = *( (uint32_t*) *fileBuffer );
        *fileBuffer += sizeof( uint32_t );

        return value;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     ReadInt64FromFileBuffer
    //
    // Description:
    //     Reads int64_t int from file buffer.
    //
    // Input:
    //     uint8_t**      fileBuffer - pointer to the binary file buffer array
    //     const uint32_t adapterId  - adapter id for purpose of logging
    //
    // Output:
    //     int64_t               - read int64_t
    //
    //////////////////////////////////////////////////////////////////////////////
    int64_t ReadInt64FromFileBuffer( uint8_t** fileBuffer, const uint32_t adapterId )
    {
        if( fileBuffer == nullptr || *fileBuffer == nullptr )
        {
            MD_ASSERT_A( adapterId, fileBuffer != nullptr );
            MD_ASSERT_A( adapterId, *fileBuffer != nullptr );
            return 0;
        }

        int64_t value = *( (int64_t*) *fileBuffer );
        *fileBuffer += sizeof( int64_t );

        return value;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     ReadTTypedValueFromFileBuffer
    //
    // Description:
    //     Reads TTypedValue struct from file buffer.
    //
    // Input:
    //     uint8_t**      fileBuffer - pointer to the binary file buffer array
    //     const uint32_t adapterId  - adapter id for purpose of logging
    //
    // Output:
    //     TTypedValue_1_0       - read TTypedValue
    //
    //////////////////////////////////////////////////////////////////////////////
    TTypedValue_1_0 ReadTTypedValueFromFileBuffer( uint8_t** fileBuffer, const uint32_t adapterId )
    {
        TTypedValue_1_0 typedValue;
        typedValue.ValueType   = VALUE_TYPE_UINT32;
        typedValue.ValueUInt32 = 0;

        if( fileBuffer == nullptr || *fileBuffer == nullptr )
        {
            MD_ASSERT_A( adapterId, fileBuffer != nullptr );
            MD_ASSERT_A( adapterId, *fileBuffer != nullptr );
            return typedValue;
        }

        typedValue.ValueType = ( *(TValueType*) *fileBuffer );
        *fileBuffer += sizeof( TValueType );

        switch( typedValue.ValueType )
        {
            case VALUE_TYPE_UINT32:
                typedValue.ValueUInt32 = *( (uint32_t*) *fileBuffer );
                *fileBuffer += sizeof( uint32_t );
                break;

            case VALUE_TYPE_UINT64:
                typedValue.ValueUInt64 = *( (uint64_t*) *fileBuffer );
                *fileBuffer += sizeof( uint64_t );
                break;

            case VALUE_TYPE_FLOAT:
                typedValue.ValueFloat = *( (float*) *fileBuffer );
                *fileBuffer += sizeof( float );
                break;

            case VALUE_TYPE_BOOL:
                typedValue.ValueBool = *( (bool*) *fileBuffer );
                *fileBuffer += sizeof( bool );
                break;

            case VALUE_TYPE_CSTRING:
                MD_LOG_A( adapterId, LOG_DEBUG, "calling ReadCStringFromFileBuffer()..." );
                typedValue.ValueCString = ReadCStringFromFileBuffer( fileBuffer, adapterId );
                *fileBuffer += sizeof( bool );
                break;

            case VALUE_TYPE_BYTEARRAY:
                MD_LOG_A( adapterId, LOG_DEBUG, "calling ReadByteArrayFromFileBuffer()..." );
                typedValue.ValueByteArray = ReadByteArrayFromFileBuffer( fileBuffer, adapterId );
                break;
            default:
                MD_ASSERT_A( adapterId, false );
                break;
        }

        return typedValue;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     ReadEquationStringFromFile
    //
    // Description:
    //     Reads equation string from file buffer.
    //
    // Input:
    //     uint8_t**      fileBuffer - pointer to the binary file buffer array
    //     const uint32_t adapterId  - adapter id for purpose of logging
    //
    // Output:
    //     char*                 - if not empty, pointer to the cstring in buffer (not copied)
    //
    //////////////////////////////////////////////////////////////////////////////
    char* ReadEquationStringFromFile( uint8_t** fileBuffer, const uint32_t adapterId )
    {
        if( fileBuffer == nullptr || *fileBuffer == nullptr )
        {
            MD_ASSERT_A( adapterId, fileBuffer != nullptr );
            MD_ASSERT_A( adapterId, *fileBuffer != nullptr );
            return (char*) "";
        }

        char* ret = nullptr;

        if( ( **fileBuffer ) == 0xFF )
        {
            ret = (char*) "";
            ( *fileBuffer )++;
        }
        else
        {
            ret = ReadCStringFromFileBuffer( fileBuffer, adapterId );
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     SetBitInByteArray
    //
    // Description:
    //     Sets chosen bit in given byte array.
    //
    // Input:
    //     TByteArrayLatest& byteArray - byte array where set bit
    //     const uint32_t    bitIndex  - indicates bit which will be set to 1
    //     const uint32_t    adapterId - adapter id for purpose of logging
    //
    // Output:
    //     TCompletionCode             - result
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode SetBitInByteArray( TByteArrayLatest* byteArray, const uint32_t bitIndex, const uint32_t adapterId )
    {
        MD_CHECK_PTR_RET_A( adapterId, byteArray, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, byteArray->Data, CC_ERROR_INVALID_PARAMETER );

        const uint32_t byteIndex      = bitIndex / 8;
        const uint32_t bitInByteIndex = bitIndex % 8;
        const uint8_t  mask           = MD_BIT( bitInByteIndex );

        if( byteIndex > byteArray->Size - 1 )
        {
            return CC_ERROR_INVALID_PARAMETER;
        }

        byteArray->Data[byteIndex] |= mask;

        if( !( byteArray->Data[byteIndex] & mask ) )
        {
            return CC_ERROR_GENERAL;
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     SetAllBitsPlatformMask
    //
    // Description:
    //     Set all bits to 1 in platform mask.
    //     It means PLATFORM_ALL.
    //
    // Input:
    //     const uint32_t    adapterId          - adapter id for purpose of logging
    //     TByteArrayLatest& platformMask       - platform mask byte array to be set
    //     uint32_t          platformMaskLegacy - (optional) platform mask legacy to be set
    //
    // Output:
    //     TCompletionCode                       - result
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode SetAllBitsPlatformMask( const uint32_t adapterId, TByteArrayLatest* platformMask, uint32_t* platformMaskLegacy /*= nullptr*/ )
    {
        MD_CHECK_PTR_RET_A( adapterId, platformMask, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, platformMask->Data, CC_ERROR_INVALID_PARAMETER );

        if( platformMask->Size == 0 )
        {
            MD_LOG_A( adapterId, LOG_WARNING, "WARNING: byte array size is 0. Cannot set platform mask." );
            return CC_ERROR_GENERAL;
        }

        auto ret = iu_memset( platformMask->Data, 0xFF, platformMask->Size ) ? CC_OK : CC_ERROR_GENERAL;

        if( platformMaskLegacy )
        {
            *platformMaskLegacy = PLATFORM_ALL;
        }

        return ret;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     ComparePlatforms
    //
    // Description:
    //     Compares two platforms if they are equal.
    //
    // Input:
    //     const TByteArrayLatest* firstPlatformMask    -
    //     const uint32_t          firstGtMask          -
    //     const TByteArrayLatest* secondPlatformMask   -
    //     const uint32_t          secondGtMask         -
    //     const uint32_t          adapterId            -
    // Output:
    //     bool                                         - comparison result
    //
    //////////////////////////////////////////////////////////////////////////////
    bool ComparePlatforms( const TByteArrayLatest* firstPlatformMask, const uint32_t firstGtMask, const TByteArrayLatest* secondPlatformMask, const uint32_t secondGtMask, const uint32_t adapterId )
    {
        MD_CHECK_PTR_RET_A( adapterId, firstPlatformMask, false );
        MD_CHECK_PTR_RET_A( adapterId, firstPlatformMask->Data, false );
        MD_CHECK_PTR_RET_A( adapterId, secondPlatformMask, false );
        MD_CHECK_PTR_RET_A( adapterId, secondPlatformMask->Data, false );

        bool gtMatch       = ( firstGtMask & secondGtMask ) != 0;
        bool platformMatch = false;

        if( firstPlatformMask->Size != secondPlatformMask->Size )
        {
            MD_LOG_A( adapterId, LOG_ERROR, "ByteArray sizes are not equal!" );
            return false;
        }

        for( uint32_t i = 0; i < firstPlatformMask->Size; ++i )
        {
            platformMatch = ( ( firstPlatformMask->Data[i] ) & ( secondPlatformMask->Data[i] ) ) != 0;
            if( platformMatch )
            {
                break;
            }
        }

        return platformMatch && gtMatch;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     IsPlatformPresentInMask
    //
    // Description:
    //     Checks if platform is presented in current platform mask.
    //
    // Input:
    //     const TByteArrayLatest* platformMask   - platform mask
    //     const uint32_t          platformIndex  - platform index
    //     const uint32_t          adapterId      - adapter id for purpose of logging
    // Output:
    //     bool                                   - result
    //
    //////////////////////////////////////////////////////////////////////////////
    bool IsPlatformPresentInMask( const TByteArrayLatest* platformMask, const uint32_t platformIndex, const uint32_t adapterId )
    {
        MD_CHECK_PTR_RET_A( adapterId, platformMask, false );
        MD_CHECK_PTR_RET_A( adapterId, platformMask->Data, false );

        const uint32_t byteIndex      = platformIndex / 8;
        const uint32_t bitInByteIndex = platformIndex % 8;
        const uint8_t  mask           = MD_BIT( bitInByteIndex );

        if( byteIndex > platformMask->Size - 1 )
        {
            return false;
        }

        if( ( platformMask->Data[byteIndex] ) & mask )
        {
            return true;
        }

        return false;
    }
    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     ClearVector
    //
    // Description:
    //     Clears given std::vector
    //     If vector contains pointers to objects these objects are deleted and the
    //     memory is freed.
    //     Mirrors the behaviour of MetricsDiscoveryInternal::Vector::Clear
    //
    // Input:
    //     std::vector<T>& / std::vector<T*>& - reference to vector
    //
    //////////////////////////////////////////////////////////////////////////////
    template <typename T>
    void ClearVector( std::vector<T*>& vector )
    {
        for( T* ptr : vector )
        {
            MD_SAFE_DELETE( ptr );
        }

        vector.clear();
    }

    template <typename T>
    void ClearVector( std::vector<T>& vector )
    {
        vector.clear();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     ClearUnorderedMap
    //
    // Description:
    //     Clears given std::unordered_map
    //     If unordered_map contains pointers to objects these objects are deleted and the
    //     memory is freed.
    //
    // Input:
    //     std::unordered_map<Key, Value*>& - reference to unordered_map
    //
    //////////////////////////////////////////////////////////////////////////////
    template <typename Key, typename Value>
    void ClearUnorderedMap( std::unordered_map<Key, Value*>& unorderedMap )
    {
        for( auto& ptr : unorderedMap )
        {
            MD_SAFE_DELETE( ptr.second );
        }

        unorderedMap.clear();
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     ClearList
    //
    // Description:
    //     Clears given std::list
    //     If list contains pointers to objects these objects are deleted and the
    //     memory is freed.
    //     Mirrors the behaviour of MetricsDiscoveryInternal::List::Clear
    //
    // Input:
    //     std::list<T>* / std::list<T*>* - reference to list
    //
    //////////////////////////////////////////////////////////////////////////////
    template <typename T>
    void ClearList( std::list<T>& list )
    {
        list.clear();
    }

    template <typename T>

    void ClearList( std::list<T*>& list )
    {
        for( T* ptr : list )
        {
            MD_SAFE_DELETE( ptr );
        }

        list.clear();
    }

    // Explicit Instantiation
    template void ClearVector( std::vector<CInformation*>& );
    template void ClearVector( std::vector<CAdapter*>& );
    template void ClearVector( std::vector<CConcurrentGroup*>& );
    template void ClearVector( std::vector<CMetricSet*>& );
    template void ClearVector( std::vector<CMetric*>& );
    template void ClearVector( std::vector<char const*>& );
    template void ClearVector( std::vector<SRegister*>& );
    template void ClearVector( std::vector<CEquationElementInternal>& );
    template void ClearVector( std::vector<SGlobalSymbol*>& );
    template void ClearVector( std::vector<IOverride_1_2*>& );
    template void ClearList( std::list<uint64_t>& );
    template void ClearList( std::list<CRegisterSet*>& );
    template void ClearList( std::list<CMetricSet*>& );
    template void ClearList( std::list<SRegister>& );
    template void ClearUnorderedMap( std::unordered_map<std::string_view, TGlobalSymbol*>& unorderedMap );

} // namespace MetricsDiscoveryInternal
