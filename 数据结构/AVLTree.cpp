//平衡二叉树的cpp复现
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

template<typename T>
class AVL{
private:
    struct Node{
        T val;
        int bf;
        Node* left;
        Node* right;
        Node(const T &v):val(v),bf(0),left(nullptr),right(nullptr){}
    };
    Node* root;
    enum{LH=1,EH=0,RH=-1};//平衡度的集合

    void R_Rotate(Node* &p);
    void L_Rotate(Node* &p);
    void L_Balance(Node* &t);
    void R_Balance(Node* &t);
    bool Insert(Node* &t,const T &key,bool &taller);
    void InOrder(Node* t)const;
    void Destroy(Node* t);
public:
    AVL(){root=nullptr;}
    ~AVL(){Destroy(root);}
    bool Insert(const T &key);
    void InOrder()const;
};

//右旋操作
template<typename T>
void AVL<T>::R_Rotate(Node* &p){//引用，因为要修改p指针
    Node* s=p->left;
    p->left=s->right;
    s->right=p;
    p=s;
}

//左旋操作
template<typename T>
void AVL<T>::L_Rotate(Node* &p){
    Node* s=p->right;
    p->right=s->left;
    s->left=p;
    p=s;
}

//左平衡调整，t是最早不平衡点，在t的左子树新增了结点，使得t的平衡度超过了1
//如果t的左孩子和自己平衡度一样都是正的，可以直接对t右旋，如果不同，得先对t左孩子进行左旋再对t进行右旋
//此处难点在于进行左旋右旋后对结点平衡度的调整，需要自己画个最简图，自己推演一下
template<typename T>
void AVL<T>::L_Balance(Node* &t){
    Node* &p=t->left;
    switch(p->bf){
        case LH:{
            //因为旋转操作后p和t都指向同一个结点，所以在旋转之前就先调整结点的平衡度
            t->bf=EH;
            p->bf=EH;
            R_Rotate(t);
            break;
        }
        case RH:{
            Node* pr=p->right;//要对p进行左旋，所以也要考虑p的有右孩子的平衡度，这些平衡度调整只能自己画图来推导
            switch(pr->bf){
                case(LH):{
                    pr->bf=EH;
                    t->bf=RH;
                    p->bf=EH;
                    L_Rotate(p);
                    R_Rotate(t);
                    break;
                }
                case(EH):{
                    pr->bf=EH;
                    t->bf=EH;
                    p->bf=EH;
                    L_Rotate(p);
                    R_Rotate(t);
                    break;
                }
                case(RH):{
                    pr->bf=EH;
                    p->bf=LH;
                    t->bf=EH;
                    L_Rotate(p);
                    R_Rotate(t);
                    break;
                }
                default:break;
            }
            break;
        }
        default:{
            break;
        }
    }
}

//右平衡调整，和左平衡调整相似
template<typename T>
void AVL<T>::R_Balance(Node* &t){
    Node* &p=t->right;
    switch(p->bf){
        case RH:{
            t->bf=EH;
            p->bf=EH;
            L_Rotate(t);
            break;
        }
        case LH:{
            Node* pl=p->left;
            switch(pl->bf){
                case RH:{
                    pl->bf=EH;
                    p->bf=EH;
                    t->bf=LH;
                    R_Rotate(p);
                    L_Rotate(t);
                    break;
                }
                case EH:{
                    pl->bf=EH;
                    p->bf=EH;
                    t->bf=EH;
                    R_Rotate(p);
                    L_Rotate(t);
                    break;
                }
                case LH:{
                    pl->bf=EH;
                    t->bf=EH;
                    p->bf=RH;
                    R_Rotate(p);
                    L_Rotate(t);
                    break;
                }
                default:break;
            }
            break;
        }
        default:{
            break;
        }
    }
}

//插入操作的递归函数
//比较要插入的值和当前结点的值，再递归进子树进行查找，如果结点的值和插入的值相同就直接退出，平衡二叉树里没有相同值的结点
//如果结点为空就新建结点，同时传回taller变量，用于判断子树是否长高，再结点当前结点的平衡度进行调整
template<typename T>
bool AVL<T>::Insert(Node* &t,const T &key,bool &taller){
    //新建结点
    if(t==nullptr){
        t=new Node(key);
        taller=true;//只右这里才能修改taller为true
        return true;
    }else{
        if(t->val==key){
            return false;//结点值重复无法插入，直接退出
        }else if(t->val>key){
            if(!Insert(t->left,key,taller)){//结点值大了就去左子树进行插入操作，如果在左子树插入失败了，也返回失败
                return false;
            }
            //如果子树长高了
            if(taller){
                switch (t->bf){//根据当前结点的平衡度来调整
                    case LH:{//本来就左高，现在左子树又长高，所以现在t的平衡度大于1，对t进行左平衡调整
                        L_Balance(t);
                        taller=false;//左平衡调整后子树高度和插入新结点前的高度一样，就没有长高了
                        break;
                    }
                    case EH:{//本来左右平衡，现在左子树长高了
                        t->bf=LH;
                        break;
                    }
                    case RH:{//本来右子树高，现在互相平衡了
                        t->bf=EH;
                        taller=false;
                        break;
                    }
                    default:break;
                }
            }
        }else{//结点值小了就去右子树进行插入，思路和左子树插入相似
            if(!Insert(t->right,key,taller)){
                return false;
            }
            if(taller){
                switch(t->bf){
                    case LH:{
                        t->bf=EH;
                        taller=false;
                        break;
                    }
                    case EH:{
                        t->bf=RH;
                        break;
                    }
                    case RH:{
                        R_Balance(t);
                        taller=false;
                        break;
                    }
                    default:break;
                }
            }
        }
    }
    return true;
}

//插入操作的函数
template<typename T>
bool AVL<T>::Insert(const T &key){
    bool taller=false;
    return Insert(root,key,taller);
}

//清空树的函数
template<typename T>
void AVL<T>::Destroy(Node* t){
    if(t==nullptr) return;
    Destroy(t->left);
    Destroy(t->right);
    delete t;
}

//中序遍历的递归函数
template<typename T>
void AVL<T>::InOrder(Node* t)const{
    if(t==nullptr) return;
    InOrder(t->left);
    cout<<t->val<<" ";
    InOrder(t->right);
}

//中序遍历
template<typename T>
void AVL<T>::InOrder()const{
    InOrder(root);
}

int main(){
    AVL<int> tree;
    int a[]={3,2,1,4,5,6,7,10,9,8};   // 这组数据会同时触发单旋和双旋
    for(int i=0;i<10;++i){
        tree.Insert(a[i]);
    }
    tree.InOrder();                   // 中序输出，验证 BST 有序性
    cout<<endl;
    system("pause");
    return 0;
}