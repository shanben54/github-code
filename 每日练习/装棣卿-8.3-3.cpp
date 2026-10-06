#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a=1,b=2,c;
    int i=2;
    while(i<n){
        c=a+b;
        a=b;
        b=c;
        i++;
    }
    cout<<c<<endl;
    system("pause");
    return 0;
}