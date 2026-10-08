//力扣98，判断一颗二叉搜索树是否合规
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

//方法1，运用递归判断结点的左子树和右子树的结点数值是否在范围内
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root,LLONG_MIN,LLONG_MAX);//开始传入的范围是long long的最大值和最小值
    }

    bool helper(TreeNode* root,long long l,long long r){
        if(root==nullptr) return true;
        if(l>=root->val||r<=root->val) return false;//如果结点的值不在范围内就判错，用开区间判断，所以要加等号
        if(helper(root->left,l,root->val)&&helper(root->right,root->val,r)){//再对左右子树进行判断
            return true;
        }else{
            return false;
        }
    }
};

//方法2，对树进行中序遍历，中序遍历是满足递增的，判断相邻结点是否递增
class Solution1{
public:
    bool isValidBST(TreeNode* root) {
        if(root==nullptr) return true;
        stack<TreeNode*> s;
        TreeNode* pre=nullptr;//记录上一个结点
        while(!s.empty()||root!=nullptr){
            while(root!=nullptr){
                s.push(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            if(pre!=nullptr&&root->val<=pre->val) return false;
            pre=root;
            root=root->right;
        }
        return true;
    }
};