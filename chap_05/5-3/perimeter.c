/**********************************************************************
 * Write a program that prints the perimeter of a rectangle given its
 * height and width.
 *
 * perimeter = 2 * ( width + height )
 **********************************************************************/

#include <stdio.h>

float width;        /* width of the rectangle */
float height;       /* height of the rectangle */
float perimeter;    /* perimeter (computed) */
char line[ 50 ];    /* a line from the keyboard */

int main() {
	printf( "Rectangle's height? " );
	fgets( line, sizeof( line ), stdin );
	sscanf( line, "%f", &height );

	printf( "Rectangle's width? " );
	fgets( line, sizeof( line ), stdin );
	sscanf( line, "%f", &width );

	perimeter = 2.0 * ( height + width );

	printf( "Perimeter is %f\n", perimeter );

	return( 0 );
}

