#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[11][11];
    memset(a,0,sizeof(a));
    int l=1,r=n,t=1,b=n;
    int num=1;
    while(num<=n*n){
        for(int i=l;i<=r;i++){
            a[t][i]=num++;
        }
        t++;
        for(int i=t;i<=b;i++){
            a[i][r]=num++;
        }
        r--;
        for(int i=r;i>=l;i--){
            a[b][i]=num++;
        }
        b--;
        for(int i=b;i>=t;i--){
            a[i][l]=num++;
        }
        l++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}