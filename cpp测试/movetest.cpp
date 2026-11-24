//移动和emplace_back测试
#include<iostream>
#include<string>
#include<vector>
#include<utility>
using namespace std;

struct Track{
    int id;
    Track(int x):id(x){
        cout<<"构造"<<id<<endl;
    }
    Track(const Track &o):id(o.id){
        cout<<"拷贝"<<id<<endl;
    }
    //移动构造函数
    Track(Track&& o)noexcept:id(o.id){
        cout<<"移动"<<id<<endl;
    }
    ~Track(){
        cout<<"析构"<<id<<endl;
    }
};

int main(){
    vector<Track> v;
    v.reserve(10);
    cout<<" "<<endl;
    v.push_back(Track(1));//创建临时对象再添加成员
    cout<<" "<<endl;
    v.emplace_back(2);//直接利用参数构造一个成员
    cout<<" "<<endl;
    Track t(3);
    v.push_back(t);//左值添加
    cout<<" "<<endl;
    v.push_back(std::move(t));//右值添加
}
