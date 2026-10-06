//查询亲戚关系
//通过把每个元素指向一个负责人，构建集合，来查询两个元素是否在同一个集合里面，两者的最终负责人(族长)一样，则在同一个集合里面
#include<bits/stdc++.h>
using namespace std;
#define maxn 5010
int n,m,p,x,y;
int fa[maxn];
//查询某个元素的族长
int find(int x){
    if(x==fa[x]) return x;//族长的负责人就是自己
    return fa[x]=find(fa[x]);//递归查询最终的负责人(族长)，此处还进行路径压缩，把x的负责人改成了族长，这样就不是长链结构了，提高效率
}
//如果两个元素的族长不一样，就把这两个集合合并
void join(int c1,int c2){
    int f1=find(c1),f2=find(c2);
    if(f1!=f2) fa[f1]=f2;
}
int main(){
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }//每个元素最开始的负责人就是自己
    for(int i=0;i<m;i++){
        cin>>x>>y;
        join(x,y);
    }
    for(int i=0;i<p;i++){
        cin>>x>>y;
        if(find(x)==find(y)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}