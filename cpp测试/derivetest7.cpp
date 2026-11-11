//纯虚函数和抽象类的测试
#include<iostream>
using namespace std;

const double PI=3.14;

class Shape{
public:
    virtual void Name()=0;
    virtual void Area()=0;
    virtual ~Shape()=0;
};

Shape::~Shape(){
    cout<<"Shape析构"<<endl;
}

class Circle:public Shape{
public:
    int r;
    Circle(int x):r(x){}
    void Name()override{
        cout<<"Circle"<<endl;
    }
    void Area()override{
        cout<<r*r*PI<<endl;
    }
    ~Circle(){
        cout<<"Circle析构"<<endl;
    }
};

class Rectangle:public Shape{
public:
    int d,h;
    Rectangle(int x,int y):d(x),h(y){}
    void Name()override{
        cout<<"Rectangle"<<endl;
    }
    void Area()override{
        cout<<d*h<<endl;
    }
    ~Rectangle(){
        cout<<"Rectangle析构"<<endl;
    }
};

int main(){
    Shape* s1=new Circle(3);
    Shape* s2=new Rectangle(3,6);
    s1->Name();
    s1->Area();
    s2->Name();
    s2->Area();
    delete s1;
    delete s2;
    return 0;
}