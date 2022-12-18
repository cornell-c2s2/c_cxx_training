//-------------------------------------------------------------------------
// C2S2 Utility Functions
//-------------------------------------------------------------------------

#ifndef SRC_C2S2_UTILS
#define SRC_C2S2_UTILS

// Memory management functions

void* c2s2_malloc( size_t size );
void  c2s2_free  ( void* ptr );

// Memory check functions
//  - use c2s2_memcheck

void  c2s2_memcheck_func( char const* caller_name );
#define c2s2_memcheck() c2s2_memcheck_func(__func__)

#endif // C2S2_UTILS