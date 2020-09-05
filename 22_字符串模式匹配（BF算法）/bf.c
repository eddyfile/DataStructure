#include "bf.h"

/****************************************
 * �������ƣ�BFIndex(ElemType *s, ElemType *t)
 * ����������BFƥ���㷨����
 * ���������ElemType *s    ���������
 *          ElemType *t    �����ģʽ��
 * ����ֵ����ƥ����ɷ���ģʽ�����������Ǹ�λ
 *        �ã�������ģʽ�������ڵ��±�λ�ã�
 *        ��δƥ�䵽�򷵻�-1
*****************************************/
int BFIndex(ElemType *s, ElemType *t)
{
    int i = 0;/*������ǰλ���±�*/
    int j = 0;/*ģʽ����ǰλ���±�*/
    int slen,tlen;
    slen = GetStringLen(s);
    tlen = GetStringLen(t);
    while (i < slen && j < tlen)
    {
        if(s[i] == t[j])
        {
            i++;/*���������ģʽ�����±��������һλ*/
            j++;
        }
        else
        {
            i = i-j+1;/*������������ƣ�ģʽ�����ش���*/
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
 * �������ƣ�GetStringLen(char *s)
 * ������������ȡ�ַ�������
 * �������������ȡ���ȵ��ַ���
 * ����ֵ���ַ�������
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
 * �������ƣ�main()
 * ����������������
 * �����������
 * ����ֵ��0
 **************************************/
int main()
{
    ElemType *s = "ssdfre";
    ElemType *t= "dfr";
    printf("�ַ���t��s�е�һ�γ��ֵ�λ����%d",BFIndex(s,t)+1);
    return 0;
}


S
