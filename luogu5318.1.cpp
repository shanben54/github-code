//参考文献问题，每个文章会指向其他的文章，如何不重复不遗漏的阅读完文章和其参考文献
//问题是图的遍历，每个结点指向其他的结点，然后利用搜索来遍历这个图
//这个代码使用深度优先搜索
#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int n,m;
vector<int>p[maxn];//邻接表，储存结点所指向的其他结点
bool u[maxn];
void solve(int x){
    cout<<x<<' ';//输出遍历的顺序
    for(int i=0,sz=p[x].size();i<sz;i++){
        if(!u[p[x][i]]){
            u[p[x][i]]=true;//保证每个结点只被输出一次
            solve(p[x][i]);//继续对参考文献进行遍历
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