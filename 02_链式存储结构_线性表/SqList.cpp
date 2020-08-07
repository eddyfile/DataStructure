#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"

/***************************************************
*函数名称：List_Init(SqListPtr L)
*描   述：
*        初始化线性表
*参   数:
*        SqListPtr L 待初始化的线性表
*返回值：
*        success  成功
*        fail 失败
****************************************************/
Status List_Init(SqListPtr L)
{
    Status s = fail;
    Ptr p = NULL;
    if( *L == NULL)//判断是否初始化过
    {
        p = (Ptr)malloc(sizeof(Node));//创建空间
        if(L == NULL) return s;
        ( *L ) = p;
        ( *L ) -> next = NULL;
        s = success;
    }
    return s;
}

/***************************************************
*函数名称：List_Destory(SqListPtr L)
*描   述：
*        释放线性表
*参   数:
*        SqListPtr L 待释放的线性表
*返回值：
*        无
****************************************************/
void List_Destory(SqListPtr L)
{
    Ptr p = NULL;
    if(*L)
    {
        p = (*L) ->next;
        while (p)
        {
            (*L) -> next = p -> next;
            free(p);
            p -> next = (*L) -> next;
        }
        free(*L);
        *L = NULL;
    }
/*
    List_Clear(L);
    if(*L)
    {
        free(*L);
        *L = NULL;
    }    
*/
}

/***************************************************
*函数名称：List_Clear(SqListPtr L)
*描   述：
*        清空线性表
*参   数:
*        SqListPtr L 待清空的线性表
*返回值：
*        无
****************************************************/
void List_Clear(SqListPtr L)
{
    Ptr p = NULL;
    if(*L)
    {
        p = (*L) ->next;
        while (p)
        {
            (*L) -> next = p -> next;
            free(p);
            p -> next = (*L) -> next;
        }
    }
}

/***************************************************
*函数名称：List_Empty(SqListPtr L)
*描   述：
*        判断线性表是否为空
*参   数:
*        SqListPtr L 待判断的线性表
*返回值：
*        1  成功
*        0  失败
****************************************************/
bool List_Empty(SqListPtr L)
{
    return ((*L) -> next == NULL);
}

/***************************************************
*函数名称：List_Size(SqListPtr L)
*描   述：
*        求线性表长度
*参   数:
*        SqListPtr L 待求长度的线性表
*返回值：
*        线性表的长度len
****************************************************/
int  List_Size(SqListPtr L)
{
    int len = 0;
    Ptr p = (*L) -> next;
    while (p)
    {
        len++;
        p = p -> next ;   
    }
    return len;
}

/***************************************************
*函数名称：List_Retrival(SqListPtr L, 
*                       int pos, 
*                       ElemType *elem)
*描   述：
*        取第pos个数据赋值给*elem
*参   数:
*        SqListPtr L    传入的线性表
*        int pos        第pos个元素
*        ElemType *elem 第pos个数据赋值给*elem
*返回值：
*        success  成功
*        rang_err 错误
****************************************************/
Status List_Retrival(SqListPtr L, int pos, ElemType *elem)
{
    Status s = rang_err;
    Ptr p = (*L) -> next;
    int i = 1;
    while (p && i < pos)
    {
        i++;
        p = p -> next;
    }
    if(p && pos == i)
    {
        *elem = p ->elem;
        s = success;
    }
    return s;
}

/***************************************************
*函数名称：List_Locate(SqListPtr L, ElemType elem, int *pos)
*描   述：
*        查找elem数据是第几个
*参   数:
*        SqListPtr L    传入的线性表
*        ElemType *elem 带查找的数据
*        int *pos       查找的数据所在位置
*返回值：
*        success  成功
*        fail     失败
****************************************************/
Status List_Locate(SqListPtr L, ElemType elem, int *pos)
{
    Status s = fail;
    Ptr p = (*L) -> next;
    int i = 1;
    while (p)
    {
        if(p ->elem == elem)
        {
            s = success;
            *pos = i;
            break;
        }
        i++;
        p = p->next;
    }
    return s;
    
}

