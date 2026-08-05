#include<bits/stdc++.h>
using namespace std;
class mystack{
private:
    int mains[10000];
    int mins[10000];
    int topnum;
    public:
    mystack(){
        topnum=-1;
    }
    void push(int n){
        topnum++;
        mains[topnum]=n;
        if(topnum==0||n<=mins[topnum-1]){
            mins[topnum]=n;
        }else{
            mins[topnum]=mins[topnum-1];
        }
    }
    void pop(){
        if(topnum>=0){
            topnum--;
        }
    }
    int top(){
        return mains[topnum];
    }
    int getmin(){
        return mins[topnum];
    }
};
int main(){
    mystack stk;
    int n;
    while(cin>>n){
        if(n==0){
            stk=mystack();
        }else if(n>0){
            stk.push(n);
        }else if(n==-1){
            stk.pop();
        }else if(n==-2){
            cout<<stk.top()<<endl;
        }else if(n==-3){
            cout<<stk.getmin()<<endl;
        }
    }
    system("pause");
    return 0;
}