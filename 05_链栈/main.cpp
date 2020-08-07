#include "stack.h"

int main()
{
    int i;
    int size = 0;
    LinkStack s;
    if(Stack_Init(&s) == success)
    {
        printf("请输入栈的长度：");
        scanf("%d",&size);
        for(i = 0;i <= size-1; i++)
        {
            Stack_Push(&s,&i);
        }
        printf("压栈的元素分别为：");
        Stack_Print(&s);
    }
}