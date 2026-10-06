//木材仓库问题，一个仓库储存一定量的木头，没有长度相同的木材，现可以进行存放，取出长度为lenth的木材，如果没有就取最接近的，有多根取最短的
#include<bits/stdc++.h>
using namespace std;
int n,opt,lenth;
set<int> ds;
int main(){
    cin>>n;
    while(n--){
        cin>>opt>>lenth;
        if(opt==1){
            if(ds.find(lenth)!=ds.end()) cout<<"Already Exist"<<endl;//不能有两根一样长的木材
            //如果不存在的话，find会=回返回end()
            else ds.insert(lenth);
        }
        else if(ds.empty()){
            cout<<"Empty"<<endl;
        }
        else{
            set<int>::iterator i=ds.lower_bound(lenth),j=i;//lower_bound返回不小于lenth的最小的数的地址
            if(j!=ds.begin()) --j;//如果j是begin()的话就不可以自减
            if(i!=ds.end()&&lenth-(*j)>(*i)-lenth) j=i;//i如果是end()查询不到其的值，如果i和j离lenth的距离一样取较小的j，所以是大于号
            cout<<(*j)<<endl,ds.erase(j);//取出后删除
        }
    }
    return 0;
}