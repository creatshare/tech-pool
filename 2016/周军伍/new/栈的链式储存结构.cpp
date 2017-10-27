/* 链栈 */

/*
*栈底就是链表的最后一个节点， 栈顶就是链表的第一个节点
*这个设计就使得出栈入栈很方便，节约时间
*/

#include<stdio.h>
#include<stdlib.h>

/* 链栈的定义*/
typedef struct Stacknode
{
	int data;
	struct Stacknode *next;
}slStacktype;

/* 入栈操作 */
int PushStack(slStacktype *top, int x)
{
	/* 将元素 x 压入链栈top中*/
	slStacktype *p;
	if ((p = (slStacktype *)malloc(sizeof(slStacktype))) == NULL)
		return 0;
	/*申请一个节点*/
	p->data = x;
	p->next = top->next;
	top->next = p;
	return 1;
}

/* 出栈 */
int PopStack(slStacktype *top)
{
	slStacktype *p;
	int x;
	if (top->next == NULL)
		return NULL; //空栈
	p = top->next;
	top->next = p->next;
	x = p->next;
	free(p);
	return x;
}



int main()
{

	system("pausse");
	return 0;
}