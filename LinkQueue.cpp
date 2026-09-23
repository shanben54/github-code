//链式队列的Cpp复现
#include<iostream>
#include<string>
using namespace std;

typedef int Status;
const int ok=1;
const int error=0;

template<typename T>
struct ListNode{
    T data;
    ListNode* next;
    ListNode():next(nullptr){}//无参构造函数，是为了头结点的创建
    ListNode(T v):data(v),next(nullptr){}//有参构造函数
};

template<typename T>
class LinkQueue{
private:
    int count;//队列长度
    ListNode<T>* front;//头指针，指向头结点，头结点下一个结点是队列第一个结点
    ListNode<T>* rear;//尾指针，指向队列最后一个结点
public:
    LinkQueue();
    ~LinkQueue();
    Status Empty()const;
    Status EnQueue(const T &e);
    Status DeQueue(T &e);
    Status GetFront(T &e)const;
    int GetLength()const;
    void ClearQueue();
};

//构造函数
template<typename T>
LinkQueue<T>::LinkQueue(){
    ListNode<T>* p=new ListNode<T>;//创建头结点
    front=p;
    rear=p;
    count=0;
}

//析构函数
template<typename T>
LinkQueue<T>::~LinkQueue(){
    ClearQueue();
    delete front;//释放头结点
}

//在队尾添加结点
template<typename T>
Status LinkQueue<T>::EnQueue(const T &e){
    ListNode<T>* p=new ListNode<T>(e);//创建结点
    rear->next=p;
    rear=p;
    count++;
    return ok;
}

//取出队首元素
template<typename T>
Status LinkQueue<T>::DeQueue(T &e){
    if(Empty()==ok) return error;
    ListNode<T>* p=front->next;//指向队列第一个结点
    front->next=p->next;
    e=p->data;
    if(rear==p) rear=front;//如果只剩最后一个结点，更新尾指针的位置
    delete p;
    count--;
    return ok;
}

//判断队列是否为空
template<typename T>
Status LinkQueue<T>::Empty()const{
    return front==rear?ok:error;
}


//获取队首元素，不取出
template<typename T>
Status LinkQueue<T>::GetFront(T &e)const{
    if(Empty()==ok) return error;
    ListNode<T>* p=front->next;
    e=p->data;
    return ok;
}

//获取队列长度
template<typename T>
int LinkQueue<T>::GetLength()const{
    return count;
}


//清空队列
template<typename T>
void LinkQueue<T>::ClearQueue(){
    ListNode<T>* p=front->next;//指向队列第一个元素
    while(p!=nullptr){
        ListNode<T>* q;
        q=p;
        p=p->next;
        delete q;
    }
    front->next=nullptr;//头结点指向空，清空队列不会动头结点
    rear=front;
    count=0;//更新计数
}
