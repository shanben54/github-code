//力扣235，返回二叉搜索树中p和q结点的最早祖先
//BST有独特的性质，更为方便，我们直接从根结点开始遍历，如果当前结点的值在pq的值的中间，那这个结点就是最早祖先
//如果比pq都大就去左子树遍历，小了就去右子树遍历
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

//普通递归解法
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root,p,q);
    }

    TreeNode* helper(TreeNode* r,TreeNode* p,TreeNode* q){
        if((r->val<=p->val&&r->val>=q->val)||(r->val>=p->val&&r->val<=q->val)){
            return r;
        }
        if(q->val<r->val&&p->val<r->val){
            return helper(r->left,p,q);
        }else{
            return helper(r->right,p,q);
        }
    }
};

//不用递归直接while的解法
class Solution{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int l=min(p->val,q->val);
        int r=max(q->val,p->val);
        while(root->val<l||root->val>r){
            root=root->val<l?root->right:root->left;
        }
        return root;
    }
};