//力扣78，给定一个数组求它的全部子集
//回溯算法，每次只从start往前走，这样就不会重复记录，每次进函数都先记录答案
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void DFS(const vector<int> &nums,vector<vector<int>> &ans,vector<int> &path,int start,int n){
        ans.push_back(path);//先把这个路径计入答案啊
        if(start>=n) return;
        //如果后面还有数字就继续加
        for(int i=start;i<n;i++){
            path.push_back(nums[i]);//先加入路径
            DFS(nums,ans,path,i+1,n);//再进行下一轮
            path.pop_back();//撤销，还原状态
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=(int)nums.size();
        vector<vector<int>> ans;
        vector<int>path;
        DFS(nums,ans,path,0,n);
        return ans;
    }
};