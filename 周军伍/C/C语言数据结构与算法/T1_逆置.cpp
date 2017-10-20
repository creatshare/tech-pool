#include<stdio.h>
#include<stdlib.h>

//typedef int Element;

typedef struct node		// 定义节点
{
	int data;
	struct node *next;
}Node, *LinkList;


void CreatList(LinkList &L)	// 创建链表
{
	int data;
	LinkList LNew, pre;

	pre = L;

	printf("请输入数字创建一个链表（输入为0时结束）:\n");
	while (1) {
		scanf("%d", &data);
		if (data == 0)
			break;

		LNew = (LinkList)malloc(sizeof(Node));
		LNew->data = data;

		pre->next = LNew;
		pre = LNew;
	}
	pre->next = NULL;
}

void Print(LinkList L)	// 打印链表
{
	LinkList pre;
	pre = L->next;

	//int i = 0;
	while (pre) {
		printf("%d ", pre->data);
		pre = pre->next;
		//	i++;
	}
	printf("\n");
	//printf("i = %d", i);
}


void Reverse(LinkList &L)	// 逆置链表
{
	LinkList pre;
	LinkList temp;

	pre = L->next;
	L->next = NULL;

	while (pre) {
		temp = pre->next;
		pre->next = L->next;
		L->next = pre;
		pre = temp;
	}
}


int main()
{
	LinkList L;
	L = (LinkList)malloc(sizeof(Node));

	CreatList(L);	//创建链表

	Print(L);		//输出链表

	Reverse(L);		//逆置链表

	printf("逆置之后的链表为：\n");
	Print(L);		//输出链表

	system("pause");

	return 0;
}

