//力扣234，判断链表是否为回文链表
//可以直接开个数组把数据都记录下来再判断是否回文
//更高阶的写法是直接对链表进行判断，先找到链表的中点
//因为链表不能回头，所以对后半链表进行反转，然后设置 两个变量从头和尾往中间走，依次值是否相同
//难点在于反转链表和还原链表
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {} 
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode d(0,head);
        //用快慢指针，当快指针走到尾结点的时候慢指针就在中点了
        ListNode* slow=&d;
        ListNode* fast=&d;
        while(fast->next){
            if(fast->next&&!fast->next->next){//防止最后只剩一格
                fast=fast->next;
            }else{
                fast=fast->next->next;
            }
            slow=slow->next;
        }
        //反转链表
        ListNode* pre=nullptr;//让pre从空开始
        ListNode* cur=slow->next;
        while(cur){
            ListNode* nxt=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nxt;
        }
        //开始回文判断
        ListNode* first=d.next;
        ListNode* second=fast;
        while(second){
            if(first->val!=second->val) return false;
            first=first->next;
            second=second->next;
        };
        //把链表还原回去
        cur=pre;
        pre=nullptr;
        while(cur){
            ListNode* nxt=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nxt;
        }
        return true;
    }
};