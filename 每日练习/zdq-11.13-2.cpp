//力扣242，判断两个单词里的字母出现次数是否都一样
//开一个字母数组，记录s字母出现次数，t字母出现就-1，最终如果不等于0就不一样
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;//如果长度不同直接判错
        int a[26]={0};
        for(size_t i=0;i< s.size();i++){
            a[s[i]-'a']++;
        }
        for(size_t i=0;i<t.size();i++){
            a[t[i]-'a']--;
        }
        for(size_t i=0;i<26;i++){
            if(a[i]!=0) return false;
        }
        return true;
    }
};