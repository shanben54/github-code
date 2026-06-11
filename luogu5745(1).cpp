#include<bits/stdc++.h>
using namespace std;
int a[8000010];
long long s[8000010];
long long n,m;
int find(int x){
    int l=1,r=n+1;
    while(l<r){
        int mid=l+(r-l)/2;
        if(s[mid]>=x) r=mid;
        else l=mid+1;
    }
    if(s[l]==x) return l;
    else return l-1;
}
int main(){
    long long ansmax=0;
    int ansi,ansj;
    cin>>n>>m;
    s[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        long long x=s[i-1]+m;
        int j=find(x);
        long long sum=s[j]-s[i-1];
        if(sum<=m&&sum>ansmax){
            ansmax=sum,ansi=i,ansj=j;
        }
    }
    cout<<ansi<<" "<<ansj<<" "<<ansmax<<endl;
    system("pasue");
    return 0;
}