#include <stdio.h>
#include <stdlib.h>
#include "TestSqList.h"
/***********************顺序存储结构*****************/
int main()
{
    int opt;
    SqListPtr list;
    ElemType e, *date;
    int pos, size,i;
    Status s;
    while (6 != opt)
    {
        printf("1：测试建立线性表\n");
        printf("2：测试清空线性表\n");
        printf("3：测试求某位置及前驱后继\n");
        printf("4：测试查询某元素的位置\n");
        printf("5：测试线性表长度\n");
        printf("输入其他数则结束测试\n");
        printf("请输入要测试的功能：");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                printf("线性表长度：");
                scanf("%d",&size);
                date = (ElemType *)malloc((size+1)*sizeof(ElemType));
                if(date == NULL)break;
                printf("线性表元素：");
                for(i = 1; i <= size; i++)
                    scanf("%d",&date[i]);
                s = Test_CreateList(list, date, size);
                if(success != s)
                {
                    printf("建立线性表失败\n");
                }
            break;
            case 2:
                printf("线性表长度：");
                scanf("%d",&size);
                date = (ElemType *)malloc((size+1)*sizeof(ElemType));
                if(date == NULL)break;
                printf("线性表元素：\n");
                for(i = 1; i <= size; i++)
                    scanf("%d",&date[i]);
                s = Test_CreateList(list, date, size);
                if(success == s)
                {
                    if(!List_Empty(list))
                    {
                        List_Clear(list);
                        if(List_Empty(list))
                        {
                            printf("清空线性表成功\n");
                        }
                        else
                        {
                            printf("清空线性表失败\n");
                        }
                    }
                    
                }
            break;
            case 3:
                printf("线性表长度：");
                scanf("%d",&size);
               date = (ElemType *)malloc((size+1)*sizeof(ElemType));
                if(date == NULL)break;
                printf("线性表元素：\n");
                for(i = 1; i <= size; i++)
                    scanf("%d",&date[i]);
                s = Test_CreateList(list, date, size);
                if(success == s)
                {
                    printf("请输入待查找位置：");
                    scanf("%d",&pos);
                    s = Test_RetrivalPriorNext(list, pos);
                    if(success == s)
                    {
                        printf("查询线性表直接前驱直接后继成功");
                    }
                }
            break;
            case 4:
                printf("线性表长度：");
                scanf("%d",&size);
                date = (ElemType *)malloc((size+1)*sizeof(ElemType));
                if(date == NULL)break;
                printf("线性表元素：\n");
                for(i = 1; i <= size; i++)
                    scanf("%d",&date[i]);
                s = Test_CreateList(list, date, size);
                if(success == s)
                {
                    printf("请输入元素值：");
                    scanf("%d", &e);
                    Test_Locate(list, e);
                }
            break;
            case 5:
                printf("线性表长度：");
                scanf("%d",&size);
                date = (ElemType *)malloc((size+1)*sizeof(ElemType));
                if(date == NULL)break;
                printf("线性表元素：\n");
                for(i = 1; i <= size; i++)
                    scanf("%d",&date[i]);
                s = Test_CreateList(list, date, size);
                if(success == s)
                {
                    Test_Size(list);
                }
            break;
            default:
                printf("退出程序\n");
            break;
        }
    }
    return 0;
}

//建立线性表
Status Test_CreateList(SqListPtr list, ElemType date[], int n)
{
    Status s = fail;
    int i;
    s = List_Init(list);
    if(success == s)
    {
        for(i = 1; i<= n; ++i)
        {
            s = List_Insert(list,i,date[i]);
            if(s != success)
                break;
        }
        printf("链表元素为：");
        List_Print(list);
    }
    return s;
}
//清除线性表
Status Test_ClearList(SqListPtr list)
{
    Status s = fail;
    if(!List_Empty(list))
    {
        List_Clear(list);
        if(!List_Empty(list))
            s = success;
    }
    return s;
}
//查找pos位置元素得直接前驱直接后继
Status Test_RetrivalPriorNext(SqListPtr list, int pos)
{
    Status s = success;
    ElemType e;
    s = List_Retrival(list,pos,&e);
    if(success == s)
    {
        printf("第%d个元素是：%d\n", pos, e);
        s = List_Prior(list,pos,&e);
        if(success == s)
        {
            printf("第%d个元素得直接前驱元素是：%d\n", pos, e);
        }
        else printf("没有直接前驱\n");
        s = List_Next(list, pos, &e);
        if(success == s)
        {
            printf("第%d个元素得直接后继元素是：%d\n", pos,e );
        }
        else printf("第%d个元素没有直接后继\n",pos);
        
    }
    else
    {
        printf("位置不合法\n");
    }
    
}
//检索元素
Status Test_Locate(SqListPtr list, ElemType e)
{
    Status s;
    int pos;
    s = List_Locate(list, e, &pos);
    if(success == s)
    {
        printf("%d元素得位置是%d\n", e, pos);
    }
    else
    {
        printf("查找失败\n");
    }
    
    return s;
}
//求线性表长度
void Test_Size(SqListPtr list)
{
    int len;
    len = List_Size(list);
    printf("线性表的长度是%d\n",len);
}







