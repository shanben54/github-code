#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int num[10]={0};
    for(int i=0;i<=n;i++){
        int k=i;
        while(k>=1){
            int j=k%10;
            num[j]++;
            k/=10;
        }
    }
    for(int i=0;i<10;i++){
        cout<<num[i]<<endl;
    }
    system("pause");
    return 0;
}