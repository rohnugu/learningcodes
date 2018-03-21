#include <stdlib.h>
#include <stdio.h>


#define COMPARE(x,y) ( ((x) < (y)) ? -1: (((x) == (y))? 0: 1) )

#define MAX_TERMS 100

typedef struct _term {
	unsigned int expon;
	float coef;
} term;

extern term terms[MAX_TERMS];
extern unsigned int avail;

typedef struct _polynomial {
	unsigned int start;
	unsigned int finish;
} polynomial;

void padd(polynomial A, polynomial B, polynomial *D);
void attach(float coefficient, int exponent);
