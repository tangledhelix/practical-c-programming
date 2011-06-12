/**********************************************************************
 * Write a function that takes a single string as its argument and
 * returns a pointer to the first nonwhite character in the string.
 **********************************************************************/

#include <stdio.h>
#include <string.h>

/**********************************************************************
 * find_nonwhite( mystring )
 *
 * Find the first nonwhite character in the string, and return a
 * pointer to it.
 *
 * Whitespace is defined as space or tab. Newline doesn't count
 * because if you are using keyboard input, newline can't
 * be before the string.
 *
 * Returns pointer to the first nonwhite character in the string.
 **********************************************************************/

char *find_nonwhite( char *mystring ) {

	/* as long as the first character is still whitespace,
	 * increment the pointer and try again.
	 */
	while ( ( mystring[ 0 ] == ' ' ) || ( mystring[ 0 ] == '\t' ) ) {
		++mystring;
	}

	return mystring;
}

int main() {

	char line[ 100 ];               /* a line of keyboard input */

	printf( "Enter a string: " );
	fgets( line, sizeof( line ), stdin );

	/* no newline needed, it is supplied in input */
	printf( "Result: %s", find_nonwhite( line ) );
	return( 0 );
}

