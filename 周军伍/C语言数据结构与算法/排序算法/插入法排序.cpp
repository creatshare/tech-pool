/* 插入法排序*/ 

#include <stdio.h>
#include<stdlib.h>

//对数组排序 
void CrSort(int arr[], int n) 
{
	int i, j, temp;
	for(i=1;i<n;i++){		//每次以一个数为基准， 将其前面的的基准数大的移到后面去
		temp=arr[i];
		for(j=i; j>0 && arr[j-1]>temp; j--)	
			arr[j]=arr[j-1];
		arr[j]=temp;
	}
}


int main() 
{ 	
	int i, n;
	int *arr;
	printf("请输入数组个数："); 
	while(scanf("%d",&n)!=EOF){
		arr=(int *)malloc(n*sizeof(int));
		for(i=0;i<n;i++){	
			scanf("%d",&arr[i]);
		}

		CrSort(arr, n);
		
		//输出已排好序的数组 
		for(i=0;i<n;i++)
			printf("%d ",arr[i]);
		printf("\n");
		free(arr);
	}
	return 0;
	system("pause");
}
