#include "unity.h"
#include "fizzbuzz.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_fizzbuzz_if_3_then_red(void) {
  color_t color = getColor(3);
  TEST_ASSERT_EQUAL(RED, color);
}

void test_fizzbuzz_if_5_then_green(void) {
  color_t color = getColor(5);
  TEST_ASSERT_EQUAL(GREEN, color);
}

void test_fizzbuzz_if_2_then_none(void) {
  color_t color = getColor(2);
  TEST_ASSERT_EQUAL(NONE, color);
}

void test_fizzbuzz_if_15_then_blue(void) {
  color_t color = getColor(15);
  TEST_ASSERT_EQUAL(BLUE, color);
}