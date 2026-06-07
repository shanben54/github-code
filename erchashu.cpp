#include<bits/stdc++.h>
using namespace std;
int value[260],winner[260];
int n;
void dfs(int x){
    if(x>=1<<n){
        return ;
    }
    else{
        dfs(x*2);
        dfs(x*2+1);
        int l=value[x*2],r=value[x*2+1];
        if(l>r){
            value[x]=l;
            winner[x]=winner[2*x];
        }
        else{
            value[x]=r;
            winner[x]=winner[2*x+1];
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<i<1<<n;i++){
        cin>>value[i+(1<<n)];
        winner[i+(1<<n)]=i+1;
    }
    dfs(1);
    cout<<(value[2]>value[3]?winner[3]:winner[2]);
    return 0;
}