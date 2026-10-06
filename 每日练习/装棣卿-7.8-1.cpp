#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>m;
    for(int i=n-m;i<n;i++){
        cout<<a[i]<<" ";
    }
    for(int i=0;i<n-m;i++){
        cout<<a[i]<<" ";
    }
    system("pause");
    return 0;
}