#include<bits/stdc++.h>
using namespace std;
const int N=110;
typedef pair<int,int>PII;
int map_[N][N],mark[N][N];
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1},n,m,ans;
void bfs(){
    memset(mark,-1,sizeof mark);
    queue<pair<int,int>>q;
    mark[0][0]=0;
    q.push({0,0});
    while(!q.empty()){
        PII top=q.front();
        for(int i =0;i<4;i++){
            int nex=top.first+dx[i],ney=top.second+dy[i];
            if(nex>=0&&nex<n&&ney>=0&&ney<m&&mark[nex][ney]==-1&& map_[nex][ney]==0){
                mark[nex][ney]=mark[top.first][top.second]+1;
                q.push({nex,ney});
            }
        }
        q.pop();
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map_[i][j];
        }
    }
    bfs();
    cout<<mark[n-1][m-1]<<endl;
    system("pause");
    return 0;
}