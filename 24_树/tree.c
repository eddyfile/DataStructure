#include "tree.h"

/**************************************
* 函数名称：CreatBiTree(BiTTree *T)
* 功能描述：递归的方式创建一棵二叉树，采用前序遍历的方式进行输入
* 传入参数：BiTree T		传入树
* 返回值：无
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
* 函数名称：PreorderTraverse(BiTree T, int level)
* 功能描述：遍历二叉树
* 传入参数：BiTree T		传入树
			int level		传入层数
* 返回值：无
***************************************/
void PreorderTraverse(BiTree T, int level)
{
	if(T)
	{
#if PREORDER_TRAVERSAL//前序遍历二叉树
		Visit(T ->data,level);
		PreorderTraverse(T ->lchild, level+1);
		PreorderTraverse(T ->rchild, level+1);
#elif IN_ORDER_TRAVERSAL//中序遍历二叉树
		PreorderTraverse(T ->lchild, level+1);
		Visit(T ->data,level);
		PreorderTraverse(T ->rchild, level+1);
#elif POST_ORDER_TRAVERSAL//后序遍历二叉树
		PreorderTraverse(T ->lchild, level+1);
		PreorderTraverse(T ->rchild, level+1);
		Visit(T ->data,level);
#endif
	}
}

/**************************************
* 函数名称：Visit(ElemType T,int level)
* 功能描述：访问到数据后具体操作
* 传入参数：ElemType data	传入数据
			int level		传入层数
* 返回值：无
***************************************/
void Visit(ElemType data,int level)
{
	printf("%c ",data); 
}

/**************************************
* 函数名称：main()
* 功能描述：主函数
* 传入参数：无
* 返回值：0
***************************************/
int main()
{
	int level = 1;
	BiTree T =NULL; 
	CreatBiTree(&T);
	PreorderTraverse(T,level);
	
	return 0;
}
