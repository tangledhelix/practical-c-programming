#include <stdio.h>

int main() {
	int counter;                /* loop counter */

	for (counter = 0; counter < 3; ++counter) {
		int temporary = 1;          /* A temporary variable */
		static int permanent = 1;   /* A permanent variable */

		printf("Temporary %d Permanent %d\n",
				temporary, permanent);

		++temporary;
		++permanent;
	}

	return(0);
}

