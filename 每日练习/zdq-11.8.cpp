#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        size_t left=0;
        size_t right=0;
        int sum=0;
        int ans=INT_MAX;
        for(;right<nums.size();right++){
            sum+=nums[right];
            while(sum>=target){
                ans=min(ans,int(right-left+1));
                sum-=nums[left++];
            }
        }
        return ans==INT_MAX?0:ans;
    }
};