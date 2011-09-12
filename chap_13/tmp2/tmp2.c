#include <stdio.h>
#include <string.h>

/**********************************************************************
 * After fixing the function from a previous example, we try using
 * it for two filenames. This should print out:
 *
 *     Name: tmp1
 *     Name: tmp2
 *
 * but it doesn't. What does it print and why?
 **********************************************************************/

/**********************************************************************
 * tmp_name -- Returns a temporary filename.
 *
 * Each time this function is called, a new name will be returned.
 *
 * Warning: There should be a warning here, but if we put it in,
 * we would answer the question.
 *
 * Returns
 *     Pointer to the new filename.
 **********************************************************************/

/**********************************************************************
 * problem: char is static, and we return a pointer to it. So we will
 * always return the same pointer. So if we printed name1 just after
 * it was assigned, we should get proper results, but as it stands,
 * by the time we print name1 and name2, they both have the same
 * contents because they are the same value (two pointers to the
 * same address).
 **********************************************************************/

char *tmp_name(void) {
	static char name[30];           /* The name we are generating */
	static int sequence = 0;        /* Sequence number for the last digit */

	++sequence;                     /* Move on to the next filename */

	strcpy(name, "tmp");

	/* Put in the sequence digit */
	name[3] = sequence + '0';

	/* End the string */
	name[4] = '\0';

	return(name);
}

int main() {
	char *tmp_name(void);           /* get name of a temporary file */
	char *name1;                    /* name of a temporary file */
	char *name2;                    /* name of a temporary file */

	name1 = tmp_name();
	/* print this here instead, should be correct */
	printf("Name1: %s\n", name1);

	name2 = tmp_name();

	/*printf("Name1: %s\n", name1);*/
	printf("Name2: %s\n", name2);
	return(0);
}

