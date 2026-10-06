#include<bits/stdc++.h>
using namespace std;
int main(){
    long long l,r;
    cin>>l>>r;
    long long total=r-l+1;
    long long first =l+((2-l%4)+4)%4;
    long long last=r-((r%4-2)+4)%4;
    long long cnt =0;
    if(first<=r){
        cnt=(last-first)/4+1;
    }
    cout<<total-cnt<<endl;
    system("pause");
    return 0;
}