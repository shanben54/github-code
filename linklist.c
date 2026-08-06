#include<stdio.h>

#define maxsize 20
typedef int ElemType;
#define ok 1
#define error 0
typedef int Status;
//创建链表结构
typedef struct Node{
    ElemType date;
    struct Node *next;
}Node;
typedef struct Node *LinkList;//结构体指针

//获取链表第i个元素
Status GetElem(LinkList L,int i,ElemType *e){//这里的L是指向头结点的指针
    int j;
    LinkList p;//结点p
    p=L->next;//指向链表第一个结点
    j=1;//计数器
    while(p&&j<i){
        p=p->next;
        ++j;
    }//p不断向后查询，直到第i个元素
    if(!p||j>i){
        return error;
    }//第i个元素不存在就报错
    *e=p->date;//将第i个元素的值赋给e
    return ok;
}

//在第i个位置插入元素e
Status ListInsert(LinkList *L,int i,ElemType e){//这里传入的L是二级指针，指向指向头结点的指针，之所以要传入二级指针是为了可以修改头结点的值
    int j;
    LinkList p,s;
    p=*L;//p指向头结点
    j=1;
    while(p&&j<i){
        p=p->next;
        ++j;
    }//使p指向第i-1个结点
    if(!p||i<j){
        return error;
    }//第i个元素不存在就报错
    s=(LinkList)malloc(sizeof(Node));
    //新建结点，此前定义的s并没有赋值，只是一个野指针，不能调用里面的数据，使用malloc为其开辟一块内存，成为一个真正的结构体指针
    s->date=e;
    s->next=p->next;
    p->next=s;
    return ok;
}