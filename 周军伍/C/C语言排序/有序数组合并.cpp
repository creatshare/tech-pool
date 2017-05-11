#include<stdio.h>
#include<stdlib.h>

int *MSort(int a[], int n, int b[], int m)
{
	int i, j, k;
	int *c;
	c=(int *)malloc(sizeof(int));
	i=j=k=0;
	while(i<n && j<m){
		if(a[i]<b[j])
			c[k++]=a[i++];
		else
			c[k++]=b[j++];
	}
	while(i<n)
		c[k++]=a[i++];
	while(j<m)
		c[k++]=b[j++];
		
	return c;
}

int main()
{
	int m, n;
	int *c;
	int a[]={1,5,9,15,48,78,89,123,148,178};
	int b[]={2,4,6,12,23,28,79,145,189,369,781,890,1189};
	n=sizeof(a)/sizeof(int);
	m=sizeof(b)/sizeof(int);
	
	c=MSort(a, n, b, m);
	
	for(int h=0; h<m+n; h++)
		printf("%d  ", c[h]);
	return 0; 
}