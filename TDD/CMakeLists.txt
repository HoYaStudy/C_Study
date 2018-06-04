cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_FLAGS -std=c++17)

include_directories(
	modules
	Unity
	Catch2
	GTest/include
)

file(GLOB C_SRCS
	modules/factorial.c
)

file(GLOB CPP_SRCS
	modules/factorial.cpp
)

file (GLOB UNITY_SRCS
	Unity/unity.c
	Unity/unity_fixture.c
	tests/unity_main.c
)

file (GLOB CATCH2_SRCS
	tests/catch2_main.cpp
)

file (GLOB GTEST_SRCS
	tests/gtest_main.cpp
)

project(example1)
add_executable(example1 ${C_SRCS} ${UNITY_SRCS})

project(example2)
add_executable(example2 ${CPP_SRCS} ${CATCH2_SRCS})

project(example3)
add_executable(example3 ${CPP_SRCS} ${GTEST_SRCS})
target_link_libraries(example3 pthread gtest)