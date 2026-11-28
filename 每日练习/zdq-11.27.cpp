//力扣21，合并两个有序链表
//创建一个哑结点，然后依次比较两个链表数据接到上面
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode head;
        ListNode* cur=&head;
        ListNode* a=list1;
        ListNode* b=list2;
        while(a&&b){
            if(a->val<=b->val){
                cur->next=a;
                cur=cur->next;
                a=a->next;
            }else{
                cur->next=b;
                cur=cur->next;
                b=b->next;
            }
        }
        if(a) cur->next=a;
        if(b) cur->next=b;
        return head.next;
    }
};