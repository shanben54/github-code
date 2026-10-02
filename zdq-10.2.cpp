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