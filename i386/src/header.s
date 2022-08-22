;;;; header.s - %include at the top of binary.

BITS 32
org 0x08048000 ; load address

;;; Elf32_Ehdr
ehdr:
	;; [Magic]                 [Arch] [Endian] [Ver] [ABI]     [ABI Version]
	;;                         x32,   Little,  1,    System V, 0
	db 0x7F, 0x45, 0x4C, 0x46, 0x01,  0x01,    0x01, 0x00,     0x00 ; e_ident
	times 7 db 0x00                                              ; e_ident padding

	dw 0x02      ; e_type      ; Object Type           ; ET_EXEC
	dw 0x03      ; e_machine   ; Architecture          ; x86
	dd 0x01      ; e_version   ; ELF Version           ; 1
	dd _start    ; e_entry     ; Entry Point Address   ; _start
	dd phdr - $$ ; e_phoff     ; Program Header Offset ; 0x34
	dd 0x00      ; e_shoff     ; Address Of .shstrtab  ; None
	dd 0x00      ; e_flags     ; Flags                 ; None
	dw ehsize    ; e_ehsize    ; ELF Header Size       ; ehdrsize
	dw phentsize ; e_phentsize ; Program Header Size   ; phdrsize
	dw 0x01      ; e_phnum     ; phdr Entries          ; 1
	dw 0x00      ; e_shentsize ; Section Header Size   ; 0
	dw 0x00      ; e_shnum     ; shdr Entries          ; 0
	dw 0x00      ; e_shstrndx  ; Index Of shdr Names   ; 0x00
ehsize equ $ - ehdr ; End Header

;;; Elf32_Phdr
phdr:
	dd 0x01     ; p_type   ; Segment Type           ; PT_LOAD
	dd 0x00	    ; p_offset ; Segment Offset         ; 0x00
	dd $$       ; p_vaddr  ; Virtual Address        ; phdr
	dd $$	      ; p_paddr  ; Physical Address       ; phdr
	dd fileSize ; p_filesz ; Segment Size In File   ; File Size
	dd fileSize ; p_memsz  ; Segment Size In Memory ; File Size
	dd 0x07     ; p_flags  ; Segment Flags          ; RWX
	dd 0x1000   ; p_align  ; Alignment              ; 0x1000
phentsize equ $ - phdr ; End Header
