//力扣3，求一个字符串中无重复字母的最大子串的长度
//设置一个滑动窗口来记录子串，右指针不断右移，用哈希表记录子串字母出现位置
//如果右指针指向重复的字母，让左指针移到重复字母的下一位(或者不动，因为也可能重复元素在之前的移动中被移出子串了)
//不断重复，更新子串最长长度
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t left=0;
        size_t right=0;
        int ans=0;
        size_t n=s.size();
        unordered_map<char,size_t> m;
        while(right<n){
            if(m.count(s[right])==0){
                m[s[right]]=right;
            }else{
                left=max(left,m[s[right]]+1);
                m[s[right]]=right;
            }
            ans=max(ans,int(right-left+1));
            right++;
        }
        return ans;
    }
};