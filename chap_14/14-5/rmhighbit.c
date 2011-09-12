/**********************************************************************
 * Write a program that copies a file and removes all characters with
 * the high bit set - ((ch & 0x80) != 0).
 **********************************************************************/

#include <stdio.h>

const char *in_filename = "file-in";
const char *out_filename = "file-out";

int main() {

	FILE *infile;           /* pointer to input file */
	FILE *outfile;          /* pointer to output file */
	int c;                  /* a character from a file */

	infile = fopen(in_filename, "r");
	if (infile == NULL) {
		fprintf(stderr, "Error: unable to open %s for reading\n", in_filename);
		return(8);
	}

	outfile = fopen(out_filename, "w+");
	if (outfile == NULL) {
		fprintf(stderr, "Error: unable to open %s for writing\n", out_filename);
		fclose(infile);
		return(8);
	}

	while (1) {
		c = fgetc(infile);
		if (c == EOF) {
			break;
		}

		if ((c & 0x80) == 0) {
			fputc(c, outfile);
		}
	}

	fclose(infile);
	fclose(outfile);

	return(0);
}

