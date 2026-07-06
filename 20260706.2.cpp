#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans;
    cin>>n;
    if(n<=10){
        ans=n*6;
    }
    else if(n<=20){
        ans=60+(n-10)*2;
    }
    else{
        ans=80+(n-20)*1;
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}