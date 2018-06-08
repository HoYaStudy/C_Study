cmake_minimum_required(VERSION 3.5)

include_directories(
	message
	test/Unity
)

file (GLOB MSG_SRCS
	message/message.c
)

file (GLOB MAIN_SRCS
	main.c
)

file (GLOB UNITY_SRCS
	test/Unity/unity.c
	test/Unity/unity_fixture.c
)

file (GLOB TEST_SRCS
	test/test_message.c
)

project (app)
add_executable(app ${MAIN_SRCS} ${MSG_SRCS})
target_link_libraries(app pthread)

project (unittest)
add_executable(unittest ${UNITY_SRCS} ${TEST_SRCS} ${MSG_SRCS})