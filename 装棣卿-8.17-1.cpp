#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<long long> num(100005,0);
    num[0]=1;
    long long sum=0;
    long long ans=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        sum+=a;
        int mod=sum%k;
        ans+=num[mod];
        num[mod]++;
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}