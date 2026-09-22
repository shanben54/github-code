#include<bits/stdc++.h>
using namespace std;

//动态规划，dp记录以当前下标的结点为尾能构成的等差数列个数
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;
        int ans=0;
        int dp=0;
        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                dp=dp+1;
            }else{
                dp=0;
            }
            ans+=dp;
        }
        return ans;
    }
};