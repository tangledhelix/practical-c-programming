/**********************************************************************
 * Write a program to draw a 10-by-10 bitmapped square. You can
 * borrow the code from graph/graph.c to print the results.
 **********************************************************************/

#include <stdio.h>

#define X_SIZE 10       /* size of array in X direction */
#define Y_SIZE 10       /* size of array in Y direction */
/*
 * We use X_SIZE/8 because we pack 8 bits per byte
 */
char graphics[X_SIZE / 8][Y_SIZE];      /* the graphics data */

/* These are explained in exercise 11-1's code */
#define SET_BIT(x,y) graphics[(x)/8][y] |= (0x80 >>((x)%8))
#define CLEAR_BIT(x,y) graphics[(x)/8][y] &= ~(0x80 >>((x)%8))
#define TEST_BIT(x,y) (graphics[(x)/8][y] & (0x80 >>((x)%8))) != 0

int main() {
	int loc;        /* current location we are setting */

	void print_graphics(void);      /* print the data */

	for (loc = 0; loc < X_SIZE; ++loc) {
		SET_BIT(loc, loc);
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


