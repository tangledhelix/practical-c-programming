#include <stdio.h>

void inc_count( int *count_ptr ) {
	(*count_ptr)++;
}

int main() {
	int count = 0;          /* number of times through */

	while ( count < 10 ) {
		inc_count( &count );
	}

	printf( "count is %d\n", count );

	return( 0 );
}

