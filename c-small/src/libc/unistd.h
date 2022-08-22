// unistd.h - Provides access to the POSIX operating system API.
// POSIX only.

#ifndef UNISTD_H
#define UNISTD_H

#include <sys/syscall.h> // SYS_*

#include "asm.h"
#define syscall(...) __SYSCALL_DISP(syscall, __VA_ARGS__)

#define STDIN_FILENO  0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

#endif
