#include "smatrix.h"


void smcreate(matrix *a, const unsigned int rows, const unsigned int cols) {
	assert(a != NULL);

	*a = malloc( MIN( rows*cols, MAX_ELEMENTS ) * sizeof(element));
	(*a)[0].row = rows;
	(*a)[0].col = cols;
	(*a)[0].value = 0; // zero matrix
}

void smremove(matrix *a) {
	if(a == NULL) // 포인터의 포인터 주소가 안 주어진 상태로 함수가 실행되면
		return;
	if(*a == NULL) // 배열의 base point가 NULL이면
		return;
	free(*a); // if *a does not point to a dynamically allocated memory from malloc/smcreate, it will do an undefined behavior!
	*a = NULL;
}

void smtranspose(matrix a, matrix b) {
	assert( (a != NULL) && (b != NULL) );
	assert( b[0].row * b[0].col >= a[0].value ); // dynamic allocation 문제 처리 고려함

	/* b is set to the transpose of a */
	int numTerms, currentb;
	numTerms	= a[0].value; 	/* total number of elements */
	b[0].row 	= a[0].col; 	/* rows in b = columns in a */
	b[0].col 	= a[0].row;		/* columns in b = rows in a */
	b[0].value 	= numTerms;

	if( numTerms > 0 ) { /* non zero matrix */
		currentb = 1;
		for(int i=0; i<a[0].col; i++)
			/*transpose by the columns in a */
			for(int j=1; j <= numTerms; j++)
				/* find elements from the current column */
				if( a[j].col == i ) {
					/* elements is in current column, add it to b */
					b[currentb].row 	= a[j].col;
					b[currentb].col 	= a[j].row;
					b[currentb].value 	= a[j].value;
					currentb++;
				}
	}
}

void smfastTranspose(matrix a, matrix b) {
	/* the transpose of a is placed in b */
	assert( (a != NULL) && (b != NULL) );
	assert( b[0].row * b[0].col >= a[0].value ); // dynamic allocation 문제 처리 고려함

	unsigned int rowTerms[MAX_COLS], startingPos[MAX_COLS];

	int numTerms;
	numTerms	= a[0].value; 	/* total number of elements */
	b[0].row 	= a[0].col; 	/* rows in b = columns in a */
	b[0].col 	= a[0].row;		/* columns in b = rows in a */
	b[0].value 	= numTerms;

	if( numTerms > 0 ) { /* nonzero matrix */
		for(int i=0; i < b[0].row; i++)
			rowTerms[i] = 0;

		for(int i=1; i <= numTerms; i++)
			rowTerms[a[i].col]++;
		
		startingPos[0] = 1;
		
		for(int i=1; i < b[0].row; i++)
			startingPos[i] = startingPos[i-1] + rowTerms[i-1];

		for(int i=1; i <= numTerms; i++) {
			int j = startingPos[a[i].col]++;
			b[j].row = a[i].col;
			b[j].col = a[i].row;
			b[j].value = a[i].value;
		}
	}
}

void smadd(matrix a, matrix b, matrix d);
void smmultiply(matrix a, matrix b, matrix d);
void smprint(matrix a, bool pointer) {
	assert(a != NULL);

	for(int i=0; i<a[0].value; i++) {
		if(pointer)
			printf("%p\t%d\t%d\t%d\n", &a[i], a[i].row, a[i].col, a[i].value);
		else
			printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].value);

	}
}

void smvisualprint(matrix a, bool pointer)
{
	assert(a != NULL);

	int visual[MAX_ROWS][MAX_COLS] = {0};

	for(int k=1; k <= a[0].value; k++)
		visual[a[k].row][a[k].col] = a[k].value;

	for(int i=0; i<a[0].row; i++) {
		for(int j=0; j<a[0].col; j++) {
			if(pointer)
				printf("%p\t", &visual[i][j]);
			else
				printf("%d\t", visual[i][j]);
		}
		printf("\n");
	}
}