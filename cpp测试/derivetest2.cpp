//测试虚函数多态
#include<iostream>
using namespace std;

class Base{
public:
    void a(){
        cout<<"Base::a"<<endl;
    }
    virtual void b(){
        cout<<"Base::b"<<endl;
    }
};

class Derive:public Base{
public:
    void a(){
        cout<<"Derive::a"<<endl;
    }
    void b()override{
        cout<<"Derive::b"<<endl;
    }
};

int main(){
    Derive d;
    Base& r=d;
    Base* p=&d;
    d.a();
    d.b();
    r.a();
    r.b();
    p->a();
    p->b();
    return 0;
}