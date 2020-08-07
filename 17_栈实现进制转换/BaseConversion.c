#include "BaseConversion.h"

Status InitStack(stack *stack_)
{
    Status _outcome = _fail_;
    
    stack_ ->base = (ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
    if(NULL == stack_ -> base)
    {
        return _outcome;
    }
    stack_ -> base = stack_ -> top = NULL;
    stack_ ->stacksize = STACK_INIT_SIZE;
}

Status PushStack(stack *stack_,ElemType data)
{
    Status _outcome = _fail_;
    if((stack_ ->top) - (stack_ ->base) >= STACK_INIT_SIZE)/*涓婃孩*/
    {
        stack_ ->base = (ElemType *)realloc(stack_ ->base,(stack_ ->stacksize+STACK_INCREASE_SIZE)*sizeof(ElemType));/*澧炲姞绌洪棿*/
        if(NULL == stack_ -> base)
        {
            return _outcome;
        }
    }
    *(stack_ -> top)= data;
    stack_ ->top++;
    return _outcome = _Success_;
}

Status PopStack(stack *stack_,ElemType data)
{
    Status _outcome = _fail_;
    if(stack_ ->top == stack_ ->base)/*鏍堜腑娌℃湁鏁版嵁*/
    {
        return _outcome = _Underflow;/*涓嬫孩*/
    }
    data = *(stack_ ->top--);
}

int LengthStack(stack *stack_)
{
    return (stack_ ->top) - (stack_ ->base);
}

int main()
{
    ElemType c;
    stack s,s2;
    int i,j,len,sum;
    InitStack(&s);
    printf("璇疯緭鍏ヤ簩杩涘埗鏁帮紝杈撳叆瀛楁瘝q缁撴潫:");
    scanf("%c",&c);
    while (c != 'q')
    {
        PushStack(&s,c);
        scanf("%c",&c);
    }
    getchar();/*鐢变簬涓€鑸�鏄痋n缁撳熬锛岄渶瑕佸皢\n浠庤緭鍏ョ殑鏁版嵁涓�鍓旈櫎*/
    len = LengthStack(&s);
    printf("褰撳墠鏁版嵁鐨勯暱搴︿负锛�%d",len);
    for(i = 0; i< len; i++)
    {
        PopStack(&s,c);
        sum = sum+(c-48)*pow(2,i);
    }
/*2杩涘埗杞�8杩涘埗鏂规硶*/
    for(i =0; i< len; i++)
    {
        for(j =0;j < 3; j++)
        {
            PopStack(&s,c);
            sum = sum +(c-48)*pow(2,j);
        }
        if(s.top == s.base)
        {
            break;
        }
        PushStack(&s2,sum+48);
        sum = 0;
    }
    while(s2.top != s2.base)
    {
        PopStack(&s2,c);
        print("杞�鎹㈠悗鐨�8杩涘埗鏁颁负锛�");
        printf("%c",c);
    }

/*2杩涘埗杞�16杩涘埗鏂规硶*/
    for(i =0; i< len;i++)
    {
        for(j =0; j<4;j++)
        {
            PopStack(&s,c);
            sum = sum+(c-48)*pow(2,j);
        }
        if(s.base == s.top)
        {
            break;
        }
        switch (sum)
        {
        case 10:
                sum = 'A';
            break;
        case 11:
                sum = 'B';
            break;
        case 12:
                sum = 'C';
            break;
        case 13:
                sum = 'D';
            break;
        case 14:
                sum = 'E';
            break;
        case 15:
                sum = 'F';
            break;
        default:
                sum += 48;
            break;
        }
            
        PushStack(&s2,sum);
        sum = 0;
        printf("杞�鎹㈠悗鐨�16杩涘埗鏁颁负锛�0X");
        while (s2.base != s2.top)
        {
            PopStack(&s2,c);
            printf("%c",c);
        }
        printf("H\n");
    }
    printf("杞�鍖栦负鍗佽繘鍒剁殑鏁颁负锛�%d\n",sum);
    return 0;
}
