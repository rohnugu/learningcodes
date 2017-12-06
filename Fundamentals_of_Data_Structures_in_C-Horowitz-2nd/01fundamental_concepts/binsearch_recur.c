#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
*/

#define SWAP(x,y,t) {(t) = (x); (x) = (y); (y) = (t);}
#define MAX_SIZE 101

void sort(int[], int);

#define COMPARE(x,y) ( ((x) < (y)) ? -1: (((x) == (y))? 0: 1) )

int binsearch(int list[], int searchnum, int left, int right)
{
	int middle;
	while (left<=right) {
		middle = (left + right)/2;
		switch (COMPARE(list[middle], searchnum)) {
			case -1:
				return binsearch(list, searchnum, middle+1, right);
			case 0:
				return middle;
			case 1:
				return binsearch(list, searchnum, left, middle - 1);
		}
	}

	return -1;
}

int main(void)
{
	int searchnum, p;

	int i, n;
	int list[100];
	printf("Enter the number of numbers to generate: ");

	scanf("%d", &n);

	if ( (n < 1) || (n > MAX_SIZE)) {
		/*fprintf(stderr, "Improper value of n\n");
		exit(EXIT_FAILURE); */
		printf("improper value");
		return 0;
	}

	for(i=0; i<n; i++) {
		list[i] = rand() % 1000;
		printf("%d ", list[i]);
	}

	sort(list, n);

	printf("\n Sorted array:\n ");
	for(i=0; i<n; i++) {
		printf("%d ", list[i]);
	}

	printf("\n");

	printf("Enter the number to find: ");
	scanf("%d", &searchnum);

	if ( (p = binsearch(list, searchnum, 0, n)) == -1 ) {
		printf("\n Not found\n");
	} else {
		printf("\n The position: %d\n", p);
	}
	
	return 0;
}

void sort(int list[], int n)
{
	int i, j, min, temp;
	for(i=0; i< n-1; i++) {
		min = i;

		for(j=i+1; j<n; j++) {
			if(list[j] < list[min])
				min = j;
		}

		SWAP(list[i], list[min], temp);
	}
}

