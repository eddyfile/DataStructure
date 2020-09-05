#include "tree.h"

/**************************************
* �������ƣ�CreatBiTree(BiTTree *T)
* �����������ݹ�ķ�ʽ����һ�ö�����������ǰ������ķ�ʽ��������
* ���������BiTree T		������
* ����ֵ����
***************************************/
void CreatBiTree(BiTree *T)
{
	ElemType c;
	scanf("%c",&c);
	if(' ' == c)
	{
		*T = NULL;
	}
	else
	{
		(*T) = (BiTNode *)malloc(sizeof(BiTNode));
		(*T) ->data = c;
		CreatBiTree(&(*T) -> lchild);
		CreatBiTree(&(*T) -> rchild);
	}
}
/**************************************
* �������ƣ�PreorderTraverse(BiTree T, int level)
* ��������������������
* ���������BiTree T		������
			int level		�������
* ����ֵ����
***************************************/
void PreorderTraverse(BiTree T, int level)
{
	if(T)
	{
#if PREORDER_TRAVERSAL//ǰ�����������
		Visit(T ->data,level);
		PreorderTraverse(T ->lchild, level+1);
		PreorderTraverse(T ->rchild, level+1);
#elif IN_ORDER_TRAVERSAL//�������������
		PreorderTraverse(T ->lchild, level+1);
		Visit(T ->data,level);
		PreorderTraverse(T ->rchild, level+1);
#elif POST_ORDER_TRAVERSAL//�������������
		PreorderTraverse(T ->lchild, level+1);
		PreorderTraverse(T ->rchild, level+1);
		Visit(T ->data,level);
#endif
	}
}

/**************************************
* �������ƣ�Visit(ElemType T,int level)
* �������������ʵ����ݺ�������
* ���������ElemType data	��������
			int level		�������
* ����ֵ����
***************************************/
void Visit(ElemType data,int level)
{
	printf("%c ",data); 
}

/**************************************
* �������ƣ�main()
* ����������������
* �����������
* ����ֵ��0
***************************************/
int main()
{
	int level = 1;
	BiTree T =NULL; 
	CreatBiTree(&T);
	PreorderTraverse(T,level);
	
	return 0;
}
