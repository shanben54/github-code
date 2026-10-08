//力扣236，返回结点p和q的最深共同祖先
//运用递归寻找当前结点内pq的最深共同祖先
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
    
    //寻找r的子树内pq的最深共同祖先，如果返回空说明pq不在r的子树里面
    TreeNode* helper(TreeNode* r,TreeNode* p,TreeNode* q){
        if(r==nullptr||r==p||r==q) return r;
        TreeNode* L=helper(r->left,p,q);
        TreeNode* R=helper(r->right,p,q);
        if(L&&R) return r;//左右子树都非空，说明pq各占一边，r就是他们最深共同祖先
        return L?L:R;//一棵子树返回空就返回另一棵子树，两边都空就返回空
    }
};