#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> in(numCourses,0);
        for(vector<int> &i:prerequisites){
            int a=i[0];
            int b=i[1];
            g[b].push_back(a);
            in[a]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int j=q.front();
            q.pop();
            count++;
            for(int k:g[j]){
                in[k]--;
                if(in[k]==0){
                    q.push(k);
                }
            }
        }
        if(count==numCourses){
            return true;
        }else{
            return false;
        }
    }
};