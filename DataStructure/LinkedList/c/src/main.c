/*******************************************************************************
 * @brief		Test main.
 * @author	llChameleoNll <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2017.03.07	Created
 ******************************************************************************/

/* Include Header ------------------------------------------------------------*/
// standard
#include <stdio.h>
#include <stdlib.h>
// stack
#include "../inc/stack/stack.h"

/* Function ------------------------------------------------------------------*/
int main(void)
{
	// Setup
	createStack(intStack);
	createStack(doubleStack);

	// Test
	int	nA = 1;
	if (!pushStack(&intStack, &nA))
		return printf("[ERR] pushStack - 1\n");
	int nB = 2;
	if (!pushStack(&intStack, &nB))
		return printf("[ERR] pushStack - 2\n");
	if (!popStack(&intStack))
		return printf("[ERR] popStack - 2\n");
	if (!popStack(&intStack))
		return printf("[ERR] popStack - 1\n");
	nA = 3;
	if (!pushStack(&intStack, &nA))
		return printf("[ERR] popStack - 3\n");
	displayStack(intStack, 0);

	double	dA = 1.0;
	if (!pushStack(&doubleStack, &dA))
		return printf("[ERR] pushStack - 1.0\n");
	double	dB = 2.0;
	if (!pushStack(&doubleStack, &dB))
		return printf("[ERR] pushStack - 2.0\n");
	if (!popStack(&doubleStack))
		return printf("[ERR] popStack - 2.0\n");
	if (!popStack(&doubleStack))
		return printf("[ERR] popStack - 1.0\n");
	dA = 3.0;
	if (!pushStack(&doubleStack, &dA))
		return printf("[ERR] pushStack - 3.0\n");
	displayStack(doubleStack, 1);

	return 0;
}