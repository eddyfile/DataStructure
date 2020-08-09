#include "bf.h"


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
            i++;
            j++;
        }
        else
        {
            i = i-j+1;
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

int GetStringLen(char *s)
{
    int len=0;
    while (s[len] != 0)
    {
        len++;
    }
    
    return len;
}

int main()
{
    ElemType *s = "ssdfre";
    ElemType *t= "dfr";
    printf("字符串t在s中第一次出现的位置是%d",BFIndex(s,t)+1);
    return 0;
}
