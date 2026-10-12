//力扣662，求二叉树最大宽度
//把二叉树想象成完全二叉树，中间空的结点也算，所以在存入队列的时候把编号也记录进去
//用完全二叉树的性质，孩子编号为2*r,2*r+1,这样哪怕中间有空的也可以计算出宽度，最后最右的结点减去最左边的结点的编号再+1就是这层宽度
//然后对每层结点编号进行归一化，防止溢出，这样结点的编号就是偏移量，始终很小
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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        queue <pair<TreeNode*,unsigned long long>> q;
        q.push({root,1});
        int ans=0;
        while(!q.empty()){
            int s=q.size();
            unsigned long long l=0;
            unsigned long long r=0;
            for(int i=0;i<s;i++){
                auto cur=q.front();
                q.pop();
                if(i==0) l=cur.second;
                r=cur.second-l;
                TreeNode* p=cur.first;
                if(p->left){
                    q.push({p->left,2*r});
                }
                if(p->right){
                    q.push({p->right,r*2+1});
                }
            }
            ans=max(ans,(int)(r+1));
        }
        return ans;
    }
};