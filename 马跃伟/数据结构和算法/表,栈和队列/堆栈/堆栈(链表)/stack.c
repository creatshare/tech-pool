//
// Created by DELL-XPS on 2017/6/6.
//
#include "stack.h"
Stack CreateStack() //创建一个堆栈的头结点,返回堆栈结点的指针
{
    Stack s;
    s = (Stack)malloc(sizeof(struct SNode));
    if(s == NULL){
        printf("Out of space!!!");
        return NULL;
    }
    s->Next =NULL;
    return s;
}

int IsEmpty(Stack s) //判断堆栈s是否为空,若为空返回1,否则返回0
{
    return (s ->Next == NULL);
}

void Push(ElementType item,Stack s)   //把元素item压入堆栈s
{
    Stack TemCell;
    TemCell = (Stack)malloc(sizeof(struct SNode));
    if(TemCell == NULL)
        printf("Out of space!!!");
    else{
            TemCell->Data = item;
            TemCell->Next = s->Next;
            s->Next = TemCell;
        }
}

ElementType  Pop(Stack s)  //删除并返回堆栈S的栈顶元素
{
    Stack FirstCell;
    ElementType TopElem;
    if( IsEmpty(s)){
        printf("堆栈是空的");
        return NULL;
    }else{
        FirstCell = s->Next;
        TopElem =FirstCell ->Data;
        s->Next =FirstCell ->Next;
    free(FirstCell);
        return TopElem;
    }
}

