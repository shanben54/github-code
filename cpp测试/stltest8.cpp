//set和vector查找性能对比
#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<chrono>
using namespace std;
using namespace chrono;

int main(){
    srand(time(0));
    const int N=1000000;
    const int M=1000;

    vector<int> v;
    set<int> s;

    for(int i=0;i<N;i++){
        int x=rand()%1000000;
        s.insert(x);
        v.push_back(x);
    }

    auto t1=steady_clock::now();
    int c1=0;
    for(int i=0;i<M;i++){
        c1+=s.count(i*7%1000000);
    }
    auto t2=steady_clock::now();

    auto t3=steady_clock::now();
    int c2=0;
    for(int i=0;i<M;i++){
        c2+=(find(v.begin(),v.end(),i*7%1000000)!=v.end());
    }
    auto t4=steady_clock::now();

    cout<<"插入时间对比  set: "<<duration_cast<milliseconds>(t2-t1).count()
    <<" vector: "<<duration_cast<milliseconds>(t4-t3).count()<<endl;
    cout<<c1<<" "<<c2<<endl;
    return 0;
}