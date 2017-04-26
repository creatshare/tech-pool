#include<stdio.h>
#include<string.h>
#define N 100
int main()
{
	char cNum1[N],cNum2[N];
	int iNum1[N],iNum2[N],iSum[N];
	int Num1_legth,Num2_legth,i,Sum_legth=0,temp=0;
	memset(iNum1,0,sizeof(iNum1));   
    memset(iNum2,0,sizeof(iNum2));
    memset(iSum,0,sizeof(iSum));  
	gets(cNum1);
	gets(cNum2);
	Num1_legth=strlen(cNum1);
	Num2_legth=strlen(cNum2);
	for(i=0;i<Num1_legth;i++) iNum1[Num1_legth-i-1]=cNum1[i]-48;
	for(i=0;i<Num2_legth;i++) iNum2[Num2_legth-i-1]=cNum2[i]-48;
	//printf("%d",iNum1[60]);
	while(Sum_legth<Num1_legth||Sum_legth<Num2_legth)
	{
		iSum[Sum_legth]=iNum1[Sum_legth]+iNum2[Sum_legth]+temp;
		temp=iSum[Sum_legth]/10;
		iSum[Sum_legth]%=10;
		Sum_legth++;
	}
	//printf("%d\n",Sum_legth);
	iSum[Sum_legth]=temp;
	if(iSum[Sum_legth]==0)
	{
		for(i=Sum_legth-1;i>=0;i--) printf("%d",iSum[i]);
	}
	else
	{
		for(i=Sum_legth;i>=0;i--) printf("%d",iSum[i]);
	}
	return 0;
}
