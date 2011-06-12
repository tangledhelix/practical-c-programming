
#include <stdio.h>

char line[ 100 ];       /* line of data from input */
int result;             /* the result of the calculation */
char operator;          /* operator the user specified */
int value;              /* value specified after the operator */

int main() {
	result = 0;         /* initialize the result */

	/* Loop forever (or until we hit the break statement) */
	while ( 1 ) {
		printf( "Result: %d\n", result );

		printf( "Enter operator and number: " );
		fgets( line, sizeof( line ), stdin );
		sscanf( line, "%c %d", &operator, &value );
		printf( "## after scanf %c\n", operator );

		if ( operator = '+' ) {
			printf( "## after if %c\n", operator );
			result += value;
		} else {
			printf( "Unknown operator %c\n", operator );
		}
	}
}
