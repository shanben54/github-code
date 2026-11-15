//力扣26，给定有序数组，进行去重，返回去重后个数
//运用快慢指针，把不重复的元素换到slow里面
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int fast=0;
        int slow=0;
        for(;fast<nums.size();fast++){
            if(nums[fast]!=nums[slow]){
                swap(nums[slow+1],nums[fast]);
                slow++;
            }
        }
        return slow+1;
    }
};