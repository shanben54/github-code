//vector和list性能对比
#include<iostream>
#include<vector>
#include<list>
#include<chrono>
using namespace std;
using namespace chrono;

int main(){
    const int N=1000000;
    
    vector<int>v;
    auto t1=steady_clock::now();
    for(int i=0;i<N;i++){
        v.push_back(i);
    }
    auto t2=steady_clock::now();

    list<int> l;
    auto t3=steady_clock::now();
    for(int i=0;i<N;i++){
        l.push_back(i);
    }
    auto t4=steady_clock::now();

    cout<<"插入时间对比  Vector: "<<duration_cast<milliseconds>(t2-t1).count()<<" List: "<<duration_cast<milliseconds>(t4-t3).count()<<endl;
    long long s;
    auto t5=steady_clock::now();
    for(auto x:v){
        s+=x;
    }
    auto t6=steady_clock::now();
    for(auto x:l){
        s+=x;
    }
    auto t7=steady_clock::now();
    cout<<"遍历时间对比:  Vector: "<<duration_cast<milliseconds>(t6-t5).count()<<" List: "<<duration_cast<milliseconds>(t7-t6).count()<<endl;
    cout<<s<<endl;//打印s，不然s这个变量没有用处会被编译器直接忽略

    auto li=l.begin();
    advance(li,l.size()/2);
    auto t8=steady_clock::now();
    for(int i=0;i<1000;i++){
        v.insert(v.begin()+v.size()/2,i);
    }
    auto t9=steady_clock::now();

    t1=steady_clock::now();
    for(int i=0;i<1000;i++){
        l.insert(li,i);
    }
    t2=steady_clock::now();
    cout<<"中间插入时间对比: Vector: "<<duration_cast<milliseconds>(t9-t8).count()<<" List: "<<duration_cast<milliseconds>(t2-t1).count()<<endl;
    return 0;
}