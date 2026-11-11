//力扣217，判断数组内有无重复元素
//使用集合来查找元素是否出现过
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> q;
        for(auto a:nums){
            if(q.count(a)!=0) return  true;
            q.insert(a);
        }
        return false;
    }
};