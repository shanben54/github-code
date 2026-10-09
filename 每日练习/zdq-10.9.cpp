//力扣230，返回二叉搜索树里第k小的结点数据
//直接对二叉搜索树进行中序遍历，得到的序列就是结点从小到大排序的结果，同时加入计数指标cnt，找到第k个数据
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
    int kthSmallest(TreeNode* root, int k) {
        if(root==nullptr) return 0;
        stack<TreeNode *> s;
        int cnt=0;
        while(!s.empty()||root!=nullptr){
            while(root!=nullptr){
                s.push(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            if(++cnt==k){
                return root->val;
            }
            root=root->right;
        }
        return 0;
    }
};