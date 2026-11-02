//力扣215，给定一个数组，返回数组中第k个最大的数据，最大的元素为第一个最大的
#include<bits/stdc++.h>
using namespace std;

//方法1，小顶堆，维护一个大小为k小顶堆，大小超了就取出数据，当数组所有数据都读取完了，小顶堆返回的就是第k个最大元素
class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> q;
        for(auto c:nums){
            q.push(c);
            if(q.size()>k) q.pop();
        }
        return q.top();
    }
};

//方法2，快速排序，如果找到第n-k的位置就返回，大了或者小了就只去对应区间查找，其实用三路查找更好，防止大量重复数据
class Solution2 {
public:
    int Partition(int low,int high,vector<int>& nums){
        int mid=low+(high-low)/2;
        if(nums[high]<nums[low]) swap(nums[low],nums[high]);
        if(nums[high]<nums[mid]) swap(nums[mid],nums[high]);
        if(nums[low]<nums[mid]) swap(nums[low],nums[mid]);
        int pri=nums[low];
        while(low<high){
            while(low<high&&nums[high]>=pri) high--;
            swap(nums[low],nums[high]);
            while(low<high&&nums[low]<=pri) low++;
            swap(nums[low],nums[high]);
        }
        return low;
    }
    void QSort(int low,int high,vector<int>& nums,int n,int k){
        if(low>=high) return;
        int p=Partition(low,high,nums);
        if(p==n-k){
            return;
        }else if(p<n-k){
            QSort(p+1,high,nums,n,k);
        }else{
            QSort(low,p-1,nums,n,k);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=(int)nums.size();
        QSort(0,n-1,nums,n,k);
        return nums[n-k];
    }
};