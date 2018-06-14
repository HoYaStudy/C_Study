#include "unity.h"
#include "lights.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_lights_SwitchOff(void) {
  Lights_SetHeadlightSwitchOff();
  TEST_ASSERT_EQUAL(false, Lights_IsHeadlightOn());
}

void test_lights_SwitchOn(void) {
  Lights_SetHeadlightSwitchOn();
  TEST_ASSERT_EQUAL(true, Lights_IsHeadlightOn());
}