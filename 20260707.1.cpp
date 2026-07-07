#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[11][11];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    int b=n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[j][i]<<" ";
            b--;
            if(b==0){
                cout<<endl;
                b=n;
            }

        }
    }
    system("pause");
    return  0;
}