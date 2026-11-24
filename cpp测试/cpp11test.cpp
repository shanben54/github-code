//关于cpp11的一些测试
//包括range-for,结构化绑定,nullptr和NULL，constexpr
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void f(int x){
    cout<<"int"<<endl;
}
void f(const char *s){
    cout<<"*"<<endl;
}

constexpr int square(int x){
    return x*x;
}

int main(){
    //结构化绑定测试
    vector<pair<string,int>> stu={{"诺宝",321},{"胡桃",715},{"芙芙",1013},{"牛牛",1115},{"爱妃",608},{"惠",923}};
    for(const auto &[a,b]:stu){
        cout<<a<<" "<<b<<endl;
    }
    //nullptr测试，这里没有用NULL，因为NULL写出来会歧义
    f(1);
    f("zdq");
    f(nullptr);
    //constexpr测试，直接在编译器就计算好
    int a[square(3)];//计算好后可以拿来创建数组
    cout<<sizeof(a)<<" "<<sizeof(a[0])<<endl;
    //range-for测试，auto&可以修改容器元素
    //range-for是利用迭代器遍历的，所以不要在range-for时增删元素，如果触发扩容会使迭代器失效
    vector<int> v;
    for(int i=0;i<7;i++){
        v.push_back(i);
    }
    for(auto& x:v){
        x=3;
    }
    for(auto x:v){
        cout<<x<<" ";
    }
    return 0;
}