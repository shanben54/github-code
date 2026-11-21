//力扣700，在二叉搜索树里查找值
//直接利用二叉搜索树性质进行递归
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==nullptr) return NULL;
        if(root->val==val) return root;
        else if(root->val<val){
            return searchBST(root->right,val);
        }else{
            return searchBST(root->left,val);
        }
    }
};