#include "polynomial_ver1.h"

void main() {
	polynomial* poly1 = pZero();

//	pPrint(poly1);
	//pDebugPrint(poly1);	

//	printf("%d %d %d \n", sizeof(poly1->degree), sizeof(poly1->used), sizeof(poly1->coef));

	polynomial* temp;

	temp = poly1; 
	poly1 = pSingleMult(poly1, 3, 0);
	free(temp);
	
	temp = poly1;
	poly1 = pSingleMult(poly1, 2, 1);
	free(temp);

	temp = poly1;
	poly1 = pSingleMult(poly1, 1, 2);
	free(temp);


	polynomial* poly2 = pZero();

	temp = poly2; 
	poly2 = pSingleMult(poly2, 1, 0);
	free(temp);
	
	temp = poly2;
	poly2 = pSingleMult(poly2, 2, 1);
	free(temp);

	temp = poly2;
	poly2 = pSingleMult(poly2, 3, 2);
	free(temp);

	pPrint(poly1);
	pDebugPrint(poly1);

	pPrint(poly2);
	pDebugPrint(poly2);
}