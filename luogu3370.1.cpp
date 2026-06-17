//简易版luogu3370，给定一定个数字，统计出现了多少个不同的数字
//核心是让x对mod取模，然后记录下来，最后统计有多少个不同的数字
//由于数据范围比较大，就不可以用数组a[x]来记录x是否出现，用取模的方式来记录，这样数组就不用开很大
//用vector来记录取模数相同的不同数，保证准确性
#include<bits/stdc++.h>
using namespace std;
#define mod 233333//模数
int n,x,ans;
vector<int> linker[mod+2];//创建了一个数组，数组里面每个元素都是一个vector数组
inline void insert(int x){
    for(int i=0;i<linker[x%mod].size();i++){//对取模为值为x%mod的数字进行枚举
        if(linker[x%mod][i]==x){
            return ;//如果x已经被记录过了，直接退出
        }
    }
    linker[x%mod].push_back(x);
    ans++;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        insert(x);
    }
    cout<<ans<<endl;
    return 0;
}