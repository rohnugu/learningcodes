#include "array_common.h"

void print1(int *ptr, int rows)
{
	int i;
	printf("Address Contents\n");

	for(i=0;i<rows;i++)
		// printf("%8u %5d\n", ptr + i, *(ptr+i));
		printf("%8p %5d\n", ptr + i, *(ptr+i));

	printf("\n");
}

void print1_float(float *ptr, int rows)
{
	int i;
	printf("Address Contents\n");

	for(i=0;i<rows;i++)
		//printf("%8u %10.10f\n", ptr + i, *(ptr+i));
		printf("%8p %10.10f\n", ptr + i, *(ptr+i));

	printf("\n");
}

int** make2dArray(int rows, int cols)
{
	/* create a two dimensional rows times cols array */

	int **x, i;

	/* get memory for row pointers */
	/* note that it corresponds to x = malloc(rows *sizeof(*x)); */
	MALLOC(x, rows * sizeof(*x));


	/* get memory for each row */
	for (i=0; i<rows; i++)
		MALLOC(x[i], cols * sizeof(**x));

	return x;
}
