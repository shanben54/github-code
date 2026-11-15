//力扣88，将两个非递减数组合并成一个非递减数组
//用三个指针，从后往前比较，塞到数组1后面的空位，从后往前可以不影响数组1的顺序
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int f1=m-1;
        int f2=n-1;
        int slow=m+n-1;
        while(f1>=0&&f2>=0){
            if(nums1[f1]>=nums2[f2]){
                nums1[slow--]=nums1[f1--];
            }else{
                nums1[slow--]=nums2[f2--];
            }
        }
        //处理剩余的数组2元素，如果数组1还有剩不用处理
        while(f2>=0){
            nums1[slow--]=nums2[f2--];
        }
    }
};