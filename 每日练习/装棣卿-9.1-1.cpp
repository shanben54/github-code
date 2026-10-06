#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string a;
        int maxlen=0;
        for(char c:s){
            int p=-1;
            for(int i=0;i<a.size();i++){
                if(a[i]==c){
                    p=i;
                    break;
                }
            }
            if(p!=-1){
                string b;
                for(int i=p+1;i<a.size();i++){
                    b.push_back(a[i]);
                }
                a=b;
            }
            a.push_back(c);
            maxlen=max(maxlen,int(a.size()));
        }
        return maxlen;
    }
};