// stdlib.h - Defines numeric conversion functions, pseudo-random numbers generation functions, memory allocation, process control functions.

#ifndef STDLIB_H
#define STDLIB_H

#include "unistd.h"

void exit(int status)
{
	syscall(SYS_exit_group, status);
	__builtin_unreachable();
}

void abort(void)
{
	exit(127);
	__builtin_unreachable();
}

#endif
