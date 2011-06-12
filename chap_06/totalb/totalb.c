#include <stdio.h>

char line[ 100 ];       /* line of keyboard input */
int total;              /* running total of all numbers so far */
int item;               /* next item to add to the list */
int minus_items;        /* number of negative items */

int main() {
	total = 0;
	minus_items = 0;

	while ( 1 ) {
		printf( "Enter # to add\n" );
		printf( "or 0 to stop: " );

		fgets( line, sizeof( line ), stdin );
		sscanf( line, "%d", &item );

		if ( item == 0 ) {
			break;
		}

		if ( item < 0 ) {
			++minus_items;
			continue;
		}

		total += item;
		printf( "Total: %d\n", total );
	}

	printf( "Final total %d\n", total );
	printf( "with %d negative items omitted\n", minus_items );

	return( 0 );
}
