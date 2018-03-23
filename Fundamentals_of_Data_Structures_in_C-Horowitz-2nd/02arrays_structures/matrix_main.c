#include "matrix.h"

void main()
{
	matrix a, b, d;
	a.e = NULL;
	b.e = NULL;
	d.e = NULL;

	mcreate(&a, 4, 4);
	mcreate(&d, 10, 4);

	for(int i=0;i<a.rows;i++) {
		for(int j=0;j<a.cols;j++) {
			a.e[i][j] = i*10 + j;
		}
	}

	mprint(a, true);
	mprint(a, false);

	mtranspose(a, &b);

	mprint(b, true);
	mprint(b, false);

	madd(a, b, &d);

	mprint(d, true);
	mprint(d, false);

	mmultiply(a, b, &d);

	mprint(d, true);
	mprint(d, false);
	
	mremove(&a);
	mremove(&b);
	mremove(&d);
}
