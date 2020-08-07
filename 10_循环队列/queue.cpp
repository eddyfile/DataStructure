#include "queue.h"

/****************************************
 * 函数名称：InitQueue(PtrQueue que)
 * 功能描述：初始化一个队列
 * 传入参数：PtrQueue que   待初始化的队列
 * 返回值：_success_   成功
 *        _fail_      失败 
 * 队列：
 *      fort指向对列头部，rear只想最后一个数据的
 *      下一位
 * 队列的模型如下：
 *     frot                      rear
 *       |                        |
 *       v                        v
 *     | a1 | a2 | a3 | a4 | a5 |  |
 *     -----------------------------
 * 下标  0    1    2    3    4   5
***************************************/
Status InitQueue(PtrQueue que)
{
    Status _outcome_ = _fail_;
    int i;
    que -> front = NULL;
    que -> rear = NULL;
    for(i = 0; i< MAX_SIZE; i++)
    {
        que ->data[i] = 0;/*初始化为0*/
    }
    return _outcome_ = _success_;
}

/****************************************
 * 函数名称：InsertQueue(PtrQueue q)
 * 功能描述：队尾插入数据
 * 传入参数：PtrQueue que   传入的队列
 * 返回值：_success_   成功
 *        _fail_      失败 
 *        _full_      队列满
 * 注意：队列满的条件为
 *      (rear+1)%MAX_SIZE == front
 ****************************************/
Status InsertQueue(PtrQueue q,Elemtype e)
{
    Status outcome = _fail_;
    if((q ->rear+1)%MAX_SIZE == q ->front)
    {
        return outcome = _full_;/*满队列*/
    }
    q ->data[q ->rear] = e;
    q ->rear = (q ->rear+1)%MAX_SIZE;/*后移*/
    return outcome = _success_;
}

/****************************************
 * 函数名称：OutQueue(PtrQueue q,Elemtype *e)
 * 功能描述：出队列操作
 * 传入参数：PtrQueue que   传入的队列
 *          ElemType *e    队列出来的数据赋值给*e
 * 返回值：_success_   成功
 *        _fail_      失败 
 *        _empty_      队列满
 ****************************************/
Status OutQueue(PtrQueue q,Elemtype *e)
{
    Status _outcome = _fail_;
    if(q ->front == q ->rear)
    {
        return _outcome = _empty_;/*空队列*/
    }
    *e = q ->data[q ->front];
    q ->front = (q ->front+1)%MAX_SIZE;/*后移*/
    return _outcome = _success_;
}
/*******************************************
 * 函数名称：LengthQueue(PtrQueue que)
 * 功能描述：
 * 传入参数：
 * 返回值：队列的长度
 * 队列长度计算：
 *          (rear-frot+MAX_SIZE)%MAX_SIZE 
 ******************************************/
int LengthQueue(PtrQueue que)
{
    return ((que ->rear) - (que ->front)+MAX_SIZE)%MAX_SIZE;
}
