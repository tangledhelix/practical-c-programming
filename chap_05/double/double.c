#include <stdio.h>

char line[100];         /* input line from console */
int value;              /* a value to double */

int main() {
	printf("Enter a value: ");

	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &value);

	printf("Twice %d is %d\n", value, value * 2);
	return(0);
}
