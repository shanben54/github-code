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
    void Deletemax(TreeNode* &r){
        if(r->right){
            Deletemax(r->right);
        }else{
            TreeNode* p=r;
            r=r->left?r->left:r->right;
            delete p;
        }
    }
    void Delete(TreeNode* &r){
        if(r->left&&r->right){
            TreeNode* p=r->left;
            while(p->right){
                p=p->right;
            }
            r->val=p->val;
            Deletemax(r->left);
        }else{
            TreeNode* p=r;
            r=r->left?r->left:r->right;
            delete p;
        }
    }
    void Node(TreeNode* &r,int key){
        if(r==nullptr) return;
        if(r->val==key){
            Delete(r);
        }else if(r->val>key){
            Node(r->left,key);
        }else{
            Node(r->right,key);
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        Node(root,key);
        return root;
    }
};