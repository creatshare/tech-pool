//
// Created by DELL-XPS on 2017/6/6.
//
#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
#ifndef STACKARRY_STACK_H
#define STACKARRY_STACK_H
struct StackRecord;
typedef  struct StackRecord * Stack;
int IsEmpty(Stack S); //检测一个站是不是空栈
int IsFull(Stack S); //检测一个堆栈是不是满了
void MakeEmpty(Stack S); //初始化一个堆栈
Stack CreateStack(int MaxElements); //创建一个MaxElements大小的堆栈
void DisposeStack( Stack S) ; //释放一个栈
void Push(ElementType X,Stack S); //入栈
ElementType Top(Stack S); //栈顶元素
void Pop(Stack S) ;//  出栈
ElementType  TopAndPop(Stack S); //出栈并返回栈顶元素
#endif //STACKARRY_STACK_H
#define EmmptyTOS (-1)
#define MinStackSize 5
struct StackRecord{
    int Capacity;       //堆栈大小
    int TopOfStack;
    ElementType * Array;
};