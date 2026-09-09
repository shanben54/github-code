//平衡二叉树
#include<stdio.h>

typedef int Status;
#define TRUE 1
#define FALSE 0

//树的结点定义
typedef struct BiTNode{
    int data;//结点数据
    int bf;//结点的平衡度
    struct BiTNode *lchild,*rchild;//左右孩子
}BiTNode,*BiTree;

//右旋操作
void R_Rotate(BiTree *P){
    BiTree L;
    L=(*P)->lchild;//指向P的左孩子
    (*P)->lchild=L->rchild;//L的右子树接到P的左边
    L->rchild=(*P);//P结点成为L的右孩子
    *P=L;//L成为新的P结点(根结点)
}

//左旋操作
void L_Rotate(BiTree *P){
    BiTree R;
    R=(*P)->rchild;//指向P的右孩子
    (*P)->rchild=R->lchild;//R的左子树接到P的右边
    R->lchild=(*P);//P结点成为R的左孩子
    *P=R;//R成为新的P结点(根结点)
}

//定义平衡度
#define LH 1//左边高
#define EH 0//两边一样高
#define RH -1//右边高

//以T为根结点的树的左平衡调整，也就是T是最小不平衡树的根结点，T的平衡度大于1，新的结点插入在T的左子树
void LeftBalance(BiTree *T){
    BiTree L,Lr;
    L=(*T)->lchild;//L指向T的左孩子
    switch(L->bf){//检查L的平衡度，来选择怎么旋转
        case LH:{//L和T的平衡度一样。新结点插入在L的左子树里，可以直接右旋
            (*T)->bf=L->bf=EH;//修改L和T的平衡度
            R_Rotate(T);//进行右旋
            break;
        }
        case RH:{//L和T的平衡度不一样，新结点插入在L的右子树里，需要先对L的子树左旋，再对T进行右旋
            Lr=L->rchild;//指向L的右子树
            switch(Lr->bf){//根据L的右子树的平衡度，来调整L和T的平衡度
                //这些看起来很莫名其妙，但是画个图模拟一下就明白这些平衡度为什么要调整成这样了
                case LH:{
                    (*T)->bf=RH;
                    L->bf=EH;
                    break;
                }
                case EH:{
                    (*T)->bf=L->bf=EH;
                    break;
                }
                case RH:{
                    (*T)->bf=EH;
                    L->bf=LH;
                    break;
                }
            }
            Lr->bf=EH;//再调整L的右孩子的平衡度
            L_Rotate(&(*T)->lchild);//对T的左子树进行左旋
            R_Rotate(T);//对T这棵树进行右旋
        }
    }
}

//对以T为根结点的树进行右平衡调整，T是最小不平衡树的根结点，T的平衡度小于-1，新的结点插入在T的右子树里面 
void RightBalance(BiTree *T){
    BiTree R,Rl;
    R=(*T)->rchild;//R指向T的右孩子
    switch(R->bf){//检查R的平衡度，来选择怎么旋转
        case RH:{//R平衡度和T一样，新的结点插入在R的右子树，可以直接左旋
            (*T)->bf=R->bf=EH;//调整R和T的平衡度
            L_Rotate(T);//对T进行左旋
            break;
        }
        case LH:{//R和T的平衡度不一样，新的结点插入在R的左子树，得先对R进行右旋，再对T进行左旋
            Rl=R->lchild;//指向R的左孩子
            switch(Rl->bf){//检查R的左孩子的平衡度，来调整R和T的平衡度
                case RH:{
                    (*T)->bf=LH;
                    R->bf=EH;
                    break;
                }
                case EH:{
                    (*T)->bf=R->bf=EH;
                    break;
                }
                case LH:{
                    (*T)->bf=EH;
                    R->bf=RH;
                    break;
                }
            }
            Rl->bf=EH;//调整R的左孩子的平衡度
            R_Rotate(&(*T)->rchild);//对T的右子树进行右旋
            L_Rotate(T);//对T进行左旋
        }
    }
}

Status InsertAVL(BiTree *T,int e,Status *taller){
    if(!*T){
        *T=(BiTree)malloc(sizeof(BiTNode));
        (*T)->data=e;
        (*T)->lchild=(*T)->rchild=NULL;
        (*T)->bf=EH;
        *taller=TRUE;
    }else{
        if(e==(*T)->data){
            *taller=FALSE;
            return FALSE;
        }
        if(e<(*T)->data){
            if(!InsertAVL(&(*T)->lchild,e,taller)){
                return FALSE;
            }
            if(*taller){
                switch((*T)->bf){
                    case LH:{
                        LeftBalance(T);
                        *taller=FALSE;
                        break;
                    }
                    case EH:{
                        (*T)->bf=LH;
                        *taller=TRUE;
                        break;
                    }
                    case RH:{
                        (*T)->bf=EH;
                        *taller=FALSE;
                        break;
                    }
                }
            }
        }
        else{
            if(!InsertAVL(&(*T)->rchild,e,taller)){
                return FALSE;
            }
            if(*taller){
                switch((*T)->bf){
                    case LH:{
                        (*T)->bf=EH;
                        *taller=FALSE;
                        break;
                    }
                    case EH:{
                        (*T)->bf=RH;
                        *taller=TRUE;
                        break;
                    }
                    case RH:{
                        RightBalance(T);
                        *taller=FALSE;
                        break;
                    }
                }
            }
        }
    }
    return FALSE;
}