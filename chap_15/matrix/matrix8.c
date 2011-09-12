
#define X_SIZE 60
#define Y_SIZE 32

/* a random matrix */
int matrix[X_SIZE][Y_SIZE];

#define init_matrix() \
	memset(matrix, 1, sizeof(matrix));

