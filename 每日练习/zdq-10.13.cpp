//芙芙的生日，生日快乐！
//力扣141，判断链表是否有环(之前做过还是忘了。需要留意一下)
//运用快慢指针，如果有环会一直循环，两指针可以相遇
#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int v):val(v),next(NULL){}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL&&(fast->next)->next!=NULL){//只对fast进行判断，因为他走的快
            slow=slow->next;
            fast=(fast->next)->next;
            if(slow==fast) return true;
        }
        return false;
    }
};