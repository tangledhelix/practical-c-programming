/**********************************************************************
 * Write a program that deliberately makes the following mistakes:
 *
 * - Prints a floating-point number using the %d conversion.
 * - Prints an integer using the %f conversion.
 * - Prints a character using the %d conversion.
 **********************************************************************/

#include <stdio.h>

float floatnum;     /* a floating-point number */
int intnum;         /* an integer */
char character;     /* a character */

int main() {
	floatnum = 1.0;
	intnum = 1;
	character = 'A';

	printf( "%f as %%d: %d\n", floatnum, floatnum );
	printf( "%d as %%f: %f\n", intnum, intnum );
	printf( "%c as %%d: %d\n", character, character );

	return( 0 );
}

