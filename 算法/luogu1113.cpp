//杂物问题，每个杂物都需要一定时间完成，必须先完成前置准备杂物才能完成这个杂物，如果两个杂物没有关系可以同时进行，求完成所有杂物的时间
//其实就是求最晚完成的任务的时长，每个任务只要前置任务完成就可以开始，和其他的任务独立
//每个任务所需时间就是把前置任务里面用时最长的加上自己所需的的时间
//题目规定了第k个任务的前置任务一定在1-k-1，所以这个图是有向无环图，简称DAG
#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
int n,x,y,t,ans,len[maxn],vis[maxn];
vector<int> linker[maxn];
int dfs(int x){
    if(vis[x])  return vis[x];//如果已经更新过值，就直接返回完成这个任务所需的时间
    for(int i=0;i<linker[x].size();i++){
        vis[x]=max(vis[x],dfs(linker[x][i]));//找到所需时间最长的前置任务 
    }
    vis[x]+=len[x];//再加上自己的时间
    return vis[x];
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>len[x];
        while(cin>>y){
            if(!y) break;
            else linker[y].push_back(x);
        }
    }
    for(int i=1;i<=n;i++){
        ans+=max(ans,dfs(i));//求需要时间最长的结点
    }
    cout<<ans<<endl;
    return 0;
}