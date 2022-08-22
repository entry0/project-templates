// asm.h - Inline assembly utilities.
// ABANDON ALL HOPE ALL YE WHO ENTER HERE.

#ifndef ASM_H
#define ASM_H

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

#include <stdint.h> // uint64_t uint32_t

#define asm __asm__
#define volatile __volatile__

#define BYTE(b) asm volatile (".byte " #b);
#define FORCE_INLINE __attribute__ ((always_inline)) __attribute__ ((unused)) static

#ifdef BITS64
#define MAKE_ARGS() \
	asm volatile ("pop rdi;"); \
	int argc = ASM_GetRDI(); \
	asm volatile ("pop rsi;"); \
	char** argv = (char**)ASM_GetRSI();
#endif

#ifdef BITS32
#define MAKE_ARGS() \
	asm volatile ("pop edi;"); \
	int argc = ASM_GetRDI(); \
	asm volatile ("pop esi;"); \
	char** argv = (char**)ASM_GetRSI();
#endif

#ifdef BITS64
#define INLINE_STRING(name, s) \
	asm volatile ("push %rax"); \
	asm volatile ("jmp " #name "_s"); \
	asm volatile (#name "_s:"); \
	asm volatile ("call " #name "_r"); \
	asm volatile (".asciz \"" s "\""); \
	asm volatile (#name "_r:"); \
	asm volatile ("pop %rax"); \
	const char* name = (char*)ASM_GetRAX(); \
	asm volatile ("pop %rax");
#endif

#ifdef BITS32
#define INLINE_STRING(name, s) \
	asm volatile ("push %eax"); \
	asm volatile ("jmp " #name "_s"); \
	asm volatile (#name "_s:"); \
	asm volatile ("call " #name "_r"); \
	asm volatile (".asciz \"" s "\""); \
	asm volatile (#name "_r:"); \
	asm volatile ("pop %eax"); \
	const char* name = (char*)ASM_GetEAX(); \
	asm volatile ("pop %eax");
#endif

// Ripped from musl libc internal/syscall.h
#define __SYSCALL_NARGS_X(a, b, c, d, e, f, g, h, n, ...) n
#define __SYSCALL_NARGS(...) __SYSCALL_NARGS_X(__VA_ARGS__, 7, 6, 5, 4, 3, 2, 1, 0,)
#define __SYSCALL_CONCAT_X(a, b) a##b
#define __SYSCALL_CONCAT(a, b) __SYSCALL_CONCAT_X(a, b)
#define __SYSCALL_DISP(b, ...) __SYSCALL_CONCAT(b, __SYSCALL_NARGS(__VA_ARGS__))(__VA_ARGS__)
#define ASM_Syscall(...) __SYSCALL_DISP(syscall, __VA_ARGS__)

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wattributes"

FORCE_INLINE uint64_t ASM_GetRAX()
{
	register uint64_t rax asm ("rax");
	asm ("" : "=r"(rax));
	return rax;
}

FORCE_INLINE uint64_t ASM_GetRBX()
{
	register uint64_t rbx asm ("rbx");
	asm ("" : "=r"(rbx));
	return rbx;
}

FORCE_INLINE uint64_t ASM_GetRCX()
{
	register uint64_t rcx asm ("rcx");
	asm ("" : "=r"(rcx));
	return rcx;
}

FORCE_INLINE uint64_t ASM_GetRDX()
{
	register uint64_t rdx asm ("rdx");
	asm ("" : "=r"(rdx));
	return rdx;
}

FORCE_INLINE uint64_t ASM_GetRDI()
{
	register uint64_t rdi asm ("rdi");
	asm ("" : "=r"(rdi));
	return rdi;
}

FORCE_INLINE uint64_t ASM_GetRSI()
{
	register uint64_t rsi asm ("rsi");
	asm ("" : "=r"(rsi));
	return rsi;
}

FORCE_INLINE uint64_t ASM_GetRBP()
{
	register uint64_t rbp asm ("rbp");
	asm ("" : "=r"(rbp));
	return rbp;
}

FORCE_INLINE uint32_t ASM_GetEAX()
{
	register uint32_t eax asm ("eax");
	asm ("" : "=r"(eax));
	return eax;
}

FORCE_INLINE uint32_t ASM_GetEBX()
{
	register uint32_t ebx asm ("ebx");
	asm ("" : "=r"(ebx));
	return ebx;
}

FORCE_INLINE uint32_t ASM_GetECX()
{
	register uint32_t ecx asm ("ecx");
	asm ("" : "=r"(ecx));
	return ecx;
}

FORCE_INLINE uint32_t ASM_GetEDX()
{
	register uint32_t edx asm ("edx");
	asm ("" : "=r"(edx));
	return edx;
}

FORCE_INLINE uint32_t ASM_GetEDI()
{
	register uint32_t edi asm ("edi");
	asm ("" : "=r"(edi));
	return edi;
}

FORCE_INLINE uint32_t ASM_GetESI()
{
	register uint32_t esi asm ("esi");
	asm ("" : "=r"(esi));
	return esi;
}

FORCE_INLINE uint32_t ASM_GetEBP()
{
	register uint32_t ebp asm ("ebp");
	asm ("" : "=r"(ebp));
	return ebp;
}

FORCE_INLINE uint64_t ASM_GetR8()
{
	register uint64_t r8 asm ("r8");
	asm ("" : "=r"(r8));
	return r8;
}

FORCE_INLINE uint64_t ASM_GetR9()
{
	register uint64_t r9 asm ("r9");
	asm ("" : "=r"(r9));
	return r9;
}

FORCE_INLINE uint64_t ASM_GetR10()
{
	register uint64_t r10 asm ("r10");
	asm ("" : "=r"(r10));
	return r10;
}

FORCE_INLINE uint64_t ASM_GetR11()
{
	register uint64_t r11 asm ("r11");
	asm ("" : "=r"(r11));
	return r11;
}

FORCE_INLINE uint64_t ASM_GetR12()
{
	register uint64_t r12 asm ("r12");
	asm ("" : "=r"(r12));
	return r12;
}

FORCE_INLINE uint64_t ASM_GetR13()
{
	register uint64_t r13 asm ("r13");
	asm ("" : "=r"(r13));
	return r13;
}

FORCE_INLINE uint64_t ASM_GetR14()
{
	register uint64_t r14 asm ("r14");
	asm ("" : "=r"(r14));
	return r14;
}

FORCE_INLINE uint64_t ASM_GetR15()
{
	register uint64_t r15 asm ("r15");
	asm ("" : "=r"(r15));
	return r15;
}

FORCE_INLINE void ASM_SetRAX(const uint64_t r)
{
	if (r == 0) asm volatile ("xor %rax, %rax;");
	else if (r <= 0xFF) {
		asm volatile ("xor %rax, %rax;");
		asm volatile ("movb %0, %%al;" : : "g"(r) : "rax");
	}
	else asm volatile ("movq %0, %%rax;" : : "g"(r) : "rax");
}

FORCE_INLINE void ASM_SetRBX(const uint64_t r)
{
	if (r == 0) asm volatile ("xor %rbx, %rbx;");
	else if (r <= 0xFF) {
		asm volatile ("xor %rbx, %rbx;");
		asm volatile ("movb %0, %%bl;" : : "g"(r) : "rbx");
	}
	else asm volatile ("movq %0, %%rbx;" : : "g"(r) : "rbx");
}

FORCE_INLINE void ASM_SetRCX(const uint64_t r)
{
	if (r == 0) asm volatile ("xor %rcx, %rcx;");
	else if (r <= 0xFF) {
		asm volatile ("xor %rcx, %rcx;");
		asm volatile ("movb %0, %%cl;" : : "g"(r) : "rcx");
	}
	else asm volatile ("movq %0, %%rcx;" : : "g"(r) : "rcx");
}

FORCE_INLINE void ASM_SetRDX(const uint64_t r)
{
	if (r == 0) asm volatile ("xor %rdx, %rdx;");
	else if (r <= 0xFF) {
		asm volatile ("xor %rdx, %rdx;");
		asm volatile ("movb %0, %%dl;" : : "g"(r) : "rdx");
	}
	else asm volatile ("movq %0, %%rdx;" : : "g"(r) : "rdx");
}

FORCE_INLINE void ASM_SetRDI(const uint64_t r)
{
	if (r == 0) asm volatile ("xor %rdi, %rdi;");
	else asm volatile ("movq %0, %%rdi;" : : "g"(r) : "rdi");
}

FORCE_INLINE void ASM_SetRSI(const uint64_t r)
{
	if (r == 0) asm volatile ("xor %rsi, %rsi;");
	else asm volatile ("movq %0, %%rsi;" : : "g"(r) : "rsi");
}

FORCE_INLINE void ASM_SetRBP(const uint64_t r)
{
	if (r == 0) asm volatile ("xor %rbp, %rbp;");
	else asm volatile ("movq %0, %%rbp;" : : "g"(r) : "rbp");
}

FORCE_INLINE void ASM_SetR8(const uint64_t r)
{
	if (r == 0) asm volatile ("xor %r8, %r8;");
	else asm volatile ("movq %0, %%r8;" : : "g"(r) : "r8");
}

FORCE_INLINE void ASM_SetR9(const uint64_t r)
{
	if (r == 0) asm volatile ("xor %r9, %r9;");
	else asm volatile ("movq %0, %%r9;" : : "g"(r) : "r9");
}

FORCE_INLINE void ASM_SetR10(const uint64_t r)
{
	if (r == 0) asm volatile ("xor %r10, %r10;");
	else asm volatile ("movq %0, %%r10;" : : "g"(r) : "r10");
}

FORCE_INLINE void ASM_SetR11(const uint64_t r)
{
	if (r == 0) asm volatile ("xor %r11, %r11;");
	else asm volatile ("movq %0, %%r11;" : : "g"(r) : "r11");
}

FORCE_INLINE void ASM_SetR12(const uint64_t r)
{
	if (r == 0) asm volatile ("xor %r12, %r12;");
	else asm volatile ("movq %0, %%r12;" : : "g"(r) : "r12");
}

FORCE_INLINE void ASM_SetR13(const uint64_t r)
{
	if (r == 0) asm volatile ("xor %r13, %r13;");
	else asm volatile ("movq %0, %%r13;" : : "g"(r) : "r13");
}

FORCE_INLINE void ASM_SetR14(const uint64_t r)
{
	if (r == 0) asm volatile ("xor %r14, %r14;");
	else asm volatile ("movq %0, %%r14;" : : "g"(r) : "r14");
}

FORCE_INLINE void ASM_SetR15(const uint64_t r)
{
	if (r == 0) asm volatile ("xor %r15, %r15;");
	else asm volatile ("movq %0, %%r15;" : : "g"(r) : "r15");
}

FORCE_INLINE void ASM_SetEAX(const uint32_t r)
{
	if (r == 0) asm volatile ("xor %eax, %eax;");
	else if (r <= 0xFF) {
		asm volatile ("xor %eax, %eax;");
		asm volatile ("movb %0, %%al;" : : "g"(r) : "eax");
	}
	else asm volatile ("movl %0, %%eax;" : : "g"(r) : "eax");
}

FORCE_INLINE void ASM_SetEBX(const uint32_t r)
{
	if (r == 0) asm volatile ("xor %ebx, %ebx;");
	else if (r <= 0xFF) {
		asm volatile ("xor %ebx, %ebx;");
		asm volatile ("movb %0, %%bl;" : : "g"(r) : "ebx");
	}
	else asm volatile ("movl %0, %%ebx;" : : "g"(r) : "ebx");
}

FORCE_INLINE void ASM_SetECX(const uint32_t r)
{
	if (r == 0) asm volatile ("xor %ecx, %ecx;");
	else if (r <= 0xFF) {
		asm volatile ("xor %ecx, %ecx;");
		asm volatile ("movb %0, %%cl;" : : "g"(r) : "ecx");
	}
	else asm volatile ("movl %0, %%ecx;" : : "g"(r) : "ecx");
}

FORCE_INLINE void ASM_SetEDX(const uint32_t r)
{
	if (r == 0) asm volatile ("xor %edx, %edx;");
	else if (r <= 0xFF) {
		asm volatile ("xor %edx, %edx;");
		asm volatile ("movb %0, %%dl;" : : "g"(r) : "edx");
	}
	else asm volatile ("movl %0, %%edx;" : : "g"(r) : "edx");
}

FORCE_INLINE void ASM_SetEDI(const uint32_t r)
{
	if (r == 0) asm volatile ("xor %edi, %edi;");
	else asm volatile ("movl %0, %%edi;" : : "g"(r) : "edi");
}

FORCE_INLINE void ASM_SetESI(const uint32_t r)
{
	if (r == 0) asm volatile ("xor %esi, %esi;");
	else asm volatile ("movl %0, %%esi;" : : "g"(r) : "esi");
}

FORCE_INLINE void ASM_SetEBP(const uint32_t r)
{
	if (r == 0) asm volatile ("xor %ebp, %ebp;");
	else asm volatile ("movl %0, %%ebp;" : : "g"(r) : "ebp");
}

#ifdef BITS64

long syscall0(long n)
{
	ASM_SetRAX(n);
	asm volatile ("syscall;");
	return ASM_GetRAX();
}

long syscall1(long n, long a1)
{
	ASM_SetRAX(n);
	ASM_SetRDI(a1);
	asm volatile ("syscall;");
	return ASM_GetRAX();
}

long syscall2(long n, long a1, long a2)
{
	ASM_SetRAX(n);
	ASM_SetRDI(a1);
	ASM_SetRSI(a2);
	asm volatile ("syscall;");
	return ASM_GetRAX();
}

long syscall3(long n, long a1, long a2, long a3)
{
	ASM_SetRAX(n);
	ASM_SetRDI(a1);
	ASM_SetRSI(a2);
	ASM_SetRDX(a3);
	asm volatile ("syscall;");
	return ASM_GetRAX();
}

long syscall4(long n, long a1, long a2, long a3, long a4)
{
	ASM_SetRAX(n);
	ASM_SetRDI(a1);
	ASM_SetRSI(a2);
	ASM_SetRDX(a3);
	ASM_SetR10(a4);
	asm volatile ("syscall;");
	return ASM_GetRAX();
}

long syscall5(long n, long a1, long a2, long a3, long a4, long a5)
{
	ASM_SetRAX(n);
	ASM_SetRDI(a1);
	ASM_SetRSI(a2);
	ASM_SetRDX(a3);
	ASM_SetR10(a4);
	ASM_SetR8(a5);
	asm volatile ("syscall;");
	return ASM_GetRAX();
}

long syscall6(long n, long a1, long a2, long a3, long a4, long a5, long a6)
{
	ASM_SetRAX(n);
	ASM_SetRDI(a1);
	ASM_SetRSI(a2);
	ASM_SetRDX(a3);
	ASM_SetR10(a4);
	ASM_SetR8(a5);
	ASM_SetR9(a6);
	asm volatile ("syscall;");
	return ASM_GetRAX();
}

#endif

#ifdef BITS32

long syscall0(long n)
{
	ASM_SetEAX(n);
	asm volatile ("syscall;");
	return ASM_GetEAX();
}

long syscall1(long n, long a1)
{
	ASM_SetEAX(n);
	ASM_SetEBX(a1);
	asm volatile ("syscall;");
	return ASM_GetEAX();
}

long syscall2(long n, long a1, long a2)
{
	ASM_SetEAX(n);
	ASM_SetEBX(a1);
	ASM_SetECX(a2);
	asm volatile ("syscall;");
	return ASM_GetEAX();
}

long syscall3(long n, long a1, long a2, long a3)
{
	ASM_SetEAX(n);
	ASM_SetEBX(a1);
	ASM_SetECX(a2);
	ASM_SetEDX(a3);
	asm volatile ("syscall;");
	return ASM_GetEAX();
}

long syscall4(long n, long a1, long a2, long a3, long a4)
{
	ASM_SetEAX(n);
	ASM_SetEBX(a1);
	ASM_SetECX(a2);
	ASM_SetEDX(a3);
	ASM_SetESI(a4);
	asm volatile ("syscall;");
	return ASM_GetEAX();
}

long syscall5(long n, long a1, long a2, long a3, long a4, long a5)
{
	ASM_SetEAX(n);
	ASM_SetEBX(a1);
	ASM_SetECX(a2);
	ASM_SetEDX(a3);
	ASM_SetESI(a4);
	ASM_SetEDI(a5);
	asm volatile ("syscall;");
	return ASM_GetEAX();
}

long syscall6(long n, long a1, long a2, long a3, long a4, long a5, long a6)
{
	ASM_SetEAX(n);
	ASM_SetEBX(a1);
	ASM_SetECX(a2);
	ASM_SetEDX(a3);
	ASM_SetESI(a4);
	ASM_SetEDI(a5);
	ASM_SetEBP(a6);
	asm volatile ("syscall;");
	return ASM_GetEAX();
}

#endif

#pragma GCC diagnostic pop
#endif
