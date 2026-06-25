#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int n,m;
vector<int> p[maxn];
int a[maxn];
void solve(int x,int  v){
    a[x]=v;
    for(int i=0;i<p[x].size();i++){
        if (a[p[x][i]]==0){
            solve(p[x][i],v);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        p[v].push_back(u);
    }
    for(int i=n;i>=0;i--){
        if(a[i]==0)  solve(i,i);
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }
    return 0;
}