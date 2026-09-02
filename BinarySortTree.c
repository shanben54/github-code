//二叉排序树
#include<stdio.h>

typedef int Status;
#define TRUE 1
#define FALSE 0


//二叉排序树的结点结构定义
typedef struct BiTNode{
    int data;//结点数据
    struct BiTNode *lchild,*rchild;//左子树和右子树
}BiTNode,*BiTree;

//二叉排序树的查找
//T是当前的二叉树，key是关键字，f是上一个访问的结点(T的双亲)，p用于指向查找到的结点
Status SearchBST(BiTree T,int key,BiTree f,BiTree *p){
    if(!T){//如果查找不成功，p指向上一个访问的结点，并返回FALSE
        *p=f;
        return FALSE;
    }
    else if(key==T->data){//如果查找成功，p指向这个结点，并返回TRUE
        *p=T;
    }
    else if(key<T->data){//如果key值更小
        return SearchBST(T->lchild,key,T,p);//去左子树查找
    }
    else{//如果key值更大
        return SearchBST(T->rchild,key,T,p);//去右子树查找
    }
}