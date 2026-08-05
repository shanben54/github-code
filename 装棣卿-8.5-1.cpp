//木桶效应，给定一串数字，每个盛水量为两个数字中最小的乘两个数字的间距，求最大盛水量
//直接一一枚举也可以的，就是效率低点
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> h;
    string s;
    getline(cin,s);
    stringstream ss(s);
    int n;
    while(ss>>n){
        h.push_back(n);
    }
    int left=0,right=h.size()-1;
    int ans=0;
    while(left<right){
        int sh=min(h[left],h[right]);
        int sa=sh*(right-left);
        ans=max(ans,sa);
        if(h[left]<h[right]){
            left++;
        }else{
            right--;
        }
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}