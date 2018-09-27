/*******************************************************************************
 * @brief		공백 문자가 삽입된 문자열 입력받기
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2017.09.22	Created.
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <stdio.h>

/* Private Variables ---------------------------------------------------------*/
static char string[128] = { 0 };

/* Main Routines -------------------------------------------------------------*/
int main(void) {
	// 1. using fgets()
	fgets(string, sizeof(string), stdin);

	// 2. using scanf()
	// 		[] - scanset character
	//		^\n - while the input is not a newline take input
	//		%*c - reads the newline character from the input buffer
	// scanf("%[^\n]%*c", string);

	printf("Result: %s\n", string);

	return 0;
}
