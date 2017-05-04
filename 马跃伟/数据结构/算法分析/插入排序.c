#include <stdio.h>
#define N 7
int main()
{
	int a[N]={1,4,5,8,7,2,9};
	int i,t,p;
	for (i =1; i < N; ++i)
	{
		t=a[i];
		p=i-1;
		while(p>=0 && t<a[p])
		{
			a[p+1]=a[p];
			p--;
		}
		a[p+1]=t;
	}
	 for ( i = 0; i < N; ++i)
     {
     	printf("%d\n",a[i]);/* code */
     }
}