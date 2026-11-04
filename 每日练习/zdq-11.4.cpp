//力扣455，分饼干，如果饼干大小大于等于孩子的要求就可以分给他，求最多能分给几个孩子
//贪心问题，先对孩子和饼干必须，从小到大遍历，如果饼干不合要求就下一个
//这样可以保证小饼干优先分给小孩子，从而达到最优
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        size_t i=0,j=0;
        int ans=0;
        while(i<g.size()&&j<s.size()){
            if(g[i]>s[j]){
                j++;
                continue;
            }
            i++;
            j++;
            ans++;
        }
        return ans;
    }
};