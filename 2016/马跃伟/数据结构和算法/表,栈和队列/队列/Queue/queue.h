//
// Created by DELL-XPS on 2017/6/7.
//
#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;

struct QueueRecord {
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType * Array;
};
#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

struct  QueueRecord;
typedef struct QueueRecord * Queue;

int IsEmpty( Queue Q); //测试一个队列是否为空;
int IsFull(Queue Q); //测试一个队列是否已经满了;
Queue CreateQueue(int MaxElements); //创建一个最大长度为MaxElements队列
void DisposeQueue(Queue Q) ;  //清空一个队列;
void MakeEmpty(Queue Q);//初始化一个队列;
void Enqueue(ElementType x,Queue Q);//放入一个x元素到队列里面
void Dequeue(Queue Q); //出队
ElementType Front(Queue Q);//读取队列头
ElementType FrontAndDequeue(Queue Q);//
#endif //QUEUE_QUEUE_H
