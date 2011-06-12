/**********************************************************************
 * Write a function that scans a character array for the character - and
 * replaces it with _.
 **********************************************************************/

#include <stdio.h>

void replace( char char_array[] ) {
	int i;          /* index into an array */

	for ( i = 0; i < sizeof( char_array ); ++i ) {
		if ( char_array[ i ] == '-' ) {
			char_array[ i ] = '_';
		}
	}
}

int main( void ) {
	int i;          /* index into an array */

	char chars[] = { 'f', 'o', 'o', '-', 'b', '_', 'r' };
	replace( chars );

	for ( i = 0; i < sizeof( chars ); ++i ) {
		printf( "%c\n", chars[ i ] );
	}

	return( 0 );
}

