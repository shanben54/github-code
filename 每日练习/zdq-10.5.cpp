//力扣543，返回二叉树里最大的直径，即返回最大的两结点之间距离
//运用递归函数返回结点的子树最大深度，同时比较两个子树的深度和是否可以更新为更大值
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
    int diameterOfBinaryTree(TreeNode* root) {
        ans=0;
        int d=deepth(root);
        return ans;
    }
    
    //返回结点子树的组最大深度，这个返回的不是边的数量，而是结点的数量，但是可以用来计算边的和
    //一个结点两边子树的最大距离和就是两个子树的最大深度和
    int deepth(TreeNode* r){
        if(r==nullptr) return 0;
        int L=deepth(r->left);
        int R=deepth(r->right);
        ans=max(ans,L+R);//判断更新最大半径
        return 1+max(L,R);//返回深度，子树的最大深度加自己
    }
};