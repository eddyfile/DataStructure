#include "eightqueen.h"
/**************************************************
 * 函数名称：NotDanger(int row,
 *                    int j,
 *                    int (*chess)[MAX_NUM])
 * 功能描述：判断当前位置是否合法（所在行、列、左右斜线是
 *          否又有其他皇后）
 * 传入参数：int row                 传入行
 *          int j                   传入列
 *          int (*chess)[MAX_NUM]   行首
 * 返回值： 1 合法
 *         0 不合法
 **************************************************/
int NotDanger(int row, int j, int (*chess)[MAX_NUM])
{
    int i,k;
    int flage1 = 0,flage2 = 0,flage3 = 0,flage4 = 0,flage5 = 0;
    for (i = 0; i < MAX_NUM; i++)
    {
        if(*(*(chess+i)+j) != 0)
        {
            flage1 = 1;
            break;
        }
    }
    /*左上方*/
    for(i = row,k = j; i>=0 && k >= 0; i--, k--)
    {
        if(*(*(chess+i)+k) != 0)
        {
            flage2 = 1;
            break;
        } 
    }
    /*右下方*/
    for(i = row,k = j; i<MAX_NUM && k<MAX_NUM ; i++, k++)
    {
        if(*(*(chess+i)+k) != 0)
        {
            flage3 = 1;
            break;
        } 
    }
    /*右上方*/
    for(i = row,k = j; i>=0 && k<MAX_NUM ; i--, k++)
    {
        if(*(*(chess+i)+k) != 0)
        {
            flage4 = 1;
            break;
        } 
    }
    /*左下方*/
    for(i = row,k = j; i<MAX_NUM && k>=0 ; i++, k--)
    {
        if(*(*(chess+i)+k) != 0)
        {
            flage5 = 1;
            break;
        } 
    }
    if(flage1 || flage2 || flage3 || flage4 || flage5)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
/*************************************************
 * 函数名称：EightQueen(int (*chess)[MAX_NUM],
 *                     int row,
 *                     int n)
 * 功能描述：八皇后问题递归解决实现
 * 传入参数：int (*chess)[MAX_NUM] 棋盘行首
 *          int row               行
 *          int n                 列
 * 返回值：void
**************************************************/
void EightQueen(int (*chess)[MAX_NUM],int row, int n)
{
    ElemType chess_2[MAX_NUM][MAX_NUM];
    int i,j;
	for(i=0; i<MAX_NUM; i++)
	{
		for(j =0; j<MAX_NUM; j++)
		{
			chess_2[i][j] = chess[i][j];/*棋盘赋值*/
		}
	} 
    if(MAX_NUM == row)/*结束条件*/
    {
        printf("第%d种摆法：\n",count);
        for(i = 0; i < MAX_NUM; i++)
        {
            for (j = 0; j < MAX_NUM; j++)
            {
                printf("%d ",*(*(chess_2+i)+j));
            }
            printf("\n");
        }
        printf("\n");
        count++;
    }
    else
    {
        for (j = 0; j < n; j++)
        {
            if(NotDanger(row, j, chess_2))
            {
                for (i = 0; i < 8; i++)
                {
                    *(*(chess_2 + row)+i) = 0;
                }
                *(*(chess_2 + row) +j) = 1;/*所在位置合法，则赋值*/
                EightQueen(chess_2,row+1,n);
            }
        }
    }
}
/*****************************************
 * 函数名称：CheckerBoardInit()
 * 功能描述：八皇后问题棋盘始化
 * 传入参数：int (*chess)[MAX_NUM] 棋盘行首
 * 返回值：void
 *****************************************/
void CheckerBoardInit(int (*chess)[MAX_NUM])
{
    //ElemType chess[8][8];
    int i,j;
    for (i = 0; i < MAX_NUM; i++)
    {
        for (j = 0; j < MAX_NUM; j++)
        {
            chess[i][j] = 0;
        }
    }
    
}
/***************************************************
 * 函数名称：main()
 * 功能描述：主函数
 * 传入参数：无
 * 返回值：  无
 * 八皇后：
 * _________________________
 * |__|__|__|__|__|_&|__|__|
 * |__|__|__|_&|__|__|__|__|
 * |__|__|__|__|__|__|_&|__|
 * |_&|__|__|__|__|__|__|__|
 * |__|__|__|__|__|__|__|_&|
 * |__|_&|__|__|__|__|__|__|
 * |__|__|__|__|_&|__|__|__|
 * |__|__|_&|__|__|__|__|__|
****************************************************/
int main()
{
    ElemType chess_1[MAX_NUM][MAX_NUM];
    CheckerBoardInit(chess_1);
    EightQueen(chess_1 ,0 ,MAX_NUM);
    printf("一共有%d种摆放方案\n",count);
    return 0;
}











