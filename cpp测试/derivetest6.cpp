//打印虚表
#include<iostream>
using namespace std;

class Base{
public:
    virtual void f(){
        cout<<"Base::f"<<endl;
    }
    virtual void g(){
        cout<<"Base::g"<<endl;
    }

     virtual void h(){
        cout<<"Base::h"<<endl;
    }

    virtual ~Base(){}
};

class Derive:public Base{
    void f()override{
        cout<<"Derive::f"<<endl;
    }
    void g()override{
        cout<<"Derive::g"<<endl;
    }
};

int main(){
    Base b;
    Derive d;
    
    void** vb=*reinterpret_cast<void***>(&b);
    void** vd=*reinterpret_cast<void***>(&d);

    cout<<"Base的大小:    ="<<sizeof(Base)<<endl;
    cout<<"Derive的大小:  ="<<sizeof(Derive)<<endl;
    cout<<"Base的虚表地址:     "<<vb<<endl;
    cout<<"Derive的虚表地址:   "<<vd<<endl;
    
    cout<<"--- 绕过编译器直接按虚表槽调用 ---"<<endl;
    reinterpret_cast<void(*)()>(vb[0])();
    reinterpret_cast<void(*)()>(vd[0])();
    reinterpret_cast<void(*)()>(vb[1])();
    reinterpret_cast<void(*)()>(vd[1])();

    for(int i=0;i<5;i++){
        cout<<i<<": Base= "<<vb[i]<<"  Derive= "<<vd[i]<<endl;
    }

    return 0;
}