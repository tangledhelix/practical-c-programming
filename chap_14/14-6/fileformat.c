/**********************************************************************
 * Design a file format to store a person's name, address, and other
 * information. Write a program to read this file and produce a set of
 * mailing labels.
 **********************************************************************/

/**********************************************************************
 * Format:
 *
 *     First Name
 *     Last Name
 *     Street Address
 *     City
 *     ST
 *     Zip Code
 *     Phone (optional)
 *
 *     A blank line is a record separator.
 **********************************************************************/

#include <stdio.h>
#include <string.h>

char *in_file = "formatted-file.txt";

int main() {

	FILE *infile;           /* file pointer to input file */
	char line[100];         /* a line from the file */

	int position;           /* position into the record */

	infile = fopen(in_file, "r");
	if (infile == NULL) {
		fprintf(stderr, "Problem opening %s for reading\n", in_file);
		return(8);
	}

	position = 0;
	while (fgets(line, sizeof(line), infile)) {
		if (line[0] == '\n') {
			/* blank line - record separator */
			printf("\n");
			position = 0;
			continue;
		}

		line[strlen(line) - 1] = '\0';          /* get rid of newline */

		switch (position) {
			case 1:
			case 2:
			case 5:
			case 6:
				printf("%s\n", line);       /* last name, street, zip code, phone */
				break;
			case 0:
			case 4:
				printf("%s ", line);        /* first name, state */
				break;
			case 3:
				printf("%s, ", line);       /* city */
				break;
			default:
				printf("Error: unknown field\n");
		}

		++position;

	}

	fclose(infile);

	return(0);
}

