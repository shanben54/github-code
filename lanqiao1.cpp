#include<bits/stdc++.h>
using namespace std;

bool isLeap(int year){
    if((year%4==0&&year%100!=0)||year%400==0){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int week=6;
    int count=0;
    const int start =1950;
    const int end=2012;
    for(int year=start;year<end;++year){
        if(isLeap(year)){
            week+=2;
        }
        else{
            week+=1;
        }
        week %=7;
        if(week==0){
            count++;
        }
    }
    cout<<count<<endl;
    system("pause");
    return 0;
}