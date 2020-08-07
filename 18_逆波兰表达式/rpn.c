#include "rpn.h"
/*****************************************
 * �������ƣ�InitStack(stack *s)
 * ������������ʼ��һ��ջ
 * ���������stack *s   ����ʼ����ջ
 * ����ֵ��_fail_   ʧ��
 *        _success_ �ɹ�
 *****************************************/
Status InitStack(stack *s)
{
    Status _outcome_ = _fail_;
    s ->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if(NULL == s ->base)
    {
        return _outcome_;
    }
    s ->top = s ->base = NULL;
    s ->stacksize = STACK_INIT_SIZE;
    return _outcome_ = _success_;
}

/*****************************************
 * �������ƣ�PushStack(stack *s,ElemType dat)
 * ����������ѹջ����
 * ���������stack *s     �����ջ
 *          ElemType dat ѹջ������
 * ����ֵ��_fail_   ʧ��
 *        _success_ �ɹ�
 *****************************************/
Status PushStack(stack *s,ElemType dat)
{
    Status _outcome_ = _fail_;
    if(s ->top == s ->base)
    {
        s ->base = (ElemType *)realloc(s ->base,(s ->stacksize+STACK_INCREMENT)*sizeof(ElemType));
        if(NULL == s ->base)
        {
            return _outcome_;
        }
        s ->top = s ->base +STACK_INCREMENT;
        s ->stacksize = s ->stacksize+STACK_INCREMENT;
    }
    *(s ->top) = dat;
    s ->top++;
    return _outcome_ = _success_;
}
/*****************************************
 * �������ƣ�PopStack(stack *s,ElemType *dat)
 * ������������ջ����
 * ���������stack *s     �����ջ
 *          ElemType *dat ��ջ������
 * ����ֵ��_fail_    ʧ��
 *        _success_ �ɹ�
 *        _empty_   ��ջ
 *****************************************/
Status PopStack(stack *s,ElemType *dat)
{
    Status _outcome_ = _fail_;
    if(s ->top == s ->base)
    {
        return _outcome_ = _empty_;
    }
    *dat = *--(s ->top);
    return _outcome_ = _success_;
}
/*****************************************
 * �������ƣ�LengthStack(stack *s)
 * ��������������ջ�ĳ���
 * ���������stack *s     �����ջ
 * ����ֵ��ջ�ĳ���
 *****************************************/
int LengthStack(stack *s)
{
    return ((s ->top) - (s ->base));
}






