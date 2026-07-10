#include<bits/stdc++.h>
using namespace std;
int main(){
    char s[20];
    gets(s);
    int len=strlen(s);
    for(int i=0;i<len;i++){
        char c=s[i];
        if(c>='A'&&c<='Z'){
            c=(c-'A'+5)%26+'A';
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