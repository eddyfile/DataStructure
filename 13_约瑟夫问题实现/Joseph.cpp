#include "Joseph.h"

/***************************************************
 * 函数名称：InitJoseph(int n, int m)
 * 功能描述：初始化约瑟夫循环链表
 * 传入参数：PtrNode jop_list    待初始化的循环链表
 *           int n               一共有n个结点
 * 返回值：_Success_   成功
 *         _Fail       失败
 **************************************************/
Status InitJoseph(PtrNode jop_list,int n)
{
    Status _outcome_ = _Fail;
    int i;
    jop_list = (PtrNode)malloc(sizeof(struct Node));
    PtrNode temp = NULL,Tail = NULL;
    if(jop_list != NULL)
    {
        jop_list ->data = n;/*头结点保存人数*/
        jop_list ->next = NULL;
        Tail = jop_list;
        for(i =1; i <= n; i++)
        {
            temp = (PtrNode)malloc(sizeof(struct Node));
            if(NULL != temp)
            {
                temp -> data = i;
                temp -> next = NULL;
                Tail -> next= temp;
                Tail = temp;
            }
        }
        Tail ->next = jop_list ->next;/*最后一个结点指向头结点的下一个结点，组成环*/
        _outcome_ = _Success_;
    }
    return _outcome_;
}

/***************************************************
 * 函数名称：DeleteJosephNode(int n, int k)
 * 功能描述：删除从n开始之后的第k个结点
 * 传入参数：int n   从第n个结点开始
 *           int k   删除n之后的第k个结点
 * 返回值：_Success_   成功
 *         _Fail       失败
 **************************************************/
Status DeleteJosephNode(PtrNode list, int k)
{
    Status _outcome = _Fail;
    int i;
    PtrNode tem = list;
    PtrNode p = list ->next;
    PtrNode out;
    // while(p != p ->next)
    // {
    //     for(i =1; i< k-1;i++)
    //     {
    //         p = p ->next;
    //     }
    //     printf("%d-->",p ->next ->data);
    //     tem = p ->next;
    //     p ->next = tem ->next;
    //     free(tem);
    //     p =p ->next;
    //     _outcome = _Success_;
    // }
    // printf("%d\n",p ->next);
    while(1)/**/
    {
        for(i = 1; i < k-1; i++)
        {
            tem = tem -> next;
        }
        p = temp -> next;
        out = temp -> next;
        temp -> next = out -> next;
        printf("%d号----->自杀",out -> data);
        free(out);
        _outcome = _Success_;
        if(p ->next ->next = p)
        {
            return _outcome;
        }
    }
    printf("%d--->幸存!\n%d--->幸存!\n",(p -> data), ((p -> next) -> data));
    free(p);
    return _outcome;
}

int main()
{
    PtrNode jos_list;
    InitJoseph(jos_list,41);
    DeleteJosephNode(jos_list,3);
    return 0;
}

