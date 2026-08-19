#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long> a(n+1),b(n+1);
    vector<long long> suma(n+1,0),sumb(n+1,0);
    vector<long long> lasta(n+2,0),lastb(n+2,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        suma[i]=suma[i-1]+a[i];
        sumb[i]=sumb[i-1]+b[i];
    }
    for(int i=n;i>0;i--){
        lasta[i]=lasta[i+1]+a[i];
        lastb[i]=lastb[i+1]+b[i];
    }
    long long ans=min(suma[n],sumb[n]);
    for(int i=1;i<n;i++){
        ans=min(ans,suma[i]+lastb[i+1]);
        ans=min(ans,sumb[i]+lasta[i+1]);
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}