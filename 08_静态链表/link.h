#ifndef _LINK_H_
#define _LINK_H_
#include <stdio.h>
#include <stdlib.h>

/*待处理的数据类型*/
typedef int Elemtype;

/*定义处理的静态链表最大值*/
#define MAX_SIZE 20

/*函数返回状态*/
typedef enum{
    success,
    fail,
}Status;

/*静态链表结构*/
typedef struct Stack{
    Elemtype data;
    int cur;
}StackLink,*PtrStackLink;




Status LinkInit(PtrStackLink space);



#endif
