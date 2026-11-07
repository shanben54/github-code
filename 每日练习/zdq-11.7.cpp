//力扣53，求数组连续子数组的最大和
//动态规划，dp[i]表示以i结尾的最大连续子数组和，看看加入上一个最大连续子数组和后和当前元素比哪个更大
//最终取dp里的最大值
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur=nums[0];
        int pre=nums[0];
        int ans=nums[0];
        for(size_t i=1;i<nums.size();i++){
            cur=max(nums[i],pre+nums[i]);
            ans=max(ans,cur);
            pre=cur;
        }
        return ans;
    }
};