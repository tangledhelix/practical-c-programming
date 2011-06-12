#include <stdio.h>

int total;          /* total of all the numbers */
int current;        /* current value from the user */
int counter;        /* while loop counter */

char line[ 80 ];    /* line from keyboard */

int main( void ) {
	total = 0;
	counter = 0;
	while ( counter < 5 ) {
		printf( "Number? " );

		fgets( line, sizeof( line ), stdin );
		sscanf( line, "%d", &current );
		total += current;

		++counter;
	}

	printf( "The grand total is %d\n", total );
	return( 0 );
}

