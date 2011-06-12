/**********************************************************************
 * Write a program that takes a 32-bit integer (long int) and splits it
 * into eight 4-bit values. (Be careful of the sign bit.)
 **********************************************************************/

#include <stdio.h>

long int number;        /* just int would probably be 32 bits... */
int results[ 8 ];       /* somewhere to store the result */

int main( void ) {

	number = 69005;     /* whatever value */
	int i, j;           /* loop counters */
	int pos;            /* position into the bits */

	pos = 0;            /* reset to zero */

	/* iterate over the 8 sections, which are 4 bits each */
	/* this is done with a descending counter because then the
	 * results are stored in the proper order (0 through 7)
	 * instead of being backward
	 */
	for ( i = 7; i >= 0; --i ) {

		/* initialize this loop-around's result container to zero */
		results[ i ] = 0;
		printf( "DEBUG: store into [%d]\n", i );

		/* iterate over the 4 bits in this section */
		for ( j = 0; j < 4; ++j ) {

			/* examine this bit (position pos) */
			printf( "DEGBUG: bit %d: ", pos );
			if ( ( number & ( 1 << pos ) ) != 0 ) {
				printf( "1\n" );
				results[ i ] |= ( 1 << j );
			} else {
				printf( "0\n" );
			}

			/* move counter to next bit */
			++pos;
		}
	}

	printf( "\n" );

	/* not right... if anything, 65535 bit needs to be set. */
	/* |.||  ...|  |.||  ....  |...  ....  ....  .... */
	/* 1011  0001  1011  0000  1000  0000  0000  0000 */
	/*                      6  3184  2152  1631  8421 */
	/*                      5  2610  0015  2426       */
	/*                      5  7399  4226  8          */
	/*                      3  6826  84               */
	/*                      6  84                     */

	/* 69005:
	 * 0000  0000  0000  0001  0000  1101  1000  1101
	 * bits are in reverse order!
	 *
	 * result after debug:
	 * 0000  0000  0000  0001  0000  1101  1000  1101
	 * finally right.
	 */

	/* Iterate over the results, see if they're right */
	/* this is just a double-check to see if they're in
	 * the right positions (we don't want all the values
	 * to be on the left side near element 0).
	 */
	for ( i = 0; i < 8; ++i ) {

		printf( "%d", results[ i ] );

		printf( "  " );
	}

	printf( "\n" );

	return( 0 );
}


