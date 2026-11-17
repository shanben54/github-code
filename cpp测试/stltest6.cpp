//vector循环中删除的坑，迭代器失效
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v1{1,2,2,3,4,4,5,6,6};
    for(auto it=v1.begin();it!=v1.end();it++){
        if(*it%2==0) v1.erase(it);
    }
    for(auto x:v1){
        cout<<x<<" ";
    }
    cout<<endl;
    vector<int> v2{1,2,2,3,4,4,5,6,6};
    for(auto it=v2.begin();it!=v2.end();){
        if(*it%2==0){
            it=v2.erase(it);
        }else{
            it++;
        }
    }
    for(auto x:v2){
        cout<<x<<" ";
    }
    return 0;
}