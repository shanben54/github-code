#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int b=a[0];
    int c=a[0];
    for(int i=1;i<n;i++){
        b=max(a[i],b+a[i]);
        c=max(b,c);
    }
    cout<<c<<endl;
    system("pause");
    return 0;
}