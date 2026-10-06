#include<bits/stdc++.h>
using namespace std;
void paixu(vector<int>& a,int l,int r){
    int i=l,j=r,flag=a[(l+r)/2],tmp;
    do{
        while(a[i]<flag) i++;
        while(a[j]>flag) j--;
        if(i<=j){
            tmp=a[i];
            a[i]=a[j];
            a[j]=tmp;
            i++,j--;
        }
    }while(i<=j);
    if(l<j) paixu(a,l,j);
    if(i<r) paixu(a,i,r);
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    paixu(a,0,n-1);
    cout<<a[k]<<endl;
    system("pause");
    return 0;
}