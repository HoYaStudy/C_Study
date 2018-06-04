/* Include Headers -----------------------------------------------------------*/
#include <limits>
#include "gtest/gtest.h"
#include "factorial.h"

/* Tests ---------------------------------------------------------------------*/
TEST(FactorialTest, Negative) {
  EXPECT_EQ(1, factorial(-5));
  EXPECT_EQ(1, factorial(-1));
  EXPECT_GT(factorial(-10), 0);
}

TEST(Factorial, Zero) { EXPECT_EQ(1, factorial(0)); }

TEST(Factorial, Positive) {
  EXPECT_EQ(1, factorial(1));
  EXPECT_EQ(2, factorial(2));
  EXPECT_EQ(6, factorial(3));
  EXPECT_EQ(120, factorial(5));
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}