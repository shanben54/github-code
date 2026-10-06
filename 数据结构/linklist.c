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

//删除第i个元素
Status ListDelete(LinkList *L,int i,ElemType *e){
    int j;
    LinkList p,q;
    p=*L;//p指向头结点
    j=1;
    while(p->next&&j<i){
        p=p->next;
        ++j;
    }//找到第i个元素，和插入不一样，这里是p->next要存在，插入里面只要i-1存在就可以在最末尾插入，而删除就必须要是i存在
    if(!(p->next)||j>i){
        return error;
    }//第i个元素不存在就报错
    q=p->next;
    p->next=q->next;
    *e=q->date;//将第i个元素的值赋给e
    free(q);//回收这个结点，释放内存，q成为了野指针
    return ok;
}

//单链表的整表创建

//头插法的创建
void CreateListHead(LinkList *L,int n){//传入的L是头指针，不过这时候还没有初始化，L还是野指针
    LinkList p;
    int i;
    srand(time(0));//初始化随机数种子
    *L=(LinkList)malloc(sizeof(Node));//创建头结点
    (*L)->next=NULL;//链表还为空
    for(i=0;i<n;i++){
        p=(LinkList)malloc(sizeof(Node));//创建结点
        p->date=rand()%100+1;//每个结点的数据随机生成，范围是1~100
        p->next=(*L)->next;
        (*L)->next=p;//每个新创建的结点都放在头结点之后
    }//创建n个结点并串在一起成为链表
}

//尾插法的创建
void CreateListTail(LinkList *L,int n){
    LinkList p,r;
    int i;
    srand(time(0));//初始化随机数种子
    *L=(LinkList)malloc(sizeof(Node));//创建头结点
    r=*L;//尾结点
    for(i=0;i<n;i++){
        p=(Node *)malloc(sizeof(Node));
        p->date=rand()%100+1;//结点数据为随机生成
        r->next=p;//新结点直接接到尾结点后面
        r=p;//更新当前尾结点
    }
    r->next=NULL;//尾结点指向NULL
}

//单链表的整表删除
Status ClearList(LinkList *L){
    LinkList p,q;
    p=(*L)->next;//p指向第一个结点
    while(p){
        q=p->next;//记录下一个结点
        free(p);//删除这个结点
        p=q;//指向写下一个结点
    }//遍历所有结点并删除
    (*L)->next=NULL;//头结点指向NULL
    return ok;
}