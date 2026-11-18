//力扣9，判断是否为回文数
//可以转换为字符串进行判断，也可以把当前这个数反转后对比
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x<10) return true;
        string s=to_string(x);
        size_t a=0;
        size_t b=s.size()-1;
        while(a<=b){
            if(s[a]!=s[b]) return false;
            a++;
            b--;
        }
        return true;
    }
};