//在已知前序和后序遍历的情况下，求有多少种中序遍历
//当一个结点只有一个子结点，就可能在中序遍历里产生两种情况
//当在前序里出现AB，后序里出现BA，这就说明A结点只有B这一个子结点
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
    cout<<(1<<ans)<<endl;//(1<<ans表示2的ans次方)
    return 0;
}