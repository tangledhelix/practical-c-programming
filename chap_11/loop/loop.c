/**********************************************************************
 * The first loop works, but the second fails. Why?
 **********************************************************************/

#include <stdio.h>

int main(void) {
	short int i;            /* loop counter */
	signed char ch;         /* loop counter of another kind */

	/* Works */

	/* how this works:
	 * starts as 0x80 (10000000), with each iteration, shifts one
	 * to the right (01000000, 00100000, 00010000, ...) until it
	 * reaches 0x0, at which point the loop ends.
	 */
	for (i = 0x80; i != 0; i = (i >> 1)) {
		printf("i is %x (%d)\n", i, i);
	}

	/* Fails */

	/* how this works:
	 * starts as 0x80 (10000000), with each iteration, shifts
	 * one to the right (01000000, 00100000, ...) but it is
	 * signed, so it is dragging the sign bit in from the left.
	 * The value never reaches zero as a result, and the loop
	 * never ends, terminating in an infinite loop with a decimal
	 * value of -1.
	 */
	for (ch = 0x80; ch != 0; ch = (ch >> 1)) {
		printf("ch is %x (%d)\n", ch, ch);
	}

	return(0);
}

