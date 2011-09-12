#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**********************************************************************
 * my_strchr -- Finds a character in a string.
 *     Duplicate of a standard library function,
 *     put here for illustrative purposes.
 *
 * Parameters
 *     string_ptr -- String to look through.
 *     find -- Character to find.
 *
 * Returns
 *     pointer to 1st occurrence of character
 *     in string or NULL for error.
 **********************************************************************/

char *my_strchr(char *string_ptr, char find) {

	while (*string_ptr != find) {
	
		/* Check for end */
		if (*string_ptr == '\0') {
			return(NULL);           /* not found */
		}

		++string_ptr;
	}
	return(string_ptr);             /* found */
}

int main() {

	char line[80];              /* the input line */
	char *first_ptr;            /* pointer to the first name */
	char *last_ptr;             /* pointer to the last name */

	printf("Enter a name (Last/First): ");
	fgets(line, sizeof(line), stdin);

	/* Get rid of trailing newline */
	line[strlen(line) - 1] = '\0';

	last_ptr = line;            /* last name is at beginning of line */

	first_ptr = my_strchr(line, '/');       /* find slash */

	/* Check for an error */
	if (first_ptr == NULL) {
		fprintf(stderr,
				"Error: Unable to find slash in %s\n", line);
		exit(8);
	}

	*first_ptr = '\0';      /* zero out the slash */
	++first_ptr;            /* move to first character of name */

	printf("First:%s Last:%s\n", first_ptr, last_ptr);
}

