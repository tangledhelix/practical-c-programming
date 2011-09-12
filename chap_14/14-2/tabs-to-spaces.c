/**********************************************************************
 * Write a program to copy a file, expanding all tabs to multiple
 * spaces.
 **********************************************************************/

#include <stdio.h>

/* files to read and write */
const char *in_filename = "file-in.pl";
const char *out_filename = "file-out.pl";

int main() {

	FILE *infile;           /* pointer to input file */
	FILE *outfile;          /* pointer to output file */

	int c;              /* store each character as it comes in */

	/* open input file for reading */
	infile = fopen(in_filename, "r");
	if (infile == NULL) {
		fprintf(stderr, "Problem opening %s for reading\n", in_filename);
		return(8);
	}

	/* open output file for writing */
	outfile = fopen(out_filename, "w+");
	if (outfile == NULL) {
		fprintf(stderr, "Problem opening %s for writing\n", out_filename);
		return(8);
	}

	while (1) {

		/* fetch a character */
		c = fgetc(infile);

		/* detect end-of-file, quit if we've gotten there */
		if (c == EOF) {
			break;
		}

		/* if we have found a tab, output four spaces instead. */
		/* otherwise, just output the character. */
		if (c == '\t') {
			fputc(' ', outfile);
			fputc(' ', outfile);
			fputc(' ', outfile);
			fputc(' ', outfile);
		} else {
			fputc(c, outfile);
		}
	}

	/* be tidy and close up filehandles */
	fclose(infile);
	fclose(outfile);

	return(0);
}

