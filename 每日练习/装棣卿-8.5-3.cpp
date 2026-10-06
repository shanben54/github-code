#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums;
    string s;
    getline(cin,s);
    stringstream ss(s);
    int n;
    while(ss>>n){
        nums.push_back(n);
    }
    vector<int> tail;
    for(int num:nums){
        int left=0,right=tail.size()-1;
        while(left<right){
            int mid=(left+right)/2;
            if(tail[mid]>=num){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        if(left==tail.size()){
            tail.push_back(num);
        }else{
            tail[left]=num;
        }
    }
    cout<<tail.size()<<endl;
    system("pause");
    return 0;
}