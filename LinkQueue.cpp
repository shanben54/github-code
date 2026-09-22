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
    ListNode():next(nullptr){}
    ListNode(T v):data(v),next(nullptr){}
};

template<typename T>
class LinkQueue{
    int count;
    ListNode<T>* front;
    ListNode<T>* rear;

    LinkQueue();
    ~LinkQueue();
    Status Empty()const;
    Status EnQueue(const T &e);
    Status DeQueue(T &e);
    Status GetFront(T &e)const;
    int GetLength()const;
    void ClearQueue();
};

template<typename T>
LinkQueue<T>::LinkQueue(){
    ListNode<T>* p=new ListNode<T>;
    front=p;
    rear=p;
}

template<typename T>
Status LinkQueue<T>::EnQueue(const T &e){
    ListNode<T>* p=new ListNode<T>(e);
    p->next=rear->next;
    rear->next=p;
    rear=p;
    count++;
    return ok;
}

template<typename T>
Status LinkQueue<T>::DeQueue(T &e){
    if(Empty()==ok) return error;
    ListNode<T>* p=front->next;
    front->next=p->next;
    e=p->data;
    if(rear==p) rear=front;
    delete p;
    count--;
    return ok;
}

template<typename T>
Status LinkQueue<T>::Empty()const{
    return front==rear?ok:error;
}

template<typename T>
Status LinkQueue<T>::GetFront(T &e)const{
    if(Empty()==ok) return error;
    ListNode<T>* p=front->next;
    e=p->data;
    return ok;
}