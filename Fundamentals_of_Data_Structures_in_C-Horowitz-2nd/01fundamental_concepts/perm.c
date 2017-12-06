#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST	26
#define SWAP(a,b,t)	{ (t) = (a); (a) = (b); (b) = (t); }

void perm(char *list, int i, int n)
{
	int j;
	char temp;
	if (i == n) {
		for (j = 0; j<= n; j++)
			printf("%c ", list[j]);
		printf("\n");
	}
	else {
		for(j =i; j <= n; j++) {
			SWAP(list[i], list[j], temp);
			perm(list, i+1, n);
			SWAP(list[i], list[j], temp);
		}
	}
}

int main ()
{
	int n;
	char list[MAX_LIST];

	printf("Enter the number of list: ");
	scanf("%d", &n);

	if(n < 1 || n> MAX_LIST) {
		/*fprintf(stderr, "ERROR");
		exit(1);*/
		return -1;
	}

	for(int i=0;i<n;i++) {
		list[i] = 'a' + (char) i;
/*		printf("%c", list[i]);*/
	}

	

	perm(list, 0, n-1);

	return 0;
}
