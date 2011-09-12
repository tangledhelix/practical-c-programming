#include <stdio.h>

float answer;       /* The result of our calculation */

int main() {
	/*answer = 1 / 3;*/
	answer = 1.0 / 3.0;  /* need at least one term to be float to do float math */
	printf("The value of 1/3 is %f\n", answer);

	return(0);
}
