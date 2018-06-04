cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_FLAGS -std=c++17)

include_directories(
	Unity
	Catch2
	GTest/include
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
	gtest_example.cpp
)

project(example1)
add_executable(example1 ${SRCS} ${UNITY_SRCS})

project(example2)
add_executable(example2 ${SRCS} ${CATCH2_SRCS})

project(example3)
add_executable(example3 ${SRCS} ${GTEST_SRCS})
target_link_libraries(example3 pthread gtest)