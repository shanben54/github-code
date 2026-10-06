#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int n,k;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    while(q.size()!=0){
        for(int i=1;i<k;i++){
            q.push(q.front());
            q.pop();
        }
        printf("%d ",q.front());
        q.pop();
    }
    system("pause");
    return 0;
}