#include "link.h"
/*****************************************************
 * ---------------------
 * |5|2|3|4|5|6|7|...|1|  游标
 * ---------------------
 * | |A|B|C|D| | |...| |  数据
 * ---------------------
 * |0|1|2|3|4|5|6|...|999|下标
 * 
 * 说明：用数组作为静态链表，其中第一个游标指向最后一个
 *       没有存数据的下标，最后一个游标指向第一个存数据
 *       的下标整块数组第0个和最后一个不存数据，前一个
 *       元素的游标指向下一个元素的下标。
******************************************************/
/****************************************************
 * 函数名称：静态链表初始化
 * 传入参数：
 *           PtrStackLink space 待初始化的静态链表
 * 返回值：  success 成功
 *           fail    失败
******************************************************/
Status LinkInit(PtrStackLink space)
{
    int i;
    Status outcome = fail;
    space[0] = 
    if(space)
    {
        for(i = 0; i < MAX_SIZE-1; i++)
        {
            space[i].cur = i+1;
        }
        space[MAX_SIZE-1].cur = 1;/*最后一个元素不存数据*/
        outcome = success;
    }
    
    return outcome;
}

/**********************************************************
 * 函数名称：LengthList(PtrStackLink space)
 * 功能描述：获得静态链表的长度
 * 传入参数：PtrStackLink space   待传入的静态链表
 * 返回值    静态链表长度
 **********************************************************/
int LengthList(PtrStackLink space)
{
    int i,j = 0;
    i = space[MAX_SIZE -1].cur;
    while (i)
    {
        i = space[i].cur;
        j++;
    }
    return j;
}

/*****************************************************************
 * 函数名称：Malloc_Sll(PtrStackLink space)
 * 功能描述：获得静态链表最后一个有数据的下一个的下标
 * 输入参数：PtrStackLink space 输入待插入的静态链表
 * 返回值：  静态链表最后一个有数据的下一个的下标
 *****************************************************************/
int Malloc_Sll(PtrStackLink space)
{
    int i = space[0].cur;
    if(space[0].cur)
    {
        space[0].cur = space[i].cur;/*第一个没有数据的游标改为新的最后一个没有数据的下标*/
    }
    return i;/*待插入位置的下标*/
}
/*****************************************************************
 * 函数名称：ListInsert(PtrStackLink space, int i, Elemtype e)
 * 功能描述：在静态链表的第i个位置之前插入元素e
 * 输入参数：PtrStackLink space 输入待插入的静态链表
 *           int i              在第i个元素之前插入
 *           Elemtype e         待插入的数据
 * 返回值：  success            成功
 *           fail               失败 
 *****************************************************************/
Status ListInsert(PtrStackLink space, int i, Elemtype e)
{
    Status _outcome_ = fail;
    int j,k,l;
    k = MAX_SIZE-1;/*最后一个元素*/
    j = Malloc_Sll(space);/*待插入位置下标*/
    if(i < 1 || i > LengthList(L))/*插入位置是否合法以及是否超出范围*/
    {
        space[j].data = e;
        for (l = 1; l <= i-1; l++)
        {
            k = space[k].cur;/*最后一个的游标即第一个元素的下标1*/
        }
        space[j].cur = space[k].cur;
        space[k].cur = j;
        space[0].cur = space[j].cur;/*第一个位置的元素的游标改为插入元素的下标*/
        _outcome_ = success;
    }
    return _outcome_;
}
/*****************************************************************
 * 函数名称：ListDelete(PtrStackLink space, int i)
 * 功能描述：删除静态链表的第i个元素
 * 输入参数：PtrStackLink space 输入的静态链表
 *           int i              删除数据所处位置
 * 返回值：  success            成功
 *           fail               失败 
 *****************************************************************/
Status ListDelete(PtrStackLink space, int i)
{
    Status _outcome_ = success;
    int j,k,l;
    k = MAX_SIZE - 1;/*最后一个元素的下标*/
    if(i < 1 || i > LengthList(space))
    {
        success = fail;
    }
    for(j = 1; j <= i-1;j++)
    {
        k = space[k].cur;/*待删除的元素的下标*/
    }
    j = space[k].cur;
    space[k].cur = space[j].cur;/*删除第i个元素*/

    space[k].cur = space[0].cur;/*回收为备用链表*/
    space[0].cur = k;
}










