#include "fibonacci.h"
int main(void)
{
    Fibonacci_1(30);
    //Fib(20);
    return 0;
}

/****************************************
 * 函数名称：
 * 功能描述：迭代实现斐波那契数列
 * 传入参数：int size   数列长度
 * 返回值：无
 ****************************************/
void Fibonacci_1(int size)
{
    int i = 2;
    int a[size];
    a[0] = a[1] = 1;
    printf("%d ",a[0]);
    printf("%d ",a[1]);
    if(i >= 2)
    {
        for(i =2 ;i <= size; i++)
        {
            a[i] = a[i-1]+a[i-2];
            printf("%d ",a[i]); 
            if(i % 10 == 0)
            {
                printf("\n");
            }
        }
    }
}
/*****************************************
 * 函数名称：Fibonacci_2(int size)
 * 功能描述：递归实现斐波那契数列
 * 传入参数：int size    数列长度
 * 返回值：斐波那契数列值
 * 斐波那契数列：1 1 2 3 5 8 13 21
******************************************/
int Fibonacci_2(int size)
{
    if(size < 2)
    {
        return size == 0 ? 0 : 1;
    }
    return Fibonacci_2(size - 1) + Fibonacci_2(size - 2);
}
/********************************************
 * 函数名称：Fib(int size)
 * 功能描述：打印斐波那契数列
 * 传入参数：斐波那契数列长度
 * 返回值：0
 ********************************************/
int Fib(int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%d ",Fibonacci_2(i));
    }
    return 0;
}

/**********************************
 * 函数名称：
 * 功能描述：递归实现任意长度字符串的反向输出
 * 输入参数：无
 * 输出参数：无
 **********************************/
void print()
{
    char a;
    scanf("%c",&a);
    if(a != '#') print();
    if(a != '#') printf("%c",a);
}
