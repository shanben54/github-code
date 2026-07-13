#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int num;
    cin>>num;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]+a[j]==num){
                cout<<i<<" "<<j<<endl;
                system("pause");
                return 0;
            }
        }
    }
    return 0;
}