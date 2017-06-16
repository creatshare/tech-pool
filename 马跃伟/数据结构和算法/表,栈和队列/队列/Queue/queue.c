//
// Created by DELL-XPS on 2017/6/7.
//
#include "queue.h"

int IsEmpty( Queue Q)//测试一个队列是否为空;
{
    return Q ->Size == 0 ;
}
int IsFull(Queue Q)//测试一个队列是否已经满了;
{
    return Q->Size == Q->Capacity;
}
Queue CreateQueue(int MaxElements) //创建一个最大长度为MaxElements队列
{
    Queue Q;
    Q = (Queue)malloc(sizeof(struct QueueRecord));
    Q->Array =malloc(sizeof(ElementType) * MaxElements);
    if(Q ->Array == NULL)
    {
        printf("out of space!!!");
        return NULL;
    }
    MakeEmpty(Q);
    Q ->Capacity=MaxElements;
    return  Q;
}
void DisposeQueue(Queue Q)   //清空一个队列;
{

}
void MakeEmpty(Queue Q)//初始化一个队列;
{
    Q ->Size =0;
    Q ->Front =1;
    Q ->Rear =0;
}
static int Succ(int value,Queue Q){
    if(++value ==Q->Capacity )
        value =0;
    return value;
}
void Enqueue(ElementType x,Queue Q)//放入一个x元素到队列里面
{
    if(IsFull(Q))
        printf("Full queue");
    else {
        Q->Size++;
        Q->Rear = Succ(Q->Rear,Q);
        Q->Array[Q->Rear] = x;
    }
}
void Dequeue(Queue Q) //出队
{
    if(IsEmpty(Q))
        printf("Empty queue");
    else{
        Q->Size--;
        Q->Front = Succ(Q->Front,Q);
    }
}
ElementType Front(Queue Q)//读取队列头
{
    if(IsEmpty(Q))
        printf("Empty queue");
    else
        return Q->Array[Q->Front];
}
ElementType FrontAndDequeue(Queue Q)//读取队列的开头并出队
{
    int X;
    if(IsEmpty(Q))
        printf("Empty queue");
    else
    {
        X=Q->Array[Q->Front];
        Q->Size--;
        Q->Front = Succ(Q->Front,Q);
    }
    return X;
}
