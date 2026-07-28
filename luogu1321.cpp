#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
	cin>>s;
	int n=s.size(),boy=0,girl=0;
	for (int i=0;i<n;i++){
		if (s[i]=='b') boy++;
		if (s[i]=='o'&&s[i-1]!='b') boy++;
		if (s[i]=='y'&&s[i-1]!='o'&&s[i-2]!='b') boy++;//boy的运算
		if (s[i]=='g') girl++;
		if (s[i]=='i'&&s[i-1]!='g') girl++;
		if (s[i]=='r'&&s[i-1]!='i'&&s[i-2]!='g') girl++;
		if (s[i]=='l'&&s[i-1]!='r'&&s[i-2]!='i'&&s[i-3]!='g') girl++;//girl的运算
	}
	cout<<boy<<endl<<girl<<endl;//输出结果
    system("pause");
    return 0;
}