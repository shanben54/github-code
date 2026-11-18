//力扣1142，求两个字符串最大相同子序列长度，子序列不一定连续
//动态规划，dp[i][j]表示前text1前i个字符和text2前j个字符的最大相同子序列长度
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        size_t m=text1.size();
        size_t n=text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(size_t i=1;i<=m;i++){
            for(size_t j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]){//如果当前字符相同就可以接下去
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);//如果不同就保留前面最大的结果
                }
            }
        }
        return dp[m][n];
    }
};