#include<stdio.h>

#define maxsize 1000
typedef int QElemType;
#define ok 1
#define error 0
typedef int Status;

//循环队列的定义
typedef struct{
    QElemType data[maxsize];
    int front;
    int rear;
}SqQueue;

//初始化一个空队列
Status InitQueue(SqQueue *Q){
    Q->front=0;
    Q->rear=0;
    return ok;
}

//获取队列的长度
int QueueLength(SqQueue Q){
    return (Q.rear-Q.front+maxsize)%maxsize;
}

//在队尾插入元素e
Status EnQueue(SqQueue *Q,QElemType e){
    if((Q->rear+1)%maxsize==Q->front){
        return error;
    }
    Q->data[Q->rear]=e;
    Q->rear=(Q->rear+1)%maxsize;
    return ok;
}

//删除队头的元素
Status DeQueue(SqQueue *Q,QElemType *e){
    if(Q->front==Q->rear){
        return error;
    }
    *e=Q->data[Q->front];
    Q->front=(Q->front+1)%maxsize;
    return ok;
}