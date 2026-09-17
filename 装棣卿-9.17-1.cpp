//力扣283，把数组里的0元素都移动到数组末尾
#include<bits/stdc++.h>
using namespace std;

//运用双指针，把0元素聚集在一起，逐步移动到数组末尾
//在左指针左边的都是交换好的序列，右指针及右边的是还没有进行判断的，右指针逐步移动来判断，左右指针的差就是0集的长度
//左指针指向0集，右指针指向未判断元素，是0元素就放到0集里，不是0元素就两者交换就把元素放到0集前面去，0集向数组末移动
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=0;//左指针，指向0集里面第一个元素
        int t;
        for(int r=0;r<nums.size();r++){//右指针逐渐移动
            if(nums[r]!=0){//如果不是0元素
                if(l!=r){//左右指针不一样再交换
                    t=nums[r];
                    nums[r]=nums[l];
                    nums[l]=t;
                }
                l++;//左指针也往前移动，指向0集
            }
        }
    }
};