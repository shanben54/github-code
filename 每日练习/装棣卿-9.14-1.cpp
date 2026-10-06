#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=  nums.size();    
        int maxs=0;
        for(int i=0;i<n;i++){
            if(i>maxs){
                return false;
            }
            maxs=max(maxs,i+nums[i]);
            if(maxs>=n-1){
                return true;
            }
        }
        return true;
    }
};