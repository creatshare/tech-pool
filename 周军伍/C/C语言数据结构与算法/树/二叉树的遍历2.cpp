#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
typedef struct Node
{
	char data;
	struct Node *lchild, *rchild;
}BiNode, *BiTree;

int CreateTiTree(BiTree &T)
{
	char ch;
	scanf("%c", &ch);
	if(ch=='*')
		T=NULL;
	else{
		T=(BiTree)malloc(sizeof(BiNode));
		T->data=ch;
		CreateTiTree(T->lchild);
		CreateTiTree(T->rchild);
	}
	return 0;
}


int PreOrder(BiTree T)
{
	if(T){
		printf("%c ", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
	return 0;
}

int InOrder(BiTree T)
{
	if(T){
		InOrder(T->lchild);
		printf("%c ", T->data);
		InOrder(T->rchild);
	}
	return 0;
}

int PostOrder(BiTree T)
{
	if(T){
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c ", T->data);
	}
	return 0;
}


int main()
{
	BiTree T;
	printf("用先序构建二叉树， 根为空时用 * \n");
	CreateTiTree(T);
	printf("先序遍历：");
	PreOrder(T);
	printf("\n中序遍历：");
	InOrder(T);
	printf("\n后序遍历：");
	PostOrder(T);
	printf("\n"); 
	return 0;
}