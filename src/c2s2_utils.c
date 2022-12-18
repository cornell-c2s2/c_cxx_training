//-------------------------------------------------------------------------
// C2S2 Utility Functions
//-------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include "c2s2_utils.h"

int mem_heap_size = 0;

//-----------------------------------------------------
// c2s2_malloc
//-----------------------------------------------------
// Allocates the desired space plus the size of an int,
// so wee can keep track of how much was allocated
//
// Credit: ECE2400

void* c2s2_malloc( size_t size )
{
    void* ptr = malloc( size + sizeof(int) );

    if( ptr != NULL ) // Not NULL
    {
        mem_heap_size += ( int )size;
    }
    else
    {
        return NULL;
    }

    ( (int*)ptr )[0] = ( int )size;

    return ( void* )( ( (int*)ptr ) + 1 );
}

//-----------------------------------------------------
// c2s2_free
//-----------------------------------------------------
// Deallocates the desired space and subtracts the
// space from our counter
//
// Credit: ECE2400

void c2s2_free( void* ptr )
{
    if( ptr != NULL )
    {
        mem_heap_size -= ( (int*)ptr )[-1];
        free( ( ( (int*)ptr ) - 1 ) );
    }
}

//-----------------------------------------------------
// c2s2_memcheck_func
//-----------------------------------------------------
// Checks that we have no memory allocated that we
// haven't freed

void c2s2_memcheck_func( char const* caller_name )
{
    if( mem_heap_size != 0 )
    {
        printf("Uh oh - memory leak detected in %s\n", caller_name);
        printf("Exiting...\n");
        exit(1);
    }
}
