/*========================== begin_copyright_notice ============================

Copyright (C) 2019-2025 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

//     File Name:  md_utils.cpp

//     Abstract:   C++ metrics discovery utils implementation.

#include "md_utils.h"
#include "md_adapter.h"
#include "md_metrics_device.h"
#include "md_concurrent_group.h"
#include "md_driver_ifc.h"
#include "md_equation.h"
#include "md_information.h"
#include "md_metric.h"
#include "md_metric_set.h"
#include "md_register_set.h"
#include "md_metric_enumerator.h"
#include "md_metric_prototype.h"

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
    //     WriteEquationToBuffer
    //
    // Description:
    //     Writes CEquation class to buffer. If it's equal to null, 0xFF will be written.
    //
    // Input:
    //     CEquation*     equation     - CEquation to be written
    //     uint8_t*       buffer       - pointer to a buffer
    //     uint32_t&      bufferSize   - size of the buffer
    //     uint32_t&      bufferOffset - the current offset of the buffer
    //     const uint32_t adapterId    - adapter id for purpose of logging
    //
    // Output:
    //     TCompletionCode             - result
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode WriteEquationToBuffer( CEquation* equation, uint8_t* buffer, uint32_t& bufferSize, uint32_t& bufferOffset, const uint32_t adapterId )
    {
        TCompletionCode result = CC_OK;

        if( equation )
        {
            result = equation->WriteCEquationToBuffer( buffer, bufferSize, bufferOffset );
        }
        else
        {
            const uint8_t emptyEquation = 0xFF;

            result = WriteDataToBuffer( (void*) &emptyEquation, sizeof( emptyEquation ), buffer, bufferSize, bufferOffset, adapterId );
        }

        MD_CHECK_CC_RET_A( adapterId, result );

        return CC_OK;
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
    //     CMetricsDevice& device         - metric device
    //     CEquation*&     equation       - pointer to the equation to be set
    //     const char*     equationString - euqation string, could be empty or null
    //
    // Output:
    //     TCompletionCode            - result of the operation
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode SetEquation( CMetricsDevice& device, CEquation*& equation, const char* equationString )
    {
        TCompletionCode ret = CC_OK;

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
            if( CDriverInterface::SemaphoreCreate( semaphoreName, semaphorePtr, adapterId ) != CC_OK )
            {
                MD_LOG_A( adapterId, LOG_ERROR, "semaphore create failed" );
                return CC_ERROR_GENERAL;
            }
        }

        TSemaphoreWaitResult result = CDriverInterface::SemaphoreWait( 1000L, *semaphorePtr, adapterId ); // Wait 1 sec
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

        if( CDriverInterface::SemaphoreRelease( semaphorePtr, adapterId ) != CC_OK )
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
            if( lSize < 0 )
            {
                MD_LOG_A( adapterId, LOG_DEBUG, "ftell failed" );
            }

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

        uint32_t copiedByteArraySize = 0;
        for( uint32_t i = byteArray->Size; i > 0; i -= sizeof( uint64_t ) )
        {
            const uint8_t* currentQword = byteArray->Data + ( i - sizeof( uint64_t ) );
            const uint64_t qwordValue   = *reinterpret_cast<const uint64_t*>( currentQword );

            if( qwordValue != 0 )
            {
                copiedByteArraySize = i;
                break;
            }
        }

        copiedByteArray->Size = copiedByteArraySize;
        copiedByteArray->Data = new( std::nothrow ) uint8_t[copiedByteArray->Size](); // Initialize all to 0
        if( copiedByteArray->Data == nullptr )
        {
            MD_SAFE_DELETE( copiedByteArray );
            MD_LOG_A( adapterId, LOG_DEBUG, "ERROR: null pointer: copiedByteArray->Data" );
            MD_LOG_EXIT_A( adapterId );
            return nullptr;
        }

        const bool result = iu_memcpy_s( copiedByteArray->Data, copiedByteArray->Size, byteArray->Data, copiedByteArray->Size );

        if( !result )
        {
            MD_SAFE_DELETE_ARRAY( copiedByteArray->Data );
            MD_SAFE_DELETE( copiedByteArray );
            MD_LOG_A( adapterId, LOG_DEBUG, "ERROR: memory copy failed" );
            MD_LOG_EXIT_A( adapterId );
            return nullptr;
        }

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
        byteArray.Size = static_cast<uint32_t>( strLength / 2 );

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
    //     It HAS TO be deleted later.
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
    //     It HAS TO be deleted later.
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
    //     WriteByteArrayToBuffer
    //
    // Description:
    //     Writes byte array to buffer.
    //
    // Input:
    //     const TByteArrayLatest* byteArray    - byte array to be written
    //     uint8_t*                buffer       - pointer to a buffer
    //     uint32_t&               bufferSize   - size of the buffer
    //     uint32_t&               bufferOffset - the current offset of the buffer
    //     const uint32_t          adapterId    - adapter id for purpose of logging
    //
    // Output:
    //     TCompletionCode                      - result
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode WriteByteArrayToBuffer( const TByteArrayLatest* byteArray, uint8_t* buffer, uint32_t& bufferSize, uint32_t& bufferOffset, const uint32_t adapterId )
    {
        MD_CHECK_PTR_RET_A( adapterId, byteArray, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, byteArray->Data, CC_ERROR_INVALID_PARAMETER );

        TCompletionCode result      = CC_OK;
        const uint32_t  magicNumber = MD_BYTE_ARRAY_MAGIC_NUMBER;

        result = WriteDataToBuffer( (void*) &magicNumber, sizeof( magicNumber ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteDataToBuffer( (void*) &byteArray->Size, sizeof( byteArray->Size ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        result = WriteDataToBuffer( byteArray->Data, byteArray->Size, buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     WriteCStringToBuffer
    //
    // Description:
    //     Writes null-character ended cstring to buffer.
    //
    // Input:
    //     const char*    cstring      - cstring to be written
    //     uint8_t*       buffer       - pointer to a buffer
    //     uint32_t&      bufferSize   - size of the buffer
    //     uint32_t&      bufferOffset - the current offset of the buffer
    //     const uint32_t adapterId    - adapter id for purpose of logging
    //
    // Output:
    //     TCompletionCode             - result
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode WriteCStringToBuffer( const char* cstring, uint8_t* buffer, uint32_t& bufferSize, uint32_t& bufferOffset, const uint32_t adapterId )
    {
        const char*  cstr      = ( cstring == nullptr ) ? "" : cstring;
        const size_t strLength = strlen( cstr ) + 1;

        TCompletionCode result = WriteDataToBuffer( (void*) cstr, static_cast<uint32_t>( strLength ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     WriteTTypedValueToBuffer
    //
    // Description:
    //     Writes TTypedValue struct to buffer.
    //
    // Input:
    //     const TTypedValue_1_0* typedValue   - TypedValue to be written
    //     uint8_t*               buffer       - pointer to a buffer
    //     uint32_t&              bufferSize   - size of the buffer
    //     uint32_t&              bufferOffset - the current offset of the buffer
    //     const uint32_t         adapterId    - adapter id for purpose of logging
    //
    // Output:
    //     TCompletionCode                     - result
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode WriteTTypedValueToBuffer( const TTypedValue_1_0* typedValue, uint8_t* buffer, uint32_t& bufferSize, uint32_t& bufferOffset, const uint32_t adapterId )
    {
        TCompletionCode result = WriteDataToBuffer( (void*) &typedValue->ValueType, sizeof( typedValue->ValueType ), buffer, bufferSize, bufferOffset, adapterId );
        MD_CHECK_CC_RET_A( adapterId, result );

        switch( typedValue->ValueType )
        {
            case VALUE_TYPE_UINT32:
                result = WriteDataToBuffer( (void*) &typedValue->ValueUInt32, sizeof( typedValue->ValueUInt32 ), buffer, bufferSize, bufferOffset, adapterId );
                break;

            case VALUE_TYPE_UINT64:
                result = WriteDataToBuffer( (void*) &typedValue->ValueUInt64, sizeof( typedValue->ValueUInt64 ), buffer, bufferSize, bufferOffset, adapterId );
                break;

            case VALUE_TYPE_FLOAT:
                result = WriteDataToBuffer( (void*) &typedValue->ValueFloat, sizeof( typedValue->ValueFloat ), buffer, bufferSize, bufferOffset, adapterId );
                break;

            case VALUE_TYPE_BOOL:
                result = WriteDataToBuffer( (void*) &typedValue->ValueBool, sizeof( typedValue->ValueBool ), buffer, bufferSize, bufferOffset, adapterId );
                break;

            case VALUE_TYPE_CSTRING:
                result = WriteCStringToBuffer( typedValue->ValueCString, buffer, bufferSize, bufferOffset, adapterId );
                break;

            case VALUE_TYPE_BYTEARRAY:
                result = WriteByteArrayToBuffer( typedValue->ValueByteArray, buffer, bufferSize, bufferOffset, adapterId );
                break;

            default:
                MD_ASSERT_A( adapterId, false );
                break;
        }

        MD_CHECK_CC_RET_A( adapterId, result );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     WriteDataToBuffer
    //
    // Description:
    //     Writes data to buffer.
    //
    // Input:
    //     void*          data         - data to be written
    //     const uint32_t dataSize     - size of the data
    //     uint8_t*       buffer       - pointer to a buffer
    //     uint32_t&      bufferSize   - size of the buffer
    //     uint32_t&      bufferOffset - the current offset of the buffer
    //     const uint32_t adapterId    - adapter id for purpose of logging
    //
    // Output:
    //     TCompletionCode             - result
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode WriteDataToBuffer( void* data, const uint32_t dataSize, uint8_t* buffer, uint32_t& bufferSize, uint32_t& bufferOffset, const uint32_t adapterId )
    {
        MD_CHECK_PTR_RET_A( adapterId, data, CC_ERROR_INVALID_PARAMETER );

        if( buffer )
        {
            MD_CHECK_BUFFER_A( adapterId, bufferOffset, 0, dataSize, bufferSize );
            iu_memcpy_s( buffer + bufferOffset, dataSize, data, dataSize );
            bufferOffset += dataSize;
        }
        else
        {
            bufferSize += dataSize;
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     ReadByteArrayFromBuffer
    //
    // Description:
    //     Read byte array from buffer.
    //
    // Input:
    //     uint8_t*&           buffer            - pointer to the binary buffer array
    //     const uint8_t*      bufferBeginOffset - buffer begin offset
    //     const uint32_t      bufferSize        - buffer size
    //     TByteArrayLatest*&  byteArray         - pointer to the TByteArrayLatest object
    //     const uint32_t      adapterId         - adapter id for purpose of logging
    //
    // Output:
    //     TCompletionCode                      - result
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode ReadByteArrayFromBuffer( uint8_t*& buffer, const uint8_t* bufferBeginOffset, const uint32_t bufferSize, TByteArrayLatest*& byteArray, const uint32_t adapterId )
    {
        MD_CHECK_PTR_RET_A( adapterId, buffer, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, bufferBeginOffset, CC_ERROR_INVALID_PARAMETER );

        const uint32_t magicNumber = *( (uint32_t*) buffer );
        if( magicNumber != MD_BYTE_ARRAY_MAGIC_NUMBER )
        {
            MD_LOG_A( adapterId, LOG_WARNING, "WARNING: Incorrect magic number or ByteArray is not present in buffer" );
            return CC_ERROR_GENERAL;
        }

        MD_CHECK_BUFFER_A( adapterId, buffer, bufferBeginOffset, sizeof( uint32_t ), bufferSize );
        buffer += sizeof( uint32_t );
        const uint32_t byteArraySize = *( (uint32_t*) buffer );

        MD_CHECK_BUFFER_A( adapterId, buffer, bufferBeginOffset, sizeof( uint32_t ), bufferSize );
        buffer += sizeof( uint32_t );

        byteArray = new( std::nothrow ) TByteArrayLatest();
        MD_CHECK_PTR_RET_A( adapterId, byteArray, CC_ERROR_NO_MEMORY );

        byteArray->Size = byteArraySize;
        if( byteArray->Size == 0 )
        {
            MD_LOG_A( adapterId, LOG_WARNING, "WARNING: Read ByteArray has size 0" );
            byteArray->Data = nullptr;
            MD_SAFE_DELETE( byteArray );
            return CC_ERROR_GENERAL;
        }

        byteArray->Data = new( std::nothrow ) uint8_t[byteArray->Size]();
        if( byteArray->Data == nullptr )
        {
            MD_SAFE_DELETE( byteArray );

            MD_LOG_A( adapterId, LOG_DEBUG, "ERROR: null pointer: byteArray->Data" );
            MD_LOG_EXIT_A( adapterId );
            return CC_ERROR_GENERAL;
        }

        iu_memcpy_s( byteArray->Data, byteArray->Size, buffer, byteArray->Size );
        buffer += byteArray->Size;

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     ReadCStringFromBuffer
    //
    // Description:
    //     Reads null-character ended cstring from buffer. Function DOES NOT COPY the cstring.
    //     It only advances the buffer pointer and returns a pointer to cstring in buffer.
    //
    // Input:
    //     uint8_t*&       buffer            - pointer to the binary buffer array
    //     const uint8_t*  bufferBeginOffset - buffer begin offset
    //     const uint32_t  bufferSize        - buffer size
    //     const char*&    cstring           - given cstring in buffer
    //     const uint32_t  adapterId         - adapter id for purpose of logging
    //
    // Output:
    //     TCompletionCode                   - result
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode ReadCStringFromBuffer( uint8_t*& buffer, const uint8_t* bufferBeginOffset, const uint32_t bufferSize, const char*& cstring, const uint32_t adapterId )
    {
        MD_CHECK_PTR_RET_A( adapterId, buffer, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, bufferBeginOffset, CC_ERROR_INVALID_PARAMETER );

        cstring                    = (char*) buffer;
        const size_t cstringLength = iu_strnlen_s( cstring, bufferSize - ( buffer - bufferBeginOffset ) );

        if( cstringLength == 0 )
        {
            MD_LOG_A( adapterId, LOG_DEBUG, "Empty string" );
        }

        buffer += cstringLength + 1;

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     ReadUInt32FromBuffer
    //
    // Description:
    //     Reads uint32_t from buffer.
    //
    // Input:
    //     uint8_t*&       buffer            - pointer to the binary buffer array
    //     const uint8_t*  bufferBeginOffset - buffer begin offset
    //     const uint32_t  bufferSize        - buffer size
    //     uint32_t&       value             - given value
    //     const uint32_t  adapterId         - adapter id for purpose of logging
    //
    // Output:
    //     TCompletionCode                   - result
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode ReadUInt32FromBuffer( uint8_t*& buffer, const uint8_t* bufferBeginOffset, const uint32_t bufferSize, uint32_t& value, const uint32_t adapterId )
    {
        MD_CHECK_PTR_RET_A( adapterId, buffer, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, bufferBeginOffset, CC_ERROR_INVALID_PARAMETER );

        MD_CHECK_BUFFER_A( adapterId, buffer, bufferBeginOffset, sizeof( uint32_t ), bufferSize );

        value = *( (uint32_t*) buffer );
        buffer += sizeof( uint32_t );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     ReadInt64FromBuffer
    //
    // Description:
    //     Reads int64_t from buffer.
    //
    // Input:
    //     uint8_t*&       bufferuffer       - pointer to the binary buffer array
    //     const uint8_t*  bufferBeginOffset - buffer begin offset
    //     const uint32_t  bufferSize        - buffer size
    //     int64_t&        value             - given value
    //     const uint32_t  adapterId         - adapter id for purpose of logging
    //
    // Output:
    //     TCompletionCode                   - result
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode ReadInt64FromBuffer( uint8_t*& buffer, const uint8_t* bufferBeginOffset, const uint32_t bufferSize, int64_t& value, const uint32_t adapterId )
    {
        MD_CHECK_PTR_RET_A( adapterId, buffer, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, bufferBeginOffset, CC_ERROR_INVALID_PARAMETER );

        MD_CHECK_BUFFER_A( adapterId, buffer, bufferBeginOffset, sizeof( int64_t ), bufferSize );
        value = *( (int64_t*) buffer );
        buffer += sizeof( int64_t );

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     ReadTTypedValueFromBuffer
    //
    // Description:
    //     Reads TTypedValue struct from buffer.
    //
    // Input:
    //     uint8_t*&      buffer            - pointer to the binary buffer array
    //     const uint8_t* bufferBeginOffset - buffer begin offset
    //     const uint32_t bufferSize        - buffer size
    //     const uint32_t bufferVersion     - buffer or file version
    //     const uint32_t adapterId         - adapter id for purpose of logging
    //
    // Output:
    //     TTypedValue_1_0                  - typed value
    //     TCompletionCode                  - result
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode ReadTTypedValueFromBuffer( uint8_t*& buffer, const uint8_t* bufferBeginOffset, const uint32_t bufferSize, const uint32_t bufferVersion, TTypedValue_1_0& typedValue, const uint32_t adapterId )
    {
        TCompletionCode ret      = CC_OK;
        typedValue.ValueType     = VALUE_TYPE_UINT64;
        typedValue.ValueUInt64   = 0;
        const char* valueCString = nullptr;

        MD_CHECK_PTR_RET_A( adapterId, buffer, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, bufferBeginOffset, CC_ERROR_INVALID_PARAMETER );

        MD_CHECK_BUFFER_A( adapterId, buffer, bufferBeginOffset, sizeof( TValueType ), bufferSize );
        typedValue.ValueType = ( *(TValueType*) buffer );
        buffer += sizeof( TValueType );

        switch( typedValue.ValueType )
        {
            case VALUE_TYPE_UINT32:
                MD_CHECK_BUFFER_A( adapterId, buffer, bufferBeginOffset, sizeof( uint32_t ), bufferSize );
                typedValue.ValueUInt32 = *( (uint32_t*) buffer );
                buffer += sizeof( uint32_t );
                break;

            case VALUE_TYPE_UINT64:
                MD_CHECK_BUFFER_A( adapterId, buffer, bufferBeginOffset, sizeof( uint64_t ), bufferSize );
                typedValue.ValueUInt64 = *( (uint64_t*) buffer );
                buffer += sizeof( uint64_t );
                break;

            case VALUE_TYPE_FLOAT:
                MD_CHECK_BUFFER_A( adapterId, buffer, bufferBeginOffset, sizeof( float ), bufferSize );
                typedValue.ValueFloat = *( (float*) buffer );
                buffer += sizeof( float );
                break;

            case VALUE_TYPE_BOOL:
                MD_CHECK_BUFFER_A( adapterId, buffer, bufferBeginOffset, sizeof( bool ), bufferSize );
                typedValue.ValueBool = *( (bool*) buffer );
                buffer += sizeof( bool );
                break;

            case VALUE_TYPE_CSTRING:
                MD_LOG_A( adapterId, LOG_DEBUG, "calling ReadCStringFromBuffer()..." );
                ret = ReadCStringFromBuffer( buffer, bufferBeginOffset, bufferSize, valueCString, adapterId );
                MD_CHECK_CC_RET_A( adapterId, ret );
                typedValue.ValueCString = GetCopiedCString( valueCString, adapterId );
                break;

            case VALUE_TYPE_BYTEARRAY:
                if( bufferVersion >= CUSTOM_METRICS_FILE_VERSION_3 )
                {
                    MD_LOG_A( adapterId, LOG_DEBUG, "calling ReadByteArrayFromBuffer()..." );
                    ret = ReadByteArrayFromBuffer( buffer, bufferBeginOffset, bufferSize, typedValue.ValueByteArray, adapterId );
                    MD_CHECK_CC_RET_A( adapterId, ret );
                }
                else
                {
                    MD_LOG_A( adapterId, LOG_DEBUG, "Reading ByteArray is not supported in buffer version %u", bufferVersion );
                }
                break;
            default:
                MD_ASSERT_A( adapterId, false );
                break;
        }

        return CC_OK;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Group:
    //     Metrics Discovery Utils
    //
    // Function:
    //     ReadEquationStringFromBuffer
    //
    // Description:
    //     Reads equation string from buffer.
    //
    // Input:
    //     uint8_t*&       buffer            - pointer to the binary buffer array
    //     const uint8_t*  bufferBeginOffset - buffer begin offset
    //     const uint32_t  bufferSize        - buffer size
    //     const char*&    cstring           - given cstring in buffer
    //     const uint32_t  adapterId         - adapter id for purpose of logging
    //
    // Output:
    //     TCompletionCode                   - result
    //
    //////////////////////////////////////////////////////////////////////////////
    TCompletionCode ReadEquationStringFromBuffer( uint8_t*& buffer, const uint8_t* bufferBeginOffset, const uint32_t bufferSize, const char*& cstring, const uint32_t adapterId )
    {
        TCompletionCode ret = CC_OK;

        MD_CHECK_PTR_RET_A( adapterId, buffer, CC_ERROR_INVALID_PARAMETER );
        MD_CHECK_PTR_RET_A( adapterId, bufferBeginOffset, CC_ERROR_INVALID_PARAMETER );

        cstring = nullptr;

        if( ( *buffer ) == 0xFF )
        {
            MD_CHECK_BUFFER_A( adapterId, buffer, bufferBeginOffset, sizeof( char ), bufferSize );
            cstring = (char*) "";
            buffer++;
        }
        else
        {
            ret = ReadCStringFromBuffer( buffer, bufferBeginOffset, bufferSize, cstring, adapterId );
            MD_CHECK_CC_RET_A( adapterId, ret );
        }

        return CC_OK;
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
    //     TCompletionCode                      - result
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
            *platformMaskLegacy = static_cast<uint32_t>( PLATFORM_ALL );
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
    // Function:
    //     CalculateEnabledBits
    //
    // Description:
    //     Helper function to get number of ENABLED bits on given bitmask value
    //
    // Input:
    //     uint64_t value - input value
    //     uint64_t mask  - valid bits
    //
    // Output:
    //     uint32_t       - number of enabled bits
    //
    //////////////////////////////////////////////////////////////////////////////
    uint32_t CalculateEnabledBits( uint64_t value, uint64_t mask /* = UINT64_MAX */ )
    {
        uint32_t count = 0;

        value &= mask;
        while( mask )
        {
            count += ( value & 1 );
            value >>= 1;
            mask >>= 1;
        }

        return count;
    }

    //////////////////////////////////////////////////////////////////////////////
    //
    // Function:
    //     IsQueryModeMatch
    //
    // Description:
    //     Helper function to determinate if query mode is match with given query type mask.
    //
    // Input:
    //     const TQueryMode queryMode     - query mode
    //     const uint32_t   queryModeMask - TQueryModeMask mask.
    //                                      TOaReportingType mask can be also passed.
    //                                      Values are synchronized and validated by static_assert.
    //
    // Output:
    //     bool                           - true if match
    //
    //////////////////////////////////////////////////////////////////////////////
    bool IsQueryModeMatch( const TQueryMode queryMode, const uint32_t queryModeMask )
    {
        switch( queryMode )
        {
            case QUERY_MODE_RENDER:
                return queryModeMask & QUERY_MODE_RENDER;

            case QUERY_MODE_COMPUTE:
                return queryModeMask & QUERY_MODE_COMPUTE;

            case QUERY_MODE_GLOBAL:
                return queryModeMask & QUERY_MODE_MASK_GLOBAL;

            case QUERY_MODE_GLOBAL_EXTENDED:
                return queryModeMask & QUERY_MODE_MASK_GLOBAL_EXTENDED;

            default:
                MD_LOG( LOG_DEBUG, "Unknown query mode: %u", queryMode );
                return false;
        }
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
    template void ClearVector( std::vector<CMetricsDevice*>& );
    template void ClearVector( std::vector<CConcurrentGroup*>& );
    template void ClearVector( std::vector<CMetricSet*>& );
    template void ClearVector( std::vector<CMetric*>& );
    template void ClearVector( std::vector<char const*>& );
    template void ClearVector( std::vector<SRegister*>& );
    template void ClearVector( std::vector<CEquationElementInternal>& );
    template void ClearVector( std::vector<SGlobalSymbol*>& );
    template void ClearVector( std::vector<IOverride_1_2*>& );
    template void ClearVector( std::vector<CMetricEnumerator*>& );
    template void ClearVector( std::vector<CMetricPrototype*>& );
    template void ClearVector( std::vector<TArchEvent*>& );
    template void ClearVector( std::vector<THwEvent*>& );
    template void ClearVector( std::vector<TMetricPrototypeOptionDescriptorLatest*>& );
    template void ClearList( std::list<uint64_t>& );
    template void ClearList( std::list<CRegisterSet*>& );
    template void ClearList( std::list<CMetricSet*>& );
    template void ClearList( std::list<SRegister>& );
    template void ClearUnorderedMap( std::unordered_map<std::string_view, TGlobalSymbol*>& unorderedMap );

} // namespace MetricsDiscoveryInternal
