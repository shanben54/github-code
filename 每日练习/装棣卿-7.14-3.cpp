//这题给定一个n，同时输入多个单词，统计异构的单词（组成字母相同），然后输入这些单词的序列
//初步设想是先输入的字符串按空格划分成单词并编号，然后一一比对有没有组成字母相同的，如果相同划为一类记录编号，但是不知道去实现这个
//每个单词都是一个结构体，记录编号和构成字母，然后按单词的构成字母输出，一样的话就同一行输出，不是就换一行
#include<bits/stdc++.h>
using namespace std;
struct danci{
    string key;
    int num;
};
//将单词排序的函数，让字母构成相同的单词紧挨着
bool paixu(const danci &a,const danci &b){
    if(a.key!=b.key) return a.key<b.key;
    return a.num<b.num;
}
int main(){
    int n;
    cin>>n;
    vector <danci>s;//储存所有的单词
    for(int i=0;i<n;i++){
        string a;
        cin>>a;//cin只读入到空格，所以可以把单词划分出来
        sort(a.begin(),a.end());//对构成字母排序，这样可以直接看出单词之间构成字母是否相同
        s.push_back({a,i});
    }
    sort(s.begin(),s.end(),paixu);//对所有单词进行排序
    int p=0;//要输出的次数
    while(p<n){
        bool f=true;//是不是这个字母构成的第一个单词
        string k=s[p].key;
        while(p<n&&s[p].key==k){//如果字母构成一样的话
            if(!f){//不是第一个的话先空格区分编号
                cout<<" ";
            }
            cout<<s[p].num;//输出编号
            f=false;
            p++;
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}