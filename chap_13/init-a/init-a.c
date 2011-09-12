#define MAX 10      /* size of the array */

/**********************************************************************
 * init_array_1 -- Zeroes out an array.
 *
 * Parameters
 *     data -- the array to zero out.
 **********************************************************************/

void init_array_1(int data[]) {
	int index;

	for (index = 0; index < MAX; ++index) {
		data[index] = 0;
	}
}

/**********************************************************************
 * init_array_2 -- Zeroes out an array.
 *
 * Parameters
 *     data_ptr -- Pointer to an array to zero.
 **********************************************************************/

void init_array_2(int *data_ptr) {
	int index;

	for (index = 0; index < MAX; ++index) {
		*(data_ptr + index) = 0;
	}
}

int main() {
	int array[MAX];

	void init_array_1();
	void init_array_2();

	/* one way of initializing the array */
	init_array_1(array);

	/* another way of initializing the array */
	init_array_1(&array[0]);

	/* works, but compiler generates a warning */
	init_array_1(&array);

	/* similar to first method but function is different */
	init_array_2(array);

	return(0);
}

