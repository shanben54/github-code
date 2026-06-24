//参考文献问题的广度优先搜索做法
//运用队列，将各个文献的参考文献以此放入队列，只有先把这一层的文献搜索完再进行下一层的搜索
#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int n,m;
vector<int>p[maxn];//邻接表，储存每个文献的参考文献
queue<int>q;
bool u[maxn];
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        p[x].push_back(y);
    }
    u[1]=true;
    q.push(1);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        cout<<x<<' ';//输出搜索的顺序
        for(int i=0,sz=p[x].size();i<sz;i++){
            if(!u[p[x][i]]){
                u[p[x][i]]=true;
                q.push(p[x][i]);//把参考文献放入队列
            }
        }
    }
    return  0;
}