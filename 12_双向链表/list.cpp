#include "list.h"


/************************************************************
 * 函数名称：InitList(PtrNode list)
 * 功能描述：初始化双向链表
 * 传入参数：PtrList list       待初始化的双向链表
 * 返回值：_fail_    失败
 *         _Success_ 成功
 ************************************************************/
Status InitList(PtrNode list)
{
    Status _outcome_ = _fail_;
    list = (PtrNode)malloc(sizeof(Node));
    if(NULL != list)
    {
        list ->prior = NULL;
        list ->next  = NULL;
        list ->data = 0;
        _outcome_ = _Success_;
    }
    return _outcome_;
}

/************************************************************
 * 函数名称：LengthList(PtrNode list)
 * 功能描述：计算双向链表长度
 * 传入参数：PtrList list       传入的双向链表
 * 返回值：双向链表长度
 ************************************************************/
int LengthList(PtrNode list)
{
    PtrNode p = list;
    int num;
    while(p != NULL)
    {
        p = p->next;
        num++;
    }
    return num;
}

/************************************************************
 * 函数名称：InsertList(PtrNode list, int i, ElemType elem)
 * 功能描述：在双向链表的第i个位置插入elem
 * 传入参数：PtrList list       传入的双向链表
 *           int i              插入的位置
 *           ElemType elem      插入的数据
 * 返回值：_fail_    失败
 *         _Success_ 成功
 ************************************************************/
Status InsertList(PtrNode list, int i, ElemType elem)
{
    Status _outcome_ = _fail_;
    PtrNode Target = NULL,temp = list;
    if(i<1 || i > LengthList(list)+1)
    {
        return _outcome_;
    }
    Target = (PtrNode)malloc(sizeof(Node));
    if(NULL != Target)
    {
        Target ->data = elem;
        Target ->next = NULL;
        Target ->prior = NULL;
    }
    if(1 == i)/*插入第一个节点*/
    {
        Target ->next = list;
        list ->prior = Target;
        list = Target;
    }
    else
    {
        for(int j = 1; j < i-1; j++)/*插入点的前一个结点*/
        {
            list = list ->next;
        }
        list ->next = Target;
        Target ->prior = list;
        list = temp;/*list重新指向头结点*/
        _outcome_ = _Success_;
    }
    return _outcome_;
}

/************************************************************
 * 函数名称：DeleteList(PtrNode list, int i)
 * 功能描述：删除双向链表的第i个位置的数据
 * 传入参数：PtrList list       传入的双向链表
 *           int i              待删除的位置
 * 返回值：_fail_    失败
 *         _Success_ 成功
 ************************************************************/
Status DeleteList(PtrNode list, int i)
{
    Status _outcome_ = _fail_;
    PtrNode p = NULL,temp = NULL;
    if( i > 0 || i < LengthList(list)+1)
    {
        p = list;
        if(i == 1)/*删除第一个结点*/
        {
            list = list ->next;
            list ->prior = NULL;
            free(p);
        }
        else
        {
            for(int j = 1;j < i-1; j++)/*待删除结点*/
            {
                list = list ->next;
            }
            temp = list ->next;
            list ->next = temp ->next;
            list ->next ->prior = list;
            list =p;
            free(temp);
            free(p);
        }
        _outcome_ = _Success_;
        
    }
    return _outcome_;
}
