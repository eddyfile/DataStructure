#include "Binarysearch.h"
/******************************************************
 * �������ƣ�BinarySearch(ElemType *array[],ElemType dat)
 * ����������������ɶ��ֲ���
 * ���������ElemType *array[]      �����ҵ�����
 *          ElemType dat           �����ҵ�����
 * ����ֵ��dat����λ��
*******************************************************/
int BinarySearch(ElemType *array[],ElemType dat)
{
    int head = 0;
    int end;
    int mid;
    GET_ARRAY_LEN(bsarry,end);
    while (head <= end)
    {
        mid = (end-head)/2+head;
        if(dat < bsarry[mid])
        {
            end = mid-1;
        }
        else if(dat > bsarry[mid])
        {
            head = mid+1;
        }
        else
        {
            return mid;
        }
        
    }
    printf("����ʧ�ܣ����ݲ�����\n");
    return -1;
}
/******************************************************
 * �������ƣ�RecursionBinarySearch(ElemType array[], 
 *                                ElemType dat, 
 *                                int head, 
 *                                int high)
 * �����������ݹ���ɶ��ֲ���
 * ���������ElemType *array[]      �����ҵ�����
 *          ElemType dat           �����ҵ�����
 *          int head               ����������׵�ַ
 *          int high               ���������β��ַ
 * ����ֵ��dat����λ��
*******************************************************/
int RecursionBinarySearch(ElemType array[], ElemType dat, int head, int high)
{
    int mid = (high+head)/2;
    if(high<head)
    {
        return -1;
    }
    if(dat > array[mid])
    {
        return RecursionBinarySearch(array,dat,mid+1,high);
    }
    else if(dat < array[mid])
    {
        return RecursionBinarySearch(array,dat,head,mid-1);
    }
    else if(dat == array[mid]) 
		return mid;
}
/******************************************************
 * �������ƣ�BinarySearch(ElemType *array[],ElemType dat)
 * ����������������ɶ��ֲ���
 * ���������ElemType *array[]      �����ҵ�����
 *          ElemType dat           �����ҵ�����
 * ����ֵ��dat����λ��
*******************************************************/
int main()
{
    int location1,location2;
    int sc;
    int end;
    printf("����������ҵ�����:");
    GET_ARRAY_LEN(bsarry,end);
    scanf("%d",&sc);
    location1 = RecursionBinarySearch(bsarry, sc, 0, end);
    location2 = BinarySearch(bsarry,sc);
    printf("�ݹ�:");
    printf("���ҵ�����%d�ڵ�%dλ\n",sc,location1);
    printf("����:");
    printf("���ҵ�����%d�ڵ�%dλ\n",sc,location2);
    return 0;
}





