#include "polynomial_ver2.h"

void main() {

	polynomial A, B, D;

	A.start = 0;	A.finish = 1; 	B.start = 2; 	B.finish = 5;
	avail = 6;

	terms[0].coef = 2;	terms[1].coef = 1;	terms[2].coef = 1;
	terms[3].coef = 10;	terms[4].coef = 3;	terms[5].coef = 1;

	terms[0].expon = 1000;	terms[1].expon = 0;	terms[2].expon = 4;
	terms[3].expon = 3;		terms[4].expon = 2;	terms[5].expon = 0;

	padd(A, B, &D);

	for(int i=0;i<avail;i++) {
		printf("%4.1f\t", terms[i].coef);
	}
	printf("\n");

	for(int i=0;i<avail;i++) {
		printf("%4u\t", terms[i].expon);
	}
	printf("\n");

}