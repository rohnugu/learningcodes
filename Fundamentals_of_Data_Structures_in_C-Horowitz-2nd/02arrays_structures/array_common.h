#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p,s) \
	if ( !( (p) = malloc(s) ) ) { \
		fprintf(stderr, "Insufficient memory"); \
		exit(EXIT_FAILURE); \
	}

#define CALLOC(p,n,s) \
	if ( !( (p) = calloc(n,s) ) ) { \
		fprintf(stderr, "Insufficient memory"); \
		exit(EXIT_FAILURE); \
	}

#define REALLOC(p,s) \
	if ( !( (p) = realloc(p,s) ) ) { \
		fprintf(stderr, "Insufficient memory"); \
		exit(EXIT_FAILURE); \
	}

#define FALSE 	0
#define TRUE	1

void print1(int *ptr, int rows);
void print1_float(float *ptr, int rows);
int** make2dArray(int rows, int cols);
