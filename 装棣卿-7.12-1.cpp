#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    int a[110],b[110];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    int c[210];
    int i=0,j=0,k=0;
    int l=-1,d=0;
    while(i<n&&j<m){
        if(a[i]<=b[j]){
            d=a[i++];
        }else{
            d=b[j++];
        }
        if(d==l) continue;
        c[k++]=d;
        l=d;
    }
    while(i<n){
        int d=a[i++];
        if(d==l) continue;
        c[k++]=d;
        l=d;
    }
    while(j<m){
        int d=b[j++];
        if(d==l) continue;
        c[k++]=d;
        l=d;
    }
    for(int s=0;s<k;s++){
        cout<<c[s]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}