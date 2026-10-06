//用b字符串替换s里面的a
//核心是一一遍历s，然后验证当前字符是不是a的首字符，如果不是就直接存入c，找到了就跳过a把b存入c，这样c就是把s里面的a换成了b，其他字符不变
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,a,b;
    getline(cin,s);
    getline(cin,a);
    getline(cin,b);
    string c;//替换后的字符串
    int lens=s.size();
    int lena=a.size();
    int i=0;
    while(i<lens){
        //遍历寻找a的第一个字符
        int j=1;//找到了没有
        for(int k=0;k<lena;k++){
            if(s[i+k]!=a[k]){
                j=0;
                break;
            }//通过这个字符延伸a的长度，比对每一个字符，来判断是不是找到了a
        }
        if(j){
            c+=b;
            i+=lena;
            //如果找到了，就把b加入c，然后跳过a的长度继续遍历
        }else{
            c+=s[i];
            i++;
            //没有找到就把这个字符加入c,继续一一遍历
        }
    }
    cout<<c<<endl;
    system("pause");
    return 0;
}