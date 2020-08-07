#ifndef __MAIN_H_
#define __MAIN_H_

#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct DoubleNode{
    ElemType data;
    struct DoubleNode *prior;
    struct DoubleNode *next;
}DoubleNode,* PtrDoubleNode;

enum Status{
    _SUCCESS_,
    _FAIL_,
    _ERR_OR_
};


#endif // !__MAIN_H_
