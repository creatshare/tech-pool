//
// Created by DELL-XPS on 2017/6/6.
//
#include "Stack.h"
int IsEmpty(Stack S)//检测一个站是不是空栈
{
    return S ->TopOfStack ==EmmptyTOS;
}
void MakeEmpty(Stack S)//初始化一个堆栈
{
    S ->TopOfStack = EmmptyTOS;
}
int IsFull(Stack S) //检测一个堆栈是不是满了
{
    return (S ->TopOfStack == S->Capacity);
}
Stack CreateStack(int MaxElements)  //创建一个MaxElements大小的堆栈
{
    Stack S;
    if(MaxElements < MinStackSize ){
        printf("Stack size is too small");
        return NULL;
    }
    S =malloc(sizeof(struct StackRecord));
    S ->Array =malloc(sizeof(ElementType) * MaxElements);
    if (S ->Array == NULL) {
        printf("out of space !!!");
        return NULL;
    }
    S->Capacity = MaxElements;
    MakeEmpty(S);
    return S;
}
void DisposeStack( Stack S)  //释放一个栈
{
    if(S != NULL )
    {
        free(S ->Array);
        free(S);
    }
}
void Push(ElementType X,Stack S) //入栈
{
    if(IsFull(S))
        printf("Stack is full.");
    else
        S ->Array[++S->TopOfStack] = X;
}
ElementType Top(Stack S) //栈顶元素
{
    if(IsEmpty(S))
        return S->Array[S->TopOfStack];
}
void Pop(Stack S) //  出栈
{
    if(IsEmpty(S))
        printf("这是空栈.");
    else
        S ->TopOfStack--;
}
ElementType  TopAndPop(Stack S) //出栈并返回栈顶元素
{
    if(IsEmpty(S)==0 )
        return S->Array[S ->TopOfStack--];
    else
        return 0;
}
