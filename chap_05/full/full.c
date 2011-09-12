#include <string.h>
#include <stdio.h>

char first[100];            /* first name */
char last[100];             /* last name */
char full_name[200];        /* full version, first and last name */

int main() {
	strcpy(first, "Steve");         /* initialize first name */
	strcpy(last, "Oualline");       /* initialize last name */

	strcpy(full_name, first);
	/* note: strcat not strcpy */
	strcat(full_name, " ");
	strcat(full_name, last);

	printf("The full name is %s\n", full_name);
	return(0);
}
