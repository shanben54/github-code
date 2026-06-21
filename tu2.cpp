//图的模拟，利用集合储存每个结点和这个结点链接其他结点的边
#include<bits/stdc++.h>
using  namespace std;
#define maxn 1005
struct  edge{
    int to,cost;//指向哪个结点和路径长度
};
int n,m;
vector<edge> p[maxn];
int v[maxn][maxn];//矩阵
int main(){
    cin>>n>>m;
    for(int i=i;i<=m;i++){
        int u,v,l;
        cin>>u>>v>>l;
        p[u].push_back((edge){v,l});
    }
    //将这个集合转化为矩阵，方便查找
    for(int i=1;i<=n;i++){
        for(int j=0;j<p[i].size();j++){
            v[i][p[i][j].to]=p[i][j].cost;
        }
    }
    //输出矩阵
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<v[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}