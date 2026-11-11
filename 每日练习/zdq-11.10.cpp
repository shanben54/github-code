//力扣300，返回数组里递增序列的最大长度
//动态规划，每次都找前面比自己小的，看看接上后有没有变大
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        size_t n=nums.size();
        vector<int> dp(n,1);
        int ans=1;
        for(size_t i=1;i<n;i++){
            for(size_t  j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                    ans=max(ans,dp[i]);
                }
            }
        }
        return ans;
    }
};