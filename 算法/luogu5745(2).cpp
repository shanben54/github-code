//计算这个数组里面，相邻几个数的和，不大于m的情况下，使得这个和最大
//这题是使用栈的模拟来解决，复杂度为o(n)
#include<bits/stdc++.h>
using namespace std;
int a[8000010];
long long n,m;
int main(){
    long long ansmax=0,sum=0;
    int i=1,j=1,ansi,ansj;
    cin>>n>>m;
    for(int k=1;k<=n;k++){
        cin>>a[k];
    }
    while(i<=n){
        while(j<=n&&sum+a[j]<=m){
            sum+=a[j],j++;
        }
        if(sum<=m&&sum>ansmax){
            ansmax=sum,ansi=i,ansj=j-1;
        }
        sum-=a[i],i++;
    }
    cout<<ansi<<' '<<ansj<<' '<<ansmax<<endl;
    system("pause");
    return 0;
}