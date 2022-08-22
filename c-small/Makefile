ARCH := 32
ifeq ($(ARCH), 32)
	ARCH_FLAGS := -m32 -Wl,-Ai386 -Wl,-belf32-i386
endif
ifeq ($(ARCH), 64)
	ARCH_FLAGS := -m64 -Wl,-Ai386:x86-64 -Wl,-belf64-x86-64
endif

BIN = hello
CC = gcc
CFLAGS = \
-pipe -std=c99 -D_POSIX_C_SOURCE=200112L \
-Wall -Wformat-security \
-static -Os -s -ffast-math -flto -fno-plt \
-Wl,--build-id=none -Wl,--gc-sections -Wl,-s -Wl,-n \
-nostartfiles -Wl,-Tlinker.ld $(ARCH_FLAGS)
LDFLAGS =

DIR  := src
SRCS := $(shell find $(DIR) -name '*.c')
DIRS := $(shell find $(DIR) -type d | sed 's $(DIR) . g' ) 
OBJS := $(patsubst $(DIR)/%.c,obj/%.o,$(SRCS))
DEPS := $(patsubst $(DIR)/%.c,obj/%.d,$(SRCS))
-include $(DEPS)

.PHONY: init
init:
	mkdir -p obj
	for dir in $(DIRS); do mkdir -p obj/$$dir; done

obj/%.o: $(DIR)/%.c Makefile linker.ld
	echo '> $<'
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(BIN): init $(OBJS)
	echo '> Linking $@!'
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)
	objcopy -S $(BIN) /tmp/a.out
	mv /tmp/a.out $(BIN)

.PHONY: clean
clean:
	rm -rf obj/*
	rm -f $(BIN)

.DEFAULT_GOAL := default
.PHONY: default
default:
	@clear
	@make $(BIN) -j $(shell nproc) -s
	@echo '> Stripping $(BIN)!'
	@strip -s -R '.note.gnu.property' -R '.comment' $(BIN)
	@wc -c $(BIN)
	@echo
