#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_
#include <stdio.h>
#include <stdlib.h>

#define bool int
#define TRUE 1
#define FALSE 0

/*定义待处理的数据类型*/
typedef int Elemtype;

/*定义函数返回值类型*/
typedef enum Status{
    _Success_,
    _Fail_
}Status;

/*定义链队列的结点类型*/
typedef struct QueueNode
{
    Elemtype data;
    struct QueueNode* next;
}QueueNode,*PtrQueueNode;

/*定义队列类型，包含头尾两个指针*/
typedef struct Queue
{
    PtrQueueNode front;/*头指针*/
    PtrQueueNode rear;/*尾指针*/
}Queue,*PtrQueue;

Status QueueLinkInit(PtrQueue que_);
Status DestroyQueue(PtrQueue _que_);
bool QueueEmpty(PtrQueue _que_);
int QueueLength(PtrQueue _que_);
Status GetTopQueue(PtrQueue _que_,int topdata);
Status InsertQueue(PtrQueue _que_, Elemtype e);
void PrintQueue(PtrQueue _que_);



#endif // !_LINKQUEUE_H_
