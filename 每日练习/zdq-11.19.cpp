//力扣146，设计题，设计一个满足LRU的数据结构，可以实现put和get操作，如果容量满了就把醉酒未使用的数据删除
//使用unorder_map来记录数据，用双向链表来记录数据使用情况，再用一个哈希表来记录结点，可以直接通过键找到对应的结点
//每次使用数据后都将其移到最前的位置，最后的就是最久未使用结点，通过哈希表可以直接O(1)找到key对应的结点进行操作
//双向链表可以直接找到前驱后继进行操作，使链表操作也达到O(1)
//其实这题还可以把两个哈希表合并成一个，是一个可优化点
#include<bits/stdc++.h>
using namespace std;

class LRUCache {
    int c;//容量
    int num;//数据量
    unordered_map<int,int> m;//记录键和值
    struct Node{
        int key;
        Node* pre;
        Node* next;
        Node(int k):key(k),pre(nullptr),next(nullptr){}
    };
    Node* Head;//指向最近使用的结点
    Node* Tail;//指向最久使用的结点
    unordered_map<int,Node*> n;//记录key对应的结点位置
    
public:
    LRUCache(int capacity) {
        c=capacity;
        num=0;
        Head=new Node(0);
        Tail=new Node(0);
        Head->next=Tail;
        Tail->pre=Head;
    }
    
    int get(int key) {
        if(m.count(key)==0){
            return -1;
        }else{
            Node* p=n[key];
            p->pre->next=p->next;
            p->next->pre=p->pre;
            p->next=Head->next;
            Head->next->pre=p;
            p->pre=Head;
            Head->next=p;
            return m[key];
        }
    }
    
    void put(int key, int value) {
        if(m.count(key)==0){
            m.insert({key,value});
            if(num<c){
                Node* p=new Node(key);
                p->next=Head->next;
                Head->next->pre=p;
                Head->next=p;
                p->pre=Head;
                num++;
                n.insert({key,p});
            }else{
                Node* p=Tail->pre;
                p->pre->next=Tail;
                Tail->pre=p->pre;
                m.erase(p->key);
                n.erase(p->key);
                delete p;
                Node* q=new Node(key);
                q->next=Head->next;
                Head->next->pre=q;
                Head->next=q;
                q->pre=Head;
                n.insert({key,q});
            }
        }else{
            m[key]=value;
            Node* p=n[key];
            p->pre->next=p->next;
            p->next->pre=p->pre;
            p->next=Head->next;
            Head->next->pre=p;
            p->pre=Head;
            Head->next=p;
        }
    }

    ~LRUCache(){
        Node* p=Head;
        while(p){
            Node* q=p;
            p=p->next;
            delete q;
        }
    }
};