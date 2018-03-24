#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define MAX_ELEMENTS 	101 /* maximum number of terms + 1 */
#define MAX_COLS		100
#define MAX_ROWS		MAX_COLS

typedef struct _elements {
	unsigned int row;
	unsigned int col;
	int value;
} element;

typedef element* matrix;

void smcreate(matrix *a, const unsigned int rows, const unsigned int cols);
void smremove(matrix *a);
void smtranspose(matrix a, matrix b);
void smfastTranspose(matrix a, matrix b);
void smadd(matrix a, matrix b, matrix d);
void smmultiply(matrix a, matrix b, matrix d);
void smprint(matrix a, bool pointer);
void smvisualprint(matrix a, bool pointer);
