/**********************************************************************
 * Write a program that reads an ASCII file containing a list of
 * numbers and writes a binary file containing the same list. Write a
 * program that goes the other way so that you can check your work.
 * (this is the second version.)
 **********************************************************************/

/**********************************************************************
 * file format (in): %d\0%d\0 ...
 * file format (out): one number per line, %d\n
 **********************************************************************/

#include <stdio.h>

const char *ascii_filename = "file-out.txt";
const char *binary_filename = "file.bin";

int main() {

	FILE *afile;            /* file pointer for ascii file */
	FILE *bfile;            /* file pointer for binary file */

	int c;                  /* a character from a file */

	bfile = fopen(binary_filename, "r");
	if (bfile == NULL) {
		fprintf(stderr, "Error: problem opening %s for reading\n", binary_filename);
		return(8);
	}

	afile = fopen(ascii_filename, "w+");
	if (afile == NULL) {
		fprintf(stderr, "Error: problem opening %s for writing\n", ascii_filename);
		fclose(bfile);
		return(8);
	}

	/* TODO: now that both files are open, read in the binary file
	 * and write out the ascii file
	 */

	while (1) {
		c = fgetc(bfile);
		if (c == EOF) {
			break;
		}

		/* if we are at NULL, output a separator (newline) */
		if (c == '\0') {
			fputc('\n', afile);
		} else {
			fputc(c, afile);
		}
	}

	fclose(afile);
	fclose(bfile);

	return(0);
}

