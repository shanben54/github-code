//initializer_list的测试
//可以作为临时对象，传参数，但是不可以当长期对象(数据，指针，返回值)
#include<iostream>
#include<vector>
#include<initializer_list>
using namespace std;

struct A{
    vector<int> k;
    A(initializer_list<int> b):k(b){}
};

struct B{
    initializer_list<int> keep;
    B(initializer_list<int> a):keep(a){}
};

int main(){
    B b{1,2,3};
    cout<<"b:"<<b.keep.size()<<endl;
    int sum=0;
    for(auto x:b.keep){
        sum+=x;
    }
    cout<<sum<<endl;
    A a{1,2,3};
    cout<<"a:"<<a.k.size()<<endl;
    int s=0;
    for(auto x:a.k){
        s+=x;
    }
    cout<<s<<endl;
    return 0;
}