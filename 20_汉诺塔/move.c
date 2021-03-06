#include <stdio.h>
#include <stdlib.h>

/******************************************
 * 函数名称：hanoi(int n,char x,char y,char z)
 * 功能描述：汉诺塔问题递归实现
 * 传入参数：int   n      汉诺塔的层数
 *          char  x      地一根柱子
 *          char  y      中间的柱子
 *          char  z      最右边柱子
 * 返回值：无
 * 汉诺塔：汉诺塔：汉诺塔（又称河内塔）问题是源于
 *        印度一个古老传说的益智玩具。大梵天创造
 *        世界的时候做了三根金刚石柱子，在一根柱
 *        子上从下往上按照大小顺序摞着64片黄金圆
 *        盘。大梵天命令婆罗门把圆盘从下面开始按
 *        大小顺序重新摆放在另一根柱子上。并且规
 *        定，在小圆盘上不能放大圆盘，在三根柱子
 *        之间一次只能移动一个圆盘。
 *         -|-          |           |
 *        --|--         |           |
 *       ---|---        |           |
 *     =================================
 ******************************************/
int hanoi(int n,char x,char y,char z)
{
    if(1 == n)
    {
        printf("从%c--->%c\n",x,z);
    }
    else
    {
        hanoi(n-1,x,z,y);
        printf("从%c--->%c\n",x,z);
        hanoi(n-1,y,x,z);
    }
    return 0;
}
/**************************************
 * 函数名称：main()
 * 功能描述：主函数
 * 传入参数：无
 * 返回值：0
 **************************************/
int main()
{
    int n;
    printf("请输入汉诺塔的层数：");
    scanf("%d",&n);
    hanoi(n,'x','y','z');
    return 0;
}
