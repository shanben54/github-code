//二叉排序树的cpp复现
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

template<typename T>
class BST{
private:
    struct Node{
        T val;
        Node* left;
        Node* right;
        Node(T v):val(v),left(nullptr),right(nullptr){}
    };
    Node* root;

    bool Search(Node* t,const T &key)const;
    bool Insert(Node* &t,const T &key);
    void InOrder(Node* t)const;
    void Destroy(Node *t);
    bool Erase(Node* &t,const T &key);
    void EraseNode(Node* &t);
    void EraseMax(Node* &r);
public:
    BST(){root=nullptr;}
    ~BST(){Destroy(root);}
    bool Search(const T &key)const;
    bool Insert(const T &key);
    void InOrder()const;
    bool Erase(const T &key);
};

//查找函数的辅助递归
template<typename T>
bool BST<T>::Search(Node *t,const T &key)const{
    if(t==nullptr) return false;
    if(t->val==key){
        return true;
    }else if(t->val>key){//大了就去左子树
        return Search(t->left,key);
    }else{//小了就去右子树
        return Search(t->right,key);
    }
}

//查找函数
template<typename T>
bool BST<T>::Search(const T &key)const{
    return Search(root,key);
}

//插入函数的辅助递归
template<typename T>
bool BST<T>::Insert(Node* &t,const T &key){
    //找到空的位置就新建结点
    if(t==nullptr){
        t=new Node(key);
        return true;
    }
    if(t->val>key){
        return Insert(t->left,key);
    }else if(t->val<key){
        return Insert(t->right,key);
    }else{
        return false;
    }
}

//插入函数
template<typename T>
bool BST<T>::Insert(const T &key){
    return Insert(root,key);
}

//中序遍历的递归函数
template<typename T>
void BST<T>::InOrder(Node* t)const{
    if(t==nullptr) return;
    InOrder(t->left);
    cout<<t->val<<" ";
    InOrder(t->right);
}

//中序遍历函数
template<typename T>
void BST<T>::InOrder()const{
    InOrder(root);
}

//清空树的函数
template<typename T>
void BST<T>::Destroy(Node* t){
    if(t==nullptr) return;
    Destroy(t->left);
    Destroy(t->right);
    delete t;
}

//删除结点的函数，这里是查找要删除的结点，和查找函数差不多
template<typename T>
bool BST<T>::Erase(Node* &t,const T &key){
    if(t==nullptr) return false;
    if(t->val==key){
        EraseNode(t);//找到了就删除结点
        return true;
    }else if(t->val>key){
        return Erase(t->left,key);
    }else{
        return Erase(t->right,key);
    }
}

//真正用于删除结点的函数
template<typename T>
void BST<T>::EraseNode(Node* &t){
    if(t->left&&t->right){//两颗子树都非空，先找到中序遍历的前驱，用这个值取代当前结点的值，再对前驱结点进行删除
        Node* p=t->left;
        while(p->right){
            p=p->right;
        }
        t->val=p->val;
        EraseMax(t->left);//不能直接把p传进来，这样虽然删除了结点，但是子树接在p身上了，子树就从BST上断出去了
    }else{//只有一颗或者没有子树，直接把子树接上替代自己
        Node* s=t;
        t=t->left?t->left:t->right;
        delete s;
    }
}

//递归删除前驱结点
//因为引用不能改变，所以只能用递归的方式来不断往下找到前驱结点，最后来执行删除
template<typename T>
void BST<T>::EraseMax(Node* &r){
    if(r->right) EraseMax(r->right);
    else{
        Node* p=r;
        r=r->left?r->left:r->right;
        delete p;
    }
}

//调用删除函数
template<typename T>
bool BST<T>::Erase(const T &key){
    return Erase(root,key);
}

int main(){
    BST<int> t;
    int a[] = {5,3,8,1,4,7,9,2,6};
    for (int x : a) t.Insert(x);

    t.InOrder();                                       // 应输出:1 2 3 4 5 6 7 8 9
    cout << "\nsearch 4:  " << t.Search(4)  << endl;   // 1
    cout << "search 10: "   << t.Search(10) << endl;   // 0
    cout << "insert 5:  "   << t.Insert(5)  << endl;   // 0(重复,不插入)
    t.Erase(3);  t.InOrder(); cout<<endl;  // 期望: 1 2 4 5 6 7 8 9   （双子结点）
    t.Erase(5);  t.InOrder(); cout<<endl;  // 期望: 1 2 4 6 7 8 9     （删根）
    t.Erase(1);  t.InOrder();   // 期望: 2 4 6 7 8 9       （叶子）
    system("pause");
    return 0;
}