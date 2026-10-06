#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int total=0;
        int a;
        while(n--){
            cin>>a;
            total^=a;
        }
        if(total==0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    system("pause");
    return 0;
}