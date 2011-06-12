/**********************************************************************
 * No matter what filename we give, our program can't find it. Why?
 **********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	char name[ 100 ];               /* name of the file to use */
	FILE *in_file;                  /* file for input */

	printf( "Name? " );
	fgets( name, sizeof( name ), stdin );

	/* Answer: because we left the newline in place.
	 * Let's remove it and try again.
	 */
	name[ strlen( name ) - 1 ] = '\0';

	in_file = fopen( name, "r" );
	if ( in_file == NULL ) {
		fprintf( stderr, "Could not open file\n" );
		exit( 8 );
	}

	printf( "File found\n" );
	fclose( in_file );
	return( 0 );
}

