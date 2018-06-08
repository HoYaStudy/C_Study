/*******************************************************************************
 * @brief			Tests for message module.
 * @author		llHoYall <hoya128@gmail.com>
 * @version		v1.0.0
 * @note
 * 	- 2018.06.07	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
// Test Harness
#include "unity.h"
#include "unity_fixture.h"
// Module under test
#include "message.h"

/* Tests ---------------------------------------------------------------------*/
TEST_GROUP(Message);

TEST_SETUP(Message) {}

TEST_TEAR_DOWN(Message) {}

TEST(Message, Clear) { TEST_ASSERT_EQUAL(0, clearMessage()); }

TEST_GROUP_RUNNER(Message) { RUN_TEST_CASE(Message, Clear); }

static void RunAllTests(void) { RUN_TEST_GROUP(Message); }

int main(const int argc, const char *argv[]) {
  return UnityMain(argc, argv, RunAllTests);
}
