//力扣209，求数组和大于等于target的子数组的最短长度
//滑动窗口，如果和小于target就继续滑动，大于等于就更新最短长度
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        size_t left=0;
        size_t right=0;
        int sum=0;
        int ans=INT_MAX;
        for(;right<nums.size();right++){//right一直滑动
            sum+=nums[right];//先把和加进来
            //如果和超了，从左侧缩，看看能不能长度更短还满足条件
            while(sum>=target){
                ans=min(ans,int(right-left+1));//先更新长度，缩完之后就不满足了
                sum-=nums[left++];
            }
        }
        return ans==INT_MAX?0:ans;//如果不存在这样的子数组就返回0
    }
};