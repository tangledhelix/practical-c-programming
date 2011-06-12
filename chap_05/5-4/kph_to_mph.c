/**********************************************************************
 * Write a program that converts kilometers per hour to miles per
 * hour.
 *
 * miles = ( kilometer * 0.6213712 )
 **********************************************************************/

#include <stdio.h>

float kph;          /* kilometers per hour */
float mph;          /* miles per hour (computed) */
char line[ 50 ];    /* a line from the keyboard */

int main() {
	printf( "Enter kilometers per hour: " );
	fgets( line, sizeof( line ), stdin );
	sscanf( line, "%f", &kph );

	mph = ( kph * 0.6213712 );
	printf( "%f miles per hour\n", mph );

	return( 0 );
}

