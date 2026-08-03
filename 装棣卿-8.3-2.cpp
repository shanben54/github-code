#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    stack<char> a;
    for(char c:s){
        if(c=='('||c=='{'||c=='['){
            a.push(c);
        }else{
            if(a.empty()){
                cout<<"false"<<endl;
                system("pause");
                return 0;
            }
            char top=a.top();
            a.pop();
            if((c==')'&&top!='(')||(c=='}'&&top!='{')||(c==']'&&top!='[')){
                cout<<"false"<<endl;
                system("pause");
                return 0;
            }
        }
    }
    if(a.empty()) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    system("pause");
    return 0;
}