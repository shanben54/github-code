//继承的测试
//测试继承的构造顺序和析构顺序
#include<iostream>
using namespace std;

class Member{
    char name;
public:
    Member(const char &c):name(c){
        cout<<name<<"构造"<<endl;
    }
    ~Member(){
        cout<<name<<"析构"<<endl;
    }
};

class Base{
public:
    Member m{'a'};
    Base(){
        cout<<"Base构造"<<endl;
    }
    ~Base(){
        cout<<"Base析构"<<endl;
    }
};

class Derive:public Base{
public:
    Member n{'b'};
    Derive(){
        cout<<"Derive构造"<<endl;
    }
    ~Derive(){
        cout<<"Derive析构"<<endl;
    }
};

int main(){
    {
        Derive d;
    }
    return 0;
}