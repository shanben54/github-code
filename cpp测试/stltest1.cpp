//vector扩容测试
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v;
    size_t last=v.capacity();
    cout<<"初始:size="<<v.size()<<" capacity="<<v.capacity()<<endl;
    for(int i=1;i<=40;i++){
        v.push_back(i);
        if(last!=v.capacity()){
            cout<<"第"<<i<<"插入后:size="<<v.size()<<" capacity="<<v.capacity()<<endl;
            last=v.capacity();
        }
    }
    return 0;
}