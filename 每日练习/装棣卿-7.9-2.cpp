//给定一个英文句子，求最长单词的长度和这个单词第一个字母的序列
//遍历字符串，到空格就是说明读完了一个单词，然后进行比较，找到最长的单词，返回其长度和首字母序列，读到'.'说明整个句子读完了
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
        }else{//不是空格说明这个单词读完了
            if(len>max){
                max=len;
                n=i-len;
            }
            len=0;
        }
    }
    //再对比一次，防止最长的单词是最后一个单词
    if(len>max){
        max=len;
        n=i-len;
    }
    cout<<max<<" "<<n<<endl;
    system("pause");
    return 0;
}