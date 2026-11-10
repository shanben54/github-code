//多态实验，虚函数默认参数会调用谁的
#include<iostream>
using namespace std;

class Base{
public:
    virtual void f(int x=1){
        cout<<"Base:f "<<x<<endl;    
    }
    virtual ~Base(){}
};

class Derive:public Base{
public:
    void f(int x=2)override{
        cout<<"Derive:f "<<x<<endl;
    }
};

int main(){
    Derive d;
    Base& r=d;
    d.f();
    r.f();
    return 0;
}