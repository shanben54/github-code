//力扣231，判断一个数是不是2的幂
//n&(n-1)会消去一个数二进制下的1，2的幂的二进制只有一个1，可以通过这个来判断
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0&&(n&(n-1))==0;
    }
};