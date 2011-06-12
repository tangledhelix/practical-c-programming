/**********************************************************************
 * Write a program that will take the bits in a number and shift them
 * to the left end. For example, 01010110 (binary) would become
 * 11110000 (binary).
 **********************************************************************/

#include <stdio.h>

#define BIT_DEPTH 8

unsigned char number;        /* 8 bits */
int i;              /* a loop counter */

int count;          /* a bit count */

int main() {

	/* 01010110 = 2 + 4 + 16 + 64 = 86 */
	number = 86;

	/* desired: 11110000 = 16 + 32 + 64 + 128 = 240 */

	count = bitcounter( number );
	printf( "Count: %d\n", count );
	printf( "before transform (want 86): %d\n", number );

	/* do transformation here */
	/* take the count, set the bits to 1 starting at
	 * the left. when you run the count out, start
	 * setting them to 0 until you run out.
	 */
	for ( i = BIT_DEPTH - 1; i >= 0; --i ) {
		if ( count ) {
			/* set this bit to 1 */
			printf( "set bit %d to 1\n", i );
			number |= ( 1 << i );

			/* decrement so we'll reach 0 */
			--count;
		} else {
			/* set this bit to 0 */
			printf( "set bit %d to 0\n", i );
			number &= ~( 1 << i );
		}
	}

	printf( "after transform (want 240): %d\n", number );

	return( 0 );
}

int bitcounter( int number ) {
	int i;          /* loop iterator */
	int count;      /* bit counter */

	count = 0;

	/* we look at the rightmost 16 bits */
	for ( i = 0; i < BIT_DEPTH; ++i ) {
		if ( number & ( 1 << i ) ) {
			++count;
		}
	}

	return count;
}

