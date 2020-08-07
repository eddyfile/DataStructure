#include "Stack.h"

/**************************************
*函数名称：Stack_Init(PtrDoubleStack s)
*描   述：
*        初始化一个共享空间的栈
*参   数：
*        PtrDoubleStack s 传入需要初始化的栈
*返回值 ：
*        success 成功
*        fail    失败
***************************************/
Status Stack_Init(PtrDoubleStack s)
{
    Status outcome = fail;
    s ->stack_top1 = -1;
    s -> stack_top2 = STACK_MAX_SIZE;
    outcome = success;
    return outcome;
}

/***************************************************
*函数名称：Stack_Push(PtrDoubleStack s,ElemType e,int StackNumber)
*描   述：
*        压栈操作
*参   数:
*        PtrDoubleStack s  传入栈
*        ElemType e        带压入的数据
*        int StackNumber   压入哪个栈
*返回值：
*        fail    失败
*        full    满栈
*        success 成功
*        error   错误
*注  意：
*     top1                      top2
*     --------------  --------------
*     |  |  |  |  |    |  |  |  |  |
*     --------------  --------------
*       0  1  2  3       4  5  6  7  
****************************************************/
Status Stack_Push(PtrDoubleStack s, ElemType *e, int StackNumber)
{
    Status outcome = fail;
    if(s -> stack_top1 + 1 == s -> stack_top2)
    {
        outcome = full;/*栈已满，不能再压入新的数据*/
    }
    else
    {
        if(StackNumber == STACK_ONE)/*压入栈1*/
        {
            s -> date[++s -> stack_top1] = *e;
            outcome = success;
        }
        else if(StackNumber == STACK_TWO)/*压入栈2*/
        {
            s -> date[--s -> stack_top2] = *e;
            outcome = success;
        }
        else
        {
            outcome = error;/*出入的StackNumber错误*/
        }
    }
    return outcome;
}

/**************************************
*函数名称：Stack_Empty(PtrDoubleStack s)
*描   述：
*        判断栈是否为空
*参   数：
*        PtrDoubleStack s 传入的栈
*返回值 ：
*        1    空栈
*        0    非空
***************************************/
bool Stack_Empty(PtrDoubleStack s)
{
    return (s ->stack_top1 == -1 && s ->stack_top2 == STACK_MAX_SIZE);
}

/**************************************
*函数名称：Stack_Pop(PtrDoubleStack s, ElemType *elem, int StackNumber)
*描   述：
*        出栈操作
*参   数：
*        PtrDoubleStack s 传入的栈
*        ElemType *elem   出栈的数据赋值给*elem
*        int StackNumber  确定出栈的栈
*返回值 ：
*        success 成功
*        fail    失败
*        error   错误
*        empty   空栈
***************************************/
Status Stack_Pop(PtrDoubleStack s, ElemType *elem, int StackNumber)
{
    Status outcome = error;
    if(s -> stack_top1 == -1 || s -> stack_top2 == STACK_MAX_SIZE)
    {
        outcome = empty;/*空栈无法继续弹出数据*/
    }
    else 
    {
        if(StackNumber == STACK_ONE)
        {
            *elem = s -> date[s -> stack_top1--];
            outcome = success;
        }
        else if(StackNumber == STACK_TWO)
        {
            *elem = s -> date[s -> stack_top2++];
            outcome = success;
        }
        else
        {
            outcome = error;/*出入的StackNumber错误*/
        }
    }
    return outcome;
}

/**************************************
*函数名称：Stack_Length(PtrDoubleStack s)
*描   述：
*        共享栈的数据个数即栈的长度
*参   数：
*        PtrDoubleStack s 传入的栈
*返回值 ：
*        栈的长度
***************************************/
int Stack_Length(PtrDoubleStack s)
{
    return ((s -> stack_top1+1) + (STACK_MAX_SIZE -  s->stack_top2));
}

/**************************************
*函数名称：Stack_Print(PtrDoubleStack s)
*描   述：
*        按顺序打印栈中的数据
*参   数：
*        PtrDoubleStack s 传入的栈
*返回值 ：
*        无
***************************************/
void Stack_Print(PtrDoubleStack s)
{
    int i = 0;
    if(s)
    {
        while(i <= s->stack_top1)
        {
            printf("%d ", s->date[i++]);
        }
        i = s->stack_top2;
        printf("  ");
        while(i < STACK_MAX_SIZE)
        {
            printf("%d ", s->date[i++]);
        }
        printf("\n");
    }
}

/**************************************
*函数名称：Stack_Clear(PtrDoubleStack s)
*描   述：
*        清空栈
*参   数：
*        PtrDoubleStack s 传入的栈
*返回值 ：
*        fail    失败
*        success 成功
***************************************/
Status Stack_Clear(PtrDoubleStack s)
{
    Status outcome = fail;
    if(s)
    {
        s ->stack_top1 = -1;
        s ->stack_top2 = STACK_MAX_SIZE;
        if(s ->stack_top1 == -1 && s ->stack_top2 == STACK_MAX_SIZE)
        {
            outcome = success;
        }
        else
        {
            outcome = fail;
        }   
    }
    return outcome;
}




