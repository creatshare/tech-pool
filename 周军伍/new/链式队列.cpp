#include<stdio.h>
#include<stdlib.h>

/*
*队列就像 水管一样，从一端进入，从另一端出去
*/

/* 队列的定义 */
typedef struct node1		//定义一个链队
{
	int data;
	struct node1 *next;
}QNode;

typedef struct node2	//链队列结构
{
	QNode *rear;	//指向队尾
	QNode *front;	//指向队头
}LQueue;

/* 创建一个带头结点的  空队 */
LQueue *InitLQueue()
{
	QNode *p;
	LQueue *q;

	q = (LQueue *)malloc(sizeof(LQueue));	// 申请头尾指针节点
	p = (QNode *)malloc(sizeof(QNode));	// 申请链队头结点

	p->next = NULL;
	q->front = p;
	q->rear = p;
	return q;
}

/* 入队 */
void InLQueue(LQueue *q, int x)
{
	QNode *p;
	p = (QNode *)malloc(sizeof(QNode));	//申请新节点
	p->data = x;
	p->next = NULL;

	q->rear->next = p;	// 将新加入的添加至 队尾
	q->rear = p;	// rear 指向队尾
}

/* 判断队空 */
int EmptyLQueue(LQueue *q)
{
	if (q->front == q->rear)	//头尾指针相等，队列为空
		return 0;
	else
		return 1;
}

/* 出队 */
int OutLQueue(LQueue *q, int *x)
{
	QNode *p;
	if ( EmptyLQueue(q) ) {
		printf("队空、\n");
		return 0;
	}
	else {
		p = q->front->next;
		q->front->next = p->next;
		*x = p->data;
		free(p);
		if (q->front->next == NULL)
			q->rear = q->front;
		return 1;
	}
}

/*出队操作*/
int main()
{
	;
}