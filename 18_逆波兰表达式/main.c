#include "rpn.h"
Status InfixToSuffix(stack *s, ElemType dat);
/*****************************************
 * 函数名称：main()
 * 功能描述：主函数
 * 传入参数：无
 * 返回值：0；
 *****************************************/
int main()
{
    stack s;
    char c;
    double dat,d,e;
    char str[MAXBUFFER]; 
    int i = 0;
    InitStack(&s);

    printf("请输入中缀表达式，输入字母q结束输入。\n");
    scanf("%c",&dat);

    while (dat != 'q')
    {
        if(dat >= '0'&& c <= '9')
        {
            printf("%c",dat);
        }
        else if(')' == dat)
        {
            PopStack(&s,&e);
            while ('(' == e)
            {
                printf("%c",e);
                PopStack(&s,&e);
            }   
        }
        else if('+' == dat||'-' == dat)/*优先级最低，优先处理*/
        {
            if(!LengthStack(&s))
            {
                PushStack(&s,dat);
            }
            else
            {
                do
                {
                    PopStack(&s,&c);
                    if('(' == c)
                    {
                        PushStack(&s,c);
                    }
                    else
                    {
                        printf("%c",c);
                    }
                }while (LengthStack(&s)&&'(' != c);
                PushStack(&s,dat);
            }
        }
        else if ('*' == dat || '/' == dat || '(' == dat)
        {
            PushStack(&s,dat);
        }
        else
        {
            printf("输入错误字符！\n");
            return _error_;
        }
        scanf("%c",&c);
    }
    // while ('q' != c)
    // {
    //     while (c == '.' || isdigit(c))/*判断是否是数字以及小数点*/
    //     {
    //         str[i++] = c;
    //         str[i] = '\0';
    //         if(i >= 10)
    //         {
    //             printf("输入的数据超出范围\n");
    //             return _fail_;
    //         }
    //         scanf("%c",&c);
    //         if(c == ' ')
    //         {
    //             d = atof(str);
    //             PushStack(&s,d);
    //             i = 0;
    //             break;
    //         }
    //     }
    //     switch (c)
    //     {
    //     case '+':
    //             PopStack(&s,&e);
    //             PopStack(&s,&d);
    //             PushStack(&s,d+e);
    //         break;
    //     case '-':
    //             PopStack(&s,&e);
    //             PopStack(&s,&d);
    //             PushStack(&s,d-e);
    //         break;
    //     case '*':
    //             PopStack(&s,&e);
    //             PopStack(&s,&d);
    //             PushStack(&s,d*e);
    //         break;
    //     case '/':
    //             PopStack(&s,&e);
    //             PopStack(&s,&d);
    //             if(0 != e)
    //             {
    //                 PushStack(&s,d/e);
    //             }
    //             else
    //             {
    //                 printf("分母为0，错误\n");
    //                 return _error_;
    //             }
    //         break;
    //     }
    //     scanf("%c",&c);
    // }
    // PopStack(&s,&d);
    // printf("\n最终的结果为：%f",d);

    return 0;
}


