#include <stdio.h>

int fact(int number) {
	if (number == 0) {
		return(1);
	}

	return(number * fact(number - 1));
}

int main(void) {
	printf("fact(9) is %d\n", fact(9));
	return(0);
}
