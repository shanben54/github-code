//力扣 210，给定课程表，返回课程的选择顺序
//先完成前置课程才能选择当前课程，就是在求拓扑排序
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);//邻接表，方便查找相邻结点
        vector<int> c(numCourses,0);//结点入度
        for(size_t i=0;i<prerequisites.size();i++){
            c[prerequisites[i][0]]++;
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(c[i]==0){
                q.push(i);
            }
        }
        int cnt=0;//排序的结点个数，用于判环
        vector<int> ans;
        while(!q.empty()){
            int a=q.front();
            q.pop();
            ans.push_back(a);
            cnt++;
            for(auto b:g[a]){
                c[b]--;
                if(c[b]==0){
                    q.push(b);
                }
            }
        }
        if(cnt==numCourses){
            return ans;
        }else{
            vector<int> k;
            return k;
        }
    }
};