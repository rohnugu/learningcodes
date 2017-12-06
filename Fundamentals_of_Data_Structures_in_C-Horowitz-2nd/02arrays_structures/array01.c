#include "array_common.h"
#define MAX_SIZE 100
float sum(float [], int);
float input[MAX_SIZE], answer;

void main(void)
{
	int i;

	for (i=0;i<MAX_SIZE; i++)
		input[i] = i;

	answer = sum(input, MAX_SIZE);

	printf("The sum is: %f\n", answer);

	print1_float(input, MAX_SIZE);
}

float sum(float list[], int n)
{
	int i;
	float tempsum = 0;

	for (i=0; i<n; i++)
		tempsum += list[i];

	return tempsum;
}
