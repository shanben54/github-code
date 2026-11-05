#ifndef LINKLIST_H
#define LINKLIST_H

#include<utility>

template<typename T>
class LinkList{
private:
    //定义结点
    struct Node
    {
        T data;
        Node* next;
        Node(cosnt T &v):data(v),next(nullptr){}//结点的构造函数，初始next为nullptr，更新为引用传参，这样可以减少一次拷贝构造
    };
    Node* Head;//头结点，next指向第一个结点

public:
    //构造函数，先构造一个头结点出来
    LinkList():Head(new Node(0)){}
    
    //拷贝构造，深拷贝
    LinkList(const LinkList& o){
        Head=new Node(0);
        Node* p=o.Head->next;
        Node* q=Head;
        while(p){
            Node* n=new Node(p->data);
            q->next=n;
            q=n;
            p=p->next;
        }
    }
    
    //拷贝赋值，返回值为结点的引用，方便连续赋值
    LinkList& operator=(const LinkList& o){
        LinkList tmp(o);//先用拷贝构造把要复制的结点内容复制出来
        std::swap(Head,tmp.Head);//然后再进行交换，可以这样防止万一在复制过程中出什么问题，原来的自己不变
        return *this;//返回自己
    }
    
    //析构函数，清理结点，删除头结点
    ~LinkList(){
        ClearList();
        delete Head;
    }
    
    //获取链表长度，从第一个结点开始遍历然后计数增加
    int GetLength()const{
        Node* p=Head->next;//指向第一个结点
        int n=0;
        while(p!=nullptr){
            p=p->next;
            n++;
        }
        return n;
    }
    
    //获取第i个结点的数据
    bool GetElem(int i,T &e)const{
        if(i<1) return false;//注意i不合理的判别，最开始就忘了写
        Node* p=Head->next;
        int j=1;
        while(p!=nullptr&&j<i){
            p=p->next;
            j++;
        }
        //循环结束后p指向第i个结点
        if(p==nullptr) return false;//长度没有i就报错
        e=p->data;
        return true;
    }
    
    //在第i个位置添加结点
    bool LinkListInsert(int i,T e){
        if(i<1) return false;
        Node* p=Head;
        int j=1;
        while(p!=nullptr&&j<i){
            p=p->next;
            j++;
        }
        //循环结束后p指向第i-1个结点
        if(p==nullptr) return false;
        Node* s=new Node(e);//新建结点
        //将结点链接到链表里
        s->next=p->next;
        p->next=s;
        return true;
    }
    
    //删除第i个结点
    bool LinkListDelete(int i,T &e){
        if(i<1) return false;
        Node* p=Head;
        int j=1;
        while(p!=nullptr&&j<i){
            p=p->next;
            j++;
        }
        if(p==nullptr||p->next==nullptr) return false;
        Node* q=p->next;
        e=q->data;
        p->next=q->next;
        delete q;
        return true;
    }
    
    //头插法
    bool HeadInsert(int n){
        ClearList();
        Node* p=Head->next;//p指向结点第一个数据
        for(int i=0;i<n;i++){
            Node* q=new Node(rand()%100+1);
            q->next=p;
            p=q;
        }
        Head->next=p;//把链表和头结点链接起来
        return true;
    }
    
    //尾插法
    bool TailInsert(int n){
        ClearList();
        Node* p=Head;//p指向结点最后一个数据
        for(int i=0;i<n;i++){
            Node* q=new Node(rand()%100+1);
            p->next=q;
            p=q;
        }
        p->next=nullptr;//封尾
        return true;
    }
    
    //清除链表
    bool ClearList(){
        Node* p=Head->next;
        //遍历所有结点，然后清除
        while(p!=nullptr){
            Node* q=p;
            p=p->next;
            delete q;
        }
        //更新头结点指向
        Head->next=nullptr;
        return true;
    }
};

#endif