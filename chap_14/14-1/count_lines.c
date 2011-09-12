/**********************************************************************
 * Write a program that reads a file and then counts the number of
 * lines in it.
 **********************************************************************/

#include <stdio.h>

const char *filename = "file.txt";

int main() {

	FILE *fh;               /* a filehandle */
	char line[100];         /* a line from the file */

	int count = 0;          /* a line counter */

	fh = fopen(filename, "r");
	if (fh == NULL) {
		fprintf(stderr, "Problem opening file %s\n", filename);
		return(8);
	}

	while (fgets(line, sizeof(line), fh)) {
		++count;
	}

	printf("%d lines\n", count);

	return(0);
}

