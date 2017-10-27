#include<stdio.h>
#include<stdlib.h>
typedef struct list{
	int Num;
	struct list * pNext;
}List;
List * Creat_List()
{
	List * pHead=NULL;
	List * pNew;
	pNew=(List *)malloc(sizeof(List));
	scanf("%d",&pNew->Num);
	pHead=pNew;
	pNew->pNext=NULL;
	while(pNew->Num!=0)
	{
		pNew=(List *)malloc(sizeof(List));
		scanf("%d",&pNew->Num);
		pNew->pNext=pHead;
		pHead=pNew;
	}
	return pHead;
}
Print(List * Head)
{
	//List * pHead=Head->pNext;
	while(Head->pNext!=NULL)
	{
		printf("%d ",Head->Num);
	    Head=Head->pNext;
    }
}
List * ReverseList(List * phead)
{
	List * temp_1;
	List * temp_2;
	temp_1=phead->pNext;
	temp_2=temp_1;
	phead->pNext=NULL;
	while(temp_2!=NULL)
	{
		temp_2=temp_2->pNext;
		temp_1->pNext=phead;
		phead=temp_1;
		temp_1=temp_2;
	}
	return phead;
}
int main()
{
	List * Head=NULL;
	Head=Creat_List();
	Head=ReverseList(Head);
	Print(Head);
	return 0;
 }
