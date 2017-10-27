#include<stdio.h>
#include<string.h>
#define N 50
int n;
typedef struct{
	char name[20];
	char num[20];
	char type[20];
}Mail_list;
int input(Mail_list a[N])
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%s %s %s",a[i].name,a[i].num,a[i].type);
	}
	return 0;
}
int output(Mail_list a[N])
{
	printf("\nOutput:\n");
	int i;
	for(i=0;i<n;i++)
	{
		printf("%s %s %s\n",a[i].name,a[i].num,a[i].type);
	}
	return 0;
}
int query(Mail_list a[N])
{
	int i;
	char iname[20];
	scanf("%s",iname);
	for(i=0;i<n;i++)
	{
		if(strcmp(iname,a[i].name)==0) printf("%s\n",a[i].num);
	}
	return 0;
}
int add(Mail_list a[N])
{
	n++;
	scanf("%s %s %s",a[n-1].name,a[n-1].num,a[n-1].type);
	return 0;
}
int del(Mail_list a[N])
{
	int i,k;
	char iname[20];
    scanf("%s",iname);
    for(i=0;i<n;i++)
	{
		if(strcmp(iname,a[i].name)==0) break;
	}
	for(k=i;k<n-1;k++)
	{
		a[k]=a[k+1];
	}
	n--;
	return 0;
}
int main()
{
	int i;
	Mail_list Arr[N];
	printf("Please enter the number you want to enter:\n");
	scanf("%d",&n);
	printf("Please enter information:\n");
	input(Arr);
	for(;;)
	{
	    printf("\n1.add\n2.delete\n3.query\n4.output\n\nPlease choice:\n");
	    scanf("%d",&i);
	    if(i==1) 
	    {
		    add(Arr);
		    output(Arr);
	    }
	    if(i==2) 
	    {
		    del(Arr);
		    output(Arr);
	    }
	    if(i==3) query(Arr);
	    if(i==4) output(Arr);
	}
	return 0;
}
