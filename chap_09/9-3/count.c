/**********************************************************************
 * Write a function count( number, array, length ) that counts
 * the number of times number appears in array. The array has
 * length elements. The function should be recursive. Write
 * a test program to go with the function.
 **********************************************************************/

#include <stdio.h>

int count( int number, int array[], int length ) {

	/* we've reached the beginning of the array. */
	if ( length == 0 ) {
		return 0;
	}

	if ( array[ length - 1 ] == number ) {
		/* increment counter when we find a match */
		return( 1 + count( number, array, length - 1 ) );
	} else {
		return( count( number, array, length - 1 ) );
	}
}

int main( void ) {
	int result;

	int num_list1[] = { 45, 37, 45, 37, 45, 36, 45, 37, 45, 38 };
	printf( "Want: 5\n" );
	result = count( 45, num_list1, sizeof( num_list1 ) );
	printf( "Got: %d\n", result );

	int num_list2[] = { 3, 5, 7, 9, 3, 6, 8, 3, 4, 10, 3, 3, 3, 3, 3, 219437, 3 };
	printf( "Want: 9\n" );
	result = count( 3, num_list2, sizeof( num_list2 ) );
	printf( "Got: %d\n", result );

	int num_list3[] = { 5, 5, 5, 5, 5, 9, 5, 5, 5, 5, 5 };
	printf( "Want: 10\n" );
	result = count( 5, num_list3, sizeof( num_list3 ) );
	printf( "Got: %d\n", result );

	int num_list4[] = { 1, 8, 8, 8, 8, 8, 9, 8, 8, 8, 8, 8, 1 };
	printf( "Want: 10\n" );
	result = count( 8, num_list4, sizeof( num_list4 ) );
	printf( "Got: %d\n", result );

	return( 0 );
}