/***************************************************
*函数名称：List_Insert(SqListPtr L, int pos, ElemType elem)
*描   述：
*        在线性表得pos位置插入数据elem
*参   数:
*        SqListPtr L    传入的线性表
*        int pos        带查找的位置
*        ElemType elem  查找到的数据赋值给elem
*返回值：
*        success  成功
*        fail     失败
****************************************************/
Status List_Insert(SqListPtr L, int pos, ElemType elem)
{
    Status s = fail;
    int i = 1;
    Ptr p = (*L) -> next , q = (*L);
    while(i < pos && p)
    {
        q = p;
        p = p -> next;
        i++;
    }
    if(i == pos)
    {
        p = (Ptr)malloc(sizeof(Node));
        if(p)
        {
            p -> elem = elem;
            p -> next = q -> next;
            q -> next = p;
            s = success;
        }
    }
    return s;
}

/***************************************************
*函数名称：List_delete(SqListPtr L, int pos)
*描   述：
*        删除线性表第pos个元素
*参   数:
*        SqListPtr L    传入的线性表
*        int pos        需要删除的位置
*返回值：
*        success  成功
*        fail     失败
****************************************************/
Status List_delete(SqListPtr L, int pos)
{
    Status s = fail;
    int i = 1;
    Ptr p = (*L) -> next , q = (*L);
    while (i < pos && p)
    {
        q = p;
        p = p -> next;
        i++; 
    }
    if(i == pos && p)
    {
        q -> next = p -> next;
        free(p);
        p = NULL;
        s = success;
    }
    return s;
}

/***************************************************
*函数名称：List_Find(SqListPtr L, int pos, Ptr *pAddr)
*描   述：
*        查找第pos个元素
*参   数:
*        SqListPtr L    传入的线性表
*        int pos        需要查找的位置
*        Ptr *pAddr     查找到的元素的地址
*返回值：
*        success  成功
*        fail     失败
****************************************************/
Status List_Find(SqListPtr L, int pos, Ptr *pAddr)
{
    int i = 1;
    Status s = fail;
    Ptr p = (*L) -> next, q = (*L);
    while (i < pos && p)
    {
        q = p;
        p = p -> next;
        i++;
    }
    if(i == pos && p)
    {
        *pAddr = p;
        s = success;
    }
    return s;
}

/***************************************************
*函数名称：List_Prior(SqListPtr L, int pos, ElemType *elem)
*描   述：
*        求第pos个元素得直接前驱赋值给*elem
*参   数:
*        SqListPtr L    传入的线性表
*        int pos        需要查找的位置
*        ElemType *elem 查找到的数据
*返回值：
*        success  成功
*        fail     失败
****************************************************/
Status List_Prior(SqListPtr L, int pos, ElemType *elem)
{
    Status s = fail;
    Ptr q = NULL;
    s = List_Find(L, pos-1, &q);
    if(success == s)
    {
        *elem = q -> elem;
        s = success;
    }
    return s;
}

/***************************************************
*函数名称：List_Next(SqListPtr L, int pos, ElemType *elem)
*描   述：
*        求第pos个元素得直接后继赋值给*elem
*参   数:
*        SqListPtr L    传入的线性表
*        int pos        需要查找的位置
*        ElemType *elem 查找到的数据
*返回值：
*        success  成功
*        fail     失败
****************************************************/
Status List_Next(SqListPtr L, int pos, ElemType *elem)
{
    Status s = fail;
    Ptr q = NULL;
    s = List_Find(L, pos, &q);
    if(success == s)
    {
        if(q -> next)//直接后继存在
        {
            *elem = q -> next -> elem;
            s = success;
        }
        else
        {
            s = fail;
        }
    }
    return s;
}

/***************************************************
*函数名称：List_Print(SqListPtr L)
*描   述：
*        打印线性表
*参   数:
*        SqListPtr L    传入待打印的线性表
*返回值：
*        无
****************************************************/
void List_Print(SqListPtr L)
{
    Ptr p = (*L) -> next;
    int i = 1;
    while (p)
    {
        printf("%d ", p -> elem);
        p = p -> next;
        if(0==(i++)%10)
        {
            printf("\n");
        }
    } 
}







