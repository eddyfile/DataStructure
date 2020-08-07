#include "eightqueen.h"
/**************************************************
 * �������ƣ�NotDanger(int row,
 *                    int j,
 *                    int (*chess)[MAX_NUM])
 * �����������жϵ�ǰλ���Ƿ�Ϸ��������С��С�����б����
 *          �����������ʺ�
 * ���������int row                 ������
 *          int j                   ������
 *          int (*chess)[MAX_NUM]   ����
 * ����ֵ�� 1 �Ϸ�
 *         0 ���Ϸ�
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
    /*���Ϸ�*/
    for(i = row,k = j; i>=0 && k >= 0; i--, k--)
    {
        if(*(*(chess+i)+k) != 0)
        {
            flage2 = 1;
            break;
        } 
    }
    /*���·�*/
    for(i = row,k = j; i<MAX_NUM && k<MAX_NUM ; i++, k++)
    {
        if(*(*(chess+i)+k) != 0)
        {
            flage3 = 1;
            break;
        } 
    }
    /*���Ϸ�*/
    for(i = row,k = j; i>=0 && k<MAX_NUM ; i--, k++)
    {
        if(*(*(chess+i)+k) != 0)
        {
            flage4 = 1;
            break;
        } 
    }
    /*���·�*/
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
 * �������ƣ�EightQueen(int (*chess)[MAX_NUM],
 *                     int row,
 *                     int n)
 * �����������˻ʺ�����ݹ���ʵ��
 * ���������int (*chess)[MAX_NUM] ��������
 *          int row               ��
 *          int n                 ��
 * ����ֵ��void
**************************************************/
void EightQueen(int (*chess)[MAX_NUM],int row, int n)
{
    ElemType chess_2[MAX_NUM][MAX_NUM];
    int i,j;
	for(i=0; i<MAX_NUM; i++)
	{
		for(j =0; j<MAX_NUM; j++)
		{
			chess_2[i][j] = chess[i][j];/*���̸�ֵ*/
		}
	} 
    if(MAX_NUM == row)/*��������*/
    {
        printf("��%d�ְڷ���\n",count);
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
                *(*(chess_2 + row) +j) = 1;/*����λ�úϷ�����ֵ*/
                EightQueen(chess_2,row+1,n);
            }
        }
    }
}
/*****************************************
 * �������ƣ�CheckerBoardInit()
 * �����������˻ʺ���������ʼ��
 * ���������int (*chess)[MAX_NUM] ��������
 * ����ֵ��void
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
 * �������ƣ�main()
 * ����������������
 * �����������
 * ����ֵ��  ��
 * �˻ʺ�
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
    printf("һ����%d�ְڷŷ���\n",count);
    return 0;
}











