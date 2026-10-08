//力扣124，返回二叉树里最大路径和，路上的结点的值之和最大
//和昨天的题思路类似，递归返回子树的路径和，然后判断左右子树的和是否更大，不断更新最大路径和，但是比昨天多了负数判断
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
        ans=max(ans,max(0,R)+max(0,L)+r->val);//负数判断，如果是子树的路径和是负数就没必要加入进来
        return r->val+max(max(L,0),max(R,0));
    }
};