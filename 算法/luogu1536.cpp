//城镇修路问题，和luogu1551是类似的做法
//也是用集合把城镇串联起来，然后最后统计有多少个族长，就知道有多少个集合，从而知道需要修多少路
#include<bits/stdc++.h>
using namespace std;
int fa[1010];
int n,m,x,y;
int find(int a){
    if(fa[a]==a) return a;
    return fa[a]=find(fa[a]);//压缩路径
}
void join(int a,int b){
    int a1=find(a),b1=find(b);
    if(a1!=b1){
        fa[a1]=b1;
    }
}
int main(){
    while(cin>>n&&n!=0){//当输入n=0时退出程序
        int ans=0;
        cin>>m;
        for(int i=1;i<=n;i++){
            fa[i]=i;
        }
        for(int i=0;i<m;i++){
            cin>>x>>y;
            join(x,y);
        }
        for(int i=1;i<=n;i++){
            if(find(i)==i) ans++;
        }//统计有多少个族长
        cout<<ans-1<<endl;//城镇数量-1就是需要修的路的数量
    }
    return 0;
}