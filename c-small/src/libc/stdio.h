// stdio.h - Defines core input and output functions.

#ifndef STDIO_H
#define STDIO_H

#include "unistd.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wattributes"

#define puts(s) \
	if (sizeof (s) != sizeof (void*)) { \
		syscall(SYS_write, 1, (long)s, sizeof (s) - 1); \
		syscall(SYS_write, 1, (long)"\n", 1); \
	} \
	else __puts(s);

FORCE_INLINE int __puts(const char* s)
{
	return 0;
}

#pragma GCC diagnostic pop
#endif
