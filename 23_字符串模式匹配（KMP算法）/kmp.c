#include "kmp.h"

/****************************************
 * 函数名称：KMPIndex(ElemType *s, ElemType *t)
 * 功能描述：KMP匹配算法主体
 * 传入参数：ElemType *s    传入的主串
 *          ElemType *t    传入的模式串
 * 返回值：若匹配完成返回模式串在主串的那个位
 *        置（主串中模式串首所在的下标位置）
 *        若未匹配到则返回-1
*****************************************/
int KMPIndex(ElemType *s, ElemType *t)
{
    int i = 0;
    int j = 0;
    int next[255];

    int sLen = GetStringLen(s);/*获取字符串长度*/
    int tLen = GetStringLen(t);

    GetKMPnext(s,next);/*获取next[]数组*/
    while (i < sLen && j < tLen)
    {
        if(-1 == i || s[i] == s[j])
        {
            i++;
            j++;
        }
        else
        {
            j =next[j];/*找到下一次匹配的j值*/
        }
        
    }
    if(j == tLen)/*匹配完成*/
    {
        return i-j;/*返回相匹配位置第一个字符下标*/
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

/*************************************
 * 函数名称：GetKMPnext(ElemType *p, int next[])
 * 功能描述：求KMP算法的next[]
 * 传入参数：ElemType *p    传入模式字符串
 *          int next[]     KMP算法的next[]
 * 返回值：空
*************************************/
void GetKMPnext(ElemType *p, int next[])
{
    int plen = GetStringLen(p);
    next[0] = 0;
    int i = -1;/*固定next[0] = -1*/
    int j;/*后缀*/
    while (j < plen)
    {
        /*通过寻找最长前缀后缀的方法确定next[]*/

        /*假设现在文本串S匹配到 i 位置，模式串P匹配到 j 位置，如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++，继续匹配下一个字符；
        
        如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]。这就意味着失配时，模式串P相对于文本串S向右移动了j - next [j] 位。
        
        换言之，当匹配失败时，模式串向右移动的位数为：失配字符所在位置 - 失配字符对应的next 值，即移动的实际位数为：j - next[j]，且此值大于等于1。*/
        if(-1 == i || p[i] == p[j])
        {
            ++i;
            ++j;
            next[j] = i;

            /*优化后求解next数组，下面8行替代next[j]=i*/
            /*if(p[j] != p[i])
            {
                next[j] = i;
            }
            else
            {
                next[j] = next[i];
            }*/
            
        }
        else
        {
            i = next[i];
        }
    }
}

/**************************************
 * 函数名称：main()
 * 功能描述：主函数
 * 传入参数：无
 * 返回值：0
 **************************************/
int main()
{
    
}
