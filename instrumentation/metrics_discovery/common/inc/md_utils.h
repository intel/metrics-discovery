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

    File Name:  md_utils.h

    Abstract:   C++ header with metrics discovery utils

\*****************************************************************************/
#pragma once

#include "metrics_discovery_api.h"
#include "md_debug.h"
#include "iu_std.h"

#include <stdio.h>
#include <string.h>
#include <new>

#define MD_SAFE_DELETE( object ) \
    delete object;               \
    object = NULL;

#define MD_SAFE_DELETE_ARRAY( object ) \
    delete[] object;                   \
    object = NULL;

#define MD_CHECK_PTR( object )  \
    if( (object) == NULL ) {    \
        goto exception;         \
    }

#define MD_CHECK_PTR_RET( object, ret )         \
    if( (object) == NULL )                      \
    {                                           \
        MD_LOG( LOG_DEBUG, "ERROR: null pointer: %s", #object );  \
        MD_LOG_EXIT();                          \
        return ret;                             \
    }

#define MD_CHECK_SIZE_RET( size, type, ret )    \
    if( (size) != sizeof(type) )                \
    {                                           \
        MD_LOG( LOG_DEBUG, "ERROR: invalid size" );  \
        MD_LOG_EXIT();                          \
        return ret;                             \
    }

#define MD_CHECK_CC( object ) \
    if( (object) != CC_OK ) goto exception;

#define MD_CHECK_CC_RET( object )                            \
    if( (object) != CC_OK )                                  \
    {                                                        \
        MD_LOG( LOG_DEBUG, "ERROR: result not ok: %d", (object) ); \
        MD_LOG_EXIT();                                       \
        return (object);                                     \
    }

#define MD_CHECK_CC_MSG( object, FORMAT, ... )        \
    if( (object) != CC_OK )                           \
    {                                                 \
        MD_LOG( LOG_DEBUG, FORMAT, __VA_ARGS__ );     \
    }

#define MD_BIT( i )     ( 1 << (i) )
#define MD_BITMASK( n ) ( ~((uint64_t)(-1) << (n) ) )
#define MD_BITMASK_RANGE( startbit, endbit )   ( MD_BITMASK( (endbit)+1 ) & ~MD_BITMASK( startbit ) )

#define MD_SECOND_IN_NS 1000000000ULL
#define MD_GPU_TIMESTAMP_MASK MD_BITMASK( 32 )

using namespace MetricsDiscovery;

namespace MetricsDiscoveryInternal
{

int32_t         GetFileSize( FILE* pFile );
char*           GetCopiedCString( const char* cstring );

void            WriteCStringToFile( const char* cstring, FILE* pFile );
void            WriteTTypedValueToFile( TTypedValue_1_0* typedValue, FILE* pFile );

char*           ReadCStringFromFileBuffer( unsigned char** fileBuffer );
uint32_t        ReadUInt32FromFileBuffer( unsigned char** fileBuffer );
int64_t         ReadInt64FromFileBuffer( unsigned char** fileBuffer );
TTypedValue_1_0 ReadTTypedValueFromFileBuffer( unsigned char** fileBuffer );
char*           ReadEquationStringFromFile( unsigned char** fileBuffer );


/******************************************************************************/
/* List node template:                                                        */
/******************************************************************************/
template <class T>
struct Node
{
    T        value;
    Node<T>* nextNode;
    Node<T>* prevNode;
};

/*****************************************************************************\

Group:
    Metrics Discovery Utils

Function:
    DeleteArray

Description:
    Helpers to handle deletion when *Vector* stores values or pointers.

Input:
    T**\T*** array      - array of elements
    uint32_t count      - elements count

\*****************************************************************************/
template<class T> static void DeleteArray( T** array, uint32_t count )
{
    MD_SAFE_DELETE_ARRAY( *array );
}

template<class T> static void DeleteArray( T*** array, uint32_t count )
{
    for( uint32_t i = 0; i < count; i++ )
    {
        MD_SAFE_DELETE( (*array)[i] ); // delete objects allocations
    }

    MD_SAFE_DELETE_ARRAY( *array );    // delete the array of pointers
}

/*****************************************************************************\

Group:
    Metrics Discovery Utils

Function:
    DeleteElement

Description:
    Helpers to handle deletion when *List* stores values or pointers.

Input:
    T*\T** elem - pointer to element

\*****************************************************************************/
template<class T> static void DeleteElement( T* elem )
{
    return;
}

template<class T> static void DeleteElement( T** elem )
{
    MD_SAFE_DELETE( *elem );
}


/*****************************************************************************\

Class:
    List

Description:
    Simple list template implementation. It can store values and pointers.

\*****************************************************************************/
template <class T>
class List
{
private:
    Node<T>* m_head;
    Node<T>* m_tail;
    uint32_t m_elementsCount;

public:
    /*****************************************************************************\

    Template:
        List<T>

    Method:
        List constructor

    Description:
        Constructor.

    \*****************************************************************************/
    List()
    {
        m_elementsCount = 0;
        m_head = NULL;
        m_tail = NULL;
    }

    /*****************************************************************************\

    Template:
        List<T>

    Method:
        List destructor

    Description:
        Deallocates memory.

    \*****************************************************************************/
    ~List()
    {
        Clear();
    }

    /*****************************************************************************\

    Template:
        List<T>

    Method:
        GetCount

    Description:
        Returns the elements count.

    Output:
        uint32_t    - elements count

    \*****************************************************************************/
    uint32_t GetCount()
    {
        return m_elementsCount;
    }

    /*****************************************************************************\

    Template:
        List<T>

    Method:
        Back

    Description:
        Returns a reference to the last element in the list. When it's null undefined
        behavior.

    Output:
        T&  - reference to last element

    \*****************************************************************************/
    T& Back()
    {
        MD_ASSERT( m_tail != NULL );

        return m_tail->value;
    }

    /*****************************************************************************\

    Template:
        List<T>

    Method:
        PushBack

    Description:
        Adds an element to the back of the list.

    Input:
        T element   -   element to push

    \*****************************************************************************/
    void PushBack( T element )
    {
        Node<T>* newNode = new (std::nothrow) Node<T>;
        if( !newNode )
        {
            MD_ASSERT( false );
            return;
        }
        newNode->value = element;

        if( m_elementsCount == 0 )
        {
            m_head = newNode;
        }
        else
        {
            m_tail->nextNode = newNode;
        }

        newNode->nextNode = NULL;
        newNode->prevNode = m_tail;
        m_tail = newNode;
        m_elementsCount++;
    }

    /*****************************************************************************\

    Template:
        List<T>

    Method:
        PushFront

    Description:
        Adds an element to the front of the list.

    Input:
        T element   - element to push

    \*****************************************************************************/
    void PushFront( T element )
    {
        Node<T>* newNode = new (std::nothrow) Node<T>;
        if( !newNode )
        {
            MD_ASSERT( false );
            return;
        }
        newNode->value = element;

        if( m_elementsCount == 0 )
        {
            m_tail = newNode;
        }
        else
        {
            m_head->prevNode = newNode;
        }

        newNode->prevNode = NULL;
        newNode->nextNode = m_head; // !
        m_head = newNode;
        m_elementsCount++;
    }

    /*****************************************************************************\

    Template:
        List<T>

    Method:
        PopBack

    Description:
        Deletes the last element in the list.

        \*****************************************************************************/
    void PopBack()
    {
        Node<T>* nodeToPop = m_tail;

        if( m_elementsCount != 0 )
        {
            m_tail = m_tail->prevNode;
            if( m_tail != NULL )
            {
                m_tail->nextNode = NULL;
            }
            m_elementsCount--;

            if( m_elementsCount < 2 )
            {
                m_head = m_tail;
            }
        }

        DeleteElement( &nodeToPop->value );
        MD_SAFE_DELETE( nodeToPop );
    }

    /*****************************************************************************\

    Template:
        List<T>

    Method:
        PopFront

    Description:
        Deletes the first element in the list.

    \*****************************************************************************/
    void PopFront()
    {
        Node<T>* nodeToPop = m_head;

        if( m_elementsCount != 0 )
        {
            m_head = m_head->nextNode;
            if( m_head != NULL )
            {
                m_head->prevNode = NULL;
            }
            m_elementsCount--;

            if( m_elementsCount < 2 )
            {
                m_tail = m_head;
            }
        }

        DeleteElement( &nodeToPop->value );
        MD_SAFE_DELETE( nodeToPop );
    }

    /*****************************************************************************\

    Template:
        List<T>

    Method:
        GetHeadNode

    Description:
        Returns a pointer to the first node.

    Output:
        Node<T>*    - pointer to the first node

    \*****************************************************************************/
    Node<T>* GetHeadNode()
    {
        return m_head;
    }

    /*****************************************************************************\

    Template:
        List<T>

    Method:
        Clear

    Description:
        Clear the whole list (deletes all the elements).

    \*****************************************************************************/
    void Clear()
    {
        Node<T>* node = m_head;
        Node<T>* nextNode = NULL;

        while( node != NULL )
        {
            nextNode = node->nextNode;
            DeleteElement( &node->value );
            MD_SAFE_DELETE( node );
            node = nextNode;
        }

        m_elementsCount = 0;
        m_head = NULL;
        m_tail = NULL;
    }
};

/*****************************************************************************\

Class:
    Stack

Description:
    Generic stack implementation.

\*****************************************************************************/
template< typename T>
class Stack
{
private:
    uint32_t                m_increaseFactor;       // Growth factor.
    uint32_t                m_count;                // Number of elements in the stack.
    uint32_t                m_capacity;             // Stack capacity.
    T*                      m_container;            // Stack container.
    T                       m_dummy;                // Dummy element;

public:
    /*****************************************************************************\

    Template:
        Stack<T>

    Method:
        Stack constructor.

    Description:
        Constructor.
    \*****************************************************************************/
    explicit Stack( void ) :
        m_count( 0 ),
        m_capacity( 0 ),
        m_increaseFactor( 50 ),
        m_container( NULL )
    {
    }

    /*****************************************************************************\

    Template:
        Stack<T>

    Method:
        Vector destructor.

    Description:
        Deallocates memory.

    \*****************************************************************************/
    virtual ~Stack( void )
    {
        MD_SAFE_DELETE_ARRAY( m_container );
    }

    /*****************************************************************************\

    Template:
        Stack<T>

    Method:
        push

    Description:
        Adds an element to the top of the stack.

    Input:
        const T& value - The element added to the top of the stack.

    \*****************************************************************************/
    inline void push( const T& value )
    {
        bool result = true;

        // Resize the stack if too small.
        if( m_count >= m_capacity )
        {
            result = reserve( m_capacity + m_increaseFactor );
        }

        // Push element on the stack.
        if( result && m_container )
        {
            m_container[m_count++] = value;
        }
        else
        {
            MD_ASSERT( false );
        }
    }

    /*****************************************************************************\

    Template:
        Stack<T>

    Method:
        pop

    Description:
        Removes top element from the the stack.

    \*****************************************************************************/
    inline void pop( void )
    {
        m_count = m_count > 0
            ? m_count - 1
            : 0;
    }

    /*****************************************************************************\

    Template:
        Stack<T>

    Method:
        top

    Description:
        Returns a reference to an element at the top of the stack.

    Output:
        const T& - a reference to a stack element.

    \*****************************************************************************/
    inline const T& top( void )
    {
        MD_ASSERT( m_container && m_count );

        return m_count && m_container
            ? m_container[m_count - 1]
            : m_dummy;   // We need to return anything.
    }

    /*****************************************************************************\

    Template:
        Stack<T>

    Method:
        size

    Description:
        Returns the number of elements in the stack.

    Output:
        uint32_t - number of elements in the stack.

    \*****************************************************************************/
    inline uint32_t size( void )
    {
        return m_count;
    }

    /*****************************************************************************\

    Template:
        Stack<T>

    Method:
        clear

    Description:
        Removes all elements from the stack.

    \*****************************************************************************/
    inline void clear( void )
    {
        m_count = 0;
    }

    /*****************************************************************************\

    Template:
        Stack<T>

    Method:
        reserve

    Description:
        Reserves space for stack elements.

    Input:
        uint32_t - new stack capacity.

    Output:
        bool - true if success.

    \*****************************************************************************/
    bool reserve( uint32_t size )
    {
        if( m_capacity < size )
        {
            // Allocate memory for a bigger stack.
            T* newContainer = new (std::nothrow) T[size];
            if( newContainer == NULL )
            {
                MD_ASSERT( false );
                return false;
            }

            // Copy old container into the new one.
            for( uint32_t i = 0; i < m_capacity; ++i )
            {
                newContainer[i] = m_container[i];
            }

            // Delete an old container.
            MD_SAFE_DELETE_ARRAY( m_container );

            // Update container.
            m_capacity = size;
            m_container = newContainer;
        }

        return true;
    }
};

/*****************************************************************************\

Class:
    Vector

Description:
    Simple vector template implementation. It can store values and pointers.

\*****************************************************************************/
template <class T>
class Vector
{
private:
    T*           m_vector;
    uint32_t     m_vectorSize;
    uint32_t     m_elementsCount;
    uint32_t     m_vectorIncrease;

public:
    /*****************************************************************************\

    Template:
        Vector<T>

    Method:
        Vector constructor

    Description:
        Constructor.

    Input:
        uint32_t vectorIncrease -

    \*****************************************************************************/
    Vector( uint32_t vectorIncrease )
        : m_vectorIncrease( vectorIncrease )
    {
        m_vector = new (std::nothrow) T[ m_vectorIncrease ];
        if ( !m_vector )
        {
            MD_ASSERT( false );
            return;
        }

        memset( m_vector, 0x0, sizeof( T ) * m_vectorIncrease );
        m_vectorSize = m_vectorIncrease;
        m_elementsCount = 0;
    }

    /*****************************************************************************\

    Template:
        Vector<T>

    Method:
        Vector destructor

    Description:
        Deallocates memory.

    \*****************************************************************************/
    ~Vector()
    {
        DeleteArray( &m_vector, m_elementsCount );
    }

    /*****************************************************************************\

    Template:
        Vector<T>

    Method:
        operator[]

    Description:
        Access operator.

    Input:
        int i   - index

    Output:
        T       - object

    \*****************************************************************************/
    T operator [](int i) const
    {
        return m_vector[ i ];
    }

    /*****************************************************************************\

    Template:
        Vector<T>

    Method:
        operator[]

    Description:
        Access operator.

    Input:
        int i   - index

    Output:
        T&      - reference to object

    \*****************************************************************************/
    T& operator [](int i)
    {
        return m_vector[ i ];
    }

    /*****************************************************************************\

    Template:
        Vector<T>

    Method:
        GetCount

    Description:
        Returns the elements count.

    Output:
        uint32_t    - elements count

    \*****************************************************************************/
    uint32_t GetCount()
    {
        return m_elementsCount;
    }

    /*****************************************************************************\

    Template:
        Vector<T>

    Method:
        Clear

    Description:
        Removes all elements from the vector (which are destroyed). Memory pointer and
        *m_vectorSize* remain the same.

    \*****************************************************************************/
    void Clear()
    {
        for( uint32_t i = 0; i < m_elementsCount; i++ )
        {
            DeleteElement( &m_vector[i] );
        }
        m_elementsCount = 0;
    }

    /*****************************************************************************\

    Template:
        Vector<T>

    Method:
        PushBack

    Description:
        Adds an element to the end of vector.

    Input:
        T element   - element to push

    \*****************************************************************************/
    void PushBack( T element )
    {
        if( m_elementsCount == m_vectorSize )
        {
            IncreaseSize();
        }

        m_vector[ m_elementsCount++ ] = element;
    }

    /*****************************************************************************\

    Template:
        Vector<T>

    Method:
        GetPointerToMemory

    Description:
        Returns pointer to vector memory.

    Output:
        T*  - pointer to vector memory

    \*****************************************************************************/
    T* GetMemoryPointer()
    {
        return m_vector;
    }

    /*****************************************************************************\

    Template:
        Vector<T>

    Method:
        FillWith

    Description:
        Fills entire vector with the single, specified value.

    Input:
        T element - element with which the vector will be filled, e.g. NULL

    \*****************************************************************************/
    void FillWith( T element )
    {
        for( uint32_t i = 0; i < m_elementsCount; i++ )
        {
            m_vector[i] = element;
        }
    }

private:
    /*****************************************************************************\

    Template:
        Vector<T>

    Method:
        IncreaseSize

    Description:
        Increases vector memory allocation size and copies content.

    \*****************************************************************************/
    void IncreaseSize()
    {
        T* newVector = new (std::nothrow) T[ m_vectorSize + m_vectorIncrease ];
        if( !newVector )
        {
            MD_ASSERT( false );
            return;
        }

        memset( &newVector[ m_vectorSize ], 0x0, sizeof( T ) * m_vectorIncrease );
        for( uint32_t i = 0; i < m_vectorSize; i++ )
        {
            newVector[i] = m_vector[i];
        }

        MD_SAFE_DELETE_ARRAY( m_vector );

        m_vector = newVector;
        m_vectorSize += m_vectorIncrease;
    }
};

}
