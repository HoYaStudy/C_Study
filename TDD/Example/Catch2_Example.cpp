/*******************************************************************************
 * @file		Catch2_Example.c
 * @brief		TDD example with Unity.
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @note
 * 	- 2018.06.04	Created.
 ******************************************************************************/

#define CATCH_CONFIG_MAIN

/* Include Headers -----------------------------------------------------------*/
#include "Catch2/catch.hpp"
#include "factorial.h"

/* Tests ---------------------------------------------------------------------*/
TEST_CASE("Factorial", "[factorial]") {
	REQUIRE(factorial(0) == 0);
  REQUIRE(factorial(1) == 1);
  REQUIRE(factorial(2) == 2);
  REQUIRE(factorial(5) == 120);
}