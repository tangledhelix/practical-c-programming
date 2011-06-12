#define X_SIZE 60
#define Y_SIZE 30

/* a random matrix */
int matrix[ X_SIZE ][ Y_SIZE ];

/**********************************************************************
 * init_matrix -- Sets every element of matrix to -1.
 **********************************************************************/

void init_matrix( void ) {

	register int x, y;           /* current element to zero */

	for ( x = 0; x < X_SIZE; ++x ) {
		for ( y = 0; y < Y_SIZE; ++y ) {
			matrix[ x ][ y ] = -1;
		}
	}
}

