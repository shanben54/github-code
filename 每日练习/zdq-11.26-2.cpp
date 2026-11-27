//力扣79，单词搜索，给定一个字母网格和word，求能否用网格里的相邻字母拼成单词，字母不能重复使用
//使用回溯算法，用一个used数组记录字母使用情况，先遍历网格，如果发现有个单词首字母相同的就进入DFS
//在DFS里向四个方向进行搜索看看有没有单词的下一个字母，有就继续，没有就判负
//最终遍历完网格进行判断
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dis[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    bool DFS(vector<vector<char>>& board,vector<vector<int>> &used,string path,int num,string word,int x,int y){
        if(path.size()==word.size()) return true;//在过程中进行了剪枝，所以当path和word一样长的时候就是找到了
        int m=board.size();
        int n=board[0].size();
        //向四个方向搜索
        for(auto a:dis){
            int xr=x+a[0];
            int yr=y+a[1];
            if(xr>-1&&xr<m&&yr>-1&&yr<n&&used[xr][yr]==0&&board[xr][yr]==word[num]){
                used[xr][yr]=1;
                if(DFS(board,used,path+board[xr][yr],num+1,word,xr,yr)) return true;
                used[xr][yr]=0;//回溯重置状态
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> used(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    used[i][j]=1;
                    string path="";
                    if(DFS(board,used,path+word[0],1,word,i,j)){
                        return true;
                    }
                    used[i][j]=0;
                }
            }
        }
        return false;
    }
};