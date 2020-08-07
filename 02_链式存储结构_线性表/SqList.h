#ifndef __SQLIST_H_
#define __SQLIST_H_


//定义处理的数据类型
typedef int ElemType;
#define bool int

//定义状态
typedef enum Status
{
    success, fail, fatal, rang_err
}Status;

//定义数据类型的结构
typedef struct Node
{
    ElemType elem;
    struct Node *next;
}Node,*Ptr;

//双重指针
typedef Ptr *SqListPtr;

//定义函数
Status List_Init(SqListPtr L);//初始化线性表
void List_Destory(SqListPtr L);//释放线性表
void List_Clear(SqListPtr L);//清空线性表
bool List_Empty(SqListPtr L);//判断线性表是否为空
int  List_Size(SqListPtr L);//求线性表长度
Status List_Retrival(SqListPtr L, int pos, ElemType *elem);//取第pos个数据赋值给*elem
Status List_Locate(SqListPtr L, ElemType elem, int *pos);//查找elem个元素是第几个
Status List_Insert(SqListPtr L, int pos, ElemType elem);//在线性表得pos位置插入数据elem
Status List_delete(SqListPtr L, int pos);//删除线性表第pos个元素
Status List_Find(SqListPtr L, int pos, Ptr *pAddr);//查找第pos个元素
Status List_Prior(SqListPtr L, int pos, ElemType *elem);//求第pos个元素得直接前驱赋值给*elem
Status List_Next(SqListPtr L, int pos, ElemType *elem);//求第pos个元素得直接后继赋值给*elem
void List_Print(SqListPtr L);

#endif // !__SQLIST_H_