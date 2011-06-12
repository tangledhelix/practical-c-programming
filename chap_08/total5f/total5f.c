#include <stdio.h>

int total;          /* total of all the numbers */
int current;        /* current value from the user */
int counter;        /* for loop counter */

char line[ 80 ];    /* line from keyboard */

int main( void ) {
	total = 0;

	for ( counter = 0; counter < 5; ++counter ) {
		printf( "Number? " );

		fgets( line, sizeof( line ), stdin );
		sscanf( line, "%d", &current );
		total += current;
	}

	printf( "The grand total is %d\n", total );
	return( 0 );
}

