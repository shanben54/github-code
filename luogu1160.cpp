#include<bits/stdc++.h>
using namespace std;
struct node{
    int pre,key,next;
    node(int key1=0,int pre1=0,int next1=0){
        key=key1;
        pre=pre1;
        next=next1;
    }
};
node s[100005];
int n,m,tot,index[100005]={0};
void ins_back(int x,int y){
    int now=index[x];
    s[++tot]=node(y,now,s[now].next);
    s[now].next=tot;
    s[s[now].next].pre=tot;
    index[y]=tot;
}
void ins_front(int x,int y){
    int now=index[x];
    s[++tot]=node(y,s[now].pre,now);
    s[now].pre=tot;
    s[s[now].pre].next=tot;
    index[y]=tot;
}
void del(int x){
    int now=index[x];
    int l=s[now].pre,r=s[now].next;
    s[s[now].pre].next=r;
    s[s[now].next].pre=l;
    index[x]=0;
}
int main(){
    int x,k,p,now;
    cin>>n;
    s[0]=node();
    ins_back(0,1);
    for(int i=2;i<=n;i++){
        cin>>k>>p;
        p?ins_back(k,i):ins_front(k,i);
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>x;
        if(index[x]) del(x);
    }
    now=s[0].next;
    while(now){
        cout<<s[now].key<<" ";
        now=s[now].next;
    }
    system("pause");
    return 0;
}