//力扣148，对链表进行排序
//使用归并排序来处理链表，用快慢指针找到链表中间位置
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool less(ListNode* a,ListNode* b){return a->val<b->val;}
    //归并函数
    ListNode* Merge(ListNode* u,ListNode* v){
        ListNode q(0);
        ListNode* p=&q;//新的链表
        while(u&&v){
            if(less(v,u)){
                p->next=v;//将数据接到新的链表里面
                v=v->next;
            }else{
                p->next=u;
                u=u->next;
            }
            p=p->next;
        }
        p->next=u?u:v;//把剩下的数据接过来
        return q.next;//返回新的链表
    }
    //分割函数
    ListNode* MSort(ListNode* u){
        if(u==nullptr||u->next==nullptr) return u;
        ListNode* slow=u;
        ListNode* fast=u->next;//fast先走一步，slow最终停到左半区的最后一个位置，如果fast从head开始走，当只有两个数据的时候，slow右边为空
        while(fast&&fast->next){
            if(fast->next->next){
                fast=fast->next->next;
            }else{
                fast=fast->next;
            }
            slow=slow->next;
        }
        ListNode* v=slow->next;
        slow->next=nullptr;
        u=MSort(u);//接住排序好的链表
        v=MSort(v);
        return Merge(u,v);
    }
    ListNode* sortList(ListNode* head) {
        return MSort(head);
    }
};