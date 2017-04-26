#include<stdio.h>
#include<stdlib.h>

typedef enum PointerTag{Link, Thread};	//Link 指向孩子 Thread 指向前驱，或者后继

typedef struct ThBiNode
{
	char data;
	ThBiNode *lchild, *rchild;
	PointerTag LTag, RTag;
}ThBiNode, *ThBiTree;

void InThreading(ThBiTree T, ThBiTree &pre)
{
	if(T){
		InThreading(T->lchild, pre);
		if(!T->lchild){
			T->LTag=Thread;
			T->lchild=pre;
		}else{
			T->LTag=Link;
		}
		
		if(!pre->rchild){
			pre->RTag=Thread;
			pre->rchild=T;
		}else{
			pre->RTag=Link;
		}
		
		pre=T;
		InThreading(T->rchild, pre);
	}
}

void InOrderThreading(ThBiTree T, ThBiTree &Th)
{
	ThBiTree *pre;
	Th=(ThBiTree)malloc(sizeof(ThBiNode));
	Th->LTag=Link;
	Th->RTag=Thread;
	if(!T){
		Th->lchild=Th;
		Th->rchild=Th;
	}else{
		Th->lchild=T;
		ThBiNode *pre = Th;
		InThreading(T, pre);
		pre->RTag=Thread;
		pre->rchild=Th;
		Th->rchild=pre; 
	}
}

void InOrderTraversePrint(ThBiTree T)
{
	ThBiNode *p = T->lchild;
	while(p != T){
		while(p->LTag== Link){
			p = p->lchild;
		}
		printf("%c ", p->data);
		
		while(p->RTag == Thread && p->rchild != T){
			p = p->rchild;
			printf("%c ", p->data);
		}
		
		p = p->rchild;
	}
	printf("\n");
}

void Create(ThBiTree &T)
{
	char ch;
	scanf("%c", &ch);
	if(ch == '*'){
		T=NULL;
	}else{
		T=(ThBiTree)malloc(sizeof(ThBiNode));
		T->data = ch;
		Create(T->lchild);
		Create(T->rchild);
	}
}

int main()
{
	ThBiTree T, Th;
	Create(T);
	InOrderThreading(T, Th);
	InOrderTraversePrint(Th);
}