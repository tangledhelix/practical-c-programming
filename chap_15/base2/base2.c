/**********************************************************************
 * Database -- A very simple database program to
 *             look up names in a hardcoded list.
 *
 * Usage:
 *     database [-S<file>]
 *
 *     -S<file>         Specifies save file for
 *                      debugging purposes.
 *
 *         Program will ask you for a name.
 *         Enter the name; it will tell you if
 *         the name is in the list.
 *
 *         A blank line terminates the program.
 **********************************************************************/

#define STRING_LENGTH 80            /* length of typical string */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *save_file = NULL;             /* Save file if any */
char *extended_fgets(char *, int, FILE *);

int main(int argc, char *argv[]) {

	char name[STRING_LENGTH];       /* name to look up */
	char *save_file_name;           /* name of the save file */

	int lookup(char const *const name);         /* look up a name */

	while ((argc > 1) && (argv[1][0] == '-')) {
		switch (argv[1][1]) {
			/* -S<file>     Specify a save file */
			case 'S':
				save_file_name = &argv[1][2];
				save_file = fopen(save_file_name, "w");
				if (save_file == NULL) {
					fprintf(stderr, "Warning: Unable to open save file %s\n", save_file_name);
				}
				break;
			default:
				fprintf(stderr, "Bad option: %s\n", argv[1]);
				exit(8);
		}

		--argc;
		++argv;
	}

	while (1) {
		printf("Enter name: ");
		extended_fgets(name, sizeof(name), stdin);

		/* check for a blank name */
		/* (remember 1 character for newline) */
		if (strlen(name) <= 1) {
			break;
		}

		/* get rid of newline */
		name[strlen(name) - 1] = '\0';

		if (lookup(name)) {
			printf("%s is in the list\n", name);
		} else {
			printf("%s is not in the list\n", name);
		}
	}

	return(0);
}

/**********************************************************************
 * lookup -- Looks up a name in a list.
 *
 * Parameters
 *     name -- Name to look up.
 *
 * Returns
 *     1 -- Name in the list.
 *     0 -- Name not in the list.
 **********************************************************************/

int lookup(char const *const name) {

	/* List of people in the database */
	/* Note: last name is a NULL for end of list */
	static char *list[] = {
		"John",
		"Jim",
		"Jane",
		"Clyde",
		NULL
	};

	int index;          /* index into list */

	for (index = 0; list[index] != NULL; ++index) {
		if (strcmp(list[index], name) == 0) {
			return(1);
		}
	}

	return(0);
}

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

	char *result;           /* result of fgets */

	result = fgets(line, size, file);

	/* did somsone ask for a save file?? */
	if (save_file != NULL) {
		fputs(line, save_file); /* save line in file */
	}

	return(result);
}

