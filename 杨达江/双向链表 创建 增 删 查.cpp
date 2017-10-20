#include<stdio.h>
#include<stdlib.h>
int iCloud=0;
typedef struct Two_way_linked_list{
	int iNum;
	Two_way_linked_list * Rhead;
	Two_way_linked_list * Lhead;
}Two_List;
Two_List * Creat_List()
{
	Two_List * Head=NULL;
	Two_List * pNew;
	Two_List * pEnd;
	pEnd=pNew=(Two_List *)malloc(sizeof(Two_List));
	scanf("%d",&pNew->iNum);
	while(pNew->iNum!=0){
		if(iCloud==0)
		{
			pNew->Rhead=NULL;
			pNew->Lhead=NULL;
			Head=pNew;
			iCloud++;
		}
		else{
			pNew->Rhead=NULL;
			pEnd->Rhead=pNew;
			pNew->Lhead=pEnd;
			pEnd=pNew;
			iCloud++;
		}
		pNew=(Two_List *)malloc(sizeof(Two_List));
	    scanf("%d",&pNew->iNum);
	}
	free(pNew);
	return Head;
}
add(Two_List * Head)
{
	Two_List * p=Head;
 	Two_List * pNew;
 	int temp;
 	scanf("%d",&temp);
 	while(p&&p->iNum!=temp) p=p->Rhead;
 	pNew=(Two_List * )malloc(sizeof(Two_List));
 	scanf("%d",&pNew->iNum);
 	p->Rhead->Lhead=pNew;
 	pNew->Rhead=p->Rhead;
 	pNew->Lhead=p;
 	return 0;
}
Delete(Two_List * Head)
{
	int Temp;
	scanf("%d",&Temp);
	while(Head&&Head->iNum!=Temp) 
	{
		Head=Head->Rhead;
	}
	Head->Lhead->Rhead=Head->Rhead;
	Head->Rhead->Lhead=Head->Lhead;
	free(Head);
	return 0;
}
print(Two_List * pHead)
{
	while(pHead->Rhead!=NULL)
	{
		pHead=pHead->Rhead;
	}
	while(pHead!=NULL)
	{
		printf("%d ",pHead->iNum);
		pHead=pHead->Lhead;
	}
	printf("\n");
	return 0;
}
int main()
{
	int temp;
	Two_List * Head;
	Head=Creat_List();
	for(;;)
 	{
 		printf("1.add\n2.Delete\n3.output\n");
 	    scanf("%d",&temp);
 	    if(temp==1) add(Head);
 	    else if(temp==2) Delete(Head);
 	    else if(temp==3) print(Head);
 	    else printf("error\n");
	}
	return 0;
}
