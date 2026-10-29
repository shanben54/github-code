//力扣322.给定一些面额的硬币和一个总金额，返回达到这个金额所需的最小硬币数
//动态规划，dp[i]表示到达i所需的最小硬币数，从小到大遍历
//然后遍历硬币，更新dp[i]的值，i之前的金额已经是最小的了，直接更新就是最小
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,amount+1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(auto coin:coins){
                if(coin<=i){
                    dp[i]=min(dp[i],dp[i-coin]+1);
                }
            }
        }
        return dp[amount]==amount+1?-1:dp[amount];
    }
};