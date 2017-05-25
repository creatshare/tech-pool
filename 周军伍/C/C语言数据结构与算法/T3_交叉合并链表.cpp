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

void CountLength(LinkList L, int *length)	//链表的长度计算
{
	LinkList pCur;
	pCur = L->next;

	int i = 0;
	while (pCur) {
		pCur = pCur->next;
		i++;
	}

	*length = i;
	return;
}

void Reverse(LinkList &L)	// 逆置链表
{
	LinkList pCur;
	LinkList temp;

	pCur = L->next;
	L->next = NULL;

	while (pCur) {
		temp = pCur->next;
		pCur->next = L->next;
		L->next = pCur;
		pCur = temp;
	}
	return;
}

void DirectMerge(LinkList &L1, LinkList &L2, LinkList &L)		//直接合并两个链表
{
	LinkList pCur;

	L->next = L1->next;
	pCur = L;

	//链表直接合并
	while (pCur->next) {
		pCur = pCur->next;
	}
	pCur->next = L2->next;

	free(L1);
	free(L2);

	return;
}

void CrossMerge(LinkList &L1, LinkList &L2, LinkList &L)	//交叉合并两个链表
{
	LinkList pCur;
	LinkList pCur1;
	LinkList pCur2;

	pCur = L;
	pCur1 = L1->next;
	pCur2 = L2->next;

	while (pCur2) {

		pCur->next = pCur1;
		pCur = pCur->next;		// L 指针后移
		pCur1 = pCur1->next;	// L1 链表的指针后移

		pCur->next = pCur2;
		pCur = pCur->next;		// L 指针后移
		pCur2 = pCur2->next;	// L2 链表指针后移
	}

	pCur->next = pCur1;		//

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

	int longA, longB;	//链表长度计算
	CountLength(LA, &longA);
	CountLength(LB, &longB);

	//printf("%d %d\n", longA, longB);

	LinkList L;		// 开创合并之后的头结点，方便输出，与后续使用
	L = (LinkList)malloc(sizeof(Node));
	L->next = NULL;		//头结点指针域为空，防止为合并之后为空的输出异常

	int lengthMax;
	lengthMax = longA > longB ? longA : longB;	// 计算长度最大值

	if (longA == lengthMax)		//交叉合并方式判断
		CrossMerge(LA, LB, L);
	else
		CrossMerge(LB, LA, L);

	printf("合并之后的链表:\n");
	Print(L);
	//printf("\n");


	system("pause");

	return 0;
}

