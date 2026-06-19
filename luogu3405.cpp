//城市问题，判断有多少个abcd和cdab这样类型的字符串
//首先是先要把城市和州拼成字符串，再求这个字符串的hash值
#include<bits/stdc++.h>
using namespace std;
#define mod 233333
int n;
char a[12],b[12];
long long ans;
vector<pair<int ,int>>linker[mod+2];//vector里面定义一个二元组，第一个数据表示字符串，第二个数据表示出现的次数
inline int gethash(char a[],char b[]){
    return (a[0]-'A')+(a[1]-'A')*26+(b[0]-'A')*26*26+(b[1]-'A')*26*26*26;//算出两个字符串拼在一起的hash值
}
//将字符串的hash值加入数组里面
inline void insert(int x){
    for(int i=0;i<linker[x%mod].size();i++){
        if(linker[x%mod][i].first==x){
            linker[x%mod][i].second++;//如果出现了，次数+1
            break;
        }
    }
    linker[x%mod].push_back(pair<int ,int>(x,1));//把这个数据加入vector里面
    //这里关于break的使用我也进行了思考，其实用return是最好的，如果这个数据存在，那就直接退出，这样就不会把这个重复的数据加入vector里面了
    //但其实用break也许，甚至你不写return或者break都行，虽然这样会把重复的x加入到vector里面
    //不过这些重复的数据(x,1)是加入到vector末尾的，当使用find函数进行查询的时候，只会查询到最先出现的正确的数据，这些重复的数据不会被查询到
    //虽然多了重复的数据占用内存，但是确实不影响程序的运行，给我带来一定的启发
}
//查询x出现的次数
inline int find(int x){
    for(int i=0;i<linker[x%mod].size();i++){
        if(linker[x%mod][i].first==x){
            return linker[x%mod][i].second;
        }
    }
    return 0;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;//a是城市名，b是州的名字
        a[2]=0;//只取城市名前两个字母
        if(a[0]!=b[0]||a[1]!=b[1]){//不能出现城市前两字母和州一样的情况，如果是abab，那他对应的城市也一定是ab州的，而两个城市不能出自一个州
            ans+=find(gethash(b,a));//寻找和他匹配的城市数量，然后加入匹配城市总数里面
        }
        insert(gethash(a,b));//把这个城市数据加入数组里
    }
    cout<<ans<<endl;
    return 0;
}