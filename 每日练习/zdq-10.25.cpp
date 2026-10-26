//力扣33，原本有一个有序递增的数组，从某个位置截断后将右边的数组接到左边去，现在在这个数组里查找值
//也是二分查找，因为是直接查找值所以用闭区间，每次取mid后先判断哪边有序，然后去判断目标值是否在有序集里，不在就去另一边
//其实就和普通二分一样，判断值在不在这边，不在就压一下区间，不过因为有一半数组是被打乱的，所以先找到有序集再判断值是否存在这个区间
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=(int)nums.size()-1;
        while(left<=right){//闭区间
            int mid=left+(right-left)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>=nums[left]){
                if(target>=nums[left]&&target<nums[mid]){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }else{
                if(target>nums[mid]&&target<=nums[right]){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
        }
        return -1;
    }
};