/**********************************************************************
 * Why does test #3 fail to print "Both are not zero" ?
 **********************************************************************/

/**********************************************************************
 * 4 = 0100
 * 2 = 0010
 *     ----
 *     0000
 *
 * (4 & 2) is false (0000). they have zero bits in common.
 **********************************************************************/

#include <stdio.h>

int main() {
	int i1, i2;     /* two random integers */

	i1 = 4;
	i2 = 2;

	/* Nice way of writing the conditional */
	if ( ( i1 != 0 ) && ( i2 != 0 ) ) {
		printf( "Both are not zero\n" );
	}

	/* Shorthand way of doing the same thing */
	/* Correct C code, but rotten style */
	if ( i1 && i2 ) {
		printf( "Both are not zero\n" );
	}

	/* Incorrect use of bitwise and resulting in an error */
	if ( i1 & i2 ) {
		printf( "Both are not zero\n" );
	}

	return( 0 );
}

