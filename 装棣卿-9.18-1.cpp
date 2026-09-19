//力扣219，查询数组里两个数据相同的元素的下标差是否小于k
#include<bits/stdc++.h>
using namespace std;

//运用stl里的哈希表unordered_map来储存某个值最近出现的下标
//遍历数组，查询每个值之前是否出现，如果出现了判断最近出现的下标差是否符合要求
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>last;//记录数据最近出现的下标
        for(int i=0;i<nums.size();i++){//遍历数组
            if(last.count(nums[i])&&i-last[nums[i]]<=k){//count用于判断这个值之前是否出现过
                return true;
            }
            last[nums[i]]=i;//哪怕不符合要求也更新这个值最近下标
        }
        return false;
    }
};