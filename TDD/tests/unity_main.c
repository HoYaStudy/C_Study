/*******************************************************************************
 * @file		unity_main.c
 * @brief		TDD example with Unity.
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @note
 * 	- 2018.06.01	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include "factorial.h"
#include "unity.h"
#include "unity_fixture.h"

/* Tests ---------------------------------------------------------------------*/
TEST_GROUP(Factorial);

TEST_SETUP(Factorial) {}

TEST_TEAR_DOWN(Factorial) {}

TEST(Factorial, Negative) { TEST_ASSERT_EQUAL(1, factorial(-1)); }

TEST(Factorial, Zero) { TEST_ASSERT_EQUAL(1, factorial(0)); }

TEST(Factorial, Positive) { TEST_ASSERT_EQUAL(120, factorial(5)); }

TEST_GROUP_RUNNER(Factorial) {
  RUN_TEST_CASE(Factorial, Negative);
  RUN_TEST_CASE(Factorial, Zero);
  RUN_TEST_CASE(Factorial, Positive);
}

static void RunAllTests(void) { RUN_TEST_GROUP(Factorial); }

int main(const int argc, const char* argv[]) {
  return UnityMain(argc, argv, RunAllTests);
}
