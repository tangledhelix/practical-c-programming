#include <stdio.h>

/*
 * This program produces a Celsius to Fahrenheit conversion
 * chart for the numbers 0 to 100.
 */

/* Question: When this program runs, it prints:
 *     Celsius: 101 Fahrenheit: 213
 * and nothing more. Why?
 */

/* The current Celsius temperature we are working with */
int celsius;
int main() {
	/* This line was semicolon terminated, so the loop
	 * didn't do anything. */
	/*for (celsius = 0; celsius <= 100; ++celsius);*/

	for (celsius = 0; celsius <= 100; ++celsius)
		printf("Celsius:%d Fahrenheit:%d\n",
				celsius, (celsius * 9) / 5 + 32);
		return(0);
}

