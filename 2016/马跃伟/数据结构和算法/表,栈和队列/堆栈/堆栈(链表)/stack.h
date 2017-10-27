//
// Created by DELL-XPS on 2017/6/6.
//
#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
#ifndef STACK_STACK_H
#define STACK_STACK_H
        typedef struct SNode*  Stack;
        struct SNode;
        Stack CreateStack(); //创建一个堆栈的头结点,返回堆栈结点的指针
        int IsEmpty(Stack s); //判断堆栈s是否为空,若为空返回1,否则返回0
        void Push(ElementType item,Stack s); //把元素item压入堆栈
        ElementType  Pop(Stack s);  //删除并返回堆栈S的栈顶元素

#endif //STACK_STACK_H
struct SNode {
    ElementType Data;
    struct SNode *Next;
};