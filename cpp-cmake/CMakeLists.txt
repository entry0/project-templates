set(BIN "hello")

cmake_minimum_required(VERSION 3.9)
project(${BIN} CXX)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} \
-pipe -std=c++17 -D_POSIX_SOURCE \
-Wall -Wformat-security \
-ffast-math -fdata-sections -ffunction-sections -flto \
-fno-plt -fPIC \
")

set(CMAKE_CXX_FLAGS_DEBUG "-Og -g -fsanitize=undefined -fsanitize=address") # -fsanitize=undefined -fsanitize=address -fsanitize=thread
set(CMAKE_CXX_FLAGS_RELEASE "-Os -s -Wl,--build-id=none -Wl,--gc-sections -Wl,-s")

add_executable(${BIN}
	src/main.cpp
)
target_link_libraries(${BIN} PRIVATE)
