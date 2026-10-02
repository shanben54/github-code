#include<iostream>
#include<cstdlib>
#include<string>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v):val(v),left(nullptr),right(nullptr){}
    TreeNode(int v,TreeNode* l,TreeNode* r):val(v),left(l),right(r){}
};

auto cmp=[](TreeNode* a,TreeNode* b){
    return a->val>b->val;
};

priority_queue<TreeNode*,vector<TreeNode*>,decltype(cmp)> q(cmp);

void GetCode(TreeNode* t,string code){
    if(t->left==nullptr&&t->right==nullptr){
        cout<<t->val<<":"<<code<<endl;
        return ;
    }else{
        GetCode(t->left,code+"0");
        GetCode(t->right,code+"1");
    }
}

int main(){
    int w[]{1,2,3,4,5};
    for(int a:w){
        TreeNode* p=new TreeNode(a);
        q.push(p);
    }
    while(q.size()>1){
        TreeNode* a=q.top();
        q.pop();
        TreeNode* b=q.top();
        q.pop();
        TreeNode* c=new TreeNode(a->val+b->val,a,b);
        q.push(c);
    }
    TreeNode* root=q.top();
    GetCode(root,"");
    system("pause");
    return 0;
}