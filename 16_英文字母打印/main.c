#include "main.h"
/*未通过*/
int DoubleListInit(PtrDoubleNode list)
{
    PtrDoubleNode s,p;
    int i;
    list = (PtrDoubleNode)malloc(sizeof(DoubleNode));
    if(list == NULL)
    {
        return 1;
    }
    list ->next = list ->prior = NULL;/*头结点*/
    p = list;
    for(i = 0; i < 26; i++)
    {
        s = (PtrDoubleNode)malloc(sizeof(DoubleNode));
        if(s == NULL)
        {
            return 1;
        }
        s -> data = 'A'+i;
        s ->prior = p;
        s ->next = p ->next;
        p ->next = s;

        p = s;
    }
    p -> next = list ->next;
    list -> next ->prior = p;
    // free(p);
    // free(s);
    return 0;
}

PtrDoubleNode Cyclelist(PtrDoubleNode list, int n)
{
    PtrDoubleNode p = list;
    int i;
    if(0 < n)
    {
        for(i = 0; i < n; i++)
        {
            p = p -> next;
        }
    }
    else
    {
        for(i = 0; i > n; i--)
        {
            p = p ->prior;
        }
    }
    return p;
}

/*************************************************
 * 函数名称：
 * 功能描述：
 * 传入参数：
 * 返回值： 
*************************************************/
void Reverseoutput()
{
    char a;
    
    scanf("%c",&a);
    if('#' != a)Reverseoutput();
    if('#' != a)printf("%c",a);
}


int main()
{
    PtrDoubleNode list;
    PtrDoubleNode MoveList;
    int n,i;
	printf("请输入字符：");
    Reverseoutput();
//    if(DoubleListInit(list) == _SUCCESS_)
//    {
//        printf("请输入移动的大小：");
//        scanf("%d",&n);\
//        printf("\n");
//        MoveList = Cyclelist(list,n);
//        for(i = 0; i < 26; i++)
//        {
//            MoveList = MoveList -> next;
//            printf("%c",MoveList ->data);
//        }
//        printf("\n");
//    }
    return 0;
}



