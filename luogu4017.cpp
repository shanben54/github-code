//食物链问题，给定一些捕食关系，求有多少条完整的食物链
//这也是个DAG，并且运用了拓扑排序
//f[x]表示从0入度点到x的食物链数，先将入度为0的结点入栈，然后遍历其链接的点，然后f[y]+=f[x]，并使y的入度--；
//如果y的入度也为0了就将其入栈，直到栈空为止
//这个拓扑排序确实是非常巧妙啊，每个入度为0的结点遍历自己的所有边再计算，如果某个结点也入度为0，那也加入栈里面
//这题还用了取模的性质，如果过程中每个数都取模，相加后取模的结果和这些数不取模相加后再取模的结果是一样的，就可以避免过程量也溢出了
#include<bits/stdc++.h>
using namespace std;
#define maxn 5005
#define maxm 500005
#define mod 80112002//取模数
int n,m,ans;
vector<int>p[maxn];
queue<int>q;
int f[maxn],ind[maxn],outd[maxn];
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;//输入捕食关系
        outd[x]++;
        ind[y]++;
        p[x].push_back(y);//邻接表，记录这个捕食关系，x指向y
    }
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++){
        if(ind[i]==0){
            q.push(i);//先把所有入度为0的结点入栈，作为起点
            f[i]=1;//使入度为0的结点的f值为1
        }
    }
    while(!q.empty()){//栈空为止，说明所有结点都更新完毕
        int x=q.front();
        q.pop();
        for(int i=0,sz=p[x].size();i<sz;i++){
            int y=p[x][i];
            f[y]=(f[x]+f[y])%mod;//需要取模，防止数据过大
            ind[y]--;//计算完y的一个入度结点，y的入度-1
            if(ind[y]==0) q.push(y);//入度为0时加入栈
        }
    }
    for(int i=1;i<=n;i++){
        if(outd[i]==0){//统计所有出度为0的点，也就是食物链的最底层
            ans=(ans+f[i])%mod;//总链数结果也要取模，防止数据过大
        }
    }
    cout<<ans<<endl;
    return 0;
}