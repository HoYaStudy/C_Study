/*******************************************************************************
 * @brief		main
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0.0
 * @history
 * 	2018.11.28	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <stdio.h>

#include "config.h"

#ifdef MAKE_MODULE_A
#include "file_a.h"
#endif

#ifdef MAKE_MODULE_B
#include "file_b.h"
#endif

#ifdef MAKE_MODULE_C
#include "file_c.h"
#endif

/* Main Routine --------------------------------------------------------------*/
int main(void) {
	printf("Hello World!\n");
	printf("Version: %u.%u\n", MAJOR_VERSION, MINOR_VERSION);

	#ifdef MAKE_MODULE_A
	func_a();
	#endif

	#ifdef MAKE_MODULE_B
	func_b();
	#endif

	#ifdef MAKE_MODULE_C
	func_c();
	#endif

	return 0;
}
