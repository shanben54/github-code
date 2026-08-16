#include<stdio.h>

#define maxsize 1000
typedef char TElemType;
#define ok 1
#define error 0
#define OVERFLOW -2
typedef int Status;
typedef enum{Link,Thread} PointerTag;//枚举集合，Link=0,Thread=1，两个数据是常量，用于判断孩子指针


//线索二叉树的结构
typedef struct BiThrNode{
    TElemType data;//结点数据
    struct BiThrNode *lchild,*rchild;//左右孩子指针
    PointerTag LTag;//若为0，左孩子指针指向左孩子，若为1，指向前驱
    PointerTag RTag;//若为0，右孩子指针指向右孩子，若为1，指向后继
}BiThrNode,*BiThrTree;


//中序遍历进行中序线索化
//先建好了树，然后再遍历线索化
BiThrTree pre;//全局变量，始终指向刚刚访问过的结点

void InThreading(BiThrTree p){
    if(p){
        InThreading(p->lchild);//对左子树线索化
        if(!p->lchild){//如果p的左指针为空
            p->LTag=Thread;//修改集合的值
            p->lchild=pre;//p的左指针指向前驱pre
        }
        if(!p->rchild){//如果pre的右指针为空
            pre->RTag=Thread;//修改集合的值
            pre->rchild=p;//pre的右指针指向后继p
        }
        pre=p;//更新pre指向的结点
        InThreading(p->rchild);//对右子树线索化
    }
}

//中序遍历二叉线索树表示的二叉树
//逻辑也和中序遍历差不多，先遍历左子树，找到最左边的结点，再遍历其后继（上一轮的结点），如果有右子树就遍历右子树，不断循环直到遍历完成
Status InOrderTraverse_Thr(BiThrTree T){//T指向头结点，lchild指向根结点，rchild指向中序遍历最后一个结点
    BiThrTree p;
    p=T->lchild;//p指向根结点
    while(p!=T){//空树，或者直到遍历结束，p==T
        while(p->LTag==Link){//如果左子树存在
            p=p->lchild;//继续向下
        }//因为是中序遍历，找到最左边的结点作为第一个结点
        printf("%c",p->data);//打印结点
        while(p->RTag==Thread&&p->rchild!=T){//如果没有右子树并且后继不是T
            p=p->rchild;//指向后继
            printf("%c",p->data);//打印结点
        }
        p=p->rchild;//指向右子树
    }//循环直到遍历完成
    return ok;
}