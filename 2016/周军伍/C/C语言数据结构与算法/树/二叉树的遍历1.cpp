#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Tree
{
	char date;
	struct Tree *lchild, *rchild;
};

int CreateTree(struct Tree *&T)
{
	char ch;
	scanf("%c", &ch);
	if(ch=='*')
		T=NULL;
	else{
		T=(struct Tree *)malloc(sizeof(struct Tree));
		T->date=ch;
		CreateTree(T->lchild);
		CreateTree(T->rchild);
	}
	return 0;
}

int PreOrder(struct Tree *T)
{
	if(T){
		printf("%c ", T->date);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
	return 0;
}

int InOrder(struct Tree *T)
{
	if(T){
		InOrder(T->lchild);
		printf("%c ", T->date);
		InOrder(T->rchild);
	}
	return 0;
}


int PostOrder(struct Tree *T)
{
	if(T){	
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c ", T->date);
	}
	return 0;
}

int main()
{
	struct Tree *T;
	CreateTree(T);
	
	PreOrder(T);
	printf("\n");
	
	InOrder(T);
	printf("\n");
	
	PostOrder(T);
	printf("\n");
	return 0;
}