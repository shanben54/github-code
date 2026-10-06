#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d;
    int t1,t2,t3;
    t1=a*60+b;
    t2=c*60+d;
    t3=t2-t1;
    e=t3/60;
    f=t3%60;
    cout<<e<<" "<<f<<endl;
    system("pause");
    return 0;
}