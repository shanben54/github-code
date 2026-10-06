#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    vector<long long> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];    
    }
    sort(a.begin(),a.end());
    long long ans=1e8;
    for(int l=0;l+m-1<n;l++){
        int r=l+m-1;
        long long L=a[l],R=a[r];
        long long num;
        if(R<=0){
            num=-L;
        }else if(L>=0){
            num=R;
        }else{
            long long absl=-L;
            num=absl+R+min(absl,R);
        }
        if(ans>num){
            ans=num;
        }
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}