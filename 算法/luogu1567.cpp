#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int a;
    cin>>n;
    cin>>a;
    int num=1;
    int ans=1;
    for(int i=1;i<n;i++){
        int b;
        cin>>b;
        if(b>a){
            ans++;
            num=max(num,ans);
        }else{
            ans=1;
        }
        a=b;
    }
    cout<<num<<endl;
    system("pause");
    return 0;
}