cmake_minimum_required (VERSION 3.8)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_C_COMPILER "/usr/bin/clang")
set (CMAKE_C_FLAGS "-std=c11 -Os -g3 -Wall -Wextra -Wshadow")

file (GLOB SRCS
	log.c
	log_test.c
)

project (log)
add_executable (log ${SRCS})
