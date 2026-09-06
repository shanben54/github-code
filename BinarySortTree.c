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

//二叉排序树的插入
Status InsertBST(BiTree *T,int key){
    BiTree p,s;
    if(!SearchBST(*T,key,NULL,&p)){//如果原本的树里没有这个数据，此时p指向的是最后访问的结点
        s=(BiTree)malloc(sizeof(BiTNode));//新建结点数据
        s->data=key;//添加数据
        s->lchild=s->rchild=NULL;
        if(!p){//如果p不存在说明这棵树是空的
            *T=s;//s成为根结点
        }
        else if(key<p->data){
            p->lchild=s;//插入s为左孩子
        }else{
            p->rchild=s;//插入s为右孩子
        }
        return TRUE;
    }
    else{
        return FALSE;
    }
}

//二叉排序树的删除

//从二叉排序树里删除p结点，并重连左或者右子树
Delete(BiTree *p){
    BiTree q,s;
    if((*p)->rchild=NULL){//右子树为空只要连左子树
        q=*p;
        *p=(*p)->lchild;//p的左子树成为新的p结点
        free(q);
    }else if((*p)->lchild==NULL){//左子树为空只要连右子树
        q=*p;
        *p=(*p)->rchild;
        free(q);
    }else{//左右子树都不为空
        q=*p;
        s=(*p)->lchild;//指向左子树
        while(s->rchild){//一路向右找到最右边的结点，也就是p的前驱
            q=s;
            s=s->rchild;
        }
        (*p)->data=s->data;//用p的前驱结点代替p
        if(q!=*p){
            q->rchild=s->rchild;
        }else{
            q->lchild=s->lchild;
        }
    }
    return TRUE;
}

Status DeleteBST(BiTree *T,int key){
    if(*T){
        return FALSE;
    }
    else{
        if(key==(*T)->data){
            return Delete(T);
        }else if(key<(*T)->data){
            return DeleteBST(&(*T)->lchild,key);
        }else{
            return DeleteBST(&(*T)->rchild,key);
        }
    }
}