#include <bits/stdc++.h>
using namespace std;
int a[2030];
bool zhishu(int x){
    if(x==2) return true;
    if(x%2==0) return false;
    for(int i=3;i*i<=x;i+=2){
        if(x%i==0) return false;
    }
    return true;
}
int main(){
    int num=0,n=2;
    while(num<2025){
        if(zhishu(n)){
            a[num++]=n;
        }
        n++;
    }
    cout<<a[2024];
    system("pause");
    return 0;
}