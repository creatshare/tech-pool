#include<stdio.h>
#define N 20
int BinarySearch(int arr[], int x, int n)
{
	int low, mid, high;
	low=0; high=n-1;
	while(low<=high){
		mid=(low+high)/2;
		if(arr[mid]<x)
			low=mid+1;
		else
			if(arr[mid]>x)
				high=mid-1;
			else
				return mid;
	}
	return -1;
}

int main()
{
	int arr[N];
	for(int i=1; i<=N; i++)
		arr[i]=i*2;
	int x;
	scanf("%d", &x);
	int flag;
	flag=BinarySearch(arr, x, N);
	if(flag==-1)
		printf("查无此数！\n");
	else
		printf("%d\n", flag);
} 