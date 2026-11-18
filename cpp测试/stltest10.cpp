//unordered_map和map性能测试
#include<iostream>
#include<map>
#include<unordered_map>
#include<chrono>
using namespace std;
using namespace chrono;

int main(){
    const int N=1000000;
    const int M=100000;

    unordered_map<int,int> mu;
    map<int,int> mo;

    for(int i=0;i<N;i++){
        mu[i]=i;
        mo[i]=i;
    }

    auto t1=steady_clock::now();
    int s1=0;
    for(int i=0;i<M;i++){
        s1+=mu.count(i*7%N);
    }
    auto t2=steady_clock::now();

    auto t3=steady_clock::now();
    int s2=0;
    for(int i=0;i<M;i++){
        s2+=mo.count(i*7%N);
    }
    auto t4=steady_clock::now();

    cout<<"unordered_map:"<< duration_cast<microseconds>(t2-t1).count()
        <<"      map:"<< duration_cast<microseconds>(t4-t3).count()<<endl;
    cout<<s1<<" "<<s2<<endl;

    cout<<mu.bucket_count()<<" "<<mu.load_factor()<<endl;//打印桶数组容量和模量因子
    return 0;
}