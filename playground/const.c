/******************************************************************************
 * @brief		const keyword
 * @author	llHoYall <hoya128@gmail.com>
 * @version	v1.0
 * @history
 * 		2018.10.18	Created.
 *******************************************************************************
 * const는 pointer '*'를 기준으로 영향을 준다.
 * 왼쪽이면 값에, 오른쪽이면 pointer에 영향을 준다.
 * 따라서, <const int*> == <int const *>
 ******************************************************************************/

/* Include Headers -----------------------------------------------------------*/
#include <stdio.h>

/* Main Routine --------------------------------------------------------------*/
int main(void) {
	int nA = 1;
	int nB = 2;

	const int* pA = &nA;
	int const * pB = &nA;
	int* const pC = &nA;
	const int* const pD = &nA;
	
	printf("A: %p ", pA);
	pA = &nB;
	printf("=> %p\n", pA);
	// *pA = nA;		=> Error!
	
	printf("B: %p ", pB);
	pB = &nB;
	printf("=> %p\n", pB);
	// *pB = nB;		=> Error!
	
	// pC = &nA;		=> Error!
	printf("C: %d ", *pC);
	*pC = nB;
	printf("=> %d\n", *pC);

	// pD = &nB;		=> Error!
	// *pD = nA;		=> Error!

	return 0;
}

