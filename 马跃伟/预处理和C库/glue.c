#include <stdio.h>
#define XNAME(n) x ## n
#define PRINT_XN(n) printf("x" #n " = %d\n",x ## n );

int main()
{
	int XNAME(1)= 14;// 变成int x1 =14;
	int XNAME(2)= 20;
	PRINT_XN (1);
	PRINT_XN(2);
	return 0;	
}
