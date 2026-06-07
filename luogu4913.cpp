#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
struct node{
    int left,right;
}t[maxn];
int n;
void bulid(){
    for(int i=1;i<=n;i++){
        scanf("%d %d",&t[i].left,t[i].right);
    }
}
int dfs(int x){
    if(!x) return 0;
    return max(dfs(t[x].left),dfs(t[x].right))+1;
}
int main(){
    cin>>n;
    bulid();
    cout<<dfs(1);
    return 0;
}