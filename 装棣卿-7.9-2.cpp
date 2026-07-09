#include<bits/stdc++.h>
using namespace std;
int main(){
    char s[110];
    gets(s);
    int len=0,n,max;
    int i=0;
    for(i=0;s[i]!='.';i++){
        if(s[i]!=' '){
            len++;
        }else{
            if(len>max){
                max=len;
                n=i-len;
            }
            len=0;
        }
    }
    if(len>max){
        max=len;
        n=i-len;
    }
    cout<<max<<" "<<n<<endl;
    system("pause");
    return 0;
}