#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){
    int c=*a;
    *a=*b;
    *b=c;
}
int main(){
    int a=3,b=4;
    swap(a,b);
    printf("%d,%d",a,b);
    system("pause");
    return 0;
}