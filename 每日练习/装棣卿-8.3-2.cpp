//判断输入的字符串合不合规，就是左右符合能不能对应起来
//这题用栈的方式来解决，左符号就存入栈，再取出来和右符号看看是不是对应的，这样就满足后进先出的匹配方式
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