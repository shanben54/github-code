//力扣70，爬楼梯，从0出发，每次能爬1或者2阶楼梯，求到n阶有多少种走法
//动态规划，每次取前两阶楼梯的走法之和
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];    
    }
};