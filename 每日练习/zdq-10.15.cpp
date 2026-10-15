//力扣19，删除结点倒数第n个结点并返回头结点
//首先先设置一个虚拟结点，放在头结点的前一个，这样头结点被删除后也可以直接返回
//创建快慢指针，fast先比slow多走n步，然后两者同步向前，当fast到尾结点后，slow就在倒数第n个结点的前一位了，可以直接删除
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode d(0,head);
        ListNode* slow=&d;
        ListNode* fast=&d;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* p=slow->next;
        slow->next=p->next;
        delete p;
        return d.next;
    }
};