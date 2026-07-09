#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a[110],p[110];
    cin>>n;
    int num=0,b=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=0;j<i;j++){
            if(p[j]==a[i]){
                b=1;
                break;
            }
        }if(!b){
            p[num++]=a[i];
        }
        b=0;
    }
    for(int i=0;i<num;i++){
        cout<<p[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}