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
private:
    int ans=0;
public:
    int maxPathSum(TreeNode* root) {
        if(root==nullptr) return 0;
        ans=root->val;
        helper(root);
        return ans;
    }

    int helper(TreeNode* r){
        if(r==nullptr) return 0;
        int L=helper(r->left);
        int R=helper(r->right);
        ans=max(ans,max(0,R)+max(0,L)+r->val);
        return r->val+max(max(L,0),max(R,0));
    }
};