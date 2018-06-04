/*******************************************************************************
 * @file		factorial.c
 * @brief		TDD example function.
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @note
 * 	- 2018.06.04	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include "factorial.h"

/* APIs ----------------------------------------------------------------------*/
int factorial(int n) {
  int result = 1;
  for (int i = 1; i <= n; ++i) {
    result *= i;
  }
  return result;
}