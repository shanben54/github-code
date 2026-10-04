//力扣105，给定二叉树前序和中序遍历，把这颗树建出来
//调用递归，根据前序遍历先在中序遍历找到根，得到左右子树的中序遍历，然后算出左子树个数，代会前序里求出左子树的前序遍历
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        unordered_map<int,int>pos;
        for(int i=0;i<n;i++){
            pos[inorder[i]]=i;
        }
        TreeNode* root=build(preorder,inorder,0,n-1,0,n-1,pos);
        return root;
    }

    TreeNode* build(vector<int>& preorder,vector<int>& inorder,int prel,int prer,int inl,int inr,unordered_map<int,int> &pos){
        if(prel>prer) return nullptr;
        TreeNode* root=new TreeNode(preorder[prel]);
        int k=pos[preorder[prel]];
        root->left=build(preorder,inorder,prel+1,prel+k-inl,inl,k-1,pos);
        root->right=build(preorder,inorder,prel+k-inl+1,prer,k+1,inr,pos);
        return root;
    }
};