#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#define MIN(a,b) (((a)<(b))?(a):(b))

#define MALLOC(p,s) \
	if ( !( (p) = malloc(s) ) ) { \
		fprintf(stderr, "Insufficient memory"); \
		exit(EXIT_FAILURE); \
	}

int  compare(const void *a, const void *b);
int  stralp(const char* s, char* buf, int szBuf);
void KMPpre(unsigned int **dfa, const int row, const int col, const char *needle, const unsigned int *charAt);
int  KMPsearch(char *haystack, char *needle, unsigned int **dfa, char *alphabet);

// #define REPEATION_SIZE		50000000
// #define MAX_STRING_SIZE		(2 * REPEATION_SIZE + 4)
// #define MAX_PATTERN_SIZE	(MAX_STRING_SIZE)

// char haystack[MAX_STRING_SIZE];
// char needle[MAX_PATTERN_SIZE];

int  main(int argc, char* argv[]) {

	// int n = REPEATION_SIZE;

	// for(int i=0; i<n; i++) {
	// 	haystack[2*i] = 'a';
	// 	haystack[2*i + 1] = 'b';
	// }
	// haystack[2*n+0] = 'a';
	// haystack[2*n+1] = 'a';
	// haystack[2*n+2] = 'b';
	// haystack[2*n+3] = '\0';
	// strcpy(needle, "aab");


	char alphabet[100];

	char needle[] = "ababac";
	char haystack[] = "aabacaababacaa";
	int M = strlen(needle);
	assert(M > 0);

	int R = stralp(needle, alphabet, 100);
	assert(R > 0);
	assert(R < 256); // since we use ASCII code char...

	// this line can be omitted.
	qsort(alphabet, R, sizeof(char), compare);

	// charAt[j] means the index of 'alphabet' that the j-th char of string 'needle'
	unsigned int *charAt;
	MALLOC(charAt, M * sizeof(unsigned int));
	for(int j=0; j<M; j++) {
		charAt[j] = (unsigned int) (strchr(alphabet, needle[j]) - alphabet);
//		printf("%d ", charAt[j]);
	}
//	printf("\n");

	// allocation of 2-D int array dfa
	// Sedgewick uses a static array.
	unsigned int **dfa;
	MALLOC(dfa, R * sizeof(unsigned int*) );
	for(int i=0; i<R; i++) {
		MALLOC(dfa[i], M * sizeof(unsigned int) );
	}

	KMPpre(dfa, R, M, needle, charAt);

	for(int i=0; i < R; i++) {
		for(int j=0; j < M; j++) {
			printf("%d ", dfa[i][j]);
		}
		printf("\n");
	}

	clock_t start, end;
	double duration;

	start = clock();
	int pResult = KMPsearch(haystack, needle, dfa, alphabet);
	//int pResult = KMPsearch(string, pat, dfa, alphabet);
	end = clock();
	duration = ((double) (end - start)) / CLOCKS_PER_SEC;

	if(pResult >= 0) {
		printf("KMP Algorithm in Sedgewick's Algorithms 4th Ed.:\t %p, %d\n", &haystack[pResult], pResult);
		printf("Duration: %f\n", duration);
	}

	// free of dynamic allocated arrays.
	free(charAt);
	for(int i=0; i<R; i++)
		free(dfa[i]);
	free(dfa);
}

int compare(const void *a, const void *b) {
	return ( *(char*)a - *(char*)b );
}

int stralp(const char* s, char* buf, int szBuf) {
	int count = 0;
	
	if(s == NULL)
		return 0;

	memset(buf, '\0', szBuf);

	int lenS = strlen(s);
	for(int i=0; i<lenS; i++) {
		char* p = strchr(buf, s[i]);
		if(p == NULL) {
			buf[count] = s[i];
			count++;
		}
	}

	return count;
}

void KMPpre(unsigned int **dfa, const int row, const int col, const char *needle, const unsigned int *charAt) {
	dfa[charAt[0]][0] = 1;
	for(int X = 0, j = 1; j < col; j++) {
		for(int c = 0; c < row; c++)
			dfa[c][j] = dfa[c][X];
		dfa[charAt[j]][j] = j+1;
		X = dfa[charAt[j]][X];
	}
}

int KMPsearch(char *haystack, char *needle, unsigned int **dfa, char *alphabet) {
	int k=0;
	int M = strlen(needle);

	int i = 0, j = 0;
	for(; (haystack[k] != '\0') && j < M; i++, k++) {
		unsigned int charAt = (unsigned int) (strchr(alphabet, haystack[k]) - alphabet);
		j = dfa[charAt][j];
	}
	if(j == M)
		return (i - M);
	else
		return -1;
}