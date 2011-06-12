/**********************************************************************
 * Salestax
 *
 * Calculate an 8% sales tax, then round to nearest penny.
 * Enter a value of 0 to quit the program.
 **********************************************************************/

/*#define DEBUG*/
#undef DEBUG

#include <stdio.h>

char line[ 100 ];               /* line of input from keyboard */

float amount;                   /* amount of transaction */
float tax;                      /* amount of tax */

float total;                    /* transaction with tax added */

const float TAX_RATE = 0.08;    /* rate of taxation (8%) */

int main() {

	while ( 1 ) {

		printf( "\nEnter an amount or '0' to quit: " );
		fgets( line, sizeof( line ), stdin );
		sscanf( line, "%f", &amount );

		if ( amount == 0.0 ) {
			printf( "Quitting.\n" );
			return( 0 );
		}

		tax = amount * TAX_RATE;
		total = amount + tax;

#ifdef DEBUG
		printf( "DEBUG:main(): Amount is %f\n", amount );
		printf( "DEBUG:main(): Tax is %f\n", tax );
		printf( "DEBUG:main(): Total is %f\n", total );
#endif

		printf( "Total is %0.2f\n", total );

	}

	return( 0 );
}

