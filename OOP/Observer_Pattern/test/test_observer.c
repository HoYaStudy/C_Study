#include "observer.h"
#include "unity.h"

/* Private Functions for Test ------------------------------------------------*/
static void observer1(uint32_t value1, uint32_t value2);
static void observer2(uint32_t value1, uint32_t value2);
static void observer3(uint32_t value1, uint32_t value2);
static void observer4(uint32_t value1, uint32_t value2);
static void observer5(uint32_t value1, uint32_t value2);
static void observer6(uint32_t value1, uint32_t value2);
static void observer7(uint32_t value1, uint32_t value2);
static void observer8(uint32_t value1, uint32_t value2);
static void observer9(uint32_t value1, uint32_t value2);
static void observer10(uint32_t value1, uint32_t value2);
static void observer11(uint32_t value1, uint32_t value2);

void setUp(void) { init_observer(); }

void tearDown(void) {}

void test_observer_SucceedRegisterAndUnregisterObserver(void) {
  TEST_ASSERT_TRUE(register_observer(observer1));
  TEST_ASSERT_TRUE(unregister_observer(observer1));
}

void test_observer_FailRegisterObserver(void) {
  TEST_ASSERT_TRUE(register_observer(observer1));
  TEST_ASSERT_TRUE(register_observer(observer2));
  TEST_ASSERT_TRUE(register_observer(observer3));
  TEST_ASSERT_TRUE(register_observer(observer4));
  TEST_ASSERT_TRUE(register_observer(observer5));
  TEST_ASSERT_TRUE(register_observer(observer6));
  TEST_ASSERT_TRUE(register_observer(observer7));
  TEST_ASSERT_TRUE(register_observer(observer8));
  TEST_ASSERT_TRUE(register_observer(observer9));
  TEST_ASSERT_TRUE(register_observer(observer10));
  TEST_ASSERT_FALSE(register_observer(observer11));
}

void test_observer_FailUnregisterObserver(void) {
  TEST_ASSERT_TRUE(register_observer(observer1));
  TEST_ASSERT_TRUE(unregister_observer(observer1));
  TEST_ASSERT_FALSE(unregister_observer(observer1));
}

/* Private Functions ---------------------------------------------------------*/
static void observer1(uint32_t value1, uint32_t value2) {
  printf("Observer 1: %u, %u\n", value1, value2);
}

static void observer2(uint32_t value1, uint32_t value2) {
  printf("Observer 2: %u, %u\n", value1, value2);
}

static void observer3(uint32_t value1, uint32_t value2) {
  printf("Observer 3: %u, %u\n", value1, value2);
}

static void observer4(uint32_t value1, uint32_t value2) {
  printf("Observer 4: %u, %u\n", value1, value2);
}

static void observer5(uint32_t value1, uint32_t value2) {
  printf("Observer 5: %u, %u\n", value1, value2);
}

static void observer6(uint32_t value1, uint32_t value2) {
  printf("Observer 6: %u, %u\n", value1, value2);
}

static void observer7(uint32_t value1, uint32_t value2) {
  printf("Observer 7: %u, %u\n", value1, value2);
}

static void observer8(uint32_t value1, uint32_t value2) {
  printf("Observer 8: %u, %u\n", value1, value2);
}

static void observer9(uint32_t value1, uint32_t value2) {
  printf("Observer 9: %u, %u\n", value1, value2);
}

static void observer10(uint32_t value1, uint32_t value2) {
  printf("Observer 10: %u, %u\n", value1, value2);
}

static void observer11(uint32_t value1, uint32_t value2) {
  printf("Observer 11: %u, %u\n", value1, value2);
}