#include<bits/stdc++.h>
using namespace std;
bool sushu(int x){
    if(x<1) return false;
    if(x==2) return true;
    if(x%2==0) return false;
    int i=3;
    while(i*i<=x){
        if(x%i==0) return false;
        i++;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        if(sushu(i)){
            cout<<i<<endl;
        }
    }
    system("pause");
    return 0;
}