//力扣160，判断两个链表有没有会合成一个链表
#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int v):val(v),next(NULL){}
};

//解法1，先遍历一个链表把结点都存入哈希表，然后再遍历第二个链表查看有没有重复的结点
class Solution1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> p;
        ListNode* l=headA;
        while(l){
            p.insert(l);
            l=l->next;
        }
        l=headB;
        while(l){
            if(p.count(l)==1){
                return l;
            }
            l=l->next;
        }
        return NULL;
    }
};

//解法2，双指针，一个走完A就走B，一个走完B就走A，如果有会合，两个指针第一次相同的时候就是会合点
//因为两个指针走到会合点前的路程都是一样的，所以必定是同时走到，如果不会合也会同时走到终点
class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a=headA;
        ListNode* b=headB;
        while(a!=b){
            a=(a==NULL)?headB:a->next;
            b=(b==NULL)?headA:b->next;
        }
        return a;
    }
};