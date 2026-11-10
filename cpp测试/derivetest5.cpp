//多态测试，如果构造函数里有虚函数会调用谁的
#include<iostream>
using namespace std;

class Base{
public:
    Base(){
        show();
    }
    virtual void show(){
        cout<<"Base::show"<<endl;
    }
    virtual ~Base(){}
};

class Derive:public Base {
    void show()override{
        cout<<"Derive::show"<<endl;
    }
};
int main(){
    Derive d;
    return 0;
}