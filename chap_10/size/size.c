/**********************************************************************
 * This computes the wrong value for size. Why?
 **********************************************************************/

#include <stdio.h>

#define SIZE   10;
#define FUDGE  SIZE - 2;

int main() {
	int size;           /* size to really use */

	/* this evals to:
	 *     size = 10; - 2;;
	 * and that first semicolons hoses it.
	 */
	size = FUDGE;
	printf("Size is %d\n", size);
	return(0);
}

