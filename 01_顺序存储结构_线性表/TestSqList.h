#ifndef __TESTSQLIST_H_
#define __TESTSQLIST_H_
#include "SqList.h"





Status Test_CreateList(SqListPtr list, ElemType date[], int n);//建立线性表
Status Test_ClearList(SqListPtr list);//清除线性表
Status Test_RetrivalPriorNext(SqListPtr list, int pos);//定位线性表并查找前驱后继
Status Test_Locate(SqListPtr list, ElemType e);//查询
void Test_Size(SqListPtr list);//求线性表长度



#endif // !__TESTSQLIST_H_