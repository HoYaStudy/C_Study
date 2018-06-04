#include "factorial.h"
#include "gtest/gtest.h"

TEST(FactorialTest, Negative) {
  EXPECT_EQ(1, factorial(-5));
  EXPECT_EQ(1, factorial(-1));
  EXPECT_GT(factorial(-10), 0);
}

TEST(Factorial, Zero) { EXPECT_EQ(1, Factorial(0)); }

TEST(Factorial, Positive) {
  EXPECT_EQ(1, Factorial(1));
  EXPECT_EQ(2, Factorial(2));
  EXPECT_EQ(6, Factorial(3));
  EXPECT_EQ(120, Factorial(5));
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  testing::GTEST_FLAG(catch_exceptions) = GTEST_ENABLE_CATCH_EXCEPTIONS_ != 0;
  return RUN_ALL_TESTS();
}