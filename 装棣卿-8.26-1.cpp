#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        for(int i=2;i<=n;i++){
            string next;
            int count=1;
            for(int j=1;j<s.size();j++){
                if(s[j]==s[j-1]){
                    count++;
                }else{
                    next+=to_string(count);
                    next+=s[j-1];
                    count=1;
                }
            }
            next+=to_string(count);
            next+=s.back();
            s=next;
        }
        return s;
    }
};