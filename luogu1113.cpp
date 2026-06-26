#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
int n,x,y,t,ans,len[maxn],vis[maxn];
vector<int> linker[maxn];
int dfs(int x){
    if(vis[x])  return vis[x];
    for(int i=0;i<linker[x].size();i++){
        vis[x]=max(vis[x],dfs(linker[x][i]));    
    }
    vis[x]+=len[x];
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
        ans+=max(ans,dfs(i));
    }
    cout<<ans<<endl;
    return 0;
}