//map查找键的测试
#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    map<string,string> m;
    cout<<"m初始的大小:"<<m.size()<<endl;
    string x=m["有没有这个值"];
    cout<<"查找后m的大小:"<<m.size()<<"查找到的值:"<<x<<endl;
    auto it=m.find("这个也有没有");
    cout<<"find之后m的大小:"<<m.size()<<endl;
    cout<<"找到了没有:"<<(it==m.end()?"没找到":"找到了")<<endl;
    return 0;
}