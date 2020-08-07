#include "linkqueue.h"
/*********************************************
 * 函数名称：QueueLinkInit(PtrQueue que_)
 * 功能描述：初始化链队列 que_
 * 输入参数：PtrQueue que_ 传入待初始化的链队列
 * 返回值：_Success_ 成功
 *        _Fail_    失败
 * *******************************************/
Status QueueLinkInit(PtrQueue que_)
{
    Status outcome = _Fail_;
    que_ -> front = (PtrQueueNode)malloc(sizeof(QueueNode));/*申请空间*/
    if(!que_ -> front)
    {
        return outcome;/*空间申请失败*/
    }
    else
    {
        que_ -> front -> next = NULL;
        que_ -> rear = que_ -> front;
        outcome = _Success_;
    }
    return outcome;    
}

/*******************************************
 * 函数名称：DestroyQueue(PtrQueue _que_)
 * 功能描述：销毁链队列 _que_
 * 传入参数：PtrQueue _que_ 待销毁的链队列
 * 返回值：_Fail_    失败
 *         _Success_ 成功
 ******************************************/
Status DestroyQueue(PtrQueue _que_)
{
    Status _outcome_ =_Fail_;
    while (_que_ -> front)
    {
        _que_ -> rear = _que_ -> front -> next;/*链队列为空则头尾指针相等*/
        free(_que_ -> front);
        _que_ -> front = _que_ -> rear;
    }
     return _outcome_ = _Success_;
}

/*******************************************
 * 函数名称：QueueEmpty(PtrQueue _que_)
 * 功能描述：判断链队列 _que_是否为空
 * 传入参数：PtrQueue _que_ 待判断的链队列
 * 返回值：TRUE    非空
 *         FALSE   空
 ******************************************/
bool QueueEmpty(PtrQueue _que_)
{
    if(_que_ -> front == _que_ -> rear)
    {
        return TRUE;/*空队列*/
    }
    else
    {
        return FALSE;
    }
}

/*******************************************
 * 函数名称：QueueLength(PtrQueue _que_)
 * 功能描述：计算链队列_que_长度 
 * 传入参数：PtrQueue _que_ 待测链队列
 * 返回值：count 链队列长度
 ******************************************/
int QueueLength(PtrQueue _que_)
{
    Status _outcome_ = _Fail_;
    int count = 0;
    PtrQueueNode q = _que_ -> front -> next;
    while (q)
    {
        count++;
        q = q -> next;
    }
    return count;
}

/***************************************************
 * 函数名称：GetTopQueue(PtrQueue _que_,int topdata)
 * 功能描述：若链队列不空返回队列顶数据
 * 传入参数：PtrQueue _que_ 待测链队列
 *           topdata        队列顶数据赋值给topdata
 * 返回值：_Success_  成功
 *         _Fail_     失败
 ***************************************************/
Status GetTopQueue(PtrQueue _que_,Elemtype topdata)
{
    Status _outcome_ = _Success_;
    PtrQueueNode q;
    if(_que_ -> front == _que_ -> rear)
    {
        _outcome_ = _Fail_;
    }
    else
    {
        q = _que_ ->front ->next;

        topdata = q -> data;
        _que_ ->front ->next = q ->next;
        if(_que_ ->rear == q)
        {
            _que_ ->rear = _que_ ->front;
        }
        free(q);
    }
    return _outcome_;
}

/*********************************************************
 * 函数名称：InsertQueue(PtrQueue _que_, Elemtype e)
 * 功能描述：在链队列_que_的队尾插入数据e
 * 输入参数：PtrQueue _que_     传入的链队列
 *           Elemtype e         待插入的数据
 * 返回值： _Fail_   失败
 *          _Success 成功 
 ********************************************************/
Status InsertQueue(PtrQueue _que_, Elemtype e)
{
    Status _outcome_ = _Fail_;
    PtrQueueNode s = (PtrQueueNode)malloc(sizeof(QueueNode));
    if(!s)
    {
        _outcome_ = _Fail_;
    }
    else
    {
        s -> data = e;
        s -> next = NULL;
        _que_ -> rear -> next = s;/*添加到队列尾部*/
        _que_ -> rear = s;/*更新队尾指针*/
        _outcome_ = _Success_;
    }
    return _outcome_;
}

/*******************************************************
 * 函数名称：
 * 功能描述：依次打印链队列数据
 * 传入参数：PtrQueue _que_
 * 返回值：_Success_   成功
 *         _Fail_      失败
 ******************************************************/

void PrintQueue(PtrQueue _que_)
{
    PtrQueueNode p;
    p = _que_ ->front;
    while (p)
    {
        printf("%d",p -> data);
        p = p -> next;
    }
    printf("\n");
}








