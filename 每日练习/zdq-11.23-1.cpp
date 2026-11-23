//力扣15，求三数之和为0的所有组合
//依次选取第一位数，然后通过双指针寻找另外两个
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        size_t n=nums.size();

        sort(nums.begin(),nums.end());//先对数组排序

        for(size_t i=0;i<n-2;i++){//循环第一个数
            if(nums[i]>0) break;//如果大于0，之后的两个数也大于0，最终和肯定不会等于0
            if(i>0&&nums[i]==nums[i-1]) continue;//如果第一位数据重复就跳过
            int l=i+1;
            int r=n-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];//计算当前总和
                if(sum==0){//如果等于0
                    ans.push_back({nums[i],nums[l],nums[r]});//记录当前搭配
                    //略过重复数据
                    while(l<r&&nums[l]==nums[l+1]) l++;
                    while(l<r&&nums[r]==nums[r-1]) r--;
                    //继续向中间缩
                    l++;
                    r--;
                }else if(sum<0){//如果小了就右移
                    l++;
                }else{//大了的就左移
                    r--;
                }
            }
        }   
        return ans;
    }
};