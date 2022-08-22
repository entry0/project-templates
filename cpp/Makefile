BIN = hello
CXX = g++
CXXFLAGS = \
-pipe -std=c++17 -D_POSIX_C_SOURCE=200112L \
-Wall -Wformat-security \
-O3 -s -ffast-math -fdata-sections -ffunction-sections -flto \
-fno-plt \
-Wl,--build-id=none -Wl,--gc-sections -Wl,-s \
-m64
LDFLAGS =

DIR  := src
SRCS := $(shell find $(DIR) -name '*.cpp')
DIRS := $(shell find $(DIR) -type d | sed 's $(DIR) . g' ) 
OBJS := $(patsubst $(DIR)/%.cpp,obj/%.o,$(SRCS))
DEPS := $(patsubst $(DIR)/%.cpp,obj/%.d,$(SRCS))
-include $(DEPS)

.PHONY: init
init:
	mkdir -p obj
	for dir in $(DIRS); do mkdir -p obj/$$dir; done

obj/%.o: $(DIR)/%.cpp Makefile
	echo '> $<'
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(BIN): init $(OBJS)
	echo '> Linking $@!'
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(LDFLAGS)

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
