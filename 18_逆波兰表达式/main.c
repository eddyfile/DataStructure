#include "rpn.h"
Status InfixToSuffix(stack *s, ElemType dat);
/*****************************************
 * �������ƣ�main()
 * ����������������
 * �����������
 * ����ֵ��0��
 *****************************************/
int main()
{
    stack s;
    char c;
    double dat,d,e;
    char str[MAXBUFFER]; 
    int i = 0;
    InitStack(&s);

    printf("��������׺���ʽ��������ĸq�������롣\n");
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
        else if('+' == dat||'-' == dat)/*���ȼ���ͣ����ȴ���*/
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
            printf("��������ַ���\n");
            return _error_;
        }
        scanf("%c",&c);
    }
    // while ('q' != c)
    // {
    //     while (c == '.' || isdigit(c))/*�ж��Ƿ��������Լ�С����*/
    //     {
    //         str[i++] = c;
    //         str[i] = '\0';
    //         if(i >= 10)
    //         {
    //             printf("��������ݳ�����Χ\n");
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
    //                 printf("��ĸΪ0������\n");
    //                 return _error_;
    //             }
    //         break;
    //     }
    //     scanf("%c",&c);
    // }
    // PopStack(&s,&d);
    // printf("\n���յĽ��Ϊ��%f",d);

    return 0;
}


