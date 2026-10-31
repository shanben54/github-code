//KMP匹配算法
#include<iostream>
using namespace std;

//获取next数组
//next[i]表示前i个串里最长的前缀后缀相等的串的长度，便于回退重新比较
//哪怕当前的串匹配失败，也可以通过next进行回退，看看当前的尾巴(后缀)能不能作为开头(前缀)来匹配
void GetNext(const char p[],int m,int next[]){
    next[0]=0;
    int k=0;
    for(int i=1;i<m;i++){
        while(k>0&&p[i]!=p[k]) k=next[k];//如果匹配不上就回退
        if(p[i]==p[k]) k++;//匹配上了k增加
        next[i+1]=k;//是i+1,而i是从0开始的，i+1表示前i个
    }
}

//匹配算法，给定主串，求模式串在主串最早出现的下标
//模式串的next数组已经提前算好
//主串不回退，一直往前匹配，模式串回退看看能不能匹配上
int KMP(const char s[],int n,const char p[],int m,int next[]){
    int j=0;
    for(int i=0;i<n;i++){
        while(j>0&&s[i]!=p[j]) j=next[j];//回退看看能不能找到匹配上的
        if(s[i]==p[j]) j++;
        if(j>=m) return i-m+1;//如果j等于m说明模式串匹配完了，返回第一个位置的下标
    }
    return -1;
}

int main(){
    const char* p="ababc";
    int next[6];
    GetNext(p,5,next);
    for(int i=0;i<=5;i++){
        cout<<next[i]<<" ";
    }
    cout<<KMP("abababc",7,p,5,next)<<endl;
    cout<<KMP("ababababc",9,p,5,next)<<endl;
    cout<<KMP("abababab",8,p,5,next)<<endl;
    return 0;
}