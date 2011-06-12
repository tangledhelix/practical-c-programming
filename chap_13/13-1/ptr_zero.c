/**********************************************************************
 * Write a program that uses pointers to set each element of an array
 * to zero.
 **********************************************************************/

#include <stdio.h>

#define ARRAY_MAX 10

int values[ ARRAY_MAX ] = {            /* an array of numbers */
	9, 3, 15, 0, 14, -23, -4, 5, -8, 4
};

int i;                      /* index into an array */

int *values_ptr;            /* pointer into an array */

int main() {

	/* show the current array contents */
	for ( i = 0; i < ARRAY_MAX; ++i ) {
		printf( "values[%d] = %d\n", i, values[ i ] );
	}

	/* set a pointer to the start of array */
	values_ptr = &values[ 0 ];

	/* iterate over array, setting each element to 0 */
	for ( i = 0; i < ARRAY_MAX; ++i ) {
		*values_ptr = 0;
		++values_ptr;
	}

	/* now show the resulting array */
	printf( "--------------------\n" );
	for ( i = 0; i < ARRAY_MAX; ++i ) {
		printf( "values[%d] = %d\n", i, values[ i ] );
	}

	return( 0 );
}

