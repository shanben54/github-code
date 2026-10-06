#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a,b,c;
    c=n%10,n/=10;
    b=n%10,n/=10;
    a=n%10;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    system("pause");
    return 0;
}