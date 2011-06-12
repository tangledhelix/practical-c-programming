#include <stdio.h>

/*
 * The main program opens this file if -S is on the command line.
 */

FILE *save_file = NULL;

/**********************************************************************
 * extended_fgets -- Gets a line from the input file
 *              and records it in a save file if needed.
 *
 * Parameters
 *      line -- The line to read.
 *      size -- sizeof( line ) -- maximum number of
 *                          characters to read.
 *      file -- File to read data from
 *                      (normally stdin).
 *
 * Returns
 *      NULL -- error or end-of-file in read
 *      otherwise line (just like fgets).
 **********************************************************************/

char *extended_fgets( char *line, int size, FILE *file ) {

	char *result;           /* result of fgets */

	result = fgets( line, size, file );

	/* did somsone ask for a save file?? */
	if ( save_file != NULL ) {
		fputs( line, save_file ); /* save line in file */
	}

	return( result );
}

