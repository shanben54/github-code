//今天居然忘记写代码了，罪过罪过，明天一定补上
#include<bits/stdc++.h>
using namespace std;
#define maxn 5005
#define maxm 500005
#define mod 80112002
int n,m,ans;
vector<int>p[maxn];
queue<int>q;
int f[maxn],ind[maxn],outd[maxn];
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        outd[x]++;
        ind[y]++;
        p[x].push_back(y);
    }
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++){
        if(ind[i]==0){
            q.push(i);
            f[i]=1;
        }
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0,sz=p[x].size();i<sz;i++){
            int y=p[x][i];
            f[y]=(f[x]+f[y])%mod;
            ind[y]--;
            if(ind[y]==0) q.push(y);
        }
    }
    for(int i=1;i<=n;i++){
        if(outd[i]==0){
            ans=(ans+f[i])%mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}