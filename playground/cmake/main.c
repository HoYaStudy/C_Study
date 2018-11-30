/*******************************************************************************
 * @brief		main
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0.0
 * @history
 * 	2018.11.28	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <stdio.h>

#include "file_a.h"
#include "sub_b/file_b.h"
#include "sub_c/file_c.h"

/* Main Routine --------------------------------------------------------------*/
int main(void) {
	printf("Hello World!\n");
	func_a();
	func_b();
	func_c();

	return 0;
}
