//力扣212，购买股票的最佳时期
//维护一个最大利润和最小价格，不断遍历下去，更新最大利润和最小价格
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=prices[0];
        int maxprofile=0;
        for(size_t i=0;i<prices.size();i++){
            maxprofile=max(maxprofile,prices[i]-minprice);//更新今天之前的最大利润
            minprice=min(minprice,prices[i]);//更新今天的最小值
        }
        return maxprofile;
    }
};