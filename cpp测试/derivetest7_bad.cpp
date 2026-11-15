//析构不是虚函数测试
#include<iostream>
using namespace std;

const double PI=3.14;

class Shape{
public:
    virtual void f(){}
    ~Shape();
};

Shape::~Shape(){
    cout<<"Shape析构"<<endl;
}

class Circle:public Shape{
public:
    int* r;
    Circle(int x):r(new int[x]){}
    void f(){}
    ~Circle(){
        delete[] r;
        cout<<"Circle析构"<<endl;
    }
};

class Rectangle:public Shape{
public:
    int d,h;
    Rectangle(int x,int y):d(x),h(y){}
    void f(){}
    ~Rectangle(){
        cout<<"Rectangle析构"<<endl;
    }
};

int main(){
    Shape* s1=new Circle(3);
    Shape* s2=new Rectangle(3,6);
    delete s1;
    delete s2;
    return 0;
}