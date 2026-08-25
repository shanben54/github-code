#include<bits/stdc++.h>
using namespace std;
char g[1005][1005];
bool visited[1005][1005];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin>>g[i];
    }
    int num=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(g[i][j]=='#'&&!visited[i][j]) {
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j]=true;
                int l=0;
                while(!q.empty()) {
                    pair<int,int> p = q.front();   
                    int x=p.first;                
                    int y=p.second;               
                    q.pop();
                    bool w=false;
                    for(int d=0;d<4;d++) {
                        int nx=x+dx[d];
                        int ny=y+dy[d];
                            if(g[nx][ny]=='#') {
                                if(!visited[nx][ny]) {
                                    visited[nx][ny]=true;
                                    q.push({nx,ny});
                                }
                            }else{
                                w=true;
                            }
                    }
                    if(!w) l++;
                }
                if(l==0) num++;
            }
        }
    }
    cout<<num<<endl;
    system("pause");
    return 0;
}