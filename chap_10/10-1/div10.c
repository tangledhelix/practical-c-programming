/**********************************************************************
 * Write a macro that returns TRUE if its parameter is divisible by 10
 * and FALSE otherwise.
 **********************************************************************/

#include <stdio.h>

#define TEN_DIVISIBLE(number) ((number) % 10 == 0)

int main() {
	if (TEN_DIVISIBLE(5)) {
		printf("wtf\n");
	} else {
		printf("ok, good\n");
	}

	if (TEN_DIVISIBLE(62)) {
		printf("wtf\n");
	} else {
		printf("ok, good\n");
	}

	if (TEN_DIVISIBLE(50)) {
		printf("ok, good\n");
	} else {
		printf("wtf\n");
	}

	return(0);
}

