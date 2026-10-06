#include<iostream>
#include<cstdlib>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

int main(){
    int w[]={1,2,3,4,5};
    priority_queue<int,vector<int>,greater<int>>q;
    for(int x:w){
        q.push(x);
    }
    int wpl=0;
    while(q.size()>1){
        int a=q.top();
        q.pop();
        int b=q.top();
        q.pop();
        int c=a+b;
        wpl+=c;
        q.push(c);
    }
    cout<<"WPL= "<<wpl<<endl;
    system("pause");
    return 0;
}