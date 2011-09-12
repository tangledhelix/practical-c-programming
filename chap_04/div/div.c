#include <stdio.h>

float result;       /* result of the divide */

int main() {
	result = 7.0 / 22.0;

	/*printf("The result is %d\n", result);*/
	printf("The result is %f\n", result);  /* wrong conversion in last line */
	return(0);
}
