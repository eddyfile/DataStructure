#include <stdio.h>
#include <stdlib.h>
#include "SqList.h"
//初始化线性表
Status List_Init(SqListPtr L)
{
    Status s=fail;
    if(L != NULL)
    {
        L->elem = (ElemType *)malloc((LIST_INIT_SIZE+1)*sizeof(ElemType));
        L->list_size = LIST_INIT_SIZE;
        L->length = 0;
        s = success;
    }
    return s;
}
//销毁线性表
void List_Destory(SqListPtr L)
{
    if(L)
    {
        if(L->elem)
        {
            free(L->elem);
            L->elem = NULL;
            L->length = 0;
        }
    }
}
//清除线性表
void List_Clear(SqListPtr L)
{
    if(L)
    {
        L->length = 0;
    }
}
//判断线性表是否为空
bool List_Empty(SqListPtr L)
{
    return (L->length == 0);
}
int  List_Size(SqListPtr L)
{
    return (L->length);
}
//检索第pos个元素赋值给*elem
Status List_Retrival(SqListPtr L, int pos, ElemType *elem)
{
    Status s = range_err;
    if(L)
    {
        if(pos >=1 && pos <= L->length)
        {
            *elem = L->elem[pos];
            s = success;
        }
    }
    return s;
}
//查找elem个元素是第几个
Status List_Locate(SqListPtr L, ElemType elem, int *pos)
{
    Status s = range_err;
    int i;
    if(L)
    {
        for (i = 1; i <= L->length; ++i)
        {
            if(L->elem[i] == elem)
            {
                *pos = i;
                s = success;
                break;
            }
        }
    }
    return s;
}
/*插入元素思路

1、检查插入位置是否合法，合法则继续，否则退出
2、判断线性表是否已满，满则不能实现插入
3、前面检查通过则数据元素依次从后往前将数据向后移动一位
4、新元素添加到指定位置
5、线性表长度加一

*/
//插入元素
Status List_Insert(SqListPtr L, int pos, ElemType elem)
{
    Status s = range_err;
    int i;
    if(L)
    {
        if(pos >= 1 && pos <=L->length+1)
        {
            if(L->length < L->list_size)
            {
                for(i = L->length; i>=pos; --i)
                    L->elem[i+1] = L->elem[i];
                L->elem[i+1] = elem;
                L->length++;
                s = success;
            }
        }
    }
    return s;
}
/*删除操作思路

1、检查删除位置是否合法。
2、检查通过元素依次向前移动一位。
3、表长减1.

*/
//删除元素
Status List_delete(SqListPtr L, int pos)
{
    Status s = range_err;
    int i;
    if(L)
    {
        if(pos > 1 && pos <= L->length)
        {
            for(i = pos; i<=L->length;++i)
                L->elem[i - 1] = L->elem[i];
            L->length--;
            s = success;
        }
    }
    return s;
}
//求直接前驱
Status List_Prior(SqListPtr L, int pos, ElemType *elem)
{
    Status s = range_err;
    if(L)
    {
        if(pos > 1 && pos <= L->length)
        {
            *elem = L->elem[pos-1];
            s = success;
        }
    }
    return s;
}
//求直接后继
Status List_Next(SqListPtr L, int pos, ElemType *elem)
{
    Status s = range_err;
    if(L)
    {
        if(pos >= 1 && pos < L->length)
        {
            *elem = L->elem[pos + 1];
            s = success;
        }
    }
    return s;
}
//打印线性表
void List_Print(SqListPtr L)
{
    static int i;
    if(L)
    {
        for(i = 1; i <= L->length; i++)
        {
            printf("%d ", L->elem[i]);
            if(L->length <= 10 && i == L->length)
            {
                printf("\n");
            }
            else if(0 == i % 10)
            {
                printf("\n");
            }
        }
    }
}






