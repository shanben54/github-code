//力扣39，求数组中和为target的组合，元素可以无限使用
//回溯算法来进行组合，因为是组合，所以设置一个start变量，只从之后的元素里选取，就不会重复
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void DFS(vector<int>& c,int target,vector<int> &path,int start,int sum,vector<vector<int>> &ans){
        if(sum==target){
            ans.push_back(path);
            return;
        }
        if(sum>target) return;
        for(int i=start;i<c.size();i++){
            if(c[i]>target-sum) break;//剪枝，先把candidates数组排序，如果当前元素已经大了，剩下元素也不用判断了
            path.push_back(c[i]);
            DFS(c,target,path,i,sum+c[i],ans);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int sum=0;
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        DFS(candidates,target,path,0,sum,ans);
        return ans;
    }
};