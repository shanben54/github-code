//vector用法测试
#include<iostream>
#include<vector>
#include<chrono>
#include<algorithm>
using namespace std;
using namespace chrono;

int main(){
    srand(time(0));
    const int N=200000;
    vector<int> v;
    
    vector<int> s(N);
    for(int i=0;i<N;i++){
        s[i]=rand()%1000;
    }

    auto t1=steady_clock::now();
    for(int i=0;i<N;i++){
        v.push_back(s[i]);
    }
    auto t2=steady_clock::now();
    cout<<"不reserve的时间: "<<duration_cast<milliseconds>(t2-t1).count()<<endl;

    vector<int>w;
    w.reserve(N);
    auto t3=steady_clock::now();
    for(int i=0;i<N;i++){
        w.push_back(s[i]);
    }
    auto t4=steady_clock::now();
    cout<<"reserve的时间: "<<duration_cast<milliseconds>(t4-t3).count()<<endl;

    auto t5=steady_clock::now();
    sort(v.begin(),v.end());
    auto t6=steady_clock::now();
    cout<<"排序的时间: "<<duration_cast<milliseconds>(t6-t5).count()<<endl;

    v.insert(v.begin()+5,3);
    v.erase(v.begin());
    for(int i=0;i<10;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<"v:size="<<v.size()<<" v:capacity="<<v.capacity()<<endl;
    v.resize(10);//resize只改变size不改变容量
    cout<<"v:size="<<v.size()<<" v.capacity="<<v.capacity()<<endl;
    v.shrink_to_fit();//真正缩容量的
    cout<<"v:capacity="<<v.capacity()<<endl;
    return 0;
}