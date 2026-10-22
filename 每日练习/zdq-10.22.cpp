//力扣743，求从一个点往其他点发信号最长所需时间
//求树的最短路径，然后求最大值，用Dijkstra算法
#include<bits/stdc++.h>
using namespace std;

class Solution1 {
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
                dis[v]=min(dis[v],times[i][2]);
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
        delete[] visited;
        delete[] dis;
        if(cnt==n){
            return ans;
        }else{
            return -1;
        }
    }
};

//用优先队列来优化Dijikstra算法
//思路是一样的，只是建立邻接表来方便查找边，用小顶堆来快速找到当前最短的边，提高性能
class Solution2 {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int INF=numeric_limits<int>::max()/2;
        
        //创建邻接表，存储每个结点的边，不用再去遍历查找
        vector<vector<pair<int,int>>> g(n+1);
        for(auto &t:times){
            g[t[0]].push_back({t[1],t[2]});
        }
        
        //结点到k的最短距离
        vector<int> dis(n+1,INF);
        dis[k]=0;
        
        //优先队列(小顶堆)，用于找出当前最短的边
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});//存的是距离和结点，因为先比较第一个元素所以先存距离
        while(!pq.empty()){
            int d=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            if(d>dis[u]) continue;//如果这个距离和最短距离对不上说明这个结点已经用过了
            //更新其他结点的最短距离并加入小顶堆
            for(auto &f:g[u]){
                if(dis[f.first]>dis[u]+f.second){
                    dis[f.first]=dis[u]+f.second;
                    pq.push({dis[f.first],f.first});
                }
            }
        }
        
        //遍历找到最大距离
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dis[i]==INF) return -1;
            ans=max(ans,dis[i]);
        }
        return ans;
    }
};