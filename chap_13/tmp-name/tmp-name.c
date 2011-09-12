/**********************************************************************
 * This is supposed to print out:
 *     Name: tmp1
 * but instead, we get:
 *     Name: !_@$#ds80
 * (Your results may vary). Why?
 **********************************************************************/

#include <stdio.h>
#include <string.h>

/**********************************************************************
 * tmp_name -- Return a temporary filename.
 *
 * Each time this function is called, a new name will
 * be returned.
 *
 * Returns
 *     Pointer to the new filename.
 **********************************************************************/

char *tmp_name(void) {

	/*char name[30];              [> the name we are generating <]*/
	/* redeclare as static so it doesn't vanish at end of function */
	static char name[30];       /* the name we are generating */
	static int sequence = 0;    /* sequence number for the last digit */

	++sequence;                 /* move to next filename */

	strcpy(name, "tmp");

	/* Put in the sequence digit */
	name[3] = sequence + '0';

	/* End the string */
	name[4] = '\0';

	return(name);
}

int main() {

	char *tmp_name(void);           /* get name of temporary file */

	printf("Name:%s\n", tmp_name());
	printf("Name:%s\n", tmp_name());
	printf("Name:%s\n", tmp_name());
	printf("Name:%s\n", tmp_name());
	printf("Name:%s\n", tmp_name());

	return(0);
}

