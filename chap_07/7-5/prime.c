/**********************************************************************
 * Prime - given a number, determine if it is a prime number.
 *
 * A prime number is any number divisible only by 1 and itself.
 **********************************************************************/

#include <stdio.h>

char line[ 100 ];           /* a line of input from the keyboard */

int number;                 /* a number whose primeness is unclear */
int this_factor;            /* the current divisor/factor we're testing */
int last_factor;            /* the highest factor we will test */

int result;                 /* a place to store a result */

int main() {

	/* collect a number from the user */
	printf( "Enter a number: " );
	fgets( line, sizeof( line ), stdin );
	sscanf( line, "%d", &number );

	/* start with 2, test up to (number - 1) */
	this_factor = 2;
	last_factor = number - 1;

	/* iterate over every possible factor and test it */
	while ( this_factor < last_factor ) {
		result = number % this_factor;
		if ( result == 0 ) {
			result = number / this_factor;
			printf( "%d is not prime (%d * %d)\n",
					number, this_factor, result );
			return( 0 );
		}
		++this_factor;
	}

	/* if we have reached this point, the number is prime */
	printf( "%d is a prime number.\n", number );
	return( 0 );
}

