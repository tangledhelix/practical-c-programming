/**********************************************************************
 * Write a program that takes minutes as input, and then
 * outputs the total number of hours and minutes.
 *
 * 90 minutes = 1 hour 30 minutes
 **********************************************************************/

#include <stdio.h>

int total_minutes;  /* given number of minutes */
int hours;          /* number of hours (computed) */
int minutes;        /* number of minutes (computed) */

const int MINPERHOUR = 60;      /* number of minutes in 1 hour */

char line[ 50 ];    /* line of input from keyboard */

int main() {
	printf( "Enter minutes: " );
	fgets( line, sizeof( line ), stdin );
	sscanf( line, "%d", &total_minutes );

	hours = ( total_minutes / MINPERHOUR );
	minutes = ( total_minutes % MINPERHOUR );

	printf( "%d hours, %d minutes.\n", hours, minutes );

	return( 0 );
}

