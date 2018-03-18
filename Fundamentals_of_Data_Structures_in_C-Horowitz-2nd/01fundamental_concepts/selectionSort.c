#include "selectionSort.h"
#define SWAP(x,y,t)	((t) = (x), (x) = (y), (y) = (t))

void sort(int list[], int n)
{
	int i, j, min, temp;

	for (i=0; i<n-1; i++) {
		min = i;
		for (j = i+1; j<n; j++)
			if (list[j] < list[min])
				min = j;

		SWAP(list[i], list[min], temp);
	}
}

int compare(int x, int y) {
 /* compare x and y, return -1 for less than, 0 for equal, 1 for greater */
	if (x<y) return -1;
	else 	if (x == y) return 0;
			else return 1;
}
