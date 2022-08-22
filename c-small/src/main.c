// main.c - File description.

#if _WIN32 || _WIN64
#if _WIN64
#define BITS64
#else
#define BITS32
#endif
#endif

#if __GNUC__
#if __x86_64__
#define BITS64
#else
#define BITS32
#endif
#endif

void _start(void)
{
	// exit_group(0)
#ifdef BITS64
	__asm__ __volatile__ ("syscall" : : "a"(231), "D"(0));
#endif
#ifdef BITS32
	__asm__ __volatile__ ("syscall" : : "a"(252), "b"(0));
#endif
}
