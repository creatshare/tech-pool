///顺序栈

#include<stdio.h>
#include<stdlib.h>

/* 顺序栈的描述 */
#define MAXSIZE 10	
typedef struct
{
	int data[MAXSIZE];
	int top;
}SeqStack;

/* 置空栈，首先建立栈空间，然后初始化栈顶指针 */
SeqStack *InitSeqStack()
{
	SeqStack *s;
	s = malloc(sizeof(SeqStack));
	s->top = -1;
	return s;
}

/* 判断空栈 */
int EmptySeqStack(SeqStack *s)
{
	if (s->top == -1)
		return 1;
	else
		return 0;
}

/* 入栈 */
int PushSeqStack(SeqStack *s, int x)
{
	if (s->top == MAXSIZE - 1)	//栈满不能入栈
		return 0;
	else {
		s->top++;
		s->data[s->top] = x;
		return 1;
	}
}

/* 出栈 */
int PopSeqStack(SeqStack *s, int *x)
{
	if (EmptySeqStack(s))
		return 0;
	else {
		*x = s->data[s->top];	//栈顶元素存为入 *x
		s->top--;
		return 1;
	}
}

/* 取栈顶元素 */
int TopSeqStack(SeqStack *s)
{
	if (EmptySeqStack(s))
		return 0;
	else {
		return (s->data[s->top]);
	}
}
int main()
{

}