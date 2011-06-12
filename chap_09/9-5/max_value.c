/**********************************************************************
 * Write a function that returns the maximum value of an array of numbers.
 **********************************************************************/

#include <stdio.h>

int high_water_mark( int values[] ) {
	int high_mark;      /* current largest value */
	int i;              /* index into an array */

	high_mark = 0;

	for ( i = 0; i < sizeof( values ); ++i ) {
		if ( values[ i ] > high_mark ) {
			high_mark = values[ i ];
		}
	}

	return high_mark;
}

int main( void ) {
	int values[] = { 3, 5, 7, 58, 910, 4, 64, 3 };

	printf( "Result: %d\n", high_water_mark( values ) );
	return( 0 );
}

