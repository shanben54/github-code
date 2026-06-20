#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
map<int ,int>ds;
int a[maxn],n,c;
long long ans;
int main(){
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        cin>>a[i],ds[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        ans+=ds[a[i]-c];
    }
    cout<<ans<<endl;
    return 0;
}