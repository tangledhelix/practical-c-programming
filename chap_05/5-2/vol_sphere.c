/**********************************************************************
 * Write a program to calculate the volume of a sphere.
 * (given radius)
 *
 * (4/3) * pi * r^3
 **********************************************************************/

#include <stdio.h>

float radius;       /* radius of the sphere */
float volume;       /* volume of the sphere (computed) */
char line[ 50 ];    /* a line from the keyboard */

/* the value of pi to 50 places, from wikipedia */
const float PI = 3.14159265358979323846264338327950288419716939937510;

int main() {
	printf( "Enter the radius: " );
	fgets( line, sizeof( line ), stdin );
	sscanf( line, "%f", &radius );

	volume = ( 4.0 / 3.0 ) * PI * ( radius * radius * radius );
	printf( "The volume is %f.\n", volume );

	return( 0 );
}

