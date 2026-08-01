#include<bits/stdc++.h>
using namespace std;
int b[3010];
int main(){
    int n;
    cin>>n;
    int c,d;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>c>>d;
        b[i]=b[i-1]+c+d-8;
        sum+=b[i];
    }
    cout<<sum<<endl;
    system("pause");
    return 0;
}