// assert.h - Contains the assert macro, used to assist with detecting logical errors and other types of bugs in debugging versions of a program.

#ifndef ASSERT_H
#define ASSERT_H

#ifdef NDEBUG
#define assert(ignore) ((void) 0)
#else
#define assert(E) ((void)((E) || (__assert_fail (#E, __FILE__, __LINE__), 0)))
#endif

void __assert_fail(const char* expr, const char* file, unsigned int line);

#include "stdio.h"  // stderr, fprintf()
#include "stdlib.h" // abort()

void __assert_fail(const char* expr, const char* file, unsigned int line)
{
	//fprintf(stderr, "Assertion failed: %s (%s: %d)\n", expr, file, line);
	puts("Assertion failed!\n");
	abort();
	__builtin_unreachable();
}

#endif
