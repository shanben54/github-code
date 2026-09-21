//力扣141，判断链表是否有环
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
 };

 //运用快慢指针，一个一次走两个，一个一次走一个，如果有环，指针会在环里循环，两个指针最终一定会追上
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;//慢指针
        ListNode* fast=head;//快指针
        while(fast->next!=nullptr&&(fast->next)->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;//追上说明有环
        }
        return false;
    }
};

//哈希表做法，将每个结点的地址存入哈希表，可以查询每个结点是否出现过
//我最开始想到可以标记每个结点是否出现过，但是没想到可以用哈希表来储存，也没想好可以储存结点的什么数据，现在明白可以储存结点地址
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* cur=head;
        unordered_set<ListNode*> n;
        while(cur!=nullptr){
            if(n.count(cur)) return true;//查询结点是否出现过
            n.insert(cur);
            cur=cur->next;
        }
        return false;
    }
};