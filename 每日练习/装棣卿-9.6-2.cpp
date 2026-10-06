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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> t;
        if(root==nullptr) return t;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> n;
            for(int i=0;i<size;i++){
                TreeNode* a=q.front();
                q.pop();
                n.push_back(a->val);
                if(a->left!=nullptr){
                    q.push(a->left);
                }
                if(a->right!=nullptr){
                    q.push(a->right);
                }
            }
            t.push_back(n);
        }
        return t;
    }
};