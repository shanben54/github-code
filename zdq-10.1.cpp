#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* leftchild;
    TreeNode* rightchild;
    TreeNode(int v):val(v),leftchild(nullptr),rightchild(nullptr){}
};

vector<int> RightSideView(TreeNode *root){
    vector<int> ans;
    queue<TreeNode *> q;
    if(root==nullptr) return ans;
    q.push(root);
    while(!q.empty()){
        int s=q.size();
        TreeNode* p;
        for(int i=0;i<s;i++){
            p=q.front();
            q.pop();
            if(p->leftchild){
                q.push(p->leftchild);
            }
            if(p->rightchild){
                q.push(p->rightchild);
            }
        }
        ans.push_back(p->val);
    }
    return ans;
}