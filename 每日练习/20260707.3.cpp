#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int main(){
    int n,m,i;
    cin>>n>>m;
    for(i=1;i<=n;i++) q.push(i);
    while(q.size()!=1){
        for(i=1;i<m;i++){
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
    cout<<q.front()<<endl;
    system("pause");
    return 0;
}