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
    else{//如果原本有这个数据就不添加
        return FALSE;
    }
}

//二叉排序树的删除

//从二叉排序树里删除p结点，并重连左或者右子树
//删除结点的函数
Delete(BiTree *p){
    BiTree q,s;
    if((*p)->rchild=NULL){//右子树为空只要连左子树，如果是叶子结点也是这样操作
        q=*p;
        *p=(*p)->lchild;//p的左子树成为新的p结点
        free(q);//释放这个结点
    }else if((*p)->lchild==NULL){//左子树为空只要连右子树
        q=*p;
        *p=(*p)->rchild;//p的右子树成为新的p结点
        free(q);//释放结点
    }else{//左右子树都不为空
        q=*p;
        s=(*p)->lchild;//指向左子树
        while(s->rchild){//一路向右找到最右边的结点，也就是p的前驱，此时s是p的前驱，q是s的双亲
            q=s;
            s=s->rchild;
        }
        (*p)->data=s->data;//用p的前驱结点数据代替p
        if(q!=*p){//q,p不一样说明p的左孩子有右子树，p的前驱不是他的左孩子，q的右孩子是s
            q->rchild=s->lchild;//用s的左子树代替s
        }else{//p,q相同，说明p的左孩子没有右子树，s指向的是p和q的左孩子
            q->lchild=s->lchild;//用s的左子树代替s
        }
        free(s);
    }
    return TRUE;
}

Status DeleteBST(BiTree *T,int key){
    if(*T){
        return FALSE;//没有找到这个值就返回FALSE
    }
    else{
        if(key==(*T)->data){//找到了这个结点就进行删除
            return Delete(T);
        }else if(key<(*T)->data){//小于当前结点的值就去左子树查找
            return DeleteBST(&(*T)->lchild,key);
        }else{//大于当前结点的值就去右子树查找
            return DeleteBST(&(*T)->rchild,key);
        }
    }
}