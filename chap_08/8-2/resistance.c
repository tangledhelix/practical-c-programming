/**********************************************************************
 * Resistance - calculate the resistance of any number of resistors
 * in a parallel configuration.
 *
 * Formula:
 * 1/R = 1/R1 + 1/R2 + 1/R3 + ... + 1/Rn
 **********************************************************************/

/*
 * Al helped me with the math on this one, which was eluding me.
 * Basically, as each value comes in, we calculate (1.0 / value)
 * and store it as a running tally (no problem due to the additive
 * property). Then, instead of inverting things in fraction form,
 * we just take (1.0 / running_total) and that give us the final
 * answer. Basically we created a right-side fraction that is
 * (value / 1), so we have 1/R = V/1. Then we can flip both
 * sides to get R = 1/V, calculate 1/V and we're done.
 */

#include <stdio.h>

char line[ 100 ];           /* line of input from keyboard */

float this_resistance;      /* the current resistor's rating */
float running_total;        /* running total of resistors */

int main( void ) {

	while ( 1 ) {
	
		printf( "Enter resistance in ohms (0 to end): " );
		fgets( line, sizeof( line ), stdin );
		sscanf( line, "%f", &this_resistance );

		if ( this_resistance == 0.0 ) {
			printf( "Result: %0.04f\n", 1.0 / running_total );
			return( 0 );
		}

		/* add this to our running total of 1/Rn */
		running_total += 1.0 / this_resistance;

	}
}

