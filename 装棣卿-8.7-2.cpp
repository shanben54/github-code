#include<bits/stdc++.h>
using namespace std;

int a[10010],b[10010];
void build(int l1,int r1,int l2,int r2){
    for(int i=l2;i<=r2;i++){
        if(b[i]==a[l1]){
            build(l1+1,l1+i-l2,l2,i-1);
            build(l1+i-l2+1,r1,i+1,r2);
            cout<<a[l1]<<" ";
            return ;
        }
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    build(1,n,1,n);
    system("pause");
    return 0;
}