#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int num=0;
    if(s[0]=='x'&&s[1]=='x') num+=1;
    if(s[n-1]=='x'&&s[n-2]=='x') num+=1;
    for(int j=1;j<n-1;j++){
        if(s[j]=='x'&&s[j-1]=='x'&&s[j+1]=='x'){
            num+=1;
        }
    }
    cout<<num<<endl;
    system("pause");
    return 0;
}