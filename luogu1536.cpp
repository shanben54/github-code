//城镇修路问题，和luogu1551是类似的做法
#include<bits/stdc++.h>
using namespace std;
int fa[1010];
int n,m,x,y;
int find(int a){
    if(fa[a]==a) return a;
    return fa[a]=find(fa[a]);
}
void join(int a,int b){
    int a1=find(a),b1=find(b);
    if(a1!=b1){
        fa[a1]=b1;
    }
}
int main(){
    while(cin>>n&&n!=0){
        int ans=0;
        cin>>m;
        for(int i=1;i<=n;i++){
            fa[i]=i;
        }
        for(int i=0;i<m;i++){
            cin>>x>>y;
            join(x,y);
        }
        for(int i=1;i<=n;i++){
            if(find(i)==i) ans++;
        }
        cout<<ans-1<<endl;
    }
    return 0;
}