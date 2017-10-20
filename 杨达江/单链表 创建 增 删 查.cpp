#include<stdio.h>
#include<stdlib.h>
int iCount=0;
struct list * creat_list();
void print(struct list * listhead);

struct list
{
	int num;
	struct list * Pnext;
};
///////////////
void print(struct list * listhead)
{
	struct list * pHead=listhead;
	while(pHead!=NULL)
	{
		printf("%d ",pHead->num);
		pHead=pHead->Pnext;
    }
    printf("\n");
    return;
}
/////////////////
struct list * creat_list()
{
    struct list * pHead=NULL;
	struct list *pNew,*pEnd;
	pNew=pEnd=(struct list * )malloc(sizeof(struct list));
	scanf("%d",&pNew->num);
	while(pNew->num!=0)
	{
	   iCount++;
	   if(iCount==1)
	   {  
	    pNew->Pnext=NULL;
	    pEnd=pNew;
	    pHead=pNew;
	   }
	   else
	   {
	   	pNew->Pnext=NULL;
	   	pEnd->Pnext=pNew;
	   	pEnd=pNew;
	   }
	  pNew=(struct list * )malloc(sizeof(struct list));
	  scanf("%d",&pNew->num);
	}
	free(pNew); 
	return pHead;
 }
 struct list * add(struct list * pHead)
 {
 	struct list * p=pHead;
 	struct list * pNew;
 	int temp;
 	scanf("%d",&temp);
 	fflush(stdin);
 	while(p&&p->num!=temp) p=p->Pnext;
 	pNew=(struct list * )(malloc(sizeof(struct list)));
 	scanf("%d",&pNew->num);
 	fflush(stdin);
 	pNew->Pnext=p->Pnext;
 	p->Pnext=pNew;
 	return pHead;
 }
 struct list * Delete(struct list * pHead)
 {
 	struct list * Pre;
 	struct list * pTemp=pHead;
 	int iTemp;
 	scanf("%d",&iTemp);
 	while(pTemp&&pTemp->num!=iTemp)
 	{
 		Pre=pTemp;
		pTemp=pTemp->Pnext;
	 }
	 Pre->Pnext=pTemp->Pnext;
	 free(pTemp);
	 return pHead;
 }
 //////////////////
 int main()
 {
 	struct list * head;
 	int temp;
 	printf("Please enter the number you want to store:\n");
 	head=creat_list();
 	for(;;)
 	{
 		printf("1.add\n2.Delete\n3.output\n");
 	    scanf("%d",&temp);
 	    fflush(stdin);
 	    if(temp==1) head=add(head);
 	    else if(temp==2) head=Delete(head);
 	    else if(temp==3) print(head);
 	    else printf("error\n");
	}
 	return 0;
}
