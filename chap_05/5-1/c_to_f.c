/**********************************************************************
 * Write a program that converts Centigrade to Fahrenheit.
 * F = (9/5)C + 32
 *
 * Note: the math is totally broken if you use integers. For example
 * given int(100) as centigrade, integer math states the answer is
 * 132F, which is far from the correct answer (212F).
 **********************************************************************/

#include <stdio.h>

float fahrenheit;     /* degrees fahrenheit */
float centigrade;     /* degrees centigrade */
char line[ 50 ];      /* a line of input */

int main() {
	printf( "Enter a temperature (in C): " );
	fgets( line, sizeof( line ), stdin );
	sscanf( line, "%f", &centigrade );

	fahrenheit = ( ( 9.0 / 5.0 ) * centigrade ) + 32.0;
	printf( "%f degrees Fahrenheit.\n", fahrenheit );

	return( 0 );
}

