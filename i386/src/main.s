;;;; main.s - File description.
%include "src/header.s"
%include "src/macros.s"

_start:
	jmp main

;;; Data:
message db "Hello world!", 0x0A, 0

main:
	syscall __NR_write, 1, message, 13
	syscall __NR_exit_group, 0

%include "src/footer.s"
