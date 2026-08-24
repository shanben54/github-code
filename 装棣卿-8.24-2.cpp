#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> map1(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map1[i][j];
        }
    }
    int k;
    cin>>k;
    while(k--){
        vector<vector<char>> map2=map1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map1[i][j]=='g'){
                    if(i>0) map2[i-1][j]='g';
                    if(i<n-1) map2[i+1][j]='g';
                    if(j>0) map2[i][j-1]='g';
                    if(j<m-1) map2[i][j+1]='g';
                }
            }
        }
        map1=map2;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<map1[i][j];
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}