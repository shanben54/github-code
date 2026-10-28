//力扣136，给定数组，里面所有数字都出现两次，只有一个数字没有，找出那个数字
//使用异或运算的性质，和自己异或=0，和0异或不变，满足交换律和结合律
//将所有数字分别异或，重复的数字会消掉，只剩一个数字
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a=nums[0];
        for(size_t i=1;i<nums.size();i++){
            a^=nums[i];
        }
        return a;
    }
};