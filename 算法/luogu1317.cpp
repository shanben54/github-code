#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a;
    cin>>n;
    cin>>a;
    int l=false;
    int ans=0;
    for(int i=1;i<n;i++){
        int b;
        cin>>b;
        if(a>b){
            l=true;
        }
        if(a<b&&l==true){
            ans++;
            l=false;
        }
        a=b;
    }
    cout<<ans<<endl;
    system("pasue");
    return 0;
}