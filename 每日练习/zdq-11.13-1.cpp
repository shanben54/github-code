//力扣104，求二叉树最大深度
//利用递归求最大深度
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
    void D(TreeNode* root,int deepth,int &ans){
        if(root==nullptr) return;
        deepth+=1;
        ans=max(ans,deepth);
        D(root->left,deepth,ans);
        D(root->right,deepth,ans);
    }
    int maxDepth(TreeNode* root) {
        int ans=0;
        int deepth=0;
        D(root,deepth,ans);
        return ans;
    }
};