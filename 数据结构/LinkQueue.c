#include<stdio.h>

#define maxsize 1000
typedef int QElemType;
#define ok 1
#define error 0
#define OVERFLOW -2
typedef int Status;

//链式结构队列的定义
typedef struct Qnode{
    QElemType data;
    struct Qnode *next;
}Qnode,*QueuePtr;

typedef struct{
    QueuePtr front,rear;
}LinkQueue;

//在队尾插入元素e
Status EnQueue(LinkQueue *Q,QElemType e){
    QueuePtr s=(QueuePtr)malloc(sizeof(Qnode));//新建结点
    if(!s){
        exit(OVERFLOW);
    }//如果分配内存失败就终止程序
    s->data=e;//数据为e
    s->next=NULL;//指向空
    Q->rear->next=s;//原队尾元素指向新的队尾
    Q->rear=s;//尾指针指向当前队尾结点
    return ok;
}

//删除队首元素
Status DeQueue(LinkQueue *Q,QElemType *e){
    QueuePtr p;
    if(Q->front==Q->rear){
        return error;
    }//判断队列是否为空
    p=Q->front->next;//front指向头结点，front->next就是队首元素
    *e=p->data;//将队首元素赋值给e
    Q->front->next=p->next;//更新队首元素
    if(Q->rear==p){
        Q->rear=Q->front;
    }//如果队列只有一个元素，尾指针也指向头结点
    free(p);//释放结点
    return ok;
}