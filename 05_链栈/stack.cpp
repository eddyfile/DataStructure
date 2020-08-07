#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/**************************************
*函数名称：Stack_Init(LinkStack *s)
*描   述：
*        初始化一个链栈
*参   数：
*        LinkStack *s 传入需要初始化的栈
*返回值 ：
*        success 成功
*        fail    失败
*  top       top-1
* -------    -------       -------    ------- 
  |   | |    |   | |  ~~~  |   | |    |   | | 
* -------    -------       -------    -------
*   \_________________  ___________________/
*                     \/ 
*  栈顶              count              栈尾
*注   意：栈顶为链表得第一个元素
***************************************/
Status Stack_Init(LinkStack *s)
{
    Status outcome = fail;
    s ->top = (PtrStacknode)malloc(sizeof(Stacknode));
    if(!s->top)
    {
        return outcome;/*空间申请失败*/
    }
    else
    {
        s ->top = NULL;
        s ->count = 0;
        outcome = success;
    }
    return outcome;
}

/**************************************
*函数名称：Stack_Empty(LinkStack *s)
*描   述：
*        判断栈是否为空
*参   数：
*        LinkStack *s 传入的栈
*返回值 ：
*        1    空栈
*        0    非空
***************************************/
bool Stack_Empty(LinkStack *s)
{
    return (s ->count == 0);    
}

/**************************************
*函数名称：Stack_Push(LinkStack *Stack, ElemType *elem)
*描   述：
*        压栈操作
*参   数：
*        LinkStack *Stack 传入的栈
*        ElemType *elem   待压入的数据
*返回值 ：
*        success   成功
*        fail      失败
***************************************/
Status Stack_Push(LinkStack *Stack, ElemType *elem)
{
    Status outcome = success;
    PtrStacknode s = (PtrStacknode)malloc(sizeof(Stacknode));
    if(s != NULL)
    {
        s ->data = *elem;
        s ->next = Stack ->top;
        Stack ->top = s;
        Stack ->count++;
    }
    else
    {
        outcome = fail;/*压栈操作失败*/
    }
    return outcome;
}

/**************************************
*函数名称：Stack_Pop(LinkStack *Stack,ElemType *elem)
*描   述：
*        出栈操作
*参   数：
*        LinkStack *Stack 传入的栈
*        ElemType *elem   出栈的数据保存到*elem
*返回值 ：
*        success   成功
*        empty     空栈无法弹出
***************************************/
Status Stack_Pop(LinkStack *Stack,ElemType *elem)
{
    Status outcome = success;
    if(Stack ->count != 0)
    {
        *elem = Stack ->top ->data;
        Stack ->top = Stack ->top ->next;
        Stack ->count--;
    }
    else
    {
        outcome = empty;/*空栈无法弹出*/
    }
    return outcome;
}

/**************************************
*函数名称：Stack_Print(LinkStack *s)
*描   述：
*        打印链栈
*参   数：
*        LinkStack *s 传入的栈
*返回值 ：
*        无
***************************************/
void Stack_Print(LinkStack *s)
{
    PtrStacknode p;
    p = s ->top;
    while(p)
    {
        printf("%d ",p ->data);
        p = p ->next;
    }
    printf("\n");
}
