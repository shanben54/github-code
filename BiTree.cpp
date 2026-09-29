//二叉树的cpp复现
#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
using namespace std;

template<typename T>
struct TreeNode{
    T data;//结点数据 
    TreeNode *leftchild;//左孩子
    TreeNode *rightchild;//右孩子
};

template<typename T>
class BiTree{
private:
    TreeNode<T> *root;//根结点，树为空时root=nullptr
    void Create(TreeNode<T>* &t,const string &s,int &pos);//创建二叉树的函数，从某个结点开始建立
    void Destroy(TreeNode<T>* t);//清除二叉树，从某个结点开始清理
    void PreOrder(TreeNode<T>* t)const;//前序遍历函数
    void InOrder(TreeNode<T>* t)const;//中序遍历函数
    void PostOrder(TreeNode<T>* t)const;//后序遍历函数
public:
    BiTree();
    ~BiTree();
    void Create(const string &s);
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
void BiTree<T>::Create(const string &s){
    int pos=0;//游标，记录字符串遍历到哪个值了
    Create(root,s,pos);
}

//前序遍历递归函数
template<typename T>
void BiTree<T>::PreOrder(TreeNode<T>* t)const{
    if(t==nullptr) return ;
    cout<<t->data;
    PreOrder(t->leftchild);
    PreOrder(t->rightchild);
}

//中序遍历递归函数
template<typename T>
void BiTree<T>::InOrder(TreeNode<T>* t)const{
    if(t==nullptr) return ;
    InOrder(t->leftchild);
    cout<<t->data;
    InOrder(t->rightchild);
}

//后序遍历递归函数
template<typename T>
void BiTree<T>::PostOrder(TreeNode<T>* t)const{
    if(t==nullptr) return ;
    PostOrder(t->leftchild);
    PostOrder(t->rightchild);
    cout<<t->data;
}

//建立二叉树的递归函数，字符串为前序遍历
template<typename T>
void BiTree<T>::Create(TreeNode<T>* &t,const string &s,int &pos){
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
    queue<TreeNode<T>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<T>* p=q.front();
        q.pop();
        cout<<p->data;
        if(p->leftchild!=nullptr) q.push(p->leftchild);
        if(p->rightchild!=nullptr) q.push(p->rightchild);
    }
}

//中序遍历的非递归写法啊
template<typename T>
void BiTree<T>::InOrderPlus()const{
    if(root==nullptr) return ;
    stack<TreeNode<T>*> s;
    TreeNode<T>* p=root;
    while(p!=nullptr||!s.empty()){
        while(p!=nullptr){
            s.push(p);
            p=p->leftchild;
        }
        p=s.top();
        s.pop();
        cout<<p->data;
        p=p->rightchild;
    }
}

int main(){
    BiTree<char> t;
    t.Create("ABC###DE##F##");

    cout<<"先序：";
    t.PreOrder();
    cout<<endl;

    cout<<"中序（递归版）：";
    t.InOrder();
    cout<<endl;

    cout<<"中序（非递归版）：";
    t.InOrderPlus();
    cout<<endl;

    cout<<"后序：";
    t.PostOrder();
    cout<<endl;

    system("pause");
    return 0;
}