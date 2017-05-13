#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node	*next;	
}Node,*Linklist;


Linklist CreatFromTail()
{
	Linklist L;
	Node *s;
	Node *p;
	int x;
	L=(Linklist)malloc(sizeof(Node));
	L->next=NULL;
	p=L;
	
	while(1)
	{
		scanf("%d",&x);
		if(x!=0)
		{
			
			s=(Node *)malloc(sizeof(Node));
			s->data=x;
			
			p->next = s;	//尾插法 
			p = s;
		}
		else
		{
			p->next = NULL;
			break;
		}
		
	}
	return L;
	
}
void Output(Linklist L)
{
	Node *p;
	p=L->next;
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
	
}
void Reverse(Linklist L)
{
	Node *temp,*pre;
	
	pre = L->next;
	L->next = NULL;
	
	while(pre){
		temp = pre->next;
		pre->next = L->next;
		L->next = pre;
		pre = temp;
	}
}


int main()
{	
	Linklist L;
	
	L=CreatFromTail();//创建单链表
 	
	Output(L);//打印输出单链表
	
    Reverse(L);//逆置单链表
    
    Output(L); //打印逆置的链表 
    
	Reverse(L); //再次逆置 
	
	Output(L);	//打印再次逆置之后的链表 

	
}