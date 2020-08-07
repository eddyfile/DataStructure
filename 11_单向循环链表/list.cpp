#include "list.h"

/************************************************************
 * 函数名称：InitList(PtrList list,int size)
 * 功能描述：初始化循环链表
 * 传入参数：PtrList list       待初始化的循环链表
 *           int size          初始化的循环链表长度
 * 返回值：fail    失败
 *         success 成功
 ************************************************************/
Status InitList(PtrList list, int size)
{
    Status _outcome_ = fail;
    int i = 1;
    ElemType elem;
    list = (PtrList)malloc(sizeof(Node));
    PtrList Tail;
    PtrList Temp;
    if(list != NULL)
    {
        list -> data = 0;
        list -> next = list;/*第一个节点不保存数据*/
        Tail = list;
        for(; i< size+1;size++)
        {
            Temp = (PtrList)malloc(sizeof(Node));
            if(Temp == NULL)
            {
                return _outcome_;
            }
            printf("请输入第%d个节点的数据：",i);
            scanf("%d",&elem);

            Temp -> data = elem;
            Temp ->next = list;

            Tail ->next = Temp;
            Tail = Temp;
            _outcome_ = success;
        }
    }
    return _outcome_;
}

/************************************************************
 * 函数名称：InitList(PtrList list,int size)
 * 功能描述：循环链表插入数据
 * 传入参数：PtrList lis       传入的循环链表
 *           int i             插入的位置
 *           ElemType elem     插入的数据
 * 返回值：fail    失败
 *         success 成功
 ************************************************************/
Status InsertList(PtrList list, int i,ElemType elem)
{
    Status _outcome_ = fail;
    PtrList Temp = NULL,Target = NULL;
    if(i == 1)/*循环链表头部插入结点*/
    {
        Temp = (PtrList)malloc(sizeof(Node));
        if(NULL == Temp)
        {
            return _outcome_;
        }
        Temp -> data = elem;
        for( Target = list; Target != list; Target = Target -> next);/*找到最后一个结点*/
        Temp -> next = list;
        Target ->next = Temp;
        list = Temp;/*新插入的结点作为头节点*/
        _outcome_ = success;
    }
    else
    {
        Target = list;
        for(int j = 1; j < (i-1); j++)
        {
            Target = Target -> next;/*找到第i-1个节点*/
        }
        Temp = (PtrList)malloc(sizeof(Node));
        if(Temp == NULL)
        {
            return _outcome_;
        }
        Temp ->next = Target ->next;
        Temp ->data = elem;
        Target -> next = Temp;
        _outcome_ = success;
    }
    return _outcome_;
}

/************************************************************
 * 函数名称：DeleteList(PtrList list, int i)
 * 功能描述：循环链表删除数据
 * 传入参数：PtrList lis       传入的循环链表
 *           int i             删除的位置
 * 返回值：fail    失败
 *         success 成功
 ************************************************************/
Status DeleteList(PtrList list, int i)
{
    Status _outcome_ = fail;
    PtrList Target = NULL,Temp = NULL;
    if(i == 1)
    {
        for(Target = list;Target ->next != list;Target = Target -> next);/*找到尾结点*/
        Target ->next = list ->next;
        Temp = list;
        list = list ->next;
        free(Temp);
        if( NULL != Temp)
        {
            return _outcome_;
        }
        _outcome_ = success;
    }
    else
    {
        Target = list;
        for(int j = 1; j < i-1; j++)
        {
            Target = Target -> next;/*找到第i-1个结点*/
        }
        Temp = Target ->next;
        Target ->next = Temp ->next;
        free(Temp);
        if(NULL != Temp)
        {
            return _outcome_;
        }
        _outcome_ = success;
    }
    return _outcome_;
}

/************************************************************
 * 函数名称：SearchList(PtrList list, ElemType elem)
 * 功能描述：返回节点所在位置
 * 传入参数：PtrList lis       传入的循环链表
 *           ElemType  elem    结点数据        
 * 返回值：结点位置
 *         若返回0表示循环链表中不存在该结点
 ************************************************************/
int SearchList(PtrList list, ElemType elem)
{
    PtrList Target = NULL;
    int num;
    for(Target = list; Target ->data != elem; Target = Target ->next)
    {
        if(Target != list)
        {
            ++num;
        }
        else
        {
            return 0;
        }
        return num;
    }
}

/****************************
 * 函数名称：JudgmentLinkRing_1(PtrList list)
 * 功能描述：判断链表是否有环
 * 传入参数：PtrList list  待判断的链表
 * 返回值： true   有环
 *          false  无环 
 * 方法：比较快慢指针
 ***************************/
bool JudgmentLinkRing_1(PtrList list)
{
    PtrList p1,p2;
    p1 = p2 = list;
    while(p1->next != NULL && p2->next->next != NULL)
    {
        p1 =p1 -> next;
        p2 = p2 -> next ->next;
        if(p1 == p2)
        {
            return true;
        }
    }
    return false;
}

/****************************
 * 函数名称：JudmentLinkRing_2(PtrList list)
 * 功能描述：判断链表是否有环
 * 传入参数：PtrList list  待判断的链表
 * 返回值： true   有环
 *          false  无环 
 * 方法：比较步数
 ***************************/
bool JudmentLinkRing_2(PtrList list)
{
    PtrList p1 = list;
    int num1 = 0,num2 = 0;
    PtrList p2 = list;
    while(p1)
    {
        while(p2)
        {
            if(p1 == p2)
            {
                if(num1 == num2)
                {
                    break;
                }
                else
                {
                    return true;
                }
                
            }
            p2 = p2 -> next;
            num2++;
        }
        p1 = p1 -> next;
        num1++;
    }
    return false;
}



