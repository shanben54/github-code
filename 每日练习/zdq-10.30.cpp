//力扣912，对数组进行排序
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool less(int x,int y){return x<y;}
    void QSort(vector<int> &num,int low,int high){
        if(low>=high) return;
        int lt=low;
        int i=low;
        int gt=high;
        int pri=num[low+(high-low)/2];

        while(i<=gt){
            if(less(num[i],pri)){
                swap(num[i++],num[lt++]);
            }else if(less(pri,num[i])){
                swap(num[gt--],num[i]);
            }else{
                i++;
            }
        }
        QSort(num,low,lt-1);
        QSort(num,gt+1,high);
    }
    vector<int> sortArray(vector<int>& nums) {
        QSort(nums,0,(int)nums.size()-1);
        return nums;
    }
};