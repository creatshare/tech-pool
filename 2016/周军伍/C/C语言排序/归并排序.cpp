#include<stdio.h>
#include<stdlib.h>
#define N 11

void Merge(int a[], int T[], int left, int center, int rightend)
{
	int i, leftend, num, tmp;
	leftend=center-1;
	tmp=left;
	num=rightend-left+1;
	
	while(left<=leftend && center <= rightend){
		if(a[left]<a[center])
			T[tmp++]=a[left++];
		else
			T[tmp++]=a[center++];
	}
	
	while(left <=leftend){
		T[tmp++]=a[left++];
	}
	while(center <= rightend){
		T[tmp++] = a[center++];
	}
	
	for(i=0; i<num; i++, rightend--)
		a[rightend] = T[rightend];
}

void MSort(int a[], int T[], int left, int right)
{
	int center;
	if(left<right){
		center=(left+right)/2;
		MSort(a, T, left, center);
		MSort(a, T, center+1, right);
		Merge(a, T, left, center+1, right); 
	}
}

void Mergesort(int a[])
{
	int *T;
	int n;
	T=(int *)malloc(N*sizeof(int));
	if(T!=NULL){
		MSort(a, T, 0, N-1);
		free(T);
	}else{
		printf("ERROR!"); 
	}
}

void Print(int a[])
{
	for(int i=0; i<N; i++)
		printf("%d ", a[i]);
}

int main()
{
	int arr[N]={11, 24, 21, 54, 34, 25, 18, 5, 42, 26, 30};
	Print(arr);
	printf("\n");
	
	Mergesort(arr);
	printf("\n");
	
	Print(arr);
	printf("\n");
	return 0;
}