//vector扩容迭代器失效测试
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v;
    v.push_back(3);
    int *p=&v[0];
    cout<<"扩容前"<<*p<<endl;
    for(int i=1;i<1000;i++){
        v.push_back(i);
    }
    cout<<"扩容后"<<*p<<endl;
    return 0;
}