//力扣206，反转链表
//利用三个指针 记录前驱，当前和后继，更改结点指向达到反转的效果
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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=nullptr;
        ListNode* cur=head;
        ListNode* tmp=nullptr;
        while(cur){
            tmp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=tmp;
        }
        return pre;
    }
};