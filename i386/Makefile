BIN = hello

.SILENT:
.PHONY: all
all:
	clear

	echo '> Generating syscalls32.s'
	cat /usr/include/asm/unistd_32.h | tail -n +4 | sed '$$ d' | sed 's/#/%/g' > src/syscalls32.s
	sed -i '1i %define SYSCALLS32_S' src/syscalls32.s
	sed -i '1i %ifndef SYSCALLS32_S' src/syscalls32.s
	echo '%endif' >> src/syscalls32.s

	echo '> src/main.s'
	nasm -Ox -f bin src/main.s -o $(BIN)
	chmod +x $(BIN)

	#objdump --start-address=0x00 --insn-width=15 -b binary -Mintel,i386 -m i386 -D $(BIN)
	wc -c $(BIN)
	echo

.PHONY: clean
clean:
	rm -f $(BIN)
