//结点距离问题，寻找哪个结点，使得所有结点到其的加权距离最小
//使用树的模拟来搜索解决，每个结点有子结点和父系结点
#include<bits/stdc++.h>
using namespace std;
#define maxn 110
int n=n,ans=1000000000,vis[maxn];
struct node{
    int left,right,father,value;
}t[maxn];
//用于计算某个结点的总加权距离
int cal(int x,int d){
    if(!x||vis[x]) return 0;//使得每个结点只被计算一次
    vis[x]=1;
    return cal(t[x].left,d+1)+cal(t[x].right,d+1)+cal(t[x].father,d+1)+t[x].value*d;//从这个结点辐射出去计算所有结点到此的加权距离
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i].value>>t[i].left>>t[i].right;
    }
    for(int i=1;i<=n;i++){
        t[t[i].left].father=i;
        t[t[i].right].father=i;
    }//模拟出树的结构
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        ans=min(ans,cal(i,0));
    }//对每个结点进行计算总加权距离，比出最小的
    cout<<ans<<endl;
    system("pause");
    return 0;
}