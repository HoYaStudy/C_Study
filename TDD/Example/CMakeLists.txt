cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_FLAGS -std=c++17)

include_directories(
	Unity
	Catch2
)

file(GLOB SRCS
	factorial.cpp
)

file (GLOB UNITY_SRCS
	Unity/unity.c
	Unity/unity_fixture.c
	Unity_Example.c
)

file (GLOB CATCH2_SRCS
	Catch2_Example.cpp
)

file (GLOB GTEST_SRCS
)

project(example1)
add_executable(example1 ${SRCS} ${UNITY_SRCS})

project(example2)
add_executable(example2 ${SRCS} ${CATCH2_SRCS})