#include "latin.h"
/**********************************************
 * 函数名称：LatinInit(int n)
 * 功能描述：初始化一个循环链表
 * 传入参数：int n   循环链表的长度
 * 返回值：循环链表的头结点
***********************************************/
Ptrlatin LatinInit(int n)
{
    Ptrlatin list = NULL;/*头结点*/
    Ptrlatin p,q;
    int i;
    p = list;
    for(i = 1; i <= n; i++)
    {
        q = (Ptrlatin)malloc(sizeof(latin));
        q ->data = i;
        if (list == NULL )
        {
            list = q;
        }
        else
        {
            p -> next = q;
        }
        p = q;
    }
    p ->next = list;
    return list;
}

/**********************************************
 * 函数名称：Latin(Ptrlatin list, int n)
 * 功能描述：拉丁方阵问题主要计算过程
 * 传入参数：Ptrlatin list 传入的循环链表
 *           int n          循环链表的长度
 * 返回值：无
***********************************************/
void Latin(Ptrlatin list, int n)
{
    Ptrlatin s = list;
    int i,j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ",s ->data);
            s = s -> next;
        }
        printf("\n");
        s = s ->next;
    }
}
/**********************************************
 * 函数名称：main()
 * 功能描述：主函数
 * 传入参数：无
 * 返回值：0
 * 问题：用循环链表实现拉丁方阵：
 *                      ---------------------
 *                      | 1 | 2 | 3 | 4 | 5 |
 *                      ---------------------
 *                      | 2 | 3 | 4 | 5 | 1 |
 *                      ---------------------
 *                      | 3 | 4 | 5 | 1 | 2 |
 *                      ---------------------
 *                      | 4 | 5 | 1 | 2 | 3 |
 *                      ---------------------
 *                      | 5 | 1 | 2 | 3 | 4 |
 *                      ---------------------
 * 方法：首先建立一个单向循环链表，之后进行双层
 *       循环，内层循环打印，内层循环结束后，外
 *       层循环对链表头指针后移一位
***********************************************/
int main()
{
    Ptrlatin list;
    int n;
    printf("请输入拉丁方阵的大小：");
    scanf("%d",&n);
    list = LatinInit(n);
    Latin(list,n);
    return 0;
}
