/*******************************************************************************
 * @file		Unity_Example.c
 * @brief		TDD example with Unity.
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @note
 * 	- 2018.06.01	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include "Unity/unity.h"
#include "Unity/unity_fixture.h"

/* Tests ---------------------------------------------------------------------*/
TEST_GROUP(sprintf);

static char output[100];
static const char* expected;

TEST_SETUP(sprintf) {
  memset(output, 0xaa, sizeof output);
  expected = "";
}

TEST_TEAR_DOWN(sprintf) {}

static void expect(const char* s) { expected = s; }

static void given(int charsWritten) {
  TEST_ASSERT_EQUAL(strlen(expected), charsWritten);
  TEST_ASSERT_EQUAL_STRING(expected, output);
  TEST_ASSERT_BYTES_EQUAL(0xaa, output[strlen(expected) + 1]);
}

TEST(sprintf, NoFormatOperations) {
  expect("hey");
  given(sprintf(output, "hey"));
}

TEST(sprintf, InsertString) {
  expect("Hello World\n");
  given(sprintf(output, "Hello %s\n", "World"));
}

TEST_GROUP_RUNNER(sprintf) {
  RUN_TEST_CASE(sprintf, NoFormatOperations);
  RUN_TEST_CASE(sprintf, InsertString);
}

static void RunAllTests(void) { RUN_TEST_GROUP(sprintf); }

int main(int argc, char* argv[]) { return UnityMain(argc, argv, RunAllTests); }
