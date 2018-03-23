#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* For more information on the double pointer, you can consult
http://www.annigeri.in/2011/11/dynamic-two-dimensioned-arrays-in-c.html
 */
typedef struct _matrix {
	float **e;
	unsigned int rows;
	unsigned int cols;
} matrix;

void mcreate(matrix *a, const unsigned int row, const unsigned int col);
void mremove(matrix *a);
void mtranspose(matrix a, matrix *b);
void madd(matrix a, matrix b, matrix *d);
void mmultiply(matrix a, matrix b, matrix *d);
void mprint(matrix a, bool pointer);
