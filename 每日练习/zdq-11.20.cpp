//力扣102，二叉树的层序遍历
//使用队列来实现，同时每层开始前记录当前层结点数来取出，达到每层每层的效果
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            size_t n=q.size();
            vector<int> a;
            for(size_t i=0;i<n;i++){
                TreeNode* p=q.front();
                q.pop();
                a.push_back(p->val);
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            ans.push_back(a);
        }
        return ans;
    }
};