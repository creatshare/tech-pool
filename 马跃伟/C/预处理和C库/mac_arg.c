#include <stdio.h>
#define SQUARE(X) X*X
#define PR(X) printf("The result is %d\n",X );
int main()
{
	int x=4;
	int z;
	printf("x=%d\n",x );
	z=SQUARE(x);
	printf("Evaluating SQUARE(X):");
	PR(z);
	z=SQUARE(2);
	printf("Evaluating SQUARE(2):");
	PR(z);
	printf("Evaluating SQUARE(x+2):");
	PR(x+2);
	printf("Evaluating SQUARE(100/SQUARE(2)):");
	PR(100/SQUARE(2));
	printf("x is %d\n",x );
	printf("Evaluating SQUARE(++x):");
	PR(++x);
	printf("After ubcrementing,x is %x.\n",x );
	return 0;
}
