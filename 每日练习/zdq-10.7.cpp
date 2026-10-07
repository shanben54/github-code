//力扣236，返回结点p和q的最深共同祖先
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root,p,q);
    }

    TreeNode* helper(TreeNode* r,TreeNode* p,TreeNode* q){
        if(r==nullptr||r==p||r==q) return r;
        TreeNode* L=helper(r->left,p,q);
        TreeNode* R=helper(r->right,p,q);
        if(L&&R) return r;
        return L?L:R;
    }
};