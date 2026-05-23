#include<bits/stdc++.h>
using namespace std;
int n,m,tmp;
int main(){
    vector<int>stu;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        stu.push_back(tmp);
    }
    for(int i=0;i<m;i++){
        cin>>tmp;
        cout<<stu[tmp-1]<<endl;
    }
    system("pause");
    return 0;
}