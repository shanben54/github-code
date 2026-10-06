//力扣99
//恢复二叉排序树，在二叉排序树里面有两个结点的位置被交换了，找出并恢复位置
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
    void recoverTree(TreeNode* root) {
        stack<TreeNode *>st;
        TreeNode* cur=root;
        TreeNode* pre=nullptr;//指向上一个遍历的结点
        TreeNode* first=nullptr;//第一个出错的结点
        TreeNode* second=nullptr;//第二个出错的结点
        //进行中序遍历，找出错误结点
        while(cur!=nullptr||!st.empty()){
            while(cur!=nullptr){//如果不是空结点就把左子树的左结点入栈
                st.push(cur);
                cur=cur->left;//一路左走到底
            }
            cur=st.top();//取出栈首元素
            st.pop();
            if(pre!=nullptr&&pre->val>cur->val){//如果前驱结点的值比当前的更大，说明有逆序
                if(first==nullptr){
                    first=pre;//如果第一个错误结点没有被记录就记录
                }
                second=cur;//第二个错误结点每次出现逆序都要更新，最多会有两个逆序
            }
            pre=cur;//pre更新为当前结点
            cur=cur->right;//指向右子树，进行遍历右子树，如果右子树为空就会去遍历双亲结点
        }
        //最终交换两个错误结点的值
        int temp=first->val;
        first->val=second->val;
        second->val=temp;
    }
};