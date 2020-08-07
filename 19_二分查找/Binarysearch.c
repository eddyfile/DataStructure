#include "Binarysearch.h"
/******************************************************
 * 函数名称：BinarySearch(ElemType *array[],ElemType dat)
 * 功能描述：迭代完成二分查找
 * 传入参数：ElemType *array[]      被查找的数组
 *          ElemType dat           待查找的数据
 * 返回值：dat所在位置
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
    printf("查找失败，数据不存在\n");
    return -1;
}
/******************************************************
 * 函数名称：RecursionBinarySearch(ElemType array[], 
 *                                ElemType dat, 
 *                                int head, 
 *                                int high)
 * 功能描述：递归完成二分查找
 * 传入参数：ElemType *array[]      被查找的数组
 *          ElemType dat           待查找的数据
 *          int head               查找区间的首地址
 *          int high               查找区间的尾地址
 * 返回值：dat所在位置
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
 * 函数名称：BinarySearch(ElemType *array[],ElemType dat)
 * 功能描述：迭代完成二分查找
 * 传入参数：ElemType *array[]      被查找的数组
 *          ElemType dat           待查找的数据
 * 返回值：dat所在位置
*******************************************************/
int main()
{
    int location1,location2;
    int sc;
    int end;
    printf("请输入待查找的数据:");
    GET_ARRAY_LEN(bsarry,end);
    scanf("%d",&sc);
    location1 = RecursionBinarySearch(bsarry, sc, 0, end);
    location2 = BinarySearch(bsarry,sc);
    printf("递归:");
    printf("查找的数据%d在第%d位\n",sc,location1);
    printf("迭代:");
    printf("查找的数据%d在第%d位\n",sc,location2);
    return 0;
}





