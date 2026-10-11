//力扣103，交叉遍历二叉树
//记录下每层的结点数，设置标志来判断是否反转，再用reverse将序列反转达到交叉的效果
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> num;
        if(root==nullptr) return num;
        queue<TreeNode*> q;
        q.push(root);
        bool p=true;
        while(!q.empty()){
            int s=q.size();
            vector<int> n;
            for(int i=0;i<s;i++){
                TreeNode* r=q.front();
                q.pop();
                n.push_back(r->val);
                if(r->left) q.push(r->left);
                if(r->right) q.push(r->right);
            }
            if(!p){
                reverse(n.begin(),n.end());
            }
            p=!p;
            num.push_back(n);
        }
        return num;
    }
};