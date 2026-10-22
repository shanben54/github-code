//力扣743，求从一个点往其他点发信号最长所需时间
//求树的最短路径，然后求最大值，用Dijkstra算法
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int *visited=new int[n+1];
        int INF=numeric_limits<int>::max()/2;
        int ans=0;
        int* dis=new int[n+1];
        for(int i=1;i<=n;i++){
            visited[i]=0;
            dis[i]=INF;
        }
        for(size_t i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            if(u==k){
                dis[v]=times[i][2];
            }
        }
        visited[k]=1;
        dis[k]=0;
        int cnt=1;//统计连接的结点，最后用于判断是否为连通图
        for(int i=1;i<n;i++){
            int p=-1;
            int q=INF;
            for(int j=1;j<=n;j++){
                if(visited[j]==0&&dis[j]<q){
                    p=j;
                    q=dis[j];
                }
            }
            if(p==-1) break;
            visited[p]=1;
            cnt++;
            ans=max(ans,q);
            for(size_t j=0;j<times.size();j++){
                int u=times[j][0];
                int v=times[j][1];
                if(u==p&&dis[v]>dis[u]+times[j][2]){
                    dis[v]=dis[u]+times[j][2];
                }
            }
        }
        if(cnt==n){
            return ans;
        }else{
            return -1;
        }
    }
};