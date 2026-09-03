#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n+1,0);
        vector<int> out(n+1,0);
        for(vector<int> i:trust){
            int a=i[0];
            int b=i[1];
            out[a]++;
            in[b]++;
        }
        for(int i=1;i<=n;i++){
            if(in[i]==n-1&&out[i]==0){
                return i;
            }
        }
        return -1;
    }
};