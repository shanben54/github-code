//在已知前序和后序遍历的情况下，求有多少种中序遍历
#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int ans;
char a[maxn],b[maxn];
int main(){
    cin>>a>>b;
    for(int i=0;a[i];i++){
        for(int j=1;b[j];j++){
            if(a[i]==b[j]&&a[i+1]==b[j-1]){
                ans++;
            }
        }
    }
    cout<<(1<<ans)<<endl;
    return 0;
}