cmake_minimum_required(VERSION 3.8)

project(cmake_test)

add_library(module_a STATIC file_a.c)
add_library(module_b STATIC sub_b/file_b.c)
add_library(module_c STATIC sub_c/file_c.c)

add_executable(cmake_test main.c)

target_link_libraries(cmake_test module_a module_b module_c)

add_custom_target(
	cleanup
	COMMAND rm -rf *
)
