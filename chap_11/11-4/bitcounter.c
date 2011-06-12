/**********************************************************************
 * Write a program that counts the number of bits set in an integer.
 * For example, the number 5 (decimal), which is 0000000000000101
 * (binary), has two bits set.
 **********************************************************************/

#include <stdio.h>

/* Number of bits we examine (from the right) */
#define BIT_DEPTH 16

int main( void ) {

	/* 0000000000000101 = 2 */
	printf( "(%d) want: 2 got: %d\n", 5, bitcounter( 5 ) );

	/* 0000000000001000 = 1 */
	printf( "(%d) want: 1 got: %d\n", 8, bitcounter( 8 ) );

	/* 0000000000001111 = 4 */
	printf( "(%d) want: 4 got: %d\n", 15, bitcounter( 15 ) );

	/* 0000000101101101 = 6 */
	printf( "(%d) want: 6 got: %d\n", 365, bitcounter( 365 ) );

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

