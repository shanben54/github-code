//打印杨辉三角形，每层第一个和最后一个是1，其他的等于上方和左上方的和
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[12][12]={0};
    for(int i=1;i<=n;i++){
        a[i][1]=1;
        a[i][i]=1;
        for(int j=2;j<i;j++){
            a[i][j]=a[i-1][j]+a[i-1][j-1];
        }
        for(int k=1;k<=i;k++){
            cout<<a[i][k]<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}