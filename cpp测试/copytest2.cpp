#include<iostream>
using namespace std;

class Tracer{
public:
    int id;

    Tracer(int i):id(i){
        cout<<"构造"<<id<<endl;
    }

    Tracer(const Tracer &o):id(o.id){
        cout<<"拷贝构造"<<id<<endl;
    }

    Tracer& operator=(const Tracer& o){
        id=o.id;
        cout<<"拷贝赋值"<<id<<endl;
        return *this;
    }

    ~Tracer(){
        cout<<"析构"<<endl;
    }
};

void f(Tracer t){
}

Tracer g(){
    Tracer t(3);
    return t;
}

int main(){
    {
        Tracer a(1);
    }
    {
        Tracer a(1);
        Tracer b=a;
    }
    {
        Tracer a(1);
        Tracer c(0);
        c=a;
    }
    {
        Tracer a(1);
        f(a);
    }
    {
        Tracer e=g();
    }
    return 0;
}