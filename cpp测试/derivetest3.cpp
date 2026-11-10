//多态实验，如果虚函数前后参数不一样会怎么样
#include<iostream>
using namespace std;

class Base{
public:
    virtual void g()const{
        cout<<"Base::g"<<endl;
    }
    virtual ~Base(){}
};

class Derive:public Base{
public:
    void g(){
        cout<<"Derive::g"<<endl;
    }
};

int main(){
    Derive d;
    Base& r=d;
    const Base& rc=d;
    d.g();
    r.g();
    rc.g();
    return 0;
}