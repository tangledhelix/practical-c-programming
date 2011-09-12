/**********************************************************************
 * What does this output? Try running it on your machine.
 * Why did it output what it did? Try checking the output of
 * the preprocessor.
 **********************************************************************/

/**********************************************************************
 * Using ++counter in this context is wrong. Passing ++counter to the
 * macro results in ((++counter) * (++counter)), leading to e.g.
 * 2 * 2 instead of 1 * 1. The prefix incrementor increments prior
 * to use, so it's technically predictable, but poor form.
 **********************************************************************/

/**********************************************************************
 * Why will it not produce expected output? By how much will the
 * counter go up each time?
 **********************************************************************/

/**********************************************************************
 * It will go up by two each time.
 *     SQR(++counter)
 * expands to
 *     ((++counter) * (++counter))
 * Prior to being used in an equation, the prefix increment
 * operator will increment counter by one, twice. Therefore
 * starting from 0, counter becomes 2 (2*2), next loop goes
 * to 4 (4*4) and so on. This is predictable. But bad practice.
 **********************************************************************/

#include <stdio.h>
#define SQR(x) ((x) * (x))

int main() {
	int counter;            /* counter for loop */

	counter = 0;

	while (counter < 5)
		printf("x %d square %d\n", counter, SQR(++counter));

	return(0);
}
