#include<stdio.h>

#define maxsize 1000
typedef int QElemType;
#define ok 1
#define error 0
typedef int Status;

//循环队列的定义
typedef struct{
    QElemType data[maxsize];
    int front;//头指针
    int rear;//尾指针，指向队尾元素的下一位
}SqQueue;

//初始化一个空队列
Status InitQueue(SqQueue *Q){
    Q->front=0;
    Q->rear=0;
    return ok;
}

//获取队列的长度
int QueueLength(SqQueue Q){
    return (Q.rear-Q.front+maxsize)%maxsize;//计算队列的通用公式，取模是为了防止超出长度
}

//判断队列是否为空
Status QueueEmpty(SqQueue Q){
    if(Q.front==Q.rear){
        return ok;
    }else{
        return error;
    }
}


//在队尾插入元素e
Status EnQueue(SqQueue *Q,QElemType e){
    if((Q->rear+1)%maxsize==Q->front){
        return error;
    }//判断队列是否满，如果尾指针的下一位是头指针队列为空，多空一个出来是为了和队列为空时区分，取模防止溢出
    Q->data[Q->rear]=e;//在队尾添加元素
    Q->rear=(Q->rear+1)%maxsize;//尾指针向后移动一位，若到最后就循环到数组头部
    return ok;
}

//删除队头的元素
Status DeQueue(SqQueue *Q,QElemType *e){
    if(Q->front==Q->rear){
        return error;
    }//判断队列是否为空
    *e=Q->data[Q->front];//将队首元素赋值给e
    Q->front=(Q->front+1)%maxsize;//头指针向后移动一位，到最后就循环到数组头部
    return ok;
}