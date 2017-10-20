#include <stdio.h>
#define N 10
int main()
{
	int a[N]={1,23,34,55,4,6,9,45,98,5},i,j,k,temp;
	for(i=0;i<9;i++)
	{  k=i;
  		for(j=k+1;j<10;j++)
     		{
     			if(a[k]<a[j])  
     			k=j;
     	    }
   				temp=a[i];
   				a[i]=a[k];
   				a[k]=temp;
	}
	 for ( i = 0; i < N; ++i)
     {
     	printf("%d\n",a[i]);/* code */
     }
}