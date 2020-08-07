#include "Stack.h"
int main()
{
    int i,j;
    int size1,size2;
    DoubleStack s;
    if(Stack_Init(&s) == success)
    {
        printf("请输入压栈1的数据长度：");
        scanf("%d",&size1);
        printf("请输入压栈2的数据长度：");
        scanf("%d",&size2);
        for(i = 1;i <= size1; i++ )
        {
            Stack_Push(&s, &i, STACK_ONE);
        }
        for(j = STACK_MAX_SIZE; j >= STACK_MAX_SIZE-size2+1;j--)
        {
            Stack_Push(&s,&j,2);
        }
        printf("压入栈的数据分别为：");
        Stack_Print(&s);
        printf("压入数据的长度为：%d\n",Stack_Length(&s));
        printf("清除栈是否成功（0:成功，1：失败）：%d\n",Stack_Clear(&s));
    }
    return 0;
}