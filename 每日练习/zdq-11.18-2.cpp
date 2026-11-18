//力扣200，判断岛屿数量，1是土地，0是海洋，连着的土地算一个岛
//遍历找到土地就把周围的土地都标记为海洋，这样就算一个岛，继续遍历下去
//这次踩的坑是要先更新状态再入队，不然会有重复数据，数据大了就会很恐怖 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int dis[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    queue<pair<int,int>> q;
                    grid[i][j]='0';//先更新状态再入队
                    q.push({i,j});
                    while(!q.empty()){
                        auto a=q.front();
                        q.pop();
                        int x=a.first;
                        int y=a.second;
                        for(auto b:dis){
                            int xr=x+b[0];
                            int yr=y+b[1];
                            if(xr>-1&&xr<m&&yr>-1&&yr<n&&grid[xr][yr]=='1'){//先判断有没有越界
                                grid[xr][yr]='0';
                                q.push({xr,yr});
                            }
                        }
                    }
                    ans++;
                }
            }
        }
        return ans;
    }
};