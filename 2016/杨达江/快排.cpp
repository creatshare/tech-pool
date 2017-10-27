#include<stdio.h>
#define N 50
int Arr[N];
Quick_Sort(int left,int right)
{
	if(left>right) return 0;
	int i,j,t,temp;
	temp=Arr[left];
	i=left;
	j=right;
	while(i!=j)
	{
		while(i<j&&Arr[j]>=temp)//  找较大位置 
		{
			j--;
		}
		while(i<j&&Arr[i]<=temp)  // 找较小位置 （注意等号，上面等号可不加，下面必须加）   
		{
			i++;
		}
	    if(i<j)     //  交换 
	    {
	    	t=Arr[i]; 
            Arr[i]=Arr[j]; 
            Arr[j]=t; 
		}
	}   //  填中间值 
	Arr[left]=Arr[i];
	Arr[i]=temp;
	Quick_Sort(left,i-1);  //  递归左边 
	Quick_Sort(i+1,right);  //  递归右边 
}
int main()
{
	int n;
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&Arr[i]);
	Quick_Sort(1,n);
	for(i=1;i<=n;i++) printf("%d ",Arr[i]);
	return 0;
 }
