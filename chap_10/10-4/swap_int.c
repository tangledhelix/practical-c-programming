/**********************************************************************
 * Write a preprocessor macro that swaps two integers. (For the real
 * hacker, write one that does not use a temporary variable declared
 * outside the macro.)
 **********************************************************************/

#include <stdio.h>

#define SWAP(x,y) (y)=(x)+(y);(x)=(y)-(x);(y)=(y)-(x);

int main( void ) {

	/* tested with pos and neg numbers, and when one value is 0 */
	int x = -3;
	int y = 1;

	printf( "x=%d y=%d\n", x, y );

	/* do swap */
	SWAP(x,y)

	printf( "x=%d y=%d\n", x, y );

	return( 0 );
}


/**********************************************************************
 * 2, 6         x, y
 * 2, 2+6       x, x+y      [x]
 * 2, 8         result
 * 8-2, 8       y-x, y      [x]
 * 6, 8         result
 * 6, 8-6       x, y-x      [ ]
 * 6, 2         result
 **********************************************************************/

