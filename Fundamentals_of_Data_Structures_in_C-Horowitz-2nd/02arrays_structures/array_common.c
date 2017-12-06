#include "array_common.h"

void print1(int *ptr, int rows)
{
	int i;
	printf("Address Contents\n");

	for(i=0;i<rows;i++)
		printf("%8u %5d\n", ptr + i, *(ptr+i));

	printf("\n");
}

void print1_float(float *ptr, int rows)
{
	int i;
	printf("Address Contents\n");

	for(i=0;i<rows;i++)
		printf("%8u %10.10f\n", ptr + i, *(ptr+i));

	printf("\n");
}
