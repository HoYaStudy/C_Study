cmake_minimum_required(VERSION 3.0.0)

project(Test_Queue VERSION 1.0.0)

enable_testing()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

include_directories(DataStructure/Queue/src)

add_subdirectory(googletest)

add_executable(Test_Queue tests/test_queue.cpp DataStructure/Queue/src/message_queue.c)

target_link_libraries(Test_Queue gtest)

add_test(NAME Test_Queue COMMAND Test_Queue)
