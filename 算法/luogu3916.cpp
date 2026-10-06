//图的遍历问题，给出一个图，求每个结点可以到达的最大的编号
//这题采用的是反向建边的思路，然后从最大的结点往上遍历，到达的点都记录当前这个结点的值
//如果采用正向的遍历，一直遍历直到最深的编号，但这样遇到环形的图就会得到错误的答案
//反向遍历就可以避免这个问题，因为从大到小遍历，将可以到达的点都先记录，遇到环形的图也没问题
#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int n,m;
vector<int> p[maxn];
int a[maxn];
void solve(int x,int  v){
    a[x]=v;//x点的值更新为v
    for(int i=0;i<p[x].size();i++){
        if (a[p[x][i]]==0){//如果这个点没有被更新，因为从大到小遍历，所以如果被更新了那一定是被比当前结点更大的值更新的
            solve(p[x][i],v);//如果没有被更新就继续深度搜索，如果被更新过，说明之后的点也被更新过了，就没必要再去深度搜索了 
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        p[v].push_back(u);//反向建边
    }
    for(int i=n;i>=0;i--){//从大到小遍历
        if(a[i]==0)  solve(i,i);//一样的道理，如果这个点被更新过，那他之后的点都被更新了，没必要搜索
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }
    return 0;
}