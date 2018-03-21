#include "polynomial_ver2.h"

term terms[MAX_TERMS];

unsigned int avail = 0;

void padd(polynomial A, polynomial B, polynomial *D) {
	/* add A(x) and B(x) to obtain D(x) */
	float coefficient;
	D->start = avail;
	while (A.start <= A.finish && B.start <= B.finish) {
		switch(COMPARE(terms[A.start].expon, terms[B.start].expon)) {
			case -1: /* A.expon < B.expon */
				attach(terms[B.start].coef, terms[B.start].expon);
				B.start++;
				break;
			case 0: /* equal exponents */
				coefficient = terms[A.start].coef + terms[B.start].coef;
				if(coefficient)
					attach(coefficient, terms[A.start].expon);
				A.start++;
				B.start++;
				break;
			case 1: /* A.expon > B.expon */
				attach(terms[A.start].coef, terms[A.start].expon);
				A.start++;
		}
	}
	/* add in remaining terms of A(x) */
	for(; A.start <= A.finish; A.start++) {
		attach(terms[A.start].coef, terms[A.start].expon);
	}

	for(; B.start <= B.finish; B.start++) {
		attach(terms[B.start].coef, terms[B.start].expon);
	}

	D->finish = avail - 1;
}

void attach(float coefficient, int exponent) {
	/* add a new term to the polynomial */
	if(avail >= MAX_TERMS) {
		fprintf(stderr, "Too many terms in the polynomial\n");
		exit(EXIT_FAILURE);
	}

	terms[avail].coef = coefficient;
	terms[avail++].expon = exponent;
}