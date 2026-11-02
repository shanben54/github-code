//力扣547，省份问题，两个城市直接可以直达就是在一个省份里，求有多少个省份
//并查集问题，每个城市初始老大就是自己，如果两个城市老大不一样，就把其中一个接到另一个上去
//遍历完所有城市，就会有几个不同的集合，就是省份数量
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //查找老大的函数
    int Find(int x,vector<int> boss){
        while(boss[x]!=x) x=boss[x];
        return x;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        size_t n=isConnected.size();
        vector<int> boss(n);
        for(size_t i=0;i<n;i++){
            boss[i]=i;//老大数组，初始为自己
        }
        for(size_t i=0;i<n;i++){
            for(size_t j=0;j<n;j++){
                if(isConnected[i][j]){
                    int ib=Find(i,boss);
                    int jb=Find(j,boss);
                    if(ib!=jb){
                        boss[jb]=ib;
                    }
                }
            }
        }
        int ans=0;
        for(size_t i=0;i<n;i++){
            if(Find(i,boss)==i) ans++;
        }
        return ans;
    }
};