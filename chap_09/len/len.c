/**********************************************************************
 * Question:
 *     Why does this program always report the length
 *     of any string as 0?
 *
 * A sample "main" has been provided. It will ask for a string
 * and then print the length.
 **********************************************************************/

#include <stdio.h>

/**********************************************************************
 * length -- Compute the length of a string.
 *
 * Parameters
 *     string -- The string whose length we want.
 *
 * Returns
 *     the length of the string.
 **********************************************************************/

int length( char string[] ) {
	int index;              /* index into the string */

	/*
	 * Loop until we reach the end of string character
	 */
	/* Answer: this loop contained only the return, so it
	 * only ever ran once. Solution: add braces.
	 */
	/*for ( index = 0; string[ index ] != '\0'; ++index )*/
		/*[> do nothing <]*/
	/*return( index );*/

	for ( index = 0; string[ index ] != '\0'; ++index ) {
		/* do nothing */
	}
	return( index );
}

int main() {
	char line[ 100 ];           /* input line from user */

	while ( 1 ) {
		printf( "Enter line: " );
		fgets( line, sizeof( line ), stdin );
		printf( "Length (including newline) is: %d\n", length( line ) );
	}
}

