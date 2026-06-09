#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int n,root,cnt,opt,x;
struct node{
    int left,right,size,value,num;
    node(int left1,int right1,int size1,int value1):left(left1),right(right1),size(size1),value(value1),num(1){}
    node(){}
}t[maxn];
inline void update(int root){
    t[root].size=t[t[root].left].size + t[t[root].right].size + t[root].num;
}
int rak(int x,int root){
    if(root){
        if(x<t[root].value){
            return rak(x,t[root].left);
        }
        if(x>t[root].value){
            return rak(x,t[root].right) + t[t[root].left].size + t[root].num;
        }
        return t[t[root].left].size + t[root].num;
    }
    return 1;
}
int kth(int x,int root){
    if(x<=t[t[root].left].size){
        return kth(x,t[root].left);
    }
    if(x<=t[t[root].left].size+t[root].num){
        return t[root].value;
    }
    return kth(x-t[t[root].left].size-t[root].num,t[root].right);
}