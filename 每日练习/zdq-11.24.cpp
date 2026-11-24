//力扣64，给定网格，求从左上走到右下最短路径和
//使用动态规划，每次取左边和上面最小的那个来更新当前值
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int INF=numeric_limits<int>::max()/2;
        vector<vector<int>> dp(m+1,vector<int>(n+1,INF));//多开一圈填充最大值，不用进行边界判断
        dp[1][1]=grid[0][0];
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(i==1&&j==1) continue;;
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i-1][j-1];
            }
        }
        return dp[m][n];
    }
};