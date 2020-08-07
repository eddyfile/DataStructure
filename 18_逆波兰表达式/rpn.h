#ifndef _RPN_H_
#define _RPN_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define STACK_INIT_SIZE 20
#define STACK_INCREMENT 10
#define MAXBUFFER 10
#define bool int


typedef double ElemType;

typedef struct
{
    ElemType *base;
    ElemType *top;
    int stacksize;
}stack;

typedef enum{
    _success_,
    _fail_,
    _empty_,
    _error_
}Status;

Status InitStack(stack *s);
Status PushStack(stack *s,ElemType dat);
Status PopStack(stack *s,ElemType *dat);
int LengthStack(stack *s);




#endif // !_RPN_H_
