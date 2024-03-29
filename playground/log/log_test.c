/*******************************************************************************
 * @file		log_test.c
 * @brief		Test log module.
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @note
 *	- 2018.01.28	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
// Standard
#include <stdlib.h>
// System
#include "log.h"

/* Main Function -------------------------------------------------------------*/
int main(int argc, char* argv[]) {
	(void)argc;
	(void)argv;

	LOG("This is a test string");

	int d = 1;
	LOG("Formatter test: %d", d);

	LOG_User("This is a user String");
	LOG_System("This is a system String");
	LOG_Debug("This is a debug String");

	char test[64];
	for (int i = 0; i < 64; ++i) {
		test[i] = rand() % 128;
	}
	LOG_Dump(test, 5);
	LOG_Dump(test, 48);

	return 0;
}
