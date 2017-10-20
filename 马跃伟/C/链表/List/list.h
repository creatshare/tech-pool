#include <stdio.h>
#include <stdlib.h>
#ifndef __TOOLS_H__
#define __TOOLS_H__
typedef char *  ElementType;
struct  LNode;
typedef struct LNode * List;
struct LNode{
    ElementType Data;
    List Next;
};
int Length(List PtrL); //求表长
List FindKth(int K,List PtrL); //找出第K个节点的位置
List Find(ElementType a, List PtrL); //找到第一次值为a的节点的位置
List Insert(ElementType X, int i,List PtrL); //在第i个位置插入一个值为X的节点.
List Delete(int i,List PtrL);//删除第i个结点
List Chage(ElementType X,int i,List PtrL); //将第i个位置的值修改为X
void Show(int i,List PtrL); //输出第i个位置的结点

void show_all(List PrtL);
void show_one(List PrtL);
void wirte_one(List PrtL);
void change_one(List PrtL);
void delete_one(List PrtL);
#endif