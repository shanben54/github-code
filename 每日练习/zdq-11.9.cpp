//力扣226，翻转二叉树，左右翻转；
//利用递归交换结点的左右孩子
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
    void Change(TreeNode* r){
        if(r==nullptr)  return;
        Change(r->left);
        Change(r->right);
        //直接交换结点孩子就可以了，不需要用引用
        TreeNode* p=r->left;
        r->left=r->right;
        r->right=p;
    }
    TreeNode* invertTree(TreeNode* root) {
        Change(root);
        return root;
    }
};