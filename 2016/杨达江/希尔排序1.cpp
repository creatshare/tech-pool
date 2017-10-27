#include<stdio.h>
shellsort(int Arr[],int n)
{
    int i, j, gap;  
  
    for (gap = n / 2; gap > 0; gap /= 2) //步长  
        for (i = 0; i < gap; i++)       //从头到gap第一个数 
        {  
            for (j = i + gap; j < n; j += gap)   //找有序数列 
                if (Arr[j] < Arr[j - gap])  
                {  
                    int temp = Arr[j];  
                    int k = j - gap;  
                    while (k >= 0 && Arr[k] > temp)  //从无序的数向前遍历找位置 
                    {  
                        Arr[k + gap] = Arr[k];  //向后移 
                        k -= gap;  
                    }  
                    Arr[k + gap] = temp;  //插入 
                }  
        }  
}
int main()
{
	int i;
	int arr[10]={10,9,8,7,6,5,4,3,2,1};
	shellsort(arr,10);
	for(i=0;i<10;i++) printf("%d ",arr[i]);
	return 0;
 }
