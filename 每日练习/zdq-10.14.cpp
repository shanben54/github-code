//力扣142，也是判断有没有环，但是要返回环的入口
//在用快慢指针判断出有环后，一个指针回到头结点，另一个从相遇地出发，两个都只走一格，最终相遇的地方就是入口
#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int v):val(v),next(NULL){}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL) return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next&&(fast->next)->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                fast=head;
                while(fast!=slow){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};