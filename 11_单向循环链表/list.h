#ifndef __LIST_H
#include <stdio.h>
#include <stdlib.h>




//定义处理的数据类型
typedef int ElemType;
#define bool int

//定义状态
typedef enum Status
{
    success, fail, fatal, rang_err
}Status;

//定义数据类型的结构
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node,*PtrList;


#endif // !__LIST_H