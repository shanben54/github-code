//宏的测试
#include<iostream>
using namespace std;

#define MAX(a,b) a>b?a:b
#define MAX2(a,b) ((a)>(b)?(a):(b))

constexpr int CMAX(int a,int b){
    return a>b?a:b;
}

int main(){
    int x=5,y=1;
    MAX(++x,y);
    cout<<x<<endl;
    x=5;
    //括号只影响优先级，还是会使得x++两次
    MAX2(++x,y);
    cout<<x<<endl;
    x=5;
    //而x在进入函数的时候就++一次，之后就不会再增加了
    CMAX(++x,y);
    cout<<x<<endl;
    return 0;
}