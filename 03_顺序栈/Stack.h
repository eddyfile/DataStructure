#ifndef __STACK_H_
#define __STACK_H_

//定义栈处理的数据类型
typedef int StackElemType;

/*定义栈的最大长度*/
#define STACK_MAX_SIZE 100

/*顺序栈的结构*/
typedef struct stack
{
    //栈顶位置当top=-1表示空栈，top=stack_size-1表示栈满
    int top;
    StackElemType date[STACK_MAX_SIZE];
}Stack,*StackPtr;

//定义状态
typedef enum Status
{
    success, fail, overflow, underflow
}Status;


//函数声明
Status Stack_Init(StackPtr s);
Status Stack_Push(StackPtr s,StackElemType elem);
Status Stack_Pop(StackPtr s,StackElemType *elem);
void Stack_Clear(StackPtr s);
bool Stack_Empty(StackPtr s);
Status Stack_Top(StackPtr s,StackElemType *elem);
void Stack_Print(StackPtr s);

#endif // !_STACK_H_