#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int a=0,b=0;
    while(t--){
        cin>>a>>b;
        int num=0;
        while(a!=0&&b!=0){
            if(a>b){
                int c=a-b;
                a=c;
            }else{
                int c=b-a;
                b=c;
            }
            num+=1;
        }
        cout<<num<<endl;
    }
    system("pause");
    return 0;
}