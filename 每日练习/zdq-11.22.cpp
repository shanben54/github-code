//力扣56，给定一些区间，把有重叠的区间进行合并
//先根据区间第一位把所有区间进行排序，依次比较当前区间和上一个区间的第二位，有重叠就更新上一个区间进行合并
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<int> cur;
        vector<int> pre=intervals[0];
        vector<vector<int>> ans;
        int l;
        int r;
        ans.push_back(pre);
        for(int i=1;i<intervals.size();i++){
            cur=intervals[i];
            if(cur[0]<=pre[1]){
                ans.pop_back();
                l=pre[0];
                r=max(pre[1],cur[1]);
                pre={l,r};
                ans.push_back(pre);
            }else{
                ans.push_back(cur);
                pre=cur;
            }
        }
        return ans;
    }
};