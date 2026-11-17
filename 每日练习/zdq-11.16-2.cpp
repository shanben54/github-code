//力扣191，判断一个数二进制下有多少个1
//通过n&=n-1可以消去低位1，记录消的次数就是1的个数
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int ans=0;
        while(n){
            n&=n-1;
            ans++;
        }
        return ans;
    }
};