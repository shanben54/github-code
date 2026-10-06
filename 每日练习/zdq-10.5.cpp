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
    int ans;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans=0;
        int d=deepth(root);
        return ans;
    }

    int deepth(TreeNode* r){
        if(r==nullptr) return 0;
        int L=deepth(r->left);
        int R=deepth(r->right);
        ans=max(ans,L+R);
        return 1+max(L,R);
    }
};