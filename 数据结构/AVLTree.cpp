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
        Node(const T &v):val(v),left(nullptr),right(nullptr){}
    };
    Node* root;
    enum{LH=1,EH=0,RH=-1}

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

template<typename T>
void AVL<T>::R_Rotate(Node* &p){
    Node* s=p->left;
    p->left=s->right;
    s->right=p;
    p=s;
}

template<typename T>
void AVL<T>::L_Rotate(Node* &p){
    Node* s=p->right;
    p->right=s->left;
    s->left=p;
    p=s;
}

template<typename T>
void AVL<T>::L_Balance(Node* &t){
    Node* p=t->left;
    switch(p->bf){
        case LH:{
            R_Rotate(t);
            t->bf=EH;
            p->bf=EH;
            break;
        }
        case EH:{
            R_Rotate(t);
            t->bf=LH;
            p->bf=RH;
            break;
        }
        case RH:{
            L_Rotate(p);
            R_Rotate(t);
            t->bf=EH;
            p->bf=EH;
            break;
        }
        default:{
            break;
        }
    }
}

template<typename T>
void AVL<T>::R_Balance(Node* &t){
    Node* p=t->right;
    switch(p->bf){
        case RH:{
            L_Rotate(t);
            t->bf=EH;
            p->bf=EH;
            break;
        }
        case EH:{
            L_Rotate(t);
            t->bf=RH;
            p->bf=LH;
            break;
        }
        case LH:{
            R_Rotate(p);
            L_Rotate(t);
            t->bf=EH;
            p->bf=EH;
            break;
        }
        default:{
            break;
        }
    }
}

template<typename T>
bool AVL<T>::Insert(Node* &t,const T &key,bool &taller){
    if(t==nullptr){
        t=new Node(key);
        taller=true;
        return true;
    }else{
        if(t->val==key){
            return false;
        }else if(t->val>key){
            if(!Insert(t->left,key,taller)){
                return false;
            }else{
                
            }
        }
    }
}