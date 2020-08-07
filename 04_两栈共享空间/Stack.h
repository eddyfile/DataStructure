#ifndef _STACK_H_
#define _STACK_H_
#include <stdio.h>
#include <stdlib.h>

#define bool int

/*存储空间分配*/
#define STACK_MAX_SIZE 20

#define STACK_ONE 1
#define STACK_TWO 2

/*栈中保存的数据类型*/
typedef int ElemType;

/*两栈共享空间结构*/
typedef struct stack{
    ElemType date[STACK_MAX_SIZE];
    int stack_top1;/*栈1栈顶指针*/
    int stack_top2;/*栈2栈顶指针*/
}DoubleStack,*PtrDoubleStack;

/*定义函数的返回状态*/
typedef enum Status{
    success,
    fail,
    error,
    full,
    empty
}Status;








Status Stack_Init(PtrDoubleStack s);
Status Stack_Push(PtrDoubleStack s,ElemType *e, int StackNumber);
bool Stack_Empty(PtrDoubleStack s);
Status Stack_Pop(PtrDoubleStack s, ElemType *elem, int StackNumber);
int Stack_Length(PtrDoubleStack s);
void Stack_Print(PtrDoubleStack s);
Status Stack_Clear(PtrDoubleStack s);



#endif // !_STACK_H_