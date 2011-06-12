/**********************************************************************
 * Write a program to find the square of the distance between two
 * points. (For a more advanced problem, find the actual distance.
 * This problem involves using the standard function 'sqrt'. Use your
 * help system to find out more about how to use this function.)
 **********************************************************************/

#include <stdio.h>
#include <math.h>

char line[ 100 ];           /* a line of keyboard input */
float distance;             /* distance between two points */
float square;               /* the square of the distance */
float square_root;          /* the square root of square */

int main() {
	printf( "Enter the distance: " );
	fgets( line, sizeof( line ), stdin );
	sscanf( line, "%f", &distance );

	square = distance * distance;
	printf( "Square of distance is %f\n", square );

	square_root = sqrtf( square );
	printf( "Square root of previous result is %f\n", square_root );

	return( 0 );
}

