//力扣99，恢复二叉排序树
//之前做过这道题，再做一遍巩固一下
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
       TreeNode* pre=nullptr;
       TreeNode* cur=root;
       TreeNode* first=nullptr;
       TreeNode* second=nullptr;
       stack<TreeNode*>s;
       while(cur!=nullptr||!s.empty()){
        while(cur!=nullptr){
            s.push(cur);
            cur=cur->left;
        }
        cur=s.top();
        s.pop();
        if(pre!=nullptr&&pre->val>cur->val){
            if(first==nullptr){
                first=pre;
            }
            second=cur;
        }
        pre=cur;
        cur=cur->right;
       }
       int t=first->val;
       first->val=second->val;
       second->val=t;
    }
};