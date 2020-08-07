#include "rpn.h"
/*****************************************
 * 函数名称：InitStack(stack *s)
 * 功能描述：初始化一个栈
 * 传入参数：stack *s   待初始化的栈
 * 返回值：_fail_   失败
 *        _success_ 成功
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
 * 函数名称：PushStack(stack *s,ElemType dat)
 * 功能描述：压栈操作
 * 传入参数：stack *s     传入的栈
 *          ElemType dat 压栈的数据
 * 返回值：_fail_   失败
 *        _success_ 成功
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
 * 函数名称：PopStack(stack *s,ElemType *dat)
 * 功能描述：出栈操作
 * 传入参数：stack *s     传入的栈
 *          ElemType *dat 出栈的数据
 * 返回值：_fail_    失败
 *        _success_ 成功
 *        _empty_   空栈
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
 * 函数名称：LengthStack(stack *s)
 * 功能描述：计算栈的长度
 * 传入参数：stack *s     传入的栈
 * 返回值：栈的长度
 *****************************************/
int LengthStack(stack *s)
{
    return ((s ->top) - (s ->base));
}






