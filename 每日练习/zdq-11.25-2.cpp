//力扣83，删除有序链表里的重复数据
//通过pre和cur进行比较判断是否数据重复进行删除
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr) return head;
        ListNode* cur=head->next;
        ListNode* pre=head;
        while(cur){
            if(cur->val==pre->val){
                ListNode* p=cur;
                cur=cur->next;
                delete p;
                pre->next=cur;
            }else{
                pre=cur;
                cur=cur->next;
            }
        }
        return head;
    }
};