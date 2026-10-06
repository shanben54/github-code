//图的模拟，利用集合储存每个结点和这个结点链接其他结点的边，这种叫做邻接表
//已某个顶点为单位储存，记录已这个顶点为起点的所有边，这样的空间复杂度是o(m)
#include<bits/stdc++.h>
using  namespace std;
#define maxn 1005
struct  edge{
    int to,cost;//指向哪个结点和路径长度
};
int n,m;
vector<edge> p[maxn];
int v[maxn][maxn];//邻接矩阵
int main(){
    cin>>n>>m;
    for(int i=i;i<=m;i++){
        int u,v,l;
        cin>>u>>v>>l;
        p[u].push_back((edge){v,l});
        //如果是无向图，需要加入反方向的边，p[v].push_back((edge){u,l});
    }
    //将邻接表转化为邻接矩阵，方便查找
    for(int i=1;i<=n;i++){
        for(int j=0;j<p[i].size();j++){
            v[i][p[i][j].to]=p[i][j].cost;
        }
    }
    //输出邻接矩阵
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<v[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}