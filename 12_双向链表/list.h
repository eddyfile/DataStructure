#ifndef __LIST_H_
#include <stdio.h>
#include <stdlib.h>

/*待处理数据类型*/
typedef int ElemType;

/*返回状态*/
typedef enum {
    _Success_,
    _fail_
}Status;

typedef struct Node
{
    ElemType data;
    struct Node *prior;
    struct Node *next;
}Node,*PtrNode;



#endif // !__LIST_H_
