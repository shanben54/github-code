//list删除操作后迭代器测试
#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int>v{1,2,3,4,5};
    auto p=v.begin();
    p++;
    cout<<"记住的值"<<*p<<endl;
    v.push_front(0);
    v.push_back(6);
    cout<<"插入操作后记住的值"<<*p<<endl;
    return 0;
}