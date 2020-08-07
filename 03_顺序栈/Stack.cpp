#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
/**************************************
*函数名称：Statck_Init(StackPtr s)
*描   述：
*        初始化一个栈
*参   数：
*        StackPtr s 传入需要初始化的栈
*返回值 ：
*        success 成功
*        fail    失败
***************************************/
Status Stack_Init(StackPtr s)
{
    Status outcome = fail;
    StackPtr p = NULL;
    p = (StackPtr)malloc(STACK_MAX_SIZE*sizeof(StackElemType));
    if(p == NULL)
    {
        return outcome;/*空间未申请成功*/
    }
    else
    {
        s->top = -1; 
        outcome = success;
    }
    return outcome;
}

/***************************************************
*函数名称：Stack_Push(StackPtr s,StackElemType elem)
*描   述：
*        顺序栈入栈操作的实现
*参   数：
*        StackPtr s 传入栈
*        StackElemType elem 需要压栈的数据
*返回值 ：
*        success  成功
*        overflow 栈上溢出
****************************************************/
Status Stack_Push(StackPtr s, StackElemType elem)
{
    Status outcome = success;
    if(s->top == STACK_MAX_SIZE -1)
    {
        outcome = overflow;/*栈满，上溢*/
    }
    else
    {
        s -> top++;
        s -> date[s->top] = elem;
    }
    return outcome;
}

/***************************************************
*函数名称：Stack_Pop(StackPtr s,StackElemType *elem)
*描   述：
*        顺序栈出栈操作的实现
*参   数:
*        StackPtr s 传入栈
*        StackElemType *elem 出栈的数据赋值给*elem
*返回值：
*        success  成功
*        underflow 栈下溢出
****************************************************/
Status Stack_Pop(StackPtr s,StackElemType *elem)
{
    Status outcome = success;
    if(s -> top == -1)
    {
        outcome = underflow;/*栈下溢*/
    }
    else
    {
        *elem = s->date[s->top];
        s -> top--;
    }
    return outcome;
}

/***************************************************
*函数名称：Stack_Clear(StackPtr s)
*描   述：
*        清除栈
*参   数:
*        StackPtr s 传入被清空的栈
*返回值：
*        无
****************************************************/
void Stack_Clear(StackPtr s)
{
    if(s)
    {
        s -> top = -1;
    }
}

/***************************************************
*函数名称：Stack_Empty(StackPtr s)
*描   述：
*        判断栈是否为空
*参   数:
*        StackPtr s 传入栈
*返回值：
*        1   空栈
*        0   不为空
****************************************************/
bool Stack_Empty(StackPtr s)
{
    return (s -> top == -1);
}

/***************************************************
*函数名称：Stack_Top(StackPtr s,StackElemType *elem)
*描   述：
*        取栈顶元素赋值给*elem
*参   数:
*        StackPtr s 传入栈
*        StackElemType *elem   栈顶元素赋值给*elem
*返回值：
*        success  成功
*        fail     失败
****************************************************/
Status Stack_Top(StackPtr s,StackElemType *elem)
{
    Status outcome = fail;
    if(s -> top == -1)
    {
        return outcome;
    }
    else
    {
        *elem = s->date[s->top];
        outcome = success;
    }
    return outcome;
}

/***************************************************
*函数名称：Stack_Print(StackPtr s)
*描   述：
*        打印整个栈
*参   数:
*        StackPtr s 传入栈
*返回值：
*        无
****************************************************/
void Stack_Print(StackPtr s)
{
    static int i = 0 ;
    if(s)
    {
        for(i = 0; i <= (s -> top); i++)
        {
            printf("%d", s -> date[i]);
        }
        printf("\n");
    }
}

int main()
{
    StackPtr s;
    Stack_Init(s);
    Stack_Push(s,1);
    Stack_Push(s,2);
    Stack_Push(s,3);
    Stack_Print(s);

    return 0;
}