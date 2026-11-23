//Lambda函数测试
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;

int main(){
    //排序测试
    vector<pair<string,int>> stu={{"诺宝",321},{"胡桃",715},{"芙芙",1013},{"牛牛",1115},{"爱妃",608},{"惠",923}};
    sort(stu.begin(),stu.end(),
    [](const auto &a,const auto &b){return a.second<b.second;});
    for(auto x:stu){
        cout<<x.first<<" "<<x.second<<endl;
    }
    
    //值捕获和引用捕获对比
    int k=0;
    auto f1=[k]()mutable{k++;return k;};
    auto f2=[&k](){k++;return k;};
    f1();f2();
    cout<<f1()<<endl;
    cout<<f2()<<endl;

    //循环里的值捕获漏洞
    vector<function<void()>> p;
    vector<function<void()>> q;
    for(int i=0;i<3;i++){
        p.push_back([&i](){cout<<i<<endl;});
        q.push_back([i](){cout<<i<<endl;});
    }
    //循环结束后i已经销毁了，但是p里面还存着i的引用
    for(auto f:p){
        f();
    }
    for(auto f:q){
        f();
    }
    return 0;
}