//力扣684，有一颗生成树，但是多了一条边，出现了环，找到那条边
//使用并查集来进行判断，如果一条边两个结点的祖先已经是同一个了，那这条边就是造成环的那条边
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //查找祖先，利用递归实现压缩路径，把沿途结点的祖先都接成最大的
    int Find(int x,vector<int> &boss){
        if(boss[x]!=x){
            boss[x]=Find(boss[x],boss);
        }
        return boss[x];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        size_t n=edges.size();
        vector<int> boss(n+1);
        for(size_t i= 0;i<n;i++){
            boss[i]=i;        
        }
        vector<int> b;
        for(auto a:edges){
            int u=a[0];
            int v=a[1];
            int ub=Find(u,boss);
            int vb=Find(v,boss);
            //找到产生环的边
            if(ub==vb){
                b=a;
                break;
            }
            boss[vb]=ub;
        }
        return b;
    }
};