#include<bits/stdc++.h>
using namespace std;
int a[12];
int main(){
    long long m,n;
    cin>>m>>n;
    for(long long i=m;i<=n;i++){
        long long t=i;
        while(t>0){
            a[t%10]++;
            t/=10;
        }
    }
    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
    system("pause");
    return 0;
}