#include <stdlib.h>
#include <stdio.h>
 
void Merge(int sourceArr[],int tempArr[], int startIndex, int midIndex, int endIndex)
{
    int i = startIndex, j=midIndex+1, k = startIndex;   
    while(i!=midIndex+1 && j!=endIndex+1)   //将两个数组比较合并 
    {
        if(sourceArr[i] > sourceArr[j])
            tempArr[k++] = sourceArr[j++];
        else
            tempArr[k++] = sourceArr[i++];
    }
    while(i != midIndex+1)   //将较长数组剩余部分粘贴 
        tempArr[k++] = sourceArr[i++];
    while(j != endIndex+1)
        tempArr[k++] = sourceArr[j++];
    for(i=startIndex; i<=endIndex; i++)   //返回已合并的数组 
        sourceArr[i] = tempArr[i];
}
 
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
{
    int midIndex;
    if(startIndex < endIndex)
    {
        midIndex = (startIndex + endIndex) / 2;     //二分 
        MergeSort(sourceArr, tempArr, startIndex, midIndex);   //递归左边直至有序的“一位 ” 
        MergeSort(sourceArr, tempArr, midIndex+1, endIndex);   //递归右边直至一位 
        Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);  //将左右数组合并排序 
    }
}
 
int main(int argc, char * argv[])
{
    int a[8] = {50, 10, 20, 30, 70, 40, 80, 60};
    int i, b[8];
    MergeSort(a, b, 0, 7);
    for(i=0; i<8; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
