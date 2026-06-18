//完整版的luogu3370，给定一定的字符串，统计有多少个不同的字符串
//有了简化版的思路，就是取模储存，只是计算字符串的hash值(对mod取模的值)不太一样
#include<bits/stdc++.h>
using namespace std;
#define maxn 1510
#define base 261
#define mod 23333
int n,ans;
char s[maxn];
vector<string> linker[mod+2];
inline void insert(){
    int hash=1;
    for(int i=0;s[i];i++){
        hash=(hash*1ll*base+s[i])%mod;//计算这个字符串的hash值
    }
    string t=s;
    for(int i=0;i<linker[hash].size();i++){
        if(linker[hash][i]==t) return;//对取模为hash的数进行枚举，看看有没有重复出现
    }
    linker[hash].push_back(t);
    ans++;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;insert();
    }
    cout<<ans<<endl;
    return 0;
}