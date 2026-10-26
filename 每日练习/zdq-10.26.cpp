//力扣20，括号匹配
//建个栈，然后左括号就入栈，右括号就取出匹配
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        for(auto c:s){
            if(c=='['||c=='{'||c=='('){
                p.push(c);
            }else{
                if(p.empty()) return false;//防止直接就是右括号开头
                char a=p.top();
                p.pop();
                if(!((a=='('&&c==')')||(a=='{'&&c=='}')||(a=='['&&c==']'))){
                    return false;
                }
            }
        }
        return p.empty();//防止还剩左括号没匹配
    }
};