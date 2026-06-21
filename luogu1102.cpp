//查找给出的数据里面是否存在a-b=c的情况，有多少种这样的情况
//之前是用二分的方法来解决的，现在用map来解决
//利用了map会自动初始化为0的特性，如果查询到的数是输入的数，其ds值是1，所以计数+1
#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
map<int ,int>ds;
int a[maxn],n,c;
long long ans;
int main(){
    cin>>n>>c;
    for(int i=1;i<=n;i++){
        cin>>a[i],ds[a[i]]++;//用ds记录输入的数，只有输入的数的ds值是1，其他未输入的是0
    }
    for(int i=1;i<=n;i++){
        ans+=ds[a[i]-c];//查询是否存在a-b=c,即是否存在一个b=a-c,如果存在的话ds[b]的值是1，被记录进去，如果不存在ds[b]=0，不影响结果
    }
    cout<<ans<<endl;
    return 0;
}