//力扣876，返回链表中间结点
//运用快慢指针继续查找
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next){
            if(fast->next->next){
                fast=fast->next->next;
            }else{
                fast=fast->next;
            }
            slow=slow->next;
        }
        return slow;
    }
};