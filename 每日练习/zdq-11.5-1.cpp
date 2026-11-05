//力扣198，小偷偷钱，相邻的房子不能同时被偷，求一晚上最多能偷多少
//动态规划，从头不断更新下去，每间房子有两个选项，偷或者不偷，比较哪个收益更大
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        size_t n=nums.size();
        vector<int> dp(n+1,0);
        dp[0]=0;//额外多一个空间，省去边界判断
        dp[1]=nums[0];
        for(size_t i=2;i<=n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);//比较偷和不偷哪个总收益大
        }
        return dp[n];
    }
};