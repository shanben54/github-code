#include<bits/stdc++.h>
using namespace std;
int a[10010],s[10010];
int main(){
    int n;
    cin>>n;
    s[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    int max=0;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            int num=s[j]-s[i-1];
            if(num>max){
                max=num;
            }
        }
    }
    cout<<max<<endl;
    system("pause");
    return 0;
}