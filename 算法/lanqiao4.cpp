#include<bits/stdc++.h>
using namespace std;
int rec,ans;
void dfs(int dep,int cor){
    if(cor>=10) return ;
    if(dep==rec&&cor==0){
        ans++;
        return ;
    }
    dfs(dep+1,cor+1);
    dfs(dep+1,0);
}
int main(){
    ans=1;
    for(int i=2;i<=24;i++){
        rec =i-1;
        dfs(0,0);
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}