#include "linkqueue.h"


int main()
{
    Status s;
    PtrQueue q;
    printf("开始");
    s = QueueLinkInit(q);
    if(_Success_ == s)
    {
        printf("成功构造一个链队列\n");
    }
    printf("链队列是否为空（0：空，1：非空）？\n：%d",QueueEmpty(q));
    if(_Success_ == InsertQueue(q,5))
    {
        printf("插入数据成功。\n");
    }
    return 0;
}



