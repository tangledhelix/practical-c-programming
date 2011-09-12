/**********************************************************************
 * Write a set of parameterized macros, clear_bit and test_bit,
 * to go with the set_bit operation from graph/graph.c. Write
 * a main program to test these macros.
 **********************************************************************/

#include <stdio.h>

#define X_SIZE 40       /* size of array in X direction */
#define Y_SIZE 60       /* size of array in Y direction */
/*
 * We use X_SIZE/8 because we pack 8 bits per byte
 */
char graphics[X_SIZE / 8][Y_SIZE];      /* the graphics data */

/* You set bits with |=
 * The way that works is you take e.g. 00010011 and the mask
 * 00001000, if you | them together you get 00011011.
 */
#define SET_BIT(x,y) graphics[(x)/8][y] |= (0x80 >>((x)%8))

/* You clear a bit by first inverting the mask, then & with the
 * value. For instance, 00001000 inverted is 11110111.
 * If you & that with a value 00011011, you get 00010011.
 * (The 8-bit has been cleared.)
 */
#define CLEAR_BIT(x,y) graphics[(x)/8][y] &= ~(0x80 >>((x)%8))

/* You test a bit by &'ing it with the mask, and seeing if that
 * yields a nonzero result. If the result is 0, there were no
 * bits in the &, so the mask was not matched.
 * value 00001011 and mask 00000100 would yield 0x0 because
 * no bits are in common, therefore the test fails (the bit
 * is not set).
 */
#define TEST_BIT(x,y) (graphics[(x)/8][y] & (0x80 >>((x)%8))) != 0

int main() {
	int loc;        /* current location we are setting */

	void print_graphics(void);      /* print the data */

	for (loc = 0; loc < X_SIZE; ++loc) {
		SET_BIT(loc, loc);
	}

	SET_BIT(18,9);

	if (TEST_BIT(18,9)) {
		printf("DEBUG: test bit is set\n");
	} else {
		printf("DEBUG: uh oh 1.\n");
	}

	print_graphics();

	CLEAR_BIT(18,9);

	if (TEST_BIT(18,9)) {
		printf("Uh oh 2.\n");
	} else {
		printf("DEBUG: test bit is now unset\n");
	}

	print_graphics();
	return(0);
}

/**********************************************************************
 * print_graphics -- Prints the graphics bit array
 *                  as a set of X's and .'s.
 **********************************************************************/

void print_graphics(void) {
	int x;              /* current x BYTE */
	int y;              /* current y location */
	unsigned int bit;   /* bit we are testing in current byte */

	for (y = 0; y < Y_SIZE; ++y) {
		/* Loop for each byte in the array */
		for (x = 0; x < X_SIZE / 8; ++x) {
			/* Handle each bit */
			for (bit = 0x80; bit > 0; bit = (bit >> 1)) {
				if ((graphics[x][y] & bit) != 0) {
					printf("X");
				} else {
					printf(".");
				}
			}
		}
		printf("\n");
	}
}


