#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,a,b;
    getline(cin,s);
    getline(cin,a);
    getline(cin,b);
    string c;
    int lens=s.size();
    int lena=a.size();
    int i=0;
    while(i<lens){
        int j=1;
        for(int k=0;k<lena;k++){
            if(s[i+k]!=a[k]){
                j=0;
                break;
            }
        }
        if(j){
            c+=b;
            i+=lena;
        }else{
            c+=s[i];
            i++;
        }
    }
    cout<<s<<endl;
    system("pause");
    return 0;
}