//力扣413，求等差数列子数组的个数，也就是至少连续三个元素，差值相同的子数组
#include<bits/stdc++.h>
using namespace std;

//动态规划，dp记录以nums[i]为结尾的等差数列个数
//每次到新的元素nums[i]，先判断他和前面两个元素差是否相同，如果相同至少肯定有一个数列，
//同时以nums[i-1]结尾的等差数列也都可以接上nums[i]，因为差值相同，所以nums[i]的dp值就是nums[i-1]的dp值再加上1
//如果插值不相同，就从这断了，dp归为0
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;
        int ans=0;
        int dp=0;
        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1]&&nums[i-1]-nums[i-2]){
                dp=dp+1;
            }else{
                dp=0;
            }
            ans+=dp;
        }
        return ans;
    }
};