#include<bits/stdc++.h>
using namespace std;
int main(){
    double s,x;
    cin>>s>>x;
    double sum=0.0,step=7.0;
    while(sum<s-x){
        sum+=step;
        step*=0.98;
    }
    sum+=step;
    if(sum>s+x){
        cout<<"n"<<endl;
    }else{
        cout<<"y"<<endl;
    }
    system("pause");
    return 0;
}