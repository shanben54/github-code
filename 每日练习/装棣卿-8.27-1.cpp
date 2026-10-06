#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int num=0;
        int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    num++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j]='0';
                    while(!q.empty()){
                        pair<int,int> p = q.front();   
                        int x=p.first;                
                        int y=p.second;               
                        q.pop();
                        for(int k=0;k<4;k++){
                            int nx=x+d[k][0];
                            int ny=y+d[k][1];
                            if(nx>=0&&ny>=0&&nx<m&&ny<n&&grid[nx][ny]=='1'){
                                grid[nx][ny]='0';
                                q.push({nx,ny});
                            }
                        }
                    }
                }
            }
        }
        return num;
    }
};