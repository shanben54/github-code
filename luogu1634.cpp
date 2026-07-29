//第一次提交还没通过，思索半天发现把int改成long lon就可以了，这提醒我要注意一下数据范围和类型#include<bits/stdc++.h>
using namespace std;
int main(){
    long long x,n;
    cin>>x>>n;
    long long  num=1,sum=1;
    for(int i=0;i<n;i++){
        num*=x;
        sum+=num;
        num=sum;
    }
    cout<<sum<<endl;
    system("pause");
    return 0;
}
