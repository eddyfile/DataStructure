#ifndef __BASE_CONVERSION_H_
#define __BASE_CONVERSION_H_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef char ElemType;
#define STACK_INIT_SIZE 20
#define STACK_INCREASE_SIZE 10
typedef struct 
{
    ElemType *base;
    ElemType *top;
    int stacksize;
}stack,*PtrStack;

typedef enum Status{
    _Success_,
    _fail_,
    _Underflow
}Status;







#endif
