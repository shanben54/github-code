#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int n,root,cnt,opt,x;
struct node{
    int left,right,size,value,num;
    node(int left1,int right1,int size1,int value1):left(left1),right(right1),size(size1),value(value1),num(1){}
    node(){}
}t[maxn];
//更新节点的总节点数
inline void update(int root){
    t[root].size=t[t[root].left].size + t[t[root].right].size + t[root].num;
}
//查询数字x的排名
//比节点小说明在左边，大说明在右边
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
void insert(int x,int&root){
    if(x<t[root].value){
        if(!t[root].left){
            t[t[root].left=++cnt]=node(0,0,1,x);
        }
        else{
            insert(x,t[root].left);
        }
    }
    else if(x>t[root].value){
        if(!t[root].right){
            t[t[root].right=++cnt]=node(0,0,1,x);
        }
        else{
            insert(x,t[root].right);
        }
    }else{
        t[root].num++;
    }
    update(root);
}
int main(){
    cin>>n;
    int num=0;
    t[root=++cnt]=node(0,0,1,2147483647);
    while(n--){
        cin>>opt>>x;
        num++;
        if(opt==1) cout<<rak(x,root)<<endl;
        else if(opt==2) cout<<kth(x,root)<<endl;
        else if(opt==3) cout<<kth(rak(x,root)-1,root)<<endl;
        else if(opt==4) cout<<kth(rak(x+1,root),root)<<endl;
        else num--,insert(x,root);
    }
    return 0;
}