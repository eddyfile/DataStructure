#ifndef _STACK_H_
#define _STACK_H_
#include <stdio.h>
#include <stdlib.h>

#define bool int
/*链栈的大小*/
#define STACK_MAX_SIZE 20

/*定义待处理的数据类型*/
typedef int ElemType;

/*链栈结点的结构*/
typedef struct Stacknode {
    ElemType data;
    struct Stacknode *next;
}Stacknode,*PtrStacknode;

/*栈的类型*/
typedef struct{
    PtrStacknode top;
    int count;
}LinkStack;

/*定义状态*/
typedef enum Statuc{
    success,
    fail,
    error,
    full,
    empty
}Status;

Status Stack_Init(LinkStack *s);
bool Stack_Empty(LinkStack *s);
Status Stack_Push(LinkStack *Stack, ElemType *elem);
Status Stack_Pop(LinkStack *Stack,ElemType *elem);
void Stack_Print(LinkStack *s);





#endif // !_STACK_H_
