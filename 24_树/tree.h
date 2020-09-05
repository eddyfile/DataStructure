#ifndef __TREE_H_
#define __TREE_H_
#include <stdio.h>
#include <stdlib.h>


/******************选择哪一种遍历方式输出***************/
#define PREORDER_TRAVERSAL		0		//前序遍历二叉树
#define IN_ORDER_TRAVERSAL		1		//中序遍历二叉树
#define POST_ORDER_TRAVERSAL	0		//后序遍历二叉树

//选择使用哪种表示方法
#define PARENTS 	0					//双亲表示法
#define CHILD		0					//孩子表示法
#define CHILDSIB	0					//孩子兄弟表示法

//待处理数据类型
typedef char ElemType;
//结点结构
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode,* BiTree;



#if PARENTS
//-----------双亲表示法
typedef int ElemType;

/*树的最大长度*/
#define TREE_MAX_SIZE 50

/*树的结点结构*/
typedef struct TNode
{
    ElemType data;/*数据域*/
    int parent;/*指向双亲结点*/
}TNode,* pTNode;

/*树结构*/
typedef struct 
{
    TNode nodes[TREE_MAX_SIZE];
    int r;/*根节点位置*/
    int n;/*结点数*/
}Tree,* pTree;
//------------------------------------
#endif

#if CHILD
//----孩子表示法--------

//待处理数据类型
typedef char ElemType;

//最大存储长度
#define     MAX_TREE_SIZE  50

//孩子结点结构
typedef struct TNode
{
    int child;              //孩子结点下标
    struct TNode *next;     //指向下一个孩子结点的指针
}*PTNode;

//表头结点结构
typedef struct
{
    ElemType data;          //存放的数据
    PTNode firstchild;      //指向第一个孩子节点的指针
}Header;

//树结构
typedef struct
{
    Header nodes[MAX_TREE_SIZE];        //节点数组
    int r,n;//r表示根结点位置，n表示结点个数
}Tree,* PTree;

//-------------------------------
#endif 

#if CHILDSIB
//----孩子兄弟表示法--------

//待处理数据类型
typedef char ElemType;

//最大存储长度
#define     MAX_TREE_SIZE  50

typedef struct SNode
{
    ElemType data;              //存放的数据
    struct SNode * firstchild;  //结点的第一个孩子
    struct SNode * rightsib;    //结点的右兄弟
}SNode,* PSNode;

#endif


void CreatBiTree(BiTree *T);
void PreorderTraverse(BiTree T, int level);
void Visit(ElemType T,int level);


#endif // !__TREE_H_
