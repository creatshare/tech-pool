/* 选择排序 */

#include<stdio.h>
#include<stdlib.h>

void XzSort(int *arr, int n)
{
	int i, j, temp;		//依次在剩余的元素中查找最值元素，插入到合适位置
	for (i = 0; i < n; i++) {	//利用内循环找到一个最值，然后交换
		for (j = i+1; j < n; j++) {
			if (arr[i] > arr[j]) {		//j的查找范围始终是在i的后面，所以能够找到最值
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main()
{
	int n, *arr, i;
	printf("请输入数组元素的个数：");
	while (scanf("%d", &n) != EOF) {
		arr = (int *)malloc(n * sizeof(int));
		
		for (i = 0; i < n; i++)
			scanf("%d", arr + i);
		
		XzSort(arr, n);

		for (i = 0; i < n; i++)
			printf("%d ", *(arr + i));
		printf("\n");
	}
	return 0;
	system("pause");
}