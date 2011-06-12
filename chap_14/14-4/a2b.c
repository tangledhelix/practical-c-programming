/**********************************************************************
 * Write a program that reads an ASCII file containing a list of
 * numbers and writes a binary file containing the same list. Write a
 * program that goes the other way so that you can check your work.
 **********************************************************************/

/**********************************************************************
 * file format (in): one number per line, %d\n
 * file format (out): %d\0%d\0 ...
 **********************************************************************/

#include <stdio.h>

const char *ascii_filename = "file.txt";
const char *binary_filename = "file.bin";

int main() {

	FILE *afile;            /* file pointer for ascii file */
	FILE *bfile;            /* file pointer for binary file */

	int c;                  /* a character from a file */

	afile = fopen( ascii_filename, "r" );
	if ( afile == NULL ) {
		fprintf( stderr, "Error: problem opening %s for reading\n", ascii_filename );
		return( 8 );
	}

	bfile = fopen( binary_filename, "w+" );
	if ( bfile == NULL ) {
		fprintf( stderr, "Error: problem opening %s for writing\n", binary_filename );
		fclose( afile );
		return( 8 );
	}

	/* TODO: now that both files are open, read in the ascii file
	 * and write out the binary file
	 */

	while ( 1 ) {
		c = fgetc( afile );
		if ( c == EOF ) {
			break;
		}

		/* if we are at newline, output a separator (NULL) */
		if ( c == '\n' ) {
			fputc( '\0', bfile );
		} else {
			fputc( c, bfile );
		}
	}

	fclose( afile );
	fclose( bfile );

	return( 0 );
}

