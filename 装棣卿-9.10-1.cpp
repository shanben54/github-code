#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums[0];
        int ans=nums[0];
        for(int i=0;i<nums.size();i++){
            if(n<0){
                n=nums[i];
            }else{
                n+=nums[i];
            }
            if(n>ans){
                ans=n;
            }
        }
        return ans;
    }
};