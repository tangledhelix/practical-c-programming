#include <string.h>
#include <stdio.h>

char name[30];          /* first name of someone */

int main() {
	strcpy(name, "Sam");        /* initialize the name */
	printf("The name is %s\n", name);

	return(0);
}
