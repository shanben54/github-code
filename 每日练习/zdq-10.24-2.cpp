//力扣994，橘子问题，给定一橘子在矩阵中的位置，腐烂的橘子每分钟都会感染四周的橘子，求全部橘子腐烂后的时间，不能全部腐烂就返回-1
//图的多源遍历，遍历腐烂橘子的四周，看看有没有感染新的橘子，如果没有感染新的橘子，这分钟就不算，因为在上一分钟橘子已经都腐烂了
//最后遍历看看是否还存在每腐烂的橘子
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minute=0;
        queue<pair<int,int>> q;
        size_t n=grid.size();
        size_t m=grid[0].size();
        int dist[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        for(size_t i=0;i<n;i++){
            for(size_t j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            bool is=0;
            size_t s=q.size();//将新腐烂的橘子全部取出判断有没有感染其他橘子
            for(size_t i=0;i<s;i++){
                auto a=q.front();
                q.pop();
                int u=a.first;
                int v=a.second;
                for(auto b:dist){
                    int ur=u+b[0];
                    int vr=v+b[1];
                    if(ur>-1&&ur<n&&vr>-1&&vr<m&&grid[ur][vr]==1){//注意不要越界
                        q.push({ur,vr});
                        grid[ur][vr]=2;
                        is=1;
                    }
                }
            }
            //感染新橘子这分钟才加上
            if(is){
                minute++;
            }
        }
        for(size_t i=0;i<n;i++){
            for(size_t j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return minute;
    }
};