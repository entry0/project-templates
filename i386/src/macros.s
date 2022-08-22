;;;; macros.s - Assembly utility header.

%ifndef MACROS_S
%define MACROS_S

%include "src/syscalls32.s"

%macro __movb 2
	%if %1 == eax
		xor %1, %1
		mov al, %2
	%elif %1 == ebx
		xor %1, %1
		mov bl, %2
	%elif %1 == ecx
		xor %1, %1
		mov cl, %2
	%elif %1 == edx
		xor %1, %1
		mov dl, %2
	%else
		mov %1, %2
	%endif
%endmacro

%macro set 2
%ifnid %1
	%error Destination must be a register!
%endif
%ifnid %2
	%ifnnum %2
		%error Source must be a register or a number!
	%endif
%endif

%if %1 != %2 ; don't 'mov reg, reg'
	%ifid %2 ; if src is register
		mov %1, %2
	%endif
	%ifnum %2 ; if src is a number
		%if %2 == 0 ; don't 'mov reg, 0'
			xor %1, %1
		%elif %2 == 1
			xor %1, %1
			inc %1
		%elif %2 == -1
			xor %1, %1
			dec %1
		%else
			%if %2 > 0 && %2 <= 0xFF ; reduce small numbers into 8-bit registers
				__movb %1, %2
			%else
				mov %1, %2
			%endif
		%endif
	%endif
%endif
%endmacro

%macro syscall 0-7
%if %0 > 0
	set eax, %1
%if %0 > 1
	set ebx, %2
%if %0 > 2
	set ecx, %3
%if %0 > 3
	set edx, %4
%if %0 > 4
	set esi, %5
%if %0 > 5
	set edi, %6
%if %0 > 6
	push ebp
	set ebp, %7
%endif
%endif
%endif
%endif
%endif
%endif
%endif
	int 0x80
%if %0 > 6
%if %7 != ebp
	pop ebp
%endif
%endif
%endmacro

%macro getIP 1
	jmp %%jmp
%%jmp:
	call %%call
%%call:
	pop %1
%endmacro

%macro getAddress 2
	getIP %1
	sub %1, $ - %2 - 1
%endmacro

%macro pushString 1
	jmp %%jmp
%%jmp:
	call %%call
	db %1, 0
%%call:
%endmacro

%macro pushStringLn 1
	jmp %%jmp
%%jmp:
	call %%call
	db %1, 0x0A, 0
%%call:
%endmacro

%macro enter 0
	push ebp
	mov ebp, esp
%endmacro

%macro leave 0
	mov esp, ebp
	pop ebp
%endmacro

%macro alloc 1
	sub esp, %1
%endmacro

%define dropb add esp, 1
%define droph add esp, 2
%define dropw add esp, 4
%define dropd add esp, 8

%macro malloc 1
	;; mmap2(0, %1, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, 0, 0)
	syscall __NR_mmap2, 0, %1, 0x03, 0x22, 0, 0
%endmacro

%macro free 2
	syscall __NR_munmap, %1, %2
%endmacro

%macro memcpy_inline 3
	push edi
	push esi
	push ecx
	mov edi, %1 ; dst
	mov esi, %2 ; src
	mov ecx, %3 ; count
	rep movsb
	pop ecx
	pop esi
	pop edi
%endmacro

%macro print 2
	pusha
	pushString %1
	pop ecx
	syscall __NR_write, 1, ecx, %2
	popa
%endmacro

%macro println 2
	pusha
	pushStringLn %1
	pop ecx
	syscall __NR_write, 1, ecx, %2
	popa
%endmacro

%endif
