#include <stdio.h>

FILE *save_file = NULL;             /* save input in this file */
FILE *playback_file = NULL;         /* playback data from this file */

/**********************************************************************
 * extended_fgets -- Gets a line from the input file
 *              and records it in a save file if needed.
 *
 * Parameters
 *      line -- The line to read.
 *      size -- sizeof(line) -- maximum number of
 *                          characters to read.
 *      file -- File to read data from
 *                      (normally stdin).
 *
 * Returns
 *      NULL -- error or end-of-file in read
 *      otherwise line (just like fgets).
 **********************************************************************/

char *extended_fgets(char *line, int size, FILE *file) {

	extern FILE *save_file;         /* file to save strings in */
	extern FILE *playback_file;     /* file for alternate input */

	char *result;           /* result of fgets */

	if (playback_file != NULL) {
		result = fgets(line, size, playback_file);
		/* echo the input to the standard out so the user sees it */
		fputs(line, stdout);

	} else {
		/* get the line normally */
		result = fgets(line, size, file);
	}

	/* did somsone ask for a save file?? */
	if (save_file != NULL) {
		fputs(line, save_file); /* save line in file */
	}

	return(result);
}

