#include<bits/stdc++.h>
using namespace std;
int n,q,opt,i,j,k;
int main(){
    cin>>n>>q;
    vector<vector<int>>l(n+1);
    while(q--){
        cin>>opt;
        if(opt==1){
            cin>>i>>j>>k;
            if(l[i].size()<j+1){
                l[i].resize(j+1);
            }
            l[i][j]=k;
        }
        else{
            cin>>i>>j;
            cout<<l[i][j]<<endl;
        }
    }
    system("pause");
    return 0;
}