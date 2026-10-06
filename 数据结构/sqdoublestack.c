#include<stdio.h>

#define maxsize 1000
typedef int SElemType;
#define ok 1
#define error 0
typedef int Status;

//两栈共享空间结构
typedef struct{
    SElemType data[maxsize];
    int top1;//栈1的顶点
    int top2;//栈2的顶点
}SqDoubleStack;


//将元素e插入栈顶
Status Push(SqDoubleStack *S,SElemType e,int stackNumber){
    if(S->top1+1==S->top2){
        return error;
    }//如果栈已满就报错
    if(stackNumber==1){
        S->data[++S->top1]=e;//插入栈1，top1增加
    }else if(stackNumber==2){
        S->data[--S->top2]=e;//插入栈2，top2减小
    }
    return ok;
}

//删除栈顶元素
Status Pop(SqDoubleStack *S,SElemType *e,int stackNumber){
    if(stackNumber==1){
        if(S->top1==-1){
            return error;
        }//如果栈1为空就报错
        *e=S->data[S->top1--];//将栈顶元素赋值给e，top1减小
    }else if(stackNumber==2){
        if(S->top2==maxsize){
            return error;
        }//如果栈2为空就报错
        *e=S->data[S->top2++];//将栈顶元素赋值给e，top2增大
    }
    return ok;
}