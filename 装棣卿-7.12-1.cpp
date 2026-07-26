//合并数组，给定两个有序数组，进行合并成一个新的有序数组，要去重
//跟背包问题里面的合并差不多，不过要进行去重，所有用了l和d,一个记录上次的数字，一个记录当下的，如果一样就直接跳过，就不会重复了
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    int a[110],b[110];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    int c[210];//合并后的数组
    int i=0,j=0,k=0;
    int l=-1,d=0;//一个记录上一个数字，一个记录当下的数字
    while(i<n&&j<m){
        if(a[i]<=b[j]){
            d=a[i++];
        }else{
            d=b[j++];
        }
        if(d==l) continue;//如果现在的数字和上一个相等，直接跳过，避免重复
        c[k++]=d;
        l=d;
    }
    while(i<n){
        int d=a[i++];
        if(d==l) continue;
        c[k++]=d;
        l=d;
    }
    while(j<m){
        int d=b[j++];
        if(d==l) continue;
        c[k++]=d;
        l=d;
    }
    for(int s=0;s<k;s++){
        cout<<c[s]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}