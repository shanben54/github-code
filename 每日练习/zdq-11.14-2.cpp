//力扣27，移除数组中值为val的元素，返回不等于val的元素个数k，将不等于val的元素换到前k位
//运用快慢指针，fast向前查找，slow维护不等于val的个数，如果fas遇到不等于val的就交换并slow++
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int fast=0;
        int slow=0;
        for(;fast<nums.size();fast++){
            if(nums[fast]!=val){
                swap(nums[slow],nums[fast]);
                slow++;
            }
        }
        return slow;
    }
};