#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[10000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int num=INT16_MAX;
    for(int i=0;i<n-m+1;i++){
        int ans=0;
        for(int j=i;j<i+m;j++){
            ans+=a[j];
        }
        num=min(ans,num);
    }
    cout<<num<<endl;
    system("pause");
    return 0;
}