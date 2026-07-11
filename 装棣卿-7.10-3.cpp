//输入一个字符串，如果其中有字母或者数字，将其顺序向后移动5格，超过了z或者0就绕圈从头来
#include<bits/stdc++.h>
using namespace std;
int main(){
    char s[20];
    gets(s);
    int len=strlen(s);
    for(int i=0;i<len;i++){
        char c=s[i];
        if(c>='A'&&c<='Z'){
            c=(c-'A'+5)%26+'A';//取模再加上'A'就可以解决如果加5超过'Z'就循环的问题
        }
        if(c>='a'&&c<='z'){
            c=(c-'a'+5)%26+'a';
        }
        if(c>='0'&&c<='9'){
            c=(c-'0'+5)%10+'0';
        }
        cout<<c;
    }
    cout<<endl;
    system("pause");
    return 0;
}