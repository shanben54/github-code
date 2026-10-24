//力扣34，给定数组，返回关键字最早出现和最晚出现的下标，如果没有这个关键字就返回-1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int a,b;
        int low=0;
        int high=(int)nums.size();
        //查找第一个大于等于关键字的元素的下标
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=target){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        a=low;//此时a最早大于等于关键字的元素
        low=0;
        high=(int)nums.size();
        //查找第一个大于关键字的元素的位置
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid]>target){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        b=low;//此时b就是最早大于关键字的元素
        //如果ab相等说明这个关键字不存在，a是大于等于关键字的最早元素，b是大于关键字的最早元素
        if(a==b){
            ans.push_back(-1);
            ans.push_back(-1);
        }else{
            ans.push_back(a);
            ans.push_back(b-1);//b-1就是关键字最晚出现的位置
        }
        return ans;
    }
};

void check(const string& name, vector<int> nums, int target, vector<int> expected) {
      Solution s;
      vector<int> got = s.searchRange(nums, target);
      if (got == expected) {
          cout << "[OK]   " << name << endl;
      } else {
          cout << "[FAIL] " << name << "  期望: ";
          for (int x : expected) cout << x << " ";
          cout << "  实际: ";
          for (int x : got) cout << x << " ";
          cout << endl;
      }
  }

  int main() {
      check("有重复",     {5,7,7,8,8,10}, 8, {3,4});
      check("找不到",     {5,7,7,8,8,10}, 6, {-1,-1});
      check("空数组",     {},             0, {-1,-1});
      check("单个命中",   {1},            1, {0,0});
      check("单个不中",   {1},            2, {-1,-1});
      check("全是target", {2,2,2},        2, {0,2});
      check("比所有小",   {1,2,3},        0, {-1,-1});
      check("比所有大",   {1,2,3},        5, {-1,-1});
      return 0;
  }