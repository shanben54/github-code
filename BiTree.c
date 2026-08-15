#include<stdio.h>

#define maxsize 1000
typedef int TElemType;
#define ok 1
#define error 0
#define OVERFLOW -2
typedef int Status;

//二叉树的链表结构
typedef struct BiTNode{
    TElemType data;//结点储存的数据
    struct BiTNode *lchild,*rchild;//左孩子和右孩子的地址
}BiTNode,*BiTree;

//二叉树的遍历

//前序遍历
void PreOrderTraverse(BiTree T){//传入的T是根结点的地址
    if( T==NULL) return;//如果树空就返回
    printf("%c",T->data);//先打印结点
    PreOrderTraverse(T->lchild);//再遍历左子树
    PreOrderTraverse(T->rchild);//最后遍历右子树
}

//中序遍历
void InOrderTraverse(BiTree T){
    if(T==NULL) return;//树空就返回
    PreOrderTraverse(T->lchild);//先遍历左子树
    printf("%c",T->data);//再打印结点
    PreOrderTraverse(T->rchild);//最后遍历右子树
}

//后序遍历
void PostOrderTraverse(BiTree T){
    if(T==NULL) return;//树空就返回
    PostOrderTraverse(T->lchild);//先遍历左子树
    PostOrderTraverse(T->rchild);//再遍历右子树
    printf("%c",T->data);//最后打印结点
}