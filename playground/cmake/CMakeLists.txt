cmake_minimum_required(VERSION 3.8)

include(tool.cmake)

option(MAKE_MODULE_A "Is make module a?" ON)
option(MAKE_MODULE_B "Is make module b?" ON)
option(MAKE_MODULE_C "Is make module c?" ON)

set(MAJOR_VERSION		1)
set(MINOR_VERSION		0)

project(cmake_test)

configure_file(
	"${PROJECT_SOURCE_DIR}/config.h.in"
	"${PROJECT_BINARY_DIR}/config.h"
)

include_directories("${PROJECT_BINARY_DIR}")

if (MAKE_MODULE_A)
	include_directories("${PROJECT_SOURCE_DIR}")
	add_library(module_a STATIC file_a.c)
endif (MAKE_MODULE_A)

if (MAKE_MODULE_B)
	include_directories("${PROJECT_SOURCE_DIR}/sub_b")
	add_library(module_b STATIC sub_b/file_b.c)
endif (MAKE_MODULE_B)

if (MAKE_MODULE_C)
	include_directories("${PROJECT_SOURCE_DIR}/sub_c")
	add_library(module_c STATIC sub_c/file_c.c)
endif (MAKE_MODULE_C)

add_executable(cmake_test main.c)

target_link_libraries(cmake_test module_a module_b module_c)

add_custom_target(
	cleanup
	COMMAND rm -rf *
)
