//用二维数组来模拟出图的矩阵，v[i][j]代表从i到j的路径长度
//不过用二维数组的空间复杂度和时间复杂度都是o(n方)，而且如果是单向的图，会有一半数据是相等的，如果这个图比较稀疏，会有很多空间被浪费
#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
int n;
int v[maxn][maxn];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>v[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(v[i][j]>0){
                cout<<"edge feom point"<<i<<"to point"<<j<<"with length"<<v[i][j]<<'\n';
            }
        }
    }
    return 0;
}