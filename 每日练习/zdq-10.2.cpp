//判断一颗二叉树是否是镜像对称的
//写一个判断两颗子树是否镜像对称的函数，判断左树的左子树和右数的右子树，左树的右子树和右树的左子树又分别是否镜像对称
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

bool Mirror(TreeNode* p,TreeNode* q){
    if(q==nullptr&&p==nullptr) return true;
    else if(q==nullptr||p==nullptr) return false;
    else {
        if((p->val==q->val)&&(Mirror(p->left,q->right))&&(Mirror(p->right,q->left))){
            return true;
        }else{
            return false;
        }
    }
}

bool IsSymmetric(TreeNode* root){
    if(root==nullptr) return true;
    return Mirror(root->left,root->right);
}