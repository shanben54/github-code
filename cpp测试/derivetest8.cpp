#include<iostream>
using namespace std;

class Base{
public:
    int x=1;
    virtual void show(){
        cout<<"Base:x= "<<x<<endl;
    }
    virtual ~Base(){}
};

class Derive:public Base{
public:
    int y=2;
    void show(){
        cout<<"Derive:x="<<x<<" y="<<y<<endl;
    }
};

void Vshow(Base b){b.show();}
void Rshow(Base& b){b.show();}

int main(){
    cout<<"Base的大小"<<sizeof(Base)<<"Derive的大小"<<sizeof(Derive)<<endl;
    Derive d;
    d.show();
    Vshow(d);
    Rshow(d);

    Base b=d;
    b.show();

    return 0;
}