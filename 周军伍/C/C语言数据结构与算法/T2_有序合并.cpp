#define _CRT_SECURE_NO_WARNINGS		//预编译处理
#include<stdio.h>
#include<stdlib.h>


typedef struct node		// 定义节点
{
	int data;
	struct node *next;
}Node, *LinkList;


void CreatList(LinkList &L)	// 创建链表
{
	int data;
	LinkList LNew, pCur;

	pCur = L;

	printf("请输入数字创建一个链表（输入为0时结束）:\n");
	while (1) {
		scanf("%d", &data);
		if (data == 0)
			break;

		LNew = (LinkList)malloc(sizeof(Node));
		LNew->data = data;

		pCur->next = LNew;
		pCur = LNew;
	}
	pCur->next = NULL;
	return;
}

void Print(LinkList L)	// 打印链表
{
	if (L->next == NULL) {		//判断空链表
		printf("此链表为空！\n");
		return;
	}

	LinkList pCur;
	pCur = L->next;

	while (pCur) {
		printf("%-4d ", pCur->data);
		pCur = pCur->next;
	}
	printf("\n");
	return;
}

//方法1
/*
void SortMerge(LinkList &L1, LinkList &L2, LinkList &L)	//有序合并
{
	LinkList pCur;
	LinkList pCur1;
	LinkList pCur2;

	pCur = L;
	pCur1 = L1->next;
	pCur2 = L2->next;

	int temp;
	while (pCur1 && pCur2) {
		if (pCur1->data < pCur2->data) {
			pCur1 = pCur1->next;
		}
		else {
			temp = pCur1->data;
			pCur1->data = pCur2->data;
			pCur2->data = temp;
			if (pCur2->data > pCur2->next->data) {
				temp = pCur2->data;
				pCur2->data = pCur2->next->data;
				pCur2->next->data;
			}
		}
	}
}
*/


void SortMerge(LinkList &L1, LinkList &L2, LinkList &L)	//合并两个同序链表
{
	LinkList pCur;
	LinkList pCur1;
	LinkList pCur2;

	pCur = L;
	pCur1 = L1->next;
	pCur2 = L2->next;

	while (pCur1 && pCur2) {
		if (pCur1->data < pCur2->data) {
			pCur->next = pCur1;
			pCur1 = pCur1->next;
			pCur = pCur->next;
		}
		else {
			pCur->next = pCur2;
			pCur2 = pCur2->next;
			pCur = pCur->next;
		}
	}
	
	if (pCur1) {
		pCur->next = pCur1;
	}
	else {
		pCur->next = pCur2;
	}
	
	free(L1);
	free(L2);
	return; 
}

int main()		//主函数
{
	LinkList LA, LB;	// A, B 链表的声明和头结点空间申请
	LA = (LinkList)malloc(sizeof(Node));
	LB = (LinkList)malloc(sizeof(Node));

	CreatList(LA);	//创建链表
	CreatList(LB);

	Print(LA);		//输出链表
	Print(LB);


	LinkList L;		// 开创合并之后的头结点，方便输出，与后续使用
	L = (LinkList)malloc(sizeof(Node));
	L->next = NULL;		//头结点指针域为空，防止为合并之后为空的输出异常

	SortMerge(LA, LB, L);

	//Print(LA);
	//Print(LB);

	printf("合并之后的链表:\n");
	Print(L);

	system("pause");

	return 0;
}

