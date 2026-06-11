#include<bits/stdc++.h>
using namespace std;
int a[8000010];
long long n,m;
int main(){
    long long ansmax=0,sum=0;
    int i=1,j=1,ansi,ansj;
    cin>>n>>m;
    for(int k=1;k<=n;k++){
        cin>>a[k];
    }
    while(i<=n){
        while(j<=n&&sum+a[j]<=m){
            sum+=a[j],j++;
        }
        if(sum<=m&&sum>ansmax){
            ansmax=sum,ansi=i,ansj=j-1;
        }
        sum-=a[i],i++;
    }
    cout<<ansi<<' '<<ansj<<' '<<ansmax<<endl;
    system("pause");
    return 0;
}