#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for(int i=0;i<students.size();i++){
            q.push(students[i]);
        }
        int s=0;
        while(true){
            int n=students.size();
            int no=0;
            for(int i=0;i<n;i++){
                int m=q.front();
                q.pop();
                if(m==sandwiches[s]){
                    s++;
                }else{
                    q.push(m);
                    no++;
                }
            }
            if(no==n){
                break;
            }
        }
        return q.size();
    }
};