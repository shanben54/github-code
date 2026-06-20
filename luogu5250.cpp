#include<bits/stdc++.h>
using namespace std;
int n,opt,lenth;
set<int> ds;
int main(){
    cin>>n;
    while(n--){
        cin>>opt>>lenth;
        if(opt==1){
            if(ds.find(lenth)!=ds.end()) cout<<"Already Exist"<<endl;
            else ds.insert(lenth);
        }
        else if(ds.empty()){
            cout<<"Empty"<<endl;
        }
        else{
            set<int>::iterator i=ds.lower_bound(lenth),j=i;
            if(j!=ds.begin()) --j;
            if(i!=ds.end()&&lenth-(*j)>(*i)-lenth) j=i;
            cout<<(*j)<<endl,ds.erase(j);
        }
    }
    return 0;
}