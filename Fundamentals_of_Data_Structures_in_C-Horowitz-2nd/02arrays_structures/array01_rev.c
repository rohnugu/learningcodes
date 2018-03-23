#include "array_common.h"
float sum(float [], int);
float answer;

void main(void)
{
	int i, n;
	float *input;

	printf("Enter the number of numbers to generate: ");
	scanf("%d",&n);

	if (n < 1) {
		fprintf(stderr, "Improper value of n\n");
		exit(EXIT_FAILURE);
	}

	MALLOC(input, n * sizeof(float));

	for (i=0;i<n; i++)
		input[i] = i;

	answer = sum(input, n);

	printf("The sum is: %f\n", answer);

	print1_float(input, n);
}

float sum(float list[], int n)
{
	int i;
	float tempsum = 0;

	for (i=0; i<n; i++)
		tempsum += list[i];

	return tempsum;
}
