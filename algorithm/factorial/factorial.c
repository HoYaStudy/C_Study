/*******************************************************************************
 * @brief		Factorial algorithm.
 * @author	llChameleoNll <hoya128@gmail.com>
 * @version	v0.0
 * @history
 * 		2017.03.31 - Created
 ******************************************************************************/

/* Include Header ------------------------------------------------------------*/
// standard
#include <stdio.h>

/* Private Function Prototype ------------------------------------------------*/
static const int factorial(const int _number);

/* Function ------------------------------------------------------------------*/
int main(int argc, char* argv[])
{
  if (factorial(0) != 1)  printf("[Error]: factorial(0) - Expected: %d, Result: %d\n", 1, factorial(0));
  if (factorial(1) != 1)  printf("[Error]: factorial(1) - Expected: %d, Result: %d\n", 1, factorial(1));
  if (factorial(2) != 2)  printf("[Error]: factorial(2) - Expected: %d, Result: %d\n", 2, factorial(2));
  if (factorial(3) != 6)  printf("[Error]: factorial(3) - Expected: %d, Result: %d\n", 6, factorial(3));
  if (factorial(4) != 24)  printf("[Error]: factorial(4) - Expected: %d, Result: %d\n", 24, factorial(4));
  if (factorial(5) != 120)  printf("[Error]: factorial(5) - Expected: %d, Result: %d\n", 120, factorial(5));

  return 0;
}

/* Private Function ----------------------------------------------------------*/
static const int factorial(const int _number) {
  // Error Handling
  if (_number < 0)  return -1;

  // 1. Recursive
  if (_number == 0 || _number == 1) return 1;
  return _number * factorial(_number -1);

  // 2. While Loop
  // if (_number == 0) return 1;
  // int loop = _number;
  // int result = _number;
  // while (loop-- > 1) {
  //   result *= loop;
  // }
  // return result;

  // 3. For Loop
  // int result = 1;
  // if (_number == 0) return 1;
  // for (int i = 1; i <= _number; ++i) {
  //   result *= i;
  // }
  // return result;
}