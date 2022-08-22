BIN = hello
CC = musl-gcc
CFLAGS = \
-pipe -std=c99 -D_POSIX_C_SOURCE=200112L \
-Wall -Wformat-security \
-static -Os -s -ffast-math -fdata-sections -ffunction-sections -flto \
-no-pie -fno-plt \
-Wl,--build-id=none -Wl,--gc-sections -Wl,-s \
-m64
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

obj/%.o: $(DIR)/%.c Makefile
	echo '> $<'
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(BIN): init $(OBJS)
	echo '> Linking $@!'
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

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
	@echo
