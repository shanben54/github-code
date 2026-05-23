#include<bits/stdc++.h>
using namespace std;
int main(){
    float s;
    cin>>s;
    float a=2;
    float ans=2;
    int n=1;
    while (ans<=s){
        a=a*0.98;
        ans+=a;
        n++;
    }
    cout<<n<<endl;
    system("pause");
    return 0;
}