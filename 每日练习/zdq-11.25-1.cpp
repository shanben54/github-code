//力扣22，给定n，求n个括号所有合法的搭配
//回溯算法，在过程中剪枝，左括号数不能大于n，右括号数不能大于左括号，最后字符串大小等于2n时就是合法答案
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void DFS(string path,vector<string> &ans,int lnum,int rnum,int n){
        if(path.size()==2*n){
            ans.push_back(path);
            return;
        }else{
            if(lnum<n){
                DFS(path+"(",ans,lnum+1,rnum,n);
            }
            if(rnum<lnum){
                DFS(path+")",ans,lnum,rnum+1,n);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        DFS("",ans,0,0,n);
        return ans;
    }
};