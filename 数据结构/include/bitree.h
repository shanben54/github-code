#ifndef BITREE_H
#define BITREE_H

#include<iostream>
#include<queue>
#include<stack>
#include<utility>
#include<string>

template<typename T>
struct TreeNode{
    T data;//结点数据 
    TreeNode *leftchild;//左孩子
    TreeNode *rightchild;//右孩子
    TreeNode():data(T()),leftchild(nullptr),rightchild(nullptr){}
};

template<typename T>
class BiTree{
private:
    TreeNode<T> *root;//根结点，树为空时root=nullptr
    void Create(TreeNode<T>* &t,const std::string &s,int &pos);//创建二叉树的函数，从某个结点开始建立
    void Destroy(TreeNode<T>* t);//清除二叉树，从某个结点开始清理
    void PreOrder(TreeNode<T>* t)const;//前序遍历函数
    void InOrder(TreeNode<T>* t)const;//中序遍历函数
    void PostOrder(TreeNode<T>* t)const;//后序遍历函数
    TreeNode<T>* Clone(TreeNode<T>* t)const;
public:
    BiTree();
    BiTree(const BiTree &o);
    BiTree& operator=(const BiTree &o);
    ~BiTree();
    void Create(const std::string &s);
    void PreOrder()const;
    void InOrder()const;
    void PostOrder()const;
    void LevelOrder()const;
    void InOrderPlus()const;
};

//构造函数
template<typename T>
BiTree<T>::BiTree(){
    root=nullptr;
}

template<typename T>
TreeNode<T>* BiTree<T>::Clone(TreeNode<T>* t)const{
    if(t==nullptr) return t;
    TreeNode<T>* p= new TreeNode<T>;
    p->data=t->data;
    p->leftchild=Clone(t->leftchild);
    p->rightchild=Clone(t->rightchild);
    return p;
}

template<typename T>
BiTree<T>::BiTree(const BiTree &o){
    root=Clone(o.root);
}

template<typename T>
BiTree<T>& BiTree<T>::operator=(const BiTree &o){
    BiTree tmp(o);
    std::swap(tmp.root,root);
    return *this;
}

//析构函数
template<typename T>
BiTree<T>::~BiTree(){
    Destroy(root);
    root=nullptr;//处理根结点
}

//前序遍历
template<typename T>
void BiTree<T>::PreOrder()const{
    PreOrder(root);
}

//中序遍历
template<typename T>
void BiTree<T>::InOrder()const{
    InOrder(root);
}

//后序遍历
template<typename T>
void BiTree<T>::PostOrder()const{
    PostOrder(root);
}

//建立树，从根结点开始递归调用建立函数
template<typename T>
void BiTree<T>::Create(const std::string &s){
    int pos=0;//游标，记录字符串遍历到哪个值了
    Create(root,s,pos);
}

//前序遍历递归函数
template<typename T>
void BiTree<T>::PreOrder(TreeNode<T>* t)const{
    if(t==nullptr) return ;
    std::cout<<t->data;
    PreOrder(t->leftchild);
    PreOrder(t->rightchild);
}

//中序遍历递归函数
template<typename T>
void BiTree<T>::InOrder(TreeNode<T>* t)const{
    if(t==nullptr) return ;
    InOrder(t->leftchild);
    std::cout<<t->data;
    InOrder(t->rightchild);
}

//后序遍历递归函数
template<typename T>
void BiTree<T>::PostOrder(TreeNode<T>* t)const{
    if(t==nullptr) return ;
    PostOrder(t->leftchild);
    PostOrder(t->rightchild);
    std::cout<<t->data;
}

//建立二叉树的递归函数，字符串为前序遍历
template<typename T>
void BiTree<T>::Create(TreeNode<T>* &t,const std::string &s,int &pos){
    char c=s[pos++];
    if(c=='#') t=nullptr;//空结点
    else{
        t=new TreeNode<T>;//新建结点
        t->data=c;
        Create(t->leftchild,s,pos);
        Create(t->rightchild,s,pos);
    }
}

//清除的递归函数
template<typename T>
void BiTree<T>::Destroy(TreeNode<T>* t){
    if(t==nullptr) return ;
    Destroy(t->leftchild);
    Destroy(t->rightchild);
    delete t;//最后再清理结点，不然清理不了子树
}

template<typename T>
void BiTree<T>::LevelOrder()const{
    if(root==nullptr) return;
    std::queue<TreeNode<T>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<T>* p=q.front();
        q.pop();
        std::cout<<p->data;
        if(p->leftchild!=nullptr) q.push(p->leftchild);
        if(p->rightchild!=nullptr) q.push(p->rightchild);
    }
}

//中序遍历的非递归写法
template<typename T>
void BiTree<T>::InOrderPlus()const{
    if(root==nullptr) return ;
    std::stack<TreeNode<T>*> s;
    TreeNode<T>* p=root;
    while(p!=nullptr||!s.empty()){
        while(p!=nullptr){
            s.push(p);
            p=p->leftchild;
        }
        p=s.top();
        s.pop();
        std::cout<<p->data;
        p=p->rightchild;
    }
}

#endif