cmake_minimum_required(VERSION 3.5)

project(example1)

include_directories(Unity)

file(GLOB SRCS
	Unity/unity.c
	Unity/unity_fixture.c
	Unity_Example.c
)

add_executable(example1 ${SRCS})
