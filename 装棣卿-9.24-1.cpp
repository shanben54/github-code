#include<bits/stdc++.h>
using namespace std;

//将符号一一取出，左符号就直接放入栈，右符号就和栈顶进行匹配，不匹配就是无效，匹配就和栈顶元素一起消去，最后检查栈是否为空
class Solution {
public:
    bool isValid(string s) {
        stack<char> f;
        for(char c:s){
            if(c=='('||c=='{'||c=='['){
                f.push(c);
            }else{
                if(f.empty()) return false;
                char t=f.top();
                if((t=='('&&c==')')||(t=='{'&&c=='}')||(t=='['&&c==']')){
                    f.pop();
                }else{
                    return false;
                }
            }
        }
        if(f.empty()){
            return true;
        }else{
            return false;
        }
    }
};