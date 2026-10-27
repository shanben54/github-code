//给定一些不重复的数字，求这些数字的全排列
//深度优先搜索加回溯，不断递归往路径里填充数字，填满了就回到上一层
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   //深度优先搜索回溯函数
    void DFS(vector<int> &path,size_t n,vector<vector<int>> &ans,vector<int> &nums,vector<bool> &visited){
        //如果路径已经满了就加入答案并返回
        if(path.size()==n){
            ans.push_back(path);
            return; 
        }
        //找到没加入路径的数字
        for(size_t i=0;i<n;i++){
            if(visited[i]==false){
                path.push_back(nums[i]);
                visited[i]=true;//更新这个数字的状态
                DFS(path,n,ans,nums,visited);//递归
                path.pop_back();
                visited[i]=false;
                //递归完要还原状态，回溯
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        size_t n=nums.size();
        vector<bool> visited(n,false);
        vector<vector<int>> ans;
        vector<int> path;
        DFS(path,n,ans,nums,visited);
        return ans;
    }
};