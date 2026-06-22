#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int n,m;
vector<int>p[maxn];
bool u[maxn];
void solve(int x){
    cout<<x<<' ';
    for(int i=0,sz=p[x].size();i<sz;i++){
        if(!u[p[x][i]]){
            u[p[x][i]]=true;
            solve(p[x][i]);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        p[x].push_back(y);
    }
    u[1]=true;
    solve(1);
    return 0;
}