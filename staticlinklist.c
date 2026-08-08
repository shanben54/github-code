#include<stdio.h>

#define maxsize 100
typedef int ElemType;
#define ok 1
#define error 0
typedef int Status;


typedef struct{
    ElemType data;
    int cur;//后继元素的数组下标
}Component,StaticLinkList[maxsize];

//返回链表的长度
int ListLength(StaticLinkList L){
    int count=0;
    int p=L[maxsize-1].cur;
    while(p!=0){
        count++;
        p=L[p].cur;
    }
    return count;
}


//静态链表的初始化
Status InitList(StaticLinkList space){
    int i;
    for(i=0;i<maxsize-1;i++){
        space[i].cur=i+1;//把链表串起来
    }
    space[maxsize-1].cur=0;//链表为空时，最后一个结点指向0
    return ok;
}

//静态链表的插入
//用于申请新结点的函数
int Malloc_SSL(StaticLinkList space){
    int i=space[0].cur;//space[0]指向备用链表（空闲空间）的第一位
    if(space[i].cur){
        space[0].cur=space[i].cur;//space[i]被征用了，不再是空闲，space[0]指向space[i]的下一位
    }
    return i;//返回申请的数组下标
}

//在第i个位置插入元素e
Status ListInsert(StaticLinkList L,int i,ElemType e){
    int j,k,l;
    k=maxsize-1;//k是最后一个元素的下标，L[k]指向链表第一个元素
    if(i<1||i>ListLength(L)+1){
        return error;
    }//如果i不合规就报错
    j=Malloc_SSL(L);//申请新的结点
    if(j){//如果新结点是存在的
        L[j].data=e;
        for(l=1;l<=i-1;l++){
            k=L[k].cur;
        }//找到第i-1个元素
        L[j].cur=L[k].cur;
        L[k].cur=j;//把这个结点链接到链表中
        return ok;
    }
    return error;
}


//静态链表的删除
//用于释放结点的函数
void Free_SSL(StaticLinkList space,int k){
    space[k].cur=space[0].cur;
    space[0].cur=k;//这个结点成为空闲空间的第一位
}

//删除第i个元素
Status ListDelete(StaticLinkList L,int i){
    int j,k;
    if(i<1||i>ListLength(L)){
        return error;
    }//i不合规就报错
    k=maxsize-1;
    for(j=1;j<=i-1;j++){
        k=L[k].cur;
    }//找到第i-1个元素
    j=L[k].cur;//第i个元素
    L[k].cur=L[j].cur;//将第i个元素从链表中分离出去
    Free_SSL(L,j);//释放这个结点
    return ok;
}
