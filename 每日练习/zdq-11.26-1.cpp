//力扣82，删除有序链表里的重复数据 ，重复数据全部都删除(不留)
//因为重复的数据都删除而不保留，只能通过cur探查他后面两个数据是否重复
//如果重复就记录重复值然后把值为这个的结点全部删除，最后再接回cur继续判断
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
        ListNode h;
        h.next=head;
        ListNode* cur=&h;
        while(cur->next&&cur->next->next){
            if(cur->next->val==cur->next->next->val){
                int x=cur->next->val;
                ListNode* p=cur->next;
                while(p&&p->val==x){
                    ListNode* q=p;
                    p=p->next;
                    delete q;
                }
                cur->next=p;
            }else{
                cur=cur->next;
            }
        }
        return h.next;
    }
};