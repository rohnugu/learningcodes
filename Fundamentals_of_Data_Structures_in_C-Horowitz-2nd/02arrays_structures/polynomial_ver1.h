#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define MALLOC(p,s) \
	if ( !( (p) = malloc(s) ) ) { \
		fprintf(stderr, "Insufficient memory"); \
		exit(EXIT_FAILURE); \
	}

#define FALSE	0
#define TRUE	1

#define MAX_DEGREE 101

typedef unsigned int 	expon_t;
typedef float		coef_t;

typedef struct _polynomial {
	expon_t degree;
	bool used[MAX_DEGREE]; // hjroh
	coef_t coef[MAX_DEGREE];
} polynomial;

polynomial* pCopy(polynomial* poly) { // hjroh
	polynomial* result;
	//MALLOC(result, sizeof(result->degree) + sizeof(result->used) + sizeof(result->coef));
	
	MALLOC( result , sizeof(polynomial) );


	result->degree = poly->degree;

	for(expon_t i=0; i<MAX_DEGREE; i++) {
		result->used[i] = poly->used[i];
		result->coef[i] = poly->coef[i];
	}

	return result;
}

polynomial* pZero() {
	polynomial* result = NULL;

	//printf("D %u %u\n", sizeof(polynomial), sizeof(result->degree) + sizeof(result->used) + sizeof(result->coef));
	MALLOC( result , sizeof(polynomial) );

	result->degree = 0;
	
	for(expon_t i=0; i<MAX_DEGREE; i++) {
		result->used[i] = false;
		result->coef[i] = 0.0f;
	}

	result->used[0] = false;

	return result;
}

bool pIsZero(polynomial* poly) {
	if( poly->degree > 0 ) return FALSE;
	else {
		/* for debug */
		for(expon_t i=0; i<MAX_DEGREE; i++) {
			assert( (i>0) ? !(poly->used[i]) : (poly->used[i]) );
			assert(poly->coef[i] == 0.0f);
		}

		return TRUE;
	}
}

coef_t pCoef(polynomial* poly, expon_t expon) {
	if(expon >= MAX_DEGREE) {
		printf("pCoef: Out of range\n");
		return 0;
	} else {
		return ( poly->used[expon] ? poly->coef[expon] : 0 );
	}
}

expon_t pLeadExp(polynomial* poly) {
	assert( poly->degree < MAX_DEGREE );
	assert( poly->used[poly->degree] );
	return poly->degree;
}

polynomial* pAttach(polynomial* poly, coef_t coef, expon_t expon) {
	if(expon >= MAX_DEGREE) {
		printf("pAttach: Out of range\n");
		return NULL;
	}
	/* now we have expon < MAX_DEGREE */
	assert( !(poly->used[expon]) ); // if (expon \in poly) return error
	polynomial* result = pCopy(poly);
	result->used[expon] = true;
	result->coef[expon] = coef;

	result->degree = MAX(expon, result->degree);

	return result;
}

polynomial* pRemove(polynomial* poly, expon_t expon) {
	if(expon >= MAX_DEGREE) {
		printf("pRemove: Out of range\n");
		return NULL;		
	}

	assert( !(poly->used[expon]) ); // if (expon \notin poly) return error
	polynomial* result = pCopy(poly);

	result->used[expon] = false;
	result->coef[expon] = 0.0f;

	if(expon == result->degree)
		while( --(result->degree) ) {
			if(result->coef[result->degree] != 0.0f)
				break;
		}

	// if(result->degree == 0) {
	// 	result->used[0] = true;
	// 	result->coef[0] = 0.0f;
	// }

	return result;
}

polynomial* pSingleMult(polynomial* poly, coef_t coef, expon_t expon) {
	assert ( (poly->degree + expon) < MAX_DEGREE);

	polynomial* result = pCopy(poly);

	bool isAllZero = true;

	result->degree = (coef == 0.0f) ? 0 : (poly->degree + expon);

	for(int i = poly->degree ; i >= 0 ; i--) {
		result->coef[i + expon] = coef * (result->coef[i + expon]);
		result->used[i + expon] = ( result->coef[i + expon] != 0.0f );

		if(result->used[i + expon]) {
			isAllZero = false;
		}
	}

	for(expon_t i = 0; i < expon; i++) {
		result->used[i] = false;
		result->coef[i] = 0.0f;
		// no need to modify isAllZero
	}

	if(isAllZero) { // if the result is zero polynomial
		result->used[0] = true;
	}

	return result;
}

polynomial* pAdd(polynomial* poly1, polynomial* poly2) {
	polynomial* result = pCopy( (poly1->degree == MAX(poly1->degree, poly2->degree) ) ? poly1 : poly2 );


	bool isAllZero = true;

	for(expon_t i = 0; i <= result->degree; i++) {
		// it should be carefully implemented, since when used[i] == false, it has a dummy value in coef[i].
		result->coef[i] = (poly1->used[i] ? poly1->coef[i] : 0.0f) + (poly2->used[i] ? poly2->coef[i] : 0.0f);
		result->used[i] = ( result->coef[i] != 0.0f );

		if(result->used[i]) {
			isAllZero = false;
			result->degree = i;
		}
	}

	if(isAllZero) { // if the result is zero polynomial
		result->used[0] = true;
		result->degree = 0;
	}

	return result;
}

polynomial* pMulti(polynomial* poly1, polynomial* poly2) {
	assert ( (poly1->degree + poly2->degree) < MAX_DEGREE);

	polynomial* result = pZero();

	for(expon_t i = 0; i <= poly1->degree; i++) {
		if(poly1->used[i]) {
			polynomial* mulPoly2 = pSingleMult(poly2, poly1->coef[i], i);
			polynomial* prevResult = result;
			result = pAdd(result, mulPoly2);
			free(mulPoly2);
			free(prevResult);
		}
	}

	return result;
}

void pPrint(polynomial* poly) {
	for(int i= poly->degree; i >= 0; i--) {
//		printf("%u\n", i);

//		printf("%d\n",poly->used[i]);

		if(poly->used[i])
			printf("%8.4f * x^%u ",poly->coef[i], i);
	}

	printf("\n");
}

void pDebugPrint(polynomial* poly) {
	for(int i= MAX_DEGREE - 1 ; i > poly->degree; i--)
		assert(!(poly->used[i]));

	for(int i= poly->degree; i >= 0; i--) {
		printf("%8.4f * x^%u ", poly->coef[i], i);
	}

	printf("\n");
}