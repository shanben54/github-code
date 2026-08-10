#include<stdio.h>

#define maxsize 1000
typedef int SElemType;
#define ok 1
#define error 0
typedef int Status;
//栈的顺序储存结构

typedef struct{
    SElemType data[maxsize];
    int top;
}SqStack;


//e元素进栈
Status Push(SqStack *S,SElemType e){
    if(S->top==maxsize-1){
        return error;
    }//如果栈满了就报错
    S->top++;//top的下标增加
    S->data[S->top]=e;//将e存入栈
    return ok;
}

//S栈顶元素出栈
Status Pop(SqStack *S,SElemType *e){
    if(S->top==-1){
        return error;
    }//如果栈是空的就报错
    *e=S->data[S->top];//将栈顶的元素赋值给e
    S->top--;//top的下标减小
    return ok;
}