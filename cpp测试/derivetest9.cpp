//多重继承测试
#include<iostream>
using namespace std;

class A{
public:
    int a=1;
    virtual void f(){
        cout<<"A::f,a="<<a<<endl;
    }
    virtual ~A(){}
};

class B1:public A{};
class B2:public A{};

class C:public B1,public B2{};

int main(){
    C c;
    cout<<"A的大小"<<sizeof(A)<<"C的大小"<<sizeof(C)<<endl;

    c.B1::a=2;
    c.B2::a=3;
    cout<<"&c.B1::a="<<&c.B1::a<<"  &c.B2::a="<<&c.B2::a<<endl;

    c.B1::f();
    c.B2::f();

    return 0;
}