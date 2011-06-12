/**********************************************************************
 * The routine fputc can be used to write out a single byte of a
 * binary file. This writes out the numbers 0 to 127 in a file called
 * test.out. It works just fine on UNIX, creating a 128-byte long
 * file; however, on MS-DOS/Windows, the file contains 129 bytes. Why?
 **********************************************************************/

/**********************************************************************
 * Answer (not tested): file should be opened as wb, not w. CRLF is
 * being turned into CR, or LF, whichever. CR and LF happen to be
 * adjacent in the ASCII series.
 **********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#ifndef __MSDOS__
#include <unistd.h>
#endif

int main() {

	int cur_char;           /* current character to write */
	FILE *out_file;         /* output file */

	out_file = fopen( "test.out", "w" );
	if ( out_file == NULL ) {
		fprintf( stderr, "Cannot open output file\n" );
		exit( 8 );
	}

	for ( cur_char = 0; cur_char < 128; ++cur_char ) {
		fputc( cur_char, out_file );
	}

	fclose( out_file );
	return( 0 );
}

