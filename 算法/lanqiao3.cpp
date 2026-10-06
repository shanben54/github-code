#include<bits/stdc++.h>
using namespace std;
struct unionfind{
    vector<int> parent;
    vector<int> size;
    int cnt;
    unionfind(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        cnt=n;
        for(int i=1;i<=n;i++){
            parent[i]=i;
       }
    }
    int find(int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y){
            return;
        }
        if(size[x]<size[y]){
            swap(x,y);
        }
        parent[y]=x;
        size[x]+=size[y];
        cnt--;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    unionfind uf(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(a==b){
            continue;
        }
        uf.unite(a,b);
    }
    long long k=uf.cnt;
    long long fight=k*(k-1)/2;
    cout<<k<<" "<<fight<<endl;
    system("pause");
    return 0;
}