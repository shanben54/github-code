//vector是否reverse的影响(避免拷贝)
#include<iostream>
#include<vector>
#include<chrono>
using namespace std;
using namespace chrono;

int main(){
    const int N=1000000;
    vector<int>a;
    auto t1=steady_clock::now();//记录时间
    for(int i=0;i<N;i++){
        a.push_back(i);
    }
    auto t2=steady_clock::now();

    vector<int> b;
    b.reserve(N);
    auto t3=steady_clock::now();
    for(int i=0;i<N;i++){
        b.push_back(i);
    }
    auto t4=steady_clock::now();

    cout<<"不reserve: "<<duration_cast<milliseconds>(t2-t1).count()<<endl;
    cout<<"reserve后: "<< duration_cast<milliseconds>(t4-t3).count()<<endl;
    cout<<"a的capacity="<<a.capacity()<<" b的capacity="<<b.capacity()<<endl;
    return 0;
}