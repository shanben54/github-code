#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,v;
    cin>>n>>v;
    vector<int> w(n),val(n);
    for(int i=0;i<n;i++){
        cin>>w[i]>>val[i];
    }
    vector<int>dp(n+1,0);
    for(int i=0;i<n;i++){
        for(int j=v;j>=w[i];j--){
            dp[j]=max(dp[j],dp[j-w[i]]+val[i]);
        }
    }
    cout<<dp[v]<<endl;
}