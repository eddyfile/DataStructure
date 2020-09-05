#ifndef __TREE_H_
#define __TREE_H_
#include <stdio.h>
#include <stdlib.h>


/******************ѡ����һ�ֱ�����ʽ���***************/
#define PREORDER_TRAVERSAL		0		//ǰ�����������
#define IN_ORDER_TRAVERSAL		1		//�������������
#define POST_ORDER_TRAVERSAL	0		//�������������

//ѡ��ʹ�����ֱ�ʾ����
#define PARENTS 	0					//˫�ױ�ʾ��
#define CHILD		0					//���ӱ�ʾ��
#define CHILDSIB	0					//�����ֵܱ�ʾ��

//��������������
typedef char ElemType;
//���ṹ
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode,* BiTree;



#if PARENTS
//-----------˫�ױ�ʾ��
typedef int ElemType;

/*������󳤶�*/
#define TREE_MAX_SIZE 50

/*���Ľ��ṹ*/
typedef struct TNode
{
    ElemType data;/*������*/
    int parent;/*ָ��˫�׽��*/
}TNode,* pTNode;

/*���ṹ*/
typedef struct 
{
    TNode nodes[TREE_MAX_SIZE];
    int r;/*���ڵ�λ��*/
    int n;/*�����*/
}Tree,* pTree;
//------------------------------------
#endif

#if CHILD
//----���ӱ�ʾ��--------

//��������������
typedef char ElemType;

//���洢����
#define     MAX_TREE_SIZE  50

//���ӽ��ṹ
typedef struct TNode
{
    int child;              //���ӽ���±�
    struct TNode *next;     //ָ����һ�����ӽ���ָ��
}*PTNode;

//��ͷ���ṹ
typedef struct
{
    ElemType data;          //��ŵ�����
    PTNode firstchild;      //ָ���һ�����ӽڵ��ָ��
}Header;

//���ṹ
typedef struct
{
    Header nodes[MAX_TREE_SIZE];        //�ڵ�����
    int r,n;//r��ʾ�����λ�ã�n��ʾ������
}Tree,* PTree;

//-------------------------------
#endif 

#if CHILDSIB
//----�����ֵܱ�ʾ��--------

//��������������
typedef char ElemType;

//���洢����
#define     MAX_TREE_SIZE  50

typedef struct SNode
{
    ElemType data;              //��ŵ�����
    struct SNode * firstchild;  //���ĵ�һ������
    struct SNode * rightsib;    //�������ֵ�
}SNode,* PSNode;

#endif


void CreatBiTree(BiTree *T);
void PreorderTraverse(BiTree T, int level);
void Visit(ElemType T,int level);


#endif // !__TREE_H_
