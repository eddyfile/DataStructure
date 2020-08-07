#include "magician.h"

/*******************************************
 * 函数名称：MagicianInit()
 * 功能描述：魔术师发牌问题链表初始化
 * 传入参数：无
 * 返回值： 循环链表头指针
********************************************/
Ptrmagician MagicianInit()
{
    Ptrmagician list = NULL;
    Ptrmagician p,q;
    int i;
    q = list;
    for(i = 1; i<= MAX_CARDS; i++)
    {
        p = (Ptrmagician)malloc(sizeof(magician));
        p -> data = 0;/*初始状态不保存数据*/
        if(list == NULL)
        {
            list = p;/*头结点*/
        }
        else
        {
            q -> next = p;
        }
        q = p;
    }
    q -> next = list;/*首尾相连*/
    return list;
}

/*******************************************
 * 函数名称：Magician(Ptrmagician list)
 * 功能描述：魔术师发牌问题中牌的顺序计算
 * 传入参数：Ptrmagician list   传入的链表
 * 返回值： 无
********************************************/
void Magician(Ptrmagician list)
{
    Ptrmagician s;
    int i;
    int count = 2;/*第一张牌存有数据1，第二张牌在1之后的第二张*/
    s = list;
    s -> data = 1;
    while(1)
    {
        for (i = 0; i < count; i++)
        {
            s = s -> next;
            if(s -> data != 0)
            {
                s -> next;/*这里是指向，而不是赋值*/
                i--;/*当前位置存有数据*/
            }
        }
        if(s -> data == 0)
        {
            s -> data = count;
            count++;
            if(count == MAX_CARDS+1)
            {
                break;/*牌的顺序计算完成*/
            }
        }
    }
}

/**********************************************
 * 函数名称：DestoryList(Ptrmagician list)
 * 功能描述：销毁链表
 * 传入参数：PTRmagician list   待销毁的链表
 * 返回值： 无
***********************************************/
void DestoryList(Ptrmagician list)
{
    Ptrmagician buffer[MAX_CARDS];/*存指针的数组*/
    Ptrmagician s = list;
    int i = 0;
    while (i < MAX_CARDS)
    {
        buffer[i++] = s;
        s = s ->next;
    }
    for ( i = 0; i < MAX_CARDS; i++)
    {
        free(buffer[i]);
    }
    list = NULL;    
}
/*****************************************************************
 * 函数名称：main()
 * 功能描述：主函数
 * 传入参数：无
 * 返回值：0
 * 魔术师发牌问题描述：
 *                  魔术师利用一副普通的扑克牌中的13张黑桃，预先将
 *                  他们排好后叠放在一起，牌面朝下，对观众说：“我不
 *                  看牌，只数数就可以猜到每张牌是什么，我大声数数，
 *                  你们听，不信？现场演示。”
 *                  一开始，魔术师数1，然后把最上面的那张牌翻过来，
 *                  是黑桃A；然后将其放到桌面上；第二次,魔术师数1、
 *                  2；将第一张牌放到手中未翻过的扑克牌的最下面，将
 *                  第二张牌翻转过来，正好是黑桃2；第三次，魔术师数
 *                  1、2、3；将第1、2张牌依次放到手中未翻过的扑克牌
 *                  的最下面，将第三张牌翻过来正好是黑桃3；……直到将
 *                  所有的牌都翻出来为止。问原来牌的顺序是如何的。
******************************************************************/
int main()
{
    Ptrmagician m;
    int i;
    m = MagicianInit();
    Magician(m);
    printf("魔术师发牌问题中牌的顺序如下：\n");
    for(i = 0; i< MAX_CARDS; i++)
    {
        printf("黑桃%d ", m ->data);
        m = m -> next;
    }
    printf("\n");
    DestoryList(m);
    return 0;
}