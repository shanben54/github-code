//力扣1584，给定一些点的坐标，求将这些点都连通最小距离，距离用两坐标相减的绝对值
//其实就是求图的最小生成树，因为边可以有很多，所以用Prim算法来解
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        size_t n=points.size();
        int* visited=new int[n];
        int ans=0;
        int INF=numeric_limits<int>::max()/2;
        int* dis=new int[n];
        for(size_t i=0;i<n;i++){
            visited[i]=0;
            dis[i]=abs(points[i][0]-points[0][0])+abs(points[i][1]-points[0][1]);
        }
        visited[0]=1;
        for(size_t i=1;i<n;i++){
            int p=INF;
            int q=-1;
            for(size_t j=0;j<n;j++){
                if(visited[j]==0&&dis[j]<p){
                    p=dis[j];
                    q=j;
                }
            }
            visited[q]=1;
            ans+=p;
            for(size_t j=0;j<n;j++){
                int d=abs(points[j][0]-points[q][0])+abs(points[j][1]-points[q][1]);
                if(visited[j]==0&&dis[j]>d){
                    dis[j]=d;
                }
            }
        }
        delete[] visited;
        delete[] dis;
        return ans;
    }
};