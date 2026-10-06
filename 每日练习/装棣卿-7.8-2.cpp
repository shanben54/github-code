#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int a[11][11];
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    int b=n;
    for(int j=1;j<=n;j++){
        for(int i=n;i>=1;i--){
            cout<<a[i][j]<<" ";
            b--;
            if(b==0){
                cout<<endl;
                b=n;
            }
        }
    }
    system("pause");
    return 0;
}