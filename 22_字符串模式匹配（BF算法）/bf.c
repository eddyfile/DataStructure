#include "bf.h"

/****************************************
 * 函数名称：BFIndex(ElemType *s, ElemType *t)
 * 功能描述：BF匹配算法主体
 * 传入参数：ElemType *s    传入的主串
 *          ElemType *t    传入的模式串
 * 返回值：若匹配完成返回模式串在主串的那个位
 *        置（主串中模式串首所在的下标位置）
 *        若未匹配到则返回-1
*****************************************/
int BFIndex(ElemType *s, ElemType *t)
{
    int i = 0;/*主串当前位置下标*/
    int j = 0;/*模式串当前位置下标*/
    int slen,tlen;
    slen = GetStringLen(s);
    tlen = GetStringLen(t);
    while (i < slen && j < tlen)
    {
        if(s[i] == t[j])
        {
            i++;/*相等主串和模式串的下标整体后移一位*/
            j++;
        }
        else
        {
            i = i-j+1;/*不相等主串后移，模式串返回串首*/
            j = 0;
        }
    }
    if(j == tlen)
    {
        return i - tlen;
    }
    else
    {
        return -1;
    }
}
/*************************************
 * 函数名称：GetStringLen(char *s)
 * 功能描述：获取字符串长度
 * 传入参数：待获取长度的字符串
 * 返回值：字符串长度
*************************************/
int GetStringLen(char *s)
{
    int len=0;
    while (s[len] != 0)
    {
        len++;
    }
    return len;
}
/**************************************
 * 函数名称：main()
 * 功能描述：主函数
 * 传入参数：无
 * 返回值：0
 **************************************/
int main()
{
    ElemType *s = "ssdfre";
    ElemType *t= "dfr";
    printf("字符串t在s中第一次出现的位置是%d",BFIndex(s,t)+1);
    return 0;
}


S
