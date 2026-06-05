#include<bits/stdc++.h>
using namespace std;
struct node{
    int pre,next,key;
    node(int key1,int pre1,int next1){
        pre=pre1;
        next=next1;
        key=key1;
    }
};
node s[1005];
int tot=0;
int find(int x){
    int now=1;
    while(now&&s[now].key!=x){
        now=s[now].next;
    }
    return now;
}
void ins_back(int x,int y){
    int now=find(x);
    s[++tot]=node(y,now,s[now].next);
    s[s[now].next].pre=tot;
    s[now].next=tot;
}
void ins_front(int x,int y){
    int now=find(x);
    s[++tot]=node(y,s[now].pre,now);
    s[s[now].pre].next=tot;
    s[now].pre=tot;
}
int  ask_back(int x){
    int now=find(x);
    return s[s[now].next].key;
}
int ask_front(int x){
    int now=find(x);
    return s[s[now].pre].key;
}
void del(int x){
    int now=find(x);
    int l=s[now].pre,r=s[now].next;
    s[l].next=r;
    s[r].pre=l;
}