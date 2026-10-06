#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n=0;
    cin>>n;
    long long num[10];
    for(int factor=1;factor<=n;factor*=10){
        int high=n/(factor*10);
        int cur=(n/factor)%10;
        int low=n%factor;
        for(int d=0;d<10;d++){
            int ans=0;
            if(d==0){
                if(high>0) ans=(high-1)*factor+(cur>d?factor:0)+(cur==d?low+1:0);
            }else{
                ans=high*factor+(cur>d?factor:0)+(cur==d?low+1:0);
            }
            num[d]+=ans;
        }
    }
    for(int i=0;i<10;i++){
        cout<<num[i]<<endl;
    }
    system("pause");
    return 0;
}