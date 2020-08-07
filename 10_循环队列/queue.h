#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "stdio.h"
#include "stdlib.h"

#define MAX_SIZE 20

typedef enum Status{
    _success_,
    _fail_,
    _full_,
    _empty_
}Status;

typedef int Elemtype;

typedef struct queue
{
    Elemtype data[MAX_SIZE];
/*头指针*/
    int front;
/*尾指针,若队列不为空rear指向队列最后一个元素的下一个位置*/
    int rear;
}Queue,* PtrQueue;


#endif // !_QUEUE_H_