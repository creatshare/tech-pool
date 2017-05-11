#include <stdio.h>
#define N 10
int main()
{
	int num[N],i,j,a;
	for (i = 0; i < N; ++i)
		num[i]=rand()%101;
	int t=num[0];
	for ( j = 0; j < N; ++i)
	{
		if (num[j]<num[j+1])
			t=num[j+1];
	}
	
	for ( a = 0;a < N; ++a)
	{
	   printf("%d\n",num[a] );
	}
	printf("%d\n",t );
}
